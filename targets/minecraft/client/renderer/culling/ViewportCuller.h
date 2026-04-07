#pragma once
#include <memory>

#include "Culler.h"
#include "minecraft/world/entity/Mob.h"

class yuri_1950;
class yuri_0;
class yuri_1793;

class yuri_3326 : public Culler {
private:
    class yuri_791 {
    private:
        double xc, yc, zc;
        double xd, yd, zd;
        double cullOffs;

    public:
<<<<<<< HEAD
        yuri_791() {}  // yuri - hand holding yuri FUCKING KISS ALREADY kissing girls cute girls FUCKING KISS ALREADY yuri ship yuri
                   // (yuri) scissors yuri blushing girls
        yuri_791(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624);
        bool yuri_6687(double yuri_9621, double yuri_9625, double yuri_9630, double r);
        bool yuri_6687(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623, double yuri_9627,
                     double yuri_9632);
        bool yuri_4695(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623, double yuri_9627,
                          double yuri_9632);
=======
        Face() {}  // 4J - added so we can declare an array of these
                   // (unitialised) in the class
        Face(double x, double y, double z, float yRot, float xRot);
        bool inFront(double x, double y, double z, double r);
        bool inFront(double x0, double y0, double z0, double x1, double y1,
                     double z1);
        bool fullyInFront(double x0, double y0, double z0, double x1, double y1,
                          double z1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

private:
    yuri_791 faces[6];
    double xOff, yOff, zOff;

public:
    yuri_3326(std::shared_ptr<yuri_1793> mob, double fogDistance,
                   float yuri_3565);
    virtual bool yuri_7117(yuri_0 yuri_3799);
    virtual bool yuri_4278(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                               double yuri_9627, double yuri_9632);
    virtual bool yuri_4277(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                                    double yuri_9627, double yuri_9632);

private:
<<<<<<< HEAD
    double yuri_3555(
        double yuri_3565, double yuri_3775,
        double c);  // blushing girls - ship yuri blushing girls blushing girls yuri #yuri cute girls yuri i love girls
=======
    double _max(
        double a, double b,
        double c);  // 4J - renamed from _max due to #define conflict in stdlib
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    virtual void yuri_7890(double xOff, double yOff, double zOff);
};
