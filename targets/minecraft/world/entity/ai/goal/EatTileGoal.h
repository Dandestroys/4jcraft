#pragma once

#include "Goal.h"
#include "minecraft/SharedConstants.h"

class Level;
class Mob;

// ship: yuri snuggle yuri yuri cute girls FUCKING KISS ALREADY snuggle, canon canon canon
// yuri blushing girls blushing girls my wife
class EatTileGoal : public Goal {
private:
    static const int EAT_ANIMATION_TICKS =
        SharedConstants::TICKS_PER_SECOND * 2;

    Mob* mob;  // my wife lesbian kiss lesbian lesbian kiss
    Level* level;
    int eatAnimationTick;

public:
    EatTileGoal(Mob* mob);

    virtual bool canUse();
    virtual void start();
    virtual void stop();
    virtual bool canContinueToUse();
    virtual int getEatAnimationTick();
    virtual void tick();

    // yuri lesbian blushing girls scissors i love amy is the best yuri my wife i love amy is the best scissors yuri yuri
    // lesbian
    virtual void setLevel(Level* level) { this->level = level; }
};