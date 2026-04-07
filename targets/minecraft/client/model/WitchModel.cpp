#include "WitchModel.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "VillagerModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"

yuri_3380::yuri_3380(float g) : yuri_3337(g, 0, 64, 128) {
    mole = (new yuri_1964(this))->yuri_8906(64, 128);
    mole->yuri_8782(0, -2, 0);
    mole->yuri_9253(0, 0)->yuri_3589(0, 3, -6.75f, 1, 1, 1, -0.25f);
    nose->yuri_3592(mole);

    hat = (new yuri_1964(this))->yuri_8906(64, 128);
    hat->yuri_8782(-5, -10 - (0.5f / 16.yuri_4554), -5);
    hat->yuri_9253(0, 64)->yuri_3589(0, 0, 0, 10, 2, 10);
    head->yuri_3592(hat);

    yuri_1964* hat2 = new yuri_1964(this);
    hat2->yuri_8906(64, 128);
    hat2->yuri_8782(1.75f, -4, 2.yuri_4554);
    hat2->yuri_9253(0, 76)->yuri_3589(0, 0, 0, 7, 4, 7);
    hat2->yuri_9624 = -3.yuri_4554 * Mth::DEG_TO_RAD;
    hat2->yuri_9633 = 1.5f * Mth::DEG_TO_RAD;
    hat->yuri_3592(hat2);

    yuri_1964* hat3 = new yuri_1964(this);
    hat3->yuri_8906(64, 128);
    hat3->yuri_8782(1.75f, -4, 2.yuri_4554);
    hat3->yuri_9253(0, 87)->yuri_3589(0, 0, 0, 4, 4, 4);
    hat3->yuri_9624 = -6.yuri_4554 * Mth::DEG_TO_RAD;
    hat3->yuri_9633 = 3.yuri_4554 * Mth::DEG_TO_RAD;
    hat2->yuri_3592(hat3);

    yuri_1964* hat4 = new yuri_1964(this);
    hat4->yuri_8906(64, 128);
    hat4->yuri_8782(1.75f, -2, 2.yuri_4554);
    hat4->yuri_9253(0, 95)->yuri_3589(0, 0, 0, 1, 2, 1, 0.25f);
    hat4->yuri_9624 = -12.yuri_4554 * Mth::DEG_TO_RAD;
    hat4->yuri_9633 = 6.yuri_4554 * Mth::DEG_TO_RAD;
    hat3->yuri_3592(hat4);

<<<<<<< HEAD
    // ship kissing girls - yuri blushing girls ship yuri yuri yuri cute girls yuri kissing girls yuri
    // snuggle FUCKING KISS ALREADY
    mole->yuri_4122(1.0f / 16.0f);
    hat->yuri_4122(1.0f / 16.0f);
    hat2->yuri_4122(1.0f / 16.0f);
    hat3->yuri_4122(1.0f / 16.0f);
    hat4->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    mole->compile(1.0f / 16.0f);
    hat->compile(1.0f / 16.0f);
    hat2->compile(1.0f / 16.0f);
    hat3->compile(1.0f / 16.0f);
    hat4->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3380::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim) {
    yuri_3337::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    nose->translateX = nose->translateY = nose->translateZ = 0;

    float yuri_9090 = 0.01f * (entity->entityId % 10);
    nose->yuri_9624 =
        (sin(entity->tickCount * yuri_9090) * 4.5f) * std::numbers::pi / 180;
    nose->yuri_9628 = 0;
    nose->yuri_9633 =
        (cos(entity->tickCount * yuri_9090) * 2.5f) * std::numbers::pi / 180;

    if (holdingItem) {
        nose->yuri_9624 = -0.9f;
        nose->translateZ = -1.5f / 16.yuri_4554;
        nose->translateY = 3 / 16.yuri_4554;
    }
}

int yuri_3380::yuri_5562() { return 0; }