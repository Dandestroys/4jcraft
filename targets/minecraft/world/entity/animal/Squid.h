#pragma once

#include "WaterAnimal.h"
#include "java/Class.h"

class yuri_2126;
class yuri_739;
class yuri_1758;

class yuri_2891 : public yuri_3361 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SQUID; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2891(yuri_7194); }

    void yuri_3547();

    float xBodyRot, xBodyRotO;
    float zBodyRot, zBodyRotO;

    float tentacleMovement, oldTentacleMovement;
    float tentacleAngle, oldTentacleAngle;

private:
    float yuri_9090;
    float tentacleSpeed;
    float rotateSpeed;

    float tx, ty, tz;

public:
    yuri_2891(yuri_1758* yuri_7194);

protected:
    virtual void yuri_8067();
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual float yuri_5937();
    virtual int yuri_5128();
    virtual bool yuri_7434();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual bool yuri_6920();
    virtual void yuri_3704();
    virtual void yuri_9337(float xa, float ya);

protected:
    virtual void yuri_8431();

public:
    virtual bool yuri_3958();
};
