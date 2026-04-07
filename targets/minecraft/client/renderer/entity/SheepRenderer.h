#pragma once
#include "MobRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_2779 : public yuri_1955 {
private:
    static yuri_2412 SHEEP_LOCATION;
    static yuri_2412 SHEEP_FUR_LOCATION;

public:
    yuri_2779(yuri_1962* model, yuri_1962* armor, float shadow);

protected:
    virtual int yuri_7892(std::shared_ptr<yuri_1793> _sheep, int layer,
                             float yuri_3565);

public:
    virtual void yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};