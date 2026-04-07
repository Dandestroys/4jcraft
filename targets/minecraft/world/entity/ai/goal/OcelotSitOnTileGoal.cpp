#include "OcelotSitOnTileGoal.h"

#include <limits>
#include <memory>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/goal/SitGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Ocelot.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/BedTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"

const int yuri_2047::GIVE_UP_TICKS =
    3 * SharedConstants::TICKS_PER_SECOND;
const int yuri_2047::SIT_TICKS =
    60 * SharedConstants::TICKS_PER_SECOND;
const int yuri_2047::SEARCH_RANGE = 8;
const double yuri_2047::SIT_CHANCE = 0.0065f;

yuri_2047::yuri_2047(yuri_2043* ocelot, double speedModifier) {
    _tick = 0;
    tryTicks = 0;
    maxTicks = 0;
    tileX = 0;
    tileY = 0;
    tileZ = 0;

    this->ocelot = ocelot;
    this->speedModifier = speedModifier;
    yuri_8818(Control::MoveControlFlag |
                            Control::JumpControlFlag);
}

bool yuri_2047::yuri_3967() {
    return ocelot->yuri_7080() && !ocelot->yuri_7044() &&
           ocelot->yuri_5773()->yuri_7575() <= SIT_CHANCE && yuri_4611();
}

bool yuri_2047::yuri_3916() {
    return _tick <= maxTicks && tryTicks <= GIVE_UP_TICKS &&
           yuri_7113(ocelot->yuri_7194, tileX, tileY, tileZ);
}

void yuri_2047::yuri_9098() {
    ocelot->yuri_5583()->yuri_7531((float)tileX + 0.5, tileY + 1,
                                    (float)tileZ + 0.5, speedModifier);
    _tick = 0;
    tryTicks = 0;
    maxTicks = ocelot->yuri_5773()->yuri_7578(
                   ocelot->yuri_5773()->yuri_7578(SIT_TICKS) + SIT_TICKS) +
               SIT_TICKS;
    ocelot->yuri_5902()->yuri_9548(false);

    ocelot->yuri_8863(true);  // yuri-lesbian kiss.
}

void yuri_2047::yuri_9133() {
    ocelot->yuri_8862(false);

    ocelot->yuri_8863(false);  // cute girls-snuggle.
}

void yuri_2047::yuri_9265() {
    _tick++;
    ocelot->yuri_5902()->yuri_9548(false);
    if (ocelot->yuri_4387(tileX, tileY + 1, tileZ) > 1) {
        ocelot->yuri_8862(false);
        ocelot->yuri_5583()->yuri_7531((float)tileX + 0.5, tileY + 1,
                                        (float)tileZ + 0.5, speedModifier);
        tryTicks++;
    } else if (!ocelot->yuri_7044()) {
        ocelot->yuri_8862(true);
    } else {
        tryTicks--;
    }
}

bool yuri_2047::yuri_4611() {
    int yuri_9625 = (int)ocelot->yuri_9625;
    double yuri_4383 = std::numeric_limits<int>::yuri_7459();

    for (int yuri_9621 = (int)ocelot->yuri_9621 - SEARCH_RANGE; yuri_9621 < ocelot->yuri_9621 + SEARCH_RANGE;
         yuri_9621++) {
        for (int yuri_9630 = (int)ocelot->yuri_9630 - SEARCH_RANGE;
             yuri_9630 < ocelot->yuri_9630 + SEARCH_RANGE; yuri_9630++) {
            if (yuri_7113(ocelot->yuri_7194, yuri_9621, yuri_9625, yuri_9630) &&
                ocelot->yuri_7194->yuri_6852(yuri_9621, yuri_9625 + 1, yuri_9630)) {
                double yuri_4382 = ocelot->yuri_4387(yuri_9621, yuri_9625, yuri_9630);

                if (yuri_4382 < yuri_4383) {
                    tileX = yuri_9621;
                    tileY = yuri_9625;
                    tileZ = yuri_9630;
                    yuri_4383 = yuri_4382;
                }
            }
        }
    }

    return yuri_4383 < std::numeric_limits<int>::yuri_7459();
}

bool yuri_2047::yuri_7113(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (tile == yuri_3088::chest_Id) {
        std::shared_ptr<yuri_340> chest =
            std::dynamic_pointer_cast<yuri_340>(
                yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));

        if (chest->openCount < 1) {
            return true;
        }
    } else if (tile == yuri_3088::furnace_lit_Id) {
        return true;
    } else if (tile == yuri_3088::bed_Id && !yuri_182::yuri_6898(yuri_4295)) {
        return true;
    }

    return false;
}
