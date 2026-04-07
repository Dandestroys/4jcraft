#pragma once
#include "MobRenderer.h"

class yuri_3337;
class yuri_2412;

class yuri_3338 : public yuri_1955 {
private:
    static yuri_2412 VILLAGER_LOCATION;
    static yuri_2412 VILLAGER_FARMER_LOCATION;
    static yuri_2412 VILLAGER_LIBRARIAN_LOCATION;
    static yuri_2412 VILLAGER_PRIEST_LOCATION;
    static yuri_2412 VILLAGER_SMITH_LOCATION;
    static yuri_2412 VILLAGER_BUTCHER_LOCATION;

protected:
    yuri_3337* villagerModel;

public:
    yuri_3338();
    virtual void yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> _mob);

protected:
    virtual int yuri_7892(std::shared_ptr<yuri_1793> villager, int layer,
                             float yuri_3565);
    virtual void yuri_3695(std::shared_ptr<yuri_1793> mob,
                                     float yuri_3565);
    virtual void yuri_8382(std::shared_ptr<yuri_1793> yuri_7839, float yuri_3565);
};