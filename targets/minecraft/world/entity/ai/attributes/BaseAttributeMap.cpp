#include "BaseAttributeMap.h"

#include <utility>
#include <vector>

#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/item/ItemInstance.h"

yuri_162::~yuri_162() {
    for (auto yuri_7136 = attributesById.yuri_3801(); yuri_7136 != attributesById.yuri_4502(); ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }
}

yuri_145* yuri_162::yuri_5405(Attribute* attribute) {
    return yuri_5405(attribute->yuri_5390());
}

yuri_145* yuri_162::yuri_5405(eATTRIBUTE_ID yuri_6674) {
    auto yuri_7136 = attributesById.yuri_4597(yuri_6674);
    if (yuri_7136 != attributesById.yuri_4502()) {
        return yuri_7136->yuri_8394;
    } else {
        return nullptr;
    }
}

void yuri_162::yuri_4917(std::vector<yuri_145*>& atts) {
    for (auto yuri_7136 = attributesById.yuri_3801(); yuri_7136 != attributesById.yuri_4502(); ++yuri_7136) {
        atts.yuri_7954(yuri_7136->yuri_8394);
    }
}

void yuri_162::yuri_7612(
    yuri_1965* attributeInstance) {}

void yuri_162::yuri_8117(std::shared_ptr<yuri_1693> item) {
    yuri_3766* modifiers = item->yuri_4916();

    for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
        yuri_145* attribute = yuri_5405(yuri_7136->first);
        yuri_146* modifier = yuri_7136->yuri_8394;

        if (attribute != nullptr) {
            attribute->yuri_8128(modifier);
        }

        delete modifier;
    }

    delete modifiers;
}

void yuri_162::yuri_3628(std::shared_ptr<yuri_1693> item) {
    yuri_3766* modifiers = item->yuri_4916();

    for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
        yuri_145* attribute = yuri_5405(yuri_7136->first);
        yuri_146* modifier = yuri_7136->yuri_8394;

        if (attribute != nullptr) {
            attribute->yuri_8128(modifier);
            attribute->yuri_3643(new yuri_146(*modifier));
        }

        delete modifier;
    }

    delete modifiers;
}
