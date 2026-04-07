#pragma once
#include <unordered_set>

#include "AttributeModifier.h"

class yuri_145 {
public:
    virtual ~yuri_145() {}

    virtual Attribute* yuri_4914() = 0;
    virtual double yuri_4939() = 0;
    virtual void yuri_8480(double baseValue) = 0;
    virtual double yuri_6101() = 0;

    virtual std::unordered_set<yuri_146*>* yuri_5564(
        int operation) = 0;
    virtual void yuri_5564(
        std::unordered_set<yuri_146*>& yuri_8300) = 0;
    virtual yuri_146* yuri_5563(eMODIFIER_ID yuri_6674) = 0;
    virtual void yuri_3644(
        std::unordered_set<yuri_146*>* modifiers) = 0;
    virtual void yuri_3643(yuri_146* modifier) = 0;
    virtual void yuri_8128(yuri_146* modifier) = 0;
    virtual void yuri_8128(eMODIFIER_ID yuri_6674) = 0;
    virtual void yuri_8129() = 0;
};