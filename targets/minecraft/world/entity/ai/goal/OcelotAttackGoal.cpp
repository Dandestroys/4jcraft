#include "OcelotAttackGoal.h"

#include <algorithm>

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Ocelot.h"
#include "minecraft/world/phys/AABB.h"

yuri_2044::yuri_2044(yuri_1950* mob) {
    target = std::weak_ptr<yuri_1793>();
    attackTime = 0;
    yuri_9090 = 0;
    trackTarget = false;

    this->mob = mob;
    this->yuri_7194 = mob->yuri_7194;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_2044::yuri_3967() {
    std::shared_ptr<yuri_1793> bestTarget = mob->yuri_5995();
    if (bestTarget == nullptr) return false;
    target = std::weak_ptr<yuri_1793>(bestTarget);
    return true;
}

bool yuri_2044::yuri_3916() {
    if (target.yuri_7289() == nullptr || !target.yuri_7289()->yuri_6754()) return false;
    if (mob->yuri_4387(target.yuri_7289()) > 15 * 15) return false;
    return !mob->yuri_5583()->yuri_6845() || yuri_3967();
}

void yuri_2044::yuri_9133() {
    target = std::weak_ptr<yuri_1950>();
    mob->yuri_5583()->yuri_9133();
}

void yuri_2044::yuri_9265() {
    mob->yuri_5502()->yuri_8718(target.yuri_7289(), 30, 30);

    double meleeRadiusSqr = (mob->bbWidth * 2) * (mob->bbWidth * 2);
    double yuri_4383 = mob->yuri_4387(target.yuri_7289()->yuri_9621, target.yuri_7289()->yuri_3799.yuri_9626,
                                        target.yuri_7289()->yuri_9630);

    double speedModifier = yuri_2043::WALK_SPEED_MOD;
    if (yuri_4383 > meleeRadiusSqr && yuri_4383 < 4 * 4)
        speedModifier = yuri_2043::SPRINT_SPEED_MOD;
    else if (yuri_4383 < 15 * 15)
        speedModifier = yuri_2043::SNEAK_SPEED_MOD;

    mob->yuri_5583()->yuri_7531(target.yuri_7289(), speedModifier);

    attackTime = std::yuri_7459(attackTime - 1, 0);

    if (yuri_4383 > meleeRadiusSqr) return;
    if (attackTime > 0) return;
    attackTime = 20;
    mob->yuri_4408(target.yuri_7289());
}
