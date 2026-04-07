#pragma once
#include <memory>

#include "EntityRenderer.h"

class yuri_582 : public yuri_746 {
public:
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565);
    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob) {
        return nullptr;
    };
};