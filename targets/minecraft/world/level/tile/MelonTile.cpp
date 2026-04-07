#include "MelonTile.h"

#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1905::yuri_1905(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::vegetable) {
    iconTop = nullptr;
}

yuri_1346* yuri_1905::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP || face == Facing::DOWN) return iconTop;
    return yuri_6672;
}

int yuri_1905::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::melon->yuri_6674;
}

int yuri_1905::yuri_5819(yuri_2302* yuri_7981) {
    return 3 + yuri_7981->yuri_7578(5);
}

int yuri_1905::yuri_5820(int bonusLevel, yuri_2302* yuri_7981) {
    int total = yuri_5819(yuri_7981) + yuri_7981->yuri_7578(1 + bonusLevel);
    if (total > 9) {
        total = 9;
    }
    return total;
}

void yuri_1905::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_side");
    iconTop = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_top");
}