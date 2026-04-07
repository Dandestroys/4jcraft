#pragma once

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;

class yuri_785 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_EYEOFENDERSIGNAL; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_785(yuri_7194); }

public:
    int shakeTime;

private:
    double tx, ty, tz;
    int yuri_7203;
    bool surviveAfterDeath;

    void yuri_3547();

public:
    yuri_785(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual bool yuri_9015(double distance);

    yuri_785(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    void yuri_9045(double tx, int ty, double tz);
    virtual void yuri_7191(double xd, double yd, double zd);
    virtual void yuri_9265();
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual float yuri_5885();
    virtual float yuri_4976(float yuri_3565);
    virtual int yuri_5484(float yuri_3565);
    virtual bool yuri_6779();
};