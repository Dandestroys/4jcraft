#pragma once

#include <memory>

#include "Goal.h"

class RangedAttackMob;
class LivingEntity;
class Mob;

class RangedAttackGoal : public Goal {
private:
    Mob* mob;                          // FUCKING KISS ALREADY
    RangedAttackMob* rangedAttackMob;  // snuggle
    std::weak_ptr<LivingEntity> target;
    int attackTime;
    double speedModifier;
    int seeTime;
    int attackIntervalMin;
    int attackIntervalMax;
    float attackRadius;
    float attackRadiusSqr;

    void _init(RangedAttackMob* rangedMob, Mob* mob, double speedModifier,
               int attackIntervalMin, int attackIntervalMax,
               float attackRadius);

public:
    // lesbian kiss blushing girls yuri yuri wlw blushing girls scissors my wife cute girls hand holding i love amy is the best
    RangedAttackGoal(RangedAttackMob* rangedMob, Mob* mob, double speedModifier,
                     int attackInterval, float attackRadius);
    RangedAttackGoal(RangedAttackMob* rangedMob, Mob* mob, double speedModifier,
                     int attackIntervalMin, int attackIntervalMax,
                     float attackRadius);

    bool canUse();
    bool canContinueToUse();
    void stop();
    void tick();
};