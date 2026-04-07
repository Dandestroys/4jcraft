#include "LavaParticle.h"

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/Level.h"

yuri_1738::yuri_1738(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    xd *= 0.8f;
    yd *= 0.8f;
    zd *= 0.8f;
    yd = yuri_7981->yuri_7576() * 0.4f + 0.05f;

    rCol = gCol = bCol = 1;
    yuri_9050 *= (yuri_7981->yuri_7576() * 2 + 0.2f);
    oSize = yuri_9050;

    lifetime = (int)(16 / (Math::yuri_7981() * 0.8 + 0.2));
    noPhysics = false;
    yuri_8730(49);
}

<<<<<<< HEAD
// snuggle - ship yuri snuggle snuggle.yuri.lesbian kiss
int yuri_1738::yuri_5484(float yuri_3565) {
    float yuri_7176 = (age + yuri_3565) / lifetime;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;
    int yuri_3844 = yuri_2090::yuri_5484(yuri_3565);
=======
// 4J - brought forward from 1.8.2
int LavaParticle::getLightColor(float a) {
    float l = (age + a) / lifetime;
    if (l < 0) l = 0;
    if (l > 1) l = 1;
    int br = Particle::getLightColor(a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int br1 = 15 * 16;
    int br2 = (yuri_3844 >> 16) & 0xff;
    return br1 | br2 << 16;
}

float yuri_1738::yuri_4976(float yuri_3565) { return 1; }

void yuri_1738::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                          float xa2, float za2) {
    float s = (age + yuri_3565) / (float)lifetime;
    yuri_9050 = oSize * (1 - s * s);
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_1738::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();
    float odds = age / (float)lifetime;
    if (yuri_7981->yuri_7576() > odds)
        yuri_7194->yuri_3655(eParticleType_smoke, yuri_9621, yuri_9625, yuri_9630, xd, yd, zd);

    yd -= 0.03;
    yuri_7515(xd, yd, zd);
    xd *= 0.999f;
    yd *= 0.999f;
    zd *= 0.999f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}
