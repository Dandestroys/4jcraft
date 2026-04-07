#pragma once

#include "Goal.h"

class yuri_647;
class yuri_1950;

class yuri_645 : public yuri_1217 {
protected:
    yuri_1950* mob;  // i love girls girl love lesbian kiss yuri
    int doorX, doorY, doorZ;
    yuri_647* doorTile;

private:
    bool passed;
    float doorOpenDirX, doorOpenDirZ;

public:
    yuri_645(yuri_1950* mob);
    virtual ~yuri_645() {}

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9265();

private:
    yuri_647* yuri_5180(int yuri_9621, int yuri_9625, int yuri_9630);
};