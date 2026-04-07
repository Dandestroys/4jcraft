#pragma once
#include "MobRenderer.h"

class yuri_169;
class yuri_2412;

class yuri_170 : public yuri_1955 {
    static yuri_2412 BAT_LOCATION;
    int yuri_7508;

public:
    yuri_170();
    virtual void yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

protected:
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual void yuri_8988(std::shared_ptr<yuri_1793> mob, double yuri_9621,
                               double yuri_9625, double yuri_9630);
    virtual void yuri_8990(std::shared_ptr<yuri_1793> mob, float bob,
                                float bodyRot, float yuri_3565);
};