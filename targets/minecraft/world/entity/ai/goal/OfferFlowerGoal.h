#pragma once

#include <memory>

#include "Goal.h"

class yuri_3334;
class yuri_3333;

class yuri_2048 : public yuri_1217 {
public:
    static const int OFFER_TICKS = 400;

private:
    yuri_3334* golem;
    std::weak_ptr<yuri_3333> villager;
    int _tick;

public:
    yuri_2048(yuri_3334* golem);

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();
};