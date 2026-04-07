#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Golem.h"
#include "java/Class.h"

class yuri_3327;
class yuri_1758;
class yuri_739;

class yuri_3334 : public yuri_1220 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_VILLAGERGOLEM; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_3334(yuri_7194); }

protected:
    static const int DATA_FLAGS_ID = 16;

private:
    int villageUpdateInterval;
    std::weak_ptr<yuri_3327> village;
    int attackAnimationTick;
    int offerFlowerTick;

public:
    yuri_3334(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual bool yuri_9490();

protected:
    virtual void yuri_8430();
    virtual void yuri_8067();
    virtual int yuri_4319(int currentSupply);
    virtual void yuri_4413(std::shared_ptr<yuri_739> e);

public:
    virtual void yuri_3704();
    virtual bool yuri_3905(eINSTANCEOF yuri_9188);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual bool yuri_4408(std::shared_ptr<yuri_739> target);
    virtual void yuri_6469(yuri_9368 yuri_6674);
    virtual std::shared_ptr<yuri_3327> yuri_6114();
    virtual int yuri_4909();
    virtual void yuri_7604(bool offer);

protected:
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual void yuri_7835(int xt, int yt, int zt, int t);
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual int yuri_5614();
    virtual bool yuri_6989();
    virtual void yuri_8770(bool yuri_9514);
    virtual void yuri_4360(yuri_548* yuri_9075);
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);
};