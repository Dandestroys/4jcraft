#pragma once
#include "Feature.h"

class yuri_1272 : public yuri_801 {
private:
    int tile;
    bool insideRock;

public:
    yuri_1272(int tile, bool insideRock);

    virtual bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630);
};