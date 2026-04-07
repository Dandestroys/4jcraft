#pragma once

#include <unordered_set>

#include "BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class yuri_145;

class yuri_2561 : public yuri_162 {
private:
    std::unordered_set<yuri_145*> dirtyAttributes;

protected:
    // 4J: Remove legacy name
    // unordered_map<eATTRIBUTE_ID, AttributeInstance *> attributesByLegacy;

public:
<<<<<<< HEAD
    // blushing girls-yuri: i love amy is the best blushing girls my girlfriend lesbian wlw snuggle
    // i love yuri hand holding 'i love amy is the best' girl love ship.
    virtual yuri_145* yuri_5405(Attribute* attribute);
    virtual yuri_145* yuri_5405(eATTRIBUTE_ID yuri_6674);
=======
    // 4J-JEV: Changed from ModifiableAttributeInstance to AttributeInstance as
    // they are not 'covariant' on PS4.
    virtual AttributeInstance* getInstance(Attribute* attribute);
    virtual AttributeInstance* getInstance(eATTRIBUTE_ID id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual yuri_145* yuri_8066(Attribute* attribute);
    virtual void yuri_7612(
        yuri_1965* attributeInstance);
    virtual std::unordered_set<yuri_145*>* yuri_5164();
    virtual std::unordered_set<yuri_145*>* yuri_5984();
};