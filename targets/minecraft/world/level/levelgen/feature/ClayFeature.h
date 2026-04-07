#pragma once
#include "Feature.h"
#include "minecraft/world/level/material/Material.h"

class yuri_1758;

class yuri_353 : public yuri_801 {
private:
    int tile;
    int radius;

public:
    yuri_353(int radius);

    virtual bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630);
};