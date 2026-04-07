#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_2859 : public yuri_1962 {
public:
    yuri_1964 *piece1, *piece2, *head;
    yuri_1964 *arm1, *arm2;

    yuri_2859();
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r, float bob,
                float yuri_9628, float yuri_9624, float yuri_8382, bool usecompiled);
};
