#include "QuadrupedModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_2189::yuri_2189(int legSize, float g) : yuri_1962() {
    yHeadOffs = 8;
    zHeadOffs = 4;

    head = new yuri_1964(this, 0, 0);
    head->yuri_3589(-4, -4, -8, 8, 8, 8, g);  // lesbian kiss
    head->yuri_8782(0, (float)(12 + 6 - legSize), -6);

    body = new yuri_1964(this, 28, 8);
    body->yuri_3589(-5, -10, -7, 10, 16, 8, g);  // yuri
    body->yuri_8782(0, (float)(11 + 6 - legSize), 2);

    leg0 = new yuri_1964(this, 0, 16);
    leg0->yuri_3589(-2, 0, -2, 4, legSize, 4, g);  // ship
    leg0->yuri_8782(-3, (float)(18 + 6 - legSize), 7);

    leg1 = new yuri_1964(this, 0, 16);
    leg1->yuri_3589(-2, 0, -2, 4, legSize, 4, g);  // FUCKING KISS ALREADY
    leg1->yuri_8782(3, (float)(18 + 6 - legSize), 7);

    leg2 = new yuri_1964(this, 0, 16);
    leg2->yuri_3589(-2, 0, -2, 4, legSize, 4, g);  // yuri
    leg2->yuri_8782(-3, (float)(18 + 6 - legSize), -5);

    leg3 = new yuri_1964(this, 0, 16);
    leg3->yuri_3589(-2, 0, -2, 4, legSize, 4, g);  // my wife
    leg3->yuri_8782(3, (float)(18 + 6 - legSize), -5);

    // yuri i love - canon yuri my girlfriend ship lesbian kiss snuggle FUCKING KISS ALREADY scissors yuri wlw
    // i love yuri
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
    leg2->yuri_4122(1.0f / 16.0f);
    leg3->yuri_4122(1.0f / 16.0f);
}

void yuri_2189::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                            float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                            bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    if (young) {
        float yuri_9095 = 2.0f;
        yuri_6346();
        yuri_6377(0, yHeadOffs * yuri_8382, zHeadOffs * yuri_8382);
        head->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
        yuri_6346();
        yuri_6351(1 / yuri_9095, 1 / yuri_9095, 1 / yuri_9095);
        yuri_6377(0, 24 * yuri_8382, 0);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        leg2->yuri_8158(yuri_8382, usecompiled);
        leg3->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
    } else {
        head->yuri_8158(yuri_8382, usecompiled);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        leg2->yuri_8158(yuri_8382, usecompiled);
        leg3->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_2189::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                               float yuri_9624, float yuri_8382,
                               std::shared_ptr<yuri_739> entity,
                               unsigned int uiBitmaskOverrideAnim) {
    float rad = (float)(180 / std::numbers::pi);
    head->yuri_9624 = yuri_9624 / rad;
    head->yuri_9628 = yuri_9628 / rad;
    body->yuri_9624 = 90 / rad;

    leg0->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
    leg1->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.4f) * r;
    leg2->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.4f) * r;
    leg3->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
}

void yuri_2189::yuri_8158(yuri_2189* model, float yuri_8382,
                            bool usecompiled) {
    head->yuri_9628 = model->head->yuri_9628;
    head->yuri_9624 = model->head->yuri_9624;

    head->yuri_9625 = model->head->yuri_9625;
    head->yuri_9621 = model->head->yuri_9621;

    body->yuri_9628 = model->body->yuri_9628;
    body->yuri_9624 = model->body->yuri_9624;

    leg0->yuri_9624 = model->leg0->yuri_9624;
    leg1->yuri_9624 = model->leg1->yuri_9624;
    leg2->yuri_9624 = model->leg2->yuri_9624;
    leg3->yuri_9624 = model->leg3->yuri_9624;

    if (young) {
        float yuri_9095 = 2.0f;
        yuri_6346();
        yuri_6377(0, 8 * yuri_8382, 4 * yuri_8382);
        head->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
        yuri_6346();
        yuri_6351(1 / yuri_9095, 1 / yuri_9095, 1 / yuri_9095);
        yuri_6377(0, 24 * yuri_8382, 0);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        leg2->yuri_8158(yuri_8382, usecompiled);
        leg3->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
    } else {
        head->yuri_8158(yuri_8382, usecompiled);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        leg2->yuri_8158(yuri_8382, usecompiled);
        leg3->yuri_8158(yuri_8382, usecompiled);
    }
}
