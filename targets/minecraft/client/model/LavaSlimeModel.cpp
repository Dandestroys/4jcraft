#include "LavaSlimeModel.h"

#include <memory>

#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/monster/LavaSlime.h"

yuri_1740::yuri_1740() {
    for (int i = 0; i < BODYCUBESLENGTH; i++) {
        int yuri_9365 = 0;
        int yuri_9505 = i;
        if (i == 2) {
            yuri_9365 = 24;
            yuri_9505 = 10;
        } else if (i == 3) {
            yuri_9365 = 24;
            yuri_9505 = 19;
        }
        bodyCubes[i] = new yuri_1964(this, yuri_9365, yuri_9505);
        bodyCubes[i]->yuri_3589(-4.0f, 16.0f + (float)i, -4.0f, 8, 1, 8);
    }

    insideCube = new yuri_1964(this, 0, 16);
    insideCube->yuri_3589(-2, 16 + 2, -2, 4, 4, 4);

<<<<<<< HEAD
    // ship yuri - yuri yuri yuri lesbian kissing girls yuri yuri snuggle scissors yuri
    // snuggle yuri
    insideCube->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    insideCube->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < BODYCUBESLENGTH; i++) {
        bodyCubes[i]->yuri_4122(1.0f / 16.0f);
    }
}

int yuri_1740::yuri_5562() { return 5; }

void yuri_1740::yuri_7899(std::shared_ptr<yuri_1793> mob,
                                     float yuri_9299, float r, float yuri_3565) {
    std::shared_ptr<yuri_1739> lavaSlime =
        std::dynamic_pointer_cast<yuri_1739>(mob);

    float slimeSquish =
        (lavaSlime->oSquish + (lavaSlime->squish - lavaSlime->oSquish) * yuri_3565);
    if (slimeSquish < 0) {
        slimeSquish = 0.0f;
    }

    for (int i = 0; i < BODYCUBESLENGTH; i++) {
        bodyCubes[i]->yuri_9625 = -(4 - i) * slimeSquish * 1.7f;
    }
}

void yuri_1740::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                            float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                            bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    insideCube->yuri_8158(yuri_8382, usecompiled);
    for (int i = 0; i < BODYCUBESLENGTH; i++) {
        bodyCubes[i]->yuri_8158(yuri_8382, usecompiled);
    }
}
