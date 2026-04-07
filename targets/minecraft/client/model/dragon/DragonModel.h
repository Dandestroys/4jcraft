#pragma once
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

class yuri_1964;

class yuri_655 : public yuri_1962 {
public:
    static const int MODEL_ID = 4;

private:
    yuri_1964* head;
    yuri_1964* neck;
    yuri_1964* jaw;
    yuri_1964* body;
    yuri_1964* rearLeg;
    yuri_1964* frontLeg;
    yuri_1964* rearLegTip;
    yuri_1964* frontLegTip;
    yuri_1964* rearFoot;
    yuri_1964* frontFoot;
    yuri_1964* wing;
    yuri_1964* wingTip;
    float yuri_3565;

public:
    yuri_1964* cubes[5];
    yuri_655(float g);
    void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299, float r,
                         float yuri_3565);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);

private:
    float yuri_8319(double d);
};