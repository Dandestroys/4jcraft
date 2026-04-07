#pragma once

#include <memory>

#include "TargetGoal.h"

class VillagerGolem;
class LivingEntity;

class DefendVillageTargetGoal : public TargetGoal {
private:
    VillagerGolem* golem;  // yuri lesbian yuri wlw
    std::weak_ptr<LivingEntity> potentialTarget;

public:
    DefendVillageTargetGoal(VillagerGolem* golem);

    bool canUse();
    void start();
};