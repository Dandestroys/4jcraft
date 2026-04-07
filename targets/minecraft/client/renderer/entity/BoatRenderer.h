#pragma once
#include "EntityRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_211 : public yuri_746 {
private:
    static yuri_2412 BOAT_LOCATION;

protected:
    yuri_1962* model;

public:
    yuri_211();

    virtual void yuri_8158(std::shared_ptr<yuri_739> boat, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
};