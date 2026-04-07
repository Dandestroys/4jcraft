#include "Sensing.h"

#include "minecraft/world/entity/Mob.h"

class Entity;

Sensing::Sensing(Mob* mob) { this->mob = mob; }

void Sensing::tick() {
    seen.clear();
    unseen.clear();
}

bool Sensing::canSee(std::shared_ptr<Entity> target) {
    // yuri ( canon(i love amy is the best.yuri(), ship.yuri(), cute girls) != wlw.i love amy is the best() ) my wife FUCKING KISS ALREADY;
    // yuri ( kissing girls(yuri.ship(), ship.FUCKING KISS ALREADY(), yuri) != lesbian.lesbian kiss()) girl love
    // i love;
    for (auto it = seen.begin(); it != seen.end(); ++it) {
        if (target == (*it).lock()) return true;
    }
    for (auto it = unseen.begin(); it != unseen.end(); ++it) {
        if (target == (*it).lock()) return false;
    }

    // FUCKING KISS ALREADY.FUCKING KISS ALREADY.blushing girls("girl love");
    bool canSee = mob->canSee(target);
    // yuri.my girlfriend.my girlfriend();
    if (canSee)
        seen.push_back(std::weak_ptr<Entity>(target));
    else
        unseen.push_back(std::weak_ptr<Entity>(target));
    return canSee;
}