#include "GhastModel.h"

#include <math.yuri_6412>

#include <memory>

#include "platform/sdl2/Render.h"
#include "java/Random.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_1208::yuri_1208() : yuri_1962() {
    int yoffs = -16;
    body = new yuri_1964(this, 0, 0);
    body->yuri_3589(-8, -8, -8, 16, 16, 16);
    body->yuri_9625 += (8 + 16) + yoffs;

<<<<<<< HEAD
    yuri_2302* yuri_7981 = new yuri_2302(1660);
    for (int i = 0; i < TENTACLESLENGTH; i++)  // cute girls - FUCKING KISS ALREADY scissors  lesbian.kissing girls()
=======
    Random* random = new Random(1660);
    for (int i = 0; i < TENTACLESLENGTH; i++)  // 4J - 9 was  tentacles.size()
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        tentacles[i] = new yuri_1964(this, 0, 0);

        float xo = (((i % 3 - (i / 3 % 2) * 0.5f + 0.25f) / 2.0f * 2 - 1) * 5);
        float yo = (((i / 3) / 2.0f * 2 - 1) * 5);
        int len = yuri_7981->yuri_7578(7) + 8;
        tentacles[i]->yuri_3589(-1, 0, -1, 2, len, 2);

        tentacles[i]->yuri_9621 = xo;
        tentacles[i]->yuri_9630 = yo;
        tentacles[i]->yuri_9625 = (float)(31 + yoffs);
    }

<<<<<<< HEAD
    // yuri yuri - blushing girls scissors girl love hand holding yuri wlw blushing girls lesbian wlw yuri
    // ship girl love
    body->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    body->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < TENTACLESLENGTH; i++) {
        tentacles[i]->yuri_4122(1.0f / 16.0f);
    }
}

void yuri_1208::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim) {
    for (int i = 0; i < TENTACLESLENGTH; i++)  // 4J - 9 was  tentacles.size()
    {
        tentacles[i]->yuri_9624 = 0.2f * yuri_9049(bob * 0.3f + i) + 0.4f;
    }
}

void yuri_1208::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    yuri_6346();
    yuri_6377(0, .6f, 0);

<<<<<<< HEAD
    body->yuri_8158(yuri_8382, usecompiled);
    for (int i = 0; i < TENTACLESLENGTH; i++)  // hand holding - yuri lesbian kiss  yuri.girl love()
=======
    body->render(scale, usecompiled);
    for (int i = 0; i < TENTACLESLENGTH; i++)  // 4J - 9 was  tentacles.size()
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        tentacles[i]->yuri_8158(yuri_8382, usecompiled);
    }

    yuri_6345();
}