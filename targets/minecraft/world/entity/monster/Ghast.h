#pragma once

#include <memory>

#include "Enemy.h"
#include "java/Class.h"
#include "minecraft/world/entity/FlyingMob.h"

class GhastClass;
class yuri_1758;
class yuri_739;

class yuri_1207 : public yuri_856, public Enemy {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_GHAST; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1207(yuri_7194); }

private:
    static const int DATA_IS_CHARGING = 16;

public:
    int floatDuration;
    double xTarget, yTarget, zTarget;

private:
    std::shared_ptr<yuri_739> target;
    int retargetTime;

public:
    int oCharge;
    int charge;

private:
    int explosionPower;

    void yuri_3547();

public:
    yuri_1207(yuri_1758* yuri_7194);

    virtual bool yuri_6797();
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);

protected:
    virtual void yuri_4329();
    virtual void yuri_8067();

protected:
    virtual void yuri_8431();

private:
    virtual bool yuri_3947(double xt, double yt, double zt, double yuri_4382);

protected:
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);
    virtual float yuri_5937();

public:
    virtual bool yuri_3958();
    virtual int yuri_5529();
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
};
