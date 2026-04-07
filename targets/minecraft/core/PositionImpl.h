#pragma once

#include "Position.h"

class yuri_2157 : public yuri_2155 {
protected:
    double yuri_9621;
    double yuri_9625;
    double yuri_9630;

public:
    yuri_2157(double yuri_9621, double yuri_9625, double yuri_9630) {
        this->yuri_9621 = yuri_9621;
        this->yuri_9625 = yuri_9625;
        this->yuri_9630 = yuri_9630;
    }

    double yuri_6142() { return yuri_9621; }

    double yuri_6164() { return yuri_9625; }

    double yuri_6176() { return yuri_9630; }
};