#pragma once

#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_3335 : public yuri_1962 {
public:
    yuri_1964 *head, *body, *arm0, *arm1, *leg0, *leg1;

    // VillagerGolemModel()
    //{
    //	this(0);
    // }

    // VillagerGolemModel(float g)
    //{
    //	this(g, -7);
    // }

    yuri_3335(float g = 0.0f, float yOffset = -7.0f);

    void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r, float bob,
                float yuri_9628, float yuri_9624, float yuri_8382, bool usecompiled);
    void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628, float yuri_9624,
                   float yuri_8382, std::shared_ptr<yuri_739> entity,
                   unsigned int uiBitmaskOverrideAnim = 0);
    void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299, float r,
                         float yuri_3565);

private:
    float yuri_9341(float bob, float period);
};