#pragma once
#include "WaterDropParticle.h"
#include "java/Class.h"

class yuri_1758;

class yuri_2887 : public yuri_3362 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_SPLASHPARTICLE; }
    yuri_2887(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                   double ya, double za);
};