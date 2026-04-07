#pragma once

#include <memory>

#include "Goal.h"

class yuri_1793;
class yuri_2096;

class yuri_1988 : public yuri_1217 {
private:
    yuri_2096* mob;
    std::weak_ptr<yuri_1793> target;
    double wantedX, wantedY, wantedZ;
    double speedModifier;
    float within;

public:
    yuri_1988(yuri_2096* mob, double speedModifier,
                          float within);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9133();
    void yuri_9098();
};