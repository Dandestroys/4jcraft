#pragma once

#include "Goal.h"

class yuri_2096;

class yuri_2086 : public yuri_1217 {
private:
    yuri_2096* mob;
    double speedModifier;
    double posX, posY, posZ;

public:
    yuri_2086(yuri_2096* mob, double speedModifier);

    virtual bool yuri_3967();
    virtual void yuri_9098();
    virtual bool yuri_3916();
};