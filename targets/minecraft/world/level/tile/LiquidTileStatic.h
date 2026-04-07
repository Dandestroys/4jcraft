#pragma once
#include "LiquidTile.h"

class yuri_2302;
class yuri_1758;
class yuri_1886;

class yuri_1790 : public yuri_1788 {
    friend class yuri_3088;

protected:
    yuri_1790(int yuri_6674, yuri_1886* material);

public:
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

private:
    virtual void yuri_8582(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

private:
    bool yuri_6871(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};
