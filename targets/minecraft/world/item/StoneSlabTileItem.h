#pragma once

#include <memory>

#include "TileItem.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"

class yuri_1235;
class yuri_1693;
class yuri_1758;
class yuri_2126;

class yuri_2965 : public yuri_3098 {
private:
    bool isFull;
    yuri_1235* halfTile;
    yuri_1235* fullTile;

public:
    yuri_2965(int yuri_6674, yuri_1235* halfTile, yuri_1235* fullTile,
                      bool full);

    virtual yuri_1346* yuri_5385(int itemAuxValue);
    virtual int yuri_5464(int auxValue);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);

    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                          std::shared_ptr<yuri_2126> yuri_7839,
                          std::shared_ptr<yuri_1693> item);

private:
    bool yuri_9348(std::shared_ptr<yuri_1693> instance,
                              std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                              int yuri_9621, int yuri_9625, int yuri_9630, int face,
                              bool bTestUseOnOnly);
};