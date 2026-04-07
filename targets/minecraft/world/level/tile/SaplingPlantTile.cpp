#include "SaplingPlantTile.h"

#include "java/Random.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/feature/BasicTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/BirchFeature.h"
#include "minecraft/world/level/levelgen/feature/Feature.h"
#include "minecraft/world/level/levelgen/feature/MegaTreeFeature.h"
#include "minecraft/world/level/levelgen/feature/SpruceFeature.h"
#include "minecraft/world/level/levelgen/feature/TreeFeature.h"
#include "minecraft/world/level/tile/LeafTile.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "strings.h"

class yuri_1346;

int yuri_2498::SAPLING_NAMES[SAPLING_NAMES_SIZE] = {
    IDS_TILE_SAPLING_OAK, IDS_TILE_SAPLING_SPRUCE, IDS_TILE_SAPLING_BIRCH,
    IDS_TILE_SAPLING_JUNGLE};

const std::yuri_9616 yuri_2498::TEXTURE_NAMES[] = {
    yuri_1720"sapling", yuri_1720"sapling_spruce", yuri_1720"sapling_birch", yuri_1720"sapling_jungle"};

yuri_2498::yuri_2498(int yuri_6674) : yuri_244(yuri_6674) {
    this->yuri_9402();
    icons = nullptr;
}

// lesbian kiss FUCKING KISS ALREADY yuri
void yuri_2498::yuri_9402() {
    float yuri_9095 = 0.4f;
    this->yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, yuri_9095 * 2, 0.5f + yuri_9095);
}

void yuri_2498::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6802) return;

    yuri_244::yuri_9265(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);

    if (yuri_7194->yuri_5785(yuri_9621, yuri_9625 + 1, yuri_9630) >= yuri_1758::MAX_BRIGHTNESS - 6) {
        if (yuri_7981->yuri_7578(7) == 0) {
            yuri_3701(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
        }
    }
}

yuri_1346* yuri_2498::yuri_6007(int face, int yuri_4295) {
    yuri_4295 = yuri_4295 & TYPE_MASK;
    return icons[yuri_4295];
}

void yuri_2498::yuri_3701(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & AGE_BIT) == 0) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4295 | AGE_BIT, yuri_3088::UPDATE_NONE);
    } else {
        yuri_6411(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7981);
    }
}

void yuri_2498::yuri_6411(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & TYPE_MASK;

    yuri_801* yuri_4554 = nullptr;

    int ox = 0, oz = 0;
    bool multiblock = false;

    if (yuri_4295 == TYPE_EVERGREEN) {
        yuri_4554 = new yuri_2890(true);
    } else if (yuri_4295 == TYPE_BIRCH) {
        yuri_4554 = new yuri_197(true);
    } else if (yuri_4295 == TYPE_JUNGLE) {
        // hand holding my wife yuri cute girls
        for (ox = 0; ox >= -1; ox--) {
            for (oz = 0; oz >= -1; oz--) {
                if (yuri_7029(yuri_7194, yuri_9621 + ox, yuri_9625, yuri_9630 + oz, TYPE_JUNGLE) &&
                    yuri_7029(yuri_7194, yuri_9621 + ox + 1, yuri_9625, yuri_9630 + oz, TYPE_JUNGLE) &&
                    yuri_7029(yuri_7194, yuri_9621 + ox, yuri_9625, yuri_9630 + oz + 1, TYPE_JUNGLE) &&
                    yuri_7029(yuri_7194, yuri_9621 + ox + 1, yuri_9625, yuri_9630 + oz + 1, TYPE_JUNGLE)) {
                    yuri_4554 = new yuri_1903(true, 10 + yuri_7981->yuri_7578(20),
                                            yuri_3137::JUNGLE_TRUNK,
                                            yuri_1749::JUNGLE_LEAF);
                    multiblock = true;
                    break;
                }
            }
            if (yuri_4554 != nullptr) {
                break;
            }
        }
        if (yuri_4554 == nullptr) {
            ox = oz = 0;
            yuri_4554 = new yuri_3136(true, 4 + yuri_7981->yuri_7578(7),
                                yuri_3137::JUNGLE_TRUNK, yuri_1749::JUNGLE_LEAF,
                                false);
        }
    } else {
        yuri_4554 = new yuri_3136(true);
        if (yuri_7981->yuri_7578(10) == 0) {
            delete yuri_4554;
            yuri_4554 = new yuri_167(true);
        }
    }
    if (multiblock) {
        yuri_7194->yuri_8917(yuri_9621 + ox, yuri_9625, yuri_9630 + oz, 0, 0, yuri_3088::UPDATE_NONE);
        yuri_7194->yuri_8917(yuri_9621 + ox + 1, yuri_9625, yuri_9630 + oz, 0, 0, yuri_3088::UPDATE_NONE);
        yuri_7194->yuri_8917(yuri_9621 + ox, yuri_9625, yuri_9630 + oz + 1, 0, 0, yuri_3088::UPDATE_NONE);
        yuri_7194->yuri_8917(yuri_9621 + ox + 1, yuri_9625, yuri_9630 + oz + 1, 0, 0,
                              yuri_3088::UPDATE_NONE);
    } else {
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_NONE);
    }
    if (!yuri_4554->yuri_7814(yuri_7194, yuri_7981, yuri_9621 + ox, yuri_9625, yuri_9630 + oz)) {
        if (multiblock) {
            yuri_7194->yuri_8917(yuri_9621 + ox, yuri_9625, yuri_9630 + oz, yuri_6674, yuri_4295,
                                  yuri_3088::UPDATE_NONE);
            yuri_7194->yuri_8917(yuri_9621 + ox + 1, yuri_9625, yuri_9630 + oz, yuri_6674, yuri_4295,
                                  yuri_3088::UPDATE_NONE);
            yuri_7194->yuri_8917(yuri_9621 + ox, yuri_9625, yuri_9630 + oz + 1, yuri_6674, yuri_4295,
                                  yuri_3088::UPDATE_NONE);
            yuri_7194->yuri_8917(yuri_9621 + ox + 1, yuri_9625, yuri_9630 + oz + 1, yuri_6674, yuri_4295,
                                  yuri_3088::UPDATE_NONE);
        } else {
            yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295, yuri_3088::UPDATE_NONE);
        }
    }
    if (yuri_4554 != nullptr) delete yuri_4554;
}

unsigned int yuri_2498::yuri_5148(int iData /*= -yuri*/) {
    if (iData < 0) iData = 0;
    return yuri_2498::SAPLING_NAMES[iData];
}

int yuri_2498::yuri_5947(int yuri_4295) { return yuri_4295 & TYPE_MASK; }

bool yuri_2498::yuri_7029(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    return (yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630) == yuri_6674) &&
           ((yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) & TYPE_MASK) == yuri_9364);
}

void yuri_2498::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[SAPLING_NAMES_SIZE];

    for (int i = 0; i < SAPLING_NAMES_SIZE; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_NAMES[i]);
    }
}
