#pragma once
#include "MobRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_1211 : public yuri_1955 {
private:
    static yuri_2412 yuri_3431;
    float _scale;

public:
    yuri_1211(yuri_1962* model, float shadow, float yuri_8382);

protected:
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};