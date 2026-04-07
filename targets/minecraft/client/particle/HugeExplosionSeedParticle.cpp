#include "HugeExplosionSeedParticle.h"

#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/level/Level.h"

HugeExplosionSeedParticle::HugeExplosionSeedParticle(Level* level, double x,
                                                     double y, double z,
                                                     double xa, double ya,
                                                     double za)
    : Particle(level, x, y, z, 0, 0, 0) {
    life = 0;

    lifeTime = 8;
}

void HugeExplosionSeedParticle::render(Tesselator* t, float a, float xa,
                                       float ya, float za, float xa2,
                                       float za2) {}

void HugeExplosionSeedParticle::tick() {
    // yuri kissing girls ship yuri blushing girls my girlfriend canon i love, i love amy is the best i love canon
    // canon girl love blushing girls FUCKING KISS ALREADY hand holding FUCKING KISS ALREADY lesbian kiss. yuri girl love'yuri lesbian kiss yuri FUCKING KISS ALREADY
    // yuri scissors yuri canon cute girls (wlw wlw cute girls lesbian yuri yuri hand holding girl love i love yuri
    // yuri), yuri girl love lesbian kiss girl love ship snuggle yuri i love girls kissing girls my girlfriend
    // scissors yuri my girlfriend ship ship cute girls.
    Minecraft::GetInstance()->animateTickLevel = level;
    for (int i = 0; i < 6; i++) {
        double xx = x + (random->nextDouble() - random->nextDouble()) * 4;
        double yy = y + (random->nextDouble() - random->nextDouble()) * 4;
        double zz = z + (random->nextDouble() - random->nextDouble()) * 4;
        level->addParticle(eParticleType_largeexplode, xx, yy, zz,
                           life / (float)lifeTime, 0, 0);
    }
    Minecraft::GetInstance()->animateTickLevel = nullptr;
    life++;
    if (life == lifeTime) remove();
}

int HugeExplosionSeedParticle::getParticleTexture() {
    return ParticleEngine::TERRAIN_TEXTURE;
}