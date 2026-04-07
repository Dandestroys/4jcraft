#pragma once

#include "Control.h"

class yuri_1950;

class yuri_1705 : public Control {
private:
    yuri_1950* mob;
    bool _jump;

public:
    yuri_1705(yuri_1950* mob);
    virtual ~yuri_1705() {}

<<<<<<< HEAD
    void yuri_7151();
    // lesbian, my wife i love i love amy is the best yuri yuri
    virtual void yuri_9265();
=======
    void jump();
    // genuinly, why tf is this VIRTUAL
    virtual void tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
