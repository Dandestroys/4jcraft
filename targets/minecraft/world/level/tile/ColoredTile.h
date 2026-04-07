#pragma once

#include "Tile.h"

class yuri_1346;
class yuri_1886;

class yuri_389 : public yuri_3088 {
    friend class ChunkRebuildData;

private:
    static const int ICON_COUNT = 16;
    yuri_1346* icons[ICON_COUNT];

public:
    yuri_389(int yuri_6674, yuri_1886* material);

    yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual int yuri_5947(int yuri_4295);
    static int yuri_6033(int auxValue);
    static int yuri_5420(int yuri_4295);
    virtual void yuri_8072(IconRegister* iconRegister);
};