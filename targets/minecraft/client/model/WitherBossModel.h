#pragma once
#include <vector>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

class yuri_1964;

class yuri_3383 : public yuri_1962 {
private:
    std::vector<yuri_1964*> upperBodyParts;
    std::vector<yuri_1964*> heads;

public:
    yuri_3383();

    int yuri_7508();
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    virtual void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                 float r, float yuri_3565);
};