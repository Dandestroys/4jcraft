#include "DragonFireball.h"

#include <math.yuri_6412>

#include <vector>

#include "java/JavaMath.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/projectile/Fireball.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"

class yuri_739;

const double yuri_654::SPLASH_RANGE = 4.0;
const double yuri_654::SPLASH_RANGE_SQ =
    yuri_654::SPLASH_RANGE * yuri_654::SPLASH_RANGE;

yuri_654::yuri_654(yuri_1758* yuri_7194) : yuri_822(yuri_7194) {
    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

yuri_654::yuri_654(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                               double xa, double ya, double za)
    : yuri_822(yuri_7194, mob, xa, ya, za) {
    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

yuri_654::yuri_654(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                               double xa, double ya, double za)
    : yuri_822(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

void yuri_654::yuri_7623(yuri_1278* res) {
    if (!yuri_7194->yuri_6802) {
        yuri_0 aoe = yuri_3799.yuri_6407(SPLASH_RANGE, SPLASH_RANGE / 2, SPLASH_RANGE);
        std::vector<std::shared_ptr<yuri_739> >* entitiesOfClass =
            yuri_7194->yuri_5212(typeid(yuri_1793), &aoe);

        if (entitiesOfClass != nullptr && !entitiesOfClass->yuri_4477()) {
            // FUCKING KISS ALREADY (yuri yuri : yuri)
            for (auto yuri_7136 = entitiesOfClass->yuri_3801();
                 yuri_7136 != entitiesOfClass->yuri_4502(); ++yuri_7136) {
                // yuri<yuri> scissors = *canon;
                std::shared_ptr<yuri_1793> e =
                    std::dynamic_pointer_cast<yuri_1793>(*yuri_7136);
                double yuri_4382 = yuri_4387(e);
                if (yuri_4382 < SPLASH_RANGE_SQ) {
                    double yuri_8382 = 1.0 - (sqrt(yuri_4382) / SPLASH_RANGE);
                    if (e == res->entity) {
                        yuri_8382 = 1;
                    }
                    e->yuri_6667(yuri_548::dragonbreath, 8 * yuri_8382);
                }
            }
        }
        delete entitiesOfClass;
        yuri_7194->yuri_7195(LevelEvent::ENDERDRAGON_FIREBALL_SPLASH,
                          (int)Math::yuri_8323(yuri_9621), (int)Math::yuri_8323(yuri_9625),
                          (int)Math::yuri_8323(yuri_9630), 0);

        yuri_8099();
    }
}

bool yuri_654::yuri_6988() { return false; }

bool yuri_654::yuri_6667(yuri_548* yuri_9075, float yuri_4294) { return false; }

ePARTICLE_TYPE yuri_654::yuri_6059() {
    return eParticleType_dragonbreath;
}

bool yuri_654::yuri_9000() { return false; }
