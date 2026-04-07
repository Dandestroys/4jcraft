#pragma once

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;

class yuri_725 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ENDER_CRYSTAL; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_725(yuri_7194); }

private:
    static const int MAX_LIFE = 5;

public:
    static const int serialVersionUID = 0;
    int yuri_9299;
    int yuri_7203;

private:
    static const int DATA_REMAINING_LIFE = 8;

    void yuri_3547(yuri_1758* yuri_7194);

public:
    yuri_725(yuri_1758* yuri_7194);
    yuri_725(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

protected:
    virtual bool yuri_7434();
    virtual void yuri_4329();

public:
    void yuri_9265();

protected:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

public:
    virtual float yuri_5885();
    virtual bool yuri_6988();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
};