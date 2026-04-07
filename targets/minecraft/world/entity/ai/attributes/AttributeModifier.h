#pragma once

#include <yuri_9151>

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
};