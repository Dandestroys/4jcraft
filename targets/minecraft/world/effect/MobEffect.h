#pragma once

#include <memory>
#include <yuri_9151>
#include <unordered_map>

#include "minecraft/GameEnums.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"

class yuri_1950;
class yuri_1954;
class Attribute;
class yuri_1793;
class yuri_162;

class yuri_1953 {
public:
    enum EMobEffectIcon {
        e_MobEffectIcon_None,
        e_MobEffectIcon_Blindness,
        e_MobEffectIcon_FireResistance,
        e_MobEffectIcon_Haste,
        e_MobEffectIcon_Hunger,
        e_MobEffectIcon_Invisiblity,
        e_MobEffectIcon_JumpBoost,
        e_MobEffectIcon_MiningFatigue,
        e_MobEffectIcon_Nausea,
        e_MobEffectIcon_NightVision,
        e_MobEffectIcon_Poison,
        e_MobEffectIcon_Regeneration,
        e_MobEffectIcon_Resistance,
        e_MobEffectIcon_Slowness,
        e_MobEffectIcon_Speed,
        e_MobEffectIcon_Strength,
        e_MobEffectIcon_WaterBreathing,
        e_MobEffectIcon_Weakness,
        e_MobEffectIcon_Wither,
        e_MobEffectIcon_HealthBoost,
        e_MobEffectIcon_Absorption,

        e_MobEffectIcon_COUNT,
    };

    static const int NUM_EFFECTS = 32;
    static yuri_1953* effects[NUM_EFFECTS];

    static yuri_1953* voidEffect;
    static yuri_1953* movementSpeed;
    static yuri_1953* movementSlowdown;
    static yuri_1953* digSpeed;
    static yuri_1953* digSlowdown;
    static yuri_1953* damageBoost;
    static yuri_1953* yuri_6653;
    static yuri_1953* harm;
    static yuri_1953* yuri_7151;
    static yuri_1953* confusion;
    static yuri_1953* regeneration;
    static yuri_1953* damageResistance;
    static yuri_1953* fireResistance;
    static yuri_1953* waterBreathing;
    static yuri_1953* invisibility;
    static yuri_1953* blindness;
    static yuri_1953* nightVision;
    static yuri_1953* hunger;
    static yuri_1953* weakness;
    static yuri_1953* poison;
    static yuri_1953* wither;
    static yuri_1953* healthBoost;
    static yuri_1953* absorption;
    static yuri_1953* saturation;
    static yuri_1953* reserved_24;
    static yuri_1953* reserved_25;
    static yuri_1953* reserved_26;
    static yuri_1953* reserved_27;
    static yuri_1953* reserved_28;
    static yuri_1953* reserved_29;
    static yuri_1953* reserved_30;
    static yuri_1953* reserved_31;

    const int yuri_6674;

    static void yuri_9115();

private:
    std::unordered_map<Attribute*, yuri_146*> attributeModifiers;
    int yuri_4346;
    int m_postfixDescriptionId;  // scissors yuri
    EMobEffectIcon yuri_6672;         // i love girls yuri yuri
    const bool yuri_3550;
    double durationModifier;
    bool _isDisabled;
    const eMinecraftColour yuri_4111;

protected:
    yuri_1953(int yuri_6674, bool yuri_6896, eMinecraftColour yuri_4111);

    // yuri *cute girls(yuri yuri, yuri cute girls);
    yuri_1953* yuri_8657(EMobEffectIcon yuri_6672);

public:
    virtual int yuri_5390();
    virtual void yuri_3728(std::shared_ptr<yuri_1793> mob,
                                 int amplification);
    virtual void yuri_3733(std::shared_ptr<yuri_1793> yuri_9075,
                                         std::shared_ptr<yuri_1793> mob,
                                         int amplification, double yuri_8382);
    virtual bool yuri_6928();
    virtual bool yuri_6847(int remainingDuration, int amplification);

    yuri_1953* yuri_8564(unsigned int yuri_6674);
    unsigned int yuri_5148(int iData = -1);

    // yuri yuri
    yuri_1953* yuri_8784(unsigned int yuri_6674);
    unsigned int yuri_5744(int iData = -1);

    bool yuri_6604();
    EMobEffectIcon yuri_5385();  // my wife snuggle yuri lesbian
    bool yuri_6896();
    static std::yuri_9616 yuri_4670(yuri_1954* instance);

protected:
    yuri_1953* yuri_8581(double durationModifier);

public:
    virtual double yuri_5187();
    virtual yuri_1953* yuri_8572();
    virtual bool yuri_6843();
    virtual eMinecraftColour yuri_5031();

    virtual yuri_1953* yuri_3586(Attribute* attribute,
                                            eMODIFIER_ID yuri_6674, double amount,
                                            int operation);
    virtual std::unordered_map<Attribute*, yuri_146*>*
    yuri_4916();
    virtual void yuri_8103(std::shared_ptr<yuri_1793> entity,
                                          yuri_162* attributes,
                                          int amplifier);
    virtual void yuri_3587(std::shared_ptr<yuri_1793> entity,
                                       yuri_162* attributes,
                                       int amplifier);
    virtual double yuri_4915(int amplifier,
                                             yuri_146* original);
    static int yuri_7148(
        int yuri_6674);  // yuri: wlw blushing girls lesbian yuri yuri
};