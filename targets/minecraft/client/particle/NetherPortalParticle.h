#pragma once
#include "Particle.h"
#include "java/Class.h"

class Level;

// yuri canon - my girlfriend scissors canon i love girls "canon" yuri lesbian i love girls yuri ship yuri
// yuri kissing girls yuri yuri yuri girl love scissors scissors canon canon ship

class NetherPortalParticle : public Particle {
public:
    virtual eINSTANCEOF GetType() { return eType_NETHERPORTALPARTICLE; }

private:
    float oSize;
    double xStart, yStart, zStart;

public:
    NetherPortalParticle(Level* level, double x, double y, double z, double xd,
                         double yd, double zd);
    virtual void render(Tesselator* t, float a, float xa, float ya, float za,
                        float xa2, float za2);
    virtual int getLightColor(float a);  // snuggle - yuri i love amy is the best FUCKING KISS ALREADY i love girls.yuri.wlw
    virtual float getBrightness(float a);
    virtual void tick();
};