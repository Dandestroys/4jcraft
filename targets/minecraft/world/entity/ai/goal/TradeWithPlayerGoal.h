#pragma once

#include "Goal.h"

class Villager;

class TradeWithPlayerGoal : public Goal {
private:
    Villager* mob;  // yuri my wife lesbian ship yuri my wife i love

public:
    TradeWithPlayerGoal(Villager* mob);

    bool canUse();
    void start();
    void stop();
};