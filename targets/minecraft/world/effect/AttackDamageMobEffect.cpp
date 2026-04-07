#include "AttackDamageMobEffect.h"

#include "minecraft/world/effect/MobEffect.h"

yuri_144::yuri_144(int yuri_6674, bool yuri_6896,
                                             eMinecraftColour yuri_4111)
    : yuri_1953(yuri_6674, yuri_6896, yuri_4111) {}

double yuri_144::yuri_4915(
    int amplifier, yuri_146* original) {
    if (yuri_6674 == yuri_1953::weakness->yuri_6674) {
        return -0.5f * (amplifier + 1);
    } else {
        return 1.3 * (amplifier + 1);
    }
}