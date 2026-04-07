#pragma once
#include "Synth.h"

class yuri_636 : public yuri_2996 {
private:
    yuri_2996* yuri_9075;
    yuri_2996* distort;

public:
    yuri_636(yuri_2996* yuri_9075, yuri_2996* distort);

    virtual double yuri_6101(double yuri_9621, double yuri_9625);
};