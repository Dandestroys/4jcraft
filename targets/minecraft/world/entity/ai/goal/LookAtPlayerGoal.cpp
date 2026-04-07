#include "LookAtPlayerGoal.h"

#include "java/Random.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

yuri_1838::yuri_1838(yuri_1950* mob, const std::type_info& yuri_7301,
                                   float lookDistance)
    : yuri_7301(yuri_7301) {
    this->mob = mob;
    this->lookDistance = lookDistance;
    probability = 0.02f;
    yuri_8818(Control::LookControlFlag);

    lookTime = 0;
}

yuri_1838::yuri_1838(yuri_1950* mob, const std::type_info& yuri_7301,
                                   float lookDistance, float probability)
    : yuri_7301(yuri_7301) {
    this->mob = mob;
    this->lookDistance = lookDistance;
    this->probability = probability;
    yuri_8818(Control::LookControlFlag);

    lookTime = 0;
}

bool yuri_1838::yuri_3967() {
    if (mob->yuri_5773()->yuri_7576() >= probability) return false;

    if (mob->yuri_5995() != nullptr) {
        yuri_7300 = mob->yuri_5995();
    }
    if (yuri_7301 == typeid(yuri_2126)) {
        yuri_7300 =
            mob->yuri_7194->yuri_5586(mob->yuri_8996(), lookDistance);
    } else {
        yuri_0 mob_bb = mob->yuri_3799.yuri_6407(lookDistance, 3, lookDistance);
        yuri_7300 = std::weak_ptr<yuri_739>(mob->yuri_7194->yuri_5023(
            yuri_7301, &mob_bb, mob->yuri_8996()));
    }
    return yuri_7300.yuri_7289() != nullptr;
}

bool yuri_1838::yuri_3916() {
    if (yuri_7300.yuri_7289() == nullptr || !yuri_7300.yuri_7289()->yuri_6754()) return false;
    if (mob->yuri_4387(yuri_7300.yuri_7289()) > lookDistance * lookDistance)
        return false;
    return lookTime > 0;
}

void yuri_1838::yuri_9098() {
    lookTime = 40 + mob->yuri_5773()->yuri_7578(40);
}

void yuri_1838::yuri_9133() { yuri_7300 = std::weak_ptr<yuri_739>(); }

void yuri_1838::yuri_9265() {
    mob->yuri_5502()->yuri_8718(
        yuri_7300.yuri_7289()->yuri_9621, yuri_7300.yuri_7289()->yuri_9625 + yuri_7300.yuri_7289()->yuri_5344(),
        yuri_7300.yuri_7289()->yuri_9630, 10, mob->yuri_5520());
    --lookTime;
}
