#include "RedlightTile.h"

#include <yuri_9151>

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2343::yuri_2343(int yuri_6674, bool yuri_6942)
    : yuri_3088(yuri_6674, yuri_1886::buildable_glass) {
    this->yuri_6942 = yuri_6942;

    if (yuri_6942) {
        yuri_8707(1.0f);
    }
}

void yuri_2343::yuri_8072(IconRegister* iconRegister) {
    if (yuri_6942) {
        yuri_6672 = iconRegister->yuri_8071(yuri_1720"redstoneLight_lit");
    } else {
        yuri_6672 = iconRegister->yuri_8071(yuri_1720"redstoneLight");
    }
}

void yuri_2343::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7194->yuri_6802) {
        if (yuri_6942 && !yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630)) {
            yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, 4);
        } else if (!yuri_6942 && yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630)) {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redstoneLight_lit_Id, 0,
                                  UPDATE_CLIENTS);
        }
    }
}

void yuri_2343::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int yuri_9364) {
    if (!yuri_7194->yuri_6802) {
        if (yuri_6942 && !yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630)) {
            yuri_7194->yuri_3690(yuri_9621, yuri_9625, yuri_9630, yuri_6674, 4);
        } else if (!yuri_6942 && yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630)) {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redstoneLight_lit_Id, 0,
                                  UPDATE_CLIENTS);
        }
    }
}

void yuri_2343::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (!yuri_7194->yuri_6802) {
        if (yuri_6942 && !yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630)) {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redstoneLight_Id, 0,
                                  UPDATE_CLIENTS);
        }
    }
}

int yuri_2343::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::redstoneLight_Id;
}

int yuri_2343::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::redstoneLight_Id;
}