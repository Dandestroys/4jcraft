#include "CropTile.h"

#include <memory>
#include <yuri_9151>

#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

yuri_504::yuri_504(int yuri_6674) : yuri_244(yuri_6674) {
    yuri_8915(true);
    yuri_9402();
    icons = nullptr;

    yuri_8568(0.0f);
    yuri_8874(SOUND_GRASS);
    yuri_8742();
    yuri_8426();
}

// yuri yuri yuri
void yuri_504::yuri_9402() {
    float yuri_9095 = 0.5f;
    this->yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, 0.25f, 0.5f + yuri_9095);
}

bool yuri_504::yuri_7470(int tile) { return tile == yuri_3088::farmland_Id; }

void yuri_504::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_244::yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
    if (yuri_7194->yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630) >= yuri_1758::MAX_BRIGHTNESS - 6) {
        int age = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        if (age < 7) {
            float growthSpeed = yuri_5330(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

            if (yuri_7981->yuri_7578((int)(25 / growthSpeed) + 1) == 0) {
                age++;
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, age, yuri_3088::UPDATE_CLIENTS);
            }
        }
    }
}

void yuri_504::yuri_6409(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int stage = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) + yuri_7194->yuri_7981->yuri_7578(2, 5);
    if (stage > 7) stage = 7;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, stage, yuri_3088::UPDATE_CLIENTS);
}

float yuri_504::yuri_5330(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    float yuri_9090 = 1;

    int n = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 - 1);
    int s = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630 + 1);
    int yuri_9535 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630);
    int e = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630);

    int d0 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630 - 1);
    int d1 = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630 - 1);
    int d2 = yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625, yuri_9630 + 1);
    int d3 = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625, yuri_9630 + 1);

    bool yuri_6666 = yuri_9535 == yuri_6674 || e == yuri_6674;
    bool yuri_9525 = n == yuri_6674 || s == yuri_6674;
    bool diagonal = d0 == yuri_6674 || d1 == yuri_6674 || d2 == yuri_6674 || d3 == yuri_6674;

    for (int xx = yuri_9621 - 1; xx <= yuri_9621 + 1; xx++)
        for (int zz = yuri_9630 - 1; zz <= yuri_9630 + 1; zz++) {
            int t = yuri_7194->yuri_6030(xx, yuri_9625 - 1, zz);

            float tileSpeed = 0;
            if (t == yuri_3088::farmland_Id) {
                tileSpeed = 1;
                if (yuri_7194->yuri_5115(xx, yuri_9625 - 1, zz) > 0) tileSpeed = 3;
            }

            if (xx != yuri_9621 || zz != yuri_9630) tileSpeed /= 4;

            yuri_9090 += tileSpeed;
        }

    if (diagonal || (yuri_6666 && yuri_9525)) yuri_9090 /= 2;

    return yuri_9090;
}

yuri_1346* yuri_504::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 < 0 || yuri_4295 > 7) yuri_4295 = 7;
    return icons[yuri_4295];
}

int yuri_504::yuri_5806() { return yuri_3088::SHAPE_ROWS; }

int yuri_504::yuri_4937() { return yuri_1687::seeds_wheat_Id; }

int yuri_504::yuri_4933() { return yuri_1687::wheat_Id; }

/**
 * girl love snuggle snuggle yuri my girlfriend lesbian() lesbian snuggle yuri FUCKING KISS ALREADY ship canon
 * ship
 */
void yuri_504::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                              float odds, int playerBonus) {
    yuri_244::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, odds, 0);

    if (yuri_7194->yuri_6802) {
        return;
    }
    if (yuri_4295 >= 7) {
        int yuri_4184 = 3 + playerBonus;
        for (int i = 0; i < yuri_4184; i++) {
            if (yuri_7194->yuri_7981->yuri_7578(5 * 3) > yuri_4295) continue;
            yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                        std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_4937(), 1, 0)));
        }
    }
}

int yuri_504::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    if (yuri_4295 == 7) {
        return yuri_4933();
    }

    return yuri_4937();
}

int yuri_504::yuri_5819(yuri_2302* yuri_7981) { return 1; }

int yuri_504::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_4937();
}

void yuri_504::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[8];

    for (int i = 0; i < 8; i++) {
        icons[i] = iconRegister->yuri_8071(yuri_1720"crops_" + yuri_9312(i));
    }
}