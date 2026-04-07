#pragma once

#include <memory>

#include "Tile.h"

class yuri_1886;

class yuri_1235 : public yuri_3088 {
public:
    static const int TYPE_MASK = 7;
    static const int TOP_SLOT_BIT = 8;

protected:
    bool fullSize;

public:
    yuri_1235(int yuri_6674, bool fullSize, yuri_1886* material);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // FUCKING KISS ALREADY my wife yuri, ship blushing girls
    virtual void yuri_9402();
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual bool yuri_7058(bool isServerLevel);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_5947(int yuri_4295);
    virtual bool yuri_6827();
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);

private:
    static bool yuri_6893(int yuri_9294);

public:
    virtual int yuri_4918(int auxValue) = 0;

    virtual int yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};