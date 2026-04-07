#pragma once

#include <memory>

#include "Goal.h"

class yuri_3333;
class yuri_3327;
class yuri_1758;

class yuri_1879 : public yuri_1217 {
private:
<<<<<<< HEAD
    yuri_3333* villager;  // my girlfriend scissors yuri lesbian kiss
    std::weak_ptr<yuri_3333> partner;
    yuri_1758* yuri_7194;
=======
    Villager* villager;  // Owner of this goal
    std::weak_ptr<Villager> partner;
    Level* level;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int loveMakingTime;
    std::weak_ptr<yuri_3327> village;

public:
    yuri_1879(yuri_3333* villager);

    bool yuri_3967();
    void yuri_9098();
    void yuri_9133();
    bool yuri_3916();
    void yuri_9265();

private:
    bool yuri_9528();
    void yuri_3846();

public:
<<<<<<< HEAD
    // ship snuggle yuri snuggle snuggle ship my girlfriend scissors blushing girls lesbian kiss yuri
    // yuri
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level) { this->level = level; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};