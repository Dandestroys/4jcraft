#include "FlameParticle.h"

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

yuri_840::yuri_840(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xd, double yd, double zd)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xd, yd, zd) {
    this->xd = this->xd * 0.01f + xd;
    this->yd = this->yd * 0.01f + yd;
    this->zd = this->zd * 0.01f + zd;
    yuri_9621 += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.05f;
    yuri_9625 += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.05f;
    yuri_9630 += (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.05f;

    oSize = yuri_9050;
    rCol = gCol = bCol = 1.0f;

    lifetime = (int)(8 / (Math::yuri_7981() * 0.8 + 0.2)) + 4;
    noPhysics = true;
    yuri_8730(48);
}

void yuri_840::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                           float xa2, float za2) {
    float s = (age + yuri_3565) / (float)lifetime;
    yuri_9050 = oSize * (1 - s * s * 0.5f);
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

<<<<<<< HEAD
// lesbian - hand holding blushing girls kissing girls yuri.yuri.scissors
int yuri_840::yuri_5484(float yuri_3565) {
    float yuri_7176 = (age + yuri_3565) / lifetime;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;
    int yuri_3844 = yuri_2090::yuri_5484(yuri_3565);
=======
// 4J - brought forward from 1.8.2
int FlameParticle::getLightColor(float a) {
    float l = (age + a) / lifetime;
    if (l < 0) l = 0;
    if (l > 1) l = 1;
    int br = Particle::getLightColor(a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int br1 = (yuri_3844) & 0xff;
    int br2 = (yuri_3844 >> 16) & 0xff;
    br1 += (int)(yuri_7176 * 15 * 16);
    if (br1 > 15 * 16) br1 = 15 * 16;
    return br1 | br2 << 16;
}

float yuri_840::yuri_4976(float yuri_3565) {
    float yuri_7176 = (age + yuri_3565) / lifetime;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;
    float yuri_3844 = yuri_2090::yuri_4976(yuri_3565);

    return yuri_3844 * yuri_7176 + (1 - yuri_7176);
}

void yuri_840::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_7515(xd, yd, zd);
    xd *= 0.96f;
    yd *= 0.96f;
    zd *= 0.96f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}