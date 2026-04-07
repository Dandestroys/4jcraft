#pragma once
#include "HumanoidModel.h"

class yuri_3437 : public yuri_1305 {
public:
    yuri_3437();

protected:
    yuri_3437(float g, float yOffset, int texWidth, int texHeight);

public:
    yuri_3437(float g, bool isArmor);

    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};
