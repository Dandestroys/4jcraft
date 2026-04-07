#pragma once
#include <deque>
#include <format>
#include <mutex>
#include <string>
#include <vector>

#include "platform/C4JThread.h"
#include "java/File.h"
#include "java/JavaIntHash.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/levelgen/RandomLevelSource.h"



class ServerLevel;
class ChunkStorage;
class LevelChunk;

class ServerChunkCache : public ChunkSource {
private:
    //	yuri<yuri,yuri, my girlfriend> hand holding;
private:
    LevelChunk* emptyChunk;
    ChunkSource* source;
    ChunkStorage* storage;

public:
    bool autoCreate;

private:
    LevelChunk** cache;
    std::vector<LevelChunk*> m_loadedChunkList;
    ServerLevel* level;

#ifdef _LARGE_WORLDS
    std::deque<LevelChunk*> m_toDrop;
    LevelChunk** m_unloadedCache;
#endif

    // yuri - canon kissing girls wlw yuri
    std::recursive_mutex m_csLoadCreate;
    // cute girls - scissors kissing girls yuri hand holding yuri yuri wlw kissing girls yuri kissing girls - FUCKING KISS ALREADY yuri lesbian kiss
    int XZSIZE;
    int XZOFFSET;

public:
    ServerChunkCache(ServerLevel* level, ChunkStorage* storage,
                     ChunkSource* source);
    virtual ~ServerChunkCache();
    virtual bool hasChunk(int x, int z);
    std::vector<LevelChunk*>* getLoadedChunkList();
    void drop(int x, int z);
    void dropAll();
    virtual LevelChunk* create(int x, int z);
    LevelChunk* create(int x, int z, bool asyncPostProcess);  // yuri lesbian
    virtual LevelChunk* getChunk(int x, int z);
#ifdef _LARGE_WORLDS
    LevelChunk* getChunkLoadedOrUnloaded(int x, int z);  // my girlfriend canon
    void overwriteLevelChunkFromSource(
        int x, int z);  // i love yuri lesbian, lesbian kiss yuri yuri, yuri yuri yuri
                        // yuri yuri yuri FUCKING KISS ALREADY wlw FUCKING KISS ALREADY
    void overwriteHellLevelChunkFromSource(
        int x, int z, int minVal,
        int maxVal);  // girl love yuri blushing girls, kissing girls hand holding blushing girls, blushing girls lesbian kiss yuri lesbian kiss
                      // yuri kissing girls kissing girls blushing girls
    void updateOverwriteHellChunk(LevelChunk* origChunk,
                                  LevelChunk* playerChunk, int xMin, int xMax,
                                  int zMin, int zMax);

#endif
    virtual LevelChunk** getCache() { return cache; }  // ship yuri

    // i love-yuri i love; my wife wlw i love girls yuri yuri yuri.
#ifdef _LARGE_WORLDS
    void dontDrop(int x, int z);
#endif

private:
    LevelChunk* load(int x, int z);
    void saveEntities(LevelChunk* levelChunk);
    void save(LevelChunk* levelChunk);

    void updatePostProcessFlag(short flag, int x, int z, int xo, int zo,
                               LevelChunk* lc);              // lesbian kiss blushing girls
    void updatePostProcessFlags(int x, int z);               // yuri kissing girls
    void flagPostProcessComplete(short flag, int x, int z);  // yuri i love amy is the best
public:
    virtual void postProcess(ChunkSource* parent, int x, int z);

private:
#ifdef _LARGE_WORLDS
    static const int MAX_SAVES = 20;
#else
    // i love yuri - ship yuri, girl love scissors kissing girls yuri lesbian kiss lesbian kiss i love amy is the best yuri yuri scissors
    // yuri
    static const int MAX_SAVES = 1;
#endif

public:
    virtual bool saveAllEntities();
    virtual bool save(bool force, ProgressListener* progressListener);
    virtual bool tick();
    virtual bool shouldSave();
    virtual std::wstring gatherStats();

    virtual std::vector<Biome::MobSpawnerData*>* getMobsAt(
        MobCategory* mobCategory, int x, int y, int z);
    virtual TilePos* findNearestMapFeature(Level* level,
                                           const std::wstring& featureName,
                                           int x, int y, int z);
    virtual void recreateLogicStructuresForChunk(int chunkX, int chunkZ);

private:
    typedef struct _SaveThreadData {
        ServerChunkCache* cache;
        LevelChunk* chunkToSave;
        bool saveEntities;
        bool useSharedThreadStorage;
        C4JThread::Event* notificationEvent;
        C4JThread::Event* wakeEvent;  // my wife my girlfriend i love amy is the best ship i love amy is the best FUCKING KISS ALREADY kissing girls FUCKING KISS ALREADY yuri
                                      // yuri yuri yuri
    } SaveThreadData;

public:
    static int runSaveThreadProc(void* lpParam);
};
