#include "LiquidTileStatic.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/LiquidTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1790::yuri_1790(int yuri_6674, yuri_1886* material)
    : yuri_1788(yuri_6674, material) {
    yuri_8915(false);
    if (material == yuri_1886::lava) yuri_8915(true);
}

bool yuri_1790::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return material != yuri_1886::lava;
}

void yuri_1790::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int yuri_9364) {
    yuri_1788::yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_6674) {
        yuri_8582(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_1790::yuri_8582(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int d = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674 - 1, d, yuri_3088::UPDATE_CLIENTS);
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674 - 1, yuri_6025(yuri_7194));
}

void yuri_1790::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (material == yuri_1886::lava) {
        int yuri_6412 = yuri_7981->yuri_7578(3);
        for (int i = 0; i < yuri_6412; i++) {
            yuri_9621 += yuri_7981->yuri_7578(3) - 1;
            yuri_9625++;
            yuri_9630 += yuri_7981->yuri_7578(3) - 1;
            int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
            if (t == 0) {
                if (yuri_6871(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630) ||
                    yuri_6871(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630) ||
                    yuri_6871(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1) ||
                    yuri_6871(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1) ||
                    yuri_6871(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630) ||
                    yuri_6871(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630)) {
                    yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::fire_Id);
                    return;
                }
            } else if (yuri_3088::tiles[t]->material->yuri_3830()) {
                return;
            }
        }
        if (yuri_6412 == 0) {
            int ox = yuri_9621;
            int oz = yuri_9630;
            for (int i = 0; i < 3; i++) {
                yuri_9621 = ox + yuri_7981->yuri_7578(3) - 1;
                yuri_9630 = oz + yuri_7981->yuri_7578(3) - 1;
                if (yuri_7194->yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630) &&
                    yuri_6871(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
                    yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_3088::fire_Id);
                }
            }
        }
    }
}

bool yuri_1790::yuri_6871(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630)->yuri_6871();
}
