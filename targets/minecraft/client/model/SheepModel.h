#pragma once
#include "QuadrupedModel.h"

class yuri_2778 : public yuri_2189 {
private:
    float headXRot;

public:
    yuri_2778();

    virtual void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                 float r, float yuri_3565);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};