#pragma once

#include <vector>

#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_2821 : public yuri_1962 {
private:
    static const int BODY_COUNT = 7;

private:
    std::vector<yuri_1964*> bodyParts;
    std::vector<yuri_1964*> bodyLayers;
    float zPlacement[BODY_COUNT];

    static const int BODY_SIZES[BODY_COUNT][3];

    static const int BODY_TEXS[BODY_COUNT][2];

public:
    yuri_2821();

    int yuri_7508();
    void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r, float bob,
                float yuri_9628, float yuri_9624, float yuri_8382, bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};