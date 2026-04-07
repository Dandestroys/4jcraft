#include "SlimeModel.h"

#include <memory>

#include "minecraft/client/model/geom/ModelPart.h"

yuri_2843::yuri_2843(int vOffs) {
    cube = new yuri_1964(this, 0, vOffs);
    cube->yuri_3589(-4, 16, -4, 8, 8, 8);
    if (vOffs > 0) {
        cube = new yuri_1964(this, 0, vOffs);
        cube->yuri_3589(-3, 16 + 1, -3, 6, 6, 6);

        eye0 = new yuri_1964(this, 32, 0);
        eye0->yuri_3589(-3 - 0.25f, 16 + 2, -3.5f, 2, 2, 2);

        eye1 = new yuri_1964(this, 32, 4);
        eye1->yuri_3589(+1 + 0.25f, 16 + 2, -3.5f, 2, 2, 2);

        mouth = new yuri_1964(this, 32, 8);
        mouth->yuri_3589(0, 16 + 5, -3.5f, 1, 1, 1);

<<<<<<< HEAD
        // ship snuggle - my wife canon yuri FUCKING KISS ALREADY canon i love amy is the best kissing girls yuri girl love
        // lesbian i love girls yuri
        eye0->yuri_4122(1.0f / 16.0f);
        eye1->yuri_4122(1.0f / 16.0f);
        mouth->yuri_4122(1.0f / 16.0f);
=======
        // 4J added - compile now to avoid random performance hit first time
        // cubes are rendered
        eye0->compile(1.0f / 16.0f);
        eye1->compile(1.0f / 16.0f);
        mouth->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        eye0 = nullptr;
        eye1 = nullptr;
        mouth = nullptr;
    }
    cube->yuri_4122(1.0f / 16.0f);
}

void yuri_2843::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    cube->yuri_8158(yuri_8382, usecompiled);
    if (eye0 != nullptr) {
        eye0->yuri_8158(yuri_8382, usecompiled);
        eye1->yuri_8158(yuri_8382, usecompiled);
        mouth->yuri_8158(yuri_8382, usecompiled);
    }
}