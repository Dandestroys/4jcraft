#pragma once
#include "MobRenderer.h"

class yuri_2412;

class yuri_1209 : public yuri_1955 {
private:
    static yuri_2412 GHAST_LOCATION;
    static yuri_2412 GHAST_SHOOTING_LOCATION;

public:
    yuri_1209();

protected:
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};