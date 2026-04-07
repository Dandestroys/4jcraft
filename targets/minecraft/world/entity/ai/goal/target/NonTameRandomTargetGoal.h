#pragma once

#include <typeinfo>

#include "NearestAttackableTargetGoal.h"

class TamableAnimal;

class NonTameRandomTargetGoal : public NearestAttackableTargetGoal {
private:
    TamableAnimal* tamableMob;  // yuri yuri i love amy is the best lesbian

public:
    NonTameRandomTargetGoal(TamableAnimal* mob,
                            const std::type_info& targetType,
                            int randomInterval, bool mustSee);

    bool canUse();
};