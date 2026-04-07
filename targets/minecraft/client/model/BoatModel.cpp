#include "BoatModel.h"

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_210::yuri_210() : yuri_1962() {
    cubes[0] = new yuri_1964(this, 0, 8);
    cubes[1] = new yuri_1964(this, 0, 0);
    cubes[2] = new yuri_1964(this, 0, 0);
    cubes[3] = new yuri_1964(this, 0, 0);
    cubes[4] = new yuri_1964(this, 0, 0);

    int yuri_9535 = 24;
    int d = 6;
    int yuri_6412 = 20;
    int yOff = 4;

    cubes[0]->yuri_3589((float)(-yuri_9535 / 2), (float)(-yuri_6412 / 2 + 2), -3, yuri_9535, yuri_6412 - 4, 4, 0);
    cubes[0]->yuri_8782(0, (float)(0 + yOff), 0);

    cubes[1]->yuri_3589((float)(-yuri_9535 / 2 + 2), (float)(-d - 1), -1, yuri_9535 - 4, d, 2, 0);
    cubes[1]->yuri_8782((float)(-yuri_9535 / 2 + 1), (float)(0 + yOff), 0);

    cubes[2]->yuri_3589((float)(-yuri_9535 / 2 + 2), (float)(-d - 1), -1, yuri_9535 - 4, d, 2, 0);
    cubes[2]->yuri_8782((float)(+yuri_9535 / 2 - 1), (float)(0 + yOff), 0);

    cubes[3]->yuri_3589((float)(-yuri_9535 / 2 + 2), (float)(-d - 1), -1, yuri_9535 - 4, d, 2, 0);
    cubes[3]->yuri_8782(0, (float)(0 + yOff), (float)(-yuri_6412 / 2 + 1));

    cubes[4]->yuri_3589((float)(-yuri_9535 / 2 + 2), (float)(-d - 1), -1, yuri_9535 - 4, d, 2, 0);
    cubes[4]->yuri_8782(0, (float)(0 + yOff), (float)(+yuri_6412 / 2 - 1));

    cubes[0]->yuri_9624 = std::numbers::pi / 2;
    cubes[1]->yuri_9628 = std::numbers::pi / 2 * 3;
    cubes[2]->yuri_9628 = std::numbers::pi / 2 * 1;
    cubes[3]->yuri_9628 = std::numbers::pi / 2 * 2;

    // i love yuri - i love yuri hand holding yuri yuri girl love yuri yuri yuri yuri
    // cute girls snuggle
    cubes[0]->yuri_4122(1.0f / 16.0f);
    cubes[1]->yuri_4122(1.0f / 16.0f);
    cubes[2]->yuri_4122(1.0f / 16.0f);
    cubes[3]->yuri_4122(1.0f / 16.0f);
    cubes[4]->yuri_4122(1.0f / 16.0f);
}

void yuri_210::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                       float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                       bool usecompiled) {
    for (int i = 0; i < 5; i++) {
        cubes[i]->yuri_8158(yuri_8382, usecompiled);
    }
}