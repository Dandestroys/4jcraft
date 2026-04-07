#pragma once
#include "Button.h"

class yuri_3127 : public yuri_245 {
private:
    bool mirrored;

public:
    yuri_3127(int yuri_6674, int yuri_9621, int yuri_9625, bool mirrored);

protected:
    int yuri_6168(bool hovered) override;
    void yuri_8165(yuri_1945* minecraft, int xm, int ym) override;
};