#pragma once

#include "DiodeTile.h"

class yuri_2393 : public yuri_613 {
public:
    static const int DELAY_MASK = DIRECTION_INV_MASK;
    static const int DELAY_SHIFT = 2;

    static const double DELAY_RENDER_OFFSETS[4];

private:
    static const int DELAYS[4];

public:
    yuri_2393(int yuri_6674, bool on);

    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);

protected:
    virtual int yuri_6064(int yuri_4295);
    virtual yuri_613* yuri_5619();
    virtual yuri_613* yuri_5613();

public:
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5806();
    virtual bool yuri_6949(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);

protected:
    virtual bool yuri_6768(int tile);

public:
    void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_2302* yuri_7981);
    void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);

    virtual bool yuri_3033();
};