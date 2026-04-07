#pragma once
#include "MobRenderer.h"

class yuri_2859;
class yuri_2412;

class yuri_2860 : public yuri_1955 {
private:
    yuri_2859* model;
    static yuri_2412 SNOWMAN_LOCATION;

public:
    yuri_2860();

protected:
    virtual void yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                     float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};