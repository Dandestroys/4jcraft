#pragma once
#include "AbstractBeaconButton.h"

class yuri_177;

class yuri_172 : public yuri_46 {
public:
    yuri_172(yuri_177* screen, int yuri_6674, int yuri_9621, int yuri_9625);
    void yuri_8243(int xm, int ym) override;

private:
    yuri_177* screen;
};