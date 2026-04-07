#pragma once
#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_840 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_FLAMEPARTICLE; }

private:
    float oSize;

public:
    yuri_840(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xd,
                  double yd, double zd);
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                        float xa2, float za2);
<<<<<<< HEAD
    virtual int yuri_5484(float yuri_3565);  // i love girls - yuri lesbian cute girls yuri.i love amy is the best.my girlfriend
    virtual float yuri_4976(float yuri_3565);
    virtual void yuri_9265();
=======
    virtual int getLightColor(float a);  // 4J - brought forward from 1.8.2
    virtual float getBrightness(float a);
    virtual void tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};