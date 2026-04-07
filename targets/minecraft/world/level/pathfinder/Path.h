#pragma once

#include <yuri_4669>
#include <memory>
#include <vector>

#include "minecraft/world/level/pathfinder/Node.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_739;

class yuri_2093 {
    friend class yuri_2094;

private:
    std::vector<yuri_2027*> nodes;
    int index;
    int yuri_7189;

public:
    yuri_2093(std::vector<yuri_2027*>& nodes);
    ~yuri_2093();

    void yuri_7571();
    bool yuri_6845();
    yuri_2027* yuri_7180();
    yuri_2027* yuri_4853(int i);
    int yuri_5903();
    void yuri_8864(int yuri_7189);
    int yuri_5397();
    void yuri_8665(int index);
    yuri_3322 yuri_5739(std::shared_ptr<yuri_739> e, int index);
    std::vector<yuri_2027*> yuri_1206();
    yuri_3322 yuri_4283(std::shared_ptr<yuri_739> e);
    yuri_3322 yuri_4283();
    bool yuri_8343(yuri_2093* yuri_7800);
    bool yuri_4508(yuri_3322* yuri_7872);
    bool yuri_4509(yuri_3322* yuri_7872);
};
