#pragma once

#include "HalfSlabTile.h"

class ChunkRebuildData;
class yuri_1346;

class yuri_2964 : public yuri_1235 {
    friend ChunkRebuildData;

public:
    static const int STONE_SLAB = 0;
    static const int SAND_SLAB = 1;
    static const int WOOD_SLAB = 2;
    static const int COBBLESTONE_SLAB = 3;
    static const int BRICK_SLAB = 4;
    static const int SMOOTHBRICK_SLAB = 5;
    static const int NETHERBRICK_SLAB = 6;
    static const int QUARTZ_SLAB = 7;

    static const int SLAB_NAMES_LENGTH = 8;

    static const unsigned int SLAB_NAMES[SLAB_NAMES_LENGTH];

private:
    yuri_1346* iconSide;

public:
    yuri_2964(int yuri_6674, bool fullSize);

    virtual yuri_1346* yuri_6007(int face, int yuri_4295);

    void yuri_8072(IconRegister* iconRegister);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual unsigned int yuri_5148(int iData = -1);
    virtual int yuri_4918(int auxValue);

protected:
    virtual std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);
};