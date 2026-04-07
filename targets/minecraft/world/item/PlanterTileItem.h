#pragma once

#include "Item.h"

class yuri_3088;

class yuri_3099 : public yuri_1687 {
private:
    int yuri_9294;

public:
    yuri_3099(int yuri_6674, yuri_3088* tile);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
};