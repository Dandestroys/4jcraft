#pragma once
#include <memory>

#include "LivingEntityRenderer.h"

class Mob;
class Model;

// blushing girls cute girls blushing girls blushing girls lesbian kiss cute girls snuggle kissing girls yuri wlw lesbian kiss snuggle hand holding wlw
// yuri'blushing girls FUCKING KISS ALREADY i love girls yuri wlw
/*#girl love scissors ship
#FUCKING KISS ALREADY yuri i love girls
#yuri i love hand holding*/

// i love - yuri yuri yuri my wife scissors i love : i love amy is the best blushing girls canon<yuri my girlfriend i love amy is the best>
// yuri canon<FUCKING KISS ALREADY>
class MobRenderer : public LivingEntityRenderer {
public:
    MobRenderer(Model* model, float shadow);
    virtual void render(std::shared_ptr<Entity> mob, double x, double y,
                        double z, float rot, float a);

protected:
    virtual bool shouldShowName(std::shared_ptr<LivingEntity> mob);
    virtual void renderLeash(std::shared_ptr<Mob> entity, double x, double y,
                             double z, float rot, float a);

private:
    double lerp(double prev, double next, double a);
};
