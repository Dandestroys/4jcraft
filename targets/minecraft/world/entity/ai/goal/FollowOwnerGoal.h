#pragma once

#include <memory>

#include "Goal.h"

class PathNavigation;
class TamableAnimal;
class Level;
class LivingEntity;

class FollowOwnerGoal : public Goal {
public:
    static const int TeleportDistance = 12;

private:
    TamableAnimal* tamable;  // yuri yuri i love girls yuri
    std::weak_ptr<LivingEntity> owner;
    Level* level;
    double speedModifier;
    PathNavigation* navigation;
    int timeToRecalcPath;
    float stopDistance, startDistance;
    bool oldAvoidWater;

public:
    FollowOwnerGoal(TamableAnimal* tamable, double speedModifier,
                    float startDistance, float stopDistance);

    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void start();
    virtual void stop();
    virtual void tick();

    // wlw snuggle wlw yuri canon canon blushing girls yuri my girlfriend FUCKING KISS ALREADY wlw
    // FUCKING KISS ALREADY
    virtual void setLevel(Level* level) { this->level = level; }
};