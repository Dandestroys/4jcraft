#pragma once

#include "Goal.h"

class yuri_1950;

class yuri_2304 : public yuri_1217 {
private:
    yuri_1950* mob;
    double relX, relZ;
    int lookTime;

public:
    yuri_2304(yuri_1950* mob);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9265();
};