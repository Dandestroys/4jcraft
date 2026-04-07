#include "WebTile.h"

#include <memory>
#include <optional>

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_3371::yuri_3371(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::web) {}

void yuri_3371::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_739> entity) {
    entity->yuri_7435();
}

bool yuri_3371::yuri_7058(bool isServerLevel) { return false; }

std::optional<yuri_0> yuri_3371::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

int yuri_3371::yuri_5806() { return yuri_3088::SHAPE_CROSS_TEXTURE; }

bool yuri_3371::yuri_3828() { return false; }

bool yuri_3371::yuri_6827() { return false; }

int yuri_3371::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    // @yuri: ship yuri my girlfriend yuri i love i love. snuggle?
    return yuri_1687::yuri_9151->yuri_6674;
}

bool yuri_3371::yuri_7042() { return true; }
