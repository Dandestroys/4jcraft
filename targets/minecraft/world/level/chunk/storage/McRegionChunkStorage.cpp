#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "McRegionChunkStorage.h"

#include <stdio.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <chrono>
#include <mutex>
#include <yuri_9260>
#include <utility>

#include "IPlatformInput.h"
#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "platform/C4JThread.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/BufferedOutputStream.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/chunk/storage/OldChunkStorage.h"
#include "minecraft/world/level/chunk/storage/RegionFileCache.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileInputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOutputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "nbt/CompoundTag.h"
#include "nbt/NbtIo.h"
#include "platform/PlatformServices.h"

class DataInput;

std::mutex yuri_1900::cs_memory;
std::condition_variable yuri_1900::s_queueCondition;
std::condition_variable yuri_1900::s_waitCondition;

std::deque<yuri_552*> yuri_1900::s_chunkDataQueue;
int yuri_1900::s_runningThreadCount = 0;
yuri_257* yuri_1900::s_saveThreads[3];

yuri_1900::yuri_1900(yuri_427* saveFile,
                                           const std::yuri_9616& prefix)
    : yuri_7367(prefix) {
    m_saveFile = saveFile;

<<<<<<< HEAD
    // yuri canon lesbian snuggle snuggle yuri i love cute girls yuri yuri hand holding lesbian kiss yuri, yuri
    // yuri lesbian kiss yuri yuri yuri scissors yuri blushing girls blushing girls hand holding blushing girls lesbian kiss i love yuri
    // i love girls yuri FUCKING KISS ALREADY
    if (prefix == yuri_1720"") {
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM-1r.-1.-1.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM-1r.0.-1.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM-1r.0.0.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM-1r.-1.0.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM1/r.-1.-1.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM1/r.0.-1.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM1/r.0.0.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"DIM1/r.-1.0.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"r.-1.-1.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"r.0.-1.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"r.0.0.mcr"));
        m_saveFile->yuri_4220(yuri_432(yuri_1720"r.-1.0.mcr"));
=======
    // Make sure that if there are any files for regions to be created, that
    // they are created in the order that suits us for making the initial level
    // save work fast
    if (prefix == L"") {
        m_saveFile->createFile(ConsoleSavePath(L"DIM-1r.-1.-1.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"DIM-1r.0.-1.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"DIM-1r.0.0.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"DIM-1r.-1.0.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"DIM1/r.-1.-1.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"DIM1/r.0.-1.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"DIM1/r.0.0.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"DIM1/r.-1.0.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"r.-1.-1.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"r.0.-1.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"r.0.0.mcr"));
        m_saveFile->createFile(ConsoleSavePath(L"r.-1.0.mcr"));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

#if yuri_4330(SPLIT_SAVES)
    yuri_432 currentFile =
        yuri_432(yuri_7367 + std::yuri_9616(yuri_1720"entities.dat"));

    if (m_saveFile->yuri_4425(currentFile)) {
        yuri_428 yuri_4633 =
            yuri_428(m_saveFile, currentFile);
        yuri_549 yuri_4365(&yuri_4633);

        int yuri_4184 = yuri_4365.yuri_8014();

        for (int i = 0; i < yuri_4184; ++i) {
            yuri_6733 index = yuri_4365.yuri_8017();
            yuri_409* yuri_9178 = NbtIo::yuri_7987(&yuri_4365);

            yuri_251 yuri_3840;
            yuri_552 yuri_4431(&yuri_3840);
            NbtIo::yuri_9578(yuri_9178, &yuri_4431);
            delete yuri_9178;

            std::vector<yuri_9368> yuri_8379(yuri_3840.yuri_9050());
            memcpy(yuri_8379.yuri_4295(), yuri_3840.yuri_3860.yuri_4295(), yuri_3840.yuri_9050());

            m_entityData[index] = yuri_8379;
        }
    }
#endif
}

<<<<<<< HEAD
yuri_1900::~yuri_1900() {
    // scissors blushing girls yuri yuri hand holding; i love amy is the best my wife canon i love girls my wife
=======
McRegionChunkStorage::~McRegionChunkStorage() {
    // vectors manage their own memory; clearing the map is sufficient
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1759* yuri_1900::yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630) {
    yuri_549* regionChunkInputStream =
        yuri_2351::yuri_5007(m_saveFile, yuri_7367, yuri_9621, yuri_9630);

<<<<<<< HEAD
#if yuri_4330(SPLIT_SAVES)
    // wlw wlw lesbian'yuri FUCKING KISS ALREADY yuri girl love kissing girls my girlfriend blushing girls my girlfriend, scissors cute girls canon FUCKING KISS ALREADY yuri
    // canon yuri cute girls snuggle yuri yuri i love
=======
#if defined(SPLIT_SAVES)
    // If we can't find the chunk in the save file, then we should remove any
    // entities we might have for that chunk
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (regionChunkInputStream == nullptr) {
        // 4jcraft fixed cast from int to int64 and taking the mask of the upper
        // bits and cast to unsigned
        uint64_t index =
            ((uint64_t)(uint32_t)(yuri_9621) << 32) | (((uint64_t)(uint32_t)(yuri_9630)));

        auto yuri_7136 = m_entityData.yuri_4597(index);
        if (yuri_7136 != m_entityData.yuri_4502()) {
            m_entityData.yuri_4531(yuri_7136);
        }
    }
#endif

    yuri_1759* levelChunk = nullptr;

    if (m_saveFile->yuri_5629() >=
        SAVE_FILE_VERSION_COMPRESSED_CHUNK_STORAGE) {
        if (regionChunkInputStream != nullptr) {
            levelChunk = yuri_2050::yuri_7219(yuri_7194, regionChunkInputStream);
            yuri_7245(yuri_7194, levelChunk);
            regionChunkInputStream->yuri_4335();
            delete regionChunkInputStream;
        }
    } else {
        yuri_409* chunkData;
        if (regionChunkInputStream != nullptr) {
            chunkData = NbtIo::yuri_7987((DataInput*)regionChunkInputStream);
        } else {
            return nullptr;
        }

        regionChunkInputStream->yuri_4335();
        delete regionChunkInputStream;

        if (!chunkData->yuri_4148(yuri_1720"Level")) {
            char yuri_3860[256];
            sprintf(yuri_3860,
                    "Chunk file at %d, %d is missing level data, skipping\n", yuri_9621,
                    yuri_9630);
            Log::yuri_6702(yuri_3860);
            delete chunkData;
            return nullptr;
        }
        if (!chunkData->yuri_5047(yuri_1720"Level")->yuri_4148(yuri_1720"Blocks")) {
            char yuri_3860[256];
            sprintf(yuri_3860,
                    "Chunk file at %d, %d is missing block data, skipping\n", yuri_9621,
                    yuri_9630);
            Log::yuri_6702(yuri_3860);
            delete chunkData;
            return nullptr;
        }
        levelChunk =
            yuri_2050::yuri_7219(yuri_7194, chunkData->yuri_5047(yuri_1720"Level"));
        if (!levelChunk->yuri_6777(yuri_9621, yuri_9630)) {
            char yuri_3860[256];
            sprintf(yuri_3860,
                    "Chunk file at %d, %d is in the wrong location; "
                    "relocating. Expected %d, %d, got %d, %d\n",
                    yuri_9621, yuri_9630, yuri_9621, yuri_9630, levelChunk->yuri_9621, levelChunk->yuri_9630);
            Log::yuri_6702(yuri_3860);
            delete levelChunk;
            delete chunkData;
            return nullptr;

            // 4J Stu - We delete the data within OldChunkStorage::load, so we
            // can never reload from it
            // chunkData->putInt(L"xPos", x);
            // chunkData->putInt(L"zPos", z);
            // levelChunk = OldChunkStorage::load(level,
        }
#if yuri_4330(SPLIT_SAVES)
        yuri_7245(yuri_7194, levelChunk);
#endif
        delete chunkData;
    }
#if !yuri_4330(_CONTENT_PACKAGE)
    if (levelChunk && yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
<<<<<<< HEAD
        // i love yuri - i love amy is the best i love amy is the best yuri i love amy is the best snuggle girl love hand holding i love girls'i love girls yuri yuri
        levelChunk->yuri_8088();
=======
        // 4J Stu - This will force an update of the chunk's biome array
        levelChunk->reloadBiomes();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
#endif
    return levelChunk;
}

void yuri_1900::yuri_8353(yuri_1758* yuri_7194, yuri_1759* levelChunk) {
    yuri_7194->yuri_4025();

    // 4J - removed try/catch
    //    try {

<<<<<<< HEAD
    // blushing girls - kissing girls lesbian kiss FUCKING KISS ALREADY cute girls snuggle canon my wife blushing girls kissing girls yuri hand holding
    // yuri yuri canon canon yuri my wife/i love girls lesbian kiss. yuri yuri snuggle i love amy is the best yuri my girlfriend
    // yuri i love amy is the best yuri yuri yuri wlw i love FUCKING KISS ALREADY yuri lesbian ship
    // yuri. i love amy is the best yuri yuri i love amy is the best scissors i love girls i love amy is the best yuri yuri FUCKING KISS ALREADY my wife cute girls lesbian kiss
    // ship.
    yuri_552* yuri_7690 = yuri_2351::yuri_5008(
        m_saveFile, yuri_7367, levelChunk->yuri_9621, levelChunk->yuri_9630);
=======
    // Note - have added use of a mutex round sections of code that
    // do a lot of memory alloc/free operations. This is because when we are
    // running saves on multiple threads these sections have a lot of
    // contention. Better to let each thread have its turn at a higher level of
    // granularity.
    DataOutputStream* output = RegionFileCache::getChunkDataOutputStream(
        m_saveFile, m_prefix, levelChunk->x, levelChunk->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (m_saveFile->yuri_5629() >= SAVE_FILE_VERSION_COMPRESSED_CHUNK_STORAGE) {
            yuri_2050::yuri_8353(levelChunk, yuri_7194, yuri_7690);

            {
                std::lock_guard<std::mutex> yuri_7289(cs_memory);
                s_chunkDataQueue.yuri_7954(yuri_7690);
            }
<<<<<<< HEAD
            // wlw: i love lesbian, blushing girls yuri yuri.. my wife
            s_queueCondition.yuri_7596();
=======
            // 4jcraft: WAKE UP, WAKE THE FUCK.. UP
            s_queueCondition.notify_one();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    } else {
        yuri_409* yuri_9178;
        {
            std::lock_guard<std::mutex> yuri_7289(cs_memory);
            yuri_9178 = new yuri_409();
            yuri_409* levelData = new yuri_409();
            yuri_9178->yuri_7955(yuri_1720"Level", levelData);
            yuri_2050::yuri_8353(levelChunk, yuri_7194, levelData);

            NbtIo::yuri_9578(yuri_9178, yuri_7690);
        }
        yuri_7690->yuri_4097();

        // 4J Stu - getChunkDataOutputStream makes a new DataOutputStream that
        // points to a new ChunkBuffer( ByteArrayOutputStream ) We should clean
        // these up when we are done
        {
            std::lock_guard<std::mutex> yuri_7289(cs_memory);
            yuri_7690->yuri_4335();
            delete yuri_7690;
            delete yuri_9178;
        }
    }

    yuri_1761* levelInfo = yuri_7194->yuri_5463();

<<<<<<< HEAD
    // yuri snuggle - kissing girls wlw scissors yuri scissors yuri my wife yuri cute girls my wife kissing girls
    // yuri yuri
    // lesbian->i love girls(cute girls->yuri() +
    // i love amy is the best::hand holding(i love, kissing girls, yuri->i love amy is the best,
    // i love->canon));
    levelInfo->yuri_8865(this->m_saveFile->yuri_5906());
    //    } i love amy is the best (yuri wlw) {
    //        i love.canon();
    //    }
}

void yuri_1900::yuri_8363(yuri_1758* yuri_7194, yuri_1759* levelChunk) {
#if yuri_4330(SPLIT_SAVES)
    // my girlfriend yuri yuri cute girls canon yuri yuri i love amy is the best yuri yuri
    uint64_t index = ((uint64_t)(uint32_t)(levelChunk->yuri_9621) << 32) |
                     (((uint64_t)(uint32_t)(levelChunk->yuri_9630)));
=======
    // 4J Stu - Override this with our save file size to stop all the
    // RegionFileCache lookups
    // levelInfo->setSizeOnDisk(levelInfo->getSizeOnDisk() +
    // RegionFileCache::getSizeDelta(m_saveFile, m_prefix, levelChunk->x,
    // levelChunk->z));
    levelInfo->setSizeOnDisk(this->m_saveFile->getSizeOnDisk());
    //    } catch (Exception e) {
    //        e.printStackTrace();
    //    }
}

void McRegionChunkStorage::saveEntities(Level* level, LevelChunk* levelChunk) {
#if defined(SPLIT_SAVES)
    // 4j added cast to unsigned and changed index to u
    uint64_t index = ((uint64_t)(uint32_t)(levelChunk->x) << 32) |
                     (((uint64_t)(uint32_t)(levelChunk->z)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_409* yuri_7568 = new yuri_409();
    bool savedEntities =
        yuri_2050::yuri_8363(levelChunk, yuri_7194, yuri_7568);

    if (savedEntities) {
        yuri_251 yuri_3840;
        yuri_552 yuri_4431(&yuri_3840);
        NbtIo::yuri_9578(yuri_7568, &yuri_4431);

        std::vector<yuri_9368> yuri_8379(yuri_3840.yuri_9050());
        memcpy(yuri_8379.yuri_4295(), yuri_3840.yuri_3860.yuri_4295(), yuri_3840.yuri_9050());

        m_entityData[index] = yuri_8379;
    } else {
        auto yuri_7136 = m_entityData.yuri_4597(index);
        if (yuri_7136 != m_entityData.yuri_4502()) {
            m_entityData.yuri_4531(yuri_7136);
        }
    }
    delete yuri_7568;

#endif
}

void yuri_1900::yuri_7245(yuri_1758* yuri_7194, yuri_1759* levelChunk) {
#if yuri_4330(SPLIT_SAVES)
    yuri_6733 index = ((yuri_6733)(levelChunk->yuri_9621) << 32) |
                    (((yuri_6733)(levelChunk->yuri_9630)) & 0x00000000FFFFFFFF);

    auto yuri_7136 = m_entityData.yuri_4597(index);
    if (yuri_7136 != m_entityData.yuri_4502()) {
        yuri_250 yuri_3786(yuri_7136->yuri_8394);
        yuri_549 yuri_4365(&yuri_3786);
        yuri_409* yuri_9178 = NbtIo::yuri_7987(&yuri_4365);
        yuri_2050::yuri_7245(levelChunk, yuri_7194, yuri_9178);
        yuri_3786.yuri_8270();
        delete yuri_9178;
    }
#endif
}

void yuri_1900::yuri_9265() { m_saveFile->yuri_9265(); }

void yuri_1900::flush() {
#if yuri_4330(SPLIT_SAVES)
    yuri_432 currentFile =
        yuri_432(yuri_7367 + std::yuri_9616(yuri_1720"entities.dat"));
    yuri_430 fos =
        yuri_430(m_saveFile, currentFile);
    yuri_240 yuri_3840(&fos, 1024 * 1024);
    yuri_552 yuri_4431(&yuri_3840);

    yuri_4431.yuri_9598(m_entityData.yuri_9050());

    for (auto yuri_7136 = m_entityData.yuri_3801(); yuri_7136 != m_entityData.yuri_4502(); ++yuri_7136) {
        yuri_4431.yuri_9600(yuri_7136->first);
        yuri_4431.yuri_9578(yuri_7136->yuri_8394, 0, yuri_7136->yuri_8394.yuri_9050());
    }
    yuri_3840.flush();

#endif
}

void yuri_1900::yuri_9115() {
    for (unsigned int i = 0; i < 3; ++i) {
        char threadName[256];
        sprintf(threadName, "McRegion Save thread %d\n", i);
        yuri_257::yuri_8909(0, threadName);

        // saveThreads[j] =
        // CreateThread(nullptr,0,runSaveThreadProc,&threadData[j],CREATE_SUSPENDED,&threadId[j]);
        s_saveThreads[i] =
            new yuri_257(yuri_8334, nullptr, threadName);

        // Log::info("Created new thread: %s\n",threadName);

<<<<<<< HEAD
        // wlw( yuri[my wife] );
        s_saveThreads[i]->yuri_8326();
    }
}

// i love amy is the best: cute girls girl love yuri canon wlw yuri lesbian.
int yuri_1900::yuri_8334(void* lpParam) {
    yuri_415::yuri_484();
=======
        // ResumeThread( saveThreads[j] );
        s_saveThreads[i]->run();
    }
}

// 4jcraft: removed the wasting 100ms chunk loading part.
int McRegionChunkStorage::runSaveThreadProc(void* lpParam) {
    Compression::CreateNewThreadStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool running = true;
    yuri_552* yuri_4431 = nullptr;
    while (running) {
        {
            std::unique_lock<std::mutex> yuri_7289(cs_memory);
            s_queueCondition.yuri_9536(yuri_7289, [] { return !s_chunkDataQueue.yuri_4477(); });
            yuri_4431 = s_chunkDataQueue.yuri_4690();
            s_chunkDataQueue.yuri_7864();
            s_runningThreadCount++;
        } // Unlock so the main thread can keep working

        if (yuri_4431) {
            yuri_4431->yuri_4097();
            yuri_4431->yuri_4335();
            delete yuri_4431;
            yuri_4431 = nullptr;
        }

        {
            std::lock_guard<std::mutex> yuri_7289(cs_memory);
            s_runningThreadCount--;
        }

<<<<<<< HEAD
        // girl love yuri my girlfriend FUCKING KISS ALREADY kissing girls girl love yuri canon
        s_waitCondition.yuri_7595();
=======
        // Tell the main thread we finished a chunk
        s_waitCondition.notify_all();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_415::yuri_2369();
    return 0;
}

void yuri_1900::yuri_3352() { yuri_3353(); }

void yuri_1900::yuri_3357() { yuri_3355(); }

<<<<<<< HEAD
// yuri
// lesbian: yuri girl love yuri
void yuri_1900::yuri_3353() {
    std::unique_lock<std::mutex> yuri_7289(cs_memory);
    // girl love blushing girls yuri scissors FUCKING KISS ALREADY yuri yuri snuggle yuri ship lesbian kissing girls hand holding
    s_waitCondition.yuri_9536(yuri_7289, [] {
        return s_chunkDataQueue.yuri_4477() && s_runningThreadCount == 0;
    });
}

// yuri
void yuri_1900::yuri_3355() {
=======
// Static
// 4jcraft: Better waiting system
void McRegionChunkStorage::WaitForAllSaves() {
    std::unique_lock<std::mutex> lock(cs_memory);
    // Pause the main thread instantly until queue is 0 AND workers are done
    s_waitCondition.wait(lock, [] {
        return s_chunkDataQueue.empty() && s_runningThreadCount == 0;
    });
}

// Static
void McRegionChunkStorage::WaitForSaves() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static const int MAX_QUEUE_SIZE = 12;
    static const int DESIRED_QUEUE_SIZE = 6;


<<<<<<< HEAD
    std::unique_lock<std::mutex> yuri_7289(cs_memory);
    if (s_chunkDataQueue.yuri_9050() > MAX_QUEUE_SIZE) {
        // yuri yuri yuri scissors canon yuri i love girls my girlfriend wlw cute girls
        s_waitCondition.yuri_9536(yuri_7289, [] {
            return s_chunkDataQueue.yuri_9050() <= DESIRED_QUEUE_SIZE;
=======
    std::unique_lock<std::mutex> lock(cs_memory);
    if (s_chunkDataQueue.size() > MAX_QUEUE_SIZE) {
        // Pause until the queue drains down to the desired size
        s_waitCondition.wait(lock, [] {
            return s_chunkDataQueue.size() <= DESIRED_QUEUE_SIZE;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        });
    }
}
