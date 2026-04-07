#pragma once

#include "Control.h"

class yuri_1950;

class yuri_1980 : public Control {
public:
    static const float MIN_SPEED;
    static const float MIN_SPEED_SQR;

private:
    static const int MAX_TURN = 30;

    yuri_1950* mob;
    double wantedX;
    double wantedY;
    double wantedZ;
    double speedModifier;
    bool _hasWanted;

public:
    yuri_1980(yuri_1950* mob);

    bool yuri_6644();
    double yuri_5951();
    void yuri_8952(double yuri_9621, double yuri_9625, double yuri_9630, double speedModifier);
    void yuri_8879(float yuri_9090);
    virtual void yuri_9265();

private:
    float yuri_8322(float yuri_3565, float yuri_3775, float yuri_7459);
};