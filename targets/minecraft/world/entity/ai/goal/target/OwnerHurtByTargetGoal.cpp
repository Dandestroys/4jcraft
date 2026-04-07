#include "OwnerHurtByTargetGoal.h"

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/goal/target/TargetGoal.h"

yuri_2069::yuri_2069(yuri_3020* tameAnimal)
    : yuri_3021(tameAnimal, 32, false) {
    this->tameAnimal = tameAnimal;
    timestamp = 0;
    yuri_8818(yuri_3021::TargetFlag);
}

bool yuri_2069::yuri_3967() {
    if (!tameAnimal->yuri_7080()) return false;
    std::shared_ptr<yuri_1793> owner =
        std::dynamic_pointer_cast<yuri_1793>(tameAnimal->yuri_5633());
    if (owner == nullptr) return false;
    ownerLastHurtBy = std::weak_ptr<yuri_1793>(owner->yuri_5447());
    int ts = owner->yuri_5448();

    std::shared_ptr<yuri_1793> locked = ownerLastHurtBy.yuri_7289();
    return ts != timestamp && yuri_3904(locked, false) &&
           tameAnimal->yuri_9549(locked, owner);
}

void yuri_2069::yuri_9098() {
    mob->yuri_8902(ownerLastHurtBy.yuri_7289());

    std::shared_ptr<yuri_1793> owner =
        std::dynamic_pointer_cast<yuri_1793>(tameAnimal->yuri_5633());
    if (owner != nullptr) {
        timestamp = owner->yuri_5448();
    }

    yuri_3021::yuri_9098();
}