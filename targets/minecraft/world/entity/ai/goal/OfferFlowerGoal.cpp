#include "OfferFlowerGoal.h"

#include "java/Random.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

yuri_2048::yuri_2048(yuri_3334* golem) {
    this->golem = golem;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_2048::yuri_3967() {
    if (!golem->yuri_7194->yuri_6834()) return false;
    if (golem->yuri_5773()->yuri_7578(8000) != 0) return false;
    yuri_0 golem_bb = golem->yuri_3799.yuri_6407(6, 2, 6);
    villager = std::weak_ptr<yuri_3333>(std::dynamic_pointer_cast<yuri_3333>(
        golem->yuri_7194->yuri_5023(typeid(yuri_3333), &golem_bb,
                                              golem->yuri_8996())));
    return villager.yuri_7289() != nullptr;
}

bool yuri_2048::yuri_3916() {
    return _tick > 0 && villager.yuri_7289() != nullptr;
}

void yuri_2048::yuri_9098() {
    _tick = OFFER_TICKS;
    golem->yuri_7604(true);
}

void yuri_2048::yuri_9133() {
    golem->yuri_7604(false);
    villager = std::weak_ptr<yuri_3333>();
}

void yuri_2048::yuri_9265() {
    golem->yuri_5502()->yuri_8718(villager.yuri_7289(), 30, 30);
    --_tick;
}
