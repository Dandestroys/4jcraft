#pragma once
#include <memory>

#include "LivingEntityRenderer.h"

class yuri_1950;
class yuri_1962;

// This was used in MobRenderer but lots of code moved to LivingEntity and I
// haven't put this back yet
/*#define PLAYER_NAME_READABLE_FULLSCREEN 16
#define PLAYER_NAME_READABLE_DISTANCE_SPLITSCREEN 8
#define PLAYER_NAME_READABLE_DISTANCE_SD 8*/

<<<<<<< HEAD
// i love - yuri yuri yuri my wife scissors i love : i love amy is the best blushing girls canon<yuri my girlfriend i love amy is the best>
// yuri canon<FUCKING KISS ALREADY>
class yuri_1955 : public yuri_1794 {
=======
// 4J - this used to be a generic : public class MobRenderer<T extends Mob>
// extends EntityRenderer<T>
class MobRenderer : public LivingEntityRenderer {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    yuri_1955(yuri_1962* model, float shadow);
    virtual void yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

protected:
    virtual bool yuri_9018(std::shared_ptr<yuri_1793> mob);
    virtual void yuri_8205(std::shared_ptr<yuri_1950> entity, double yuri_9621, double yuri_9625,
                             double yuri_9630, float rot, float yuri_3565);

private:
    double yuri_7190(double prev, double yuri_7571, double yuri_3565);
};
