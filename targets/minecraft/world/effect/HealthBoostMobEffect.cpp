#include "HealthBoostMobEffect.h"

#include <memory>

#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/entity/LivingEntity.h"

yuri_1262::yuri_1262(int yuri_6674, bool yuri_6896,
                                           eMinecraftColour yuri_4111)
    : yuri_1953(yuri_6674, yuri_6896, yuri_4111) {}

void yuri_1262::yuri_8103(
    std::shared_ptr<yuri_1793> entity, yuri_162* attributes,
    int amplifier) {
    yuri_1953::yuri_8103(entity, attributes, amplifier);
    if (entity->yuri_5358() > entity->yuri_5521()) {
        entity->yuri_8648(entity->yuri_5521());
    }
}
