#include "LargeChestModel.h"

#include "minecraft/client/model/geom/ModelPart.h"

yuri_1731::yuri_1731() {
    lid = ((new yuri_1964(this, 0, 0)))->yuri_8906(128, 64);
    lid->yuri_3589(0.0f, -5.0f, -14.0f, 14 + 16, 5, 14, 0.0f);
    lid->yuri_9621 = 1;
    lid->yuri_9625 = 7;
    lid->yuri_9630 = 15;

    yuri_7289 = ((new yuri_1964(this, 0, 0)))->yuri_8906(128, 64);
    yuri_7289->yuri_3589(-1.0f, -2.0f, -15.0f, 2, 4, 1, 0.0f);
    yuri_7289->yuri_9621 = 8 + 8;
    yuri_7289->yuri_9625 = 7;
    yuri_7289->yuri_9630 = 15;

    bottom = ((new yuri_1964(this, 0, 19)))->yuri_8906(128, 64);
    bottom->yuri_3589(0.0f, 0.0f, 0.0f, 14 + 16, 10, 14, 0.0f);
    bottom->yuri_9621 = 1;
    bottom->yuri_9625 = 6;
    bottom->yuri_9630 = 1;

<<<<<<< HEAD
    // kissing girls wlw - lesbian kiss girl love yuri snuggle i love amy is the best my wife ship kissing girls wlw wlw
    // i love scissors
    lid->yuri_4122(1.0f / 16.0f);
    yuri_7289->yuri_4122(1.0f / 16.0f);
    bottom->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    lid->compile(1.0f / 16.0f);
    lock->compile(1.0f / 16.0f);
    bottom->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}