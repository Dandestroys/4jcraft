#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_169 : public yuri_1962 {
private:
    yuri_1964* head;
    yuri_1964* body;
    yuri_1964* rightWing;
    yuri_1964* leftWing;
    yuri_1964* rightWingTip;
    yuri_1964* leftWingTip;

public:
    yuri_169();

    int yuri_7508();

    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
};