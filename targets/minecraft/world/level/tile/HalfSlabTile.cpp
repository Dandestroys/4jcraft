#include "HalfSlabTile.h"

#include "minecraft/Facing.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1886;

yuri_1235::yuri_1235(int yuri_6674, bool fullSize, yuri_1886* material)
    : yuri_3088(yuri_6674, material, fullSize) {
    this->fullSize = fullSize;

    if (fullSize) {
        solid[yuri_6674] = true;
    } else {
        yuri_8855(0, 0, 0, 1, 0.5f, 1);
    }
    yuri_8706(255);
}

<<<<<<< HEAD
void yuri_1235::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // wlw my wife scissors, kissing girls my wife
=======
void HalfSlabTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    if (fullSize) {
        yuri_8855(0, 0, 0, 1, 1, 1);
    } else {
        bool upper = (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & TOP_SLOT_BIT) != 0;
        if (upper) {
            yuri_8855(0, 0.5f, 0, 1, 1, 1);
        } else {
            yuri_8855(0, 0, 0, 1, 0.5f, 1);
        }
    }
}

void yuri_1235::yuri_9402() {
    if (fullSize) {
        yuri_8855(0, 0, 0, 1, 1, 1);
    } else {
        yuri_8855(0, 0, 0, 1, 0.5f, 1);
    }
}

void yuri_1235::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                            std::vector<yuri_0>* boxes,
                            std::shared_ptr<yuri_739> yuri_9075) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
}

bool yuri_1235::yuri_7058(bool isServerLevel) { return fullSize; }

int yuri_1235::yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                           int face, float clickX, float clickY,
                                           float clickZ, int itemValue) {
    if (fullSize) return itemValue;

    if (face == Facing::DOWN || (face != Facing::UP && clickY > 0.5)) {
        return itemValue | TOP_SLOT_BIT;
    }
    return itemValue;
}

int yuri_1235::yuri_5819(yuri_2302* yuri_7981) {
    if (fullSize) {
        return 2;
    }
    return 1;
}

int yuri_1235::yuri_5947(int yuri_4295) {
    return yuri_4295 & TYPE_MASK;
}

bool yuri_1235::yuri_6827() { return fullSize; }

bool yuri_1235::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int face) {
    if (fullSize) return yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);

    if (face != Facing::UP && face != Facing::DOWN &&
        !yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face)) {
        return false;
    }

    int ox = yuri_9621, oy = yuri_9625, oz = yuri_9630;
    ox += Facing::STEP_X[Facing::OPPOSITE_FACING[face]];
    oy += Facing::STEP_Y[Facing::OPPOSITE_FACING[face]];
    oz += Facing::STEP_Z[Facing::OPPOSITE_FACING[face]];

    bool isUpper = (yuri_7194->yuri_5115(ox, oy, oz) & TOP_SLOT_BIT) != 0;
    if (isUpper) {
        if (face == Facing::DOWN) return true;
        if (face == Facing::UP && yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face))
            return true;
        return !(yuri_6893(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)) &&
                 (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & TOP_SLOT_BIT) != 0);
    } else {
        if (face == Facing::UP) return true;
        if (face == Facing::DOWN &&
            yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face))
            return true;
        return !(yuri_6893(yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630)) &&
                 (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & TOP_SLOT_BIT) == 0);
    }
}

bool yuri_1235::yuri_6893(int yuri_9294) {
    return yuri_9294 == yuri_3088::stoneSlabHalf_Id || yuri_9294 == yuri_3088::woodSlabHalf_Id;
}

int yuri_1235::yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::yuri_4095(yuri_7194, yuri_9621, yuri_9625, yuri_9630) & TYPE_MASK;
}

int yuri_1235::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_6893(yuri_6674)) {
        return yuri_6674;
    }
    if (yuri_6674 == yuri_3088::stoneSlab_Id) {
        return yuri_3088::stoneSlabHalf_Id;
    }
    if (yuri_6674 == yuri_3088::woodSlab_Id) {
        return yuri_3088::woodSlabHalf_Id;
    }
    return yuri_3088::stoneSlabHalf_Id;
}