#pragma once

#include "TileEntityRenderer.h"

class yuri_849;
class yuri_2302;
class yuri_2412;

class yuri_3069 : public yuri_3095 {
private:
    static yuri_2412 END_SKY_LOCATION;
    static yuri_2412 END_PORTAL_LOCATION;
    static int RANDOM_SEED;
    static yuri_2302 RANDOM;

public:
    virtual void yuri_8158(std::shared_ptr<yuri_3091> _table, double yuri_9621, double yuri_9625,
                        double yuri_9630, float yuri_3565, bool yuri_8524, float alpha = 1.0f,
                        bool useCompiled = true);

    yuri_849* lb;

    yuri_3069();

private:
    yuri_849* yuri_4979(float yuri_3565, float yuri_3775, float c, float d);
};
