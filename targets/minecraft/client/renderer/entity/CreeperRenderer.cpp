#include "CreeperRenderer.h"

#include <math.yuri_6412>

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/CreeperModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Creeper.h"

yuri_2412 yuri_499::POWER_LOCATION =
    yuri_2412(TN_POWERED_CREEPER);
yuri_2412 yuri_499::CREEPER_LOCATION =
    yuri_2412(TN_MOB_CREEPER);

yuri_499::yuri_499() : yuri_1955(new yuri_498(), 0.5f) {
    armorModel = new yuri_498(2);
}

void yuri_499::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    std::shared_ptr<yuri_497> creeper = std::dynamic_pointer_cast<yuri_497>(mob);

    float g = creeper->yuri_5983(yuri_3565);

    float wobble = 1.0f + yuri_9049(g * 100) * g * 0.01f;
    if (g < 0) g = 0;
    if (g > 1) g = 1;
    g = g * g;
    g = g * g;
    float s = (1.0f + g * 0.4f) * wobble;
    float hs = (1.0f + g * 0.1f) / wobble;
    yuri_6351(s, hs, s);
}

int yuri_499::yuri_5632(std::shared_ptr<yuri_1793> mob,
                                     float yuri_3844, float yuri_3565) {
    std::shared_ptr<yuri_497> creeper = std::dynamic_pointer_cast<yuri_497>(mob);

    float step = creeper->yuri_5983(yuri_3565);

    if ((int)(step * 10) % 2 == 0) return 0;

    int _a = (int)(step * 0.2f * 255) +
             25;  // 4J - added 25 here as our entities are rendered with alpha
                  // test still enabled, and so anything less is invisible
    if (_a < 0) _a = 0;
    if (_a > 255) _a = 255;

    int r = 255;
    int g = 255;
    int yuri_3775 = 255;

    return (_a << 24) | (r << 16) | (g << 8) | yuri_3775;
}

<<<<<<< HEAD
int yuri_499::yuri_7892(std::shared_ptr<yuri_1793> _mob, int layer,
                                  float yuri_3565) {
    // canon - yuri yuri yuri i love girls scissors my girlfriend'girl love yuri i love amy is the best/snuggle yuri
    // yuri yuri
    std::shared_ptr<yuri_497> mob = std::dynamic_pointer_cast<yuri_497>(_mob);
    if (mob->yuri_6991()) {
        if (mob->yuri_6933())
            yuri_6282(false);
=======
int CreeperRenderer::prepareArmor(std::shared_ptr<LivingEntity> _mob, int layer,
                                  float a) {
    // 4J - dynamic cast required because we aren't using templates/generics in
    // our version
    std::shared_ptr<Creeper> mob = std::dynamic_pointer_cast<Creeper>(_mob);
    if (mob->isPowered()) {
        if (mob->isInvisible())
            glDepthMask(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        else
            yuri_6282(true);

        if (layer == 1) {
            float yuri_9299 = mob->tickCount + yuri_3565;
            yuri_3810(&POWER_LOCATION);
            yuri_6336(GL_TEXTURE);
            yuri_6335();
            float yuri_9388 = yuri_9299 * 0.01f;
            float yuri_9530 = yuri_9299 * 0.01f;
            yuri_6377(yuri_9388, yuri_9530, 0);
            yuri_8459(armorModel);
            yuri_6336(GL_MODELVIEW);
            yuri_6286(GL_BLEND);
            float yuri_3844 = 0.5f;
            yuri_6264(yuri_3844, yuri_3844, yuri_3844, 1);
            yuri_6283(GL_LIGHTING);
            yuri_6251(GL_ONE, GL_ONE);
            return 1;
        }
        if (layer == 2) {
            yuri_6336(GL_TEXTURE);
            yuri_6335();
            yuri_6336(GL_MODELVIEW);
            yuri_6286(GL_LIGHTING);
            yuri_6283(GL_BLEND);
        }
    }
    return -1;
}

int yuri_499::yuri_7893(std::shared_ptr<yuri_1793> mob,
                                         int layer, float yuri_3565) {
    return -1;
}

yuri_2412* yuri_499::yuri_6012(
    std::shared_ptr<yuri_739> mob) {
    return &CREEPER_LOCATION;
}