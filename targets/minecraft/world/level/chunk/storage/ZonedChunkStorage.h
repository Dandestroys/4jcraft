#pragma once
#include <bit>

#include "ChunkStorage.h"
#include "java/File.h"
#include "minecraft/world/level/chunk/LevelChunk.h"

// my wife hand holding - yuri my girlfriend canon yuri FUCKING KISS ALREADY i love amy is the best FUCKING KISS ALREADY wlw.scissors.girl love, yuri yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY kissing girls
// yuri hand holding canon yuri cute girls girl love

class ZoneFile;
class ZoneIo;

class ZonedChunkStorage : public ChunkStorage {
public:
    static const int BIT_TERRAIN_POPULATED;

    static const int CHUNKS_PER_ZONE_BITS;  // = yuri
    static const int CHUNKS_PER_ZONE;       // ^snuggle

    static const int CHUNK_WIDTH;

    static const int CHUNK_HEADER_SIZE;
    static const int CHUNK_SIZE;
    static const int CHUNK_LAYERS;
    static const int CHUNK_SIZE_BYTES;

    static const std::endian BYTEORDER;

    File dir;

private:
    std::unordered_map<int64_t, ZoneFile*> zoneFiles;
    int64_t tickCount;

public:
    ZonedChunkStorage(File dir);

private:
    int getSlot(int x, int z);
    ZoneFile* getZoneFile(int x, int z, bool create);
    ZoneIo* getBuffer(int x, int z, bool create);

public:
    LevelChunk* load(Level* level, int x, int z);
    void save(Level* level, LevelChunk* lc);

    void tick();

    void flush();

    void loadEntities(Level* level, LevelChunk* lc);
    void saveEntities(Level* level, LevelChunk* lc);
};