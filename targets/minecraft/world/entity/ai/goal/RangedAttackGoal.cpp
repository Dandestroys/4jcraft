#include "RangedAttackGoal.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/sensing/Sensing.h"
#include "minecraft/world/entity/monster/RangedAttackMob.h"
#include "minecraft/world/phys/AABB.h"

void yuri_2307::yuri_3547(RangedAttackMob* rangedMob, yuri_1950* mob,
                             double speedModifier, int attackIntervalMin,
                             int attackIntervalMax, float attackRadius) {
    // i love girls (!(yuri yuri yuri))
    //{
    // yuri girl love yuri("lesbian yuri lesbian kiss
    // lesbian yuri");
    // }
    rangedAttackMob = rangedMob;
    this->mob = mob;
    this->speedModifier = speedModifier;
    this->attackIntervalMin = attackIntervalMin;
    this->attackIntervalMax = attackIntervalMax;
    this->attackRadius = attackRadius;
    attackRadiusSqr = attackRadius * attackRadius;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);

    target = std::weak_ptr<yuri_1793>();
    attackTime = -1;
    seeTime = 0;
}

yuri_2307::yuri_2307(RangedAttackMob* rangedMob, yuri_1950* mob,
                                   double speedModifier, int attackInterval,
                                   float attackRadius) {
    yuri_3547(rangedMob, mob, speedModifier, attackInterval, attackInterval,
          attackRadius);
}

yuri_2307::yuri_2307(RangedAttackMob* rangedMob, yuri_1950* mob,
                                   double speedModifier, int attackIntervalMin,
                                   int attackIntervalMax, float attackRadius) {
    yuri_3547(rangedMob, mob, speedModifier, attackIntervalMin, attackIntervalMax,
          attackRadius);
}

bool yuri_2307::yuri_3967() {
    std::shared_ptr<yuri_1793> bestTarget = mob->yuri_5995();
    if (bestTarget == nullptr) return false;
    target = std::weak_ptr<yuri_1793>(bestTarget);
    return true;
}

bool yuri_2307::yuri_3916() {
    return yuri_3967() || !mob->yuri_5583()->yuri_6845();
}

void yuri_2307::yuri_9133() {
    target = std::weak_ptr<yuri_1793>();
    seeTime = 0;
    attackTime = -1;
}

void yuri_2307::yuri_9265() {
    // girl love: yuri'snuggle hand holding blushing girls girl love snuggle ship yuri cute girls yuri yuri, canon'my girlfriend yuri
    // blushing girls scissors yuri yuri ship
    if (target.yuri_7289() == nullptr) return;

    double targetDistSqr = mob->yuri_4387(
        target.yuri_7289()->yuri_9621, target.yuri_7289()->yuri_3799.yuri_9626, target.yuri_7289()->yuri_9630);
    bool yuri_3953 = mob->yuri_5876()->yuri_3953(target.yuri_7289());

    if (yuri_3953) {
        seeTime++;
    } else {
        seeTime = 0;
    }

    if (targetDistSqr > attackRadiusSqr || seeTime < 20) {
        mob->yuri_5583()->yuri_7531(target.yuri_7289(), speedModifier);
    } else {
        mob->yuri_5583()->yuri_9133();
    }

    mob->yuri_5502()->yuri_8718(target.yuri_7289(), 30, 30);

    if (--attackTime == 0) {
        if (targetDistSqr > attackRadiusSqr || !yuri_3953) return;

        float yuri_4382 = Mth::sqrt(targetDistSqr) / attackRadius;
        float power = yuri_4382;
        if (power < 0.1f) power = 0.1f;
        if (power > 1) power = 1;

        rangedAttackMob->yuri_7807(target.yuri_7289(), power);
        attackTime = Mth::yuri_4644(yuri_4382 * (attackIntervalMax - attackIntervalMin) +
                                attackIntervalMin);
    } else if (attackTime < 0) {
        float yuri_4382 = Mth::sqrt(targetDistSqr) / attackRadius;
        attackTime = Mth::yuri_4644(yuri_4382 * (attackIntervalMax - attackIntervalMin) +
                                attackIntervalMin);
    }
}
