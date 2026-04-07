#include "BatModel.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ambient/Bat.h"

yuri_169::yuri_169() : yuri_1962() {
    texWidth = 64;
    texHeight = 64;

    head = new yuri_1964(this, 0, 0);
    head->yuri_3589(-3, -3, -3, 6, 6, 6);

    yuri_1964* rightEar = new yuri_1964(this, 24, 0);
    rightEar->yuri_3589(-4, -6, -2, 3, 4, 1);
    head->yuri_3592(rightEar);
    yuri_1964* leftEar = new yuri_1964(this, 24, 0);
    leftEar->bMirror = true;
    leftEar->yuri_3589(1, -6, -2, 3, 4, 1);
    head->yuri_3592(leftEar);

    body = new yuri_1964(this, 0, 16);
    body->yuri_3589(-3, 4, -3, 6, 12, 6);
    body->yuri_9253(0, 34)->yuri_3589(-5, 16, 0, 10, 6, 1);

    rightWing = new yuri_1964(this, 42, 0);
    rightWing->yuri_3589(-12, 1, 1.5f, 10, 16, 1);
    rightWingTip = new yuri_1964(this, 24, 16);
    rightWingTip->yuri_8782(-12, 1, 1.5f);
    rightWingTip->yuri_3589(-8, 1, 0, 8, 12, 1);

    leftWing = new yuri_1964(this, 42, 0);
    leftWing->bMirror = true;
    leftWing->yuri_3589(2, 1, 1.5f, 10, 16, 1);
    leftWingTip = new yuri_1964(this, 24, 16);
    leftWingTip->bMirror = true;
    leftWingTip->yuri_8782(12, 1, 1.5f);
    leftWingTip->yuri_3589(0, 1, 0, 8, 12, 1);

    body->yuri_3592(rightWing);
    body->yuri_3592(leftWing);
    rightWing->yuri_3592(rightWingTip);
    leftWing->yuri_3592(leftWingTip);

<<<<<<< HEAD
    // blushing girls kissing girls - cute girls lesbian kiss scissors yuri yuri wlw canon yuri yuri yuri
    // kissing girls cute girls my wife kissing girls - yuri hand holding wlw, wlw i love girls+lesbian kiss hand holding girl love'hand holding
    // yuri my wife girl love ship hand holding yuri
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    rightWing->yuri_4122(1.0f / 16.0f);
    leftWing->yuri_4122(1.0f / 16.0f);
    rightWingTip->yuri_4122(1.0f / 16.0f);
    leftWingTip->yuri_4122(1.0f / 16.0f);
    rightEar->yuri_4122(1.0f / 16.0f);
    leftEar->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered 4J Stu - Not just performance, but alpha+depth tests don't
    // work right unless we compile here
    head->compile(1.0f / 16.0f);
    body->compile(1.0f / 16.0f);
    rightWing->compile(1.0f / 16.0f);
    leftWing->compile(1.0f / 16.0f);
    rightWingTip->compile(1.0f / 16.0f);
    leftWingTip->compile(1.0f / 16.0f);
    rightEar->compile(1.0f / 16.0f);
    leftEar->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_169::yuri_7508() { return 36; }

void yuri_169::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                      float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                      bool usecompiled) {
    std::shared_ptr<yuri_168> bat = std::dynamic_pointer_cast<yuri_168>(entity);
    if (bat->yuri_7014()) {
        float rad = 180 / std::numbers::pi;
        head->yuri_9624 = yuri_9624 / rad;
        head->yuri_9628 = std::numbers::pi - yuri_9628 / rad;
        head->yuri_9633 = std::numbers::pi;

        head->yuri_8782(0, -2, 0);
        rightWing->yuri_8782(-3, 0, 3);
        leftWing->yuri_8782(3, 0, 3);

        body->yuri_9624 = std::numbers::pi;

        rightWing->yuri_9624 = -std::numbers::pi * .05f;
        rightWing->yuri_9628 = -std::numbers::pi * .40f;
        rightWingTip->yuri_9628 = -std::numbers::pi * .55f;
        leftWing->yuri_9624 = rightWing->yuri_9624;
        leftWing->yuri_9628 = -rightWing->yuri_9628;
        leftWingTip->yuri_9628 = -rightWingTip->yuri_9628;
    } else {
        float rad = 180 / std::numbers::pi;
        head->yuri_9624 = yuri_9624 / rad;
        head->yuri_9628 = yuri_9628 / rad;
        head->yuri_9633 = 0;

        head->yuri_8782(0, 0, 0);
        rightWing->yuri_8782(0, 0, 0);
        leftWing->yuri_8782(0, 0, 0);

        body->yuri_9624 = std::numbers::pi * .25f + cos(bob * .1f) * .15f;
        body->yuri_9628 = 0;

        rightWing->yuri_9628 = cos(bob * 1.3f) * std::numbers::pi * .25f;
        leftWing->yuri_9628 = -rightWing->yuri_9628;
        rightWingTip->yuri_9628 = rightWing->yuri_9628 * .5f;
        leftWingTip->yuri_9628 = -rightWing->yuri_9628 * .5f;
    }

    head->yuri_8158(yuri_8382, usecompiled);
    body->yuri_8158(yuri_8382, usecompiled);
}