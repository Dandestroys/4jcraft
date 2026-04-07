#pragma once

#include <memory>

#include "Fireball.h"
#include "java/Class.h"
#include "minecraft/core/particles/ParticleTypes.h"

class yuri_1278;
class yuri_739;
class yuri_1758;
class yuri_1793;

class yuri_654 : public yuri_822 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_DRAGON_FIREBALL; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_654(yuri_7194); }

public:
    static const double SPLASH_RANGE;

private:
    static const double SPLASH_RANGE_SQ;

public:
    yuri_654(yuri_1758* yuri_7194);
    yuri_654(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob, double xa,
                   double ya, double za);
    yuri_654(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                   double ya, double za);

protected:
    virtual void yuri_7623(yuri_1278* res);

public:
    virtual bool yuri_6988();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);

protected:
<<<<<<< HEAD
    // wlw yuri yuri
    virtual ePARTICLE_TYPE yuri_6059();
=======
    // 4J Added TU9
    virtual ePARTICLE_TYPE getTrailParticleType();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual bool yuri_9000();
};