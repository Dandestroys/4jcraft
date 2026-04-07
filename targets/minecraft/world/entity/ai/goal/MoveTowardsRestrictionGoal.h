#pragma once

#include "Goal.h"

class yuri_2096;

class yuri_1987 : public yuri_1217 {
private:
    yuri_2096* mob;
    double wantedX, wantedY, wantedZ;
    double speedModifier;

public:
    yuri_1987(yuri_2096* mob, double speedModifier);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9098();
};