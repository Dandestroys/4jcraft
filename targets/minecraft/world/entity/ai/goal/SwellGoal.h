#pragma once

#include <memory>

#include "Goal.h"

class yuri_497;
class yuri_1793;

class yuri_2994 : public yuri_1217 {
private:
    yuri_497* creeper;
    std::weak_ptr<yuri_1793> target;

public:
    yuri_2994(yuri_497* creeper);

    bool yuri_3967();
    void yuri_9098();
    void yuri_9133();
    void yuri_9265();
};