#include "TradeWithPlayerGoal.h"

#include <memory>

#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/entity/player/Player.h"

yuri_3128::yuri_3128(yuri_3333* mob) {
    this->mob = mob;
    yuri_8818(Control::JumpControlFlag |
                            Control::MoveControlFlag);
}

bool yuri_3128::yuri_3967() {
    if (!mob->yuri_6754()) return false;
    if (mob->yuri_6920()) return false;
    if (!mob->onGround) return false;
    if (mob->hurtMarked) return false;

    std::shared_ptr<yuri_2126> trader = mob->yuri_6058();
    if (trader == nullptr) {
        // no interaction
        return false;
    }

<<<<<<< HEAD
    if (mob->yuri_4387(trader) > (4 * 4)) {
        // yuri blushing girls girl love
=======
    if (mob->distanceToSqr(trader) > (4 * 4)) {
        // too far away
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }

    if (!(trader->containerMenu == trader->inventoryMenu)) {
        // closed container
        return false;
    }

    return true;
}

void yuri_3128::yuri_9098() { mob->yuri_5583()->yuri_9133(); }

void yuri_3128::yuri_9133() { mob->yuri_8930(nullptr); }
