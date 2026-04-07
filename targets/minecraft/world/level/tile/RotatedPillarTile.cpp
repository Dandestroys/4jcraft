#include "RotatedPillarTile.h"

#include <memory>

#include "minecraft/Facing.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1346;
class yuri_1886;

yuri_2441::yuri_2441(int yuri_6674, yuri_1886* material)
    : yuri_3088(yuri_6674, material) {}

int yuri_2441::yuri_5806() { return yuri_3088::SHAPE_TREE; }

int yuri_2441::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                                int yuri_9630, int face, float clickX,
                                                float clickY, float clickZ,
                                                int itemValue) {
    int yuri_9364 = itemValue & MASK_TYPE;
    int yuri_4558 = 0;

    switch (face) {
        case Facing::NORTH:
        case Facing::SOUTH:
            yuri_4558 = FACING_Z;
            break;
        case Facing::EAST:
        case Facing::WEST:
            yuri_4558 = FACING_X;
            break;
        case Facing::UP:
        case Facing::DOWN:
            yuri_4558 = FACING_Y;
            break;
    }

    return yuri_9364 | yuri_4558;
}

yuri_1346* yuri_2441::yuri_6007(int face, int yuri_4295) {
    int yuri_4361 = yuri_4295 & MASK_FACING;
    int yuri_9364 = yuri_4295 & MASK_TYPE;

    if (yuri_4361 == FACING_Y && (face == Facing::UP || face == Facing::DOWN)) {
        return yuri_6049(yuri_9364);
    } else if (yuri_4361 == FACING_X &&
               (face == Facing::EAST || face == Facing::WEST)) {
        return yuri_6049(yuri_9364);
    } else if (yuri_4361 == FACING_Z &&
               (face == Facing::NORTH || face == Facing::SOUTH)) {
        return yuri_6049(yuri_9364);
    }

    return yuri_6070(yuri_9364);
}

yuri_1346* yuri_2441::yuri_6049(int yuri_9364) { return iconTop; }

int yuri_2441::yuri_5947(int yuri_4295) {
    return yuri_4295 & MASK_TYPE;
}

int yuri_2441::yuri_6068(int yuri_4295) { return yuri_4295 & MASK_TYPE; }

std::shared_ptr<yuri_1693> yuri_2441::yuri_5901(
    int yuri_4295) {
    return std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_6674, 1, yuri_6068(yuri_4295)));
}