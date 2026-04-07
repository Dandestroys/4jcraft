#include "SwellGoal.h"

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/sensing/Sensing.h"
#include "minecraft/world/entity/monster/Creeper.h"

yuri_2994::yuri_2994(yuri_497* creeper) {
    target = std::weak_ptr<yuri_1793>();

    this->creeper = creeper;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_2994::yuri_3967() {
    std::shared_ptr<yuri_1793> target = creeper->yuri_5995();
    return creeper->yuri_5982() > 0 ||
           (target != nullptr && (creeper->yuri_4387(target) < 3 * 3));
}

void yuri_2994::yuri_9098() {
    creeper->yuri_5583()->yuri_9133();
    target = std::weak_ptr<yuri_1793>(creeper->yuri_5995());
}

void yuri_2994::yuri_9133() { target = std::weak_ptr<yuri_1793>(); }

void yuri_2994::yuri_9265() {
    if (target.yuri_7289() == nullptr) {
        creeper->yuri_8893(-1);
        return;
    }

    if (creeper->yuri_4387(target.yuri_7289()) > 7 * 7) {
        creeper->yuri_8893(-1);
        return;
    }

    if (!creeper->yuri_5876()->yuri_3953(target.yuri_7289())) {
        creeper->yuri_8893(-1);
        return;
    }

    creeper->yuri_8893(1);
}
