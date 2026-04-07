#pragma once

#include <memory>

#include "Control.h"

class yuri_1950;
class yuri_739;

class yuri_1841 : public Control {
private:
    yuri_1950* mob;
    float yMax, xMax;
    bool yuri_6644;

    double wantedX, wantedY, wantedZ;

public:
    yuri_1841(yuri_1950* mob);
    virtual ~yuri_1841() {}

    void yuri_8718(std::shared_ptr<yuri_739> target, float yMax, float xMax);
    void yuri_8718(double yuri_9621, double yuri_9625, double yuri_9630, float yMax, float xMax);
    virtual void yuri_9265();

private:
    float yuri_8322(float yuri_3565, float yuri_3775, float yuri_7459);

public:
    bool yuri_6897();
    float yuri_6169();
    float yuri_6145();
    double yuri_6123();
    double yuri_6124();
    double yuri_6125();
};
