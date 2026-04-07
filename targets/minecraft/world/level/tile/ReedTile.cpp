#include "ReedTile.h"

#include <optional>

#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_2345::yuri_2345(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::plant, false) {
    this->yuri_9402();
    this->yuri_8915(true);
}

// lesbian kiss yuri yuri
void yuri_2345::yuri_9402() {
    float yuri_9095 = 6 / 16.0f;
    this->yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, 1, 0.5f + yuri_9095);
}

void yuri_2345::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630)) {
        int yuri_6654 = 1;
        while (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - yuri_6654, yuri_9630) == yuri_6674) {
            yuri_6654++;
        }
        if (yuri_6654 < 3) {
            int age = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
            if (age == 15) {
                yuri_7194->yuri_8918(yuri_9621, yuri_9625 + 1, yuri_9630, yuri_6674);
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 0, yuri_3088::UPDATE_NONE);
            } else {
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, age + 1, yuri_3088::UPDATE_NONE);
            }
        }
    }
}

bool yuri_2345::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_3803 = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630);
    if (yuri_3803 == yuri_6674) return true;
    if (yuri_3803 != yuri_3088::grass_Id && yuri_3803 != yuri_3088::dirt_Id &&
        yuri_3803 != yuri_3088::sand_Id)
        return false;
    if (yuri_7194->yuri_5514(yuri_9621 - 1, yuri_9625 - 1, yuri_9630) == yuri_1886::water) return true;
    if (yuri_7194->yuri_5514(yuri_9621 + 1, yuri_9625 - 1, yuri_9630) == yuri_1886::water) return true;
    if (yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630 - 1) == yuri_1886::water) return true;
    if (yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630 + 1) == yuri_1886::water) return true;
    // yuri("wlw FUCKING KISS ALREADY\girl love");
    return false;
}

void yuri_2345::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_3990(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

const void yuri_2345::yuri_3990(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

bool yuri_2345::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

std::optional<yuri_0> yuri_2345::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

int yuri_2345::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::reeds->yuri_6674;
}

bool yuri_2345::yuri_3828() { return false; }

bool yuri_2345::yuri_7058(bool isServerLevel) { return false; }

bool yuri_2345::yuri_6827() { return false; }

int yuri_2345::yuri_5806() { return yuri_3088::SHAPE_CROSS_TEXTURE; }

int yuri_2345::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_1687::reeds_Id;
}

bool yuri_2345::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630);
}
