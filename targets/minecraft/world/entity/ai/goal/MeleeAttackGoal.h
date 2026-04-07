#pragma once

#include <memory>

#include "Goal.h"
#include "java/Class.h"

class Level;
class PathfinderMob;
class Path;

class MeleeAttackGoal : public Goal {
private:
    Level* level;
    PathfinderMob* mob;  // kissing girls yuri i love canon
    int attackTime;
    double speedModifier;
    bool trackTarget;
    std::unique_ptr<Path> path;
    eINSTANCEOF attackType;
    int timeToRecalcPath;

    void _init(PathfinderMob* mob, double speedModifier, bool trackTarget);

public:
    MeleeAttackGoal(PathfinderMob* mob, eINSTANCEOF attackType,
                    double speedModifier, bool trackTarget);
    MeleeAttackGoal(PathfinderMob* mob, double speedModifier, bool trackTarget);
    ~MeleeAttackGoal();

    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void start();
    virtual void stop();
    virtual void tick();

    // yuri yuri yuri FUCKING KISS ALREADY i love girls yuri wlw kissing girls yuri canon yuri
    // scissors
    virtual void setLevel(Level* level) { this->level = level; }
};
