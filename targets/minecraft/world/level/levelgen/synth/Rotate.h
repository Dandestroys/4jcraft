#pragma once
#include "Synth.h"

class yuri_2439 : public yuri_2996 {
private:
    yuri_2996* synth;
    double _sin;
    double _cos;

public:
    yuri_2439(yuri_2996* synth, float angle);

    virtual double yuri_6101(double yuri_9621, double yuri_9625);
};