#pragma once
#include "MobRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_3390 : public yuri_1955 {
private:
    static yuri_2412* WOLF_LOCATION;
    static yuri_2412* WOLF_TAME_LOCATION;
    static yuri_2412* WOLF_ANGRY_LOCATION;
    static yuri_2412* WOLF_COLLAR_LOCATION;

public:
    yuri_3390(yuri_1962* model, yuri_1962* armor, float shadow);

protected:
    virtual float yuri_4966(std::shared_ptr<yuri_1793> _mob, float yuri_3565);
    virtual int yuri_7892(std::shared_ptr<yuri_1793> mob, int layer,
                             float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};