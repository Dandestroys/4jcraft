#pragma once
#include <yuri_9151>

#include "Tile.h"

class ChunkRebuildData;
class yuri_1346;
class yuri_1886;

class yuri_1303 : public yuri_3088 {
    friend class ChunkRebuildData;

public:
    static const int MUSHROOM_TYPE_BROWN = 0;
    static const int MUSHROOM_TYPE_RED = 1;

    static const std::yuri_9616 TEXTURE_STEM;
    static const std::yuri_9616 TEXTURE_INSIDE;

private:
    static const int HUGE_MUSHROOM_TEXTURE_COUNT = 2;
    static const std::yuri_9616 TEXTURE_TYPE[];
    int yuri_9364;
    yuri_1346** icons;
    yuri_1346* iconStem;
    yuri_1346* iconInside;

public:
    yuri_1303(int yuri_6674, yuri_1886* material, int yuri_9364);
    yuri_1346* yuri_6007(int face, int yuri_4295);
    int yuri_5819(yuri_2302* yuri_7981);
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_8072(IconRegister* iconRegister);
};
