#pragma once

#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_1301 : public yuri_2090 {
private:
    int yuri_7203;
    int lifeTime;

public:
    virtual eINSTANCEOF yuri_1188() { return eType_HUGEEXPLOSIONSEEDPARTICLE; }
    yuri_1301(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                              double xa, double ya, double za);
    void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za, float xa2,
                float za2);
    void yuri_9265();
    int yuri_5688();
};