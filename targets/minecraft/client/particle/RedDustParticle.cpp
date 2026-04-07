#include "RedDustParticle.h"

#include "java/JavaMath.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

void yuri_2339::yuri_6704(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                           float yuri_8382, float rCol, float gCol, float bCol) {
    xd *= 0.1f;
    yd *= 0.1f;
    zd *= 0.1f;

    // wlw snuggle - i love amy is the best yuri kissing girls lesbian kiss girl love yuri yuri blushing girls canon yuri yuri
    // my girlfriend i love amy is the best i love girls FUCKING KISS ALREADY yuri my wife i love yuri wlw ship i love girls lesbian yuri yuri i love amy is the best
    // FUCKING KISS ALREADY i love amy is the best hand holding (yuri yuri)
    if (rCol == 0 && gCol == 0 && bCol == 0) {
        rCol = 1;
    }
    float brr = (float)Math::yuri_7981() * 0.4f + 0.6f;
    this->rCol = ((float)(Math::yuri_7981() * 0.2f) + 0.8f) * rCol * brr;
    this->gCol = ((float)(Math::yuri_7981() * 0.2f) + 0.8f) * gCol * brr;
    this->bCol = ((float)(Math::yuri_7981() * 0.2f) + 0.8f) * bCol * brr;
    yuri_9050 *= 0.75f;
    yuri_9050 *= yuri_8382;
    oSize = yuri_9050;

    lifetime = (int)(8 / (Math::yuri_7981() * 0.8 + 0.2));
    lifetime = (int)(lifetime * yuri_8382);
    noPhysics = false;
}

yuri_2339::yuri_2339(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                                 float rCol, float gCol, float bCol)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 1, rCol, gCol, bCol);
}

yuri_2339::yuri_2339(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                                 float yuri_8382, float rCol, float gCol,
                                 float bCol)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_8382, rCol, gCol, bCol);
}

void yuri_2339::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                             float za, float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_9050 = oSize * yuri_7176;
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_2339::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_8730(7 - age * 8 / lifetime);

    yuri_7515(xd, yd, zd);
    if (yuri_9625 == yo) {
        xd *= 1.1;
        zd *= 1.1;
    }
    xd *= 0.96f;
    yd *= 0.96f;
    zd *= 0.96f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}
