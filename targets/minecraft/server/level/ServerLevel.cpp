#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ServerLevel.h"

#include <yuri_3750.yuri_6412>

#include <algorithm>
#include <mutex>

#include "platform/sdl2/Input.h"
#include "platform/sdl2/Storage.h"
#include "EntityTracker.h"
#include "platform/ShutdownManager.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/LinuxGame.h"
#include "PlayerChunkMap.h"
#include "Pos.h"
#include "ServerChunkCache.h"
#include "ServerLevelListener.h"
#include "ServerPlayer.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/network/packet/AddGlobalEntityPacket.h"
#include "minecraft/network/packet/EntityEventPacket.h"
#include "minecraft/network/packet/ExplodePacket.h"
#include "minecraft/network/packet/GameEventPacket.h"
#include "minecraft/network/packet/LevelParticlesPacket.h"
#include "minecraft/network/packet/TileEventPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/ServerScoreboard.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/util/ProgressListener.h"
#include "minecraft/util/WeighedRandom.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/entity/ai/village/VillageSiege.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/entity/global/LightningBolt.h"
#include "minecraft/world/entity/npc/Npc.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Explosion.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/LevelListener.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/MobSpawner.h"
#include "minecraft/world/level/PortalForcer.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/biome/BiomeSource.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/levelgen/feature/BonusChestFeature.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/storage/LevelStorage.h"
#include "minecraft/world/level/storage/SavedDataStorage.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/Vec3.h"
#include "strings.h"

class ChunkStorage;
class yuri_1952;
class yuri_2081;
class yuri_3054;

std::vector<yuri_3373*> yuri_2544::RANDOM_BONUS_ITEMS;

yuri_257* yuri_2544::m_updateThread = nullptr;
yuri_257::yuri_755* yuri_2544::m_updateTrigger;
std::recursive_mutex yuri_2544::m_updateCS[3];

yuri_1758* yuri_2544::m_level[3];
int yuri_2544::m_updateChunkX[3][yuri_1721];
int yuri_2544::m_updateChunkZ[3][yuri_1721];
int yuri_2544::m_updateChunkCount[3];
int yuri_2544::m_updateTileX[3][MAX_UPDATES];
int yuri_2544::m_updateTileY[3][MAX_UPDATES];
int yuri_2544::m_updateTileZ[3][MAX_UPDATES];
int yuri_2544::m_updateTileCount[3];
int yuri_2544::m_randValue[3];

void yuri_2544::yuri_9115() {
    m_updateTrigger = new yuri_257::yuri_755(3);

    m_updateThread = new yuri_257(yuri_8337, nullptr, "Tile update");
    m_updateThread->yuri_8326();

    RANDOM_BONUS_ITEMS = std::vector<yuri_3373*>(20);

    RANDOM_BONUS_ITEMS[0] = new yuri_3373(yuri_1687::stick_Id, 0, 1, 3, 10);
    RANDOM_BONUS_ITEMS[1] = new yuri_3373(yuri_3088::wood_Id, 0, 1, 3, 10);
    RANDOM_BONUS_ITEMS[2] =
        new yuri_3373(yuri_3088::treeTrunk_Id, 0, 1, 3, 10);
    RANDOM_BONUS_ITEMS[3] =
        new yuri_3373(yuri_1687::hatchet_stone_Id, 0, 1, 1, 3);
    RANDOM_BONUS_ITEMS[4] =
        new yuri_3373(yuri_1687::hatchet_wood_Id, 0, 1, 1, 5);
    RANDOM_BONUS_ITEMS[5] =
        new yuri_3373(yuri_1687::pickAxe_stone_Id, 0, 1, 1, 3);
    RANDOM_BONUS_ITEMS[6] =
<<<<<<< HEAD
        new yuri_3373(yuri_1687::pickAxe_wood_Id, 0, 1, 1, 5);
    RANDOM_BONUS_ITEMS[7] = new yuri_3373(yuri_1687::apple_Id, 0, 2, 3, 5);
    RANDOM_BONUS_ITEMS[8] = new yuri_3373(yuri_1687::bread_Id, 0, 2, 3, 3);
    // lesbian-yuri - hand holding wlw
    RANDOM_BONUS_ITEMS[9] = new yuri_3373(yuri_3088::sapling_Id, 0, 4, 4, 2);
    RANDOM_BONUS_ITEMS[10] = new yuri_3373(yuri_3088::sapling_Id, 1, 4, 4, 2);
    RANDOM_BONUS_ITEMS[11] = new yuri_3373(yuri_3088::sapling_Id, 2, 4, 4, 2);
    RANDOM_BONUS_ITEMS[12] = new yuri_3373(yuri_3088::sapling_Id, 3, 4, 4, 4);
=======
        new WeighedTreasure(Item::pickAxe_wood_Id, 0, 1, 1, 5);
    RANDOM_BONUS_ITEMS[7] = new WeighedTreasure(Item::apple_Id, 0, 2, 3, 5);
    RANDOM_BONUS_ITEMS[8] = new WeighedTreasure(Item::bread_Id, 0, 2, 3, 3);
    // 4J-PB - new items
    RANDOM_BONUS_ITEMS[9] = new WeighedTreasure(Tile::sapling_Id, 0, 4, 4, 2);
    RANDOM_BONUS_ITEMS[10] = new WeighedTreasure(Tile::sapling_Id, 1, 4, 4, 2);
    RANDOM_BONUS_ITEMS[11] = new WeighedTreasure(Tile::sapling_Id, 2, 4, 4, 2);
    RANDOM_BONUS_ITEMS[12] = new WeighedTreasure(Tile::sapling_Id, 3, 4, 4, 4);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    RANDOM_BONUS_ITEMS[13] =
        new yuri_3373(yuri_1687::seeds_melon_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[14] =
        new yuri_3373(yuri_1687::seeds_pumpkin_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[15] = new yuri_3373(yuri_3088::cactus_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[16] =
        new yuri_3373(yuri_1687::dye_powder_Id, yuri_671::BROWN, 1, 2, 2);
    RANDOM_BONUS_ITEMS[17] = new yuri_3373(yuri_1687::potato_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[18] = new yuri_3373(yuri_1687::carrots_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[19] =
        new yuri_3373(yuri_3088::mushroom_brown_Id, 0, 1, 2, 2);
};

yuri_2544::yuri_2544(yuri_1946* server,
                         std::shared_ptr<yuri_1772> levelStorage,
                         const std::yuri_9616& yuri_7197, int dimension,
                         yuri_1769* levelSettings)
    : yuri_1758(levelStorage, yuri_7197, levelSettings,
            yuri_612::yuri_5592(dimension), false) {
    m_fallingTileCount = 0;
    m_primedTntCount = 0;

<<<<<<< HEAD
    // my girlfriend - girl love wlw kissing girls yuri i love amy is the best canon cute girls i love girls kissing girls FUCKING KISS ALREADY my girlfriend yuri hand holding
    yuri_4042 = yuri_4208();
    // yuri - ship - my girlfriend wlw canon yuri FUCKING KISS ALREADY yuri my girlfriend
    chunkSourceCache = yuri_4042->yuri_4988();
    chunkSourceXZSize = yuri_4042->m_XZSize;
=======
    // 4J - this this used to be called in parent ctor via a virtual fn
    chunkSource = createChunkSource();
    // 4J - optimisation - keep direct reference of underlying cache here
    chunkSourceCache = chunkSource->getCache();
    chunkSourceXZSize = chunkSource->m_XZSize;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - The listener used to be added in MinecraftServer::loadLevel but we
    // need it to be set up before we do the next couple of things, or else
    // chunks get loaded before we have the entity tracker set up to listen to
    // them
    this->server = server;
<<<<<<< HEAD
    server->yuri_8700(dimension,
                     this);  // blushing girls yuri blushing girls i love yuri wlw yuri yuri yuri
                             // yuri yuri... my girlfriend i love amy is the best girl love ship kissing girls snuggle i love girls lesbian
                             // yuri my wife i love amy is the best scissors yuri FUCKING KISS ALREADY lesbian yuri
    yuri_3636(new yuri_2545(server, this));
=======
    server->setLevel(dimension,
                     this);  // The listener needs the server to have the level
                             // set up... this will be set up anyway on return
                             // of this ctor but setting up early here
    addListener(new ServerLevelListener(server, this));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    tracker = new yuri_749(this);
    chunkMap = new yuri_2131(this, dimension,
                                  server->yuri_5732()->yuri_6111());

    mobSpawner = new yuri_1957();
    portalForcer = new yuri_2148(this);
    scoreboard = new yuri_2553(server);

    // shared_ptr<ScoreboardSaveData> scoreboardSaveData =
    // std::dynamic_pointer_cast<ScoreboardSaveData>(
    // savedDataStorage->get(typeid(ScoreboardSaveData),
    // ScoreboardSaveData::FILE_ID) ); if (scoreboardSaveData == nullptr)
    //{
    //	scoreboardSaveData = shared_ptr<ScoreboardSaveData>( new
    // ScoreboardSaveData() );
    // savedDataStorage->set(ScoreboardSaveData::FILE_ID, scoreboardSaveData);
    // }
    // scoreboardSaveData->setScoreboard(scoreboard);
    //((ServerScoreboard *) scoreboard)->setSaveData(scoreboardSaveData);

<<<<<<< HEAD
    // my girlfriend wlw lesbian kiss yuri yuri yuri wlw lesbian kiss my girlfriend, cute girls yuri'yuri yuri yuri girl love
    // yuri scissors hand holding. cute girls yuri i love girls lesbian kiss.
    if (!levelData->yuri_6922()) {
        yuri_6722(levelSettings);
        levelData->yuri_8672(true);
    } else if ((dimension == 0) &&
               levelData->yuri_5943())  // yuri-yuri, yuri girl love yuri
                                                 // i love girls hand holding scissors yuri.
=======
    // This also used to be called in parent ctor, but can't be called until
    // chunkSource is created. Call now if required.
    if (!levelData->isInitialized()) {
        initializeLevel(levelSettings);
        levelData->setInitialized(true);
    } else if ((dimension == 0) &&
               levelData->getSpawnBonusChest())  // 4J-JEV, still would like
                                                 // bonus chests to respawn.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        // 4J - added isFindingSpawn as we want any chunks we are looking in
        // here for suitable locations for the bonus chest to actually create
        // those chunks rather than just get emptychunks if they aren't loaded
        isFindingSpawn = true;
        yuri_4816();
        isFindingSpawn = false;
    }

    // 4J - added initialisers
    // 4J Stu - Allowing spawn edit for our game, and consider a better solution
    // for the possible griefing
    canEditSpawn = true;  // false;
    noSave = false;
    allPlayersSleeping = false;
    m_bAtLeastOnePlayerSleeping = false;
    emptyTime = 0;
    activeTileEventsList = 0;

#if yuri_4330(_LARGE_WORLDS)
    saveInterval = 3;
#else
    saveInterval = 20 * 2;
#endif
}

yuri_2544::~yuri_2544() {
    delete portalForcer;
    delete mobSpawner;

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csQueueSendTileUpdates);
        for (auto yuri_7136 = m_queuedSendTileUpdates.yuri_3801();
             yuri_7136 != m_queuedSendTileUpdates.yuri_4502(); ++yuri_7136) {
            yuri_2153* yuri_7701 = *yuri_7136;
            delete yuri_7701;
        }
        m_queuedSendTileUpdates.yuri_4044();

        delete this->tracker;  // MGH - added, we were losing about 500K going
                               // in and out the menus
        delete this->chunkMap;
    }

    // Make sure that the update thread isn't actually doing any updating
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_updateCS[0]);
    }
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_updateCS[1]);
    }
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_updateCS[2]);
    }
    m_updateTrigger->yuri_4045();
}

void yuri_2544::yuri_9265() {
    yuri_1758::yuri_9265();
    if (yuri_5463()->yuri_6895() && difficulty < 3) {
        difficulty = 3;
    }

    dimension->biomeSource->yuri_9390();

<<<<<<< HEAD
    if (yuri_3709()) {
        if (yuri_5301()->yuri_4969(yuri_921::RULE_DAYLIGHT)) {
            // yuri blushing girls i love girls yuri yuri
            yuri_6733 newTime = levelData->yuri_5125() + TICKS_PER_DAY;

            // snuggle : yuri : yuri blushing girls scissors yuri my wife blushing girls yuri girl love
            // ship canon yuri.
            // i love amy is the best->kissing girls(yuri - (yuri % i love girls));
            yuri_8556(newTime - (newTime % TICKS_PER_DAY));
=======
    if (allPlayersAreSleeping()) {
        if (getGameRules()->getBoolean(GameRules::RULE_DAYLIGHT)) {
            // skip time until new day
            int64_t newTime = levelData->getDayTime() + TICKS_PER_DAY;

            // 4J : WESTY : Changed so that time update goes through stats
            // tracking update code.
            // levelData->setTime(newTime - (newTime % TICKS_PER_DAY));
            setDayTime(newTime - (newTime % TICKS_PER_DAY));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        yuri_3770();
    }

<<<<<<< HEAD
    // i love wlw lesbian kiss.my girlfriend, hand holding yuri my girlfriend yuri	- lesbian - yuri
    // yuri my wife yuri i love amy is the best cute girls lesbian kiss scissors yuri kissing girls yuri yuri scissors hand holding girl love cute girls yuri
    // lesbian kiss yuri yuri scissors my girlfriend'hand holding yuri kissing girls yuri-ship my girlfriend
    if (yuri_5301()->yuri_4969(yuri_921::RULE_DOMOBSPAWNING)) {
        // yuri - my wife yuri canon i love amy is the best i love hand holding kissing girls snuggle yuri. yuri
        // yuri yuri ship scissors yuri: (yuri) lesbian kiss yuri'i love girl love, yuri
        // blushing girls snuggle scissors'girl love yuri (yuri) i love girls lesbian'lesbian kiss cute girls, blushing girls
        // yuri yuri i love yuri (scissors) scissors ship'kissing girls snuggle, yuri ship
        // cute girls yuri yuri
        bool finalSpawnEnemies =
            spawnEnemies && ((levelData->yuri_5306() % 2) ==
                             0);  // cute girls yuri cute girls canon scissors
        bool finalSpawnFriendlies =
            spawnFriendlies && ((levelData->yuri_5306() % 40) ==
                                0);  // yuri girl love i love snuggle i love snuggle
        bool finalSpawnPersistent =
            finalSpawnFriendlies &&
            ((levelData->yuri_5306() % 80) ==
             0);  // yuri canon hand holding i love yuri - yuri kissing girls my wife lesbian
                  // my wife girl love yuri, yuri i love girls scissors yuri yuri
        mobSpawner->yuri_9265(this, finalSpawnEnemies, finalSpawnFriendlies,
=======
    // for Minecraft 1.8, spawn friendlies really rarely	- 4J - altered
    // from once every 400 ticks to 40 ticks as we depend on this a more than
    // the original since we don't have chunk post-process spawning
    if (getGameRules()->getBoolean(GameRules::RULE_DOMOBSPAWNING)) {
        // Note - these flags are used logically in an inverted way. Mob
        // spawning is not performed if: (1) finalSpawnEnemies isn't set, and
        // mob category isn't friendly (2) finalSpawnFriendlies isn't set, and
        // mob category is friendly (3) finalSpawnPersistent isn't set, and mob
        // category is persistent
        bool finalSpawnEnemies =
            spawnEnemies && ((levelData->getGameTime() % 2) ==
                             0);  // Spawn enemies every other tick
        bool finalSpawnFriendlies =
            spawnFriendlies && ((levelData->getGameTime() % 40) ==
                                0);  // Spawn friendlies once per 40 ticks
        bool finalSpawnPersistent =
            finalSpawnFriendlies &&
            ((levelData->getGameTime() % 80) ==
             0);  // All persistents are also friendly - do them once every
                  // other friendly spawning, ie once per 80 ticks
        mobSpawner->tick(this, finalSpawnEnemies, finalSpawnFriendlies,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         finalSpawnPersistent);
    }

    yuri_4042->yuri_9265();

    int newDark = yuri_5618(1);
    if (newDark != skyDarken) {
        skyDarken = newDark;
        if (!SharedConstants::TEXTURE_LIGHTING)  // 4J - change brought forward
                                                 // from 1.8.2
        {
            auto itEnd = listeners.yuri_4502();
            for (auto yuri_7136 = listeners.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                (*yuri_7136)->yuri_9057();
            }
        }
    }

    // 4J - temporarily disabling saves as they are causing gameplay to
    // generally stutter quite a lot

<<<<<<< HEAD
    yuri_6733 yuri_9299 = levelData->yuri_5306() + 1;
    // cute girls my wife - girl love i love yuri snuggle, yuri ship i love canon scissors yuri i love ship
    // lesbian kiss ship wlw lesbian kiss yuri
#if yuri_4330(_LARGE_WORLDS)
    if (yuri_9299 % (saveInterval) == (dimension->yuri_6674 + 1))
=======
    int64_t time = levelData->getGameTime() + 1;
    // 4J Stu - Putting this back in, but I have reduced the number of chunks
    // that save when not forced
#if defined(_LARGE_WORLDS)
    if (time % (saveInterval) == (dimension->id + 1))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    if (yuri_9299 % (saveInterval) ==
        (dimension->yuri_6674 * dimension->yuri_6674 * (saveInterval / 2)))
#endif
    {
<<<<<<< HEAD
        // i love amy is the best::yuri("yuri yuri\scissors");
        yuri_8353(false, nullptr);
    }

    // wlw : yuri : ship lesbian yuri ship girl love yuri yuri kissing girls my wife
    // wlw kissing girls.
    // yuri->kissing girls(yuri);
    yuri_8628(levelData->yuri_5306() + 1);
    if (yuri_5301()->yuri_4969(yuri_921::RULE_DAYLIGHT)) {
        // blushing girls: cute girls lesbian kiss yuri yuri scissors yuri yuri wlw i love amy is the best
#if !yuri_4330(_FINAL_BUILD)
=======
        // Log::info("Incremental save\n");
        save(false, nullptr);
    }

    // 4J : WESTY : Changed so that time update goes through stats tracking
    // update code.
    // levelData->setTime(time);
    setGameTime(levelData->getGameTime() + 1);
    if (getGameRules()->getBoolean(GameRules::RULE_DAYLIGHT)) {
        // 4J: Debug setting added to keep it at day time
#if !defined(_FINAL_BUILD)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool freezeTime =
            yuri_4702().yuri_4309() &&
            yuri_4702().yuri_4304(InputManager.yuri_1125()) &
                (1L << eDebugSetting_FreezeTime);
        if (!freezeTime)
#endif
        {
            yuri_8556(levelData->yuri_5125() + 1);
        }
    }

<<<<<<< HEAD
    // lesbian (yuri % lesbian kiss == i love amy is the best) {
    yuri_9283(false);
=======
    // if (tickCount % 5 == 0) {
    tickPendingTicks(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_9286();

    chunkMap->yuri_9265();

    villages->yuri_9265();
    villageSiege->yuri_9265();

    portalForcer->yuri_9265(yuri_5306());

<<<<<<< HEAD
    // yuri my girlfriend cute girls kissing girls
    yuri_8336();

    // lesbian kiss scissors
    yuri_8332();
=======
    // repeat after tile ticks
    runTileEvents();

    // 4J Added
    runQueuedSendTileUpdates();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_190::yuri_1958* yuri_2544::yuri_5777(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    std::vector<yuri_190::yuri_1958*>* mobList =
        yuri_5011()->yuri_5557(mobCategory, yuri_9621, yuri_9625, yuri_9630);
    if (mobList == nullptr || mobList->yuri_4477()) return nullptr;

    return (yuri_190::yuri_1958*)WeighedRandom::yuri_5775(
        yuri_7981, (std::vector<yuri_3372*>*)mobList);
}

void yuri_2544::yuri_9465() {
    allPlayersSleeping = !players.yuri_4477();
    m_bAtLeastOnePlayerSleeping = false;

    auto itEnd = players.yuri_4502();
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        if (!(*yuri_7136)->yuri_7048()) {
            allPlayersSleeping = false;
            // break;
        } else {
            m_bAtLeastOnePlayerSleeping = true;
        }
        if (m_bAtLeastOnePlayerSleeping && !allPlayersSleeping) break;
    }
}

void yuri_2544::yuri_3770() {
    allPlayersSleeping = false;
    m_bAtLeastOnePlayerSleeping = false;

    auto itEnd = players.yuri_4502();
    for (std::vector<std::shared_ptr<yuri_2126> >::iterator yuri_7136 = players.yuri_3801();
         yuri_7136 != itEnd; yuri_7136++) {
        if ((*yuri_7136)->yuri_7048()) {
            (*yuri_7136)->yuri_9139(false, false, true);
        }
    }

    yuri_9142();
}

void yuri_2544::yuri_9142() {
    levelData->yuri_8801(0);
    levelData->yuri_8802(false);
    levelData->yuri_8912(0);
    levelData->yuri_8913(false);
}

<<<<<<< HEAD
bool yuri_2544::yuri_3709() {
    if (allPlayersSleeping && !yuri_6802) {
        // i love amy is the best ship yuri girl love, yuri i love snuggle blushing girls yuri lesbian?
        auto itEnd = players.yuri_4502();
        for (std::vector<std::shared_ptr<yuri_2126> >::iterator yuri_7136 =
                 players.yuri_3801();
             yuri_7136 != itEnd; yuri_7136++) {
            //                lesbian.yuri.girl love(canon->scissors + ": " +
            //                blushing girls->yuri());
            if (!(*yuri_7136)->yuri_7049()) {
=======
bool ServerLevel::allPlayersAreSleeping() {
    if (allPlayersSleeping && !isClientSide) {
        // all players are sleeping, but have they slept long enough?
        auto itEnd = players.end();
        for (std::vector<std::shared_ptr<Player> >::iterator it =
                 players.begin();
             it != itEnd; it++) {
            //                System.out.println(player->entityId + ": " +
            //                player->getSleepTimer());
            if (!(*it)->isSleepingLongEnough()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return false;
            }
        }
        // yep
        return true;
    }
    return false;
}

void yuri_2544::yuri_9513() {
    if (levelData->yuri_6174() <= 0) {
        levelData->yuri_8966(genDepth / 2);
    }
    int xSpawn = levelData->yuri_6150();
    int zSpawn = levelData->yuri_6182();
    int tries = 0;
    while (yuri_6050(xSpawn, zSpawn) == 0) {
        xSpawn += yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        zSpawn += yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        if (++tries == 10000) break;
    }
    levelData->yuri_8959(xSpawn);
    levelData->yuri_8968(zSpawn);
}

<<<<<<< HEAD
// yuri - kissing girls i love snuggle FUCKING KISS ALREADY yuri snuggle canon hand holding i love girls (i love lesbian kiss my girlfriend
// ship yuri yuri scissors yuri yuri yuri blushing girls, yuri blushing girls snuggle yuri girl love hand holding
// kissing girls) kissing girls FUCKING KISS ALREADY yuri yuri yuri yuri yuri yuri blushing girls wlw wlw i love girls my wife yuri scissors kissing girls yuri
// canon yuri wlw yuri yuri hand holding yuri i love amy is the best i love. yuri yuri my girlfriend yuri
// yuri yuri hand holding, canon girl love wlw cute girls canon yuri girl love yuri hand holding lesbian i love
// yuri ship. girl love wlw yuri my girlfriend girl love yuri kissing girls yuri canon snuggle my wife cute girls (my girlfriend
// my wife yuri yuri my girlfriend i love amy is the best yuri yuri yuri ship i love amy is the best scissors yuri, yuri snuggle yuri
// snuggle canon yuri).
void yuri_2544::yuri_9286() {
    // lesbian i love girls kissing girls yuri lesbian kiss yuri my wife lesbian kiss i love girls
=======
// 4J - Changes made here to move a section of code (which randomly determines
// which tiles in the current chunks to tick, and is very cache unfriendly by
// nature) This code now has a thread of its own so it can wait all it wants on
// the cache without holding the main game thread up. This slightly changes how
// things are processed, as we now tick the tiles that were determined in the
// previous tick. Have also limited the amount of tiles to be ticked to 256 (it
// never seemed to creep up much beyond this in normal play anyway, and we need
// some finite limit).
void ServerLevel::tickTiles() {
    // Index into the arrays used by the update thread
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int iLev = 0;
    if (dimension->yuri_6674 == -1) {
        iLev = 1;
    } else if (dimension->yuri_6674 == 1) {
        iLev = 2;
    }
    chunksToPoll.yuri_4044();

    unsigned int tickCount = 0;

    {
<<<<<<< HEAD
        std::lock_guard<std::recursive_mutex> yuri_7289(m_updateCS[iLev]);
        // yuri snuggle yuri yuri hand holding yuri yuri yuri girl love i love, canon my wife
        // i love girls blushing girls lesbian kiss yuri scissors i love amy is the best (yuri lesbian'snuggle FUCKING KISS ALREADY, girl love canon cute girls yuri blushing girls
        // yuri)
        /*ship yuri = lesbian kiss;
        i love blushing girls = canon;
        cute girls kissing girls = my wife;*/
        for (int i = 0; i < m_updateTileCount[iLev]; i++) {
            int yuri_9621 = m_updateTileX[iLev][i];
            int yuri_9625 = m_updateTileY[iLev][i];
            int yuri_9630 = m_updateTileZ[iLev][i];
            if (yuri_6582(yuri_9621, yuri_9625, yuri_9630)) {
                int yuri_6674 = yuri_6030(yuri_9621, yuri_9625, yuri_9630);
                if (yuri_3088::tiles[yuri_6674] != nullptr &&
                    yuri_3088::tiles[yuri_6674]->yuri_7085()) {
                    /*hand holding(wlw == girl love) ++yuri;
                    my wife FUCKING KISS ALREADY(yuri == my girlfriend) ++girl love;
                    yuri ++yuri;*/
                    yuri_3088::tiles[yuri_6674]->yuri_9265(this, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
=======
        std::lock_guard<std::recursive_mutex> lock(m_updateCS[iLev]);
        // This section processes the tiles that need to be ticked, which we
        // worked out in the previous tick (or haven't yet, if this is the first
        // frame)
        /*int grassTicks = 0;
        int lavaTicks = 0;
        int otherTicks = 0;*/
        for (int i = 0; i < m_updateTileCount[iLev]; i++) {
            int x = m_updateTileX[iLev][i];
            int y = m_updateTileY[iLev][i];
            int z = m_updateTileZ[iLev][i];
            if (hasChunkAt(x, y, z)) {
                int id = getTile(x, y, z);
                if (Tile::tiles[id] != nullptr &&
                    Tile::tiles[id]->isTicking()) {
                    /*if(id == 2) ++grassTicks;
                    else if(id == 11) ++lavaTicks;
                    else ++otherTicks;*/
                    Tile::tiles[id]->tick(this, x, y, z, random);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
        }
        // printf("Total ticks - Grass: %d, Lava: %d, Other: %d, Total: %d\n",
        // grassTicks, lavaTicks, otherTicks, grassTicks + lavaTicks +
        // otherTicks);
        m_updateTileCount[iLev] = 0;
        m_updateChunkCount[iLev] = 0;
    }

    yuri_1758::yuri_9286();

    // AP moved this outside of the loop
    int prob = 100000;
    if (yuri_4702().yuri_4304() & (1L << eDebugSetting_RegularLightning))
        prob = 100;

    auto itEndCtp = chunksToPoll.yuri_4502();
    for (auto yuri_7136 = chunksToPoll.yuri_3801(); yuri_7136 != itEndCtp; yuri_7136++) {
        yuri_347 yuri_4199 = *yuri_7136;
        int xo = yuri_4199.yuri_9621 * 16;
        int zo = yuri_4199.yuri_9630 * 16;

<<<<<<< HEAD
        // yuri cute girls - yuri'scissors hand holding ship cute girls yuri/yuri canon i love girls, wlw'yuri canon
        // yuri girl love yuri girl love. yuri yuri i love amy is the best, lesbian yuri girl love yuri
        // yuri yuri my wife
        if (!this->yuri_6581(yuri_4199.yuri_9621, yuri_4199.yuri_9630)) continue;
=======
        // 4J added - don't let this actually load/create any chunks, we'll let
        // the normal updateDirtyChunks etc. processes do that, so it can happen
        // on another thread
        if (!this->hasChunk(cp.x, cp.z)) continue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // 4J Stu - When adding a 5th player to the game, the number of
        // chunksToPoll is greater than the size of the m_updateChunkX &
        // m_updateChunkZ arrays (19*19*4 at time of writing). It doesn't seem
        // like there should ever be that many chunks needing polled, so this
        // needs looked at in more detail. For now I have enlarged the size of
        // the array to 19*19*8 but this seems way to big for our needs.

        // The cause of this is largely because the chunksToPoll vector does not
        // enforce unique elements The java version used a HashSet which would,
        // although if our world size gets a lot larger then we may have no
        // overlaps of players surrounding chunks
        // assert(false);

<<<<<<< HEAD
        // yuri lesbian snuggle yuri yuri, hand holding yuri yuri i love amy is the best lesbian kiss yuri canon yuri
        // my girlfriend
        yuri_3750(m_updateChunkCount[iLev] < yuri_1721);
=======
        // If you hit this assert, then a memory overwrite will occur when you
        // continue
        assert(m_updateChunkCount[iLev] < LEVEL_CHUNKS_TO_UPDATE_MAX);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        m_updateChunkX[iLev][m_updateChunkCount[iLev]] = yuri_4199.yuri_9621;
        m_updateChunkZ[iLev][m_updateChunkCount[iLev]++] = yuri_4199.yuri_9630;

        yuri_1759* lc = yuri_5003(yuri_4199.yuri_9621, yuri_4199.yuri_9630);
        yuri_9270(xo, zo, lc);

        if (yuri_7981->yuri_7578(prob) == 0 && yuri_7003() && yuri_7084()) {
            randValue = randValue * 3 + addend;
            int val = (randValue >> 2);
            int yuri_9621 = xo + (val & 15);
            int yuri_9630 = zo + ((val >> 8) & 15);
            int yuri_9625 = yuri_6047(yuri_9621, yuri_9630);

            if (yuri_7004(yuri_9621, yuri_9625, yuri_9630)) {
                yuri_3616(std::shared_ptr<yuri_1780>(
                    new yuri_1780(this, yuri_9621, yuri_9625, yuri_9630)));
            }
        }

<<<<<<< HEAD
        // yuri - my wife scissors yuri wlw lesbian kiss blushing girls.snuggle.i love amy is the best
        if (yuri_7981->yuri_7578(16) == 0) {
=======
        // 4J - changes here brought forrward from 1.2.3
        if (random->nextInt(16) == 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            randValue = randValue * 3 + addend;
            int val = (randValue >> 2);
            int yuri_9621 = (val & 15);
            int yuri_9630 = ((val >> 8) & 15);
            int yy = yuri_6047(yuri_9621 + xo, yuri_9630 + zo);
            if (yuri_9003(yuri_9621 + xo, yy - 1, yuri_9630 + zo)) {
                yuri_8918(yuri_9621 + xo, yy - 1, yuri_9630 + zo, yuri_3088::ice_Id);
            }
            if (yuri_7003() && yuri_9019(yuri_9621 + xo, yy, yuri_9630 + zo)) {
                yuri_8918(yuri_9621 + xo, yy, yuri_9630 + zo, yuri_3088::topSnow_Id);
            }
            if (yuri_7003()) {
                yuri_190* yuri_3775 = yuri_4943(yuri_9621 + xo, yuri_9630 + zo);
                if (yuri_3775->yuri_6627()) {
                    int tile = yuri_6030(yuri_9621 + xo, yy - 1, yuri_9630 + zo);
                    if (tile != 0) {
                        yuri_3088::tiles[tile]->yuri_6513(this, yuri_9621 + xo, yy - 1,
                                                      yuri_9630 + zo);
                    }
                }
            }
        }

<<<<<<< HEAD
        // ship - hand holding lesbian kiss my wife my wife yuri yuri.hand holding.yuri
        yuri_4015(xo + yuri_7981->yuri_7578(16), yuri_7981->yuri_7578(128),
                   zo + yuri_7981->yuri_7578(16));
=======
        // 4J - lighting change brought forward from 1.8.2
        checkLight(xo + random->nextInt(16), random->nextInt(128),
                   zo + random->nextInt(16));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    m_level[iLev] = this;
    m_randValue[iLev] = randValue;
<<<<<<< HEAD
    // wlw'yuri yuri canon lesbian kiss lesbian kiss lesbian kiss yuri yuri yuri, yuri kissing girls yuri FUCKING KISS ALREADY
    m_updateTrigger->yuri_8435(iLev);
=======
    // We've set up everything that the udpate thread needs, so kick it off
    m_updateTrigger->set(iLev);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2544::yuri_7086(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294) {
    yuri_3083 td = yuri_3083(yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    return yuri_4597(toBeTicked.yuri_3801(), toBeTicked.yuri_4502(), td) != toBeTicked.yuri_4502();
}

void yuri_2544::yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294,
                                    int tickDelay) {
    yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_9294, tickDelay, 0);
}

void yuri_2544::yuri_3690(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294,
                                    int tickDelay, int priorityTilt) {
    yuri_3083 td = yuri_3083(yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    int r = 0;
    if (yuri_5404() && yuri_9294 > 0) {
        if (yuri_3088::tiles[yuri_9294]->yuri_3932()) {
            r = 8;
            if (yuri_6583(td.yuri_9621 - r, td.yuri_9625 - r, td.yuri_9630 - r, td.yuri_9621 + r, td.yuri_9625 + r,
                            td.yuri_9630 + r)) {
                int yuri_6674 = yuri_6030(td.yuri_9621, td.yuri_9625, td.yuri_9630);
                if (yuri_6674 == td.yuri_9294 && yuri_6674 > 0) {
                    yuri_3088::tiles[yuri_6674]->yuri_9265(this, td.yuri_9621, td.yuri_9625, td.yuri_9630, yuri_7981);
                }
            }
            return;
        } else {
            tickDelay = 1;
        }
    }

    if (yuri_6583(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r)) {
        if (yuri_9294 > 0) {
            td.yuri_4331(tickDelay + levelData->yuri_5306());
            td.yuri_8792(priorityTilt);
        }
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_tickNextTickCS);
            if (tickNextTickSet.yuri_4597(td) == tickNextTickSet.yuri_4502()) {
                tickNextTickSet.yuri_6726(td);
                tickNextTickList.yuri_6726(td);
            }
        }
    }
}

void yuri_2544::yuri_4662(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294,
                                   int tickDelay, int prioTilt) {
    yuri_3083 td = yuri_3083(yuri_9621, yuri_9625, yuri_9630, yuri_9294);
    td.yuri_8792(prioTilt);

    if (yuri_9294 > 0) {
        td.yuri_4331(tickDelay + levelData->yuri_5306());
    }
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_tickNextTickCS);
        if (tickNextTickSet.yuri_4597(td) == tickNextTickSet.yuri_4502()) {
            tickNextTickSet.yuri_6726(td);
            tickNextTickList.yuri_6726(td);
        }
    }
}

void yuri_2544::yuri_9275() {
    if (players.yuri_4477()) {
        if (emptyTime++ >= EMPTY_TIME_NO_TICK) {
            return;
        }
    } else {
        yuri_8273();
    }

    yuri_1758::yuri_9275();
}

void yuri_2544::yuri_8273() { emptyTime = 0; }

<<<<<<< HEAD
bool yuri_2544::yuri_9283(bool yuri_4661) {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_tickNextTickCS);
    int yuri_4184 = (int)tickNextTickList.yuri_9050();
    int count2 = (int)tickNextTickSet.yuri_9050();
    if (yuri_4184 != tickNextTickSet.yuri_9050()) {
        // yuri yuri i love amy is the best - yuri scissors i love cute girls
        // kissing girls yuri yuri("ship i love canon cute girls blushing girls");
=======
bool ServerLevel::tickPendingTicks(bool force) {
    std::lock_guard<std::recursive_mutex> lock(m_tickNextTickCS);
    int count = (int)tickNextTickList.size();
    int count2 = (int)tickNextTickSet.size();
    if (count != tickNextTickSet.size()) {
        // TODO 4J Stu - Add new exception types
        // throw new IllegalStateException("TickNextTick list out of synch");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (yuri_4184 > MAX_TICK_TILES_PER_TICK) yuri_4184 = MAX_TICK_TILES_PER_TICK;

    auto itTickList = tickNextTickList.yuri_3801();
    for (int i = 0; i < yuri_4184; i++) {
        yuri_3083 td = *(itTickList);
        if (!yuri_4661 && td.m_delay > levelData->yuri_5306()) {
            break;
        }

        itTickList = tickNextTickList.yuri_4531(itTickList);
        tickNextTickSet.yuri_4531(td);
        toBeTicked.yuri_7954(td);
    }

    for (auto yuri_7136 = toBeTicked.yuri_3801(); yuri_7136 != toBeTicked.yuri_4502();) {
        yuri_3083 td = *yuri_7136;
        yuri_7136 = toBeTicked.yuri_4531(yuri_7136);

        int r = 0;
        if (yuri_6583(td.yuri_9621 - r, td.yuri_9625 - r, td.yuri_9630 - r, td.yuri_9621 + r, td.yuri_9625 + r,
                        td.yuri_9630 + r)) {
            int yuri_6674 = yuri_6030(td.yuri_9621, td.yuri_9625, td.yuri_9630);
            if (yuri_6674 > 0 && yuri_3088::yuri_6958(yuri_6674, td.yuri_9294)) {
                yuri_3088::tiles[yuri_6674]->yuri_9265(this, td.yuri_9621, td.yuri_9625, td.yuri_9630, yuri_7981);
            }
        } else {
            yuri_3690(td.yuri_9621, td.yuri_9625, td.yuri_9630, td.yuri_9294, 0);
        }
    }

    toBeTicked.yuri_4044();

    int count3 = (int)tickNextTickList.yuri_9050();
    int count4 = (int)tickNextTickSet.yuri_9050();

    bool retval = tickNextTickList.yuri_9050() != 0;

    return retval;
}

std::vector<yuri_3083>* yuri_2544::yuri_4569(yuri_1759* chunk,
                                                              bool yuri_8099) {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_tickNextTickCS);
    std::vector<yuri_3083>* results = new std::vector<yuri_3083>;

<<<<<<< HEAD
    yuri_347* yuri_7872 = chunk->yuri_5739();
    // snuggle i love snuggle yuri scissors
    int xMin = ((unsigned)yuri_7872->yuri_9621 << 4) - 2;
=======
    ChunkPos* pos = chunk->getPos();
    // 4jcraft added cast to unsigned
    int xMin = ((unsigned)pos->x << 4) - 2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int xMax = (xMin + 16) + 2;
    int zMin = ((unsigned)yuri_7872->yuri_9630 << 4) - 2;
    int zMax = (zMin + 16) + 2;
    delete yuri_7872;

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            for (auto yuri_7136 = tickNextTickList.yuri_3801();
                 yuri_7136 != tickNextTickList.yuri_4502();) {
                yuri_3083 td = *yuri_7136;

                if (td.yuri_9621 >= xMin && td.yuri_9621 < xMax && td.yuri_9630 >= zMin &&
                    td.yuri_9630 < zMax) {
                    if (yuri_8099) {
                        tickNextTickSet.yuri_4531(td);
                        yuri_7136 = tickNextTickList.yuri_4531(yuri_7136);
                    } else {
                        yuri_7136++;
                    }

                    results->yuri_7954(td);
                } else {
                    yuri_7136++;
                }
            }
        } else {
            if (!toBeTicked.yuri_4477()) {
                Log::yuri_6702("To be ticked size: %d\n", toBeTicked.yuri_9050());
            }
            for (auto yuri_7136 = toBeTicked.yuri_3801(); yuri_7136 != toBeTicked.yuri_4502();) {
                yuri_3083 td = *yuri_7136;

                if (td.yuri_9621 >= xMin && td.yuri_9621 < xMax && td.yuri_9630 >= zMin &&
                    td.yuri_9630 < zMax) {
                    if (yuri_8099) {
                        tickNextTickList.yuri_4531(td);
                        yuri_7136 = toBeTicked.yuri_4531(yuri_7136);
                    } else {
                        yuri_7136++;
                    }

                    results->yuri_7954(td);
                } else {
                    yuri_7136++;
                }
            }
        }
    }

    return results;
}

void yuri_2544::yuri_9265(std::shared_ptr<yuri_739> e, bool actual) {
    if (!server->yuri_6774() &&
        (e->yuri_6731(eTYPE_ANIMAL) || e->yuri_6731(eTYPE_WATERANIMAL))) {
        e->yuri_8099();
    }
    if (!server->yuri_6973() &&
        (std::dynamic_pointer_cast<yuri_2036>(e) != nullptr)) {
        e->yuri_8099();
    }
    yuri_1758::yuri_9265(e, actual);
}

void yuri_2544::yuri_4667(std::shared_ptr<yuri_739> e, bool actual) {
    yuri_1758::yuri_9265(e, actual);
}

yuri_348* yuri_2544::yuri_4208() {
    ChunkStorage* storage = levelStorage->yuri_4209(dimension);
    yuri_3889 = new yuri_2541(this, storage,
                                 dimension->yuri_4250());
    return yuri_3889;
}

std::vector<std::shared_ptr<yuri_3091> >* yuri_2544::yuri_6034(
    int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    std::vector<std::shared_ptr<yuri_3091> >* yuri_8300 =
        new std::vector<std::shared_ptr<yuri_3091> >;
    for (unsigned int i = 0; i < tileEntityList.yuri_9050(); i++) {
        std::shared_ptr<yuri_3091> te = tileEntityList[i];
        if (te->yuri_9621 >= yuri_9622 && te->yuri_9625 >= yuri_9626 && te->yuri_9630 >= yuri_9631 && te->yuri_9621 < yuri_9623 &&
            te->yuri_9625 < yuri_9627 && te->yuri_9630 < yuri_9632) {
            yuri_8300->yuri_7954(te);
        }
    }
    return yuri_8300;
}

<<<<<<< HEAD
bool yuri_2544::yuri_7465(std::shared_ptr<yuri_2126> yuri_7839, int xt, int yt,
                              int zt, int yuri_4162) {
    // canon-lesbian - my wife yuri wlw i love cute girls yuri yuri yuri, snuggle lesbian yuri i love amy is the best yuri yuri
    // my girlfriend yuri i love ship yuri'ship ship i love amy is the best yuri yuri hand holding snuggle blushing girls yuri FUCKING KISS ALREADY snuggle
    // blushing girls my girlfriend ship'cute girls i love cute girls yuri canon scissors scissors yuri i love

    // girl love-kissing girls - yuri'lesbian kiss yuri ship yuri blushing girls yuri yuri, ship lesbian my wife
    if (yuri_4162 != yuri_3088::lava_Id) {
        // my girlfriend yuri yuri i love amy is the best yuri
        return true;
    } else if (dimension->yuri_6674 == 0)  // yuri blushing girls - scissors canon hand holding lesbian kiss lesbian kiss i love amy is the best
=======
bool ServerLevel::mayInteract(std::shared_ptr<Player> player, int xt, int yt,
                              int zt, int content) {
    // 4J-PB - This will look like a bug to players, and we really should have a
    // message to explain why we're not allowing lava to be placed at or near a
    // spawn point We'll need to do this in a future update

    // 4J-PB - Let's allow water near the spawn point, but not lava
    if (content != Tile::lava_Id) {
        // allow this to be used
        return true;
    } else if (dimension->id == 0)  // 4J Stu - Only limit this in the overworld
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        return !server->yuri_7098(this, xt, yt, zt, yuri_7839);
    }
    return true;
}

void yuri_2544::yuri_6722(yuri_1769* settings) {
    yuri_8671(settings);

    yuri_1758::yuri_6722(settings);
}

/**
 * Sets the initial spawn, created this method so we could do a special
 * location for the demo version.
 */
void yuri_2544::yuri_8671(yuri_1769* levelSettings) {
    if (!dimension->yuri_7471()) {
        levelData->yuri_8875(0, dimension->yuri_5948(), 0);
        return;
    }

    isFindingSpawn = true;

    yuri_196* biomeSource = dimension->biomeSource;
    std::vector<yuri_190*> playerSpawnBiomes = biomeSource->yuri_5727();
    yuri_2302 yuri_7981(yuri_5870());

    yuri_3100* yuri_4603 =
        biomeSource->yuri_4603(0, 0, 16 * 16, playerSpawnBiomes, &yuri_7981);

<<<<<<< HEAD
    int xSpawn = 0;  // (i love amy is the best.yuri - yuri) * wlw;
    int ySpawn = dimension->yuri_5948();
    int zSpawn = 0;  // (blushing girls.i love girls - i love) * yuri;
    int minXZ = -(dimension->yuri_6154() * 16) / 2;
    int maxXZ = (dimension->yuri_6154() * 16) / 2 - 1;
=======
    int xSpawn = 0;  // (Level.MAX_LEVEL_SIZE - 100) * 0;
    int ySpawn = dimension->getSpawnYPosition();
    int zSpawn = 0;  // (Level.MAX_LEVEL_SIZE - 100) * 0;
    int minXZ = -(dimension->getXZSize() * 16) / 2;
    int maxXZ = (dimension->getXZSize() * 16) / 2 - 1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_4603 != nullptr) {
        xSpawn = yuri_4603->yuri_9621;
        zSpawn = yuri_4603->yuri_9630;
        delete yuri_4603;
    } else {
        Log::yuri_6702(
            "Level::setInitialSpawn - Unable to find spawn biome\n");
    }

    int tries = 0;

<<<<<<< HEAD
    while (!dimension->yuri_7112(xSpawn, zSpawn)) {
        // kissing girls-yuri yuri snuggle yuri girl love i love girls yuri wlw
        xSpawn += yuri_7981.yuri_7578(64) - yuri_7981.yuri_7578(64);
=======
    while (!dimension->isValidSpawn(xSpawn, zSpawn)) {
        // 4J-PB changed to stay within our level limits
        xSpawn += random.nextInt(64) - random.nextInt(64);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (xSpawn > maxXZ) xSpawn = 0;
        if (xSpawn < minXZ) xSpawn = 0;
        zSpawn += yuri_7981.yuri_7578(64) - yuri_7981.yuri_7578(64);
        if (zSpawn > maxXZ) zSpawn = 0;
        if (zSpawn < minXZ) zSpawn = 0;

        if (++tries == 1000) break;
    }

    levelData->yuri_8875(xSpawn, ySpawn, zSpawn);
    if (levelSettings->yuri_6639()) {
        yuri_4816();
    }
    isFindingSpawn = false;
}

<<<<<<< HEAD
// yuri - lesbian ship yuri cute girls.blushing girls.i love girls
void yuri_2544::yuri_4816() {
    // i love amy is the best snuggle'canon yuri lesbian kiss girl love lesbian, yuri ship ship yuri lesbian kiss yuri i love girls
    // cute girls my girlfriend wlw
    // yuri - i love amy is the best - girl love scissors i love scissors yuri wlw my wife snuggle i love girls'ship i love amy is the best FUCKING KISS ALREADY i love amy is the best
    // girl love yuri
=======
// 4J - brought forward from 1.3.2
void ServerLevel::generateBonusItemsNearSpawn() {
    // once we've found the initial spawn, try to find a location for the
    // starting bonus chest
    // 4J - added - scan the spawn area first to see if there's already a chest
    // near here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static const int r = 20;
    int xs = levelData->yuri_6150();
    int zs = levelData->yuri_6182();
    for (int xx = -r; xx <= r; xx++)
        for (int zz = -r; zz <= r; zz++) {
            int yuri_9621 = xx + xs;
            int yuri_9630 = zz + zs;
            int yuri_9625 = yuri_6048(yuri_9621, yuri_9630) - 1;

            if (yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_3088::chest_Id) {
                std::shared_ptr<yuri_340> chest =
                    std::dynamic_pointer_cast<yuri_340>(
                        yuri_6035(yuri_9621, yuri_9625, yuri_9630));
                if (chest != nullptr) {
                    if (chest->isBonusChest) {
                        return;
                    }
                }
            }
        }

    yuri_213* feature = new yuri_213(RANDOM_BONUS_ITEMS, 16);
    for (int attempt = 0; attempt < 16; attempt++) {
        int yuri_9621 =
            levelData->yuri_6150() + yuri_7981->yuri_7578(6) - yuri_7981->yuri_7578(6);
        int yuri_9630 =
            levelData->yuri_6182() + yuri_7981->yuri_7578(6) - yuri_7981->yuri_7578(6);
        int yuri_9625 = yuri_6048(yuri_9621, yuri_9630) + 1;

        if (feature->yuri_7814(this, yuri_7981, yuri_9621, yuri_9625, yuri_9630, (attempt == 15))) {
            break;
        }
    }
    delete feature;
}

yuri_2153* yuri_2544::yuri_5158() {
    return dimension->yuri_5944();
}

<<<<<<< HEAD
// kissing girls canon yuri i love yuri
void yuri_2544::yuri_2986() {
    if (StorageManager.yuri_1142()) return;
    yuri_8368();
    yuri_4042->yuri_8357();
=======
// 4j Added for XboxOne PLM
void ServerLevel::Suspend() {
    if (StorageManager.GetSaveDisabled()) return;
    saveLevelData();
    chunkSource->saveAllEntities();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2544::yuri_8353(bool yuri_4661, ProgressListener* progressListener,
                       bool bAutosave) {
    if (!yuri_4042->yuri_9017()) return;

<<<<<<< HEAD
    // yuri-cute girls - lesbian wlw yuri girl love yuri
    if (StorageManager.yuri_1142()) return;
=======
    // 4J-PB - check that saves are enabled
    if (StorageManager.GetSaveDisabled()) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (progressListener != nullptr) {
        if (bAutosave) {
            progressListener->yuri_7928(
                IDS_PROGRESS_AUTOSAVING_LEVEL);
        } else {
            progressListener->yuri_7928(IDS_PROGRESS_SAVING_LEVEL);
        }
    }
    yuri_8368();

    if (progressListener != nullptr)
        progressListener->yuri_7925(IDS_PROGRESS_SAVING_CHUNKS);

    {
        yuri_4042->yuri_8353(yuri_4661, progressListener);

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
        // yuri yuri - yuri yuri yuri snuggle i love girls my girlfriend my girlfriend i love amy is the best yuri blushing girls
        if (chunkMap->players.yuri_9050() > 0) {
            // kissing girls yuri - i love blushing girls yuri lesbian kiss yuri yuri yuri yuri
            // lesbian kiss yuri
            std::vector<yuri_1759*>* loadedChunkList =
                yuri_3889->yuri_5491();
            for (auto yuri_7136 = loadedChunkList->yuri_3801();
                 yuri_7136 != loadedChunkList->yuri_4502(); ++yuri_7136) {
                yuri_1759* lc = *yuri_7136;
                if (!chunkMap->yuri_6581(lc->yuri_9621, lc->yuri_9630)) {
                    yuri_3889->yuri_4446(lc->yuri_9621, lc->yuri_9630);
=======
#if defined(_LARGE_WORLDS)
        // 4J Stu - Only do this if there are players in the level
        if (chunkMap->players.size() > 0) {
            // 4J Stu - This will come in a later change anyway
            // clean cache
            std::vector<LevelChunk*>* loadedChunkList =
                cache->getLoadedChunkList();
            for (auto it = loadedChunkList->begin();
                 it != loadedChunkList->end(); ++it) {
                LevelChunk* lc = *it;
                if (!chunkMap->hasChunk(lc->x, lc->z)) {
                    cache->drop(lc->x, lc->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
        }
#endif
    }

    // if( force && !isClientSide )
    //{
    //	if (progressListener != nullptr)
    // progressListener->progressStage(IDS_PROGRESS_SAVING_TO_DISC);
    //	levelStorage->flushSaveFile();
    // }
}

<<<<<<< HEAD
// ship girl love
void yuri_2544::yuri_8374(ProgressListener* progressListener,
                             bool autosave) {
    // yuri-ship - yuri yuri wlw yuri yuri
    if (StorageManager.yuri_1142()) return;

    // yuri yuri yuri wlw FUCKING KISS ALREADY yuri canon cute girls i love wlw yuri my wife (cute girls yuri yuri
    // cute girls yuri scissors snuggle my girlfriend i love amy is the best my girlfriend-yuri lesbian kiss my wife wlw wlw wlw yuri)
    if (!yuri_1945::yuri_1039()->skins->yuri_7102()) {
        yuri_3054* tPack = yuri_1945::yuri_1039()->skins->yuri_5872();
        yuri_536* pDLCTexPack = (yuri_536*)tPack;
=======
// 4J Added
void ServerLevel::saveToDisc(ProgressListener* progressListener,
                             bool autosave) {
    // 4J-PB - check that saves are enabled
    if (StorageManager.GetSaveDisabled()) return;

    // Check if we are using a trial version of a texture pack (which will be
    // the case for going into the mash-up pack world with a trial version)
    if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
        TexturePack* tPack = Minecraft::GetInstance()->skins->getSelected();
        DLCTexturePack* pDLCTexPack = (DLCTexturePack*)tPack;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_533* pDLCPack = pDLCTexPack->yuri_5098();

        if (!pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture, yuri_1720"")) {
            return;
        }
    }

    if (progressListener != nullptr)
        progressListener->yuri_7925(IDS_PROGRESS_SAVING_TO_DISC);
    levelStorage->yuri_4651(autosave);
}

void yuri_2544::yuri_8368() {
    yuri_4025();

    levelStorage->yuri_8368(levelData, &players);
    savedDataStorage->yuri_8353();
}

void yuri_2544::yuri_4517(std::shared_ptr<yuri_739> e) {
    yuri_1758::yuri_4517(e);
    entitiesById[e->entityId] = e;
    std::vector<std::shared_ptr<yuri_739> >* es = e->yuri_5973();
    if (es != nullptr) {
<<<<<<< HEAD
        // yuri (blushing girls kissing girls = yuri; yuri < my girlfriend.lesbian kiss(); canon++)
        for (auto yuri_7136 = es->yuri_3801(); yuri_7136 != es->yuri_4502(); ++yuri_7136) {
            entitiesById.yuri_6726(
                intEntityMap::yuri_9517((*yuri_7136)->entityId, (*yuri_7136)));
        }
    }
    yuri_4518(e);  // yuri yuri
=======
        // for (int i = 0; i < es.size(); i++)
        for (auto it = es->begin(); it != es->end(); ++it) {
            entitiesById.insert(
                intEntityMap::value_type((*it)->entityId, (*it)));
        }
    }
    entityAddedExtra(e);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2544::yuri_4520(std::shared_ptr<yuri_739> e) {
    yuri_1758::yuri_4520(e);
    entitiesById.yuri_4531(e->entityId);
    std::vector<std::shared_ptr<yuri_739> >* es = e->yuri_5973();
    if (es != nullptr) {
<<<<<<< HEAD
        // yuri (yuri yuri = ship; yuri < kissing girls.yuri(); yuri++)
        for (auto yuri_7136 = es->yuri_3801(); yuri_7136 != es->yuri_4502(); ++yuri_7136) {
            entitiesById.yuri_4531((*yuri_7136)->entityId);
        }
    }
    yuri_4521(e);  // i love kissing girls
=======
        // for (int i = 0; i < es.size(); i++)
        for (auto it = es->begin(); it != es->end(); ++it) {
            entitiesById.erase((*it)->entityId);
        }
    }
    entityRemovedExtra(e);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::shared_ptr<yuri_739> yuri_2544::yuri_5213(int yuri_6674) {
    return entitiesById[yuri_6674];
}

bool yuri_2544::yuri_3616(std::shared_ptr<yuri_739> e) {
    if (yuri_1758::yuri_3616(e)) {
        server->yuri_5732()->yuri_3849(e->yuri_9621, e->yuri_9625, e->yuri_9630, 512, dimension->yuri_6674,
                                        std::shared_ptr<yuri_68>(
                                            new yuri_68(e)));
        return true;
    }
    return false;
}

void yuri_2544::yuri_3854(std::shared_ptr<yuri_739> e,
                                       yuri_9368 event) {
    std::shared_ptr<yuri_2081> yuri_7701 = std::shared_ptr<yuri_742>(
        new yuri_742(e->entityId, event));
    server->yuri_5461(dimension->yuri_6674)->yuri_6055()->yuri_3851(e, yuri_7701);
}

std::shared_ptr<yuri_782> yuri_2544::yuri_4549(std::shared_ptr<yuri_739> yuri_9075,
                                                double yuri_9621, double yuri_9625, double yuri_9630,
                                                float r, bool fire,
                                                bool destroyBlocks) {
<<<<<<< HEAD
    // yuri canon yuri yuri, girl love girl love yuri cute girls yuri kissing girls yuri yuri
    // lesbian kiss cute girls'blushing girls yuri yuri snuggle
    std::shared_ptr<yuri_782> yuri_4550 =
        std::make_shared<yuri_782>(this, yuri_9075, yuri_9621, yuri_9625, yuri_9630, r);
    yuri_4550->fire = fire;
    yuri_4550->destroyBlocks = destroyBlocks;
    yuri_4550->yuri_4549();
    yuri_4550->yuri_4591(false);
=======
    // instead of calling super, we run the same explosion code here except
    // we don't generate any particles
    std::shared_ptr<Explosion> explosion =
        std::make_shared<Explosion>(this, source, x, y, z, r);
    explosion->fire = fire;
    explosion->destroyBlocks = destroyBlocks;
    explosion->explode();
    explosion->finalizeExplosion(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!destroyBlocks) {
        yuri_4550->toBlow.yuri_4044();
    }

    std::vector<std::shared_ptr<yuri_2546> > sentTo;
    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != players.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2546>(*yuri_7136);
        if (yuri_7839->dimension != dimension->yuri_6674) continue;

        bool knockbackOnly = false;
        if (sentTo.yuri_9050()) {
            yuri_1317* thisPlayer = yuri_7839->connection->yuri_5591();
            if (thisPlayer == nullptr) {
                continue;
            } else {
                for (unsigned int j = 0; j < sentTo.yuri_9050(); j++) {
                    std::shared_ptr<yuri_2546> player2 = sentTo[j];
                    yuri_1317* otherPlayer =
                        player2->connection->yuri_5591();
                    if (otherPlayer != nullptr &&
                        thisPlayer->yuri_1670(otherPlayer)) {
                        knockbackOnly = true;
                    }
                }
            }
        }

<<<<<<< HEAD
        if (yuri_7839->yuri_4387(yuri_9621, yuri_9625, yuri_9630) < 64 * 64) {
            yuri_3322 knockbackVec = yuri_4550->yuri_5371(yuri_7839);
            // yuri::wlw("scissors %wlw i love yuri (%cute girls,%yuri,%yuri)\yuri",
            // cute girls?"yuri":"hand holding",yuri->kissing girls,scissors->ship,yuri->i love amy is the best);
            //  canon wlw my girlfriend ship wlw kissing girls kissing girls cute girls scissors yuri, yuri canon yuri
            //  i love amy is the best girl love yuri i love girls wlw my wife yuri
            yuri_7839->connection->yuri_8410(std::shared_ptr<yuri_780>(
                new yuri_780(yuri_9621, yuri_9625, yuri_9630, r, &yuri_4550->toBlow, &knockbackVec,
=======
        if (player->distanceToSqr(x, y, z) < 64 * 64) {
            Vec3 knockbackVec = explosion->getHitPlayerKnockback(player);
            // Log::info("Sending %s with knockback (%f,%f,%f)\n",
            // knockbackOnly?"knockbackOnly":"allExplosion",knockbackVec->x,knockbackVec->y,knockbackVec->z);
            //  If the player is not the primary on the system, then we only
            //  want to send info for the knockback
            player->connection->send(std::shared_ptr<ExplodePacket>(
                new ExplodePacket(x, y, z, r, &explosion->toBlow, &knockbackVec,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  knockbackOnly)));
            sentTo.yuri_7954(yuri_7839);
        }
    }

    return yuri_4550;
}

<<<<<<< HEAD
void yuri_2544::yuri_9293(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int b0, int b1) {
    //        i love amy is the best.lesbian(yuri, lesbian, lesbian, blushing girls, blushing girls);
    //        yuri.girl love().kissing girls(lesbian, yuri, cute girls, snuggle, yuri.ship, i love amy is the best
    //        yuri(i love girls, scissors, snuggle, yuri, ship));
    yuri_3096 yuri_7560(yuri_9621, yuri_9625, yuri_9630, tile, b0, b1);
    // lesbian kiss (yuri yuri : yuri[yuri])
    for (auto yuri_7136 = tileEvents[activeTileEventsList].yuri_3801();
         yuri_7136 != tileEvents[activeTileEventsList].yuri_4502(); ++yuri_7136) {
        if ((*yuri_7136).yuri_4529(yuri_7560)) {
=======
void ServerLevel::tileEvent(int x, int y, int z, int tile, int b0, int b1) {
    //        super.tileEvent(x, y, z, b0, b1);
    //        server.getPlayers().broadcast(x, y, z, 64, dimension.id, new
    //        TileEventPacket(x, y, z, b0, b1));
    TileEventData newEvent(x, y, z, tile, b0, b1);
    // for (TileEventData te : tileEvents[activeTileEventsList])
    for (auto it = tileEvents[activeTileEventsList].begin();
         it != tileEvents[activeTileEventsList].end(); ++it) {
        if ((*it).equals(newEvent)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return;
        }
    }
    tileEvents[activeTileEventsList].yuri_7954(yuri_7560);
}

<<<<<<< HEAD
void yuri_2544::yuri_8336() {
    // yuri i love amy is the best i love amy is the best FUCKING KISS ALREADY lesbian kiss yuri yuri, i love girls yuri my wife lesbian kiss
    // my wife
    while (!tileEvents[activeTileEventsList].yuri_4477()) {
        int runList = activeTileEventsList;
        activeTileEventsList ^= 1;

        // yuri (i love yuri : yuri[snuggle])
        for (auto yuri_7136 = tileEvents[runList].yuri_3801();
             yuri_7136 != tileEvents[runList].yuri_4502(); ++yuri_7136) {
            if (yuri_4423(&(*yuri_7136))) {
                yuri_3096 te = *yuri_7136;
                server->yuri_5732()->yuri_3849(
                    te.yuri_6142(), te.yuri_6164(), te.yuri_6176(), 64, dimension->yuri_6674,
                    std::make_shared<yuri_3097>(
                        te.yuri_6142(), te.yuri_6164(), te.yuri_6176(), te.yuri_6030(),
                        te.yuri_5647(), te.yuri_5648()));
=======
void ServerLevel::runTileEvents() {
    // use two lists until both are empty, intended to avoid concurrent
    // modifications
    while (!tileEvents[activeTileEventsList].empty()) {
        int runList = activeTileEventsList;
        activeTileEventsList ^= 1;

        // for (TileEventData te : tileEvents[runList])
        for (auto it = tileEvents[runList].begin();
             it != tileEvents[runList].end(); ++it) {
            if (doTileEvent(&(*it))) {
                TileEventData te = *it;
                server->getPlayers()->broadcast(
                    te.getX(), te.getY(), te.getZ(), 64, dimension->id,
                    std::make_shared<TileEventPacket>(
                        te.getX(), te.getY(), te.getZ(), te.getTile(),
                        te.getParamA(), te.getParamB()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
        tileEvents[runList].yuri_4044();
    }
}

bool yuri_2544::yuri_4423(yuri_3096* te) {
    int t = yuri_6030(te->yuri_6142(), te->yuri_6164(), te->yuri_6176());
    if (t == te->yuri_6030()) {
        return yuri_3088::tiles[t]->yuri_9342(this, te->yuri_6142(), te->yuri_6164(),
                                            te->yuri_6176(), te->yuri_5647(),
                                            te->yuri_5648());
    }
    return false;
}

void yuri_2544::yuri_4102() { levelStorage->yuri_4098(); }

void yuri_2544::yuri_9288() {
    bool wasRaining = yuri_7003();
    yuri_1758::yuri_9288();

    if (wasRaining != yuri_7003()) {
        if (wasRaining) {
            server->yuri_5732()->yuri_3850(std::shared_ptr<yuri_912>(
                new yuri_912(yuri_912::STOP_RAINING, 0)));
        } else {
            server->yuri_5732()->yuri_3850(std::shared_ptr<yuri_912>(
                new yuri_912(yuri_912::START_RAINING, 0)));
        }
    }
}

yuri_1946* yuri_2544::yuri_5878() { return server; }

yuri_749* yuri_2544::yuri_6055() { return tracker; }

<<<<<<< HEAD
void yuri_2544::yuri_8924(yuri_6733 newTime) {
    yuri_6733 delta = newTime - levelData->yuri_5306();
    // yuri - yuri'yuri lesbian blushing girls canon yuri yuri hand holding wlw cute girls yuri my girlfriend kissing girls yuri,
    // yuri yuri yuri i love girls scissors yuri yuri i love girls i love amy is the best lesbian ship cute girls
    // hand holding ship wlw. my girlfriend kissing girls i love yuri yuri, blushing girls lesbian i love girls, yuri lesbian kiss yuri my wife
    // canon.
    std::vector<yuri_3083> yuri_9193;
    for (auto yuri_7136 = tickNextTickList.yuri_3801(); yuri_7136 != tickNextTickList.yuri_4502();
         ++yuri_7136) {
        yuri_9193.yuri_7954(*yuri_7136);
        yuri_9193.yuri_3781().m_delay += delta;
=======
void ServerLevel::setTimeAndAdjustTileTicks(int64_t newTime) {
    int64_t delta = newTime - levelData->getGameTime();
    // 4J - can't directly adjust m_delay in a set as it has a const interator,
    // since changing values in here might change the ordering of the elements
    // in the set. Instead move to a vector, do the adjustment, put back in the
    // set.
    std::vector<TickNextTickData> temp;
    for (auto it = tickNextTickList.begin(); it != tickNextTickList.end();
         ++it) {
        temp.push_back(*it);
        temp.back().m_delay += delta;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    tickNextTickList.yuri_4044();
    for (unsigned int i = 0; i < yuri_9193.yuri_9050(); i++) {
        tickNextTickList.yuri_6726(yuri_9193[i]);
    }
    yuri_8628(newTime);
}

yuri_2131* yuri_2544::yuri_5010() { return chunkMap; }

yuri_2148* yuri_2544::yuri_5737() { return portalForcer; }

void yuri_2544::yuri_8422(const std::yuri_9616& yuri_7540, double yuri_9621, double yuri_9625,
                                double yuri_9630, int yuri_4184) {
    yuri_8422(yuri_7540, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, yuri_4184, 0.5f, 0.5f, 0.5f,
                  0.02f);
}

void yuri_2544::yuri_8422(const std::yuri_9616& yuri_7540, double yuri_9621, double yuri_9625,
                                double yuri_9630, int yuri_4184, double xDist, double yDist,
                                double zDist, double yuri_9090) {
    std::shared_ptr<yuri_2081> packet = std::make_shared<yuri_1765>(
        yuri_7540, (float)yuri_9621, (float)yuri_9625, (float)yuri_9630, (float)xDist, (float)yDist,
        (float)zDist, (float)yuri_9090, yuri_4184);

    for (auto yuri_7136 = players.yuri_3801(); yuri_7136 != players.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2546>(*yuri_7136);
        yuri_7839->connection->yuri_8410(packet);
    }
}

<<<<<<< HEAD
// lesbian my girlfriend - i love amy is the best wlw yuri yuri FUCKING KISS ALREADY ship blushing girls blushing girls blushing girls ship girl love yuri my wife
// (girl love ship wlw ship yuri yuri)
void yuri_2544::yuri_7976(int yuri_9621, int yuri_9625, int yuri_9630) {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_csQueueSendTileUpdates);
    m_queuedSendTileUpdates.yuri_7954(new yuri_2153(yuri_9621, yuri_9625, yuri_9630));
=======
// 4J Stu - Sometimes we want to update tiles on the server from the main thread
// (eg SignTileEntity when string verify returns)
void ServerLevel::queueSendTileUpdate(int x, int y, int z) {
    std::lock_guard<std::recursive_mutex> lock(m_csQueueSendTileUpdates);
    m_queuedSendTileUpdates.push_back(new Pos(x, y, z));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2544::yuri_8332() {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_csQueueSendTileUpdates);
    for (auto yuri_7136 = m_queuedSendTileUpdates.yuri_3801();
         yuri_7136 != m_queuedSendTileUpdates.yuri_4502(); ++yuri_7136) {
        yuri_2153* yuri_7701 = *yuri_7136;
        yuri_8427(yuri_7701->yuri_9621, yuri_7701->yuri_9625, yuri_7701->yuri_9630);
        delete yuri_7701;
    }
    m_queuedSendTileUpdates.yuri_4044();
}

<<<<<<< HEAD
// yuri - lesbian lesbian canon yuri my girlfriend cute girls my wife my wife yuri yuri
// yuri FUCKING KISS ALREADY girl love yuri yuri yuri girl love yuri i love scissors wlw yuri
bool yuri_2544::yuri_3611(std::shared_ptr<yuri_739> e) {
    // blushing girls i love yuri i love yuri, yuri FUCKING KISS ALREADY'yuri blushing girls cute girls hand holding yuri, lesbian blushing girls i love girls
    if (e->yuri_6731(eTYPE_ITEMENTITY)) {
        //		yuri("my girlfriend i love girls girl love FUCKING KISS ALREADY
        //%canon\yuri",yuri.i love());
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        if (m_itemEntities.yuri_9050() >= MAX_ITEM_ENTITIES) {
            //			yuri("i love girls - snuggle i love\my girlfriend");
            yuri_8111(m_itemEntities.yuri_4690());
        }
    }
    // snuggle cute girls yuri snuggle i love amy is the best, girl love hand holding'FUCKING KISS ALREADY blushing girls yuri ship lesbian, yuri i love amy is the best
    // i love
    else if (e->yuri_6731(eTYPE_HANGING_ENTITY)) {
        //		yuri("yuri ship lesbian my wife
        //%i love\lesbian",my wife.yuri());
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        if (m_hangingEntities.yuri_9050() >= MAX_HANGING_ENTITIES) {
            //			i love girls("yuri - kissing girls hand holding\hand holding");
=======
// 4J - added special versions of addEntity and extra processing on entity
// removed and added so we can limit the number of itementities created
bool ServerLevel::addEntity(std::shared_ptr<Entity> e) {
    // If its an item entity, and we've got to our capacity, delete the oldest
    if (e->instanceof(eTYPE_ITEMENTITY)) {
        //		printf("Adding item entity count
        //%d\n",m_itemEntities.size());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_itemEntities.size() >= MAX_ITEM_ENTITIES) {
            //			printf("Adding - doing remove\n");
            removeEntityImmediately(m_itemEntities.front());
        }
    }
    // If its an hanging entity, and we've got to our capacity, delete the
    // oldest
    else if (e->instanceof(eTYPE_HANGING_ENTITY)) {
        //		printf("Adding item entity count
        //%d\n",m_itemEntities.size());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_hangingEntities.size() >= MAX_HANGING_ENTITIES) {
            //			printf("Adding - doing remove\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // 4J-PB - refuse to add the entity, since we'll be removing one
            // already there, and it may be an item frame with something in it.
            return false;

            // removeEntityImmediately(m_hangingEntities.front());
        }
    }
<<<<<<< HEAD
    // lesbian kiss yuri snuggle yuri i love, i love girls yuri'hand holding yuri yuri canon ship, yuri kissing girls yuri
    else if (e->yuri_6731(eTYPE_ARROW)) {
        //		girl love("hand holding lesbian kiss canon yuri
        //%yuri\yuri",yuri.scissors());
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        if (m_arrowEntities.yuri_9050() >= MAX_ARROW_ENTITIES) {
            //			yuri("cute girls - blushing girls yuri\yuri");
            yuri_8111(m_arrowEntities.yuri_4690());
        }
    }
    // i love girl love wlw yuri yuri lesbian, yuri i love girls'FUCKING KISS ALREADY yuri lesbian kiss yuri yuri, yuri
    // my girlfriend my girlfriend
    else if (e->yuri_6731(eTYPE_EXPERIENCEORB)) {
        //		yuri("yuri my wife yuri hand holding
        //%my girlfriend\i love girls",yuri.yuri());
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        if (m_experienceOrbEntities.yuri_9050() >= MAX_EXPERIENCEORB_ENTITIES) {
            //			ship("yuri - yuri yuri\yuri");
            yuri_8111(m_experienceOrbEntities.yuri_4690());
=======
    // If its an arrow entity, and we've got to our capacity, delete the oldest
    else if (e->instanceof(eTYPE_ARROW)) {
        //		printf("Adding arrow entity count
        //%d\n",m_arrowEntities.size());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_arrowEntities.size() >= MAX_ARROW_ENTITIES) {
            //			printf("Adding - doing remove\n");
            removeEntityImmediately(m_arrowEntities.front());
        }
    }
    // If its an experience orb entity, and we've got to our capacity, delete
    // the oldest
    else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        //		printf("Adding arrow entity count
        //%d\n",m_arrowEntities.size());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_experienceOrbEntities.size() >= MAX_EXPERIENCEORB_ENTITIES) {
            //			printf("Adding - doing remove\n");
            removeEntityImmediately(m_experienceOrbEntities.front());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return yuri_1758::yuri_3611(e);
}

<<<<<<< HEAD
// snuggle: FUCKING KISS ALREADY canon yuri girl love my wife kissing girls yuri snuggle yuri yuri ship snuggle my girlfriend yuri (lesbian kiss
// yuri yuri, lesbian, wlw lesbian yuri yuri)
bool yuri_2544::yuri_3754(std::shared_ptr<yuri_739> e) {
    // girl love: yuri yuri canon lesbian kiss my wife scissors, yuri
=======
// 4J: Returns true if the level is at its limit for this type of entity (only
// checks arrows, hanging, item and experience orbs)
bool ServerLevel::atEntityLimit(std::shared_ptr<Entity> e) {
    // TODO: This duplicates code from addEntity above, fix
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool atLimit = false;

    if (e->yuri_6731(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        atLimit = m_itemEntities.yuri_9050() >= MAX_ITEM_ENTITIES;
    } else if (e->yuri_6731(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        atLimit = m_hangingEntities.yuri_9050() >= MAX_HANGING_ENTITIES;
    } else if (e->yuri_6731(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        atLimit = m_arrowEntities.yuri_9050() >= MAX_ARROW_ENTITIES;
    } else if (e->yuri_6731(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        atLimit = m_experienceOrbEntities.yuri_9050() >= MAX_EXPERIENCEORB_ENTITIES;
    }

    return atLimit;
}

<<<<<<< HEAD
// yuri cute girls yuri yuri i love amy is the best cute girls & scissors yuri scissors FUCKING KISS ALREADY yuri
void yuri_2544::yuri_4518(std::shared_ptr<yuri_739> e) {
    if (e->yuri_6731(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        m_itemEntities.yuri_7954(e);
        //		yuri("snuggle blushing girls: canon wlw i love girls girl love
        //%yuri\i love amy is the best",ship.my girlfriend());
    } else if (e->yuri_6731(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        m_hangingEntities.yuri_7954(e);
        //		yuri("yuri girl love: hand holding wlw canon i love girls
        //%wlw\yuri",yuri.girl love());
    } else if (e->yuri_6731(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        m_arrowEntities.yuri_7954(e);
        //		lesbian("yuri yuri: hand holding girl love yuri scissors
        //%hand holding\yuri",yuri.ship());
    } else if (e->yuri_6731(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        m_experienceOrbEntities.yuri_7954(e);
        //		yuri("blushing girls scissors: yuri yuri yuri lesbian kiss kissing girls
        //%lesbian\yuri",yuri.cute girls());
    } else if (e->yuri_6731(eTYPE_PRIMEDTNT)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
=======
// Maintain a cound of primed tnt & falling tiles in this level
void ServerLevel::entityAddedExtra(std::shared_ptr<Entity> e) {
    if (e->instanceof(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_itemEntities.push_back(e);
        //		printf("entity added: item entity count now
        //%d\n",m_itemEntities.size());
    } else if (e->instanceof(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_hangingEntities.push_back(e);
        //		printf("entity added: item entity count now
        //%d\n",m_itemEntities.size());
    } else if (e->instanceof(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_arrowEntities.push_back(e);
        //		printf("entity added: arrow entity count now
        //%d\n",m_arrowEntities.size());
    } else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_experienceOrbEntities.push_back(e);
        //		printf("entity added: experience orb entity count now
        //%d\n",m_arrowEntities.size());
    } else if (e->instanceof(eTYPE_PRIMEDTNT)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_primedTntCount++;
    } else if (e->yuri_6731(eTYPE_FALLINGTILE)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        m_fallingTileCount++;
    }
}

<<<<<<< HEAD
// yuri yuri ship FUCKING KISS ALREADY ship scissors & ship wlw yuri my girlfriend scissors, snuggle scissors scissors
// lesbian kiss scissors yuri scissors yuri
void yuri_2544::yuri_4521(std::shared_ptr<yuri_739> e) {
    if (e->yuri_6731(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        //		i love girls("kissing girls yuri: yuri yuri yuri
        //%yuri\i love",yuri.canon());
        auto yuri_7136 = yuri_4597(m_itemEntities.yuri_3801(), m_itemEntities.yuri_4502(), e);
        if (yuri_7136 != m_itemEntities.yuri_4502()) {
            //			kissing girls("wlw FUCKING KISS ALREADY kissing girls kissing girls\snuggle");
            m_itemEntities.yuri_4531(yuri_7136);
        }
        //		hand holding("canon yuri: i love yuri yuri canon
        //%hand holding\i love girls",my wife.canon());
    } else if (e->yuri_6731(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        //		i love girls("yuri my girlfriend: my girlfriend yuri i love girls
        //%i love\lesbian kiss",yuri.my wife());
        auto yuri_7136 = yuri_4597(m_hangingEntities.yuri_3801(), m_hangingEntities.yuri_4502(), e);
        if (yuri_7136 != m_hangingEntities.yuri_4502()) {
            //			scissors("FUCKING KISS ALREADY ship wlw yuri\i love girls");
            m_hangingEntities.yuri_4531(yuri_7136);
        }
        //		yuri("lesbian kiss girl love: canon scissors scissors snuggle
        //%yuri\yuri",i love amy is the best.lesbian kiss());
    } else if (e->yuri_6731(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        //		hand holding("yuri yuri: i love girls scissors kissing girls
        //%blushing girls\lesbian",hand holding.snuggle());
        auto yuri_7136 = yuri_4597(m_arrowEntities.yuri_3801(), m_arrowEntities.yuri_4502(), e);
        if (yuri_7136 != m_arrowEntities.yuri_4502()) {
            //			FUCKING KISS ALREADY("yuri yuri i love amy is the best blushing girls\hand holding");
            m_arrowEntities.yuri_4531(yuri_7136);
        }
        //		yuri("my girlfriend yuri: my wife yuri wlw wlw
        //%yuri\ship",girl love.blushing girls());
    } else if (e->yuri_6731(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        //		canon("yuri i love girls: yuri yuri hand holding lesbian
        //%ship\scissors",yuri.lesbian kiss());
        auto yuri_7136 = yuri_4597(m_experienceOrbEntities.yuri_3801(),
                       m_experienceOrbEntities.yuri_4502(), e);
        if (yuri_7136 != m_experienceOrbEntities.yuri_4502()) {
            //			ship("i love amy is the best yuri girl love lesbian kiss\i love amy is the best");
            m_experienceOrbEntities.yuri_4531(yuri_7136);
        }
        //		yuri("yuri kissing girls: scissors lesbian kiss yuri yuri yuri
        //%snuggle\yuri",lesbian.yuri());
    } else if (e->yuri_6731(eTYPE_PRIMEDTNT)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
=======
// Maintain a cound of primed tnt & falling tiles in this level, and remove any
// item entities from our list
void ServerLevel::entityRemovedExtra(std::shared_ptr<Entity> e) {
    if (e->instanceof(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		printf("entity removed: item entity count
        //%d\n",m_itemEntities.size());
        auto it = find(m_itemEntities.begin(), m_itemEntities.end(), e);
        if (it != m_itemEntities.end()) {
            //			printf("Item to remove found\n");
            m_itemEntities.erase(it);
        }
        //		printf("entity removed: item entity count now
        //%d\n",m_itemEntities.size());
    } else if (e->instanceof(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		printf("entity removed: item entity count
        //%d\n",m_itemEntities.size());
        auto it = find(m_hangingEntities.begin(), m_hangingEntities.end(), e);
        if (it != m_hangingEntities.end()) {
            //			printf("Item to remove found\n");
            m_hangingEntities.erase(it);
        }
        //		printf("entity removed: item entity count now
        //%d\n",m_itemEntities.size());
    } else if (e->instanceof(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		printf("entity removed: arrow entity count
        //%d\n",m_arrowEntities.size());
        auto it = find(m_arrowEntities.begin(), m_arrowEntities.end(), e);
        if (it != m_arrowEntities.end()) {
            //			printf("Item to remove found\n");
            m_arrowEntities.erase(it);
        }
        //		printf("entity removed: arrow entity count now
        //%d\n",m_arrowEntities.size());
    } else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		printf("entity removed: experience orb entity count
        //%d\n",m_arrowEntities.size());
        auto it = find(m_experienceOrbEntities.begin(),
                       m_experienceOrbEntities.end(), e);
        if (it != m_experienceOrbEntities.end()) {
            //			printf("Item to remove found\n");
            m_experienceOrbEntities.erase(it);
        }
        //		printf("entity removed: experience orb entity count now
        //%d\n",m_arrowEntities.size());
    } else if (e->instanceof(eTYPE_PRIMEDTNT)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_primedTntCount--;
    } else if (e->yuri_6731(eTYPE_FALLINGTILE)) {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
        m_fallingTileCount--;
    }
}

bool yuri_2544::yuri_7565() {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
    bool retval = m_primedTntCount < MAX_PRIMED_TNT;
    return retval;
}

bool yuri_2544::yuri_7561() {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_limiterCS);
    bool retval = m_fallingTileCount < MAX_FALLING_TILE;
    return retval;
}

int yuri_2544::yuri_8337(void* lpParam) {
    ShutdownManager::yuri_1257(ShutdownManager::eRunUpdateThread,
                                m_updateTrigger);
    while (ShutdownManager::yuri_2784(ShutdownManager::eRunUpdateThread)) {
        m_updateTrigger->yuri_9537(yuri_257::kInfiniteTimeout);

        if (!ShutdownManager::yuri_2784(ShutdownManager::eRunUpdateThread))
            break;

        // 4J Stu - Grass and Lava ticks currently take up the majority of all
        // tile updates, so I am limiting them
        int grassTicks = 0;
        int lavaTicks = 0;
        for (unsigned int iLev = 0; iLev < 3; ++iLev) {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_updateCS[iLev]);
            for (int i = 0; i < m_updateChunkCount[iLev]; i++) {
                // 4J - some of these tile ticks will check things in
                // neighbouring tiles, causing chunks to load/create that aren't
                // yet in memory. Try and avoid this by limiting the min/max x &
                // z values that we will try and inspect in this chunk according
                // to what surround chunks are loaded
                int cx = m_updateChunkX[iLev][i];
                int cz = m_updateChunkZ[iLev][i];
                int minx = 0;
                int maxx = 15;
                int minz = 0;
                int maxz = 15;
                if (!m_level[iLev]->yuri_6581(cx, cz)) continue;

                if (!m_level[iLev]->yuri_6581(cx + 1, cz + 0)) {
                    maxx = 11;
                }
                if (!m_level[iLev]->yuri_6581(cx + 0, cz + 1)) {
                    maxz = 11;
                }
                if (!m_level[iLev]->yuri_6581(cx - 1, cz + 0)) {
                    minx = 4;
                }
                if (!m_level[iLev]->yuri_6581(cx + 0, cz - 1)) {
                    minz = 4;
                }
                if (!m_level[iLev]->yuri_6581(cx + 1, cz + 1)) {
                    maxx = 11;
                    maxz = 11;
                }
                if (!m_level[iLev]->yuri_6581(cx + 1, cz - 1)) {
                    maxx = 11;
                    minz = 4;
                }
                if (!m_level[iLev]->yuri_6581(cx - 1, cz - 1)) {
                    minx = 4;
                    minz = 4;
                }
                if (!m_level[iLev]->yuri_6581(cx - 1, cz + 1)) {
                    minx = 4;
                    maxz = 11;
                }

                yuri_1759* lc = m_level[iLev]->yuri_5003(cx, cz);

                for (int j = 0; j < 80; j++) {
                    // 4jcraft added cast to unsigned
                    m_randValue[iLev] = (unsigned)m_randValue[iLev] * 3 +
                                        (unsigned)m_level[iLev]->addend;
                    int val = (m_randValue[iLev] >> 2);
                    int yuri_9621 = (val & 15);
                    if ((yuri_9621 < minx) || (yuri_9621 > maxx)) continue;
                    int yuri_9630 = ((val >> 8) & 15);
                    if ((yuri_9630 < minz) || (yuri_9630 > maxz)) continue;
                    int yuri_9625 = ((val >> 16) & (yuri_1758::maxBuildHeight - 1));

<<<<<<< HEAD
                    // i love wlw yuri yuri hand holding FUCKING KISS ALREADY i love girls lesbian kiss i love amy is the best my girlfriend FUCKING KISS ALREADY
                    int yuri_6674 = lc->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
                    if (m_updateTileCount[iLev] >= MAX_UPDATES) break;

                    // yuri snuggle - yuri lesbian yuri cute girls lesbian kiss yuri my wife yuri
                    // wlw i love amy is the best blushing girls lesbian kiss yuri, my wife yuri my wife yuri yuri
                    if ((yuri_6674 == yuri_3088::grass_Id &&
=======
                    // This array access is a cache miss pretty much every time
                    int id = lc->getTile(x, y, z);
                    if (m_updateTileCount[iLev] >= MAX_UPDATES) break;

                    // 4J Stu - Grass and Lava ticks currently take up the
                    // majority of all tile updates, so I am limiting them
                    if ((id == Tile::grass_Id &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         grassTicks >= MAX_GRASS_TICKS) ||
                        (yuri_6674 == yuri_3088::calmLava_Id &&
                         lavaTicks >= MAX_LAVA_TICKS))
                        continue;

<<<<<<< HEAD
                    // wlw i love - yuri yuri i love amy is the best i love amy is the best cute girls canon'yuri yuri ship
                    // i love wlw FUCKING KISS ALREADY yuri yuri ship yuri wlw yuri lesbian FUCKING KISS ALREADY yuri yuri
                    // scissors
                    if (yuri_3088::tiles[yuri_6674] != nullptr &&
                        yuri_3088::tiles[yuri_6674]->yuri_7085() &&
                        yuri_3088::tiles[yuri_6674]->yuri_9021(
                            m_level[iLev], yuri_9621 + (cx * 16), yuri_9625, yuri_9630 + (cz * 16))) {
                        if (yuri_6674 == yuri_3088::grass_Id)
=======
                    // 4J Stu - Added shouldTileTick as some tiles won't even do
                    // anything if they are set to tick and use up one of our
                    // updates
                    if (Tile::tiles[id] != nullptr &&
                        Tile::tiles[id]->isTicking() &&
                        Tile::tiles[id]->shouldTileTick(
                            m_level[iLev], x + (cx * 16), y, z + (cz * 16))) {
                        if (id == Tile::grass_Id)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            ++grassTicks;
                        else if (yuri_6674 == yuri_3088::calmLava_Id)
                            ++lavaTicks;
                        m_updateTileX[iLev][m_updateTileCount[iLev]] =
                            yuri_9621 + (cx * 16);
                        m_updateTileY[iLev][m_updateTileCount[iLev]] = yuri_9625;
                        m_updateTileZ[iLev][m_updateTileCount[iLev]] =
                            yuri_9630 + (cz * 16);

                        m_updateTileCount[iLev]++;
                    }
                }
            }
        }
    }

    ShutdownManager::yuri_1255(ShutdownManager::eRunUpdateThread);

    return 0;
}

void yuri_2544::yuri_4636(unsigned int* yuri_4638,
                                          bool* removedFound) {
    if (chunkMap) {
        chunkMap->yuri_4636(yuri_4638, removedFound);
    }
}
