#include "RailTile.h"

#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/tile/BaseRailTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2299::yuri_2299(int yuri_6674) : yuri_166(yuri_6674, false) {}

yuri_1346* yuri_2299::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 >= 6) {
        return iconTurn;
    } else {
        return yuri_6672;
    }
}

void yuri_2299::yuri_8072(IconRegister* iconRegister) {
    yuri_166::yuri_8072(iconRegister);
    iconTurn = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_turned");
}

void yuri_2299::yuri_9470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295, int yuri_4361,
                           int yuri_9364) {
    if (yuri_9364 > 0 && yuri_3088::tiles[yuri_9364]->yuri_7041()) {
        if (yuri_2298(yuri_7194, yuri_9621, yuri_9625, yuri_9630).yuri_4195() == 3) {
            yuri_9404(yuri_7194, yuri_9621, yuri_9625, yuri_9630, false);
        }
    }
}