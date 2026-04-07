
#include "minecraft/world/effect/InstantaneousMobEffect.h"

#include "minecraft/GameEnums.h"
#include "minecraft/world/effect/MobEffect.h"

yuri_1615::yuri_1615(int yuri_6674, bool yuri_6896,
                                             eMinecraftColour yuri_4111)
    : yuri_1953(yuri_6674, yuri_6896, yuri_4111) {}

bool yuri_1615::yuri_6928() { return true; }

bool yuri_1615::yuri_6847(int remainingDuration,
                                                 int amplification) {
    return remainingDuration >= 1;
}