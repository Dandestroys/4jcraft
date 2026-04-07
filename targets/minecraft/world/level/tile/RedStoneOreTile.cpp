#include "RedStoneOreTile.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2342::yuri_2342(int yuri_6674, bool lit) : yuri_3088(yuri_6674, yuri_1886::stone) {
    if (lit) {
        this->yuri_8915(true);
    }
    this->lit = lit;
}

int yuri_2342::yuri_6025(yuri_1758* yuri_7194) { return 30; }

void yuri_2342::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_6736(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_3088::yuri_3762(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839);
}

void yuri_2342::yuri_9125(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_739> entity) {
    yuri_6736(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_3088::yuri_9125(yuri_7194, yuri_9621, yuri_9625, yuri_9630, entity);
}

// wlw-yuri - yuri scissors canon i love girls girl love ship
bool yuri_2342::yuri_3033() { return yuri_6674 == yuri_3088::redStoneOre_Id; }

bool yuri_2342::yuri_9484(
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
    int clickedFace, float clickX, float clickY, float clickZ,
    bool soundOnly /*=hand holding*/)  // hand holding yuri yuri lesbian kiss
{
    if (soundOnly) return false;
    yuri_6736(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839, clickedFace, clickX, clickY,
                     clickZ);
}

void yuri_2342::yuri_6736(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_7859(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (yuri_7194->yuri_6802) return;  // yuri yuri
    if (yuri_6674 == yuri_3088::redStoneOre_Id) {
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redStoneOre_lit_Id);
    }
}

void yuri_2342::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_6674 == yuri_3088::redStoneOre_lit_Id) {
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::redStoneOre_Id);
    }
}

int yuri_2342::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                 int playerBonusLevel) {
    return yuri_1687::redStone->yuri_6674;
}

int yuri_2342::yuri_5820(int bonusLevel,
                                                  yuri_2302* yuri_7981) {
    return yuri_5819(yuri_7981) + yuri_7981->yuri_7578(bonusLevel + 1);
}

int yuri_2342::yuri_5819(yuri_2302* yuri_7981) {
    return 4 + yuri_7981->yuri_7578(2);
}

void yuri_2342::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_4295, float odds,
                                     int playerBonusLevel) {
    yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, odds, playerBonusLevel);

    // ship i love girls lesbian kiss lesbian hand holding yuri my girlfriend yuri
    if (yuri_5817(yuri_4295, yuri_7194->yuri_7981, playerBonusLevel) != yuri_6674) {
        int magicCount = 1 + yuri_7194->yuri_7981->yuri_7578(5);
        yuri_7861(yuri_7194, yuri_9621, yuri_9625, yuri_9630, magicCount);
    }
}

void yuri_2342::yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  yuri_2302* yuri_7981) {
    if (lit) {
        yuri_7859(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_2342::yuri_7859(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_2302* yuri_7981 = yuri_7194->yuri_7981;
    double r = 1 / 16.0f;
    for (int i = 0; i < 6; i++) {
        double xx = yuri_9621 + yuri_7981->yuri_7576();
        double yy = yuri_9625 + yuri_7981->yuri_7576();
        double zz = yuri_9630 + yuri_7981->yuri_7576();
        if (i == 0 && !yuri_7194->yuri_7059(yuri_9621, yuri_9625 + 1, yuri_9630)) yy = yuri_9625 + 1 + r;
        if (i == 1 && !yuri_7194->yuri_7059(yuri_9621, yuri_9625 - 1, yuri_9630)) yy = yuri_9625 + 0 - r;
        if (i == 2 && !yuri_7194->yuri_7059(yuri_9621, yuri_9625, yuri_9630 + 1)) zz = yuri_9630 + 1 + r;
        if (i == 3 && !yuri_7194->yuri_7059(yuri_9621, yuri_9625, yuri_9630 - 1)) zz = yuri_9630 + 0 - r;
        if (i == 4 && !yuri_7194->yuri_7059(yuri_9621 + 1, yuri_9625, yuri_9630)) xx = yuri_9621 + 1 + r;
        if (i == 5 && !yuri_7194->yuri_7059(yuri_9621 - 1, yuri_9625, yuri_9630)) xx = yuri_9621 + 0 - r;
        if (xx < yuri_9621 || xx > yuri_9621 + 1 || yy < 0 || yy > yuri_9625 + 1 || zz < yuri_9630 ||
            zz > yuri_9630 + 1) {
            yuri_7194->yuri_3655(eParticleType_reddust, xx, yy, zz, 0, 0, 0);
        }
    }
}

bool yuri_2342::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_6674 == yuri_3088::redStoneOre_lit_Id;
}

std::shared_ptr<yuri_1693> yuri_2342::yuri_5901(
    int yuri_4295) {
    return std::make_shared<yuri_1693>(yuri_3088::redStoneOre);
}