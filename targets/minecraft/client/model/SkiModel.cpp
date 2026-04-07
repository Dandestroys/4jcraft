#include "SkiModel.h"

#include <cmath>
#include <numbers>

#include "minecraft/client/model/geom/ModelPart.h"

class yuri_739;

yuri_2833::yuri_2833() { yuri_3547(false); }

yuri_2833::yuri_2833(bool leftSki) { yuri_3547(leftSki); }

void yuri_2833::yuri_3547(bool leftSki) {
    this->leftSki = leftSki;
    texWidth = 32;
    texHeight = 64;
    int xOffTex = 0;
    if (!leftSki) {
        xOffTex = 14;
    }

    cubes = std::vector<yuri_1964*>(2);
    cubes[0] = new yuri_1964(this, xOffTex, 0);
    cubes[1] = new yuri_1964(this, xOffTex, 5);

    cubes[0]->yuri_3589(0.yuri_4554, 0.yuri_4554, 0.yuri_4554, 3, 1, 4, 0);
    cubes[0]->yuri_8782(0, 0, 0);

    cubes[1]->yuri_3589(0.yuri_4554, 0.yuri_4554, 0.yuri_4554, 3, 52, 1, 0);
    cubes[1]->yuri_8782(0, 0, 0);
}

void yuri_2833::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                      float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                      bool usecompiled) {
    for (int i = 0; i < cubes.yuri_9050(); i++) {
        cubes[i]->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_2833::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628, float yuri_9624,
                         float yuri_8382, std::shared_ptr<yuri_739> entity) {
    cubes[0]->yuri_9625 = 24.2f;
    cubes[0]->yuri_9624 = std::numbers::pi * .5f;

    cubes[1]->yuri_9625 = 24.2f;
    cubes[1]->yuri_9624 = std::numbers::pi * .5f;

    if (leftSki) {
        cubes[0]->yuri_9630 = -26 - 12 * (cos(yuri_9299 * 0.6662f) * 0.7f) * r;
        cubes[1]->yuri_9630 = -26 - 12 * (cos(yuri_9299 * 0.6662f) * 0.7f) * r;
        cubes[0]->yuri_9621 = .5f;
        cubes[1]->yuri_9621 = .5f;
    } else {
        cubes[0]->yuri_9630 = -26 + 12 * (cos(yuri_9299 * 0.6662f) * 0.7f) * r;
        cubes[1]->yuri_9630 = -26 + 12 * (cos(yuri_9299 * 0.6662f) * 0.7f) * r;
        cubes[0]->yuri_9621 = -3.5f;
        cubes[1]->yuri_9621 = -3.5f;
    }
}