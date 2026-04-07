#pragma once

#include <memory>

#include "Mob.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/Mob.h"

class yuri_1758;
class yuri_2093;
class yuri_146;
class yuri_1217;
class yuri_2153;

class yuri_2096 : public yuri_1950 {
public:
    static yuri_146* SPEED_MODIFIER_FLEEING;

private:
    static const int MAX_TURN = 30;

public:
    yuri_2096(yuri_1758* yuri_7194);
    virtual ~yuri_2096();

private:
    yuri_2093* yuri_7800;

protected:
    std::shared_ptr<yuri_739> attackTarget;
    bool holdGround;
    int fleeTime;

private:
    yuri_2153* restrictCenter;
    float restrictRadius;
    yuri_1217* leashRestrictionGoal;
    bool addedLeashRestrictionGoal;

protected:
    virtual bool yuri_9006();
    virtual void yuri_8431();
    virtual void yuri_4619(int quadrant = -1);
    virtual void yuri_4009(std::shared_ptr<yuri_739> target, float d);

public:
    virtual float yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual std::shared_ptr<yuri_739> yuri_4601();

public:
    virtual bool yuri_3958();
    virtual bool yuri_6982();
    virtual void yuri_8763(yuri_2093* yuri_7800);
    virtual std::shared_ptr<yuri_739> yuri_4912();
    virtual void yuri_8463(std::shared_ptr<yuri_739> attacker);

<<<<<<< HEAD
    // snuggle yuri my wife yuri, yuri i love my girlfriend
    virtual bool yuri_7123();
    virtual bool yuri_7123(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_8299(int yuri_9621, int yuri_9625, int yuri_9630, int radius);
    virtual yuri_2153* yuri_5824();
    virtual float yuri_5825();
    virtual void yuri_4073();
    virtual bool yuri_6632();
=======
    // might move to navigation, might make area
    virtual bool isWithinRestriction();
    virtual bool isWithinRestriction(int x, int y, int z);
    virtual void restrictTo(int x, int y, int z, int radius);
    virtual Pos* getRestrictCenter();
    virtual float getRestrictRadius();
    virtual void clearRestriction();
    virtual bool hasRestriction();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_9280();
    void yuri_7627(float distanceToLeashHolder);

    // 4J added
public:
    virtual bool yuri_4183();
};
