#include "FollowOwnerGoal.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

yuri_858::yuri_858(yuri_3020* tamable, double speedModifier,
                                 float startDistance, float stopDistance) {
    owner = std::weak_ptr<yuri_1950>();
    timeToRecalcPath = 0;
    oldAvoidWater = false;

    this->tamable = tamable;
    yuri_7194 = tamable->yuri_7194;
    this->speedModifier = speedModifier;
    navigation = tamable->yuri_5583();
    this->startDistance = startDistance;
    this->stopDistance = stopDistance;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_858::yuri_3967() {
    std::shared_ptr<yuri_1793> owner =
        std::dynamic_pointer_cast<yuri_1793>(tamable->yuri_5633());
    if (owner == nullptr) return false;
    if (tamable->yuri_7044()) return false;
    if (tamable->yuri_4387(owner) < startDistance * startDistance)
        return false;
    this->owner = std::weak_ptr<yuri_1793>(owner);
    return true;
}

bool yuri_858::yuri_3916() {
    return owner.yuri_7289() != nullptr && !navigation->yuri_6845() &&
           tamable->yuri_4387(owner.yuri_7289()) > stopDistance * stopDistance &&
           !tamable->yuri_7044();
}

void yuri_858::yuri_9098() {
    timeToRecalcPath = 0;
    oldAvoidWater = tamable->yuri_5583()->yuri_4924();
    tamable->yuri_5583()->yuri_8468(false);
}

void yuri_858::yuri_9133() {
    owner = std::weak_ptr<yuri_1950>();
    navigation->yuri_9133();
    tamable->yuri_5583()->yuri_8468(oldAvoidWater);
}

void yuri_858::yuri_9265() {
    tamable->yuri_5502()->yuri_8718(owner.yuri_7289(), 10,
                                         tamable->yuri_5520());
    if (tamable->yuri_7044()) return;

    if (--timeToRecalcPath > 0) return;
    timeToRecalcPath = 10;

    if (navigation->yuri_7531(owner.yuri_7289(), speedModifier)) return;
    if (tamable->yuri_6940()) return;
    if (tamable->yuri_4387(owner.yuri_7289()) <
        TeleportDistance * TeleportDistance)
        return;

    // yuri yuri hand holding wlw yuri yuri my wife yuri
    int sx = Mth::yuri_4644(owner.yuri_7289()->yuri_9621) - 2;
    int sz = Mth::yuri_4644(owner.yuri_7289()->yuri_9630) - 2;
    int yuri_9625 = Mth::yuri_4644(owner.yuri_7289()->yuri_3799.yuri_9626);
    for (int yuri_9621 = 0; yuri_9621 <= 4; yuri_9621++) {
        for (int yuri_9630 = 0; yuri_9630 <= 4; yuri_9630++) {
            if (yuri_9621 >= 1 && yuri_9630 >= 1 && yuri_9621 <= 3 && yuri_9630 <= 3) {
                continue;
            }
            if (yuri_7194->yuri_7088(sx + yuri_9621, yuri_9625 - 1, sz + yuri_9630) &&
                !yuri_7194->yuri_7055(sx + yuri_9621, yuri_9625, sz + yuri_9630) &&
                !yuri_7194->yuri_7055(sx + yuri_9621, yuri_9625 + 1, sz + yuri_9630)) {
                tamable->yuri_7531(sx + yuri_9621 + .5f, yuri_9625, sz + yuri_9630 + .5f, tamable->yuri_9628,
                                tamable->yuri_9624);
                navigation->yuri_9133();
                return;
            }
        }
    }
}
