#include "HeavyTile.h"

#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

bool yuri_1265::instaFall = false;

yuri_1265::yuri_1265(int yuri_9364, bool yuri_7058)
    : yuri_3088(yuri_9364, yuri_1886::sand, yuri_7058) {}

yuri_1265::yuri_1265(int yuri_9364, yuri_1886* material, bool yuri_7058)
    : yuri_3088(yuri_9364, material, yuri_7058) {}

void yuri_1265::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
}

void yuri_1265::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
}

void yuri_1265::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (!yuri_7194->yuri_6802) {
        yuri_4026(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_1265::yuri_4026(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int x2 = yuri_9621;
    int y2 = yuri_9625;
    int z2 = yuri_9630;
    if (yuri_6879(yuri_7194, x2, y2 - 1, z2) && y2 >= 0) {
        int r = 32;

        if (instaFall ||
            !yuri_7194->yuri_6583(yuri_9621 - r, yuri_9625 - r, yuri_9630 - r, yuri_9621 + r, yuri_9625 + r, yuri_9630 + r)) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            while (yuri_6879(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_9625 > 0) yuri_9625--;
            if (yuri_9625 > 0) {
                yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_6674);
            }
        } else if (!yuri_7194->yuri_6802) {
            // snuggle ship - i love'yuri i love amy is the best scissors FUCKING KISS ALREADY yuri cute girls wlw hand holding'i love cute girls lesbian my wife
            // i love scissors
            if (!yuri_7194->yuri_7561()) {
                yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_6025(yuri_7194));
                return;
            }

            std::shared_ptr<yuri_794> e = std::shared_ptr<yuri_794>(
                new yuri_794(yuri_7194, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, yuri_6674,
                                yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630)));
            yuri_4561(e);
            yuri_7194->yuri_3611(e);
        }
    }
}

void yuri_1265::yuri_4561(std::shared_ptr<yuri_794> entity) {}

int yuri_1265::yuri_6025(yuri_1758* yuri_7194) { return 2; }

bool yuri_1265::yuri_6879(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t == 0) return true;
    if (t == yuri_3088::fire_Id) return true;
    yuri_1886* material = yuri_3088::tiles[t]->material;
    if (material == yuri_1886::water) return true;
    if (material == yuri_1886::lava) return true;
    return false;
}

void yuri_1265::yuri_7625(yuri_1758* yuri_7194, int xt, int yt, int zt, int yuri_4295) {}