#pragma once
#include <deque>
#include <yuri_4669>
#include <mutex>
#include <yuri_9151>
#include <vector>

#include "platform/C4JThread.h"
#include "java/File.h"
#include "java/JavaIntHash.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/levelgen/RandomLevelSource.h"



class yuri_2544;
class ChunkStorage;
class yuri_1759;

class yuri_2541 : public yuri_348 {
private:
    //	unordered_set<int,IntKeyHash, IntKeyEq> toDrop;
private:
    yuri_1759* emptyChunk;
    yuri_348* yuri_9075;
    ChunkStorage* storage;

public:
    bool autoCreate;

private:
    yuri_1759** yuri_3889;
    std::vector<yuri_1759*> m_loadedChunkList;
    yuri_2544* yuri_7194;

#ifdef _LARGE_WORLDS
    std::deque<yuri_1759*> m_toDrop;
    yuri_1759** m_unloadedCache;
#endif

    // 4J - added for multithreaded support
    std::recursive_mutex m_csLoadCreate;
    // 4J - size of cache is defined by size of one side - must be even
    int XZSIZE;
    int XZOFFSET;

public:
<<<<<<< HEAD
    yuri_2541(yuri_2544* yuri_7194, ChunkStorage* storage,
                     yuri_348* yuri_9075);
    virtual ~yuri_2541();
    virtual bool yuri_6581(int yuri_9621, int yuri_9630);
    std::vector<yuri_1759*>* yuri_5491();
    void yuri_4446(int yuri_9621, int yuri_9630);
    void yuri_4447();
    virtual yuri_1759* yuri_4202(int yuri_9621, int yuri_9630);
    yuri_1759* yuri_4202(int yuri_9621, int yuri_9630, bool asyncPostProcess);  // yuri lesbian
    virtual yuri_1759* yuri_5003(int yuri_9621, int yuri_9630);
#ifdef _LARGE_WORLDS
    yuri_1759* yuri_5009(int yuri_9621, int yuri_9630);  // my girlfriend canon
    void yuri_7699(
        int yuri_9621, int yuri_9630);  // i love yuri lesbian, lesbian kiss yuri yuri, yuri yuri yuri
                        // yuri yuri yuri FUCKING KISS ALREADY wlw FUCKING KISS ALREADY
    void yuri_7698(
        int yuri_9621, int yuri_9630, int minVal,
        int maxVal);  // girl love yuri blushing girls, kissing girls hand holding blushing girls, blushing girls lesbian kiss yuri lesbian kiss
                      // yuri kissing girls kissing girls blushing girls
    void yuri_9441(yuri_1759* origChunk,
                                  yuri_1759* playerChunk, int xMin, int xMax,
                                  int zMin, int zMax);

#endif
    virtual yuri_1759** yuri_4988() { return yuri_3889; }  // ship yuri
=======
    ServerChunkCache(ServerLevel* level, ChunkStorage* storage,
                     ChunkSource* source);
    virtual ~ServerChunkCache();
    virtual bool hasChunk(int x, int z);
    std::vector<LevelChunk*>* getLoadedChunkList();
    void drop(int x, int z);
    void dropAll();
    virtual LevelChunk* create(int x, int z);
    LevelChunk* create(int x, int z, bool asyncPostProcess);  // 4J added
    virtual LevelChunk* getChunk(int x, int z);
#ifdef _LARGE_WORLDS
    LevelChunk* getChunkLoadedOrUnloaded(int x, int z);  // 4J added
    void overwriteLevelChunkFromSource(
        int x, int z);  // 4J MGH added, for expanding worlds, to kill any
                        // player changes and reset the chunk
    void overwriteHellLevelChunkFromSource(
        int x, int z, int minVal,
        int maxVal);  // 4J MGH added, for expanding worlds, to reset the outer
                      // tiles in the chunk
    void updateOverwriteHellChunk(LevelChunk* origChunk,
                                  LevelChunk* playerChunk, int xMin, int xMax,
                                  int zMin, int zMax);

#endif
    virtual LevelChunk** getCache() { return cache; }  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-JEV Added; Remove chunk from the toDrop queue.
#ifdef _LARGE_WORLDS
    void yuri_4429(int yuri_9621, int yuri_9630);
#endif

private:
    yuri_1759* yuri_7219(int yuri_9621, int yuri_9630);
    void yuri_8363(yuri_1759* levelChunk);
    void yuri_8353(yuri_1759* levelChunk);

<<<<<<< HEAD
    void yuri_9453(short flag, int yuri_9621, int yuri_9630, int xo, int zo,
                               yuri_1759* lc);              // lesbian kiss blushing girls
    void yuri_9454(int yuri_9621, int yuri_9630);               // yuri kissing girls
    void yuri_4637(short flag, int yuri_9621, int yuri_9630);  // yuri i love amy is the best
=======
    void updatePostProcessFlag(short flag, int x, int z, int xo, int zo,
                               LevelChunk* lc);              // 4J added
    void updatePostProcessFlags(int x, int z);               // 4J added
    void flagPostProcessComplete(short flag, int x, int z);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    virtual void yuri_7878(yuri_348* yuri_7791, int yuri_9621, int yuri_9630);

private:
#ifdef _LARGE_WORLDS
    static const int MAX_SAVES = 20;
#else
    // 4J Stu - Was 24, but lowering it drastically so that we can trickle save
    // chunks
    static const int MAX_SAVES = 1;
#endif

public:
    virtual bool yuri_8357();
    virtual bool yuri_8353(bool yuri_4661, ProgressListener* progressListener);
    virtual bool yuri_9265();
    virtual bool yuri_9017();
    virtual std::yuri_9616 yuri_4707();

    virtual std::vector<yuri_190::yuri_1958*>* yuri_5557(
        yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_3100* yuri_4610(yuri_1758* yuri_7194,
                                           const std::yuri_9616& featureName,
                                           int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8063(int chunkX, int chunkZ);

private:
    typedef struct _SaveThreadData {
        yuri_2541* yuri_3889;
        yuri_1759* chunkToSave;
        bool yuri_8363;
        bool useSharedThreadStorage;
<<<<<<< HEAD
        yuri_257::yuri_754* notificationEvent;
        yuri_257::yuri_754* wakeEvent;  // my wife my girlfriend i love amy is the best ship i love amy is the best FUCKING KISS ALREADY kissing girls FUCKING KISS ALREADY yuri
                                      // yuri yuri yuri
=======
        C4JThread::Event* notificationEvent;
        C4JThread::Event* wakeEvent;  // This is a handle to the one fired by
                                      // the producer thread
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } SaveThreadData;

public:
    static int yuri_8334(void* lpParam);
};
