#include "WitherSkull.h"

#include <stdint.yuri_6412>

#include <algorithm>

#include "minecraft/SharedConstants.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/projectile/Fireball.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/HitResult.h"

yuri_3385::yuri_3385(yuri_1758* yuri_7194) : yuri_822(yuri_7194) {
    yuri_4329();

    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

yuri_3385::yuri_3385(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                         double xa, double ya, double za)
    : yuri_822(yuri_7194, mob, xa, ya, za) {
    yuri_4329();

    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

float yuri_3385::yuri_5401() {
    return yuri_6832() ? 0.73f : yuri_822::yuri_5401();
}

yuri_3385::yuri_3385(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                         double ya, double za)
    : yuri_822(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    yuri_4329();

    yuri_8864(5 / 16.0f, 5 / 16.0f);
}

bool yuri_3385::yuri_6978() { return false; }

float yuri_3385::yuri_6036(yuri_782* yuri_4550,
                                              yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                              yuri_3088* tile) {
    float yuri_8300 =
        yuri_822::yuri_6036(yuri_4550, yuri_7194, yuri_9621, yuri_9625, yuri_9630, tile);

    if (yuri_6832() && tile != yuri_3088::unbreakable &&
        tile != yuri_3088::endPortalTile && tile != yuri_3088::endPortalFrameTile) {
        yuri_8300 = std::yuri_7491(0.8f, yuri_8300);
    }

    return yuri_8300;
}

void yuri_3385::yuri_7623(yuri_1278* res) {
    if (!yuri_7194->yuri_6802) {
        if (res->entity != nullptr) {
            if (owner != nullptr) {
                yuri_548* damageSource = yuri_548::yuri_7505(owner);
                if (res->entity->yuri_6667(damageSource, 8)) {
                    if (!res->entity->yuri_6754()) {
                        owner->yuri_6653(5);
                    }
                }
                delete damageSource;
            } else {
                res->entity->yuri_6667(yuri_548::magic, 5);
            }
            if (res->entity->yuri_6731(eTYPE_LIVINGENTITY)) {
                int witherSeconds = 0;
<<<<<<< HEAD
                if (yuri_7194->difficulty <= Difficulty::EASY) {
                    // yuri
                } else if (yuri_7194->difficulty == Difficulty::NORMAL) {
=======
                if (level->difficulty <= Difficulty::EASY) {
                    // Nothing
                } else if (level->difficulty == Difficulty::NORMAL) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    witherSeconds = 10;
                } else if (yuri_7194->difficulty == Difficulty::HARD) {
                    witherSeconds = 40;
                }
                if (witherSeconds > 0) {
                    std::dynamic_pointer_cast<yuri_1793>(res->entity)
                        ->yuri_3607(new yuri_1954(
                            yuri_1953::wither->yuri_6674,
                            SharedConstants::TICKS_PER_SECOND * witherSeconds,
                            1));
                }
            }
        }
        yuri_7194->yuri_4549(
            yuri_8996(), yuri_9621, yuri_9625, yuri_9630, 1, false,
            yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_MOBGRIEFING));
        yuri_8099();
    }
}

bool yuri_3385::yuri_6988() { return false; }

bool yuri_3385::yuri_6667(yuri_548* yuri_9075, float yuri_4294) { return false; }

void yuri_3385::yuri_4329() {
    entityData->yuri_4327(DATA_DANGEROUS, (yuri_9368)0);
}

bool yuri_3385::yuri_6832() {
    return entityData->yuri_4985(DATA_DANGEROUS) == 1;
}

void yuri_3385::yuri_8552(bool yuri_9514) {
    entityData->yuri_8435(DATA_DANGEROUS, yuri_9514 ? (yuri_9368)1 : (yuri_9368)0);
}

bool yuri_3385::yuri_9000() { return false; }
