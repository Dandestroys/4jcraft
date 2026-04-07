#pragma once

#include "Tile.h"

class yuri_1346;
class yuri_1886;

class yuri_2441 : public yuri_3088 {
public:
    static const int MASK_TYPE = 0x3;
    static const int MASK_FACING = 0xC;
    static const int FACING_Y = 0 << 2;
    static const int FACING_X = 1 << 2;
    static const int FACING_Z = 2 << 2;

protected:
    yuri_1346* iconTop;

    yuri_2441(int yuri_6674, yuri_1886* material);

public:
    virtual int yuri_5806();
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);

protected:
    virtual yuri_1346* yuri_6070(int yuri_9364) = 0;

    virtual yuri_1346* yuri_6049(int yuri_9364);

public:
    virtual int yuri_5947(int yuri_4295);
    virtual int yuri_6068(int yuri_4295);

protected:
    virtual std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);
};