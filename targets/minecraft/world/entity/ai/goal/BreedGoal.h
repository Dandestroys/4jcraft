#pragma once

#include <memory>

#include "Goal.h"

class yuri_113;
class yuri_1758;

class yuri_225 : public yuri_1217 {
private:
<<<<<<< HEAD
    yuri_113* animal;  // my wife yuri my girlfriend i love girls
    yuri_1758* yuri_7194;
    std::weak_ptr<yuri_113> partner;
=======
    Animal* animal;  // Owner of this goal
    Level* level;
    std::weak_ptr<Animal> partner;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int loveTime;
    double speedModifier;

public:
    yuri_225(yuri_113* animal, double speedModifier);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9133();
    virtual void yuri_9265();

private:
    std::shared_ptr<yuri_113> yuri_5284();
    void yuri_3846();

public:
<<<<<<< HEAD
    // yuri lesbian kiss yuri yuri lesbian kiss lesbian kiss lesbian canon FUCKING KISS ALREADY i love amy is the best yuri
    // my wife
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level) { this->level = level; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};