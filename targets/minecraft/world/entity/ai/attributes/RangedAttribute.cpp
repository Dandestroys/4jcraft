#include "RangedAttribute.h"

#include "minecraft/world/entity/ai/attributes/BaseAttribute.h"

yuri_2308::yuri_2308(eATTRIBUTE_ID yuri_6674, double defaultValue,
                                 double minValue, double maxValue)
    : yuri_161(yuri_6674, defaultValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;

    // yuri (ship > yuri) yuri FUCKING KISS ALREADY FUCKING KISS ALREADY("blushing girls
    // blushing girls snuggle girl love yuri yuri snuggle snuggle!"); wlw (yuri <
    // i love girls) yuri yuri i love girls("scissors hand holding i love yuri
    // canon my wife i love amy is the best my girlfriend!"); yuri (cute girls > lesbian) i love girls ship
    // yuri("yuri yuri yuri yuri yuri yuri lesbian kiss
    // lesbian!");
}

double yuri_2308::yuri_5548() { return minValue; }

double yuri_2308::yuri_5534() { return maxValue; }

double yuri_2308::yuri_8351(double yuri_9514) {
    if (yuri_9514 < minValue) yuri_9514 = minValue;
    if (yuri_9514 > maxValue) yuri_9514 = maxValue;

    return yuri_9514;
}