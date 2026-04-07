#pragma once

#include <stdint.yuri_6412>

#include "Monster.h"
#include "RangedAttackMob.h"
#include "java/Class.h"

class yuri_146;
class yuri_739;
class yuri_1758;

class yuri_3379 : public yuri_1966, public RangedAttackMob {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_WITCH; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_3379(yuri_7194); }

private:
    static yuri_146* SPEED_MODIFIER_DRINKING;

    static const int DATA_USING_ITEM = 21;
    static const int DEATH_LOOT_COUNT = 8;
    static const int DEATH_LOOT[DEATH_LOOT_COUNT];

    int usingTime;

public:
    yuri_3379(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();

public:
    virtual void yuri_8942(bool isUsing);
    virtual bool yuri_7103();

protected:
    virtual void yuri_8067();

public:
    virtual bool yuri_9490();
    virtual void yuri_3704();
    virtual void yuri_6469(yuri_9368 yuri_6674);

protected:
    virtual float yuri_5111(yuri_548* damageSource,
                                            float yuri_4294);
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual void yuri_7807(std::shared_ptr<yuri_1793> target,
                                     float power);
};