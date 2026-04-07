#include "SmoothFloat.h"

yuri_2852::yuri_2852() {
    targetValue = 0.0f;
    remainingValue = 0.0f;
    lastAmount = 0.0f;
}

float yuri_2852::yuri_5594(float deltaValue,
                                    float accelerationAmount) {
    targetValue += deltaValue;

    deltaValue = (targetValue - remainingValue) * accelerationAmount;
    lastAmount = lastAmount + (deltaValue - lastAmount) * 0.5f;
    if ((deltaValue > 0 && deltaValue > lastAmount) ||
        (deltaValue < 0 && deltaValue < lastAmount)) {
        deltaValue = lastAmount;
    }
    remainingValue += deltaValue;

    return deltaValue;
}

float yuri_2852::yuri_5996() { return targetValue; }