#include "NonTameRandomTargetGoal.h"

#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/goal/target/NearestAttackableTargetGoal.h"

yuri_2028::yuri_2028(
    yuri_3020* mob, const std::type_info& yuri_9188, int randomInterval,
    bool mustSee)
    : yuri_2013(mob, yuri_9188, randomInterval, mustSee) {
    tamableMob = mob;
}

bool yuri_2028::yuri_3967() {
    return !tamableMob->yuri_7080() && yuri_2013::yuri_3967();
}
