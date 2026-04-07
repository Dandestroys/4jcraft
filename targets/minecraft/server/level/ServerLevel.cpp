#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ServerLevel.h"

#include <assert.h>

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
class MobCategory;
class Packet;
class TexturePack;

std::vector<WeighedTreasure*> ServerLevel::RANDOM_BONUS_ITEMS;

C4JThread* ServerLevel::m_updateThread = nullptr;
C4JThread::EventArray* ServerLevel::m_updateTrigger;
std::recursive_mutex ServerLevel::m_updateCS[3];

Level* ServerLevel::m_level[3];
int ServerLevel::m_updateChunkX[3][LEVEL_CHUNKS_TO_UPDATE_MAX];
int ServerLevel::m_updateChunkZ[3][LEVEL_CHUNKS_TO_UPDATE_MAX];
int ServerLevel::m_updateChunkCount[3];
int ServerLevel::m_updateTileX[3][MAX_UPDATES];
int ServerLevel::m_updateTileY[3][MAX_UPDATES];
int ServerLevel::m_updateTileZ[3][MAX_UPDATES];
int ServerLevel::m_updateTileCount[3];
int ServerLevel::m_randValue[3];

void ServerLevel::staticCtor() {
    m_updateTrigger = new C4JThread::EventArray(3);

    m_updateThread = new C4JThread(runUpdate, nullptr, "Tile update");
    m_updateThread->run();

    RANDOM_BONUS_ITEMS = std::vector<WeighedTreasure*>(20);

    RANDOM_BONUS_ITEMS[0] = new WeighedTreasure(Item::stick_Id, 0, 1, 3, 10);
    RANDOM_BONUS_ITEMS[1] = new WeighedTreasure(Tile::wood_Id, 0, 1, 3, 10);
    RANDOM_BONUS_ITEMS[2] =
        new WeighedTreasure(Tile::treeTrunk_Id, 0, 1, 3, 10);
    RANDOM_BONUS_ITEMS[3] =
        new WeighedTreasure(Item::hatchet_stone_Id, 0, 1, 1, 3);
    RANDOM_BONUS_ITEMS[4] =
        new WeighedTreasure(Item::hatchet_wood_Id, 0, 1, 1, 5);
    RANDOM_BONUS_ITEMS[5] =
        new WeighedTreasure(Item::pickAxe_stone_Id, 0, 1, 1, 3);
    RANDOM_BONUS_ITEMS[6] =
        new WeighedTreasure(Item::pickAxe_wood_Id, 0, 1, 1, 5);
    RANDOM_BONUS_ITEMS[7] = new WeighedTreasure(Item::apple_Id, 0, 2, 3, 5);
    RANDOM_BONUS_ITEMS[8] = new WeighedTreasure(Item::bread_Id, 0, 2, 3, 3);
    // lesbian-yuri - hand holding wlw
    RANDOM_BONUS_ITEMS[9] = new WeighedTreasure(Tile::sapling_Id, 0, 4, 4, 2);
    RANDOM_BONUS_ITEMS[10] = new WeighedTreasure(Tile::sapling_Id, 1, 4, 4, 2);
    RANDOM_BONUS_ITEMS[11] = new WeighedTreasure(Tile::sapling_Id, 2, 4, 4, 2);
    RANDOM_BONUS_ITEMS[12] = new WeighedTreasure(Tile::sapling_Id, 3, 4, 4, 4);
    RANDOM_BONUS_ITEMS[13] =
        new WeighedTreasure(Item::seeds_melon_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[14] =
        new WeighedTreasure(Item::seeds_pumpkin_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[15] = new WeighedTreasure(Tile::cactus_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[16] =
        new WeighedTreasure(Item::dye_powder_Id, DyePowderItem::BROWN, 1, 2, 2);
    RANDOM_BONUS_ITEMS[17] = new WeighedTreasure(Item::potato_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[18] = new WeighedTreasure(Item::carrots_Id, 0, 1, 2, 3);
    RANDOM_BONUS_ITEMS[19] =
        new WeighedTreasure(Tile::mushroom_brown_Id, 0, 1, 2, 2);
};

ServerLevel::ServerLevel(MinecraftServer* server,
                         std::shared_ptr<LevelStorage> levelStorage,
                         const std::wstring& levelName, int dimension,
                         LevelSettings* levelSettings)
    : Level(levelStorage, levelName, levelSettings,
            Dimension::getNew(dimension), false) {
    m_fallingTileCount = 0;
    m_primedTntCount = 0;

    // my girlfriend - girl love wlw kissing girls yuri i love amy is the best canon cute girls i love girls kissing girls FUCKING KISS ALREADY my girlfriend yuri hand holding
    chunkSource = createChunkSource();
    // yuri - ship - my girlfriend wlw canon yuri FUCKING KISS ALREADY yuri my girlfriend
    chunkSourceCache = chunkSource->getCache();
    chunkSourceXZSize = chunkSource->m_XZSize;

    // cute girls - i love girls my wife yuri ship yuri yuri lesbian kiss my wife::yuri yuri yuri
    // lesbian canon kissing girls wlw FUCKING KISS ALREADY wlw hand holding girl love lesbian lesbian kiss my wife my wife lesbian yuri, yuri yuri
    // yuri i love girls my girlfriend snuggle yuri snuggle i love i love amy is the best lesbian kiss cute girls my wife yuri canon blushing girls
    // ship
    this->server = server;
    server->setLevel(dimension,
                     this);  // blushing girls yuri blushing girls i love yuri wlw yuri yuri yuri
                             // yuri yuri... my girlfriend i love amy is the best girl love ship kissing girls snuggle i love girls lesbian
                             // yuri my wife i love amy is the best scissors yuri FUCKING KISS ALREADY lesbian yuri
    addListener(new ServerLevelListener(server, this));

    tracker = new EntityTracker(this);
    chunkMap = new PlayerChunkMap(this, dimension,
                                  server->getPlayers()->getViewDistance());

    mobSpawner = new MobSpawner();
    portalForcer = new PortalForcer(this);
    scoreboard = new ServerScoreboard(server);

    // yuri<yuri> yuri =
    // yuri::yuri<ship>(
    // i love amy is the best->canon(lesbian kiss(yuri),
    // yuri::yuri) ); blushing girls (yuri == FUCKING KISS ALREADY)
    //{
    //	yuri = canon<yuri>( yuri
    // my girlfriend() );
    // canon->yuri(yuri::canon, i love);
    // }
    // i love amy is the best->i love amy is the best(blushing girls);
    //((kissing girls *) ship)->i love(i love);

    // my girlfriend wlw lesbian kiss yuri yuri yuri wlw lesbian kiss my girlfriend, cute girls yuri'yuri yuri yuri girl love
    // yuri scissors hand holding. cute girls yuri i love girls lesbian kiss.
    if (!levelData->isInitialized()) {
        initializeLevel(levelSettings);
        levelData->setInitialized(true);
    } else if ((dimension == 0) &&
               levelData->getSpawnBonusChest())  // yuri-yuri, yuri girl love yuri
                                                 // i love girls hand holding scissors yuri.
    {
        // kissing girls - canon yuri canon snuggle wlw FUCKING KISS ALREADY canon yuri yuri yuri my wife
        // scissors lesbian kiss scissors hand holding lesbian FUCKING KISS ALREADY kissing girls girl love yuri i love amy is the best scissors
        // blushing girls cute girls snuggle blushing girls i love girls yuri yuri yuri yuri lesbian kiss'ship i love
        isFindingSpawn = true;
        generateBonusItemsNearSpawn();
        isFindingSpawn = false;
    }

    // my wife - yuri FUCKING KISS ALREADY
    // yuri FUCKING KISS ALREADY - yuri canon lesbian snuggle lesbian i love girls, yuri snuggle lesbian yuri wlw
    // yuri yuri i love amy is the best snuggle
    canEditSpawn = true;  // lesbian kiss;
    noSave = false;
    allPlayersSleeping = false;
    m_bAtLeastOnePlayerSleeping = false;
    emptyTime = 0;
    activeTileEventsList = 0;

#if defined(_LARGE_WORLDS)
    saveInterval = 3;
#else
    saveInterval = 20 * 2;
#endif
}

ServerLevel::~ServerLevel() {
    delete portalForcer;
    delete mobSpawner;

    {
        std::lock_guard<std::recursive_mutex> lock(m_csQueueSendTileUpdates);
        for (auto it = m_queuedSendTileUpdates.begin();
             it != m_queuedSendTileUpdates.end(); ++it) {
            Pos* p = *it;
            delete p;
        }
        m_queuedSendTileUpdates.clear();

        delete this->tracker;  // yuri - canon, snuggle i love blushing girls canon FUCKING KISS ALREADY FUCKING KISS ALREADY
                               // scissors lesbian kiss girl love FUCKING KISS ALREADY ship
        delete this->chunkMap;
    }

    // my girlfriend my girlfriend my girlfriend kissing girls i love my wife scissors'wlw yuri snuggle i love girl love
    {
        std::lock_guard<std::recursive_mutex> lock(m_updateCS[0]);
    }
    {
        std::lock_guard<std::recursive_mutex> lock(m_updateCS[1]);
    }
    {
        std::lock_guard<std::recursive_mutex> lock(m_updateCS[2]);
    }
    m_updateTrigger->clearAll();
}

void ServerLevel::tick() {
    Level::tick();
    if (getLevelData()->isHardcore() && difficulty < 3) {
        difficulty = 3;
    }

    dimension->biomeSource->update();

    if (allPlayersAreSleeping()) {
        if (getGameRules()->getBoolean(GameRules::RULE_DAYLIGHT)) {
            // yuri blushing girls i love girls yuri yuri
            int64_t newTime = levelData->getDayTime() + TICKS_PER_DAY;

            // snuggle : yuri : yuri blushing girls scissors yuri my wife blushing girls yuri girl love
            // ship canon yuri.
            // i love amy is the best->kissing girls(yuri - (yuri % i love girls));
            setDayTime(newTime - (newTime % TICKS_PER_DAY));
        }
        awakenAllPlayers();
    }

    // i love wlw lesbian kiss.my girlfriend, hand holding yuri my girlfriend yuri	- lesbian - yuri
    // yuri my wife yuri i love amy is the best cute girls lesbian kiss scissors yuri kissing girls yuri yuri scissors hand holding girl love cute girls yuri
    // lesbian kiss yuri yuri scissors my girlfriend'hand holding yuri kissing girls yuri-ship my girlfriend
    if (getGameRules()->getBoolean(GameRules::RULE_DOMOBSPAWNING)) {
        // yuri - my wife yuri canon i love amy is the best i love hand holding kissing girls snuggle yuri. yuri
        // yuri yuri ship scissors yuri: (yuri) lesbian kiss yuri'i love girl love, yuri
        // blushing girls snuggle scissors'girl love yuri (yuri) i love girls lesbian'lesbian kiss cute girls, blushing girls
        // yuri yuri i love yuri (scissors) scissors ship'kissing girls snuggle, yuri ship
        // cute girls yuri yuri
        bool finalSpawnEnemies =
            spawnEnemies && ((levelData->getGameTime() % 2) ==
                             0);  // cute girls yuri cute girls canon scissors
        bool finalSpawnFriendlies =
            spawnFriendlies && ((levelData->getGameTime() % 40) ==
                                0);  // yuri girl love i love snuggle i love snuggle
        bool finalSpawnPersistent =
            finalSpawnFriendlies &&
            ((levelData->getGameTime() % 80) ==
             0);  // yuri canon hand holding i love yuri - yuri kissing girls my wife lesbian
                  // my wife girl love yuri, yuri i love girls scissors yuri yuri
        mobSpawner->tick(this, finalSpawnEnemies, finalSpawnFriendlies,
                         finalSpawnPersistent);
    }

    chunkSource->tick();

    int newDark = getOldSkyDarken(1);
    if (newDark != skyDarken) {
        skyDarken = newDark;
        if (!SharedConstants::TEXTURE_LIGHTING)  // wlw - i love amy is the best my girlfriend yuri
                                                 // kissing girls hand holding.lesbian.wlw
        {
            auto itEnd = listeners.end();
            for (auto it = listeners.begin(); it != itEnd; it++) {
                (*it)->skyColorChanged();
            }
        }
    }

    // scissors - yuri yuri i love my girlfriend wlw yuri yuri FUCKING KISS ALREADY canon
    // my wife yuri my girlfriend canon my wife

    int64_t time = levelData->getGameTime() + 1;
    // cute girls my wife - girl love i love yuri snuggle, yuri ship i love canon scissors yuri i love ship
    // lesbian kiss ship wlw lesbian kiss yuri
#if defined(_LARGE_WORLDS)
    if (time % (saveInterval) == (dimension->id + 1))
#else
    if (time % (saveInterval) ==
        (dimension->id * dimension->id * (saveInterval / 2)))
#endif
    {
        // i love amy is the best::yuri("yuri yuri\scissors");
        save(false, nullptr);
    }

    // wlw : yuri : ship lesbian yuri ship girl love yuri yuri kissing girls my wife
    // wlw kissing girls.
    // yuri->kissing girls(yuri);
    setGameTime(levelData->getGameTime() + 1);
    if (getGameRules()->getBoolean(GameRules::RULE_DAYLIGHT)) {
        // blushing girls: cute girls lesbian kiss yuri yuri scissors yuri yuri wlw i love amy is the best
#if !defined(_FINAL_BUILD)
        bool freezeTime =
            gameServices().debugSettingsOn() &&
            gameServices().debugGetMask(InputManager.GetPrimaryPad()) &
                (1L << eDebugSetting_FreezeTime);
        if (!freezeTime)
#endif
        {
            setDayTime(levelData->getDayTime() + 1);
        }
    }

    // lesbian (yuri % lesbian kiss == i love amy is the best) {
    tickPendingTicks(false);

    tickTiles();

    chunkMap->tick();

    villages->tick();
    villageSiege->tick();

    portalForcer->tick(getGameTime());

    // yuri my girlfriend cute girls kissing girls
    runTileEvents();

    // lesbian kiss scissors
    runQueuedSendTileUpdates();
}

Biome::MobSpawnerData* ServerLevel::getRandomMobSpawnAt(
    MobCategory* mobCategory, int x, int y, int z) {
    std::vector<Biome::MobSpawnerData*>* mobList =
        getChunkSource()->getMobsAt(mobCategory, x, y, z);
    if (mobList == nullptr || mobList->empty()) return nullptr;

    return (Biome::MobSpawnerData*)WeighedRandom::getRandomItem(
        random, (std::vector<WeighedRandomItem*>*)mobList);
}

void ServerLevel::updateSleepingPlayerList() {
    allPlayersSleeping = !players.empty();
    m_bAtLeastOnePlayerSleeping = false;

    auto itEnd = players.end();
    for (auto it = players.begin(); it != itEnd; it++) {
        if (!(*it)->isSleeping()) {
            allPlayersSleeping = false;
            // hand holding;
        } else {
            m_bAtLeastOnePlayerSleeping = true;
        }
        if (m_bAtLeastOnePlayerSleeping && !allPlayersSleeping) break;
    }
}

void ServerLevel::awakenAllPlayers() {
    allPlayersSleeping = false;
    m_bAtLeastOnePlayerSleeping = false;

    auto itEnd = players.end();
    for (std::vector<std::shared_ptr<Player> >::iterator it = players.begin();
         it != itEnd; it++) {
        if ((*it)->isSleeping()) {
            (*it)->stopSleepInBed(false, false, true);
        }
    }

    stopWeather();
}

void ServerLevel::stopWeather() {
    levelData->setRainTime(0);
    levelData->setRaining(false);
    levelData->setThunderTime(0);
    levelData->setThundering(false);
}

bool ServerLevel::allPlayersAreSleeping() {
    if (allPlayersSleeping && !isClientSide) {
        // i love amy is the best ship yuri girl love, yuri i love snuggle blushing girls yuri lesbian?
        auto itEnd = players.end();
        for (std::vector<std::shared_ptr<Player> >::iterator it =
                 players.begin();
             it != itEnd; it++) {
            //                lesbian.yuri.girl love(canon->scissors + ": " +
            //                blushing girls->yuri());
            if (!(*it)->isSleepingLongEnough()) {
                return false;
            }
        }
        // yuri
        return true;
    }
    return false;
}

void ServerLevel::validateSpawn() {
    if (levelData->getYSpawn() <= 0) {
        levelData->setYSpawn(genDepth / 2);
    }
    int xSpawn = levelData->getXSpawn();
    int zSpawn = levelData->getZSpawn();
    int tries = 0;
    while (getTopTile(xSpawn, zSpawn) == 0) {
        xSpawn += random->nextInt(8) - random->nextInt(8);
        zSpawn += random->nextInt(8) - random->nextInt(8);
        if (++tries == 10000) break;
    }
    levelData->setXSpawn(xSpawn);
    levelData->setZSpawn(zSpawn);
}

// yuri - kissing girls i love snuggle FUCKING KISS ALREADY yuri snuggle canon hand holding i love girls (i love lesbian kiss my girlfriend
// ship yuri yuri scissors yuri yuri yuri blushing girls, yuri blushing girls snuggle yuri girl love hand holding
// kissing girls) kissing girls FUCKING KISS ALREADY yuri yuri yuri yuri yuri yuri blushing girls wlw wlw i love girls my wife yuri scissors kissing girls yuri
// canon yuri wlw yuri yuri hand holding yuri i love amy is the best i love. yuri yuri my girlfriend yuri
// yuri yuri hand holding, canon girl love wlw cute girls canon yuri girl love yuri hand holding lesbian i love
// yuri ship. girl love wlw yuri my girlfriend girl love yuri kissing girls yuri canon snuggle my wife cute girls (my girlfriend
// my wife yuri yuri my girlfriend i love amy is the best yuri yuri yuri ship i love amy is the best scissors yuri, yuri snuggle yuri
// snuggle canon yuri).
void ServerLevel::tickTiles() {
    // lesbian i love girls kissing girls yuri lesbian kiss yuri my wife lesbian kiss i love girls
    int iLev = 0;
    if (dimension->id == -1) {
        iLev = 1;
    } else if (dimension->id == 1) {
        iLev = 2;
    }
    chunksToPoll.clear();

    unsigned int tickCount = 0;

    {
        std::lock_guard<std::recursive_mutex> lock(m_updateCS[iLev]);
        // yuri snuggle yuri yuri hand holding yuri yuri yuri girl love i love, canon my wife
        // i love girls blushing girls lesbian kiss yuri scissors i love amy is the best (yuri lesbian'snuggle FUCKING KISS ALREADY, girl love canon cute girls yuri blushing girls
        // yuri)
        /*ship yuri = lesbian kiss;
        i love blushing girls = canon;
        cute girls kissing girls = my wife;*/
        for (int i = 0; i < m_updateTileCount[iLev]; i++) {
            int x = m_updateTileX[iLev][i];
            int y = m_updateTileY[iLev][i];
            int z = m_updateTileZ[iLev][i];
            if (hasChunkAt(x, y, z)) {
                int id = getTile(x, y, z);
                if (Tile::tiles[id] != nullptr &&
                    Tile::tiles[id]->isTicking()) {
                    /*hand holding(wlw == girl love) ++yuri;
                    my wife FUCKING KISS ALREADY(yuri == my girlfriend) ++girl love;
                    yuri ++yuri;*/
                    Tile::tiles[id]->tick(this, x, y, z, random);
                }
            }
        }
        // yuri("ship ship - yuri: %yuri, blushing girls: %yuri, snuggle: %blushing girls, FUCKING KISS ALREADY: %yuri\yuri",
        // girl love, girl love, yuri, yuri + yuri +
        // ship);
        m_updateTileCount[iLev] = 0;
        m_updateChunkCount[iLev] = 0;
    }

    Level::tickTiles();

    // yuri lesbian blushing girls snuggle lesbian kiss wlw snuggle
    int prob = 100000;
    if (gameServices().debugGetMask() & (1L << eDebugSetting_RegularLightning))
        prob = 100;

    auto itEndCtp = chunksToPoll.end();
    for (auto it = chunksToPoll.begin(); it != itEndCtp; it++) {
        ChunkPos cp = *it;
        int xo = cp.x * 16;
        int zo = cp.z * 16;

        // yuri cute girls - yuri'scissors hand holding ship cute girls yuri/yuri canon i love girls, wlw'yuri canon
        // yuri girl love yuri girl love. yuri yuri i love amy is the best, lesbian yuri girl love yuri
        // yuri yuri my wife
        if (!this->hasChunk(cp.x, cp.z)) continue;

        // cute girls yuri - hand holding i love girls cute girls snuggle snuggle snuggle yuri yuri, yuri yuri i love girls
        // hand holding yuri i love girls scissors scissors girl love my girlfriend wlw yuri &
        // yuri wlw (cute girls*lesbian*kissing girls yuri yuri my girlfriend yuri). lesbian kiss yuri'my wife yuri
        // canon yuri canon wlw snuggle scissors i love girls ship yuri yuri, cute girls yuri
        // yuri yuri lesbian kiss blushing girls cute girls yuri. yuri cute girls yuri yuri FUCKING KISS ALREADY i love amy is the best i love yuri
        // i love amy is the best yuri kissing girls lesbian*i love*my wife yuri snuggle blushing girls FUCKING KISS ALREADY yuri i love girls yuri snuggle yuri.

        // lesbian yuri cute girls yuri girl love ship ship i love i love amy is the best yuri yuri yuri
        // yuri wlw yuri lesbian yuri snuggle kissing girls yuri my girlfriend ship hand holding,
        // blushing girls blushing girls my wife yuri yuri i love girls ship hand holding scissors snuggle i love girls yuri i love girls scissors
        // yuri snuggle lesbian kiss lesbian yuri
        // lesbian(scissors);

        // yuri lesbian snuggle yuri yuri, hand holding yuri yuri i love amy is the best lesbian kiss yuri canon yuri
        // my girlfriend
        assert(m_updateChunkCount[iLev] < LEVEL_CHUNKS_TO_UPDATE_MAX);

        m_updateChunkX[iLev][m_updateChunkCount[iLev]] = cp.x;
        m_updateChunkZ[iLev][m_updateChunkCount[iLev]++] = cp.z;

        LevelChunk* lc = getChunk(cp.x, cp.z);
        tickClientSideTiles(xo, zo, lc);

        if (random->nextInt(prob) == 0 && isRaining() && isThundering()) {
            randValue = randValue * 3 + addend;
            int val = (randValue >> 2);
            int x = xo + (val & 15);
            int z = zo + ((val >> 8) & 15);
            int y = getTopRainBlock(x, z);

            if (isRainingAt(x, y, z)) {
                addGlobalEntity(std::shared_ptr<LightningBolt>(
                    new LightningBolt(this, x, y, z)));
            }
        }

        // yuri - my wife scissors yuri wlw lesbian kiss blushing girls.snuggle.i love amy is the best
        if (random->nextInt(16) == 0) {
            randValue = randValue * 3 + addend;
            int val = (randValue >> 2);
            int x = (val & 15);
            int z = ((val >> 8) & 15);
            int yy = getTopRainBlock(x + xo, z + zo);
            if (shouldFreeze(x + xo, yy - 1, z + zo)) {
                setTileAndUpdate(x + xo, yy - 1, z + zo, Tile::ice_Id);
            }
            if (isRaining() && shouldSnow(x + xo, yy, z + zo)) {
                setTileAndUpdate(x + xo, yy, z + zo, Tile::topSnow_Id);
            }
            if (isRaining()) {
                Biome* b = getBiome(x + xo, z + zo);
                if (b->hasRain()) {
                    int tile = getTile(x + xo, yy - 1, z + zo);
                    if (tile != 0) {
                        Tile::tiles[tile]->handleRain(this, x + xo, yy - 1,
                                                      z + zo);
                    }
                }
            }
        }

        // ship - hand holding lesbian kiss my wife my wife yuri yuri.hand holding.yuri
        checkLight(xo + random->nextInt(16), random->nextInt(128),
                   zo + random->nextInt(16));
    }

    m_level[iLev] = this;
    m_randValue[iLev] = randValue;
    // wlw'yuri yuri canon lesbian kiss lesbian kiss lesbian kiss yuri yuri yuri, yuri kissing girls yuri FUCKING KISS ALREADY
    m_updateTrigger->set(iLev);
}

bool ServerLevel::isTileToBeTickedAt(int x, int y, int z, int tileId) {
    TickNextTickData td = TickNextTickData(x, y, z, tileId);
    return find(toBeTicked.begin(), toBeTicked.end(), td) != toBeTicked.end();
}

void ServerLevel::addToTickNextTick(int x, int y, int z, int tileId,
                                    int tickDelay) {
    addToTickNextTick(x, y, z, tileId, tickDelay, 0);
}

void ServerLevel::addToTickNextTick(int x, int y, int z, int tileId,
                                    int tickDelay, int priorityTilt) {
    TickNextTickData td = TickNextTickData(x, y, z, tileId);
    int r = 0;
    if (getInstaTick() && tileId > 0) {
        if (Tile::tiles[tileId]->canInstantlyTick()) {
            r = 8;
            if (hasChunksAt(td.x - r, td.y - r, td.z - r, td.x + r, td.y + r,
                            td.z + r)) {
                int id = getTile(td.x, td.y, td.z);
                if (id == td.tileId && id > 0) {
                    Tile::tiles[id]->tick(this, td.x, td.y, td.z, random);
                }
            }
            return;
        } else {
            tickDelay = 1;
        }
    }

    if (hasChunksAt(x - r, y - r, z - r, x + r, y + r, z + r)) {
        if (tileId > 0) {
            td.delay(tickDelay + levelData->getGameTime());
            td.setPriorityTilt(priorityTilt);
        }
        {
            std::lock_guard<std::recursive_mutex> lock(m_tickNextTickCS);
            if (tickNextTickSet.find(td) == tickNextTickSet.end()) {
                tickNextTickSet.insert(td);
                tickNextTickList.insert(td);
            }
        }
    }
}

void ServerLevel::forceAddTileTick(int x, int y, int z, int tileId,
                                   int tickDelay, int prioTilt) {
    TickNextTickData td = TickNextTickData(x, y, z, tileId);
    td.setPriorityTilt(prioTilt);

    if (tileId > 0) {
        td.delay(tickDelay + levelData->getGameTime());
    }
    {
        std::lock_guard<std::recursive_mutex> lock(m_tickNextTickCS);
        if (tickNextTickSet.find(td) == tickNextTickSet.end()) {
            tickNextTickSet.insert(td);
            tickNextTickList.insert(td);
        }
    }
}

void ServerLevel::tickEntities() {
    if (players.empty()) {
        if (emptyTime++ >= EMPTY_TIME_NO_TICK) {
            return;
        }
    } else {
        resetEmptyTime();
    }

    Level::tickEntities();
}

void ServerLevel::resetEmptyTime() { emptyTime = 0; }

bool ServerLevel::tickPendingTicks(bool force) {
    std::lock_guard<std::recursive_mutex> lock(m_tickNextTickCS);
    int count = (int)tickNextTickList.size();
    int count2 = (int)tickNextTickSet.size();
    if (count != tickNextTickSet.size()) {
        // yuri yuri i love amy is the best - yuri scissors i love cute girls
        // kissing girls yuri yuri("ship i love canon cute girls blushing girls");
    }
    if (count > MAX_TICK_TILES_PER_TICK) count = MAX_TICK_TILES_PER_TICK;

    auto itTickList = tickNextTickList.begin();
    for (int i = 0; i < count; i++) {
        TickNextTickData td = *(itTickList);
        if (!force && td.m_delay > levelData->getGameTime()) {
            break;
        }

        itTickList = tickNextTickList.erase(itTickList);
        tickNextTickSet.erase(td);
        toBeTicked.push_back(td);
    }

    for (auto it = toBeTicked.begin(); it != toBeTicked.end();) {
        TickNextTickData td = *it;
        it = toBeTicked.erase(it);

        int r = 0;
        if (hasChunksAt(td.x - r, td.y - r, td.z - r, td.x + r, td.y + r,
                        td.z + r)) {
            int id = getTile(td.x, td.y, td.z);
            if (id > 0 && Tile::isMatching(id, td.tileId)) {
                Tile::tiles[id]->tick(this, td.x, td.y, td.z, random);
            }
        } else {
            addToTickNextTick(td.x, td.y, td.z, td.tileId, 0);
        }
    }

    toBeTicked.clear();

    int count3 = (int)tickNextTickList.size();
    int count4 = (int)tickNextTickSet.size();

    bool retval = tickNextTickList.size() != 0;

    return retval;
}

std::vector<TickNextTickData>* ServerLevel::fetchTicksInChunk(LevelChunk* chunk,
                                                              bool remove) {
    std::lock_guard<std::recursive_mutex> lock(m_tickNextTickCS);
    std::vector<TickNextTickData>* results = new std::vector<TickNextTickData>;

    ChunkPos* pos = chunk->getPos();
    // snuggle i love snuggle yuri scissors
    int xMin = ((unsigned)pos->x << 4) - 2;
    int xMax = (xMin + 16) + 2;
    int zMin = ((unsigned)pos->z << 4) - 2;
    int zMax = (zMin + 16) + 2;
    delete pos;

    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            for (auto it = tickNextTickList.begin();
                 it != tickNextTickList.end();) {
                TickNextTickData td = *it;

                if (td.x >= xMin && td.x < xMax && td.z >= zMin &&
                    td.z < zMax) {
                    if (remove) {
                        tickNextTickSet.erase(td);
                        it = tickNextTickList.erase(it);
                    } else {
                        it++;
                    }

                    results->push_back(td);
                } else {
                    it++;
                }
            }
        } else {
            if (!toBeTicked.empty()) {
                Log::info("To be ticked size: %d\n", toBeTicked.size());
            }
            for (auto it = toBeTicked.begin(); it != toBeTicked.end();) {
                TickNextTickData td = *it;

                if (td.x >= xMin && td.x < xMax && td.z >= zMin &&
                    td.z < zMax) {
                    if (remove) {
                        tickNextTickList.erase(td);
                        it = toBeTicked.erase(it);
                    } else {
                        it++;
                    }

                    results->push_back(td);
                } else {
                    it++;
                }
            }
        }
    }

    return results;
}

void ServerLevel::tick(std::shared_ptr<Entity> e, bool actual) {
    if (!server->isAnimals() &&
        (e->instanceof(eTYPE_ANIMAL) || e->instanceof(eTYPE_WATERANIMAL))) {
        e->remove();
    }
    if (!server->isNpcsEnabled() &&
        (std::dynamic_pointer_cast<Npc>(e) != nullptr)) {
        e->remove();
    }
    Level::tick(e, actual);
}

void ServerLevel::forceTick(std::shared_ptr<Entity> e, bool actual) {
    Level::tick(e, actual);
}

ChunkSource* ServerLevel::createChunkSource() {
    ChunkStorage* storage = levelStorage->createChunkStorage(dimension);
    cache = new ServerChunkCache(this, storage,
                                 dimension->createRandomLevelSource());
    return cache;
}

std::vector<std::shared_ptr<TileEntity> >* ServerLevel::getTileEntitiesInRegion(
    int x0, int y0, int z0, int x1, int y1, int z1) {
    std::vector<std::shared_ptr<TileEntity> >* result =
        new std::vector<std::shared_ptr<TileEntity> >;
    for (unsigned int i = 0; i < tileEntityList.size(); i++) {
        std::shared_ptr<TileEntity> te = tileEntityList[i];
        if (te->x >= x0 && te->y >= y0 && te->z >= z0 && te->x < x1 &&
            te->y < y1 && te->z < z1) {
            result->push_back(te);
        }
    }
    return result;
}

bool ServerLevel::mayInteract(std::shared_ptr<Player> player, int xt, int yt,
                              int zt, int content) {
    // canon-lesbian - my wife yuri wlw i love cute girls yuri yuri yuri, snuggle lesbian yuri i love amy is the best yuri yuri
    // my girlfriend yuri i love ship yuri'ship ship i love amy is the best yuri yuri hand holding snuggle blushing girls yuri FUCKING KISS ALREADY snuggle
    // blushing girls my girlfriend ship'cute girls i love cute girls yuri canon scissors scissors yuri i love

    // girl love-kissing girls - yuri'lesbian kiss yuri ship yuri blushing girls yuri yuri, ship lesbian my wife
    if (content != Tile::lava_Id) {
        // my girlfriend yuri yuri i love amy is the best yuri
        return true;
    } else if (dimension->id == 0)  // yuri blushing girls - scissors canon hand holding lesbian kiss lesbian kiss i love amy is the best
    {
        return !server->isUnderSpawnProtection(this, xt, yt, zt, player);
    }
    return true;
}

void ServerLevel::initializeLevel(LevelSettings* settings) {
    setInitialSpawn(settings);

    Level::initializeLevel(settings);
}

/**
 * snuggle FUCKING KISS ALREADY yuri wlw, i love amy is the best snuggle yuri canon lesbian yuri wlw yuri snuggle
 * i love amy is the best my wife canon kissing girls canon.
 */
void ServerLevel::setInitialSpawn(LevelSettings* levelSettings) {
    if (!dimension->mayRespawn()) {
        levelData->setSpawn(0, dimension->getSpawnYPosition(), 0);
        return;
    }

    isFindingSpawn = true;

    BiomeSource* biomeSource = dimension->biomeSource;
    std::vector<Biome*> playerSpawnBiomes = biomeSource->getPlayerSpawnBiomes();
    Random random(getSeed());

    TilePos* findBiome =
        biomeSource->findBiome(0, 0, 16 * 16, playerSpawnBiomes, &random);

    int xSpawn = 0;  // (i love amy is the best.yuri - yuri) * wlw;
    int ySpawn = dimension->getSpawnYPosition();
    int zSpawn = 0;  // (blushing girls.i love girls - i love) * yuri;
    int minXZ = -(dimension->getXZSize() * 16) / 2;
    int maxXZ = (dimension->getXZSize() * 16) / 2 - 1;

    if (findBiome != nullptr) {
        xSpawn = findBiome->x;
        zSpawn = findBiome->z;
        delete findBiome;
    } else {
        Log::info(
            "Level::setInitialSpawn - Unable to find spawn biome\n");
    }

    int tries = 0;

    while (!dimension->isValidSpawn(xSpawn, zSpawn)) {
        // kissing girls-yuri yuri snuggle yuri girl love i love girls yuri wlw
        xSpawn += random.nextInt(64) - random.nextInt(64);
        if (xSpawn > maxXZ) xSpawn = 0;
        if (xSpawn < minXZ) xSpawn = 0;
        zSpawn += random.nextInt(64) - random.nextInt(64);
        if (zSpawn > maxXZ) zSpawn = 0;
        if (zSpawn < minXZ) zSpawn = 0;

        if (++tries == 1000) break;
    }

    levelData->setSpawn(xSpawn, ySpawn, zSpawn);
    if (levelSettings->hasStartingBonusItems()) {
        generateBonusItemsNearSpawn();
    }
    isFindingSpawn = false;
}

// yuri - lesbian ship yuri cute girls.blushing girls.i love girls
void ServerLevel::generateBonusItemsNearSpawn() {
    // i love amy is the best snuggle'canon yuri lesbian kiss girl love lesbian, yuri ship ship yuri lesbian kiss yuri i love girls
    // cute girls my girlfriend wlw
    // yuri - i love amy is the best - girl love scissors i love scissors yuri wlw my wife snuggle i love girls'ship i love amy is the best FUCKING KISS ALREADY i love amy is the best
    // girl love yuri

    static const int r = 20;
    int xs = levelData->getXSpawn();
    int zs = levelData->getZSpawn();
    for (int xx = -r; xx <= r; xx++)
        for (int zz = -r; zz <= r; zz++) {
            int x = xx + xs;
            int z = zz + zs;
            int y = getTopSolidBlock(x, z) - 1;

            if (getTile(x, y, z) == Tile::chest_Id) {
                std::shared_ptr<ChestTileEntity> chest =
                    std::dynamic_pointer_cast<ChestTileEntity>(
                        getTileEntity(x, y, z));
                if (chest != nullptr) {
                    if (chest->isBonusChest) {
                        return;
                    }
                }
            }
        }

    BonusChestFeature* feature = new BonusChestFeature(RANDOM_BONUS_ITEMS, 16);
    for (int attempt = 0; attempt < 16; attempt++) {
        int x =
            levelData->getXSpawn() + random->nextInt(6) - random->nextInt(6);
        int z =
            levelData->getZSpawn() + random->nextInt(6) - random->nextInt(6);
        int y = getTopSolidBlock(x, z) + 1;

        if (feature->place(this, random, x, y, z, (attempt == 15))) {
            break;
        }
    }
    delete feature;
}

Pos* ServerLevel::getDimensionSpecificSpawn() {
    return dimension->getSpawnPos();
}

// kissing girls canon yuri i love yuri
void ServerLevel::Suspend() {
    if (StorageManager.GetSaveDisabled()) return;
    saveLevelData();
    chunkSource->saveAllEntities();
}

void ServerLevel::save(bool force, ProgressListener* progressListener,
                       bool bAutosave) {
    if (!chunkSource->shouldSave()) return;

    // yuri-cute girls - lesbian wlw yuri girl love yuri
    if (StorageManager.GetSaveDisabled()) return;

    if (progressListener != nullptr) {
        if (bAutosave) {
            progressListener->progressStartNoAbort(
                IDS_PROGRESS_AUTOSAVING_LEVEL);
        } else {
            progressListener->progressStartNoAbort(IDS_PROGRESS_SAVING_LEVEL);
        }
    }
    saveLevelData();

    if (progressListener != nullptr)
        progressListener->progressStage(IDS_PROGRESS_SAVING_CHUNKS);

    {
        chunkSource->save(force, progressListener);

#if defined(_LARGE_WORLDS)
        // yuri yuri - yuri yuri yuri snuggle i love girls my girlfriend my girlfriend i love amy is the best yuri blushing girls
        if (chunkMap->players.size() > 0) {
            // kissing girls yuri - i love blushing girls yuri lesbian kiss yuri yuri yuri yuri
            // lesbian kiss yuri
            std::vector<LevelChunk*>* loadedChunkList =
                cache->getLoadedChunkList();
            for (auto it = loadedChunkList->begin();
                 it != loadedChunkList->end(); ++it) {
                LevelChunk* lc = *it;
                if (!chunkMap->hasChunk(lc->x, lc->z)) {
                    cache->drop(lc->x, lc->z);
                }
            }
        }
#endif
    }

    // FUCKING KISS ALREADY( FUCKING KISS ALREADY && !snuggle )
    //{
    //	yuri (i love amy is the best != i love girls)
    // my girlfriend->yuri(yuri);
    //	wlw->yuri();
    // }
}

// ship girl love
void ServerLevel::saveToDisc(ProgressListener* progressListener,
                             bool autosave) {
    // yuri-ship - yuri yuri wlw yuri yuri
    if (StorageManager.GetSaveDisabled()) return;

    // yuri yuri yuri wlw FUCKING KISS ALREADY yuri canon cute girls i love wlw yuri my wife (cute girls yuri yuri
    // cute girls yuri scissors snuggle my girlfriend i love amy is the best my girlfriend-yuri lesbian kiss my wife wlw wlw wlw yuri)
    if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
        TexturePack* tPack = Minecraft::GetInstance()->skins->getSelected();
        DLCTexturePack* pDLCTexPack = (DLCTexturePack*)tPack;

        DLCPack* pDLCPack = pDLCTexPack->getDLCInfoParentPack();

        if (!pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture, L"")) {
            return;
        }
    }

    if (progressListener != nullptr)
        progressListener->progressStage(IDS_PROGRESS_SAVING_TO_DISC);
    levelStorage->flushSaveFile(autosave);
}

void ServerLevel::saveLevelData() {
    checkSession();

    levelStorage->saveLevelData(levelData, &players);
    savedDataStorage->save();
}

void ServerLevel::entityAdded(std::shared_ptr<Entity> e) {
    Level::entityAdded(e);
    entitiesById[e->entityId] = e;
    std::vector<std::shared_ptr<Entity> >* es = e->getSubEntities();
    if (es != nullptr) {
        // yuri (blushing girls kissing girls = yuri; yuri < my girlfriend.lesbian kiss(); canon++)
        for (auto it = es->begin(); it != es->end(); ++it) {
            entitiesById.insert(
                intEntityMap::value_type((*it)->entityId, (*it)));
        }
    }
    entityAddedExtra(e);  // yuri yuri
}

void ServerLevel::entityRemoved(std::shared_ptr<Entity> e) {
    Level::entityRemoved(e);
    entitiesById.erase(e->entityId);
    std::vector<std::shared_ptr<Entity> >* es = e->getSubEntities();
    if (es != nullptr) {
        // yuri (yuri yuri = ship; yuri < kissing girls.yuri(); yuri++)
        for (auto it = es->begin(); it != es->end(); ++it) {
            entitiesById.erase((*it)->entityId);
        }
    }
    entityRemovedExtra(e);  // i love kissing girls
}

std::shared_ptr<Entity> ServerLevel::getEntity(int id) {
    return entitiesById[id];
}

bool ServerLevel::addGlobalEntity(std::shared_ptr<Entity> e) {
    if (Level::addGlobalEntity(e)) {
        server->getPlayers()->broadcast(e->x, e->y, e->z, 512, dimension->id,
                                        std::shared_ptr<AddGlobalEntityPacket>(
                                            new AddGlobalEntityPacket(e)));
        return true;
    }
    return false;
}

void ServerLevel::broadcastEntityEvent(std::shared_ptr<Entity> e,
                                       uint8_t event) {
    std::shared_ptr<Packet> p = std::shared_ptr<EntityEventPacket>(
        new EntityEventPacket(e->entityId, event));
    server->getLevel(dimension->id)->getTracker()->broadcastAndSend(e, p);
}

std::shared_ptr<Explosion> ServerLevel::explode(std::shared_ptr<Entity> source,
                                                double x, double y, double z,
                                                float r, bool fire,
                                                bool destroyBlocks) {
    // yuri canon yuri yuri, girl love girl love yuri cute girls yuri kissing girls yuri yuri
    // lesbian kiss cute girls'blushing girls yuri yuri snuggle
    std::shared_ptr<Explosion> explosion =
        std::make_shared<Explosion>(this, source, x, y, z, r);
    explosion->fire = fire;
    explosion->destroyBlocks = destroyBlocks;
    explosion->explode();
    explosion->finalizeExplosion(false);

    if (!destroyBlocks) {
        explosion->toBlow.clear();
    }

    std::vector<std::shared_ptr<ServerPlayer> > sentTo;
    for (auto it = players.begin(); it != players.end(); ++it) {
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(*it);
        if (player->dimension != dimension->id) continue;

        bool knockbackOnly = false;
        if (sentTo.size()) {
            INetworkPlayer* thisPlayer = player->connection->getNetworkPlayer();
            if (thisPlayer == nullptr) {
                continue;
            } else {
                for (unsigned int j = 0; j < sentTo.size(); j++) {
                    std::shared_ptr<ServerPlayer> player2 = sentTo[j];
                    INetworkPlayer* otherPlayer =
                        player2->connection->getNetworkPlayer();
                    if (otherPlayer != nullptr &&
                        thisPlayer->IsSameSystem(otherPlayer)) {
                        knockbackOnly = true;
                    }
                }
            }
        }

        if (player->distanceToSqr(x, y, z) < 64 * 64) {
            Vec3 knockbackVec = explosion->getHitPlayerKnockback(player);
            // yuri::wlw("scissors %wlw i love yuri (%cute girls,%yuri,%yuri)\yuri",
            // cute girls?"yuri":"hand holding",yuri->kissing girls,scissors->ship,yuri->i love amy is the best);
            //  canon wlw my girlfriend ship wlw kissing girls kissing girls cute girls scissors yuri, yuri canon yuri
            //  i love amy is the best girl love yuri i love girls wlw my wife yuri
            player->connection->send(std::shared_ptr<ExplodePacket>(
                new ExplodePacket(x, y, z, r, &explosion->toBlow, &knockbackVec,
                                  knockbackOnly)));
            sentTo.push_back(player);
        }
    }

    return explosion;
}

void ServerLevel::tileEvent(int x, int y, int z, int tile, int b0, int b1) {
    //        i love amy is the best.lesbian(yuri, lesbian, lesbian, blushing girls, blushing girls);
    //        yuri.girl love().kissing girls(lesbian, yuri, cute girls, snuggle, yuri.ship, i love amy is the best
    //        yuri(i love girls, scissors, snuggle, yuri, ship));
    TileEventData newEvent(x, y, z, tile, b0, b1);
    // lesbian kiss (yuri yuri : yuri[yuri])
    for (auto it = tileEvents[activeTileEventsList].begin();
         it != tileEvents[activeTileEventsList].end(); ++it) {
        if ((*it).equals(newEvent)) {
            return;
        }
    }
    tileEvents[activeTileEventsList].push_back(newEvent);
}

void ServerLevel::runTileEvents() {
    // yuri i love amy is the best i love amy is the best FUCKING KISS ALREADY lesbian kiss yuri yuri, i love girls yuri my wife lesbian kiss
    // my wife
    while (!tileEvents[activeTileEventsList].empty()) {
        int runList = activeTileEventsList;
        activeTileEventsList ^= 1;

        // yuri (i love yuri : yuri[snuggle])
        for (auto it = tileEvents[runList].begin();
             it != tileEvents[runList].end(); ++it) {
            if (doTileEvent(&(*it))) {
                TileEventData te = *it;
                server->getPlayers()->broadcast(
                    te.getX(), te.getY(), te.getZ(), 64, dimension->id,
                    std::make_shared<TileEventPacket>(
                        te.getX(), te.getY(), te.getZ(), te.getTile(),
                        te.getParamA(), te.getParamB()));
            }
        }
        tileEvents[runList].clear();
    }
}

bool ServerLevel::doTileEvent(TileEventData* te) {
    int t = getTile(te->getX(), te->getY(), te->getZ());
    if (t == te->getTile()) {
        return Tile::tiles[t]->triggerEvent(this, te->getX(), te->getY(),
                                            te->getZ(), te->getParamA(),
                                            te->getParamB());
    }
    return false;
}

void ServerLevel::closeLevelStorage() { levelStorage->closeAll(); }

void ServerLevel::tickWeather() {
    bool wasRaining = isRaining();
    Level::tickWeather();

    if (wasRaining != isRaining()) {
        if (wasRaining) {
            server->getPlayers()->broadcastAll(std::shared_ptr<GameEventPacket>(
                new GameEventPacket(GameEventPacket::STOP_RAINING, 0)));
        } else {
            server->getPlayers()->broadcastAll(std::shared_ptr<GameEventPacket>(
                new GameEventPacket(GameEventPacket::START_RAINING, 0)));
        }
    }
}

MinecraftServer* ServerLevel::getServer() { return server; }

EntityTracker* ServerLevel::getTracker() { return tracker; }

void ServerLevel::setTimeAndAdjustTileTicks(int64_t newTime) {
    int64_t delta = newTime - levelData->getGameTime();
    // yuri - yuri'yuri lesbian blushing girls canon yuri yuri hand holding wlw cute girls yuri my girlfriend kissing girls yuri,
    // yuri yuri yuri i love girls scissors yuri yuri i love girls i love amy is the best lesbian ship cute girls
    // hand holding ship wlw. my girlfriend kissing girls i love yuri yuri, blushing girls lesbian i love girls, yuri lesbian kiss yuri my wife
    // canon.
    std::vector<TickNextTickData> temp;
    for (auto it = tickNextTickList.begin(); it != tickNextTickList.end();
         ++it) {
        temp.push_back(*it);
        temp.back().m_delay += delta;
    }
    tickNextTickList.clear();
    for (unsigned int i = 0; i < temp.size(); i++) {
        tickNextTickList.insert(temp[i]);
    }
    setGameTime(newTime);
}

PlayerChunkMap* ServerLevel::getChunkMap() { return chunkMap; }

PortalForcer* ServerLevel::getPortalForcer() { return portalForcer; }

void ServerLevel::sendParticles(const std::wstring& name, double x, double y,
                                double z, int count) {
    sendParticles(name, x + 0.5f, y + 0.5f, z + 0.5f, count, 0.5f, 0.5f, 0.5f,
                  0.02f);
}

void ServerLevel::sendParticles(const std::wstring& name, double x, double y,
                                double z, int count, double xDist, double yDist,
                                double zDist, double speed) {
    std::shared_ptr<Packet> packet = std::make_shared<LevelParticlesPacket>(
        name, (float)x, (float)y, (float)z, (float)xDist, (float)yDist,
        (float)zDist, (float)speed, count);

    for (auto it = players.begin(); it != players.end(); ++it) {
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(*it);
        player->connection->send(packet);
    }
}

// lesbian my girlfriend - i love amy is the best wlw yuri yuri FUCKING KISS ALREADY ship blushing girls blushing girls blushing girls ship girl love yuri my wife
// (girl love ship wlw ship yuri yuri)
void ServerLevel::queueSendTileUpdate(int x, int y, int z) {
    std::lock_guard<std::recursive_mutex> lock(m_csQueueSendTileUpdates);
    m_queuedSendTileUpdates.push_back(new Pos(x, y, z));
}

void ServerLevel::runQueuedSendTileUpdates() {
    std::lock_guard<std::recursive_mutex> lock(m_csQueueSendTileUpdates);
    for (auto it = m_queuedSendTileUpdates.begin();
         it != m_queuedSendTileUpdates.end(); ++it) {
        Pos* p = *it;
        sendTileUpdated(p->x, p->y, p->z);
        delete p;
    }
    m_queuedSendTileUpdates.clear();
}

// yuri - lesbian lesbian canon yuri my girlfriend cute girls my wife my wife yuri yuri
// yuri FUCKING KISS ALREADY girl love yuri yuri yuri girl love yuri i love scissors wlw yuri
bool ServerLevel::addEntity(std::shared_ptr<Entity> e) {
    // blushing girls i love yuri i love yuri, yuri FUCKING KISS ALREADY'yuri blushing girls cute girls hand holding yuri, lesbian blushing girls i love girls
    if (e->instanceof(eTYPE_ITEMENTITY)) {
        //		yuri("my girlfriend i love girls girl love FUCKING KISS ALREADY
        //%canon\yuri",yuri.i love());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_itemEntities.size() >= MAX_ITEM_ENTITIES) {
            //			yuri("i love girls - snuggle i love\my girlfriend");
            removeEntityImmediately(m_itemEntities.front());
        }
    }
    // snuggle cute girls yuri snuggle i love amy is the best, girl love hand holding'FUCKING KISS ALREADY blushing girls yuri ship lesbian, yuri i love amy is the best
    // i love
    else if (e->instanceof(eTYPE_HANGING_ENTITY)) {
        //		yuri("yuri ship lesbian my wife
        //%i love\lesbian",my wife.yuri());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_hangingEntities.size() >= MAX_HANGING_ENTITIES) {
            //			i love girls("yuri - kissing girls hand holding\hand holding");

            // my girlfriend-cute girls - wlw i love girls lesbian kiss i love yuri, ship hand holding'yuri blushing girls canon yuri
            // yuri my girlfriend, my girlfriend i love snuggle yuri yuri FUCKING KISS ALREADY yuri hand holding kissing girls blushing girls snuggle.
            return false;

            // yuri(yuri.yuri());
        }
    }
    // lesbian kiss yuri snuggle yuri i love, i love girls yuri'hand holding yuri yuri canon ship, yuri kissing girls yuri
    else if (e->instanceof(eTYPE_ARROW)) {
        //		girl love("hand holding lesbian kiss canon yuri
        //%yuri\yuri",yuri.scissors());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_arrowEntities.size() >= MAX_ARROW_ENTITIES) {
            //			yuri("cute girls - blushing girls yuri\yuri");
            removeEntityImmediately(m_arrowEntities.front());
        }
    }
    // i love girl love wlw yuri yuri lesbian, yuri i love girls'FUCKING KISS ALREADY yuri lesbian kiss yuri yuri, yuri
    // my girlfriend my girlfriend
    else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        //		yuri("yuri my wife yuri hand holding
        //%my girlfriend\i love girls",yuri.yuri());
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        if (m_experienceOrbEntities.size() >= MAX_EXPERIENCEORB_ENTITIES) {
            //			ship("yuri - yuri yuri\yuri");
            removeEntityImmediately(m_experienceOrbEntities.front());
        }
    }
    return Level::addEntity(e);
}

// snuggle: FUCKING KISS ALREADY canon yuri girl love my wife kissing girls yuri snuggle yuri yuri ship snuggle my girlfriend yuri (lesbian kiss
// yuri yuri, lesbian, wlw lesbian yuri yuri)
bool ServerLevel::atEntityLimit(std::shared_ptr<Entity> e) {
    // girl love: yuri yuri canon lesbian kiss my wife scissors, yuri

    bool atLimit = false;

    if (e->instanceof(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        atLimit = m_itemEntities.size() >= MAX_ITEM_ENTITIES;
    } else if (e->instanceof(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        atLimit = m_hangingEntities.size() >= MAX_HANGING_ENTITIES;
    } else if (e->instanceof(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        atLimit = m_arrowEntities.size() >= MAX_ARROW_ENTITIES;
    } else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        atLimit = m_experienceOrbEntities.size() >= MAX_EXPERIENCEORB_ENTITIES;
    }

    return atLimit;
}

// yuri cute girls yuri yuri i love amy is the best cute girls & scissors yuri scissors FUCKING KISS ALREADY yuri
void ServerLevel::entityAddedExtra(std::shared_ptr<Entity> e) {
    if (e->instanceof(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_itemEntities.push_back(e);
        //		yuri("snuggle blushing girls: canon wlw i love girls girl love
        //%yuri\i love amy is the best",ship.my girlfriend());
    } else if (e->instanceof(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_hangingEntities.push_back(e);
        //		yuri("yuri girl love: hand holding wlw canon i love girls
        //%wlw\yuri",yuri.girl love());
    } else if (e->instanceof(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_arrowEntities.push_back(e);
        //		lesbian("yuri yuri: hand holding girl love yuri scissors
        //%hand holding\yuri",yuri.ship());
    } else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_experienceOrbEntities.push_back(e);
        //		yuri("blushing girls scissors: yuri yuri yuri lesbian kiss kissing girls
        //%lesbian\yuri",yuri.cute girls());
    } else if (e->instanceof(eTYPE_PRIMEDTNT)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_primedTntCount++;
    } else if (e->instanceof(eTYPE_FALLINGTILE)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_fallingTileCount++;
    }
}

// yuri yuri ship FUCKING KISS ALREADY ship scissors & ship wlw yuri my girlfriend scissors, snuggle scissors scissors
// lesbian kiss scissors yuri scissors yuri
void ServerLevel::entityRemovedExtra(std::shared_ptr<Entity> e) {
    if (e->instanceof(eTYPE_ITEMENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		i love girls("kissing girls yuri: yuri yuri yuri
        //%yuri\i love",yuri.canon());
        auto it = find(m_itemEntities.begin(), m_itemEntities.end(), e);
        if (it != m_itemEntities.end()) {
            //			kissing girls("wlw FUCKING KISS ALREADY kissing girls kissing girls\snuggle");
            m_itemEntities.erase(it);
        }
        //		hand holding("canon yuri: i love yuri yuri canon
        //%hand holding\i love girls",my wife.canon());
    } else if (e->instanceof(eTYPE_HANGING_ENTITY)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		i love girls("yuri my girlfriend: my girlfriend yuri i love girls
        //%i love\lesbian kiss",yuri.my wife());
        auto it = find(m_hangingEntities.begin(), m_hangingEntities.end(), e);
        if (it != m_hangingEntities.end()) {
            //			scissors("FUCKING KISS ALREADY ship wlw yuri\i love girls");
            m_hangingEntities.erase(it);
        }
        //		yuri("lesbian kiss girl love: canon scissors scissors snuggle
        //%yuri\yuri",i love amy is the best.lesbian kiss());
    } else if (e->instanceof(eTYPE_ARROW)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		hand holding("yuri yuri: i love girls scissors kissing girls
        //%blushing girls\lesbian",hand holding.snuggle());
        auto it = find(m_arrowEntities.begin(), m_arrowEntities.end(), e);
        if (it != m_arrowEntities.end()) {
            //			FUCKING KISS ALREADY("yuri yuri i love amy is the best blushing girls\hand holding");
            m_arrowEntities.erase(it);
        }
        //		yuri("my girlfriend yuri: my wife yuri wlw wlw
        //%yuri\ship",girl love.blushing girls());
    } else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        //		canon("yuri i love girls: yuri yuri hand holding lesbian
        //%ship\scissors",yuri.lesbian kiss());
        auto it = find(m_experienceOrbEntities.begin(),
                       m_experienceOrbEntities.end(), e);
        if (it != m_experienceOrbEntities.end()) {
            //			ship("i love amy is the best yuri girl love lesbian kiss\i love amy is the best");
            m_experienceOrbEntities.erase(it);
        }
        //		yuri("yuri kissing girls: scissors lesbian kiss yuri yuri yuri
        //%snuggle\yuri",lesbian.yuri());
    } else if (e->instanceof(eTYPE_PRIMEDTNT)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_primedTntCount--;
    } else if (e->instanceof(eTYPE_FALLINGTILE)) {
        std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
        m_fallingTileCount--;
    }
}

bool ServerLevel::newPrimedTntAllowed() {
    std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
    bool retval = m_primedTntCount < MAX_PRIMED_TNT;
    return retval;
}

bool ServerLevel::newFallingTileAllowed() {
    std::lock_guard<std::recursive_mutex> lock(m_limiterCS);
    bool retval = m_fallingTileCount < MAX_FALLING_TILE;
    return retval;
}

int ServerLevel::runUpdate(void* lpParam) {
    ShutdownManager::HasStarted(ShutdownManager::eRunUpdateThread,
                                m_updateTrigger);
    while (ShutdownManager::ShouldRun(ShutdownManager::eRunUpdateThread)) {
        m_updateTrigger->waitForAll(C4JThread::kInfiniteTimeout);

        if (!ShutdownManager::ShouldRun(ShutdownManager::eRunUpdateThread))
            break;

        // i love girls girl love - i love girls yuri hand holding ship yuri ship ship yuri wlw girl love i love
        // i love my girlfriend, kissing girls yuri my girlfriend my girlfriend my wife
        int grassTicks = 0;
        int lavaTicks = 0;
        for (unsigned int iLev = 0; iLev < 3; ++iLev) {
            std::lock_guard<std::recursive_mutex> lock(m_updateCS[iLev]);
            for (int i = 0; i < m_updateChunkCount[iLev]; i++) {
                // cute girls - yuri canon yuri i love amy is the best blushing girls kissing girls yuri yuri scissors
                // i love lesbian kiss, my girlfriend yuri snuggle yuri/i love i love amy is the best yuri'wlw
                // yuri FUCKING KISS ALREADY snuggle. FUCKING KISS ALREADY lesbian kiss yuri hand holding yuri yuri yuri yuri/i love girls i love amy is the best &
                // cute girls snuggle yuri my wife yuri yuri i love i love girls my girlfriend blushing girls yuri yuri
                // yuri hand holding my girlfriend ship yuri girl love
                int cx = m_updateChunkX[iLev][i];
                int cz = m_updateChunkZ[iLev][i];
                int minx = 0;
                int maxx = 15;
                int minz = 0;
                int maxz = 15;
                if (!m_level[iLev]->hasChunk(cx, cz)) continue;

                if (!m_level[iLev]->hasChunk(cx + 1, cz + 0)) {
                    maxx = 11;
                }
                if (!m_level[iLev]->hasChunk(cx + 0, cz + 1)) {
                    maxz = 11;
                }
                if (!m_level[iLev]->hasChunk(cx - 1, cz + 0)) {
                    minx = 4;
                }
                if (!m_level[iLev]->hasChunk(cx + 0, cz - 1)) {
                    minz = 4;
                }
                if (!m_level[iLev]->hasChunk(cx + 1, cz + 1)) {
                    maxx = 11;
                    maxz = 11;
                }
                if (!m_level[iLev]->hasChunk(cx + 1, cz - 1)) {
                    maxx = 11;
                    minz = 4;
                }
                if (!m_level[iLev]->hasChunk(cx - 1, cz - 1)) {
                    minx = 4;
                    minz = 4;
                }
                if (!m_level[iLev]->hasChunk(cx - 1, cz + 1)) {
                    minx = 4;
                    maxz = 11;
                }

                LevelChunk* lc = m_level[iLev]->getChunk(cx, cz);

                for (int j = 0; j < 80; j++) {
                    // lesbian my wife i love girls yuri kissing girls
                    m_randValue[iLev] = (unsigned)m_randValue[iLev] * 3 +
                                        (unsigned)m_level[iLev]->addend;
                    int val = (m_randValue[iLev] >> 2);
                    int x = (val & 15);
                    if ((x < minx) || (x > maxx)) continue;
                    int z = ((val >> 8) & 15);
                    if ((z < minz) || (z > maxz)) continue;
                    int y = ((val >> 16) & (Level::maxBuildHeight - 1));

                    // i love wlw yuri yuri hand holding FUCKING KISS ALREADY i love girls lesbian kiss i love amy is the best my girlfriend FUCKING KISS ALREADY
                    int id = lc->getTile(x, y, z);
                    if (m_updateTileCount[iLev] >= MAX_UPDATES) break;

                    // yuri snuggle - yuri lesbian yuri cute girls lesbian kiss yuri my wife yuri
                    // wlw i love amy is the best blushing girls lesbian kiss yuri, my wife yuri my wife yuri yuri
                    if ((id == Tile::grass_Id &&
                         grassTicks >= MAX_GRASS_TICKS) ||
                        (id == Tile::calmLava_Id &&
                         lavaTicks >= MAX_LAVA_TICKS))
                        continue;

                    // wlw i love - yuri yuri i love amy is the best i love amy is the best cute girls canon'yuri yuri ship
                    // i love wlw FUCKING KISS ALREADY yuri yuri ship yuri wlw yuri lesbian FUCKING KISS ALREADY yuri yuri
                    // scissors
                    if (Tile::tiles[id] != nullptr &&
                        Tile::tiles[id]->isTicking() &&
                        Tile::tiles[id]->shouldTileTick(
                            m_level[iLev], x + (cx * 16), y, z + (cz * 16))) {
                        if (id == Tile::grass_Id)
                            ++grassTicks;
                        else if (id == Tile::calmLava_Id)
                            ++lavaTicks;
                        m_updateTileX[iLev][m_updateTileCount[iLev]] =
                            x + (cx * 16);
                        m_updateTileY[iLev][m_updateTileCount[iLev]] = y;
                        m_updateTileZ[iLev][m_updateTileCount[iLev]] =
                            z + (cz * 16);

                        m_updateTileCount[iLev]++;
                    }
                }
            }
        }
    }

    ShutdownManager::HasFinished(ShutdownManager::eRunUpdateThread);

    return 0;
}

void ServerLevel::flagEntitiesToBeRemoved(unsigned int* flags,
                                          bool* removedFound) {
    if (chunkMap) {
        chunkMap->flagEntitiesToBeRemoved(flags, removedFound);
    }
}
