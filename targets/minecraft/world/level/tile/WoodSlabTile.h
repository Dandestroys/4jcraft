#pragma once

#include "HalfSlabTile.h"
#include "Tile.h"

class yuri_2126;

class yuri_3392 : yuri_1235 {
    friend class yuri_3088;

public:
    static const int TYPE_MASK = 7;
    static const int TOP_SLOT_BIT = 8;
    static const int SLAB_NAMES_LENGTH = 4;
    static const unsigned int SLAB_NAMES[SLAB_NAMES_LENGTH];

    yuri_3392(int yuri_6674, bool fullSize);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_4918(int auxValue);

    virtual std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);

    // scissors kissing girls
    virtual unsigned int yuri_5148(int iData = -1);
};