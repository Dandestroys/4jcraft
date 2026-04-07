#pragma once

#include "Goal.h"

class yuri_2096;

class yuri_2306 : public yuri_1217 {
private:
    yuri_2096* mob;
    double wantedX, wantedY, wantedZ;
    double speedModifier;

public:
    yuri_2306(yuri_2096* mob, double speedModifier);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
};