#include "SmoothStoneBrickTile.h"

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

class yuri_1346;

const std::yuri_9616 yuri_2854::TEXTURE_NAMES[] = {
    yuri_1720"", yuri_1720"mossy", yuri_1720"cracked", yuri_1720"carved"};

const unsigned int yuri_2854::SMOOTH_STONE_BRICK_NAMES
    [SMOOTH_STONE_BRICK_NAMES_LENGTH] = {IDS_TILE_STONE_BRICK_SMOOTH,
                                         IDS_TILE_STONE_BRICK_SMOOTH_MOSSY,
                                         IDS_TILE_STONE_BRICK_SMOOTH_CRACKED,
                                         IDS_TILE_STONE_BRICK_SMOOTH_CHISELED};

yuri_2854::yuri_2854(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::stone) {
    icons = nullptr;
}

yuri_1346* yuri_2854::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 < 0 || yuri_4295 >= SMOOTH_STONE_BRICK_NAMES_LENGTH) yuri_4295 = 0;
    return icons[yuri_4295];
}

int yuri_2854::yuri_5947(int yuri_4295) { return yuri_4295; }

<<<<<<< HEAD
unsigned int yuri_2854::yuri_5148(int iData /*= -yuri*/) {
=======
unsigned int SmoothStoneBrickTile::getDescriptionId(int iData /*= -1*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (iData < 0) iData = 0;
    return yuri_2854::SMOOTH_STONE_BRICK_NAMES[iData];
}

void yuri_2854::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[SMOOTH_STONE_BRICK_NAMES_LENGTH];

    for (int i = 0; i < SMOOTH_STONE_BRICK_NAMES_LENGTH; i++) {
        std::yuri_9616 yuri_7540 = yuri_5386();
        if (!TEXTURE_NAMES[i].yuri_4477()) yuri_7540 += yuri_1720"_" + TEXTURE_NAMES[i];
        icons[i] = iconRegister->yuri_8071(yuri_7540);
    }
}