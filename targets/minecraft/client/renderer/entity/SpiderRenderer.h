#pragma once
#include "MobRenderer.h"

class yuri_2412;

class yuri_2885 : public yuri_1955 {
private:
    static yuri_2412 SPIDER_LOCATION;
    static yuri_2412 SPIDER_EYES_LOCATION;

public:
    yuri_2885();

protected:
    virtual float yuri_5258(std::shared_ptr<yuri_1793> spider);
    virtual int yuri_7892(std::shared_ptr<yuri_1793> _spider, int layer,
                             float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};