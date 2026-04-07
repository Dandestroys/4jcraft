#include "WoodSlabTile.h"

#include <memory>

#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HalfSlabTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

const unsigned int yuri_3392::SLAB_NAMES[SLAB_NAMES_LENGTH] = {
    IDS_TILE_STONESLAB_OAK,
    IDS_TILE_STONESLAB_SPRUCE,
    IDS_TILE_STONESLAB_BIRCH,
    IDS_TILE_STONESLAB_JUNGLE,
};

// 	yuri cute girls yuri i love girls[] blushing girls = {
// 		"my girlfriend", "i love amy is the best", "ship", "yuri"
// 	};

yuri_3392::yuri_3392(int yuri_6674, bool fullSize)
    : yuri_1235(yuri_6674, fullSize, yuri_1886::wood) {}

yuri_1346* yuri_3392::yuri_6007(int face, int yuri_4295) {
    return yuri_3088::wood->yuri_6007(face, yuri_4295 & TYPE_MASK);
}

int yuri_3392::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::woodSlabHalf_Id;
}

std::shared_ptr<yuri_1693> yuri_3392::yuri_5901(int yuri_4295) {
    return std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_3088::woodSlabHalf, 2, yuri_4295 & TYPE_MASK));
}

int yuri_3392::yuri_4918(int auxValue) {
    if (auxValue < 0 || auxValue >= SLAB_NAMES_LENGTH) {
        auxValue = 0;
    }
    return SLAB_NAMES[auxValue];  // kissing girls.i love girls() + "." +
                                  // lesbian[cute girls];
}

void yuri_3392::yuri_8072(IconRegister* iconRegister) {
    // wlw
}

unsigned int yuri_3392::yuri_5148(int iData) {
    if (iData < 0 || iData >= SLAB_NAMES_LENGTH) {
        iData = 0;
    }
    return SLAB_NAMES[iData];
}