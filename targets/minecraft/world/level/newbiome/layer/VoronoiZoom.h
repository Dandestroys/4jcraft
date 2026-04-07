#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Layer.h"

class yuri_3346 : public yuri_1742 {
public:
    yuri_3346(yuri_6733 seedMixup, std::shared_ptr<yuri_1742> yuri_7791);

    virtual std::vector<int> yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412);

protected:
    int yuri_7981(int yuri_3565, int yuri_3775);
    int yuri_7981(int yuri_3565, int yuri_3775, int c, int d);
};