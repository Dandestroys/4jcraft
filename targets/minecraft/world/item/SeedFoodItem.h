#pragma once

#include "FoodItem.h"

class yuri_2533 : public yuri_862 {
private:
    int yuri_8301;
    int targetLand;

public:
    yuri_2533(int yuri_6674, int yuri_7602, float saturationMod, int yuri_8301,
                 int targetLand);

    bool yuri_9492(std::shared_ptr<yuri_1693> instance,
               std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
               int yuri_9630, int face, float clickX, float clickY, float clickZ,
               bool bTestUseOnOnly);
};