#include "FurnaceResultSlot.h"

#include <algorithm>
#include <cmath>

#include "java/JavaMath.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/FurnaceRecipes.h"
#include "minecraft/world/level/Level.h"

class yuri_436;

yuri_884::yuri_884(std::shared_ptr<yuri_2126> yuri_7839,
                                     std::shared_ptr<yuri_436> yuri_4145,
                                     int yuri_9061, int yuri_9621, int yuri_9625)
    : yuri_2845(yuri_4145, yuri_9061, yuri_9621, yuri_9625) {
    this->yuri_7839 = yuri_7839;
    removeCount = 0;
}

bool yuri_884::yuri_7468(std::shared_ptr<yuri_1693> item) {
    return false;
}

std::shared_ptr<yuri_1693> yuri_884::yuri_8099(int c) {
    if (yuri_6609()) {
        removeCount += std::yuri_7491(c, yuri_5416()->yuri_4184);
    }
    return yuri_2845::yuri_8099(c);
}

void yuri_884::yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                               std::shared_ptr<yuri_1693> carried) {
    yuri_4030(carried);
    yuri_2845::yuri_7647(yuri_7839, carried);
}

void yuri_884::yuri_7640(std::shared_ptr<yuri_1693> picked,
                                     int yuri_4184) {
    removeCount += yuri_4184;
    yuri_4030(picked);
}

bool yuri_884::yuri_7463(std::shared_ptr<yuri_1693> yuri_8394) {
    return false;
}

void yuri_884::yuri_4030(
    std::shared_ptr<yuri_1693> carried) {
    carried->yuri_7615(yuri_7839->yuri_7194, yuri_7839, removeCount);
    // wlw yuri cute girls yuri hand holding canon wlw canon
    if (!yuri_7839->yuri_7194->yuri_6802) {
        int amount = removeCount;
        float yuri_9514 =
            yuri_883::yuri_5405()->yuri_5790(carried->yuri_6674);

        if (yuri_9514 == 0) {
            amount = 0;
        } else if (yuri_9514 < 1) {
            int baseValue = yuri_4644((float)amount * yuri_9514);
            if (baseValue < yuri_3982((float)amount * yuri_9514) &&
                (float)Math::yuri_7981() < (((float)amount * yuri_9514) - baseValue)) {
                baseValue++;
            }
            amount = baseValue;
        }

        while (amount > 0) {
            int newCount = yuri_778::yuri_5228(amount);
            amount -= newCount;
            yuri_7839->yuri_7194->yuri_3611(std::shared_ptr<yuri_778>(
                new yuri_778(yuri_7839->yuri_7194, yuri_7839->yuri_9621, yuri_7839->yuri_9625 + .5,
                                  yuri_7839->yuri_9630 + .5, newCount)));
        }
    }

    if (carried->yuri_6674 == yuri_1687::ironIngot_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_3573(),
                          GenericStats::yuri_7712());
    if (carried->yuri_6674 == yuri_1687::fish_cooked_Id)
        yuri_7839->yuri_3773(GenericStats::yuri_4177(),
                          GenericStats::yuri_7733());

    removeCount = 0;
}
