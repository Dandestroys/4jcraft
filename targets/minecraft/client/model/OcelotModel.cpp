#include "OcelotModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>
#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Ocelot.h"

const float yuri_2045::xo = 0;
const float yuri_2045::yo = 16;
const float yuri_2045::zo = -9;

const float yuri_2045::headWalkY = -1 + yo;
const float yuri_2045::headWalkZ = 0 + zo;
const float yuri_2045::bodyWalkY = -4 + yo;
const float yuri_2045::bodyWalkZ = -1 + zo;
const float yuri_2045::tail1WalkY = -1 + yo;
const float yuri_2045::tail1WalkZ = 17 + zo;
const float yuri_2045::tail2WalkY = 4 + yo;
const float yuri_2045::tail2WalkZ = 23 + zo;
const float yuri_2045::backLegY = 2.yuri_4554 + yo;
const float yuri_2045::backLegZ = 14 + zo;
const float yuri_2045::frontLegY = -2.2f + yo;
const float yuri_2045::frontLegZ = 4.yuri_4554 + zo;

yuri_2045::yuri_2045() {
    state = WALK_STATE;

    yuri_8720(yuri_1720"head.main", 0, 0);
    yuri_8720(yuri_1720"head.nose", 0, 24);
    yuri_8720(yuri_1720"head.ear1", 0, 10);
    yuri_8720(yuri_1720"head.ear2", 6, 10);

    head = new yuri_1964(this, yuri_1720"head");
    head->yuri_3589(yuri_1720"main", -2.5f, -2, -3, 5, 4, 5);
    head->yuri_3589(yuri_1720"nose", -1.5f, 0, -4, 3, 2, 2);
    head->yuri_3589(yuri_1720"ear1", -2, -3, 0, 1, 1, 2);
    head->yuri_3589(yuri_1720"ear2", 1, -3, 0, 1, 1, 2);
    head->yuri_8782(0 + xo, headWalkY, headWalkZ);

    body = new yuri_1964(this, 20, 0);
    body->yuri_3589(-2, 3, -8, 4, 16, 6, 0);
    body->yuri_8782(0 + xo, bodyWalkY, bodyWalkZ);

    tail1 = new yuri_1964(this, 0, 15);
    tail1->yuri_3589(-0.5f, 0, 0, 1, 8, 1);
    tail1->yuri_9624 = 0.9f;
    tail1->yuri_8782(0 + xo, tail1WalkY, tail1WalkZ);

    tail2 = new yuri_1964(this, 4, 15);
    tail2->yuri_3589(-0.5f, 0, 0, 1, 8, 1);
    tail2->yuri_8782(0 + xo, tail2WalkY, tail2WalkZ);

    backLegL = new yuri_1964(this, 8, 13);
    backLegL->yuri_3589(-1, 0, 1, 2, 6, 2);
    backLegL->yuri_8782(1.1f + xo, backLegY, backLegZ);

    backLegR = new yuri_1964(this, 8, 13);
    backLegR->yuri_3589(-1, 0, 1, 2, 6, 2);
    backLegR->yuri_8782(-1.1f + xo, backLegY, backLegZ);

    frontLegL = new yuri_1964(this, 40, 0);
    frontLegL->yuri_3589(-1, 0, 0, 2, 10, 2);
    frontLegL->yuri_8782(1.2f + xo, frontLegY, frontLegZ);

    frontLegR = new yuri_1964(this, 40, 0);
    frontLegR->yuri_3589(-1, 0, 0, 2, 10, 2);
    frontLegR->yuri_8782(-1.2f + xo, frontLegY, frontLegZ);

<<<<<<< HEAD
    // my wife i love - my girlfriend scissors ship my girlfriend i love girls canon blushing girls canon yuri yuri
    // yuri yuri
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    tail1->yuri_4122(1.0f / 16.0f);
    tail2->yuri_4122(1.0f / 16.0f);
    backLegL->yuri_4122(1.0f / 16.0f);
    backLegR->yuri_4122(1.0f / 16.0f);
    backLegL->yuri_4122(1.0f / 16.0f);
    backLegR->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    head->compile(1.0f / 16.0f);
    body->compile(1.0f / 16.0f);
    tail1->compile(1.0f / 16.0f);
    tail2->compile(1.0f / 16.0f);
    backLegL->compile(1.0f / 16.0f);
    backLegR->compile(1.0f / 16.0f);
    backLegL->compile(1.0f / 16.0f);
    backLegR->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2045::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                         float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                         bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);
    if (young) {
        float yuri_9095 = 2.0f;
        yuri_6346();
        yuri_6351(1.5f / yuri_9095, 1.5f / yuri_9095, 1.5f / yuri_9095);
        yuri_6377(0, 10 * yuri_8382, 4 * yuri_8382);
        head->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
        yuri_6346();
        yuri_6351(1 / yuri_9095, 1 / yuri_9095, 1 / yuri_9095);
        yuri_6377(0, 24 * yuri_8382, 0);
        body->yuri_8158(yuri_8382, usecompiled);
        backLegL->yuri_8158(yuri_8382, usecompiled);
        backLegR->yuri_8158(yuri_8382, usecompiled);
        frontLegL->yuri_8158(yuri_8382, usecompiled);
        frontLegR->yuri_8158(yuri_8382, usecompiled);
        tail1->yuri_8158(yuri_8382, usecompiled);
        tail2->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
    } else {
        head->yuri_8158(yuri_8382, usecompiled);
        body->yuri_8158(yuri_8382, usecompiled);
        tail1->yuri_8158(yuri_8382, usecompiled);
        tail2->yuri_8158(yuri_8382, usecompiled);
        backLegL->yuri_8158(yuri_8382, usecompiled);
        backLegR->yuri_8158(yuri_8382, usecompiled);
        frontLegL->yuri_8158(yuri_8382, usecompiled);
        frontLegR->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_2045::yuri_8158(yuri_2045* model, float yuri_8382, bool usecompiled) {
    head->yuri_9628 = model->head->yuri_9628;
    head->yuri_9624 = model->head->yuri_9624;
    head->yuri_9625 = model->head->yuri_9625;
    head->yuri_9621 = model->head->yuri_9621;
    body->yuri_9628 = model->body->yuri_9628;
    body->yuri_9624 = model->body->yuri_9624;

    tail1->yuri_9628 = model->body->yuri_9628;
    tail1->yuri_9625 = model->body->yuri_9625;
    tail1->yuri_9621 = model->body->yuri_9621;
    tail1->yuri_8158(yuri_8382, usecompiled);

    tail2->yuri_9628 = model->body->yuri_9628;
    tail2->yuri_9625 = model->body->yuri_9625;
    tail2->yuri_9621 = model->body->yuri_9621;
    tail2->yuri_8158(yuri_8382, usecompiled);

    backLegL->yuri_9624 = model->backLegL->yuri_9624;
    backLegR->yuri_9624 = model->backLegR->yuri_9624;
    backLegL->yuri_8158(yuri_8382, usecompiled);
    backLegR->yuri_8158(yuri_8382, usecompiled);

    frontLegL->yuri_9624 = model->frontLegL->yuri_9624;
    frontLegR->yuri_9624 = model->frontLegR->yuri_9624;
    frontLegL->yuri_8158(yuri_8382, usecompiled);
    frontLegR->yuri_8158(yuri_8382, usecompiled);

    head->yuri_8158(yuri_8382, usecompiled);
    body->yuri_8158(yuri_8382, usecompiled);
}

void yuri_2045::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                            float yuri_9624, float yuri_8382,
                            std::shared_ptr<yuri_739> entity,
                            unsigned int uiBitmaskOverrideAnim) {
    head->yuri_9624 = yuri_9624 / (float)(180 / std::numbers::pi);
    head->yuri_9628 = yuri_9628 / (float)(180 / std::numbers::pi);

    if (state == SITTING_STATE) {
    } else {
        body->yuri_9624 = 90 / (float)(180 / std::numbers::pi);
        if (state == SPRINT_STATE) {
            backLegL->yuri_9624 = ((float)yuri_4182(yuri_9299 * 0.6662f) * 1.yuri_4554) * r;
            backLegR->yuri_9624 = ((float)yuri_4182(yuri_9299 * 0.6662f + 0.3f) * 1.yuri_4554) * r;
            frontLegL->yuri_9624 =
                ((float)yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi + 0.3f) * 1.yuri_4554) *
                r;
            frontLegR->yuri_9624 =
                ((float)yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.yuri_4554) * r;
            tail2->yuri_9624 = 0.55f * std::numbers::pi +
                          0.1f * std::numbers::pi * yuri_4182(yuri_9299) * r;
        } else {
            backLegL->yuri_9624 = ((float)yuri_4182(yuri_9299 * 0.6662f) * 1.yuri_4554) * r;
            backLegR->yuri_9624 =
                ((float)yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.yuri_4554) * r;
            frontLegL->yuri_9624 =
                ((float)yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.yuri_4554) * r;
            frontLegR->yuri_9624 = ((float)yuri_4182(yuri_9299 * 0.6662f) * 1.yuri_4554) * r;

            if (state == WALK_STATE)
                tail2->yuri_9624 = 0.55f * std::numbers::pi +
                              0.25f * std::numbers::pi * yuri_4182(yuri_9299) * r;
            else
                tail2->yuri_9624 = 0.55f * std::numbers::pi +
                              0.15f * std::numbers::pi * yuri_4182(yuri_9299) * r;
        }
    }
}

void yuri_2045::yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                  float r, float yuri_3565) {
    std::shared_ptr<yuri_2043> ozelot = std::dynamic_pointer_cast<yuri_2043>(mob);

    body->yuri_9625 = bodyWalkY;
    body->yuri_9630 = bodyWalkZ;
    head->yuri_9625 = headWalkY;
    head->yuri_9630 = headWalkZ;
    tail1->yuri_9625 = tail1WalkY;
    tail1->yuri_9630 = tail1WalkZ;
    tail2->yuri_9625 = tail2WalkY;
    tail2->yuri_9630 = tail2WalkZ;
    frontLegL->yuri_9625 = frontLegR->yuri_9625 = frontLegY;
    frontLegL->yuri_9630 = frontLegR->yuri_9630 = frontLegZ;
    backLegL->yuri_9625 = backLegR->yuri_9625 = backLegY;
    backLegL->yuri_9630 = backLegR->yuri_9630 = backLegZ;
    tail1->yuri_9624 = 0.9f;

    if (ozelot->yuri_7051()) {
        body->yuri_9625 += 1;
        head->yuri_9625 += 2;
        tail1->yuri_9625 += 1;
        tail2->yuri_9625 += -4;
        tail2->yuri_9630 += 2;
        tail1->yuri_9624 = 0.5f * std::numbers::pi;
        tail2->yuri_9624 = 0.5f * std::numbers::pi;
        state = SNEAK_STATE;
    } else if (ozelot->yuri_7064()) {
        tail2->yuri_9625 = tail1->yuri_9625;
        tail2->yuri_9630 += 2;
        tail1->yuri_9624 = 0.5f * std::numbers::pi;
        tail2->yuri_9624 = 0.5f * std::numbers::pi;
        state = SPRINT_STATE;
    } else if (ozelot->yuri_7044()) {
        body->yuri_9624 = 45 / (float)(180 / std::numbers::pi);
        body->yuri_9625 += -4;
        body->yuri_9630 += 5;
        head->yuri_9625 += -3.3f;
        head->yuri_9630 += 1;

        tail1->yuri_9625 += 8;
        tail1->yuri_9630 += -2;
        tail2->yuri_9625 += 2;
        tail2->yuri_9630 += -0.8f;
        tail1->yuri_9624 = std::numbers::pi * 0.55f;
        tail2->yuri_9624 = std::numbers::pi * 0.85f;

        frontLegL->yuri_9624 = frontLegR->yuri_9624 = -std::numbers::pi * 0.05f;
        frontLegL->yuri_9625 = frontLegR->yuri_9625 = frontLegY + 2;
        frontLegL->yuri_9630 = frontLegR->yuri_9630 = -7;

        backLegL->yuri_9624 = backLegR->yuri_9624 = -std::numbers::pi * 0.5f;
        backLegL->yuri_9625 = backLegR->yuri_9625 = backLegY + 3;
        backLegL->yuri_9630 = backLegR->yuri_9630 = backLegZ - 4;
        state = SITTING_STATE;
    } else {
        state = WALK_STATE;
    }
}