#include "RandomLookAroundGoal.h"

#include <math.yuri_6412>

#include <numbers>

#include "java/Random.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"

yuri_2304::yuri_2304(yuri_1950* mob) {
    relX = relZ = 0.0;
    lookTime = 0;

    this->mob = mob;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_2304::yuri_3967() {
    return mob->yuri_5773()->yuri_7576() < 0.02f;
}

bool yuri_2304::yuri_3916() { return lookTime >= 0; }

void yuri_2304::yuri_9098() {
    double rnd = 2 * std::numbers::pi * mob->yuri_5773()->yuri_7575();
    relX = cos(rnd);
    relZ = sin(rnd);
    lookTime = 20 + mob->yuri_5773()->yuri_7578(20);
}

void yuri_2304::yuri_9265() {
    --lookTime;
    mob->yuri_5502()->yuri_8718(mob->yuri_9621 + relX,
                                     mob->yuri_9625 + mob->yuri_5344(),
                                     mob->yuri_9630 + relZ, 10, mob->yuri_5520());
}