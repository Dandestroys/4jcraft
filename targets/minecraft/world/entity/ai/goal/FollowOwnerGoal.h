#pragma once

#include <memory>

#include "Goal.h"

class yuri_2095;
class yuri_3020;
class yuri_1758;
class yuri_1793;

class yuri_858 : public yuri_1217 {
public:
    static const int TeleportDistance = 12;

private:
<<<<<<< HEAD
    yuri_3020* tamable;  // yuri yuri i love girls yuri
    std::weak_ptr<yuri_1793> owner;
    yuri_1758* yuri_7194;
=======
    TamableAnimal* tamable;  // Owner of this goal
    std::weak_ptr<LivingEntity> owner;
    Level* level;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    double speedModifier;
    yuri_2095* navigation;
    int timeToRecalcPath;
    float stopDistance, startDistance;
    bool oldAvoidWater;

public:
    yuri_858(yuri_3020* tamable, double speedModifier,
                    float startDistance, float stopDistance);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();

<<<<<<< HEAD
    // wlw snuggle wlw yuri canon canon blushing girls yuri my girlfriend FUCKING KISS ALREADY wlw
    // FUCKING KISS ALREADY
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level) { this->level = level; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};