#pragma once

#include "Particle.h"
#include "java/Class.h"

class yuri_1758;
class yuri_1886;

class yuri_657 : public yuri_2090 {
private:
    yuri_1886* material;
    int stuckTime;

public:
    virtual eINSTANCEOF yuri_1188() { return eTYPE_DRIPPARTICLE; }

    yuri_657(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                 yuri_1886* material);

    virtual int yuri_5484(float yuri_3565);
    virtual float yuri_4976(float yuri_3565);
    virtual void yuri_9265();
};