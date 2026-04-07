#include "GravelTile.h"

#include "java/Random.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/HeavyTile.h"

yuri_1223::yuri_1223(int yuri_9364) : yuri_1265(yuri_9364) {}

int yuri_1223::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    if (playerBonusLevel > 3) playerBonusLevel = 3;
    if (yuri_7981->yuri_7578(10 - playerBonusLevel * 3) == 0) return yuri_1687::flint->yuri_6674;
    return yuri_6674;
}