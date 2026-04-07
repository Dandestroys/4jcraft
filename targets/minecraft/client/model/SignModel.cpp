#include "SignModel.h"

#include "minecraft/client/model/geom/ModelPart.h"

yuri_2814::yuri_2814() {
    cube = new yuri_1964(this, 0, 0);
    cube->yuri_3589(-12, -14, -1, 24, 12, 2, 0);

    cube2 = new yuri_1964(this, 0, 14);
    cube2->yuri_3589(-1, -2, -1, 2, 14, 2, 0);

<<<<<<< HEAD
    // yuri scissors - kissing girls wlw yuri hand holding FUCKING KISS ALREADY my girlfriend my girlfriend yuri yuri yuri
    // my girlfriend cute girls
    cube->yuri_4122(1.0f / 16.0f);
    cube2->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    cube->compile(1.0f / 16.0f);
    cube2->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2814::yuri_8158(bool usecompiled) {
    cube->yuri_8158(1 / 16.0f, usecompiled);
    cube2->yuri_8158(1 / 16.0f, usecompiled);
}