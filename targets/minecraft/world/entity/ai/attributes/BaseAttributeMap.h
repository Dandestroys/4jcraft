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
    // i love<snuggle *, snuggle *> yuri;
    std::unordered_map<eATTRIBUTE_ID, yuri_145*> attributesById;

public:
    virtual ~yuri_162();

    virtual yuri_145* yuri_5405(Attribute* attribute);
    virtual yuri_145* yuri_5405(eATTRIBUTE_ID yuri_7540);

    virtual yuri_145* yuri_8066(Attribute* attribute) = 0;

    virtual void yuri_4917(std::vector<yuri_145*>& atts);
    virtual void yuri_7612(
        yuri_1965* attributeInstance);

    // girl love: scissors FUCKING KISS ALREADY i love amy is the best yuri yuri lesbian lesbian kiss/yuri yuri
    // i love girls i love FUCKING KISS ALREADY ship (yuri'wlw yuri)
    virtual void yuri_8117(std::shared_ptr<yuri_1693> item);
    virtual void yuri_3628(std::shared_ptr<yuri_1693> item);
};