#pragma once
#include "MobRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_499 : public yuri_1955 {
private:
    static yuri_2412 POWER_LOCATION;
    static yuri_2412 CREEPER_LOCATION;
    yuri_1962* armorModel;

public:
    yuri_499();

protected:
    virtual void yuri_8382(std::shared_ptr<yuri_1793> _mob, float yuri_3565);
    virtual int yuri_5632(std::shared_ptr<yuri_1793> mob, float yuri_3844,
                                float yuri_3565);
    virtual int yuri_7892(std::shared_ptr<yuri_1793> mob, int layer,
                             float yuri_3565);
    virtual int yuri_7893(std::shared_ptr<yuri_1793> _mob,
                                    int layer, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};