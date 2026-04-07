#pragma once
#include "TileEntityRenderer.h"

class yuri_180;
class yuri_2412;

class yuri_176 : public yuri_3095 {
private:
    static yuri_2412 BEAM_LOCATION;

public:
    virtual void yuri_8158(std::shared_ptr<yuri_3091> _beacon, double yuri_9621, double yuri_9625,
                        double yuri_9630, float yuri_3565, bool yuri_8524, float alpha,
                        bool useCompiled);
};
