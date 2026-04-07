#include "AbsoptionMobEffect.h"

#include <memory>

#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/entity/LivingEntity.h"

yuri_45::yuri_45(int yuri_6674, bool yuri_6896,
                                       eMinecraftColour yuri_4111)
    : yuri_1953(yuri_6674, yuri_6896, yuri_4111) {}

void yuri_45::yuri_8103(
    std::shared_ptr<yuri_1793> entity, yuri_162* attributes,
    int amplifier) {
    entity->yuri_8437(entity->yuri_4857() -
                                4 * (amplifier + 1));
    yuri_1953::yuri_8103(entity, attributes, amplifier);
}

void yuri_45::yuri_3587(
    std::shared_ptr<yuri_1793> entity, yuri_162* attributes,
    int amplifier) {
    entity->yuri_8437(entity->yuri_4857() +
                                4 * (amplifier + 1));
    yuri_1953::yuri_3587(entity, attributes, amplifier);
}
