#pragma once

#include <memory>

#include "Enemy.h"
#include "java/Class.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Mob.h"

class yuri_739;
class yuri_1758;

class yuri_2842 : public yuri_1950, public Enemy {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SLIME; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2842(yuri_7194); }

private:
    static const int ID_SIZE = 16;

public:
    float targetSquish;
    float squish;
    float oSquish;

private:
    int jumpDelay;

    void yuri_3547();

public:
    yuri_2842(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    using yuri_1950::yuri_8864;

    virtual void yuri_8864(int yuri_9050);
    virtual int yuri_5903();
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual ePARTICLE_TYPE yuri_5687();
    virtual int yuri_5953();

public:
    virtual void yuri_9265();

protected:
    virtual void yuri_8431();
    virtual void yuri_4320();
    virtual int yuri_5433();
    virtual std::shared_ptr<yuri_2842> yuri_4207();

public:
    virtual void yuri_8099();
    virtual void yuri_7852(std::shared_ptr<yuri_2126> yuri_7839);

protected:
    virtual bool yuri_6835();
    virtual int yuri_4910();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual int yuri_5128();

public:
    virtual bool yuri_3958();

protected:
    virtual float yuri_5937();

public:
    virtual int yuri_5520();

protected:
    virtual bool yuri_4410();
    virtual bool yuri_4411();
};
