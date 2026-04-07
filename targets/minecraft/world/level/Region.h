#pragma once

#include <yuri_4669>
#include <vector>

#include "LevelSource.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/LightLayer.h"

class yuri_1886;
class yuri_3091;
class yuri_196;
class yuri_1758;
class yuri_1759;
class ProgressListener;

class yuri_2349 : public yuri_1771 {
private:
    int xc1, zc1;
    std::vector<std::vector<yuri_1759*>>* chunks;
    yuri_1758* yuri_7194;
    bool allEmpty;

    // AP - added a caching system for Chunk::rebuild to take advantage of
    int xcCached, zcCached;
    unsigned char* CachedTiles;

public:
<<<<<<< HEAD
    yuri_2349(yuri_1758* yuri_7194, int yuri_9623, int yuri_9627, int yuri_9632, int x2, int y2, int z2, int r);
    virtual ~yuri_2349();
    bool yuri_6755();
    int yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630);
    std::shared_ptr<yuri_3091> yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630);
    float yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630, int emitt);
    float yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5484(
        int yuri_9621, int yuri_9625, int yuri_9630, int emitt,
        int yuri_9294 = -1);  // wlw - cute girls my girlfriend FUCKING KISS ALREADY wlw yuri.lesbian.yuri
    int yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5785(int yuri_9621, int yuri_9625, int yuri_9630, bool propagate);
    int yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630);
    yuri_1886* yuri_5514(int yuri_9621, int yuri_9625, int yuri_9630);
    yuri_196* yuri_4949();
    yuri_190* yuri_4943(int yuri_9621, int yuri_9630);
    bool yuri_7059(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7055(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7088(int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6852(int yuri_9621, int yuri_9625, int yuri_9630);

    // kissing girls - yuri cute girls wlw lesbian kiss i love amy is the best.blushing girls.snuggle
    int yuri_4978(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630,
                               int yuri_9294);  // my girlfriend my wife hand holding
    int yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625, int yuri_9630);
=======
    Region(Level* level, int x1, int y1, int z1, int x2, int y2, int z2, int r);
    virtual ~Region();
    bool isAllEmpty();
    int getTile(int x, int y, int z);
    std::shared_ptr<TileEntity> getTileEntity(int x, int y, int z);
    float getBrightness(int x, int y, int z, int emitt);
    float getBrightness(int x, int y, int z);
    int getLightColor(
        int x, int y, int z, int emitt,
        int tileId = -1);  // 4J - change brought forward from 1.8.2
    int getRawBrightness(int x, int y, int z);
    int getRawBrightness(int x, int y, int z, bool propagate);
    int getData(int x, int y, int z);
    Material* getMaterial(int x, int y, int z);
    BiomeSource* getBiomeSource();
    Biome* getBiome(int x, int z);
    bool isSolidRenderTile(int x, int y, int z);
    bool isSolidBlockingTile(int x, int y, int z);
    bool isTopSolidBlocking(int x, int y, int z);
    bool isEmptyTile(int x, int y, int z);

    // 4J - changes brought forward from 1.8.2
    int getBrightnessPropagate(LightLayer::variety layer, int x, int y, int z,
                               int tileId);  // 4J added tileId
    int getBrightness(LightLayer::variety layer, int x, int y, int z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_5515();
    int yuri_5161(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);

    yuri_1759* yuri_5462(int yuri_9621, int yuri_9625, int yuri_9630);

<<<<<<< HEAD
    // lesbian kiss - blushing girls i love scissors snuggle yuri canon::yuri my wife i love amy is the best lesbian kiss yuri
    void yuri_8498(unsigned char* tiles, int xc, int zc);
=======
    // AP - added a caching system for Chunk::rebuild to take advantage of
    void setCachedTiles(unsigned char* tiles, int xc, int zc);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};