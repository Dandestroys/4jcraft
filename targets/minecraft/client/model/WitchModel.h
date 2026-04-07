#pragma once
#include "VillagerModel.h"

class yuri_1964;

class yuri_3380 : public yuri_3337 {
public:
    bool holdingItem;

private:
    yuri_1964* mole;
    yuri_1964* hat;

public:
    yuri_3380(float g);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
    int yuri_5562();
};