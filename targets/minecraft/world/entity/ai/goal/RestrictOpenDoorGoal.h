#pragma once

#include <memory>

#include "Goal.h"

class yuri_2096;
class yuri_644;

class yuri_2414 : public yuri_1217 {
private:
    yuri_2096* mob;
    std::weak_ptr<yuri_644> doorInfo;

public:
    yuri_2414(yuri_2096* mob);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();
};