#pragma once

#include <memory>

#include "Goal.h"

class yuri_2096;
class yuri_2126;

class yuri_3029 : public yuri_1217 {
private:
    yuri_2096* mob;
    double speedModifier;
    double px, py, pz, pRotX, pRotY;
    std::weak_ptr<yuri_2126> yuri_7839;
    int calmDown;
    bool _isRunning;
    int yuri_7138;
    bool canScare;
    bool oldAvoidWater;

public:
    yuri_3029(yuri_2096* mob, double speedModifier, int yuri_7138,
              bool canScare);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9098();
    void yuri_9133();
    void yuri_9265();
    bool yuri_7020();
};