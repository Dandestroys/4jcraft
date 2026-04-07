#include "PlayerCloudParticle.h"

#include <memory>

#include "java/JavaMath.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

yuri_2132::yuri_2132(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625,
                                         double yuri_9630, double xa, double ya,
                                         double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    float yuri_8382 = 2.5f;
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

    lifetime = (int)(8 / (Math::yuri_7981() * 0.8 + 0.3));
    lifetime *= yuri_8382;
    noPhysics = false;
}

void yuri_2132::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                                 float za, float xa2, float za2) {
    float yuri_7176 = ((age + yuri_3565) / lifetime) * 32;
    if (yuri_7176 < 0) yuri_7176 = 0;
    if (yuri_7176 > 1) yuri_7176 = 1;

    yuri_9050 = oSize * yuri_7176;
    yuri_2090::yuri_8158(t, yuri_3565, xa, ya, za, xa2, za2);
}

void yuri_2132::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (age++ >= lifetime) yuri_8099();

    yuri_8730(7 - age * 8 / lifetime);

    yuri_7515(xd, yd, zd);
    xd *= 0.96f;
    yd *= 0.96f;
    zd *= 0.96f;
    std::shared_ptr<yuri_2126> yuri_7701 = yuri_7194->yuri_5586(yuri_8996(), 2);
    if (yuri_7701 != nullptr) {
        if (yuri_9625 > yuri_7701->yuri_3799.yuri_9626) {
            yuri_9625 += (yuri_7701->yuri_3799.yuri_9626 - yuri_9625) * 0.2;
            yd += (yuri_7701->yd - yd) * 0.2;
            yuri_8782(yuri_9621, yuri_9625, yuri_9630);
        }
    }

    if (onGround) {
        xd *= 0.7f;
        zd *= 0.7f;
    }
}
