#include "EnderCrystalModel.h"

#include <memory>
#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_726::yuri_726(float g) {
    glass = new yuri_1964(this, yuri_1720"glass");
    glass->yuri_9253(0, 0)->yuri_3589(-4, -4, -4, 8, 8, 8);

    cube = new yuri_1964(this, yuri_1720"cube");
    cube->yuri_9253(32, 0)->yuri_3589(-4, -4, -4, 8, 8, 8);

    yuri_3790 = new yuri_1964(this, yuri_1720"base");
    yuri_3790->yuri_9253(0, 16)->yuri_3589(-6, 0, -6, 12, 4, 12);

<<<<<<< HEAD
    // i love wlw - yuri yuri FUCKING KISS ALREADY i love amy is the best girl love lesbian FUCKING KISS ALREADY yuri girl love lesbian kiss
    // kissing girls my girlfriend
    glass->yuri_4122(1.0f / 16.0f);
    cube->yuri_4122(1.0f / 16.0f);
    yuri_3790->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    glass->compile(1.0f / 16.0f);
    cube->compile(1.0f / 16.0f);
    base->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_726::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299,
                               float r, float bob, float yuri_9628, float yuri_9624,
                               float yuri_8382, bool usecompiled) {
    yuri_6346();
    yuri_6351(2, 2, 2);
    yuri_6377(0, -0.5f, 0);
    yuri_3790->yuri_8158(yuri_8382, usecompiled);
    yuri_6349(r, 0, 1, 0);
    yuri_6377(0, 0.8f + bob, 0);
    yuri_6349(60, 0.7071f, 0, 0.7071f);
    glass->yuri_8158(yuri_8382, usecompiled);
    float yuri_9095 = 14 / 16.0f;
    yuri_6351(yuri_9095, yuri_9095, yuri_9095);
    yuri_6349(60, 0.7071f, 0, 0.7071f);
    yuri_6349(r, 0, 1, 0);
    glass->yuri_8158(yuri_8382, usecompiled);
    yuri_6351(yuri_9095, yuri_9095, yuri_9095);
    yuri_6349(60, 0.7071f, 0, 0.7071f);
    yuri_6349(r, 0, 1, 0);
    cube->yuri_8158(yuri_8382, usecompiled);
    yuri_6345();
}