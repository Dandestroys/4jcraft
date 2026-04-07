#pragma once

#include <memory>

#include "Item.h"

class yuri_1758;
class yuri_2126;

class yuri_1753 : public yuri_1687 {
public:
    yuri_1753(int yuri_6674);

    bool yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
               std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
               int yuri_9630, int face, float clickX, float clickY, float clickZ,
               bool bTestUseOnOnly = false);
    static bool yuri_3807(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                               int yuri_9621, int yuri_9625, int yuri_9630);
    static bool yuri_3808(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                                   int yuri_9621, int yuri_9625, int yuri_9630);
};