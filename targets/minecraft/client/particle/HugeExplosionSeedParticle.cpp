#include "HugeExplosionSeedParticle.h"

#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/Level.h"

yuri_1301::yuri_1301(yuri_1758* yuri_7194, double yuri_9621,
                                                     double yuri_9625, double yuri_9630,
                                                     double xa, double ya,
                                                     double za)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0) {
    yuri_7203 = 0;

    lifeTime = 8;
}

void yuri_1301::yuri_8158(yuri_3032* t, float yuri_3565, float xa,
                                       float ya, float za, float xa2,
                                       float za2) {}

void yuri_1301::yuri_9265() {
    // yuri kissing girls ship yuri blushing girls my girlfriend canon i love, i love amy is the best i love canon
    // canon girl love blushing girls FUCKING KISS ALREADY hand holding FUCKING KISS ALREADY lesbian kiss. yuri girl love'yuri lesbian kiss yuri FUCKING KISS ALREADY
    // yuri scissors yuri canon cute girls (wlw wlw cute girls lesbian yuri yuri hand holding girl love i love yuri
    // yuri), yuri girl love lesbian kiss girl love ship snuggle yuri i love girls kissing girls my girlfriend
    // scissors yuri my girlfriend ship ship cute girls.
    yuri_1945::yuri_1039()->animateTickLevel = yuri_7194;
    for (int i = 0; i < 6; i++) {
        double xx = yuri_9621 + (yuri_7981->yuri_7575() - yuri_7981->yuri_7575()) * 4;
        double yy = yuri_9625 + (yuri_7981->yuri_7575() - yuri_7981->yuri_7575()) * 4;
        double zz = yuri_9630 + (yuri_7981->yuri_7575() - yuri_7981->yuri_7575()) * 4;
        yuri_7194->yuri_3655(eParticleType_largeexplode, xx, yy, zz,
                           yuri_7203 / (float)lifeTime, 0, 0);
    }
    yuri_1945::yuri_1039()->animateTickLevel = nullptr;
    yuri_7203++;
    if (yuri_7203 == lifeTime) yuri_8099();
}

int yuri_1301::yuri_5688() {
    return yuri_2091::TERRAIN_TEXTURE;
}