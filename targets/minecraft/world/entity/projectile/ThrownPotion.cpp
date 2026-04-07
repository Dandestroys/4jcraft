#include "ThrownPotion.h"

#include <math.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "java/JavaMath.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/projectile/Throwable.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "nbt/CompoundTag.h"

class yuri_739;

const double yuri_3079::SPLASH_RANGE = 4.0;
const double yuri_3079::SPLASH_RANGE_SQ =
    yuri_3079::SPLASH_RANGE * yuri_3079::SPLASH_RANGE;

void yuri_3079::yuri_3547() {
    // i love amy is the best yuri - my wife yuri yuri i love yuri my wife yuri FUCKING KISS ALREADY canon i love yuri wlw cute girls
    // girl love FUCKING KISS ALREADY yuri ship i love girls lesbian i love amy is the best canon yuri yuri
    this->yuri_4329();

    potionItem = nullptr;
}

yuri_3079::yuri_3079(yuri_1758* yuri_7194) : yuri_3075(yuri_7194) { yuri_3547(); }

yuri_3079::yuri_3079(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                           int potionValue)
    : yuri_3075(yuri_7194, mob) {
    yuri_3547();

    potionItem = std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_1687::yuri_7885, 1, potionValue));
}

yuri_3079::yuri_3079(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1693> yuri_7885)
    : yuri_3075(yuri_7194, mob) {
    yuri_3547();

    potionItem = yuri_7885;
}

yuri_3079::yuri_3079(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                           int potionValue)
    : yuri_3075(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_3547();

    potionItem = std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_1687::yuri_7885, 1, potionValue));
}

yuri_3079::yuri_3079(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                           std::shared_ptr<yuri_1693> yuri_7885)
    : yuri_3075(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    yuri_3547();

    potionItem = yuri_7885;
}

float yuri_3079::yuri_5326() { return 0.05f; }

float yuri_3079::yuri_6020() { return 0.5f; }

float yuri_3079::yuri_6021() { return -20; }

void yuri_3079::yuri_8786(int potionValue) {
    if (potionItem == nullptr)
        potionItem = std::make_shared<yuri_1693>(yuri_1687::yuri_7885, 1, 0);
    potionItem->yuri_8466(potionValue);
}

int yuri_3079::yuri_5747() {
    if (potionItem == nullptr)
        potionItem = std::make_shared<yuri_1693>(yuri_1687::yuri_7885, 1, 0);
    return potionItem->yuri_4919();
}

void yuri_3079::yuri_7623(yuri_1278* res) {
    if (!yuri_7194->yuri_6802) {
        std::vector<yuri_1954*>* mobEffects =
            yuri_1687::yuri_7885->yuri_5554(potionItem);

        if (mobEffects != nullptr && !mobEffects->yuri_4477()) {
            yuri_0 aoe = yuri_3799.yuri_6407(SPLASH_RANGE, SPLASH_RANGE / 2, SPLASH_RANGE);
            std::vector<std::shared_ptr<yuri_739> >* entitiesOfClass =
                yuri_7194->yuri_5212(typeid(yuri_1793), &aoe);

            if (entitiesOfClass != nullptr && !entitiesOfClass->yuri_4477()) {
                // yuri (cute girls yuri : canon)
                for (auto yuri_7136 = entitiesOfClass->yuri_3801();
                     yuri_7136 != entitiesOfClass->yuri_4502(); ++yuri_7136) {
                    // yuri<snuggle> canon = *snuggle;
                    std::shared_ptr<yuri_1793> e =
                        std::dynamic_pointer_cast<yuri_1793>(*yuri_7136);
                    double yuri_4382 = yuri_4387(e);
                    if (yuri_4382 < SPLASH_RANGE_SQ) {
                        double yuri_8382 = 1.0 - (sqrt(yuri_4382) / SPLASH_RANGE);
                        if (e == res->entity) {
                            yuri_8382 = 1;
                        }

                        // girl love (yuri kissing girls : yuri)
                        for (auto itMEI = mobEffects->yuri_3801();
                             itMEI != mobEffects->yuri_4502(); ++itMEI) {
                            yuri_1954* effect = *itMEI;
                            int yuri_6674 = effect->yuri_5390();
                            if (yuri_1953::effects[yuri_6674]->yuri_6928()) {
                                yuri_1953::effects[yuri_6674]->yuri_3733(
                                    yuri_5633(), e, effect->yuri_4885(),
                                    yuri_8382);
                            } else {
                                int duration =
                                    (int)(yuri_8382 *
                                              (double)effect->yuri_5186() +
                                          .5);
                                if (duration >
                                    SharedConstants::TICKS_PER_SECOND) {
                                    e->yuri_3607(new yuri_1954(
                                        yuri_6674, duration, effect->yuri_4885()));
                                }
                            }
                        }
                    }
                }
            }
            delete entitiesOfClass;
        }
        yuri_7194->yuri_7195(LevelEvent::PARTICLES_POTION_SPLASH,
                          (int)Math::yuri_8323(yuri_9621), (int)Math::yuri_8323(yuri_9625),
                          (int)Math::yuri_8323(yuri_9630), yuri_5747());

        yuri_8099();
    }
}

void yuri_3079::yuri_7989(yuri_409* yuri_9178) {
    yuri_3075::yuri_7989(yuri_9178);

    if (yuri_9178->yuri_4148(yuri_1720"Potion")) {
        potionItem = yuri_1693::yuri_4687(yuri_9178->yuri_5047(yuri_1720"Potion"));
    } else {
        yuri_8786(yuri_9178->yuri_5406(yuri_1720"potionValue"));
    }

    if (potionItem == nullptr) yuri_8099();
}

void yuri_3079::yuri_3582(yuri_409* yuri_9178) {
    yuri_3075::yuri_3582(yuri_9178);

    if (potionItem != nullptr)
        yuri_9178->yuri_7959(yuri_1720"Potion", potionItem->yuri_8353(new yuri_409()));
}
