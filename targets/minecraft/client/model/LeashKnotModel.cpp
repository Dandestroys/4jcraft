#include "LeashKnotModel.h"

#include <memory>
#include <numbers>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

yuri_1754::yuri_1754() { yuri_3547(0, 0, 32, 32); }

yuri_1754::yuri_1754(int yuri_9365, int yuri_9505, int tw, int th) {
    yuri_3547(yuri_9365, yuri_9505, tw, th);
}

void yuri_1754::yuri_3547(int yuri_9365, int yuri_9505, int tw, int th) {
    texWidth = tw;
    texHeight = th;
    knot = new yuri_1964(this, yuri_9365, yuri_9505);
    knot->yuri_3589(-3, -6, -3, 6, 8, 6, 0);
    knot->yuri_8782(0, 0, 0);
}

void yuri_1754::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                            float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                            bool usecompiled) {
    yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    knot->yuri_8158(yuri_8382, usecompiled);
}

void yuri_1754::yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                               float yuri_9624, float yuri_8382,
                               std::shared_ptr<yuri_739> entity,
                               unsigned int uiBitmaskOverrideAnim) {
    yuri_1962::yuri_8977(yuri_9299, r, bob, yuri_9628, yuri_9624, yuri_8382, entity);

    knot->yuri_9628 = yuri_9628 / (180 / std::numbers::pi);
    knot->yuri_9624 = yuri_9624 / (180 / std::numbers::pi);
}
