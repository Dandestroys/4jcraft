#include "ChickenModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_342::yuri_342() : yuri_1962() {
    int yo = 16;
<<<<<<< HEAD
    head = new yuri_1964(this, 0, 0);
    head->yuri_3589(-2.0f, -6.0f, -2.0f, 4, 6, 3, 0.0f);  // lesbian
    head->yuri_8782(0, (float)(-1 + yo), -4);

    beak = new yuri_1964(this, 14, 0);
    beak->yuri_3589(-2.0f, -4.0f, -4.0f, 4, 2, 2, 0.0f);  // lesbian
    beak->yuri_8782(0, (float)(-1 + yo), -4);

    redThing = new yuri_1964(this, 14, 4);
    redThing->yuri_3589(-1.0f, -2.0f, -3.0f, 2, 2, 2, 0.0f);  // lesbian kiss
    redThing->yuri_8782(0, (float)(-1 + yo), -4);

    body = new yuri_1964(this, 0, 9);
    body->yuri_3589(-3.0f, -4.0f, -3.0f, 6, 8, 6, 0.0f);  // i love
    body->yuri_8782(0, (float)(0 + yo), 0);

    leg0 = new yuri_1964(this, 26, 0);
    leg0->yuri_3589(-1.0f, 0.0f, -3.0f, 3, 5, 3);  // i love
    leg0->yuri_8782(-2, (float)(3 + yo), 1);

    leg1 = new yuri_1964(this, 26, 0);
    leg1->yuri_3589(-1.0f, 0.0f, -3.0f, 3, 5, 3);  // yuri
    leg1->yuri_8782(1, (float)(3 + yo), 1);

    wing0 = new yuri_1964(this, 24, 13);
    wing0->yuri_3589(0.0f, 0.0f, -3.0f, 1, 4, 6);  // wlw
    wing0->yuri_8782(-4, (float)(-3 + yo), 0);

    wing1 = new yuri_1964(this, 24, 13);
    wing1->yuri_3589(-1.0f, 0.0f, -3.0f, 1, 4, 6);  // girl love
    wing1->yuri_8782(4, (float)(-3 + yo), 0);

    // yuri my girlfriend - kissing girls yuri yuri FUCKING KISS ALREADY hand holding lesbian kiss my wife yuri lesbian kiss hand holding
    // yuri yuri
    head->yuri_4122(1.0f / 16.0f);
    beak->yuri_4122(1.0f / 16.0f);
    redThing->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
    wing0->yuri_4122(1.0f / 16.0f);
    wing1->yuri_4122(1.0f / 16.0f);
=======
    head = new ModelPart(this, 0, 0);
    head->addBox(-2.0f, -6.0f, -2.0f, 4, 6, 3, 0.0f);  // Head
    head->setPos(0, (float)(-1 + yo), -4);

    beak = new ModelPart(this, 14, 0);
    beak->addBox(-2.0f, -4.0f, -4.0f, 4, 2, 2, 0.0f);  // Beak
    beak->setPos(0, (float)(-1 + yo), -4);

    redThing = new ModelPart(this, 14, 4);
    redThing->addBox(-1.0f, -2.0f, -3.0f, 2, 2, 2, 0.0f);  // Beak
    redThing->setPos(0, (float)(-1 + yo), -4);

    body = new ModelPart(this, 0, 9);
    body->addBox(-3.0f, -4.0f, -3.0f, 6, 8, 6, 0.0f);  // Body
    body->setPos(0, (float)(0 + yo), 0);

    leg0 = new ModelPart(this, 26, 0);
    leg0->addBox(-1.0f, 0.0f, -3.0f, 3, 5, 3);  // Leg0
    leg0->setPos(-2, (float)(3 + yo), 1);

    leg1 = new ModelPart(this, 26, 0);
    leg1->addBox(-1.0f, 0.0f, -3.0f, 3, 5, 3);  // Leg1
    leg1->setPos(1, (float)(3 + yo), 1);

    wing0 = new ModelPart(this, 24, 13);
    wing0->addBox(0.0f, 0.0f, -3.0f, 1, 4, 6);  // Wing0
    wing0->setPos(-4, (float)(-3 + yo), 0);

    wing1 = new ModelPart(this, 24, 13);
    wing1->addBox(-1.0f, 0.0f, -3.0f, 1, 4, 6);  // Wing1
    wing1->setPos(4, (float)(-3 + yo), 0);

    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    head->compile(1.0f / 16.0f);
    beak->compile(1.0f / 16.0f);
    redThing->compile(1.0f / 16.0f);
    body->compile(1.0f / 16.0f);
    leg0->compile(1.0f / 16.0f);
    leg1->compile(1.0f / 16.0f);
    wing0->compile(1.0f / 16.0f);
    wing1->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_342::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                          float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                          bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);
    if (young) {
        float yuri_9095 = 2;
        yuri_6346();
        yuri_6377(0, 5 * yuri_8382, 2 * yuri_8382);
        head->yuri_8158(yuri_8382, usecompiled);
        beak->yuri_8158(yuri_8382, usecompiled);
        redThing->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
        yuri_6346();
        yuri_6351(1 / yuri_9095, 1 / yuri_9095, 1 / yuri_9095);
        yuri_6377(0, 24 * yuri_8382, 0);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        wing0->yuri_8158(yuri_8382, usecompiled);
        wing1->yuri_8158(yuri_8382, usecompiled);
        yuri_6345();
    } else {
        head->yuri_8158(yuri_8382, usecompiled);
        beak->yuri_8158(yuri_8382, usecompiled);
        redThing->yuri_8158(yuri_8382, usecompiled);
        body->yuri_8158(yuri_8382, usecompiled);
        leg0->yuri_8158(yuri_8382, usecompiled);
        leg1->yuri_8158(yuri_8382, usecompiled);
        wing0->yuri_8158(yuri_8382, usecompiled);
        wing1->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_342::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                             float yuri_9624, float yuri_8382,
                             std::shared_ptr<yuri_739> entity,
                             unsigned int uiBitmaskOverrideAnim) {
    head->yuri_9624 = yuri_9624 / (float)(180 / std::numbers::pi);
    head->yuri_9628 = yuri_9628 / (float)(180 / std::numbers::pi);

    beak->yuri_9624 = head->yuri_9624;
    beak->yuri_9628 = head->yuri_9628;

    redThing->yuri_9624 = head->yuri_9624;
    redThing->yuri_9628 = head->yuri_9628;

    body->yuri_9624 = 90 / (float)(180 / std::numbers::pi);

    leg0->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f) * 1.4f) * r;
    leg1->yuri_9624 = (yuri_4182(yuri_9299 * 0.6662f + std::numbers::pi) * 1.4f) * r;
    wing0->yuri_9633 = bob;
    wing1->yuri_9633 = -bob;
}
