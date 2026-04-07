#pragma once

#include <memory>

#include "Tile.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_853 : public yuri_3088 {
public:
    static const int TYPE_FLOWER_RED = 1;
    static const int TYPE_FLOWER_YELLOW = 2;
    static const int TYPE_SAPLING_DEFAULT = 3;
    static const int TYPE_SAPLING_EVERGREEN = 4;
    static const int TYPE_SAPLING_BIRCH = 5;
    static const int TYPE_SAPLING_JUNGLE = 6;
    static const int TYPE_MUSHROOM_RED = 7;
    static const int TYPE_MUSHROOM_BROWN = 8;
    static const int TYPE_CACTUS = 9;
    static const int TYPE_DEAD_BUSH = 10;
    static const int TYPE_FERN = 11;

    yuri_853(int yuri_6674);

    void yuri_9402();
    bool yuri_7058(bool isServerLevel = false);
    int yuri_5806();
    bool yuri_6827();
    bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
             int clickedFace, float clickX, float clickY, float clickZ,
             bool soundOnly = false);
    int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_9493();
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    using yuri_3088::yuri_9087;
    void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, float odds,
                        int playerBonusLevel);
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    static std::shared_ptr<yuri_1693> yuri_5424(int yuri_9364);
    static int yuri_6069(std::shared_ptr<yuri_1693> item);
};