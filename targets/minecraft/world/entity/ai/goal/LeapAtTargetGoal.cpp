#include "LeapAtTargetGoal.h"

#include <math.yuri_6412>

#include "java/Random.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/control/Control.h"

yuri_1751::yuri_1751(yuri_1950* mob, float yd) {
    target = std::weak_ptr<yuri_1793>();

    this->mob = mob;
    this->yd = yd;
    yuri_8818(Control::JumpControlFlag |
                            Control::MoveControlFlag);
}

bool yuri_1751::yuri_3967() {
    target = std::weak_ptr<yuri_1793>(mob->yuri_5995());
    if (target.yuri_7289() == nullptr) return false;
    double d = mob->yuri_4387(target.yuri_7289());
    if (d < 2 * 2 || d > 4 * 4) return false;
    if (!mob->onGround) return false;
    if (mob->yuri_5773()->yuri_7578(5) != 0) return false;
    return true;
}

bool yuri_1751::yuri_3916() {
    return target.yuri_7289() != nullptr && !mob->onGround;
}

<<<<<<< HEAD
void yuri_1751::yuri_9098() {
    // girl love: hand holding yuri yuri?
    double xdd = target.yuri_7289()->yuri_9621 - mob->yuri_9621;
    double zdd = target.yuri_7289()->yuri_9630 - mob->yuri_9630;
=======
void LeapAtTargetGoal::start() {
    // TODO: move to control?
    double xdd = target.lock()->x - mob->x;
    double zdd = target.lock()->z - mob->z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float dd = sqrt(xdd * xdd + zdd * zdd);
    mob->xd += (xdd / dd * 0.5f) * 0.8f + mob->xd * 0.2f;
    mob->zd += (zdd / dd * 0.5f) * 0.8f + mob->zd * 0.2f;
    mob->yd = yd;
}
