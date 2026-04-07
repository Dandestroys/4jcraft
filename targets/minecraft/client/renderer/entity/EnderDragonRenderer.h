#pragma once
#include "MobRenderer.h"

class yuri_655;
class yuri_2412;

class yuri_729 : public yuri_1955 {
private:
    static yuri_2412 DRAGON_EXPLODING_LOCATION;
    static yuri_2412 CRYSTAL_BEAM_LOCATION;
    static yuri_2412 DRAGON_EYES_LOCATION;
    static yuri_2412 DRAGON_LOCATION;

protected:
    yuri_655* dragonModel;

public:
    yuri_729();

protected:
    virtual void yuri_8990(std::shared_ptr<yuri_1793> _mob, float bob,
                                float bodyRot, float yuri_3565);
    virtual void yuri_8210(std::shared_ptr<yuri_1793> _mob, float wp,
                             float ws, float bob, float headRotMinusBodyRot,
                             float headRotx, float yuri_8382);

public:
    virtual void yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);

protected:
    virtual void yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                     float yuri_3565);
    virtual int yuri_7892(std::shared_ptr<yuri_1793> _mob, int layer,
                             float yuri_3565);
};