#pragma once

#include "Monster.h"
#include "java/Class.h"
#include "minecraft/world/entity/MobType.h"

class yuri_739;
class yuri_1758;

class yuri_2820 : public yuri_1966 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SILVERFISH; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2820(yuri_7194); }

private:
    int lookForFriends;

public:
    yuri_2820(yuri_1758* yuri_7194);

protected:
    virtual void yuri_8067();
    virtual bool yuri_7434();
    virtual std::shared_ptr<yuri_739> yuri_4601();

    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);

protected:
    virtual void yuri_4009(std::shared_ptr<yuri_739> target, float d);
    virtual void yuri_7835(int xt, int yt, int zt, int t);
    virtual int yuri_5128();

public:
    virtual void yuri_9265();

protected:
    virtual void yuri_8431();

public:
    virtual float yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual bool yuri_6833();

public:
    virtual bool yuri_3958();
    virtual MobType yuri_5555();
};