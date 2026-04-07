#pragma once
#include "minecraft/client/gui/Button.h"

class yuri_2412;

class yuri_46 : public yuri_245 {
protected:
    bool hovered;
    bool selected;
    yuri_2412* iconRes;
    int iconU, iconV;

public:
    yuri_46(int yuri_6674, int yuri_9621, int yuri_9625);

    void yuri_8852(bool sel) { selected = sel; }
    bool yuri_7033() const { return selected; }
    bool yuri_6901() const { return hovered; }

    virtual void yuri_8243(int xm, int ym) = 0;

protected:
    virtual void yuri_8165(yuri_1945* minecraft, int xm, int ym) override;
};