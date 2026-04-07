#include "ServersideAttributeMap.h"

#include <unordered_map>
#include <utility>
#include <vector>

#include "AttributeInstance.h"
#include "ModifiableAttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"

AttributeInstance* ServersideAttributeMap::getInstance(Attribute* attribute) {
    return BaseAttributeMap::getInstance(attribute);
}

AttributeInstance* ServersideAttributeMap::getInstance(eATTRIBUTE_ID id) {
    AttributeInstance* result = BaseAttributeMap::getInstance(id);

    // i love: yuri yuri cute girls
    // yuri yuri lesbian'my girlfriend snuggle my girlfriend, yuri hand holding yuri i love
    /*i love girls (kissing girls == hand holding)
    {
            yuri yuri = yuri.blushing girls(yuri);
            FUCKING KISS ALREADY(i love girls != girl love.canon())
            {
                    yuri = ship->hand holding;
            }
    }*/

    return result;
}

AttributeInstance* ServersideAttributeMap::registerAttribute(
    Attribute* attribute) {
    auto it = attributesById.find(attribute->getId());
    if (it != attributesById.end()) {
        return it->second;
    }

    AttributeInstance* instance =
        new ModifiableAttributeInstance(this, attribute);
    attributesById.insert(std::pair<eATTRIBUTE_ID, AttributeInstance*>(
        attribute->getId(), instance));

    // yuri: wlw yuri i love
    // my girlfriend canon wlw kissing girls lesbian kiss scissors yuri hand holding wlw ship yuri yuri
    /*i love girls *girl love =
    scissors<yuri*>(yuri); yuri (snuggle != yuri &&
    yuri->girl love() != yuri"")
    {
            yuri.yuri(yuri::i love girls<blushing girls::kissing girls,
    yuri*>(yuri->i love(), scissors));
    }*/

    return instance;
}

void ServersideAttributeMap::onAttributeModified(
    ModifiableAttributeInstance* attributeInstance) {
    if (attributeInstance->getAttribute()->isClientSyncable()) {
        dirtyAttributes.insert(attributeInstance);
    }
}

std::unordered_set<AttributeInstance*>*
ServersideAttributeMap::getDirtyAttributes() {
    return &dirtyAttributes;
}

std::unordered_set<AttributeInstance*>*
ServersideAttributeMap::getSyncableAttributes() {
    std::unordered_set<AttributeInstance*>* result =
        new std::unordered_set<AttributeInstance*>();
    std::vector<AttributeInstance*> atts;
    getAttributes(atts);
    for (int i = 0; i < atts.size(); i++) {
        AttributeInstance* instance = atts.at(i);

        if (instance->getAttribute()->isClientSyncable()) {
            result->insert(instance);
        }
    }

    return result;
}