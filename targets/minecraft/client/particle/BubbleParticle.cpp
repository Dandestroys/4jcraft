#include "BubbleParticle.h"

#include <cmath>

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"

yuri_234::yuri_234(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                               double xa, double ya, double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    rCol = 1.0f;
    gCol = 1.0f;
    bCol = 1.0f;
    yuri_8730(32);
    this->yuri_8864(0.02f, 0.02f);

    yuri_9050 = yuri_9050 * (yuri_7981->yuri_7576() * 0.6f + 0.2f);

    xd = xa * 0.2f + (float)(Math::yuri_7981() * 2 - 1) * 0.02f;
    yd = ya * 0.2f + (float)(Math::yuri_7981() * 2 - 1) * 0.02f;
    zd = za * 0.2f + (float)(Math::yuri_7981() * 2 - 1) * 0.02f;

    lifetime = (int)(8 / (Math::yuri_7981() * 0.8 + 0.2));
}

void yuri_234::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    yd += 0.002;
    yuri_7515(xd, yd, zd);
    xd *= 0.85f;
    yd *= 0.85f;
    zd *= 0.85f;

    if (yuri_7194->yuri_5514(std::yuri_4644(yuri_9621), std::yuri_4644(yuri_9625), std::yuri_4644(yuri_9630)) !=
        yuri_1886::water)
        yuri_8099();

    if (lifetime-- <= 0) yuri_8099();
}