#pragma once

#include "Goal.h"

class yuri_3020;

class yuri_2828 : public yuri_1217 {
private:
    yuri_3020* mob;
    bool _wantToSit;

public:
    yuri_2828(yuri_3020* mob);

    bool yuri_3967();
    void yuri_9098();
    void yuri_9133();
    void yuri_9548(bool _wantToSit);
};