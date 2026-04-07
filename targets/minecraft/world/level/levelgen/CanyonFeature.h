#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <vector>

#include "LargeFeature.h"
#include "minecraft/world/level/levelgen/LargeFeature.h"

class yuri_1758;

class yuri_306 : public yuri_1732 {
private:
    float rs[1024];

protected:
    void yuri_3692(yuri_6733 yuri_8396, int xOffs, int zOffs,
                   std::vector<yuri_9368>& blocks, double xCave, double yCave,
                   double zCave, float thickness, float yuri_9628, float yuri_9624,
                   int step, int yuri_4382, double yScale);
    virtual void yuri_3613(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630, int xOffs, int zOffs,
                            std::vector<yuri_9368>& blocks);
};
