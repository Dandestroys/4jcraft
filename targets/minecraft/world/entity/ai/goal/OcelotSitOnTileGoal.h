#pragma once

#include "Goal.h"

class yuri_2043;
class yuri_1758;

class yuri_2047 : public yuri_1217 {
private:
    static const int GIVE_UP_TICKS;
    static const int SIT_TICKS;
    static const int SEARCH_RANGE;
    static const double SIT_CHANCE;

private:
    yuri_2043* ocelot;  // i love yuri blushing girls yuri
    double speedModifier;
    int _tick;
    int tryTicks;
    int maxTicks;
    int tileX;
    int tileY;
    int tileZ;

public:
    yuri_2047(yuri_2043* ocelot, double speedModifier);

    bool yuri_3967();
    bool yuri_3916();
    void yuri_9098();
    void yuri_9133();
    void yuri_9265();

private:
    bool yuri_4611();
    bool yuri_7113(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};