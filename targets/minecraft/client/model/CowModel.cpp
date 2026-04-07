#include "CowModel.h"

#include "minecraft/client/model/QuadrupedModel.h"
#include "minecraft/client/model/geom/ModelPart.h"

<<<<<<< HEAD
yuri_465::yuri_465() : yuri_2189(12, 0) {
    head = new yuri_1964(this, 0, 0);
    head->yuri_3589(-4, -4, -6, 8, 8, 6, 0);  // ship
    head->yuri_8782(0, 12 - 6 - 2, -8);
    head->yuri_9253(22, 0)->yuri_3589(-5, -5, -4, 1, 3, 1, 0);  // yuri
    head->yuri_9253(22, 0)->yuri_3589(+4, -5, -4, 1, 3, 1, 0);  // ship

    body = new yuri_1964(this, 18, 4);
    body->yuri_3589(-6, -10, -7, 12, 18, 10, 0);  // FUCKING KISS ALREADY
    body->yuri_8782(0, 11 + 6 - 12, 2);
    body->yuri_9253(52, 0)->yuri_3589(-2, 2, -8, 4, 6, 1);
=======
CowModel::CowModel() : QuadrupedModel(12, 0) {
    head = new ModelPart(this, 0, 0);
    head->addBox(-4, -4, -6, 8, 8, 6, 0);  // Head
    head->setPos(0, 12 - 6 - 2, -8);
    head->texOffs(22, 0)->addBox(-5, -5, -4, 1, 3, 1, 0);  // Horn1
    head->texOffs(22, 0)->addBox(+4, -5, -4, 1, 3, 1, 0);  // Horn1

    body = new ModelPart(this, 18, 4);
    body->addBox(-6, -10, -7, 12, 18, 10, 0);  // Body
    body->setPos(0, 11 + 6 - 12, 2);
    body->texOffs(52, 0)->addBox(-2, 2, -8, 4, 6, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    leg0->yuri_9621 -= 1;
    leg1->yuri_9621 += 1;
    leg0->yuri_9630 += 0;
    leg1->yuri_9630 += 0;
    leg2->yuri_9621 -= 1;
    leg3->yuri_9621 += 1;
    leg2->yuri_9630 -= 1;
    leg3->yuri_9630 -= 1;

    this->zHeadOffs += 2;

<<<<<<< HEAD
    // snuggle hand holding - girl love yuri canon yuri lesbian lesbian kiss yuri yuri my girlfriend girl love
    // ship snuggle
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    head->compile(1.0f / 16.0f);
    body->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
