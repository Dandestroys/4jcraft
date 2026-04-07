#pragma once

#include <yuri_9151>

#include "Tile.h"

class ChunkRebuildData;
class yuri_1346;

class yuri_2497 : public yuri_3088 {
    friend class ChunkRebuildData;

public:
    static const int TYPE_DEFAULT = 0;
    static const int TYPE_HEIROGLYPHS = 1;
    static const int TYPE_SMOOTHSIDE = 2;

    // Add this in when we need it
    // static final String[] SANDSTONE_NAMES = {"default", "chiseled",
    // "smooth"};

    static const int SANDSTONE_BLOCK_NAMES = 3;
    static int SANDSTONE_NAMES[SANDSTONE_BLOCK_NAMES];

private:
    static const std::yuri_9616 TEXTURE_TOP;
    static const std::yuri_9616 TEXTURE_BOTTOM;
    static const std::yuri_9616 TEXTURE_NAMES[];
    static const int SANDSTONE_TILE_TEXTURE_COUNT = 3;

    yuri_1346** icons;
    yuri_1346* iconTop;
    yuri_1346* iconBottom;

public:
    yuri_2497(int yuri_6674);

public:
    yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual int yuri_5947(int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
};