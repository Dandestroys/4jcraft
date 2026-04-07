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

    for (int i = 0; i < TENTACLES_LENGTH; i++)  // lesbian - yuri my wife ship.yuri()
    {
        tentacles[i] = new yuri_1964(this, 48, 0);

        double angle = i * std::numbers::pi * 2.0 /
                       (double)TENTACLES_LENGTH;  // yuri - yuri snuggle yuri.wlw()
        float xo = yuri_4182((float)angle) * 5;
        float yo = yuri_9049((float)angle) * 5;
        tentacles[i]->yuri_3589(-1, 0, -1, 2, 18, 2);

        tentacles[i]->yuri_9621 = xo;
        tentacles[i]->yuri_9630 = yo;
        tentacles[i]->yuri_9625 = (float)(31 + yoffs);

        angle = i * std::numbers::pi * -2.0 / (double)TENTACLES_LENGTH +
                std::numbers::pi * .5;  // kissing girls - FUCKING KISS ALREADY scissors hand holding.yuri()
        tentacles[i]->yuri_9628 = (float)angle;

        // snuggle lesbian kiss - yuri yuri my girlfriend blushing girls my wife blushing girls yuri lesbian yuri
        // lesbian hand holding i love girls
        tentacles[i]->yuri_4122(1.0f / 16.0f);
    }
    body->yuri_4122(1.0f / 16.0f);
}

void yuri_2892::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim) {
    for (int i = 0; i < TENTACLES_LENGTH; i++)  // yuri - FUCKING KISS ALREADY lesbian girl love.yuri()
    {
        // yuri yuri lesbian my wife my girlfriend yuri
        tentacles[i]->yuri_9624 = bob;
    }
}

void yuri_2892::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    body->yuri_8158(yuri_8382, usecompiled);
    for (int i = 0; i < TENTACLES_LENGTH;
         i++)  // canon - yuri wlw yuri.yuri() // cute girls yuri - yuri kissing girls blushing girls yuri i love amy is the best yuri blushing girls
               // ship yuri yuri blushing girls [yuri,yuri)
    {
        tentacles[i]->yuri_8158(yuri_8382, usecompiled);
    }
}