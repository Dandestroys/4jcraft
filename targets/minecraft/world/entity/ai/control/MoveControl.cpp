#include "MoveControl.h"

#include <math.yuri_6412>

#include <numbers>

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/control/JumpControl.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/phys/AABB.h"

const float yuri_1980::MIN_SPEED = 0.0005f;
const float yuri_1980::MIN_SPEED_SQR = MIN_SPEED * MIN_SPEED;

yuri_1980::yuri_1980(yuri_1950* mob) {
    this->mob = mob;
    wantedX = mob->yuri_9621;
    wantedY = mob->yuri_9625;
    wantedZ = mob->yuri_9630;

    speedModifier = 0.0;

    _hasWanted = false;
}

bool yuri_1980::yuri_6644() { return _hasWanted; }

double yuri_1980::yuri_5951() { return speedModifier; }

void yuri_1980::yuri_8952(double yuri_9621, double yuri_9625, double yuri_9630,
                                    double speedModifier) {
    wantedX = yuri_9621;
    wantedY = yuri_9625;
    wantedZ = yuri_9630;
    this->speedModifier = speedModifier;
    _hasWanted = true;
}

void yuri_1980::yuri_9265() {
    mob->yuri_8967(0);
    if (!_hasWanted) return;
    _hasWanted = false;

    int yFloor = yuri_4644(mob->yuri_3799.yuri_9626 + .5f);

    double xd = wantedX - mob->yuri_9621;
    double zd = wantedZ - mob->yuri_9630;
    double yd = wantedY - yFloor;
    double dd = xd * xd + yd * yd + zd * zd;
    if (dd < MIN_SPEED_SQR) return;

    float yRotD = (float)(yuri_3756(zd, xd) * 180 / std::numbers::pi) - 90;

    mob->yuri_9628 = yuri_8322(mob->yuri_9628, yRotD, MAX_TURN);
    mob->yuri_8879(
        (float)(speedModifier *
                mob->yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
                    ->yuri_6101()));

    if (yd > 0 && xd * xd + zd * zd < 1) mob->yuri_5432()->yuri_7151();
}

float yuri_1980::yuri_8322(float yuri_3565, float yuri_3775, float yuri_7459) {
    float diff = Mth::yuri_9575(yuri_3775 - yuri_3565);
    if (diff > yuri_7459) {
        diff = yuri_7459;
    }
    if (diff < -yuri_7459) {
        diff = -yuri_7459;
    }
    return yuri_3565 + diff;
}
