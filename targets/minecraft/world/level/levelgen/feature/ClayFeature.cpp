#include "ClayFeature.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_353::yuri_353(int radius) {
    this->tile = yuri_3088::clay_Id;
    this->radius = radius;
}

bool yuri_353::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_5514(yuri_9621, yuri_9625, yuri_9630) != yuri_1886::water) return false;

    int r = yuri_7981->yuri_7578(radius - 2) + 2;
    int yr = 1;
    for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++) {
        for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++) {
            int xd = xx - yuri_9621;
            int zd = zz - yuri_9630;
            if (xd * xd + zd * zd > r * r) continue;
            for (int yy = yuri_9625 - yr; yy <= yuri_9625 + yr; yy++) {
                int t = yuri_7194->yuri_6030(xx, yy, zz);
                if (t == yuri_3088::dirt_Id || t == yuri_3088::clay_Id) {
                    yuri_7194->yuri_8917(xx, yy, zz, tile, 0,
                                          yuri_3088::UPDATE_CLIENTS);
                }
            }
        }
    }

    return true;
}
