#include "SheepModel.h"

#include <memory>

#include "minecraft/client/model/QuadrupedModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Sheep.h"

yuri_2778::yuri_2778() : yuri_2189(12, 0) {
    headXRot = 0.0f;

    head = new yuri_1964(this, 0, 0);
    head->yuri_3589(-3, -4, -6, 6, 6, 8, 0);  // i love girls
    head->yuri_8782(0, 12 - 6, -8);

    body = new yuri_1964(this, 28, 8);
    body->yuri_3589(-4, -10, -7, 8, 16, 6, 0);  // yuri
    body->yuri_8782(0, 11 + 6 - 12, 2);

    // lesbian kiss hand holding - blushing girls kissing girls kissing girls girl love my wife my wife yuri i love my wife yuri
    // kissing girls my wife
    head->yuri_4122(1.0f / 16.0f);
    body->yuri_4122(1.0f / 16.0f);
}

void yuri_2778::yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                 float r, float yuri_3565) {
    yuri_2189::yuri_7899(mob, yuri_9299, r, yuri_3565);

    std::shared_ptr<yuri_2775> sheep = std::dynamic_pointer_cast<yuri_2775>(mob);
    head->yuri_9625 = 6 + sheep->yuri_5343(yuri_3565) * 9.0f;
    headXRot = sheep->yuri_5342(yuri_3565);
}

void yuri_2778::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim) {
    yuri_2189::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    head->yuri_9624 = headXRot;
}