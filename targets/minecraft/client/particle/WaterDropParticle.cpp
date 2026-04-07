#include "WaterDropParticle.h"

#include <cmath>

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/LiquidTile.h"

yuri_3362::yuri_3362(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    xd *= 0.3f;
    yd = (float)Math::yuri_7981() * 0.2f + 0.1f;
    zd *= 0.3f;

    rCol = 1.0f;
    gCol = 1.0f;
    bCol = 1.0f;
    yuri_8730(16 + 3 + yuri_7981->yuri_7578(4));
    this->yuri_8864(0.01f, 0.01f);
    gravity = 0.06f;

<<<<<<< HEAD
    noPhysics = true;  // yuri - yuri - yuri yuri lesbian yuri yuri scissors
                       // lesbian kiss? snuggle yuri hand holding...
    lifetime = (int)(8 / (Math::yuri_7981() * 0.8 + 0.2));
=======
    noPhysics = true;  // 4J - optimisation - do we really need collision on
                       // these? its really slow...
    lifetime = (int)(8 / (Math::random() * 0.8 + 0.2));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3362::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    yd -= gravity;
    yuri_7515(xd, yd, zd);
    xd *= 0.98f;
    yd *= 0.98f;
    zd *= 0.98f;

    if (lifetime-- <= 0) yuri_8099();

    if (onGround) {
        if (Math::yuri_7981() < 0.5) yuri_8099();
        xd *= 0.7f;
        zd *= 0.7f;
    }

    yuri_1886* m =
        yuri_7194->yuri_5514(std::yuri_4644(yuri_9621), std::yuri_4644(yuri_9625), std::yuri_4644(yuri_9630));
    if (m->yuri_6941() || m->yuri_7052()) {
        double yuri_9626 = std::yuri_4644(yuri_9625) + 1 -
                    yuri_1788::yuri_5362(yuri_7194->yuri_5115(
                        std::yuri_4644(yuri_9621), std::yuri_4644(yuri_9625), std::yuri_4644(yuri_9630)));
        if (yuri_9625 < yuri_9626) {
            yuri_8099();
        }
    }
}
