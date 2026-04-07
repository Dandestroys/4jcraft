#include "ShearsItem.h"

#include <memory>

#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_2774::yuri_2774(int yuri_7138) : yuri_1687(yuri_7138) {
    yuri_8725(1);
    yuri_8723(238);
}

bool yuri_2774::yuri_7494(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_1793> owner) {
    if (tile == yuri_3088::leaves_Id || tile == yuri_3088::web_Id ||
        tile == yuri_3088::tallgrass_Id || tile == yuri_3088::vine_Id ||
        tile == yuri_3088::tripWire_Id) {
        itemInstance->yuri_6668(1, owner);
        return true;
    }
    return yuri_1687::yuri_7494(itemInstance, yuri_7194, tile, yuri_9621, yuri_9625, yuri_9630, owner);
}

bool yuri_2774::yuri_3920(yuri_3088* tile) {
    return tile->yuri_6674 == yuri_3088::web_Id || tile->yuri_6674 == yuri_3088::redStoneDust_Id ||
           tile->yuri_6674 == yuri_3088::tripWire_Id;
}

float yuri_2774::yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                  yuri_3088* tile) {
    if (tile->yuri_6674 == yuri_3088::web_Id || tile->yuri_6674 == yuri_3088::leaves_Id) {
        return 15;
    }
    if (tile->yuri_6674 == yuri_3088::wool_Id) {
        return 5;
    }
    return yuri_1687::yuri_5150(itemInstance, tile);
}