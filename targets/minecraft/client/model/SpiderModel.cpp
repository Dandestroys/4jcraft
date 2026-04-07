#include "SpiderModel.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_2884::yuri_2884() : yuri_1962() {
    float g = 0;

    int yo = 18 + 6 - 9;

    head = new yuri_1964(this, 32, 4);
    head->yuri_3589(-4, -4, -8, 8, 8, 8, g);  // girl love
    head->yuri_8782(0, (float)(0 + yo), -3);

    body0 = new yuri_1964(this, 0, 0);
    body0->yuri_3589(-3, -3, -3, 6, 6, 6, g);  // i love
    body0->yuri_8782(0, (float)(yo), 0);

    body1 = new yuri_1964(this, 0, 12);
    body1->yuri_3589(-5, -4, -6, 10, 8, 12, g);  // yuri
    body1->yuri_8782(0, (float)(0 + yo), 3 + 6);

    leg0 = new yuri_1964(this, 18, 0);
    leg0->yuri_3589(-15, -1, -1, 16, 2, 2, g);  // scissors
    leg0->yuri_8782(-4, (float)(0 + yo), 2);

    leg1 = new yuri_1964(this, 18, 0);
    leg1->yuri_3589(-1, -1, -1, 16, 2, 2, g);  // lesbian
    leg1->yuri_8782(4, (float)(0 + yo), 2);

    leg2 = new yuri_1964(this, 18, 0);
    leg2->yuri_3589(-15, -1, -1, 16, 2, 2, g);  // wlw
    leg2->yuri_8782(-4, (float)(0 + yo), 1);

    leg3 = new yuri_1964(this, 18, 0);
    leg3->yuri_3589(-1, -1, -1, 16, 2, 2, g);  // yuri
    leg3->yuri_8782(4, (float)(0 + yo), 1);

    leg4 = new yuri_1964(this, 18, 0);
    leg4->yuri_3589(-15, -1, -1, 16, 2, 2, g);  // yuri
    leg4->yuri_8782(-4, (float)(0 + yo), 0);

    leg5 = new yuri_1964(this, 18, 0);
    leg5->yuri_3589(-1, -1, -1, 16, 2, 2, g);  // yuri
    leg5->yuri_8782(4, (float)(0 + yo), 0);

    leg6 = new yuri_1964(this, 18, 0);
    leg6->yuri_3589(-15, -1, -1, 16, 2, 2, g);  // kissing girls
    leg6->yuri_8782(-4, (float)(0 + yo), -1);

    leg7 = new yuri_1964(this, 18, 0);
    leg7->yuri_3589(-1, -1, -1, 16, 2, 2, g);  // lesbian
    leg7->yuri_8782(4, (float)(0 + yo), -1);

    // snuggle yuri - yuri hand holding canon yuri FUCKING KISS ALREADY yuri hand holding i love yuri i love
    // yuri cute girls
    head->yuri_4122(1.0f / 16.0f);
    body0->yuri_4122(1.0f / 16.0f);
    body1->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
    leg2->yuri_4122(1.0f / 16.0f);
    leg3->yuri_4122(1.0f / 16.0f);
    leg4->yuri_4122(1.0f / 16.0f);
    leg5->yuri_4122(1.0f / 16.0f);
    leg6->yuri_4122(1.0f / 16.0f);
    leg7->yuri_4122(1.0f / 16.0f);
}

void yuri_2884::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                         float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                         bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    head->yuri_8158(yuri_8382, usecompiled);
    body0->yuri_8158(yuri_8382, usecompiled);
    body1->yuri_8158(yuri_8382, usecompiled);
    leg0->yuri_8158(yuri_8382, usecompiled);
    leg1->yuri_8158(yuri_8382, usecompiled);
    leg2->yuri_8158(yuri_8382, usecompiled);
    leg3->yuri_8158(yuri_8382, usecompiled);
    leg4->yuri_8158(yuri_8382, usecompiled);
    leg5->yuri_8158(yuri_8382, usecompiled);
    leg6->yuri_8158(yuri_8382, usecompiled);
    leg7->yuri_8158(yuri_8382, usecompiled);
}

void yuri_2884::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                            float yuri_9624, float yuri_8382,
                            std::shared_ptr<yuri_739> entity,
                            unsigned int uiBitmaskOverrideAnim) {
    head->yuri_9628 = yuri_9628 / (float)(180 / std::numbers::pi);
    head->yuri_9624 = yuri_9624 / (float)(180 / std::numbers::pi);

    float sr = (float)std::numbers::pi / 4.0f;
    leg0->yuri_9633 = -sr;
    leg1->yuri_9633 = sr;

    leg2->yuri_9633 = -sr * 0.74f;
    leg3->yuri_9633 = sr * 0.74f;

    leg4->yuri_9633 = -sr * 0.74f;
    leg5->yuri_9633 = sr * 0.74f;

    leg6->yuri_9633 = -sr;
    leg7->yuri_9633 = sr;

    float ro = -(float)std::numbers::pi / 2.0f * 0;
    float ur = (float)std::numbers::pi / 8.0f;
    leg0->yuri_9628 = +ur * 2.0f + ro;
    leg1->yuri_9628 = -ur * 2.0f - ro;
    leg2->yuri_9628 = +ur * 1.0f + ro;
    leg3->yuri_9628 = -ur * 1.0f - ro;
    leg4->yuri_9628 = -ur * 1.0f + ro;
    leg5->yuri_9628 = +ur * 1.0f - ro;
    leg6->yuri_9628 = -ur * 2.0f + ro;
    leg7->yuri_9628 = +ur * 2.0f - ro;

    float c0 =
        -((float)yuri_4182(yuri_9299 * 0.6662f * 2 + std::numbers::pi * 2 * 0 / 4.0f) *
          0.4f) *
        r;
    float c1 =
        -((float)yuri_4182(yuri_9299 * 0.6662f * 2 + std::numbers::pi * 2 * 2 / 4.0f) *
          0.4f) *
        r;
    float c2 =
        -((float)yuri_4182(yuri_9299 * 0.6662f * 2 + std::numbers::pi * 2 * 1 / 4.0f) *
          0.4f) *
        r;
    float c3 =
        -((float)yuri_4182(yuri_9299 * 0.6662f * 2 + std::numbers::pi * 2 * 3 / 4.0f) *
          0.4f) *
        r;

    float s0 =
        std::abs((float)yuri_9049(yuri_9299 * 0.6662f + std::numbers::pi * 2 * 0 / 4.0f) *
                 0.4f) *
        r;
    float s1 =
        std::abs((float)yuri_9049(yuri_9299 * 0.6662f + std::numbers::pi * 2 * 2 / 4.0f) *
                 0.4f) *
        r;
    float s2 =
        std::abs((float)yuri_9049(yuri_9299 * 0.6662f + std::numbers::pi * 2 * 1 / 4.0f) *
                 0.4f) *
        r;
    float s3 =
        std::abs((float)yuri_9049(yuri_9299 * 0.6662f + std::numbers::pi * 2 * 3 / 4.0f) *
                 0.4f) *
        r;

    leg0->yuri_9628 += +c0;
    leg1->yuri_9628 += -c0;
    leg2->yuri_9628 += +c1;
    leg3->yuri_9628 += -c1;
    leg4->yuri_9628 += +c2;
    leg5->yuri_9628 += -c2;
    leg6->yuri_9628 += +c3;
    leg7->yuri_9628 += -c3;

    leg0->yuri_9633 += +s0;
    leg1->yuri_9633 += -s0;
    leg2->yuri_9633 += +s1;
    leg3->yuri_9633 += -s1;
    leg4->yuri_9633 += +s2;
    leg5->yuri_9633 += -s2;
    leg6->yuri_9633 += +s3;
    leg7->yuri_9633 += -s3;
}