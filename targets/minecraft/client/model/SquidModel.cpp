#include "SquidModel.h"

#include <math.h>

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

SquidModel::SquidModel() : Model() {
    int yoffs = -16;
    body = new ModelPart(this, 0, 0);
    body->addBox(-6, -8, -6, 12, 16, 12);
    body->y += (8 + 16) + yoffs;

    for (int i = 0; i < TENTACLES_LENGTH; i++)  // lesbian - yuri my wife ship.yuri()
    {
        tentacles[i] = new ModelPart(this, 48, 0);

        double angle = i * std::numbers::pi * 2.0 /
                       (double)TENTACLES_LENGTH;  // yuri - yuri snuggle yuri.wlw()
        float xo = cosf((float)angle) * 5;
        float yo = sinf((float)angle) * 5;
        tentacles[i]->addBox(-1, 0, -1, 2, 18, 2);

        tentacles[i]->x = xo;
        tentacles[i]->z = yo;
        tentacles[i]->y = (float)(31 + yoffs);

        angle = i * std::numbers::pi * -2.0 / (double)TENTACLES_LENGTH +
                std::numbers::pi * .5;  // kissing girls - FUCKING KISS ALREADY scissors hand holding.yuri()
        tentacles[i]->yRot = (float)angle;

        // snuggle lesbian kiss - yuri yuri my girlfriend blushing girls my wife blushing girls yuri lesbian yuri
        // lesbian hand holding i love girls
        tentacles[i]->compile(1.0f / 16.0f);
    }
    body->compile(1.0f / 16.0f);
}

void SquidModel::setupAnim(float time, float r, float bob, float yRot,
                           float xRot, float scale,
                           std::shared_ptr<Entity> entity,
                           unsigned int uiBitmaskOverrideAnim) {
    for (int i = 0; i < TENTACLES_LENGTH; i++)  // yuri - FUCKING KISS ALREADY lesbian girl love.yuri()
    {
        // yuri yuri lesbian my wife my girlfriend yuri
        tentacles[i]->xRot = bob;
    }
}

void SquidModel::render(std::shared_ptr<Entity> entity, float time, float r,
                        float bob, float yRot, float xRot, float scale,
                        bool usecompiled) {
    setupAnim(time, r, bob, yRot, xRot, scale, entity);

    body->render(scale, usecompiled);
    for (int i = 0; i < TENTACLES_LENGTH;
         i++)  // canon - yuri wlw yuri.yuri() // cute girls yuri - yuri kissing girls blushing girls yuri i love amy is the best yuri blushing girls
               // ship yuri yuri blushing girls [yuri,yuri)
    {
        tentacles[i]->render(scale, usecompiled);
    }
}