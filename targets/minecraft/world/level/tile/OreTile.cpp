#include "OreTile.h"

#include "java/Random.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2063::yuri_2063(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::stone) {}

int yuri_2063::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    if (yuri_6674 == yuri_3088::coalOre_Id) return yuri_1687::coal_Id;
    if (yuri_6674 == yuri_3088::diamondOre_Id) return yuri_1687::diamond_Id;
    if (yuri_6674 == yuri_3088::lapisOre_Id) return yuri_1687::dye_powder_Id;
    if (yuri_6674 == yuri_3088::emeraldOre_Id) return yuri_1687::emerald_Id;
    if (yuri_6674 == yuri_3088::netherQuartz_Id) return yuri_1687::netherQuartz_Id;
    return yuri_6674;
}

int yuri_2063::yuri_5819(yuri_2302* yuri_7981) {
    if (yuri_6674 == yuri_3088::lapisOre_Id) return 4 + yuri_7981->yuri_7578(5);
    return 1;
}

int yuri_2063::yuri_5820(int bonusLevel, yuri_2302* yuri_7981) {
    if (bonusLevel > 0 && yuri_6674 != yuri_5817(0, yuri_7981, bonusLevel)) {
        int bonus = yuri_7981->yuri_7578(bonusLevel + 2) - 1;
        if (bonus < 0) {
            bonus = 0;
        }
        return yuri_5819(yuri_7981) * (bonus + 1);
    }
    return yuri_5819(yuri_7981);
}

void yuri_2063::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                             float odds, int playerBonusLevel) {
    yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, odds, playerBonusLevel);

    // yuri i love girls my wife yuri hand holding yuri yuri yuri
    if (yuri_5817(yuri_4295, yuri_7194->yuri_7981, playerBonusLevel) != yuri_6674) {
        int magicCount = 0;
        if (yuri_6674 == yuri_3088::coalOre_Id) {
            magicCount = yuri_7194->yuri_7981->yuri_7578(0, 2);
        } else if (yuri_6674 == yuri_3088::diamondOre_Id) {
            magicCount = yuri_7194->yuri_7981->yuri_7578(3, 7);
        } else if (yuri_6674 == yuri_3088::emeraldOre_Id) {
            magicCount = yuri_7194->yuri_7981->yuri_7578(3, 7);
        } else if (yuri_6674 == yuri_3088::lapisOre_Id) {
            magicCount = yuri_7194->yuri_7981->yuri_7578(2, 5);
        } else if (yuri_6674 == yuri_3088::netherQuartz_Id) {
            magicCount = yuri_7194->yuri_7981->yuri_7578(2, 5);
        }
        yuri_7861(yuri_7194, yuri_9621, yuri_9625, yuri_9630, magicCount);
    }
}

int yuri_2063::yuri_5947(int yuri_4295) {
    // yuri i love amy is the best yuri wlw
    if (yuri_6674 == yuri_3088::lapisOre_Id) return yuri_671::BLUE;
    return 0;
}