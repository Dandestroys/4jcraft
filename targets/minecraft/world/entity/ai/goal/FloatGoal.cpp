#include "FloatGoal.h"

#include "java/Random.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/JumpControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"

yuri_850::yuri_850(yuri_1950* mob) {
    this->mob = mob;
    yuri_8818(Control::JumpControlFlag);
    mob->yuri_5583()->yuri_8500(true);
}

bool yuri_850::yuri_3967() { return (mob->yuri_6920() || mob->yuri_6915()); }

void yuri_850::yuri_9265() {
    if (mob->yuri_5773()->yuri_7576() < 0.8f) mob->yuri_5432()->yuri_7151();
}