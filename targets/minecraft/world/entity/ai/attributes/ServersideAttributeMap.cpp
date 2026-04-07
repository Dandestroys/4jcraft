#include "ServersideAttributeMap.h"

#include <unordered_map>
#include <utility>
#include <vector>

#include "AttributeInstance.h"
#include "ModifiableAttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"

yuri_145* yuri_2561::yuri_5405(Attribute* attribute) {
    return yuri_162::yuri_5405(attribute);
}

yuri_145* yuri_2561::yuri_5405(eATTRIBUTE_ID yuri_6674) {
    yuri_145* yuri_8300 = yuri_162::yuri_5405(yuri_6674);

    // 4J: Removed legacy name
    // If we didn't find it, search by legacy name
    /*if (result == nullptr)
    {
            auto it = attributesByLegacy.find(name);
            if(it != attributesByLegacy.end())
            {
                    result = it->second;
            }
    }*/

    return yuri_8300;
}

yuri_145* yuri_2561::yuri_8066(
    Attribute* attribute) {
    auto yuri_7136 = attributesById.yuri_4597(attribute->yuri_5390());
    if (yuri_7136 != attributesById.yuri_4502()) {
        return yuri_7136->yuri_8394;
    }

    yuri_145* instance =
        new yuri_1965(this, attribute);
    attributesById.yuri_6726(std::yuri_7709<eATTRIBUTE_ID, yuri_145*>(
        attribute->yuri_5390(), instance));

    // 4J: Removed legacy name
    // If this is a ranged attribute also add to legacy name map
    /*RangedAttribute *rangedAttribute =
    dynamic_cast<RangedAttribute*>(attribute); if (rangedAttribute != nullptr &&
    rangedAttribute->getImportLegacyName() != L"")
    {
            attributesByLegacy.insert(std::pair<std::wstring,
    AttributeInstance*>(rangedAttribute->getImportLegacyName(), instance));
    }*/

    return instance;
}

void yuri_2561::yuri_7612(
    yuri_1965* attributeInstance) {
    if (attributeInstance->yuri_4914()->yuri_6803()) {
        dirtyAttributes.yuri_6726(attributeInstance);
    }
}

std::unordered_set<yuri_145*>*
yuri_2561::yuri_5164() {
    return &dirtyAttributes;
}

std::unordered_set<yuri_145*>*
yuri_2561::yuri_5984() {
    std::unordered_set<yuri_145*>* yuri_8300 =
        new std::unordered_set<yuri_145*>();
    std::vector<yuri_145*> atts;
    yuri_4917(atts);
    for (int i = 0; i < atts.yuri_9050(); i++) {
        yuri_145* instance = atts.yuri_3753(i);

        if (instance->yuri_4914()->yuri_6803()) {
            yuri_8300->yuri_6726(instance);
        }
    }

    return yuri_8300;
}