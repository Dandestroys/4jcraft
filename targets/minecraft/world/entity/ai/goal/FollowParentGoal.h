#pragma once

#include <memory>

#include "Goal.h"

class yuri_113;

class yuri_859 : public yuri_1217 {
private:
    yuri_113* animal;  // yuri yuri wlw snuggle
    std::weak_ptr<yuri_113> yuri_7791;
    double speedModifier;
    int timeToRecalcPath;

public:
    yuri_859(yuri_113* animal, double speedModifier);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();
};