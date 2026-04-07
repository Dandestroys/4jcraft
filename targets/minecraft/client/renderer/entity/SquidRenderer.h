#pragma once
#include "MobRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_2893 : public yuri_1955 {
private:
    static yuri_2412 SQUID_LOCATION;

public:
    yuri_2893(yuri_1962* model, float shadow);
    virtual void yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

protected:
    virtual void yuri_8990(std::shared_ptr<yuri_1793> _mob, float bob,
                                float bodyRot, float yuri_3565);
    virtual float yuri_4966(std::shared_ptr<yuri_1793> _mob, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};