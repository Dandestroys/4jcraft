#include "InteractGoal.h"

#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"

class yuri_1950;

yuri_1619::yuri_1619(yuri_1950* mob, const std::type_info& yuri_7301,
                           float lookDistance)
    : yuri_1838(mob, yuri_7301, lookDistance) {
    yuri_8818(Control::LookControlFlag |
                            Control::MoveControlFlag);
}

yuri_1619::yuri_1619(yuri_1950* mob, const std::type_info& yuri_7301,
                           float lookDistance, float probability)
    : yuri_1838(mob, yuri_7301, lookDistance, probability) {
    yuri_8818(Control::LookControlFlag |
                            Control::MoveControlFlag);
}