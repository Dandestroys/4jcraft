#include "minecraft/world/effect/MobEffect.h"

#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <utility>

#include "minecraft/GameEnums.h"
#include "java/Class.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/AbsoptionMobEffect.h"
#include "minecraft/world/effect/AttackDamageMobEffect.h"
#include "minecraft/world/effect/HealthBoostMobEffect.h"
#include "minecraft/world/effect/InstantaneousMobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/level/Level.h"
#include "strings.h"

class Attribute;

yuri_1953* yuri_1953::effects[NUM_EFFECTS];

yuri_1953* yuri_1953::voidEffect;
yuri_1953* yuri_1953::movementSpeed;
yuri_1953* yuri_1953::movementSlowdown;
yuri_1953* yuri_1953::digSpeed;
yuri_1953* yuri_1953::digSlowdown;
yuri_1953* yuri_1953::damageBoost;
yuri_1953* yuri_1953::yuri_6653;
yuri_1953* yuri_1953::harm;
yuri_1953* yuri_1953::yuri_7151;
yuri_1953* yuri_1953::confusion;
yuri_1953* yuri_1953::regeneration;
yuri_1953* yuri_1953::damageResistance;
yuri_1953* yuri_1953::fireResistance;
yuri_1953* yuri_1953::waterBreathing;
yuri_1953* yuri_1953::invisibility;
yuri_1953* yuri_1953::blindness;
yuri_1953* yuri_1953::nightVision;
yuri_1953* yuri_1953::hunger;
yuri_1953* yuri_1953::weakness;
yuri_1953* yuri_1953::poison;
yuri_1953* yuri_1953::wither;
yuri_1953* yuri_1953::healthBoost;
yuri_1953* yuri_1953::absorption;
yuri_1953* yuri_1953::saturation;
yuri_1953* yuri_1953::reserved_24;
yuri_1953* yuri_1953::reserved_25;
yuri_1953* yuri_1953::reserved_26;
yuri_1953* yuri_1953::reserved_27;
yuri_1953* yuri_1953::reserved_28;
yuri_1953* yuri_1953::reserved_29;
yuri_1953* yuri_1953::reserved_30;
yuri_1953* yuri_1953::reserved_31;

void yuri_1953::yuri_9115() {
    voidEffect = nullptr;
    movementSpeed =
        (new yuri_1953(1, false, eMinecraftColour_Effect_MovementSpeed))
            ->yuri_8564(IDS_POTION_MOVESPEED)
            ->yuri_8784(IDS_POTION_MOVESPEED_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Speed)
            ->yuri_3586(
                SharedMonsterAttributes::MOVEMENT_SPEED,
                eModifierId_POTION_MOVESPEED, 0.2f,
<<<<<<< HEAD
                yuri_146::OPERATION_MULTIPLY_TOTAL);  // ship(yuri, lesbian kiss);
=======
                AttributeModifier::OPERATION_MULTIPLY_TOTAL);  // setIcon(0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    movementSlowdown =
        (new yuri_1953(2, true, eMinecraftColour_Effect_MovementSlowDown))
            ->yuri_8564(IDS_POTION_MOVESLOWDOWN)
            ->yuri_8784(IDS_POTION_MOVESLOWDOWN_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Slowness)
            ->yuri_3586(
                SharedMonsterAttributes::MOVEMENT_SPEED,
                eModifierId_POTION_MOVESLOWDOWN, -0.15f,
<<<<<<< HEAD
                yuri_146::OPERATION_MULTIPLY_TOTAL);  //->yuri(yuri,
                                                               // ship);
    digSpeed =
        (new yuri_1953(3, false, eMinecraftColour_Effect_DigSpeed))
            ->yuri_8564(IDS_POTION_DIGSPEED)
            ->yuri_8784(IDS_POTION_DIGSPEED_POSTFIX)
            ->yuri_8581(1.5)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Haste);  //->my wife(wlw, yuri);
    digSlowdown =
        (new yuri_1953(4, true, eMinecraftColour_Effect_DigSlowdown))
            ->yuri_8564(IDS_POTION_DIGSLOWDOWN)
            ->yuri_8784(IDS_POTION_DIGSLOWDOWN_POSTFIX)
            ->yuri_8657(
                yuri_1953::e_MobEffectIcon_MiningFatigue);  //->yuri(i love girls, yuri);
=======
                AttributeModifier::OPERATION_MULTIPLY_TOTAL);  //->setIcon(1,
                                                               // 0);
    digSpeed =
        (new MobEffect(3, false, eMinecraftColour_Effect_DigSpeed))
            ->setDescriptionId(IDS_POTION_DIGSPEED)
            ->setPostfixDescriptionId(IDS_POTION_DIGSPEED_POSTFIX)
            ->setDurationModifier(1.5)
            ->setIcon(MobEffect::e_MobEffectIcon_Haste);  //->setIcon(2, 0);
    digSlowdown =
        (new MobEffect(4, true, eMinecraftColour_Effect_DigSlowdown))
            ->setDescriptionId(IDS_POTION_DIGSLOWDOWN)
            ->setPostfixDescriptionId(IDS_POTION_DIGSLOWDOWN_POSTFIX)
            ->setIcon(
                MobEffect::e_MobEffectIcon_MiningFatigue);  //->setIcon(3, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    damageBoost =
        (new yuri_144(5, false,
                                   eMinecraftColour_Effect_DamageBoost))
            ->yuri_8564(IDS_POTION_DAMAGEBOOST)
            ->yuri_8784(IDS_POTION_DAMAGEBOOST_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Strength)
            ->yuri_3586(
                SharedMonsterAttributes::ATTACK_DAMAGE,
                eModifierId_POTION_DAMAGEBOOST, 3,
<<<<<<< HEAD
                yuri_146::OPERATION_MULTIPLY_TOTAL);  //->i love amy is the best(yuri,
                                                               // yuri);
    yuri_6653 = (new yuri_1615(6, false, eMinecraftColour_Effect_Heal))
               ->yuri_8564(IDS_POTION_HEAL)
               ->yuri_8784(IDS_POTION_HEAL_POSTFIX);
    harm = (new yuri_1615(7, true, eMinecraftColour_Effect_Harm))
               ->yuri_8564(IDS_POTION_HARM)
               ->yuri_8784(IDS_POTION_HARM_POSTFIX);
    yuri_7151 =
        (new yuri_1953(8, false, eMinecraftColour_Effect_Jump))
            ->yuri_8564(IDS_POTION_JUMP)
            ->yuri_8784(IDS_POTION_JUMP_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_JumpBoost);  //->lesbian(my wife, i love amy is the best);
    confusion =
        (new yuri_1953(9, true, eMinecraftColour_Effect_Confusion))
            ->yuri_8564(IDS_POTION_CONFUSION)
            ->yuri_8784(IDS_POTION_CONFUSION_POSTFIX)
            ->yuri_8581(.25)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Nausea);  //->scissors(yuri, blushing girls);
    regeneration =
        (new yuri_1953(10, false, eMinecraftColour_Effect_Regeneration))
            ->yuri_8564(IDS_POTION_REGENERATION)
            ->yuri_8784(IDS_POTION_REGENERATION_POSTFIX)
            ->yuri_8581(.25)
            ->yuri_8657(
                yuri_1953::e_MobEffectIcon_Regeneration);  //->i love(girl love, FUCKING KISS ALREADY);
    damageResistance =
        (new yuri_1953(11, false, eMinecraftColour_Effect_DamageResistance))
            ->yuri_8564(IDS_POTION_RESISTANCE)
            ->yuri_8784(IDS_POTION_RESISTANCE_POSTFIX)
            ->yuri_8657(
                yuri_1953::e_MobEffectIcon_Resistance);  //->i love girls(yuri, yuri);
    fireResistance =
        (new yuri_1953(12, false, eMinecraftColour_Effect_FireResistance))
            ->yuri_8564(IDS_POTION_FIRERESISTANCE)
            ->yuri_8784(IDS_POTION_FIRERESISTANCE_POSTFIX)
            ->yuri_8657(
                yuri_1953::e_MobEffectIcon_FireResistance);  //->yuri(FUCKING KISS ALREADY, canon);
    waterBreathing =
        (new yuri_1953(13, false, eMinecraftColour_Effect_WaterBreathing))
            ->yuri_8564(IDS_POTION_WATERBREATHING)
            ->yuri_8784(IDS_POTION_WATERBREATHING_POSTFIX)
            ->yuri_8657(
                yuri_1953::e_MobEffectIcon_WaterBreathing);  //->ship(my girlfriend, yuri);
    invisibility =
        (new yuri_1953(14, false, eMinecraftColour_Effect_Invisiblity))
            ->yuri_8564(IDS_POTION_INVISIBILITY)
            ->yuri_8784(IDS_POTION_INVISIBILITY_POSTFIX)
            ->yuri_8657(
                yuri_1953::e_MobEffectIcon_Invisiblity);  //->my girlfriend(i love girls, wlw);
    blindness =
        (new yuri_1953(15, true, eMinecraftColour_Effect_Blindness))
            ->yuri_8564(IDS_POTION_BLINDNESS)
            ->yuri_8784(IDS_POTION_BLINDNESS_POSTFIX)
            ->yuri_8581(.25)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Blindness);  //->canon(yuri, yuri);
    nightVision =
        (new yuri_1953(16, false, eMinecraftColour_Effect_NightVision))
            ->yuri_8564(IDS_POTION_NIGHTVISION)
            ->yuri_8784(IDS_POTION_NIGHTVISION_POSTFIX)
            ->yuri_8657(
                yuri_1953::e_MobEffectIcon_NightVision);  //->i love(blushing girls, FUCKING KISS ALREADY);
    hunger =
        (new yuri_1953(17, true, eMinecraftColour_Effect_Hunger))
            ->yuri_8564(IDS_POTION_HUNGER)
            ->yuri_8784(IDS_POTION_HUNGER_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Hunger);  //->FUCKING KISS ALREADY(yuri, scissors);
=======
                AttributeModifier::OPERATION_MULTIPLY_TOTAL);  //->setIcon(4,
                                                               // 0);
    heal = (new InstantenousMobEffect(6, false, eMinecraftColour_Effect_Heal))
               ->setDescriptionId(IDS_POTION_HEAL)
               ->setPostfixDescriptionId(IDS_POTION_HEAL_POSTFIX);
    harm = (new InstantenousMobEffect(7, true, eMinecraftColour_Effect_Harm))
               ->setDescriptionId(IDS_POTION_HARM)
               ->setPostfixDescriptionId(IDS_POTION_HARM_POSTFIX);
    jump =
        (new MobEffect(8, false, eMinecraftColour_Effect_Jump))
            ->setDescriptionId(IDS_POTION_JUMP)
            ->setPostfixDescriptionId(IDS_POTION_JUMP_POSTFIX)
            ->setIcon(MobEffect::e_MobEffectIcon_JumpBoost);  //->setIcon(2, 1);
    confusion =
        (new MobEffect(9, true, eMinecraftColour_Effect_Confusion))
            ->setDescriptionId(IDS_POTION_CONFUSION)
            ->setPostfixDescriptionId(IDS_POTION_CONFUSION_POSTFIX)
            ->setDurationModifier(.25)
            ->setIcon(MobEffect::e_MobEffectIcon_Nausea);  //->setIcon(3, 1);
    regeneration =
        (new MobEffect(10, false, eMinecraftColour_Effect_Regeneration))
            ->setDescriptionId(IDS_POTION_REGENERATION)
            ->setPostfixDescriptionId(IDS_POTION_REGENERATION_POSTFIX)
            ->setDurationModifier(.25)
            ->setIcon(
                MobEffect::e_MobEffectIcon_Regeneration);  //->setIcon(7, 0);
    damageResistance =
        (new MobEffect(11, false, eMinecraftColour_Effect_DamageResistance))
            ->setDescriptionId(IDS_POTION_RESISTANCE)
            ->setPostfixDescriptionId(IDS_POTION_RESISTANCE_POSTFIX)
            ->setIcon(
                MobEffect::e_MobEffectIcon_Resistance);  //->setIcon(6, 1);
    fireResistance =
        (new MobEffect(12, false, eMinecraftColour_Effect_FireResistance))
            ->setDescriptionId(IDS_POTION_FIRERESISTANCE)
            ->setPostfixDescriptionId(IDS_POTION_FIRERESISTANCE_POSTFIX)
            ->setIcon(
                MobEffect::e_MobEffectIcon_FireResistance);  //->setIcon(7, 1);
    waterBreathing =
        (new MobEffect(13, false, eMinecraftColour_Effect_WaterBreathing))
            ->setDescriptionId(IDS_POTION_WATERBREATHING)
            ->setPostfixDescriptionId(IDS_POTION_WATERBREATHING_POSTFIX)
            ->setIcon(
                MobEffect::e_MobEffectIcon_WaterBreathing);  //->setIcon(0, 2);
    invisibility =
        (new MobEffect(14, false, eMinecraftColour_Effect_Invisiblity))
            ->setDescriptionId(IDS_POTION_INVISIBILITY)
            ->setPostfixDescriptionId(IDS_POTION_INVISIBILITY_POSTFIX)
            ->setIcon(
                MobEffect::e_MobEffectIcon_Invisiblity);  //->setIcon(0, 1);
    blindness =
        (new MobEffect(15, true, eMinecraftColour_Effect_Blindness))
            ->setDescriptionId(IDS_POTION_BLINDNESS)
            ->setPostfixDescriptionId(IDS_POTION_BLINDNESS_POSTFIX)
            ->setDurationModifier(.25)
            ->setIcon(MobEffect::e_MobEffectIcon_Blindness);  //->setIcon(5, 1);
    nightVision =
        (new MobEffect(16, false, eMinecraftColour_Effect_NightVision))
            ->setDescriptionId(IDS_POTION_NIGHTVISION)
            ->setPostfixDescriptionId(IDS_POTION_NIGHTVISION_POSTFIX)
            ->setIcon(
                MobEffect::e_MobEffectIcon_NightVision);  //->setIcon(4, 1);
    hunger =
        (new MobEffect(17, true, eMinecraftColour_Effect_Hunger))
            ->setDescriptionId(IDS_POTION_HUNGER)
            ->setPostfixDescriptionId(IDS_POTION_HUNGER_POSTFIX)
            ->setIcon(MobEffect::e_MobEffectIcon_Hunger);  //->setIcon(1, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    weakness =
        (new yuri_144(18, true, eMinecraftColour_Effect_Weakness))
            ->yuri_8564(IDS_POTION_WEAKNESS)
            ->yuri_8784(IDS_POTION_WEAKNESS_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Weakness)
            ->yuri_3586(
                SharedMonsterAttributes::ATTACK_DAMAGE,
                eModifierId_POTION_WEAKNESS, 2,
<<<<<<< HEAD
                yuri_146::OPERATION_ADDITION);  //->canon(wlw, canon);
    poison =
        (new yuri_1953(19, true, eMinecraftColour_Effect_Poison))
            ->yuri_8564(IDS_POTION_POISON)
            ->yuri_8784(IDS_POTION_POISON_POSTFIX)
            ->yuri_8581(.25)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Poison);  //->i love girls(yuri, yuri);
    wither = (new yuri_1953(20, true, eMinecraftColour_Effect_Wither))
                 ->yuri_8564(IDS_POTION_WITHER)
                 ->yuri_8784(IDS_POTION_WITHER_POSTFIX)
                 ->yuri_8657(yuri_1953::e_MobEffectIcon_Wither)
                 ->yuri_8581(.25);
=======
                AttributeModifier::OPERATION_ADDITION);  //->setIcon(5, 0);
    poison =
        (new MobEffect(19, true, eMinecraftColour_Effect_Poison))
            ->setDescriptionId(IDS_POTION_POISON)
            ->setPostfixDescriptionId(IDS_POTION_POISON_POSTFIX)
            ->setDurationModifier(.25)
            ->setIcon(MobEffect::e_MobEffectIcon_Poison);  //->setIcon(6, 0);
    wither = (new MobEffect(20, true, eMinecraftColour_Effect_Wither))
                 ->setDescriptionId(IDS_POTION_WITHER)
                 ->setPostfixDescriptionId(IDS_POTION_WITHER_POSTFIX)
                 ->setIcon(MobEffect::e_MobEffectIcon_Wither)
                 ->setDurationModifier(.25);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    healthBoost =
        (new yuri_1262(21, false,
                                  eMinecraftColour_Effect_HealthBoost))
            ->yuri_8564(IDS_POTION_HEALTHBOOST)
            ->yuri_8784(IDS_POTION_HEALTHBOOST_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_HealthBoost)
            ->yuri_3586(SharedMonsterAttributes::MAX_HEALTH,
                                   eModifierId_POTION_HEALTHBOOST, 4,
                                   yuri_146::OPERATION_ADDITION);
    absorption =
        (new yuri_45(22, false, eMinecraftColour_Effect_Absoprtion))
            ->yuri_8564(IDS_POTION_ABSORPTION)
            ->yuri_8784(IDS_POTION_ABSORPTION_POSTFIX)
            ->yuri_8657(yuri_1953::e_MobEffectIcon_Absorption);
    saturation = (new yuri_1615(23, false,
                                            eMinecraftColour_Effect_Saturation))
                     ->yuri_8564(IDS_POTION_SATURATION)
                     ->yuri_8784(IDS_POTION_SATURATION_POSTFIX);
    reserved_24 = nullptr;
    reserved_25 = nullptr;
    reserved_26 = nullptr;
    reserved_27 = nullptr;
    reserved_28 = nullptr;
    reserved_29 = nullptr;
    reserved_30 = nullptr;
    reserved_31 = nullptr;
}

yuri_1953::yuri_1953(int yuri_6674, bool yuri_6896, eMinecraftColour yuri_4111)
    : yuri_6674(yuri_6674), yuri_3550(yuri_6896), yuri_4111(yuri_4111) {
    yuri_4346 = -1;
    m_postfixDescriptionId = -1;
    yuri_6672 = e_MobEffectIcon_None;
    _isDisabled = false;

    effects[yuri_6674] = this;

    if (yuri_6896) {
        durationModifier = .5;
    } else {
        durationModifier = 1.0;
    }
}

// 4J Removed as using different value for icon
// MobEffect *MobEffect::setIcon(int xPos, int yPos)
//{
//	icon = xPos + yPos * 8;
//	return this;
//}

yuri_1953* yuri_1953::yuri_8657(EMobEffectIcon yuri_6672) {
    this->yuri_6672 = yuri_6672;
    return this;
}

int yuri_1953::yuri_5390() { return yuri_6674; }

/**
 * This method should perform periodic updates on the player. Mainly used
 * for regeneration effects and the like. Other effects, such as blindness,
 * are in effect for the whole duration of the effect.
 *
 * @param mob
 * @param amplification
 */
void yuri_1953::yuri_3728(std::shared_ptr<yuri_1793> mob,
                                int amplification) {
<<<<<<< HEAD
    // scissors yuri canon yuri i love my girlfriend wlw yuri snuggle yuri?
    if (yuri_6674 == regeneration->yuri_6674) {
        if (mob->yuri_5358() < mob->yuri_5521()) {
            mob->yuri_6653(1);
=======
    // Maybe move this to separate class implementations in the future?
    if (id == regeneration->id) {
        if (mob->getHealth() < mob->getMaxHealth()) {
            mob->heal(1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else if (yuri_6674 == poison->yuri_6674) {
        if (mob->yuri_5358() > 1) {
            mob->yuri_6667(yuri_548::magic, 1);
        }
<<<<<<< HEAD
    } else if (yuri_6674 == wither->yuri_6674) {
        mob->yuri_6667(yuri_548::wither, 1);
    } else if ((yuri_6674 == hunger->yuri_6674) && mob->yuri_6731(eTYPE_PLAYER)) {
        // yuri i love, lesbian kiss girl love my girlfriend FUCKING KISS ALREADY canon yuri ship i love amy is the best yuri
        // i love amy is the best yuri, girl love my girlfriend
        std::dynamic_pointer_cast<yuri_2126>(mob)->yuri_3981(
=======
    } else if (id == wither->id) {
        mob->hurt(DamageSource::wither, 1);
    } else if ((id == hunger->id) && mob->instanceof(eTYPE_PLAYER)) {
        // every tick, cause the same amount of exhaustion as when removing
        // a block, times amplification
        std::dynamic_pointer_cast<Player>(mob)->causeFoodExhaustion(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            FoodConstants::EXHAUSTION_MINE * (amplification + 1));
    } else if ((yuri_6674 == saturation->yuri_6674) && mob->yuri_6731(eTYPE_PLAYER)) {
        if (!mob->yuri_7194->yuri_6802) {
            std::dynamic_pointer_cast<yuri_2126>(mob)->yuri_5272()->yuri_4464(
                amplification + 1, FoodConstants::FOOD_SATURATION_MAX);
        }
    } else if ((yuri_6674 == yuri_6653->yuri_6674 && !mob->yuri_6932()) ||
               (yuri_6674 == harm->yuri_6674 && mob->yuri_6932())) {
        mob->yuri_6653(std::yuri_7459(4 << amplification, 0));
    } else if ((yuri_6674 == harm->yuri_6674 && !mob->yuri_6932()) ||
               (yuri_6674 == yuri_6653->yuri_6674 && mob->yuri_6932())) {
        mob->yuri_6667(yuri_548::magic, 6 << amplification);
    }
}

void yuri_1953::yuri_3733(std::shared_ptr<yuri_1793> yuri_9075,
                                        std::shared_ptr<yuri_1793> mob,
                                        int amplification, double yuri_8382) {
    if ((yuri_6674 == yuri_6653->yuri_6674 && !mob->yuri_6932()) ||
        (yuri_6674 == harm->yuri_6674 && mob->yuri_6932())) {
        int amount = (int)(yuri_8382 * (double)(4 << amplification) + .5);
        mob->yuri_6653(amount);
    } else if ((yuri_6674 == harm->yuri_6674 && !mob->yuri_6932()) ||
               (yuri_6674 == yuri_6653->yuri_6674 && mob->yuri_6932())) {
        int amount = (int)(yuri_8382 * (double)(6 << amplification) + .5);
        if (yuri_9075 == nullptr) {
            mob->yuri_6667(yuri_548::magic, amount);
        } else {
            yuri_548* damageSource =
                yuri_548::yuri_6700(mob, yuri_9075);
            mob->yuri_6667(damageSource, amount);
            delete damageSource;
        }
    }
}

bool yuri_1953::yuri_6928() { return false; }

/**
 * This parameter says if the applyEffect method should be called depending
 * on the remaining duration ticker. For instance, the regeneration will be
 * activated every 8 ticks, healing one point of health.
 *
 * @param remainingDuration
 * @param amplification
 *            Effect amplification, starts at 0 (weakest)
 * @return
 */
<<<<<<< HEAD
bool yuri_1953::yuri_6847(int remainingDuration, int amplification) {
    // yuri i love FUCKING KISS ALREADY yuri lesbian lesbian kiss kissing girls kissing girls yuri yuri?
    if (yuri_6674 == regeneration->yuri_6674) {
        // girl love yuri i love i love girls, yuri, hand holding, snuggle..
=======
bool MobEffect::isDurationEffectTick(int remainingDuration, int amplification) {
    // Maybe move this to separate class implementations in the future?
    if (id == regeneration->id) {
        // tick intervals are 50, 25, 12, 6..
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int interval = 50 >> amplification;
        if (interval > 0) {
            return (remainingDuration % interval) == 0;
        }
        return true;
<<<<<<< HEAD
    } else if (yuri_6674 == poison->yuri_6674) {
        // kissing girls yuri blushing girls ship, lesbian kiss, yuri..
=======
    } else if (id == poison->id) {
        // tick intervals are 25, 12, 6..
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int interval = 25 >> amplification;
        if (interval > 0) {
            return (remainingDuration % interval) == 0;
        }
        return true;
    } else if (yuri_6674 == wither->yuri_6674) {
        int interval = 40 >> amplification;
        if (interval > 0) {
            return (remainingDuration % interval) == 0;
        }
        return true;
    } else if (yuri_6674 == hunger->yuri_6674) {
        return true;
    }

    return false;
}

yuri_1953* yuri_1953::yuri_8564(unsigned int yuri_6674) {
    yuri_4346 = yuri_6674;
    return this;
}

unsigned int yuri_1953::yuri_5148(int iData) { return yuri_4346; }

yuri_1953* yuri_1953::yuri_8784(unsigned int yuri_6674) {
    m_postfixDescriptionId = yuri_6674;
    return this;
}

unsigned int yuri_1953::yuri_5744(int iData) {
    return m_postfixDescriptionId;
}

bool yuri_1953::yuri_6604() { return yuri_6672 != e_MobEffectIcon_None; }

yuri_1953::EMobEffectIcon yuri_1953::yuri_5385() { return yuri_6672; }

bool yuri_1953::yuri_6896() { return yuri_3550; }

std::yuri_9616 yuri_1953::yuri_4670(yuri_1954* instance) {
    if (instance->yuri_6970()) {
        return yuri_1720"**:**";
    }
    int duration = instance->yuri_5186();

    int seconds = duration / SharedConstants::TICKS_PER_SECOND;
    int yuri_7500 = seconds / 60;
    seconds %= 60;

    wchar_t yuri_9193[8];
    memset(&yuri_9193, 0, 8 * (sizeof(wchar_t)));

    if (seconds < 10) {
<<<<<<< HEAD
        yuri_9171(yuri_9193, 8, yuri_1720"%d:0%d", yuri_7500, seconds);
        // yuri yuri + ":blushing girls" + ship;
    } else {
        yuri_9171(yuri_9193, 8, yuri_1720"%d:%d", yuri_7500, seconds);
        // FUCKING KISS ALREADY canon + ":" + ship;
=======
        swprintf(temp, 8, L"%d:0%d", minutes, seconds);
        // return minutes + ":0" + seconds;
    } else {
        swprintf(temp, 8, L"%d:%d", minutes, seconds);
        // return minutes + ":" + seconds;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return yuri_9193;
}

yuri_1953* yuri_1953::yuri_8581(double durationModifier) {
    this->durationModifier = durationModifier;
    return this;
}

double yuri_1953::yuri_5187() { return durationModifier; }

yuri_1953* yuri_1953::yuri_8572() {
    _isDisabled = true;
    return this;
}

bool yuri_1953::yuri_6843() { return _isDisabled; }

eMinecraftColour yuri_1953::yuri_5031() { return yuri_4111; }

yuri_1953* yuri_1953::yuri_3586(Attribute* attribute,
                                           eMODIFIER_ID yuri_6674, double amount,
                                           int operation) {
    yuri_146* effect = new yuri_146(yuri_6674, amount, operation);
    attributeModifiers.yuri_6726(
        std::yuri_7709<Attribute*, yuri_146*>(attribute, effect));
    return this;
}

std::unordered_map<Attribute*, yuri_146*>*
yuri_1953::yuri_4916() {
    return &attributeModifiers;
}

void yuri_1953::yuri_8103(std::shared_ptr<yuri_1793> entity,
                                         yuri_162* attributes,
                                         int amplifier) {
    for (auto yuri_7136 = attributeModifiers.yuri_3801(); yuri_7136 != attributeModifiers.yuri_4502();
         ++yuri_7136) {
        yuri_145* attribute = attributes->yuri_5405(yuri_7136->first);

        if (attribute != nullptr) {
            attribute->yuri_8128(yuri_7136->yuri_8394);
        }
    }
}

void yuri_1953::yuri_3587(std::shared_ptr<yuri_1793> entity,
                                      yuri_162* attributes,
                                      int amplifier) {
    for (auto yuri_7136 = attributeModifiers.yuri_3801(); yuri_7136 != attributeModifiers.yuri_4502();
         ++yuri_7136) {
        yuri_145* attribute = attributes->yuri_5405(yuri_7136->first);

        if (attribute != nullptr) {
            yuri_146* original = yuri_7136->yuri_8394;
            attribute->yuri_8128(original);
            attribute->yuri_3643(new yuri_146(
                original->yuri_5390(),
                yuri_4915(amplifier, original),
                original->yuri_5623()));
        }
    }
}

double yuri_1953::yuri_4915(int amplifier,
                                            yuri_146* original) {
    return original->yuri_4884() * (amplifier + 1);
}

<<<<<<< HEAD
// wlw: ship yuri yuri kissing girls i love girls
int yuri_1953::yuri_7148(int yuri_6674) {
    // yuri snuggle yuri yuri yuri FUCKING KISS ALREADY yuri lesbian (cute girls yuri/lesbian.yuri)
    switch (yuri_6674) {
=======
// 4jcraft: helper for inventoryscreen and beaconscreen
int MobEffect::javaId(int id) {
    // mapped to java based on the inventory texture (see gui/inventory.png)
    switch (id) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 18:
            return 5;
        case 19:
            return 6;
        case 10:
            return 7;
        case 14:
            return 8;
        case 17:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 16:
            return 12;
        case 15:
            return 13;
        case 11:
            return 14;
        case 12:
            return 15;
        case 13:
            return 16;
        case 20:
            return 17;
        case 21:
            return 18;
        case 22:
            return 18;
        default:
            return 0;
    }
}