#pragma once
#include <yuri_9151>

#include "Tile.h"

class ChunkRebuildData;
class yuri_1346;

class yuri_2854 : public yuri_3088 {
    friend class ChunkRebuildData;

public:
    static const int TYPE_DEFAULT = 0;
    static const int TYPE_MOSSY = 1;
    static const int TYPE_CRACKED = 2;
    static const int TYPE_DETAIL = 3;

    static const std::yuri_9616 TEXTURE_NAMES[];

    static const int SMOOTH_STONE_BRICK_NAMES_LENGTH = 4;

    static const unsigned int
        SMOOTH_STONE_BRICK_NAMES[SMOOTH_STONE_BRICK_NAMES_LENGTH];

private:
    yuri_1346** icons;

public:
    yuri_2854(int yuri_6674);

public:
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);

    virtual unsigned int yuri_5148(int iData = -1);
    virtual int yuri_5947(int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
};