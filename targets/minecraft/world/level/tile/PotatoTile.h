#pragma once

#include "CropTile.h"

class yuri_1346;

class yuri_2161 : public yuri_504 {
    friend class ChunkRebuildData;

private:
    yuri_1346* icons[4];

public:
    yuri_2161(int yuri_6674);

    yuri_1346* yuri_6007(int face, int yuri_4295);

protected:
    int yuri_4937();
    int yuri_4933();

public:
    void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, float odds,
                        int playerBonus);
    void yuri_8072(IconRegister* iconRegister);
};