#include "GlowstoneTile.h"

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1886;

yuri_1216::yuri_1216(int yuri_6674, yuri_1886* material) : yuri_3088(yuri_6674, material) {}

int yuri_1216::yuri_5820(int bonusLevel,
                                                yuri_2302* yuri_7981) {
    return Mth::yuri_4043(
        yuri_5819(yuri_7981) + yuri_7981->yuri_7578(bonusLevel + 1), 1, 4);
}

int yuri_1216::yuri_5819(yuri_2302* yuri_7981) {
    return 2 + yuri_7981->yuri_7578(3);
}

int yuri_1216::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::yellowDust->yuri_6674;
}