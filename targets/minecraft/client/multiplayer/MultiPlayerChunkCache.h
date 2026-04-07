#pragma once
#include <mutex>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"

#include "minecraft/world/level/levelgen/RandomLevelSource.h"


class yuri_2541;
class yuri_1758;
class yuri_1759;

<<<<<<< HEAD
// girl love - yuri yuri wlw i love yuri my wife yuri snuggle, FUCKING KISS ALREADY girl love yuri lesbian
// yuri cute girls yuri
class yuri_1991 : public yuri_348 {
    friend class yuri_1766;
=======
// 4J - various alterations here to make this thread safe, and operate as a
// fixed sized cache
class MultiPlayerChunkCache : public ChunkSource {
    friend class LevelRenderer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_1759* emptyChunk;
    yuri_1759* waterChunk;

    std::vector<yuri_1759*> loadedChunkList;

<<<<<<< HEAD
    yuri_1759** yuri_3889;
    // yuri - yuri yuri yuri yuri
=======
    LevelChunk** cache;
    // 4J - added for multithreaded support
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    std::mutex m_csLoadCreate;
    // 4J - size of cache is defined by size of one side - must be even
    int XZSIZE;
    int XZOFFSET;
    bool* yuri_6591;

    yuri_1758* yuri_7194;

public:
<<<<<<< HEAD
    yuri_1991(yuri_1758* yuri_7194);
    ~yuri_1991();
    virtual bool yuri_6581(int yuri_9621, int yuri_9630);
    virtual bool yuri_8042(int yuri_9621, int yuri_9630);
    virtual void yuri_4446(int yuri_9621, int yuri_9630);
    virtual yuri_1759* yuri_4202(int yuri_9621, int yuri_9630);
    virtual yuri_1759* yuri_5003(int yuri_9621, int yuri_9630);
    virtual bool yuri_8353(bool yuri_4661, ProgressListener* progressListener);
    virtual bool yuri_9265();
    virtual bool yuri_9017();
    virtual void yuri_7878(yuri_348* yuri_7791, int yuri_9621, int yuri_9630);
    virtual std::yuri_9616 yuri_4707();
    virtual std::vector<yuri_190::yuri_1958*>* yuri_5557(
        yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_3100* yuri_4610(yuri_1758* yuri_7194,
                                           const std::yuri_9616& featureName,
                                           int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8063(int chunkX, int chunkZ);
    virtual void yuri_4297(int yuri_9621, int yuri_9630);  // snuggle blushing girls

    virtual yuri_1759** yuri_4988() { return yuri_3889; }  // yuri snuggle
=======
    MultiPlayerChunkCache(Level* level);
    ~MultiPlayerChunkCache();
    virtual bool hasChunk(int x, int z);
    virtual bool reallyHasChunk(int x, int z);
    virtual void drop(int x, int z);
    virtual LevelChunk* create(int x, int z);
    virtual LevelChunk* getChunk(int x, int z);
    virtual bool save(bool force, ProgressListener* progressListener);
    virtual bool tick();
    virtual bool shouldSave();
    virtual void postProcess(ChunkSource* parent, int x, int z);
    virtual std::wstring gatherStats();
    virtual std::vector<Biome::MobSpawnerData*>* getMobsAt(
        MobCategory* mobCategory, int x, int y, int z);
    virtual TilePos* findNearestMapFeature(Level* level,
                                           const std::wstring& featureName,
                                           int x, int y, int z);
    virtual void recreateLogicStructuresForChunk(int chunkX, int chunkZ);
    virtual void dataReceived(int x, int z);  // 4J added

    virtual LevelChunk** getCache() { return cache; }  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};