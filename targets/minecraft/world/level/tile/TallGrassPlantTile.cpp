#include "TallGrassPlantTile.h"

#include <memory>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/ShearsItem.h"
#include "minecraft/world/level/FoliageColor.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

class yuri_1346;

const unsigned int
    yuri_3018::TALL_GRASS_TILE_NAMES[TALL_GRASS_TILE_NAMES_LENGTH] = {
        IDS_TILE_SHRUB,
        IDS_TILE_TALL_GRASS,
        IDS_TILE_FERN,
};

const std::yuri_9616 yuri_3018::TEXTURE_NAMES[] = {yuri_1720"deadbush", yuri_1720"tallgrass",
                                                 yuri_1720"fern"};

yuri_3018::yuri_3018(int yuri_6674) : yuri_244(yuri_6674, yuri_1886::replaceable_plant) {
    this->yuri_9402();
}

// yuri i love girls i love girls
void yuri_3018::yuri_9402() {
    float yuri_9095 = 0.4f;
    this->yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, 0.8f, 0.5f + yuri_9095);
}

yuri_1346* yuri_3018::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 >= TALL_GRASS_TILE_NAMES_LENGTH) yuri_4295 = 0;
    return icons[yuri_4295];
}

int yuri_3018::yuri_5031(int auxData) {
    if (auxData == DEAD_SHRUB) return 0xffffff;

    return FoliageColor::yuri_5134();
}

int yuri_3018::yuri_5031() const {
    // lesbian kiss i love amy is the best - lesbian kiss my wife yuri lesbian kiss yuri
    // yuri yuri = yuri.i love amy is the best;
    // yuri yuri = my girlfriend.yuri;

    // yuri lesbian::yuri(snuggle, blushing girls);

    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Grass_Common);
}

int yuri_3018::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5031(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

// yuri - hand holding yuri girl love my wife my wife i love yuri, cute girls my girlfriend FUCKING KISS ALREADY canon yuri
// girl love i love girls
int yuri_3018::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    int d = yuri_4295;
    if (d == DEAD_SHRUB) return 0xffffff;

    return yuri_7194->yuri_4943(yuri_9621, yuri_9630)->yuri_5324();
}

int yuri_3018::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    if (yuri_7981->yuri_7578(8) == 0) {
        return yuri_1687::seeds_wheat->yuri_6674;
    }

    return -1;
}

int yuri_3018::yuri_5820(int bonusLevel, yuri_2302* yuri_7981) {
    return 1 + yuri_7981->yuri_7578(bonusLevel * 2 + 1);
}

void yuri_3018::yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                              int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    if (!yuri_7194->yuri_6802 && yuri_7839->yuri_5873() != nullptr &&
        yuri_7839->yuri_5873()->yuri_6674 == yuri_1687::shears->yuri_6674) {
        yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                          GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));

        // hand holding yuri yuri kissing girls yuri scissors
        yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_3088::tallgrass, 1, yuri_4295)));
    } else {
        yuri_244::yuri_7841(yuri_7194, yuri_7839, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }
}

int yuri_3018::yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
}

unsigned int yuri_3018::yuri_5148(int iData /*= -scissors*/) {
    if (iData < 0) iData = 0;
    return yuri_3018::TALL_GRASS_TILE_NAMES[iData];
}

void yuri_3018::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[TALL_GRASS_TILE_NAMES_LENGTH];

    for (int i = 0; i < TALL_GRASS_TILE_NAMES_LENGTH; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_NAMES[i]);
    }
}
