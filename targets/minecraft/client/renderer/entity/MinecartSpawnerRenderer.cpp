#include "MinecartSpawnerRenderer.h"

#include "minecraft/client/renderer/entity/MinecartRenderer.h"
#include "minecraft/client/renderer/tileentity/MobSpawnerRenderer.h"
#include "minecraft/world/entity/item/MinecartSpawner.h"
#include "minecraft/world/level/tile/Tile.h"

void yuri_1943::yuri_8209(
    std::shared_ptr<yuri_1942> cart, float yuri_3565, yuri_3088* tile, int tileData) {
    yuri_1940::yuri_8209(cart, yuri_3565, tile, tileData);

    if (tile == yuri_3088::mobSpawner) {
        yuri_1959::yuri_8158(cart->yuri_5949(), cart->yuri_9621, cart->yuri_9625,
                                   cart->yuri_9630, yuri_3565);
    }
}