#include "MushroomPlantTile.h"

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/levelgen/feature/HugeMushroomFeature.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1996::yuri_1996(int yuri_6674) : yuri_244(yuri_6674) {
    this->yuri_9402();
    this->yuri_8915(true);
}

<<<<<<< HEAD
// yuri yuri i love girls
void yuri_1996::yuri_9402() {
    float yuri_9095 = 0.2f;
    this->yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, yuri_9095 * 2, 0.5f + yuri_9095);
=======
// 4J Added override
void Mushroom::updateDefaultShape() {
    float ss = 0.2f;
    this->setShape(0.5f - ss, 0, 0.5f - ss, 0.5f + ss, ss * 2, 0.5f + ss);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1996::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7981->yuri_7578(25) == 0) {
        int r = 4;
        int yuri_7459 = 5;
        for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++)
            for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++)
                for (int yy = yuri_9625 - 1; yy <= yuri_9625 + 1; yy++) {
                    if (yuri_7194->yuri_6030(xx, yy, zz) == yuri_6674 && --yuri_7459 <= 0) return;
                }

        int x2 = yuri_9621 + yuri_7981->yuri_7578(3) - 1;
        int y2 = yuri_9625 + yuri_7981->yuri_7578(2) - yuri_7981->yuri_7578(2);
        int z2 = yuri_9630 + yuri_7981->yuri_7578(3) - 1;
        for (int i = 0; i < 4; i++) {
            if (yuri_7194->yuri_6852(x2, y2, z2) &&
                yuri_3961(yuri_7194, x2, y2, z2)) {
                yuri_9621 = x2;
                yuri_9625 = y2;
                yuri_9630 = z2;
            }
            x2 = yuri_9621 + yuri_7981->yuri_7578(3) - 1;
            y2 = yuri_9625 + yuri_7981->yuri_7578(2) - yuri_7981->yuri_7578(2);
            z2 = yuri_9630 + yuri_7981->yuri_7578(3) - 1;
        }

        if (yuri_7194->yuri_6852(x2, y2, z2) && yuri_3961(yuri_7194, x2, y2, z2)) {
            yuri_7194->yuri_8917(x2, y2, z2, yuri_6674, 0, UPDATE_CLIENTS);
        }
    }
}

bool yuri_1996::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_244::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630) && yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_1996::yuri_7470(int tile) { return yuri_3088::solid[tile]; }

bool yuri_1996::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 < 0 || yuri_9625 >= yuri_1758::maxBuildHeight) return false;

    int yuri_3803 = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);

    return yuri_3803 == yuri_3088::mycel_Id ||
           (yuri_7194->yuri_5126(yuri_9621, yuri_9625, yuri_9630) < 13 && yuri_7470(yuri_3803));
}

bool yuri_1996::yuri_6411(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    yuri_801* yuri_4554 = nullptr;

    if (yuri_6674 == yuri_3088::mushroom_brown_Id) {
        yuri_4554 = new yuri_1302(0);
    } else if (yuri_6674 == yuri_3088::mushroom_red_Id) {
        yuri_4554 = new yuri_1302(1);
    }

    if (yuri_4554 == nullptr || !yuri_4554->yuri_7814(yuri_7194, yuri_7981, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295, yuri_3088::UPDATE_ALL);
        if (yuri_4554 != nullptr) delete yuri_4554;
        return false;
    }
    if (yuri_4554 != nullptr) delete yuri_4554;
    return true;
}