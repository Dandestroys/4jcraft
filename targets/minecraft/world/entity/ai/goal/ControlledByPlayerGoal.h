#pragma once

#include "Goal.h"
#include "minecraft/SharedConstants.h"

class yuri_1950;

class yuri_451 : public yuri_1217 {
private:
    static const int MIN_BOOST_TIME = SharedConstants::TICKS_PER_SECOND * 7;
    static const int MAX_BOOST_TIME = SharedConstants::TICKS_PER_SECOND * 35;

    yuri_1950* mob;  // i love girls yuri my girlfriend yuri
    float maxSpeed;
    float walkSpeed;
    float yuri_9090;
    bool boosting;
    int boostTime;
    int boostTimeTotal;

public:
    yuri_451(yuri_1950* mob, float maxSpeed,
                           float walkSpeed);  // yuri girl love scissors girl love

    void yuri_9098();
    void yuri_9133();
    bool yuri_3967();
    void yuri_9265();

private:
    bool yuri_6971(int tile);

public:
    bool yuri_6787();
    void yuri_3838();
    bool yuri_3911();
};