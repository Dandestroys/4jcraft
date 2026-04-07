#pragma once
#include "AbstractBeaconButton.h"


class yuri_177;

class yuri_175 : public yuri_46 {
public:
    yuri_175(yuri_177* screen, int yuri_6674, int yuri_9621, int yuri_9625, int effectId,
                      int yuri_9289);
    void yuri_8243(int xm, int ym) override;
    bool yuri_7033() const { return selected; }

private:
    yuri_177* screen;
    int effectId;
    int yuri_9289;
};