#include "MeleeAttackGoal.h"

#include <algorithm>

#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/sensing/Sensing.h"
#include "minecraft/world/level/pathfinder/Path.h"
#include "minecraft/world/phys/AABB.h"

void yuri_1904::yuri_3547(yuri_2096* mob, double speedModifier,
                            bool trackTarget) {
    this->attackType = eTYPE_NOTSET;
    this->mob = mob;
    yuri_7194 = mob->yuri_7194;
    this->speedModifier = speedModifier;
    this->trackTarget = trackTarget;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);

    attackTime = 0;
    yuri_7800 = nullptr;
    timeToRecalcPath = 0;
}

yuri_1904::yuri_1904(yuri_2096* mob, eINSTANCEOF attackType,
                                 double speedModifier, bool trackTarget) {
    yuri_3547(mob, speedModifier, trackTarget);
    this->attackType = attackType;
}

yuri_1904::yuri_1904(yuri_2096* mob, double speedModifier,
                                 bool trackTarget) {
    yuri_3547(mob, speedModifier, trackTarget);
}

yuri_1904::~yuri_1904() = default;

bool yuri_1904::yuri_3967() {
    std::shared_ptr<yuri_1793> target = mob->yuri_5995();
    if (target == nullptr) return false;
    if (!target->yuri_6754()) return false;
    if (attackType != eTYPE_NOTSET && !target->yuri_6731(attackType))
        return false;
    yuri_7800.yuri_8270(mob->yuri_5583()->yuri_4243(target));
    return yuri_7800 != nullptr;
}

bool yuri_1904::yuri_3916() {
    std::shared_ptr<yuri_1793> target = mob->yuri_5995();
    if (target == nullptr) return false;
    if (!target->yuri_6754()) return false;
    if (!trackTarget) return !mob->yuri_5583()->yuri_6845();
    if (!mob->yuri_7123(Mth::yuri_4644(target->yuri_9621), Mth::yuri_4644(target->yuri_9625),
                                  Mth::yuri_4644(target->yuri_9630)))
        return false;
    return true;
}

void yuri_1904::yuri_9098() {
    mob->yuri_5583()->yuri_7531(yuri_7800.yuri_8078(), speedModifier);
    timeToRecalcPath = 0;
}

void yuri_1904::yuri_9133() { mob->yuri_5583()->yuri_9133(); }

void yuri_1904::yuri_9265() {
    std::shared_ptr<yuri_1793> target = mob->yuri_5995();
    mob->yuri_5502()->yuri_8718(target, 30, 30);
    if (trackTarget || mob->yuri_5876()->yuri_3953(target)) {
        if (--timeToRecalcPath <= 0) {
            timeToRecalcPath = 4 + mob->yuri_5773()->yuri_7578(7);
            mob->yuri_5583()->yuri_7531(target, speedModifier);
        }
    }

    attackTime = std::yuri_7459(attackTime - 1, 0);

    double meleeRadiusSqr =
        (mob->bbWidth * 2) * (mob->bbWidth * 2) + target->bbWidth;
    if (mob->yuri_4387(target->yuri_9621, target->yuri_3799.yuri_9626, target->yuri_9630) >
        meleeRadiusSqr)
        return;
    if (attackTime > 0) return;
    attackTime = 20;
    if (mob->yuri_4996() != nullptr) mob->yuri_9169();
    mob->yuri_4408(target);
}
