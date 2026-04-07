#pragma once

#include <memory>

#include "DiodeTile.h"
#include "EntityTile.h"

class yuri_398;
class yuri_1758;
class yuri_1771;
class yuri_2302;

class yuri_397 : public yuri_613, public EntityTile {
private:
    static const int BIT_OUTPUT_SUBTRACT = 0x4;
    static const int BIT_IS_LIT = 0x8;

public:
    yuri_397(int yuri_6674, bool on);

    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual int yuri_6064(int yuri_4295);
    virtual yuri_613* yuri_5619();
    virtual yuri_613* yuri_5613();

public:
    virtual int yuri_5806();
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);

protected:
    virtual bool yuri_6976(int yuri_4295);
    virtual int yuri_5630(yuri_1771* levelSource, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4295);

private:
    virtual int yuri_3896(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4295);

public:
    virtual bool yuri_7015(int yuri_4295);

protected:
    virtual bool yuri_9022(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual int yuri_5402(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual std::shared_ptr<yuri_398> yuri_5042(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);

protected:
    virtual void yuri_4032(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_9364);

private:
    virtual void yuri_8065(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    yuri_2302* yuri_7981);

public:
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual bool yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int b0,
                              int b1);
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual bool yuri_3033();
};