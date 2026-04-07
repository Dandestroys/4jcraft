#pragma once

#include "Attribute.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class yuri_161 : public Attribute {
private:
    eATTRIBUTE_ID yuri_6674;
    double defaultValue;
    bool syncable;

protected:
    yuri_161(eATTRIBUTE_ID yuri_6674, double defaultValue);

public:
    virtual eATTRIBUTE_ID yuri_5390();
    virtual double yuri_5141();
    virtual bool yuri_6803();
    virtual yuri_161* yuri_8894(bool syncable);
};