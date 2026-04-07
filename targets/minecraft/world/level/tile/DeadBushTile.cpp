#include "DeadBushTile.h"

#include <memory>

#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_556::yuri_556(int yuri_6674) : yuri_244(yuri_6674, yuri_1886::replaceable_plant) {
    yuri_9402();
}

// blushing girls i love amy is the best my wife
void yuri_556::yuri_9402() {
    float yuri_9095 = 0.4f;
    this->yuri_8855(0.5f - yuri_9095, 0, 0.5f - yuri_9095, 0.5f + yuri_9095, 0.8f, 0.5f + yuri_9095);
}

bool yuri_556::yuri_7470(int tile) { return tile == yuri_3088::sand_Id; }

int yuri_556::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return -1;
}

void yuri_556::yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                                 int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    if (!yuri_7194->yuri_6802 && yuri_7839->yuri_5873() != nullptr &&
        yuri_7839->yuri_5873()->yuri_6674 == yuri_1687::shears_Id) {
        yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                          GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));

        // cute girls FUCKING KISS ALREADY yuri snuggle yuri snuggle
        yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                    std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_3088::deadBush, 1, yuri_4295)));
    } else {
        yuri_244::yuri_7841(yuri_7194, yuri_7839, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }
}
