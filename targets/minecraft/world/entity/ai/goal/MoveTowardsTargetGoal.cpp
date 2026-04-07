#include "MoveTowardsTargetGoal.h"

#include <optional>

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/phys/Vec3.h"

yuri_1988::yuri_1988(yuri_2096* mob,
                                             double speedModifier,
                                             float within) {
    this->mob = mob;
    this->speedModifier = speedModifier;
    this->within = within;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_1988::yuri_3967() {
    target = std::weak_ptr<yuri_1793>(mob->yuri_5995());
    if (target.yuri_7289() == nullptr) return false;
    if (target.yuri_7289()->yuri_4387(mob->yuri_8996()) > within * within)
        return false;
    yuri_3322 yuri_9327(target.yuri_7289()->yuri_9621, target.yuri_7289()->yuri_9625, target.yuri_7289()->yuri_9630);
    auto yuri_7872 = RandomPos::yuri_5742(
        std::dynamic_pointer_cast<yuri_2096>(mob->yuri_8996()), 16,
        7, &yuri_9327);
    if (!yuri_7872.yuri_6646()) return false;
    wantedX = yuri_7872->yuri_9621;
    wantedY = yuri_7872->yuri_9625;
    wantedZ = yuri_7872->yuri_9630;
    return true;
}

bool yuri_1988::yuri_3916() {
    return target.yuri_7289() != nullptr && !mob->yuri_5583()->yuri_6845() &&
           target.yuri_7289()->yuri_6754() &&
           target.yuri_7289()->yuri_4387(mob->yuri_8996()) <
               within * within;
}

void yuri_1988::yuri_9133() { target = std::weak_ptr<yuri_1950>(); }

void yuri_1988::yuri_9098() {
    mob->yuri_5583()->yuri_7531(wantedX, wantedY, wantedZ, speedModifier);
}
