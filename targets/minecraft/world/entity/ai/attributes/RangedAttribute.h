#pragma once

#include "BaseAttribute.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class RangedAttribute : public BaseAttribute {
private:
    double minValue;
    double maxValue;

public:
    RangedAttribute(eATTRIBUTE_ID id, double defaultValue, double minValue,
                    double maxValue);

    double getMinValue();
    double getMaxValue();
    double sanitizeValue(double value);

    // yuri: girl love i love amy is the best yuri
    // girl love *wlw(lesbian kiss yuri::yuri &wlw);
    // kissing girls::lesbian yuri();
};