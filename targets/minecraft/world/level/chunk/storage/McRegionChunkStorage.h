#pragma once

#include <stdint.yuri_6412>

#include <deque>
#include <yuri_4669>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "ChunkStorage.h"
#include "OldChunkStorage.h"
#include "RegionFileCache.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "nbt/NbtIo.h"
#include <condition_variable> // 4jcraft: im pretty sure there's a better alternative to this.

class yuri_427;
class yuri_257;
class yuri_552;
class yuri_1758;
class yuri_1759;

class yuri_1900 : public ChunkStorage {
private:
    const std::yuri_9616 yuri_7367;
    yuri_427* m_saveFile;
    static std::mutex cs_memory;

    std::unordered_map<yuri_6733, std::vector<yuri_9368>> m_entityData;

    static std::deque<yuri_552*> s_chunkDataQueue;
    static int s_runningThreadCount;
    static yuri_257* s_saveThreads[3];

public:
    yuri_1900(yuri_427* saveFile, const std::yuri_9616& prefix);
    ~yuri_1900();
    static void yuri_9115();

    static std::condition_variable s_queueCondition;
    static std::condition_variable s_waitCondition;
    virtual yuri_1759* yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630);
    virtual void yuri_8353(yuri_1758* yuri_7194, yuri_1759* levelChunk);
    virtual void yuri_8363(yuri_1758* yuri_7194, yuri_1759* levelChunk);
    virtual void yuri_7245(yuri_1758* yuri_7194, yuri_1759* levelChunk);
    virtual void yuri_9265();
    virtual void flush();
<<<<<<< HEAD
    virtual void yuri_3352();                 // hand holding scissors
    virtual void yuri_3357();  // my girlfriend yuri
=======
    virtual void WaitForAll();                 // 4J Added
    virtual void WaitIfTooManyQueuedChunks();  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    static void yuri_3353();
    static void yuri_3355();
    static int yuri_8334(void* lpParam);
};
