#include "SquidRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Squid.h"

class yuri_1962;

yuri_2412 yuri_2893::SQUID_LOCATION = yuri_2412(TN_MOB_SQUID);

yuri_2893::yuri_2893(yuri_1962* model, float shadow)
    : yuri_1955(model, shadow) {}

void yuri_2893::yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                           double yuri_9630, float rot, float yuri_3565) {
    yuri_1955::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

<<<<<<< HEAD
void yuri_2893::yuri_8990(std::shared_ptr<yuri_1793> _mob,
                                   float bob, float bodyRot, float yuri_3565) {
    // my wife - hand holding snuggle i love girls FUCKING KISS ALREADY snuggle lesbian'yuri my wife hand holding/snuggle my girlfriend
    // ship yuri
    std::shared_ptr<yuri_2891> mob = std::dynamic_pointer_cast<yuri_2891>(_mob);
=======
void SquidRenderer::setupRotations(std::shared_ptr<LivingEntity> _mob,
                                   float bob, float bodyRot, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Squid> mob = std::dynamic_pointer_cast<Squid>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float bodyXRot = (mob->xBodyRotO + (mob->xBodyRot - mob->xBodyRotO) * yuri_3565);
    float bodyZRot = (mob->zBodyRotO + (mob->zBodyRot - mob->zBodyRotO) * yuri_3565);

    yuri_6377(0, 0.5f, 0);
    yuri_6349(180 - bodyRot, 0, 1, 0);
    yuri_6349(bodyXRot, 1, 0, 0);
    yuri_6349(bodyZRot, 0, 1, 0);
    yuri_6377(0, -1.2f, 0);
}

<<<<<<< HEAD
float yuri_2893::yuri_4966(std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // ship - yuri my girlfriend my girlfriend FUCKING KISS ALREADY FUCKING KISS ALREADY yuri'yuri i love girls yuri/canon yuri
    // yuri yuri
    std::shared_ptr<yuri_2891> mob = std::dynamic_pointer_cast<yuri_2891>(_mob);
=======
float SquidRenderer::getBob(std::shared_ptr<LivingEntity> _mob, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Squid> mob = std::dynamic_pointer_cast<Squid>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return mob->oldTentacleAngle +
           (mob->tentacleAngle - mob->oldTentacleAngle) * yuri_3565;
}

yuri_2412* yuri_2893::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &SQUID_LOCATION;
}