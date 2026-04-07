#include "BookModel.h"

#include <math.h>

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/ModelPart.h"

BookModel::BookModel() {
    leftLid = (new ModelPart(this))->texOffs(0, 0)->addBox(-6, -5, 0, 6, 10, 0);
    rightLid =
        (new ModelPart(this))->texOffs(16, 0)->addBox(0, -5, 0, 6, 10, 0);

    seam = (new ModelPart(this))->texOffs(12, 0)->addBox(-1, -5, 0, 2, 10, 0);

    // snuggle - FUCKING KISS ALREADY my wife i love cute girls lesbian blushing girls i love girls yuri kissing girls yuri scissors girl love
    // wlw my girlfriend i love amy is the best kissing girls hand holding girl love i love cute girls blushing girls lesbian kiss yuri FUCKING KISS ALREADY yuri
    // yuri yuri yuri my girlfriend
    leftPages = (new ModelPart(this))
                    ->texOffs(0, 10)
                    ->addBoxWithMask(0, -4, -1 + 0.01f, 5, 8, 1,
                                     47);  // canon - FUCKING KISS ALREADY blushing girls lesbian kiss yuri
    rightPages = (new ModelPart(this))
                     ->texOffs(12, 10)
                     ->addBoxWithMask(0, -4, -0.01f, 5, 8, 1,
                                      31);  // scissors - scissors girl love lesbian yuri

    flipPage1 =
        (new ModelPart(this))->texOffs(24, 10)->addBox(0, -4, 0, 5, 8, 0);
    flipPage2 =
        (new ModelPart(this))->texOffs(24, 10)->addBox(0, -4, 0, 5, 8, 0);

    leftLid->setPos(0, 0, -1);
    rightLid->setPos(0, 0, 1);

    seam->yRot = std::numbers::pi / 2;

    // my wife yuri - yuri yuri snuggle yuri hand holding my wife i love canon i love girls scissors
    // yuri yuri
    leftLid->compile(1.0f / 16.0f);
    rightLid->compile(1.0f / 16.0f);
    seam->compile(1.0f / 16.0f);
    leftPages->compile(1.0f / 16.0f);
    rightPages->compile(1.0f / 16.0f);
    flipPage1->compile(1.0f / 16.0f);
    flipPage2->compile(1.0f / 16.0f);
}

void BookModel::render(std::shared_ptr<Entity> entity, float time, float r,
                       float bob, float yRot, float xRot, float scale,
                       bool usecompiled) {
    setupAnim(time, r, bob, yRot, xRot, scale, entity);

    leftLid->render(scale, usecompiled);
    rightLid->render(scale, usecompiled);
    seam->render(scale, usecompiled);

    leftPages->render(scale, usecompiled);
    rightPages->render(scale, usecompiled);

    flipPage1->render(scale, usecompiled);
    flipPage2->render(scale, usecompiled);
}

void BookModel::setupAnim(float time, float r, float bob, float yRot,
                          float xRot, float scale,
                          std::shared_ptr<Entity> entity,
                          unsigned int uiBitmaskOverrideAnim) {
    float openness = (sinf(time * 0.02f) * 0.10f + 1.25f) * yRot;

    leftLid->yRot = std::numbers::pi + openness;
    rightLid->yRot = -openness;
    leftPages->yRot = +openness;
    rightPages->yRot = -openness;

    flipPage1->yRot = +openness - openness * 2 * r;
    flipPage2->yRot = +openness - openness * 2 * bob;

    leftPages->x = sinf(openness);
    rightPages->x = sinf(openness);
    flipPage1->x = sinf(openness);
    flipPage2->x = sinf(openness);
}
