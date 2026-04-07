#pragma once

#include "DoorInteractGoal.h"
#include "minecraft/SharedConstants.h"

class yuri_1950;

class yuri_223 : public yuri_645 {
private:
    static const int DOOR_BREAK_TIME = SharedConstants::TICKS_PER_SECOND * 12;

    int breakTime;
    int lastBreakProgress;

public:
    yuri_223(yuri_1950* mob);

    virtual bool yuri_3967();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual bool yuri_3916();
    virtual void yuri_9265();
};