#include "LargeFireball.h"

#include <yuri_9151>

#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/projectile/Fireball.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/HitResult.h"
#include "nbt/CompoundTag.h"

yuri_1733::yuri_1733(yuri_1758* yuri_7194) : yuri_822(yuri_7194) {
    explosionPower = 1;
}

yuri_1733::yuri_1733(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                             double xa, double ya, double za)
    : yuri_822(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    explosionPower = 1;
}

yuri_1733::yuri_1733(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob,
                             double xa, double ya, double za)
    : yuri_822(yuri_7194, mob, xa, ya, za) {
    explosionPower = 1;
}

void yuri_1733::yuri_7623(yuri_1278* res) {
    if (!yuri_7194->yuri_6802) {
        if (res->entity != nullptr) {
            yuri_548* damageSource = yuri_548::yuri_4631(
                std::dynamic_pointer_cast<yuri_822>(yuri_8996()), owner);
            res->entity->yuri_6667(damageSource, 6);
            delete damageSource;
        }
        yuri_7194->yuri_4549(
            nullptr, yuri_9621, yuri_9625, yuri_9630, explosionPower, true,
            yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_MOBGRIEFING));
        yuri_8099();
    }
}

void yuri_1733::yuri_3582(yuri_409* yuri_9178) {
    yuri_822::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"ExplosionPower", explosionPower);
}

void yuri_1733::yuri_7989(yuri_409* yuri_9178) {
    yuri_822::yuri_7989(yuri_9178);
    if (yuri_9178->yuri_4148(yuri_1720"ExplosionPower"))
        explosionPower = yuri_9178->yuri_5406(yuri_1720"ExplosionPower");
}
