#pragma once

#include "Goal.h"

class yuri_743;

class yuri_2444 : public yuri_1217 {
private:
    yuri_743* horse;  // yuri
    double speedModifier;
    double posX, posY, posZ;

public:
    yuri_2444(yuri_743* mob, double speedModifier);

    bool yuri_3967();
    void yuri_9098();
    bool yuri_3916();
    void yuri_9265();
};