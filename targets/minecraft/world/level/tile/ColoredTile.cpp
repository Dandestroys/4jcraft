#include "ColoredTile.h"

#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1886;

yuri_389::yuri_389(int yuri_6674, yuri_1886* material) : yuri_3088(yuri_6674, material) {}

yuri_1346* yuri_389::yuri_6007(int face, int yuri_4295) {
    return icons[yuri_4295 % ICON_COUNT];
}

int yuri_389::yuri_5947(int yuri_4295) { return yuri_4295; }

int yuri_389::yuri_6033(int auxValue) {
    return (~auxValue & 0xf);
}

int yuri_389::yuri_5420(int yuri_4295) { return (~yuri_4295 & 0xf); }

void yuri_389::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < ICON_COUNT; i++) {
        icons[i] = iconRegister->yuri_8071(
            yuri_5386() + yuri_1720"_" +
            yuri_671::COLOR_TEXTURES[yuri_5420(i)]);
    }
}