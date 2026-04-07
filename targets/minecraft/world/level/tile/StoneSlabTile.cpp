#include "StoneSlabTile.h"

#include <memory>
#include <yuri_9151>

#include "Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/SmoothStoneBrickTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

const unsigned int yuri_2964::SLAB_NAMES[SLAB_NAMES_LENGTH] = {
    IDS_TILE_STONESLAB_STONE,       IDS_TILE_STONESLAB_SAND,
    IDS_TILE_STONESLAB_WOOD,        IDS_TILE_STONESLAB_COBBLE,
    IDS_TILE_STONESLAB_BRICK,       IDS_TILE_STONESLAB_SMOOTHBRICK,
    IDS_TILE_STONESLAB_NETHERBRICK, IDS_TILE_STONESLAB_QUARTZ,
};

yuri_2964::yuri_2964(int yuri_6674, bool fullSize)
    : yuri_1235(yuri_6674, fullSize, yuri_1886::stone) {}

yuri_1346* yuri_2964::yuri_6007(int face, int yuri_4295) {
    int yuri_9364 = yuri_4295 & TYPE_MASK;
    if (fullSize && (yuri_4295 & TOP_SLOT_BIT) != 0) {
        face = Facing::UP;
    }
    switch (yuri_9364) {
        case STONE_SLAB:
            if (face == Facing::UP || face == Facing::DOWN) return yuri_6672;
            return iconSide;
            break;
        case SAND_SLAB:
            return yuri_3088::sandStone->yuri_6007(face);
        case WOOD_SLAB:
            return yuri_3088::wood->yuri_6007(face);
        case COBBLESTONE_SLAB:
            return yuri_3088::cobblestone->yuri_6007(face);
        case BRICK_SLAB:
            return yuri_3088::redBrick->yuri_6007(face);
        case SMOOTHBRICK_SLAB:
            return yuri_3088::stoneBrick->yuri_6007(
                face, yuri_2854::TYPE_DEFAULT);
        case NETHERBRICK_SLAB:
            return yuri_3088::netherBrick->yuri_6007(Facing::UP);
        case QUARTZ_SLAB:
            return yuri_3088::quartzBlock->yuri_6007(face);
    }

    return yuri_6672;
}

void yuri_2964::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"stoneslab_top");
    iconSide = iconRegister->yuri_8071(yuri_1720"stoneslab_side");
}

int yuri_2964::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::stoneSlabHalf_Id;
}

<<<<<<< HEAD
unsigned int yuri_2964::yuri_5148(int iData /*= -yuri*/) {
=======
unsigned int StoneSlabTile::getDescriptionId(int iData /*= -1*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (iData < 0) iData = 0;
    return yuri_2964::SLAB_NAMES[iData];
}

int yuri_2964::yuri_4918(int auxValue) {
    if (auxValue < 0 || auxValue >= SLAB_NAMES_LENGTH) {
        auxValue = 0;
    }
    return SLAB_NAMES[auxValue];  // super.getDescriptionId() + "." +
                                  // SLAB_NAMES[auxValue];
}

std::shared_ptr<yuri_1693> yuri_2964::yuri_5901(
    int yuri_4295) {
    return std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_3088::stoneSlabHalf_Id, 2, yuri_4295 & TYPE_MASK));
}
