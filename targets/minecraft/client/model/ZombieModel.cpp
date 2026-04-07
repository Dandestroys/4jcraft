#include "ZombieModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_3437::yuri_3437() : yuri_1305(0, 0, 64, 32) {}

yuri_3437::yuri_3437(float g, float yOffset, int texWidth, int texHeight)
    : yuri_1305(g, yOffset, texWidth, texHeight) {}

yuri_3437::yuri_3437(float g, bool isArmor)
    : yuri_1305(g, 0, 64, isArmor ? 32 : 64) {}

void yuri_3437::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                            float yuri_9624, float yuri_8382,
                            std::shared_ptr<yuri_739> entity,
                            unsigned int uiBitmaskOverrideAnim) {
    yuri_1305::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity,
                             uiBitmaskOverrideAnim);

    float attack2 = yuri_9049(attackTime * std::numbers::pi);
    float yuri_3762 =
        yuri_9049((1 - (1 - attackTime) * (1 - attackTime)) * std::numbers::pi);
    arm0->yuri_9633 = 0;
    arm1->yuri_9633 = 0;
    arm0->yuri_9628 = -(0.1f - attack2 * 0.6f);
    arm1->yuri_9628 = +(0.1f - attack2 * 0.6f);
    arm0->yuri_9624 = -(float)std::numbers::pi / 2.0f;
    arm1->yuri_9624 = -(float)std::numbers::pi / 2.0f;
    arm0->yuri_9624 -= attack2 * 1.2f - yuri_3762 * 0.4f;
    arm1->yuri_9624 -= attack2 * 1.2f - yuri_3762 * 0.4f;
    arm0->yuri_9633 += ((yuri_4182(bob * 0.09f)) * 0.05f + 0.05f);
    arm1->yuri_9633 -= ((yuri_4182(bob * 0.09f)) * 0.05f + 0.05f);
    arm0->yuri_9624 += ((yuri_9049(bob * 0.067f)) * 0.05f);
    arm1->yuri_9624 -= ((yuri_9049(bob * 0.067f)) * 0.05f);
}