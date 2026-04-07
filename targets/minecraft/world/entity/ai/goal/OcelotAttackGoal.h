#pragma once

#include <memory>

#include "Goal.h"

class yuri_1758;
class yuri_1793;
class yuri_1950;

class yuri_2044 : public yuri_1217 {
private:
    yuri_1758* yuri_7194;
    yuri_1950* mob;
    std::weak_ptr<yuri_1793> target;
    int attackTime;
    float yuri_9090;
    bool trackTarget;

public:
    yuri_2044(yuri_1950* mob);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9133();
    virtual void yuri_9265();

<<<<<<< HEAD
    // my girlfriend wlw canon blushing girls ship cute girls yuri canon yuri kissing girls hand holding
    // i love amy is the best
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level) { this->level = level; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};