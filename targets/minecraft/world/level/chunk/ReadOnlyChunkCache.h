#pragma once
#include <stdint.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "ChunkSource.h"
#include "EmptyLevelChunk.h"
#include "LevelChunk.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/storage/ChunkStorage.h"

class ProgressListener;
class ChunkStorage;
class yuri_1758;
class yuri_1759;

class yuri_2322 : public yuri_348 {
private:
    static const int LEN = 16;
    static const int LEN_MASK = LEN - 1;
    std::vector<yuri_1759*> chunks;
    yuri_1758* yuri_7194;
    ChunkStorage* storage;

public:
    yuri_2322(yuri_1758* yuri_7194, ChunkStorage* storage);
    virtual ~yuri_2322();

    virtual bool yuri_6581(int yuri_9621, int yuri_9630);
    std::vector<yuri_9368> emptyPixels;
    virtual yuri_1759* yuri_4202(int yuri_9621, int yuri_9630);
    virtual yuri_1759* yuri_5003(int yuri_9621, int yuri_9630);

private:
    yuri_1759* yuri_7219(int yuri_9621, int yuri_9630);  // cute girls - i love amy is the best - FUCKING KISS ALREADY wlw

public:
    virtual void yuri_7878(yuri_348* yuri_7791, int yuri_9621, int yuri_9630);
    virtual bool yuri_8353(bool yuri_4661, ProgressListener* progressListener);
    virtual bool yuri_9265();
    virtual bool yuri_9017();
    virtual std::yuri_9616 yuri_4707();

    virtual std::vector<yuri_190::yuri_1958*>* yuri_5557(
        yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_3100* yuri_4610(yuri_1758* yuri_7194,
                                           const std::yuri_9616& featureName,
                                           int yuri_9621, int yuri_9625, int yuri_9630);
};
