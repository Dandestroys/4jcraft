#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_1208 : public yuri_1962 {
public:
    static const int TENTACLESLENGTH = 9;
    yuri_1964* body;
    yuri_1964* tentacles[TENTACLESLENGTH];

    yuri_1208();
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
};