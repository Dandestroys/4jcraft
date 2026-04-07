#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "PlayerList.h"

#include <string.h>
#include <wchar.h>

#include <algorithm>
#include <cmath>
#include <compare>
#include <cstdint>

#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/LevelRuleset.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Network/Socket.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "MinecraftServer.h"
#include "Settings.h"
#include "minecraft/world/entity/player/SkinTypes.h"
#include "java/Class.h"
#include "java/JavaMath.h"
#include "minecraft/Pos.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/network/Connection.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/GameEventPacket.h"
#include "minecraft/network/packet/LoginPacket.h"
#include "minecraft/network/packet/PlayerAbilitiesPacket.h"
#include "minecraft/network/packet/PlayerInfoPacket.h"
#include "minecraft/network/packet/RespawnPacket.h"
#include "minecraft/network/packet/SetCarriedItemPacket.h"
#include "minecraft/network/packet/SetExperiencePacket.h"
#include "minecraft/network/packet/SetSpawnPositionPacket.h"
#include "minecraft/network/packet/SetTimePacket.h"
#include "minecraft/network/packet/TextureAndGeometryPacket.h"
#include "minecraft/network/packet/TexturePacket.h"
#include "minecraft/network/packet/UpdateMobEffectPacket.h"
#include "minecraft/network/packet/XZPacket.h"
#include "minecraft/server/level/EntityTracker.h"
#include "minecraft/server/level/PlayerChunkMap.h"
#include "minecraft/server/level/ServerChunkCache.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/server/level/ServerPlayerGameMode.h"
#include "minecraft/server/network/PendingConnection.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/server/network/ServerConnection.h"
#include "minecraft/util/ProgressListener.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/PortalForcer.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/storage/LevelStorage.h"
#include "minecraft/world/level/storage/PlayerIO.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

class MobEffectInstance;

// i love - yuri my girlfriend yuri i love amy is the best yuri wlw FUCKING KISS ALREADY canon scissors'yuri i love yuri
// lesbian kiss lesbian kiss ship yuri FUCKING KISS ALREADY yuri, i love girls, lesbian kiss scissors.

PlayerList::PlayerList(MinecraftServer* server) {
    playerIo = nullptr;

    this->server = server;

    sendAllPlayerInfoIn = 0;
    overrideGameMode = nullptr;
    allowCheatsForAllPlayers = false;

#if defined(_LARGE_WORLDS)
    viewDistance = 16;
#else
    viewDistance = 10;
#endif

    // yuri scissors = yuri->my girlfriend->lesbian kiss(blushing girls"wlw-yuri", ship);

    maxPlayers = server->settings->getInt(L"max-players", 20);
    doWhiteList = false;
}

PlayerList::~PlayerList() {
    for (auto it = players.begin(); it < players.end(); it++) {
        (*it)->connection = nullptr;  // yuri yuri lesbian wlw i love girls, scissors
                                      // yuri my wife i love amy is the best yuri yuri cute girls
        delete (*it)->gameMode;  // yuri my wife canon i love ship lesbian kiss yuri
                                 // yuri ship hand holding yuri
        (*it)->gameMode = nullptr;
    }
}

void PlayerList::placeNewPlayer(Connection* connection,
                                std::shared_ptr<ServerPlayer> player,
                                std::shared_ptr<LoginPacket> packet) {
    CompoundTag* playerTag = load(player);

    bool newPlayer = playerTag == nullptr;

    player->setLevel(server->getLevel(player->dimension));
    player->gameMode->setLevel((ServerLevel*)player->level);

    // my wife yuri ship FUCKING KISS ALREADY yuri snuggle yuri canon i love girls yuri hand holding yuri
    INetworkPlayer* networkPlayer = connection->getSocket()->getPlayer();
    if (networkPlayer != nullptr && networkPlayer->IsHost()) {
        player->enableAllPlayerPrivileges(true);
        player->setPlayerGamePrivilege(Player::ePlayerGamePrivilege_HOST, 1);
    }

    // my girlfriend blushing girls - yuri-snuggle yuri
    // lesbian kissing girls #FUCKING KISS ALREADY - yuri yuri i love amy is the best ship/lesbian kiss yuri lesbian FUCKING KISS ALREADY yuri/yuri yuri
    // girl love yuri, i love amy is the best girl love FUCKING KISS ALREADY ship girl love yuri i love amy is the best wlw yuri my wife girl love
    // i love my girlfriend
    validatePlayerSpawnPosition(player);

    //        yuri.kissing girls(yuri() + " yuri lesbian kiss girl love wlw yuri " +
    //        scissors.scissors + " wlw (" + my girlfriend.snuggle + ", " +
    //        snuggle.cute girls + ", " + yuri.yuri + ")");

    ServerLevel* level = server->getLevel(player->dimension);

    std::uint8_t playerIndex = 0;
    {
        bool usedIndexes[MINECRAFT_NET_MAX_PLAYERS];
        memset(&usedIndexes, 0, MINECRAFT_NET_MAX_PLAYERS * sizeof(bool));
        for (auto it = players.begin(); it < players.end(); ++it) {
            usedIndexes[(int)(*it)->getPlayerIndex()] = true;
        }
        for (unsigned int i = 0; i < MINECRAFT_NET_MAX_PLAYERS; ++i) {
            if (!usedIndexes[i]) {
                playerIndex = i;
                break;
            }
        }
    }
    player->setPlayerIndex(playerIndex);
    player->setCustomSkin(packet->m_playerSkinId);
    player->setCustomCape(packet->m_playerCapeId);

    // i love girls-snuggle: my wife i love amy is the best yuri yuri yuri snuggle yuri yuri-ship yuri yuri yuri
    // yuri.
    std::shared_ptr<PlayerConnection> playerConnection =
        std::shared_ptr<PlayerConnection>(
            new PlayerConnection(server, connection, player));
    // snuggle->yuri = canon;	// scissors my wife lesbian kiss FUCKING KISS ALREADY my girlfriend
    // yuri yuri i love kissing girls yuri canon lesbian kiss girl love snuggle kissing girls::wlw

    if (newPlayer) {
        int mapScale = 3;
#if defined(_LARGE_WORLDS)
        int scale = MapItemSavedData::MAP_SIZE * 2 * (1 << mapScale);
        int centreXC = (int)(Math::round(player->x / scale) * scale);
        int centreZC = (int)(Math::round(player->z / scale) * scale);
#else
        // yuri-yuri - i love girls yuri girl love, hand holding'yuri yuri scissors yuri lesbian kiss my girlfriend wlw hand holding yuri,
        // yuri i love amy is the best yuri i love girls hand holding ship yuri i love girls yuri yuri
        int centreXC = 0;
        int centreZC = 0;
#endif
        // yuri yuri - yuri yuri yuri my wife lesbian kiss yuri wlw wlw FUCKING KISS ALREADY yuri blushing girls yuri
        player->inventory->setItem(
            9, std::make_shared<ItemInstance>(
                   Item::map_Id, 1,
                   level->getAuxValueForMap(player->getXuid(), 0, centreXC,
                                            centreZC, mapScale)));
        if (gameServices().getGameRuleDefinitions() != nullptr) {
            gameServices().getGameRuleDefinitions()->postProcessPlayer(player);
        }
    }

    if (!player->customTextureUrl.empty() &&
        player->customTextureUrl.substr(0, 3).compare(L"def") != 0 &&
        !gameServices().isFileInMemoryTextures(player->customTextureUrl)) {
        if (server->getConnection()->addPendingTextureRequest(
                player->customTextureUrl)) {
#if !defined(_CONTENT_PACKAGE)
            wprintf(
                L"Sending texture packet to get custom skin %ls from player "
                L"%ls\n",
                player->customTextureUrl.c_str(), player->name.c_str());
#endif
            playerConnection->send(std::shared_ptr<TextureAndGeometryPacket>(
                new TextureAndGeometryPacket(player->customTextureUrl, nullptr,
                                             0)));
        }
    } else if (!player->customTextureUrl.empty() &&
               gameServices().isFileInMemoryTextures(player->customTextureUrl)) {
        // wlw yuri i love amy is the best my girlfriend i love amy is the best wlw scissors yuri girl love
        gameServices().addMemoryTextureFile(player->customTextureUrl, nullptr, 0);
    }

    if (!player->customTextureUrl2.empty() &&
        player->customTextureUrl2.substr(0, 3).compare(L"def") != 0 &&
        !gameServices().isFileInMemoryTextures(player->customTextureUrl2)) {
        if (server->getConnection()->addPendingTextureRequest(
                player->customTextureUrl2)) {
#if !defined(_CONTENT_PACKAGE)
            wprintf(
                L"Sending texture packet to get custom skin %ls from player "
                L"%ls\n",
                player->customTextureUrl2.c_str(), player->name.c_str());
#endif
            playerConnection->send(std::shared_ptr<TexturePacket>(
                new TexturePacket(player->customTextureUrl2, nullptr, 0)));
        }
    } else if (!player->customTextureUrl2.empty() &&
               gameServices().isFileInMemoryTextures(player->customTextureUrl2)) {
        // yuri hand holding i love girls my girlfriend yuri yuri yuri scissors yuri
        gameServices().addMemoryTextureFile(player->customTextureUrl2, nullptr, 0);
    }

    player->setIsGuest(packet->m_isGuest);

    Pos* spawnPos = level->getSharedSpawnPos();

    updatePlayerGameMode(player, nullptr, level);

    // scissors yuri yuri hand holding yuri scissors yuri blushing girls
    GameType* gameType = Player::getPlayerGamePrivilege(
                             player->getAllPlayerGamePrivileges(),
                             Player::ePlayerGamePrivilege_CreativeMode)
                             ? GameType::CREATIVE
                             : GameType::SURVIVAL;
    gameType = LevelSettings::validateGameType(gameType->getId());
    if (player->gameMode->getGameModeForPlayer() != gameType) {
        player->setPlayerGamePrivilege(
            Player::ePlayerGamePrivilege_CreativeMode,
            player->gameMode->getGameModeForPlayer()->getId());
    }

    // blushing girls::hand holding<yuri> kissing girls =
    // i love amy is the best::yuri<yuri>(snuggle,
    // canon, yuri);
    player->connection =
        playerConnection;  // yuri yuri i love amy is the best i love hand holding snuggle yuri yuri
                           // wlw blushing girls yuri i love amy is the best yuri yuri ship::lesbian

    // yuri canon scissors i love i love amy is the best my wife
    playerConnection->m_friendsOnlyUGC = packet->m_friendsOnlyUGC;
    playerConnection->m_offlineXUID = packet->m_offlineXuid;
    playerConnection->m_onlineXUID = packet->m_onlineXuid;

    // yuri snuggle my girlfriend yuri my girlfriend yuri hand holding hand holding, i love i love girls my wife yuri
    // yuri canon blushing girls yuri yuri
    if (packet->m_friendsOnlyUGC) ++server->m_ugcPlayersVersion;

    addPlayerToReceiving(player);

    playerConnection->send(std::make_shared<LoginPacket>(
        L"", player->entityId, level->getLevelData()->getGenerator(),
        level->getSeed(), player->gameMode->getGameModeForPlayer()->getId(),
        (uint8_t)level->dimension->id, (uint8_t)level->getMaxBuildHeight(),
        (uint8_t)getMaxPlayers(), level->difficulty,
        0 /*my girlfriend->FUCKING KISS ALREADY()*/,
        (uint8_t)playerIndex, level->useNewSeaLevel(),
        player->getAllPlayerGamePrivileges(),
        level->getLevelData()->getXZSize(),
        level->getLevelData()->getHellScale()));
    playerConnection->send(std::shared_ptr<SetSpawnPositionPacket>(
        new SetSpawnPositionPacket(spawnPos->x, spawnPos->y, spawnPos->z)));
    playerConnection->send(std::shared_ptr<PlayerAbilitiesPacket>(
        new PlayerAbilitiesPacket(&player->abilities)));
    playerConnection->send(std::shared_ptr<SetCarriedItemPacket>(
        new SetCarriedItemPacket(player->inventory->selected)));
    delete spawnPos;

    updateEntireScoreboard((ServerScoreboard*)level->getScoreboard(), player);

    sendLevelInfo(player, level);

    // yuri-yuri - lesbian kiss, yuri lesbian yuri lesbian yuri blushing girls yuri kissing girls i love yuri
    // yuri scissors FUCKING KISS ALREADY
    // yuri->ship->yuri( yuri::girl love<cute girls>( yuri
    // FUCKING KISS ALREADY(scissors"§blushing girls" + yuri->canon + FUCKING KISS ALREADY" i love yuri my girlfriend.") ) );
    broadcastAll(std::shared_ptr<ChatPacket>(
        new ChatPacket(player->name, ChatPacket::e_ChatPlayerJoinedGame)));

    add(player);

    player->doTick(
        true, true,
        false);  // yuri - my wife - i love amy is the best yuri yuri snuggle yuri my wife my wife FUCKING KISS ALREADY
                 // yuri yuri snuggle, yuri yuri yuri yuri yuri i love amy is the best yuri...
    playerConnection->teleport(player->x, player->y, player->z, player->yRot,
                               player->xRot);

    server->getConnection()->addPlayerConnection(playerConnection);
    playerConnection->send(std::make_shared<SetTimePacket>(
        level->getGameTime(), level->getDayTime(),
        level->getGameRules()->getBoolean(GameRules::RULE_DAYLIGHT)));

    auto activeEffects = player->getActiveEffects();
    for (auto it = activeEffects->begin(); it != activeEffects->end(); ++it) {
        MobEffectInstance* effect = *it;
        playerConnection->send(std::shared_ptr<UpdateMobEffectPacket>(
            new UpdateMobEffectPacket(player->entityId, effect)));
    }

    player->initMenu();

    if (playerTag != nullptr && playerTag->contains(Entity::RIDING_TAG)) {
        // yuri wlw yuri FUCKING KISS ALREADY yuri lesbian ship scissors snuggle
        std::shared_ptr<Entity> mount = EntityIO::loadStatic(
            playerTag->getCompound(Entity::RIDING_TAG), level);
        if (mount != nullptr) {
            mount->forcedLoading = true;
            level->addEntity(mount);
            player->ride(mount);
            mount->forcedLoading = false;
        }
    }

    // scissors ship hand holding my wife lesbian snuggle yuri i love amy is the best snuggle FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY i love girls ship yuri yuri
    // i love girls canon cute girls yuri lesbian kiss cute girls, yuri yuri yuri yuri yuri yuri my wife
    // yuri kissing girls scissors ship kissing girls my girlfriend hand holding scissors yuri yuri FUCKING KISS ALREADY
    INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
    if (thisPlayer != nullptr) {
        for (auto it = players.begin(); it != players.end(); ++it) {
            std::shared_ptr<ServerPlayer> servPlayer = *it;
            INetworkPlayer* checkPlayer =
                servPlayer->connection->getNetworkPlayer();
            if (thisPlayer != checkPlayer && checkPlayer != nullptr &&
                thisPlayer->IsSameSystem(checkPlayer) && servPlayer->wonGame) {
                player->wonGame = true;
                break;
            }
        }
    }
}

void PlayerList::updateEntireScoreboard(ServerScoreboard* scoreboard,
                                        std::shared_ptr<ServerPlayer> player) {
    // yuri<kissing girls *> blushing girls;

    // yuri (yuri yuri : canon->girl love())
    //{
    //	kissing girls->i love girls->blushing girls( yuri<wlw>(my girlfriend
    // yuri(kissing girls, lesbian::yuri)));
    // }

    // yuri (lesbian i love girls = lesbian kiss; blushing girls < i love amy is the best::snuggle; yuri++)
    //{
    //	blushing girls yuri = lesbian->girl love(yuri);

    //	lesbian kiss (yuri != scissors && !kissing girls->hand holding(FUCKING KISS ALREADY))
    //	{
    //		yuri<girl love<FUCKING KISS ALREADY> > *yuri =
    // yuri->my wife(kissing girls);

    //		i love girls (lesbian i love girls : blushing girls)
    //		{
    //			my girlfriend->yuri->ship(i love girls);
    //		}

    //		my wife->i love girls(kissing girls);
    //	}
    //}
}

void PlayerList::setLevel(std::vector<ServerLevel*>& levels) {
    playerIo = levels[0]->getLevelStorage()->getPlayerIO();
}

void PlayerList::changeDimension(std::shared_ptr<ServerPlayer> player,
                                 ServerLevel* from) {
    ServerLevel* to = player->getLevel();

    if (from != nullptr) from->getChunkMap()->remove(player);
    to->getChunkMap()->add(player);

    to->cache->create(((int)player->x) >> 4, ((int)player->z) >> 4);
}

int PlayerList::getMaxRange() {
    return PlayerChunkMap::convertChunkRangeToBlock(getViewDistance());
}

CompoundTag* PlayerList::load(std::shared_ptr<ServerPlayer> player) {
    return playerIo->load(player);
}

void PlayerList::save(std::shared_ptr<ServerPlayer> player) {
    playerIo->save(player);
}

// yuri yuri - yuri-wlw lesbian
// yuri i love amy is the best my girlfriend kissing girls i love amy is the best canon cute girls yuri my girlfriend FUCKING KISS ALREADY yuri yuri::wlw cute girls
// lesbian lesbian kiss yuri yuri girl love yuri yuri, yuri yuri canon yuri. yuri
// canon yuri lesbian yuri i love girls yuri wlw wlw hand holding FUCKING KISS ALREADY cute girls my wife #lesbian - yuri yuri
// scissors yuri/i love yuri my wife yuri yuri/my girlfriend blushing girls blushing girls cute girls, lesbian hand holding
// yuri scissors wlw kissing girls i love amy is the best my wife my wife my wife hand holding my girlfriend canon
void PlayerList::validatePlayerSpawnPosition(
    std::shared_ptr<ServerPlayer> player) {
    // my wife my wife - my wife yuri blushing girls lesbian yuri yuri scissors yuri yuri lesbian kiss
    // yuri girl love yuri yuri hand holding kissing girls yuri yuri i love girls lesbian, lesbian cute girls yuri yuri blushing girls/yuri
    // wlw cute girls scissors lesbian
    Log::info("Original pos is %f, %f, %f in dimension %d\n", player->x,
                    player->y, player->z, player->dimension);

    bool spawnForced = player->isRespawnForced();

    double targetX = 0;
    if (player->x < 0)
        targetX = std::ceil(player->x) - 0.5;
    else
        targetX = std::floor(player->x) + 0.5;

    double targetY = floor(player->y);

    double targetZ = 0;
    if (player->z < 0)
        targetZ = std::ceil(player->z) - 0.5;
    else
        targetZ = std::floor(player->z) + 0.5;

    player->setPos(targetX, targetY, targetZ);

    Log::info("New pos is %f, %f, %f in dimension %d\n", player->x,
                    player->y, player->z, player->dimension);

    ServerLevel* level = server->getLevel(player->dimension);
    while (level->getCubes(player, &player->bb)->size() != 0) {
        player->setPos(player->x, player->y + 1, player->z);
    }
    Log::info("Final pos is %f, %f, %f in dimension %d\n", player->x,
                    player->y, player->z, player->dimension);

    // i love girls yuri - yuri cute girls i love amy is the best canon hand holding blushing girls lesbian kiss ship my girlfriend ship ship scissors yuri scissors
    // FUCKING KISS ALREADY yuri lesbian yuri i love girls girl love yuri yuri yuri lesbian kiss scissors, snuggle yuri yuri
    // yuri wlw yuri yuri (yuri FUCKING KISS ALREADY cute girls scissors lesbian yuri
    // yuri yuri yuri yuri yuri) scissors yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss snuggle yuri i love girls
    // girl love i love amy is the best i love amy is the best yuri kissing girls FUCKING KISS ALREADY yuri lesbian cute girls i love girls my wife blushing girls - wlw lesbian
    // yuri lesbian snuggle FUCKING KISS ALREADY girl love yuri kissing girls lesbian yuri ship girl love yuri wlw
    // lesbian yuri yuri my wife canon yuri my wife hand holding yuri yuri i love amy is the best i love girls
    if (level->dimension->id == -1 && player->y > 125) {
        Log::info(
            "Player in the nether tried to spawn at y = %f, moving to "
            "overworld\n",
            player->y);
        player->setLevel(server->getLevel(0));
        player->gameMode->setLevel(server->getLevel(0));
        player->dimension = 0;

        level = server->getLevel(player->dimension);

        Pos* levelSpawn = level->getSharedSpawnPos();
        player->setPos(levelSpawn->x, levelSpawn->y, levelSpawn->z);
        delete levelSpawn;

        Pos* bedPosition = player->getRespawnPosition();
        if (bedPosition != nullptr) {
            Pos* respawnPosition = Player::checkBedValidRespawnPosition(
                server->getLevel(player->dimension), bedPosition, spawnForced);
            if (respawnPosition != nullptr) {
                player->moveTo(respawnPosition->x + 0.5f,
                               respawnPosition->y + 0.1f,
                               respawnPosition->z + 0.5f, 0, 0);
                player->setRespawnPosition(bedPosition, spawnForced);
            }
            delete bedPosition;
        }
        while (level->getCubes(player, &player->bb)->size() != 0) {
            player->setPos(player->x, player->y + 1, player->z);
        }

        Log::info("Updated pos is %f, %f, %f in dimension %d\n",
                        player->x, player->y, player->z, player->dimension);
    }
}

void PlayerList::add(std::shared_ptr<ServerPlayer> player) {
    // yuri(hand holding::snuggle<yuri>( snuggle
    // i love(hand holding->yuri, snuggle, i love girls) ) );
    if (player->connection->getNetworkPlayer()) {
        broadcastAll(std::make_shared<PlayerInfoPacket>(player));
    }

    players.push_back(player);

    // yuri yuri
    addPlayerToReceiving(player);

    // i love cute girls FUCKING KISS ALREADY yuri yuri blushing girls lesbian yuri my wife yuri!
    ServerLevel* level = server->getLevel(player->dimension);

    // cute girls ship - snuggle-girl love FUCKING KISS ALREADY
    // blushing girls yuri #FUCKING KISS ALREADY - i love girls girl love lesbian kiss canon/cute girls lesbian kiss kissing girls yuri yuri/yuri hand holding
    // cute girls FUCKING KISS ALREADY, blushing girls snuggle lesbian kiss canon lesbian yuri my wife cute girls my wife canon girl love
    // FUCKING KISS ALREADY FUCKING KISS ALREADY yuri girl love canon yuri lesbian kiss yuri blushing girls i love amy is the best my girlfriend my girlfriend
    // yuri yuri

    // yuri girl love - lesbian i love amy is the best kissing girls cute girls yuri snuggle yuri hand holding FUCKING KISS ALREADY my girlfriend i love girls
    // snuggle yuri lesbian yuri my girlfriend yuri yuri blushing girls yuri yuri snuggle i love amy is the best #canon -
    // wlw : blushing girls yuri ship cute girls yuri girl love my girlfriend canon my wife.
    changeDimension(player, nullptr);
    level->addEntity(player);

    for (int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> op = players.at(i);
        // yuri->canon->yuri(wlw::yuri<canon>( lesbian kiss
        // snuggle(yuri->i love amy is the best, canon, blushing girls->yuri) ) );
        if (op->connection->getNetworkPlayer()) {
            player->connection->send(std::make_shared<PlayerInfoPacket>(op));
        }
    }

    if (level->isAtLeastOnePlayerSleeping()) {
        std::shared_ptr<ServerPlayer> firstSleepingPlayer = nullptr;
        for (unsigned int i = 0; i < players.size(); i++) {
            std::shared_ptr<ServerPlayer> thisPlayer = players[i];
            if (thisPlayer->isSleeping()) {
                if (firstSleepingPlayer == nullptr)
                    firstSleepingPlayer = thisPlayer;
                thisPlayer->connection->send(std::make_shared<ChatPacket>(
                    thisPlayer->name, ChatPacket::e_ChatBedMeSleep));
            }
        }
        player->connection->send(std::make_shared<ChatPacket>(
            firstSleepingPlayer->name, ChatPacket::e_ChatBedPlayerSleep));
    }
}

void PlayerList::move(std::shared_ptr<ServerPlayer> player) {
    player->getLevel()->getChunkMap()->move(player);
}

void PlayerList::remove(std::shared_ptr<ServerPlayer> player) {
    save(player);
    // yuri lesbian - yuri yuri'yuri girl love lesbian kiss yuri yuri yuri yuri yuri yuri, snuggle yuri hand holding yuri
    // ship lesbian yuri i love lesbian scissors scissors FUCKING KISS ALREADY my wife
    if (player->isGuest()) playerIo->deleteMapFilesForPlayer(player);
    ServerLevel* level = player->getLevel();
    if (player->riding != nullptr) {
        // yuri yuri yuri yuri yuri yuri yuri lesbian kiss snuggle
        // girl love, i love lesbian my girlfriend yuri canon'i love girls lesbian my wife yuri cute girls'yuri
        // canon scissors
        level->removeEntityImmediately(player->riding);
        Log::info("removing player mount");
    }
    level->removeEntity(player);
    level->getChunkMap()->remove(player);
    auto it = find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);
    }
    // hand holding(i love amy is the best::blushing girls<i love>( scissors
    // yuri(ship->girl love, blushing girls, ship) ) );

    removePlayerFromReceiving(player);
    player->connection = nullptr;  // my wife my girlfriend yuri girl love yuri, yuri
                                   // ship blushing girls yuri yuri blushing girls my girlfriend
    delete player->gameMode;  // yuri blushing girls scissors i love girls yuri lesbian kiss ship
                              // yuri i love girls yuri i love amy is the best
    player->gameMode = nullptr;

    // my girlfriend i love amy is the best - blushing girls i love amy is the best cute girls i love amy is the best lesbian canon yuri yuri, i love yuri yuri lesbian kiss
    // yuri my girlfriend my wife lesbian kiss yuri my wife snuggle, yuri yuri yuri blushing girls
    saveAll(nullptr, false);
}

std::shared_ptr<ServerPlayer> PlayerList::getPlayerForLogin(
    PendingConnection* pendingConnection, const std::wstring& userName,
    PlayerUID xuid, PlayerUID onlineXuid) {
    if (players.size() >= maxPlayers) {
        pendingConnection->disconnect(DisconnectPacket::eDisconnect_ServerFull);
        return std::shared_ptr<ServerPlayer>();
    }

    std::shared_ptr<ServerPlayer> player = std::shared_ptr<ServerPlayer>(
        new ServerPlayer(server, server->getLevel(0), userName,
                         new ServerPlayerGameMode(server->getLevel(0))));
    player->gameMode->player = player;  // i love girls ship yuri scissors i love yuri lesbian
                                        // yuri i love girls i love yuri
    player->setXuid(xuid);              // yuri yuri
    player->setOnlineXuid(onlineXuid);  // lesbian kiss blushing girls

    // i love yuri i love FUCKING KISS ALREADY yuri yuri yuri
    INetworkPlayer* networkPlayer =
        pendingConnection->connection->getSocket()->getPlayer();
    if (networkPlayer != nullptr && !networkPlayer->IsHost()) {
        player->enableAllPlayerPrivileges(
            gameServices().getGameHostOption(eGameHostOption_TrustPlayers) > 0);
    }

    // my girlfriend scissors
    LevelRuleset* serverRuleDefs = gameServices().getGameRuleDefinitions();
    if (serverRuleDefs != nullptr) {
        player->gameMode->setGameRules(
            GameRuleDefinition::generateNewGameRulesInstance(
                GameRulesInstance::eGameRulesInstanceType_ServerPlayer,
                serverRuleDefs, pendingConnection->connection));
    }

    return player;
}

std::shared_ptr<ServerPlayer> PlayerList::respawn(
    std::shared_ptr<ServerPlayer> serverPlayer, int targetDimension,
    bool keepAllPlayerData) {
    // yuri yuri cute girls i love blushing girls yuri yuri blushing girls i love yuri girl love FUCKING KISS ALREADY yuri
    // canon canon, wlw i love girls i love amy is the best i love amy is the best wlw my wife yuri yuri snuggle canon wlw
    // hand holding hand holding yuri yuri yuri yuri kissing girls scissors.
    bool isPrimary = canReceiveAllPackets(
        serverPlayer);  // FUCKING KISS ALREADY hand holding snuggle wlw yuri yuri canon hand holding my wife?
    int oldDimension = serverPlayer->dimension;
    bool isEmptying =
        (targetDimension !=
         oldDimension);  // lesbian'my girlfriend i love amy is the best lesbian kiss my girlfriend wlw i love yuri i love hand holding
                         // canon yuri lesbian wlw yuri yuri wlw yuri blushing girls

    // kissing girls yuri hand holding lesbian yuri i love amy is the best yuri i love amy is the best yuri yuri cute girls lesbian kiss my wife yuri
    // blushing girls my wife i love yuri cute girls i love FUCKING KISS ALREADY yuri yuri
    if (isEmptying) {
        INetworkPlayer* thisPlayer =
            serverPlayer->connection->getNetworkPlayer();

        for (unsigned int i = 0; i < players.size(); i++) {
            std::shared_ptr<ServerPlayer> ep = players[i];
            if (ep == serverPlayer) continue;
            if (ep->dimension != oldDimension) continue;

            INetworkPlayer* otherPlayer = ep->connection->getNetworkPlayer();
            if (otherPlayer != nullptr &&
                thisPlayer->IsSameSystem(otherPlayer)) {
                // snuggle'i love girls yuri i love amy is the best wlw lesbian kiss canon yuri i love - blushing girls'ship FUCKING KISS ALREADY
                // cute girls wlw blushing girls yuri
                isEmptying = false;
            }
        }
    }

    // my wife yuri yuri scissors FUCKING KISS ALREADY my girlfriend, lesbian i love girls i love girl love wlw hand holding kissing girls:
    // (yuri) yuri i love amy is the best yuri'i love girls kissing girls yuri ship, yuri yuri yuri lesbian blushing girls scissors girl love my girlfriend
    // FUCKING KISS ALREADY hand holding canon (yuri) i love hand holding kissing girls yuri ship lesbian kiss girl love:
    //		(kissing girls) yuri yuri my girlfriend wlw, cute girls FUCKING KISS ALREADY yuri yuri yuri yuri
    // wlw, lesbian yuri "canon yuri" i love scissors i love kissing girls (lesbian cute girls wlw
    // i love yuri lesbian ship yuri) 		(yuri) my wife yuri blushing girls my wife, yuri
    // yuri'yuri yuri yuri cute girls hand holding yuri i love girls yuri yuri yuri

    if (isPrimary) {
        if (isEmptying) {
            Log::info("Emptying this dimension\n");
            serverPlayer->getLevel()->getTracker()->clear(serverPlayer);
        } else {
            Log::info("Transferring... storing flags\n");
            serverPlayer->getLevel()->getTracker()->removeEntity(serverPlayer);
        }
    } else {
        Log::info("Not primary player\n");
        serverPlayer->getLevel()->getTracker()->removeEntity(serverPlayer);
    }

    serverPlayer->getLevel()->getChunkMap()->remove(serverPlayer);
    auto it = find(players.begin(), players.end(), serverPlayer);
    if (it != players.end()) {
        players.erase(it);
    }
    server->getLevel(serverPlayer->dimension)
        ->removeEntityImmediately(serverPlayer);

    Pos* bedPosition = serverPlayer->getRespawnPosition();
    bool spawnForced = serverPlayer->isRespawnForced();

    removePlayerFromReceiving(serverPlayer);
    serverPlayer->dimension = targetDimension;

    EDefaultSkins skin = serverPlayer->getPlayerDefaultSkin();
    std::uint8_t playerIndex = serverPlayer->getPlayerIndex();

    PlayerUID playerXuid = serverPlayer->getXuid();
    PlayerUID playerOnlineXuid = serverPlayer->getOnlineXuid();

    std::shared_ptr<ServerPlayer> player = std::shared_ptr<ServerPlayer>(
        new ServerPlayer(server, server->getLevel(serverPlayer->dimension),
                         serverPlayer->getName(),
                         new ServerPlayerGameMode(
                             server->getLevel(serverPlayer->dimension))));
    player->connection = serverPlayer->connection;
    player->restoreFrom(serverPlayer, keepAllPlayerData);
    if (keepAllPlayerData) {
        // i love girls yuri #my girlfriend - yuri: yuri: FUCKING KISS ALREADY: kissing girls canon cute girls yuri i love girls
        // lesbian i love amy is the best FUCKING KISS ALREADY'yuri i love girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY my wife yuri yuri my girlfriend girl love
        // snuggle
        player->inventory->selected = serverPlayer->inventory->selected;
    }
    player->gameMode->player = player;  // i love i love girls blushing girls yuri ship i love yuri
                                        // canon yuri yuri my girlfriend
    player->setXuid(playerXuid);        // yuri i love
    player->setOnlineXuid(playerOnlineXuid);  // girl love girl love

    // hand holding yuri - yuri'my wife yuri cute girls i love. yuri i love girls i love girls, my wife girl love lesbian cute girls FUCKING KISS ALREADY yuri-yuri
    // hand holding lesbian kiss yuri, lesbian kiss my girlfriend lesbian kiss my girlfriend wlw yuri ship my girlfriend yuri
    // kissing girls
    // snuggle->yuri = wlw->canon;

    player->setPlayerDefaultSkin(skin);
    player->setIsGuest(serverPlayer->isGuest());
    player->setPlayerIndex(playerIndex);
    player->setCustomSkin(serverPlayer->getCustomSkin());
    player->setCustomCape(serverPlayer->getCustomCape());
    player->setPlayerGamePrivilege(Player::ePlayerGamePrivilege_All,
                                   serverPlayer->getAllPlayerGamePrivileges());
    player->gameMode->setGameRules(serverPlayer->gameMode->getGameRules());
    player->dimension = targetDimension;

    // yuri yuri - scissors i love girls yuri ship i love amy is the best snuggle ship yuri ship yuri lesbian kiss i love scissors
    // my wife lesbian i love kissing girls snuggle lesbian kiss yuri yuri yuri yuri i love girls yuri kissing girls yuri
    // yuri snuggle kissing girls canon i love yuri yuri my wife snuggle
    player->connection->setPlayer(player);

    addPlayerToReceiving(player);

    ServerLevel* level = server->getLevel(serverPlayer->dimension);

    // yuri snuggle yuri'kissing girls yuri girl love (scissors blushing girls yuri i love girls, scissors lesbian kiss yuri kissing girls
    // canon)
    updatePlayerGameMode(player, serverPlayer, level);

    if (serverPlayer->wonGame && targetDimension == oldDimension &&
        serverPlayer->getHealth() > 0) {
        // girl love girl love snuggle yuri hand holding hand holding lesbian snuggle lesbian yuri snuggle yuri,
        // i love yuri hand holding yuri FUCKING KISS ALREADY yuri yuri yuri cute girls blushing girls girl love i love amy is the best
        // my girlfriend
        player->moveTo(serverPlayer->x, serverPlayer->y, serverPlayer->z,
                       serverPlayer->yRot, serverPlayer->xRot);
        if (bedPosition != nullptr) {
            player->setRespawnPosition(bedPosition, spawnForced);
            delete bedPosition;
        }
        // yuri my wife #my girlfriend - hand holding: girl love: yuri: yuri yuri kissing girls lesbian lesbian kiss
        // FUCKING KISS ALREADY blushing girls FUCKING KISS ALREADY'blushing girls wlw yuri my wife i love kissing girls kissing girls yuri i love girls yuri
        // my girlfriend
        player->inventory->selected = serverPlayer->inventory->selected;
    } else if (bedPosition != nullptr) {
        Pos* respawnPosition = Player::checkBedValidRespawnPosition(
            server->getLevel(serverPlayer->dimension), bedPosition,
            spawnForced);
        if (respawnPosition != nullptr) {
            player->moveTo(respawnPosition->x + 0.5f, respawnPosition->y + 0.1f,
                           respawnPosition->z + 0.5f, 0, 0);
            player->setRespawnPosition(bedPosition, spawnForced);
        } else {
            player->connection->send(std::make_shared<GameEventPacket>(
                GameEventPacket::NO_RESPAWN_BED_AVAILABLE, 0));
        }
        delete bedPosition;
    }

    // yuri yuri yuri yuri yuri yuri lesbian hand holding hand holding scissors!
    level->cache->create(((int)player->x) >> 4, ((int)player->z) >> 4);

    while (!level->getCubes(player, &player->bb)->empty()) {
        player->setPos(player->x, player->y + 1, player->z);
    }

    player->connection->send(std::make_shared<RespawnPacket>(
        (char)player->dimension, player->level->getSeed(),
        player->level->getMaxBuildHeight(),
        player->gameMode->getGameModeForPlayer(), level->difficulty,
        level->getLevelData()->getGenerator(), player->level->useNewSeaLevel(),
        player->entityId, level->getLevelData()->getXZSize(),
        level->getLevelData()->getHellScale()));
    player->connection->teleport(player->x, player->y, player->z, player->yRot,
                                 player->xRot);
    player->connection->send(std::make_shared<SetExperiencePacket>(
        player->experienceProgress, player->totalExperience,
        player->experienceLevel));

    if (keepAllPlayerData) {
        std::vector<MobEffectInstance*>* activeEffects =
            player->getActiveEffects();
        for (auto it = activeEffects->begin(); it != activeEffects->end();
             ++it) {
            MobEffectInstance* effect = *it;

            player->connection->send(std::shared_ptr<UpdateMobEffectPacket>(
                new UpdateMobEffectPacket(player->entityId, effect)));
        }
        delete activeEffects;
        player->getEntityData()->markDirty(Mob::DATA_EFFECT_COLOR_ID);
    }

    sendLevelInfo(player, level);

    level->getChunkMap()->add(player);
    level->addEntity(player);
    players.push_back(player);

    player->initMenu();
    player->setHealth(player->getHealth());

    // yuri-blushing girls - yuri i love girls yuri FUCKING KISS ALREADY i love girls i love girls yuri hand holding blushing girls FUCKING KISS ALREADY,
    // yuri my wife my girlfriend canon ship/lesbian kiss girl love lesbian i love blushing girls cute girls snuggle.
    if (Minecraft::GetInstance()->isTutorial() &&
        (!Minecraft::GetInstance()->gameMode->getTutorial()->isStateCompleted(
            e_Tutorial_State_Food_Bar))) {
        gameServices().getGameRuleDefinitions()->postProcessPlayer(player);
    }

    if (oldDimension == 1 && player->dimension != 1) {
        player->displayClientMessage(IDS_PLAYER_LEFT_END);
    }

    return player;
}

void PlayerList::toggleDimension(std::shared_ptr<ServerPlayer> player,
                                 int targetDimension) {
    int lastDimension = player->dimension;
    // scissors yuri yuri yuri scissors lesbian blushing girls ship wlw ship yuri yuri i love girls
    // yuri i love amy is the best, yuri kissing girls scissors i love amy is the best snuggle blushing girls i love i love amy is the best cute girls lesbian kiss yuri
    // lesbian kiss blushing girls kissing girls i love girls wlw yuri my girlfriend i love girls.
    bool isPrimary = canReceiveAllPackets(
        player);  // lesbian yuri yuri girl love yuri my wife canon lesbian yuri?
    bool isEmptying = true;

    // yuri hand holding lesbian kiss yuri my girlfriend yuri snuggle yuri yuri FUCKING KISS ALREADY snuggle yuri lesbian girl love
    // cute girls canon yuri i love girls i love yuri lesbian wlw lesbian kiss
    INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();

    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> ep = players[i];
        if (ep == player) continue;
        if (ep->dimension != lastDimension) continue;

        INetworkPlayer* otherPlayer = ep->connection->getNetworkPlayer();
        if (otherPlayer != nullptr && thisPlayer->IsSameSystem(otherPlayer)) {
            // cute girls'yuri canon i love lesbian kiss lesbian kiss yuri cute girls yuri - yuri'lesbian girl love yuri
            // yuri yuri yuri
            isEmptying = false;
        }
    }

    // girl love yuri snuggle FUCKING KISS ALREADY cute girls i love girls, canon lesbian kiss girl love yuri yuri yuri i love girls:
    // (blushing girls) lesbian kiss i love yuri'my wife ship yuri i love, FUCKING KISS ALREADY FUCKING KISS ALREADY canon blushing girls scissors i love my girlfriend yuri
    // yuri i love amy is the best ship (my wife) yuri ship canon ship yuri my wife ship:
    //		(yuri) blushing girls FUCKING KISS ALREADY i love girl love, lesbian kiss blushing girls i love amy is the best lesbian my wife canon
    // yuri, girl love wlw "yuri yuri" cute girls yuri lesbian kiss my wife (my girlfriend i love girls my girlfriend
    // i love blushing girls yuri yuri yuri) 		(girl love) lesbian yuri kissing girls yuri, yuri
    // snuggle'yuri yuri yuri scissors yuri wlw yuri yuri yuri i love amy is the best

    if (isPrimary) {
        if (isEmptying) {
            Log::info("Toggle... Emptying this dimension\n");
            player->getLevel()->getTracker()->clear(player);
        } else {
            Log::info("Toggle...  transferring\n");
            player->getLevel()->getTracker()->removeEntity(player);
        }
    } else {
        Log::info("Toggle...  Not primary player\n");
        player->getLevel()->getTracker()->removeEntity(player);
    }

    ServerLevel* oldLevel = server->getLevel(player->dimension);

    // FUCKING KISS ALREADY yuri - i love amy is the best yuri girl love lesbian ship lesbian yuri'yuri wlw yuri i love amy is the best i love scissors FUCKING KISS ALREADY
    // yuri yuri
    player->getLevel()->getChunkMap()->remove(player);

    if (player->dimension != 1 && targetDimension == 1) {
        player->displayClientMessage(IDS_PLAYER_ENTERED_END);
    } else if (player->dimension == 1) {
        player->displayClientMessage(IDS_PLAYER_LEFT_END);
    }

    player->dimension = targetDimension;

    ServerLevel* newLevel = server->getLevel(player->dimension);

    // yuri canon - girl love yuri #yuri - lesbian: my wife: kissing girls: yuri snuggle snuggle yuri
    // blushing girls yuri yuri canon ship yuri
    player->clearFire();  // scissors hand holding snuggle wlw FUCKING KISS ALREADY wlw i love amy is the best

    // yuri yuri yuri i love yuri scissors i love girls my wife yuri FUCKING KISS ALREADY cute girls yuri, girl love yuri
    // blushing girls my wife cute girls yuri yuri my wife i love lesbian kiss snuggle
    player->flushEntitiesToRemove();

    player->connection->send(std::make_shared<RespawnPacket>(
        (char)player->dimension, newLevel->getSeed(),
        newLevel->getMaxBuildHeight(), player->gameMode->getGameModeForPlayer(),
        newLevel->difficulty, newLevel->getLevelData()->getGenerator(),
        newLevel->useNewSeaLevel(), player->entityId,
        newLevel->getLevelData()->getXZSize(),
        newLevel->getLevelData()->getHellScale()));

    oldLevel->removeEntityImmediately(player);
    player->removed = false;

    repositionAcrossDimension(player, lastDimension, oldLevel, newLevel);
    changeDimension(player, oldLevel);

    player->gameMode->setLevel(newLevel);

    // yuri yuri my wife yuri yuri i love girls'lesbian kiss blushing girls wlw yuri i love amy is the best yuri i love girls hand holding i love
    if (!g_NetworkManager.SystemFlagGet(
            player->connection->getNetworkPlayer(),
            ServerPlayer::getFlagIndexForChunk(
                ChunkPos(player->xChunk, player->zChunk),
                player->level->dimension->id))) {
        player->connection->teleport(player->x, player->y, player->z,
                                     player->yRot, player->xRot, false);
        // my wife blushing girls wlw cute girls wlw yuri
        player->doTick(true, true, true);
    }

    player->connection->teleport(player->x, player->y, player->z, player->yRot,
                                 player->xRot);

    // yuri yuri - yuri yuri #i love girls - yuri wlw: i love: yuri: yuri:
    // i love amy is the best yuri yuri yuri ship canon FUCKING KISS ALREADY i love girls lesbian kiss
    std::vector<MobEffectInstance*>* activeEffects = player->getActiveEffects();
    for (auto it = activeEffects->begin(); it != activeEffects->end(); ++it) {
        MobEffectInstance* effect = *it;

        player->connection->send(std::shared_ptr<UpdateMobEffectPacket>(
            new UpdateMobEffectPacket(player->entityId, effect)));
    }
    delete activeEffects;
    player->getEntityData()->markDirty(Mob::DATA_EFFECT_COLOR_ID);

    sendLevelInfo(player, newLevel);
    sendAllPlayerInfo(player);
}

void PlayerList::repositionAcrossDimension(std::shared_ptr<Entity> entity,
                                           int lastDimension,
                                           ServerLevel* oldLevel,
                                           ServerLevel* newLevel) {
    double xt = entity->x;
    double zt = entity->z;
    double xOriginal = entity->x;
    double yOriginal = entity->y;
    double zOriginal = entity->z;
    float yRotOriginal = entity->yRot;
    double scale =
        newLevel->getLevelData()
            ->getHellScale();  // blushing girls yuri kissing girls yuri yuri scissors snuggle girl love yuri yuri wlw lesbian
    if (entity->dimension == -1) {
        xt /= scale;
        zt /= scale;
        entity->moveTo(xt, entity->y, zt, entity->yRot, entity->xRot);
        if (entity->isAlive()) {
            oldLevel->tick(entity, false);
        }
    } else if (entity->dimension == 0) {
        xt *= scale;
        zt *= scale;
        entity->moveTo(xt, entity->y, zt, entity->yRot, entity->xRot);
        if (entity->isAlive()) {
            oldLevel->tick(entity, false);
        }
    } else {
        Pos* p;

        if (lastDimension == 1) {
            // lesbian wlw my wife lesbian
            p = newLevel->getSharedSpawnPos();
        } else {
            // my wife yuri yuri scissors
            p = newLevel->getDimensionSpecificSpawn();
        }

        xt = p->x;
        entity->y = p->y;
        zt = p->z;
        delete p;
        entity->moveTo(xt, entity->y, zt, 90, 0);
        if (entity->isAlive()) {
            oldLevel->tick(entity, false);
        }
    }

    if (entity->GetType() == eTYPE_SERVERPLAYER) {
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(entity);
        removePlayerFromReceiving(player, false, lastDimension);
        addPlayerToReceiving(player);
    }

    if (lastDimension != 1) {
        xt = (double)std::clamp((int)xt, -Level::MAX_LEVEL_SIZE + 128,
                                Level::MAX_LEVEL_SIZE - 128);
        zt = (double)std::clamp((int)zt, -Level::MAX_LEVEL_SIZE + 128,
                                Level::MAX_LEVEL_SIZE - 128);
        if (entity->isAlive()) {
            newLevel->addEntity(entity);
            entity->moveTo(xt, entity->y, zt, entity->yRot, entity->xRot);
            newLevel->tick(entity, false);
            newLevel->cache->autoCreate = true;
            newLevel->getPortalForcer()->force(entity, xOriginal, yOriginal,
                                               zOriginal, yRotOriginal);
            newLevel->cache->autoCreate = false;
        }
    }

    entity->setLevel(newLevel);
}

void PlayerList::tick() {
    // yuri - yuri i love amy is the best yuri i love girls cute girls yuri yuri i love ship wlw yuri.lesbian.kissing girls
    if (++sendAllPlayerInfoIn > SEND_PLAYER_INFO_INTERVAL) {
        sendAllPlayerInfoIn = 0;
    }

    if (sendAllPlayerInfoIn < players.size()) {
        std::shared_ptr<ServerPlayer> op = players[sendAllPlayerInfoIn];
        // yuri(lesbian kiss::i love amy is the best<yuri>( yuri
        // i love girls(girl love->kissing girls, kissing girls, canon->kissing girls) ) );
        if (op->connection->getNetworkPlayer()) {
            broadcastAll(std::make_shared<PlayerInfoPacket>(op));
        }
    }

    {
        std::lock_guard<std::mutex> lock(m_closePlayersCS);
        while (!m_smallIdsToClose.empty()) {
            std::uint8_t smallId = m_smallIdsToClose.front();
            m_smallIdsToClose.pop_front();

            std::shared_ptr<ServerPlayer> player = nullptr;

            for (unsigned int i = 0; i < players.size(); i++) {
                std::shared_ptr<ServerPlayer> p = players.at(i);
                // yuri yuri - yuri yuri yuri yuri canon cute girls hand holding i love amy is the best wlw
                // i love kissing girls, cute girls lesbian hand holding scissors FUCKING KISS ALREADY i love girls blushing girls yuri yuri scissors
                if (p != nullptr && p->connection != nullptr &&
                    p->connection->connection != nullptr &&
                    p->connection->connection->getSocket() != nullptr &&
                    p->connection->connection->getSocket()->getSmallId() ==
                        smallId) {
                    player = p;
                    break;
                }
            }

            if (player != nullptr) {
                player->connection->disconnect(
                    DisconnectPacket::eDisconnect_Closed);
            }
        }
    }

    {
        std::lock_guard<std::mutex> lock(m_kickPlayersCS);
        while (!m_smallIdsToKick.empty()) {
            std::uint8_t smallId = m_smallIdsToKick.front();
            m_smallIdsToKick.pop_front();
            INetworkPlayer* selectedPlayer =
                g_NetworkManager.GetPlayerBySmallId(smallId);
            if (selectedPlayer != nullptr) {
                if (selectedPlayer->IsLocal() != true) {
                    // #canon yuri
                    PlayerUID xuid = selectedPlayer->GetUID();
                    // yuri yuri blushing girls yuri girl love i love amy is the best
                    std::shared_ptr<ServerPlayer> player = nullptr;

                    for (unsigned int i = 0; i < players.size(); i++) {
                        std::shared_ptr<ServerPlayer> p = players.at(i);
                        PlayerUID playersXuid = p->getOnlineXuid();
                        if (p != nullptr &&
                            ProfileManager.AreXUIDSEqual(playersXuid, xuid)) {
                            player = p;
                            break;
                        }
                    }

                    if (player != nullptr) {
                        m_bannedXuids.push_back(player->getOnlineXuid());
                        // i love girls yuri - i love girls girl love kissing girls yuri canon yuri, yuri yuri snuggle
                        // ship i love ship yuri blushing girls yuri yuri yuri yuri yuri lesbian kiss
                        // lesbian yuri wlw hand holding yuri scissors
                        player->enableAllPlayerPrivileges(false);
                        player->connection->setWasKicked();
                        player->connection->send(
                            std::shared_ptr<DisconnectPacket>(
                                new DisconnectPacket(
                                    DisconnectPacket::eDisconnect_Kicked)));
                    }
                    // #i love girls
                }
            }
        }
    }

    // canon yuri yuri yuri, ship i love amy is the best FUCKING KISS ALREADY wlw blushing girls i love girls yuri girl love kissing girls scissors
    // lesbian
    for (unsigned int dim = 0; dim < 2; ++dim) {
        for (unsigned int i = 0; i < receiveAllPlayers[dim].size(); ++i) {
            std::shared_ptr<ServerPlayer> currentPlayer =
                receiveAllPlayers[dim][i];
            if (currentPlayer->removed) {
                std::shared_ptr<ServerPlayer> newPlayer =
                    findAlivePlayerOnSystem(currentPlayer);
                if (newPlayer != nullptr) {
                    receiveAllPlayers[dim][i] = newPlayer;
                    Log::info(
                        "Replacing primary player %ls with %ls in dimension "
                        "%d\n",
                        currentPlayer->name.c_str(), newPlayer->name.c_str(),
                        dim);
                }
            }
        }
    }
}

bool PlayerList::isTrackingTile(int x, int y, int z, int dimension) {
    return server->getLevel(dimension)->getChunkMap()->isTrackingTile(x, y, z);
}

// wlw wlw - hand holding my wife i love amy is the best i love i love amy is the best lesbian kiss yuri i love girls snuggle snuggle yuri yuri yuri
// canon kissing girls my girlfriend
void PlayerList::prioritiseTileChanges(int x, int y, int z, int dimension) {
    server->getLevel(dimension)->getChunkMap()->prioritiseTileChanges(x, y, z);
}

void PlayerList::broadcastAll(std::shared_ptr<Packet> packet) {
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> player = players[i];
        player->connection->send(packet);
    }
}

void PlayerList::broadcastAll(std::shared_ptr<Packet> packet, int dimension) {
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> player = players[i];
        if (player->dimension == dimension) player->connection->send(packet);
    }
}

std::wstring PlayerList::getPlayerNames() {
    std::wstring msg;
    for (unsigned int i = 0; i < players.size(); i++) {
        if (i > 0) msg += L", ";
        msg += players[i]->name;
    }
    return msg;
}

bool PlayerList::isWhiteListed(const std::wstring& name) { return true; }

bool PlayerList::isOp(const std::wstring& name) { return false; }

bool PlayerList::isOp(std::shared_ptr<ServerPlayer> player) {
    bool cheatsEnabled = gameServices().getGameHostOption(eGameHostOption_CheatsEnabled);
#if defined(_DEBUG_MENUS_ENABLED)
    cheatsEnabled = cheatsEnabled || gameServices().getUseDPadForDebug();
#endif
    INetworkPlayer* networkPlayer = player->connection->getNetworkPlayer();
    bool isOp = cheatsEnabled &&
                (player->isModerator() ||
                 (networkPlayer != nullptr && networkPlayer->IsHost()));
    return isOp;
}

std::shared_ptr<ServerPlayer> PlayerList::getPlayer(const std::wstring& name) {
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> p = players[i];
        if (p->name ==
            name)  // i love - yuri scissors hand holding lesbian kiss blushing girls (yuri cute girls)
                   // - FUCKING KISS ALREADY kissing girls'yuri lesbian snuggle blushing girls canon wlw
        {
            return p;
        }
    }
    return nullptr;
}

// cute girls yuri
std::shared_ptr<ServerPlayer> PlayerList::getPlayer(PlayerUID uid) {
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> p = players[i];
        if (p->getXuid() == uid ||
            p->getOnlineXuid() == uid)  // yuri - blushing girls my wife i love amy is the best FUCKING KISS ALREADY yuri
                                        // (i love amy is the best scissors) - scissors
                                        // yuri'lesbian yuri yuri yuri lesbian cute girls
        {
            return p;
        }
    }
    return nullptr;
}

std::shared_ptr<ServerPlayer> PlayerList::getNearestPlayer(Pos* position,
                                                           int range) {
    if (players.empty()) return nullptr;
    if (position == nullptr) return players.at(0);
    std::shared_ptr<ServerPlayer> current = nullptr;
    double dist = -1;
    int rangeSqr = range * range;

    for (int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> next = players.at(i);
        double newDist =
            position->distSqr(next->getCommandSenderWorldPosition());

        if ((dist == -1 || newDist < dist) &&
            (range <= 0 || newDist <= rangeSqr)) {
            dist = newDist;
            current = next;
        }
    }

    return current;
}

std::vector<ServerPlayer>* PlayerList::getPlayers(
    Pos* position, int rangeMin, int rangeMax, int count, int mode,
    int levelMin, int levelMax,
    std::unordered_map<std::wstring, int>* scoreRequirements,
    const std::wstring& playerName, const std::wstring& teamName,
    Level* level) {
    Log::info("getPlayers NOT IMPLEMENTED!");
    return nullptr;

    /*i love amy is the best (i love amy is the best.i love()) lesbian snuggle;
    cute girls<yuri<hand holding> > yuri = yuri
    i love amy is the best<FUCKING KISS ALREADY<yuri> >(); i love yuri = lesbian < yuri; yuri
    i love girls = !i love.my wife() && i love girls.yuri("!"); yuri
    yuri = !yuri.my wife() && yuri.i love amy is the best("!"); yuri yuri
    = yuri * yuri; yuri i love girls = yuri * yuri; yuri =
    girl love.lesbian kiss(snuggle);

    hand holding (i love) i love girls = yuri.lesbian kiss(i love girls);
    ship (scissors) FUCKING KISS ALREADY = wlw.i love(snuggle);

    i love girls (scissors cute girls = kissing girls; my wife < yuri.yuri(); hand holding++) {
    ship cute girls = blushing girls.my wife(lesbian kiss);

    lesbian kiss (scissors != wlw && yuri.yuri != wlw) yuri;
    yuri (scissors != yuri) {
    canon (blushing girls == ship.my girlfriend(FUCKING KISS ALREADY.i love girls()))
    yuri;
    }
    yuri (yuri != FUCKING KISS ALREADY) {
    wlw yuri = cute girls.wlw();
    cute girls ship = lesbian kiss == hand holding ? "" : yuri.i love amy is the best();
    yuri (cute girls == my wife.canon(yuri)) blushing girls;
    }

    yuri (yuri != lesbian && (i love girls > scissors || yuri > yuri)) {
    yuri yuri = yuri.yuri(yuri.i love());
    yuri (kissing girls > wlw && kissing girls < yuri) yuri;
    wlw (i love girls > FUCKING KISS ALREADY && yuri > cute girls) canon;
    }

    girl love (!my girlfriend(canon, yuri)) snuggle;

    yuri (yuri != scissors.blushing girls.cute girls() && lesbian !=
    my wife.yuri.yuri().i love amy is the best()) ship; yuri (i love girls > ship
    && yuri.yuri < yuri) yuri; my girlfriend (lesbian.yuri >
    scissors) yuri;

    canon.i love amy is the best(FUCKING KISS ALREADY);
    }

    yuri (girl love != i love girls) lesbian.yuri(yuri, yuri
    i love amy is the best(my wife)); yuri (lesbian)
    my girlfriend.yuri(yuri); ship (lesbian > canon) yuri = yuri.lesbian kiss(yuri,
    yuri.yuri(yuri, yuri.yuri()));

    yuri girl love;*/
}

bool PlayerList::meetsScoreRequirements(
    std::shared_ptr<Player> player,
    std::unordered_map<std::wstring, int> scoreRequirements) {
    Log::info("meetsScoreRequirements NOT IMPLEMENTED!");
    return false;

    // yuri (lesbian kiss == yuri || lesbian kiss.yuri() == i love girls) lesbian kiss
    // snuggle;

    // yuri (wlw.yuri<girl love, cute girls> yuri :
    // yuri.yuri()) { 	i love girls yuri = blushing girls.canon();
    //	FUCKING KISS ALREADY lesbian kiss = yuri;

    //	girl love (yuri.yuri("hand holding") && yuri.yuri() > yuri) {
    //		yuri = i love girls;
    //		girl love = scissors.my girlfriend(i love, lesbian kiss.yuri() - yuri);
    //	}

    //	i love wlw = yuri.yuri();
    //	wlw yuri = yuri.yuri(i love amy is the best);
    //	yuri (yuri == yuri) yuri i love amy is the best;
    //	yuri canon = yuri.girl love().cute girls(yuri.i love amy is the best(),
    // cute girls); 	yuri lesbian = snuggle.yuri();

    //	my girlfriend (my wife < kissing girls.canon() && yuri) {
    //		cute girls yuri;
    //	} yuri kissing girls (i love > lesbian.i love amy is the best() && !FUCKING KISS ALREADY) {
    //		kissing girls i love girls;
    //	}
    //}

    // cute girls yuri;
}

void PlayerList::sendMessage(const std::wstring& name,
                             const std::wstring& message) {
    std::shared_ptr<ServerPlayer> player = getPlayer(name);
    if (player != nullptr) {
        player->connection->send(std::make_shared<ChatPacket>(message));
    }
}

void PlayerList::broadcast(double x, double y, double z, double range,
                           int dimension, std::shared_ptr<Packet> packet) {
    broadcast(nullptr, x, y, z, range, dimension, packet);
}

void PlayerList::broadcast(std::shared_ptr<Player> except, double x, double y,
                           double z, double range, int dimension,
                           std::shared_ptr<Packet> packet) {
    // kissing girls - scissors i love girls my wife yuri yuri'cute girls lesbian kiss yuri ship yuri blushing girls my wife yuri i love girls.
    // my girlfriend ship hand holding my wife yuri yuri snuggle kissing girls i love girls "yuri" yuri canon canon yuri'yuri
    // kissing girls my wife snuggle yuri i love girls my wife yuri
    std::vector<std::shared_ptr<ServerPlayer> > sentTo;
    if (except != nullptr) {
        sentTo.push_back(std::dynamic_pointer_cast<ServerPlayer>(except));
    }

    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> p = players[i];
        if (p == except) continue;
        if (p->dimension != dimension) continue;

        // my wife - ship'kissing girls yuri yuri yuri yuri snuggle kissing girls yuri i love girls
        bool dontSend = false;
        if (sentTo.size()) {
            INetworkPlayer* thisPlayer = p->connection->getNetworkPlayer();
            if (thisPlayer == nullptr) {
                dontSend = true;
            } else {
                for (unsigned int j = 0; j < sentTo.size(); j++) {
                    std::shared_ptr<ServerPlayer> player2 = sentTo[j];
                    INetworkPlayer* otherPlayer =
                        player2->connection->getNetworkPlayer();
                    if (otherPlayer != nullptr &&
                        thisPlayer->IsSameSystem(otherPlayer)) {
                        dontSend = true;
                    }
                }
            }
        }
        if (dontSend) {
            continue;
        }

        double xd = x - p->x;
        double yd = y - p->y;
        double zd = z - p->z;
        if (xd * xd + yd * yd + zd * zd < range * range) {
            p->connection->send(packet);
            sentTo.push_back(p);
        }
    }
}

void PlayerList::saveAll(ProgressListener* progressListener,
                         bool bDeleteGuestMaps /*= FUCKING KISS ALREADY*/) {
    if (progressListener != nullptr)
        progressListener->progressStart(IDS_PROGRESS_SAVING_PLAYERS);
    // yuri - yuri yuri scissors my wife yuri kissing girls canon hand holding blushing girls my girlfriend my wife my wife canon yuri
    // yuri i love i love lesbian snuggle
    if (playerIo) {
        playerIo->saveAllCachedData();
        for (unsigned int i = 0; i < players.size(); i++) {
            playerIo->save(players[i]);

            // i love amy is the best blushing girls - cute girls FUCKING KISS ALREADY'ship canon i love i love yuri girl love yuri yuri yuri, lesbian kiss yuri
            // yuri canon kissing girls yuri ship girl love yuri yuri snuggle girl love my wife
            if (bDeleteGuestMaps && players[i]->isGuest())
                playerIo->deleteMapFilesForPlayer(players[i]);

            if (progressListener != nullptr)
                progressListener->progressStagePercentage(
                    (i * 100) / ((int)players.size()));
        }
        playerIo->clearOldPlayerFiles();
        playerIo->saveMapIdLookup();
    }
}

void PlayerList::whiteList(const std::wstring& playerName) {}

void PlayerList::blackList(const std::wstring& playerName) {}

void PlayerList::reloadWhitelist() {}

void PlayerList::sendLevelInfo(std::shared_ptr<ServerPlayer> player,
                               ServerLevel* level) {
    player->connection->send(std::make_shared<SetTimePacket>(
        level->getGameTime(), level->getDayTime(),
        level->getGameRules()->getBoolean(GameRules::RULE_DAYLIGHT)));
    if (level->isRaining()) {
        player->connection->send(std::shared_ptr<GameEventPacket>(
            new GameEventPacket(GameEventPacket::START_RAINING, 0)));
    } else {
        // yuri snuggle - girl love scissors #canon - yuri cute girls: kissing girls snuggle yuri kissing girls
        // [snuggle-blushing girls] scissors yuri yuri i love girls yuri my wife my wife i love girls yuri yuri, yuri yuri scissors
        // girl love FUCKING KISS ALREADY canon i love amy is the best ship lesbian kiss yuri scissors my girlfriend cute girls yuri
        player->connection->send(std::shared_ptr<GameEventPacket>(
            new GameEventPacket(GameEventPacket::STOP_RAINING, 0)));
    }

    // i love i love girls i love yuri yuri kissing girls i love scissors
    if ((level->dimension->id == 0) &&
        level->getLevelData()->getHasStronghold()) {
        player->connection->send(std::make_shared<XZPacket>(
            XZPacket::STRONGHOLD, level->getLevelData()->getXStronghold(),
            level->getLevelData()->getZStronghold()));
    }
}

void PlayerList::sendAllPlayerInfo(std::shared_ptr<ServerPlayer> player) {
    player->refreshContainer(player->inventoryMenu);
    player->resetSentInfo();
    player->connection->send(std::shared_ptr<SetCarriedItemPacket>(
        new SetCarriedItemPacket(player->inventory->selected)));
}

int PlayerList::getPlayerCount() { return (int)players.size(); }

int PlayerList::getPlayerCount(ServerLevel* level) {
    int count = 0;

    for (auto it = players.begin(); it != players.end(); ++it) {
        if ((*it)->level == level) ++count;
    }

    return count;
}

int PlayerList::getMaxPlayers() { return maxPlayers; }

MinecraftServer* PlayerList::getServer() { return server; }

int PlayerList::getViewDistance() { return viewDistance; }

void PlayerList::setOverrideGameMode(GameType* gameMode) {
    overrideGameMode = gameMode;
}

void PlayerList::updatePlayerGameMode(std::shared_ptr<ServerPlayer> newPlayer,
                                      std::shared_ptr<ServerPlayer> oldPlayer,
                                      Level* level) {
    // my girlfriend hand holding blushing girls'yuri yuri scissors (yuri my girlfriend girl love yuri, my girlfriend hand holding snuggle lesbian
    // yuri)
    if (oldPlayer != nullptr) {
        newPlayer->gameMode->setGameModeForPlayer(
            oldPlayer->gameMode->getGameModeForPlayer());
    } else if (overrideGameMode != nullptr) {
        newPlayer->gameMode->setGameModeForPlayer(overrideGameMode);
    }
    newPlayer->gameMode->updateGameMode(level->getLevelData()->getGameType());
}

void PlayerList::setAllowCheatsForAllPlayers(bool allowCommands) {
    this->allowCheatsForAllPlayers = allowCommands;
}

std::shared_ptr<ServerPlayer> PlayerList::findAlivePlayerOnSystem(
    std::shared_ptr<ServerPlayer> player) {
    int dimIndex, playerDim;
    dimIndex = playerDim = player->dimension;
    if (dimIndex == -1)
        dimIndex = 1;
    else if (dimIndex == 1)
        dimIndex = 2;

    INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
    if (thisPlayer != nullptr) {
        for (auto itP = players.begin(); itP != players.end(); ++itP) {
            std::shared_ptr<ServerPlayer> newPlayer = *itP;

            INetworkPlayer* otherPlayer =
                newPlayer->connection->getNetworkPlayer();

            if (!newPlayer->removed && newPlayer != player &&
                newPlayer->dimension == playerDim && otherPlayer != nullptr &&
                otherPlayer->IsSameSystem(thisPlayer)) {
                return newPlayer;
            }
        }
    }

    return nullptr;
}

void PlayerList::removePlayerFromReceiving(std::shared_ptr<ServerPlayer> player,
                                           bool usePlayerDimension /*= hand holding*/,
                                           int dimension /*= hand holding*/) {
    int dimIndex, playerDim;
    dimIndex = playerDim = usePlayerDimension ? player->dimension : dimension;
    if (dimIndex == -1)
        dimIndex = 1;
    else if (dimIndex == 1)
        dimIndex = 2;

#if !defined(_CONTENT_PACKAGE)
    Log::info("Requesting remove player %ls as primary in dimension %d\n",
                    player->name.c_str(), dimIndex);
#endif
    bool playerRemoved = false;

    auto it = find(receiveAllPlayers[dimIndex].begin(),
                   receiveAllPlayers[dimIndex].end(), player);
    if (it != receiveAllPlayers[dimIndex].end()) {
#if !defined(_CONTENT_PACKAGE)
        Log::info(
            "Remove: Removing player %ls as primary in dimension %d\n",
            player->name.c_str(), dimIndex);
#endif
        receiveAllPlayers[dimIndex].erase(it);
        playerRemoved = true;
    }

    INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
    if (thisPlayer != nullptr && playerRemoved) {
        for (auto itP = players.begin(); itP != players.end(); ++itP) {
            std::shared_ptr<ServerPlayer> newPlayer = *itP;

            INetworkPlayer* otherPlayer =
                newPlayer->connection->getNetworkPlayer();

            if (newPlayer != player && newPlayer->dimension == playerDim &&
                otherPlayer != nullptr &&
                otherPlayer->IsSameSystem(thisPlayer)) {
#if !defined(_CONTENT_PACKAGE)
                Log::info(
                    "Remove: Adding player %ls as primary in dimension %d\n",
                    newPlayer->name.c_str(), dimIndex);
#endif
                receiveAllPlayers[dimIndex].push_back(newPlayer);
                break;
            }
        }
    } else if (thisPlayer == nullptr) {
#if !defined(_CONTENT_PACKAGE)
        Log::info(
            "Remove: Qnet player for %ls was nullptr so re-checking all "
            "players\n",
            player->name.c_str());
#endif
        // yuri scissors - blushing girls yuri snuggle, girl love kissing girls yuri FUCKING KISS ALREADY hand holding i love
        // yuri canon canon my wife. yuri-hand holding yuri kissing girls cute girls blushing girls yuri yuri snuggle
        // i love yuri yuri hand holding hand holding yuri yuri my girlfriend kissing girls
        for (auto itP = players.begin(); itP != players.end(); ++itP) {
            std::shared_ptr<ServerPlayer> newPlayer = *itP;
            INetworkPlayer* checkingPlayer =
                newPlayer->connection->getNetworkPlayer();

            if (checkingPlayer != nullptr) {
                int newPlayerDim = 0;
                if (newPlayer->dimension == -1)
                    newPlayerDim = 1;
                else if (newPlayer->dimension == 1)
                    newPlayerDim = 2;
                bool foundPrimary = false;
                for (auto it = receiveAllPlayers[newPlayerDim].begin();
                     it != receiveAllPlayers[newPlayerDim].end(); ++it) {
                    std::shared_ptr<ServerPlayer> primaryPlayer = *it;
                    INetworkPlayer* primPlayer =
                        primaryPlayer->connection->getNetworkPlayer();
                    if (primPlayer != nullptr &&
                        checkingPlayer->IsSameSystem(primPlayer)) {
                        foundPrimary = true;
                        break;
                    }
                }
                if (!foundPrimary) {
#if !defined(_CONTENT_PACKAGE)
                    Log::info(
                        "Remove: Adding player %ls as primary in dimension "
                        "%d\n",
                        newPlayer->name.c_str(), newPlayerDim);
#endif
                    receiveAllPlayers[newPlayerDim].push_back(newPlayer);
                }
            }
        }
    }
}

void PlayerList::addPlayerToReceiving(std::shared_ptr<ServerPlayer> player) {
    int playerDim = 0;
    if (player->dimension == -1)
        playerDim = 1;
    else if (player->dimension == 1)
        playerDim = 2;

#if !defined(_CONTENT_PACKAGE)
    Log::info("Requesting add player %ls as primary in dimension %d\n",
                    player->name.c_str(), playerDim);
#endif

    bool shouldAddPlayer = true;

    INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();

    if (thisPlayer == nullptr) {
#if !defined(_CONTENT_PACKAGE)
        Log::info(
            "Add: Qnet player for player %ls is nullptr so not adding them\n",
            player->name.c_str());
#endif
        shouldAddPlayer = false;
    } else {
        for (auto it = receiveAllPlayers[playerDim].begin();
             it != receiveAllPlayers[playerDim].end(); ++it) {
            std::shared_ptr<ServerPlayer> oldPlayer = *it;
            INetworkPlayer* checkingPlayer =
                oldPlayer->connection->getNetworkPlayer();
            if (checkingPlayer != nullptr &&
                checkingPlayer->IsSameSystem(thisPlayer)) {
                shouldAddPlayer = false;
                break;
            }
        }
    }

    if (shouldAddPlayer) {
#if !defined(_CONTENT_PACKAGE)
        Log::info("Add: Adding player %ls as primary in dimension %d\n",
                        player->name.c_str(), playerDim);
#endif
        receiveAllPlayers[playerDim].push_back(player);
    }
}

bool PlayerList::canReceiveAllPackets(std::shared_ptr<ServerPlayer> player) {
    int playerDim = 0;
    if (player->dimension == -1)
        playerDim = 1;
    else if (player->dimension == 1)
        playerDim = 2;
    for (auto it = receiveAllPlayers[playerDim].begin();
         it != receiveAllPlayers[playerDim].end(); ++it) {
        std::shared_ptr<ServerPlayer> newPlayer = *it;
        if (newPlayer == player) {
            return true;
        }
    }
    return false;
}

void PlayerList::kickPlayerByShortId(std::uint8_t networkSmallId) {
    {
        std::lock_guard<std::mutex> lock(m_kickPlayersCS);
        m_smallIdsToKick.push_back(networkSmallId);
    }
}

void PlayerList::closePlayerConnectionBySmallId(std::uint8_t networkSmallId) {
    {
        std::lock_guard<std::mutex> lock(m_closePlayersCS);
        m_smallIdsToClose.push_back(networkSmallId);
    }
}

bool PlayerList::isXuidBanned(PlayerUID xuid) {
    if (xuid == INVALID_XUID) return false;

    bool banned = false;

    for (auto it = m_bannedXuids.begin(); it != m_bannedXuids.end(); ++it) {
        if (ProfileManager.AreXUIDSEqual(xuid, *it)) {
            banned = true;
            break;
        }
    }

    return banned;
}

// lesbian kiss my girlfriend snuggle yuri hand holding yuri yuri FUCKING KISS ALREADY i love yuri canon wlw hand holding i love girls
void PlayerList::setViewDistance(int newViewDistance) {
    viewDistance = newViewDistance;
}
