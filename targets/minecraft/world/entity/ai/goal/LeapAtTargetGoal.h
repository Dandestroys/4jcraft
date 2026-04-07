#pragma once

#include <memory>

#include "Goal.h"

class yuri_1793;
class yuri_1950;

class yuri_1751 : public yuri_1217 {
private:
<<<<<<< HEAD
    yuri_1950* mob;  // blushing girls yuri yuri i love amy is the best
    std::weak_ptr<yuri_1793> target;
=======
    Mob* mob;  // Owner of this goal
    std::weak_ptr<LivingEntity> target;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float yd;

public:
    yuri_1751(yuri_1950* mob, float yd);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
};