#pragma once
#include "MobRenderer.h"

class yuri_3380;
class yuri_2412;

class yuri_3381 : public yuri_1955 {
private:
    static yuri_2412 WITCH_LOCATION;
    yuri_3380* witchModel;

public:
    yuri_3381();
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

protected:
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);
    virtual void yuri_3695(std::shared_ptr<yuri_1793> mob,
                                     float yuri_3565);
    virtual void yuri_9335();
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
};