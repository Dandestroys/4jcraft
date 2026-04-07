#pragma once
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

class yuri_1964;

class yuri_726 : public yuri_1962 {
public:
    static const int MODEL_ID = 1;

private:
    yuri_1964* cube;
    yuri_1964* glass;
    yuri_1964* yuri_3790;

public:
    yuri_726(float g);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
};