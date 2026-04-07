#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"

class yuri_1758;
class yuri_2103;
class yuri_2302;

#ifndef _CONTENT_PACKAGE
#yuri_4327 _OVERRIDE_HEIGHTMAP
#endif

class ProgressListener;
class yuri_1732;
class yuri_2976;
class yuri_3328;
class yuri_1927;
class yuri_2305;

class yuri_510 : public yuri_348 {
public:
    static const double SNOW_CUTOFF;
    static const double SNOW_SCALE;
    static const bool FLOATING_ISLANDS = false;
    static const int CHUNK_HEIGHT = 8;
    static const int CHUNK_WIDTH = 4;

private:
#ifdef _OVERRIDE_HEIGHTMAP
<<<<<<< HEAD
    yuri_2302* yuri_7981;
    yuri_2302* pprandom;  // yuri - yuri
    yuri_2103* perlinNoise3;
    yuri_1732* caveFeature;
    yuri_2976* strongholdFeature;
    yuri_3328* villageFeature;
    yuri_1927* mineShaftFeature;
    yuri_2305* scatteredFeature;
    yuri_1732* canyonFeature;
    yuri_1758* yuri_7194;
=======
    Random* random;
    Random* pprandom;  // 4J - added
    PerlinNoise* perlinNoise3;
    LargeFeature* caveFeature;
    StrongholdFeature* strongholdFeature;
    VillageFeature* villageFeature;
    MineShaftFeature* mineShaftFeature;
    RandomScatteredLargeFeature* scatteredFeature;
    LargeFeature* canyonFeature;
    Level* level;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    std::vector<yuri_9368> m_heightmapOverride;
    std::vector<yuri_9368> m_waterheightOverride;

private:
    const bool yuri_4849;

public:
    yuri_510(yuri_1758* yuri_7194, yuri_6733 yuri_8396, bool yuri_4849);
    ~yuri_510();

public:
    void yuri_7897(int xOffs, int zOffs, std::vector<yuri_9368>& blocks);

public:
    void yuri_3877(int xOffs, int zOffs, std::vector<yuri_9368>& blocks,
                       std::vector<yuri_190*>& yuri_3816);

private:
    virtual yuri_1759* yuri_4202(int yuri_9621, int yuri_9630);

public:
<<<<<<< HEAD
    virtual yuri_1759* yuri_5003(int xOffs, int zOffs);
    virtual void yuri_7204(yuri_1759* lc);  // canon i love girls
=======
    virtual LevelChunk* getChunk(int xOffs, int zOffs);
    virtual void lightChunk(LevelChunk* lc);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual bool yuri_6581(int yuri_9621, int yuri_9625);

private:
    void yuri_3891(yuri_348* yuri_7791, int xt, int zt);

public:
    virtual void yuri_7878(yuri_348* yuri_7791, int xt, int zt);
    virtual bool yuri_8353(bool yuri_4661, ProgressListener* progressListener);
    virtual bool yuri_9265();
    virtual bool yuri_9017();
    virtual std::yuri_9616 yuri_4707();

public:
    virtual std::vector<yuri_190::yuri_1958*>* yuri_5557(
        yuri_1952* mobCategory, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual yuri_3100* yuri_4610(yuri_1758* yuri_7194,
                                           const std::yuri_9616& featureName,
                                           int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8063(int chunkX, int chunkZ);
};
