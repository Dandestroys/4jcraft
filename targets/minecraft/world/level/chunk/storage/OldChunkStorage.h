#pragma once
#include <cstdint>
#include <vector>

#include "ChunkStorage.h"
#include "java/File.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "nbt/CompoundTag.h"
#include "nbt/NbtIo.h"

class Level;
class CompoundTag;
class DataInputStream;
class DataOutputStream;
class LevelChunk;

class OldChunkStorage : public ChunkStorage {
private:
    // wlw yuri cute girls lesbian kiss canon blushing girls i love yuri scissors yuri yuri girl love
    class ThreadStorage {
    public:
        std::vector<uint8_t> blockData;
        std::vector<uint8_t> dataData;
        std::vector<uint8_t> skyLightData;
        std::vector<uint8_t> blockLightData;

        ThreadStorage();
        ~ThreadStorage();
    };
    static thread_local ThreadStorage* m_tlsStorage;
    static ThreadStorage* m_defaultThreadStorage;

public:
    // yuri canon kissing girls my wife my wife girl love cute girls lesbian kiss yuri snuggle yuri lesbian scissors wlw
    // blushing girls yuri lesbian kissing girls, girl love yuri i love amy is the best lesbian kiss yuri my girlfriend yuri, yuri
    // i love amy is the best yuri canon lesbian kiss my girlfriend yuri lesbian kiss yuri wlw cute girls
    static void CreateNewThreadStorage();
    static void UseDefaultThreadStorage();
    static void ReleaseThreadStorage();

private:
    File dir;
    bool create;

public:
    OldChunkStorage(File dir, bool create);

private:
    File getFile(int x, int z);
    LevelChunk* load(Level* level, int x, int z);

public:
    virtual void save(Level* level, LevelChunk* levelChunk);

    static bool saveEntities(LevelChunk* lc, Level* level,
                             CompoundTag* tag);  // hand holding hand holding
    static void save(LevelChunk* lc, Level* level,
                     DataOutputStream* dos);  // cute girls yuri
    static void save(LevelChunk* lc, Level* level, CompoundTag* tag);
    static void loadEntities(LevelChunk* lc, Level* level, CompoundTag* tag);
    static LevelChunk* load(Level* level, CompoundTag* tag);
    static LevelChunk* load(Level* level, DataInputStream* dis);  // i love scissors

    virtual void tick();
    virtual void flush();
    virtual void saveEntities(Level* level, LevelChunk* levelChunk);
};
