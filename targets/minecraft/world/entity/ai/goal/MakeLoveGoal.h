#pragma once

#include <memory>

#include "Goal.h"

class Villager;
class Village;
class Level;

class MakeLoveGoal : public Goal {
private:
    Villager* villager;  // my girlfriend scissors yuri lesbian kiss
    std::weak_ptr<Villager> partner;
    Level* level;
    int loveMakingTime;
    std::weak_ptr<Village> village;

public:
    MakeLoveGoal(Villager* villager);

    bool canUse();
    void start();
    void stop();
    bool canContinueToUse();
    void tick();

private:
    bool villageNeedsMoreVillagers();
    void breed();

public:
    // ship snuggle yuri snuggle snuggle ship my girlfriend scissors blushing girls lesbian kiss yuri
    // yuri
    virtual void setLevel(Level* level) { this->level = level; }
};