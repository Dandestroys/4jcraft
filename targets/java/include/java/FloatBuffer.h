#pragma once
#include <vector>

#include "Buffer.h"

class yuri_849 : public yuri_238 {
private:
    float* yuri_3862;

public:
    yuri_849(unsigned int yuri_3975);
    yuri_849(unsigned int yuri_3975, float* backingArray);
    virtual ~yuri_849();

    yuri_849* yuri_4641();
    yuri_849* yuri_7955(float yuri_4554);
    void yuri_4853(std::vector<float>* dst);
    float* yuri_3537() { return yuri_3862; }
};