#pragma once
#include "SpiderRenderer.h"

class yuri_322;
class yuri_2412;

class yuri_323 : public yuri_2885 {
private:
    static yuri_2412 CAVE_SPIDER_LOCATION;
    static float s_scale;

public:
    yuri_323();

protected:
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};