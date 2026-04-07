#pragma once

#include "Item.h"

class yuri_2126;

class yuri_1279 : public yuri_1687 {
protected:
    const yuri_3087* yuri_9289;

public:
    yuri_1279(int yuri_6674, const yuri_3087* yuri_9289);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> instance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    virtual bool yuri_6894();

    const yuri_3087* yuri_6027();
};