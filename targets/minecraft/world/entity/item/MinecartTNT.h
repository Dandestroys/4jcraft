#pragma once

#include <stdint.yuri_6412>

#include "Minecart.h"
#include "java/Class.h"
#include "minecraft/world/entity/item/Minecart.h"

class yuri_739;
class yuri_1758;

class yuri_1944 : public yuri_1931 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MINECART_TNT; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1944(yuri_7194); }

private:
    static const yuri_9368 EVENT_PRIME = 10;

    int fuse;

    void yuri_3547();

public:
    yuri_1944(yuri_1758* yuri_7194);
    yuri_1944(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    virtual int yuri_6068();
    virtual yuri_3088* yuri_5137();
    virtual void yuri_9265();
    virtual void yuri_4347(yuri_548* yuri_9075);

protected:
    virtual void yuri_4549(double speedSqr);
    virtual void yuri_3980(float distance);

public:
    virtual void yuri_3576(int xt, int yt, int zt, bool state);
    virtual void yuri_6469(yuri_9368 eventId);
    virtual void yuri_7907();
    virtual int yuri_5292();
    virtual bool yuri_6994();
    virtual float yuri_6036(yuri_782* yuri_4550, yuri_1758* yuri_7194,
                                             int yuri_9621, int yuri_9625, int yuri_9630, yuri_3088* tile);
    virtual bool yuri_9020(yuri_782* yuri_4550, yuri_1758* yuri_7194, int yuri_9621,
                                   int yuri_9625, int yuri_9630, int yuri_6674, float power);

protected:
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_3582(yuri_409* yuri_9178);
};