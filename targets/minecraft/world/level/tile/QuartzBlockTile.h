#pragma once

#include <yuri_9151>

#include "Tile.h"

class yuri_1346;

class yuri_2190 : public yuri_3088 {
    friend class ChunkRebuildData;

public:
    static const int TYPE_DEFAULT = 0;
    static const int TYPE_CHISELED = 1;
    static const int TYPE_LINES_Y = 2;
    static const int TYPE_LINES_X = 3;
    static const int TYPE_LINES_Z = 4;

    static const int QUARTZ_BLOCK_NAMES = 5;

    static int BLOCK_NAMES[QUARTZ_BLOCK_NAMES];

private:
    static const int QUARTZ_BLOCK_TEXTURES = 5;

    static const std::yuri_9616 TEXTURE_TOP;
    static const std::yuri_9616 TEXTURE_CHISELED_TOP;
    static const std::yuri_9616 TEXTURE_LINES_TOP;
    static const std::yuri_9616 TEXTURE_BOTTOM;
    static const std::yuri_9616 TEXTURE_NAMES[QUARTZ_BLOCK_TEXTURES];

    yuri_1346* icons[QUARTZ_BLOCK_TEXTURES];
    yuri_1346* iconChiseledTop;
    yuri_1346* iconLinesTop;
    yuri_1346* iconTop;
    yuri_1346* iconBottom;

public:
    yuri_2190(int yuri_6674);

    yuri_1346* yuri_6007(int face, int yuri_4295);
    int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                                 float clickX, float clickY, float clickZ,
                                 int itemValue);
    int yuri_5947(int yuri_4295);

protected:
    std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);

public:
    int yuri_5806();
    void yuri_8072(IconRegister* iconRegister);
};