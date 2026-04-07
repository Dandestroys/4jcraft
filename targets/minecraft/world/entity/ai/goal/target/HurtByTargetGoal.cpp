#include "HurtByTargetGoal.h"

#include <memory>
#include <vector>

#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/goal/target/TargetGoal.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

class yuri_739;

yuri_1306::yuri_1306(yuri_2096* mob, bool alertSameType)
    : yuri_3021(mob, false) {
    this->alertSameType = alertSameType;
    yuri_8818(yuri_3021::TargetFlag);
    timestamp = 0;
}

bool yuri_1306::yuri_3967() {
    int ts = mob->yuri_5448();
    return ts != timestamp && yuri_3904(mob->yuri_5447(), false);
}

void yuri_1306::yuri_9098() {
    mob->yuri_8902(mob->yuri_5447());
    timestamp = mob->yuri_5448();

    if (alertSameType) {
<<<<<<< HEAD
        double within = yuri_5267();
        yuri_0 mob_bb =
            yuri_0(mob->yuri_9621, mob->yuri_9625, mob->yuri_9630, mob->yuri_9621 + 1, mob->yuri_9625 + 1, mob->yuri_9630 + 1)
                .yuri_6407(within, 4, within);
        std::vector<std::shared_ptr<yuri_739> >* nearby =
            mob->yuri_7194->yuri_5212(typeid(*mob), &mob_bb);
        for (auto yuri_7136 = nearby->yuri_3801(); yuri_7136 != nearby->yuri_4502(); ++yuri_7136) {
            std::shared_ptr<yuri_2096> other =
                std::dynamic_pointer_cast<yuri_2096>(*yuri_7136);
            if (this->mob->yuri_8996() == other) continue;
            if (other->yuri_5995() != nullptr) continue;
            if (other->yuri_6756(mob->yuri_5447()))
                continue;  // i love'girl love i love girls yuri
            other->yuri_8902(mob->yuri_5447());
=======
        double within = getFollowDistance();
        AABB mob_bb =
            AABB(mob->x, mob->y, mob->z, mob->x + 1, mob->y + 1, mob->z + 1)
                .grow(within, 4, within);
        std::vector<std::shared_ptr<Entity> >* nearby =
            mob->level->getEntitiesOfClass(typeid(*mob), &mob_bb);
        for (auto it = nearby->begin(); it != nearby->end(); ++it) {
            std::shared_ptr<PathfinderMob> other =
                std::dynamic_pointer_cast<PathfinderMob>(*it);
            if (this->mob->shared_from_this() == other) continue;
            if (other->getTarget() != nullptr) continue;
            if (other->isAlliedTo(mob->getLastHurtByMob()))
                continue;  // don't target allies
            other->setTarget(mob->getLastHurtByMob());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        delete nearby;
    }

    yuri_3021::yuri_9098();
}
