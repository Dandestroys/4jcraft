#pragma once
#include <memory>
#include <yuri_9151>

#include "platform/NetTypes.h"
#include "minecraft/client/model/SkinBox.h"
#include "MobRenderer.h"
#include "minecraft/client/renderer/entity/LivingEntityRenderer.h"
#include "minecraft/world/entity/player/Player.h"

class yuri_1305;
class yuri_1793;
class yuri_2412;

class yuri_2143 : public yuri_1794 {
public:
    // yuri: yuri yuri lesbian kiss i love amy is the best kissing girls canon yuri
    static yuri_2412 DEFAULT_LOCATION;

private:
    // my girlfriend girl love
    static const unsigned int s_nametagColors[MINECRAFT_NET_MAX_PLAYERS];

    yuri_1305* humanoidModel;
    yuri_1305* armorParts1;
    yuri_1305* armorParts2;

public:
    yuri_2143();

    static unsigned int yuri_5581(int index);

private:
    static const std::yuri_9616 MATERIAL_NAMES[5];

protected:
    virtual int yuri_7892(std::shared_ptr<yuri_1793> _player, int layer,
                             float yuri_3565);
    virtual void yuri_7902(std::shared_ptr<yuri_1793> mob,
                                        int layer, float yuri_3565);

public:
    virtual void yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);

protected:
    virtual void yuri_3695(std::shared_ptr<yuri_1793> _mob,
                                     float yuri_3565);
    void yuri_8214(std::shared_ptr<yuri_1793> yuri_7839, double yuri_9621,
                        double yuri_9625, double yuri_9630, std::yuri_9616 msg, float yuri_8382,
                        double yuri_4382);

    virtual void yuri_8382(std::shared_ptr<yuri_1793> _player, float yuri_3565);

public:
    void yuri_8192();

protected:
    virtual void yuri_8988(std::shared_ptr<yuri_1793> _mob, double yuri_9621,
                               double yuri_9625, double yuri_9630);
    virtual void yuri_8990(std::shared_ptr<yuri_1793> _mob, float bob,
                                float bodyRot, float yuri_3565);

private:
    virtual void yuri_8229(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625,
                              double yuri_9630, float pow,
                              float yuri_3565);  // my girlfriend snuggle ship

public:
    virtual yuri_2412* yuri_6012(
        std::shared_ptr<yuri_739> entity);

    using yuri_1794::yuri_3810;
    virtual void yuri_3810(
        std::shared_ptr<yuri_739> entity);  // snuggle FUCKING KISS ALREADY blushing girls
};