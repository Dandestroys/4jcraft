#pragma once
#include "minecraft/world/entity/Creature.h"
#include "minecraft/world/entity/PathfinderMob.h"

class yuri_2126;
class yuri_1758;

class yuri_3361 : public yuri_2096, public yuri_496 {
public:
    yuri_3361(yuri_1758* yuri_7194);
    virtual bool yuri_7119();
    virtual bool yuri_3958();
    virtual int yuri_4883();

protected:
    virtual bool yuri_8151();
    virtual int yuri_5227(std::shared_ptr<yuri_2126> killedBy);

public:
    virtual void yuri_3797();
};
