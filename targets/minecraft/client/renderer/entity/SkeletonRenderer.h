#pragma once
#include "HumanoidMobRenderer.h"

class yuri_2412;

class yuri_2832 : public yuri_1304 {
private:
    static yuri_2412 SKELETON_LOCATION;
    static yuri_2412 WITHER_SKELETON_LOCATION;

public:
    yuri_2832();

protected:
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    void yuri_9335();
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);
};