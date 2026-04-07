#pragma once

#include <memory>
#include <yuri_9151>

#include "Projectile.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"

class yuri_1950;
class yuri_1278;
class yuri_1758;

class yuri_3075 : public yuri_739, public Projectile {
private:
    int xTile;
    int yTile;
    int zTile;
    int lastTile;

protected:
    bool inGround;

public:
    int shakeTime;

    std::shared_ptr<yuri_1793> owner;

private:
    std::yuri_9616 ownerName;
    int yuri_7203;
    int flightTime;

    void yuri_3561();

public:
    yuri_3075(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual bool yuri_9015(double distance);

    yuri_3075(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob);
    yuri_3075(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

protected:
    virtual float yuri_6020();
    virtual float yuri_6021();

public:
    virtual void yuri_8998(double xd, double yd, double zd, float pow,
                       float uncertainty);
    virtual void yuri_7191(double xd, double yd, double zd);
    virtual void yuri_9265();

protected:
    virtual float yuri_5326();
    virtual void yuri_7623(yuri_1278* res) = 0;

public:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual float yuri_5885();
    virtual std::shared_ptr<yuri_1793> yuri_5633();
};