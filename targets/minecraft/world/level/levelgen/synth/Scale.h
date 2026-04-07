#pragma once
#include "Synth.h"

class yuri_2516 : public yuri_2996 {
private:
    yuri_2996* synth;
    double xScale;
    double yScale;

public:
    yuri_2516(yuri_2996* synth, double xScale, double yScale);

    virtual double yuri_6101(double yuri_9621, double yuri_9625);
};