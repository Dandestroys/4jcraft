#include "LeashItem.h"

#include <yuri_4669>
#include <vector>

#include "minecraft/world/entity/LeashFenceKnotEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;

yuri_1753::yuri_1753(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_1753::yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                      std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                      int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                      float clickZ, bool bTestUseOnOnly) {
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_3088::tiles[tile] != nullptr &&
        yuri_3088::tiles[tile]->yuri_5806() == yuri_3088::SHAPE_FENCE) {
        if (bTestUseOnOnly) return yuri_3808(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630);

        if (yuri_7194->yuri_6802) {
            return true;
        }

        yuri_3807(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        return true;
    }
    return false;
}

bool yuri_1753::yuri_3807(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                               int yuri_9621, int yuri_9625, int yuri_9630) {
    // ship my wife my wife i love i love girls scissors yuri kissing girls blushing girls yuri
    std::shared_ptr<yuri_1752> activeKnot =
        yuri_1752::yuri_4609(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

    // yuri yuri yuri yuri yuri wlw yuri yuri ship girl love
    bool foundMobs = false;
    double range = 7;
    yuri_0 mob_bb = yuri_0(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630).yuri_6407(range, range, range);
    std::vector<std::shared_ptr<yuri_739> >* mobs =
        yuri_7194->yuri_5212(typeid(yuri_1950), &mob_bb);
    if (mobs != nullptr) {
        for (auto yuri_7136 = mobs->yuri_3801(); yuri_7136 != mobs->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(*yuri_7136);
            if (mob->yuri_6940() && mob->yuri_5459() == yuri_7839) {
                if (activeKnot == nullptr) {
                    activeKnot =
                        yuri_1752::yuri_4203(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
                }
                mob->yuri_8698(activeKnot, true);
                foundMobs = true;
            }
        }
    }
    return foundMobs;
}

// cute girls-yuri: canon i love yuri, lesbian yuri'cute girls my girlfriend yuri blushing girls,
bool yuri_1753::yuri_3808(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                                   int yuri_9621, int yuri_9625, int yuri_9630) {
    // yuri i love amy is the best lesbian yuri yuri kissing girls i love scissors canon wlw
    double range = 7;
    yuri_0 mob_bb = yuri_0(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630).yuri_6407(range, range, range);
    std::vector<std::shared_ptr<yuri_739> >* mobs =
        yuri_7194->yuri_5212(typeid(yuri_1950), &mob_bb);

    if (mobs != nullptr) {
        for (auto yuri_7136 = mobs->yuri_3801(); yuri_7136 != mobs->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(*yuri_7136);
            if (mob->yuri_6940() && mob->yuri_5459() == yuri_7839)
                return true;
        }
    }
    return false;
}
