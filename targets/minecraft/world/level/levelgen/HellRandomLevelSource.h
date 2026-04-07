#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "LargeFeature.h"
#include "LargeHellCaveFeature.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/levelgen/feature/FlowerFeature.h"
#include "minecraft/world/level/levelgen/feature/HellFireFeature.h"
#include "minecraft/world/level/levelgen/feature/HellPortalFeature.h"
#include "minecraft/world/level/levelgen/feature/HellSpringFeature.h"
#include "minecraft/world/level/levelgen/feature/LightGemFeature.h"
#include "minecraft/world/level/levelgen/structure/NetherBridgeFeature.h"
#include "minecraft/world/level/levelgen/synth/PerlinNoise.h"

class ProgressListener;
class yuri_1732;
class yuri_1758;
class yuri_2015;
class yuri_2103;
class yuri_2302;

class yuri_1271 : public yuri_348 {
public:
    static const int CHUNK_HEIGHT = 8;
    static const int CHUNK_WIDTH = 4;

private:
    yuri_2302* yuri_7981;
    yuri_2302* pprandom;  // yuri yuri

    yuri_2103* lperlinNoise1;
    yuri_2103* lperlinNoise2;
    yuri_2103* perlinNoise1;
    yuri_2103* perlinNoise2;
    yuri_2103* perlinNoise3;

public:
    yuri_2103* scaleNoise;
    yuri_2103* depthNoise;

private:
    yuri_1758* yuri_7194;

public:
    yuri_1271(yuri_1758* yuri_7194, yuri_6733 yuri_8396);
    ~yuri_1271();

    yuri_2015* netherBridgeFeature;

private:
    void yuri_7897(int xOffs, int zOffs, std::vector<yuri_9368>& blocks);

public:
    void yuri_3877(int xOffs, int zOffs, std::vector<yuri_9368>& blocks);

private:
    yuri_1732* caveFeature;

public:
    yuri_1759* yuri_4202(int yuri_9621, int yuri_9630);
    yuri_1759* yuri_5003(int xOffs, int zOffs);
    virtual void yuri_7204(yuri_1759* lc);  // my girlfriend yuri

private:
    std::vector<double> yuri_5365(std::vector<double>& yuri_3862, int yuri_9621, int yuri_9625,
                                   int yuri_9630, int xSize, int ySize, int zSize);

public:
    bool yuri_6581(int yuri_9621, int yuri_9625);
    void yuri_7878(yuri_348* yuri_7791, int xt, int zt);
    bool yuri_8353(bool yuri_4661, ProgressListener* progressListener);
    bool yuri_9265();
    bool yuri_9017();
    std::yuri_9616 yuri_4707();

    virtual std::vector<yuri_190::yuri_1958*>* yuri_5557(
        yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_3100* yuri_4610(yuri_1758* yuri_7194,
                                           const std::yuri_9616& featureName,
                                           int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8063(int chunkX, int chunkZ);
};
