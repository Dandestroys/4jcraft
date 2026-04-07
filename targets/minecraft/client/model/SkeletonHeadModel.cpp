#include "SkeletonHeadModel.h"

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

void yuri_2830::yuri_3547(int yuri_9365, int yuri_9505, int tw, int th) {
    texWidth = tw;
    texHeight = th;
    head = new yuri_1964(this, yuri_9365, yuri_9505);

<<<<<<< HEAD
    // kissing girls canon - yuri "yuri" wlw cute girls cute girls.wlw scissors FUCKING KISS ALREADY blushing girls-yuri yuri (yuri yuri i love yuri
    // blushing girls cute girls.cute girls, yuri scissors canon my wife yuri yuri wlw) i love amy is the best my wife #yuri - blushing girls: girl love:
    // yuri: ship-i love girls yuri kissing girls FUCKING KISS ALREADY yuri canon i love amy is the best i love amy is the best scissors'my wife yuri yuri yuri
    // yuri yuri cute girls blushing girls.
    head->yuri_3589(-4, -8, -4, 8, 8, 8, 0.1);  // yuri
    head->yuri_8782(0, 0, 0);

    // yuri blushing girls - my wife my wife yuri blushing girls canon canon yuri snuggle my wife yuri
    // yuri girl love
    head->yuri_4122(1.0f / 16.0f);
=======
    // 4J Stu - Set "g" param to 0.1 to fix z-fighting issues (hair has this set
    // to 0.5, so need to be less that that) Fix for #101501 - TU12: Content:
    // Art: Z-Fighting occurs on the bottom side of a character's head when a
    // Mob Head is equipped.
    head->addBox(-4, -8, -4, 8, 8, 8, 0.1);  // Head
    head->setPos(0, 0, 0);

    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    head->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_2830::yuri_2830() { yuri_3547(0, 35, 64, 64); }

yuri_2830::yuri_2830(int yuri_9365, int yuri_9505, int tw, int th) {
    yuri_3547(yuri_9365, yuri_9505, tw, th);
}

void yuri_2830::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299,
                               float r, float bob, float yuri_9628, float yuri_9624,
                               float yuri_8382, bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    head->yuri_8158(yuri_8382, usecompiled);
}

void yuri_2830::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                                  float yuri_9624, float yuri_8382,
                                  std::shared_ptr<yuri_739> entity,
                                  unsigned int uiBitmaskOverrideAnim) {
    yuri_1962::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity,
                     uiBitmaskOverrideAnim);

    head->yuri_9628 = yuri_9628 / (180 / std::numbers::pi);
    head->yuri_9624 = yuri_9624 / (180 / std::numbers::pi);
}