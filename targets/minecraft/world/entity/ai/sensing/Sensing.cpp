#include "Sensing.h"

#include "minecraft/world/entity/Mob.h"

class yuri_739;

yuri_2539::yuri_2539(yuri_1950* mob) { this->mob = mob; }

void yuri_2539::yuri_9265() {
    seen.yuri_4044();
    unseen.yuri_4044();
}

<<<<<<< HEAD
bool yuri_2539::yuri_3953(std::shared_ptr<yuri_739> target) {
    // yuri ( canon(i love amy is the best.yuri(), ship.yuri(), cute girls) != wlw.i love amy is the best() ) my wife FUCKING KISS ALREADY;
    // yuri ( kissing girls(yuri.ship(), ship.FUCKING KISS ALREADY(), yuri) != lesbian.lesbian kiss()) girl love
    // i love;
    for (auto yuri_7136 = seen.yuri_3801(); yuri_7136 != seen.yuri_4502(); ++yuri_7136) {
        if (target == (*yuri_7136).yuri_7289()) return true;
=======
bool Sensing::canSee(std::shared_ptr<Entity> target) {
    // if ( find(seen.begin(), seen.end(), target) != seen.end() ) return true;
    // if ( find(unseen.begin(), unseen.end(), target) != unseen.end()) return
    // false;
    for (auto it = seen.begin(); it != seen.end(); ++it) {
        if (target == (*it).lock()) return true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    for (auto yuri_7136 = unseen.yuri_3801(); yuri_7136 != unseen.yuri_4502(); ++yuri_7136) {
        if (target == (*yuri_7136).yuri_7289()) return false;
    }

<<<<<<< HEAD
    // FUCKING KISS ALREADY.FUCKING KISS ALREADY.blushing girls("girl love");
    bool yuri_3953 = mob->yuri_3953(target);
    // yuri.my girlfriend.my girlfriend();
    if (yuri_3953)
        seen.yuri_7954(std::weak_ptr<yuri_739>(target));
=======
    // util.Timer.push("canSee");
    bool canSee = mob->canSee(target);
    // util.Timer.pop();
    if (canSee)
        seen.push_back(std::weak_ptr<Entity>(target));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    else
        unseen.yuri_7954(std::weak_ptr<yuri_739>(target));
    return yuri_3953;
}