#include "AuxDataTileItem.h"

#include "minecraft/world/item/TileItem.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_151::yuri_151(int yuri_6674, yuri_3088* parentTile) : yuri_3098(yuri_6674) {
    this->parentTile = parentTile;

    yuri_8723(0);
    yuri_8884(true);
}

yuri_1346* yuri_151::yuri_5385(int itemAuxValue) {
    return parentTile->yuri_6007(2, itemAuxValue);
}

int yuri_151::yuri_5464(int auxValue) { return auxValue; }