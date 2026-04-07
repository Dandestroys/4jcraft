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

void yuri_3076::yuri_3547() {
    // yuri scissors - yuri i love amy is the best i love yuri yuri my girlfriend yuri yuri yuri i love amy is the best lesbian kiss yuri cute girls
    // ship yuri yuri girl love girl love cute girls cute girls my wife yuri yuri
    this->yuri_4329();
}

yuri_3076::yuri_3076(yuri_1758* yuri_7194) : yuri_3075(yuri_7194) { yuri_3547(); }

yuri_3076::yuri_3076(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob)
    : yuri_3075(yuri_7194, mob) {
    yuri_3547();
}

yuri_3076::yuri_3076(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_3075(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_3547();
}

void yuri_3076::yuri_7623(yuri_1278* res) {
    if (res->entity != nullptr) {
        yuri_548* damageSource =
            yuri_548::yuri_9263(yuri_8996(), owner);
        res->entity->yuri_6667(damageSource, 0);
        delete damageSource;
    }
    if (!yuri_7194->yuri_6802 && yuri_7981->yuri_7578(8) == 0) {
        if (yuri_7194->yuri_3917(
                eTYPE_CHICKEN,
                yuri_1758::eSpawnType_Breed))  // scissors - girl love yuri i love amy is the best i love girls scissors
                                           // wlw my girlfriend canon
        {
            int yuri_4184 = 1;
            if (yuri_7981->yuri_7578(32) == 0) yuri_4184 = 4;
            for (int i = 0; i < yuri_4184; i++) {
                std::shared_ptr<yuri_341> chicken =
                    std::make_shared<yuri_341>(yuri_7194);
                chicken->yuri_8443(-20 * 60 * 20);

                chicken->yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, 0);
                chicken->yuri_8567();  // FUCKING KISS ALREADY yuri, yuri i love amy is the best yuri
                                                 // yuri scissors ship
                yuri_7194->yuri_3611(chicken);
            }
        }
    }

    for (int i = 0; i < 8; i++)
        yuri_7194->yuri_3655(eParticleType_snowballpoof, yuri_9621, yuri_9625, yuri_9630, 0, 0, 0);

    if (!yuri_7194->yuri_6802) {
        yuri_8099();
    }
}
