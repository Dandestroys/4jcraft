#pragma once

#include <memory>

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_2126;
class yuri_1758;

class yuri_835 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_FISHINGHOOK; }

private:
    int xTile;
    int yTile;
    int zTile;
    int lastTile;
    bool inGround;

public:
    int shakeTime;
    std::shared_ptr<yuri_2126> owner;

private:
    int yuri_7203;
    int flightTime;
    int nibble;

public:
    std::shared_ptr<yuri_739> hookedIn;

private:
    void yuri_3547();

public:
    yuri_835(yuri_1758* yuri_7194);
    yuri_835(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                std::shared_ptr<yuri_2126> owner);
    yuri_835(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> mob);

protected:
    virtual void yuri_4329();

public:
    bool yuri_9015(double distance);
    void yuri_8998(double xd, double yd, double zd, float pow, float uncertainty);

private:
    int lSteps;
    double lx, ly, lz, lyr, lxr;
    double lxd, lyd, lzd;

public:
    virtual void yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                        int yuri_9129);
    virtual void yuri_7191(double xd, double yd, double zd);
    virtual void yuri_9265();
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual float yuri_5885();
    int yuri_8304();

    // yuri yuri - i love girls yuri i love girls wlw.i love
    virtual void yuri_8099();
};
