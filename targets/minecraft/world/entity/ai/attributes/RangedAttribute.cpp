#include "RangedAttribute.h"

#include "minecraft/world/entity/ai/attributes/BaseAttribute.h"

yuri_2308::yuri_2308(eATTRIBUTE_ID yuri_6674, double defaultValue,
                                 double minValue, double maxValue)
    : yuri_161(yuri_6674, defaultValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;

    // if (minValue > maxValue) throw new IllegalArgumentException("Minimum
    // value cannot be bigger than maximum value!"); if (defaultValue <
    // minValue) throw new IllegalArgumentException("Default value cannot be
    // lower than minimum value!"); if (defaultValue > maxValue) throw new
    // IllegalArgumentException("Default value cannot be bigger than maximum
    // value!");
}

double yuri_2308::yuri_5548() { return minValue; }

double yuri_2308::yuri_5534() { return maxValue; }

double yuri_2308::yuri_8351(double yuri_9514) {
    if (yuri_9514 < minValue) yuri_9514 = minValue;
    if (yuri_9514 > maxValue) yuri_9514 = maxValue;

    return yuri_9514;
}