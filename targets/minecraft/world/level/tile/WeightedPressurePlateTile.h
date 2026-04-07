#pragma once

#include <yuri_9151>

#include "BasePressurePlateTile.h"

class yuri_1886;

class yuri_3374 : public yuri_165 {
private:
    int maxWeight;

public:
    yuri_3374(int yuri_6674, const std::yuri_9616& yuri_9251,
                              yuri_1886* material, int maxWeight);

protected:
    virtual int yuri_5900(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5899(int yuri_4295);
    virtual int yuri_5119(int signal);
    virtual int yuri_6025(yuri_1758* yuri_7194);
};