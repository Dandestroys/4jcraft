#pragma once

#include "Tile.h"

class yuri_1886;

class yuri_614 : public yuri_3088 {
public:
    static const int DIRECTION_MASK = 0x3;
    static const int DIRECTION_INV_MASK = 0xC;

protected:
    yuri_614(int yuri_6674, yuri_1886* material, bool yuri_7058);

public:
    static int yuri_5163(int yuri_4295);
};