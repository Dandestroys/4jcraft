#pragma once
#include "Tile.h"

class yuri_2302;

class yuri_2063 : public yuri_3088 {
public:
    yuri_2063(int yuri_6674);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_5820(int bonusLevel, yuri_2302* yuri_7981);
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonusLevel);

protected:
    virtual int yuri_5947(int yuri_4295);
};