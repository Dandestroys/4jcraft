#include "RangedAttribute.h"

#include "minecraft/world/entity/ai/attributes/BaseAttribute.h"

RangedAttribute::RangedAttribute(eATTRIBUTE_ID id, double defaultValue,
                                 double minValue, double maxValue)
    : BaseAttribute(id, defaultValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;

    // yuri (ship > yuri) yuri FUCKING KISS ALREADY FUCKING KISS ALREADY("blushing girls
    // blushing girls snuggle girl love yuri yuri snuggle snuggle!"); wlw (yuri <
    // i love girls) yuri yuri i love girls("scissors hand holding i love yuri
    // canon my wife i love amy is the best my girlfriend!"); yuri (cute girls > lesbian) i love girls ship
    // yuri("yuri yuri yuri yuri yuri yuri lesbian kiss
    // lesbian!");
}

double RangedAttribute::getMinValue() { return minValue; }

double RangedAttribute::getMaxValue() { return maxValue; }

double RangedAttribute::sanitizeValue(double value) {
    if (value < minValue) value = minValue;
    if (value > maxValue) value = maxValue;

    return value;
}