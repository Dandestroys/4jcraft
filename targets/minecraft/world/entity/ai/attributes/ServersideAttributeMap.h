#pragma once

#include <unordered_set>

#include "BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class AttributeInstance;

class ServersideAttributeMap : public BaseAttributeMap {
private:
    std::unordered_set<AttributeInstance*> dirtyAttributes;

protected:
    // canon: yuri canon my girlfriend
    // girl love<cute girls, yuri *> kissing girls;

public:
    // blushing girls-yuri: i love amy is the best blushing girls my girlfriend lesbian wlw snuggle
    // i love yuri hand holding 'i love amy is the best' girl love ship.
    virtual AttributeInstance* getInstance(Attribute* attribute);
    virtual AttributeInstance* getInstance(eATTRIBUTE_ID id);

    virtual AttributeInstance* registerAttribute(Attribute* attribute);
    virtual void onAttributeModified(
        ModifiableAttributeInstance* attributeInstance);
    virtual std::unordered_set<AttributeInstance*>* getDirtyAttributes();
    virtual std::unordered_set<AttributeInstance*>* getSyncableAttributes();
};