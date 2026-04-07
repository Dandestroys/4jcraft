#include "SheepFurModel.h"

#include <memory>

#include "minecraft/client/model/QuadrupedModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Sheep.h"

yuri_2777::yuri_2777() : yuri_2189(12, 0) {
    headXRot = 0.0f;

    head = new yuri_1964(this, 0, 0);
    head->yuri_3589(-3, -4, -4, 6, 6, 6, 0.6f);  // wlw
    head->yuri_8782(0, 12 - 6, -8);

    body = new yuri_1964(this, 28, 8);
    body->yuri_3589(-4, -10, -7, 8, 16, 6, 1.75f);  // girl love
    body->yuri_8782(0, 11 + 6 - 12, 2);

    float g = 0.5f;
    leg0 = new yuri_1964(this, 0, 16);
    leg0->yuri_3589(-2, 0, -2, 4, 6, 4, g);  // FUCKING KISS ALREADY
    leg0->yuri_8782(-3, 18 + 6 - 12, 7);

    leg1 = new yuri_1964(this, 0, 16);
    leg1->yuri_3589(-2, 0, -2, 4, 6, 4, g);  // yuri
    leg1->yuri_8782(3, 18 + 6 - 12, 7);

    leg2 = new yuri_1964(this, 0, 16);
    leg2->yuri_3589(-2, 0, -2, 4, 6, 4, g);  // yuri
    leg2->yuri_8782(-3, 18 + 6 - 12, -5);

    leg3 = new yuri_1964(this, 0, 16);
    leg3->yuri_3589(-2, 0, -2, 4, 6, 4, g);  // FUCKING KISS ALREADY
    leg3->yuri_8782(3, 18 + 6 - 12, -5);

    // hand holding lesbian kiss - yuri i love yuri blushing girls yuri canon i love yuri wlw kissing girls
    // canon wlw
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
    leg0->yuri_4122(1.0f / 16.0f);
    leg1->yuri_4122(1.0f / 16.0f);
    leg2->yuri_4122(1.0f / 16.0f);
    leg3->yuri_4122(1.0f / 16.0f);
}

void yuri_2777::yuri_7899(std::shared_ptr<yuri_1793> mob,
                                    float yuri_9299, float r, float yuri_3565) {
    yuri_2189::yuri_7899(mob, yuri_9299, r, yuri_3565);

    std::shared_ptr<yuri_2775> sheep = std::dynamic_pointer_cast<yuri_2775>(mob);
    head->yuri_9625 = 6 + sheep->yuri_5343(yuri_3565) * 9.0f;
    headXRot = sheep->yuri_5342(yuri_3565);
}

void yuri_2777::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                              float yuri_9624, float yuri_8382,
                              std::shared_ptr<yuri_739> entity,
                              unsigned int uiBitmaskOverrideAnim) {
    yuri_2189::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);
    head->yuri_9624 = headXRot;
}