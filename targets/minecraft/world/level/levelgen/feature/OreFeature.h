#pragma once
#include "Feature.h"

class yuri_1758;

class yuri_2061 : public yuri_801 {
private:
    int tile;
    int yuri_4184;
    int targetTile;

    void yuri_3547(int tile, int yuri_4184, int targetTile);

public:
    yuri_2061(int tile, int yuri_4184);
    yuri_2061(int tile, int yuri_4184, int targetTile);

    virtual bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630);
};