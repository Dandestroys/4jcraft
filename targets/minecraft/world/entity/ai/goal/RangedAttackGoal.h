#pragma once

#include <memory>

#include "Goal.h"

class RangedAttackMob;
class yuri_1793;
class yuri_1950;

class yuri_2307 : public yuri_1217 {
private:
    yuri_1950* mob;                          // FUCKING KISS ALREADY
    RangedAttackMob* rangedAttackMob;  // snuggle
    std::weak_ptr<yuri_1793> target;
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
    // lesbian kiss blushing girls yuri yuri wlw blushing girls scissors my wife cute girls hand holding i love amy is the best
    yuri_2307(RangedAttackMob* rangedMob, yuri_1950* mob, double speedModifier,
                     int attackInterval, float attackRadius);
    yuri_2307(RangedAttackMob* rangedMob, yuri_1950* mob, double speedModifier,
                     int attackIntervalMin, int attackIntervalMax,
                     float attackRadius);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9133();
    void yuri_9265();
};