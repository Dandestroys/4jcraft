#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1693;
class yuri_1758;

class yuri_831 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_FIREWORKS_ROCKET; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) {
        return new yuri_831(yuri_7194);
    }

private:
    static const int DATA_ID_FIREWORKS_ITEM = 8;

    int yuri_7203;
    int lifetime;

    // constructor needed for level loader
public:
    yuri_831(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual bool yuri_9015(double distance);

    yuri_831(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                          std::shared_ptr<yuri_1693> sourceItem);

    virtual void yuri_7191(double xd, double yd, double zd);
    virtual void yuri_9265();
    virtual void yuri_6469(yuri_9368 eventId);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual float yuri_5885();
    virtual float yuri_4976(float yuri_3565);
    virtual int yuri_5484(float yuri_3565);
    virtual bool yuri_6779();
};