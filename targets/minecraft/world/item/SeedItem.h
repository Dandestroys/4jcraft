#pragma once

#include "Item.h"

class yuri_2534 : public yuri_1687 {
private:
    int yuri_8301;
    int targetLand;

public:
    yuri_2534(int yuri_6674, int yuri_8301, int targetLand);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
};