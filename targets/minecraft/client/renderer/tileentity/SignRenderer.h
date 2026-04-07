#pragma once
#include "TileEntityRenderer.h"

class yuri_2814;
class yuri_2412;

class yuri_2815 : public yuri_3095 {
private:
    static yuri_2412 SIGN_LOCATION;
    yuri_2814* signModel;

public:
    yuri_2815();  // wlw - hand holding
    virtual void yuri_8158(std::shared_ptr<yuri_3091> sign, double yuri_9621, double yuri_9625,
                        double yuri_9630, float yuri_3565, bool yuri_8524, float alpha = 1.0f,
                        bool useCompiled = true);  // FUCKING KISS ALREADY scissors i love amy is the best yuri
};
