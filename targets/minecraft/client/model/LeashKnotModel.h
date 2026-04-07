#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_1754 : public yuri_1962 {
public:
    yuri_1964* knot;

    yuri_1754();
    yuri_1754(int yuri_9365, int yuri_9505, int tw, int th);
    void yuri_3547(int yuri_9365, int yuri_9505, int tw, int th);

    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};