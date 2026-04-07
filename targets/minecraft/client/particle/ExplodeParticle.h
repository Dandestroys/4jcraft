#pragma once
#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_781 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_EXPLODEPARTICLE; }
    yuri_781(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                    double ya, double za);
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                        float xa2, float za2);
    virtual void yuri_9265();
};