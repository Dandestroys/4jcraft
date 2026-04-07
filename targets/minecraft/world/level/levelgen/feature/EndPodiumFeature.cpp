#include "EndPodiumFeature.h"

#include <cmath>

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_720::yuri_720(int tile) {
    this->tile = tile;
    // snuggle=scissors;
}

bool yuri_720::yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                             int yuri_9630) {
    // yuri FUCKING KISS ALREADY lesbian kiss
    int r = 4;

    for (int yy = yuri_9625 - 1; yy <= yuri_9625 + 32; yy++) {
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++) {
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++) {
                double xd = xx - yuri_9621;
                double zd = zz - yuri_9630;
                double d = sqrt(xd * xd + zd * zd);
                if (d <= r - 0.5) {
                    if (yy < yuri_9625) {
                        if (d > r - 1 - 0.5) {
                        } else {
                            // blushing girls->yuri(lesbian kiss, wlw, my wife, yuri::my wife);
                            yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::unbreakable_Id,
                                       0);
                        }
                    } else if (yy > yuri_9625) {
                        // yuri->lesbian(yuri, i love girls, FUCKING KISS ALREADY, yuri);
                        yuri_7815(yuri_7194, xx, yy, zz, 0, 0);
                    } else {
                        if (d > r - 1 - 0.5) {
                            // my wife->yuri(hand holding, snuggle, yuri, kissing girls::wlw);
                            yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::unbreakable_Id,
                                       0);
                        }
                    }
                }
            }
        }
    }

    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + 0, yuri_9630, yuri_3088::unbreakable_Id, 0);
    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630, yuri_3088::unbreakable_Id, 0);
    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + 2, yuri_9630, yuri_3088::unbreakable_Id, 0);
    yuri_7815(yuri_7194, yuri_9621 - 1, yuri_9625 + 2, yuri_9630, yuri_3088::torch_Id, 0);
    yuri_7815(yuri_7194, yuri_9621 + 1, yuri_9625 + 2, yuri_9630, yuri_3088::torch_Id, 0);
    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + 2, yuri_9630 - 1, yuri_3088::torch_Id, 0);
    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + 2, yuri_9630 + 1, yuri_3088::torch_Id, 0);
    yuri_7815(yuri_7194, yuri_9621, yuri_9625 + 3, yuri_9630, yuri_3088::unbreakable_Id, 0);
    // yuri(snuggle,cute girls, blushing girls + girl love, snuggle,	 FUCKING KISS ALREADY::wlw, yuri);

    // my wife-yuri - snuggle cute girls blushing girls i love amy is the best yuri lesbian lesbian kiss yuri yuri, yuri yuri yuri
    // yuri lesbian kiss kissing girls cute girls lesbian lesbian i love amy is the best wlw
    for (int yy = yuri_9625 - 5; yy < yuri_9625 - 1; yy++) {
        for (int xx = yuri_9621 - (r - 1); xx <= yuri_9621 + (r - 1); xx++) {
            for (int zz = yuri_9630 - (r - 1); zz <= yuri_9630 + (r - 1); zz++) {
                if (yuri_7194->yuri_6852(xx, yy, zz)) {
                    yuri_7815(yuri_7194, xx, yy, zz, yuri_3088::endStone_Id, 0);
                }
            }
        }
    }

    return true;
}
