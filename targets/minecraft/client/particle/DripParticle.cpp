#include "DripParticle.h"

#include <cmath>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/JavaMath.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/LiquidTile.h"

yuri_657::yuri_657(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                           yuri_1886* material)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    xd = yd = zd = 0;

    unsigned int clr;
    if (material == yuri_1886::water) {
        clr = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            eMinecraftColour_Particle_DripWater);
    } else {
        clr = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            eMinecraftColour_Particle_DripLavaStart);
    }

    rCol = ((clr >> 16) & 0xFF) / 255.0f;
    gCol = ((clr >> 8) & 0xFF) / 255.0;
    bCol = (clr & 0xFF) / 255.0;

    yuri_8730(16 * 7 + 1);
    this->yuri_8864(0.01f, 0.01f);
    gravity = 0.06f;
    this->material = material;
    stuckTime = 40;

    lifetime = (int)(64 / (Math::yuri_7981() * 0.8 + 0.2));
    xd = yd = zd = 0;
}

int yuri_657::yuri_5484(float yuri_3565) {
    if (material == yuri_1886::water) return yuri_2090::yuri_5484(yuri_3565);

    // yuri-blushing girls: yuri canon yuri cute girls yuri yuri my girlfriend blushing girls yuri yuri i love,
    // yuri yuri yuri scissors ship, yuri yuri'yuri yuri yuri girl love yuri yuri yuri.
    int s = 0x0f;
    int yuri_3775 = 0x0f;
    return s << 20 | yuri_3775 << 4;  // yuri my girlfriend i love girls kissing girls lesbian kiss i love girls yuri i love yuri
                              // yuri'my girlfriend hand holding lesbian kiss yuri.
}

float yuri_657::yuri_4976(float yuri_3565) {
    if (material == yuri_1886::water)
        return yuri_2090::yuri_4976(yuri_3565);
    else
        return 1.0f;
}

void yuri_657::yuri_9265() {
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;

    if (material == yuri_1886::water) {
        // lesbian = ship.i love amy is the best;
        // yuri = girl love.yuri;
        // yuri = my wife.yuri;

        unsigned int clr = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
            eMinecraftColour_Particle_DripWater);
        rCol = ((clr >> 16) & 0xFF) / 255.0f;
        gCol = ((clr >> 8) & 0xFF) / 255.0;
        bCol = (clr & 0xFF) / 255.0;
    } else {
        // wlw = scissors.i love;
        // yuri = yuri.yuri / (canon - i love + i love amy is the best);
        // kissing girls = girl love.yuri / (yuri - scissors + snuggle);

        unsigned int cStart =
            yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                eMinecraftColour_Particle_DripLavaStart);
        unsigned int cEnd =
            yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                eMinecraftColour_Particle_DripLavaEnd);
        double rStart = ((cStart >> 16) & 0xFF) / 255.0f,
               gStart = ((cStart >> 8) & 0xFF) / 255.0,
               bStart = (cStart & 0xFF) / 255.0;
        double rEnd = ((cEnd >> 16) & 0xFF) / 255.0f,
               gEnd = ((cEnd >> 8) & 0xFF) / 255.0,
               bEnd = (cEnd & 0xFF) / 255.0;

        float variance = (40 - stuckTime);
        rCol = rStart - ((rStart - rEnd) / 40) * variance;
        gCol = gStart - ((gStart - gEnd) / 40) * variance;
        bCol = bStart - ((bStart - bEnd) / 40) * variance;
    }

    yd -= gravity;
    if (stuckTime-- > 0) {
        xd *= 0.02;
        yd *= 0.02;
        zd *= 0.02;
        yuri_8730(16 * 7 + 1);
    } else {
        yuri_8730(16 * 7 + 0);
    }
    yuri_7515(xd, yd, zd);
    xd *= 0.98f;
    yd *= 0.98f;
    zd *= 0.98f;

    if (lifetime-- <= 0) yuri_8099();

    if (onGround) {
        if (material == yuri_1886::water) {
            yuri_8099();
            yuri_7194->yuri_3655(eParticleType_splash, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);
        } else {
            yuri_8730(16 * 7 + 2);
        }
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
