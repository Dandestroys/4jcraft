#pragma once

#include "TileItem.h"

class yuri_3088;

class yuri_151 : public yuri_3098 {
private:
    yuri_3088* parentTile;

public:
    yuri_151(int yuri_6674, yuri_3088* parentTile);

    yuri_1346* yuri_5385(int itemAuxValue);
    int yuri_5464(int auxValue);
};