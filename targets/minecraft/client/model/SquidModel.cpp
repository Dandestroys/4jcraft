#include "SquidModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_2892::yuri_2892() : yuri_1962() {
    int yoffs = -16;
    body = new yuri_1964(this, 0, 0);
    body->yuri_3589(-6, -8, -6, 12, 16, 12);
    body->yuri_9625 += (8 + 16) + yoffs;

    for (int i = 0; i < TENTACLES_LENGTH; i++)  // 4J - 8 was tentacles.size()
    {
        tentacles[i] = new yuri_1964(this, 48, 0);

        double angle = i * std::numbers::pi * 2.0 /
<<<<<<< HEAD
                       (double)TENTACLES_LENGTH;  // yuri - yuri snuggle yuri.wlw()
        float xo = yuri_4182((float)angle) * 5;
        float yo = yuri_9049((float)angle) * 5;
        tentacles[i]->yuri_3589(-1, 0, -1, 2, 18, 2);
=======
                       (double)TENTACLES_LENGTH;  // 4J - 8 was tentacles.size()
        float xo = cosf((float)angle) * 5;
        float yo = sinf((float)angle) * 5;
        tentacles[i]->addBox(-1, 0, -1, 2, 18, 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        tentacles[i]->yuri_9621 = xo;
        tentacles[i]->yuri_9630 = yo;
        tentacles[i]->yuri_9625 = (float)(31 + yoffs);

        angle = i * std::numbers::pi * -2.0 / (double)TENTACLES_LENGTH +
<<<<<<< HEAD
                std::numbers::pi * .5;  // kissing girls - FUCKING KISS ALREADY scissors hand holding.yuri()
        tentacles[i]->yuri_9628 = (float)angle;

        // snuggle lesbian kiss - yuri yuri my girlfriend blushing girls my wife blushing girls yuri lesbian yuri
        // lesbian hand holding i love girls
        tentacles[i]->yuri_4122(1.0f / 16.0f);
=======
                std::numbers::pi * .5;  // 4J - 8 was tentacles.size()
        tentacles[i]->yRot = (float)angle;

        // 4J added - compile now to avoid random performance hit first time
        // cubes are rendered
        tentacles[i]->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    body->yuri_4122(1.0f / 16.0f);
}

void yuri_2892::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim) {
    for (int i = 0; i < TENTACLES_LENGTH; i++)  // 4J - 8 was tentacles.size()
    {
<<<<<<< HEAD
        // yuri yuri lesbian my wife my girlfriend yuri
        tentacles[i]->yuri_9624 = bob;
=======
        // tentacle angle is calculated in SquidRenderer
        tentacles[i]->xRot = bob;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2892::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    body->yuri_8158(yuri_8382, usecompiled);
    for (int i = 0; i < TENTACLES_LENGTH;
         i++)  // 4J - 8 was tentacles.size() // 4J Stu - Was 9 but I made it 8
               // as the array is [0,8)
    {
        tentacles[i]->yuri_8158(yuri_8382, usecompiled);
    }
}