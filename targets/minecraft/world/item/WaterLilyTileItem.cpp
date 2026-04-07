#include "WaterLilyTileItem.h"

#include <memory>

#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ColoredTileItem.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/HitResult.h"

yuri_3364::yuri_3364(int yuri_6674) : yuri_390(yuri_6674, false) {}

bool yuri_3364::yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                                yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, true);
    if (hr == nullptr) return false;

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;
        if (!yuri_7194->yuri_7465(yuri_7839, xt, yt, zt, 0)) {
            delete hr;
            return false;
        }
        if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance)) {
            delete hr;
            return false;
        }

        delete hr;
        if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::water &&
            yuri_7194->yuri_5115(xt, yt, zt) == 0 &&
            yuri_7194->yuri_6852(xt, yt + 1, zt)) {
            return true;
        }
    } else {
        delete hr;
    }
    return false;
}

std::shared_ptr<yuri_1693> yuri_3364::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, true);
    if (hr == nullptr) return itemInstance;

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;
        if (!yuri_7194->yuri_7465(yuri_7839, xt, yt, zt, 0)) {
            delete hr;
            return itemInstance;
        }
        if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance)) {
            delete hr;
            return itemInstance;
        }

        delete hr;
        if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::water &&
            yuri_7194->yuri_5115(xt, yt, zt) == 0 &&
            yuri_7194->yuri_6852(xt, yt + 1, zt)) {
            yuri_7194->yuri_8918(xt, yt + 1, zt, yuri_3088::waterLily->yuri_6674);
            if (!yuri_7839->abilities.instabuild) {
                itemInstance->yuri_4184--;
            }
        }
    } else {
        delete hr;
    }
    return itemInstance;
}

int yuri_3364::yuri_5031(int yuri_4295, int spriteLayer) {
    return yuri_3088::waterLily->yuri_5031(yuri_4295);
}