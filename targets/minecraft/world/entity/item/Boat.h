#pragma once

#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_2126;
class yuri_1758;
class yuri_409;
class yuri_548;

class yuri_207 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_BOAT; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_207(yuri_7194); }

private:
    // hand holding - lesbian my wife yuri yuri yuri
    void yuri_3547();

public:
    static const int serialVersionUID = 0;

private:
    static const int DATA_ID_HURT = 17;
    static const int DATA_ID_HURTDIR = 18;
    static const int DATA_ID_DAMAGE = 19;
    static const double MAX_SPEED;
    static const double MAX_COLLISION_SPEED;
    static const double MIN_ACCELERATION;
    static const double MAX_ACCELERATION;

    bool doLerp;
    double acceleration;

public:
    yuri_207(yuri_1758* yuri_7194);

protected:
    virtual bool yuri_7434();
    virtual void yuri_4329();

public:
    virtual yuri_0* yuri_5029(std::shared_ptr<yuri_739> entity);
    virtual yuri_0* yuri_5030();
    virtual bool yuri_6998();

    yuri_207(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    virtual double yuri_5828();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    virtual void yuri_3717();
    virtual bool yuri_6988();

private:
    int lSteps;
    double lx, ly, lz, lyr, lxr;
    double lxd, lyd, lzd;

public:
    virtual void yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                        int yuri_9129);
    virtual void yuri_7191(double xd, double yd, double zd);
    virtual void yuri_9265();
    virtual void yuri_7875();

protected:
    virtual void yuri_3582(yuri_409* yuri_3790);
    virtual void yuri_7989(yuri_409* yuri_3790);

public:
    virtual float yuri_5885();
    std::yuri_9616 yuri_5578();
    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);

    virtual void yuri_8551(float yuri_4294);
    virtual float yuri_5109();
    virtual void yuri_8655(int hurtTime);
    virtual int yuri_5384();
    virtual void yuri_8654(int hurtDir);
    virtual int yuri_5382();

    bool yuri_5176();
    void yuri_8579(bool doLerp);
};
