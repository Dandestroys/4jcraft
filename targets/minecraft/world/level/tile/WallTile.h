#pragma once

#include <memory>

#include "Tile.h"

class yuri_1771;

class yuri_3358 : public yuri_3088 {
public:
    static const float WALL_WIDTH;
    static const float WALL_HEIGHT;
    static const float POST_WIDTH;
    static const float POST_HEIGHT;

    static const int TYPE_NORMAL = 0;
    static const int TYPE_MOSSY = 1;

    static const unsigned int COBBLE_NAMES[2];

    yuri_3358(int yuri_6674, yuri_3088* baseTile);

    yuri_1346* yuri_6007(int face, int yuri_4295);
    int yuri_5806();
    bool yuri_6827();
    bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7058(bool isServerLevel = false);
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_4140(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5947(int yuri_4295);
    bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    void yuri_8072(IconRegister* iconRegister);
};
