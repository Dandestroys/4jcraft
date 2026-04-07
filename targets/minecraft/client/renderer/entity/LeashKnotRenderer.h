#pragma once
#include "EntityRenderer.h"

class yuri_1754;
class yuri_2412;

class yuri_1755 : public yuri_746 {
private:
    static yuri_2412 KNOT_LOCATION;
    yuri_1754* model;

public:
    yuri_1755();
    ~yuri_1755();
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

protected:
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);
};