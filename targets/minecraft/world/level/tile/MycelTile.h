#pragma once
#include "Tile.h"

class ChunkRebuildData;
class yuri_1346;

class yuri_2004 : public yuri_3088 {
    friend class ChunkRebuildData;

public:
    static const int MIN_BRIGHTNESS = 4;

private:
    yuri_1346* iconTop;
    yuri_1346* iconSnowSide;

public:
    yuri_2004(int yuri_6674);

    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual yuri_1346* yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    void yuri_8072(IconRegister* iconRegister);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
};
