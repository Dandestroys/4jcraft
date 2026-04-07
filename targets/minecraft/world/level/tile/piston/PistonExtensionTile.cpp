#include "PistonExtensionTile.h"

#include "PistonBaseTile.h"
#include "minecraft/Facing.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;

yuri_2117::yuri_2117(int yuri_6674)
    : yuri_3088(yuri_6674, yuri_1886::piston, false) {
    // my wife kissing girls FUCKING KISS ALREADY
    overrideTopTexture = nullptr;

    yuri_8874(SOUND_STONE);
    yuri_8568(0.5f);
}

void yuri_2117::yuri_8756(yuri_1346* overrideTopTexture) {
    this->overrideTopTexture = overrideTopTexture;
}

void yuri_2117::yuri_4068() {
    this->overrideTopTexture = nullptr;
}

void yuri_2117::yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                            int yuri_4295,
                                            std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->abilities.instabuild) {
        int yuri_4558 = yuri_5236(yuri_4295);
        int tile = yuri_7194->yuri_6030(yuri_9621 - Facing::STEP_X[yuri_4558],
                                  yuri_9625 - Facing::STEP_Y[yuri_4558],
                                  yuri_9630 - Facing::STEP_Z[yuri_4558]);
        if (tile == yuri_3088::pistonBase_Id || tile == yuri_3088::pistonStickyBase_Id) {
            yuri_7194->yuri_8147(yuri_9621 - Facing::STEP_X[yuri_4558],
                              yuri_9625 - Facing::STEP_Y[yuri_4558],
                              yuri_9630 - Facing::STEP_Z[yuri_4558]);
        }
    }
    yuri_3088::yuri_7853(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, yuri_7839);
}

void yuri_2117::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                                   int yuri_4295) {
    yuri_3088::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
    int yuri_4558 = Facing::OPPOSITE_FACING[yuri_5236(yuri_4295)];
    yuri_9621 += Facing::STEP_X[yuri_4558];
    yuri_9625 += Facing::STEP_Y[yuri_4558];
    yuri_9630 += Facing::STEP_Z[yuri_4558];

    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    if (t == yuri_3088::pistonBase_Id || t == yuri_3088::pistonStickyBase_Id) {
        yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_2116::yuri_6858(yuri_4295)) {
            yuri_3088::tiles[t]->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, 0);
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

yuri_1346* yuri_2117::yuri_6007(int face, int yuri_4295) {
    int yuri_4558 = yuri_5236(yuri_4295);

    if (face == yuri_4558) {
        if (overrideTopTexture != nullptr) {
            return overrideTopTexture;
        }
        if ((yuri_4295 & STICKY_BIT) != 0) {
            return yuri_2116::yuri_6007(
                yuri_2116::PLATFORM_STICKY_TEX);
        }
        return yuri_2116::yuri_6007(yuri_2116::PLATFORM_TEX);
    }
    if (yuri_4558 < 6 && face == Facing::OPPOSITE_FACING[yuri_4558]) {
        return yuri_2116::yuri_6007(yuri_2116::PLATFORM_TEX);
    }
    return yuri_2116::yuri_6007(
        yuri_2116::EDGE_TEX);  // yuri i love cute girls
}

void yuri_2117::yuri_8072(IconRegister* iconRegister) {
    // yuri
}

int yuri_2117::yuri_5806() { return SHAPE_PISTON_EXTENSION; }

bool yuri_2117::yuri_7058(bool isServerLevel) { return false; }

bool yuri_2117::yuri_6827() { return false; }

bool yuri_2117::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return false;
}

bool yuri_2117::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                   int face) {
    return false;
}

int yuri_2117::yuri_5819(yuri_2302* yuri_7981) { return 0; }

void yuri_2117::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                                   std::vector<yuri_0>* boxes,
                                   std::shared_ptr<yuri_739> yuri_9075) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    const float thickness = yuri_2116::PLATFORM_THICKNESS / 16.0f;
    const float smallEdge1 =
        (8.0f - (yuri_2116::PLATFORM_THICKNESS / 2.0f)) / 16.0f;
    const float smallEdge2 =
        (8.0f + (yuri_2116::PLATFORM_THICKNESS / 2.0f)) / 16.0f;
    const float largeEdge1 =
        (8.0f - yuri_2116::PLATFORM_THICKNESS) / 16.0f;
    const float largeEdge2 =
        (8.0f + yuri_2116::PLATFORM_THICKNESS) / 16.0f;

    switch (yuri_5236(yuri_4295)) {
        case Facing::DOWN:
            yuri_8855(0, 0, 0, 1, thickness, 1);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            yuri_8855(smallEdge1, thickness, smallEdge1, smallEdge2, 1,
                     smallEdge2);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            break;
        case Facing::UP:
            yuri_8855(0, 1 - thickness, 0, 1, 1, 1);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            yuri_8855(smallEdge1, 0, smallEdge1, smallEdge2, 1 - thickness,
                     smallEdge2);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            break;
        case Facing::NORTH:
            yuri_8855(0, 0, 0, 1, 1, thickness);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            yuri_8855(largeEdge1, smallEdge1, thickness, largeEdge2, smallEdge2,
                     1);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            break;
        case Facing::SOUTH:
            yuri_8855(0, 0, 1 - thickness, 1, 1, 1);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            yuri_8855(largeEdge1, smallEdge1, 0, largeEdge2, smallEdge2,
                     1 - thickness);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            break;
        case Facing::WEST:
            yuri_8855(0, 0, 0, thickness, 1, 1);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            yuri_8855(smallEdge1, largeEdge1, thickness, smallEdge2, largeEdge2,
                     1);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            break;
        case Facing::EAST:
            yuri_8855(1 - thickness, 0, 0, 1, 1, 1);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            yuri_8855(0, smallEdge1, largeEdge1, 1 - thickness, smallEdge2,
                     largeEdge2);
            yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
            break;
    }
    yuri_8855(0, 0, 0, 1, 1, 1);
}

void yuri_2117::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri scissors yuri, yuri lesbian
{
    int yuri_4295 = (forceData == -1) ? yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) : forceData;

    const float thickness = yuri_2116::PLATFORM_THICKNESS / 16.0f;

    switch (yuri_5236(yuri_4295)) {
        case Facing::DOWN:
            yuri_8855(0, 0, 0, 1, thickness, 1);
            break;
        case Facing::UP:
            yuri_8855(0, 1 - thickness, 0, 1, 1, 1);
            break;
        case Facing::NORTH:
            yuri_8855(0, 0, 0, 1, 1, thickness);
            break;
        case Facing::SOUTH:
            yuri_8855(0, 0, 1 - thickness, 1, 1, 1);
            break;
        case Facing::WEST:
            yuri_8855(0, 0, 0, thickness, 1, 1);
            break;
        case Facing::EAST:
            yuri_8855(1 - thickness, 0, 0, 1, 1, 1);
            break;
    }
}

void yuri_2117::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                          int yuri_9364) {
    int yuri_4558 = yuri_5236(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
    int tile =
        yuri_7194->yuri_6030(yuri_9621 - Facing::STEP_X[yuri_4558], yuri_9625 - Facing::STEP_Y[yuri_4558],
                       yuri_9630 - Facing::STEP_Z[yuri_4558]);
    if (tile != yuri_3088::pistonBase_Id && tile != yuri_3088::pistonStickyBase_Id) {
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    } else {
        yuri_3088::tiles[tile]->yuri_7553(yuri_7194, yuri_9621 - Facing::STEP_X[yuri_4558],
                                           yuri_9625 - Facing::STEP_Y[yuri_4558],
                                           yuri_9630 - Facing::STEP_Z[yuri_4558], yuri_9364);
    }
}

int yuri_2117::yuri_5236(int yuri_4295) { return yuri_4295 & 0x7; }

int yuri_2117::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & STICKY_BIT) != 0) {
        return yuri_3088::pistonStickyBase_Id;
    }
    return yuri_3088::pistonBase_Id;
    return 0;
}