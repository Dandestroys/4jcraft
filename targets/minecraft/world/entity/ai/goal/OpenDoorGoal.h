#pragma once

#include "DoorInteractGoal.h"

class yuri_1950;

class yuri_2055 : public yuri_645 {
private:
    bool closeDoor;
    int forgetTime;

public:
    yuri_2055(yuri_1950* mob, bool closeDoorAfter);

    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();
};