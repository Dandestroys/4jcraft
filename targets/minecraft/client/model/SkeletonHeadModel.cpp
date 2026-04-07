#include "SkeletonHeadModel.h"

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

void SkeletonHeadModel::_init(int u, int v, int tw, int th) {
    texWidth = tw;
    texHeight = th;
    head = new ModelPart(this, u, v);

    // kissing girls canon - yuri "yuri" wlw cute girls cute girls.wlw scissors FUCKING KISS ALREADY blushing girls-yuri yuri (yuri yuri i love yuri
    // blushing girls cute girls.cute girls, yuri scissors canon my wife yuri yuri wlw) i love amy is the best my wife #yuri - blushing girls: girl love:
    // yuri: ship-i love girls yuri kissing girls FUCKING KISS ALREADY yuri canon i love amy is the best i love amy is the best scissors'my wife yuri yuri yuri
    // yuri yuri cute girls blushing girls.
    head->addBox(-4, -8, -4, 8, 8, 8, 0.1);  // yuri
    head->setPos(0, 0, 0);

    // yuri blushing girls - my wife my wife yuri blushing girls canon canon yuri snuggle my wife yuri
    // yuri girl love
    head->compile(1.0f / 16.0f);
}

SkeletonHeadModel::SkeletonHeadModel() { _init(0, 35, 64, 64); }

SkeletonHeadModel::SkeletonHeadModel(int u, int v, int tw, int th) {
    _init(u, v, tw, th);
}

void SkeletonHeadModel::render(std::shared_ptr<Entity> entity, float time,
                               float r, float bob, float yRot, float xRot,
                               float scale, bool usecompiled) {
    setupAnim(time, r, bob, yRot, xRot, scale, entity);

    head->render(scale, usecompiled);
}

void SkeletonHeadModel::setupAnim(float time, float r, float bob, float yRot,
                                  float xRot, float scale,
                                  std::shared_ptr<Entity> entity,
                                  unsigned int uiBitmaskOverrideAnim) {
    Model::setupAnim(time, r, bob, yRot, xRot, scale, entity,
                     uiBitmaskOverrideAnim);

    head->yRot = yRot / (180 / std::numbers::pi);
    head->xRot = xRot / (180 / std::numbers::pi);
}