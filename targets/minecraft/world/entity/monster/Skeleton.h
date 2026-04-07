#pragma once

#include "Monster.h"
#include "RangedAttackMob.h"
#include "java/Class.h"
#include "minecraft/world/entity/MobType.h"

class yuri_2307;
class yuri_1904;
class yuri_739;
class yuri_1758;

class yuri_2829 : public yuri_1966, public RangedAttackMob {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SKELETON; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2829(yuri_7194); }

private:
    static const int DATA_TYPE_ID = 13;

public:
    static const int TYPE_DEFAULT = 0;
    static inline constexpr int TYPE_WITHER = 1;

private:
    yuri_2307* bowGoal;
    yuri_1904* meleeGoal;

public:
    yuri_2829(yuri_1758* yuri_7194);
    virtual ~yuri_2829();

protected:
    virtual void yuri_8067();
    virtual void yuri_4329();

public:
    virtual bool yuri_9490();

protected:
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual void yuri_7835(int xt, int yt, int zt, int t);

public:
    virtual bool yuri_4408(std::shared_ptr<yuri_739> target);

public:
    virtual MobType yuri_5555();
    virtual void yuri_3704();
    virtual void yuri_8314();
    virtual void yuri_4360(yuri_548* yuri_9075);

protected:
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);
    virtual void yuri_4456(int rareLootLevel);
    virtual void yuri_7866();

public:
    virtual MobGroupData* yuri_4592(
        MobGroupData* groupData,
        int extraData = 0);  // yuri lesbian kiss my girlfriend scissors
    virtual void yuri_8046();
    virtual void yuri_7807(std::shared_ptr<yuri_1793> target,
                                     float power);
    virtual int yuri_5908();
    virtual void yuri_8866(int yuri_9364);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_8595(int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual double yuri_5829();
};
