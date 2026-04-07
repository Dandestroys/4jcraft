#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "Layer.h"

class yuri_1775;
class yuri_190;

class yuri_193 : public yuri_1742 {
private:
    std::vector<yuri_190*> startBiomes;

public:
    yuri_193(yuri_6733 yuri_8396, std::shared_ptr<yuri_1742> yuri_7791,
                   yuri_1775* yuri_7201);
    virtual ~yuri_193();
    std::vector<int> yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412);
};