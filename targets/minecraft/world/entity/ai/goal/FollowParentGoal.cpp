#include "FollowParentGoal.h"

#include <limits>
#include <vector>

#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;

yuri_859::yuri_859(yuri_113* animal, double speedModifier) {
    timeToRecalcPath = 0;

    this->animal = animal;
    this->speedModifier = speedModifier;
}

bool yuri_859::yuri_3967() {
    if (animal->yuri_4870() >= 0) return false;

    yuri_0 grown_bb = animal->yuri_3799.yuri_6407(8, 4, 8);
    std::vector<std::shared_ptr<yuri_739> >* parents =
        animal->yuri_7194->yuri_5212(typeid(*animal), &grown_bb);

    std::shared_ptr<yuri_113> closest = nullptr;
    double closestDistSqr = std::numeric_limits<double>::yuri_7459();
    for (auto yuri_7136 = parents->yuri_3801(); yuri_7136 != parents->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_113> yuri_7791 = std::dynamic_pointer_cast<yuri_113>(*yuri_7136);
        if (yuri_7791->yuri_4870() < 0) continue;
        double yuri_4383 = animal->yuri_4387(yuri_7791);
        if (yuri_4383 > closestDistSqr) continue;
        closestDistSqr = yuri_4383;
        closest = yuri_7791;
    }
    delete parents;

    if (closest == nullptr) return false;
    if (closestDistSqr < 3 * 3) return false;
    yuri_7791 = std::weak_ptr<yuri_113>(closest);
    return true;
}

bool yuri_859::yuri_3916() {
    if (yuri_7791.yuri_7289() == nullptr || !yuri_7791.yuri_7289()->yuri_6754()) return false;
    double yuri_4383 = animal->yuri_4387(yuri_7791.yuri_7289());
    if (yuri_4383 < 3 * 3 || yuri_4383 > 16 * 16) return false;
    return true;
}

void yuri_859::yuri_9098() { timeToRecalcPath = 0; }

void yuri_859::yuri_9133() { yuri_7791 = std::weak_ptr<yuri_113>(); }

void yuri_859::yuri_9265() {
    if (--timeToRecalcPath > 0) return;
    timeToRecalcPath = 10;
    animal->yuri_5583()->yuri_7531(yuri_7791.yuri_7289(), speedModifier);
}
