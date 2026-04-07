#include "LadderTile.h"

#include <optional>

#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_1726::yuri_1726(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::decoration, false) {}

std::optional<yuri_0> yuri_1726::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

yuri_0 yuri_1726::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_6031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
void yuri_1726::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri snuggle lesbian, canon cute girls
=======
void LadderTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_8855(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

void yuri_1726::yuri_8855(int yuri_4295) {
    int yuri_4361 = yuri_4295;
    float r = 2 / 16.0f;

    if (yuri_4361 == 2) yuri_8855(0, 0, 1 - r, 1, 1, 1);
    if (yuri_4361 == 3) yuri_8855(0, 0, 0, 1, 1, r);
    if (yuri_4361 == 4) yuri_8855(1 - r, 0, 0, 1, 1, 1);
    if (yuri_4361 == 5) yuri_8855(0, 0, 0, r, 1, 1);
}

bool yuri_1726::yuri_3828() { return false; }

bool yuri_1726::yuri_7058(bool isServerLevel) { return false; }

bool yuri_1726::yuri_6827() { return false; }

int yuri_1726::yuri_5806() { return yuri_3088::SHAPE_LADDER; }

bool yuri_1726::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1)) {
        return true;
    } else if (yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1)) {
        return true;
    }
    return false;
}

int yuri_1726::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue) {
    int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if ((yuri_4361 == 0 || face == 2) && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1))
        yuri_4361 = 2;
    if ((yuri_4361 == 0 || face == 3) && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1))
        yuri_4361 = 3;
    if ((yuri_4361 == 0 || face == 4) && yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630))
        yuri_4361 = 4;
    if ((yuri_4361 == 0 || face == 5) && yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630))
        yuri_4361 = 5;

    return yuri_4361;
}

void yuri_1726::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    int face = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool ok = false;

    if (face == 2 && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 + 1)) ok = true;
    if (face == 3 && yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630 - 1)) ok = true;
    if (face == 4 && yuri_7194->yuri_7055(yuri_9621 + 1, yuri_9625, yuri_9630)) ok = true;
    if (face == 5 && yuri_7194->yuri_7055(yuri_9621 - 1, yuri_9625, yuri_9630)) ok = true;
    if (!ok) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, 0);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_3088::yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
}

int yuri_1726::yuri_5819(yuri_2302* yuri_7981) { return 1; }
