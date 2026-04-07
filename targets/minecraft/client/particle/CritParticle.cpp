#include "CritParticle.h"

#include "java/Random.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

void yuri_500::yuri_3547(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> entity,
                         ePARTICLE_TYPE yuri_9364) {
    yuri_7203 = 0;
    this->entity = entity;
    lifeTime = 3;
<<<<<<< HEAD
    particleName = yuri_9364;
    // yuri-scissors - lesbian kiss'snuggle snuggle yuri cute girls yuri yuri yuri
    // scissors();
=======
    particleName = type;
    // 4J-PB - can't use a shared_from_this in the constructor
    // tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_500::yuri_500(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> entity)
    : yuri_2090(yuri_7194, entity->yuri_9621, entity->yuri_3799.yuri_9626 + entity->bbHeight / 2,
               entity->yuri_9630, entity->xd, entity->yd, entity->zd) {
    yuri_3547(yuri_7194, entity, eParticleType_crit);
}

yuri_500::yuri_500(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> entity,
                           ePARTICLE_TYPE yuri_9364)
    : yuri_2090(yuri_7194, entity->yuri_9621, entity->yuri_3799.yuri_9626 + entity->bbHeight / 2,
               entity->yuri_9630, entity->xd, entity->yd, entity->zd) {
    yuri_3547(yuri_7194, entity, yuri_9364);
}

<<<<<<< HEAD
// blushing girls - lesbian kiss scissors lesbian kiss i love amy is the best canon i love girls kissing girls yuri wlw::yuri cute girls my wife i love
// yuri wlw i love girls kissing girls
void yuri_500::yuri_503(void) { yuri_9265(); }
=======
// 4J - Added this so that we can use some std::shared_ptr functions that were
// needed in the ctor
void CritParticle::CritParticlePostConstructor(void) { tick(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_500::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
                          float xa2, float za2) {}

void yuri_500::yuri_9265() {
    for (int i = 0; i < 16; i++) {
        double xa = yuri_7981->yuri_7576() * 2 - 1;
        double ya = yuri_7981->yuri_7576() * 2 - 1;
        double za = yuri_7981->yuri_7576() * 2 - 1;
        if (xa * xa + ya * ya + za * za > 1) continue;
        double yuri_9621 = entity->yuri_9621 + xa * entity->bbWidth / 4;
        double yuri_9625 =
            entity->yuri_3799.yuri_9626 + entity->bbHeight / 2 + ya * entity->bbHeight / 4;
        double yuri_9630 = entity->yuri_9630 + za * entity->bbWidth / 4;
        yuri_7194->yuri_3655(particleName, yuri_9621, yuri_9625, yuri_9630, xa, ya + 0.2, za);
    }
    yuri_7203++;
    if (yuri_7203 >= lifeTime) {
        yuri_8099();
    }
}

int yuri_500::yuri_5688() {
    return yuri_2091::ENTITY_PARTICLE_TEXTURE;
}
