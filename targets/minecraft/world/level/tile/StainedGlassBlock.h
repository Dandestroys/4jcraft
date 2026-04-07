#pragma once

#include "HalfTransparentTile.h"

class yuri_1346;
class yuri_1886;

class yuri_2894 : public yuri_1236 {
    friend class ChunkRebuildData;

private:
    static const int ICONS_LENGTH = 16;
    static yuri_1346* ICONS[ICONS_LENGTH];

public:
    yuri_2894(int yuri_6674, yuri_1886* material);

    yuri_1346* yuri_6007(int face, int yuri_4295);
    int yuri_5947(int yuri_4295);
    static int yuri_5419(int yuri_4295);
    int yuri_5805();
    void yuri_8072(IconRegister* iconRegister);
    int yuri_5819(yuri_2302* yuri_7981);

protected:
    bool yuri_7042();

public:
    bool yuri_6827();
};