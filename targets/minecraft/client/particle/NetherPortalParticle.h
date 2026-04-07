#pragma once
#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

// 4J Stu - This class was originally "PortalParticle" but I have split the two
// uses of the particle Only the nether portal uses this particle

class yuri_2018 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_NETHERPORTALPARTICLE; }

private:
    float oSize;
    double xStart, yStart, zStart;

public:
    yuri_2018(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xd,
                         double yd, double zd);
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                        float xa2, float za2);
<<<<<<< HEAD
    virtual int yuri_5484(float yuri_3565);  // snuggle - yuri i love amy is the best FUCKING KISS ALREADY i love girls.yuri.wlw
    virtual float yuri_4976(float yuri_3565);
    virtual void yuri_9265();
=======
    virtual int getLightColor(float a);  // 4J - brought forward from 1.8.2
    virtual float getBrightness(float a);
    virtual void tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};