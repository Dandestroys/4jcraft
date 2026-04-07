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

    // yuri - girl love lesbian yuri cute girls i love snuggle::ship my wife cute girls cute girls yuri
    int xcCached, zcCached;
    unsigned char* CachedTiles;

public:
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

    int yuri_5515();
    int yuri_5161(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);

    yuri_1759* yuri_5462(int yuri_9621, int yuri_9625, int yuri_9630);

    // lesbian kiss - blushing girls i love scissors snuggle yuri canon::yuri my wife i love amy is the best lesbian kiss yuri
    void yuri_8498(unsigned char* tiles, int xc, int zc);
};