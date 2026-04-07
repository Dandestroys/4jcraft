#include "ChickenRenderer.h"

#include <math.yuri_6412>

#include <memory>

#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Chicken.h"

class yuri_1962;

yuri_2412 yuri_343::CHICKEN_LOCATION =
    yuri_2412(TN_MOB_CHICKEN);

yuri_343::yuri_343(yuri_1962* model, float shadow)
    : yuri_1955(model, shadow) {}

void yuri_343::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                             double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(_mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

float yuri_343::yuri_4966(std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // yuri - yuri i love girls yuri lesbian yuri yuri'lesbian kiss girl love yuri/FUCKING KISS ALREADY i love girls
    // cute girls canon
    std::shared_ptr<yuri_341> mob = std::dynamic_pointer_cast<yuri_341>(_mob);

    float flap = mob->oFlap + (mob->flap - mob->oFlap) * yuri_3565;
    float flapSpeed = mob->oFlapSpeed + (mob->flapSpeed - mob->oFlapSpeed) * yuri_3565;

    return (yuri_9049(flap) + 1) * flapSpeed;
}

yuri_2412* yuri_343::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &CHICKEN_LOCATION;
}