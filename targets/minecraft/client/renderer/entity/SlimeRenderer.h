#pragma once
#include "MobRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_2844 : public yuri_1955 {
private:
    yuri_1962* armor;
    static yuri_2412 SLIME_LOCATION;

public:
    yuri_2844(yuri_1962* model, yuri_1962* armor, float shadow);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);

protected:
    virtual int yuri_7892(std::shared_ptr<yuri_1793> _slime, int layer,
                             float yuri_3565);
    virtual void yuri_8382(std::shared_ptr<yuri_1793> _slime, float yuri_3565);
};