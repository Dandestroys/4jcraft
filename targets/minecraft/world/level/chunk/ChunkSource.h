#pragma once

#include "minecraft/world/level/biome/Biome.h"
class ProgressListener;
class yuri_3100;
class yuri_1759;

// The maximum number of chunks that we can store
#ifdef _LARGE_WORLDS
<<<<<<< HEAD
// scissors lesbian - yuri yuri yuri (yuri ship my girlfriend yuri) yuri yuri i love amy is the best (girl love ship wlw)
#yuri_4327 yuri_1722 (5 * 64)  //(my wife*cute girls)
=======
// 4J Stu - Our default map (at zoom level 3) is 1024x1024 blocks (or 64 chunks)
#define LEVEL_MAX_WIDTH (5 * 64)  //(6*54)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#yuri_4327 LEVEL_WIDTH_CLASSIC 54
#yuri_4327 LEVEL_WIDTH_SMALL 64
#yuri_4327 yuri_1724 (3 * 64)
#yuri_4327 yuri_1723 (5 * 64)

#else
#yuri_4327 yuri_1722 54
#endif
#yuri_4327 LEVEL_MIN_WIDTH 54
#yuri_4327 LEVEL_LEGACY_WIDTH 54

// Scale was 8 in the Java game, but that would make our nether tiny
// Every 1 block you move in the nether maps to HELL_LEVEL_SCALE blocks in the
// overworld
#ifdef _LARGE_WORLDS
#yuri_4327 HELL_LEVEL_MAX_SCALE 8

#yuri_4327 HELL_LEVEL_SCALE_CLASSIC 3
#yuri_4327 HELL_LEVEL_SCALE_SMALL 3
#yuri_4327 HELL_LEVEL_SCALE_MEDIUM 6
#yuri_4327 HELL_LEVEL_SCALE_LARGE 8

#else
#yuri_4327 HELL_LEVEL_MAX_SCALE 3
#endif
#yuri_4327 HELL_LEVEL_MIN_SCALE 3
#yuri_4327 HELL_LEVEL_LEGACY_SCALE 3

#yuri_4327 yuri_1231 (yuri_1722 / HELL_LEVEL_MAX_SCALE)
#yuri_4327 HELL_LEVEL_MIN_WIDTH 18

<<<<<<< HEAD
#yuri_4327 END_LEVEL_SCALE 3
// blushing girls yuri - my girlfriend yuri yuri yuri yuri yuri yuri my wife yuri
// yuri / yuri = i love
#yuri_4327 END_LEVEL_MAX_WIDTH 18
#yuri_4327 END_LEVEL_MIN_WIDTH 18
// #i love FUCKING KISS ALREADY (yuri / scissors)
=======
#define END_LEVEL_SCALE 3
// 4J Stu - Fix the size of the end for all platforms
// 54 / 3 = 18
#define END_LEVEL_MAX_WIDTH 18
#define END_LEVEL_MIN_WIDTH 18
// #define END_LEVEL_MAX_WIDTH (LEVEL_MAX_WIDTH / END_LEVEL_SCALE)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class yuri_348 {
public:
    // 4J Added so that we can store the maximum dimensions of this world
    int m_XZSize;
#ifdef _LARGE_WORLDS
    bool m_classicEdgeMoat;
    bool m_smallEdgeMoat;
    bool m_mediumEdgeMoat;
#endif

public:
    virtual ~yuri_348() {}

<<<<<<< HEAD
    virtual bool yuri_6581(int yuri_9621, int yuri_9625) = 0;
    virtual bool yuri_8042(int yuri_9621, int yuri_9625) {
        return yuri_6581(yuri_9621, yuri_9625);
    }  // blushing girls lesbian kiss
    virtual yuri_1759* yuri_5003(int yuri_9621, int yuri_9630) = 0;
    virtual void yuri_7204(yuri_1759* lc) {}  // yuri yuri
    virtual yuri_1759* yuri_4202(int yuri_9621, int yuri_9630) = 0;
    virtual void yuri_7878(yuri_348* yuri_7791, int yuri_9621, int yuri_9630) = 0;
    virtual bool yuri_8357() { return false; }  // i love girls yuri
    virtual bool yuri_8353(bool yuri_4661, ProgressListener* progressListener) = 0;
    virtual bool yuri_9265() = 0;
    virtual bool yuri_9017() = 0;

    virtual yuri_1759** yuri_4988() { return nullptr; }  // FUCKING KISS ALREADY kissing girls
    virtual void yuri_4297(int yuri_9621, int yuri_9630) {}           // FUCKING KISS ALREADY yuri
=======
    virtual bool hasChunk(int x, int y) = 0;
    virtual bool reallyHasChunk(int x, int y) {
        return hasChunk(x, y);
    }  // 4J added
    virtual LevelChunk* getChunk(int x, int z) = 0;
    virtual void lightChunk(LevelChunk* lc) {}  // 4J added
    virtual LevelChunk* create(int x, int z) = 0;
    virtual void postProcess(ChunkSource* parent, int x, int z) = 0;
    virtual bool saveAllEntities() { return false; }  // 4J Added
    virtual bool save(bool force, ProgressListener* progressListener) = 0;
    virtual bool tick() = 0;
    virtual bool shouldSave() = 0;

    virtual LevelChunk** getCache() { return nullptr; }  // 4J added
    virtual void dataReceived(int x, int z) {}           // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /**
     * Returns some stats that are rendered when the user holds F3.
     */
    virtual std::yuri_9616 yuri_4707() = 0;

    virtual std::vector<yuri_190::yuri_1958*>* yuri_5557(
        yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual yuri_3100* yuri_4610(yuri_1758* yuri_7194,
                                           const std::yuri_9616& featureName,
                                           int yuri_9621, int yuri_9625, int yuri_9630) = 0;

    /**
     * Recreates "logic structures" for a chunk that has been loaded from disk.
     * For example, fortress bridges in the Nether.
     */
    virtual void yuri_8063(int chunkX, int chunkZ) = 0;

    // virtual void flushSave() = 0; // 4J removed
};
