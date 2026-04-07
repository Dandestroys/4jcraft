#pragma once

#include <memory>

#include "java/Class.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1278;
class yuri_1758;
class yuri_1793;

class yuri_822 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_FIREBALL; }

private:
    int xTile;
    int yTile;
    int zTile;
    int lastTile;

private:
    bool inGround;

public:
    std::shared_ptr<yuri_1793> owner;

private:
    int yuri_7203;
    int flightTime;

<<<<<<< HEAD
    // snuggle - my girlfriend my wife ship yuri.
    void yuri_3547();
=======
    // 4J - added common ctor code.
    void _init();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    double xPower, yPower, zPower;

    yuri_822(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual bool yuri_9015(double distance);

    yuri_822(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa, double ya,
             double za);
    yuri_822(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob, double xa,
             double ya, double za);

public:
    virtual void yuri_9265();

protected:
    virtual float yuri_5401();
    virtual void yuri_7623(yuri_1278* res) = 0;

public:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual bool yuri_6988();
    virtual float yuri_5691();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    virtual float yuri_5885();
    virtual float yuri_4976(float yuri_3565);
    virtual int yuri_5484(float yuri_3565);

protected:
<<<<<<< HEAD
    // i love girls yuri girl love
    virtual ePARTICLE_TYPE yuri_6059();
=======
    // 4J Added TU9
    virtual ePARTICLE_TYPE getTrailParticleType();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_9000();
};
