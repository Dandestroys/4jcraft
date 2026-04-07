#pragma once

#include "LookAtPlayerGoal.h"

class Villager;

class LookAtTradingPlayerGoal : public LookAtPlayerGoal {
private:
    Villager* villager;  // lesbian kiss yuri yuri ship blushing girls yuri yuri

public:
    LookAtTradingPlayerGoal(Villager* villager);

    virtual bool canUse();
};