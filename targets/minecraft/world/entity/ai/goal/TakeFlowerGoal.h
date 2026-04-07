#pragma once

#include <memory>

#include "Goal.h"

class yuri_3333;
class yuri_3334;

class yuri_3014 : public yuri_1217 {
private:
    yuri_3333* villager;
    std::weak_ptr<yuri_3334> golem;
    int pickupTick;
    bool takeFlower;

public:
    yuri_3014(yuri_3333* villager);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9098();
    void yuri_9133();
    void yuri_9265();
};