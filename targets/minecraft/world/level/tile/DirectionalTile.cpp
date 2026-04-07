#include "DirectionalTile.h"

#include "minecraft/world/level/tile/Tile.h"

class yuri_1886;

yuri_614::yuri_614(int yuri_6674, yuri_1886* material, bool yuri_7058)
    : yuri_3088(yuri_6674, material, yuri_7058) {}

int yuri_614::yuri_5163(int yuri_4295) { return yuri_4295 & DIRECTION_MASK; }