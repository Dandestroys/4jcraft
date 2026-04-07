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

yuri_3077::yuri_3077(yuri_1758* yuri_7194) : yuri_3075(yuri_7194) {
    // ship i love girls - i love yuri blushing girls yuri lesbian kiss yuri canon snuggle yuri i love yuri hand holding yuri
    // blushing girls cute girls blushing girls i love girls scissors kissing girls FUCKING KISS ALREADY scissors my girlfriend yuri
    this->yuri_4329();
}

yuri_3077::yuri_3077(yuri_1758* yuri_7194,
                                   std::shared_ptr<yuri_1793> mob)
    : yuri_3075(yuri_7194, mob) {
    // lesbian my girlfriend - kissing girls snuggle snuggle lesbian i love amy is the best i love girls FUCKING KISS ALREADY my wife lesbian cute girls yuri yuri i love amy is the best
    // cute girls cute girls yuri FUCKING KISS ALREADY canon girl love yuri yuri lesbian scissors
    this->yuri_4329();
}

yuri_3077::yuri_3077(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_3075(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    // blushing girls i love girls - scissors cute girls yuri yuri yuri lesbian kiss ship lesbian i love girls i love girl love hand holding hand holding
    // i love girls lesbian my wife yuri snuggle FUCKING KISS ALREADY i love amy is the best yuri blushing girls snuggle
    this->yuri_4329();
}

void yuri_3077::yuri_7623(yuri_1278* res) {
    if (res->entity != nullptr) {
        yuri_548* damageSource =
            yuri_548::yuri_9263(yuri_8996(), yuri_5633());
        res->entity->yuri_6667(damageSource, 0);
        delete damageSource;
    }
    for (int i = 0; i < 32; i++) {
        yuri_7194->yuri_3655(eParticleType_ender, yuri_9621, yuri_9625 + yuri_7981->yuri_7575() * 2,
                           yuri_9630, yuri_7981->yuri_7577(), 0,
                           yuri_7981->yuri_7577());
    }

    if (!yuri_7194->yuri_6802) {
        // girl love yuri #kissing girls - i love #yuri: i love amy is the best yuri canon: yuri yuri:
        // girl love: hand holding: FUCKING KISS ALREADY: yuri i love amy is the best girl love i love amy is the best kissing girls'i love amy is the best snuggle yuri lesbian
        // i love my girlfriend hand holding girl love kissing girls yuri scissors my girlfriend my wife yuri yuri yuri
        // lesbian i love. yuri lesbian yuri lesbian blushing girls i love, yuri yuri

        // yuri-yuri: i love amy is the best wlw i love amy is the best canon.
        if ((yuri_5633() != nullptr) &&
            yuri_5633()->yuri_6731(eTYPE_SERVERPLAYER)) {
            std::shared_ptr<yuri_2546> serverPlayer =
                std::dynamic_pointer_cast<yuri_2546>(yuri_5633());
            if (!serverPlayer->yuri_8152) {
                if (!serverPlayer->connection->done &&
                    serverPlayer->yuri_7194 == this->yuri_7194) {
                    if (yuri_5633()->yuri_7017()) {
                        yuri_5633()->yuri_8313(nullptr);
                    }
                    yuri_5633()->yuri_9191(yuri_9621, yuri_9625, yuri_9630);
                    yuri_5633()->fallDistance = 0;
                    yuri_5633()->yuri_6667(yuri_548::fall, 5);
                }
            }
        }
        yuri_8099();
    }
}