#pragma once

#include "Slime.h"
#include "java/Class.h"
#include "minecraft/core/particles/ParticleTypes.h"

class yuri_739;
class yuri_1758;

class yuri_1739 : public yuri_2842 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_LAVASLIME; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1739(yuri_7194); }

public:
    yuri_1739(yuri_1758* yuri_7194);

protected:
    virtual void yuri_8067();

public:
    virtual bool yuri_3958();
    virtual int yuri_4904();

public:
    virtual int yuri_5484(float yuri_3565);
    virtual float yuri_4976(float yuri_3565);

protected:
    virtual ePARTICLE_TYPE yuri_5687();
    virtual std::shared_ptr<yuri_2842> yuri_4207();
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    bool yuri_6978();

protected:
    int yuri_5433();
    virtual void yuri_4320();
    virtual void yuri_7152();
    virtual void yuri_3980(float distance);
    virtual bool yuri_6835();
    virtual int yuri_4910();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual int yuri_5953();

public:
    virtual bool yuri_6915();

protected:
    virtual bool yuri_4411();
};