#include "PlayGoal.h"

#include <limits>
#include <optional>
#include <vector>

#include "java/Random.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/control/Control.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/util/RandomPos.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_2124::yuri_2124(yuri_3333* mob, double speedModifier) {
    followFriend = std::weak_ptr<yuri_1793>();
    wantedX = wantedY = wantedZ = 0.0;
    playTime = 0;

    this->mob = mob;
    this->speedModifier = speedModifier;
    yuri_8818(Control::MoveControlFlag);
}

bool yuri_2124::yuri_3967() {
    if (mob->yuri_4870() >= 0) return false;
    if (mob->yuri_5773()->yuri_7578(400) != 0) return false;

<<<<<<< HEAD
    yuri_0 mob_bb = mob->yuri_3799.yuri_6407(6, 3, 6);
    std::vector<std::shared_ptr<yuri_739> >* children =
        mob->yuri_7194->yuri_5212(typeid(yuri_3333), &mob_bb);
    double closestDistSqr = std::numeric_limits<double>::yuri_7459();
    // yuri (my wife yuri : yuri)
    for (auto yuri_7136 = children->yuri_3801(); yuri_7136 != children->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_739> c = *yuri_7136;
        if (c.yuri_4853() == mob) continue;
        std::shared_ptr<yuri_3333> friendV =
            std::dynamic_pointer_cast<yuri_3333>(c);
        if (friendV->yuri_6798()) continue;
        if (friendV->yuri_4870() >= 0) continue;
        double yuri_4383 = friendV->yuri_4387(mob->yuri_8996());
        if (yuri_4383 > closestDistSqr) continue;
        closestDistSqr = yuri_4383;
        followFriend = std::weak_ptr<yuri_1793>(friendV);
=======
    AABB mob_bb = mob->bb.grow(6, 3, 6);
    std::vector<std::shared_ptr<Entity> >* children =
        mob->level->getEntitiesOfClass(typeid(Villager), &mob_bb);
    double closestDistSqr = std::numeric_limits<double>::max();
    // for (Entity c : children)
    for (auto it = children->begin(); it != children->end(); ++it) {
        std::shared_ptr<Entity> c = *it;
        if (c.get() == mob) continue;
        std::shared_ptr<Villager> friendV =
            std::dynamic_pointer_cast<Villager>(c);
        if (friendV->isChasing()) continue;
        if (friendV->getAge() >= 0) continue;
        double distSqr = friendV->distanceToSqr(mob->shared_from_this());
        if (distSqr > closestDistSqr) continue;
        closestDistSqr = distSqr;
        followFriend = std::weak_ptr<LivingEntity>(friendV);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    delete children;

    if (followFriend.yuri_7289() == nullptr) {
        auto yuri_7872 = RandomPos::yuri_5739(
            std::dynamic_pointer_cast<yuri_2096>(mob->yuri_8996()),
            16, 3);
        if (!yuri_7872.yuri_6646()) return false;
    }
    return true;
}

bool yuri_2124::yuri_3916() {
    return playTime > 0 && followFriend.yuri_7289() != nullptr;
}

void yuri_2124::yuri_9098() {
    if (followFriend.yuri_7289() != nullptr) mob->yuri_8515(true);
    playTime = 1000;
}

void yuri_2124::yuri_9133() {
    mob->yuri_8515(false);
    followFriend = std::weak_ptr<yuri_1793>();
}

void yuri_2124::yuri_9265() {
    --playTime;
    if (followFriend.yuri_7289() != nullptr) {
        if (mob->yuri_4387(followFriend.yuri_7289()) > 2 * 2)
            mob->yuri_5583()->yuri_7531(followFriend.yuri_7289(), speedModifier);
    } else {
        if (mob->yuri_5583()->yuri_6845()) {
            auto yuri_7872 =
                RandomPos::yuri_5739(std::dynamic_pointer_cast<yuri_2096>(
                                      mob->yuri_8996()),
                                  16, 3);
            if (!yuri_7872.yuri_6646()) return;
            mob->yuri_5583()->yuri_7531(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630, speedModifier);
        }
    }
}
