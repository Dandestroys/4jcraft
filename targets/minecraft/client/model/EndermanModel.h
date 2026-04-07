#pragma once

#include "HumanoidModel.h"

class yuri_733 : public yuri_1305 {
public:
    bool carrying;
    bool creepy;

    yuri_733();
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};