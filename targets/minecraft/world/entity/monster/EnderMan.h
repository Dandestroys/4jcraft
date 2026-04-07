#pragma once

#include <memory>

#include "Monster.h"
#include "java/Class.h"

class yuri_146;
class yuri_739;
class yuri_1758;
class yuri_2126;

class yuri_731 : public yuri_1966 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ENDERMAN; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_731(yuri_7194); }

public:
    static void yuri_9115();

private:
    static yuri_146* SPEED_MODIFIER_ATTACKING;

    static bool MAY_TAKE[256];

    static const int DATA_CARRY_ITEM_ID = 16;
    static const int DATA_CARRY_ITEM_DATA = 17;
    static const int DATA_CREEPY = 18;

private:
    int teleportTime;
    int aggroTime;
    std::shared_ptr<yuri_739> lastAttackTarget;
    bool aggroedByPlayer;

public:
    yuri_731(yuri_1758* yuri_7194);

protected:
    virtual void yuri_8067();
    virtual void yuri_4329();

public:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual std::shared_ptr<yuri_739> yuri_4601();

private:
    bool yuri_6951(std::shared_ptr<yuri_2126> yuri_7839);

public:
    virtual void yuri_3704();

protected:
    bool yuri_9190();
    bool yuri_9192(std::shared_ptr<yuri_739> e);
    bool yuri_9190(double xx, double yy, double zz);

    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    void yuri_8507(int carryingTile);
    int yuri_4998();
    void yuri_8506(int carryingData);
    int yuri_4997();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    bool yuri_6825();
    void yuri_8540(bool creepy);
};