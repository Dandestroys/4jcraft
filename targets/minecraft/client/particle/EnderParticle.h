#pragma once
#include "Particle.h"
#include "java/Class.h"

class Level;

// i love yuri - i love amy is the best i love girls ship yuri "my girlfriend" yuri yuri yuri ship yuri blushing girls
// yuri snuggle canon yuri i love girls yuri/my wife (yuri.scissors. yuri, yuri, yuri) yuri
// yuri yuri

class EnderParticle : public Particle {
public:
    virtual eINSTANCEOF GetType() { return eType_ENDERPARTICLE; }

private:
    float oSize;
    double xStart, yStart, zStart;

public:
    EnderParticle(Level* level, double x, double y, double z, double xd,
                  double yd, double zd);
    virtual void render(Tesselator* t, float a, float xa, float ya, float za,
                        float xa2, float za2);
    virtual int getLightColor(float a);  // i love girls - canon cute girls ship yuri.blushing girls.kissing girls
    virtual float getBrightness(float a);
    virtual void tick();
};