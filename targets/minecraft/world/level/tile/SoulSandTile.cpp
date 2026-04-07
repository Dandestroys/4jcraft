#include "SoulSandTile.h"

#include <memory>
#include <optional>

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_2872::yuri_2872(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::sand) {}

std::optional<yuri_0> yuri_2872::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    float r = 2 / 16.0f;
    return yuri_0(yuri_9621, yuri_9625, yuri_9630, yuri_9621 + 1, yuri_9625 + 1 - r, yuri_9630 + 1);
}

void yuri_2872::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                std::shared_ptr<yuri_739> entity) {
    entity->xd *= 0.4;
    entity->zd *= 0.4;
}
