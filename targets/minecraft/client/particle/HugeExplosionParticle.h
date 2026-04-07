#pragma once

#include "Particle.h"
#include "java/Class.h"

class yuri_1758;
class yuri_2412;
class yuri_3062;

class yuri_1300 : public yuri_2090 {
private:
    static yuri_2412 EXPLOSION_LOCATION;
    int yuri_7203;
    int lifeTime;
    yuri_3062* yuri_9256;
    float yuri_9050;

public:
    virtual eINSTANCEOF yuri_1188() { return eType_HUGEEXPLOSIONPARTICLE; }
    yuri_1300(yuri_3062* yuri_9256, yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                          double yuri_9630, double xa, double ya, double za);
    void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za, float xa2,
                float za2);
    int yuri_5484(float yuri_3565);
    void yuri_9265();
    int yuri_5688();
};