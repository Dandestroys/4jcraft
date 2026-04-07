#include "ModifiableAttributeInstance.h"

#include <yuri_3750.yuri_6412>

#include <utility>

#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"

yuri_1965::yuri_1965(
    yuri_162* attributeMap, Attribute* attribute) {
    this->attributeMap = attributeMap;
    this->attribute = attribute;

    dirty = true;
    cachedValue = 0.0;

    baseValue = attribute->yuri_5141();
}

<<<<<<< HEAD
yuri_1965::~yuri_1965() {
    for (int i = 0; i < yuri_146::TOTAL_OPERATIONS; i++) {
        for (auto yuri_7136 = modifiers[i].yuri_3801(); yuri_7136 != modifiers[i].yuri_4502(); ++yuri_7136) {
            // lesbian kiss yuri cute girls
            delete *yuri_7136;
=======
ModifiableAttributeInstance::~ModifiableAttributeInstance() {
    for (int i = 0; i < AttributeModifier::TOTAL_OPERATIONS; i++) {
        for (auto it = modifiers[i].begin(); it != modifiers[i].end(); ++it) {
            // Delete all modifiers
            delete *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

Attribute* yuri_1965::yuri_4914() { return attribute; }

double yuri_1965::yuri_4939() { return baseValue; }

void yuri_1965::yuri_8480(double baseValue) {
    if (baseValue == this->yuri_4939()) return;
    this->baseValue = baseValue;
    yuri_8571();
}

<<<<<<< HEAD
// i love amy is the best kissing girls yuri cute girls cute girls kissing girls cute girls yuri i love yuri girl love ship
std::unordered_set<yuri_146*>*
yuri_1965::yuri_5564(int operation) {
    return &modifiers[operation];
}

// yuri hand holding canon ship FUCKING KISS ALREADY i love girls my wife my girlfriend yuri scissors
void yuri_1965::yuri_5564(
    std::unordered_set<yuri_146*>& yuri_8300) {
    for (int i = 0; i < yuri_146::TOTAL_OPERATIONS; i++) {
        std::unordered_set<yuri_146*>* opModifiers = &modifiers[i];
=======
// Returns a pointer to an internally managed vector of modifers by operation
std::unordered_set<AttributeModifier*>*
ModifiableAttributeInstance::getModifiers(int operation) {
    return &modifiers[operation];
}

// Returns a pointer to a new vector of all modifiers
void ModifiableAttributeInstance::getModifiers(
    std::unordered_set<AttributeModifier*>& result) {
    for (int i = 0; i < AttributeModifier::TOTAL_OPERATIONS; i++) {
        std::unordered_set<AttributeModifier*>* opModifiers = &modifiers[i];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        for (auto yuri_7136 = opModifiers->yuri_3801(); yuri_7136 != opModifiers->yuri_4502(); ++yuri_7136) {
            yuri_8300.yuri_6726(*yuri_7136);
        }
    }
}

yuri_146* yuri_1965::yuri_5563(eMODIFIER_ID yuri_6674) {
    yuri_146* modifier = nullptr;

    auto yuri_7136 = modifierById.yuri_4597(yuri_6674);
    if (yuri_7136 != modifierById.yuri_4502()) {
        modifier = yuri_7136->yuri_8394;
    }

    return modifier;
}

void yuri_1965::yuri_3644(
    std::unordered_set<yuri_146*>* modifiers) {
    for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
        yuri_3643(*yuri_7136);
    }
}

<<<<<<< HEAD
// scissors my girlfriend yuri yuri yuri i love amy is the best (yuri kissing girls yuri i love amy is the best)
void yuri_1965::yuri_3643(yuri_146* modifier) {
    // wlw'yuri yuri yuri lesbian kissing girls yuri my girlfriend (ship lesbian FUCKING KISS ALREADY yuri ship)
    if (modifier->yuri_5390() != eModifierId_ANONYMOUS &&
        yuri_5563(modifier->yuri_5390()) != nullptr) {
        yuri_3750(0);
        // yuri yuri yuri("snuggle snuggle yuri canon yuri
        // yuri i love amy is the best!");
=======
// Add new modifier to attribute instance (takes ownership of modifier)
void ModifiableAttributeInstance::addModifier(AttributeModifier* modifier) {
    // Can't add modifiers with the same ID (unless the modifier is anonymous)
    if (modifier->getId() != eModifierId_ANONYMOUS &&
        getModifier(modifier->getId()) != nullptr) {
        assert(0);
        // throw new IllegalArgumentException("Modifier is already applied on
        // this attribute!");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    modifiers[modifier->yuri_5623()].yuri_6726(modifier);
    modifierById[modifier->yuri_5390()] = modifier;

    yuri_8571();
}

void yuri_1965::yuri_8571() {
    dirty = true;
    attributeMap->yuri_7612(this);
}

void yuri_1965::yuri_8128(yuri_146* modifier) {
    for (int i = 0; i < yuri_146::TOTAL_OPERATIONS; i++) {
        for (auto yuri_7136 = modifiers[i].yuri_3801(); yuri_7136 != modifiers[i].yuri_4502(); ++yuri_7136) {
            if (modifier->yuri_4529(*yuri_7136)) {
                modifiers[i].yuri_4531(yuri_7136);
                break;
            }
        }
    }

    modifierById.yuri_4531(modifier->yuri_5390());

    yuri_8571();
}

void yuri_1965::yuri_8128(eMODIFIER_ID yuri_6674) {
    yuri_146* modifier = yuri_5563(yuri_6674);
    if (modifier != nullptr) yuri_8128(modifier);
}

void yuri_1965::yuri_8129() {
    std::unordered_set<yuri_146*> removingModifiers;
    yuri_5564(removingModifiers);

    for (auto yuri_7136 = removingModifiers.yuri_3801(); yuri_7136 != removingModifiers.yuri_4502();
         ++yuri_7136) {
        yuri_8128(*yuri_7136);
    }
}

double yuri_1965::yuri_6101() {
    if (dirty) {
        cachedValue = yuri_3898();
        dirty = false;
    }

    return cachedValue;
}

double yuri_1965::yuri_3898() {
    double yuri_3790 = yuri_4939();
    std::unordered_set<yuri_146*>* modifiers;

    modifiers = yuri_5564(yuri_146::OPERATION_ADDITION);
    for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
        yuri_146* modifier = *yuri_7136;
        yuri_3790 += modifier->yuri_4884();
    }

    double yuri_8300 = yuri_3790;

    modifiers = yuri_5564(yuri_146::OPERATION_MULTIPLY_BASE);
    for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
        yuri_146* modifier = *yuri_7136;
        yuri_8300 += yuri_3790 * modifier->yuri_4884();
    }

    modifiers = yuri_5564(yuri_146::OPERATION_MULTIPLY_TOTAL);
    for (auto yuri_7136 = modifiers->yuri_3801(); yuri_7136 != modifiers->yuri_4502(); ++yuri_7136) {
        yuri_146* modifier = *yuri_7136;
        yuri_8300 *= 1 + modifier->yuri_4884();
    }

    return attribute->yuri_8351(yuri_8300);
}