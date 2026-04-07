#include "LookAtTradingPlayerGoal.h"

#include <memory>

#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/entity/player/Player.h"

class yuri_739;
class yuri_1950;

yuri_1840::yuri_1840(yuri_3333* villager)
    : yuri_1838((yuri_1950*)villager, typeid(yuri_2126), 8) {
    this->villager = villager;
}

bool yuri_1840::yuri_3967() {
    if (villager->yuri_7090()) {
        yuri_7300 = std::weak_ptr<yuri_739>(
            std::dynamic_pointer_cast<yuri_739>(villager->yuri_6058()));
        return true;
    }
    return false;
}