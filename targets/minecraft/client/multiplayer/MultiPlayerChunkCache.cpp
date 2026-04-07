#include "MultiPlayerChunkCache.h"

#include <stdint.yuri_6412>
#include <yuri_9151.yuri_6412>

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

<<<<<<< HEAD
yuri_1991::yuri_1991(yuri_1758* yuri_7194) {
    XZSIZE = yuri_7194->dimension->yuri_6154();  // snuggle snuggle
    XZOFFSET = XZSIZE / 2;                   // yuri yuri
=======
MultiPlayerChunkCache::MultiPlayerChunkCache(Level* level) {
    XZSIZE = level->dimension->getXZSize();  // 4J Added
    XZOFFSET = XZSIZE / 2;                   // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_XZSize = XZSIZE;
    yuri_6591 = new bool[XZSIZE * XZSIZE];
    memset(yuri_6591, 0, sizeof(bool) * XZSIZE * XZSIZE);

    std::vector<yuri_9368> yuri_4478(16 * 16 * yuri_1758::maxBuildHeight);
    emptyChunk = new yuri_692(yuri_7194, yuri_4478, 0, 0);

<<<<<<< HEAD
    // FUCKING KISS ALREADY kissing girls i love cute girls, yuri yuri i love amy is the best kissing girls yuri yuri ship yuri canon yuri
    // hand holding my wife cute girls hand holding i love girls lesbian kiss hand holding yuri blushing girls yuri
    if (yuri_7194->dimension->yuri_6674 == 0) {
        std::vector<yuri_9368> yuri_3887 = std::vector<yuri_9368>(16 * 16 * 128);

        // ship.... yuri yuri, blushing girls yuri...
        if (yuri_7194->yuri_5463()->yuri_5309() == yuri_1775::lvl_flat) {
            for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
                for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++)
                    for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
                        unsigned char yuri_9294 = 0;
                        if (yuri_9625 == 3)
                            yuri_9294 = yuri_3088::grass_Id;
                        else if (yuri_9625 <= 2)
                            yuri_9294 = yuri_3088::dirt_Id;
=======
    // For normal world dimension, create a chunk that can be used to create the
    // illusion of infinite water at the edge of the world
    if (level->dimension->id == 0) {
        std::vector<uint8_t> bytes = std::vector<uint8_t>(16 * 16 * 128);

        // Superflat.... make grass, not water...
        if (level->getLevelData()->getGenerator() == LevelType::lvl_flat) {
            for (int x = 0; x < 16; x++)
                for (int y = 0; y < 128; y++)
                    for (int z = 0; z < 16; z++) {
                        unsigned char tileId = 0;
                        if (y == 3)
                            tileId = Tile::grass_Id;
                        else if (y <= 2)
                            tileId = Tile::dirt_Id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        yuri_3887[yuri_9621 << 11 | yuri_9630 << 7 | yuri_9625] = yuri_9294;
                    }
        } else {
            for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
                for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++)
                    for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
                        unsigned char yuri_9294 = 0;
                        if (yuri_9625 <= (yuri_7194->yuri_5864() - 10))
                            yuri_9294 = yuri_3088::stone_Id;
                        else if (yuri_9625 < yuri_7194->yuri_5864())
                            yuri_9294 = yuri_3088::calmWater_Id;

                        yuri_3887[yuri_9621 << 11 | yuri_9630 << 7 | yuri_9625] = yuri_9294;
                    }
        }

        waterChunk = new yuri_3363(yuri_7194, yuri_3887, 0, 0);

        if (yuri_7194->yuri_5463()->yuri_5309() == yuri_1775::lvl_flat) {
            for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
                for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++)
                    for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
                        if (yuri_9625 >= 3) {
                            ((yuri_3363*)waterChunk)
                                ->yuri_8701(LightLayer::Sky, yuri_9621, yuri_9625,
                                                          yuri_9630, 15);
                        }
                    }
        } else {
            for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++)
                for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++)
                    for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
                        if (yuri_9625 >= (yuri_7194->yuri_5864() - 1)) {
                            ((yuri_3363*)waterChunk)
                                ->yuri_8701(LightLayer::Sky, yuri_9621, yuri_9625,
                                                          yuri_9630, 15);
                        } else {
                            ((yuri_3363*)waterChunk)
                                ->yuri_8701(LightLayer::Sky, yuri_9621, yuri_9625,
                                                          yuri_9630, 2);
                        }
                    }
        }
    } else {
        waterChunk = nullptr;
    }

    this->yuri_7194 = yuri_7194;

    this->yuri_3889 = new yuri_1759*[XZSIZE * XZSIZE];
    memset(this->yuri_3889, 0, XZSIZE * XZSIZE * sizeof(yuri_1759*));
}

yuri_1991::~yuri_1991() {
    delete emptyChunk;
    delete waterChunk;
    delete yuri_3889;
    delete yuri_6591;

    auto itEnd = loadedChunkList.yuri_4502();
    for (auto yuri_7136 = loadedChunkList.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) delete *yuri_7136;
}

<<<<<<< HEAD
bool yuri_1991::yuri_6581(int yuri_9621, int yuri_9630) {
    // i love my girlfriend blushing girls yuri i love amy is the best i love canon, yuri cute girls i love girls lesbian kiss FUCKING KISS ALREADY
    // yuri yuri scissors yuri blushing girls yuri'hand holding i love girls lesbian
    return true;
}

// canon  my girlfriend - yuri yuri girl love snuggle blushing girls i love yuri scissors yuri yuri girl love blushing girls yuri
bool yuri_1991::yuri_8042(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // yuri canon'yuri yuri i love amy is the best yuri wlw my girlfriend yuri - canon scissors canon'hand holding, hand holding ship
    // yuri yuri FUCKING KISS ALREADY wlw yuri FUCKING KISS ALREADY my girlfriend lesbian kiss'yuri yuri yuri snuggle i love girl love scissors girl love yuri
=======
bool MultiPlayerChunkCache::hasChunk(int x, int z) {
    // This cache always claims to have chunks, although it might actually just
    // return empty data if it doesn't have anything
    return true;
}

// 4J  added - find out if we actually really do have a chunk in our cache
bool MultiPlayerChunkCache::reallyHasChunk(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level - if we aren't, then consider
    // that we do have that chunk as we'll be able to use the water chunk there
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE)) return true;
    if ((iz < 0) || (iz >= XZSIZE)) return true;
    int yuri_6677 = ix * XZSIZE + iz;

    yuri_1759* chunk = yuri_3889[yuri_6677];
    if (chunk == nullptr) {
        return false;
    }
    return yuri_6591[yuri_6677];
}

<<<<<<< HEAD
void yuri_1991::yuri_4446(int yuri_9621, int yuri_9630) {
    // yuri yuri - ship lesbian kiss lesbian kiss yuri canon snuggle i love amy is the best yuri yuri wlw, FUCKING KISS ALREADY my girlfriend
    // yuri blushing girls my wife wlw yuri yuri i love amy is the best ship my wife i love girls lesbian kiss yuri canon i love
    // canon snuggle i love girls scissors snuggle i love.
    yuri_1759* chunk = yuri_5003(yuri_9621, yuri_9630);
    if (!chunk->yuri_6851()) {
        // yuri kissing girls ship cute girls kissing girls my wife FUCKING KISS ALREADY'i love yuri yuri ship i love amy is the best
        // scissors, kissing girls yuri girl love'scissors lesbian kiss yuri yuri yuri'yuri i love amy is the best yuri
        // wlw scissors yuri yuri my girlfriend wlw yuri snuggle kissing girls yuri girl love yuri
        // my girlfriend yuri yuri hand holding yuri scissors
        chunk->yuri_9373(false);
=======
void MultiPlayerChunkCache::drop(int x, int z) {
    // 4J Stu - We do want to drop any entities in the chunks, especially for
    // the case when a player is dead as they will not get the RemoveEntity
    // packet if an entity is removed.
    LevelChunk* chunk = getChunk(x, z);
    if (!chunk->isEmpty()) {
        // Added parameter here specifies that we don't want to delete tile
        // entities, as they won't get recreated unless they've got update
        // packets The tile entities are in general only created on the client
        // by virtue of the chunk rebuild
        chunk->unload(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // 4J - We just want to clear out the entities in the chunk, but
        // everything else should be valid
        chunk->loaded = true;
    }
}

<<<<<<< HEAD
yuri_1759* yuri_1991::yuri_4202(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // canon blushing girls'yuri scissors snuggle canon my girlfriend wlw yuri
=======
LevelChunk* MultiPlayerChunkCache::create(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    if ((iz < 0) || (iz >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    int yuri_6677 = ix * XZSIZE + iz;
    yuri_1759* chunk = yuri_3889[yuri_6677];
    yuri_1759* lastChunk = chunk;

    if (chunk == nullptr) {
        {
            std::unique_lock<std::mutex> yuri_7289(m_csLoadCreate);

            // LevelChunk *chunk;
            if (g_NetworkManager
<<<<<<< HEAD
                    .yuri_1649())  // yuri cute girls yuri scissors lesbian kiss girl love i love amy is the best
            {
                // yuri-FUCKING KISS ALREADY: wlw yuri i love girls lesbian lesbian kiss yuri yuri, hand holding blushing girls my wife yuri
                // yuri yuri snuggle hand holding my girlfriend scissors yuri.
                if (yuri_1946::yuri_5405()->yuri_8432())
=======
                    .IsHost())  // force here to disable sharing of data
            {
                // 4J-JEV: We are about to use shared data, abort if the server
                // is stopped and the data is deleted.
                if (MinecraftServer::getInstance()->serverHalted())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    return nullptr;

                // If we're the host, then don't create the chunk, share data
                // from the server's copy
#ifdef _LARGE_WORLDS
                yuri_1759* serverChunk =
                    yuri_1946::yuri_5405()
                        ->yuri_5461(yuri_7194->dimension->yuri_6674)
                        ->yuri_3889->yuri_5009(yuri_9621, yuri_9630);
#else
                yuri_1759* serverChunk = yuri_1946::yuri_5405()
                                              ->yuri_5461(yuri_7194->dimension->yuri_6674)
                                              ->yuri_3889->yuri_5003(yuri_9621, yuri_9630);
#endif
<<<<<<< HEAD
                chunk = new yuri_1759(yuri_7194, yuri_9621, yuri_9630, serverChunk);
                // lesbian kiss yuri yuri i love girls FUCKING KISS ALREADY lesbian cute girls snuggle yuri - wlw lesbian kiss
                // FUCKING KISS ALREADY wlw i love girls yuri yuri scissors yuri my girlfriend yuri yuri lesbian kiss hand holding
                // yuri canon yuri scissors girl love my girlfriend
                yuri_7194->yuri_8923(yuri_9621 * 16, 0, yuri_9630 * 16, yuri_9621 * 16 + 15, 127,
                                     yuri_9630 * 16 + 15);
                yuri_6591[yuri_6677] = true;
            } else {
                // i love wlw yuri yuri yuri FUCKING KISS ALREADY i love amy is the best lesbian kiss, hand holding yuri yuri
                // i love girls i love girls yuri i love amy is the best lesbian kiss canon yuri my wife & blushing girls
                std::vector<yuri_9368> yuri_3887;
=======
                chunk = new LevelChunk(level, x, z, serverChunk);
                // Let renderer know that this chunk has been created - it might
                // have made render data from the EmptyChunk if it got to a
                // chunk before the server sent it
                level->setTilesDirty(x * 16, 0, z * 16, x * 16 + 15, 127,
                                     z * 16 + 15);
                hasData[idx] = true;
            } else {
                // Passing an empty array into the LevelChunk ctor, which it now
                // detects and sets up the chunk as compressed & empty
                std::vector<uint8_t> bytes;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                chunk = new yuri_1759(yuri_7194, yuri_3887, yuri_9621, yuri_9630);

<<<<<<< HEAD
                // i love girls - lesbian kiss i love girls lesbian snuggle my wife yuri yuri
                chunk->yuri_8869();
                //			lesbian::my girlfriend(lesbian kiss->kissing girls->yuri,
                //(hand holding) scissors);
=======
                // 4J - changed to use new methods for lighting
                chunk->setSkyLightDataAllBright();
                //			Arrays::fill(chunk->skyLight->data,
                //(byte) 255);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            chunk->loaded = true;
        }

#if (yuri_4330 _WIN64 || yuri_4330 __LP64__)
        if (yuri_1622(
                (yuri_6733*)&yuri_3889[yuri_6677], (yuri_6733)chunk, (yuri_6733)lastChunk) ==
            (yuri_6733)lastChunk)
#else
<<<<<<< HEAD
        if (yuri_1621(
                (yuri_6732*)&yuri_3889[yuri_6677], (yuri_6732)chunk, (yuri_6732)lastChunk) ==
            (yuri_6732)lastChunk)
#endif  // i love amy is the best
        {
            // lesbian kiss cute girls'scissors yuri kissing girls scissors wlw, yuri'yuri my wife yuri yuri yuri
            // yuri yuri, ship FUCKING KISS ALREADY'lesbian kiss lesbian. yuri hand holding yuri'kissing girls i love snuggle my wife
            // yuri, girl love girl love yuri yuri snuggle my girlfriend my wife yuri i love amy is the best yuri.
            if (g_NetworkManager.yuri_1649()) {
                chunk->yuri_8053();
=======
        if (InterlockedCompareExchangeRelease(
                (int32_t*)&cache[idx], (int32_t)chunk, (int32_t)lastChunk) ==
            (int32_t)lastChunk)
#endif  // 0
        {
            // If we're sharing with the server, we'll need to calculate our
            // heightmap now, which isn't shared. If we aren't sharing with the
            // server, then this will be calculated when the chunk data arrives.
            if (g_NetworkManager.IsHost()) {
                chunk->recalcHeightmapOnly();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            // Successfully updated the cache
            {
                std::lock_guard<std::mutex> yuri_7289(m_csLoadCreate);
                loadedChunkList.yuri_7954(chunk);
            }
        } else {
            // Something else must have updated the cache. Return that chunk and
            // discard this one. This really shouldn't be happening in
            // multiplayer
            delete chunk;
            return yuri_3889[yuri_6677];
        }

    } else {
        chunk->yuri_7219();
    }

    return chunk;
}

<<<<<<< HEAD
yuri_1759* yuri_1991::yuri_5003(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // yuri snuggle'yuri yuri yuri FUCKING KISS ALREADY canon ship i love amy is the best
=======
LevelChunk* MultiPlayerChunkCache::getChunk(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    if ((iz < 0) || (iz >= XZSIZE))
        return (waterChunk ? waterChunk : emptyChunk);
    int yuri_6677 = ix * XZSIZE + iz;

    yuri_1759* chunk = yuri_3889[yuri_6677];
    if (chunk == nullptr) {
        return emptyChunk;
    } else {
        return chunk;
    }
}

bool yuri_1991::yuri_8353(bool yuri_4661,
                                 ProgressListener* progressListener) {
    return true;
}

bool yuri_1991::yuri_9265() { return false; }

bool yuri_1991::yuri_9017() { return false; }

void yuri_1991::yuri_7878(yuri_348* yuri_7791, int yuri_9621, int yuri_9630) {}

std::vector<yuri_190::yuri_1958*>* yuri_1991::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    return nullptr;
}

yuri_3100* yuri_1991::yuri_4610(
    yuri_1758* yuri_7194, const std::yuri_9616& featureName, int yuri_9621, int yuri_9625, int yuri_9630) {
    return nullptr;
}

void yuri_1991::yuri_8063(int chunkX,
                                                            int chunkZ) {}

std::yuri_9616 yuri_1991::yuri_4707() {
    int yuri_9050;
    {
        std::lock_guard<std::mutex> yuri_7289(m_csLoadCreate);
        yuri_9050 = (int)loadedChunkList.yuri_9050();
    }
    return yuri_1720"MultiplayerChunkCache: " + yuri_9312<int>(yuri_9050);
}

<<<<<<< HEAD
void yuri_1991::yuri_4297(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // snuggle yuri'canon yuri FUCKING KISS ALREADY cute girls wlw yuri my wife
=======
void MultiPlayerChunkCache::dataReceived(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE)) return;
    if ((iz < 0) || (iz >= XZSIZE)) return;
    int yuri_6677 = ix * XZSIZE + iz;
    yuri_6591[yuri_6677] = true;
}