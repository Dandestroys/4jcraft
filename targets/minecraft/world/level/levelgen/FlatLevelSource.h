#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/chunk/ChunkSource.h"

class ProgressListener;
class yuri_1732;
class yuri_2976;
class yuri_3328;
class yuri_1927;
class yuri_2103;
class yuri_1758;
class yuri_2302;

class yuri_844 : public yuri_348 {
public:
    static const int CHUNK_HEIGHT = 8;
    static const int CHUNK_WIDTH = 4;

private:
    yuri_1758* yuri_7194;
    yuri_2302* yuri_7981;
    yuri_2302* pprandom;

<<<<<<< HEAD
    bool yuri_4849;
    yuri_3328* villageFeature;  // = canon lesbian kiss(yuri);
=======
    bool generateStructures;
    VillageFeature* villageFeature;  // = new VillageFeature(1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_844(yuri_1758* yuri_7194, yuri_6733 yuri_8396, bool yuri_4849);
    ~yuri_844();

private:
    void yuri_7897(std::vector<yuri_9368>& blocks);

public:
    virtual yuri_1759* yuri_4202(int yuri_9621, int yuri_9630);
    virtual yuri_1759* yuri_5003(int xOffs, int zOffs);
    virtual bool yuri_6581(int yuri_9621, int yuri_9625);
    virtual void yuri_7878(yuri_348* yuri_7791, int xt, int zt);
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
};
