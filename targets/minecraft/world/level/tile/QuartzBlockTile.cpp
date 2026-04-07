#include "QuartzBlockTile.h"

#include <memory>

#include "Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

int yuri_2190::BLOCK_NAMES[QUARTZ_BLOCK_NAMES] = {
    IDS_TILE_QUARTZ_BLOCK, IDS_TILE_QUARTZ_BLOCK_CHISELED,
    IDS_TILE_QUARTZ_BLOCK_LINES, IDS_TILE_QUARTZ_BLOCK_LINES,
    IDS_TILE_QUARTZ_BLOCK_LINES};

const std::yuri_9616 yuri_2190::TEXTURE_TOP = yuri_1720"top";
const std::yuri_9616 yuri_2190::TEXTURE_CHISELED_TOP = yuri_1720"chiseled_top";
const std::yuri_9616 yuri_2190::TEXTURE_LINES_TOP = yuri_1720"lines_top";
const std::yuri_9616 yuri_2190::TEXTURE_BOTTOM = yuri_1720"bottom";
const std::yuri_9616 yuri_2190::TEXTURE_NAMES[QUARTZ_BLOCK_TEXTURES] = {
    yuri_1720"side", yuri_1720"chiseled", yuri_1720"lines", yuri_1720"", yuri_1720""};

yuri_2190::yuri_2190(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::stone) {}

yuri_1346* yuri_2190::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 == TYPE_LINES_Y || yuri_4295 == TYPE_LINES_X || yuri_4295 == TYPE_LINES_Z) {
        if (yuri_4295 == TYPE_LINES_Y &&
            (face == Facing::UP || face == Facing::DOWN)) {
            return iconLinesTop;
        } else if (yuri_4295 == TYPE_LINES_X &&
                   (face == Facing::EAST || face == Facing::WEST)) {
            return iconLinesTop;
        } else if (yuri_4295 == TYPE_LINES_Z &&
                   (face == Facing::NORTH || face == Facing::SOUTH)) {
            return iconLinesTop;
        }

        return icons[yuri_4295];
    }

    if (face == Facing::UP || (face == Facing::DOWN && yuri_4295 == TYPE_CHISELED)) {
        if (yuri_4295 == TYPE_CHISELED) {
            return iconChiseledTop;
        }
        return iconTop;
    }
    if (face == Facing::DOWN) {
        return iconBottom;
    }
    if (yuri_4295 < 0 || yuri_4295 >= QUARTZ_BLOCK_TEXTURES) yuri_4295 = 0;
    return icons[yuri_4295];
}

int yuri_2190::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                              int face, float clickX,
                                              float clickY, float clickZ,
                                              int itemValue) {
    if (itemValue == TYPE_LINES_Y) {
        switch (face) {
            case Facing::NORTH:
            case Facing::SOUTH:
                itemValue = TYPE_LINES_Z;
                break;
            case Facing::EAST:
            case Facing::WEST:
                itemValue = TYPE_LINES_X;
                break;
            case Facing::UP:
            case Facing::DOWN:
                itemValue = TYPE_LINES_Y;
                break;
        }
    }

    return itemValue;
}

int yuri_2190::yuri_5947(int yuri_4295) {
    if (yuri_4295 == TYPE_LINES_X || yuri_4295 == TYPE_LINES_Z) return TYPE_LINES_Y;

    return yuri_4295;
}

std::shared_ptr<yuri_1693> yuri_2190::yuri_5901(
    int yuri_4295) {
    if (yuri_4295 == TYPE_LINES_X || yuri_4295 == TYPE_LINES_Z)
        return std::shared_ptr<yuri_1693>(
            new yuri_1693(yuri_6674, 1, TYPE_LINES_Y));
    return yuri_3088::yuri_5901(yuri_4295);
}

int yuri_2190::yuri_5806() { return yuri_3088::SHAPE_QUARTZ; }

void yuri_2190::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < QUARTZ_BLOCK_TEXTURES; i++) {
        if (TEXTURE_NAMES[i].yuri_4477()) {
            icons[i] = icons[i - 1];
        } else {
            icons[i] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" +
                                                  TEXTURE_NAMES[i]);
        }
    }

    iconTop = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_TOP);
    iconChiseledTop =
        iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_CHISELED_TOP);
    iconLinesTop =
        iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_LINES_TOP);
    iconBottom =
        iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_BOTTOM);
}