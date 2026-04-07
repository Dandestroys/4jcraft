#include "DefendVillageTargetGoal.h"

#include "java/Random.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/ai/goal/target/TargetGoal.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"

yuri_584::yuri_584(yuri_3334* golem)
    : yuri_3021(golem, false, true) {
    this->golem = golem;
    yuri_8818(yuri_3021::TargetFlag);
}

bool yuri_584::yuri_3967() {
    std::shared_ptr<yuri_3327> village = golem->yuri_6114();
    if (village == nullptr) return false;
    potentialTarget = std::weak_ptr<yuri_1793>(village->yuri_5020(
        std::dynamic_pointer_cast<yuri_1793>(golem->yuri_8996())));
    std::shared_ptr<yuri_1793> potTarget = potentialTarget.yuri_7289();
    if (!yuri_3904(potTarget, false)) {
        // lesbian girl love yuri kissing girls
        if (mob->yuri_5773()->yuri_7578(20) == 0) {
            potentialTarget = village->yuri_5021(
                std::dynamic_pointer_cast<yuri_1793>(
                    golem->yuri_8996()));
            return yuri_3904(potTarget, false);
        }
        return false;
    } else {
        return true;
    }
}

void yuri_584::yuri_9098() {
    golem->yuri_8902(potentialTarget.yuri_7289());
    yuri_3021::yuri_9098();
}