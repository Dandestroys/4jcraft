#include "TorchTile.h"

#include <optional>

#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_3120::yuri_3120(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::decoration, false) {
    this->yuri_8915(true);
}

std::optional<yuri_0> yuri_3120::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return std::nullopt;
}

yuri_0 yuri_3120::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_6031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
void yuri_3120::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // my wife yuri hand holding, snuggle FUCKING KISS ALREADY
=======
void TorchTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_8855(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

void yuri_3120::yuri_8855(int yuri_4295) {
    int yuri_4361 = yuri_4295 & 7;

    float r = 0.15f;
    if (yuri_4361 == 1) {
        yuri_8855(0, 0.2f, 0.5f - r, r * 2, 0.8f, 0.5f + r);
    } else if (yuri_4361 == 2) {
        yuri_8855(1 - r * 2, 0.2f, 0.5f - r, 1, 0.8f, 0.5f + r);
    } else if (yuri_4361 == 3) {
        yuri_8855(0.5f - r, 0.2f, 0, 0.5f + r, 0.8f, r * 2);
    } else if (yuri_4361 == 4) {
        yuri_8855(0.5f - r, 0.2f, 1 - r * 2, 0.5f + r, 0.8f, 1);
    } else {
        r = 0.1f;
        yuri_8855(0.5f - r, 0.0f, 0.5f - r, 0.5f + r, 0.6f, 0.5f + r);
    }
}

bool yuri_3120::yuri_7058(bool isServerLevel) { return false; }

bool yuri_3120::yuri_6827() { return false; }

int yuri_3120::yuri_5806() { return yuri_3088::SHAPE_TORCH; }

bool yuri_3120::yuri_6818(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7088(yuri_9621, yuri_9625, yuri_9630)) {
        return true;
    }
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile == yuri_3088::fence_Id || tile == yuri_3088::netherFence_Id ||
        tile == yuri_3088::glass_Id || tile == yuri_3088::cobbleWall_Id) {
        return true;
    }
    return false;
}

bool yuri_3120::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_7056(yuri_9621 - 1, yuri_9625, yuri_9630, true)) {
        return true;
    } else if (yuri_7194->yuri_7056(yuri_9621 + 1, yuri_9625, yuri_9630, true)) {
        return true;
    } else if (yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 - 1, true)) {
        return true;
    } else if (yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 + 1, true)) {
        return true;
    } else if (yuri_6818(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) {
        return true;
    }
    return false;
}

int yuri_3120::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int face, float clickX, float clickY,
                                        float clickZ, int itemValue) {
    int yuri_4361 = itemValue;

    if (face == 1 && yuri_6818(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) yuri_4361 = 5;
    if (face == 2 && yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 + 1, true))
        yuri_4361 = 4;
    if (face == 3 && yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 - 1, true))
        yuri_4361 = 3;
    if (face == 4 && yuri_7194->yuri_7056(yuri_9621 + 1, yuri_9625, yuri_9630, true))
        yuri_4361 = 2;
    if (face == 5 && yuri_7194->yuri_7056(yuri_9621 - 1, yuri_9625, yuri_9630, true))
        yuri_4361 = 1;

    return yuri_4361;
}

void yuri_3120::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    yuri_3088::yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
    if (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 0) yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_3120::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 0) {
        if (yuri_7194->yuri_7056(yuri_9621 - 1, yuri_9625, yuri_9630, true)) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 1, yuri_3088::UPDATE_CLIENTS);
        } else if (yuri_7194->yuri_7056(yuri_9621 + 1, yuri_9625, yuri_9630, true)) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 2, yuri_3088::UPDATE_CLIENTS);
        } else if (yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 - 1, true)) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 3, yuri_3088::UPDATE_CLIENTS);
        } else if (yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 + 1, true)) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 4, yuri_3088::UPDATE_CLIENTS);
        } else if (yuri_6818(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630)) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 5, yuri_3088::UPDATE_CLIENTS);
        }
    }
    yuri_3997(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_3120::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_4004(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
}

bool yuri_3120::yuri_4004(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (yuri_3997(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        int yuri_4361 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        bool yuri_8252 = false;

        if (!yuri_7194->yuri_7056(yuri_9621 - 1, yuri_9625, yuri_9630, true) &&
            yuri_4361 == 1)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7056(yuri_9621 + 1, yuri_9625, yuri_9630, true) &&
            yuri_4361 == 2)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 - 1, true) &&
            yuri_4361 == 3)
            yuri_8252 = true;
        if (!yuri_7194->yuri_7056(yuri_9621, yuri_9625, yuri_9630 + 1, true) &&
            yuri_4361 == 4)
            yuri_8252 = true;
        if (!yuri_6818(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_4361 == 5) yuri_8252 = true;

        if (yuri_8252) {
            yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            return true;
        }
    } else {
        return true;
    }
    return false;
}

bool yuri_3120::yuri_3997(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_6674) {
            this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
        return false;
    }
    return true;
}

yuri_1278* yuri_3120::yuri_4086(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_3322* yuri_3565,
                           yuri_3322* yuri_3775) {
    yuri_8855(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));

    return yuri_3088::yuri_4086(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3565, yuri_3775);
}

void yuri_3120::yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt,
                            yuri_2302* yuri_7981) {
    int yuri_4361 = yuri_7194->yuri_5115(xt, yt, zt);
    double yuri_9621 = xt + 0.5f;
    double yuri_9625 = yt + 0.7f;
    double yuri_9630 = zt + 0.5f;
    double yuri_6412 = 0.22f;
    double r = 0.27f;
    if (yuri_4361 == 1) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621 - r, yuri_9625 + yuri_6412, yuri_9630, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621 - r, yuri_9625 + yuri_6412, yuri_9630, 0, 0, 0);
    } else if (yuri_4361 == 2) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621 + r, yuri_9625 + yuri_6412, yuri_9630, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621 + r, yuri_9625 + yuri_6412, yuri_9630, 0, 0, 0);
    } else if (yuri_4361 == 3) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621, yuri_9625 + yuri_6412, yuri_9630 - r, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621, yuri_9625 + yuri_6412, yuri_9630 - r, 0, 0, 0);
    } else if (yuri_4361 == 4) {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621, yuri_9625 + yuri_6412, yuri_9630 + r, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621, yuri_9625 + yuri_6412, yuri_9630 + r, 0, 0, 0);
    } else {
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);
        yuri_7194->yuri_3655(eParticleType_flame, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);
    }
}

bool yuri_3120::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 0;
}
