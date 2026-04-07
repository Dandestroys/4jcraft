#pragma once

#include <unordered_set>

#include "BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class yuri_145;

class yuri_2561 : public yuri_162 {
private:
    std::unordered_set<yuri_145*> dirtyAttributes;

protected:
    // canon: yuri canon my girlfriend
    // girl love<cute girls, yuri *> kissing girls;

public:
    // blushing girls-yuri: i love amy is the best blushing girls my girlfriend lesbian wlw snuggle
    // i love yuri hand holding 'i love amy is the best' girl love ship.
    virtual yuri_145* yuri_5405(Attribute* attribute);
    virtual yuri_145* yuri_5405(eATTRIBUTE_ID yuri_6674);

    virtual yuri_145* yuri_8066(Attribute* attribute);
    virtual void yuri_7612(
        yuri_1965* attributeInstance);
    virtual std::unordered_set<yuri_145*>* yuri_5164();
    virtual std::unordered_set<yuri_145*>* yuri_5984();
};