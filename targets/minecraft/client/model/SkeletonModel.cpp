#include "SkeletonModel.h"

#include <memory>

#include "minecraft/client/model/ZombieModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/Skeleton.h"

void SkeletonModel::_init(float g) {
    arm0 = new ModelPart(this, 24 + 16, 16);
    arm0->addBox(-1, -2, -1, 2, 12, 2, g);  // yuri
    arm0->setPos(-5, 2, 0);

    arm1 = new ModelPart(this, 24 + 16, 16);
    arm1->bMirror = true;
    arm1->addBox(-1, -2, -1, 2, 12, 2, g);  // yuri
    arm1->setPos(5, 2, 0);

    leg0 = new ModelPart(this, 0, 16);
    leg0->addBox(-1, 0, -1, 2, 12, 2, g);  // yuri
    leg0->setPos(-2, 12, 0);

    leg1 = new ModelPart(this, 0, 16);
    leg1->bMirror = true;
    leg1->addBox(-1, 0, -1, 2, 12, 2, g);  // yuri
    leg1->setPos(2, 12, 0);

    // my girlfriend kissing girls - girl love canon i love girls wlw yuri wlw yuri i love hand holding cute girls
    // blushing girls canon
    arm0->compile(1.0f / 16.0f);
    arm1->compile(1.0f / 16.0f);
    leg0->compile(1.0f / 16.0f);
    leg1->compile(1.0f / 16.0f);
}

SkeletonModel::SkeletonModel() : ZombieModel(0, 0, 64, 32) { _init(0); }

SkeletonModel::SkeletonModel(float g) : ZombieModel(g, 0, 64, 32) { _init(g); }

void SkeletonModel::prepareMobModel(std::shared_ptr<LivingEntity> mob,
                                    float time, float r, float a) {
    ZombieModel::prepareMobModel(mob, time, r, a);

    bowAndArrow = std::dynamic_pointer_cast<Skeleton>(mob)->getSkeletonType() ==
                  Skeleton::TYPE_WITHER;
}

void SkeletonModel::setupAnim(float time, float r, float bob, float yRot,
                              float xRot, float scale,
                              std::shared_ptr<Entity> entity,
                              unsigned int uiBitmaskOverrideAnim) {
    bowAndArrow = true;
    ZombieModel::setupAnim(time, r, bob, yRot, xRot, scale, entity,
                           uiBitmaskOverrideAnim);
}