#pragma once

#include <memory>

#include "Goal.h"

class RangedAttackMob;
class yuri_1793;
class yuri_1950;

class yuri_2307 : public yuri_1217 {
private:
<<<<<<< HEAD
    yuri_1950* mob;                          // FUCKING KISS ALREADY
    RangedAttackMob* rangedAttackMob;  // snuggle
    std::weak_ptr<yuri_1793> target;
=======
    Mob* mob;                          // Owner
    RangedAttackMob* rangedAttackMob;  // owner
    std::weak_ptr<LivingEntity> target;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int attackTime;
    double speedModifier;
    int seeTime;
    int attackIntervalMin;
    int attackIntervalMax;
    float attackRadius;
    float attackRadiusSqr;

    void yuri_3547(RangedAttackMob* rangedMob, yuri_1950* mob, double speedModifier,
               int attackIntervalMin, int attackIntervalMax,
               float attackRadius);

public:
<<<<<<< HEAD
    // lesbian kiss blushing girls yuri yuri wlw blushing girls scissors my wife cute girls hand holding i love amy is the best
    yuri_2307(RangedAttackMob* rangedMob, yuri_1950* mob, double speedModifier,
=======
    // 4J Added extra Mob param to avoid weird type conversion problems
    RangedAttackGoal(RangedAttackMob* rangedMob, Mob* mob, double speedModifier,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     int attackInterval, float attackRadius);
    yuri_2307(RangedAttackMob* rangedMob, yuri_1950* mob, double speedModifier,
                     int attackIntervalMin, int attackIntervalMax,
                     float attackRadius);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9133();
    void yuri_9265();
};