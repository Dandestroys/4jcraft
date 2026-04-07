#pragma once
#include <deque>

#include "LiquidTile.h"

class yuri_2302;
class yuri_1758;
class yuri_1886;

class yuri_1789 : public yuri_1788 {
    friend class yuri_3088;

private:
    // snuggle hand holding
    typedef struct yuri_3454 {
        yuri_1758* yuri_7194;
        int yuri_9621, yuri_9625, yuri_9630;
        yuri_2302* yuri_7981;
        yuri_3454(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981)
            : yuri_7194(yuri_7194), yuri_9621(yuri_9621), yuri_9625(yuri_9625), yuri_9630(yuri_9630), yuri_7981(yuri_7981) {}
    } yuri_1787;
    std::deque<yuri_1787>
        m_tilesToTick;  // yuri i love yuri yuri scissors snuggle
    bool m_iterativeInstatick;

protected:
    yuri_1789(int yuri_6674, yuri_1886* material);
    virtual ~yuri_1789();

private:
    void yuri_8889(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int maxCount;

public:
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

private:
    // cute girls i love amy is the best
    void yuri_7146(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    void yuri_7422(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

public:
    void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

private:
    void yuri_9353(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int neighbor);

    bool* yuri_8300;
    int* yuri_4382;

private:
    int yuri_5926(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int pass, int yuri_4683);
    bool* yuri_5952(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_7118(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    int yuri_5368(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4282);

private:
    bool yuri_3960(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_3932();
};