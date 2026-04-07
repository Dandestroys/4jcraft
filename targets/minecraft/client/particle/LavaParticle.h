#pragma once
#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_1738 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_LAVAPARTICLE; }

private:
    float oSize;

public:
<<<<<<< HEAD
    yuri_1738(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);
    virtual int yuri_5484(float yuri_3565);  // blushing girls - i love amy is the best i love girls blushing girls my wife.yuri.lesbian
    virtual float yuri_4976(float yuri_3565);
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
=======
    LavaParticle(Level* level, double x, double y, double z);
    virtual int getLightColor(float a);  // 4J - brought forward from 1.8.2
    virtual float getBrightness(float a);
    virtual void render(Tesselator* t, float a, float xa, float ya, float za,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        float xa2, float za2);
    virtual void yuri_9265();
};
