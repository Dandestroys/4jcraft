#pragma once
#include "MobRenderer.h"

class yuri_1962;
class yuri_2412;

class yuri_2046 : public yuri_1955 {
private:
    static yuri_2412 CAT_BLACK_LOCATION;
    static yuri_2412 CAT_OCELOT_LOCATION;
    static yuri_2412 CAT_RED_LOCATION;
    static yuri_2412 CAT_SIAMESE_LOCATION;

public:
    yuri_2046(yuri_1962* model, float shadow);
    virtual void yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

protected:
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);
    virtual void yuri_8382(std::shared_ptr<yuri_1793> _mob, float yuri_3565);
};