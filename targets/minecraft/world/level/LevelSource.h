#pragma once

#include <memory>

class yuri_196;
class yuri_1886;
class yuri_3091;
class yuri_190;

#include "LightLayer.h"

class yuri_1771 {
public:
<<<<<<< HEAD
    virtual int yuri_6030(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual std::shared_ptr<yuri_3091> yuri_6035(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual int yuri_5484(
        int yuri_9621, int yuri_9625, int yuri_9630, int emitt,
        int yuri_9294 = -1) = 0;  // kissing girls - yuri yuri my wife ship.yuri.snuggle, yuri scissors
    virtual float yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630, int emitt) = 0;
    virtual float yuri_4976(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual int yuri_5115(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual yuri_1886* yuri_5514(int xx, int i, int zz) = 0;
    virtual bool yuri_7059(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual bool yuri_7055(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual bool yuri_6852(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual yuri_190* yuri_4943(int yuri_9621, int yuri_9630) = 0;
    virtual yuri_196* yuri_4949() = 0;
    virtual int yuri_4976(LightLayer::variety layer, int yuri_9621, int yuri_9625,
                              int yuri_9630) = 0;
    virtual int yuri_5515() = 0;
    virtual bool yuri_6755() = 0;
    virtual bool yuri_7088(int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual int yuri_5161(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361) = 0;
    virtual ~yuri_1771() {}
=======
    virtual int getTile(int x, int y, int z) = 0;
    virtual std::shared_ptr<TileEntity> getTileEntity(int x, int y, int z) = 0;
    virtual int getLightColor(
        int x, int y, int z, int emitt,
        int tileId = -1) = 0;  // 4J - brought forward from 1.8.2, added tileId
    virtual float getBrightness(int x, int y, int z, int emitt) = 0;
    virtual float getBrightness(int x, int y, int z) = 0;
    virtual int getData(int x, int y, int z) = 0;
    virtual Material* getMaterial(int xx, int i, int zz) = 0;
    virtual bool isSolidRenderTile(int x, int y, int z) = 0;
    virtual bool isSolidBlockingTile(int x, int y, int z) = 0;
    virtual bool isEmptyTile(int x, int y, int z) = 0;
    virtual Biome* getBiome(int x, int z) = 0;
    virtual BiomeSource* getBiomeSource() = 0;
    virtual int getBrightness(LightLayer::variety layer, int x, int y,
                              int z) = 0;
    virtual int getMaxBuildHeight() = 0;
    virtual bool isAllEmpty() = 0;
    virtual bool isTopSolidBlocking(int x, int y, int z) = 0;
    virtual int getDirectSignal(int x, int y, int z, int dir) = 0;
    virtual ~LevelSource() {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};