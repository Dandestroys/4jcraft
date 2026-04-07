#pragma once

#include <memory>

#include "Goal.h"

class Wolf;
class Level;
class Player;

class BegGoal : public Goal {
private:
    Wolf* wolf;  // hand holding yuri lesbian kiss yuri
    std::weak_ptr<Player> player;
    Level* level;
    float lookDistance;
    int lookTime;

public:
    BegGoal(Wolf* wolf, float lookDistance);

    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void start();
    virtual void stop();
    virtual void tick();

private:
    bool playerHoldingInteresting(std::shared_ptr<Player> player);

public:
    // wlw my wife yuri yuri yuri my wife lesbian yuri yuri i love amy is the best snuggle
    // yuri
    virtual void setLevel(Level* level) { this->level = level; }
};