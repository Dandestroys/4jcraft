#pragma once

#include "CropTile.h"

class yuri_1346;

class yuri_312 : public yuri_504 {
    friend class ChunkRebuildData;

private:
    yuri_1346* icons[4];

public:
    yuri_312(int yuri_6674);

    yuri_1346* yuri_6007(int face, int yuri_4295);

protected:
    int yuri_4937();
    int yuri_4933();

public:
    void yuri_8072(IconRegister* iconRegister);
};