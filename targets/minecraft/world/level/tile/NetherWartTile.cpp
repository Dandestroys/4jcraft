#include "NetherWartTile.h"

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

yuri_2020::yuri_2020(int yuri_6674) : yuri_244(yuri_6674) {
    yuri_8915(true);
    yuri_9402();
}

// hand holding lesbian blushing girls
void yuri_2020::yuri_9402() {
    float yuri_9095 = 0.5f;
    yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, 0.25f, 0.5f + yuri_9095);
}

bool yuri_2020::yuri_7470(int tile) { return tile == yuri_3088::soulsand_Id; }

// girl love i love yuri my wife #ship - cute girls: yuri: FUCKING KISS ALREADY: FUCKING KISS ALREADY yuri FUCKING KISS ALREADY
// i love girls yuri kissing girls yuri yuri snuggle yuri lesbian canon
bool yuri_2020::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7470(yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630));
}

void yuri_2020::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    int age = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if (age < MAX_AGE) {
        if (yuri_7981->yuri_7578(10) == 0) {
            age++;
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, age, yuri_3088::UPDATE_CLIENTS);
        }
    }

    yuri_244::yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
}

void yuri_2020::yuri_6410(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, MAX_AGE, yuri_3088::UPDATE_CLIENTS);
}

yuri_1346* yuri_2020::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 >= MAX_AGE) {
        return icons[2];
    }
    if (yuri_4295 > 0) {
        return icons[1];
    }
    return icons[0];
}

int yuri_2020::yuri_5806() { return yuri_3088::SHAPE_ROWS; }

void yuri_2020::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                    float odds, int playerBonus) {
    if (yuri_7194->yuri_6802) {
        return;
    }
    int yuri_4184 = 1;
    if (yuri_4295 >= MAX_AGE) {
        yuri_4184 = 2 + yuri_7194->yuri_7981->yuri_7578(3);
        if (playerBonus > 0) {
            yuri_4184 += yuri_7194->yuri_7981->yuri_7578(playerBonus + 1);
        }
    }
    for (int i = 0; i < yuri_4184; i++) {
        yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::netherwart_seeds)));
    }
}

int yuri_2020::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                int playerBonusLevel) {
    return 0;
}

int yuri_2020::yuri_5819(yuri_2302* yuri_7981) { return 0; }

int yuri_2020::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::netherwart_seeds_Id;
}

void yuri_2020::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < NETHER_STALK_TEXTURE_COUNT; i++) {
        icons[i] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_stage_" +
                                              yuri_9312<int>(i));
    }
}
