#pragma once
#include "EntityRenderer.h"

class yuri_3101;

class yuri_795 : public yuri_746 {
private:
    yuri_3101* tileRenderer;

public:
    yuri_795();

    virtual void yuri_8158(std::shared_ptr<yuri_739> _tile, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};