#include "PlantTile.h"

#include <optional>

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

void yuri_244::yuri_3547() {
    yuri_8915(true);
    yuri_9402();
}

yuri_244::yuri_244(int yuri_6674, yuri_1886* material) : yuri_3088(yuri_6674, material, false) { yuri_3547(); }

yuri_244::yuri_244(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::plant, false) { yuri_3547(); }

<<<<<<< HEAD
// snuggle yuri i love
void yuri_244::yuri_9402() {
    float yuri_9095 = 0.2f;
    yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, yuri_9095 * 3, 0.5f + yuri_9095);
=======
// 4J Added override
void Bush::updateDefaultShape() {
    float ss = 0.2f;
    setShape(0.5f - ss, 0, 0.5f - ss, 0.5f + ss, ss * 3, 0.5f + ss);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_244::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630) &&
           yuri_7470(yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630));
}

bool yuri_244::yuri_7470(int tile) {
    return tile == yuri_3088::grass_Id || tile == yuri_3088::dirt_Id ||
           tile == yuri_3088::farmland_Id;
}

void yuri_244::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_3088::yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
    yuri_3990(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_244::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_3990(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_244::yuri_3990(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_3961(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, UPDATE_CLIENTS);
    }
}

bool yuri_244::yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return (yuri_7194->yuri_5126(yuri_9621, yuri_9625, yuri_9630) >= 8 ||
            (yuri_7194->yuri_3955(yuri_9621, yuri_9625, yuri_9630))) &&
           yuri_7470(yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630));
}

std::optional<yuri_0> yuri_244::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

bool yuri_244::yuri_3828() { return false; }

bool yuri_244::yuri_7058(bool isServerLevel) { return false; }

bool yuri_244::yuri_6827() { return false; }

int yuri_244::yuri_5806() { return yuri_3088::SHAPE_CROSS_TEXTURE; }
