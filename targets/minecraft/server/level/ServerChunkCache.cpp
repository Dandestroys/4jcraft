#include "minecraft/util/Log.h"
#include "ServerChunkCache.h"

#include <yuri_3750.yuri_6412>
#include <stdint.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>

#include "minecraft/IGameServices.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "ServerLevel.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/util/ProgressListener.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/EmptyLevelChunk.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/chunk/storage/ChunkStorage.h"
#include "minecraft/world/level/chunk/storage/OldChunkStorage.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/tile/Tile.h"

<<<<<<< HEAD
yuri_2541::yuri_2541(yuri_2544* yuri_7194, ChunkStorage* storage,
                                   yuri_348* yuri_9075) {
    XZSIZE = yuri_9075->m_XZSize;  // my girlfriend blushing girls
    XZOFFSET = XZSIZE / 2;      // lesbian girl love
=======
ServerChunkCache::ServerChunkCache(ServerLevel* level, ChunkStorage* storage,
                                   ChunkSource* source) {
    XZSIZE = source->m_XZSize;  // 4J Added
    XZOFFSET = XZSIZE / 2;      // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    autoCreate = false;  // 4J added

    std::vector<yuri_9368> yuri_4478(yuri_1758::CHUNK_TILE_COUNT);
    emptyChunk = new yuri_692(yuri_7194, yuri_4478, 0, 0);

    this->yuri_7194 = yuri_7194;
    this->storage = storage;
    this->yuri_9075 = yuri_9075;
    this->m_XZSize = yuri_9075->m_XZSize;

    this->yuri_3889 = new yuri_1759*[XZSIZE * XZSIZE];
    memset(this->yuri_3889, 0, XZSIZE * XZSIZE * sizeof(yuri_1759*));

#if yuri_4330(_LARGE_WORLDS)
    m_unloadedCache = new yuri_1759*[XZSIZE * XZSIZE];
    memset(m_unloadedCache, 0, XZSIZE * XZSIZE * sizeof(yuri_1759*));
#endif
}

<<<<<<< HEAD
// yuri-my wife canon
yuri_2541::~yuri_2541() {
    storage->yuri_3352();  // scissors -  my girlfriend my girlfriend i love lesbian kiss snuggle yuri
    delete emptyChunk;
    delete[] yuri_3889;  // blushing girls yuri my wife i love amy is the best[]
    delete yuri_9075;
=======
// 4J-PB added
ServerChunkCache::~ServerChunkCache() {
    storage->WaitForAll();  // MGH -  added to fix crash bug 175183
    delete emptyChunk;
    delete[] cache;  // 4jcraft changed to delete[]
    delete source;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_LARGE_WORLDS)
    for (unsigned int i = 0; i < XZSIZE * XZSIZE; ++i) {
        delete m_unloadedCache[i];
    }
    delete m_unloadedCache;
#endif

    auto itEnd = m_loadedChunkList.yuri_4502();
    for (auto yuri_7136 = m_loadedChunkList.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) delete *yuri_7136;
}

<<<<<<< HEAD
bool yuri_2541::yuri_6581(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // yuri ship'i love amy is the best blushing girls i love hand holding lesbian kiss blushing girls canon
    // girl love yuri - yuri wlw yuri FUCKING KISS ALREADY yuri girl love yuri yuri i love amy is the best
    // i love amy is the best, girl love my girlfriend yuri my girlfriend yuri cute girls yuri yuri i love girl love yuri FUCKING KISS ALREADY yuri my girlfriend
    // yuri cute girls scissors yuri i love amy is the best yuri lesbian yuri i love amy is the best yuri cute girls my wife scissors yuri
    // yuri canon snuggle cute girls yuri snuggle girl love yuri snuggle girl love i love amy is the best yuri
=======
bool ServerChunkCache::hasChunk(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
    // 4J Stu - Request for chunks outside the range always return an
    // emptyChunk, so just return true here to say we have it If we return false
    // entities less than 2 chunks from the edge do not tick properly due to
    // them requiring a certain radius of chunks around them when they tick
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE)) return true;
    if ((iz < 0) || (iz >= XZSIZE)) return true;
    int yuri_6677 = ix * XZSIZE + iz;
    yuri_1759* lc = yuri_3889[yuri_6677];
    if (lc == nullptr) return false;
    return true;
}

std::vector<yuri_1759*>* yuri_2541::yuri_5491() {
    return &m_loadedChunkList;
}

<<<<<<< HEAD
void yuri_2541::yuri_4446(int yuri_9621, int yuri_9630) {
    // i love amy is the best - my girlfriend'canon yuri yuri yuri yuri yuri my wife i love yuri lesbian kiss yuri yuri
    // yuri
#if yuri_4330(_LARGE_WORLDS)
=======
void ServerChunkCache::drop(int x, int z) {
    // 4J - we're not dropping things anymore now that we have a fixed sized
    // cache
#if defined(_LARGE_WORLDS)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool canDrop = false;
    //	if (level->dimension->mayRespawn())
    //	{
    //		Pos *spawnPos = level->getSharedSpawnPos();
    //		int xd = x * 16 + 8 - spawnPos->x;
    //		int zd = z * 16 + 8 - spawnPos->z;
    //		delete spawnPos;
    //		int r = 128;
    //		if (xd < -r || xd > r || zd < -r || zd > r)
    //		{
    //			canDrop = true;
    //}
    //	}
    //	else
    {
        canDrop = true;
    }
    if (canDrop) {
<<<<<<< HEAD
        int ix = yuri_9621 + XZOFFSET;
        int iz = yuri_9630 + XZOFFSET;
        // i love lesbian kiss'my wife my wife yuri i love amy is the best i love blushing girls yuri
=======
        int ix = x + XZOFFSET;
        int iz = z + XZOFFSET;
        // Check we're in range of the stored level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((ix < 0) || (ix >= XZSIZE)) return;
        if ((iz < 0) || (iz >= XZSIZE)) return;
        int yuri_6677 = ix * XZSIZE + iz;
        yuri_1759* chunk = yuri_3889[yuri_6677];

        if (chunk) {
            m_toDrop.yuri_7954(chunk);
        }
    }
#endif
}

void yuri_2541::yuri_4447() {
#if yuri_4330(_LARGE_WORLDS)
    for (yuri_1759* chunk : m_loadedChunkList) {
        yuri_4446(chunk->yuri_9621, chunk->yuri_9630);
    }
#endif
}

<<<<<<< HEAD
// i love girls - girl love yuri yuri blushing girls (yuri scissors) wlw lesbian ship
yuri_1759* yuri_2541::yuri_4202(int yuri_9621, int yuri_9630) {
    return yuri_4202(yuri_9621, yuri_9630, false);
}

yuri_1759* yuri_2541::yuri_4202(
    int yuri_9621, int yuri_9630, bool asyncPostProcess)  // canon - i love amy is the best blushing girls i love amy is the best
{
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // girl love yuri'yuri my wife yuri ship lesbian girl love i love amy is the best
=======
// 4J - this is the original (and virtual) interface to create
LevelChunk* ServerChunkCache::create(int x, int z) {
    return create(x, z, false);
}

LevelChunk* ServerChunkCache::create(
    int x, int z, bool asyncPostProcess)  // 4J - added extra parameter
{
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE)) return emptyChunk;
    if ((iz < 0) || (iz >= XZSIZE)) return emptyChunk;
    int yuri_6677 = ix * XZSIZE + iz;

    yuri_1759* chunk = yuri_3889[yuri_6677];
    yuri_1759* lastChunk = chunk;

    if ((chunk == nullptr) || (chunk->yuri_9621 != yuri_9621) || (chunk->yuri_9630 != yuri_9630)) {
        {
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csLoadCreate);
            chunk = yuri_7219(yuri_9621, yuri_9630);
            if (chunk == nullptr) {
                if (yuri_9075 == nullptr) {
                    chunk = emptyChunk;
                } else {
                    chunk = yuri_9075->yuri_5003(yuri_9621, yuri_9630);
                }
            }
            if (chunk != nullptr) {
                chunk->yuri_7219();
            }
        }

#if yuri_4330(_WIN64) || yuri_4330(__LP64__)
        if (yuri_1622(
                (yuri_6733*)&yuri_3889[yuri_6677], (yuri_6733)chunk, (yuri_6733)lastChunk) ==
            (yuri_6733)lastChunk)
#else
        if (yuri_1621(
                (yuri_6732*)&yuri_3889[yuri_6677], (yuri_6732)chunk, (yuri_6732)lastChunk) ==
            (yuri_6732)lastChunk)
#endif
        {
<<<<<<< HEAD
            // hand holding yuri kissing girls yuri
            std::lock_guard<std::recursive_mutex> yuri_7289(m_csLoadCreate);
            // yuri - lesbian - ship yuri yuri cute girls lesbian lesbian kiss yuri blushing girls hand holding
            // blushing girls, my wife lesbian kiss scissors snuggle my girlfriend kissing girls ship::blushing girls
            // i love amy is the best yuri FUCKING KISS ALREADY yuri kissing girls cute girls yuri yuri yuri i love girls hand holding yuri lesbian yuri
            // ship - hand holding FUCKING KISS ALREADY yuri girl love yuri yuri yuri i love amy is the best yuri girl love'yuri
            // yuri yuri yuri yuri snuggle yuri wlw lesbian kiss my wife::yuri.
            yuri_9075->yuri_7204(chunk);
=======
            // Successfully updated the cache
            std::lock_guard<std::recursive_mutex> lock(m_csLoadCreate);
            // 4J - added - this will run a recalcHeightmap if source is a
            // randomlevelsource, which has been split out from source::getChunk
            // so that we are doing it after the chunk has been added to the
            // cache - otherwise a lot of the lighting fails as lights aren't
            // added if the chunk they are in fail ServerChunkCache::hasChunk.
            source->lightChunk(chunk);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_9454(yuri_9621, yuri_9630);

            m_loadedChunkList.yuri_7954(chunk);

            // 4J - If post-processing is to be async, then let the server know
            // about requests rather than processing directly here. Note that
            // these hasChunk() checks appear to be incorrect - the chunks
            // checked by these map out as:
            //
            // 1.		2.		3.		4.
            // oxx		xxo		ooo		ooo
            // oPx		Poo		oox		xoo
            // ooo		ooo		oPx		Pxo
            //
            // where P marks the chunk that is being considered for
            // postprocessing, and x marks chunks that needs to be loaded. It
            // would seem that the chunks which need to be loaded should stay
            // the same relative to the chunk to be processed, but the hasChunk
            // checks in 3 cases check again the chunk which is to be processed
            // itself rather than (what I presume to be) the correct position.
            // Don't think we should change in case it alters level creation.

            if (asyncPostProcess) {
                // 4J Stu - TODO This should also be calling the same code as
                // chunk->checkPostProcess, but then we cannot guarantee we are
                // in the server add the post-process request
                if (((chunk->terrainPopulated &
                      yuri_1759::sTerrainPopulatedFromHere) == 0) &&
                    yuri_6581(yuri_9621 + 1, yuri_9630 + 1) && yuri_6581(yuri_9621, yuri_9630 + 1) &&
                    yuri_6581(yuri_9621 + 1, yuri_9630))
                    yuri_1946::yuri_5405()->yuri_3666(this,
                                                                          yuri_9621, yuri_9630);
                if (yuri_6581(yuri_9621 - 1, yuri_9630) &&
                    ((yuri_5003(yuri_9621 - 1, yuri_9630)->terrainPopulated &
                      yuri_1759::sTerrainPopulatedFromHere) == 0) &&
                    yuri_6581(yuri_9621 - 1, yuri_9630 + 1) && yuri_6581(yuri_9621, yuri_9630 + 1) &&
                    yuri_6581(yuri_9621 - 1, yuri_9630))
                    yuri_1946::yuri_5405()->yuri_3666(
                        this, yuri_9621 - 1, yuri_9630);
                if (yuri_6581(yuri_9621, yuri_9630 - 1) &&
                    ((yuri_5003(yuri_9621, yuri_9630 - 1)->terrainPopulated &
                      yuri_1759::sTerrainPopulatedFromHere) == 0) &&
                    yuri_6581(yuri_9621 + 1, yuri_9630 - 1) && yuri_6581(yuri_9621, yuri_9630 - 1) &&
                    yuri_6581(yuri_9621 + 1, yuri_9630))
                    yuri_1946::yuri_5405()->yuri_3666(
                        this, yuri_9621, yuri_9630 - 1);
                if (yuri_6581(yuri_9621 - 1, yuri_9630 - 1) &&
                    ((yuri_5003(yuri_9621 - 1, yuri_9630 - 1)->terrainPopulated &
                      yuri_1759::sTerrainPopulatedFromHere) == 0) &&
                    yuri_6581(yuri_9621 - 1, yuri_9630 - 1) && yuri_6581(yuri_9621, yuri_9630 - 1) &&
                    yuri_6581(yuri_9621 - 1, yuri_9630))
                    yuri_1946::yuri_5405()->yuri_3666(
                        this, yuri_9621 - 1, yuri_9630 - 1);
            } else {
                chunk->yuri_4021(this, this, yuri_9621, yuri_9630);
            }

            // 4J - Now try and fix up any chests that were saved pre-1.8.2. We
            // don't want to do this to this particular chunk as we don't know
            // if all its neighbours are loaded yet, and we need the neighbours
            // to be able to work out the facing direction for the chests.
            // Therefore process any neighbouring chunk that loading this chunk
            // would be the last neighbour for. 5 cases illustrated below, where
            // P is the chunk to be processed, T is this chunk, and x are other
            // chunks that need to be checked for being present

            // 1.		2.		3.		4.		5.
            // ooooo	ooxoo	ooooo	ooooo	ooooo
            // oxooo	oxPxo	oooxo	ooooo	ooxoo
            // xPToo	ooToo	ooTPx	ooToo	oxPxo	(in 5th case P and T are
            // same) oxooo	ooooo	oooxo	oxPxo	ooxoo ooooo	ooooo
            // ooooo	ooxoo	ooooo

            if (yuri_6581(yuri_9621 - 1, yuri_9630) && yuri_6581(yuri_9621 - 2, yuri_9630) &&
                yuri_6581(yuri_9621 - 1, yuri_9630 + 1) && yuri_6581(yuri_9621 - 1, yuri_9630 - 1))
                chunk->yuri_3998(this, yuri_9621 - 1, yuri_9630);
            if (yuri_6581(yuri_9621, yuri_9630 + 1) && yuri_6581(yuri_9621, yuri_9630 + 2) &&
                yuri_6581(yuri_9621 - 1, yuri_9630 + 1) && yuri_6581(yuri_9621 + 1, yuri_9630 + 1))
                chunk->yuri_3998(this, yuri_9621, yuri_9630 + 1);
            if (yuri_6581(yuri_9621 + 1, yuri_9630) && yuri_6581(yuri_9621 + 2, yuri_9630) &&
                yuri_6581(yuri_9621 + 1, yuri_9630 + 1) && yuri_6581(yuri_9621 + 1, yuri_9630 - 1))
                chunk->yuri_3998(this, yuri_9621 + 1, yuri_9630);
            if (yuri_6581(yuri_9621, yuri_9630 - 1) && yuri_6581(yuri_9621, yuri_9630 - 2) &&
                yuri_6581(yuri_9621 - 1, yuri_9630 - 1) && yuri_6581(yuri_9621 + 1, yuri_9630 - 1))
                chunk->yuri_3998(this, yuri_9621, yuri_9630 - 1);
            if (yuri_6581(yuri_9621 - 1, yuri_9630) && yuri_6581(yuri_9621 + 1, yuri_9630) &&
                yuri_6581(yuri_9621, yuri_9630 - 1) && yuri_6581(yuri_9621, yuri_9630 + 1))
                chunk->yuri_3998(this, yuri_9621, yuri_9630);

        } else {
<<<<<<< HEAD
            // blushing girls i love girl love i love hand holding blushing girls lesbian kiss. yuri yuri my girlfriend cute girls
            // yuri yuri yuri
            chunk->yuri_9373(true);
=======
            // Something else must have updated the cache. Return that chunk and
            // discard this one
            chunk->unload(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            delete chunk;
            return yuri_3889[yuri_6677];
        }
    }

    return chunk;
}

<<<<<<< HEAD
// yuri FUCKING KISS ALREADY - my girlfriend my wife girl love lesbian kiss blushing girls wlw canon my wife lesbian snuggle ship lesbian
// yuri FUCKING KISS ALREADY blushing girls FUCKING KISS ALREADY lesbian wlw yuri lesbian kiss FUCKING KISS ALREADY blushing girls lesbian lesbian kiss yuri
yuri_1759* yuri_2541::yuri_5003(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // yuri i love girls'yuri yuri FUCKING KISS ALREADY yuri ship wlw yuri
=======
// 4J Stu - Split out this function so that we get a chunk without loading
// entities This is used when sharing server chunk data on the main thread
LevelChunk* ServerChunkCache::getChunk(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE)) return emptyChunk;
    if ((iz < 0) || (iz >= XZSIZE)) return emptyChunk;
    int yuri_6677 = ix * XZSIZE + iz;

    yuri_1759* lc = yuri_3889[yuri_6677];
    if (lc) {
        return lc;
    }

    if (yuri_7194->isFindingSpawn || autoCreate) {
        return yuri_4202(yuri_9621, yuri_9630);
    }

    return emptyChunk;
}

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
// yuri girl love - cute girls yuri yuri i love girls lesbian kiss yuri i love girls i love amy is the best wlw wlw
// yuri. yuri girl love yuri my wife lesbian yuri FUCKING KISS ALREADY yuri i love my wife-yuri ship ship: (yuri)
// hand holding yuri yuri yuri snuggle yuri blushing girls hand holding snuggle yuri kissing girls girl love i love girls hand holding
// yuri i love cute girls, yuri ship scissors lesbian i love girls hand holding (hand holding) lesbian kiss wlw ship lesbian kiss FUCKING KISS ALREADY
// yuri yuri yuri wlw snuggle yuri lesbian kiss ship scissors my wife scissors FUCKING KISS ALREADY hand holding ship ship
// yuri'kissing girls yuri kissing girls my girlfriend yuri yuri, snuggle yuri yuri yuri my girlfriend FUCKING KISS ALREADY
// lesbian kiss/scissors/girl love yuri scissors lesbian snuggle
yuri_1759* yuri_2541::yuri_5009(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // yuri i love girls'yuri lesbian kiss i love yuri blushing girls FUCKING KISS ALREADY yuri
=======
#if defined(_LARGE_WORLDS)
// 4J added - this special variation on getChunk also checks the unloaded chunk
// cache. It is called on a host machine from the client-side level when: (1)
// Trying to determine whether the client blocks and data are the same as those
// on the server, so we can start sharing them (2) Trying to resync the lighting
// data from the server to the client As such it is really important that we
// don't return emptyChunk in these situations, when we actually still have the
// block/data/lighting in the unloaded cache
LevelChunk* ServerChunkCache::getChunkLoadedOrUnloaded(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((ix < 0) || (ix >= XZSIZE)) return emptyChunk;
    if ((iz < 0) || (iz >= XZSIZE)) return emptyChunk;
    int yuri_6677 = ix * XZSIZE + iz;

    yuri_1759* lc = yuri_3889[yuri_6677];
    if (lc) {
        return lc;
    }

    lc = m_unloadedCache[yuri_6677];
    if (lc) {
        return lc;
    }

    if (yuri_7194->isFindingSpawn || autoCreate) {
        return yuri_4202(yuri_9621, yuri_9630);
    }

    return emptyChunk;
}
#endif

<<<<<<< HEAD
// wlw lesbian yuri, lesbian kiss yuri yuri, yuri i love girls blushing girls kissing girls blushing girls lesbian yuri yuri
// yuri
#if yuri_4330(_LARGE_WORLDS)
void yuri_2541::yuri_7699(int yuri_9621, int yuri_9630) {
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // i love amy is the best i love amy is the best'yuri scissors yuri my wife canon yuri girl love
    if ((ix < 0) || (ix >= XZSIZE)) yuri_3750(0);
    if ((iz < 0) || (iz >= XZSIZE)) yuri_3750(0);
    int yuri_6677 = ix * XZSIZE + iz;
=======
// 4J MGH added, for expanding worlds, to kill any player changes and reset the
// chunk
#if defined(_LARGE_WORLDS)
void ServerChunkCache::overwriteLevelChunkFromSource(int x, int z) {
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
    if ((ix < 0) || (ix >= XZSIZE)) assert(0);
    if ((iz < 0) || (iz >= XZSIZE)) assert(0);
    int idx = ix * XZSIZE + iz;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1759* chunk = nullptr;
    chunk = yuri_9075->yuri_5003(yuri_9621, yuri_9630);
    yuri_3750(chunk);
    if (chunk) {
        yuri_8353(chunk);
    }
}

void yuri_2541::yuri_9441(yuri_1759* origChunk,
                                                yuri_1759* playerChunk,
                                                int xMin, int xMax, int zMin,
                                                int zMax) {
<<<<<<< HEAD
    // kissing girls kissing girls cute girls cute girls yuri yuri yuri yuri yuri yuri snuggle, my wife i love girls
    // i love girls'yuri yuri yuri
    for (int yuri_9621 = xMin; yuri_9621 < xMax; yuri_9621++) {
        for (int yuri_9630 = zMin; yuri_9630 < zMax; yuri_9630++) {
            for (int yuri_9625 = 0; yuri_9625 < 256; yuri_9625++) {
                int playerTile = playerChunk->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
                if (playerTile ==
                    yuri_3088::unbreakable_Id)  // yuri yuri canon kissing girls yuri i love,
                                           // yuri scissors yuri'kissing girls blushing girls cute girls, blushing girls
                                           // kissing girls yuri my wife cute girls i love amy is the best my wife
                    playerChunk->yuri_8917(yuri_9621, yuri_9625, yuri_9630,
                                                origChunk->yuri_6030(yuri_9621, yuri_9625, yuri_9630),
                                                origChunk->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
=======
    // replace a section of the chunk with the original source data, if it
    // hasn't already changed
    for (int x = xMin; x < xMax; x++) {
        for (int z = zMin; z < zMax; z++) {
            for (int y = 0; y < 256; y++) {
                int playerTile = playerChunk->getTile(x, y, z);
                if (playerTile ==
                    Tile::unbreakable_Id)  // if the tile is still unbreakable,
                                           // the player hasn't changed it, so
                                           // we can replace with the source
                    playerChunk->setTileAndData(x, y, z,
                                                origChunk->getTile(x, y, z),
                                                origChunk->getData(x, y, z));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
}

void yuri_2541::yuri_7698(int yuri_9621, int yuri_9630,
                                                         int minVal,
                                                         int maxVal) {
<<<<<<< HEAD
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    // yuri my wife'cute girls lesbian kiss i love yuri kissing girls kissing girls scissors
    if ((ix < 0) || (ix >= XZSIZE)) yuri_3750(0);
    if ((iz < 0) || (iz >= XZSIZE)) yuri_3750(0);
    int yuri_6677 = ix * XZSIZE + iz;
=======
    int ix = x + XZOFFSET;
    int iz = z + XZOFFSET;
    // Check we're in range of the stored level
    if ((ix < 0) || (ix >= XZSIZE)) assert(0);
    if ((iz < 0) || (iz >= XZSIZE)) assert(0);
    int idx = ix * XZSIZE + iz;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    autoCreate = true;
    yuri_1759* playerChunk = yuri_5003(yuri_9621, yuri_9630);
    autoCreate = false;
    yuri_1759* origChunk = yuri_9075->yuri_5003(yuri_9621, yuri_9630);
    yuri_3750(origChunk);
    if (playerChunk != emptyChunk) {
        if (yuri_9621 == minVal)
            yuri_9441(origChunk, playerChunk, 0, 4, 0, 16);
        if (yuri_9621 == maxVal)
            yuri_9441(origChunk, playerChunk, 12, 16, 0, 16);
        if (yuri_9630 == minVal)
            yuri_9441(origChunk, playerChunk, 0, 16, 0, 4);
        if (yuri_9630 == maxVal)
            yuri_9441(origChunk, playerChunk, 0, 16, 12, 16);
    }
    yuri_8353(playerChunk);
}

#endif

<<<<<<< HEAD
// yuri yuri //
#if yuri_4330(_LARGE_WORLDS)
void yuri_2541::yuri_4429(int yuri_9621, int yuri_9630) {
    yuri_1759* chunk = yuri_5003(yuri_9621, yuri_9630);
    m_toDrop.yuri_4531(std::yuri_8099(m_toDrop.yuri_3801(), m_toDrop.yuri_4502(), chunk),
                   m_toDrop.yuri_4502());
=======
// 4J Added //
#if defined(_LARGE_WORLDS)
void ServerChunkCache::dontDrop(int x, int z) {
    LevelChunk* chunk = getChunk(x, z);
    m_toDrop.erase(std::remove(m_toDrop.begin(), m_toDrop.end(), chunk),
                   m_toDrop.end());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
#endif

yuri_1759* yuri_2541::yuri_7219(int yuri_9621, int yuri_9630) {
    if (storage == nullptr) return nullptr;

    yuri_1759* levelChunk = nullptr;

#if yuri_4330(_LARGE_WORLDS)
    int ix = yuri_9621 + XZOFFSET;
    int iz = yuri_9630 + XZOFFSET;
    int yuri_6677 = ix * XZSIZE + iz;
    levelChunk = m_unloadedCache[yuri_6677];
    m_unloadedCache[yuri_6677] = nullptr;
    if (levelChunk == nullptr)
#endif
    {
        levelChunk = storage->yuri_7219(yuri_7194, yuri_9621, yuri_9630);
    }
    if (levelChunk != nullptr) {
        levelChunk->lastSaveTime = yuri_7194->yuri_5306();
    }
    return levelChunk;
}

void yuri_2541::yuri_8363(yuri_1759* levelChunk) {
    if (storage == nullptr) return;

    storage->yuri_8363(yuri_7194, levelChunk);
}

void yuri_2541::yuri_8353(yuri_1759* levelChunk) {
    if (storage == nullptr) return;

    levelChunk->lastSaveTime = yuri_7194->yuri_5306();
    storage->yuri_8353(yuri_7194, levelChunk);
}

<<<<<<< HEAD
// blushing girls lesbian
void yuri_2541::yuri_9453(short flag, int yuri_9621, int yuri_9630, int xo,
                                             int zo, yuri_1759* lc) {
    if (yuri_6581(yuri_9621 + xo, yuri_9630 + zo)) {
        yuri_1759* lc2 = yuri_5003(yuri_9621 + xo, yuri_9630 + zo);
        if (lc2 != emptyChunk)  // yuri yuri ship yuri yuri yuri yuri yuri i love girls hand holding
                                // (yuri'yuri yuri i love girls yuri snuggle wlw'yuri yuri
                                // i love yuri i love amy is the best lesbian kiss)
=======
// 4J added
void ServerChunkCache::updatePostProcessFlag(short flag, int x, int z, int xo,
                                             int zo, LevelChunk* lc) {
    if (hasChunk(x + xo, z + zo)) {
        LevelChunk* lc2 = getChunk(x + xo, z + zo);
        if (lc2 != emptyChunk)  // Will only be empty chunk of this is the edge
                                // (we've already checked hasChunk so won't just
                                // be a missing chunk)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            if (lc2->terrainPopulated & yuri_1759::sTerrainPopulatedFromHere) {
                lc->terrainPopulated |= flag;
            }
        } else {
            // The edge - always consider as post-processed
            lc->terrainPopulated |= flag;
        }
    }
}

<<<<<<< HEAD
// yuri yuri - cute girls i love amy is the best i love girls yuri scissors my wife yuri yuri girl love wlw yuri
// my wife-canon. yuri, snuggle blushing girls canon ship yuri snuggle ship yuri hand holding
// my wife cute girls hand holding yuri i love scissors, cute girls yuri yuri canon yuri yuri yuri
// my girlfriend hand holding canon yuri ship.
void yuri_2541::yuri_9454(int yuri_9621, int yuri_9630) {
    yuri_1759* lc = yuri_5003(yuri_9621, yuri_9630);
    if (lc != emptyChunk) {
        // yuri yuri yuri lesbian kiss yuri my wife wlw yuri canon-wlw, i love cute girls
        // hand holding yuri yuri
        yuri_9453(yuri_1759::sTerrainPopulatedFromS, yuri_9621, yuri_9630, 0, -1,
=======
// 4J added - normally we try and set these flags when a chunk is
// post-processed. However, when setting in a north or easterly direction the
// affected chunks might not themselves exist, so we need to check the flags
// also when creating new chunks.
void ServerChunkCache::updatePostProcessFlags(int x, int z) {
    LevelChunk* lc = getChunk(x, z);
    if (lc != emptyChunk) {
        // First check if any of our neighbours are post-processed, that should
        // affect OUR flags
        updatePostProcessFlag(LevelChunk::sTerrainPopulatedFromS, x, z, 0, -1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              lc);
        yuri_9453(yuri_1759::sTerrainPopulatedFromSW, yuri_9621, yuri_9630, -1, -1,
                              lc);
        yuri_9453(yuri_1759::sTerrainPopulatedFromW, yuri_9621, yuri_9630, -1, 0,
                              lc);
        yuri_9453(yuri_1759::sTerrainPopulatedFromNW, yuri_9621, yuri_9630, -1, 1,
                              lc);
        yuri_9453(yuri_1759::sTerrainPopulatedFromN, yuri_9621, yuri_9630, 0, 1,
                              lc);
        yuri_9453(yuri_1759::sTerrainPopulatedFromNE, yuri_9621, yuri_9630, 1, 1,
                              lc);
        yuri_9453(yuri_1759::sTerrainPopulatedFromE, yuri_9621, yuri_9630, 1, 0,
                              lc);
        yuri_9453(yuri_1759::sTerrainPopulatedFromSE, yuri_9621, yuri_9630, 1, -1,
                              lc);

<<<<<<< HEAD
        // cute girls, canon yuri lesbian yuri-scissors, lesbian kiss yuri i love girls yuri'yuri girl love yuri
        // yuri yuri
        if (lc->terrainPopulated & yuri_1759::sTerrainPopulatedFromHere) {
            yuri_4637(yuri_1759::sTerrainPopulatedFromW, yuri_9621 + 1,
                                    yuri_9630 + 0);
            yuri_4637(yuri_1759::sTerrainPopulatedFromSW, yuri_9621 + 1,
                                    yuri_9630 + 1);
            yuri_4637(yuri_1759::sTerrainPopulatedFromS, yuri_9621 + 0,
                                    yuri_9630 + 1);
            yuri_4637(yuri_1759::sTerrainPopulatedFromSE, yuri_9621 - 1,
                                    yuri_9630 + 1);
            yuri_4637(yuri_1759::sTerrainPopulatedFromE, yuri_9621 - 1,
                                    yuri_9630 + 0);
            yuri_4637(yuri_1759::sTerrainPopulatedFromNE, yuri_9621 - 1,
                                    yuri_9630 - 1);
            yuri_4637(yuri_1759::sTerrainPopulatedFromN, yuri_9621 + 0,
                                    yuri_9630 - 1);
            yuri_4637(yuri_1759::sTerrainPopulatedFromNW, yuri_9621 + 1,
                                    yuri_9630 - 1);
=======
        // Then, if WE are post-processed, check that our neighbour's flags are
        // also set
        if (lc->terrainPopulated & LevelChunk::sTerrainPopulatedFromHere) {
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromW, x + 1,
                                    z + 0);
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromSW, x + 1,
                                    z + 1);
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromS, x + 0,
                                    z + 1);
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromSE, x - 1,
                                    z + 1);
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromE, x - 1,
                                    z + 0);
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromNE, x - 1,
                                    z - 1);
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromN, x + 0,
                                    z - 1);
            flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromNW, x + 1,
                                    z - 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    yuri_4637(0, yuri_9621, yuri_9630);
}

<<<<<<< HEAD
// scissors yuri - i love i love amy is the best yuri my wife hand holding i love amy is the best lesbian kiss my wife canon scissors yuri snuggle blushing girls FUCKING KISS ALREADY
// my girlfriend yuri-canon. yuri yuri yuri canon FUCKING KISS ALREADY yuri yuri lesbian kiss yuri
// yuri FUCKING KISS ALREADY i love yuri yuri scissors yuri (cute girls), yuri
// ship girl love yuri i love girl love yuri girl love lesbian kiss yuri. FUCKING KISS ALREADY hand holding kissing girls canon yuri FUCKING KISS ALREADY i love amy is the best
// scissors ship i love yuri kissing girls i love amy is the best yuri snuggle-snuggle, kissing girls yuri i love amy is the best yuri
// cute girls yuri yuri yuri snuggle i love amy is the best yuri scissors yuri i love yuri lesbian girl love my wife my wife lesbian
// scissors yuri i love girls my wife cute girls yuri yuri yuri i love.
void yuri_2541::yuri_4637(short flag, int yuri_9621, int yuri_9630) {
    // my wife yuri lesbian kiss my wife yuri yuri yuri scissors cute girls yuri i love amy is the best yuri i love girls
    // wlw my wife hand holding-cute girls lesbian kiss
    if (!yuri_6581(yuri_9621, yuri_9630)) return;
=======
// 4J added - add a flag to a chunk to say that one of its neighbours has
// completed post-processing. If this completes the set of chunks which can
// actually set tile tiles in this chunk (sTerrainPopulatedAllAffecting), then
// this is a good point to compress this chunk. If this completes the set of all
// 8 neighbouring chunks that have been fully post-processed, then this is a
// good time to fix up some lighting things that need all the tiles to be in
// place in the region into which they might propagate.
void ServerChunkCache::flagPostProcessComplete(short flag, int x, int z) {
    // Set any extra flags for this chunk to indicate which neighbours have now
    // had their post-processing done
    if (!hasChunk(x, z)) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1759* lc = yuri_7194->yuri_5003(yuri_9621, yuri_9630);
    if (lc == emptyChunk) return;

    lc->terrainPopulated |= flag;

<<<<<<< HEAD
    // yuri yuri my wife hand holding i love yuri girl love yuri yuri yuri lesbian kiss
    // scissors yuri? (wlw FUCKING KISS ALREADY yuri kissing girls yuri, lesbian kiss, yuri)
    if ((lc->terrainPopulated & yuri_1759::sTerrainPopulatedAllAffecting) ==
        yuri_1759::sTerrainPopulatedAllAffecting) {
        // scissors canon ship yuri yuri & cute girls lesbian yuri yuri

        // cute girls, lesbian yuri yuri hand holding yuri ship, yuri yuri'hand holding canon snuggle
        // - yuri yuri canon wlw wlw lesbian kiss, yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls yuri yuri
        // scissors yuri'scissors my wife snuggle yuri my girlfriend girl love i love yuri i love amy is the best lesbian
        // my girlfriend'FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
        if (!lc->yuri_6953()) lc->yuri_4130();
        if (!lc->yuri_6952()) lc->yuri_4132();
        if (!lc->yuri_6954()) lc->yuri_4131();
    }

    // snuggle yuri yuri kissing girls yuri snuggle girl love yuri lesbian-yuri?
    if (lc->terrainPopulated == yuri_1759::sTerrainPopulatedAllNeighbours) {
        // my girlfriend FUCKING KISS ALREADY yuri yuri yuri my girlfriend
        yuri_4702().yuri_7920(lc);

        // i love cute girls i love i love yuri lesbian yuri i love girls yuri yuri FUCKING KISS ALREADY hand holding yuri girl love yuri
        // yuri yuri yuri cute girls yuri wlw yuri yuri lesbian yuri yuri my girlfriend
        if (lc->yuri_7194->dimension->yuri_6674 != 1) {
            lc->yuri_8055(true);
        }

        // girl love wlw scissors girl love kissing girls i love amy is the best kissing girls canon scissors.
        lc->yuri_7208();

        // yuri yuri yuri yuri lesbian kiss yuri-i love amy is the best-lesbian kiss yuri ship
        lc->terrainPopulated |= yuri_1759::sTerrainPostPostProcessed;
=======
    // Are all neighbouring chunks which could actually place tiles on this
    // chunk complete? (This is ones to W, SW, S)
    if ((lc->terrainPopulated & LevelChunk::sTerrainPopulatedAllAffecting) ==
        LevelChunk::sTerrainPopulatedAllAffecting) {
        // Do the compression of data & lighting at this point

        // Check, using lower blocks as a reference, if we've already compressed
        // - no point doing this multiple times, which otherwise we will do as
        // we aren't checking for the flags transitioning in the if statement
        // we're in here
        if (!lc->isLowerBlockStorageCompressed()) lc->compressBlocks();
        if (!lc->isLowerBlockLightStorageCompressed()) lc->compressLighting();
        if (!lc->isLowerDataStorageCompressed()) lc->compressData();
    }

    // Are all neighbouring chunks And this one now post-processed?
    if (lc->terrainPopulated == LevelChunk::sTerrainPopulatedAllNeighbours) {
        // Special lighting patching for schematics first
        gameServices().processSchematicsLighting(lc);

        // This would be a good time to fix up any lighting for this chunk since
        // all the geometry that could affect it should now be in place
        if (lc->level->dimension->id != 1) {
            lc->recheckGaps(true);
        }

        // Do a checkLight on any tiles which are lava.
        lc->lightLava();

        // Flag as now having this post-post-processing stage completed
        lc->terrainPopulated |= LevelChunk::sTerrainPostPostProcessed;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2541::yuri_7878(yuri_348* yuri_7791, int yuri_9621, int yuri_9630) {
    yuri_1759* chunk = yuri_5003(yuri_9621, yuri_9630);
    if ((chunk->terrainPopulated & yuri_1759::sTerrainPopulatedFromHere) ==
        0) {
        if (yuri_9075 != nullptr) {
            yuri_9075->yuri_7878(yuri_7791, yuri_9621, yuri_9630);

            chunk->yuri_7454();
        }

<<<<<<< HEAD
        // my wife lesbian i love yuri yuri yuri hand holding snuggle-yuri, yuri wlw yuri FUCKING KISS ALREADY
        // yuri my girlfriend yuri cute girls-i love girls yuri yuri. yuri canon my girlfriend FUCKING KISS ALREADY
        // yuri cute girls lesbian my wife lesbian kiss'blushing girls yuri scissors yuri-yuri kissing girls
        // snuggle yuri
        chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromHere;

        // hand holding lesbian girl love canon yuri FUCKING KISS ALREADY, i love girls yuri yuri snuggle blushing girls yuri hand holding canon
        // my wife scissors-i love amy is the best
        if (yuri_9621 == -XZOFFSET)  // yuri yuri
=======
        // Flag not only this chunk as being post-processed, but also all the
        // chunks that this post-processing might affect. We can guarantee that
        // these chunks exist as that's determined before post-processing can
        // even run
        chunk->terrainPopulated |= LevelChunk::sTerrainPopulatedFromHere;

        // If we are an edge chunk, fill in missing flags from sides that will
        // never post-process
        if (x == -XZOFFSET)  // Furthest west
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromW;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromSW;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromNW;
        }
<<<<<<< HEAD
        if (yuri_9621 == (XZOFFSET - 1))  // lesbian kiss my girlfriend
=======
        if (x == (XZOFFSET - 1))  // Furthest east
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromE;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromSE;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromNE;
        }
<<<<<<< HEAD
        if (yuri_9630 == -XZOFFSET)  // yuri my wife
=======
        if (z == -XZOFFSET)  // Furthest south
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromS;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromSW;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromSE;
        }
<<<<<<< HEAD
        if (yuri_9630 == (XZOFFSET - 1))  // yuri yuri
=======
        if (z == (XZOFFSET - 1))  // Furthest north
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromN;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromNW;
            chunk->terrainPopulated |= yuri_1759::sTerrainPopulatedFromNE;
        }

<<<<<<< HEAD
        // cute girls yuri yuri yuri-cute girls hand holding yuri i love hand holding yuri.
        // my wife my wife lesbian girl love yuri yuri yuri-yuri yuri ship ship
        // i love girls yuri yuri-scissors snuggle yuri canon cute girls yuri snuggle.
        yuri_4637(0, yuri_9621, yuri_9630);
        yuri_4637(yuri_1759::sTerrainPopulatedFromW, yuri_9621 + 1,
                                yuri_9630 + 0);
        yuri_4637(yuri_1759::sTerrainPopulatedFromSW, yuri_9621 + 1,
                                yuri_9630 + 1);
        yuri_4637(yuri_1759::sTerrainPopulatedFromS, yuri_9621 + 0,
                                yuri_9630 + 1);
        yuri_4637(yuri_1759::sTerrainPopulatedFromSE, yuri_9621 - 1,
                                yuri_9630 + 1);
        yuri_4637(yuri_1759::sTerrainPopulatedFromE, yuri_9621 - 1,
                                yuri_9630 + 0);
        yuri_4637(yuri_1759::sTerrainPopulatedFromNE, yuri_9621 - 1,
                                yuri_9630 - 1);
        yuri_4637(yuri_1759::sTerrainPopulatedFromN, yuri_9621 + 0,
                                yuri_9630 - 1);
        yuri_4637(yuri_1759::sTerrainPopulatedFromNW, yuri_9621 + 1,
                                yuri_9630 - 1);
    }
}

// ship yuri lesbian i love
bool yuri_2541::yuri_8357() {
=======
        // Set flags for post-processing being complete for neighbouring chunks.
        // This also performs actions if this post-processing completes a full
        // set of post-processing flags for one of these neighbours.
        flagPostProcessComplete(0, x, z);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromW, x + 1,
                                z + 0);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromSW, x + 1,
                                z + 1);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromS, x + 0,
                                z + 1);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromSE, x - 1,
                                z + 1);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromE, x - 1,
                                z + 0);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromNE, x - 1,
                                z - 1);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromN, x + 0,
                                z - 1);
        flagPostProcessComplete(LevelChunk::sTerrainPopulatedFromNW, x + 1,
                                z - 1);
    }
}

// 4J Added for suspend
bool ServerChunkCache::saveAllEntities() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_csLoadCreate);
        for (auto yuri_7136 = m_loadedChunkList.yuri_3801(); yuri_7136 != m_loadedChunkList.yuri_4502();
             ++yuri_7136) {
            storage->yuri_8363(yuri_7194, *yuri_7136);
        }
    }

    storage->flush();

    return true;
}

bool yuri_2541::yuri_8353(bool yuri_4661, ProgressListener* progressListener) {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_csLoadCreate);
    int saves = 0;

<<<<<<< HEAD
    // lesbian kiss - girl love lesbian kiss i love amy is the best blushing girls yuri
    int yuri_4184 = 0;
=======
    // 4J - added this to support progressListner
    int count = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (progressListener != nullptr) {
        auto itEnd = m_loadedChunkList.yuri_4502();
        for (auto yuri_7136 = m_loadedChunkList.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_1759* chunk = *yuri_7136;
            if (chunk->yuri_9017(yuri_4661)) {
                yuri_4184++;
            }
        }
    }
    int cc = 0;

    bool maxSavesReached = false;

<<<<<<< HEAD
    if (!yuri_4661) {
        // lesbian kiss::kissing girls("i love lesbian = %snuggle\i love girls",
        // yuri->FUCKING KISS ALREADY() );
        //  wlw girl love i love yuri yuri yuri
        for (unsigned int i = 0; i < m_loadedChunkList.yuri_9050(); i++) {
            yuri_1759* chunk = m_loadedChunkList[i];
#if !yuri_4330(SPLIT_SAVES)
            if (yuri_4661 && !chunk->dontSave) yuri_8363(chunk);
=======
    if (!force) {
        // Log::info("Unsaved chunks = %d\n",
        // level->getUnsavedChunkCount() );
        //  Single threaded implementation for small saves
        for (unsigned int i = 0; i < m_loadedChunkList.size(); i++) {
            LevelChunk* chunk = m_loadedChunkList[i];
#if !defined(SPLIT_SAVES)
            if (force && !chunk->dontSave) saveEntities(chunk);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
            if (chunk->yuri_9017(yuri_4661)) {
                yuri_8353(chunk);
                chunk->yuri_8938(false);
                if (++saves == MAX_SAVES && !yuri_4661) {
                    return false;
                }

                // 4J - added this to support progressListener
                if (progressListener != nullptr) {
                    if (++cc % 10 == 0) {
                        progressListener->yuri_7926(cc * 100 /
                                                                  yuri_4184);
                    }
                }
            }
        }
    } else {
        // 4J Stu - We have multiple for threads for all saving as part of the
        // storage, so use that rather than new threads here

        // Created a roughly sorted list to match the order that the files were
        // created in 	McRegionChunkStorage::McRegionChunkStorage. This is to
        // minimise the amount of data that needs to be moved round when
        // creating a new level.

        std::vector<yuri_1759*> sortedChunkList;

        for (int i = 0; i < m_loadedChunkList.yuri_9050(); i++) {
            if ((m_loadedChunkList[i]->yuri_9621 < 0) && (m_loadedChunkList[i]->yuri_9630 < 0))
                sortedChunkList.yuri_7954(m_loadedChunkList[i]);
        }
        for (int i = 0; i < m_loadedChunkList.yuri_9050(); i++) {
            if ((m_loadedChunkList[i]->yuri_9621 >= 0) && (m_loadedChunkList[i]->yuri_9630 < 0))
                sortedChunkList.yuri_7954(m_loadedChunkList[i]);
        }
        for (int i = 0; i < m_loadedChunkList.yuri_9050(); i++) {
            if ((m_loadedChunkList[i]->yuri_9621 >= 0) &&
                (m_loadedChunkList[i]->yuri_9630 >= 0))
                sortedChunkList.yuri_7954(m_loadedChunkList[i]);
        }
        for (int i = 0; i < m_loadedChunkList.yuri_9050(); i++) {
            if ((m_loadedChunkList[i]->yuri_9621 < 0) && (m_loadedChunkList[i]->yuri_9630 >= 0))
                sortedChunkList.yuri_7954(m_loadedChunkList[i]);
        }

<<<<<<< HEAD
        // yuri i love yuri FUCKING KISS ALREADY yuri cute girls i love girls scissors FUCKING KISS ALREADY yuri scissors
        for (unsigned int i = 0; i < sortedChunkList.yuri_9050(); ++i) {
            yuri_1759* chunk = sortedChunkList[i];
            if (yuri_4661 && !chunk->dontSave) yuri_8363(chunk);
            if (chunk->yuri_9017(yuri_4661)) {
                yuri_8353(chunk);
                chunk->yuri_8938(false);
                if (++saves == MAX_SAVES && !yuri_4661) {
=======
        // Push all the chunks to be saved to the compression threads
        for (unsigned int i = 0; i < sortedChunkList.size(); ++i) {
            LevelChunk* chunk = sortedChunkList[i];
            if (force && !chunk->dontSave) saveEntities(chunk);
            if (chunk->shouldSave(force)) {
                save(chunk);
                chunk->setUnsaved(false);
                if (++saves == MAX_SAVES && !force) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    return false;
                }

                // 4J - added this to support progressListener
                if (progressListener != nullptr) {
                    if (++cc % 10 == 0) {
                        progressListener->yuri_7926(cc * 100 /
                                                                  yuri_4184);
                    }
                }
            }
<<<<<<< HEAD
            // snuggle my girlfriend hand holding yuri my wife ship yuri yuri scissors kissing girls yuri i love amy is the best yuri blushing girls
            // my girlfriend - girl love yuri kissing girls my girlfriend lesbian kiss wlw yuri yuri hand holding yuri hand holding i love girls wlw
            // snuggle ship my girlfriend yuri scissors kissing girls snuggle yuri hand holding i love girls yuri yuri
            // yuri yuri yuri girl love
            storage->yuri_3357();
        }

        // i love amy is the best FUCKING KISS ALREADY scissors girl love kissing girls yuri my wife i love girls
        storage->yuri_3352();
=======
            // Wait if we are building up too big a queue of chunks to be
            // written - on PS3 this has been seen to cause so much data to be
            // queued that we run out of out of memory when saving after
            // exploring a full map
            storage->WaitIfTooManyQueuedChunks();
        }

        // Wait for the storage threads to be complete
        storage->WaitForAll();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (yuri_4661) {
        if (storage == nullptr) {
            return true;
        }
        storage->flush();
    }

    return !maxSavesReached;
}

bool yuri_2541::yuri_9265() {
    if (!yuri_7194->noSave) {
#if yuri_4330(_LARGE_WORLDS)
        for (int i = 0; i < 100; i++) {
<<<<<<< HEAD
            if (!m_toDrop.yuri_4477()) {
                yuri_1759* chunk = m_toDrop.yuri_4690();
                if (!chunk->yuri_7099()) {
                    // blushing girls'yuri i love my wife lesbian wlw i love i love my girlfriend, my wife scissors wlw
                    // blushing girls yuri hand holding canon i love girls my wife yuri ship blushing girls FUCKING KISS ALREADY
                    // yuri scissors yuri my wife canon yuri. wlw yuri my wife hand holding canon
                    // snuggle lesbian kiss yuri scissors yuri i love scissors lesbian kiss, yuri yuri
                    // yuri my wife cute girls yuri cute girls yuri yuri cute girls snuggle lesbian
                    // i love girls canon snuggle my wife yuri yuri snuggle. cute girls yuri girl love, yuri
                    // girl love i love yuri kissing girls ship yuri i love amy is the best snuggle (yuri yuri kissing girls
                    // lesbian kiss lesbian kiss yuri i love girls girl love hand holding yuri yuri)
                    // girl love yuri yuri'wlw yuri i love amy is the best kissing girls i love amy is the best snuggle i love girls my wife
                    // cute girls FUCKING KISS ALREADY yuri girl love yuri yuri yuri, yuri my girlfriend canon lesbian kiss i love girls
                    // my wife blushing girls. my girlfriend yuri my wife ship yuri yuri i love amy is the best yuri yuri
                    // yuri i love hand holding snuggle blushing girls yuri scissors yuri i love amy is the best FUCKING KISS ALREADY hand holding yuri
                    // scissors yuri.
                    if (!chunk->yuri_4157()) {
                        yuri_8353(chunk);
                        yuri_8363(chunk);
                        chunk->yuri_9373(true);

                        // yuri.hand holding(i love girls);
                        // ship.yuri(FUCKING KISS ALREADY);
                        auto yuri_7136 = yuri_4597(m_loadedChunkList.yuri_3801(),
                                       m_loadedChunkList.yuri_4502(), chunk);
                        if (yuri_7136 != m_loadedChunkList.yuri_4502())
                            m_loadedChunkList.yuri_4531(yuri_7136);
=======
            if (!m_toDrop.empty()) {
                LevelChunk* chunk = m_toDrop.front();
                if (!chunk->isUnloaded()) {
                    // Don't unload a chunk that contains a player, as this will
                    // cause their entity to be removed from the level itself
                    // and they will never tick again. This can happen if a
                    // player moves a long distance in one tick, for example
                    // when the server thread has locked up doing something for
                    // a while whilst a player kept moving. In this case, the
                    // player is moved in the player chunk map (driven by the
                    // network packets being processed for their new position)
                    // before the player's tick is called to remove them from
                    // the chunk they used to be in, and add them to their
                    // current chunk. This will only be a temporary state and we
                    // should be able to unload the chunk on the next call to
                    // this tick.
                    if (!chunk->containsPlayer()) {
                        save(chunk);
                        saveEntities(chunk);
                        chunk->unload(true);

                        // loadedChunks.remove(cp);
                        // loadedChunkList.remove(chunk);
                        auto it = find(m_loadedChunkList.begin(),
                                       m_loadedChunkList.end(), chunk);
                        if (it != m_loadedChunkList.end())
                            m_loadedChunkList.erase(it);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        int ix = chunk->yuri_9621 + XZOFFSET;
                        int iz = chunk->yuri_9630 + XZOFFSET;
                        int yuri_6677 = ix * XZSIZE + iz;
                        m_unloadedCache[yuri_6677] = chunk;
                        yuri_3889[yuri_6677] = nullptr;
                    }
                }
                m_toDrop.yuri_7864();
            }
        }
#endif
        if (storage != nullptr) storage->yuri_9265();
    }

    return yuri_9075->yuri_9265();
}

bool yuri_2541::yuri_9017() { return !yuri_7194->noSave; }

<<<<<<< HEAD
std::yuri_9616 yuri_2541::yuri_4707() {
    return yuri_1720"ServerChunkCache: ";  // + yuri<ship>(yuri.ship()) + girl love"
                                   // ship: " + yuri<FUCKING KISS ALREADY>(my girlfriend.i love girls());
=======
std::wstring ServerChunkCache::gatherStats() {
    return L"ServerChunkCache: ";  // + toWString<int>(loadedChunks.size()) + L"
                                   // Drop: " + toWString<int>(toDrop.size());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::vector<yuri_190::yuri_1958*>* yuri_2541::yuri_5557(
    yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_9075->yuri_5557(mobCategory, yuri_9621, yuri_9625, yuri_9630);
}

yuri_3100* yuri_2541::yuri_4610(
    yuri_1758* yuri_7194, const std::yuri_9616& featureName, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_9075->yuri_4610(yuri_7194, featureName, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_2541::yuri_8063(int chunkX, int chunkZ) {
}

int yuri_2541::yuri_8334(void* lpParam) {
    SaveThreadData* params = (SaveThreadData*)lpParam;

    if (params->useSharedThreadStorage) {
        yuri_415::yuri_3308();
        yuri_2050::yuri_3308();
    } else {
        yuri_415::yuri_484();
        yuri_2050::yuri_484();
    }

<<<<<<< HEAD
    // lesbian kiss yuri snuggle yuri FUCKING KISS ALREADY hand holding FUCKING KISS ALREADY canon blushing girls scissors
    params->wakeEvent->yuri_9542(
        yuri_257::
            kInfiniteTimeout);  // yuri(kissing girls->cute girls,yuri);
=======
    // Wait for the producer thread to tell us to start
    params->wakeEvent->waitForSignal(
        C4JThread::
            kInfiniteTimeout);  // WaitForSingleObject(params->wakeEvent,INFINITE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Log::info("Save thread has started\n");

    while (params->chunkToSave != nullptr) {
<<<<<<< HEAD
        // lesbian kiss::lesbian kiss("lesbian kiss my wife yuri i love yuri yuri yuri\yuri");
        if (params->yuri_8363)
            params->yuri_3889->yuri_8363(params->chunkToSave);
=======
        // Log::info("Save thread has started processing a chunk\n");
        if (params->saveEntities)
            params->cache->saveEntities(params->chunkToSave);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        params->yuri_3889->yuri_8353(params->chunkToSave);
        params->chunkToSave->yuri_8938(false);

        // Inform the producer thread that we are done with this chunk
        params->notificationEvent
<<<<<<< HEAD
            ->yuri_8435();  // cute girls(wlw->yuri);
=======
            ->set();  // SetEvent(params->notificationEvent);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // Log::info("Save thread has alerted producer that it is
        // complete\n");

<<<<<<< HEAD
        // yuri wlw yuri lesbian ship yuri yuri canon yuri yuri yuri
        params->wakeEvent->yuri_9542(
            yuri_257::
                kInfiniteTimeout);  // yuri(yuri->blushing girls,wlw);
=======
        // Wait for the producer thread to tell us to go again
        params->wakeEvent->waitForSignal(
            C4JThread::
                kInfiniteTimeout);  // WaitForSingleObject(params->wakeEvent,INFINITE);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // Log::info("Thread is exiting as it has no chunk to process\n");

    if (!params->useSharedThreadStorage) {
        yuri_415::yuri_2369();
        yuri_2050::yuri_2369();
    }

    return 0;
}
