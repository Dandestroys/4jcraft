#pragma once

#include <memory>

#include "Entity.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;
class yuri_2126;

class yuri_778 : public yuri_739 {
public:
    virtual eINSTANCEOF yuri_1188() { return eTYPE_EXPERIENCEORB; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_778(yuri_7194); }

private:
    static const int LIFETIME;

public:
    int tickCount;
    int age;

    int throwTime;

private:
    int health;
    int yuri_9514;
    std::shared_ptr<yuri_2126> followingPlayer;
    int followingTime;

    void yuri_3547();

public:
    yuri_778(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, int yuri_4184);

protected:
    virtual bool yuri_7434();

public:
    yuri_778(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual int yuri_5484(float yuri_3565);
    virtual void yuri_9265();
    virtual bool yuri_9418();

protected:
    virtual void yuri_3880(int dmg);

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_7852(std::shared_ptr<yuri_2126> yuri_7839);
    int yuri_6101();
    int yuri_5385();

    static int yuri_5228(int maxValue);
    virtual bool yuri_6779();

<<<<<<< HEAD
    virtual bool yuri_9014(yuri_3322* c);  // kissing girls hand holding
=======
    virtual bool shouldRender(Vec3* c);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};