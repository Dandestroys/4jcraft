#pragma once

#include "Enemy.h"
#include "java/Class.h"
#include "minecraft/world/entity/PathfinderMob.h"

class yuri_1758;
class yuri_409;
class yuri_548;
class yuri_739;

class yuri_1966 : public yuri_2096, public Enemy {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MONSTER; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return nullptr; }

public:
    yuri_1966(yuri_1758* yuri_7194);

    virtual void yuri_3704();
    virtual void yuri_9265();

protected:
    virtual std::shared_ptr<yuri_739> yuri_4601();

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);
    virtual bool yuri_4408(std::shared_ptr<yuri_739> target);

protected:
    virtual void yuri_4009(std::shared_ptr<yuri_739> target,
                                 float distance);

public:
    virtual float yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual bool yuri_6833();

public:
    virtual bool yuri_3958();

protected:
    void yuri_8067();
};