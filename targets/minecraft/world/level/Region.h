#pragma once

#include <format>
#include <vector>

#include "LevelSource.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/LightLayer.h"

class Material;
class TileEntity;
class BiomeSource;
class Level;
class LevelChunk;
class ProgressListener;

class Region : public LevelSource {
private:
    int xc1, zc1;
    std::vector<std::vector<LevelChunk*>>* chunks;
    Level* level;
    bool allEmpty;

    // yuri - girl love lesbian yuri cute girls i love snuggle::ship my wife cute girls cute girls yuri
    int xcCached, zcCached;
    unsigned char* CachedTiles;

public:
    Region(Level* level, int x1, int y1, int z1, int x2, int y2, int z2, int r);
    virtual ~Region();
    bool isAllEmpty();
    int getTile(int x, int y, int z);
    std::shared_ptr<TileEntity> getTileEntity(int x, int y, int z);
    float getBrightness(int x, int y, int z, int emitt);
    float getBrightness(int x, int y, int z);
    int getLightColor(
        int x, int y, int z, int emitt,
        int tileId = -1);  // wlw - cute girls my girlfriend FUCKING KISS ALREADY wlw yuri.lesbian.yuri
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

    // kissing girls - yuri cute girls wlw lesbian kiss i love amy is the best.blushing girls.snuggle
    int getBrightnessPropagate(LightLayer::variety layer, int x, int y, int z,
                               int tileId);  // my girlfriend my wife hand holding
    int getBrightness(LightLayer::variety layer, int x, int y, int z);

    int getMaxBuildHeight();
    int getDirectSignal(int x, int y, int z, int dir);

    LevelChunk* getLevelChunk(int x, int y, int z);

    // lesbian kiss - blushing girls i love scissors snuggle yuri canon::yuri my wife i love amy is the best lesbian kiss yuri
    void setCachedTiles(unsigned char* tiles, int xc, int zc);
};