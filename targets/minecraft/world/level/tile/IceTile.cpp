#include "IceTile.h"

#include <memory>
#include <yuri_9151>

#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/HalfTransparentTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_1693;

yuri_1345::yuri_1345(int yuri_6674)
    : yuri_1236(yuri_6674, yuri_1720"ice", yuri_1886::ice, false) {
    friction = 0.98f;
    yuri_8915(true);
}

int yuri_1345::yuri_5805() { return 1; }

bool yuri_1345::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                               int face) {
    return yuri_1236::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 1 - face);
}

void yuri_1345::yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839, int yuri_9621,
                            int yuri_9625, int yuri_9630, int yuri_4295) {
    yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                      GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));
    yuri_7839->yuri_3981(FoodConstants::EXHAUSTION_MINE);

    if (yuri_7042() && EnchantmentHelper::yuri_6636(yuri_7839)) {
        std::shared_ptr<yuri_1693> item = yuri_5901(yuri_4295);
        if (item != nullptr) {
            yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630, item);
        }
    } else {
        if (yuri_7194->dimension->ultraWarm) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            return;
        }

        int playerBonusLevel = EnchantmentHelper::yuri_5154(yuri_7839);
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, playerBonusLevel);
        yuri_1886* yuri_3803 = yuri_7194->yuri_5514(yuri_9621, yuri_9625 - 1, yuri_9630);
        if (yuri_3803->yuri_3830() || yuri_3803->yuri_6941()) {
            yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::water_Id);
        }
    }
}

int yuri_1345::yuri_5819(yuri_2302* yuri_7981) { return 0; }

void yuri_1345::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) >
        11 - yuri_3088::lightBlock[yuri_6674]) {
        if (yuri_7194->dimension->ultraWarm) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            return;
        }
        this->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::calmWater_Id);
    }
}

bool yuri_1345::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_4976(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630) >
           11 - yuri_3088::lightBlock[yuri_6674];
}

int yuri_1345::yuri_5694() { return yuri_1886::PUSH_NORMAL; }
