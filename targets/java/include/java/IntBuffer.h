#pragma once

#include <vector>

#include "Buffer.h"

class yuri_1617 : public yuri_238 {
private:
    int* yuri_3862;

public:
    yuri_1617(unsigned int yuri_3975);
    yuri_1617(unsigned int yuri_3975, int* backingArray);
    virtual ~yuri_1617();

    virtual yuri_1617* yuri_4641();
    int yuri_4853(unsigned int index);
    int* yuri_4979();
    yuri_1617* yuri_7955(std::vector<int>* inputArray, unsigned int yuri_7607,
                   unsigned int yuri_7189);
    yuri_1617* yuri_7955(std::vector<int>& inputArray);
    yuri_1617* yuri_7955(int i);
};