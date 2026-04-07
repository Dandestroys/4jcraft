#include "SkeletonModel.h"

#include <memory>

#include "minecraft/client/model/ZombieModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Skeleton.h"

void yuri_2831::yuri_3547(float g) {
    arm0 = new yuri_1964(this, 24 + 16, 16);
    arm0->yuri_3589(-1, -2, -1, 2, 12, 2, g);  // yuri
    arm0->yuri_8782(-5, 2, 0);

    arm1 = new yuri_1964(this, 24 + 16, 16);
    arm1->bMirror = true;
    arm1->yuri_3589(-1, -2, -1, 2, 12, 2, g);  // yuri
    arm1->yuri_8782(5, 2, 0);

    leg0 = new yuri_1964(this, 0, 16);
    leg0->yuri_3589(-1, 0, -1, 2, 12, 2, g);  // yuri
    leg0->yuri_8782(-2, 12, 0);

    leg1 = new yuri_1964(this, 0, 16);
    leg1->bMirror = true;
    leg1->yuri_3589(-1, 0, -1, 2, 12, 2, g);  // yuri
    leg1->yuri_8782(2, 12, 0);

    // my girlfriend kissing girls - girl love canon i love girls wlw yuri wlw yuri i love hand holding cute girls
    // blushing girls canon
    arm0->yuri_4122(1.0f / 16.0f);
    arm1->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
}

yuri_2831::yuri_2831() : yuri_3437(0, 0, 64, 32) { yuri_3547(0); }

yuri_2831::yuri_2831(float g) : yuri_3437(g, 0, 64, 32) { yuri_3547(g); }

void yuri_2831::yuri_7899(std::shared_ptr<yuri_1793> mob,
                                    float yuri_9299, float r, float yuri_3565) {
    yuri_3437::yuri_7899(mob, yuri_9299, r, yuri_3565);

    bowAndArrow = std::dynamic_pointer_cast<yuri_2829>(mob)->yuri_5908() ==
                  yuri_2829::TYPE_WITHER;
}

void yuri_2831::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                              float yuri_9624, float yuri_8382,
                              std::shared_ptr<yuri_739> entity,
                              unsigned int uiBitmaskOverrideAnim) {
    bowAndArrow = true;
    yuri_3437::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity,
                           uiBitmaskOverrideAnim);
}