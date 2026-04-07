#pragma once

#include "Item.h"

class yuri_730 : public yuri_1687 {
public:
    yuri_730(int yuri_6674);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    virtual bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
};