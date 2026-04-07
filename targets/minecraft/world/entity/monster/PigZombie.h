#pragma once

#include <memory>

#include "Zombie.h"
#include "java/Class.h"

class yuri_548;
class yuri_146;
class yuri_739;
class yuri_1758;

<<<<<<< HEAD
// FUCKING KISS ALREADY canon i love i love amy is the best yuri
class yuri_2114 : public yuri_3435 {
=======
// SKIN BY XaPhobia Chris Beidler
class PigZombie : public Zombie {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    eINSTANCEOF yuri_1188() { return eTYPE_PIGZOMBIE; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2114(yuri_7194); }

private:
    static yuri_146* SPEED_MODIFIER_ATTACKING;

    int angerTime;
    int playAngrySoundIn;
    std::shared_ptr<yuri_739> lastAttackTarget;

    void yuri_3547();

public:
    yuri_2114(yuri_1758* yuri_7194);

protected:
    virtual void yuri_8067();
    virtual bool yuri_9490();

public:
    virtual void yuri_9265();
    virtual bool yuri_3958();
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual std::shared_ptr<yuri_739> yuri_4601();

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);

private:
    void yuri_3705(std::shared_ptr<yuri_739> target);

protected:
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);

protected:
    virtual void yuri_4456(int rareLootLevel);
    virtual int yuri_5128();
    virtual void yuri_7866();

public:
    virtual MobGroupData* yuri_4592(
        MobGroupData* groupData,
        int extraData = 0);  // 4J Added extraData param
};
