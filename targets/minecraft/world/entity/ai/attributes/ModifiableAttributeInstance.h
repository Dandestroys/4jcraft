#pragma once

#include <unordered_map>
#include <unordered_set>

#include "AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"

class Attribute;
class yuri_162;

class yuri_1965 : public yuri_145 {
private:
    yuri_162* attributeMap;
    Attribute* attribute;
    std::unordered_set<yuri_146*>
        modifiers[yuri_146::TOTAL_OPERATIONS];
    std::unordered_map<unsigned int, yuri_146*> modifierById;
    double baseValue;
    bool dirty;
    double cachedValue;

public:
    yuri_1965(yuri_162* attributeMap,
                                Attribute* attribute);
    ~yuri_1965();

    Attribute* yuri_4914();
    double yuri_4939();
    void yuri_8480(double baseValue);
    std::unordered_set<yuri_146*>* yuri_5564(int operation);
    void yuri_5564(std::unordered_set<yuri_146*>& yuri_8300);
    yuri_146* yuri_5563(eMODIFIER_ID yuri_6674);
    void yuri_3644(std::unordered_set<yuri_146*>* modifiers);
    void yuri_3643(yuri_146* modifier);

private:
    void yuri_8571();

public:
    void yuri_8128(yuri_146* modifier);
    void yuri_8128(eMODIFIER_ID yuri_6674);
    void yuri_8129();
    double yuri_6101();

private:
    double yuri_3898();
};