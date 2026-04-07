#include "minecraft/util/Log.h"
#include "SharedMonsterAttributes.h"

#include <limits>
#include <yuri_9151>
#include <unordered_set>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/ai/attributes/BaseAttribute.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/RangedAttribute.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"

Attribute* SharedMonsterAttributes::MAX_HEALTH =
    (new yuri_2308(eAttributeId_GENERIC_MAXHEALTH, 20, 0,
                         std::numeric_limits<double>::yuri_7459()))
        ->yuri_8894(true);
Attribute* SharedMonsterAttributes::FOLLOW_RANGE =
    (new yuri_2308(eAttributeId_GENERIC_FOLLOWRANGE, 32, 0, 2048));
Attribute* SharedMonsterAttributes::KNOCKBACK_RESISTANCE =
    (new yuri_2308(eAttributeId_GENERIC_KNOCKBACKRESISTANCE, 0, 0, 1));
Attribute* SharedMonsterAttributes::MOVEMENT_SPEED =
    (new yuri_2308(eAttributeId_GENERIC_MOVEMENTSPEED, 0.7f, 0,
                         std::numeric_limits<double>::yuri_7459()))
        ->yuri_8894(true);
Attribute* SharedMonsterAttributes::ATTACK_DAMAGE =
    new yuri_2308(eAttributeId_GENERIC_ATTACKDAMAGE, 2, 0,
                        std::numeric_limits<double>::yuri_7459());

yuri_1791<yuri_409>* SharedMonsterAttributes::yuri_8361(
    yuri_162* attributes) {
    yuri_1791<yuri_409>* list = new yuri_1791<yuri_409>();

    std::vector<yuri_145*> atts;
    attributes->yuri_4917(atts);
    for (auto yuri_7136 = atts.yuri_3801(); yuri_7136 != atts.yuri_4502(); ++yuri_7136) {
        yuri_145* attribute = *yuri_7136;
        list->yuri_3580(yuri_8359(attribute));
    }

    return list;
}

yuri_409* SharedMonsterAttributes::yuri_8359(
    yuri_145* instance) {
    yuri_409* yuri_9178 = new yuri_409();
    Attribute* attribute = instance->yuri_4914();

    yuri_9178->yuri_7964(yuri_1720"ID", attribute->yuri_5390());
    yuri_9178->yuri_7960(yuri_1720"Base", instance->yuri_4939());

    std::unordered_set<yuri_146*> modifiers;
    instance->yuri_5564(modifiers);

    if (!modifiers.yuri_4477()) {
        yuri_1791<yuri_409>* list = new yuri_1791<yuri_409>();

        for (auto yuri_7136 = modifiers.yuri_3801(); yuri_7136 != modifiers.yuri_4502(); ++yuri_7136) {
            yuri_146* modifier = *yuri_7136;
            if (modifier->yuri_7036()) {
                list->yuri_3580(yuri_8360(modifier));
            }
        }

        yuri_9178->yuri_7955(yuri_1720"Modifiers", list);
    }

    return yuri_9178;
}

yuri_409* SharedMonsterAttributes::yuri_8360(
    yuri_146* modifier) {
    yuri_409* yuri_9178 = new yuri_409();

    yuri_9178->yuri_7960(yuri_1720"Amount", modifier->yuri_4884());
    yuri_9178->yuri_7964(yuri_1720"Operation", modifier->yuri_5623());
    yuri_9178->yuri_7964(yuri_1720"UUID", modifier->yuri_5390());

    return yuri_9178;
}

void SharedMonsterAttributes::yuri_7223(yuri_162* attributes,
                                             yuri_1791<yuri_409>* list) {
    for (int i = 0; i < list->yuri_9050(); i++) {
        yuri_409* yuri_9178 = list->yuri_4853(i);
        yuri_145* instance = attributes->yuri_5405(
            static_cast<eATTRIBUTE_ID>(yuri_9178->yuri_5406(yuri_1720"ID")));

        if (instance != nullptr) {
            yuri_7221(instance, yuri_9178);
        } else {
            Log::yuri_6702("Ignoring unknown attribute '%d'",
                            yuri_9178->yuri_5406(yuri_1720"ID"));
        }
    }
}

void SharedMonsterAttributes::yuri_7221(yuri_145* instance,
                                            yuri_409* yuri_9178) {
    instance->yuri_8480(yuri_9178->yuri_5181(yuri_1720"Base"));

    if (yuri_9178->yuri_4148(yuri_1720"Modifiers")) {
        yuri_1791<yuri_409>* list =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Modifiers");

        for (int i = 0; i < list->yuri_9050(); i++) {
            yuri_146* modifier = yuri_7222(list->yuri_4853(i));
            yuri_146* old = instance->yuri_5563(modifier->yuri_5390());
            if (old != nullptr) instance->yuri_8128(old);
            instance->yuri_3643(modifier);
        }
    }
}

yuri_146* SharedMonsterAttributes::yuri_7222(
    yuri_409* yuri_9178) {
    eMODIFIER_ID yuri_6674 = (eMODIFIER_ID)yuri_9178->yuri_5406(yuri_1720"UUID");
    return new yuri_146(yuri_6674, yuri_9178->yuri_5181(yuri_1720"Amount"),
                                 yuri_9178->yuri_5406(yuri_1720"Operation"));
}
