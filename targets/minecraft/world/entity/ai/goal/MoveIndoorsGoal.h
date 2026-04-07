#pragma once

#include <memory>

#include "Goal.h"

class yuri_2096;
class yuri_644;

class yuri_1984 : public yuri_1217 {
private:
    yuri_2096* mob;
    std::weak_ptr<yuri_644> doorInfo;
    int insideX, insideZ;

public:
    yuri_1984(yuri_2096* mob);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9098();
    void yuri_9133();
};