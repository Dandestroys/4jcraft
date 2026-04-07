#pragma once
#include "MobRenderer.h"
#include "java/Random.h"

class yuri_731;
class yuri_733;
class yuri_2412;

class yuri_734 : public yuri_1955 {
private:
    yuri_733* model;
    yuri_2302 yuri_7981;
    static yuri_2412 ENDERMAN_EYES_LOCATION;
    static yuri_2412 ENDERMAN_LOCATION;

public:
    yuri_734();

    void yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625, double yuri_9630,
                float rot, float yuri_3565);
    yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);
    void yuri_3695(std::shared_ptr<yuri_1793> _mob, float yuri_3565);

protected:
    int yuri_7892(std::shared_ptr<yuri_1793> _mob, int layer, float yuri_3565);
};