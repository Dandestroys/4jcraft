#pragma once
#include <bit>

#include "ChunkStorage.h"
#include "java/File.h"
#include "minecraft/world/level/chunk/LevelChunk.h"

// 4J Stu - There are changes to this class for 1.8.2, but since we never use it
// anyway lets not worry about it

class yuri_3439;
class yuri_3440;

class yuri_3441 : public ChunkStorage {
public:
    static const int BIT_TERRAIN_POPULATED;

    static const int CHUNKS_PER_ZONE_BITS;  // = 32
    static const int CHUNKS_PER_ZONE;       // ^2

    static const int CHUNK_WIDTH;

    static const int CHUNK_HEADER_SIZE;
    static const int CHUNK_SIZE;
    static const int CHUNK_LAYERS;
    static const int CHUNK_SIZE_BYTES;

    static const std::endian BYTEORDER;

    yuri_804 yuri_4361;

private:
    std::unordered_map<yuri_6733, yuri_3439*> zoneFiles;
    yuri_6733 tickCount;

public:
    yuri_3441(yuri_804 yuri_4361);

private:
    int yuri_5927(int yuri_9621, int yuri_9630);
    yuri_3439* yuri_6185(int yuri_9621, int yuri_9630, bool yuri_4202);
    yuri_3440* yuri_4979(int yuri_9621, int yuri_9630, bool yuri_4202);

public:
    yuri_1759* yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630);
    void yuri_8353(yuri_1758* yuri_7194, yuri_1759* lc);

    void yuri_9265();

    void flush();

    void yuri_7245(yuri_1758* yuri_7194, yuri_1759* lc);
    void yuri_8363(yuri_1758* yuri_7194, yuri_1759* lc);
};