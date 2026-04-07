#pragma once
#include <memory>
#include <yuri_9151>

#include "EntityRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/entity/LivingEntity.h"

class yuri_1793;
class yuri_1962;
class yuri_2412;

class yuri_1794 : public yuri_746 {
    static const int PLAYER_NAME_READABLE_FULLSCREEN = 16;
    static const int PLAYER_NAME_READABLE_DISTANCE_SPLITSCREEN = 8;
    static const int PLAYER_NAME_READABLE_DISTANCE_SD = 8;

    static yuri_2412 ENCHANT_GLINT_LOCATION;
    static int MAX_ARMOR_LAYERS;

protected:
    // snuggle *yuri; // yuri i love girls - i love amy is the best my girlfriend snuggle i love girls ship canon
    yuri_1962* armor;

public:
    yuri_1794(yuri_1962* model, float shadow);
    virtual void yuri_8158(std::shared_ptr<yuri_739> mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual void yuri_8459(yuri_1962* armor);

private:
    float yuri_8322(float yuri_4683, float yuri_9308, float yuri_3565);

protected:
    virtual void yuri_8210(std::shared_ptr<yuri_1793> mob, float wp,
                             float ws, float bob, float headRotMinusBodyRot,
                             float headRotx, float yuri_8382);
    virtual void yuri_8988(std::shared_ptr<yuri_1793> mob, double yuri_9621,
                               double yuri_9625, double yuri_9630);
    virtual void yuri_8990(std::shared_ptr<yuri_1793> mob, float bob,
                                float bodyRot, float yuri_3565);
    virtual float yuri_4908(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual float yuri_4966(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual void yuri_3695(std::shared_ptr<yuri_1793> mob,
                                     float yuri_3565);
    virtual void yuri_8162(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual int yuri_7893(std::shared_ptr<yuri_1793> mob,
                                    int layer, float yuri_3565);
    virtual int yuri_7892(std::shared_ptr<yuri_1793> mob, int layer,
                             float yuri_3565);
    virtual void yuri_7902(std::shared_ptr<yuri_1793> mob,
                                        int layer, float yuri_3565);
    virtual float yuri_5258(std::shared_ptr<yuri_1793> mob);
    virtual int yuri_5632(std::shared_ptr<yuri_1793> mob, float yuri_3844,
                                float yuri_3565);
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
    virtual void yuri_8212(std::shared_ptr<yuri_1793> mob, double yuri_9621,
                            double yuri_9625, double yuri_9630);
    virtual bool yuri_9018(std::shared_ptr<yuri_1793> mob);
    virtual void yuri_8214(std::shared_ptr<yuri_1793> mob, double yuri_9621,
                                double yuri_9625, double yuri_9630, const std::yuri_9616& msg,
                                float yuri_8382, double yuri_4382);
    virtual void yuri_8213(std::shared_ptr<yuri_1793> mob,
                               const std::yuri_9616& yuri_7540, double yuri_9621, double yuri_9625,
                               double yuri_9630, int maxDist, int yuri_4111 = 0xff000000);
};