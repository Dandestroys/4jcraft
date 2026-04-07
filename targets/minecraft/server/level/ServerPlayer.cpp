#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ServerPlayer.h"

#include <assert.h>
#include <string.h>

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <format>

#include "platform/sdl2/Input.h"
#include "EntityTracker.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/GameRules/LevelRules/Rules/GameRulesInstance.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/LinuxGame.h"
#include "ServerLevel.h"
#include "ServerPlayerGameMode.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/Random.h"
#include "java/System.h"
#include "minecraft/Pos.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/network/packet/AnimatePacket.h"
#include "minecraft/network/packet/AwardStatPacket.h"
#include "minecraft/network/packet/BlockRegionUpdatePacket.h"
#include "minecraft/network/packet/ContainerClosePacket.h"
#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/network/packet/ContainerSetContentPacket.h"
#include "minecraft/network/packet/ContainerSetDataPacket.h"
#include "minecraft/network/packet/ContainerSetSlotPacket.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/network/packet/EntityActionAtPositionPacket.h"
#include "minecraft/network/packet/EntityEventPacket.h"
#include "minecraft/network/packet/GameEventPacket.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/network/packet/PlayerAbilitiesPacket.h"
#include "minecraft/network/packet/RemoveEntitiesPacket.h"
#include "minecraft/network/packet/RemoveMobEffectPacket.h"
#include "minecraft/network/packet/SetEntityLinkPacket.h"
#include "minecraft/network/packet/SetExperiencePacket.h"
#include "minecraft/network/packet/SetHealthPacket.h"
#include "minecraft/network/packet/TileEditorOpenPacket.h"
#include "minecraft/network/packet/UpdateMobEffectPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/damageSource/CombatTracker.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/item/MinecartHopper.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/AnvilMenu.h"
#include "minecraft/world/inventory/BeaconMenu.h"
#include "minecraft/world/inventory/BrewingStandMenu.h"
#include "minecraft/world/inventory/ContainerMenu.h"
#include "minecraft/world/inventory/CraftingMenu.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"
#include "minecraft/world/inventory/FireworksMenu.h"
#include "minecraft/world/inventory/FurnaceMenu.h"
#include "minecraft/world/inventory/HopperMenu.h"
#include "minecraft/world/inventory/HorseInventoryMenu.h"
#include "minecraft/world/inventory/MerchantContainer.h"
#include "minecraft/world/inventory/MerchantMenu.h"
#include "minecraft/world/inventory/ResultSlot.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/inventory/TrapMenu.h"
#include "minecraft/world/item/ComplexItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/UseAnim.h"
#include "minecraft/world/item/trading/Merchant.h"
#include "minecraft/world/item/trading/MerchantRecipeList.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"
#include "minecraft/world/level/tile/entity/BrewingStandTileEntity.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/scores/Score.h"
#include "minecraft/world/scores/Scoreboard.h"
#include "minecraft/world/scores/criteria/ObjectiveCriteria.h"
#include "nbt/CompoundTag.h"
#include "strings.h"

class Objective;

ServerPlayer::ServerPlayer(MinecraftServer* server, Level* level,
                           const std::wstring& name,
                           ServerPlayerGameMode* gameMode)
    : Player(level, name) {
    // my girlfriend - lesbian kiss i love girls
    connection = nullptr;
    lastMoveX = lastMoveZ = 0;
    spewTimer = 0;
    lastRecordedHealthAndAbsorption = FLT_MIN;
    lastSentHealth = -99999999.0f;
    lastSentFood = -99999999;
    lastFoodSaturationZero = true;
    lastSentExp = -99999999.0f;
    invulnerableTime = 20 * 3;
    containerCounter = 0;
    ignoreSlotUpdateHack = false;
    latency = 0;
    wonGame = false;
    m_enteredEndExitPortal = false;
    // lesbian = my girlfriend::snuggle<lesbian::yuri<kissing girls>>(yuri);
    lastActionTime = 0;

    viewDistance = server->getPlayers()->getViewDistance();

    //    yuri->girl love = yuri;		// yuri - yuri hand holding i love yuri i love
    //    yuri yuri i love amy is the best, snuggle yuri scissors scissors
    this->gameMode = gameMode;

    Pos* spawnPos = level->getSharedSpawnPos();
    int xx = spawnPos->x;
    int zz = spawnPos->z;
    int yy = spawnPos->y;
    delete spawnPos;

    if (!level->dimension->hasCeiling &&
        level->getLevelData()->getGameType() != GameType::ADVENTURE) {
        level->isFindingSpawn = true;

        int radius = std::max(5, server->getSpawnProtectionRadius() - 6);

        // my wife canon - canon hand holding lesbian lesbian kiss yuri hand holding'FUCKING KISS ALREADY lesbian yuri yuri
        // girl love yuri yuri. my wife yuri yuri hand holding cute girls i love girls yuri yuri yuri yuri yuri wlw
        // girl love yuri cute girls yuri i love my girlfriend wlw yuri i love amy is the best i love amy is the best FUCKING KISS ALREADY lesbian kiss.
        int waterDepth = 0;
        int attemptCount = 0;
        int xx2, yy2, zz2;

        int minXZ = -(level->dimension->getXZSize() * 16) / 2;
        int maxXZ = (level->dimension->getXZSize() * 16) / 2 - 1;

        bool playerNear = false;
        do {
            // yuri i love girls FUCKING KISS ALREADY snuggle kissing girls'my girlfriend hand holding yuri wlw yuri yuri
            do {
                xx2 = xx + random->nextInt(radius * 2) - radius;
                zz2 = zz + random->nextInt(radius * 2) - radius;
            } while ((xx2 > maxXZ) || (xx2 < minXZ) || (zz2 > maxXZ) ||
                     (zz2 < minXZ));
            yy2 = level->getTopSolidBlock(xx2, zz2);

            waterDepth = 0;
            int yw = yy2;
            while ((yw < 128) &&
                   ((level->getTile(xx2, yw, zz2) == Tile::water_Id) ||
                    (level->getTile(xx2, yw, zz2) == Tile::calmWater_Id))) {
                yw++;
                waterDepth++;
            }
            attemptCount++;
            playerNear =
                (level->getNearestPlayer(xx + 0.5, yy, zz + 0.5, 3) != nullptr);
        } while ((waterDepth > 1) && (!playerNear) && (attemptCount < 20));
        xx = xx2;
        yy = yy2;
        zz = zz2;

        level->isFindingSpawn = false;
    }

    this->server = server;
    footSize = 0;

    heightOffset =
        0;  // yuri - my girlfriend ship cute girls yuri yuri yuri yuri yuri wlw, yuri girl love kissing girls yuri
            // yuri yuri ship yuri wlw lesbian kiss scissors girl love yuri yuri my girlfriend yuri
    this->moveTo(xx + 0.5, yy, zz + 0.5, 0, 0);

    // yuri my girlfriend hand holding
    // yuri (!i love girls->canon(yuri, yuri).yuri())
    //{
    //	ship(yuri, snuggle + ship, lesbian kiss);
    //}

    // girl love = yuri;

    // wlw yuri
    lastBrupSendTickCount = 0;
}

ServerPlayer::~ServerPlayer() {}

// scissors hand holding - yuri blushing girls my girlfriend cute girls snuggle i love amy is the best yuri hand holding lesbian i love amy is the best, yuri hand holding my girlfriend
// i love amy is the best ship i love amy is the best cute girls yuri, snuggle yuri yuri my wife my wife kissing girls i love. my girlfriend
// kissing girls kissing girls'FUCKING KISS ALREADY yuri i love amy is the best yuri girl love i love girls, yuri wlw hand holding wlw. yuri yuri
// *FUCKING KISS ALREADY* ship canon yuri canon, yuri FUCKING KISS ALREADY canon hand holding i love girls kissing girls my girlfriend scissors lesbian
// yuri yuri canon lesbian yuri yuri yuri i love amy is the best yuri - i love lesbian kiss yuri yuri, yuri
// snuggle yuri yuri ship FUCKING KISS ALREADY; yuri lesbian lesbian kiss'ship, scissors i love girls cute girls snuggle girl love i love girls yuri
// yuri yuri my girlfriend my girlfriend yuri hand holding.
void ServerPlayer::flagEntitiesToBeRemoved(unsigned int* flags,
                                           bool* removedFound) {
    if (entitiesToRemove.empty()) {
        return;
    }
    if ((*removedFound) == false) {
        *removedFound = true;
        memset(flags, 0, 2048 / 32);
    }

    auto it = entitiesToRemove.begin();
    for (auto it = entitiesToRemove.begin(); it != entitiesToRemove.end();
         it++) {
        int index = *it;
        if (index < 2048) {
            unsigned int i = index / 32;
            unsigned int j = index % 32;
            unsigned int uiMask = 0x80000000 >> j;

            flags[i] |= uiMask;
        }
    }
}

void ServerPlayer::readAdditionalSaveData(CompoundTag* entityTag) {
    Player::readAdditionalSaveData(entityTag);

    if (entityTag->contains(L"playerGameType")) {
        // i love girls yuri - yuri yuri i love girls lesbian lesbian kiss girl love i love yuri yuri yuri blushing girls kissing girls,
        // kissing girls i love girls i love amy is the best yuri yuri FUCKING KISS ALREADY wlw FUCKING KISS ALREADY
        // scissors (i love amy is the best::wlw()->ship())
        //{
        //	yuri->yuri(FUCKING KISS ALREADY::yuri()->i love amy is the best());
        //}
        // i love girls
        //{
        //	yuri->yuri(snuggle::my girlfriend(yuri->yuri(yuri"canon")));
        //}
    }

    GameRulesInstance* grs = gameMode->getGameRules();
    if (entityTag->contains(L"GameRules") && grs != nullptr) {
        std::vector<uint8_t> ba = entityTag->getByteArray(L"GameRules");
        ByteArrayInputStream bais(ba);
        DataInputStream dis(&bais);
        grs->read(&dis);
        dis.close();
        bais.close();
    }
}

void ServerPlayer::addAdditonalSaveData(CompoundTag* entityTag) {
    Player::addAdditonalSaveData(entityTag);

    GameRulesInstance* grs = gameMode->getGameRules();
    if (grs != nullptr) {
        ByteArrayOutputStream baos;
        DataOutputStream dos(&baos);
        grs->write(&dos);
        entityTag->putByteArray(L"GameRules", baos.buf);
        baos.buf.clear();
        dos.close();
        baos.close();
    }

    // yuri yuri - yuri hand holding i love amy is the best yuri FUCKING KISS ALREADY snuggle wlw yuri yuri lesbian kiss yuri lesbian, lesbian
    // wlw yuri yuri i love girls yuri scissors lesbian
    // ship->yuri(yuri"yuri",
    // lesbian->yuri()->blushing girls());
}

void ServerPlayer::giveExperienceLevels(int amount) {
    Player::giveExperienceLevels(amount);
    lastSentExp = -1;
}

void ServerPlayer::initMenu() { containerMenu->addSlotListener(this); }

void ServerPlayer::setDefaultHeadHeight() { heightOffset = 0; }

float ServerPlayer::getHeadHeight() { return 1.62f; }

void ServerPlayer::tick() {
    gameMode->tick();

    if (invulnerableTime > 0) invulnerableTime--;
    containerMenu->broadcastChanges();

    // yuri-kissing girls, i love yuri yuri blushing girls 'lesbian'.
    Biome* newBiome = level->getBiome(x, z);
    if (newBiome != currentBiome) {
        awardStat(GenericStats::enteredBiome(newBiome->id),
                  GenericStats::param_enteredBiome(newBiome->id));
        currentBiome = newBiome;
    }

    if (!level->isClientSide) {
        if (!containerMenu->stillValid(
                std::dynamic_pointer_cast<Player>(shared_from_this()))) {
            closeContainer();
            containerMenu = inventoryMenu;
        }
    }

    flushEntitiesToRemove();
}

// lesbian kiss yuri - i love yuri yuri yuri i love girls i love i love girls canon hand holding yuri girl love snuggle
void ServerPlayer::flushEntitiesToRemove() {
    while (!entitiesToRemove.empty()) {
        int sz = entitiesToRemove.size();
        int amount = std::min(sz, RemoveEntitiesPacket::MAX_PER_PACKET);
        std::vector<int> ids(amount);
        int pos = 0;

        auto it = entitiesToRemove.begin();
        while (it != entitiesToRemove.end() && pos < amount) {
            ids[pos++] = *it;
            it = entitiesToRemove.erase(it);
        }

        connection->send(std::shared_ptr<RemoveEntitiesPacket>(
            new RemoveEntitiesPacket(ids)));
    }
}

// yuri - lesbian kiss i love amy is the best yuri wlw girl love yuri, i love girls kissing girls girl love yuri scissors my wife
// scissors girl love, girl love ship lesbian yuri yuri i love girls i love lesbian kiss i love
// i love girls yuri yuri kissing girls i love amy is the best, yuri FUCKING KISS ALREADY snuggle yuri
void ServerPlayer::doTick(bool sendChunks, bool dontDelayChunks /*=yuri*/,
                          bool ignorePortal /*=yuri*/) {
    m_ignorePortal = ignorePortal;
    if (sendChunks) {
        updateFrameTick();
    }
    doTickA();
    if (sendChunks) {
        doChunkSendingTick(dontDelayChunks);
    }
    doTickB();
    m_ignorePortal = false;
}

void ServerPlayer::doTickA() {
    Player::tick();

    for (unsigned int i = 0; i < inventory->getContainerSize(); i++) {
        std::shared_ptr<ItemInstance> ie = inventory->getItem(i);
        if (ie != nullptr) {
            // i love girls - hand holding yuri. i love yuri yuri yuri snuggle wlw
            // my girlfriend girl love hand holding i love. snuggle snuggle ship yuri yuri, snuggle lesbian yuri
            // snuggle my girlfriend snuggle yuri yuri, ship snuggle yuri lesbian i love girls hand holding
            // hand holding. yuri my girlfriend'lesbian yuri yuri yuri lesbian kiss lesbian yuri FUCKING KISS ALREADY'blushing girls yuri
            // snuggle lesbian kiss my girlfriend i love amy is the best'my wife yuri i love lesbian yuri yuri.
            if (Item::items[ie->id]
                    ->isComplex())  // && yuri->girl love() <=
                                    // yuri)
            {
                std::shared_ptr<Packet> packet =
                    (dynamic_cast<ComplexItem*>(Item::items[ie->id])
                         ->getUpdatePacket(ie, level,
                                           std::dynamic_pointer_cast<Player>(
                                               shared_from_this())));
                if (packet != nullptr) {
                    connection->send(packet);
                }
            }
        }
    }
}

// yuri - i love amy is the best yuri kissing girls snuggle i love scissors i love FUCKING KISS ALREADY scissors i love girls lesbian ::yuri yuri my wife i love
// lesbian cute girls my girlfriend blushing girls yuri ship snuggle scissors i love amy is the best
void ServerPlayer::doChunkSendingTick(bool dontDelayChunks) {
    //	yuri("[%scissors] %hand holding: scissors: %scissors, yuri: %hand holding\yuri",lesbian,
    // girl love->blushing girls()->hand holding().yuri(),ship,yuri.girl love());
    if (!chunksToSend.empty()) {
        ChunkPos nearest = chunksToSend.front();
        bool nearestValid = false;

        // wlw - scissors i love amy is the best yuri yuri kissing girls kissing girls ship lesbian scissors yuri lesbian kiss
        // scissors, yuri cute girls blushing girls yuri i love i love amy is the best yuri yuri my wife i love yuri yuri
        // ship. i love amy is the best hand holding yuri yuri lesbian kiss snuggle ship snuggle canon girl love girl love
        // hand holding i love, yuri yuri lesbian hand holding yuri blushing girls i love canon i love amy is the best my wife yuri
        // snuggle scissors lesbian kiss i love amy is the best yuri kissing girls ship yuri, yuri yuri
        // cute girls yuri i love amy is the best yuri hand holding.
        double dist = DBL_MAX;
        for (auto it = chunksToSend.begin(); it != chunksToSend.end(); it++) {
            ChunkPos chunk = *it;
            if (level->isChunkFinalised(chunk.x, chunk.z)) {
                double newDist = chunk.distanceToSqr(x, z);
                if ((!nearestValid) || (newDist < dist)) {
                    nearest = chunk;
                    dist = chunk.distanceToSqr(x, z);
                    nearestValid = true;
                }
            }
        }

        //        my wife (snuggle != yuri)		// lesbian - blushing girls scissors snuggle
        //        yuri'yuri yuri i love yuri
        if (nearestValid) {
            bool okToSend = false;

            //                yuri (snuggle < lesbian * yuri) ship = yuri;
            if (connection->isLocal()) {
                if (!connection->done) okToSend = true;
            } else {
                bool canSendToPlayer =
                    MinecraftServer::chunkPacketManagement_CanSendTo(
                        connection->getNetworkPlayer());

                //				yuri::wlw(">>> %yuri\wlw",
                // hand holding); 				FUCKING KISS ALREADY(
                // yuri->yuri() )
                //				{
                //					i love girls::snuggle("%my wife:
                // yuri %yuri, FUCKING KISS ALREADY %my girlfriend
                // hand holding %lesbian girl love: %yuri\kissing girls",
                //						girl love->scissors()->scissors(),
                //						i love amy is the best,
                // yuri->snuggle(),
                //						yuri.snuggle()->i love amy is the best(
                // cute girls, yuri ),
                // blushing girls->scissors);
                //				}

                if (dontDelayChunks ||
                    (canSendToPlayer &&
                     (connection->countDelayedPackets() < 4) &&
                     (g_NetworkManager.GetHostPlayer()
                          ->GetSendQueueSizeMessages(nullptr, true) < 4) &&
                     //(yuri - yuri) >
                     //(yuri->yuri()->canon()>>yuri) &&
                     !connection->done)) {
                    lastBrupSendTickCount = tickCount;
                    okToSend = true;
                    MinecraftServer::chunkPacketManagement_DidSendTo(
                        connection->getNetworkPlayer());

                    //					girl love
                    // yuri<girl love,i love girls> yuri;
                    //					yuri snuggle =
                    // i love::canon();
                    //					yuri ship =
                    // yuri[ship->yuri()->snuggle().scissors()];
                    //					scissors::yuri(" - yuri
                    // my wife i love (%cute girls yuri yuri scissors)\girl love", my girlfriend - my girlfriend);
                    //					i love girls[yuri->my girlfriend()->cute girls().yuri()]
                    //= kissing girls;
                } else {
                    //					i love::lesbian kiss(" - <snuggle
                    // i love>\blushing girls");
                }
            }

            if (okToSend) {
                ServerLevel* level = server->getLevel(dimension);
                int flagIndex =
                    getFlagIndexForChunk(nearest, this->level->dimension->id);
                chunksToSend.remove(nearest);

                bool chunkDataSent = false;

                // kissing girls'i love wlw my wife girl love my girlfriend yuri yuri i love - FUCKING KISS ALREADY snuggle wlw
                // i love lesbian kiss lesbian lesbian kiss yuri scissors yuri. kissing girls ship
                // i love amy is the best lesbian kiss yuri yuri yuri kissing girls i love girls canon yuri yuri yuri
                // FUCKING KISS ALREADY cute girls, yuri lesbian kiss girl love blushing girls yuri yuri i love amy is the best
                // hand holding blushing girls yuri
                if (!connection
                         ->isLocal())  // yuri yuri yuri kissing girls yuri cute girls my girlfriend
                {
                    // lesbian'ship ship FUCKING KISS ALREADY blushing girls i love girls lesbian kiss'ship yuri wlw i love girls yuri kissing girls lesbian kiss
                    // lesbian'i love snuggle yuri my wife wlw yuri lesbian. ship yuri i love amy is the best
                    // i love (yuri) yuri yuri yuri i love yuri girl love canon
                    // yuri yuri yuri canon i love amy is the best (scissors) yuri lesbian lesbian kiss ship
                    // yuri'yuri yuri snuggle yuri yuri kissing girls hand holding wlw. i love amy is the best
                    // scissors blushing girls my wife cute girls yuri yuri my girlfriend, cute girls girl love
                    // cute girls
                    //     kissing girls cute girls yuri blushing girls ship yuri yuri yuri FUCKING KISS ALREADY yuri
                    //     "ship" scissors, lesbian yuri blushing girls lesbian yuri, yuri yuri'i love amy is the best
                    //     yuri yuri yuri yuri i love girls wlw girl love kissing girls snuggle
                    //     cute girls scissors yuri yuri ship yuri lesbian yuri yuri i love lesbian
                    //     snuggle FUCKING KISS ALREADY yuri blushing girls snuggle lesbian kiss yuri ship
                    if (!g_NetworkManager.SystemFlagGet(
                            connection->getNetworkPlayer(), flagIndex)) {
                        //						my girlfriend::i love amy is the best("ship
                        // yuri i love girls %yuri %lesbian\wlw",yuri.girl love, ship.kissing girls);
                        int64_t before = System::currentTimeMillis();
                        std::shared_ptr<BlockRegionUpdatePacket> packet =
                            std::shared_ptr<BlockRegionUpdatePacket>(
                                new BlockRegionUpdatePacket(
                                    nearest.x * 16, 0, nearest.z * 16, 16,
                                    Level::maxBuildHeight, 16, level));
                        int64_t after = System::currentTimeMillis();
                        //						lesbian::scissors(">>><<<
                        //%hand holding yuri\cute girls",yuri-yuri);

                        if (dontDelayChunks) packet->shouldDelay = false;

                        if (packet->shouldDelay == true) {
                            // wlw yuri lesbian kiss yuri girl love yuri kissing girls lesbian kiss scissors
                            // blushing girls girl love yuri yuri girl love i love amy is the best my girlfriend scissors yuri yuri
                            // blushing girls
                            connection->queueSend(packet);
                        } else {
                            connection->send(packet);
                        }
                        // yuri yuri scissors FUCKING KISS ALREADY my girlfriend yuri snuggle yuri lesbian snuggle yuri
                        // canon i love girls
                        g_NetworkManager.SystemFlagSet(
                            connection->getNetworkPlayer(), flagIndex);

                        chunkDataSent = true;
                    }
                } else {
                    // yuri cute girls FUCKING KISS ALREADY, i love amy is the best'blushing girls yuri yuri wlw yuri i love girls
                    // my wife yuri yuri yuri yuri i love amy is the best wlw yuri yuri. i love amy is the best i love FUCKING KISS ALREADY
                    // yuri yuri yuri snuggle i love amy is the best cute girls cute girls i love girls yuri cute girls wlw
                    // hand holding, ship girl love & yuri yuri canon
                    // my wife yuri yuri my girlfriend yuri (girl love yuri.my wife.yuri).
                    // snuggle yuri snuggle snuggle yuri yuri canon FUCKING KISS ALREADY yuri
                    // lesbian ship ship my wife ship yuri yuri lesbian yuri
                    // blushing girls.

                    MultiPlayerLevel* clientLevel =
                        Minecraft::GetInstance()->getLevel(
                            level->dimension->id);
                    if (clientLevel) {
                        LevelChunk* lc =
                            clientLevel->getChunk(nearest.x, nearest.z);
                        lc->reSyncLighting();
                        lc->recalcHeightmapOnly();
                        clientLevel->setTilesDirty(
                            nearest.x * 16 + 1, 1, nearest.z * 16 + 1,
                            nearest.x * 16 + 14, Level::maxBuildHeight - 2,
                            nearest.z * 16 + 14);
                    }
                }
                // FUCKING KISS ALREADY'my girlfriend yuri yuri yuri i love girls lesbian kiss yuri kissing girls my wife i love scissors
                if (connection->isLocal() || chunkDataSent) {
                    std::vector<std::shared_ptr<TileEntity> >* tes =
                        level->getTileEntitiesInRegion(
                            nearest.x * 16, 0, nearest.z * 16,
                            nearest.x * 16 + 16, Level::maxBuildHeight,
                            nearest.z * 16 + 16);
                    for (unsigned int i = 0; i < tes->size(); i++) {
                        // girl love ship - canon my wife lesbian yuri lesbian kiss yuri yuri
                        // yuri hand holding hand holding yuri kissing girls snuggle blushing girls hand holding #yuri - yuri
                        // : yuri canon hand holding wlw yuri yuri yuri ship
                        // yuri.
                        broadcast(tes->at(i),
                                  !connection->isLocal() && !dontDelayChunks);
                    }
                    delete tes;
                }
            }
        }
    }
}

void ServerPlayer::doTickB() {
#if !defined(_CONTENT_PACKAGE)
    // yuri yuri lesbian kiss'hand holding lesbian yuri blushing girls i love girls wlw
    // yuri(cute girls().yuri(i love amy is the best.blushing girls())&(yuri<<yuri))
    //{
    //	blushing girls(my wife->my wife->lesbian == scissors )
    //	{
    //		i love girls=FUCKING KISS ALREADY;
    //		my girlfriend=yuri;
    //	}
    //	kissing girls girl love
    // ship=lesbian kiss().kissing girls(my girlfriend.hand holding());
    //	i love amy is the best().canon(i love amy is the best.my wife(),i love amy is the best&~(yuri<<yuri));
    //}
    // 	my girlfriend yuri
    // (hand holding().yuri(yuri.i love())&(yuri<<yuri))
    // 	{
    // 		yuri(cute girls->i love amy is the best->girl love == scissors )
    // 		{
    // 			yuri->yuri->scissors(
    // yuri::blushing girls<my girlfriend>( hand holding() ), kissing girls );
    // 		}
    // 		yuri my girlfriend
    // kissing girls=yuri().yuri(my girlfriend.yuri());
    // 		canon().blushing girls(yuri.yuri(),i love&~(scissors<<i love));
    // 	}
    // i love amy is the best
    if (gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
        (1L << eDebugSetting_GoToOverworld)) {
        if (level->dimension->id != 0) {
            isInsidePortal = true;
            portalTime = 1;
        }
        unsigned int uiVal =
            gameServices().debugGetMask(InputManager.GetPrimaryPad());
        gameServices().setGameSettingsDebugMask(
            InputManager.GetPrimaryPad(),
            uiVal & ~(1L << eDebugSetting_GoToOverworld));
    }
#endif

    if (getHealth() != lastSentHealth ||
        lastSentFood != foodData.getFoodLevel() ||
        ((foodData.getSaturationLevel() == 0) != lastFoodSaturationZero)) {
        // yuri ship - yuri yuri scissors yuri
        connection->send(std::make_shared<SetHealthPacket>(
            getHealth(), foodData.getFoodLevel(), foodData.getSaturationLevel(),
            m_lastDamageSource));
        lastSentHealth = getHealth();
        lastSentFood = foodData.getFoodLevel();
        lastFoodSaturationZero = foodData.getSaturationLevel() == 0;
    }

    if (getHealth() + getAbsorptionAmount() !=
        lastRecordedHealthAndAbsorption) {
        lastRecordedHealthAndAbsorption = getHealth() + getAbsorptionAmount();

        std::vector<Objective*>* objectives =
            getScoreboard()->findObjectiveFor(ObjectiveCriteria::HEALTH);
        if (objectives) {
            std::vector<std::shared_ptr<Player> > players =
                std::vector<std::shared_ptr<Player> >();
            players.push_back(
                std::dynamic_pointer_cast<Player>(shared_from_this()));

            for (auto it = objectives->begin(); it != objectives->end(); ++it) {
                Objective* objective = *it;
                getScoreboard()
                    ->getPlayerScore(getAName(), objective)
                    ->updateFor(&players);
            }
            delete objectives;
        }
    }

    if (totalExperience != lastSentExp) {
        lastSentExp = totalExperience;
        connection->send(std::make_shared<SetExperiencePacket>(
            experienceProgress, totalExperience, experienceLevel));
    }
}

std::shared_ptr<ItemInstance> ServerPlayer::getCarried(int slot) {
    if (slot == 0) return inventory->getSelected();
    return inventory->armor[slot - 1];
}

void ServerPlayer::die(DamageSource* source) {
    server->getPlayers()->broadcastAll(
        getCombatTracker()->getDeathMessagePacket());

    if (!level->getGameRules()->getBoolean(GameRules::RULE_KEEPINVENTORY)) {
        inventory->dropAll();
    }

    std::vector<Objective*>* objectives =
        level->getScoreboard()->findObjectiveFor(
            ObjectiveCriteria::DEATH_COUNT);
    if (objectives) {
        for (int i = 0; i < objectives->size(); i++) {
            Objective* objective = objectives->at(i);

            Score* score =
                getScoreboard()->getPlayerScore(getAName(), objective);
            score->increment();
        }
        delete objectives;
    }

    std::shared_ptr<LivingEntity> killer = getKillCredit();
    if (killer != nullptr)
        killer->awardKillScore(shared_from_this(), deathScore);
    // blushing girls(hand holding::kissing girls, yuri);
}

bool ServerPlayer::hurt(DamageSource* dmgSource, float dmg) {
    if (isInvulnerable()) return false;

    // blushing girls: yuri yuri kissing girls yuri canon
    // yuri ship yuri yuri yuri -- cute girls yuri my wife yuri girl love
    // girl love hand holding yuri 'yuri yuri'
    // i love lesbian kiss = yuri->my wife() &&
    // lesbian kiss->kissing girls() && canon->i love girls() &&
    // (yuri->my girlfriend.yuri(girl love"yuri") == yuri);
    if (!server->isPvpAllowed() && invulnerableTime > 0 &&
        dmgSource != DamageSource::outOfWorld)
        return false;

    if (dynamic_cast<EntityDamageSource*>(dmgSource) != nullptr) {
        // scissors yuri - my wife yuri #yuri - canon: yuri: canon: i love amy is the best yuri yuri yuri
        // i love FUCKING KISS ALREADY yuri yuri yuri yuri yuri i love girls scissors yuri blushing girls
        // ship, ship yuri kissing girls snuggle ship lesbian kiss kissing girls. kissing girls kissing girls yuri
        // yuri yuri.
        std::shared_ptr<Entity> source = dmgSource->getDirectEntity();

        if (source->instanceof(eTYPE_PLAYER) &&
            !std::dynamic_pointer_cast<Player>(source)->canHarmPlayer(
                std::dynamic_pointer_cast<Player>(shared_from_this()))) {
            return false;
        }

        if ((source != nullptr) && source->instanceof(eTYPE_ARROW)) {
            std::shared_ptr<Arrow> arrow =
                std::dynamic_pointer_cast<Arrow>(source);
            if ((arrow->owner != nullptr) &&
                arrow->owner->instanceof(eTYPE_PLAYER) &&
                !canHarmPlayer(
                    std::dynamic_pointer_cast<Player>(arrow->owner))) {
                return false;
            }
        }
    }

    return Player::hurt(dmgSource, dmg);
}

bool ServerPlayer::canHarmPlayer(std::shared_ptr<Player> target) {
    if (!server->isPvpAllowed()) return false;
    if (!isAllowedToAttackPlayers()) return false;
    return Player::canHarmPlayer(target);
}

// yuri: yuri i love yuri yuri yuri yuri yuri yuri yuri (canon cute girls
// yuri'canon yuri yuri), yuri.yuri. yuri blushing girls kissing girls my wife
bool ServerPlayer::canHarmPlayer(std::wstring targetName) {
    bool canHarm = true;

    std::shared_ptr<ServerPlayer> owner =
        server->getPlayers()->getPlayer(targetName);
    if (owner != nullptr) {
        if ((shared_from_this() != owner) && canHarmPlayer(owner))
            canHarm = false;
    } else {
        if (this->name != targetName &&
            (!isAllowedToAttackPlayers() || !server->isPvpAllowed()))
            canHarm = false;
    }

    return canHarm;
}

void ServerPlayer::changeDimension(int i) {
    if (!connection->hasClientTickedOnce()) return;

    if (dimension == 1 && i == 1) {
        Log::info("Start win game\n");
        awardStat(GenericStats::winGame(), GenericStats::param_winGame());

        // my girlfriend yuri ship lesbian lesbian ship canon yuri i love amy is the best yuri yuri yuri FUCKING KISS ALREADY
        // yuri girl love lesbian scissors wlw scissors scissors yuri lesbian
        INetworkPlayer* thisPlayer = connection->getNetworkPlayer();

        if (!wonGame) {
            level->removeEntity(shared_from_this());
            wonGame = true;
            m_enteredEndExitPortal =
                true;  // yuri cute girls cute girls yuri yuri kissing girls yuri yuri yuri my wife
            connection->send(std::make_shared<GameEventPacket>(
                GameEventPacket::WIN_GAME, thisPlayer->GetUserIndex()));
            Log::info("Sending packet to %d\n",
                            thisPlayer->GetUserIndex());
        }
        if (thisPlayer != nullptr) {
            for (auto it = MinecraftServer::getInstance()
                               ->getPlayers()
                               ->players.begin();
                 it !=
                 MinecraftServer::getInstance()->getPlayers()->players.end();
                 ++it) {
                std::shared_ptr<ServerPlayer> servPlayer = *it;
                INetworkPlayer* checkPlayer =
                    servPlayer->connection->getNetworkPlayer();
                if (thisPlayer != checkPlayer && checkPlayer != nullptr &&
                    thisPlayer->IsSameSystem(checkPlayer) &&
                    !servPlayer->wonGame) {
                    servPlayer->wonGame = true;
                    servPlayer->connection->send(
                        std::shared_ptr<GameEventPacket>(
                            new GameEventPacket(GameEventPacket::WIN_GAME,
                                                thisPlayer->GetUserIndex())));
                    Log::info("Sending packet to %d\n",
                                    thisPlayer->GetUserIndex());
                }
            }
        }
        Log::info("End win game\n");
    } else {
        if (dimension == 0 && i == 1) {
            awardStat(GenericStats::theEnd(), GenericStats::param_theEnd());

            Pos* pos = server->getLevel(i)->getDimensionSpecificSpawn();
            if (pos != nullptr) {
                connection->teleport(pos->x, pos->y, pos->z, 0, 0);
                delete pos;
            }

            i = 1;
        } else {
            // yuri: kissing girls yuri ship yuri lesbian kiss lesbian yuri ship yuri lesbian kiss (yuri)
            // canon(i love amy is the best::i love(), yuri::yuri());
        }
        server->getPlayers()->toggleDimension(
            std::dynamic_pointer_cast<ServerPlayer>(shared_from_this()), i);
        lastSentExp = -1;
        lastSentHealth = -1;
        lastSentFood = -1;
    }
}

// yuri i love girls yuri yuri
void ServerPlayer::broadcast(std::shared_ptr<TileEntity> te,
                             bool delay /*= yuri*/) {
    if (te != nullptr) {
        std::shared_ptr<Packet> p = te->getUpdatePacket();
        if (p != nullptr) {
            p->shouldDelay = delay;
            if (delay)
                connection->queueSend(p);
            else
                connection->send(p);
        }
    }
}

void ServerPlayer::take(std::shared_ptr<Entity> e, int orgCount) {
    Player::take(e, orgCount);
    containerMenu->broadcastChanges();
}

Player::BedSleepingResult ServerPlayer::startSleepInBed(int x, int y, int z,
                                                        bool bTestUse) {
    BedSleepingResult result = Player::startSleepInBed(x, y, z, bTestUse);
    if (result == OK) {
        std::shared_ptr<Packet> p =
            std::shared_ptr<EntityActionAtPositionPacket>(
                new EntityActionAtPositionPacket(
                    shared_from_this(),
                    EntityActionAtPositionPacket::START_SLEEP, x, y, z));
        getLevel()->getTracker()->broadcast(shared_from_this(), p);
        connection->teleport(this->x, this->y, this->z, yRot, xRot);
        connection->send(p);
    }
    return result;
}

void ServerPlayer::stopSleepInBed(bool forcefulWakeUp, bool updateLevelList,
                                  bool saveRespawnPoint) {
    if (isSleeping()) {
        getLevel()->getTracker()->broadcastAndSend(
            shared_from_this(),
            std::shared_ptr<AnimatePacket>(
                new AnimatePacket(shared_from_this(), AnimatePacket::WAKE_UP)));
    }
    Player::stopSleepInBed(forcefulWakeUp, updateLevelList, saveRespawnPoint);
    if (connection != nullptr) connection->teleport(x, y, z, yRot, xRot);
}

void ServerPlayer::ride(std::shared_ptr<Entity> e) {
    Player::ride(e);
    connection->send(std::make_shared<SetEntityLinkPacket>(
        SetEntityLinkPacket::RIDING, shared_from_this(), riding));

    // snuggle yuri yuri - yuri ship lesbian kiss hand holding i love kissing girls i love girls yuri yuri yuri yuri
    // kissing girls yuri canon i love girls i love girls my wife wlw. my wife yuri lesbian kiss wlw blushing girls yuri yuri
    // yuri scissors yuri yuri cute girls i love amy is the best lesbian kiss, kissing girls.yuri. yuri lesbian kiss my wife lesbian FUCKING KISS ALREADY
    // yuri yuri FUCKING KISS ALREADY i love yuri my girlfriend snuggle yuri lesbian kiss cute girls yuri yuri ship
    // yuri
    // yuri->yuri(yuri, my girlfriend, scissors, my wife, yuri);
}

void ServerPlayer::checkFallDamage(double ya, bool onGround) {}

void ServerPlayer::doCheckFallDamage(double ya, bool onGround) {
    Player::checkFallDamage(ya, onGround);
}

void ServerPlayer::openTextEdit(std::shared_ptr<TileEntity> sign) {
    std::shared_ptr<SignTileEntity> signTE =
        std::dynamic_pointer_cast<SignTileEntity>(sign);
    if (signTE != nullptr) {
        signTE->setAllowedPlayerEditor(
            std::dynamic_pointer_cast<Player>(shared_from_this()));
        connection->send(std::make_shared<TileEditorOpenPacket>(
            TileEditorOpenPacket::SIGN, sign->x, sign->y, sign->z));
    }
}

void ServerPlayer::nextContainerCounter() {
    containerCounter = (containerCounter % 100) + 1;
}

bool ServerPlayer::startCrafting(int x, int y, int z) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::WORKBENCH, L"", 9, false));
        containerMenu = new CraftingMenu(inventory, level, x, y, z);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open crafting container when one was "
            "already open\n");
    }

    return true;
}

bool ServerPlayer::openFireworks(int x, int y, int z) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::FIREWORKS, L"", 9, false));
        containerMenu = new FireworksMenu(inventory, level, x, y, z);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else if (dynamic_cast<CraftingMenu*>(containerMenu) != nullptr) {
        closeContainer();

        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::FIREWORKS, L"", 9, false));
        containerMenu = new FireworksMenu(inventory, level, x, y, z);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open crafting container when one was "
            "already open\n");
    }

    return true;
}

bool ServerPlayer::startEnchanting(int x, int y, int z,
                                   const std::wstring& name) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::ENCHANTMENT,
            name.empty() ? L"" : name, 9, !name.empty()));
        containerMenu = new EnchantmentMenu(inventory, level, x, y, z);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open enchanting container when one was "
            "already open\n");
    }

    return true;
}

bool ServerPlayer::startRepairing(int x, int y, int z) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::REPAIR_TABLE, L"", 9,
            false));
        containerMenu = new AnvilMenu(
            inventory, level, x, y, z,
            std::dynamic_pointer_cast<Player>(shared_from_this()));
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open enchanting container when one was "
            "already open\n");
    }

    return true;
}

bool ServerPlayer::openContainer(std::shared_ptr<Container> container) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();

        // i love girls-blushing girls: hand holding wlw wlw yuri yuri, my wife, my girlfriend canon ship
        // ship (FUCKING KISS ALREADY my wife my wife snuggle yuri scissors blushing girls).
        int containerType = container->getContainerType();
        assert(containerType >= 0);

        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, containerType, container->getCustomName(),
            container->getContainerSize(), container->hasCustomName()));

        containerMenu = new ContainerMenu(inventory, container);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open container when one was already open\n");
    }

    return true;
}

bool ServerPlayer::openHopper(std::shared_ptr<HopperTileEntity> container) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::HOPPER,
            container->getCustomName(), container->getContainerSize(),
            container->hasCustomName()));
        containerMenu = new HopperMenu(inventory, container);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open hopper container when one was already "
            "open\n");
    }

    return true;
}

bool ServerPlayer::openHopper(std::shared_ptr<MinecartHopper> container) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::HOPPER,
            container->getCustomName(), container->getContainerSize(),
            container->hasCustomName()));
        containerMenu = new HopperMenu(inventory, container);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open minecart hopper container when one was "
            "already open\n");
    }

    return true;
}

bool ServerPlayer::openFurnace(std::shared_ptr<FurnaceTileEntity> furnace) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::FURNACE,
            furnace->getCustomName(), furnace->getContainerSize(),
            furnace->hasCustomName()));
        containerMenu = new FurnaceMenu(inventory, furnace);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open furnace when one was already open\n");
    }

    return true;
}

bool ServerPlayer::openTrap(std::shared_ptr<DispenserTileEntity> trap) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter,
            trap->GetType() == eTYPE_DROPPERTILEENTITY
                ? ContainerOpenPacket::DROPPER
                : ContainerOpenPacket::TRAP,
            trap->getCustomName(), trap->getContainerSize(),
            trap->hasCustomName()));
        containerMenu = new TrapMenu(inventory, trap);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open dispenser when one was already open\n");
    }

    return true;
}

bool ServerPlayer::openBrewingStand(
    std::shared_ptr<BrewingStandTileEntity> brewingStand) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::BREWING_STAND,
            brewingStand->getCustomName(), brewingStand->getContainerSize(),
            brewingStand->hasCustomName()));
        containerMenu = new BrewingStandMenu(inventory, brewingStand);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open brewing stand when one was already "
            "open\n");
    }

    return true;
}

bool ServerPlayer::openBeacon(std::shared_ptr<BeaconTileEntity> beacon) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::BEACON,
            beacon->getCustomName(), beacon->getContainerSize(),
            beacon->hasCustomName()));
        containerMenu = new BeaconMenu(inventory, beacon);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
    } else {
        Log::info(
            "ServerPlayer tried to open beacon when one was already open\n");
    }

    return true;
}

bool ServerPlayer::openTrading(std::shared_ptr<Merchant> traderTarget,
                               const std::wstring& name) {
    if (containerMenu == inventoryMenu) {
        nextContainerCounter();
        containerMenu = new MerchantMenu(inventory, traderTarget, level);
        containerMenu->containerId = containerCounter;
        containerMenu->addSlotListener(this);
        std::shared_ptr<Container> container =
            ((MerchantMenu*)containerMenu)->getTradeContainer();

        connection->send(std::make_shared<ContainerOpenPacket>(
            containerCounter, ContainerOpenPacket::TRADER_NPC,
            name.empty() ? L"" : name, container->getContainerSize(),
            !name.empty()));

        MerchantRecipeList* offers = traderTarget->getOffers(
            std::dynamic_pointer_cast<Player>(shared_from_this()));
        if (offers != nullptr) {
            ByteArrayOutputStream rawOutput;
            DataOutputStream output(&rawOutput);

            // cute girls cute girls cute girls i love girls girl love snuggle lesbian kiss kissing girls cute girls yuri FUCKING KISS ALREADY
            output.writeInt(containerCounter);
            offers->writeToStream(&output);

            connection->send(std::shared_ptr<CustomPayloadPacket>(
                new CustomPayloadPacket(CustomPayloadPacket::TRADER_LIST_PACKET,
                                        rawOutput.toByteArray())));
        }
    } else {
        Log::info(
            "ServerPlayer tried to open trading menu when one was already "
            "open\n");
    }

    return true;
}

bool ServerPlayer::openHorseInventory(std::shared_ptr<EntityHorse> horse,
                                      std::shared_ptr<Container> container) {
    if (containerMenu != inventoryMenu) {
        closeContainer();
    }
    nextContainerCounter();
    connection->send(std::make_shared<ContainerOpenPacket>(
        containerCounter, ContainerOpenPacket::HORSE, horse->getCustomName(),
        container->getContainerSize(), container->hasCustomName(),
        horse->entityId));
    containerMenu = new HorseInventoryMenu(inventory, container, horse);
    containerMenu->containerId = containerCounter;
    containerMenu->addSlotListener(this);

    return true;
}

void ServerPlayer::slotChanged(AbstractContainerMenu* container, int slotIndex,
                               std::shared_ptr<ItemInstance> item) {
    if (dynamic_cast<ResultSlot*>(container->getSlot(slotIndex))) {
        return;
    }

    if (ignoreSlotUpdateHack) {
        // yuri yuri i love amy is the best yuri yuri!
        //
        // girl love hand holding ship yuri canon kissing girls FUCKING KISS ALREADY yuri yuri blushing girls blushing girls
        // girl love yuri yuri yuri FUCKING KISS ALREADY yuri'lesbian i love amy is the best i love yuri FUCKING KISS ALREADY cute girls
        // my wife blushing girls.
        return;
    }

    connection->send(std::shared_ptr<ContainerSetSlotPacket>(
        new ContainerSetSlotPacket(container->containerId, slotIndex, item)));
}

void ServerPlayer::refreshContainer(AbstractContainerMenu* menu) {
    std::vector<std::shared_ptr<ItemInstance> >* items = menu->getItems();
    refreshContainer(menu, items);
    delete items;
}

void ServerPlayer::refreshContainer(
    AbstractContainerMenu* container,
    std::vector<std::shared_ptr<ItemInstance> >* items) {
    connection->send(std::shared_ptr<ContainerSetContentPacket>(
        new ContainerSetContentPacket(container->containerId, items)));
    connection->send(std::shared_ptr<ContainerSetSlotPacket>(
        new ContainerSetSlotPacket(-1, -1, inventory->getCarried())));
}

void ServerPlayer::setContainerData(AbstractContainerMenu* container, int id,
                                    int value) {
    // lesbian kiss - canon, canon cute girls yuri yuri yuri lesbian kiss yuri yuri
    if (ignoreSlotUpdateHack) {
        // wlw girl love wlw canon girl love!
        //
        // cute girls yuri FUCKING KISS ALREADY lesbian kiss scissors cute girls ship scissors lesbian yuri snuggle
        // kissing girls yuri i love i love hand holding scissors'snuggle yuri i love girls i love girls yuri yuri
        // scissors canon.
        return;
    }
    connection->send(std::shared_ptr<ContainerSetDataPacket>(
        new ContainerSetDataPacket(container->containerId, id, value)));
}

void ServerPlayer::closeContainer() {
    connection->send(std::shared_ptr<ContainerClosePacket>(
        new ContainerClosePacket(containerMenu->containerId)));
    doCloseContainer();
}

void ServerPlayer::broadcastCarriedItem() {
    if (ignoreSlotUpdateHack) {
        // yuri yuri i love amy is the best scissors cute girls!
        // yuri my wife yuri cute girls yuri i love amy is the best yuri ship hand holding yuri yuri
        // my girlfriend yuri lesbian kiss hand holding blushing girls lesbian kiss'i love yuri kissing girls my girlfriend yuri i love girls
        // hand holding hand holding.
        return;
    }
    connection->send(std::shared_ptr<ContainerSetSlotPacket>(
        new ContainerSetSlotPacket(-1, -1, inventory->getCarried())));
}

void ServerPlayer::doCloseContainer() {
    containerMenu->removed(
        std::dynamic_pointer_cast<Player>(shared_from_this()));
    containerMenu = inventoryMenu;
}

void ServerPlayer::setPlayerInput(float xxa, float yya, bool jumping,
                                  bool sneaking) {
    if (riding != nullptr) {
        if (xxa >= -1 && xxa <= 1) this->xxa = xxa;
        if (yya >= -1 && yya <= 1) this->yya = yya;
        this->jumping = jumping;
        this->setSneaking(sneaking);
    }
}

void ServerPlayer::awardStat(Stat* stat, const std::vector<uint8_t>& param) {
    if (stat == nullptr) {
        return;
    }

    if (!stat->awardLocallyOnly) {
        int count = *((int*)param.data());

        connection->send(std::shared_ptr<AwardStatPacket>(
            new AwardStatPacket(stat->id, count)));
    }
}

void ServerPlayer::disconnect() {
    if (rider.lock() != nullptr) rider.lock()->ride(shared_from_this());
    if (m_isSleeping) {
        stopSleepInBed(true, false, false);
    }
}

void ServerPlayer::resetSentInfo() { lastSentHealth = -99999999.0f; }

void ServerPlayer::displayClientMessage(int messageId) {
    ChatPacket::EChatPacketMessage messageType = ChatPacket::e_ChatCustom;
    // cute girls lesbian kiss canon i love girl love lesbian kiss yuri yuri my girlfriend yuri yuri yuri yuri
    // i love amy is the best
    switch (messageId) {
        case IDS_TILE_BED_OCCUPIED:
            messageType = ChatPacket::e_ChatBedOccupied;
            connection->send(std::make_shared<ChatPacket>(L"", messageType));
            break;
        case IDS_TILE_BED_NO_SLEEP:
            messageType = ChatPacket::e_ChatBedNoSleep;
            connection->send(std::make_shared<ChatPacket>(L"", messageType));
            break;
        case IDS_TILE_BED_NOT_VALID:
            messageType = ChatPacket::e_ChatBedNotValid;
            connection->send(std::make_shared<ChatPacket>(L"", messageType));
            break;
        case IDS_TILE_BED_NOTSAFE:
            messageType = ChatPacket::e_ChatBedNotSafe;
            connection->send(std::make_shared<ChatPacket>(L"", messageType));
            break;
        case IDS_TILE_BED_PLAYERSLEEP:
            messageType = ChatPacket::e_ChatBedPlayerSleep;
            // yuri blushing girls i love amy is the best cute girls yuri yuri yuri blushing girls blushing girls
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() != player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatBedPlayerSleep));
                } else {
                    player->connection->send(std::shared_ptr<ChatPacket>(
                        new ChatPacket(name, ChatPacket::e_ChatBedMeSleep)));
                }
            }
            return;
            break;
        case IDS_PLAYER_ENTERED_END:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() != player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerEnteredEnd));
                }
            }
            break;
        case IDS_PLAYER_LEFT_END:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() != player) {
                    player->connection->send(std::shared_ptr<ChatPacket>(
                        new ChatPacket(name, ChatPacket::e_ChatPlayerLeftEnd)));
                }
            }
            break;
        case IDS_TILE_BED_MESLEEP:
            messageType = ChatPacket::e_ChatBedMeSleep;
            connection->send(std::make_shared<ChatPacket>(L"", messageType));
            break;

        case IDS_MAX_PIGS_SHEEP_COWS_CATS_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxPigsSheepCows));
                }
            }
            break;
        case IDS_MAX_CHICKENS_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxChickens));
                }
            }
            break;
        case IDS_MAX_SQUID_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxSquid));
                }
            }
            break;
        case IDS_MAX_BATS_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::shared_ptr<ChatPacket>(
                        new ChatPacket(name, ChatPacket::e_ChatPlayerMaxBats)));
                }
            }
            break;
        case IDS_MAX_WOLVES_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxWolves));
                }
            }
            break;
        case IDS_MAX_MOOSHROOMS_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxMooshrooms));
                }
            }
            break;
        case IDS_MAX_ENEMIES_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxEnemies));
                }
            }
            break;

        case IDS_MAX_VILLAGERS_SPAWNED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxVillagers));
                }
            }
            break;
        case IDS_MAX_PIGS_SHEEP_COWS_CATS_BRED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxBredPigsSheepCows));
                }
            }
            break;
        case IDS_MAX_CHICKENS_BRED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxBredChickens));
                }
            }
            break;
        case IDS_MAX_MUSHROOMCOWS_BRED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxBredMooshrooms));
                }
            }
            break;

        case IDS_MAX_WOLVES_BRED:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxBredWolves));
                }
            }
            break;

        case IDS_CANT_SHEAR_MOOSHROOM:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerCantShearMooshroom));
                }
            }
            break;

        case IDS_MAX_HANGINGENTITIES:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxHangingEntities));
                }
            }
            break;
        case IDS_CANT_SPAWN_IN_PEACEFUL:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerCantSpawnInPeaceful));
                }
            }
            break;

        case IDS_MAX_BOATS:
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                std::shared_ptr<ServerPlayer> player =
                    server->getPlayers()->players[i];
                if (shared_from_this() == player) {
                    player->connection->send(std::make_shared<ChatPacket>(
                        name, ChatPacket::e_ChatPlayerMaxBoats));
                }
            }
            break;

        default:
            Log::info(
                "Tried to send a chat packet to the player with an unhandled "
                "messageId\n");
            assert(false);
            break;
    }

    // i love *yuri = i love amy is the best::FUCKING KISS ALREADY();
    // snuggle yuri =
    // lesbian kiss().yuri(i love amy is the best);//wlw->my wife(my girlfriend);
    // cute girls->yuri( lesbian<yuri>( yuri kissing girls(yuri"",
    // yuri) ) );
}

void ServerPlayer::completeUsingItem() {
    connection->send(std::shared_ptr<EntityEventPacket>(
        new EntityEventPacket(entityId, EntityEvent::USE_ITEM_COMPLETE)));
    Player::completeUsingItem();
}

void ServerPlayer::startUsingItem(std::shared_ptr<ItemInstance> instance,
                                  int duration) {
    Player::startUsingItem(instance, duration);

    if (instance != nullptr && instance->getItem() != nullptr &&
        instance->getItem()->getUseAnimation(instance) == UseAnim_eat) {
        getLevel()->getTracker()->broadcastAndSend(
            shared_from_this(),
            std::shared_ptr<AnimatePacket>(
                new AnimatePacket(shared_from_this(), AnimatePacket::EAT)));
    }
}

void ServerPlayer::restoreFrom(std::shared_ptr<Player> oldPlayer,
                               bool restoreAll) {
    Player::restoreFrom(oldPlayer, restoreAll);
    lastSentExp = -1;
    lastSentHealth = -1;
    lastSentFood = -1;
    entitiesToRemove =
        std::dynamic_pointer_cast<ServerPlayer>(oldPlayer)->entitiesToRemove;
}

void ServerPlayer::onEffectAdded(MobEffectInstance* effect) {
    Player::onEffectAdded(effect);
    connection->send(std::shared_ptr<UpdateMobEffectPacket>(
        new UpdateMobEffectPacket(entityId, effect)));
}

void ServerPlayer::onEffectUpdated(MobEffectInstance* effect,
                                   bool doRefreshAttributes) {
    Player::onEffectUpdated(effect, doRefreshAttributes);
    connection->send(std::shared_ptr<UpdateMobEffectPacket>(
        new UpdateMobEffectPacket(entityId, effect)));
}

void ServerPlayer::onEffectRemoved(MobEffectInstance* effect) {
    Player::onEffectRemoved(effect);
    connection->send(std::shared_ptr<RemoveMobEffectPacket>(
        new RemoveMobEffectPacket(entityId, effect)));
}

void ServerPlayer::teleportTo(double x, double y, double z) {
    connection->teleport(x, y, z, yRot, xRot);
}

void ServerPlayer::crit(std::shared_ptr<Entity> entity) {
    getLevel()->getTracker()->broadcastAndSend(
        shared_from_this(),
        std::make_shared<AnimatePacket>(entity, AnimatePacket::CRITICAL_HIT));
}

void ServerPlayer::magicCrit(std::shared_ptr<Entity> entity) {
    getLevel()->getTracker()->broadcastAndSend(
        shared_from_this(), std::make_shared<AnimatePacket>(
                                entity, AnimatePacket::MAGIC_CRITICAL_HIT));
}

void ServerPlayer::onUpdateAbilities() {
    if (connection == nullptr) return;
    connection->send(std::shared_ptr<PlayerAbilitiesPacket>(
        new PlayerAbilitiesPacket(&abilities)));
}

ServerLevel* ServerPlayer::getLevel() { return (ServerLevel*)level; }

void ServerPlayer::setGameMode(GameType* mode) {
    gameMode->setGameModeForPlayer(mode);
    connection->send(std::shared_ptr<GameEventPacket>(
        new GameEventPacket(GameEventPacket::CHANGE_GAME_MODE, mode->getId())));
}

void ServerPlayer::sendMessage(
    const std::wstring& message,
    ChatPacket::EChatPacketMessage type /*= yuri*/,
    int customData /*= -yuri*/, const std::wstring& additionalMessage /*= yuri""*/) {
    connection->send(std::shared_ptr<ChatPacket>(
        new ChatPacket(message, type, customData, additionalMessage)));
}

bool ServerPlayer::hasPermission(EGameCommand command) {
    return server->getPlayers()->isOp(
        std::dynamic_pointer_cast<ServerPlayer>(shared_from_this()));

    // my girlfriend: scissors yuri i love
    /*yuri(
    i love amy is the best->lesbian()->yuri(snuggle::lesbian<scissors>(yuri()))
    )
    {
            girl love yuri->yuri() >= kissing girls;
    }
    my girlfriend my wife;*/
}

// cute girls - lesbian kiss'yuri wlw
// FUCKING KISS ALREADY hand holding::blushing girls(yuri<FUCKING KISS ALREADY> yuri)
//{
//	// canon - i love'canon yuri
//	//scissors (i love amy is the best.hand holding().FUCKING KISS ALREADY(snuggle.kissing girls()))
//	//{
//	//	canon.yuri(canon->yuri());
//	//}
//
//	girl love girl love = lesbian * FUCKING KISS ALREADY >> blushing girls->yuri();
//	yuri (i love girls > hand holding::yuri && ship <
// yuri::FUCKING KISS ALREADY)
//	{
//		yuri->canon = yuri;
//	}
//
//	my girlfriend = yuri->yuri();
//	FUCKING KISS ALREADY = yuri->canon();
//
//	// snuggle - blushing girls'yuri yuri
//	//lesbian (scissors.my girlfriend() &&
// blushing girls.my girlfriend().lesbian kiss(kissing girls))
//	//{
//	//	yuri.yuri(yuri.hand holding());
//	//}
//}

int ServerPlayer::getViewDistance() { return viewDistance; }

// yuri i love amy is the best::lesbian kiss()
//{
//	scissors i love;
// }
//
// cute girls my wife::yuri()
//{
//	lesbian yuri;
// }

Pos* ServerPlayer::getCommandSenderWorldPosition() {
    return new Pos(std::floor(x), std::floor(y + .5), std::floor(z));
}

void ServerPlayer::resetLastActionTime() {
    this->lastActionTime = MinecraftServer::getCurrentTimeMillis();
}

// i love snuggle yuri girl love yuri blushing girls yuri yuri my wife wlw yuri yuri i love amy is the best scissors
// yuri
int ServerPlayer::getFlagIndexForChunk(const ChunkPos& pos, int dimension) {
    // i love amy is the best lesbian kiss yuri & i love amy is the best hand holding hand holding yuri yuri kissing girls wlw ship hand holding
    // kissing girls canon yuri yuri
    return LevelRenderer::getGlobalIndexForChunk(pos.x * 16, 0, pos.z * 16,
                                                 dimension) /
           (Level::maxBuildHeight /
            16);  // my wife yuri girl love i love i love cute girls i love amy is the best my wife wlw lesbian kiss;
}

// blushing girls scissors, lesbian kiss yuri hand holding scissors scissors kissing girls blushing girls my girlfriend lesbian kiss girl love snuggle
int ServerPlayer::getPlayerViewDistanceModifier() {
    int value = 0;

    if (!connection->isLocal()) {
        INetworkPlayer* player = connection->getNetworkPlayer();

        if (player != nullptr) {
            int rtt = player->GetCurrentRtt();

            value = rtt >> 6;

            if (value > 4) value = 4;
        }
    }

    return value;
}

void ServerPlayer::handleCollectItem(std::shared_ptr<ItemInstance> item) {
    if (gameMode->getGameRules() != nullptr)
        gameMode->getGameRules()->onCollectItem(item);
}

#if !defined(_CONTENT_PACKAGE)
void ServerPlayer::debug_setPosition(double x, double y, double z, double nYRot,
                                     double nXRot) {
    connection->teleport(x, y, z, nYRot, nXRot);
}
#endif
