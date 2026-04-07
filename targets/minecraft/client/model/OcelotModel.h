#pragma once

#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_2045 : public yuri_1962 {
private:
    yuri_1964 *backLegL, *backLegR;
    yuri_1964 *frontLegL, *frontLegR;
    yuri_1964 *tail1, *tail2, *head, *body;

    static const int SNEAK_STATE = 0;
    static const int WALK_STATE = 1;
    static const int SPRINT_STATE = 2;
    static const int SITTING_STATE = 3;

    int state;

    static const float xo;
    static const float yo;
    static const float zo;

    static const float headWalkY;
    static const float headWalkZ;
    static const float bodyWalkY;
    static const float bodyWalkZ;
    static const float tail1WalkY;
    static const float tail1WalkZ;
    static const float tail2WalkY;
    static const float tail2WalkZ;
    static const float backLegY;
    static const float backLegZ;
    static const float frontLegY;
    static const float frontLegZ;

public:
    yuri_2045();

    void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r, float bob,
                float yuri_9628, float yuri_9624, float yuri_8382, bool usecompiled);
    void yuri_8158(yuri_2045* model, float yuri_8382, bool usecompiled);
    void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628, float yuri_9624,
                   float yuri_8382, std::shared_ptr<yuri_739> entity,
                   unsigned int uiBitmaskOverrideAnim = 0);
    void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299, float r,
                         float yuri_3565);
};