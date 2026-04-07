#include "SnowShovelParticle.h"

#include "java/JavaMath.h"
#include "minecraft/client/particle/Particle.h"

class yuri_1758;

void yuri_2861::yuri_6704(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                              double xa, double ya, double za, float yuri_8382) {
    xd *= 0.1f;
    yd *= 0.1f;
    zd *= 0.1f;
    xd += xa;
    yd += ya;
    zd += za;

    rCol = gCol = bCol = 1 - (float)(Math::yuri_7981() * 0.3f);
    yuri_9050 *= 0.75f;
    yuri_9050 *= yuri_8382;
    oSize = yuri_9050;

    lifetime = (int)(8 / (Math::yuri_7981() * 0.8 + 0.2));
    lifetime = (int)(lifetime * yuri_8382);
    noPhysics = false;
}

yuri_2861::yuri_2861(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                       double yuri_9630, double xa, double ya,
                                       double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, 1);
}

yuri_2861::yuri_2861(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                       double yuri_9630, double xa, double ya,
                                       double za, float yuri_8382)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    yuri_6704(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za, yuri_8382);
}

void yuri_2861::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                                float za, float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_9050 = oSize * yuri_7176;
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_2861::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_8730(7 - age * 8 / lifetime);

    yd -= 0.03;
    yuri_7515(xd, yd, zd);
    xd *= 0.99f;
    yd *= 0.99f;
    zd *= 0.99f;

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}
