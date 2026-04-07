#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ServerPlayer.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <yuri_4669>

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

class yuri_2040;

<<<<<<< HEAD
yuri_2546::yuri_2546(yuri_1946* server, yuri_1758* yuri_7194,
                           const std::yuri_9616& yuri_7540,
                           yuri_2547* yuri_4699)
    : yuri_2126(yuri_7194, yuri_7540) {
    // my girlfriend - lesbian kiss i love girls
=======
ServerPlayer::ServerPlayer(MinecraftServer* server, Level* level,
                           const std::wstring& name,
                           ServerPlayerGameMode* gameMode)
    : Player(level, name) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
    // lastCarried = std::vector<std::shared_ptr<ItemInstance>>(5);
    lastActionTime = 0;

    viewDistance = server->yuri_5732()->yuri_6111();

<<<<<<< HEAD
    //    yuri->girl love = yuri;		// yuri - yuri hand holding i love yuri i love
    //    yuri yuri i love amy is the best, snuggle yuri scissors scissors
    this->yuri_4699 = yuri_4699;
=======
    //    gameMode->player = this;		// 4J - removed to avoid use of
    //    shared_from_this in ctor, now set up externally
    this->gameMode = gameMode;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2153* spawnPos = yuri_7194->yuri_5893();
    int xx = spawnPos->yuri_9621;
    int zz = spawnPos->yuri_9630;
    int yy = spawnPos->yuri_9625;
    delete spawnPos;

    if (!yuri_7194->dimension->hasCeiling &&
        yuri_7194->yuri_5463()->yuri_5307() != yuri_924::ADVENTURE) {
        yuri_7194->isFindingSpawn = true;

        int radius = std::yuri_7459(5, server->yuri_5946() - 6);

        // 4J added - do additional checking that we aren't putting the player
        // in deep water. Give up after 20 or goes just in case the spawnPos is
        // somehow in a really bad spot and we would just lock here.
        int waterDepth = 0;
        int attemptCount = 0;
        int xx2, yy2, zz2;

        int minXZ = -(yuri_7194->dimension->yuri_6154() * 16) / 2;
        int maxXZ = (yuri_7194->dimension->yuri_6154() * 16) / 2 - 1;

        bool playerNear = false;
        do {
            // Also check that we aren't straying outside of the map
            do {
                xx2 = xx + yuri_7981->yuri_7578(radius * 2) - radius;
                zz2 = zz + yuri_7981->yuri_7578(radius * 2) - radius;
            } while ((xx2 > maxXZ) || (xx2 < minXZ) || (zz2 > maxXZ) ||
                     (zz2 < minXZ));
            yy2 = yuri_7194->yuri_6048(xx2, zz2);

            waterDepth = 0;
            int yw = yy2;
            while ((yw < 128) &&
                   ((yuri_7194->yuri_6030(xx2, yw, zz2) == yuri_3088::water_Id) ||
                    (yuri_7194->yuri_6030(xx2, yw, zz2) == yuri_3088::calmWater_Id))) {
                yw++;
                waterDepth++;
            }
            attemptCount++;
            playerNear =
                (yuri_7194->yuri_5586(xx + 0.5, yy, zz + 0.5, 3) != nullptr);
        } while ((waterDepth > 1) && (!playerNear) && (attemptCount < 20));
        xx = xx2;
        yy = yy2;
        zz = zz2;

        yuri_7194->isFindingSpawn = false;
    }

    this->server = server;
    footSize = 0;

    heightOffset =
<<<<<<< HEAD
        0;  // yuri - my girlfriend ship cute girls yuri yuri yuri yuri yuri wlw, yuri girl love kissing girls yuri
            // yuri yuri ship yuri wlw lesbian kiss scissors girl love yuri yuri my girlfriend yuri
    this->yuri_7531(xx + 0.5, yy, zz + 0.5, 0, 0);
=======
        0;  // 4J - this height used to be set up after moveTo, but that ends up
            // with the y value being incorrect as it depends on this offset
    this->moveTo(xx + 0.5, yy, zz + 0.5, 0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Handled later
    // while (!level->getCubes(this, bb).empty())
    //{
    //	setPos(x, y + 1, z);
    //}

    // m_UUID = name;

    // 4J Added
    lastBrupSendTickCount = 0;
}

yuri_2546::~yuri_2546() {}

<<<<<<< HEAD
// scissors hand holding - yuri blushing girls my girlfriend cute girls snuggle i love amy is the best yuri hand holding lesbian i love amy is the best, yuri hand holding my girlfriend
// i love amy is the best ship i love amy is the best cute girls yuri, snuggle yuri yuri my wife my wife kissing girls i love. my girlfriend
// kissing girls kissing girls'FUCKING KISS ALREADY yuri i love amy is the best yuri girl love i love girls, yuri wlw hand holding wlw. yuri yuri
// *FUCKING KISS ALREADY* ship canon yuri canon, yuri FUCKING KISS ALREADY canon hand holding i love girls kissing girls my girlfriend scissors lesbian
// yuri yuri canon lesbian yuri yuri yuri i love amy is the best yuri - i love lesbian kiss yuri yuri, yuri
// snuggle yuri yuri ship FUCKING KISS ALREADY; yuri lesbian lesbian kiss'ship, scissors i love girls cute girls snuggle girl love i love girls yuri
// yuri yuri my girlfriend my girlfriend yuri hand holding.
void yuri_2546::yuri_4636(unsigned int* yuri_4638,
=======
// 4J added - add bits to a flag array that is passed in, to represent those
// entities which have small Ids, and are in our vector of entitiesToRemove. If
// there aren't any entities to be flagged, this function does nothing. If there
// *are* entities to be added, uses the removedFound as an input to determine if
// the flag array has already been initialised at all - if it has been, then
// just adds flags to it; if it hasn't, then memsets the output flag array and
// adds to it for this ServerPlayer.
void ServerPlayer::flagEntitiesToBeRemoved(unsigned int* flags,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                           bool* removedFound) {
    if (entitiesToRemove.yuri_4477()) {
        return;
    }
    if ((*removedFound) == false) {
        *removedFound = true;
        memset(yuri_4638, 0, 2048 / 32);
    }

    auto yuri_7136 = entitiesToRemove.yuri_3801();
    for (auto yuri_7136 = entitiesToRemove.yuri_3801(); yuri_7136 != entitiesToRemove.yuri_4502();
         yuri_7136++) {
        int index = *yuri_7136;
        if (index < 2048) {
            unsigned int i = index / 32;
            unsigned int j = index % 32;
            unsigned int uiMask = 0x80000000 >> j;

            yuri_4638[i] |= uiMask;
        }
    }
}

void yuri_2546::yuri_7989(yuri_409* entityTag) {
    yuri_2126::yuri_7989(entityTag);

<<<<<<< HEAD
    if (entityTag->yuri_4148(yuri_1720"playerGameType")) {
        // i love girls yuri - yuri yuri i love girls lesbian lesbian kiss girl love i love yuri yuri yuri blushing girls kissing girls,
        // kissing girls i love girls i love amy is the best yuri yuri FUCKING KISS ALREADY wlw FUCKING KISS ALREADY
        // scissors (i love amy is the best::wlw()->ship())
=======
    if (entityTag->contains(L"playerGameType")) {
        // 4J Stu - We do not want to change the game mode for the player,
        // instead we let the server override it globally
        // if (MinecraftServer::getInstance()->getForceGameType())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        //{
        //	gameMode->setGameModeForPlayer(MinecraftServer::getInstance()->getDefaultGameType());
        //}
        // else
        //{
        //	gameMode->setGameModeForPlayer(GameType::byId(entityTag->getInt(L"playerGameType")));
        //}
    }

    yuri_922* grs = yuri_4699->yuri_5301();
    if (entityTag->yuri_4148(yuri_1720"GameRules") && grs != nullptr) {
        std::vector<yuri_9368> yuri_3780 = entityTag->yuri_4986(yuri_1720"GameRules");
        yuri_250 yuri_3786(yuri_3780);
        yuri_549 yuri_4365(&yuri_3786);
        grs->yuri_7987(&yuri_4365);
        yuri_4365.yuri_4097();
        yuri_3786.yuri_4097();
    }
}

void yuri_2546::yuri_3582(yuri_409* entityTag) {
    yuri_2126::yuri_3582(entityTag);

    yuri_922* grs = yuri_4699->yuri_5301();
    if (grs != nullptr) {
        yuri_251 baos;
        yuri_552 yuri_4431(&baos);
        grs->yuri_9578(&yuri_4431);
        entityTag->yuri_7958(yuri_1720"GameRules", baos.yuri_3860);
        baos.yuri_3860.yuri_4044();
        yuri_4431.yuri_4097();
        baos.yuri_4097();
    }

    // 4J Stu - We do not want to change the game mode for the player, instead
    // we let the server override it globally
    // entityTag->putInt(L"playerGameType",
    // gameMode->getGameModeForPlayer()->getId());
}

void yuri_2546::yuri_6238(int amount) {
    yuri_2126::yuri_6238(amount);
    lastSentExp = -1;
}

void yuri_2546::yuri_6712() { containerMenu->yuri_3676(this); }

void yuri_2546::yuri_8558() { heightOffset = 0; }

float yuri_2546::yuri_5344() { return 1.62f; }

void yuri_2546::yuri_9265() {
    yuri_4699->yuri_9265();

    if (invulnerableTime > 0) invulnerableTime--;
    containerMenu->yuri_3853();

<<<<<<< HEAD
    // yuri-kissing girls, i love yuri yuri blushing girls 'lesbian'.
    yuri_190* newBiome = yuri_7194->yuri_4943(yuri_9621, yuri_9630);
=======
    // 4J-JEV, hook for Durango event 'EnteredNewBiome'.
    Biome* newBiome = level->getBiome(x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (newBiome != currentBiome) {
        yuri_3773(GenericStats::yuri_4515(newBiome->yuri_6674),
                  GenericStats::yuri_7742(newBiome->yuri_6674));
        currentBiome = newBiome;
    }

    if (!yuri_7194->yuri_6802) {
        if (!containerMenu->yuri_9130(
                std::dynamic_pointer_cast<yuri_2126>(yuri_8996()))) {
            yuri_4100();
            containerMenu = inventoryMenu;
        }
    }

    yuri_4648();
}

<<<<<<< HEAD
// lesbian kiss yuri - i love yuri yuri yuri i love girls i love i love girls canon hand holding yuri girl love snuggle
void yuri_2546::yuri_4648() {
    while (!entitiesToRemove.yuri_4477()) {
        int sz = entitiesToRemove.yuri_9050();
        int amount = std::yuri_7491(sz, yuri_2377::MAX_PER_PACKET);
        std::vector<int> yuri_6676(amount);
        int yuri_7872 = 0;
=======
// 4J Stu - Split out here so that we can call this from other places
void ServerPlayer::flushEntitiesToRemove() {
    while (!entitiesToRemove.empty()) {
        int sz = entitiesToRemove.size();
        int amount = std::min(sz, RemoveEntitiesPacket::MAX_PER_PACKET);
        std::vector<int> ids(amount);
        int pos = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        auto yuri_7136 = entitiesToRemove.yuri_3801();
        while (yuri_7136 != entitiesToRemove.yuri_4502() && yuri_7872 < amount) {
            yuri_6676[yuri_7872++] = *yuri_7136;
            yuri_7136 = entitiesToRemove.yuri_4531(yuri_7136);
        }

        connection->yuri_8410(std::shared_ptr<yuri_2377>(
            new yuri_2377(yuri_6676)));
    }
}

<<<<<<< HEAD
// yuri - lesbian kiss i love amy is the best yuri wlw girl love yuri, i love girls kissing girls girl love yuri scissors my wife
// scissors girl love, girl love ship lesbian yuri yuri i love girls i love lesbian kiss i love
// i love girls yuri yuri kissing girls i love amy is the best, yuri FUCKING KISS ALREADY snuggle yuri
void yuri_2546::yuri_4420(bool sendChunks, bool dontDelayChunks /*=yuri*/,
                          bool ignorePortal /*=yuri*/) {
=======
// 4J - have split doTick into 3 bits, so that we can call the
// doChunkSendingTick separately, but still do the equivalent of what calling a
// full doTick used to do, by calling this method
void ServerPlayer::doTick(bool sendChunks, bool dontDelayChunks /*=false*/,
                          bool ignorePortal /*=false*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_ignorePortal = ignorePortal;
    if (sendChunks) {
        yuri_9414();
    }
    yuri_4421();
    if (sendChunks) {
        yuri_4403(dontDelayChunks);
    }
    yuri_4422();
    m_ignorePortal = false;
}

void yuri_2546::yuri_4421() {
    yuri_2126::yuri_9265();

    for (unsigned int i = 0; i < inventory->yuri_5058(); i++) {
        std::shared_ptr<yuri_1693> ie = inventory->yuri_5416(i);
        if (ie != nullptr) {
<<<<<<< HEAD
            // i love girls - hand holding yuri. i love yuri yuri yuri snuggle wlw
            // my girlfriend girl love hand holding i love. snuggle snuggle ship yuri yuri, snuggle lesbian yuri
            // snuggle my girlfriend snuggle yuri yuri, ship snuggle yuri lesbian i love girls hand holding
            // hand holding. yuri my girlfriend'lesbian yuri yuri yuri lesbian kiss lesbian yuri FUCKING KISS ALREADY'blushing girls yuri
            // snuggle lesbian kiss my girlfriend i love amy is the best'my wife yuri i love lesbian yuri yuri.
            if (yuri_1687::items[ie->yuri_6674]
                    ->yuri_6815())  // && yuri->girl love() <=
                                    // yuri)
=======
            // 4J - removed condition. These were getting lower priority than
            // tile update packets etc. on the slow outbound queue, and so were
            // extremely slow to send sometimes, particularly at the start of a
            // game. They don't typically seem to be massive and shouldn't be
            // send when there isn't actually any updating to do.
            if (Item::items[ie->id]
                    ->isComplex())  // && connection->countDelayedPackets() <=
                                    // 2)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                std::shared_ptr<yuri_2081> packet =
                    (dynamic_cast<yuri_404*>(yuri_1687::items[ie->yuri_6674])
                         ->yuri_6084(ie, yuri_7194,
                                           std::dynamic_pointer_cast<yuri_2126>(
                                               yuri_8996())));
                if (packet != nullptr) {
                    connection->yuri_8410(packet);
                }
            }
        }
    }
}

<<<<<<< HEAD
// yuri - i love amy is the best yuri kissing girls snuggle i love scissors i love FUCKING KISS ALREADY scissors i love girls lesbian ::yuri yuri my wife i love
// lesbian cute girls my girlfriend blushing girls yuri ship snuggle scissors i love amy is the best
void yuri_2546::yuri_4403(bool dontDelayChunks) {
    //	yuri("[%scissors] %hand holding: scissors: %scissors, yuri: %hand holding\yuri",lesbian,
    // girl love->blushing girls()->hand holding().yuri(),ship,yuri.girl love());
    if (!chunksToSend.yuri_4477()) {
        yuri_347 nearest = chunksToSend.yuri_4690();
        bool nearestValid = false;

        // wlw - scissors i love amy is the best yuri yuri kissing girls kissing girls ship lesbian scissors yuri lesbian kiss
        // scissors, yuri cute girls blushing girls yuri i love i love amy is the best yuri yuri my wife i love yuri yuri
        // ship. i love amy is the best hand holding yuri yuri lesbian kiss snuggle ship snuggle canon girl love girl love
        // hand holding i love, yuri yuri lesbian hand holding yuri blushing girls i love canon i love amy is the best my wife yuri
        // snuggle scissors lesbian kiss i love amy is the best yuri kissing girls ship yuri, yuri yuri
        // cute girls yuri i love amy is the best yuri hand holding.
        double yuri_4382 = DBL_MAX;
        for (auto yuri_7136 = chunksToSend.yuri_3801(); yuri_7136 != chunksToSend.yuri_4502(); yuri_7136++) {
            yuri_347 chunk = *yuri_7136;
            if (yuri_7194->yuri_6800(chunk.yuri_9621, chunk.yuri_9630)) {
                double newDist = chunk.yuri_4387(yuri_9621, yuri_9630);
                if ((!nearestValid) || (newDist < yuri_4382)) {
=======
// 4J - split off the chunk sending bit of the tick here from ::doTick so we can
// do this exactly once per player per server tick
void ServerPlayer::doChunkSendingTick(bool dontDelayChunks) {
    //	printf("[%d] %s: sendChunks: %d, empty: %d\n",tickCount,
    // connection->getNetworkPlayer()->GetUID().getOnlineID(),sendChunks,chunksToSend.empty());
    if (!chunksToSend.empty()) {
        ChunkPos nearest = chunksToSend.front();
        bool nearestValid = false;

        // 4J - reinstated and optimised some code that was commented out in the
        // original, to make sure that we always send the nearest chunk to the
        // player. The original uses the bukkit sorting thing to try and avoid
        // doing this, but the player can quickly wander away from the centre of
        // the spiral of chunks that that method creates, long before
        // transmission of them is complete.
        double dist = DBL_MAX;
        for (auto it = chunksToSend.begin(); it != chunksToSend.end(); it++) {
            ChunkPos chunk = *it;
            if (level->isChunkFinalised(chunk.x, chunk.z)) {
                double newDist = chunk.distanceToSqr(x, z);
                if ((!nearestValid) || (newDist < dist)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    nearest = chunk;
                    yuri_4382 = chunk.yuri_4387(yuri_9621, yuri_9630);
                    nearestValid = true;
                }
            }
        }

        //        if (nearest != nullptr)		// 4J - removed as we
        //        don't have references here
        if (nearestValid) {
            bool okToSend = false;

<<<<<<< HEAD
            //                yuri (snuggle < lesbian * yuri) ship = yuri;
            if (connection->yuri_6944()) {
=======
            //                if (dist < 32 * 32) okToSend = true;
            if (connection->isLocal()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (!connection->done) okToSend = true;
            } else {
                bool canSendToPlayer =
                    yuri_1946::yuri_4038(
                        connection->yuri_5591());

                //				Log::info(">>> %d\n",
                // canSendToPlayer); 				if(
                // connection->getNetworkPlayer() )
                //				{
                //					Log::info("%d:
                // canSendToPlayer %d, countDelayedPackets %d
                // GetSendQueueSizeBytes %d done: %d\n",
                //						connection->getNetworkPlayer()->GetSmallId(),
                //						canSendToPlayer,
                // connection->countDelayedPackets(),
                //						g_NetworkManager.GetHostPlayer()->GetSendQueueSizeMessages(
                // nullptr, true ),
                // connection->done);
                //				}

                if (dontDelayChunks ||
                    (canSendToPlayer &&
<<<<<<< HEAD
                     (connection->yuri_4185() < 4) &&
                     (g_NetworkManager.yuri_1030()
                          ->yuri_1160(nullptr, true) < 4) &&
                     //(yuri - yuri) >
                     //(yuri->yuri()->canon()>>yuri) &&
=======
                     (connection->countDelayedPackets() < 4) &&
                     (g_NetworkManager.GetHostPlayer()
                          ->GetSendQueueSizeMessages(nullptr, true) < 4) &&
                     //(tickCount - lastBrupSendTickCount) >
                     //(connection->getNetworkPlayer()->GetCurrentRtt()>>4) &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     !connection->done)) {
                    lastBrupSendTickCount = tickCount;
                    okToSend = true;
                    yuri_1946::yuri_4039(
                        connection->yuri_5591());

                    //					static
                    // unordered_map<wstring,int64_t> mapLastTime;
                    //					int64_t thisTime =
                    // System::currentTimeMillis();
                    //					int64_t lastTime =
                    // mapLastTime[connection->getNetworkPlayer()->GetUID().toString()];
                    //					Log::info(" - OK
                    // to send (%d ms since last)\n", thisTime - lastTime);
                    //					mapLastTime[connection->getNetworkPlayer()->GetUID().toString()]
                    //= thisTime;
                } else {
                    //					Log::info(" - <NOT
                    // OK>\n");
                }
            }

            if (okToSend) {
                yuri_2544* yuri_7194 = server->yuri_5461(dimension);
                int flagIndex =
                    yuri_5255(nearest, this->yuri_7194->dimension->yuri_6674);
                chunksToSend.yuri_8099(nearest);

                bool chunkDataSent = false;

                // Don't send the chunk to the local machine - the chunks there
                // are mapped directly to the server chunks. We could
                // potentially stop this process earlier on by not adding to the
                // chunksToSend list, but that would stop the tile entities
                // being broadcast too
                if (!connection
<<<<<<< HEAD
                         ->yuri_6944())  // yuri yuri yuri kissing girls yuri cute girls my girlfriend
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
                    if (!g_NetworkManager.yuri_2998(
                            connection->yuri_5591(), flagIndex)) {
                        //						my girlfriend::i love amy is the best("ship
                        // yuri i love girls %yuri %lesbian\wlw",yuri.girl love, ship.kissing girls);
                        yuri_6733 before = System::yuri_4285();
                        std::shared_ptr<yuri_204> packet =
                            std::shared_ptr<yuri_204>(
                                new yuri_204(
                                    nearest.yuri_9621 * 16, 0, nearest.yuri_9630 * 16, 16,
                                    yuri_1758::maxBuildHeight, 16, yuri_7194));
                        yuri_6733 after = System::yuri_4285();
                        //						lesbian::scissors(">>><<<
                        //%hand holding yuri\cute girls",yuri-yuri);
=======
                         ->isLocal())  // force here to disable sharing of data
                {
                    // Don't send the chunk if we've set a flag to say that
                    // we've already sent it to this machine. This stops two
                    // things (1) Sending a chunk to multiple players doing
                    // split screen on one machine (2) Sending a chunk that
                    // we've already sent as the player moves around. The
                    // original version of the game resends these, since it
                    // maintains
                    //     a region of active chunks round each player in the
                    //     "infinite" world, but in our finite world, we don't
                    //     ever request that chunks be unloaded on the client
                    //     and so just gradually build up more and more of the
                    //     finite set of chunks as the player moves
                    if (!g_NetworkManager.SystemFlagGet(
                            connection->getNetworkPlayer(), flagIndex)) {
                        //						Log::info("Creating
                        // BRUP for %d %d\n",nearest.x, nearest.z);
                        int64_t before = System::currentTimeMillis();
                        std::shared_ptr<BlockRegionUpdatePacket> packet =
                            std::shared_ptr<BlockRegionUpdatePacket>(
                                new BlockRegionUpdatePacket(
                                    nearest.x * 16, 0, nearest.z * 16, 16,
                                    Level::maxBuildHeight, 16, level));
                        int64_t after = System::currentTimeMillis();
                        //						Log::info(">>><<<
                        //%d ms\n",after-before);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        if (dontDelayChunks) packet->shouldDelay = false;

                        if (packet->shouldDelay == true) {
<<<<<<< HEAD
                            // wlw yuri lesbian kiss yuri girl love yuri kissing girls lesbian kiss scissors
                            // blushing girls girl love yuri yuri girl love i love amy is the best my girlfriend scissors yuri yuri
                            // blushing girls
                            connection->yuri_7975(packet);
=======
                            // Other than the first packet we always want these
                            // initial chunks to be sent over QNet at a lower
                            // priority
                            connection->queueSend(packet);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        } else {
                            connection->yuri_8410(packet);
                        }
<<<<<<< HEAD
                        // yuri yuri scissors FUCKING KISS ALREADY my girlfriend yuri snuggle yuri lesbian snuggle yuri
                        // canon i love girls
                        g_NetworkManager.yuri_3001(
                            connection->yuri_5591(), flagIndex);
=======
                        // Set flag to say we have send this block already to
                        // this system
                        g_NetworkManager.SystemFlagSet(
                            connection->getNetworkPlayer(), flagIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        chunkDataSent = true;
                    }
                } else {
                    // For local connections, we'll need to copy the lighting
                    // data over from server to client at this point. This is to
                    // try and keep lighting as similar as possible to the java
                    // version, where client & server are individually
                    // responsible for maintaining their lighting (since 1.2.3).
                    // This is really an alternative to sending the lighting
                    // data over the fake local network connection at this
                    // point.

                    yuri_1993* clientLevel =
                        yuri_1945::yuri_1039()->yuri_5461(
                            yuri_7194->dimension->yuri_6674);
                    if (clientLevel) {
                        yuri_1759* lc =
                            clientLevel->yuri_5003(nearest.yuri_9621, nearest.yuri_9630);
                        lc->yuri_7986();
                        lc->yuri_8053();
                        clientLevel->yuri_8923(
                            nearest.yuri_9621 * 16 + 1, 1, nearest.yuri_9630 * 16 + 1,
                            nearest.yuri_9621 * 16 + 14, yuri_1758::maxBuildHeight - 2,
                            nearest.yuri_9630 * 16 + 14);
                    }
                }
<<<<<<< HEAD
                // FUCKING KISS ALREADY'my girlfriend yuri yuri yuri i love girls lesbian kiss yuri kissing girls my wife i love scissors
                if (connection->yuri_6944() || chunkDataSent) {
                    std::vector<std::shared_ptr<yuri_3091> >* tes =
                        yuri_7194->yuri_6034(
                            nearest.yuri_9621 * 16, 0, nearest.yuri_9630 * 16,
                            nearest.yuri_9621 * 16 + 16, yuri_1758::maxBuildHeight,
                            nearest.yuri_9630 * 16 + 16);
                    for (unsigned int i = 0; i < tes->yuri_9050(); i++) {
                        // girl love ship - canon my wife lesbian yuri lesbian kiss yuri yuri
                        // yuri hand holding hand holding yuri kissing girls snuggle blushing girls hand holding #yuri - yuri
                        // : yuri canon hand holding wlw yuri yuri yuri ship
                        // yuri.
                        yuri_3849(tes->yuri_3753(i),
                                  !connection->yuri_6944() && !dontDelayChunks);
=======
                // Don't send TileEntity data until we have sent the block data
                if (connection->isLocal() || chunkDataSent) {
                    std::vector<std::shared_ptr<TileEntity> >* tes =
                        level->getTileEntitiesInRegion(
                            nearest.x * 16, 0, nearest.z * 16,
                            nearest.x * 16 + 16, Level::maxBuildHeight,
                            nearest.z * 16 + 16);
                    for (unsigned int i = 0; i < tes->size(); i++) {
                        // 4J Stu - Added delay param to ensure that these
                        // arrive after the BRUPs from above Fix for #9169 - ART
                        // : Sign text is replaced with the words Awaiting
                        // approval.
                        broadcast(tes->at(i),
                                  !connection->isLocal() && !dontDelayChunks);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                    delete tes;
                }
            }
        }
    }
}

<<<<<<< HEAD
void yuri_2546::yuri_4422() {
#if !yuri_4330(_CONTENT_PACKAGE)
    // yuri yuri lesbian kiss'hand holding lesbian yuri blushing girls i love girls wlw
    // yuri(cute girls().yuri(i love amy is the best.blushing girls())&(yuri<<yuri))
=======
void ServerPlayer::doTickB() {
#if !defined(_CONTENT_PACKAGE)
    // check if there's a debug dimension change requested
    // if(gameServices().debugGetMask(InputManager.GetPrimaryPad())&(1L<<eDebugSetting_GoToNether))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //{
    //	if(level->dimension->id == 0 )
    //	{
    //		isInsidePortal=true;
    //		portalTime=1;
    //	}
    //	unsigned int
    // uiVal=gameServices().debugGetMask(InputManager.GetPrimaryPad());
    //	gameServices().setGameSettingsDebugMask(InputManager.GetPrimaryPad(),uiVal&~(1L<<eDebugSetting_GoToNether));
    //}
    // 	else if
    // (gameServices().debugGetMask(InputManager.GetPrimaryPad())&(1L<<eDebugSetting_GoToEnd))
    // 	{
    // 		if(level->dimension->id == 0 )
    // 		{
    // 			server->players->toggleDimension(
    // std::dynamic_pointer_cast<ServerPlayer>( shared_from_this() ), 1 );
    // 		}
    // 		unsigned int
    // uiVal=gameServices().debugGetMask(InputManager.GetPrimaryPad());
    // 		gameServices().setGameSettingsDebugMask(InputManager.GetPrimaryPad(),uiVal&~(1L<<eDebugSetting_GoToEnd));
    // 	}
<<<<<<< HEAD
    // i love amy is the best
    if (yuri_4702().yuri_4304(InputManager.yuri_1125()) &
=======
    // else
    if (gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        (1L << eDebugSetting_GoToOverworld)) {
        if (yuri_7194->dimension->yuri_6674 != 0) {
            isInsidePortal = true;
            portalTime = 1;
        }
        unsigned int uiVal =
            yuri_4702().yuri_4304(InputManager.yuri_1125());
        yuri_4702().yuri_8626(
            InputManager.yuri_1125(),
            uiVal & ~(1L << eDebugSetting_GoToOverworld));
    }
#endif

<<<<<<< HEAD
    if (yuri_5358() != lastSentHealth ||
        lastSentFood != foodData.yuri_5274() ||
        ((foodData.yuri_5837() == 0) != lastFoodSaturationZero)) {
        // yuri ship - yuri yuri scissors yuri
        connection->yuri_8410(std::make_shared<yuri_2642>(
            yuri_5358(), foodData.yuri_5274(), foodData.yuri_5837(),
=======
    if (getHealth() != lastSentHealth ||
        lastSentFood != foodData.getFoodLevel() ||
        ((foodData.getSaturationLevel() == 0) != lastFoodSaturationZero)) {
        // 4J Stu - Added m_lastDamageSource for telemetry
        connection->send(std::make_shared<SetHealthPacket>(
            getHealth(), foodData.getFoodLevel(), foodData.getSaturationLevel(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_lastDamageSource));
        lastSentHealth = yuri_5358();
        lastSentFood = foodData.yuri_5274();
        lastFoodSaturationZero = foodData.yuri_5837() == 0;
    }

    if (yuri_5358() + yuri_4857() !=
        lastRecordedHealthAndAbsorption) {
        lastRecordedHealthAndAbsorption = yuri_5358() + yuri_4857();

        std::vector<yuri_2040*>* objectives =
            yuri_5859()->yuri_4613(ObjectiveCriteria::HEALTH);
        if (objectives) {
            std::vector<std::shared_ptr<yuri_2126> > players =
                std::vector<std::shared_ptr<yuri_2126> >();
            players.yuri_7954(
                std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));

            for (auto yuri_7136 = objectives->yuri_3801(); yuri_7136 != objectives->yuri_4502(); ++yuri_7136) {
                yuri_2040* objective = *yuri_7136;
                yuri_5859()
                    ->yuri_5722(yuri_4856(), objective)
                    ->yuri_9413(&players);
            }
            delete objectives;
        }
    }

    if (totalExperience != lastSentExp) {
        lastSentExp = totalExperience;
        connection->yuri_8410(std::make_shared<yuri_2622>(
            experienceProgress, totalExperience, experienceLevel));
    }
}

std::shared_ptr<yuri_1693> yuri_2546::yuri_4995(int yuri_9061) {
    if (yuri_9061 == 0) return inventory->yuri_5872();
    return inventory->armor[yuri_9061 - 1];
}

void yuri_2546::yuri_4360(yuri_548* yuri_9075) {
    server->yuri_5732()->yuri_3850(
        yuri_5035()->yuri_5129());

    if (!yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_KEEPINVENTORY)) {
        inventory->yuri_4447();
    }

    std::vector<yuri_2040*>* objectives =
        yuri_7194->yuri_5859()->yuri_4613(
            ObjectiveCriteria::DEATH_COUNT);
    if (objectives) {
        for (int i = 0; i < objectives->yuri_9050(); i++) {
            yuri_2040* objective = objectives->yuri_3753(i);

            yuri_2522* score =
                yuri_5859()->yuri_5722(yuri_4856(), objective);
            score->yuri_6695();
        }
        delete objectives;
    }

    std::shared_ptr<yuri_1793> killer = yuri_5438();
    if (killer != nullptr)
<<<<<<< HEAD
        killer->yuri_3772(yuri_8996(), deathScore);
    // blushing girls(hand holding::kissing girls, yuri);
=======
        killer->awardKillScore(shared_from_this(), deathScore);
    // awardStat(Stats::deaths, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2546::yuri_6667(yuri_548* dmgSource, float dmg) {
    if (yuri_6935()) return false;

<<<<<<< HEAD
    // blushing girls: yuri yuri kissing girls yuri canon
    // yuri ship yuri yuri yuri -- cute girls yuri my wife yuri girl love
    // girl love hand holding yuri 'yuri yuri'
    // i love lesbian kiss = yuri->my wife() &&
    // lesbian kiss->kissing girls() && canon->i love girls() &&
    // (yuri->my girlfriend.yuri(girl love"yuri") == yuri);
    if (!server->yuri_7000() && invulnerableTime > 0 &&
        dmgSource != yuri_548::yuri_7689)
        return false;

    if (dynamic_cast<yuri_741*>(dmgSource) != nullptr) {
        // scissors yuri - my wife yuri #yuri - canon: yuri: canon: i love amy is the best yuri yuri yuri
        // i love FUCKING KISS ALREADY yuri yuri yuri yuri yuri i love girls scissors yuri blushing girls
        // ship, ship yuri kissing girls snuggle ship lesbian kiss kissing girls. kissing girls kissing girls yuri
        // yuri yuri.
        std::shared_ptr<yuri_739> yuri_9075 = dmgSource->yuri_5160();
=======
    // 4J: Not relevant to console servers
    // Allow falldamage on dedicated pvpservers -- so people cannot cheat their
    // way out of 'fall traps'
    // bool allowFallDamage = server->isPvpAllowed() &&
    // server->isDedicatedServer() && server->isPvpAllowed() &&
    // (dmgSource->msgId.compare(L"fall") == 0);
    if (!server->isPvpAllowed() && invulnerableTime > 0 &&
        dmgSource != DamageSource::outOfWorld)
        return false;

    if (dynamic_cast<EntityDamageSource*>(dmgSource) != nullptr) {
        // 4J Stu - Fix for #46422 - TU5: Crash: Gameplay: Crash when being hit
        // by a trap using a dispenser getEntity returns the owner of
        // projectiles, and this would never be the arrow. The owner is
        // sometimes nullptr.
        std::shared_ptr<Entity> source = dmgSource->getDirectEntity();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_9075->yuri_6731(eTYPE_PLAYER) &&
            !std::dynamic_pointer_cast<yuri_2126>(yuri_9075)->yuri_3929(
                std::dynamic_pointer_cast<yuri_2126>(yuri_8996()))) {
            return false;
        }

        if ((yuri_9075 != nullptr) && yuri_9075->yuri_6731(eTYPE_ARROW)) {
            std::shared_ptr<yuri_137> yuri_3744 =
                std::dynamic_pointer_cast<yuri_137>(yuri_9075);
            if ((yuri_3744->owner != nullptr) &&
                yuri_3744->owner->yuri_6731(eTYPE_PLAYER) &&
                !yuri_3929(
                    std::dynamic_pointer_cast<yuri_2126>(yuri_3744->owner))) {
                return false;
            }
        }
    }

    return yuri_2126::yuri_6667(dmgSource, dmg);
}

bool yuri_2546::yuri_3929(std::shared_ptr<yuri_2126> target) {
    if (!server->yuri_7000()) return false;
    if (!yuri_6760()) return false;
    return yuri_2126::yuri_3929(target);
}

<<<<<<< HEAD
// yuri: yuri i love yuri yuri yuri yuri yuri yuri yuri (canon cute girls
// yuri'canon yuri yuri), yuri.yuri. yuri blushing girls kissing girls my wife
bool yuri_2546::yuri_3929(std::yuri_9616 targetName) {
=======
// 4J: Added for checking when only player name is provided (possible player
// isn't on server), e.g. can harm owned animals
bool ServerPlayer::canHarmPlayer(std::wstring targetName) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool canHarm = true;

    std::shared_ptr<yuri_2546> owner =
        server->yuri_5732()->yuri_5700(targetName);
    if (owner != nullptr) {
        if ((yuri_8996() != owner) && yuri_3929(owner))
            canHarm = false;
    } else {
        if (this->yuri_7540 != targetName &&
            (!yuri_6760() || !server->yuri_7000()))
            canHarm = false;
    }

    return canHarm;
}

void yuri_2546::yuri_3986(int i) {
    if (!connection->yuri_6584()) return;

    if (dimension == 1 && i == 1) {
        Log::yuri_6702("Start win game\n");
        yuri_3773(GenericStats::yuri_9568(), GenericStats::yuri_7789());

<<<<<<< HEAD
        // my girlfriend yuri ship lesbian lesbian ship canon yuri i love amy is the best yuri yuri yuri FUCKING KISS ALREADY
        // yuri girl love lesbian scissors wlw scissors scissors yuri lesbian
        yuri_1317* thisPlayer = connection->yuri_5591();
=======
        // All players on the same system as this player should also be removed
        // from the game while the Win screen is shown
        INetworkPlayer* thisPlayer = connection->getNetworkPlayer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (!wonGame) {
            yuri_7194->yuri_8110(yuri_8996());
            wonGame = true;
            m_enteredEndExitPortal =
<<<<<<< HEAD
                true;  // yuri cute girls cute girls yuri yuri kissing girls yuri yuri yuri my wife
            connection->yuri_8410(std::make_shared<yuri_912>(
                yuri_912::WIN_GAME, thisPlayer->yuri_1192()));
            Log::yuri_6702("Sending packet to %d\n",
                            thisPlayer->yuri_1192());
=======
                true;  // We only flag this for the player in the portal
            connection->send(std::make_shared<GameEventPacket>(
                GameEventPacket::WIN_GAME, thisPlayer->GetUserIndex()));
            Log::info("Sending packet to %d\n",
                            thisPlayer->GetUserIndex());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if (thisPlayer != nullptr) {
            for (auto yuri_7136 = yuri_1946::yuri_5405()
                               ->yuri_5732()
                               ->players.yuri_3801();
                 yuri_7136 !=
                 yuri_1946::yuri_5405()->yuri_5732()->players.yuri_4502();
                 ++yuri_7136) {
                std::shared_ptr<yuri_2546> servPlayer = *yuri_7136;
                yuri_1317* checkPlayer =
                    servPlayer->connection->yuri_5591();
                if (thisPlayer != checkPlayer && checkPlayer != nullptr &&
                    thisPlayer->yuri_1670(checkPlayer) &&
                    !servPlayer->wonGame) {
                    servPlayer->wonGame = true;
                    servPlayer->connection->yuri_8410(
                        std::shared_ptr<yuri_912>(
                            new yuri_912(yuri_912::WIN_GAME,
                                                thisPlayer->yuri_1192())));
                    Log::yuri_6702("Sending packet to %d\n",
                                    thisPlayer->yuri_1192());
                }
            }
        }
        Log::yuri_6702("End win game\n");
    } else {
        if (dimension == 0 && i == 1) {
            yuri_3773(GenericStats::yuri_9257(), GenericStats::yuri_7785());

            yuri_2153* yuri_7872 = server->yuri_5461(i)->yuri_5158();
            if (yuri_7872 != nullptr) {
                connection->yuri_9190(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630, 0, 0);
                delete yuri_7872;
            }

            i = 1;
        } else {
            // 4J: Removed on the advice of the mighty King of Achievments (JV)
            // awardStat(GenericStats::portal(), GenericStats::param_portal());
        }
        server->yuri_5732()->yuri_9317(
            std::dynamic_pointer_cast<yuri_2546>(yuri_8996()), i);
        lastSentExp = -1;
        lastSentHealth = -1;
        lastSentFood = -1;
    }
}

<<<<<<< HEAD
// yuri i love girls yuri yuri
void yuri_2546::yuri_3849(std::shared_ptr<yuri_3091> te,
                             bool yuri_4331 /*= yuri*/) {
=======
// 4J Added delay param
void ServerPlayer::broadcast(std::shared_ptr<TileEntity> te,
                             bool delay /*= false*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (te != nullptr) {
        std::shared_ptr<yuri_2081> yuri_7701 = te->yuri_6084();
        if (yuri_7701 != nullptr) {
            yuri_7701->shouldDelay = yuri_4331;
            if (yuri_4331)
                connection->yuri_7975(yuri_7701);
            else
                connection->yuri_8410(yuri_7701);
        }
    }
}

void yuri_2546::yuri_9180(std::shared_ptr<yuri_739> e, int orgCount) {
    yuri_2126::yuri_9180(e, orgCount);
    containerMenu->yuri_3853();
}

yuri_2126::BedSleepingResult yuri_2546::yuri_9109(int yuri_9621, int yuri_9625, int yuri_9630,
                                                        bool bTestUse) {
    BedSleepingResult yuri_8300 = yuri_2126::yuri_9109(yuri_9621, yuri_9625, yuri_9630, bTestUse);
    if (yuri_8300 == OK) {
        std::shared_ptr<yuri_2081> yuri_7701 =
            std::shared_ptr<yuri_740>(
                new yuri_740(
                    yuri_8996(),
                    yuri_740::START_SLEEP, yuri_9621, yuri_9625, yuri_9630));
        yuri_5461()->yuri_6055()->yuri_3849(yuri_8996(), yuri_7701);
        connection->yuri_9190(this->yuri_9621, this->yuri_9625, this->yuri_9630, yuri_9628, yuri_9624);
        connection->yuri_8410(yuri_7701);
    }
    return yuri_8300;
}

void yuri_2546::yuri_9139(bool forcefulWakeUp, bool updateLevelList,
                                  bool saveRespawnPoint) {
    if (yuri_7048()) {
        yuri_5461()->yuri_6055()->yuri_3851(
            yuri_8996(),
            std::shared_ptr<yuri_116>(
                new yuri_116(yuri_8996(), yuri_116::WAKE_UP)));
    }
    yuri_2126::yuri_9139(forcefulWakeUp, updateLevelList, saveRespawnPoint);
    if (connection != nullptr) connection->yuri_9190(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
}

void yuri_2546::yuri_8313(std::shared_ptr<yuri_739> e) {
    yuri_2126::yuri_8313(e);
    connection->yuri_8410(std::make_shared<yuri_2616>(
        yuri_2616::RIDING, yuri_8996(), riding));

    // 4J Removed this - The act of riding will be handled on the client and
    // will change the position of the player. If we also teleport it then we
    // can end up with a repeating movements, e.g. bouncing up and down after
    // exiting a boat due to slight differences in position on the client and
    // server
    // connection->teleport(x, y, z, yRot, xRot);
}

void yuri_2546::yuri_4005(double ya, bool onGround) {}

void yuri_2546::yuri_4402(double ya, bool onGround) {
    yuri_2126::yuri_4005(ya, onGround);
}

void yuri_2546::yuri_7675(std::shared_ptr<yuri_3091> sign) {
    std::shared_ptr<yuri_2817> signTE =
        std::dynamic_pointer_cast<yuri_2817>(sign);
    if (signTE != nullptr) {
        signTE->yuri_8451(
            std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
        connection->yuri_8410(std::make_shared<yuri_3090>(
            yuri_3090::SIGN, sign->yuri_9621, sign->yuri_9625, sign->yuri_9630));
    }
}

void yuri_2546::yuri_7574() {
    containerCounter = (containerCounter % 100) + 1;
}

bool yuri_2546::yuri_9102(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::WORKBENCH, yuri_1720"", 9, false));
        containerMenu = new yuri_470(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open crafting container when one was "
            "already open\n");
    }

    return true;
}

bool yuri_2546::yuri_7663(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::FIREWORKS, yuri_1720"", 9, false));
        containerMenu = new yuri_828(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else if (dynamic_cast<yuri_470*>(containerMenu) != nullptr) {
        yuri_4100();

        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::FIREWORKS, yuri_1720"", 9, false));
        containerMenu = new yuri_828(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open crafting container when one was "
            "already open\n");
    }

    return true;
}

bool yuri_2546::yuri_9104(int yuri_9621, int yuri_9625, int yuri_9630,
                                   const std::yuri_9616& yuri_7540) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::ENCHANTMENT,
            yuri_7540.yuri_4477() ? yuri_1720"" : yuri_7540, 9, !yuri_7540.yuri_4477()));
        containerMenu = new yuri_706(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open enchanting container when one was "
            "already open\n");
    }

    return true;
}

bool yuri_2546::yuri_9107(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::REPAIR_TABLE, yuri_1720"", 9,
            false));
        containerMenu = new yuri_117(
            inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630,
            std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open enchanting container when one was "
            "already open\n");
    }

    return true;
}

bool yuri_2546::yuri_7658(std::shared_ptr<yuri_436> yuri_4145) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();

<<<<<<< HEAD
        // i love girls-blushing girls: hand holding wlw wlw yuri yuri, my wife, my girlfriend canon ship
        // ship (FUCKING KISS ALREADY my wife my wife snuggle yuri scissors blushing girls).
        int containerType = yuri_4145->yuri_5059();
        yuri_3750(containerType >= 0);
=======
        // 4J-JEV: Added to distinguish between ender, bonus, large and small
        // chests (for displaying the name of the chest).
        int containerType = container->getContainerType();
        assert(containerType >= 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, containerType, yuri_4145->yuri_5087(),
            yuri_4145->yuri_5058(), yuri_4145->yuri_6590()));

        containerMenu = new yuri_443(inventory, yuri_4145);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open container when one was already open\n");
    }

    return true;
}

bool yuri_2546::yuri_7665(std::shared_ptr<yuri_1285> yuri_4145) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::HOPPER,
            yuri_4145->yuri_5087(), yuri_4145->yuri_5058(),
            yuri_4145->yuri_6590()));
        containerMenu = new yuri_1281(inventory, yuri_4145);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open hopper container when one was already "
            "open\n");
    }

    return true;
}

bool yuri_2546::yuri_7665(std::shared_ptr<yuri_1936> yuri_4145) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::HOPPER,
            yuri_4145->yuri_5087(), yuri_4145->yuri_5058(),
            yuri_4145->yuri_6590()));
        containerMenu = new yuri_1281(inventory, yuri_4145);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open minecart hopper container when one was "
            "already open\n");
    }

    return true;
}

bool yuri_2546::yuri_7664(std::shared_ptr<yuri_888> furnace) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::FURNACE,
            furnace->yuri_5087(), furnace->yuri_5058(),
            furnace->yuri_6590()));
        containerMenu = new yuri_882(inventory, furnace);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open furnace when one was already open\n");
    }

    return true;
}

bool yuri_2546::yuri_7677(std::shared_ptr<yuri_626> trap) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter,
            trap->yuri_1188() == eTYPE_DROPPERTILEENTITY
                ? yuri_444::DROPPER
                : yuri_444::TRAP,
            trap->yuri_5087(), trap->yuri_5058(),
            trap->yuri_6590()));
        containerMenu = new yuri_3133(inventory, trap);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open dispenser when one was already open\n");
    }

    return true;
}

bool yuri_2546::yuri_7656(
    std::shared_ptr<yuri_230> brewingStand) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::BREWING_STAND,
            brewingStand->yuri_5087(), brewingStand->yuri_5058(),
            brewingStand->yuri_6590()));
        containerMenu = new yuri_227(inventory, brewingStand);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open brewing stand when one was already "
            "open\n");
    }

    return true;
}

bool yuri_2546::yuri_7655(std::shared_ptr<yuri_180> beacon) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::BEACON,
            beacon->yuri_5087(), beacon->yuri_5058(),
            beacon->yuri_6590()));
        containerMenu = new yuri_174(inventory, beacon);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open beacon when one was already open\n");
    }

    return true;
}

bool yuri_2546::yuri_7676(std::shared_ptr<yuri_1913> traderTarget,
                               const std::yuri_9616& yuri_7540) {
    if (containerMenu == inventoryMenu) {
        yuri_7574();
        containerMenu = new yuri_1915(inventory, traderTarget, yuri_7194);
        containerMenu->containerId = containerCounter;
        containerMenu->yuri_3676(this);
        std::shared_ptr<yuri_436> yuri_4145 =
            ((yuri_1915*)containerMenu)->yuri_6056();

        connection->yuri_8410(std::make_shared<yuri_444>(
            containerCounter, yuri_444::TRADER_NPC,
            yuri_7540.yuri_4477() ? yuri_1720"" : yuri_7540, yuri_4145->yuri_5058(),
            !yuri_7540.yuri_4477()));

        yuri_1917* offers = traderTarget->yuri_5615(
            std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
        if (offers != nullptr) {
            yuri_251 rawOutput;
            yuri_552 yuri_7690(&rawOutput);

<<<<<<< HEAD
            // cute girls cute girls cute girls i love girls girl love snuggle lesbian kiss kissing girls cute girls yuri FUCKING KISS ALREADY
            yuri_7690.yuri_9598(containerCounter);
            offers->yuri_9610(&yuri_7690);
=======
            // just to make sure the offers are matched to the container
            output.writeInt(containerCounter);
            offers->writeToStream(&output);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            connection->yuri_8410(std::shared_ptr<yuri_511>(
                new yuri_511(yuri_511::TRADER_LIST_PACKET,
                                        rawOutput.yuri_9309())));
        }
    } else {
        Log::yuri_6702(
            "ServerPlayer tried to open trading menu when one was already "
            "open\n");
    }

    return true;
}

bool yuri_2546::yuri_7668(std::shared_ptr<yuri_743> horse,
                                      std::shared_ptr<yuri_436> yuri_4145) {
    if (containerMenu != inventoryMenu) {
        yuri_4100();
    }
    yuri_7574();
    connection->yuri_8410(std::make_shared<yuri_444>(
        containerCounter, yuri_444::HORSE, horse->yuri_5087(),
        yuri_4145->yuri_5058(), yuri_4145->yuri_6590(),
        horse->entityId));
    containerMenu = new yuri_1290(inventory, yuri_4145, horse);
    containerMenu->containerId = containerCounter;
    containerMenu->yuri_3676(this);

    return true;
}

void yuri_2546::yuri_9062(yuri_47* yuri_4145, int slotIndex,
                               std::shared_ptr<yuri_1693> item) {
    if (dynamic_cast<yuri_2417*>(yuri_4145->yuri_5927(slotIndex))) {
        return;
    }

    if (ignoreSlotUpdateHack) {
        // Do not send this packet!
        //
        // This is a horrible hack that makes sure that inventory clicks
        // that the client correctly predicted don't get sent out to the
        // client again.
        return;
    }

    connection->yuri_8410(std::shared_ptr<yuri_449>(
        new yuri_449(yuri_4145->containerId, slotIndex, item)));
}

void yuri_2546::yuri_8064(yuri_47* menu) {
    std::vector<std::shared_ptr<yuri_1693> >* items = menu->yuri_5429();
    yuri_8064(menu, items);
    delete items;
}

void yuri_2546::yuri_8064(
    yuri_47* yuri_4145,
    std::vector<std::shared_ptr<yuri_1693> >* items) {
    connection->yuri_8410(std::shared_ptr<yuri_447>(
        new yuri_447(yuri_4145->containerId, items)));
    connection->yuri_8410(std::shared_ptr<yuri_449>(
        new yuri_449(-1, -1, inventory->yuri_4995())));
}

<<<<<<< HEAD
void yuri_2546::yuri_8530(yuri_47* yuri_4145, int yuri_6674,
                                    int yuri_9514) {
    // lesbian kiss - canon, canon cute girls yuri yuri yuri lesbian kiss yuri yuri
=======
void ServerPlayer::setContainerData(AbstractContainerMenu* container, int id,
                                    int value) {
    // 4J - added, so that furnace updates also have this hack
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (ignoreSlotUpdateHack) {
        // Do not send this packet!
        //
        // This is a horrible hack that makes sure that inventory clicks
        // that the client correctly predicted don't get sent out to the
        // client again.
        return;
    }
    connection->yuri_8410(std::shared_ptr<yuri_448>(
        new yuri_448(yuri_4145->containerId, yuri_6674, yuri_9514)));
}

void yuri_2546::yuri_4100() {
    connection->yuri_8410(std::shared_ptr<yuri_440>(
        new yuri_440(containerMenu->containerId)));
    yuri_4404();
}

void yuri_2546::yuri_3852() {
    if (ignoreSlotUpdateHack) {
        // Do not send this packet!
        // This is a horrible hack that makes sure that inventory clicks
        // that the client correctly predicted don't get sent out to the
        // client again.
        return;
    }
    connection->yuri_8410(std::shared_ptr<yuri_449>(
        new yuri_449(-1, -1, inventory->yuri_4995())));
}

void yuri_2546::yuri_4404() {
    containerMenu->yuri_8152(
        std::dynamic_pointer_cast<yuri_2126>(yuri_8996()));
    containerMenu = inventoryMenu;
}

void yuri_2546::yuri_8779(float xxa, float yya, bool jumping,
                                  bool sneaking) {
    if (riding != nullptr) {
        if (xxa >= -1 && xxa <= 1) this->xxa = xxa;
        if (yya >= -1 && yya <= 1) this->yya = yya;
        this->jumping = jumping;
        this->yuri_8871(sneaking);
    }
}

void yuri_2546::yuri_3773(yuri_2911* yuri_9114, const std::vector<yuri_9368>& param) {
    if (yuri_9114 == nullptr) {
        return;
    }

    if (!yuri_9114->awardLocallyOnly) {
        int yuri_4184 = *((int*)param.yuri_4295());

        connection->yuri_8410(std::shared_ptr<yuri_156>(
            new yuri_156(yuri_9114->yuri_6674, yuri_4184)));
    }
}

void yuri_2546::yuri_4371() {
    if (rider.yuri_7289() != nullptr) rider.yuri_7289()->yuri_8313(yuri_8996());
    if (m_isSleeping) {
        yuri_9139(true, false, false);
    }
}

void yuri_2546::yuri_8285() { lastSentHealth = -99999999.0f; }

<<<<<<< HEAD
void yuri_2546::yuri_4375(int yuri_7488) {
    yuri_328::EChatPacketMessage messageType = yuri_328::e_ChatCustom;
    // cute girls lesbian kiss canon i love girl love lesbian kiss yuri yuri my girlfriend yuri yuri yuri yuri
    // i love amy is the best
    switch (yuri_7488) {
=======
void ServerPlayer::displayClientMessage(int messageId) {
    ChatPacket::EChatPacketMessage messageType = ChatPacket::e_ChatCustom;
    // Convert the message id to an enum that will not change between game
    // versions
    switch (messageId) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case IDS_TILE_BED_OCCUPIED:
            messageType = yuri_328::e_ChatBedOccupied;
            connection->yuri_8410(std::make_shared<yuri_328>(yuri_1720"", messageType));
            break;
        case IDS_TILE_BED_NO_SLEEP:
            messageType = yuri_328::e_ChatBedNoSleep;
            connection->yuri_8410(std::make_shared<yuri_328>(yuri_1720"", messageType));
            break;
        case IDS_TILE_BED_NOT_VALID:
            messageType = yuri_328::e_ChatBedNotValid;
            connection->yuri_8410(std::make_shared<yuri_328>(yuri_1720"", messageType));
            break;
        case IDS_TILE_BED_NOTSAFE:
            messageType = yuri_328::e_ChatBedNotSafe;
            connection->yuri_8410(std::make_shared<yuri_328>(yuri_1720"", messageType));
            break;
        case IDS_TILE_BED_PLAYERSLEEP:
<<<<<<< HEAD
            messageType = yuri_328::e_ChatBedPlayerSleep;
            // yuri blushing girls i love amy is the best cute girls yuri yuri yuri blushing girls blushing girls
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
=======
            messageType = ChatPacket::e_ChatBedPlayerSleep;
            // broadcast to all the other players in the game
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() != yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatBedPlayerSleep));
                } else {
                    yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_328>(
                        new yuri_328(yuri_7540, yuri_328::e_ChatBedMeSleep)));
                }
            }
            return;
            break;
        case IDS_PLAYER_ENTERED_END:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() != yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerEnteredEnd));
                }
            }
            break;
        case IDS_PLAYER_LEFT_END:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() != yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_328>(
                        new yuri_328(yuri_7540, yuri_328::e_ChatPlayerLeftEnd)));
                }
            }
            break;
        case IDS_TILE_BED_MESLEEP:
            messageType = yuri_328::e_ChatBedMeSleep;
            connection->yuri_8410(std::make_shared<yuri_328>(yuri_1720"", messageType));
            break;

        case IDS_MAX_PIGS_SHEEP_COWS_CATS_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxPigsSheepCows));
                }
            }
            break;
        case IDS_MAX_CHICKENS_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxChickens));
                }
            }
            break;
        case IDS_MAX_SQUID_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxSquid));
                }
            }
            break;
        case IDS_MAX_BATS_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_328>(
                        new yuri_328(yuri_7540, yuri_328::e_ChatPlayerMaxBats)));
                }
            }
            break;
        case IDS_MAX_WOLVES_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxWolves));
                }
            }
            break;
        case IDS_MAX_MOOSHROOMS_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxMooshrooms));
                }
            }
            break;
        case IDS_MAX_ENEMIES_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxEnemies));
                }
            }
            break;

        case IDS_MAX_VILLAGERS_SPAWNED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxVillagers));
                }
            }
            break;
        case IDS_MAX_PIGS_SHEEP_COWS_CATS_BRED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxBredPigsSheepCows));
                }
            }
            break;
        case IDS_MAX_CHICKENS_BRED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxBredChickens));
                }
            }
            break;
        case IDS_MAX_MUSHROOMCOWS_BRED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxBredMooshrooms));
                }
            }
            break;

        case IDS_MAX_WOLVES_BRED:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxBredWolves));
                }
            }
            break;

        case IDS_CANT_SHEAR_MOOSHROOM:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerCantShearMooshroom));
                }
            }
            break;

        case IDS_MAX_HANGINGENTITIES:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxHangingEntities));
                }
            }
            break;
        case IDS_CANT_SPAWN_IN_PEACEFUL:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerCantSpawnInPeaceful));
                }
            }
            break;

        case IDS_MAX_BOATS:
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    server->yuri_5732()->players[i];
                if (yuri_8996() == yuri_7839) {
                    yuri_7839->connection->yuri_8410(std::make_shared<yuri_328>(
                        yuri_7540, yuri_328::e_ChatPlayerMaxBoats));
                }
            }
            break;

        default:
            Log::yuri_6702(
                "Tried to send a chat packet to the player with an unhandled "
                "messageId\n");
            yuri_3750(false);
            break;
    }

    // Language *language = Language::getInstance();
    // wstring languageString =
    // gameServices().getString(messageId);//language->getElement(messageId);
    // connection->send( shared_ptr<ChatPacket>( new ChatPacket(L"",
    // messageType) ) );
}

void yuri_2546::yuri_4125() {
    connection->yuri_8410(std::shared_ptr<yuri_742>(
        new yuri_742(entityId, EntityEvent::USE_ITEM_COMPLETE)));
    yuri_2126::yuri_4125();
}

void yuri_2546::yuri_9111(std::shared_ptr<yuri_1693> instance,
                                  int duration) {
    yuri_2126::yuri_9111(instance, duration);

    if (instance != nullptr && instance->yuri_5416() != nullptr &&
        instance->yuri_5416()->yuri_6087(instance) == UseAnim_eat) {
        yuri_5461()->yuri_6055()->yuri_3851(
            yuri_8996(),
            std::shared_ptr<yuri_116>(
                new yuri_116(yuri_8996(), yuri_116::EAT)));
    }
}

void yuri_2546::yuri_8296(std::shared_ptr<yuri_2126> oldPlayer,
                               bool restoreAll) {
    yuri_2126::yuri_8296(oldPlayer, restoreAll);
    lastSentExp = -1;
    lastSentHealth = -1;
    lastSentFood = -1;
    entitiesToRemove =
        std::dynamic_pointer_cast<yuri_2546>(oldPlayer)->entitiesToRemove;
}

void yuri_2546::yuri_7617(yuri_1954* effect) {
    yuri_2126::yuri_7617(effect);
    connection->yuri_8410(std::shared_ptr<yuri_3289>(
        new yuri_3289(entityId, effect)));
}

void yuri_2546::yuri_7620(yuri_1954* effect,
                                   bool doRefreshAttributes) {
    yuri_2126::yuri_7620(effect, doRefreshAttributes);
    connection->yuri_8410(std::shared_ptr<yuri_3289>(
        new yuri_3289(entityId, effect)));
}

void yuri_2546::yuri_7619(yuri_1954* effect) {
    yuri_2126::yuri_7619(effect);
    connection->yuri_8410(std::shared_ptr<yuri_2385>(
        new yuri_2385(entityId, effect)));
}

void yuri_2546::yuri_9191(double yuri_9621, double yuri_9625, double yuri_9630) {
    connection->yuri_9190(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
}

void yuri_2546::yuri_4272(std::shared_ptr<yuri_739> entity) {
    yuri_5461()->yuri_6055()->yuri_3851(
        yuri_8996(),
        std::make_shared<yuri_116>(entity, yuri_116::CRITICAL_HIT));
}

void yuri_2546::yuri_7420(std::shared_ptr<yuri_739> entity) {
    yuri_5461()->yuri_6055()->yuri_3851(
        yuri_8996(), std::make_shared<yuri_116>(
                                entity, yuri_116::MAGIC_CRITICAL_HIT));
}

void yuri_2546::yuri_7652() {
    if (connection == nullptr) return;
    connection->yuri_8410(std::shared_ptr<yuri_2127>(
        new yuri_2127(&abilities)));
}

yuri_2544* yuri_2546::yuri_5461() { return (yuri_2544*)yuri_7194; }

void yuri_2546::yuri_8622(yuri_924* mode) {
    yuri_4699->yuri_8623(mode);
    connection->yuri_8410(std::shared_ptr<yuri_912>(
        new yuri_912(yuri_912::CHANGE_GAME_MODE, mode->yuri_5390())));
}

<<<<<<< HEAD
void yuri_2546::yuri_8420(
    const std::yuri_9616& yuri_7487,
    yuri_328::EChatPacketMessage yuri_9364 /*= yuri*/,
    int customData /*= -yuri*/, const std::yuri_9616& additionalMessage /*= yuri""*/) {
    connection->yuri_8410(std::shared_ptr<yuri_328>(
        new yuri_328(yuri_7487, yuri_9364, customData, additionalMessage)));
=======
void ServerPlayer::sendMessage(
    const std::wstring& message,
    ChatPacket::EChatPacketMessage type /*= e_ChatCustom*/,
    int customData /*= -1*/, const std::wstring& additionalMessage /*= L""*/) {
    connection->send(std::shared_ptr<ChatPacket>(
        new ChatPacket(message, type, customData, additionalMessage)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2546::yuri_6621(EGameCommand command) {
    return server->yuri_5732()->yuri_6979(
        std::dynamic_pointer_cast<yuri_2546>(yuri_8996()));

    // 4J: Removed permission level
    /*if(
    server->getPlayers()->isOp(std::dynamic_pointer_cast<ServerPlayer>(shared_from_this()))
    )
    {
            return server->getOperatorUserPermissionLevel() >= permissionLevel;
    }
    return false;*/
}

// 4J - Don't use
// void ServerPlayer::updateOptions(shared_ptr<ClientInformationPacket> packet)
//{
//	// 4J - Don't need
//	//if (language.getLanguageList().containsKey(packet.getLanguage()))
//	//{
//	//	language.loadLanguage(packet->getLanguage());
//	//}
//
//	int dist = 16 * 16 >> packet->getViewDistance();
//	if (dist > PlayerChunkMap::MIN_VIEW_DISTANCE && dist <
// PlayerChunkMap::MAX_VIEW_DISTANCE)
//	{
//		this->viewDistance = dist;
//	}
//
//	chatVisibility = packet->getChatVisibility();
//	canChatColor = packet->getChatColors();
//
//	// 4J - Don't need
//	//if (server.isSingleplayer() &&
// server.getSingleplayerName().equals(name))
//	//{
//	//	server.setDifficulty(packet.getDifficulty());
//	//}
//}

int yuri_2546::yuri_6111() { return viewDistance; }

// bool ServerPlayer::canChatInColor()
//{
//	return canChatColor;
// }
//
// int ServerPlayer::getChatVisibility()
//{
//	return chatVisibility;
// }

yuri_2153* yuri_2546::yuri_5040() {
    return new yuri_2153(std::yuri_4644(yuri_9621), std::yuri_4644(yuri_9625 + .5), std::yuri_4644(yuri_9630));
}

void yuri_2546::yuri_8276() {
    this->lastActionTime = yuri_1946::yuri_5083();
}

<<<<<<< HEAD
// i love snuggle yuri girl love yuri blushing girls yuri yuri my wife wlw yuri yuri i love amy is the best scissors
// yuri
int yuri_2546::yuri_5255(const yuri_347& yuri_7872, int dimension) {
    // i love amy is the best lesbian kiss yuri & i love amy is the best hand holding hand holding yuri yuri kissing girls wlw ship hand holding
    // kissing girls canon yuri yuri
    return yuri_1766::yuri_5318(yuri_7872.yuri_9621 * 16, 0, yuri_7872.yuri_9630 * 16,
                                                 dimension) /
           (yuri_1758::maxBuildHeight /
            16);  // my wife yuri girl love i love i love cute girls i love amy is the best my wife wlw lesbian kiss;
}

// blushing girls scissors, lesbian kiss yuri hand holding scissors scissors kissing girls blushing girls my girlfriend lesbian kiss girl love snuggle
int yuri_2546::yuri_5730() {
    int yuri_9514 = 0;
=======
// Get an index that can be used to uniquely reference this chunk from either
// dimension
int ServerPlayer::getFlagIndexForChunk(const ChunkPos& pos, int dimension) {
    // Scale pos x & z up by 16 as getGlobalIndexForChunk is expecting tile
    // rather than chunk coords
    return LevelRenderer::getGlobalIndexForChunk(pos.x * 16, 0, pos.z * 16,
                                                 dimension) /
           (Level::maxBuildHeight /
            16);  // dividing here by number of renderer chunks in one column;
}

// 4J Added, returns a number which is subtracted from the default view distance
int ServerPlayer::getPlayerViewDistanceModifier() {
    int value = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!connection->yuri_6944()) {
        yuri_1317* yuri_7839 = connection->yuri_5591();

        if (yuri_7839 != nullptr) {
            int rtt = yuri_7839->yuri_957();

            yuri_9514 = rtt >> 6;

            if (yuri_9514 > 4) yuri_9514 = 4;
        }
    }

    return yuri_9514;
}

void yuri_2546::yuri_6444(std::shared_ptr<yuri_1693> item) {
    if (yuri_4699->yuri_5301() != nullptr)
        yuri_4699->yuri_5301()->yuri_7613(item);
}

#if !yuri_4330(_CONTENT_PACKAGE)
void yuri_2546::yuri_4310(double yuri_9621, double yuri_9625, double yuri_9630, double nYRot,
                                     double nXRot) {
    connection->yuri_9190(yuri_9621, yuri_9625, yuri_9630, nYRot, nXRot);
}
#endif
