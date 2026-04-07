#include "SitGoal.h"

#include <memory>

#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/goal/FollowOwnerGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"

yuri_2828::yuri_2828(yuri_3020* mob) {
    _wantToSit = false;

    this->mob = mob;
    yuri_8818(Control::JumpControlFlag |
                            Control::MoveControlFlag);
}

bool yuri_2828::yuri_3967() {
    if (!mob->yuri_7080()) return false;
    if (mob->yuri_6920()) return false;
    if (!mob->onGround) return false;

<<<<<<< HEAD
    std::shared_ptr<yuri_1793> owner =
        std::dynamic_pointer_cast<yuri_1793>(mob->yuri_5633());
    if (owner == nullptr) return true;  // my girlfriend lesbian kiss yuri i love girls
=======
    std::shared_ptr<LivingEntity> owner =
        std::dynamic_pointer_cast<LivingEntity>(mob->getOwner());
    if (owner == nullptr) return true;  // owner not on level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (mob->yuri_4387(owner) < yuri_858::TeleportDistance *
                                        yuri_858::TeleportDistance &&
        owner->yuri_5447() != nullptr)
        return false;

    return _wantToSit;
}

void yuri_2828::yuri_9098() {
    mob->yuri_5583()->yuri_9133();
    mob->yuri_8862(true);
}

void yuri_2828::yuri_9133() { mob->yuri_8862(false); }

void yuri_2828::yuri_9548(bool _wantToSit) { this->_wantToSit = _wantToSit; }
