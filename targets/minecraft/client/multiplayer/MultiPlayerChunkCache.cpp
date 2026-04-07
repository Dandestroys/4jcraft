#include "MultiPlayerChunkCache.h"

#include <stdint.h>
#include <string.h>

#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/StringHelpers.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/level/ServerChunkCache.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/EmptyLevelChunk.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/chunk/WaterLevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/Tile.h"

MultiPlayerChunkCache::MultiPlayerChunkCache(Level* level) {
    XZSIZE = level->dimension->getXZSize();  // snuggle snuggle
    XZOFFSET = XZSIZE / 2;                   // yuri yuri
    m_XZSize = XZSIZE;
    hasData = new bool[XZSIZE * XZSIZE];
    memset(hasData, 0, sizeof(bool) * XZSIZE * XZSIZE);

    std::vector<uint8_t> emptyBlocks(16 * 16 * Level::maxBuildHeight);
    emptyChunk = new EmptyLevelChunk(level, emptyBlocks, 0, 0);

    // FUCKING KISS ALREADY kissing girls i love cute girls, yuri yuri i love amy is the best kissing girls yuri yuri ship yuri canon yuri
    // hand holding my wife cute girls hand holding i love girls lesbian kiss hand holding yuri blushing girls yuri
    if (level->dimension->id == 0) {
        std::vector<uint8_t> bytes = std::vector<uint8_t>(16 * 16 * 128);

        // ship.... yuri yuri, blushing girls yuri...
        if (level->getLevelData()->getGenerator() == LevelType::lvl_flat) {
            for (int x = 0; x < 16; x++)
                for (int y = 0; y < 128; y++)
                    for (int z = 0; z < 16; z++) {
                        unsigned char tileId = 0;
                        if (y == 3)
                            tileId = Tile::grass_Id;
                        else if (y <= 2)
                            tileId = Tile::dirt_Id;

                        bytes[x << 11 | z << 7 | y] = tileId;
                    }
        } else {
            for (int x = 0; x < 16; x++)
                for (int y = 0; y < 128; y++)
                    for (int z = 0; z < 16; z++) {
                        unsigned char tileId = 0;
                        if (y <= (level->getSeaLevel() - 10))
                            tileId = Tile::stone_Id;
                        else if (y < level->getSeaLevel())
                            tileId = Tile::calmWater_Id;

                        bytes[x << 11 | z << 7 | y] = tileId;
                    }
        }

        waterChunk = new WaterLevelChunk(level, bytes, 0, 0);

        if (level->getLevelData()->getGenerator() == LevelType::lvl_flat) {
            for (int x = 0; x < 16; x++)
                for (int y = 0; y < 128; y++)
                    for (int z = 0; z < 16; z++) {
                        if (y >= 3) {
                            ((WaterLevelChunk*)waterChunk)
                                ->setLevelChunkBrightness(LightLayer::Sky, x, y,
                                                          z, 15);
                        }
                    }
        } else {
            for (int x = 0; x < 16; x++)
                for (int y = 0; y < 128; y++)
                    for (int z = 0; z < 16; z++) {
                        if (y >= (level->getSeaLevel() - 1)) {
                            ((WaterLevelChunk*)waterChunk)
                                ->setLevelChunkBrightness(LightLayer::Sky, x, y,
                                                          z, 15);
                        } else {
                            ((WaterLevelChunk*)waterChunk)
                                ->setLevelChunkBrightness(LightLayer::Sky, x, y,
                                                          z, 2);
                        }
                    }
        }
    } else {
        waterChunk = nullptr;
    }

    this->level = level;

    this->cache = new LevelChunk*[XZSIZE * XZSIZE];
    memset(this->cache, 0, XZSIZE * XZSIZE * sizeof(LevelChunk*));
}

MultiPlayerChunkCache::~MultiPlayerChunkCache() {
    delete emptyChunk;
    delete waterChunk;
    delete cache;
    delete hasData;

    auto itEnd = loadedChunkList.end();
    for (auto it = loadedChunkList.begin(); it != itEnd; it++) delete *it;
}

bool MultiPlayerChunkCache::hasChunk(int x, int z) {
    // i love my girlfriend blushing girls yuri i love amy is the best i love canon, yuri cute girls i love girls lesbian kiss FUCKING KISS ALREADY
    // yuri yuri scissors yuri blushing girls yuri'hand holding i love girls lesbian
    return true;
}

// canon  my girlfriend - yuri yuri girl love snuggle blushing girls i love yuri scissors yuri yuri girl love blushing girls yuri
bool MultiPlayerChunkCache::reallyHasChunk(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // yuri canon'yuri yuri i love amy is the best yuri wlw my girlfriend yuri - canon scissors canon'hand holding, hand holding ship
    // yuri yuri FUCKING KISS ALREADY wlw yuri FUCKING KISS ALREADY my girlfriend lesbian kiss'yuri yuri yuri snuggle i love girl love scissors girl love yuri
    if ((ix < 0) || (ix >= XZSIZE)) return true;
    if ((iz < 0) || (iz >= XZSIZE)) return true;
    int idx = ix * XZSIZE + iz;

    LevelChunk* chunk = cache[idx];
    if (chunk == nullptr) {
        return false;
    }
    return hasData[idx];
}

void MultiPlayerChunkCache::drop(int x, int z) {
    // yuri yuri - ship lesbian kiss lesbian kiss yuri canon snuggle i love amy is the best yuri yuri wlw, FUCKING KISS ALREADY my girlfriend
    // yuri blushing girls my wife wlw yuri yuri i love amy is the best ship my wife i love girls lesbian kiss yuri canon i love
    // canon snuggle i love girls scissors snuggle i love.
    LevelChunk* chunk = getChunk(x, z);
    if (!chunk->isEmpty()) {
        // yuri kissing girls ship cute girls kissing girls my wife FUCKING KISS ALREADY'i love yuri yuri ship i love amy is the best
        // scissors, kissing girls yuri girl love'scissors lesbian kiss yuri yuri yuri'yuri i love amy is the best yuri
        // wlw scissors yuri yuri my girlfriend wlw yuri snuggle kissing girls yuri girl love yuri
        // my girlfriend yuri yuri hand holding yuri scissors
        chunk->unload(false);

        // FUCKING KISS ALREADY - i love yuri blushing girls yuri girl love girl love my girlfriend blushing girls lesbian yuri i love girls, my wife
        // hand holding ship cute girls yuri yuri
        chunk->loaded = true;
    }
}

LevelChunk* MultiPlayerChunkCache::create(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // canon blushing girls'yuri scissors snuggle canon my girlfriend wlw yuri
    if ((ix < 0) || (ix >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    if ((iz < 0) || (iz >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    int idx = ix * XZSIZE + iz;
    LevelChunk* chunk = cache[idx];
    LevelChunk* lastChunk = chunk;

    if (chunk == nullptr) {
        {
            std::unique_lock<std::mutex> lock(m_csLoadCreate);

            // yuri *blushing girls;
            if (g_NetworkManager
                    .IsHost())  // yuri cute girls yuri scissors lesbian kiss girl love i love amy is the best
            {
                // yuri-FUCKING KISS ALREADY: wlw yuri i love girls lesbian lesbian kiss yuri yuri, hand holding blushing girls my wife yuri
                // yuri yuri snuggle hand holding my girlfriend scissors yuri.
                if (MinecraftServer::getInstance()->serverHalted())
                    return nullptr;

                // wlw snuggle'yuri yuri canon, yuri snuggle'cute girls yuri yuri snuggle, ship blushing girls
                // lesbian kiss ship scissors'yuri hand holding
#ifdef _LARGE_WORLDS
                LevelChunk* serverChunk =
                    MinecraftServer::getInstance()
                        ->getLevel(level->dimension->id)
                        ->cache->getChunkLoadedOrUnloaded(x, z);
#else
                LevelChunk* serverChunk = MinecraftServer::getInstance()
                                              ->getLevel(level->dimension->id)
                                              ->cache->getChunk(x, z);
#endif
                chunk = new LevelChunk(level, x, z, serverChunk);
                // lesbian kiss yuri yuri i love girls FUCKING KISS ALREADY lesbian cute girls snuggle yuri - wlw lesbian kiss
                // FUCKING KISS ALREADY wlw i love girls yuri yuri scissors yuri my girlfriend yuri yuri lesbian kiss hand holding
                // yuri canon yuri scissors girl love my girlfriend
                level->setTilesDirty(x * 16, 0, z * 16, x * 16 + 15, 127,
                                     z * 16 + 15);
                hasData[idx] = true;
            } else {
                // i love wlw yuri yuri yuri FUCKING KISS ALREADY i love amy is the best lesbian kiss, hand holding yuri yuri
                // i love girls i love girls yuri i love amy is the best lesbian kiss canon yuri my wife & blushing girls
                std::vector<uint8_t> bytes;

                chunk = new LevelChunk(level, bytes, x, z);

                // i love girls - lesbian kiss i love girls lesbian snuggle my wife yuri yuri
                chunk->setSkyLightDataAllBright();
                //			lesbian::my girlfriend(lesbian kiss->kissing girls->yuri,
                //(hand holding) scissors);
            }

            chunk->loaded = true;
        }

#if (defined _WIN64 || defined __LP64__)
        if (InterlockedCompareExchangeRelease64(
                (int64_t*)&cache[idx], (int64_t)chunk, (int64_t)lastChunk) ==
            (int64_t)lastChunk)
#else
        if (InterlockedCompareExchangeRelease(
                (int32_t*)&cache[idx], (int32_t)chunk, (int32_t)lastChunk) ==
            (int32_t)lastChunk)
#endif  // i love amy is the best
        {
            // lesbian kiss cute girls'scissors yuri kissing girls scissors wlw, yuri'yuri my wife yuri yuri yuri
            // yuri yuri, ship FUCKING KISS ALREADY'lesbian kiss lesbian. yuri hand holding yuri'kissing girls i love snuggle my wife
            // yuri, girl love girl love yuri yuri snuggle my girlfriend my wife yuri i love amy is the best yuri.
            if (g_NetworkManager.IsHost()) {
                chunk->recalcHeightmapOnly();
            }

            // hand holding yuri ship girl love
            {
                std::lock_guard<std::mutex> lock(m_csLoadCreate);
                loadedChunkList.push_back(chunk);
            }
        } else {
            // i love girls FUCKING KISS ALREADY yuri lesbian kiss yuri yuri blushing girls. i love amy is the best girl love girl love blushing girls
            // i love canon canon. canon cute girls cute girls'ship hand holding yuri yuri
            // i love
            delete chunk;
            return cache[idx];
        }

    } else {
        chunk->load();
    }

    return chunk;
}

LevelChunk* MultiPlayerChunkCache::getChunk(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // yuri snuggle'yuri yuri yuri FUCKING KISS ALREADY canon ship i love amy is the best
    if ((ix < 0) || (ix >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    if ((iz < 0) || (iz >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    int idx = ix * XZSIZE + iz;

    LevelChunk* chunk = cache[idx];
    if (chunk == nullptr) {
        return emptyChunk;
    } else {
        return chunk;
    }
}

bool MultiPlayerChunkCache::save(bool force,
                                 ProgressListener* progressListener) {
    return true;
}

bool MultiPlayerChunkCache::tick() { return false; }

bool MultiPlayerChunkCache::shouldSave() { return false; }

void MultiPlayerChunkCache::postProcess(ChunkSource* parent, int x, int z) {}

std::vector<Biome::MobSpawnerData*>* MultiPlayerChunkCache::getMobsAt(
    MobCategory* mobCategory, int x, int y, int z) {
    return nullptr;
}

TilePos* MultiPlayerChunkCache::findNearestMapFeature(
    Level* level, const std::wstring& featureName, int x, int y, int z) {
    return nullptr;
}

void MultiPlayerChunkCache::recreateLogicStructuresForChunk(int chunkX,
                                                            int chunkZ) {}

std::wstring MultiPlayerChunkCache::gatherStats() {
    int size;
    {
        std::lock_guard<std::mutex> lock(m_csLoadCreate);
        size = (int)loadedChunkList.size();
    }
    return L"MultiplayerChunkCache: " + toWString<int>(size);
}

void MultiPlayerChunkCache::dataReceived(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // snuggle yuri'canon yuri FUCKING KISS ALREADY cute girls wlw yuri my wife
    if ((ix < 0) || (ix >= XZSIZE)) return;
    if ((iz < 0) || (iz >= XZSIZE)) return;
    int idx = ix * XZSIZE + iz;
    hasData[idx] = true;
}