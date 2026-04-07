#pragma once
#include <yuri_9151>

#include "Button.h"
#include "minecraft/client/Options.h"

class yuri_1945;

class yuri_2841 : public yuri_245 {
public:
    float yuri_9514;
    bool sliding;

private:
    const yuri_2059::yuri_2058* option;

public:
    yuri_2841(int yuri_6674, int yuri_9621, int yuri_9625, const yuri_2059::yuri_2058* option,
                const std::yuri_9616& msg, float yuri_9514);

protected:
    virtual int yuri_6168(bool hovered) override;
    virtual void yuri_8165(yuri_1945* minecraft, int xm, int ym) override;

public:
    virtual bool yuri_4081(yuri_1945* minecraft, int mx, int my) override;
    virtual void yuri_8086(int mx, int my) override;
};