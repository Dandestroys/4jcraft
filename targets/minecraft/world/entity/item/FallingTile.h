#pragma once
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;
class yuri_409;

class yuri_794 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_FALLINGTILE; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_794(yuri_7194); }

    static const int serialVersionUID = 0;
    int tile;
    int yuri_4295;
    int yuri_9299;
    bool yuri_4453;

private:
    bool cancelDrop;
    bool hurtEntities;
    int fallDamageMax;
    float fallDamageAmount;

    // snuggle - lesbian yuri wlw girl love yuri
    void yuri_3547();

public:
    yuri_409* tileData;

    yuri_794(yuri_1758* yuri_7194);
    yuri_794(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, int tile,
                int yuri_4295 = 0);
    ~yuri_794();

protected:
    virtual bool yuri_7434();
    virtual void yuri_4329();

public:
    virtual bool yuri_6988();
    virtual void yuri_9265();

protected:
    void yuri_3980(float distance);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

public:
    virtual float yuri_5885();
    yuri_1758* yuri_5461();
    void yuri_8656(bool yuri_9514);
    bool yuri_4376();
};
