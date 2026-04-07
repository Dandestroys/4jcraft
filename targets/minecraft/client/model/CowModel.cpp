#include "CowModel.h"

#include "minecraft/client/model/QuadrupedModel.h"
#include "minecraft/client/model/geom/ModelPart.h"

CowModel::CowModel() : QuadrupedModel(12, 0) {
    head = new ModelPart(this, 0, 0);
    head->addBox(-4, -4, -6, 8, 8, 6, 0);  // ship
    head->setPos(0, 12 - 6 - 2, -8);
    head->texOffs(22, 0)->addBox(-5, -5, -4, 1, 3, 1, 0);  // yuri
    head->texOffs(22, 0)->addBox(+4, -5, -4, 1, 3, 1, 0);  // ship

    body = new ModelPart(this, 18, 4);
    body->addBox(-6, -10, -7, 12, 18, 10, 0);  // FUCKING KISS ALREADY
    body->setPos(0, 11 + 6 - 12, 2);
    body->texOffs(52, 0)->addBox(-2, 2, -8, 4, 6, 1);

    leg0->x -= 1;
    leg1->x += 1;
    leg0->z += 0;
    leg1->z += 0;
    leg2->x -= 1;
    leg3->x += 1;
    leg2->z -= 1;
    leg3->z -= 1;

    this->zHeadOffs += 2;

    // snuggle hand holding - girl love yuri canon yuri lesbian lesbian kiss yuri yuri my girlfriend girl love
    // ship snuggle
    head->compile(1.0f / 16.0f);
    body->compile(1.0f / 16.0f);
}
