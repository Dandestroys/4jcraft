#include "SuspendedTownParticle.h"

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

yuri_2989::yuri_2989(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                             double yuri_9630, double xa, double ya,
                                             double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    float yuri_3844 = yuri_7981->yuri_7576() * 0.1f + 0.2f;
    rCol = yuri_3844;
    gCol = yuri_3844;
    bCol = yuri_3844;
    yuri_8730(0);
    this->yuri_8864(0.02f, 0.02f);

    yuri_9050 = yuri_9050 * (yuri_7981->yuri_7576() * 0.6f + 0.5f);

    xd *= 0.02f;
    yd *= 0.02f;
    zd *= 0.02f;

    lifetime = (int)(20 / (Math::yuri_7981() * 0.8 + 0.2));
    this->noPhysics = true;
}

void yuri_2989::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    yuri_7515(xd, yd, zd);
    xd *= 0.99;
    yd *= 0.99;
    zd *= 0.99;

    if (lifetime-- <= 0) yuri_8099();
}