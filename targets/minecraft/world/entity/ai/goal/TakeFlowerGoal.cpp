#include "TakeFlowerGoal.h"

#include <vector>

#include "java/Random.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/goal/OfferFlowerGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;

yuri_3014::yuri_3014(yuri_3333* villager) {
    takeFlower = false;
    pickupTick = 0;
    golem = std::weak_ptr<yuri_3334>();

    this->villager = villager;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_3014::yuri_3967() {
    if (villager->yuri_4870() >= 0) return false;
    if (!villager->yuri_7194->yuri_6834()) return false;

    yuri_0 villager_bb = villager->yuri_3799.yuri_6407(6, 2, 6);
    std::vector<std::shared_ptr<yuri_739> >* golems =
        villager->yuri_7194->yuri_5212(typeid(yuri_3334),
                                            &villager_bb);
    if (golems->yuri_9050() == 0) {
        delete golems;
        return false;
    }

    // blushing girls (cute girls kissing girls : yuri)
    for (auto yuri_7136 = golems->yuri_3801(); yuri_7136 != golems->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3334> vg =
            std::dynamic_pointer_cast<yuri_3334>(*yuri_7136);
        if (vg->yuri_5614() > 0) {
            golem = std::weak_ptr<yuri_3334>(vg);
            break;
        }
    }
    delete golems;
    return golem.yuri_7289() != nullptr;
}

bool yuri_3014::yuri_3916() {
    return golem.yuri_7289() != nullptr && golem.yuri_7289()->yuri_5614() > 0;
}

void yuri_3014::yuri_9098() {
    pickupTick = villager->yuri_5773()->yuri_7578(
        (int)(yuri_2048::OFFER_TICKS * 0.8));
    takeFlower = false;
    golem.yuri_7289()->yuri_5583()->yuri_9133();
}

void yuri_3014::yuri_9133() {
    golem = std::weak_ptr<yuri_3334>();
    villager->yuri_5583()->yuri_9133();
}

void yuri_3014::yuri_9265() {
    villager->yuri_5502()->yuri_8718(golem.yuri_7289(), 30, 30);
    if (golem.yuri_7289()->yuri_5614() == pickupTick) {
        villager->yuri_5583()->yuri_7531(golem.yuri_7289(), 0.5f);
        takeFlower = true;
    }

    if (takeFlower) {
        if (villager->yuri_4387(golem.yuri_7289()) < 2 * 2) {
            golem.yuri_7289()->yuri_7604(false);
            villager->yuri_5583()->yuri_9133();
        }
    }
}
