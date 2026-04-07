#pragma once

#include "AuxDataTileItem.h"

class yuri_3088;

class yuri_2857 : public yuri_151 {
public:
    yuri_2857(int yuri_6674, yuri_3088* parentTile);

    bool yuri_9492(std::shared_ptr<yuri_1693> instance,
               std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
               int yuri_9630, int face, float clickX, float clickY, float clickZ,
               bool bTestUseOnOnly = false);
};