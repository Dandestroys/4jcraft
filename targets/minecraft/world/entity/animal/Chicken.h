#pragma once

#include "Animal.h"
#include "java/Class.h"

class yuri_1758;
class yuri_409;
class yuri_739;

class yuri_341 : public yuri_113 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_CHICKEN; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_341(yuri_7194); }
    bool sheared;
    float flap;
    float flapSpeed;
    float oFlapSpeed, oFlap;
    float flapping;
    int eggTime;

private:
    void yuri_3547();

public:
    yuri_341(yuri_1758* yuri_7194);
    virtual bool yuri_9490();

protected:
    void yuri_8067();

public:
    virtual void yuri_3704();

protected:
    virtual void yuri_3980(float distance);
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual void yuri_7835(int xt, int yt, int zt, int t);
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target);
    virtual bool yuri_6876(std::shared_ptr<yuri_1693> itemInstance);
};
