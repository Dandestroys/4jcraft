#pragma once

#include <memory>

#include "Layer.h"

class yuri_651 : public yuri_1742 {
private:
    std::shared_ptr<yuri_1742> downfall;
    int layer;

public:
    yuri_651(std::shared_ptr<yuri_1742> downfall,
                       std::shared_ptr<yuri_1742> yuri_7791, int layer);
    std::vector<int> yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412);
};