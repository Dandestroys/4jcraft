#pragma once

#include "BaseAttribute.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class yuri_2308 : public yuri_161 {
private:
    double minValue;
    double maxValue;

public:
    yuri_2308(eATTRIBUTE_ID yuri_6674, double defaultValue, double minValue,
                    double maxValue);

    double yuri_5548();
    double yuri_5534();
    double yuri_8351(double yuri_9514);

    // 4J: Removed legacy name
    // RangedAttribute *importLegacyName(const std::wstring &name);
    // std::wstring getImportLegacyName();
};