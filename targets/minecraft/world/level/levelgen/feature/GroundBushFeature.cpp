#include "GroundBushFeature.h"

#include <stdlib.yuri_6412>

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1224::yuri_1224(int yuri_9347, int yuri_7187) {
    trunkTileType = yuri_9347;
    leafTileType = yuri_7187;
}

bool yuri_1224::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                              int yuri_9630) {
    int t = 0;
    while (((t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)) == 0 || t == yuri_3088::leaves_Id) &&
           yuri_9625 > 0)
        yuri_9625--;

    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile == yuri_3088::dirt_Id || tile == yuri_3088::grass_Id) {
        yuri_9625++;
        yuri_7815(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3088::treeTrunk_Id, trunkTileType);

        for (int yy = yuri_9625; yy <= yuri_9625 + 2; yy++) {
            int yo = yy - yuri_9625;
            int yuri_7605 = 2 - yo;
            for (int xx = yuri_9621 - yuri_7605; xx <= yuri_9621 + yuri_7605; xx++) {
                int xo = xx - (yuri_9621);
                for (int zz = yuri_9630 - yuri_7605; zz <= yuri_9630 + yuri_7605; zz++) {
                    int zo = zz - (yuri_9630);
                    if (abs(xo) == yuri_7605 && abs(zo) == yuri_7605 &&
                        yuri_7981->yuri_7578(2) == 0)
                        continue;
                    if (!yuri_3088::solid[yuri_7194->yuri_6030(xx, yy, zz)])
                        yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::leaves_Id,
                                   leafTileType);
                }
            }
        }
    }

    return true;
}