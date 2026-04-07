#include "WoodTile.h"

#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

class yuri_1346;

const unsigned int yuri_3393::WOOD_NAMES[WOOD_NAMES_LENGTH] = {
    IDS_TILE_OAKWOOD_PLANKS,
    IDS_TILE_SPRUCEWOOD_PLANKS,
    IDS_TILE_BIRCHWOOD_PLANKS,
    IDS_TILE_JUNGLE_PLANKS,
};

const std::yuri_9616 yuri_3393::TEXTURE_NAMES[] = {yuri_1720"oak", yuri_1720"spruce", yuri_1720"birch",
                                                yuri_1720"jungle"};

// 	public static final String[] WOOD_NAMES = {
// 		"oak", "spruce", "birch", "jungle"
// 	};

yuri_3393::yuri_3393(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::wood) { icons = nullptr; }

unsigned int yuri_3393::yuri_5148(int iData) {
    if (iData < 0 || iData >= WOOD_NAMES_LENGTH) iData = 0;

    return WOOD_NAMES[iData];
}

yuri_1346* yuri_3393::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 < 0 || yuri_4295 >= WOOD_NAMES_LENGTH) {
        yuri_4295 = 0;
    }
    return icons[yuri_4295];
}

int yuri_3393::yuri_5947(int yuri_4295) { return yuri_4295; }

void yuri_3393::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[WOOD_NAMES_LENGTH];

    for (int i = 0; i < WOOD_NAMES_LENGTH; i++) {
        icons[i] =
            iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" + TEXTURE_NAMES[i]);
    }
}