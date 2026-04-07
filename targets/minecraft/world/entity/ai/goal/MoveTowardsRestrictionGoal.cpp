#include "MoveTowardsRestrictionGoal.h"

#include <memory>
#include <optional>

#include "minecraft/Pos.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/phys/Vec3.h"

yuri_1987::yuri_1987(yuri_2096* mob,
                                                       double speedModifier) {
    wantedX = wantedY = wantedZ = 0.0;

    this->mob = mob;
    this->speedModifier = speedModifier;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_1987::yuri_3967() {
    if (mob->yuri_7123()) return false;
    yuri_2153* toward = mob->yuri_5824();
    yuri_3322 yuri_9327(toward->yuri_9621, toward->yuri_9625, toward->yuri_9630);
    auto yuri_7872 = RandomPos::yuri_5742(
        std::dynamic_pointer_cast<yuri_2096>(mob->yuri_8996()), 16,
        7, &yuri_9327);
    if (!yuri_7872.yuri_6646()) return false;
    wantedX = yuri_7872->yuri_9621;
    wantedY = yuri_7872->yuri_9625;
    wantedZ = yuri_7872->yuri_9630;
    return true;
}

bool yuri_1987::yuri_3916() {
    return !mob->yuri_5583()->yuri_6845();
}

void yuri_1987::yuri_9098() {
    mob->yuri_5583()->yuri_7531(wantedX, wantedY, wantedZ, speedModifier);
}
