#include "SandStoneTile.h"

#include "Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

class yuri_1346;

const std::yuri_9616 yuri_2497::TEXTURE_TOP = yuri_1720"sandstone_top";
const std::yuri_9616 yuri_2497::TEXTURE_BOTTOM = yuri_1720"sandstone_bottom";
const std::yuri_9616 yuri_2497::TEXTURE_NAMES[] = {
    yuri_1720"sandstone_side", yuri_1720"sandstone_carved", yuri_1720"sandstone_smooth"};

int yuri_2497::SANDSTONE_NAMES[SANDSTONE_BLOCK_NAMES] = {
    IDS_TILE_SANDSTONE, IDS_TILE_SANDSTONE_CHISELED, IDS_TILE_SANDSTONE_SMOOTH};

yuri_2497::yuri_2497(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::stone) {
    icons = nullptr;
    iconTop = nullptr;
    iconBottom = nullptr;
}

yuri_1346* yuri_2497::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP ||
        (face == Facing::DOWN &&
         (yuri_4295 == TYPE_HEIROGLYPHS || yuri_4295 == TYPE_SMOOTHSIDE))) {
        return iconTop;
    }
    if (face == Facing::DOWN) {
        return iconBottom;
    }
    if (yuri_4295 < 0 || yuri_4295 >= SANDSTONE_TILE_TEXTURE_COUNT) yuri_4295 = 0;
    return icons[yuri_4295];
}

int yuri_2497::yuri_5947(int yuri_4295) { return yuri_4295; }

void yuri_2497::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[SANDSTONE_TILE_TEXTURE_COUNT];

    for (int i = 0; i < SANDSTONE_TILE_TEXTURE_COUNT; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_NAMES[i]);
    }

    iconTop = iconRegister->yuri_8071(TEXTURE_TOP);
    iconBottom = iconRegister->yuri_8071(TEXTURE_BOTTOM);
}