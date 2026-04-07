#pragma once
#include "EntityRenderer.h"

class yuri_2830;
class yuri_2412;

class yuri_3386 : public yuri_746 {
private:
    static yuri_2412 yuri_3350;
    static yuri_2412 yuri_3351;

    yuri_2830* model;

public:
    yuri_3386();
    void yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625, double yuri_9630,
                float rot, float yuri_3565);
    yuri_2412* yuri_6012(std::shared_ptr<yuri_739> entity);

private:
    float yuri_8322(float yuri_4683, float yuri_9308, float yuri_3565);
};