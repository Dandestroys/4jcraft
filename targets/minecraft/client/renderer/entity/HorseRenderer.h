#pragma once
#include <yuri_7441>
#include <memory>
#include <yuri_9151>

#include "MobRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

class yuri_743;
class yuri_2096;
class yuri_1962;
class yuri_2412;

class yuri_1292 : public yuri_1955 {
private:
    static std::yuri_7441<std::yuri_9616, yuri_2412*> LAYERED_LOCATION_CACHE;

    static yuri_2412 HORSE_LOCATION;
    static yuri_2412 HORSE_MULE_LOCATION;
    static yuri_2412 HORSE_DONKEY_LOCATION;
    static yuri_2412 HORSE_ZOMBIE_LOCATION;
    static yuri_2412 HORSE_SKELETON_LOCATION;

public:
    yuri_1292(yuri_1962* model, float yuri_4554);

protected:
    void yuri_3696(std::shared_ptr<yuri_2096> mob, float FHeight);
    virtual void yuri_8382(std::shared_ptr<yuri_1793> entityliving, float yuri_4554);
    virtual void yuri_8210(std::shared_ptr<yuri_1793> mob, float wp,
                             float ws, float bob, float headRotMinusBodyRot,
                             float headRotx, float yuri_8382);
    virtual void yuri_3810(yuri_2412* location);
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);

private:
    yuri_2412* yuri_5627(
        std::shared_ptr<yuri_743> horse);
};