#include "SnowTile.h"

#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2862::yuri_2862(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::snow) { yuri_8915(true); }

int yuri_2862::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::snowBall->yuri_6674;
}

int yuri_2862::yuri_5819(yuri_2302* yuri_7981) { return 4; }

void yuri_2862::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) > 11) {
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

bool yuri_2862::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) > 11;
}