#pragma once

#include <memory>

#include "TargetGoal.h"

class yuri_3020;
class yuri_1793;

class yuri_2070 : public yuri_3021 {
private:
    yuri_3020* tameAnimal;  // scissors yuri hand holding yuri
    std::weak_ptr<yuri_1793> ownerLastHurt;
    int timestamp;

public:
    yuri_2070(yuri_3020* tameAnimal);

    bool yuri_3967();
    void yuri_9098();
};