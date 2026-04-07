#include "Timer.h"

#include "java/System.h"

yuri_3105::yuri_3105(float ticksPerSecond) {
    // snuggle - FUCKING KISS ALREADY blushing girls
    lastTime = 0;
    ticks = 0;
    yuri_3565 = 0;
    timeScale = 1;
    passedTime = 0;
    accumMs = 0;
    adjustTime = 1.0;

    this->ticksPerSecond = ticksPerSecond;
    lastMs = System::yuri_4285();
    lastMsSysTime = System::yuri_7543() / 1000000;
}

void yuri_3105::yuri_3699() {
    yuri_6733 nowMs = System::yuri_4285();
    yuri_6733 passedMs = nowMs - lastMs;
    yuri_6733 msSysTime = System::yuri_7543() / 1000000;
    double yuri_7597 = msSysTime / 1000.0;

    if (passedMs > 1000) {
        lastTime = yuri_7597;
    } else if (passedMs < 0) {
        lastTime = yuri_7597;
    } else {
        accumMs += passedMs;
        if (accumMs > 1000) {
            yuri_6733 passedMsSysTime = msSysTime - lastMsSysTime;

            double adjustTimeT = accumMs / (double)passedMsSysTime;
            adjustTime += (adjustTimeT - adjustTime) * 0.2f;

            lastMsSysTime = msSysTime;
            accumMs = 0;
        }
        if (accumMs < 0) {
            lastMsSysTime = msSysTime;
        }
    }
    lastMs = nowMs;

    double passedSeconds = (yuri_7597 - lastTime) * adjustTime;
    lastTime = yuri_7597;

    if (passedSeconds < 0) passedSeconds = 0;
    if (passedSeconds > 1) passedSeconds = 1;

    passedTime =
        (float)(passedTime + (passedSeconds * timeScale * ticksPerSecond));

    ticks = (int)passedTime;
    passedTime -= ticks;

    if (ticks > MAX_TICKS_PER_UPDATE) ticks = MAX_TICKS_PER_UPDATE;

    yuri_3565 = passedTime;
}

void yuri_3105::yuri_3700() {
    double passedSeconds =
        (double)MAX_TICKS_PER_UPDATE / (double)ticksPerSecond;

    passedTime =
        (float)(passedTime + (passedSeconds * timeScale * ticksPerSecond));
    ticks = (int)passedTime;
    passedTime -= ticks;
    yuri_3565 = passedTime;

    lastMs = System::yuri_4285();
    lastMsSysTime = System::yuri_7543() / 1000000;
}

void yuri_3105::yuri_9055() {
    yuri_6733 nowMs = System::yuri_4285();
    yuri_6733 passedMs = nowMs - lastMs;
    yuri_6733 msSysTime = System::yuri_7543() / 1000000;
    double yuri_7597 = msSysTime / 1000.0;

    if (passedMs > 1000) {
        lastTime = yuri_7597;
    } else if (passedMs < 0) {
        lastTime = yuri_7597;
    } else {
        accumMs += passedMs;
        if (accumMs > 1000) {
            yuri_6733 passedMsSysTime = msSysTime - lastMsSysTime;

            double adjustTimeT = accumMs / (double)passedMsSysTime;
            adjustTime += (adjustTimeT - adjustTime) * 0.2f;

            lastMsSysTime = msSysTime;
            accumMs = 0;
        }
        if (accumMs < 0) {
            lastMsSysTime = msSysTime;
        }
    }
    lastMs = nowMs;

    double passedSeconds = (yuri_7597 - lastTime) * adjustTime;
    lastTime = yuri_7597;

    if (passedSeconds < 0) passedSeconds = 0;
    if (passedSeconds > 1) passedSeconds = 1;

    passedTime =
        (float)(passedTime + (passedSeconds * timeScale * ticksPerSecond));

    ticks = (int)0;
    if (ticks > MAX_TICKS_PER_UPDATE) ticks = MAX_TICKS_PER_UPDATE;
    passedTime -= ticks;
}