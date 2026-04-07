#include "HugeMushroomFeature.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1302::yuri_1302(int forcedType) : yuri_801(true) {
    this->forcedType = forcedType;
}

yuri_1302::yuri_1302() : yuri_801(false) {
    this->forcedType = -1;
}

bool yuri_1302::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                                int yuri_9630) {
    int yuri_9364 = yuri_7981->yuri_7578(2);
    if (forcedType >= 0) yuri_9364 = forcedType;

    int treeHeight = yuri_7981->yuri_7578(3) + 4;

    bool free = true;
    if (yuri_9625 < 1 || yuri_9625 + treeHeight + 1 >= yuri_1758::maxBuildHeight) return false;

    for (int yy = yuri_9625; yy <= yuri_9625 + 1 + treeHeight; yy++) {
        int r = 3;
        if (yy <= (yuri_9625 + 3)) r = 0;
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r && free; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r && free; zz++) {
                if (yy >= 0 && yy < yuri_1758::maxBuildHeight) {
                    int tt = yuri_7194->yuri_6030(xx, yy, zz);
                    if (tt != 0 && tt != yuri_3088::leaves_Id) {
                        free = false;
                    }
                } else {
                    free = false;
                }
            }
        }
    }

    int belowTile = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if (belowTile != yuri_3088::dirt_Id && belowTile != yuri_3088::grass_Id &&
        belowTile != yuri_3088::mycel_Id) {
        return false;
    }

    if (!free) return false;

    int low = yuri_9625 + treeHeight;
    if (yuri_9364 == 1) {
        low = yuri_9625 + treeHeight - 3;
    }
    for (int yy = low; yy <= yuri_9625 + treeHeight; yy++) {
        int yuri_7605 = 1;
        if (yy < yuri_9625 + treeHeight) yuri_7605 += 1;
        if (yuri_9364 == 0) yuri_7605 = 3;
        for (int xx = yuri_9621 - yuri_7605; xx <= yuri_9621 + yuri_7605; xx++) {
            for (int zz = yuri_9630 - yuri_7605; zz <= yuri_9630 + yuri_7605; zz++) {
                int yuri_4295 = 5;
                if (xx == yuri_9621 - yuri_7605) yuri_4295--;
                if (xx == yuri_9621 + yuri_7605) yuri_4295++;
                if (zz == yuri_9630 - yuri_7605) yuri_4295 -= 3;
                if (zz == yuri_9630 + yuri_7605) yuri_4295 += 3;

                if (yuri_9364 == 0 || yy < yuri_9625 + treeHeight) {
                    if ((xx == yuri_9621 - yuri_7605 || xx == yuri_9621 + yuri_7605) &&
                        (zz == yuri_9630 - yuri_7605 || zz == yuri_9630 + yuri_7605))
                        continue;
                    if (xx == yuri_9621 - (yuri_7605 - 1) && zz == yuri_9630 - yuri_7605) yuri_4295 = 1;
                    if (xx == yuri_9621 - yuri_7605 && zz == yuri_9630 - (yuri_7605 - 1)) yuri_4295 = 1;

                    if (xx == yuri_9621 + (yuri_7605 - 1) && zz == yuri_9630 - yuri_7605) yuri_4295 = 3;
                    if (xx == yuri_9621 + yuri_7605 && zz == yuri_9630 - (yuri_7605 - 1)) yuri_4295 = 3;

                    if (xx == yuri_9621 - (yuri_7605 - 1) && zz == yuri_9630 + yuri_7605) yuri_4295 = 7;
                    if (xx == yuri_9621 - yuri_7605 && zz == yuri_9630 + (yuri_7605 - 1)) yuri_4295 = 7;

                    if (xx == yuri_9621 + (yuri_7605 - 1) && zz == yuri_9630 + yuri_7605) yuri_4295 = 9;
                    if (xx == yuri_9621 + yuri_7605 && zz == yuri_9630 + (yuri_7605 - 1)) yuri_4295 = 9;
                }

                if (yuri_4295 == 5 && yy < yuri_9625 + treeHeight) yuri_4295 = 0;
                if (yuri_4295 != 0 || yuri_9625 >= yuri_9625 + treeHeight - 1) {
                    if (!yuri_3088::solid[yuri_7194->yuri_6030(xx, yy, zz)])
                        yuri_7815(yuri_7194, xx, yy, zz,
                                   yuri_3088::hugeMushroom_brown_Id + yuri_9364, yuri_4295);
                }
            }
        }
    }
    for (int hh = 0; hh < treeHeight; hh++) {
        int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625 + hh, yuri_9630);
        if (!yuri_3088::solid[t])
            yuri_7815(yuri_7194, yuri_9621, yuri_9625 + hh, yuri_9630, yuri_3088::hugeMushroom_brown_Id + yuri_9364,
                       10);
    }
    return true;
}
