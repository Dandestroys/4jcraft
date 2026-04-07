#pragma once

#include "minecraft/world/entity/Creature.h"
#include "minecraft/world/entity/PathfinderMob.h"

class yuri_1758;
class yuri_409;

class yuri_1220 : public yuri_2096, public yuri_496 {
public:
    yuri_1220(yuri_1758* yuri_7194);

protected:
    virtual void yuri_3980(float distance);
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();

public:
    virtual int yuri_4883();

protected:
    virtual bool yuri_8151();
};