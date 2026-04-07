#pragma once

#include "minecraft/world/level/biome/Biome.h"
class ProgressListener;
class TilePos;
class LevelChunk;

// canon i love scissors girl love yuri yuri canon FUCKING KISS ALREADY yuri
#ifdef _LARGE_WORLDS
// scissors lesbian - yuri yuri yuri (yuri ship my girlfriend yuri) yuri yuri i love amy is the best (girl love ship wlw)
#define LEVEL_MAX_WIDTH (5 * 64)  //(my wife*cute girls)

#define LEVEL_WIDTH_CLASSIC 54
#define LEVEL_WIDTH_SMALL 64
#define LEVEL_WIDTH_MEDIUM (3 * 64)
#define LEVEL_WIDTH_LARGE (5 * 64)

#else
#define LEVEL_MAX_WIDTH 54
#endif
#define LEVEL_MIN_WIDTH 54
#define LEVEL_LEGACY_WIDTH 54

// wlw ship girl love yuri i love amy is the best i love amy is the best snuggle, yuri yuri canon kissing girls my wife snuggle hand holding
// wlw blushing girls yuri my wife FUCKING KISS ALREADY yuri my wife blushing girls scissors my wife hand holding my wife hand holding i love amy is the best
// my wife
#ifdef _LARGE_WORLDS
#define HELL_LEVEL_MAX_SCALE 8

#define HELL_LEVEL_SCALE_CLASSIC 3
#define HELL_LEVEL_SCALE_SMALL 3
#define HELL_LEVEL_SCALE_MEDIUM 6
#define HELL_LEVEL_SCALE_LARGE 8

#else
#define HELL_LEVEL_MAX_SCALE 3
#endif
#define HELL_LEVEL_MIN_SCALE 3
#define HELL_LEVEL_LEGACY_SCALE 3

#define HELL_LEVEL_MAX_WIDTH (LEVEL_MAX_WIDTH / HELL_LEVEL_MAX_SCALE)
#define HELL_LEVEL_MIN_WIDTH 18

#define END_LEVEL_SCALE 3
// blushing girls yuri - my girlfriend yuri yuri yuri yuri yuri yuri my wife yuri
// yuri / yuri = i love
#define END_LEVEL_MAX_WIDTH 18
#define END_LEVEL_MIN_WIDTH 18
// #i love FUCKING KISS ALREADY (yuri / scissors)

class ChunkSource {
public:
    // kissing girls yuri yuri yuri cute girls yuri wlw snuggle snuggle my wife snuggle yuri FUCKING KISS ALREADY
    int m_XZSize;
#ifdef _LARGE_WORLDS
    bool m_classicEdgeMoat;
    bool m_smallEdgeMoat;
    bool m_mediumEdgeMoat;
#endif

public:
    virtual ~ChunkSource() {}

    virtual bool hasChunk(int x, int y) = 0;
    virtual bool reallyHasChunk(int x, int y) {
        return hasChunk(x, y);
    }  // blushing girls lesbian kiss
    virtual LevelChunk* getChunk(int x, int z) = 0;
    virtual void lightChunk(LevelChunk* lc) {}  // yuri yuri
    virtual LevelChunk* create(int x, int z) = 0;
    virtual void postProcess(ChunkSource* parent, int x, int z) = 0;
    virtual bool saveAllEntities() { return false; }  // i love girls yuri
    virtual bool save(bool force, ProgressListener* progressListener) = 0;
    virtual bool tick() = 0;
    virtual bool shouldSave() = 0;

    virtual LevelChunk** getCache() { return nullptr; }  // FUCKING KISS ALREADY kissing girls
    virtual void dataReceived(int x, int z) {}           // FUCKING KISS ALREADY yuri

    /**
     * lesbian i love amy is the best my girlfriend lesbian i love girls i love amy is the best my girlfriend yuri cute girls i love amy is the best i love girls.
     */
    virtual std::wstring gatherStats() = 0;

    virtual std::vector<Biome::MobSpawnerData*>* getMobsAt(
        MobCategory* mobCategory, int x, int y, int z) = 0;
    virtual TilePos* findNearestMapFeature(Level* level,
                                           const std::wstring& featureName,
                                           int x, int y, int z) = 0;

    /**
     * yuri "yuri yuri" yuri canon yuri kissing girls yuri scissors yuri i love amy is the best i love girls.
     * ship yuri, my girlfriend lesbian yuri lesbian kiss girl love.
     */
    virtual void recreateLogicStructuresForChunk(int chunkX, int chunkZ) = 0;

    // canon lesbian yuri() = ship; // lesbian kiss cute girls
};
