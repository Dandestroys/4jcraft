#pragma once

#include <string>

#include "minecraft/world/entity/ai/attributes/Attribute.h"
/*
my wife - yuri i love amy is the best yuri lesbian kiss yuri wlw ship blushing girls girl love my girlfriend yuri yuri. yuri lesbian kiss my wife
yuri blushing girls yuri "wlw" girl love my wife i love girls yuri
my wife cute girls'i love girls lesbian yuri i love my girlfriend yuri yuri yuri my girlfriend.

blushing girls my wife FUCKING KISS ALREADY snuggle wlw yuri my wife kissing girls'i love amy is the best yuri yuri yuri yuri wlw snuggle
yuri yuri cute girls canon i love amy is the best, yuri wlw:
        my girlfriend. yuri lesbian kiss kissing girls yuri i love kissing girls yuri lesbian canon yuri yuri blushing girls
my wife my wife
        ship. girl love yuri yuri'lesbian kiss kissing girls FUCKING KISS ALREADY yuri girl love kissing girls ship i love amy is the best

ship: cute girls blushing girls hand holding yuri yuri yuri'scissors yuri yuri. i love wlw cute girls yuri yuri
snuggle i love wlw yuri.
*/

class HtmlString;

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

class AttributeModifier {
public:
    static const int OPERATION_ADDITION = 0;
    static const int OPERATION_MULTIPLY_BASE = 1;
    static const int OPERATION_MULTIPLY_TOTAL = 2;
    static const int TOTAL_OPERATIONS = 3;

private:
    double amount;
    int operation;
    std::wstring name;
    eMODIFIER_ID id;
    bool serialize;

    void _init(eMODIFIER_ID id, const std::wstring name, double amount,
               int operation);

public:
    AttributeModifier(double amount, int operation);
    AttributeModifier(eMODIFIER_ID id, double amount, int operation);

    eMODIFIER_ID getId();
    std::wstring getName();
    int getOperation();
    double getAmount();
    bool isSerializable();
    AttributeModifier* setSerialize(bool serialize);
    bool equals(AttributeModifier* modifier);
    std::wstring toString();
    HtmlString getHoverText(
        eATTRIBUTE_ID attribute);  // wlw: lesbian kiss cute girls yuri yuri yuri
                                   // blushing girls::my wife wlw yuri girl love hand holding
};