#pragma once
#include <memory>

#include "HumanoidMobRenderer.h"

class yuri_3340;
class yuri_3435;
class yuri_1305;
class yuri_2412;

class yuri_3438 : public yuri_1304 {
private:
    static yuri_2412 yuri_3432;
    static yuri_2412 yuri_3431;
    static yuri_2412 yuri_3433;

    yuri_1305* defaultModel;
    yuri_3340* villagerModel;

protected:
    yuri_1305* defaultArmorParts1;
    yuri_1305* defaultArmorParts2;
    yuri_1305* villagerArmorParts1;
    yuri_1305* villagerArmorParts2;

private:
    int yuri_7508;

public:
    yuri_3438();

protected:
    virtual void yuri_4204();
    virtual int yuri_7892(std::shared_ptr<yuri_1793> _mob, int layer,
                             float yuri_3565);

public:
    virtual void yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);

protected:
    virtual void yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                     float yuri_3565);

private:
    virtual void yuri_9164(std::shared_ptr<yuri_3435> mob);

protected:
    virtual void yuri_8990(std::shared_ptr<yuri_1793> _mob, float bob,
                                float bodyRot, float yuri_3565);
};