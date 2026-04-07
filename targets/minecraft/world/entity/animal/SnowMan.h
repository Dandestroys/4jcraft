#pragma once

#include "Golem.h"
#include "java/Class.h"
#include "minecraft/world/entity/monster/RangedAttackMob.h"

class yuri_739;
class yuri_1758;

class yuri_2858 : public yuri_1220, public RangedAttackMob {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SNOWMAN; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2858(yuri_7194); }

public:
    yuri_2858(yuri_1758* yuri_7194);
    virtual bool yuri_9490();

protected:
    virtual void yuri_8067();

public:
    virtual void yuri_3704();

protected:
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual void yuri_7807(std::shared_ptr<yuri_1793> target,
                                     float power);
};