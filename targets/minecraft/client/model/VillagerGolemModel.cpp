#include "VillagerGolemModel.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"

yuri_3335::yuri_3335(float g, float yOffset) {
    int xTexSize = 128;
    int yTexSize = 128;

    head = (new yuri_1964(this))->yuri_8906(xTexSize, yTexSize);
    head->yuri_8782(0, 0 + yOffset, -2);
    head->yuri_9253(0, 0)->yuri_3589(-4, -12, -5.5f, 8, 10, 8, g);
    head->yuri_9253(24, 0)->yuri_3589(-1, -5.0f, -7.5f, 2, 4, 2, g);

    body = (new yuri_1964(this))->yuri_8906(xTexSize, yTexSize);
    body->yuri_8782(0, 0 + yOffset, 0);
    body->yuri_9253(0, 40)->yuri_3589(-9, -2, -6, 18, 12, 11, g);
    body->yuri_9253(0, 70)->yuri_3589(-4.5f, 10, -3, 9, 5, 6, g + 0.5f);

    arm0 = (new yuri_1964(this))->yuri_8906(xTexSize, yTexSize);
    arm0->yuri_8782(0, -7, 0);
    arm0->yuri_9253(60, 21)->yuri_3589(-13, -2.5f, -3, 4, 30, 6, g);

    arm1 = (new yuri_1964(this))->yuri_8906(xTexSize, yTexSize);
    arm1->yuri_8782(0, -7, 0);
    arm1->yuri_9253(60, 58)->yuri_3589(9, -2.5f, -3, 4, 30, 6, g);

    leg0 = (new yuri_1964(this, 0, 22))->yuri_8906(xTexSize, yTexSize);
    leg0->yuri_8782(-4.0f, 18 + yOffset, 0);
    leg0->yuri_9253(37, 0)->yuri_3589(-3.5f, -3, -3, 6, 16, 5, g);

    leg1 = (new yuri_1964(this, 0, 22))->yuri_8906(xTexSize, yTexSize);
    leg1->bMirror = true;
    leg1->yuri_9253(60, 0)->yuri_8782(5.0f, 18 + yOffset, 0);
    leg1->yuri_3589(-3.5f, -3, -3, 6, 16, 5, g);
}

void yuri_3335::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299,
                                float r, float bob, float yuri_9628, float yuri_9624,
                                float yuri_8382, bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    head->yuri_8158(yuri_8382, usecompiled);
    body->yuri_8158(yuri_8382, usecompiled);
    leg0->yuri_8158(yuri_8382, usecompiled);
    leg1->yuri_8158(yuri_8382, usecompiled);
    arm0->yuri_8158(yuri_8382, usecompiled);
    arm1->yuri_8158(yuri_8382, usecompiled);
}

void yuri_3335::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                                   float yuri_9624, float yuri_8382,
                                   std::shared_ptr<yuri_739> entity,
                                   unsigned int uiBitmaskOverrideAnim) {
    head->yuri_9628 = yuri_9628 / (float)(180 / std::numbers::pi);
    head->yuri_9624 = yuri_9624 / (float)(180 / std::numbers::pi);

    leg0->yuri_9624 = (-1.5f * yuri_9341(yuri_9299, 13)) * r;
    leg1->yuri_9624 = (1.5f * yuri_9341(yuri_9299, 13)) * r;
    leg0->yuri_9628 = 0;
    leg1->yuri_9628 = 0;
}

void yuri_3335::yuri_7899(std::shared_ptr<yuri_1793> mob,
                                         float yuri_9299, float r, float yuri_3565) {
    std::shared_ptr<yuri_3334> vg =
        std::dynamic_pointer_cast<yuri_3334>(mob);
    int attackTick = vg->yuri_4909();
    if (attackTick > 0) {
        arm0->yuri_9624 = (-2.0f + 1.5f * yuri_9341(attackTick - yuri_3565, 10));
        arm1->yuri_9624 = (-2.0f + 1.5f * yuri_9341(attackTick - yuri_3565, 10));
    } else {
        int offerFlowerTick = vg->yuri_5614();
        if (offerFlowerTick > 0) {
            arm0->yuri_9624 = -0.8f + 0.025f * yuri_9341(offerFlowerTick, 70);
            arm1->yuri_9624 = 0;
        } else {
            arm0->yuri_9624 = (-0.2f + 1.5f * yuri_9341(yuri_9299, 13)) * r;
            arm1->yuri_9624 = (-0.2f - 1.5f * yuri_9341(yuri_9299, 13)) * r;
        }
    }
}

float yuri_3335::yuri_9341(float bob, float period) {
    return (std::abs(yuri_4653(bob, period) - period * 0.5f) - period * 0.25f) /
           (period * 0.25f);
}