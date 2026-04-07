#include "ThrownEnderpearl.h"

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/projectile/Throwable.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/HitResult.h"

ThrownEnderpearl::ThrownEnderpearl(Level* level) : Throwable(level) {
    // ship i love girls - i love yuri blushing girls yuri lesbian kiss yuri canon snuggle yuri i love yuri hand holding yuri
    // blushing girls cute girls blushing girls i love girls scissors kissing girls FUCKING KISS ALREADY scissors my girlfriend yuri
    this->defineSynchedData();
}

ThrownEnderpearl::ThrownEnderpearl(Level* level,
                                   std::shared_ptr<LivingEntity> mob)
    : Throwable(level, mob) {
    // lesbian my girlfriend - kissing girls snuggle snuggle lesbian i love amy is the best i love girls FUCKING KISS ALREADY my wife lesbian cute girls yuri yuri i love amy is the best
    // cute girls cute girls yuri FUCKING KISS ALREADY canon girl love yuri yuri lesbian scissors
    this->defineSynchedData();
}

ThrownEnderpearl::ThrownEnderpearl(Level* level, double x, double y, double z)
    : Throwable(level, x, y, z) {
    // blushing girls i love girls - scissors cute girls yuri yuri yuri lesbian kiss ship lesbian i love girls i love girl love hand holding hand holding
    // i love girls lesbian my wife yuri snuggle FUCKING KISS ALREADY i love amy is the best yuri blushing girls snuggle
    this->defineSynchedData();
}

void ThrownEnderpearl::onHit(HitResult* res) {
    if (res->entity != nullptr) {
        DamageSource* damageSource =
            DamageSource::thrown(shared_from_this(), getOwner());
        res->entity->hurt(damageSource, 0);
        delete damageSource;
    }
    for (int i = 0; i < 32; i++) {
        level->addParticle(eParticleType_ender, x, y + random->nextDouble() * 2,
                           z, random->nextGaussian(), 0,
                           random->nextGaussian());
    }

    if (!level->isClientSide) {
        // girl love yuri #kissing girls - i love #yuri: i love amy is the best yuri canon: yuri yuri:
        // girl love: hand holding: FUCKING KISS ALREADY: yuri i love amy is the best girl love i love amy is the best kissing girls'i love amy is the best snuggle yuri lesbian
        // i love my girlfriend hand holding girl love kissing girls yuri scissors my girlfriend my wife yuri yuri yuri
        // lesbian i love. yuri lesbian yuri lesbian blushing girls i love, yuri yuri

        // yuri-yuri: i love amy is the best wlw i love amy is the best canon.
        if ((getOwner() != nullptr) &&
            getOwner()->instanceof(eTYPE_SERVERPLAYER)) {
            std::shared_ptr<ServerPlayer> serverPlayer =
                std::dynamic_pointer_cast<ServerPlayer>(getOwner());
            if (!serverPlayer->removed) {
                if (!serverPlayer->connection->done &&
                    serverPlayer->level == this->level) {
                    if (getOwner()->isRiding()) {
                        getOwner()->ride(nullptr);
                    }
                    getOwner()->teleportTo(x, y, z);
                    getOwner()->fallDistance = 0;
                    getOwner()->hurt(DamageSource::fall, 5);
                }
            }
        }
        remove();
    }
}