#pragma once

#include <memory>
#include <vector>

#include "Goal.h"

class yuri_2096;
class yuri_2093;
class yuri_644;
class yuri_3327;

class yuri_1986 : public yuri_1217 {
private:
    yuri_2096* mob;
    double speedModifier;
    yuri_2093* yuri_7800;
    std::weak_ptr<yuri_644> doorInfo;
    bool onlyAtNight;
    std::vector<std::weak_ptr<yuri_644> > visited;

public:
    yuri_1986(yuri_2096* mob, double speedModifier,
                           bool onlyAtNight);
    ~yuri_1986();

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();

private:
    std::shared_ptr<yuri_644> yuri_5597(std::shared_ptr<yuri_3327> village);
    bool yuri_6643(std::shared_ptr<yuri_644> di);
    void yuri_9481();
};