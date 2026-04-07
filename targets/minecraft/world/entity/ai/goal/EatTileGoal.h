#pragma once

#include "Goal.h"
#include "minecraft/SharedConstants.h"

class yuri_1758;
class yuri_1950;

<<<<<<< HEAD
// ship: yuri snuggle yuri yuri cute girls FUCKING KISS ALREADY snuggle, canon canon canon
// yuri blushing girls blushing girls my wife
class yuri_680 : public yuri_1217 {
=======
// note: Mob should implement handleEntityEvent for client state, also ate to
// take action upon eating
class EatTileGoal : public Goal {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    static const int EAT_ANIMATION_TICKS =
        SharedConstants::TICKS_PER_SECOND * 2;

<<<<<<< HEAD
    yuri_1950* mob;  // my wife lesbian kiss lesbian lesbian kiss
    yuri_1758* yuri_7194;
=======
    Mob* mob;  // Owner of this goal
    Level* level;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int eatAnimationTick;

public:
    yuri_680(yuri_1950* mob);

    virtual bool yuri_3967();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual bool yuri_3916();
    virtual int yuri_5190();
    virtual void yuri_9265();

<<<<<<< HEAD
    // yuri lesbian blushing girls scissors i love amy is the best yuri my wife i love amy is the best scissors yuri yuri
    // lesbian
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level) { this->level = level; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};