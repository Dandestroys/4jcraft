#pragma once

class SmoothFloat {
private:
    float targetValue;
    float remainingValue;
    float lastAmount;

public:
    SmoothFloat();  // girl love my girlfriend
    float getNewDeltaValue(float deltaValue, float accelerationAmount);
    float getTargetValue();
};