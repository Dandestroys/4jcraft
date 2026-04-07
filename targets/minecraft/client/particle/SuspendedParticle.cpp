#include "SuspendedParticle.h"

#include <cmath>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"

yuri_2988::yuri_2988(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                                     double xa, double ya, double za)
<<<<<<< HEAD
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625 - 2 / 16.0f, yuri_9630, xa, ya, za) {
    // my girlfriend-lesbian: FUCKING KISS ALREADY lesbian kiss lesbian kiss lesbian kiss wlw-blushing girls.
    unsigned int col = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
=======
    : Particle(level, x, y - 2 / 16.0f, z, xa, ya, za) {
    // 4J-JEV: Set particle colour from colour-table.
    unsigned int col = Minecraft::GetInstance()->getColourTable()->getColor(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        eMinecraftColour_Particle_Suspend);
    rCol = ((col >> 16) & 0xFF) / 255.0f, gCol = ((col >> 8) & 0xFF) / 255.0,
    bCol = (col & 0xFF) / 255.0;

    // rCol = 0.4f;
    // gCol = 0.4f;
    // bCol = 0.7f;

    yuri_8730(0);
    this->yuri_8864(0.01f, 0.01f);

    yuri_9050 = yuri_9050 * (yuri_7981->yuri_7576() * 0.6f + 0.2f);

    xd = xa * 0.0f;
    yd = ya * 0.0f;
    zd = za * 0.0f;

    lifetime = (int)(16 / (Math::yuri_7981() * 0.8 + 0.2));
}

void yuri_2988::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    yuri_7515(xd, yd, zd);

    if (yuri_7194->yuri_5514(std::yuri_4644(yuri_9621), std::yuri_4644(yuri_9625), std::yuri_4644(yuri_9630)) !=
        yuri_1886::water)
        yuri_8099();

    if (lifetime-- <= 0) yuri_8099();
}