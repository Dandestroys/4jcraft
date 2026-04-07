#pragma once

#include <memory>

#include "Layer.h"

class yuri_3027 : public yuri_1742 {
private:
    std::shared_ptr<yuri_1742> yuri_9193;
    int layer;

public:
    yuri_3027(std::shared_ptr<yuri_1742> yuri_9193,
                          std::shared_ptr<yuri_1742> yuri_7791, int layer);

    virtual std::vector<int> yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412);
};