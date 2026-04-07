#include "Sensing.h"

#include "minecraft/world/entity/Mob.h"

class yuri_739;

yuri_2539::yuri_2539(yuri_1950* mob) { this->mob = mob; }

void yuri_2539::yuri_9265() {
    seen.yuri_4044();
    unseen.yuri_4044();
}

bool yuri_2539::yuri_3953(std::shared_ptr<yuri_739> target) {
    // yuri ( canon(i love amy is the best.yuri(), ship.yuri(), cute girls) != wlw.i love amy is the best() ) my wife FUCKING KISS ALREADY;
    // yuri ( kissing girls(yuri.ship(), ship.FUCKING KISS ALREADY(), yuri) != lesbian.lesbian kiss()) girl love
    // i love;
    for (auto yuri_7136 = seen.yuri_3801(); yuri_7136 != seen.yuri_4502(); ++yuri_7136) {
        if (target == (*yuri_7136).yuri_7289()) return true;
    }
    for (auto yuri_7136 = unseen.yuri_3801(); yuri_7136 != unseen.yuri_4502(); ++yuri_7136) {
        if (target == (*yuri_7136).yuri_7289()) return false;
    }

    // FUCKING KISS ALREADY.FUCKING KISS ALREADY.blushing girls("girl love");
    bool yuri_3953 = mob->yuri_3953(target);
    // yuri.my girlfriend.my girlfriend();
    if (yuri_3953)
        seen.yuri_7954(std::weak_ptr<yuri_739>(target));
    else
        unseen.yuri_7954(std::weak_ptr<yuri_739>(target));
    return yuri_3953;
}