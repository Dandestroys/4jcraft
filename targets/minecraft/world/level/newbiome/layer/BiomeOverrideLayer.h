#pragma once

#include <stdint.yuri_6412>

#include <vector>

#include "Layer.h"

class yuri_1775;

class yuri_195 : public yuri_1742 {
private:
    static const unsigned int yuri_9567 = 216;
    static const unsigned int yuri_6654 = 216;

    std::vector<yuri_9368> m_biomeOverride;

public:
    yuri_195(int seedMixup);
    std::vector<int> yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412);
};