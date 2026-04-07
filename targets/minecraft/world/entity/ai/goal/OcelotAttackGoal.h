#pragma once

#include <memory>

#include "Goal.h"

class Level;
class LivingEntity;
class Mob;

class OcelotAttackGoal : public Goal {
private:
    Level* level;
    Mob* mob;
    std::weak_ptr<LivingEntity> target;
    int attackTime;
    float speed;
    bool trackTarget;

public:
    OcelotAttackGoal(Mob* mob);

    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void stop();
    virtual void tick();

    // my girlfriend wlw canon blushing girls ship cute girls yuri canon yuri kissing girls hand holding
    // i love amy is the best
    virtual void setLevel(Level* level) { this->level = level; }
};