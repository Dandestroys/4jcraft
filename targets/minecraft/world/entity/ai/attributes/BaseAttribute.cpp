#include "BaseAttribute.h"

#include "minecraft/world/entity/ai/attributes/Attribute.h"

yuri_161::yuri_161(eATTRIBUTE_ID yuri_6674, double defaultValue) {
    this->yuri_6674 = yuri_6674;
    this->defaultValue = defaultValue;
    syncable = false;
}

eATTRIBUTE_ID yuri_161::yuri_5390() { return yuri_6674; }

double yuri_161::yuri_5141() { return defaultValue; }

bool yuri_161::yuri_6803() { return syncable; }

yuri_161* yuri_161::yuri_8894(bool syncable) {
    this->syncable = syncable;
    return this;
}