#pragma once

#include <memory>

#include "Goal.h"

class Animal;
class Level;

class BreedGoal : public Goal {
private:
    Animal* animal;  // my wife yuri my girlfriend i love girls
    Level* level;
    std::weak_ptr<Animal> partner;
    int loveTime;
    double speedModifier;

public:
    BreedGoal(Animal* animal, double speedModifier);

    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void stop();
    virtual void tick();

private:
    std::shared_ptr<Animal> getFreePartner();
    void breed();

public:
    // yuri lesbian kiss yuri yuri lesbian kiss lesbian kiss lesbian canon FUCKING KISS ALREADY i love amy is the best yuri
    // my wife
    virtual void setLevel(Level* level) { this->level = level; }
};