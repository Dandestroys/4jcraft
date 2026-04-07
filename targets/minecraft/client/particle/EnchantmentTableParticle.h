#pragma once

#include "Particle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_681 : public yuri_2090 {
private:
    float oSize;
    double xStart, yStart, zStart;

public:
    virtual eINSTANCEOF yuri_1188() { return eTYPE_ENCHANTMENTTABLEPARTICLE; }

    yuri_681(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                            double xd, double yd, double zd);

    virtual int yuri_5484(float yuri_3565);
    virtual float yuri_4976(float yuri_3565);
    virtual void yuri_9265();
};