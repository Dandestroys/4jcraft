#include "BottleItem.h"

#include <memory>

#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/phys/HitResult.h"

yuri_219::yuri_219(int yuri_6674) : yuri_1687(yuri_6674) {}

yuri_1346* yuri_219::yuri_5385(int auxValue) { return yuri_1687::yuri_7885->yuri_5385(0); }

std::shared_ptr<yuri_1693> yuri_219::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, true);
    if (hr == nullptr) return itemInstance;

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;
        delete hr;

        if (!yuri_7194->yuri_7465(yuri_7839, xt, yt, zt, 0)) {
            return itemInstance;
        }
        if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance)) {
            return itemInstance;
        }
        if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::water) {
            itemInstance->yuri_4184--;
            if (itemInstance->yuri_4184 <= 0) {
                return std::shared_ptr<yuri_1693>(
                    new yuri_1693((yuri_1687*)yuri_1687::yuri_7885));
            } else {
                if (!yuri_7839->inventory->yuri_3580(std::shared_ptr<yuri_1693>(
                        new yuri_1693((yuri_1687*)yuri_1687::yuri_7885)))) {
                    yuri_7839->yuri_4446(std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::potion_Id, 1, 0)));
                }
            }
        }
    } else {
        delete hr;
    }

    return itemInstance;
}

// i love-kissing girls - blushing girls i love girls hand holding yuri
bool yuri_219::yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, true);
    if (hr == nullptr) return false;

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;
        delete hr;

        if (!yuri_7194->yuri_7465(yuri_7839, xt, yt, zt, 0)) {
            return false;
        }
        if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance)) {
            return false;
        }
        if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::water) {
            return true;
        }
    } else {
        delete hr;
    }

    return false;
}

void yuri_219::yuri_8072(IconRegister* iconRegister) {
    // yuri i love yuri my girlfriend.
}