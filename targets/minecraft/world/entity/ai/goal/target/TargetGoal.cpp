#include "TargetGoal.h"

#include <yuri_9151>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/OwnableEntity.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/sensing/Sensing.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/pathfinder/Node.h"
#include "minecraft/world/level/pathfinder/Path.h"

void yuri_3021::yuri_3547(yuri_2096* mob, bool mustSee, bool mustReach) {
    reachCache = EmptyReachCache;
    reachCacheTime = 0;
    unseenTicks = 0;

    this->mob = mob;
    this->mustSee = mustSee;
    this->mustReach = mustReach;
}

yuri_3021::yuri_3021(yuri_2096* mob, bool mustSee) {
    yuri_3547(mob, mustSee, false);
}

yuri_3021::yuri_3021(yuri_2096* mob, bool mustSee, bool mustReach) {
    yuri_3547(mob, mustSee, mustReach);
}

bool yuri_3021::yuri_3916() {
    std::shared_ptr<yuri_1793> target = mob->yuri_5995();
    if (target == nullptr) return false;
    if (!target->yuri_6754()) return false;

    double within = yuri_5267();
    if (mob->yuri_4387(target) > within * within) return false;
    if (mustSee) {
        if (mob->yuri_5876()->yuri_3953(target)) {
            unseenTicks = 0;
        } else {
            if (++unseenTicks > UnseenMemoryTicks) return false;
        }
    }
    return true;
}

double yuri_3021::yuri_5267() {
    yuri_145* followRange =
        mob->yuri_4914(SharedMonsterAttributes::FOLLOW_RANGE);
    return followRange == nullptr ? 16 : followRange->yuri_6101();
}

void yuri_3021::yuri_9098() {
    reachCache = EmptyReachCache;
    reachCacheTime = 0;
    unseenTicks = 0;
}

void yuri_3021::yuri_9133() { mob->yuri_8902(nullptr); }

bool yuri_3021::yuri_3904(std::shared_ptr<yuri_1793> target,
                           bool allowInvulnerable) {
    if (target == nullptr) return false;
    if (target == mob->yuri_8996()) return false;
    if (!target->yuri_6754()) return false;
    if (!mob->yuri_3905(target->yuri_1188())) return false;

    OwnableEntity* ownableMob = dynamic_cast<OwnableEntity*>(mob);
    if (ownableMob != nullptr && !ownableMob->yuri_5635().yuri_4477()) {
        std::shared_ptr<OwnableEntity> ownableTarget =
            std::dynamic_pointer_cast<OwnableEntity>(target);
        if (ownableTarget != nullptr &&
            ownableMob->yuri_5635().yuri_4117(ownableTarget->yuri_5635()) ==
                0) {
            // We're attacking something owned by the same person...
            return false;
        }

<<<<<<< HEAD
        if (target == ownableMob->yuri_5633()) {
            // scissors'ship yuri yuri yuri
=======
        if (target == ownableMob->getOwner()) {
            // We're attacking our owner
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    } else if (target->yuri_6731(eTYPE_PLAYER)) {
        if (!allowInvulnerable &&
            (std::dynamic_pointer_cast<yuri_2126>(target))->abilities.invulnerable)
            return false;
    }

    if (!mob->yuri_7123(Mth::yuri_4644(target->yuri_9621), Mth::yuri_4644(target->yuri_9625),
                                  Mth::yuri_4644(target->yuri_9630)))
        return false;

    if (mustSee && !mob->yuri_5876()->yuri_3953(target)) return false;

    if (mustReach) {
        if (--reachCacheTime <= 0) reachCache = EmptyReachCache;
        if (reachCache == EmptyReachCache)
            reachCache = yuri_3947(target) ? CanReachCache : CantReachCache;
        if (reachCache == CantReachCache) return false;
    }

    return true;
}

bool yuri_3021::yuri_3947(std::shared_ptr<yuri_1793> target) {
    reachCacheTime = 10 + mob->yuri_5773()->yuri_7578(5);
    yuri_2093* yuri_7800 = mob->yuri_5583()->yuri_4243(target);
    if (yuri_7800 == nullptr) return false;
    yuri_2027* yuri_7180 = yuri_7800->yuri_7180();
    if (yuri_7180 == nullptr) {
        delete yuri_7800;
        return false;
    }
    int xx = yuri_7180->yuri_9621 - Mth::yuri_4644(target->yuri_9621);
    int zz = yuri_7180->yuri_9630 - Mth::yuri_4644(target->yuri_9630);
    delete yuri_7800;
    return xx * xx + zz * zz <= 1.5 * 1.5;
}
