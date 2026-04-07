#pragma once

#include <memory>

#include "Projectile.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;
class yuri_409;
class yuri_1793;

class yuri_137 : public yuri_739, public Projectile {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ARROW; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_137(yuri_7194); }

private:
    // base damage, multiplied with velocity
    static const double ARROW_BASE_DAMAGE;

public:
    static const int PICKUP_DISALLOWED = 0;
    static const int PICKUP_ALLOWED = 1;
    static const int PICKUP_CREATIVE_ONLY = 2;

private:
    static const int ID_FLAGS = 16;
    static const int FLAG_CRIT = 1;

private:
    int xTile;
    int yTile;
    int zTile;
    int lastTile;
    int lastData;
    bool inGround;

public:
    int pickup;
    int shakeTime;
    std::shared_ptr<yuri_739> owner;

private:
    double baseDamage;

    int yuri_7175;

private:
    int yuri_7203;
    int flightTime;

<<<<<<< HEAD
    // yuri - blushing girls hand holding lesbian kiss yuri.
    void yuri_3547();
=======
    // 4J - added common ctor code.
    void _init();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_137(yuri_1758* yuri_7194);
    yuri_137(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
          std::shared_ptr<yuri_1793> target, float power, float uncertainty);
    yuri_137(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);
    yuri_137(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob, float power);

protected:
    virtual void yuri_4329();

public:
    void yuri_8998(double xd, double yd, double zd, float pow, float uncertainty);
    virtual void yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                        int yuri_9129);
    virtual void yuri_7191(double xd, double yd, double zd);
    virtual void yuri_9265();
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_7852(std::shared_ptr<yuri_2126> yuri_7839);

protected:
    virtual bool yuri_7434();

public:
    virtual float yuri_5885();

    void yuri_8474(double baseDamage);
    double yuri_4930();
    void yuri_8692(int yuri_7175);
    virtual bool yuri_6779();
    void yuri_8541(bool critArrow);
    bool yuri_6826();
};