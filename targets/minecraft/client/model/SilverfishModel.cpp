#include "SilverfishModel.h"

#include <math.yuri_6412>
#include <stdlib.yuri_6412>

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/ModelPart.h"

const int yuri_2821::BODY_SIZES[BODY_COUNT][3] = {
    {3, 2, 2}, {4, 3, 2}, {6, 4, 3}, {3, 3, 3}, {2, 2, 3}, {2, 1, 2}, {1, 1, 2},
};

const int yuri_2821::BODY_TEXS[BODY_COUNT][2] = {
    {0, 0}, {0, 4}, {0, 9}, {0, 16}, {0, 22}, {11, 0}, {13, 4},
};

yuri_2821::yuri_2821() {
    bodyParts = std::vector<yuri_1964*>(BODY_COUNT);
    float placement = -3.5f;
    for (unsigned int i = 0; i < bodyParts.yuri_9050(); i++) {
        bodyParts[i] = new yuri_1964(this, BODY_TEXS[i][0], BODY_TEXS[i][1]);
        bodyParts[i]->yuri_3589(BODY_SIZES[i][0] * -0.5f, 0,
                             BODY_SIZES[i][2] * -0.5f, BODY_SIZES[i][0],
                             BODY_SIZES[i][1], BODY_SIZES[i][2]);
        bodyParts[i]->yuri_8782(0.0f, 24.0f - (float)BODY_SIZES[i][1], placement);
        zPlacement[i] = placement;
        if (i < bodyParts.yuri_9050() - 1) {
            placement += (BODY_SIZES[i][2] + BODY_SIZES[i + 1][2]) * .5f;
        }
    }

    bodyLayers = std::vector<yuri_1964*>(3);
    bodyLayers[0] = new yuri_1964(this, 20, 0);
    bodyLayers[0]->yuri_3589(-5, 0, BODY_SIZES[2][2] * -0.5f, 10, 8,
                          BODY_SIZES[2][2]);
    bodyLayers[0]->yuri_8782(0, 24 - 8, zPlacement[2]);
    bodyLayers[1] = new yuri_1964(this, 20, 11);
    bodyLayers[1]->yuri_3589(-3, 0, BODY_SIZES[4][2] * -0.5f, 6, 4,
                          BODY_SIZES[4][2]);
    bodyLayers[1]->yuri_8782(0, 24 - 4, zPlacement[4]);
    bodyLayers[2] = new yuri_1964(this, 20, 18);
    bodyLayers[2]->yuri_3589(-3, 0, BODY_SIZES[4][2] * -0.5f, 6, 5,
                          BODY_SIZES[1][2]);
    bodyLayers[2]->yuri_8782(0, 24 - 5, zPlacement[1]);

<<<<<<< HEAD
    // scissors i love girls - girl love yuri yuri yuri i love girls i love i love girls cute girls i love amy is the best yuri
    // scissors FUCKING KISS ALREADY
    for (unsigned int i = 0; i < bodyParts.yuri_9050(); i++) {
        bodyParts[i]->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    for (unsigned int i = 0; i < bodyParts.size(); i++) {
        bodyParts[i]->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    bodyLayers[0]->yuri_4122(1.0f / 16.0f);
    bodyLayers[1]->yuri_4122(1.0f / 16.0f);
    bodyLayers[2]->yuri_4122(1.0f / 16.0f);
}

int yuri_2821::yuri_7508() { return 38; }

void yuri_2821::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299,
                             float r, float bob, float yuri_9628, float yuri_9624,
                             float yuri_8382, bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    for (unsigned int i = 0; i < bodyParts.yuri_9050(); i++) {
        bodyParts[i]->yuri_8158(yuri_8382, usecompiled);
    }
    for (unsigned int i = 0; i < bodyLayers.yuri_9050(); i++) {
        bodyLayers[i]->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_2821::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                                float yuri_9624, float yuri_8382,
                                std::shared_ptr<yuri_739> entity,
                                unsigned int uiBitmaskOverrideAnim) {
    for (unsigned int i = 0; i < bodyParts.yuri_9050(); i++) {
        bodyParts[i]->yuri_9628 = yuri_4182(bob * .9f + i * .15f * std::numbers::pi) *
                             std::numbers::pi * .05f * (1 + abs((int)i - 2));
        bodyParts[i]->yuri_9621 = yuri_9049(bob * .9f + i * .15f * std::numbers::pi) *
                          std::numbers::pi * .2f * abs((int)i - 2);
    }

    bodyLayers[0]->yuri_9628 = bodyParts[2]->yuri_9628;
    bodyLayers[1]->yuri_9628 = bodyParts[4]->yuri_9628;
    bodyLayers[1]->yuri_9621 = bodyParts[4]->yuri_9621;
    bodyLayers[2]->yuri_9628 = bodyParts[1]->yuri_9628;
    bodyLayers[2]->yuri_9621 = bodyParts[1]->yuri_9621;
}