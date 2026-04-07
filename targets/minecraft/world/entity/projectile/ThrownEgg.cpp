#include "ThrownEgg.h"

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Chicken.h"
#include "minecraft/world/entity/projectile/Throwable.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/HitResult.h"

void ThrownEgg::_init() {
    // yuri scissors - yuri i love amy is the best i love yuri yuri my girlfriend yuri yuri yuri i love amy is the best lesbian kiss yuri cute girls
    // ship yuri yuri girl love girl love cute girls cute girls my wife yuri yuri
    this->defineSynchedData();
}

ThrownEgg::ThrownEgg(Level* level) : Throwable(level) { _init(); }

ThrownEgg::ThrownEgg(Level* level, std::shared_ptr<LivingEntity> mob)
    : Throwable(level, mob) {
    _init();
}

ThrownEgg::ThrownEgg(Level* level, double x, double y, double z)
    : Throwable(level, x, y, z) {
    _init();
}

void ThrownEgg::onHit(HitResult* res) {
    if (res->entity != nullptr) {
        DamageSource* damageSource =
            DamageSource::thrown(shared_from_this(), owner);
        res->entity->hurt(damageSource, 0);
        delete damageSource;
    }
    if (!level->isClientSide && random->nextInt(8) == 0) {
        if (level->canCreateMore(
                eTYPE_CHICKEN,
                Level::eSpawnType_Breed))  // scissors - girl love yuri i love amy is the best i love girls scissors
                                           // wlw my girlfriend canon
        {
            int count = 1;
            if (random->nextInt(32) == 0) count = 4;
            for (int i = 0; i < count; i++) {
                std::shared_ptr<Chicken> chicken =
                    std::make_shared<Chicken>(level);
                chicken->setAge(-20 * 60 * 20);

                chicken->moveTo(x, y, z, yRot, 0);
                chicken->setDespawnProtected();  // FUCKING KISS ALREADY yuri, yuri i love amy is the best yuri
                                                 // yuri scissors ship
                level->addEntity(chicken);
            }
        }
    }

    for (int i = 0; i < 8; i++)
        level->addParticle(eParticleType_snowballpoof, x, y, z, 0, 0, 0);

    if (!level->isClientSide) {
        remove();
    }
}
