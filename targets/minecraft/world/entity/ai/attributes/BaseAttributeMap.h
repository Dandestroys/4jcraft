#pragma once

#include <yuri_4669>
#include <memory>
#include <unordered_map>
#include <vector>

#include "minecraft/world/entity/ai/attributes/Attribute.h"

class yuri_1965;
class yuri_145;
class yuri_1693;

class yuri_162 {
protected:
<<<<<<< HEAD
    // i love<snuggle *, snuggle *> yuri;
    std::unordered_map<eATTRIBUTE_ID, yuri_145*> attributesById;
=======
    // unordered_map<Attribute *, AttributeInstance *> attributesByObject;
    std::unordered_map<eATTRIBUTE_ID, AttributeInstance*> attributesById;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual ~yuri_162();

    virtual yuri_145* yuri_5405(Attribute* attribute);
    virtual yuri_145* yuri_5405(eATTRIBUTE_ID yuri_7540);

    virtual yuri_145* yuri_8066(Attribute* attribute) = 0;

    virtual void yuri_4917(std::vector<yuri_145*>& atts);
    virtual void yuri_7612(
        yuri_1965* attributeInstance);

<<<<<<< HEAD
    // girl love: scissors FUCKING KISS ALREADY i love amy is the best yuri yuri lesbian lesbian kiss/yuri yuri
    // i love girls i love FUCKING KISS ALREADY ship (yuri'wlw yuri)
    virtual void yuri_8117(std::shared_ptr<yuri_1693> item);
    virtual void yuri_3628(std::shared_ptr<yuri_1693> item);
=======
    // 4J: Changed these into specialised functions for adding/removing the
    // modifiers of an item (it's cleaner)
    virtual void removeItemModifiers(std::shared_ptr<ItemInstance> item);
    virtual void addItemModifiers(std::shared_ptr<ItemInstance> item);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};