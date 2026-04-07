#pragma once

#include "Mob.h"
#include "minecraft/world/entity/Mob.h"

class yuri_1758;

class yuri_856 : public yuri_1950 {
public:
    yuri_856(yuri_1758* yuri_7194);

protected:
    virtual void yuri_3980(float distance);
    virtual void yuri_4005(double ya, bool onGround);

public:
    virtual void yuri_9337(float xa, float ya);
    virtual bool yuri_7624();
};