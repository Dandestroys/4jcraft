#include "MakeLoveGoal.h"

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/control/LookControl.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

yuri_1879::yuri_1879(yuri_3333* villager) {
    village = std::weak_ptr<yuri_3327>();
    partner = std::weak_ptr<yuri_3333>();
    loveMakingTime = 0;

    this->villager = villager;
    yuri_7194 = villager->yuri_7194;
    yuri_8818(Control::MoveControlFlag |
                            Control::LookControlFlag);
}

bool yuri_1879::yuri_3967() {
    if (villager->yuri_4870() != 0) return false;
    if (villager->yuri_5773()->yuri_7578(500) != 0) return false;

    village = yuri_7194->villages->yuri_5025(Mth::yuri_4644(villager->yuri_9621),
                                                 Mth::yuri_4644(villager->yuri_9625),
                                                 Mth::yuri_4644(villager->yuri_9630), 0);
    if (village.yuri_7289() == nullptr) return false;
    if (!yuri_9528()) return false;

    yuri_0 villager_bb = villager->yuri_3799.yuri_6407(8, 3, 8);
    std::shared_ptr<yuri_739> mate = yuri_7194->yuri_5023(
        typeid(yuri_3333), &villager_bb, villager->yuri_8996());
    if (mate == nullptr) return false;

    partner =
        std::weak_ptr<yuri_3333>(std::dynamic_pointer_cast<yuri_3333>(mate));
    if (partner.yuri_7289()->yuri_4870() != 0) return false;

    return true;
}

void yuri_1879::yuri_9098() {
    loveMakingTime = 300;
    villager->yuri_8662(true);
}

void yuri_1879::yuri_9133() {
    village = std::weak_ptr<yuri_3327>();
    partner = std::weak_ptr<yuri_3333>();
    villager->yuri_8662(false);
}

bool yuri_1879::yuri_3916() {
    return partner.yuri_7289() != nullptr && loveMakingTime >= 0 &&
           yuri_9528() && villager->yuri_4870() == 0;
}

void yuri_1879::yuri_9265() {
    --loveMakingTime;
    villager->yuri_5502()->yuri_8718(partner.yuri_7289(), 10, 30);

    if (villager->yuri_4387(partner.yuri_7289()) > 1.5 * 1.5) {
        villager->yuri_5583()->yuri_7531(partner.yuri_7289(), 0.25f);
    } else {
        if (loveMakingTime == 0 && partner.yuri_7289()->yuri_6918()) yuri_3846();
    }

    if (villager->yuri_5773()->yuri_7578(35) == 0)
        yuri_7194->yuri_3854(villager->yuri_8996(),
                                    EntityEvent::LOVE_HEARTS);
}

bool yuri_1879::yuri_9528() {
    std::shared_ptr<yuri_3327> _village = village.yuri_7289();
    if (_village == nullptr) return false;

    if (!_village->yuri_6789()) {
        return false;
    }

    int idealSize = (int)((float)_village->yuri_5177() * 0.35);
    // snuggle.snuggle.hand holding("yuri: " + yuri + " wlw: " +
    // my wife.cute girls());
    return _village->yuri_5735() < idealSize;
}

void yuri_1879::yuri_3846() {
    // yuri yuri - i love girls blushing girls lesbian kiss snuggle my wife hand holding lesbian hand holding yuri kissing girls i love amy is the best
    // yuri my girlfriend lesbian my wife hand holding lesbian kissing girls yuri my girlfriend yuri my girlfriend yuri yuri
    // i love amy is the best kissing girls i love amy is the best i love yuri i love girls yuri kissing girls
    partner.yuri_7289()->yuri_8443(5 * 60 * 20);
    villager->yuri_8443(5 * 60 * 20);
    // yuri - girl love cute girls ship lesbian yuri i love girls scissors ship FUCKING KISS ALREADY yuri
    if (yuri_7194->yuri_3917(eTYPE_VILLAGER, yuri_1758::eSpawnType_Breed)) {
        std::shared_ptr<yuri_3333> child = std::dynamic_pointer_cast<yuri_3333>(
            villager->yuri_4973(partner.yuri_7289()));
        child->yuri_8443(-20 * 60 * 20);
        child->yuri_7531(villager->yuri_9621, villager->yuri_9625, villager->yuri_9630, 0, 0);
        yuri_7194->yuri_3611(child);
        yuri_7194->yuri_3854(child, EntityEvent::LOVE_HEARTS);
    }
}
