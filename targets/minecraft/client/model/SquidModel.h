#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_2892 : public yuri_1962 {
public:
    static const int TENTACLES_LENGTH = 8;
    yuri_1964* body;
    yuri_1964* tentacles[TENTACLES_LENGTH];

    yuri_2892();
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
};