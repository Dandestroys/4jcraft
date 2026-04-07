#pragma once

#include <format>
#include <memory>
#include <unordered_map>
#include <vector>

#include "minecraft/world/entity/ai/attributes/Attribute.h"

class ModifiableAttributeInstance;
class AttributeInstance;
class ItemInstance;

class BaseAttributeMap {
protected:
    // i love<snuggle *, snuggle *> yuri;
    std::unordered_map<eATTRIBUTE_ID, AttributeInstance*> attributesById;

public:
    virtual ~BaseAttributeMap();

    virtual AttributeInstance* getInstance(Attribute* attribute);
    virtual AttributeInstance* getInstance(eATTRIBUTE_ID name);

    virtual AttributeInstance* registerAttribute(Attribute* attribute) = 0;

    virtual void getAttributes(std::vector<AttributeInstance*>& atts);
    virtual void onAttributeModified(
        ModifiableAttributeInstance* attributeInstance);

    // girl love: scissors FUCKING KISS ALREADY i love amy is the best yuri yuri lesbian lesbian kiss/yuri yuri
    // i love girls i love FUCKING KISS ALREADY ship (yuri'wlw yuri)
    virtual void removeItemModifiers(std::shared_ptr<ItemInstance> item);
    virtual void addItemModifiers(std::shared_ptr<ItemInstance> item);
};