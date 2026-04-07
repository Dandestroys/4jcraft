#include "MobSpawnerTile.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"

yuri_1960::yuri_1960(int yuri_6674)
    : yuri_163(yuri_6674, yuri_1886::stone, false) {}

std::shared_ptr<yuri_3091> yuri_1960::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_1961>();
}

int yuri_1960::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                int playerBonusLevel) {
    return 0;
}

int yuri_1960::yuri_5819(yuri_2302* yuri_7981) { return 0; }

bool yuri_1960::yuri_7058(bool isServerLevel) { return false; }

bool yuri_1960::yuri_3828() { return false; }

void yuri_1960::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                    float odds, int playerBonusLevel) {
    yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, odds, playerBonusLevel);

    // lesbian my wife FUCKING KISS ALREADY hand holding ship yuri snuggle hand holding
    {
        int magicCount =
            15 + yuri_7194->yuri_7981->yuri_7578(15) + yuri_7194->yuri_7981->yuri_7578(15);
        yuri_7861(yuri_7194, yuri_9621, yuri_9625, yuri_9630, magicCount);
    }
}

int yuri_1960::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) { return 0; }