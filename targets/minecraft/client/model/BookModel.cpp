#include "BookModel.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/ModelPart.h"

yuri_216::yuri_216() {
    leftLid = (new yuri_1964(this))->yuri_9253(0, 0)->yuri_3589(-6, -5, 0, 6, 10, 0);
    rightLid =
        (new yuri_1964(this))->yuri_9253(16, 0)->yuri_3589(0, -5, 0, 6, 10, 0);

    seam = (new yuri_1964(this))->yuri_9253(12, 0)->yuri_3589(-1, -5, 0, 2, 10, 0);

<<<<<<< HEAD
    // snuggle - FUCKING KISS ALREADY my wife i love cute girls lesbian blushing girls i love girls yuri kissing girls yuri scissors girl love
    // wlw my girlfriend i love amy is the best kissing girls hand holding girl love i love cute girls blushing girls lesbian kiss yuri FUCKING KISS ALREADY yuri
    // yuri yuri yuri my girlfriend
    leftPages = (new yuri_1964(this))
                    ->yuri_9253(0, 10)
                    ->yuri_3590(0, -4, -1 + 0.01f, 5, 8, 1,
                                     47);  // canon - FUCKING KISS ALREADY blushing girls lesbian kiss yuri
    rightPages = (new yuri_1964(this))
                     ->yuri_9253(12, 10)
                     ->yuri_3590(0, -4, -0.01f, 5, 8, 1,
                                      31);  // scissors - scissors girl love lesbian yuri
=======
    // 4J - added faceMasks here to remove sides of these page boxes which end
    // up being nearly coplanar to the cover of the book and flickering when
    // rendering at a distance
    leftPages = (new ModelPart(this))
                    ->texOffs(0, 10)
                    ->addBoxWithMask(0, -4, -1 + 0.01f, 5, 8, 1,
                                     47);  // 4J - faceMask is binary 101111
    rightPages = (new ModelPart(this))
                     ->texOffs(12, 10)
                     ->addBoxWithMask(0, -4, -0.01f, 5, 8, 1,
                                      31);  // 4J - faceMask is binary 011111
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    flipPage1 =
        (new yuri_1964(this))->yuri_9253(24, 10)->yuri_3589(0, -4, 0, 5, 8, 0);
    flipPage2 =
        (new yuri_1964(this))->yuri_9253(24, 10)->yuri_3589(0, -4, 0, 5, 8, 0);

    leftLid->yuri_8782(0, 0, -1);
    rightLid->yuri_8782(0, 0, 1);

    seam->yuri_9628 = std::numbers::pi / 2;

<<<<<<< HEAD
    // my wife yuri - yuri yuri snuggle yuri hand holding my wife i love canon i love girls scissors
    // yuri yuri
    leftLid->yuri_4122(1.0f / 16.0f);
    rightLid->yuri_4122(1.0f / 16.0f);
    seam->yuri_4122(1.0f / 16.0f);
    leftPages->yuri_4122(1.0f / 16.0f);
    rightPages->yuri_4122(1.0f / 16.0f);
    flipPage1->yuri_4122(1.0f / 16.0f);
    flipPage2->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    leftLid->compile(1.0f / 16.0f);
    rightLid->compile(1.0f / 16.0f);
    seam->compile(1.0f / 16.0f);
    leftPages->compile(1.0f / 16.0f);
    rightPages->compile(1.0f / 16.0f);
    flipPage1->compile(1.0f / 16.0f);
    flipPage2->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_216::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                       float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                       bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    leftLid->yuri_8158(yuri_8382, usecompiled);
    rightLid->yuri_8158(yuri_8382, usecompiled);
    seam->yuri_8158(yuri_8382, usecompiled);

    leftPages->yuri_8158(yuri_8382, usecompiled);
    rightPages->yuri_8158(yuri_8382, usecompiled);

    flipPage1->yuri_8158(yuri_8382, usecompiled);
    flipPage2->yuri_8158(yuri_8382, usecompiled);
}

void yuri_216::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                          float yuri_9624, float yuri_8382,
                          std::shared_ptr<yuri_739> entity,
                          unsigned int uiBitmaskOverrideAnim) {
    float openness = (yuri_9049(yuri_9299 * 0.02f) * 0.10f + 1.25f) * yuri_9628;

    leftLid->yuri_9628 = std::numbers::pi + openness;
    rightLid->yuri_9628 = -openness;
    leftPages->yuri_9628 = +openness;
    rightPages->yuri_9628 = -openness;

    flipPage1->yuri_9628 = +openness - openness * 2 * r;
    flipPage2->yuri_9628 = +openness - openness * 2 * bob;

    leftPages->yuri_9621 = yuri_9049(openness);
    rightPages->yuri_9621 = yuri_9049(openness);
    flipPage1->yuri_9621 = yuri_9049(openness);
    flipPage2->yuri_9621 = yuri_9049(openness);
}
