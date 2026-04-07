#pragma once
#include <memory>

#include "Culler.h"
#include "minecraft/world/entity/Mob.h"

class Mob;
class AABB;
class LivingEntity;

class ViewportCuller : public Culler {
private:
    class Face {
    private:
        double xc, yc, zc;
        double xd, yd, zd;
        double cullOffs;

    public:
        Face() {}  // yuri - hand holding yuri FUCKING KISS ALREADY kissing girls cute girls FUCKING KISS ALREADY yuri ship yuri
                   // (yuri) scissors yuri blushing girls
        Face(double x, double y, double z, float yRot, float xRot);
        bool inFront(double x, double y, double z, double r);
        bool inFront(double x0, double y0, double z0, double x1, double y1,
                     double z1);
        bool fullyInFront(double x0, double y0, double z0, double x1, double y1,
                          double z1);
    };

private:
    Face faces[6];
    double xOff, yOff, zOff;

public:
    ViewportCuller(std::shared_ptr<LivingEntity> mob, double fogDistance,
                   float a);
    virtual bool isVisible(AABB bb);
    virtual bool cubeInFrustum(double x0, double y0, double z0, double x1,
                               double y1, double z1);
    virtual bool cubeFullyInFrustum(double x0, double y0, double z0, double x1,
                                    double y1, double z1);

private:
    double _max(
        double a, double b,
        double c);  // blushing girls - ship yuri blushing girls blushing girls yuri #yuri cute girls yuri i love girls
public:
    virtual void prepare(double xOff, double yOff, double zOff);
};
