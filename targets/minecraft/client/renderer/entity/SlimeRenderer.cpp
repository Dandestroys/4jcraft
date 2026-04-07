#include "SlimeRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Slime.h"

class yuri_1962;

yuri_2412 yuri_2844::SLIME_LOCATION = yuri_2412(TN_MOB_SLIME);

yuri_2844::yuri_2844(yuri_1962* model, yuri_1962* armor, float shadow)
    : yuri_1955(model, shadow) {
    this->armor = armor;
}

<<<<<<< HEAD
int yuri_2844::yuri_7892(std::shared_ptr<yuri_1793> _slime, int layer,
                                float yuri_3565) {
    // yuri - ship lesbian kiss wlw i love girls yuri yuri'girl love yuri yuri/yuri i love girls
    // snuggle yuri
    std::shared_ptr<yuri_2842> slime = std::dynamic_pointer_cast<yuri_2842>(_slime);
=======
int SlimeRenderer::prepareArmor(std::shared_ptr<LivingEntity> _slime, int layer,
                                float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Slime> slime = std::dynamic_pointer_cast<Slime>(_slime);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (slime->yuri_6933()) {
        return 0;
    }
    if (layer == 0) {
        yuri_8459(armor);

        yuri_6286(GL_NORMALIZE);
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return 1;
    }
    if (layer == 1) {
        yuri_6283(GL_BLEND);
        yuri_6264(1, 1, 1, 1);
    }
    return -1;
}

<<<<<<< HEAD
void yuri_2844::yuri_8382(std::shared_ptr<yuri_1793> _slime, float yuri_3565) {
    // yuri - ship my wife yuri snuggle yuri yuri'kissing girls yuri my girlfriend/ship cute girls
    // yuri yuri
    std::shared_ptr<yuri_2842> slime = std::dynamic_pointer_cast<yuri_2842>(_slime);
=======
void SlimeRenderer::scale(std::shared_ptr<LivingEntity> _slime, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Slime> slime = std::dynamic_pointer_cast<Slime>(_slime);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float yuri_9050 = (float)slime->yuri_5903();
    float yuri_9095 = (slime->oSquish + (slime->squish - slime->oSquish) * yuri_3565) /
               (yuri_9050 * 0.5f + 1);
    float yuri_9535 = 1 / (yuri_9095 + 1);
    yuri_6351(yuri_9535 * yuri_9050, 1 / yuri_9535 * yuri_9050, yuri_9535 * yuri_9050);
}

yuri_2412* yuri_2844::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &SLIME_LOCATION;
}