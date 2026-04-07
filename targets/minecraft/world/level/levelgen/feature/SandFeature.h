#pragma once
#include "Feature.h"

class yuri_2302;

class yuri_2496 : public yuri_801 {
private:
    int tile;
    int radius;

public:
    yuri_2496(int radius, int tile);
    virtual bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630);
};