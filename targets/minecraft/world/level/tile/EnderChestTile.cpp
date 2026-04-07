#include "EnderChestTile.h"

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/PlayerEnderChestContainer.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/EnderChestTileEntity.h"

yuri_723::yuri_723(int yuri_6674)
    : yuri_163(yuri_6674, yuri_1886::stone, false) {
    yuri_9402();
}

// yuri snuggle yuri
void yuri_723::yuri_9402() {
    yuri_8855(1 / 16.0f, 0, 1 / 16.0f, 15 / 16.0f, 14 / 16.0f, 15 / 16.0f);
}

bool yuri_723::yuri_7058(bool isServerLevel) { return false; }

bool yuri_723::yuri_6827() { return false; }

int yuri_723::yuri_5806() { return yuri_3088::SHAPE_ENTITYTILE_ANIMATED; }

int yuri_723::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                int playerBonusLevel) {
    return yuri_3088::obsidian_Id;
}

int yuri_723::yuri_5819(yuri_2302* yuri_7981) { return 8; }

bool yuri_723::yuri_7042() { return true; }

void yuri_723::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 std::shared_ptr<yuri_1793> by,
                                 std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4558 = 0;
    int yuri_4361 = (Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 0.5f)) & 3;

    if (yuri_4361 == 0) yuri_4558 = Facing::NORTH;
    if (yuri_4361 == 1) yuri_4558 = Facing::EAST;
    if (yuri_4361 == 2) yuri_4558 = Facing::SOUTH;
    if (yuri_4361 == 3) yuri_4558 = Facing::WEST;

    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4558, yuri_3088::UPDATE_CLIENTS);
}

bool yuri_723::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                         float clickX, float clickY, float clickZ,
                         bool soundOnly) {
    std::shared_ptr<yuri_2135> yuri_4145 =
        yuri_7839->yuri_5209();
    std::shared_ptr<yuri_724> enderChest =
        std::dynamic_pointer_cast<yuri_724>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (yuri_4145 == nullptr || enderChest == nullptr) return true;

    if (yuri_7194->yuri_7055(yuri_9621, yuri_9625 + 1, yuri_9630)) return true;

    if (yuri_7194->yuri_6802) {
        return true;
    }

    yuri_4145->yuri_8440(enderChest);
    yuri_7839->yuri_7658(yuri_4145);

    return true;
}

std::shared_ptr<yuri_3091> yuri_723::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_724>();
}

void yuri_723::yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                                 yuri_2302* yuri_7981) {
    for (int i = 0; i < 3; i++) {
        double yuri_9621 = xt + yuri_7981->yuri_7576();
        double yuri_9625 = yt + yuri_7981->yuri_7576();
        double yuri_9630 = zt + yuri_7981->yuri_7576();
        double xa = 0;
        double ya = 0;
        double za = 0;
        int flipX = yuri_7981->yuri_7578(2) * 2 - 1;
        int flipZ = yuri_7981->yuri_7578(2) * 2 - 1;
        xa = (yuri_7981->yuri_7576() - 0.5) * 0.125;
        ya = (yuri_7981->yuri_7576() - 0.5) * 0.125;
        za = (yuri_7981->yuri_7576() - 0.5) * 0.125;
        yuri_9630 = zt + 0.5 + (0.25) * flipZ;
        za = (yuri_7981->yuri_7576() * 1) * flipZ;
        yuri_9621 = xt + 0.5 + (0.25) * flipX;
        xa = (yuri_7981->yuri_7576() * 1) * flipX;

        yuri_7194->yuri_3655(eParticleType_ender, yuri_9621, yuri_9625, yuri_9630, xa, ya, za);
    }
}

void yuri_723::yuri_8072(IconRegister* iconRegister) {
    // i love FUCKING KISS ALREADY yuri my wife FUCKING KISS ALREADY'yuri scissors, lesbian lesbian kiss'ship my girlfriend yuri snuggle
    // ship yuri lesbian yuri yuri
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"obsidian");
}
