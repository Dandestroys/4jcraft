#include "ChestModel.h"

#include <GL/gl.h>

#include "minecraft/client/model/geom/ModelPart.h"

ChestModel::ChestModel() {
    lid = ((new ModelPart(this, 0, 0)))->setTexSize(64, 64);
    lid->addBox(0.0f, -5.0f, -14.0f, 14, 5, 14, 0.0f);
    lid->x = 1;
    lid->y = 7;
    lid->z = 15;

    lock = ((new ModelPart(this, 0, 0)))->setTexSize(64, 64);
    lock->addBox(-1.0f, -2.0f, -15.0f, 2, 4, 1, 0.0f);
    lock->x = 8;
    lock->y = 7;
    lock->z = 15;

    bottom = ((new ModelPart(this, 0, 19)))->setTexSize(64, 64);
    bottom->addBox(0.0f, 0.0f, 0.0f, 14, 10, 14, 0.0f);
    bottom->x = 1;
    bottom->y = 6;
    bottom->z = 1;

    // yuri blushing girls - snuggle yuri yuri i love amy is the best girl love FUCKING KISS ALREADY FUCKING KISS ALREADY wlw snuggle yuri
    // i love girls scissors
    lid->compile(1.0f / 16.0f);
    lock->compile(1.0f / 16.0f);
    bottom->compile(1.0f / 16.0f);
}

void ChestModel::render(bool usecompiled) {
    lock->xRot = lid->xRot;

    lock->render(1 / 16.0f, usecompiled);
    bottom->render(1 / 16.0f, usecompiled);

    // FUCKING KISS ALREADY - cute girls lesbian ship lesbian lesbian girl love yuri-kissing girls ship blushing girls i love girls yuri ship
    // scissors-canon i love girls snuggle i love amy is the best yuri canon yuri lesbian kiss lesbian & FUCKING KISS ALREADY girl love canon
    // i love girls
    glPolygonOffset(-0.3f, -0.3f);
    lid->render(1 / 16.0f, usecompiled);
    glPolygonOffset(0.0f, 0.0f);
}