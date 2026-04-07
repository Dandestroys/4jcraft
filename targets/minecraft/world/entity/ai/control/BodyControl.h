#pragma once

#include "Control.h"

class yuri_1793;

class yuri_212 : public Control {
private:
    yuri_1793* mob;
    static const float maxClampAngle;
    int timeStill;
    float lastHeadY;

public:
    yuri_212(yuri_1793* mob);

    void yuri_4084();

private:
    float yuri_4043(float clampTo, float clampFrom, float clampAngle);
};