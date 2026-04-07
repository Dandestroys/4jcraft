#include "StainedGlassBlock.h"

#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/level/tile/HalfTransparentTile.h"

class yuri_1346;
class yuri_1886;

yuri_1346* yuri_2894::ICONS[yuri_2894::ICONS_LENGTH];

yuri_2894::yuri_2894(int yuri_6674, yuri_1886* material)
    : yuri_1236(yuri_6674, yuri_1720"glass", material, false) {}

yuri_1346* yuri_2894::yuri_6007(int face, int yuri_4295) {
    return ICONS[yuri_4295 % ICONS_LENGTH];
}

int yuri_2894::yuri_5947(int yuri_4295) { return yuri_4295; }

int yuri_2894::yuri_5419(int yuri_4295) {
    return (~yuri_4295 & 0xf);
}

int yuri_2894::yuri_5805() { return 1; }

void yuri_2894::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < ICONS_LENGTH; i++) {
        ICONS[i] = iconRegister->yuri_8071(
            yuri_5386() + yuri_1720"_" +
            yuri_671::COLOR_TEXTURES[yuri_5419(i)]);
    }
}

int yuri_2894::yuri_5819(yuri_2302* yuri_7981) { return 0; }

bool yuri_2894::yuri_7042() { return true; }

bool yuri_2894::yuri_6827() { return false; }
