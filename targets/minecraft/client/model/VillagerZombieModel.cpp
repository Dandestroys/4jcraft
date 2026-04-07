#include "VillagerZombieModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/model/geom/ModelPart.h"

void yuri_3340::yuri_3547(float g, float yOffset, bool isArmor) {
    delete head;
    if (isArmor) {
        head = new yuri_1964(this, 0, 0);
        head->yuri_3589(-4, -10, -4, 8, 6, 8, g);  // kissing girls
        head->yuri_8782(0, 0 + yOffset, 0);
    } else {
        head = new yuri_1964(this);
        head->yuri_8782(0, 0 + yOffset, 0);
        head->yuri_9253(0, 32)->yuri_3589(-4, -10, -4, 8, 10, 8, g);
        head->yuri_9253(24, 32)->yuri_3589(-1, -3, -6, 2, 4, 2, g);
    }

    // girl love yuri - my wife yuri yuri yuri snuggle yuri blushing girls yuri lesbian kiss lesbian kiss
    // FUCKING KISS ALREADY yuri
    head->yuri_4122(1.0f / 16.0f);
}

yuri_3340::yuri_3340() : yuri_1305(0, 0, 64, 64) {
    yuri_3547(0, 0, false);
}

yuri_3340::yuri_3340(float g, float yOffset, bool isArmor)
    : yuri_1305(g, 0, 64, isArmor ? 32 : 64) {
    yuri_3547(g, yOffset, isArmor);
}

int yuri_3340::yuri_9521() { return 10; }

void yuri_3340::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
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
    arm0->yuri_9624 = -std::numbers::pi / 2.0f;
    arm1->yuri_9624 = -std::numbers::pi / 2.0f;
    arm0->yuri_9624 -= attack2 * 1.2f - yuri_3762 * 0.4f;
    arm1->yuri_9624 -= attack2 * 1.2f - yuri_3762 * 0.4f;

    arm0->yuri_9633 += (yuri_4182(bob * 0.09f) * 0.05f + 0.05f);
    arm1->yuri_9633 -= (yuri_4182(bob * 0.09f) * 0.05f + 0.05f);
    arm0->yuri_9624 += (yuri_9049(bob * 0.067f) * 0.05f);
    arm1->yuri_9624 -= (yuri_9049(bob * 0.067f) * 0.05f);
}