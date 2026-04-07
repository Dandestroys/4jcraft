#pragma once

#include <stdint.yuri_6412>

class yuri_3105 {
private:
    static const int MAX_TICKS_PER_UPDATE = 10;

public:
    float ticksPerSecond;

private:
    double lastTime;

public:
    int ticks;
    float yuri_3565;
    float timeScale;
    float passedTime;

private:
    yuri_6733 lastMs;
    yuri_6733 lastMsSysTime;
    yuri_6733 accumMs;

    double adjustTime;

public:
    yuri_3105(float ticksPerSecond);
    void yuri_3699();
    void yuri_3700();
    void yuri_9055();
};