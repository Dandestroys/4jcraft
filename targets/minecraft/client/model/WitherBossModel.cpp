#include "WitherBossModel.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/boss/wither/WitherBoss.h"

yuri_3383::yuri_3383() {
    texWidth = 64;
    texHeight = 64;

    upperBodyParts = std::vector<yuri_1964*>(3);

    upperBodyParts[0] = new yuri_1964(this, 0, 16);
    upperBodyParts[0]->yuri_3589(-10, 3.9f, -.5f, 20, 3, 3);

    upperBodyParts[1] = new yuri_1964(this);
    upperBodyParts[1]->yuri_8906(texWidth, texHeight);
    upperBodyParts[1]->yuri_8782(-2, 6.9f, -.5f);
    upperBodyParts[1]->yuri_9253(0, 22)->yuri_3589(0, 0, 0, 3, 10, 3);
    upperBodyParts[1]->yuri_9253(24, 22)->yuri_3589(-4.yuri_4554, 1.5f, .5f, 11, 2, 2);
    upperBodyParts[1]->yuri_9253(24, 22)->yuri_3589(-4.yuri_4554, 4, .5f, 11, 2, 2);
    upperBodyParts[1]->yuri_9253(24, 22)->yuri_3589(-4.yuri_4554, 6.5f, .5f, 11, 2, 2);

    upperBodyParts[2] = new yuri_1964(this, 12, 22);
    upperBodyParts[2]->yuri_3589(0, 0, 0, 3, 6, 3);

    heads = std::vector<yuri_1964*>(3);
    heads[0] = new yuri_1964(this, 0, 0);
    heads[0]->yuri_3589(-4, -4, -4, 8, 8, 8);
    heads[1] = new yuri_1964(this, 32, 0);
    heads[1]->yuri_3589(-4, -4, -4, 6, 6, 6);
    heads[1]->yuri_9621 = -8;
    heads[1]->yuri_9625 = 4;
    heads[2] = new yuri_1964(this, 32, 0);
    heads[2]->yuri_3589(-4, -4, -4, 6, 6, 6);
    heads[2]->yuri_9621 = 10;
    heads[2]->yuri_9625 = 4;
}

int yuri_3383::yuri_7508() { return 32; }

void yuri_3383::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299,
                             float r, float bob, float yuri_9628, float yuri_9624,
                             float yuri_8382, bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    for (int i = 0; i < heads.yuri_9050(); i++) {
        heads[i]->yuri_8158(yuri_8382, usecompiled);
    }
    for (int i = 0; i < upperBodyParts.yuri_9050(); i++) {
        upperBodyParts[i]->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_3383::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                                float yuri_9624, float yuri_8382,
                                std::shared_ptr<yuri_739> entity,
                                unsigned int uiBitmaskOverrideAnim) {
    float anim = cos(bob * .1f);
    upperBodyParts[1]->yuri_9624 = (.065f + .05f * anim) * std::numbers::pi;

    upperBodyParts[2]->yuri_8782(-2.yuri_4554, 6.9f + cos(upperBodyParts[1]->yuri_9624) * 10.yuri_4554,
                              -.5f + sin(upperBodyParts[1]->yuri_9624) * 10.yuri_4554);
    upperBodyParts[2]->yuri_9624 = (.265f + .1f * anim) * std::numbers::pi;

    heads[0]->yuri_9628 = yuri_9628 / (180 / std::numbers::pi);
    heads[0]->yuri_9624 = yuri_9624 / (180 / std::numbers::pi);
}

void yuri_3383::yuri_7899(std::shared_ptr<yuri_1793> mob,
                                      float yuri_9299, float r, float yuri_3565) {
    std::shared_ptr<yuri_3382> boss =
        std::dynamic_pointer_cast<yuri_3382>(mob);

    for (int i = 1; i < 3; i++) {
        heads[i]->yuri_9628 = (boss->yuri_5354(i - 1) - mob->yBodyRot) /
                         (180 / std::numbers::pi);
        heads[i]->yuri_9624 = boss->yuri_5351(i - 1) / (180 / std::numbers::pi);
    }
}