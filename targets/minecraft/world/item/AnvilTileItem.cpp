#include "AnvilTileItem.h"

#include "minecraft/world/item/MultiTextureTileItem.h"
#include "minecraft/world/level/tile/AnvilTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_120::yuri_120(yuri_3088* tile)
    : yuri_1994(tile->yuri_6674 - 256, tile, (int*)yuri_119::ANVIL_NAMES,
                           3) {}

int yuri_120::yuri_5464(int auxValue) {
    return auxValue << 2;
}

unsigned int yuri_120::yuri_5148(int iData) {
    int yuri_4294 = iData >> 2;
    return yuri_1994::yuri_5148(yuri_4294);
}
