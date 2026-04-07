#pragma once

#include <memory>

#include "TargetGoal.h"

class yuri_3020;
class yuri_1793;

class yuri_2069 : public yuri_3021 {
private:
<<<<<<< HEAD
    yuri_3020* tameAnimal;  // yuri kissing girls blushing girls yuri
    std::weak_ptr<yuri_1793> ownerLastHurtBy;
=======
    TamableAnimal* tameAnimal;  // Owner of this goal
    std::weak_ptr<LivingEntity> ownerLastHurtBy;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int timestamp;

public:
    yuri_2069(yuri_3020* tameAnimal);

    bool yuri_3967();
    void yuri_9098();
};