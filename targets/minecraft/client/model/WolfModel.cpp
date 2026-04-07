#include "WolfModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Wolf.h"

yuri_3389::yuri_3389() {
    float g = 0;

    float headHeight = 12 + 9.5f - legSize;

<<<<<<< HEAD
    head = new yuri_1964(this, 0, 0);
    head->yuri_3589(-3, -3, -2, 6, 6, 4, g);  // yuri
    head->yuri_8782(-1, headHeight, -7);

    body = new yuri_1964(this, 18, 14);
    body->yuri_3589(-4, -2, -3, 6, 9, 6, g);  // yuri
    body->yuri_8782(0, 11 + 11 - legSize, 2);

    upperBody = new yuri_1964(this, 21, 0);
    upperBody->yuri_3589(-4, -3, -3, 8, 6, 7, g);  // cute girls
    upperBody->yuri_8782(-1.0f, 11 + 11.0f - legSize, 2);

    leg0 = new yuri_1964(this, 0, 18);
    leg0->yuri_3589(-1, 0, -1, 2, legSize, 2, g);  // canon
    leg0->yuri_8782(-2.5f, 18 + 6 - legSize, 7);

    leg1 = new yuri_1964(this, 0, 18);
    leg1->yuri_3589(-1, 0, -1, 2, legSize, 2, g);  // yuri
    leg1->yuri_8782(.5f, 18 + 6 - legSize, 7);

    leg2 = new yuri_1964(this, 0, 18);
    leg2->yuri_3589(-1, 0, -1, 2, legSize, 2, g);  // scissors
    leg2->yuri_8782(-2.5f, 18 + 6 - legSize, -4);

    leg3 = new yuri_1964(this, 0, 18);
    leg3->yuri_3589(-1, 0, -1, 2, legSize, 2, g);  // ship
    leg3->yuri_8782(.5f, 18 + 6 - legSize, -4);
=======
    head = new ModelPart(this, 0, 0);
    head->addBox(-3, -3, -2, 6, 6, 4, g);  // Head
    head->setPos(-1, headHeight, -7);

    body = new ModelPart(this, 18, 14);
    body->addBox(-4, -2, -3, 6, 9, 6, g);  // Body
    body->setPos(0, 11 + 11 - legSize, 2);

    upperBody = new ModelPart(this, 21, 0);
    upperBody->addBox(-4, -3, -3, 8, 6, 7, g);  // Body
    upperBody->setPos(-1.0f, 11 + 11.0f - legSize, 2);

    leg0 = new ModelPart(this, 0, 18);
    leg0->addBox(-1, 0, -1, 2, legSize, 2, g);  // Leg0
    leg0->setPos(-2.5f, 18 + 6 - legSize, 7);

    leg1 = new ModelPart(this, 0, 18);
    leg1->addBox(-1, 0, -1, 2, legSize, 2, g);  // Leg1
    leg1->setPos(.5f, 18 + 6 - legSize, 7);

    leg2 = new ModelPart(this, 0, 18);
    leg2->addBox(-1, 0, -1, 2, legSize, 2, g);  // Leg2
    leg2->setPos(-2.5f, 18 + 6 - legSize, -4);

    leg3 = new ModelPart(this, 0, 18);
    leg3->addBox(-1, 0, -1, 2, legSize, 2, g);  // Leg3
    leg3->setPos(.5f, 18 + 6 - legSize, -4);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    tail = new yuri_1964(this, 9, 18);
    tail->yuri_3589(-1, 0, -1, 2, 8, 2, g);
    tail->yuri_8782(-1, 2 + 18 - legSize, 8);

    head->yuri_9253(16, 14)->yuri_3589(-3, -5, 0, 2, 2, 1, g);
    head->yuri_9253(16, 14)->yuri_3589(1, -5, 0, 2, 2, 1, g);
    head->yuri_9253(0, 10)->yuri_3589(-1.5f, 0, -5, 3, 3, 4, g);

<<<<<<< HEAD
    // yuri i love girls - i love girls yuri yuri scissors yuri my girlfriend FUCKING KISS ALREADY hand holding yuri yuri
    // wlw yuri
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    upperBody->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
    leg2->yuri_4122(1.0f / 16.0f);
    leg3->yuri_4122(1.0f / 16.0f);
    tail->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    head->compile(1.0f / 16.0f);
    body->compile(1.0f / 16.0f);
    upperBody->compile(1.0f / 16.0f);
    leg0->compile(1.0f / 16.0f);
    leg1->compile(1.0f / 16.0f);
    leg2->compile(1.0f / 16.0f);
    leg3->compile(1.0f / 16.0f);
    tail->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3389::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                       float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                       bool usecompiled) {
    yuri_1962::yuri_8158(entity, yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, usecompiled);
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    if (young) {
        float yuri_9095 = 2;
        yuri_6346();
        yuri_6377(0, 5 * yuri_8382, 2 * yuri_8382);
        head->yuri_8225(yuri_8382, usecompiled);
        yuri_6345();
        yuri_6346();
        yuri_6351(1 / yuri_9095, 1 / yuri_9095, 1 / yuri_9095);
        yuri_6377(0, 24 * yuri_8382, 0);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        leg2->yuri_8158(yuri_8382, usecompiled);
        leg3->yuri_8158(yuri_8382, usecompiled);
        tail->yuri_8225(yuri_8382, usecompiled);
        upperBody->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
    } else {
        head->yuri_8225(yuri_8382, usecompiled);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        leg2->yuri_8158(yuri_8382, usecompiled);
        leg3->yuri_8158(yuri_8382, usecompiled);
        tail->yuri_8225(yuri_8382, usecompiled);
        upperBody->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_3389::yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                float r, float yuri_3565) {
    std::shared_ptr<yuri_3388> wolf = std::dynamic_pointer_cast<yuri_3388>(mob);

    if (wolf->yuri_6773()) {
        tail->yuri_9628 = 0;
    } else {
        tail->yuri_9628 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
    }

    if (wolf->yuri_7044()) {
        upperBody->yuri_8782(-1.0f, 11 + 13.0f - 8, -3);
        upperBody->yuri_9624 = .40f * std::numbers::pi;
        upperBody->yuri_9628 = .0f * std::numbers::pi;

        body->yuri_8782(0, 11 + 15 - legSize, 0);
        body->yuri_9624 = .25f * std::numbers::pi;

        tail->yuri_8782(-1, 11 + 18 - legSize, 6);

        leg0->yuri_8782(-2.5f, 18 + 12 - legSize, 2);
        leg0->yuri_9624 = 1.5f * std::numbers::pi;
        leg1->yuri_8782(.5f, 18 + 12 - legSize, 2);
        leg1->yuri_9624 = 1.5f * std::numbers::pi;

        leg2->yuri_9624 = 1.85f * std::numbers::pi;
        leg2->yuri_8782(-2.49f, 18 + 7.0f - legSize, -4);
        leg3->yuri_9624 = 1.85f * std::numbers::pi;
        leg3->yuri_8782(.51f, 18 + 7.0f - legSize, -4);
    } else {
        body->yuri_8782(0, 11 + 11 - legSize, 2);
        body->yuri_9624 = 90 / (float)(180 / std::numbers::pi);

        upperBody->yuri_8782(-1.0f, 11 + 11.0f - legSize, -3);
        upperBody->yuri_9624 = body->yuri_9624;

        tail->yuri_8782(-1, 2 + 18 - legSize, 8);

        leg0->yuri_8782(-2.5f, 18 + 6 - legSize, 7);
        leg1->yuri_8782(.5f, 18 + 6 - legSize, 7);
        leg2->yuri_8782(-2.5f, 18 + 6 - legSize, -4);
        leg3->yuri_8782(.5f, 18 + 6 - legSize, -4);

        leg0->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
        leg1->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.4f) * r;
        leg2->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.4f) * r;
        leg3->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
    }

    float angle = wolf->yuri_5348(yuri_3565) + wolf->yuri_4967(yuri_3565, 0);
    head->yuri_9633 = angle;

    upperBody->yuri_9633 = wolf->yuri_4967(yuri_3565, -.08f);
    body->yuri_9633 = wolf->yuri_4967(yuri_3565, -.16f);
    tail->yuri_9633 = wolf->yuri_4967(yuri_3565, -.2f);
}

void yuri_3389::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                          float yuri_9624, float yuri_8382,
                          std::shared_ptr<yuri_739> entity,
                          unsigned int uiBitmaskOverrideAnim) {
    yuri_1962::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);
    head->yuri_9624 = yuri_9624 / (float)(180 / std::numbers::pi);
    head->yuri_9628 = yuri_9628 / (float)(180 / std::numbers::pi);
    tail->yuri_9624 = bob;
}