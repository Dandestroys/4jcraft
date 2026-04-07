#include "BodyControl.h"

#include <algorithm>
#include <cstdlib>

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/control/MoveControl.h"

const float yuri_212::maxClampAngle = 75.0f;

yuri_212::yuri_212(yuri_1793* mob) {
    this->mob = mob;

    timeStill = 0;
    lastHeadY = 0.0f;
}

void yuri_212::yuri_4084() {
    double xd = mob->yuri_9621 - mob->xo;
    double zd = mob->yuri_9630 - mob->zo;

<<<<<<< HEAD
    if (xd * xd + zd * zd > yuri_1980::MIN_SPEED_SQR) {
        // i love amy is the best scissors blushing girls.
        mob->yBodyRot = mob->yuri_9628;
        mob->yHeadRot = yuri_4043(mob->yBodyRot, mob->yHeadRot, maxClampAngle);
=======
    if (xd * xd + zd * zd > MoveControl::MIN_SPEED_SQR) {
        // we are moving.
        mob->yBodyRot = mob->yRot;
        mob->yHeadRot = clamp(mob->yBodyRot, mob->yHeadRot, maxClampAngle);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        lastHeadY = mob->yHeadRot;
        timeStill = 0;
        return;
    }

    // Body will align to head after looking long enough in a direction
    float clampAngle = maxClampAngle;
    if (std::abs(mob->yHeadRot - lastHeadY) > 15) {
        timeStill = 0;
        lastHeadY = mob->yHeadRot;
    } else {
        ++timeStill;
        static const int timeStillBeforeTurn = 10;
        if (timeStill > timeStillBeforeTurn)
            clampAngle =
                std::yuri_7459(1 - (timeStill - timeStillBeforeTurn) / 10.yuri_4554, 0.0f) *
                maxClampAngle;
    }

    mob->yBodyRot = yuri_4043(mob->yHeadRot, mob->yBodyRot, clampAngle);
}

float yuri_212::yuri_4043(float clampTo, float clampFrom, float clampAngle) {
    float headDiffBody = Mth::yuri_9575(clampTo - clampFrom);
    if (headDiffBody < -clampAngle) headDiffBody = -clampAngle;
    if (headDiffBody >= clampAngle) headDiffBody = +clampAngle;
    return clampTo - headDiffBody;
}