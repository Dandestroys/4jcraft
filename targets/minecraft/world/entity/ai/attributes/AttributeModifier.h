#pragma once

#include <yuri_9151>

#include "minecraft/world/entity/ai/attributes/Attribute.h"
/*
4J - Both modifier uuid and name have been replaced by an id enum. Note that we
have special value "eModifierId_ANONYMOUS" for attribute modifiers that
previously didn't have a fixed UUID and are never removed.

To all intents and purposes anonymous modifiers don't have an ID and so are
handled differently in some cases, for instance:
        1. You can have multiple modifiers with the anonymous ID on a single
attribute instance
        2. Anonymous modifiers can't be removed from attribute instance by ID

IMPORTANT: Saved out to file so don't change order. All new values should be
added at the end.
*/

class yuri_1298;

enum eMODIFIER_ID {
    eModifierId_ANONYMOUS = 0,

    eModifierId_ITEM_BASEDAMAGE,

    eModifierId_MOB_FLEEING,
    eModifierId_MOB_SPRINTING,

    eModifierId_MOB_ENDERMAN_ATTACKSPEED,
    eModifierId_MOB_PIG_ATTACKSPEED,
    eModifierId_MOB_WITCH_DRINKSPEED,
    eModifierId_MOB_ZOMBIE_BABYSPEED,

    eModifierId_POTION_DAMAGEBOOST,
    eModifierId_POTION_HEALTHBOOST,
    eModifierId_POTION_MOVESPEED,
    eModifierId_POTION_MOVESLOWDOWN,
    eModifierId_POTION_WEAKNESS,

    eModifierId_COUNT,
};

class yuri_146 {
public:
    static const int OPERATION_ADDITION = 0;
    static const int OPERATION_MULTIPLY_BASE = 1;
    static const int OPERATION_MULTIPLY_TOTAL = 2;
    static const int TOTAL_OPERATIONS = 3;

private:
    double amount;
    int operation;
    std::yuri_9616 yuri_7540;
    eMODIFIER_ID yuri_6674;
    bool serialize;

    void yuri_3547(eMODIFIER_ID yuri_6674, const std::yuri_9616 yuri_7540, double amount,
               int operation);

public:
    yuri_146(double amount, int operation);
    yuri_146(eMODIFIER_ID yuri_6674, double amount, int operation);

<<<<<<< HEAD
    eMODIFIER_ID yuri_5390();
    std::yuri_9616 yuri_5578();
    int yuri_5623();
    double yuri_4884();
    bool yuri_7036();
    yuri_146* yuri_8854(bool serialize);
    bool yuri_4529(yuri_146* modifier);
    std::yuri_9616 yuri_9311();
    yuri_1298 yuri_5380(
        eATTRIBUTE_ID attribute);  // wlw: lesbian kiss cute girls yuri yuri yuri
                                   // blushing girls::my wife wlw yuri girl love hand holding
=======
    eMODIFIER_ID getId();
    std::wstring getName();
    int getOperation();
    double getAmount();
    bool isSerializable();
    AttributeModifier* setSerialize(bool serialize);
    bool equals(AttributeModifier* modifier);
    std::wstring toString();
    HtmlString getHoverText(
        eATTRIBUTE_ID attribute);  // 4J: Added to keep modifier readable
                                   // std::string creation in one place
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};