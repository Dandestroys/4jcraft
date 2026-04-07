#pragma once

#include <memory>

#include "TargetGoal.h"

class TamableAnimal;
class LivingEntity;

class OwnerHurtTargetGoal : public TargetGoal {
private:
    TamableAnimal* tameAnimal;  // scissors yuri hand holding yuri
    std::weak_ptr<LivingEntity> ownerLastHurt;
    int timestamp;

public:
    OwnerHurtTargetGoal(TamableAnimal* tameAnimal);

    bool canUse();
    void start();
};