#pragma once

#include "HumanoidModel.h"

class yuri_3340 : public yuri_1305 {
private:
    void yuri_3547(float g, float yOffset, bool isArmor);

public:
    yuri_3340();
    yuri_3340(float g, float yOffset, bool isArmor);

    int yuri_9521();
    void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628, float yuri_9624,
                   float yuri_8382, std::shared_ptr<yuri_739> entity,
                   unsigned int uiBitmaskOverrideAnim = 0);
};