#include "TallGrassFeature.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3019::yuri_3019(int tile, int yuri_9364) {
    this->tile = tile;
    this->yuri_9364 = yuri_9364;
}

bool yuri_3019::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                             int yuri_9630) {
    int t = 0;
    while (((t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)) == 0 || t == yuri_3088::leaves_Id) &&
           yuri_9625 > 0)
        yuri_9625--;

    for (int i = 0; i < 128; i++) {
        int x2 = yuri_9621 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        int y2 = yuri_9625 + yuri_7981->yuri_7578(4) - yuri_7981->yuri_7578(4);
        int z2 = yuri_9630 + yuri_7981->yuri_7578(8) - yuri_7981->yuri_7578(8);
        if (yuri_7194->yuri_6852(x2, y2, z2)) {
            if (yuri_3088::tiles[tile]->yuri_3961(yuri_7194, x2, y2, z2)) {
                yuri_7194->yuri_8917(x2, y2, z2, tile, yuri_9364,
                                      yuri_3088::UPDATE_CLIENTS);
            }
        }
    }

    return true;
}