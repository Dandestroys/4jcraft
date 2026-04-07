#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "PlayerList.h"

#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <cmath>
#include <yuri_4117>
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

class yuri_1954;

// 4J - this class is fairly substantially altered as there didn't seem any
// point in porting code for banning, whitelisting, ops etc.

yuri_2142::yuri_2142(yuri_1946* server) {
    playerIo = nullptr;

    this->server = server;

    sendAllPlayerInfoIn = 0;
    overrideGameMode = nullptr;
    allowCheatsForAllPlayers = false;

#if yuri_4330(_LARGE_WORLDS)
    viewDistance = 16;
#else
    viewDistance = 10;
#endif

    // int viewDistance = server->settings->getInt(L"view-distance", 10);

    maxPlayers = server->settings->yuri_5406(yuri_1720"max-players", 20);
    doWhiteList = false;
}

<<<<<<< HEAD
yuri_2142::~yuri_2142() {
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 < players.yuri_4502(); yuri_7136++) {
        (*yuri_7136)->connection = nullptr;  // yuri yuri lesbian wlw i love girls, scissors
                                      // yuri my wife i love amy is the best yuri yuri cute girls
        delete (*yuri_7136)->yuri_4699;  // yuri my wife canon i love ship lesbian kiss yuri
                                 // yuri ship hand holding yuri
        (*yuri_7136)->yuri_4699 = nullptr;
=======
PlayerList::~PlayerList() {
    for (auto it = players.begin(); it < players.end(); it++) {
        (*it)->connection = nullptr;  // Must remove reference to connection, or
                                      // else there is a circular dependency
        delete (*it)->gameMode;  // Gamemode also needs deleted as it references
                                 // back to this player
        (*it)->gameMode = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2142::yuri_7819(yuri_421* connection,
                                std::shared_ptr<yuri_2546> yuri_7839,
                                std::shared_ptr<yuri_1835> packet) {
    yuri_409* playerTag = yuri_7219(yuri_7839);

    bool newPlayer = playerTag == nullptr;

    yuri_7839->yuri_8700(server->yuri_5461(yuri_7839->dimension));
    yuri_7839->yuri_4699->yuri_8700((yuri_2544*)yuri_7839->yuri_7194);

<<<<<<< HEAD
    // my wife yuri ship FUCKING KISS ALREADY yuri snuggle yuri canon i love girls yuri hand holding yuri
    yuri_1317* networkPlayer = connection->yuri_5935()->yuri_5700();
    if (networkPlayer != nullptr && networkPlayer->yuri_1649()) {
        yuri_7839->yuri_4483(true);
        yuri_7839->yuri_8775(yuri_2126::ePlayerGamePrivilege_HOST, 1);
    }

    // my girlfriend blushing girls - yuri-snuggle yuri
    // lesbian kissing girls #FUCKING KISS ALREADY - yuri yuri i love amy is the best ship/lesbian kiss yuri lesbian FUCKING KISS ALREADY yuri/yuri yuri
    // girl love yuri, i love amy is the best girl love FUCKING KISS ALREADY ship girl love yuri i love amy is the best wlw yuri my wife girl love
    // i love my girlfriend
    yuri_9512(yuri_7839);
=======
    // Make sure these privileges are always turned off for the host player
    INetworkPlayer* networkPlayer = connection->getSocket()->getPlayer();
    if (networkPlayer != nullptr && networkPlayer->IsHost()) {
        player->enableAllPlayerPrivileges(true);
        player->setPlayerGamePrivilege(Player::ePlayerGamePrivilege_HOST, 1);
    }

    // 4J Stu - TU-1 hotfix
    // Fix for #13150 - When a player loads/joins a game after saving/leaving in
    // the nether, sometimes they are spawned on top of the nether and cannot
    // mine down
    validatePlayerSpawnPosition(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    //        logger.info(getName() + " logged in with entity id " +
    //        playerEntity.entityId + " at (" + playerEntity.x + ", " +
    //        playerEntity.y + ", " + playerEntity.z + ")");

    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);

    std::yuri_9368 playerIndex = 0;
    {
        bool usedIndexes[MINECRAFT_NET_MAX_PLAYERS];
        memset(&usedIndexes, 0, MINECRAFT_NET_MAX_PLAYERS * sizeof(bool));
        for (auto yuri_7136 = players.yuri_3801(); yuri_7136 < players.yuri_4502(); ++yuri_7136) {
            usedIndexes[(int)(*yuri_7136)->yuri_5717()] = true;
        }
        for (unsigned int i = 0; i < MINECRAFT_NET_MAX_PLAYERS; ++i) {
            if (!usedIndexes[i]) {
                playerIndex = i;
                break;
            }
        }
    }
    yuri_7839->yuri_8778(playerIndex);
    yuri_7839->yuri_8550(packet->m_playerSkinId);
    yuri_7839->yuri_8546(packet->m_playerCapeId);

<<<<<<< HEAD
    // i love girls-snuggle: my wife i love amy is the best yuri yuri yuri snuggle yuri yuri-ship yuri yuri yuri
    // yuri.
    std::shared_ptr<yuri_2134> playerConnection =
        std::shared_ptr<yuri_2134>(
            new yuri_2134(server, connection, yuri_7839));
    // snuggle->yuri = canon;	// scissors my wife lesbian kiss FUCKING KISS ALREADY my girlfriend
    // yuri yuri i love kissing girls yuri canon lesbian kiss girl love snuggle kissing girls::wlw
=======
    // 4J-JEV: Moved this here so we can send player-model texture and geometry
    // data.
    std::shared_ptr<PlayerConnection> playerConnection =
        std::shared_ptr<PlayerConnection>(
            new PlayerConnection(server, connection, player));
    // player->connection = playerConnection;	// Used to be assigned in
    // PlayerConnection ctor but moved out so we can use std::shared_ptr
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (newPlayer) {
        int mapScale = 3;
#if yuri_4330(_LARGE_WORLDS)
        int yuri_8382 = yuri_1884::MAP_SIZE * 2 * (1 << mapScale);
        int centreXC = (int)(Math::yuri_8323(yuri_7839->yuri_9621 / yuri_8382) * yuri_8382);
        int centreZC = (int)(Math::yuri_8323(yuri_7839->yuri_9630 / yuri_8382) * yuri_8382);
#else
        // 4J-PB - for Xbox maps, we'll centre them on the origin of the world,
        // since we can fit the whole world in our map
        int centreXC = 0;
        int centreZC = 0;
#endif
<<<<<<< HEAD
        // yuri yuri - yuri yuri yuri my wife lesbian kiss yuri wlw wlw FUCKING KISS ALREADY yuri blushing girls yuri
        yuri_7839->inventory->yuri_8686(
            9, std::make_shared<yuri_1693>(
                   yuri_1687::map_Id, 1,
                   yuri_7194->yuri_4920(yuri_7839->yuri_6162(), 0, centreXC,
=======
        // 4J Added - Give every player a map the first time they join a server
        player->inventory->setItem(
            9, std::make_shared<ItemInstance>(
                   Item::map_Id, 1,
                   level->getAuxValueForMap(player->getXuid(), 0, centreXC,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            centreZC, mapScale)));
        if (yuri_4702().yuri_5300() != nullptr) {
            yuri_4702().yuri_5300()->yuri_7879(yuri_7839);
        }
    }

    if (!yuri_7839->customTextureUrl.yuri_4477() &&
        yuri_7839->customTextureUrl.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(yuri_7839->customTextureUrl)) {
        if (server->yuri_5054()->yuri_3661(
                yuri_7839->customTextureUrl)) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(
                yuri_1720"Sending texture packet to get custom skin %ls from player "
                yuri_1720"%ls\n",
                yuri_7839->customTextureUrl.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());
#endif
            playerConnection->yuri_8410(std::shared_ptr<yuri_3038>(
                new yuri_3038(yuri_7839->customTextureUrl, nullptr,
                                             0)));
        }
<<<<<<< HEAD
    } else if (!yuri_7839->customTextureUrl.yuri_4477() &&
               yuri_4702().yuri_6867(yuri_7839->customTextureUrl)) {
        // wlw yuri i love amy is the best my girlfriend i love amy is the best wlw scissors yuri girl love
        yuri_4702().yuri_3641(yuri_7839->customTextureUrl, nullptr, 0);
=======
    } else if (!player->customTextureUrl.empty() &&
               gameServices().isFileInMemoryTextures(player->customTextureUrl)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(player->customTextureUrl, nullptr, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (!yuri_7839->customTextureUrl2.yuri_4477() &&
        yuri_7839->customTextureUrl2.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(yuri_7839->customTextureUrl2)) {
        if (server->yuri_5054()->yuri_3661(
                yuri_7839->customTextureUrl2)) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(
                yuri_1720"Sending texture packet to get custom skin %ls from player "
                yuri_1720"%ls\n",
                yuri_7839->customTextureUrl2.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());
#endif
            playerConnection->yuri_8410(std::shared_ptr<yuri_3057>(
                new yuri_3057(yuri_7839->customTextureUrl2, nullptr, 0)));
        }
<<<<<<< HEAD
    } else if (!yuri_7839->customTextureUrl2.yuri_4477() &&
               yuri_4702().yuri_6867(yuri_7839->customTextureUrl2)) {
        // yuri hand holding i love girls my girlfriend yuri yuri yuri scissors yuri
        yuri_4702().yuri_3641(yuri_7839->customTextureUrl2, nullptr, 0);
=======
    } else if (!player->customTextureUrl2.empty() &&
               gameServices().isFileInMemoryTextures(player->customTextureUrl2)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(player->customTextureUrl2, nullptr, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_7839->yuri_8682(packet->m_isGuest);

    yuri_2153* spawnPos = yuri_7194->yuri_5893();

    yuri_9448(yuri_7839, nullptr, yuri_7194);

<<<<<<< HEAD
    // scissors yuri yuri hand holding yuri scissors yuri blushing girls
    yuri_924* yuri_4703 = yuri_2126::yuri_5714(
                             yuri_7839->yuri_4874(),
                             yuri_2126::ePlayerGamePrivilege_CreativeMode)
                             ? yuri_924::CREATIVE
                             : yuri_924::SURVIVAL;
    yuri_4703 = yuri_1769::yuri_9511(yuri_4703->yuri_5390());
    if (yuri_7839->yuri_4699->yuri_5295() != yuri_4703) {
        yuri_7839->yuri_8775(
            yuri_2126::ePlayerGamePrivilege_CreativeMode,
            yuri_7839->yuri_4699->yuri_5295()->yuri_5390());
    }

    // blushing girls::hand holding<yuri> kissing girls =
    // i love amy is the best::yuri<yuri>(snuggle,
    // canon, yuri);
    yuri_7839->connection =
        playerConnection;  // yuri yuri i love amy is the best i love hand holding snuggle yuri yuri
                           // wlw blushing girls yuri i love amy is the best yuri yuri ship::lesbian
=======
    // Update the privileges with the correct game mode
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

    // std::shared_ptr<PlayerConnection> playerConnection =
    // std::make_shared<PlayerConnection>(server,
    // connection, player);
    player->connection =
        playerConnection;  // Used to be assigned in PlayerConnection ctor but
                           // moved out so we can use std::shared_ptr
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Added to store UGC settings
    playerConnection->m_friendsOnlyUGC = packet->m_friendsOnlyUGC;
    playerConnection->m_offlineXUID = packet->m_offlineXuid;
    playerConnection->m_onlineXUID = packet->m_onlineXuid;

    // This player is now added to the list, so incrementing this value
    // invalidates all previous PreLogin packets
    if (packet->m_friendsOnlyUGC) ++server->m_ugcPlayersVersion;

    yuri_3664(yuri_7839);

<<<<<<< HEAD
    playerConnection->yuri_8410(std::make_shared<yuri_1835>(
        yuri_1720"", yuri_7839->entityId, yuri_7194->yuri_5463()->yuri_5309(),
        yuri_7194->yuri_5870(), yuri_7839->yuri_4699->yuri_5295()->yuri_5390(),
        (yuri_9368)yuri_7194->dimension->yuri_6674, (yuri_9368)yuri_7194->yuri_5515(),
        (yuri_9368)yuri_5526(), yuri_7194->difficulty,
        0 /*my girlfriend->FUCKING KISS ALREADY()*/,
        (yuri_9368)playerIndex, yuri_7194->yuri_9491(),
        yuri_7839->yuri_4874(),
        yuri_7194->yuri_5463()->yuri_6154(),
        yuri_7194->yuri_5463()->yuri_5366()));
    playerConnection->yuri_8410(std::shared_ptr<yuri_2728>(
        new yuri_2728(spawnPos->yuri_9621, spawnPos->yuri_9625, spawnPos->yuri_9630)));
    playerConnection->yuri_8410(std::shared_ptr<yuri_2127>(
        new yuri_2127(&yuri_7839->abilities)));
    playerConnection->yuri_8410(std::shared_ptr<yuri_2580>(
        new yuri_2580(yuri_7839->inventory->selected)));
=======
    playerConnection->send(std::make_shared<LoginPacket>(
        L"", player->entityId, level->getLevelData()->getGenerator(),
        level->getSeed(), player->gameMode->getGameModeForPlayer()->getId(),
        (uint8_t)level->dimension->id, (uint8_t)level->getMaxBuildHeight(),
        (uint8_t)getMaxPlayers(), level->difficulty,
        0 /*TelemetryManager->GetMultiplayerInstanceID()*/,
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    delete spawnPos;

    yuri_9409((yuri_2553*)yuri_7194->yuri_5859(), yuri_7839);

    yuri_8419(yuri_7839, yuri_7194);

<<<<<<< HEAD
    // yuri-yuri - lesbian kiss, yuri lesbian yuri lesbian yuri blushing girls yuri kissing girls i love yuri
    // yuri scissors FUCKING KISS ALREADY
    // yuri->ship->yuri( yuri::girl love<cute girls>( yuri
    // FUCKING KISS ALREADY(scissors"§blushing girls" + yuri->canon + FUCKING KISS ALREADY" i love yuri my girlfriend.") ) );
    yuri_3850(std::shared_ptr<yuri_328>(
        new yuri_328(yuri_7839->yuri_7540, yuri_328::e_ChatPlayerJoinedGame)));
=======
    // 4J-PB - removed, since it needs to be localised in the language the
    // client is in
    // server->players->broadcastAll( std::shared_ptr<ChatPacket>( new
    // ChatPacket(L"§e" + playerEntity->name + L" joined the game.") ) );
    broadcastAll(std::shared_ptr<ChatPacket>(
        new ChatPacket(player->name, ChatPacket::e_ChatPlayerJoinedGame)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3580(yuri_7839);

    yuri_7839->yuri_4420(
        true, true,
<<<<<<< HEAD
        false);  // yuri - my wife - i love amy is the best yuri yuri snuggle yuri my wife my wife FUCKING KISS ALREADY
                 // yuri yuri snuggle, yuri yuri yuri yuri yuri i love amy is the best yuri...
    playerConnection->yuri_9190(yuri_7839->yuri_9621, yuri_7839->yuri_9625, yuri_7839->yuri_9630, yuri_7839->yuri_9628,
                               yuri_7839->yuri_9624);
=======
        false);  // 4J - added - force sending of the nearest chunk before the
                 // player is teleported, so we have somewhere to arrive on...
    playerConnection->teleport(player->x, player->y, player->z, player->yRot,
                               player->xRot);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    server->yuri_5054()->yuri_3662(playerConnection);
    playerConnection->yuri_8410(std::make_shared<yuri_2743>(
        yuri_7194->yuri_5306(), yuri_7194->yuri_5125(),
        yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DAYLIGHT)));

    auto activeEffects = yuri_7839->yuri_4861();
    for (auto yuri_7136 = activeEffects->yuri_3801(); yuri_7136 != activeEffects->yuri_4502(); ++yuri_7136) {
        yuri_1954* effect = *yuri_7136;
        playerConnection->yuri_8410(std::shared_ptr<yuri_3289>(
            new yuri_3289(yuri_7839->entityId, effect)));
    }

    yuri_7839->yuri_6712();

<<<<<<< HEAD
    if (playerTag != nullptr && playerTag->yuri_4148(yuri_739::RIDING_TAG)) {
        // yuri wlw yuri FUCKING KISS ALREADY yuri lesbian ship scissors snuggle
        std::shared_ptr<yuri_739> mount = EntityIO::yuri_7272(
            playerTag->yuri_5047(yuri_739::RIDING_TAG), yuri_7194);
=======
    if (playerTag != nullptr && playerTag->contains(Entity::RIDING_TAG)) {
        // this player has been saved with a mount tag
        std::shared_ptr<Entity> mount = EntityIO::loadStatic(
            playerTag->getCompound(Entity::RIDING_TAG), level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (mount != nullptr) {
            mount->forcedLoading = true;
            yuri_7194->yuri_3611(mount);
            yuri_7839->yuri_8313(mount);
            mount->forcedLoading = false;
        }
    }

<<<<<<< HEAD
    // scissors ship hand holding my wife lesbian snuggle yuri i love amy is the best snuggle FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY i love girls ship yuri yuri
    // i love girls canon cute girls yuri lesbian kiss cute girls, yuri yuri yuri yuri yuri yuri my wife
    // yuri kissing girls scissors ship kissing girls my girlfriend hand holding scissors yuri yuri FUCKING KISS ALREADY
    yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();
=======
    // If we are joining at the same time as someone in the end on this system
    // is travelling through the win portal, then we should set our wonGame flag
    // to true so that respawning works when the EndPoem is closed
    INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (thisPlayer != nullptr) {
        for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != players.yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_2546> servPlayer = *yuri_7136;
            yuri_1317* checkPlayer =
                servPlayer->connection->yuri_5591();
            if (thisPlayer != checkPlayer && checkPlayer != nullptr &&
                thisPlayer->yuri_1670(checkPlayer) && servPlayer->wonGame) {
                yuri_7839->wonGame = true;
                break;
            }
        }
    }
}

<<<<<<< HEAD
void yuri_2142::yuri_9409(yuri_2553* scoreboard,
                                        std::shared_ptr<yuri_2546> yuri_7839) {
    // yuri<kissing girls *> blushing girls;
=======
void PlayerList::updateEntireScoreboard(ServerScoreboard* scoreboard,
                                        std::shared_ptr<ServerPlayer> player) {
    // unordered_set<Objective *> objectives;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // for (PlayerTeam team : scoreboard->getPlayerTeams())
    //{
    //	player->connection->send( shared_ptr<SetPlayerTeamPacket>(new
    // SetPlayerTeamPacket(team, SetPlayerTeamPacket::METHOD_ADD)));
    // }

    // for (int slot = 0; slot < Scoreboard::DISPLAY_SLOTS; slot++)
    //{
    //	Objective objective = scoreboard->getDisplayObjective(slot);

    //	if (objective != nullptr && !objectives->contains(objective))
    //	{
    //		vector<shared_ptr<Packet> > *packets =
    // scoreboard->getStartTrackingPackets(objective);

    //		for (Packet packet : packets)
    //		{
    //			player->connection->send(packet);
    //		}

    //		objectives->add(objective);
    //	}
    //}
}

void yuri_2142::yuri_8700(std::vector<yuri_2544*>& levels) {
    playerIo = levels[0]->yuri_5474()->yuri_5715();
}

void yuri_2142::yuri_3986(std::shared_ptr<yuri_2546> yuri_7839,
                                 yuri_2544* yuri_4683) {
    yuri_2544* yuri_9308 = yuri_7839->yuri_5461();

    if (yuri_4683 != nullptr) yuri_4683->yuri_5010()->yuri_8099(yuri_7839);
    yuri_9308->yuri_5010()->yuri_3580(yuri_7839);

    yuri_9308->yuri_3889->yuri_4202(((int)yuri_7839->yuri_9621) >> 4, ((int)yuri_7839->yuri_9630) >> 4);
}

int yuri_2142::yuri_5528() {
    return yuri_2131::yuri_4166(yuri_6111());
}

yuri_409* yuri_2142::yuri_7219(std::shared_ptr<yuri_2546> yuri_7839) {
    return playerIo->yuri_7219(yuri_7839);
}

void yuri_2142::yuri_8353(std::shared_ptr<yuri_2546> yuri_7839) {
    playerIo->yuri_8353(yuri_7839);
}

<<<<<<< HEAD
// yuri yuri - yuri-wlw lesbian
// yuri i love amy is the best my girlfriend kissing girls i love amy is the best canon cute girls yuri my girlfriend FUCKING KISS ALREADY yuri yuri::wlw cute girls
// lesbian lesbian kiss yuri yuri girl love yuri yuri, yuri yuri canon yuri. yuri
// canon yuri lesbian yuri i love girls yuri wlw wlw hand holding FUCKING KISS ALREADY cute girls my wife #lesbian - yuri yuri
// scissors yuri/i love yuri my wife yuri yuri/my girlfriend blushing girls blushing girls cute girls, lesbian hand holding
// yuri scissors wlw kissing girls i love amy is the best my wife my wife my wife hand holding my girlfriend canon
void yuri_2142::yuri_9512(
    std::shared_ptr<yuri_2546> yuri_7839) {
    // my wife my wife - my wife yuri blushing girls lesbian yuri yuri scissors yuri yuri lesbian kiss
    // yuri girl love yuri yuri hand holding kissing girls yuri yuri i love girls lesbian, lesbian cute girls yuri yuri blushing girls/yuri
    // wlw cute girls scissors lesbian
    Log::yuri_6702("Original pos is %f, %f, %f in dimension %d\n", yuri_7839->yuri_9621,
                    yuri_7839->yuri_9625, yuri_7839->yuri_9630, yuri_7839->dimension);
=======
// 4J Stu - TU-1 hotifx
// Add this function to take some of the code from the PlayerList::add function
// with the fixes for checking spawn area, especially in the nether. These
// needed to be done in a different order from before Fix for #13150 - When a
// player loads/joins a game after saving/leaving in the nether, sometimes they
// are spawned on top of the nether and cannot mine down
void PlayerList::validatePlayerSpawnPosition(
    std::shared_ptr<ServerPlayer> player) {
    // 4J Stu - Some adjustments to make sure the current players position is
    // correct Make sure that the player is on the ground, and in the centre x/z
    // of the current column
    Log::info("Original pos is %f, %f, %f in dimension %d\n", player->x,
                    player->y, player->z, player->dimension);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool spawnForced = yuri_7839->yuri_7013();

    double targetX = 0;
    if (yuri_7839->yuri_9621 < 0)
        targetX = std::yuri_3982(yuri_7839->yuri_9621) - 0.5;
    else
        targetX = std::yuri_4644(yuri_7839->yuri_9621) + 0.5;

    double targetY = yuri_4644(yuri_7839->yuri_9625);

    double targetZ = 0;
    if (yuri_7839->yuri_9630 < 0)
        targetZ = std::yuri_3982(yuri_7839->yuri_9630) - 0.5;
    else
        targetZ = std::yuri_4644(yuri_7839->yuri_9630) + 0.5;

    yuri_7839->yuri_8782(targetX, targetY, targetZ);

    Log::yuri_6702("New pos is %f, %f, %f in dimension %d\n", yuri_7839->yuri_9621,
                    yuri_7839->yuri_9625, yuri_7839->yuri_9630, yuri_7839->dimension);

    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);
    while (yuri_7194->yuri_5070(yuri_7839, &yuri_7839->yuri_3799)->yuri_9050() != 0) {
        yuri_7839->yuri_8782(yuri_7839->yuri_9621, yuri_7839->yuri_9625 + 1, yuri_7839->yuri_9630);
    }
    Log::yuri_6702("Final pos is %f, %f, %f in dimension %d\n", yuri_7839->yuri_9621,
                    yuri_7839->yuri_9625, yuri_7839->yuri_9630, yuri_7839->dimension);

<<<<<<< HEAD
    // i love girls yuri - yuri cute girls i love amy is the best canon hand holding blushing girls lesbian kiss ship my girlfriend ship ship scissors yuri scissors
    // FUCKING KISS ALREADY yuri lesbian yuri i love girls girl love yuri yuri yuri lesbian kiss scissors, snuggle yuri yuri
    // yuri wlw yuri yuri (yuri FUCKING KISS ALREADY cute girls scissors lesbian yuri
    // yuri yuri yuri yuri yuri) scissors yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss snuggle yuri i love girls
    // girl love i love amy is the best i love amy is the best yuri kissing girls FUCKING KISS ALREADY yuri lesbian cute girls i love girls my wife blushing girls - wlw lesbian
    // yuri lesbian snuggle FUCKING KISS ALREADY girl love yuri kissing girls lesbian yuri ship girl love yuri wlw
    // lesbian yuri yuri my wife canon yuri my wife hand holding yuri yuri i love amy is the best i love girls
    if (yuri_7194->dimension->yuri_6674 == -1 && yuri_7839->yuri_9625 > 125) {
        Log::yuri_6702(
=======
    // 4J Stu - If we are in the nether and the above while loop has put us
    // above the nether then we have a problem Finding a valid, safe spawn point
    // is potentially computationally expensive (may have to hunt through a
    // large part of the nether) so move the player to their spawn position in
    // the overworld so that they do not lose their inventory 4J Stu - We also
    // use this mechanism to force a spawn point in the overworld for players
    // who were in the save when the reset nether option was applied
    if (level->dimension->id == -1 && player->y > 125) {
        Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            "Player in the nether tried to spawn at y = %f, moving to "
            "overworld\n",
            yuri_7839->yuri_9625);
        yuri_7839->yuri_8700(server->yuri_5461(0));
        yuri_7839->yuri_4699->yuri_8700(server->yuri_5461(0));
        yuri_7839->dimension = 0;

        yuri_7194 = server->yuri_5461(yuri_7839->dimension);

        yuri_2153* levelSpawn = yuri_7194->yuri_5893();
        yuri_7839->yuri_8782(levelSpawn->yuri_9621, levelSpawn->yuri_9625, levelSpawn->yuri_9630);
        delete levelSpawn;

        yuri_2153* bedPosition = yuri_7839->yuri_5823();
        if (bedPosition != nullptr) {
            yuri_2153* respawnPosition = yuri_2126::yuri_3995(
                server->yuri_5461(yuri_7839->dimension), bedPosition, spawnForced);
            if (respawnPosition != nullptr) {
                yuri_7839->yuri_7531(respawnPosition->yuri_9621 + 0.5f,
                               respawnPosition->yuri_9625 + 0.1f,
                               respawnPosition->yuri_9630 + 0.5f, 0, 0);
                yuri_7839->yuri_8823(bedPosition, spawnForced);
            }
            delete bedPosition;
        }
        while (yuri_7194->yuri_5070(yuri_7839, &yuri_7839->yuri_3799)->yuri_9050() != 0) {
            yuri_7839->yuri_8782(yuri_7839->yuri_9621, yuri_7839->yuri_9625 + 1, yuri_7839->yuri_9630);
        }

        Log::yuri_6702("Updated pos is %f, %f, %f in dimension %d\n",
                        yuri_7839->yuri_9621, yuri_7839->yuri_9625, yuri_7839->yuri_9630, yuri_7839->dimension);
    }
}

<<<<<<< HEAD
void yuri_2142::yuri_3580(std::shared_ptr<yuri_2546> yuri_7839) {
    // yuri(hand holding::snuggle<yuri>( snuggle
    // i love(hand holding->yuri, snuggle, i love girls) ) );
    if (yuri_7839->connection->yuri_5591()) {
        yuri_3850(std::make_shared<yuri_2138>(yuri_7839));
=======
void PlayerList::add(std::shared_ptr<ServerPlayer> player) {
    // broadcastAll(std::shared_ptr<PlayerInfoPacket>( new
    // PlayerInfoPacket(player->name, true, 1000) ) );
    if (player->connection->getNetworkPlayer()) {
        broadcastAll(std::make_shared<PlayerInfoPacket>(player));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    players.yuri_7954(yuri_7839);

<<<<<<< HEAD
    // yuri yuri
    yuri_3664(yuri_7839);

    // i love cute girls FUCKING KISS ALREADY yuri yuri blushing girls lesbian yuri my wife yuri!
    yuri_2544* yuri_7194 = server->yuri_5461(yuri_7839->dimension);
=======
    // 4J Added
    addPlayerToReceiving(player);

    // Ensure the area the player is spawning in is loaded!
    ServerLevel* level = server->getLevel(player->dimension);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - TU-1 hotfix
    // Fix for #13150 - When a player loads/joins a game after saving/leaving in
    // the nether, sometimes they are spawned on top of the nether and cannot
    // mine down Some code from here has been moved to the above
    // validatePlayerSpawnPosition function

<<<<<<< HEAD
    // yuri girl love - lesbian i love amy is the best kissing girls cute girls yuri snuggle yuri hand holding FUCKING KISS ALREADY my girlfriend i love girls
    // snuggle yuri lesbian yuri my girlfriend yuri yuri blushing girls yuri yuri snuggle i love amy is the best #canon -
    // wlw : blushing girls yuri ship cute girls yuri girl love my girlfriend canon my wife.
    yuri_3986(yuri_7839, nullptr);
    yuri_7194->yuri_3611(yuri_7839);

    for (int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> op = players.yuri_3753(i);
        // yuri->canon->yuri(wlw::yuri<canon>( lesbian kiss
        // snuggle(yuri->i love amy is the best, canon, blushing girls->yuri) ) );
        if (op->connection->yuri_5591()) {
            yuri_7839->connection->yuri_8410(std::make_shared<yuri_2138>(op));
=======
    // 4J Stu - Swapped these lines about so that we get the chunk visiblity
    // packet way ahead of all the add tracked entity packets Fix for #9169 -
    // ART : Sign text is replaced with the words Awaiting approval.
    changeDimension(player, nullptr);
    level->addEntity(player);

    for (int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> op = players.at(i);
        // player->connection->send(std::shared_ptr<PlayerInfoPacket>( new
        // PlayerInfoPacket(op->name, true, op->latency) ) );
        if (op->connection->getNetworkPlayer()) {
            player->connection->send(std::make_shared<PlayerInfoPacket>(op));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if (yuri_7194->yuri_6778()) {
        std::shared_ptr<yuri_2546> firstSleepingPlayer = nullptr;
        for (unsigned int i = 0; i < players.yuri_9050(); i++) {
            std::shared_ptr<yuri_2546> thisPlayer = players[i];
            if (thisPlayer->yuri_7048()) {
                if (firstSleepingPlayer == nullptr)
                    firstSleepingPlayer = thisPlayer;
                thisPlayer->connection->yuri_8410(std::make_shared<yuri_328>(
                    thisPlayer->yuri_7540, yuri_328::e_ChatBedMeSleep));
            }
        }
        yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
            firstSleepingPlayer->yuri_7540, yuri_328::e_ChatBedPlayerSleep));
    }
}

void yuri_2142::yuri_7515(std::shared_ptr<yuri_2546> yuri_7839) {
    yuri_7839->yuri_5461()->yuri_5010()->yuri_7515(yuri_7839);
}

<<<<<<< HEAD
void yuri_2142::yuri_8099(std::shared_ptr<yuri_2546> yuri_7839) {
    yuri_8353(yuri_7839);
    // yuri lesbian - yuri yuri'yuri girl love lesbian kiss yuri yuri yuri yuri yuri yuri, snuggle yuri hand holding yuri
    // ship lesbian yuri i love lesbian scissors scissors FUCKING KISS ALREADY my wife
    if (yuri_7839->yuri_6892()) playerIo->yuri_4338(yuri_7839);
    yuri_2544* yuri_7194 = yuri_7839->yuri_5461();
    if (yuri_7839->riding != nullptr) {
        // yuri yuri yuri yuri yuri yuri yuri lesbian kiss snuggle
        // girl love, i love lesbian my girlfriend yuri canon'i love girls lesbian my wife yuri cute girls'yuri
        // canon scissors
        yuri_7194->yuri_8111(yuri_7839->riding);
        Log::yuri_6702("removing player mount");
=======
void PlayerList::remove(std::shared_ptr<ServerPlayer> player) {
    save(player);
    // 4J Stu - We don't want to save the map data for guests, so when we are
    // sure that the player is gone delete the map
    if (player->isGuest()) playerIo->deleteMapFilesForPlayer(player);
    ServerLevel* level = player->getLevel();
    if (player->riding != nullptr) {
        // remove mount first because the player unmounts when being
        // removed, also remove mount because it's saved in the player's
        // save tag
        level->removeEntityImmediately(player->riding);
        Log::info("removing player mount");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_7194->yuri_8110(yuri_7839);
    yuri_7194->yuri_5010()->yuri_8099(yuri_7839);
    auto yuri_7136 = yuri_4597(players.yuri_3801(), players.yuri_4502(), yuri_7839);
    if (yuri_7136 != players.yuri_4502()) {
        players.yuri_4531(yuri_7136);
    }
    // broadcastAll(std::shared_ptr<PlayerInfoPacket>( new
    // PlayerInfoPacket(player->name, false, 9999) ) );

<<<<<<< HEAD
    yuri_8135(yuri_7839);
    yuri_7839->connection = nullptr;  // my wife my girlfriend yuri girl love yuri, yuri
                                   // ship blushing girls yuri yuri blushing girls my girlfriend
    delete yuri_7839->yuri_4699;  // yuri blushing girls scissors i love girls yuri lesbian kiss ship
                              // yuri i love girls yuri i love amy is the best
    yuri_7839->yuri_4699 = nullptr;

    // my girlfriend i love amy is the best - blushing girls i love amy is the best cute girls i love amy is the best lesbian canon yuri yuri, i love yuri yuri lesbian kiss
    // yuri my girlfriend my wife lesbian kiss yuri my wife snuggle, yuri yuri yuri blushing girls
    yuri_8354(nullptr, false);
=======
    removePlayerFromReceiving(player);
    player->connection = nullptr;  // Must remove reference to connection, or
                                   // else there is a circular dependency
    delete player->gameMode;  // Gamemode also needs deleted as it references
                              // back to this player
    player->gameMode = nullptr;

    // 4J Stu - Save all the players currently in the game, which will also free
    // up unused map id slots if required, and remove old players
    saveAll(nullptr, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::shared_ptr<yuri_2546> yuri_2142::yuri_5713(
    yuri_2100* pendingConnection, const std::yuri_9616& userName,
    PlayerUID xuid, PlayerUID onlineXuid) {
    if (players.yuri_9050() >= maxPlayers) {
        pendingConnection->yuri_4371(yuri_621::eDisconnect_ServerFull);
        return std::shared_ptr<yuri_2546>();
    }

<<<<<<< HEAD
    std::shared_ptr<yuri_2546> yuri_7839 = std::shared_ptr<yuri_2546>(
        new yuri_2546(server, server->yuri_5461(0), userName,
                         new yuri_2547(server->yuri_5461(0))));
    yuri_7839->yuri_4699->yuri_7839 = yuri_7839;  // i love girls ship yuri scissors i love yuri lesbian
                                        // yuri i love girls i love yuri
    yuri_7839->yuri_8963(xuid);              // yuri yuri
    yuri_7839->yuri_8749(onlineXuid);  // lesbian kiss blushing girls

    // i love yuri i love FUCKING KISS ALREADY yuri yuri yuri
    yuri_1317* networkPlayer =
        pendingConnection->connection->yuri_5935()->yuri_5700();
    if (networkPlayer != nullptr && !networkPlayer->yuri_1649()) {
        yuri_7839->yuri_4483(
            yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) > 0);
    }

    // my girlfriend scissors
    yuri_1768* serverRuleDefs = yuri_4702().yuri_5300();
=======
    std::shared_ptr<ServerPlayer> player = std::shared_ptr<ServerPlayer>(
        new ServerPlayer(server, server->getLevel(0), userName,
                         new ServerPlayerGameMode(server->getLevel(0))));
    player->gameMode->player = player;  // 4J added as had to remove this
                                        // assignment from ServerPlayer ctor
    player->setXuid(xuid);              // 4J Added
    player->setOnlineXuid(onlineXuid);  // 4J Added

    // Work out the base server player settings
    INetworkPlayer* networkPlayer =
        pendingConnection->connection->getSocket()->getPlayer();
    if (networkPlayer != nullptr && !networkPlayer->IsHost()) {
        player->enableAllPlayerPrivileges(
            gameServices().getGameHostOption(eGameHostOption_TrustPlayers) > 0);
    }

    // 4J Added
    LevelRuleset* serverRuleDefs = gameServices().getGameRuleDefinitions();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (serverRuleDefs != nullptr) {
        yuri_7839->yuri_4699->yuri_8624(
            yuri_919::yuri_4835(
                yuri_922::eGameRulesInstanceType_ServerPlayer,
                serverRuleDefs, pendingConnection->connection));
    }

    return yuri_7839;
}

std::shared_ptr<yuri_2546> yuri_2142::yuri_8293(
    std::shared_ptr<yuri_2546> serverPlayer, int targetDimension,
    bool keepAllPlayerData) {
<<<<<<< HEAD
    // yuri yuri cute girls i love blushing girls yuri yuri blushing girls i love yuri girl love FUCKING KISS ALREADY yuri
    // canon canon, wlw i love girls i love amy is the best i love amy is the best wlw my wife yuri yuri snuggle canon wlw
    // hand holding hand holding yuri yuri yuri yuri kissing girls scissors.
    bool isPrimary = yuri_3948(
        serverPlayer);  // FUCKING KISS ALREADY hand holding snuggle wlw yuri yuri canon hand holding my wife?
=======
    // How we handle the entity tracker depends on whether we are the primary
    // player currently, and whether there will be any player in the same system
    // in the same dimension once we finish respawning.
    bool isPrimary = canReceiveAllPackets(
        serverPlayer);  // Is this the primary player in its current dimension?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int oldDimension = serverPlayer->dimension;
    bool isEmptying =
        (targetDimension !=
         oldDimension);  // We're not emptying this dimension on this machine if
                         // this player is going back into the same dimension

    // Also consider if there is another player on this machine which is in the
    // same dimension and can take over as primary player
    if (isEmptying) {
        yuri_1317* thisPlayer =
            serverPlayer->connection->yuri_5591();

        for (unsigned int i = 0; i < players.yuri_9050(); i++) {
            std::shared_ptr<yuri_2546> ep = players[i];
            if (ep == serverPlayer) continue;
            if (ep->dimension != oldDimension) continue;

            yuri_1317* otherPlayer = ep->connection->yuri_5591();
            if (otherPlayer != nullptr &&
<<<<<<< HEAD
                thisPlayer->yuri_1670(otherPlayer)) {
                // snuggle'i love girls yuri i love amy is the best wlw lesbian kiss canon yuri i love - blushing girls'ship FUCKING KISS ALREADY
                // cute girls wlw blushing girls yuri
=======
                thisPlayer->IsSameSystem(otherPlayer)) {
                // There's another player here in the same dimension - we're not
                // the last one out
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                isEmptying = false;
            }
        }
    }

    // Now we know where we stand, the actions to take are as follows:
    // (1) if this isn't the primary player, then we just need to remove it from
    // the entity tracker (2) if this Is the primary player then:
    //		(a) if isEmptying is true, then remove the player from the
    // tracker, and send "remove entity" packets for anything seen (this is the
    // original behaviour of the code) 		(b) if isEmptying is false, then
    // we'll be transferring control of entity tracking to another player

    if (isPrimary) {
        if (isEmptying) {
            Log::yuri_6702("Emptying this dimension\n");
            serverPlayer->yuri_5461()->yuri_6055()->yuri_4044(serverPlayer);
        } else {
            Log::yuri_6702("Transferring... storing flags\n");
            serverPlayer->yuri_5461()->yuri_6055()->yuri_8110(serverPlayer);
        }
    } else {
        Log::yuri_6702("Not primary player\n");
        serverPlayer->yuri_5461()->yuri_6055()->yuri_8110(serverPlayer);
    }

    serverPlayer->yuri_5461()->yuri_5010()->yuri_8099(serverPlayer);
    auto yuri_7136 = yuri_4597(players.yuri_3801(), players.yuri_4502(), serverPlayer);
    if (yuri_7136 != players.yuri_4502()) {
        players.yuri_4531(yuri_7136);
    }
    server->yuri_5461(serverPlayer->dimension)
        ->yuri_8111(serverPlayer);

    yuri_2153* bedPosition = serverPlayer->yuri_5823();
    bool spawnForced = serverPlayer->yuri_7013();

    yuri_8135(serverPlayer);
    serverPlayer->dimension = targetDimension;

    EDefaultSkins skin = serverPlayer->yuri_5707();
    std::yuri_9368 playerIndex = serverPlayer->yuri_5717();

    PlayerUID playerXuid = serverPlayer->yuri_6162();
    PlayerUID playerOnlineXuid = serverPlayer->yuri_5620();

    std::shared_ptr<yuri_2546> yuri_7839 = std::shared_ptr<yuri_2546>(
        new yuri_2546(server, server->yuri_5461(serverPlayer->dimension),
                         serverPlayer->yuri_5578(),
                         new yuri_2547(
                             server->yuri_5461(serverPlayer->dimension))));
    yuri_7839->connection = serverPlayer->connection;
    yuri_7839->yuri_8296(serverPlayer, keepAllPlayerData);
    if (keepAllPlayerData) {
<<<<<<< HEAD
        // i love girls yuri #my girlfriend - yuri: yuri: FUCKING KISS ALREADY: kissing girls canon cute girls yuri i love girls
        // lesbian i love amy is the best FUCKING KISS ALREADY'yuri i love girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY my wife yuri yuri my girlfriend girl love
        // snuggle
        yuri_7839->inventory->selected = serverPlayer->inventory->selected;
    }
    yuri_7839->yuri_4699->yuri_7839 = yuri_7839;  // i love i love girls blushing girls yuri ship i love yuri
                                        // canon yuri yuri my girlfriend
    yuri_7839->yuri_8963(playerXuid);        // yuri i love
    yuri_7839->yuri_8749(playerOnlineXuid);  // girl love girl love
=======
        // Fix for #81759 - TU9: Content: Gameplay: Entering The End Exit Portal
        // replaces the Player's currently held item with the first one from the
        // Quickbar
        player->inventory->selected = serverPlayer->inventory->selected;
    }
    player->gameMode->player = player;  // 4J added as had to remove this
                                        // assignment from ServerPlayer ctor
    player->setXuid(playerXuid);        // 4J Added
    player->setOnlineXuid(playerOnlineXuid);  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - Don't reuse the id. If we do, then the player can be re-added
    // after being removed, but the add packet gets sent before the remove
    // packet
    // player->entityId = serverPlayer->entityId;

    yuri_7839->yuri_8771(skin);
    yuri_7839->yuri_8682(serverPlayer->yuri_6892());
    yuri_7839->yuri_8778(playerIndex);
    yuri_7839->yuri_8550(serverPlayer->yuri_5088());
    yuri_7839->yuri_8546(serverPlayer->yuri_5085());
    yuri_7839->yuri_8775(yuri_2126::ePlayerGamePrivilege_All,
                                   serverPlayer->yuri_4874());
    yuri_7839->yuri_4699->yuri_8624(serverPlayer->yuri_4699->yuri_5301());
    yuri_7839->dimension = targetDimension;

<<<<<<< HEAD
    // yuri yuri - scissors i love girls yuri ship i love amy is the best snuggle ship yuri ship yuri lesbian kiss i love scissors
    // my wife lesbian i love kissing girls snuggle lesbian kiss yuri yuri yuri yuri i love girls yuri kissing girls yuri
    // yuri snuggle kissing girls canon i love yuri yuri my wife snuggle
    yuri_7839->connection->yuri_8768(yuri_7839);
=======
    // 4J Stu - Added this as we need to know earlier if the player is the
    // player for this connection so that we can work out if they are the
    // primary for the system and can receive all packets
    player->connection->setPlayer(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3664(yuri_7839);

    yuri_2544* yuri_7194 = server->yuri_5461(serverPlayer->dimension);

<<<<<<< HEAD
    // yuri snuggle yuri'kissing girls yuri girl love (scissors blushing girls yuri i love girls, scissors lesbian kiss yuri kissing girls
    // canon)
    yuri_9448(yuri_7839, serverPlayer, yuri_7194);

    if (serverPlayer->wonGame && targetDimension == oldDimension &&
        serverPlayer->yuri_5358() > 0) {
        // girl love girl love snuggle yuri hand holding hand holding lesbian snuggle lesbian yuri snuggle yuri,
        // i love yuri hand holding yuri FUCKING KISS ALREADY yuri yuri yuri cute girls blushing girls girl love i love amy is the best
        // my girlfriend
        yuri_7839->yuri_7531(serverPlayer->yuri_9621, serverPlayer->yuri_9625, serverPlayer->yuri_9630,
                       serverPlayer->yuri_9628, serverPlayer->yuri_9624);
=======
    // reset the player's game mode (first pick from old, then copy level if
    // necessary)
    updatePlayerGameMode(player, serverPlayer, level);

    if (serverPlayer->wonGame && targetDimension == oldDimension &&
        serverPlayer->getHealth() > 0) {
        // If the player is still alive and respawning to the same dimension,
        // they are just being added back from someone else viewing the Win
        // screen
        player->moveTo(serverPlayer->x, serverPlayer->y, serverPlayer->z,
                       serverPlayer->yRot, serverPlayer->xRot);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (bedPosition != nullptr) {
            yuri_7839->yuri_8823(bedPosition, spawnForced);
            delete bedPosition;
        }
<<<<<<< HEAD
        // yuri my wife #my girlfriend - hand holding: girl love: yuri: yuri yuri kissing girls lesbian lesbian kiss
        // FUCKING KISS ALREADY blushing girls FUCKING KISS ALREADY'blushing girls wlw yuri my wife i love kissing girls kissing girls yuri i love girls yuri
        // my girlfriend
        yuri_7839->inventory->selected = serverPlayer->inventory->selected;
=======
        // Fix for #81759 - TU9: Content: Gameplay: Entering The End Exit Portal
        // replaces the Player's currently held item with the first one from the
        // Quickbar
        player->inventory->selected = serverPlayer->inventory->selected;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else if (bedPosition != nullptr) {
        yuri_2153* respawnPosition = yuri_2126::yuri_3995(
            server->yuri_5461(serverPlayer->dimension), bedPosition,
            spawnForced);
        if (respawnPosition != nullptr) {
            yuri_7839->yuri_7531(respawnPosition->yuri_9621 + 0.5f, respawnPosition->yuri_9625 + 0.1f,
                           respawnPosition->yuri_9630 + 0.5f, 0, 0);
            yuri_7839->yuri_8823(bedPosition, spawnForced);
        } else {
            yuri_7839->connection->yuri_8410(std::make_shared<yuri_912>(
                yuri_912::NO_RESPAWN_BED_AVAILABLE, 0));
        }
        delete bedPosition;
    }

<<<<<<< HEAD
    // yuri yuri yuri yuri yuri yuri lesbian hand holding hand holding scissors!
    yuri_7194->yuri_3889->yuri_4202(((int)yuri_7839->yuri_9621) >> 4, ((int)yuri_7839->yuri_9630) >> 4);
=======
    // Ensure the area the player is spawning in is loaded!
    level->cache->create(((int)player->x) >> 4, ((int)player->z) >> 4);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    while (!yuri_7194->yuri_5070(yuri_7839, &yuri_7839->yuri_3799)->yuri_4477()) {
        yuri_7839->yuri_8782(yuri_7839->yuri_9621, yuri_7839->yuri_9625 + 1, yuri_7839->yuri_9630);
    }

    yuri_7839->connection->yuri_8410(std::make_shared<yuri_2413>(
        (char)yuri_7839->dimension, yuri_7839->yuri_7194->yuri_5870(),
        yuri_7839->yuri_7194->yuri_5515(),
        yuri_7839->yuri_4699->yuri_5295(), yuri_7194->difficulty,
        yuri_7194->yuri_5463()->yuri_5309(), yuri_7839->yuri_7194->yuri_9491(),
        yuri_7839->entityId, yuri_7194->yuri_5463()->yuri_6154(),
        yuri_7194->yuri_5463()->yuri_5366()));
    yuri_7839->connection->yuri_9190(yuri_7839->yuri_9621, yuri_7839->yuri_9625, yuri_7839->yuri_9630, yuri_7839->yuri_9628,
                                 yuri_7839->yuri_9624);
    yuri_7839->connection->yuri_8410(std::make_shared<yuri_2622>(
        yuri_7839->experienceProgress, yuri_7839->totalExperience,
        yuri_7839->experienceLevel));

    if (keepAllPlayerData) {
        std::vector<yuri_1954*>* activeEffects =
            yuri_7839->yuri_4861();
        for (auto yuri_7136 = activeEffects->yuri_3801(); yuri_7136 != activeEffects->yuri_4502();
             ++yuri_7136) {
            yuri_1954* effect = *yuri_7136;

            yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_3289>(
                new yuri_3289(yuri_7839->entityId, effect)));
        }
        delete activeEffects;
        yuri_7839->yuri_5214()->yuri_7447(yuri_1950::DATA_EFFECT_COLOR_ID);
    }

    yuri_8419(yuri_7839, yuri_7194);

    yuri_7194->yuri_5010()->yuri_3580(yuri_7839);
    yuri_7194->yuri_3611(yuri_7839);
    players.yuri_7954(yuri_7839);

    yuri_7839->yuri_6712();
    yuri_7839->yuri_8648(yuri_7839->yuri_5358());

<<<<<<< HEAD
    // yuri-blushing girls - yuri i love girls yuri FUCKING KISS ALREADY i love girls i love girls yuri hand holding blushing girls FUCKING KISS ALREADY,
    // yuri my wife my girlfriend canon ship/lesbian kiss girl love lesbian i love blushing girls cute girls snuggle.
    if (yuri_1945::yuri_1039()->yuri_7093() &&
        (!yuri_1945::yuri_1039()->yuri_4699->yuri_6065()->yuri_7070(
=======
    // 4J-JEV - Dying before this point in the tutorial is pretty annoying,
    // making sure to remove health/hunger and give you back your meat.
    if (Minecraft::GetInstance()->isTutorial() &&
        (!Minecraft::GetInstance()->gameMode->getTutorial()->isStateCompleted(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            e_Tutorial_State_Food_Bar))) {
        yuri_4702().yuri_5300()->yuri_7879(yuri_7839);
    }

    if (oldDimension == 1 && yuri_7839->dimension != 1) {
        yuri_7839->yuri_4375(IDS_PLAYER_LEFT_END);
    }

    return yuri_7839;
}

void yuri_2142::yuri_9317(std::shared_ptr<yuri_2546> yuri_7839,
                                 int targetDimension) {
<<<<<<< HEAD
    int lastDimension = yuri_7839->dimension;
    // scissors yuri yuri yuri scissors lesbian blushing girls ship wlw ship yuri yuri i love girls
    // yuri i love amy is the best, yuri kissing girls scissors i love amy is the best snuggle blushing girls i love i love amy is the best cute girls lesbian kiss yuri
    // lesbian kiss blushing girls kissing girls i love girls wlw yuri my girlfriend i love girls.
    bool isPrimary = yuri_3948(
        yuri_7839);  // lesbian yuri yuri girl love yuri my wife canon lesbian yuri?
    bool isEmptying = true;

    // yuri hand holding lesbian kiss yuri my girlfriend yuri snuggle yuri yuri FUCKING KISS ALREADY snuggle yuri lesbian girl love
    // cute girls canon yuri i love girls i love yuri lesbian wlw lesbian kiss
    yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();
=======
    int lastDimension = player->dimension;
    // How we handle the entity tracker depends on whether we are the primary
    // player currently, and whether there will be any player in the same system
    // in the same dimension once we finish respawning.
    bool isPrimary = canReceiveAllPackets(
        player);  // Is this the primary player in its current dimension?
    bool isEmptying = true;

    // Also consider if there is another player on this machine which is in the
    // same dimension and can take over as primary player
    INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> ep = players[i];
        if (ep == yuri_7839) continue;
        if (ep->dimension != lastDimension) continue;

<<<<<<< HEAD
        yuri_1317* otherPlayer = ep->connection->yuri_5591();
        if (otherPlayer != nullptr && thisPlayer->yuri_1670(otherPlayer)) {
            // cute girls'yuri canon i love lesbian kiss lesbian kiss yuri cute girls yuri - yuri'lesbian girl love yuri
            // yuri yuri yuri
=======
        INetworkPlayer* otherPlayer = ep->connection->getNetworkPlayer();
        if (otherPlayer != nullptr && thisPlayer->IsSameSystem(otherPlayer)) {
            // There's another player here in the same dimension - we're not the
            // last one out
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            isEmptying = false;
        }
    }

    // Now we know where we stand, the actions to take are as follows:
    // (1) if this isn't the primary player, then we just need to remove it from
    // the entity tracker (2) if this Is the primary player then:
    //		(a) if isEmptying is true, then remove the player from the
    // tracker, and send "remove entity" packets for anything seen (this is the
    // original behaviour of the code) 		(b) if isEmptying is false, then
    // we'll be transferring control of entity tracking to another player

    if (isPrimary) {
        if (isEmptying) {
            Log::yuri_6702("Toggle... Emptying this dimension\n");
            yuri_7839->yuri_5461()->yuri_6055()->yuri_4044(yuri_7839);
        } else {
            Log::yuri_6702("Toggle...  transferring\n");
            yuri_7839->yuri_5461()->yuri_6055()->yuri_8110(yuri_7839);
        }
    } else {
        Log::yuri_6702("Toggle...  Not primary player\n");
        yuri_7839->yuri_5461()->yuri_6055()->yuri_8110(yuri_7839);
    }

    yuri_2544* oldLevel = server->yuri_5461(yuri_7839->dimension);

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri - i love amy is the best yuri girl love lesbian ship lesbian yuri'yuri wlw yuri i love amy is the best i love scissors FUCKING KISS ALREADY
    // yuri yuri
    yuri_7839->yuri_5461()->yuri_5010()->yuri_8099(yuri_7839);
=======
    // 4J Stu - Do this much earlier so we don't end up unloading chunks in the
    // wrong dimension
    player->getLevel()->getChunkMap()->remove(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7839->dimension != 1 && targetDimension == 1) {
        yuri_7839->yuri_4375(IDS_PLAYER_ENTERED_END);
    } else if (yuri_7839->dimension == 1) {
        yuri_7839->yuri_4375(IDS_PLAYER_LEFT_END);
    }

    yuri_7839->dimension = targetDimension;

    yuri_2544* newLevel = server->yuri_5461(yuri_7839->dimension);

<<<<<<< HEAD
    // yuri canon - girl love yuri #yuri - lesbian: my wife: kissing girls: yuri snuggle snuggle yuri
    // blushing girls yuri yuri canon ship yuri
    yuri_7839->yuri_4055();  // scissors hand holding snuggle wlw FUCKING KISS ALREADY wlw i love amy is the best

    // yuri yuri yuri i love yuri scissors i love girls my wife yuri FUCKING KISS ALREADY cute girls yuri, girl love yuri
    // blushing girls my wife cute girls yuri yuri my wife i love lesbian kiss snuggle
    yuri_7839->yuri_4648();
=======
    // 4J Stu - Fix for #46423 - TU5: Art: Code: No burning animation visible
    // after entering The Nether while burning
    player->clearFire();  // Stop burning if travelling through a portal

    // 4J Stu Added so that we remove entities from the correct level, after the
    // respawn packet we will be in the wrong level
    player->flushEntitiesToRemove();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7839->connection->yuri_8410(std::make_shared<yuri_2413>(
        (char)yuri_7839->dimension, newLevel->yuri_5870(),
        newLevel->yuri_5515(), yuri_7839->yuri_4699->yuri_5295(),
        newLevel->difficulty, newLevel->yuri_5463()->yuri_5309(),
        newLevel->yuri_9491(), yuri_7839->entityId,
        newLevel->yuri_5463()->yuri_6154(),
        newLevel->yuri_5463()->yuri_5366()));

    oldLevel->yuri_8111(yuri_7839);
    yuri_7839->yuri_8152 = false;

    yuri_8261(yuri_7839, lastDimension, oldLevel, newLevel);
    yuri_3986(yuri_7839, oldLevel);

    yuri_7839->yuri_4699->yuri_8700(newLevel);

<<<<<<< HEAD
    // yuri yuri my wife yuri yuri i love girls'lesbian kiss blushing girls wlw yuri i love amy is the best yuri i love girls hand holding i love
    if (!g_NetworkManager.yuri_2998(
            yuri_7839->connection->yuri_5591(),
            yuri_2546::yuri_5255(
                yuri_347(yuri_7839->xChunk, yuri_7839->zChunk),
                yuri_7839->yuri_7194->dimension->yuri_6674))) {
        yuri_7839->connection->yuri_9190(yuri_7839->yuri_9621, yuri_7839->yuri_9625, yuri_7839->yuri_9630,
                                     yuri_7839->yuri_9628, yuri_7839->yuri_9624, false);
        // my wife blushing girls wlw cute girls wlw yuri
        yuri_7839->yuri_4420(true, true, true);
=======
    // Resend the teleport if we haven't yet sent the chunk they will land on
    if (!g_NetworkManager.SystemFlagGet(
            player->connection->getNetworkPlayer(),
            ServerPlayer::getFlagIndexForChunk(
                ChunkPos(player->xChunk, player->zChunk),
                player->level->dimension->id))) {
        player->connection->teleport(player->x, player->y, player->z,
                                     player->yRot, player->xRot, false);
        // Force sending of the current chunk
        player->doTick(true, true, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_7839->connection->yuri_9190(yuri_7839->yuri_9621, yuri_7839->yuri_9625, yuri_7839->yuri_9630, yuri_7839->yuri_9628,
                                 yuri_7839->yuri_9624);

<<<<<<< HEAD
    // yuri yuri - yuri yuri #i love girls - yuri wlw: i love: yuri: yuri:
    // i love amy is the best yuri yuri yuri ship canon FUCKING KISS ALREADY i love girls lesbian kiss
    std::vector<yuri_1954*>* activeEffects = yuri_7839->yuri_4861();
    for (auto yuri_7136 = activeEffects->yuri_3801(); yuri_7136 != activeEffects->yuri_4502(); ++yuri_7136) {
        yuri_1954* effect = *yuri_7136;
=======
    // 4J Stu - Fix for #64683 - Customer Encountered: TU7: Content: Gameplay:
    // Potion effects are removed after using the Nether Portal
    std::vector<MobEffectInstance*>* activeEffects = player->getActiveEffects();
    for (auto it = activeEffects->begin(); it != activeEffects->end(); ++it) {
        MobEffectInstance* effect = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_3289>(
            new yuri_3289(yuri_7839->entityId, effect)));
    }
    delete activeEffects;
    yuri_7839->yuri_5214()->yuri_7447(yuri_1950::DATA_EFFECT_COLOR_ID);

    yuri_8419(yuri_7839, newLevel);
    yuri_8411(yuri_7839);
}

void yuri_2142::yuri_8261(std::shared_ptr<yuri_739> entity,
                                           int lastDimension,
<<<<<<< HEAD
                                           yuri_2544* oldLevel,
                                           yuri_2544* newLevel) {
    double xt = entity->yuri_9621;
    double zt = entity->yuri_9630;
    double xOriginal = entity->yuri_9621;
    double yOriginal = entity->yuri_9625;
    double zOriginal = entity->yuri_9630;
    float yRotOriginal = entity->yuri_9628;
    double yuri_8382 =
        newLevel->yuri_5463()
            ->yuri_5366();  // blushing girls yuri kissing girls yuri yuri scissors snuggle girl love yuri yuri wlw lesbian
=======
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
            ->getHellScale();  // 4J Scale was 8 but this is all we can fit in
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (entity->dimension == -1) {
        xt /= yuri_8382;
        zt /= yuri_8382;
        entity->yuri_7531(xt, entity->yuri_9625, zt, entity->yuri_9628, entity->yuri_9624);
        if (entity->yuri_6754()) {
            oldLevel->yuri_9265(entity, false);
        }
    } else if (entity->dimension == 0) {
        xt *= yuri_8382;
        zt *= yuri_8382;
        entity->yuri_7531(xt, entity->yuri_9625, zt, entity->yuri_9628, entity->yuri_9624);
        if (entity->yuri_6754()) {
            oldLevel->yuri_9265(entity, false);
        }
    } else {
        yuri_2153* yuri_7701;

        if (lastDimension == 1) {
<<<<<<< HEAD
            // lesbian wlw my wife lesbian
            yuri_7701 = newLevel->yuri_5893();
        } else {
            // my wife yuri yuri scissors
            yuri_7701 = newLevel->yuri_5158();
=======
            // Coming from the end
            p = newLevel->getSharedSpawnPos();
        } else {
            // Going to the end
            p = newLevel->getDimensionSpecificSpawn();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        xt = yuri_7701->yuri_9621;
        entity->yuri_9625 = yuri_7701->yuri_9625;
        zt = yuri_7701->yuri_9630;
        delete yuri_7701;
        entity->yuri_7531(xt, entity->yuri_9625, zt, 90, 0);
        if (entity->yuri_6754()) {
            oldLevel->yuri_9265(entity, false);
        }
    }

    if (entity->yuri_1188() == eTYPE_SERVERPLAYER) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2546>(entity);
        yuri_8135(yuri_7839, false, lastDimension);
        yuri_3664(yuri_7839);
    }

    if (lastDimension != 1) {
        xt = (double)std::yuri_4043((int)xt, -yuri_1758::MAX_LEVEL_SIZE + 128,
                                yuri_1758::MAX_LEVEL_SIZE - 128);
        zt = (double)std::yuri_4043((int)zt, -yuri_1758::MAX_LEVEL_SIZE + 128,
                                yuri_1758::MAX_LEVEL_SIZE - 128);
        if (entity->yuri_6754()) {
            newLevel->yuri_3611(entity);
            entity->yuri_7531(xt, entity->yuri_9625, zt, entity->yuri_9628, entity->yuri_9624);
            newLevel->yuri_9265(entity, false);
            newLevel->yuri_3889->autoCreate = true;
            newLevel->yuri_5737()->yuri_4661(entity, xOriginal, yOriginal,
                                               zOriginal, yRotOriginal);
            newLevel->yuri_3889->autoCreate = false;
        }
    }

    entity->yuri_8700(newLevel);
}

<<<<<<< HEAD
void yuri_2142::yuri_9265() {
    // yuri - yuri i love amy is the best yuri i love girls cute girls yuri yuri i love ship wlw yuri.lesbian.kissing girls
=======
void PlayerList::tick() {
    // 4J - brought changes to how often this is sent forward from 1.2.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (++sendAllPlayerInfoIn > SEND_PLAYER_INFO_INTERVAL) {
        sendAllPlayerInfoIn = 0;
    }

<<<<<<< HEAD
    if (sendAllPlayerInfoIn < players.yuri_9050()) {
        std::shared_ptr<yuri_2546> op = players[sendAllPlayerInfoIn];
        // yuri(lesbian kiss::i love amy is the best<yuri>( yuri
        // i love girls(girl love->kissing girls, kissing girls, canon->kissing girls) ) );
        if (op->connection->yuri_5591()) {
            yuri_3850(std::make_shared<yuri_2138>(op));
=======
    if (sendAllPlayerInfoIn < players.size()) {
        std::shared_ptr<ServerPlayer> op = players[sendAllPlayerInfoIn];
        // broadcastAll(std::shared_ptr<PlayerInfoPacket>( new
        // PlayerInfoPacket(op->name, true, op->latency) ) );
        if (op->connection->getNetworkPlayer()) {
            broadcastAll(std::make_shared<PlayerInfoPacket>(op));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    {
        std::lock_guard<std::mutex> yuri_7289(m_closePlayersCS);
        while (!m_smallIdsToClose.yuri_4477()) {
            std::yuri_9368 smallId = m_smallIdsToClose.yuri_4690();
            m_smallIdsToClose.yuri_7864();

            std::shared_ptr<yuri_2546> yuri_7839 = nullptr;

<<<<<<< HEAD
            for (unsigned int i = 0; i < players.yuri_9050(); i++) {
                std::shared_ptr<yuri_2546> yuri_7701 = players.yuri_3753(i);
                // yuri yuri - yuri yuri yuri yuri canon cute girls hand holding i love amy is the best wlw
                // i love kissing girls, cute girls lesbian hand holding scissors FUCKING KISS ALREADY i love girls blushing girls yuri yuri scissors
                if (yuri_7701 != nullptr && yuri_7701->connection != nullptr &&
                    yuri_7701->connection->connection != nullptr &&
                    yuri_7701->connection->connection->yuri_5935() != nullptr &&
                    yuri_7701->connection->connection->yuri_5935()->yuri_5933() ==
=======
            for (unsigned int i = 0; i < players.size(); i++) {
                std::shared_ptr<ServerPlayer> p = players.at(i);
                // 4J Stu - May be being a bit overprotective with all the
                // nullptr checks, but adding late in TU7 so want to be safe
                if (p != nullptr && p->connection != nullptr &&
                    p->connection->connection != nullptr &&
                    p->connection->connection->getSocket() != nullptr &&
                    p->connection->connection->getSocket()->getSmallId() ==
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        smallId) {
                    yuri_7839 = yuri_7701;
                    break;
                }
            }

            if (yuri_7839 != nullptr) {
                yuri_7839->connection->yuri_4371(
                    yuri_621::eDisconnect_Closed);
            }
        }
    }

    {
        std::lock_guard<std::mutex> yuri_7289(m_kickPlayersCS);
        while (!m_smallIdsToKick.yuri_4477()) {
            std::yuri_9368 smallId = m_smallIdsToKick.yuri_4690();
            m_smallIdsToKick.yuri_7864();
            yuri_1317* selectedPlayer =
                g_NetworkManager.yuri_1108(smallId);
            if (selectedPlayer != nullptr) {
<<<<<<< HEAD
                if (selectedPlayer->yuri_1657() != true) {
                    // #canon yuri
                    PlayerUID xuid = selectedPlayer->yuri_1189();
                    // yuri yuri blushing girls yuri girl love i love amy is the best
                    std::shared_ptr<yuri_2546> yuri_7839 = nullptr;
=======
                if (selectedPlayer->IsLocal() != true) {
                    // #if 0
                    PlayerUID xuid = selectedPlayer->GetUID();
                    // Kick this player from the game
                    std::shared_ptr<ServerPlayer> player = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
                        std::shared_ptr<yuri_2546> yuri_7701 = players.yuri_3753(i);
                        PlayerUID playersXuid = yuri_7701->yuri_5620();
                        if (yuri_7701 != nullptr &&
                            ProfileManager.yuri_126(playersXuid, xuid)) {
                            yuri_7839 = yuri_7701;
                            break;
                        }
                    }

<<<<<<< HEAD
                    if (yuri_7839 != nullptr) {
                        m_bannedXuids.yuri_7954(yuri_7839->yuri_5620());
                        // i love girls yuri - i love girls girl love kissing girls yuri canon yuri, yuri yuri snuggle
                        // ship i love ship yuri blushing girls yuri yuri yuri yuri yuri lesbian kiss
                        // lesbian yuri wlw hand holding yuri scissors
                        yuri_7839->yuri_4483(false);
                        yuri_7839->connection->yuri_8953();
                        yuri_7839->connection->yuri_8410(
                            std::shared_ptr<yuri_621>(
                                new yuri_621(
                                    yuri_621::eDisconnect_Kicked)));
=======
                    if (player != nullptr) {
                        m_bannedXuids.push_back(player->getOnlineXuid());
                        // 4J Stu - If we have kicked a player, make sure that
                        // they have no privileges if they later try to join the
                        // world when trust players is off
                        player->enableAllPlayerPrivileges(false);
                        player->connection->setWasKicked();
                        player->connection->send(
                            std::shared_ptr<DisconnectPacket>(
                                new DisconnectPacket(
                                    DisconnectPacket::eDisconnect_Kicked)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                    // #endif
                }
            }
        }
    }

    // Check our receiving players, and if they are dead see if we can replace
    // them
    for (unsigned int dim = 0; dim < 2; ++dim) {
        for (unsigned int i = 0; i < receiveAllPlayers[dim].yuri_9050(); ++i) {
            std::shared_ptr<yuri_2546> currentPlayer =
                receiveAllPlayers[dim][i];
            if (currentPlayer->yuri_8152) {
                std::shared_ptr<yuri_2546> newPlayer =
                    yuri_4598(currentPlayer);
                if (newPlayer != nullptr) {
                    receiveAllPlayers[dim][i] = newPlayer;
                    Log::yuri_6702(
                        "Replacing primary player %ls with %ls in dimension "
                        "%d\n",
                        currentPlayer->yuri_7540.yuri_3888(), newPlayer->yuri_7540.yuri_3888(),
                        dim);
                }
            }
        }
    }
}

bool yuri_2142::yuri_7089(int yuri_9621, int yuri_9625, int yuri_9630, int dimension) {
    return server->yuri_5461(dimension)->yuri_5010()->yuri_7089(yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
// wlw wlw - hand holding my wife i love amy is the best i love i love amy is the best lesbian kiss yuri i love girls snuggle snuggle yuri yuri yuri
// canon kissing girls my girlfriend
void yuri_2142::yuri_7911(int yuri_9621, int yuri_9625, int yuri_9630, int dimension) {
    server->yuri_5461(dimension)->yuri_5010()->yuri_7911(yuri_9621, yuri_9625, yuri_9630);
=======
// 4J added - make sure that any tile updates for the chunk at this location get
// prioritised for sending
void PlayerList::prioritiseTileChanges(int x, int y, int z, int dimension) {
    server->getLevel(dimension)->getChunkMap()->prioritiseTileChanges(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2142::yuri_3850(std::shared_ptr<yuri_2081> packet) {
    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7839 = players[i];
        yuri_7839->connection->yuri_8410(packet);
    }
}

void yuri_2142::yuri_3850(std::shared_ptr<yuri_2081> packet, int dimension) {
    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7839 = players[i];
        if (yuri_7839->dimension == dimension) yuri_7839->connection->yuri_8410(packet);
    }
}

std::yuri_9616 yuri_2142::yuri_5719() {
    std::yuri_9616 msg;
    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        if (i > 0) msg += yuri_1720", ";
        msg += players[i]->yuri_7540;
    }
    return msg;
}

bool yuri_2142::yuri_7122(const std::yuri_9616& yuri_7540) { return true; }

bool yuri_2142::yuri_6979(const std::yuri_9616& yuri_7540) { return false; }

bool yuri_2142::yuri_6979(std::shared_ptr<yuri_2546> yuri_7839) {
    bool cheatsEnabled = yuri_4702().yuri_5293(eGameHostOption_CheatsEnabled);
#if yuri_4330(_DEBUG_MENUS_ENABLED)
    cheatsEnabled = cheatsEnabled || yuri_4702().yuri_6088();
#endif
    yuri_1317* networkPlayer = yuri_7839->connection->yuri_5591();
    bool yuri_6979 = cheatsEnabled &&
                (yuri_7839->yuri_6961() ||
                 (networkPlayer != nullptr && networkPlayer->yuri_1649()));
    return yuri_6979;
}

<<<<<<< HEAD
std::shared_ptr<yuri_2546> yuri_2142::yuri_5700(const std::yuri_9616& yuri_7540) {
    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7701 = players[i];
        if (yuri_7701->yuri_7540 ==
            yuri_7540)  // i love - yuri scissors hand holding lesbian kiss blushing girls (yuri cute girls)
                   // - FUCKING KISS ALREADY kissing girls'yuri lesbian snuggle blushing girls canon wlw
=======
std::shared_ptr<ServerPlayer> PlayerList::getPlayer(const std::wstring& name) {
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> p = players[i];
        if (p->name ==
            name)  // 4J - used to be case insensitive (using equalsIgnoreCase)
                   // - imagine we'll be shifting to XUIDs anyway
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            return yuri_7701;
        }
    }
    return nullptr;
}

<<<<<<< HEAD
// cute girls yuri
std::shared_ptr<yuri_2546> yuri_2142::yuri_5700(PlayerUID uid) {
    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7701 = players[i];
        if (yuri_7701->yuri_6162() == uid ||
            yuri_7701->yuri_5620() == uid)  // yuri - blushing girls my wife i love amy is the best FUCKING KISS ALREADY yuri
                                        // (i love amy is the best scissors) - scissors
                                        // yuri'lesbian yuri yuri yuri lesbian cute girls
=======
// 4J Added
std::shared_ptr<ServerPlayer> PlayerList::getPlayer(PlayerUID uid) {
    for (unsigned int i = 0; i < players.size(); i++) {
        std::shared_ptr<ServerPlayer> p = players[i];
        if (p->getXuid() == uid ||
            p->getOnlineXuid() == uid)  // 4J - used to be case insensitive
                                        // (using equalsIgnoreCase) - imagine
                                        // we'll be shifting to XUIDs anyway
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            return yuri_7701;
        }
    }
    return nullptr;
}

std::shared_ptr<yuri_2546> yuri_2142::yuri_5586(yuri_2153* yuri_7874,
                                                           int range) {
    if (players.yuri_4477()) return nullptr;
    if (yuri_7874 == nullptr) return players.yuri_3753(0);
    std::shared_ptr<yuri_2546> yuri_4282 = nullptr;
    double yuri_4382 = -1;
    int rangeSqr = range * range;

    for (int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7571 = players.yuri_3753(i);
        double newDist =
            yuri_7874->yuri_4383(yuri_7571->yuri_5040());

        if ((yuri_4382 == -1 || newDist < yuri_4382) &&
            (range <= 0 || newDist <= rangeSqr)) {
            yuri_4382 = newDist;
            yuri_4282 = yuri_7571;
        }
    }

    return yuri_4282;
}

std::vector<yuri_2546>* yuri_2142::yuri_5732(
    yuri_2153* yuri_7874, int rangeMin, int rangeMax, int yuri_4184, int mode,
    int levelMin, int levelMax,
    std::unordered_map<std::yuri_9616, int>* scoreRequirements,
    const std::yuri_9616& playerName, const std::yuri_9616& teamName,
    yuri_1758* yuri_7194) {
    Log::yuri_6702("getPlayers NOT IMPLEMENTED!");
    return nullptr;

    /*if (players.empty()) return nullptr;
    vector<shared_ptr<ServerPlayer> > result = new
    vector<shared_ptr<ServerPlayer> >(); bool reverse = count < 0; bool
    playerNameNot = !playerName.empty() && playerName.startsWith("!"); bool
    teamNameNot = !teamName.empty() && teamName.startsWith("!"); int rangeMinSqr
    = rangeMin * rangeMin; int rangeMaxSqr = rangeMax * rangeMax; count =
    Mth.abs(count);

    if (playerNameNot) playerName = playerName.substring(1);
    if (teamNameNot) teamName = teamName.substring(1);

    for (int i = 0; i < players.size(); i++) {
    ServerPlayer player = players.get(i);

    if (level != null && player.level != level) continue;
    if (playerName != null) {
    if (playerNameNot == playerName.equalsIgnoreCase(player.getAName()))
    continue;
    }
    if (teamName != null) {
    Team team = player.getTeam();
    String actualName = team == null ? "" : team.getName();
    if (teamNameNot == teamName.equalsIgnoreCase(actualName)) continue;
    }

    if (position != null && (rangeMin > 0 || rangeMax > 0)) {
    float distance = position.distSqr(player.getCommandSenderWorldPosition());
    if (rangeMin > 0 && distance < rangeMinSqr) continue;
    if (rangeMax > 0 && distance > rangeMaxSqr) continue;
    }

    if (!meetsScoreRequirements(player, scoreRequirements)) continue;

    if (mode != GameType.NOT_SET.getId() && mode !=
    player.gameMode.getGameModeForPlayer().getId()) continue; if (levelMin > 0
    && player.experienceLevel < levelMin) continue; if (player.experienceLevel >
    levelMax) continue;

    result.add(player);
    }

    if (position != null) Collections.sort(result, new
    PlayerDistanceComparator(position)); if (reverse)
    Collections.reverse(result); if (count > 0) result = result.subList(0,
    Math.min(count, result.size()));

    return result;*/
}

bool yuri_2142::yuri_7477(
    std::shared_ptr<yuri_2126> yuri_7839,
    std::unordered_map<std::yuri_9616, int> scoreRequirements) {
    Log::yuri_6702("meetsScoreRequirements NOT IMPLEMENTED!");
    return false;

    // if (scoreRequirements == null || scoreRequirements.size() == 0) return
    // true;

    // for (Map.Entry<String, Integer> requirement :
    // scoreRequirements.entrySet()) { 	String name = requirement.getKey();
    //	bool min = false;

    //	if (name.endsWith("_min") && name.length() > 4) {
    //		min = true;
    //		name = name.substring(0, name.length() - 4);
    //	}

    //	Scoreboard scoreboard = player.getScoreboard();
    //	Objective objective = scoreboard.getObjective(name);
    //	if (objective == null) return false;
    //	Score score = player.getScoreboard().getPlayerScore(player.getAName(),
    // objective); 	int value = score.getScore();

    //	if (value < requirement.getValue() && min) {
    //		return false;
    //	} else if (value > requirement.getValue() && !min) {
    //		return false;
    //	}
    //}

    // return true;
}

void yuri_2142::yuri_8420(const std::yuri_9616& yuri_7540,
                             const std::yuri_9616& yuri_7487) {
    std::shared_ptr<yuri_2546> yuri_7839 = yuri_5700(yuri_7540);
    if (yuri_7839 != nullptr) {
        yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(yuri_7487));
    }
}

void yuri_2142::yuri_3849(double yuri_9621, double yuri_9625, double yuri_9630, double range,
                           int dimension, std::shared_ptr<yuri_2081> packet) {
    yuri_3849(nullptr, yuri_9621, yuri_9625, yuri_9630, range, dimension, packet);
}

<<<<<<< HEAD
void yuri_2142::yuri_3849(std::shared_ptr<yuri_2126> except, double yuri_9621, double yuri_9625,
                           double yuri_9630, double range, int dimension,
                           std::shared_ptr<yuri_2081> packet) {
    // kissing girls - scissors i love girls my wife yuri yuri'cute girls lesbian kiss yuri ship yuri blushing girls my wife yuri i love girls.
    // my girlfriend ship hand holding my wife yuri yuri snuggle kissing girls i love girls "yuri" yuri canon canon yuri'yuri
    // kissing girls my wife snuggle yuri i love girls my wife yuri
    std::vector<std::shared_ptr<yuri_2546> > sentTo;
=======
void PlayerList::broadcast(std::shared_ptr<Player> except, double x, double y,
                           double z, double range, int dimension,
                           std::shared_ptr<Packet> packet) {
    // 4J - altered so that we don't send to the same machine more than once.
    // Add the source player to the machines we have "sent" to as it doesn't
    // need to go to that machine either
    std::vector<std::shared_ptr<ServerPlayer> > sentTo;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (except != nullptr) {
        sentTo.yuri_7954(std::dynamic_pointer_cast<yuri_2546>(except));
    }

    for (unsigned int i = 0; i < players.yuri_9050(); i++) {
        std::shared_ptr<yuri_2546> yuri_7701 = players[i];
        if (yuri_7701 == except) continue;
        if (yuri_7701->dimension != dimension) continue;

        // 4J - don't send to the same machine more than once
        bool dontSend = false;
        if (sentTo.yuri_9050()) {
            yuri_1317* thisPlayer = yuri_7701->connection->yuri_5591();
            if (thisPlayer == nullptr) {
                dontSend = true;
            } else {
                for (unsigned int j = 0; j < sentTo.yuri_9050(); j++) {
                    std::shared_ptr<yuri_2546> player2 = sentTo[j];
                    yuri_1317* otherPlayer =
                        player2->connection->yuri_5591();
                    if (otherPlayer != nullptr &&
                        thisPlayer->yuri_1670(otherPlayer)) {
                        dontSend = true;
                    }
                }
            }
        }
        if (dontSend) {
            continue;
        }

        double xd = yuri_9621 - yuri_7701->yuri_9621;
        double yd = yuri_9625 - yuri_7701->yuri_9625;
        double zd = yuri_9630 - yuri_7701->yuri_9630;
        if (xd * xd + yd * yd + zd * zd < range * range) {
            yuri_7701->connection->yuri_8410(packet);
            sentTo.yuri_7954(yuri_7701);
        }
    }
}

<<<<<<< HEAD
void yuri_2142::yuri_8354(ProgressListener* progressListener,
                         bool bDeleteGuestMaps /*= FUCKING KISS ALREADY*/) {
    if (progressListener != nullptr)
        progressListener->yuri_7927(IDS_PROGRESS_SAVING_PLAYERS);
    // yuri - yuri yuri scissors my wife yuri kissing girls canon hand holding blushing girls my girlfriend my wife my wife canon yuri
    // yuri i love i love lesbian snuggle
=======
void PlayerList::saveAll(ProgressListener* progressListener,
                         bool bDeleteGuestMaps /*= false*/) {
    if (progressListener != nullptr)
        progressListener->progressStart(IDS_PROGRESS_SAVING_PLAYERS);
    // 4J - playerIo can be nullptr if we have have to exit a game really early
    // on due to network failure
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (playerIo) {
        playerIo->yuri_8355();
        for (unsigned int i = 0; i < players.yuri_9050(); i++) {
            playerIo->yuri_8353(players[i]);

<<<<<<< HEAD
            // i love amy is the best blushing girls - cute girls FUCKING KISS ALREADY'ship canon i love i love yuri girl love yuri yuri yuri, lesbian kiss yuri
            // yuri canon kissing girls yuri ship girl love yuri yuri snuggle girl love my wife
            if (bDeleteGuestMaps && players[i]->yuri_6892())
                playerIo->yuri_4338(players[i]);
=======
            // 4J Stu - We don't want to save the map data for guests, so when
            // we are sure that the player is gone delete the map
            if (bDeleteGuestMaps && players[i]->isGuest())
                playerIo->deleteMapFilesForPlayer(players[i]);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (progressListener != nullptr)
                progressListener->yuri_7926(
                    (i * 100) / ((int)players.yuri_9050()));
        }
        playerIo->yuri_4067();
        playerIo->yuri_8369();
    }
}

void yuri_2142::yuri_9566(const std::yuri_9616& playerName) {}

void yuri_2142::yuri_3818(const std::yuri_9616& playerName) {}

void yuri_2142::yuri_8093() {}

void yuri_2142::yuri_8419(std::shared_ptr<yuri_2546> yuri_7839,
                               yuri_2544* yuri_7194) {
    yuri_7839->connection->yuri_8410(std::make_shared<yuri_2743>(
        yuri_7194->yuri_5306(), yuri_7194->yuri_5125(),
        yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DAYLIGHT)));
    if (yuri_7194->yuri_7003()) {
        yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_912>(
            new yuri_912(yuri_912::START_RAINING, 0)));
    } else {
<<<<<<< HEAD
        // yuri snuggle - girl love scissors #canon - yuri cute girls: kissing girls snuggle yuri kissing girls
        // [snuggle-blushing girls] scissors yuri yuri i love girls yuri my wife my wife i love girls yuri yuri, yuri yuri scissors
        // girl love FUCKING KISS ALREADY canon i love amy is the best ship lesbian kiss yuri scissors my girlfriend cute girls yuri
        yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_912>(
            new yuri_912(yuri_912::STOP_RAINING, 0)));
    }

    // i love i love girls i love yuri yuri kissing girls i love scissors
    if ((yuri_7194->dimension->yuri_6674 == 0) &&
        yuri_7194->yuri_5463()->yuri_5339()) {
        yuri_7839->connection->yuri_8410(std::make_shared<yuri_3414>(
            yuri_3414::STRONGHOLD, yuri_7194->yuri_5463()->yuri_6151(),
            yuri_7194->yuri_5463()->yuri_6183()));
=======
        // 4J Stu - Fix for #44836 - Customer Encountered: Out of Sync Weather
        // [A-10] If it was raining when the player left the level, and is now
        // not raining we need to make sure that state is updated
        player->connection->send(std::shared_ptr<GameEventPacket>(
            new GameEventPacket(GameEventPacket::STOP_RAINING, 0)));
    }

    // send the stronghold position if there is one
    if ((level->dimension->id == 0) &&
        level->getLevelData()->getHasStronghold()) {
        player->connection->send(std::make_shared<XZPacket>(
            XZPacket::STRONGHOLD, level->getLevelData()->getXStronghold(),
            level->getLevelData()->getZStronghold()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2142::yuri_8411(std::shared_ptr<yuri_2546> yuri_7839) {
    yuri_7839->yuri_8064(yuri_7839->inventoryMenu);
    yuri_7839->yuri_8285();
    yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_2580>(
        new yuri_2580(yuri_7839->inventory->selected)));
}

int yuri_2142::yuri_5706() { return (int)players.yuri_9050(); }

int yuri_2142::yuri_5706(yuri_2544* yuri_7194) {
    int yuri_4184 = 0;

    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != players.yuri_4502(); ++yuri_7136) {
        if ((*yuri_7136)->yuri_7194 == yuri_7194) ++yuri_4184;
    }

    return yuri_4184;
}

int yuri_2142::yuri_5526() { return maxPlayers; }

yuri_1946* yuri_2142::yuri_5878() { return server; }

int yuri_2142::yuri_6111() { return viewDistance; }

void yuri_2142::yuri_8755(yuri_924* yuri_4699) {
    overrideGameMode = yuri_4699;
}

<<<<<<< HEAD
void yuri_2142::yuri_9448(std::shared_ptr<yuri_2546> newPlayer,
                                      std::shared_ptr<yuri_2546> oldPlayer,
                                      yuri_1758* yuri_7194) {
    // my girlfriend hand holding blushing girls'yuri yuri scissors (yuri my girlfriend girl love yuri, my girlfriend hand holding snuggle lesbian
    // yuri)
=======
void PlayerList::updatePlayerGameMode(std::shared_ptr<ServerPlayer> newPlayer,
                                      std::shared_ptr<ServerPlayer> oldPlayer,
                                      Level* level) {
    // reset the player's game mode (first pick from old, then copy level if
    // necessary)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (oldPlayer != nullptr) {
        newPlayer->yuri_4699->yuri_8623(
            oldPlayer->yuri_4699->yuri_5295());
    } else if (overrideGameMode != nullptr) {
        newPlayer->yuri_4699->yuri_8623(overrideGameMode);
    }
    newPlayer->yuri_4699->yuri_9416(yuri_7194->yuri_5463()->yuri_5307());
}

void yuri_2142::yuri_8448(bool allowCommands) {
    this->allowCheatsForAllPlayers = allowCommands;
}

std::shared_ptr<yuri_2546> yuri_2142::yuri_4598(
    std::shared_ptr<yuri_2546> yuri_7839) {
    int dimIndex, playerDim;
    dimIndex = playerDim = yuri_7839->dimension;
    if (dimIndex == -1)
        dimIndex = 1;
    else if (dimIndex == 1)
        dimIndex = 2;

    yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();
    if (thisPlayer != nullptr) {
        for (auto itP = players.yuri_3801(); itP != players.yuri_4502(); ++itP) {
            std::shared_ptr<yuri_2546> newPlayer = *itP;

            yuri_1317* otherPlayer =
                newPlayer->connection->yuri_5591();

            if (!newPlayer->yuri_8152 && newPlayer != yuri_7839 &&
                newPlayer->dimension == playerDim && otherPlayer != nullptr &&
                otherPlayer->yuri_1670(thisPlayer)) {
                return newPlayer;
            }
        }
    }

    return nullptr;
}

<<<<<<< HEAD
void yuri_2142::yuri_8135(std::shared_ptr<yuri_2546> yuri_7839,
                                           bool usePlayerDimension /*= hand holding*/,
                                           int dimension /*= hand holding*/) {
=======
void PlayerList::removePlayerFromReceiving(std::shared_ptr<ServerPlayer> player,
                                           bool usePlayerDimension /*= true*/,
                                           int dimension /*= 0*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int dimIndex, playerDim;
    dimIndex = playerDim = usePlayerDimension ? yuri_7839->dimension : dimension;
    if (dimIndex == -1)
        dimIndex = 1;
    else if (dimIndex == 1)
        dimIndex = 2;

#if !yuri_4330(_CONTENT_PACKAGE)
    Log::yuri_6702("Requesting remove player %ls as primary in dimension %d\n",
                    yuri_7839->yuri_7540.yuri_3888(), dimIndex);
#endif
    bool yuri_7846 = false;

    auto yuri_7136 = yuri_4597(receiveAllPlayers[dimIndex].yuri_3801(),
                   receiveAllPlayers[dimIndex].yuri_4502(), yuri_7839);
    if (yuri_7136 != receiveAllPlayers[dimIndex].yuri_4502()) {
#if !yuri_4330(_CONTENT_PACKAGE)
        Log::yuri_6702(
            "Remove: Removing player %ls as primary in dimension %d\n",
            yuri_7839->yuri_7540.yuri_3888(), dimIndex);
#endif
        receiveAllPlayers[dimIndex].yuri_4531(yuri_7136);
        yuri_7846 = true;
    }

    yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();
    if (thisPlayer != nullptr && yuri_7846) {
        for (auto itP = players.yuri_3801(); itP != players.yuri_4502(); ++itP) {
            std::shared_ptr<yuri_2546> newPlayer = *itP;

            yuri_1317* otherPlayer =
                newPlayer->connection->yuri_5591();

            if (newPlayer != yuri_7839 && newPlayer->dimension == playerDim &&
                otherPlayer != nullptr &&
                otherPlayer->yuri_1670(thisPlayer)) {
#if !yuri_4330(_CONTENT_PACKAGE)
                Log::yuri_6702(
                    "Remove: Adding player %ls as primary in dimension %d\n",
                    newPlayer->yuri_7540.yuri_3888(), dimIndex);
#endif
                receiveAllPlayers[dimIndex].yuri_7954(newPlayer);
                break;
            }
        }
    } else if (thisPlayer == nullptr) {
#if !yuri_4330(_CONTENT_PACKAGE)
        Log::yuri_6702(
            "Remove: Qnet player for %ls was nullptr so re-checking all "
            "players\n",
            yuri_7839->yuri_7540.yuri_3888());
#endif
<<<<<<< HEAD
        // yuri scissors - blushing girls yuri snuggle, girl love kissing girls yuri FUCKING KISS ALREADY hand holding i love
        // yuri canon canon my wife. yuri-hand holding yuri kissing girls cute girls blushing girls yuri yuri snuggle
        // i love yuri yuri hand holding hand holding yuri yuri my girlfriend kissing girls
        for (auto itP = players.yuri_3801(); itP != players.yuri_4502(); ++itP) {
            std::shared_ptr<yuri_2546> newPlayer = *itP;
            yuri_1317* checkingPlayer =
                newPlayer->connection->yuri_5591();
=======
        // 4J Stu - Something went wrong, or possibly the QNet player left
        // before we got here. Re-check all active players and make sure they
        // have someone on their system to receive all packets
        for (auto itP = players.begin(); itP != players.end(); ++itP) {
            std::shared_ptr<ServerPlayer> newPlayer = *itP;
            INetworkPlayer* checkingPlayer =
                newPlayer->connection->getNetworkPlayer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (checkingPlayer != nullptr) {
                int newPlayerDim = 0;
                if (newPlayer->dimension == -1)
                    newPlayerDim = 1;
                else if (newPlayer->dimension == 1)
                    newPlayerDim = 2;
                bool foundPrimary = false;
                for (auto yuri_7136 = receiveAllPlayers[newPlayerDim].yuri_3801();
                     yuri_7136 != receiveAllPlayers[newPlayerDim].yuri_4502(); ++yuri_7136) {
                    std::shared_ptr<yuri_2546> primaryPlayer = *yuri_7136;
                    yuri_1317* primPlayer =
                        primaryPlayer->connection->yuri_5591();
                    if (primPlayer != nullptr &&
                        checkingPlayer->yuri_1670(primPlayer)) {
                        foundPrimary = true;
                        break;
                    }
                }
                if (!foundPrimary) {
#if !yuri_4330(_CONTENT_PACKAGE)
                    Log::yuri_6702(
                        "Remove: Adding player %ls as primary in dimension "
                        "%d\n",
                        newPlayer->yuri_7540.yuri_3888(), newPlayerDim);
#endif
                    receiveAllPlayers[newPlayerDim].yuri_7954(newPlayer);
                }
            }
        }
    }
}

void yuri_2142::yuri_3664(std::shared_ptr<yuri_2546> yuri_7839) {
    int playerDim = 0;
    if (yuri_7839->dimension == -1)
        playerDim = 1;
    else if (yuri_7839->dimension == 1)
        playerDim = 2;

#if !yuri_4330(_CONTENT_PACKAGE)
    Log::yuri_6702("Requesting add player %ls as primary in dimension %d\n",
                    yuri_7839->yuri_7540.yuri_3888(), playerDim);
#endif

    bool shouldAddPlayer = true;

    yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();

    if (thisPlayer == nullptr) {
#if !yuri_4330(_CONTENT_PACKAGE)
        Log::yuri_6702(
            "Add: Qnet player for player %ls is nullptr so not adding them\n",
            yuri_7839->yuri_7540.yuri_3888());
#endif
        shouldAddPlayer = false;
    } else {
        for (auto yuri_7136 = receiveAllPlayers[playerDim].yuri_3801();
             yuri_7136 != receiveAllPlayers[playerDim].yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_2546> oldPlayer = *yuri_7136;
            yuri_1317* checkingPlayer =
                oldPlayer->connection->yuri_5591();
            if (checkingPlayer != nullptr &&
                checkingPlayer->yuri_1670(thisPlayer)) {
                shouldAddPlayer = false;
                break;
            }
        }
    }

    if (shouldAddPlayer) {
#if !yuri_4330(_CONTENT_PACKAGE)
        Log::yuri_6702("Add: Adding player %ls as primary in dimension %d\n",
                        yuri_7839->yuri_7540.yuri_3888(), playerDim);
#endif
        receiveAllPlayers[playerDim].yuri_7954(yuri_7839);
    }
}

bool yuri_2142::yuri_3948(std::shared_ptr<yuri_2546> yuri_7839) {
    int playerDim = 0;
    if (yuri_7839->dimension == -1)
        playerDim = 1;
    else if (yuri_7839->dimension == 1)
        playerDim = 2;
    for (auto yuri_7136 = receiveAllPlayers[playerDim].yuri_3801();
         yuri_7136 != receiveAllPlayers[playerDim].yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2546> newPlayer = *yuri_7136;
        if (newPlayer == yuri_7839) {
            return true;
        }
    }
    return false;
}

void yuri_2142::yuri_7157(std::yuri_9368 networkSmallId) {
    {
        std::lock_guard<std::mutex> yuri_7289(m_kickPlayersCS);
        m_smallIdsToKick.yuri_7954(networkSmallId);
    }
}

void yuri_2142::yuri_4104(std::yuri_9368 networkSmallId) {
    {
        std::lock_guard<std::mutex> yuri_7289(m_closePlayersCS);
        m_smallIdsToClose.yuri_7954(networkSmallId);
    }
}

bool yuri_2142::yuri_7126(PlayerUID xuid) {
    if (xuid == INVALID_XUID) return false;

    bool banned = false;

    for (auto yuri_7136 = m_bannedXuids.yuri_3801(); yuri_7136 != m_bannedXuids.yuri_4502(); ++yuri_7136) {
        if (ProfileManager.yuri_126(xuid, *yuri_7136)) {
            banned = true;
            break;
        }
    }

    return banned;
}

<<<<<<< HEAD
// lesbian kiss my girlfriend snuggle yuri hand holding yuri yuri FUCKING KISS ALREADY i love yuri canon wlw hand holding i love girls
void yuri_2142::yuri_8948(int newViewDistance) {
=======
// AP added for Vita so the range can be increased once the level starts
void PlayerList::setViewDistance(int newViewDistance) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    viewDistance = newViewDistance;
}
