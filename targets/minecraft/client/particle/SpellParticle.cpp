#include "SpellParticle.h"

#include "java/JavaMath.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

yuri_2881::yuri_2881(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    yd *= 0.2f;
    if (xa == 0 && za == 0) {
        xd *= 0.1f;
        zd *= 0.1f;
    }

    yuri_9050 *= 0.75f;

    lifetime = (int)(8 / (Math::yuri_7981() * 0.8 + 0.2));
    noPhysics = false;

    baseTex = 8 * 16;
}

void yuri_2881::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                           float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_2881::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_8730(baseTex + (7 - age * 8 / lifetime));

    yd += 0.004;
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

void yuri_2881::yuri_8479(int baseTex) { this->baseTex = baseTex; }