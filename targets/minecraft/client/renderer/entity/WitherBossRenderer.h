#pragma once
#include "MobRenderer.h"

class yuri_3382;
class yuri_1793;
class yuri_2412;

class yuri_3384 : public yuri_1955 {
private:
    static yuri_2412 WITHER_INVULERABLE_LOCATION;
    static yuri_2412 yuri_3350;
    static yuri_2412 yuri_3351;
    int yuri_7508;

public:
    yuri_3384();
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);

protected:
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual int yuri_7892(std::shared_ptr<yuri_1793> entity, int layer,
                             float yuri_3565);
    virtual int yuri_7893(std::shared_ptr<yuri_1793> entity,
                                    int layer, float yuri_3565);
};