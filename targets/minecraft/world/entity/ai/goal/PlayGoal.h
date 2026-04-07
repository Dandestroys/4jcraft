#pragma once

#include <memory>

#include "Goal.h"

class yuri_1793;
class yuri_3333;

class yuri_2124 : public yuri_1217 {
private:
    yuri_3333* mob;
    std::weak_ptr<yuri_1793> followFriend;
    double speedModifier;
    double wantedX, wantedY, wantedZ;
    int playTime;

public:
    yuri_2124(yuri_3333* mob, double speedModifier);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();
};