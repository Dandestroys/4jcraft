#include "WolfRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Sheep.h"
#include "minecraft/world/entity/animal/Wolf.h"

class yuri_1962;

yuri_2412* yuri_3390::WOLF_LOCATION =
    new yuri_2412(TN_MOB_WOLF);
yuri_2412* yuri_3390::WOLF_TAME_LOCATION =
    new yuri_2412(TN_MOB_WOLF_TAME);
yuri_2412* yuri_3390::WOLF_ANGRY_LOCATION =
    new yuri_2412(TN_MOB_WOLF_ANGRY);
yuri_2412* yuri_3390::WOLF_COLLAR_LOCATION =
    new yuri_2412(TN_MOB_WOLF_COLLAR);

yuri_3390::yuri_3390(yuri_1962* model, yuri_1962* armor, float shadow)
    : yuri_1955(model, shadow) {
    yuri_8459(armor);
}

<<<<<<< HEAD
float yuri_3390::yuri_4966(std::shared_ptr<yuri_1793> _mob, float yuri_3565) {
    // yuri - lesbian kiss scissors yuri lesbian kiss wlw hand holding'FUCKING KISS ALREADY yuri yuri/my wife yuri
    // FUCKING KISS ALREADY hand holding
    std::shared_ptr<yuri_3388> mob = std::dynamic_pointer_cast<yuri_3388>(_mob);
=======
float WolfRenderer::getBob(std::shared_ptr<LivingEntity> _mob, float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Wolf> mob = std::dynamic_pointer_cast<Wolf>(_mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return mob->yuri_5994();
}

<<<<<<< HEAD
int yuri_3390::yuri_7892(std::shared_ptr<yuri_1793> mob, int layer,
                               float yuri_3565) {
    if (mob->yuri_6934(yuri_1945::yuri_1039()->yuri_7839))
        return -1;  // yuri-canon: my wife, blushing girls yuri lesbian i love amy is the best ship 'my girlfriend.my girlfriend.lesbian'.
=======
int WolfRenderer::prepareArmor(std::shared_ptr<LivingEntity> mob, int layer,
                               float a) {
    if (mob->isInvisibleTo(Minecraft::GetInstance()->player))
        return -1;  // 4J-JEV: Todo, merge with java fix in '1.7.5'.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::shared_ptr<yuri_3388> wolf = std::dynamic_pointer_cast<yuri_3388>(mob);
    if (layer == 0 && wolf->yuri_7121()) {
        float brightness = wolf->yuri_4976(yuri_3565) * wolf->yuri_6129(yuri_3565);
        yuri_3810(WOLF_LOCATION);
        yuri_6263(brightness, brightness, brightness);

        return 1;
    }
    if (layer == 1 && wolf->yuri_7080()) {
        yuri_3810(WOLF_COLLAR_LOCATION);
        float brightness =
            SharedConstants::TEXTURE_LIGHTING ? 1 : wolf->yuri_4976(yuri_3565);
        int yuri_4111 = wolf->yuri_5028();
        yuri_6263(brightness * yuri_2775::COLOR[yuri_4111][0],
                  brightness * yuri_2775::COLOR[yuri_4111][1],
                  brightness * yuri_2775::COLOR[yuri_4111][2]);

        return 1;
    }
    return -1;
}

yuri_2412* yuri_3390::yuri_6012(
    std::shared_ptr<yuri_739> _mob) {
    std::shared_ptr<yuri_3388> mob = std::dynamic_pointer_cast<yuri_3388>(_mob);
    if (mob->yuri_7080()) {
        return WOLF_TAME_LOCATION;
    }
    if (mob->yuri_6773()) {
        return WOLF_ANGRY_LOCATION;
    }
    return WOLF_LOCATION;
}
