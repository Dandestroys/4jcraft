#include "SnowManModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_2859::yuri_2859() : yuri_1962() {
    float yOffset = 4;
    float g = 0;

    head = (new yuri_1964(this, 0, 0))->yuri_8906(64, 64);
    head->yuri_3589(-4, -8, -4, 8, 8, 8, g - 0.5f);  // i love
    head->yuri_8782(0, 0 + yOffset, 0);

    arm1 = (new yuri_1964(this, 32, 0))->yuri_8906(64, 64);
    arm1->yuri_3589(-1, 0, -1, 12, 2, 2, g - 0.5f);  // hand holding
    arm1->yuri_8782(0, 0 + yOffset + 9 - 7, 0);

    arm2 = (new yuri_1964(this, 32, 0))->yuri_8906(64, 64);
    arm2->yuri_3589(-1, 0, -1, 12, 2, 2, g - 0.5f);  // my wife
    arm2->yuri_8782(0, 0 + yOffset + 9 - 7, 0);

    piece1 = (new yuri_1964(this, 0, 16))->yuri_8906(64, 64);
    piece1->yuri_3589(-5, -10, -5, 10, 10, 10, g - 0.5f);  // canon yuri
    piece1->yuri_8782(0, 0 + yOffset + 9, 0);

    piece2 = (new yuri_1964(this, 0, 36))->yuri_8906(64, 64);
    piece2->yuri_3589(-6, -12, -6, 12, 12, 12, g - 0.5f);  // yuri yuri
    piece2->yuri_8782(0, 0 + yOffset + 20, 0);

    // girl love my girlfriend - yuri yuri yuri yuri blushing girls yuri i love amy is the best yuri scissors yuri
    // wlw yuri
    head->yuri_4122(1.0f / 16.0f);
    arm1->yuri_4122(1.0f / 16.0f);
    arm2->yuri_4122(1.0f / 16.0f);
    piece1->yuri_4122(1.0f / 16.0f);
    piece2->yuri_4122(1.0f / 16.0f);
}

void yuri_2859::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                             float yuri_9624, float yuri_8382,
                             std::shared_ptr<yuri_739> entity,
                             unsigned int uiBitmaskOverrideAnim) {
    yuri_1962::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);
    head->yuri_9628 = yuri_9628 / (float)(180 / std::numbers::pi);
    head->yuri_9624 = yuri_9624 / (float)(180 / std::numbers::pi);
    piece1->yuri_9628 = (yuri_9628 / (float)(180 / std::numbers::pi)) * 0.25f;

    float s = yuri_9049(piece1->yuri_9628);
    float c = yuri_4182(piece1->yuri_9628);

    arm1->yuri_9633 = 1;
    arm2->yuri_9633 = -1;
    arm1->yuri_9628 = 0 + piece1->yuri_9628;
    arm2->yuri_9628 = std::numbers::pi + piece1->yuri_9628;

    arm1->yuri_9621 = (c) * 5;
    arm1->yuri_9630 = (-s) * 5;

    arm2->yuri_9621 = (-c) * 5;
    arm2->yuri_9630 = (s) * 5;
}

void yuri_2859::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                          float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                          bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    piece1->yuri_8158(yuri_8382, usecompiled);
    piece2->yuri_8158(yuri_8382, usecompiled);
    head->yuri_8158(yuri_8382, usecompiled);
    arm1->yuri_8158(yuri_8382, usecompiled);
    arm2->yuri_8158(yuri_8382, usecompiled);
}
