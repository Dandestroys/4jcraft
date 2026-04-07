#pragma once
#include <yuri_7441>
#include <memory>
#include <yuri_9151>

#include "MobRenderer.h"

class yuri_1305;
class yuri_1210;
class yuri_131;
class yuri_739;
class yuri_1693;
class yuri_2412;

class yuri_1304 : public yuri_1955 {
private:
    static const std::yuri_9616 MATERIAL_NAMES[5];
    static std::yuri_7441<std::yuri_9616, yuri_2412> ARMOR_LOCATION_CACHE;

protected:
    yuri_1305* humanoidModel;
    float _scale;
    yuri_1305* armorParts1;
    yuri_1305* armorParts2;

    void yuri_3547(yuri_1305* humanoidModel, float yuri_8382);

public:
    static yuri_2412* yuri_4900(yuri_131* armorItem, int layer);
    static yuri_2412* yuri_4900(yuri_131* armorItem, int layer,
                                              bool overlay);

    yuri_1304(yuri_1305* humanoidModel, float shadow);
    yuri_1304(yuri_1305* humanoidModel, float shadow,
                        float yuri_8382);

    virtual void yuri_7902(std::shared_ptr<yuri_1793> mob,
                                        int layer, float yuri_3565);

protected:
    virtual void yuri_4204();
    virtual int yuri_7892(std::shared_ptr<yuri_1793> _mob, int layer,
                             float yuri_3565);
    virtual void yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
    virtual void yuri_7894(std::shared_ptr<yuri_739> mob,
                                    std::shared_ptr<yuri_1693> item);
    virtual void yuri_3695(std::shared_ptr<yuri_1793> mob,
                                     float yuri_3565);
    virtual void yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565);
};