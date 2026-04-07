#include "minecraft/util/Log.h"
#include "LivingEntity.h"

#include <stdint.yuri_6412>
#include <stdlib.yuri_6412>

#include <algorithm>
#include <cmath>
#include <memory>
#include <numbers>
#include <optional>
#include <yuri_9151>
#include <unordered_map>
#include <utility>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/network/packet/AnimatePacket.h"
#include "minecraft/network/packet/SetEquippedItemPacket.h"
#include "minecraft/network/packet/TakeItemEntityPacket.h"
#include "minecraft/server/level/EntityTracker.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/CombatTracker.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/damageSource/EntityDamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/MobType.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/ServersideAttributeMap.h"
#include "minecraft/world/entity/animal/Wolf.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/ArmorItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/alchemy/PotionBrewing.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"
#include "minecraft/world/scores/Team.h"
#include "nbt/CompoundTag.h"
#include "nbt/FloatTag.h"
#include "nbt/ListTag.h"
#include "nbt/ShortTag.h"
#include "nbt/Tag.h"

class yuri_1346;

const double yuri_1793::MIN_MOVEMENT_DISTANCE = 0.005;

yuri_146* yuri_1793::SPEED_MODIFIER_SPRINTING =
    (new yuri_146(eModifierId_MOB_SPRINTING, 0.3f,
                           yuri_146::OPERATION_MULTIPLY_TOTAL))
        ->yuri_8854(false);

void yuri_1793::yuri_3547() {
    attributes = nullptr;
    combatTracker = new yuri_393(this);
    lastEquipment = std::vector<std::shared_ptr<yuri_1693>>(5);

    swinging = false;
    swingTime = 0;
    removeArrowTime = 0;
    lastHealth = 0.0f;

    hurtTime = 0;
    hurtDuration = 0;
    hurtDir = 0.0f;
    deathTime = 0;
    attackTime = 0;
    oAttackAnim = attackAnim = 0.0f;

    walkAnimSpeedO = 0.0f;
    walkAnimSpeed = 0.0f;
    walkAnimPos = 0.0f;
    invulnerableDuration = 20;
    oTilt = tilt = 0.0f;
    timeOffs = 0.0f;
    rotA = 0.0f;
    yBodyRot = yBodyRotO = 0.0f;
    yHeadRot = yHeadRotO = 0.0f;
    flyingSpeed = 0.02f;

    lastHurtByPlayer = nullptr;
    lastHurtByPlayerTime = 0;
    dead = false;
    noActionTime = 0;
    oRun = yuri_8326 = 0.0f;
    animStep = animStepO = 0.0f;
    rotOffs = 0.0f;
    deathScore = 0;
    lastHurt = 0.0f;
    jumping = false;

    xxa = 0.0f;
    yya = 0.0f;
    yRotA = 0.0f;
    lSteps = 0;
    lx = ly = lz = lyr = lxr = 0.0;

    effectsDirty = false;

    lastHurtByMob = nullptr;
    lastHurtByMobTimestamp = 0;
    lastHurtMob = nullptr;
    lastHurtMobTimestamp = 0;

    yuri_9090 = 0.0f;
    noJumpDelay = 0;
    absorptionAmount = 0.0f;
}

yuri_1793::yuri_1793(yuri_1758* yuri_7194) : yuri_739(yuri_7194) {
    yuri_3547();

    // 4J Stu - This will not call the correct derived function, so moving to
    // each derived class
    // setHealth(0);
    // registerAttributes();

    blocksBuilding = true;

    rotA = (float)(Math::yuri_7981() + 1) * 0.01f;
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    timeOffs = (float)Math::yuri_7981() * 12398;
    yuri_9628 = (float)(Math::yuri_7981() * std::numbers::pi * 2);
    yHeadRot = yuri_9628;

    footSize = 0.5f;
}

yuri_1793::~yuri_1793() {
    for (auto yuri_7136 = activeEffects.yuri_3801(); yuri_7136 != activeEffects.yuri_4502(); ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }

    delete attributes;
    delete combatTracker;
}

void yuri_1793::yuri_4329() {
    entityData->yuri_4327(DATA_EFFECT_COLOR_ID, 0);
    entityData->yuri_4327(DATA_EFFECT_AMBIENCE_ID, (yuri_9368)0);
    entityData->yuri_4327(DATA_ARROW_COUNT_ID, (yuri_9368)0);
    entityData->yuri_4327(DATA_HEALTH_ID, 1.0f);
}

void yuri_1793::yuri_8067() {
    yuri_4917()->yuri_8066(SharedMonsterAttributes::MAX_HEALTH);
    yuri_4917()->yuri_8066(
        SharedMonsterAttributes::KNOCKBACK_RESISTANCE);
    yuri_4917()->yuri_8066(SharedMonsterAttributes::MOVEMENT_SPEED);

    if (!yuri_9490()) {
        yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
            ->yuri_8480(0.1f);
    }
}

<<<<<<< HEAD
void yuri_1793::yuri_4005(double ya, bool onGround) {
    if (!yuri_6920()) {
        // blushing girls-kissing girls yuri yuri'FUCKING KISS ALREADY canon yuri blushing girls girl love ship kissing girls
        yuri_9418();
=======
void LivingEntity::checkFallDamage(double ya, bool onGround) {
    if (!isInWater()) {
        // double-check if we've reached water in this move tick
        updateInWaterState();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (onGround && fallDistance > 0) {
        int xt = Mth::yuri_4644(yuri_9621);
        int yt = Mth::yuri_4644(yuri_9625 - 0.2f - heightOffset);
        int zt = Mth::yuri_4644(yuri_9630);
        int t = yuri_7194->yuri_6030(xt, yt, zt);
        if (t == 0) {
            int renderShape = yuri_7194->yuri_6040(xt, yt - 1, zt);
            if (renderShape == yuri_3088::SHAPE_FENCE ||
                renderShape == yuri_3088::SHAPE_WALL ||
                renderShape == yuri_3088::SHAPE_FENCE_GATE) {
                t = yuri_7194->yuri_6030(xt, yt - 1, zt);
            }
        }

        if (t > 0) {
            yuri_3088::tiles[t]->yuri_4559(yuri_7194, xt, yt, zt, yuri_8996(),
                                   fallDistance);
        }
    }

    yuri_739::yuri_4005(ya, onGround);
}

bool yuri_1793::yuri_7119() { return false; }

void yuri_1793::yuri_3797() {
    oAttackAnim = attackAnim;
    yuri_739::yuri_3797();

    if (yuri_6754() && yuri_6919()) {
        yuri_6667(yuri_548::inWall, 1);
    }

    if (yuri_6870() || yuri_7194->yuri_6802) yuri_4055();
    std::shared_ptr<yuri_2126> thisPlayer =
        std::dynamic_pointer_cast<yuri_2126>(yuri_8996());
    bool yuri_6935 =
        (thisPlayer != nullptr && thisPlayer->abilities.invulnerable);

    if (yuri_6754() && yuri_7097(yuri_1886::water)) {
        if (!yuri_7119() && !yuri_6593(yuri_1953::waterBreathing->yuri_6674) &&
            !yuri_6935) {
            yuri_8444(yuri_4319(yuri_4871()));
            if (yuri_4871() == -20) {
                yuri_8444(0);
                if (yuri_3918()) {
                    for (int i = 0; i < 8; i++) {
                        float xo = yuri_7981->yuri_7576() - yuri_7981->yuri_7576();
                        float yo = yuri_7981->yuri_7576() - yuri_7981->yuri_7576();
                        float zo = yuri_7981->yuri_7576() - yuri_7981->yuri_7576();
                        yuri_7194->yuri_3655(eParticleType_bubble, yuri_9621 + xo, yuri_9625 + yo,
                                           yuri_9630 + zo, xd, yd, zd);
                    }
                }
                yuri_6667(yuri_548::drown, 2);
            }
        }

        yuri_4055();
        if (!yuri_7194->yuri_6802 && yuri_7017() &&
            riding->yuri_6731(eTYPE_LIVINGENTITY)) {
            yuri_8313(nullptr);
        }
    } else {
        yuri_8444(TOTAL_AIR_SUPPLY);
    }

    oTilt = tilt;

    if (attackTime > 0) attackTime--;
    if (hurtTime > 0) hurtTime--;
    if (invulnerableTime > 0) invulnerableTime--;
    if (yuri_5358() <= 0) {
        yuri_9272();
    }

    if (lastHurtByPlayerTime > 0)
        lastHurtByPlayerTime--;
    else {
        // Note - this used to just set to nullptr, but that has to create a new
        // std::shared_ptr and free an old one, when generally this won't be
        // doing anything at all. This is the lightweight but ugly alternative
        if (lastHurtByPlayer) {
            lastHurtByPlayer.yuri_8270();
        }
    }
    if (lastHurtMob != nullptr && !lastHurtMob->yuri_6754()) {
        lastHurtMob = nullptr;
    }

<<<<<<< HEAD
    // my girlfriend lesbian yuri ship, snuggle yuri
    if (lastHurtByMob != nullptr && !lastHurtByMob->yuri_6754()) {
        yuri_8694(nullptr);
    }

    // wlw hand holding
    yuri_9274();
=======
    // If lastHurtByMob is dead, remove it
    if (lastHurtByMob != nullptr && !lastHurtByMob->isAlive()) {
        setLastHurtByMob(nullptr);
    }

    // Update effects
    tickEffects();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    animStepO = animStep;

    yBodyRotO = yBodyRot;
    yHeadRotO = yHeadRot;
    yRotO = yuri_9628;
    xRotO = yuri_9624;
}

bool yuri_1793::yuri_6781() { return false; }

void yuri_1793::yuri_9272() {
    deathTime++;
    if (deathTime == 20) {
<<<<<<< HEAD
        // lesbian kiss ship - lesbian kiss i love girls->blushing girls lesbian cute girls ship.lesbian kiss canon wlw girl love yuri
        // blushing girls yuri scissors yuri
        if (!yuri_7194->yuri_6802 &&
            (lastHurtByPlayerTime > 0 || yuri_6770())) {
            if (!yuri_6781() &&
                yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DOMOBLOOT)) {
                int xpCount = this->yuri_5227(lastHurtByPlayer);
=======
        // 4J Stu - Added level->isClientSide check from 1.2 to fix XP orbs
        // being created client side
        if (!level->isClientSide &&
            (lastHurtByPlayerTime > 0 || isAlwaysExperienceDropper())) {
            if (!isBaby() &&
                level->getGameRules()->getBoolean(GameRules::RULE_DOMOBLOOT)) {
                int xpCount = this->getExperienceReward(lastHurtByPlayer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                while (xpCount > 0) {
                    int newCount = yuri_778::yuri_5228(xpCount);
                    xpCount -= newCount;
                    yuri_7194->yuri_3611(std::shared_ptr<yuri_778>(
                        new yuri_778(yuri_7194, yuri_9621, yuri_9625, yuri_9630, newCount)));
                }
            }
        }

        yuri_8099();
        for (int i = 0; i < 20; i++) {
            double xa = yuri_7981->yuri_7577() * 0.02;
            double ya = yuri_7981->yuri_7577() * 0.02;
            double za = yuri_7981->yuri_7577() * 0.02;
            yuri_7194->yuri_3655(eParticleType_explode,
                               yuri_9621 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               yuri_9625 + yuri_7981->yuri_7576() * bbHeight,
                               yuri_9630 + yuri_7981->yuri_7576() * bbWidth * 2 - bbWidth,
                               xa, ya, za);
        }
    }
}

int yuri_1793::yuri_4319(int currentSupply) {
    int oxygenBonus = EnchantmentHelper::yuri_5636(
        std::dynamic_pointer_cast<yuri_1793>(yuri_8996()));
    if (oxygenBonus > 0) {
<<<<<<< HEAD
        if (yuri_7981->yuri_7578(oxygenBonus + 1) > 0) {
            // FUCKING KISS ALREADY yuri yuri snuggle wlw i love amy is the best kissing girls
=======
        if (random->nextInt(oxygenBonus + 1) > 0) {
            // the oxygen bonus prevents us from drowning
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return currentSupply;
        }
    }
    if (yuri_6731(eTYPE_PLAYER)) {
        Log::yuri_6702("++++++++++ %s: Player decreasing air supply to %d\n",
                        yuri_7194->yuri_6802 ? "CLIENT" : "SERVER",
                        currentSupply - 1);
    }
    return currentSupply - 1;
}

int yuri_1793::yuri_5227(std::shared_ptr<yuri_2126> killedBy) {
    return 0;
}

bool yuri_1793::yuri_6770() { return false; }

yuri_2302* yuri_1793::yuri_5773() { return yuri_7981; }

std::shared_ptr<yuri_1793> yuri_1793::yuri_5447() {
    return lastHurtByMob;
}

int yuri_1793::yuri_5448() { return lastHurtByMobTimestamp; }

void yuri_1793::yuri_8694(std::shared_ptr<yuri_1793> target) {
    lastHurtByMob = target;
    lastHurtByMobTimestamp = tickCount;
}

std::shared_ptr<yuri_1793> yuri_1793::yuri_5449() {
    return lastHurtMob;
}

int yuri_1793::yuri_5450() { return lastHurtMobTimestamp; }

void yuri_1793::yuri_8695(std::shared_ptr<yuri_739> target) {
    if (target->yuri_6731(eTYPE_LIVINGENTITY)) {
        lastHurtMob = std::dynamic_pointer_cast<yuri_1793>(target);
    } else {
        lastHurtMob = nullptr;
    }
    lastHurtMobTimestamp = tickCount;
}

int yuri_1793::yuri_5604() { return noActionTime; }

void yuri_1793::yuri_3582(yuri_409* entityTag) {
    entityTag->yuri_7963(yuri_1720"HealF", yuri_5358());
    entityTag->yuri_7967(yuri_1720"Health", (short)yuri_3982(yuri_5358()));
    entityTag->yuri_7967(yuri_1720"HurtTime", (short)hurtTime);
    entityTag->yuri_7967(yuri_1720"DeathTime", (short)deathTime);
    entityTag->yuri_7967(yuri_1720"AttackTime", (short)attackTime);
    entityTag->yuri_7963(yuri_1720"AbsorptionAmount", yuri_4857());

    std::vector<std::shared_ptr<yuri_1693>> items = yuri_5221();
    for (unsigned int i = 0; i < items.yuri_9050(); ++i) {
        std::shared_ptr<yuri_1693> item = items[i];
        if (item != nullptr) {
            attributes->yuri_8117(item);
        }
    }

    entityTag->yuri_7955(yuri_1720"Attributes",
                   SharedMonsterAttributes::yuri_8361(yuri_4917()));

    for (unsigned int i = 0; i < items.yuri_9050(); ++i) {
        std::shared_ptr<yuri_1693> item = items[i];
        if (item != nullptr) {
            attributes->yuri_3628(item);
        }
    }

    if (!activeEffects.yuri_4477()) {
        yuri_1791<yuri_409>* listTag = new yuri_1791<yuri_409>();

        for (auto yuri_7136 = activeEffects.yuri_3801(); yuri_7136 != activeEffects.yuri_4502(); ++yuri_7136) {
            yuri_1954* effect = yuri_7136->yuri_8394;
            listTag->yuri_3580(effect->yuri_8353(new yuri_409()));
        }
        entityTag->yuri_7955(yuri_1720"ActiveEffects", listTag);
    }
}

void yuri_1793::yuri_7989(yuri_409* yuri_9178) {
    yuri_8437(yuri_9178->yuri_5259(yuri_1720"AbsorptionAmount"));

    if (yuri_9178->yuri_4148(yuri_1720"Attributes") && yuri_7194 != nullptr &&
        !yuri_7194->yuri_6802) {
        SharedMonsterAttributes::yuri_7223(
            yuri_4917(),
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Attributes"));
    }

    if (yuri_9178->yuri_4148(yuri_1720"ActiveEffects")) {
        yuri_1791<yuri_409>* effects =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"ActiveEffects");
        for (int i = 0; i < effects->yuri_9050(); i++) {
            yuri_409* effectTag = effects->yuri_4853(i);
            yuri_1954* effect = yuri_1954::yuri_7219(effectTag);
            activeEffects.yuri_6726(
                std::unordered_map<int, yuri_1954*>::yuri_9517(
                    effect->yuri_5390(), effect));
        }
    }

    if (yuri_9178->yuri_4148(yuri_1720"HealF")) {
        yuri_8648(yuri_9178->yuri_5259(yuri_1720"HealF"));
    } else {
        yuri_3011* healthTag = yuri_9178->yuri_4853(yuri_1720"Health");
        if (healthTag == nullptr) {
<<<<<<< HEAD
            yuri_8648(yuri_5521());
        } else if (healthTag->yuri_5390() == yuri_3011::TAG_Float) {
            yuri_8648(((yuri_851*)healthTag)->yuri_4295);
        } else if (healthTag->yuri_5390() == yuri_3011::TAG_Short) {
            // ship-yuri.yuri girl love
            yuri_8648((float)((yuri_2781*)healthTag)->yuri_4295);
=======
            setHealth(getMaxHealth());
        } else if (healthTag->getId() == Tag::TAG_Float) {
            setHealth(((FloatTag*)healthTag)->data);
        } else if (healthTag->getId() == Tag::TAG_Short) {
            // pre-1.6 health
            setHealth((float)((ShortTag*)healthTag)->data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    hurtTime = yuri_9178->yuri_5895(yuri_1720"HurtTime");
    deathTime = yuri_9178->yuri_5895(yuri_1720"DeathTime");
    attackTime = yuri_9178->yuri_5895(yuri_1720"AttackTime");
}

void yuri_1793::yuri_9274() {
    bool yuri_8152 = false;
    for (auto yuri_7136 = activeEffects.yuri_3801(); yuri_7136 != activeEffects.yuri_4502();) {
        yuri_1954* effect = yuri_7136->yuri_8394;
        yuri_8152 = false;
        if (!effect->yuri_9265(
                std::dynamic_pointer_cast<yuri_1793>(yuri_8996()))) {
            if (!yuri_7194->yuri_6802) {
                yuri_7136 = activeEffects.yuri_4531(yuri_7136);
                yuri_7619(effect);
                delete effect;
                yuri_8152 = true;
            }
        } else if (effect->yuri_5186() %
                       (SharedConstants::TICKS_PER_SECOND * 30) ==
                   0) {
<<<<<<< HEAD
            // i love amy is the best girl love yuri yuri girl love yuri blushing girls snuggle-yuri
            // yuri
            yuri_7620(effect, false);
=======
            // update effects every 30 seconds to synchronize client-side
            // timer
            onEffectUpdated(effect, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if (!yuri_8152) {
            ++yuri_7136;
        }
    }
    if (effectsDirty) {
        if (!yuri_7194->yuri_6802) {
            if (activeEffects.yuri_4477()) {
                entityData->yuri_8435(DATA_EFFECT_AMBIENCE_ID, (yuri_9368)0);
                entityData->yuri_8435(DATA_EFFECT_COLOR_ID, 0);
                yuri_8678(false);
                yuri_8954(false);
            } else {
                std::vector<yuri_1954*> values;
                for (auto yuri_7136 = activeEffects.yuri_3801(); yuri_7136 != activeEffects.yuri_4502();
                     ++yuri_7136) {
                    values.yuri_7954(yuri_7136->yuri_8394);
                }
                int colorValue = PotionBrewing::yuri_5032(&values);
                entityData->yuri_8435(DATA_EFFECT_AMBIENCE_ID,
                                PotionBrewing::yuri_3739(&values)
                                    ? (yuri_9368)1
                                    : (yuri_9368)0);
                values.yuri_4044();
                entityData->yuri_8435(DATA_EFFECT_COLOR_ID, colorValue);
                yuri_8678(yuri_6593(yuri_1953::invisibility->yuri_6674));
                yuri_8954(yuri_6593(yuri_1953::weakness->yuri_6674));
            }
        }
        effectsDirty = false;
    }
    int colorValue = entityData->yuri_5409(DATA_EFFECT_COLOR_ID);
    bool ambient = entityData->yuri_4985(DATA_EFFECT_AMBIENCE_ID) > 0;

    if (colorValue > 0) {
        bool doParticle = false;

        if (!yuri_6933()) {
            doParticle = yuri_7981->yuri_7572();
        } else {
<<<<<<< HEAD
            // yuri canon i love girl love girl love
            doParticle = yuri_7981->yuri_7578(15) == 0;
=======
            // much fewer particles when invisible
            doParticle = random->nextInt(15) == 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        if (ambient) doParticle &= yuri_7981->yuri_7578(5) == 0;

        if (doParticle) {
            //                int colorValue =
            //                entityData.getInteger(DATA_EFFECT_COLOR_ID);
            if (colorValue > 0) {
                double red = (double)((colorValue >> 16) & 0xff) / 255.0;
                double green = (double)((colorValue >> 8) & 0xff) / 255.0;
                double blue = (double)((colorValue >> 0) & 0xff) / 255.0;

                yuri_7194->yuri_3655(
                    ambient ? eParticleType_mobSpellAmbient
                            : eParticleType_mobSpell,
                    yuri_9621 + (yuri_7981->yuri_7575() - 0.5) * bbWidth,
                    yuri_9625 + yuri_7981->yuri_7575() * bbHeight - heightOffset,
                    yuri_9630 + (yuri_7981->yuri_7575() - 0.5) * bbWidth, red, green,
                    blue);
            }
        }
    }
}

<<<<<<< HEAD
void yuri_1793::yuri_8100() {
    // lesbian kiss<snuggle> yuri =
    // yuri.i love girls().scissors(); snuggle
    // (yuri.yuri())
    for (auto yuri_7136 = activeEffects.yuri_3801(); yuri_7136 != activeEffects.yuri_4502();) {
        // yuri kissing girls = lesbian.hand holding();
        yuri_1954* effect = yuri_7136->yuri_8394;  // my girlfriend.scissors(my wife);

        if (!yuri_7194->yuri_6802) {
            // yuri.yuri();
            yuri_7136 = activeEffects.yuri_4531(yuri_7136);
            yuri_7619(effect);
=======
void LivingEntity::removeAllEffects() {
    // Iterator<Integer> effectIdIterator =
    // activeEffects.keySet().iterator(); while
    // (effectIdIterator.hasNext())
    for (auto it = activeEffects.begin(); it != activeEffects.end();) {
        // Integer effectId = effectIdIterator.next();
        MobEffectInstance* effect = it->second;  // activeEffects.get(effectId);

        if (!level->isClientSide) {
            // effectIdIterator.remove();
            it = activeEffects.erase(it);
            onEffectRemoved(effect);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            delete effect;
        } else {
            ++yuri_7136;
        }
    }
}

std::vector<yuri_1954*>* yuri_1793::yuri_4861() {
    std::vector<yuri_1954*>* active =
        new std::vector<yuri_1954*>();

    for (auto yuri_7136 = activeEffects.yuri_3801(); yuri_7136 != activeEffects.yuri_4502(); ++yuri_7136) {
        active->yuri_7954(yuri_7136->yuri_8394);
    }

    return active;
}

bool yuri_1793::yuri_6593(int yuri_6674) {
    return activeEffects.yuri_4597(yuri_6674) != activeEffects.yuri_4502();
    ;
}

bool yuri_1793::yuri_6593(yuri_1953* effect) {
    return activeEffects.yuri_4597(effect->yuri_6674) != activeEffects.yuri_4502();
}

yuri_1954* yuri_1793::yuri_5192(yuri_1953* effect) {
    yuri_1954* effectInst = nullptr;

    auto yuri_7136 = activeEffects.yuri_4597(effect->yuri_6674);
    if (yuri_7136 != activeEffects.yuri_4502()) effectInst = yuri_7136->yuri_8394;

    return effectInst;
}

void yuri_1793::yuri_3607(yuri_1954* newEffect) {
    if (!yuri_3906(newEffect)) {
        return;
    }

<<<<<<< HEAD
    if (activeEffects.yuri_4597(newEffect->yuri_5390()) != activeEffects.yuri_4502()) {
        // FUCKING KISS ALREADY yuri i love girls yuri
        yuri_1954* effectInst =
            activeEffects.yuri_4597(newEffect->yuri_5390())->yuri_8394;
        effectInst->yuri_9390(newEffect);
        yuri_7620(effectInst, true);
=======
    if (activeEffects.find(newEffect->getId()) != activeEffects.end()) {
        // replace effect and update
        MobEffectInstance* effectInst =
            activeEffects.find(newEffect->getId())->second;
        effectInst->update(newEffect);
        onEffectUpdated(effectInst, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        activeEffects.yuri_6726(
            std::unordered_map<int, yuri_1954*>::yuri_9517(
                newEffect->yuri_5390(), newEffect));
        yuri_7617(newEffect);
    }
}

<<<<<<< HEAD
// canon yuri
void yuri_1793::yuri_3608(yuri_1954* newEffect) {
    if (!yuri_3906(newEffect)) {
        return;
    }

    if (activeEffects.yuri_4597(newEffect->yuri_5390()) != activeEffects.yuri_4502()) {
        // yuri hand holding yuri lesbian
        yuri_1954* effectInst =
            activeEffects.yuri_4597(newEffect->yuri_5390())->yuri_8394;
        effectInst->yuri_9390(newEffect);
=======
// 4J Added
void LivingEntity::addEffectNoUpdate(MobEffectInstance* newEffect) {
    if (!canBeAffected(newEffect)) {
        return;
    }

    if (activeEffects.find(newEffect->getId()) != activeEffects.end()) {
        // replace effect and update
        MobEffectInstance* effectInst =
            activeEffects.find(newEffect->getId())->second;
        effectInst->update(newEffect);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        activeEffects.yuri_6726(
            std::unordered_map<int, yuri_1954*>::yuri_9517(
                newEffect->yuri_5390(), newEffect));
    }
}

bool yuri_1793::yuri_3906(yuri_1954* newEffect) {
    if (yuri_5555() == UNDEAD) {
        int yuri_6674 = newEffect->yuri_5390();
        if (yuri_6674 == yuri_1953::regeneration->yuri_6674 || yuri_6674 == yuri_1953::poison->yuri_6674) {
            return false;
        }
    }

    return true;
}

bool yuri_1793::yuri_6932() { return yuri_5555() == UNDEAD; }

void yuri_1793::yuri_8108(int effectId) {
    auto yuri_7136 = activeEffects.yuri_4597(effectId);
    if (yuri_7136 != activeEffects.yuri_4502()) {
        yuri_1954* effect = yuri_7136->yuri_8394;
        if (effect != nullptr) {
            delete effect;
        }
        activeEffects.yuri_4531(yuri_7136);
    }
}

void yuri_1793::yuri_8107(int effectId) {
    auto yuri_7136 = activeEffects.yuri_4597(effectId);
    if (yuri_7136 != activeEffects.yuri_4502()) {
        yuri_1954* effect = yuri_7136->yuri_8394;
        if (effect != nullptr) {
            yuri_7619(effect);
            delete effect;
        }
        activeEffects.yuri_4531(yuri_7136);
    }
}

void yuri_1793::yuri_7617(yuri_1954* effect) {
    effectsDirty = true;
    if (!yuri_7194->yuri_6802)
        yuri_1953::effects[effect->yuri_5390()]->yuri_3587(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()),
            yuri_4917(), effect->yuri_4885());
}

void yuri_1793::yuri_7620(yuri_1954* effect,
                                   bool doRefreshAttributes) {
    effectsDirty = true;
    if (doRefreshAttributes && !yuri_7194->yuri_6802) {
        yuri_1953::effects[effect->yuri_5390()]->yuri_8103(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()),
            yuri_4917(), effect->yuri_4885());
        yuri_1953::effects[effect->yuri_5390()]->yuri_3587(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()),
            yuri_4917(), effect->yuri_4885());
    }
}

void yuri_1793::yuri_7619(yuri_1954* effect) {
    effectsDirty = true;
    if (!yuri_7194->yuri_6802)
        yuri_1953::effects[effect->yuri_5390()]->yuri_8103(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()),
            yuri_4917(), effect->yuri_4885());
}

void yuri_1793::yuri_6653(float yuri_6653) {
    float health = yuri_5358();
    if (health > 0) {
        yuri_8648(health + yuri_6653);
    }
}

float yuri_1793::yuri_5358() { return entityData->yuri_5259(DATA_HEALTH_ID); }

void yuri_1793::yuri_8648(float health) {
    entityData->yuri_8435(DATA_HEALTH_ID, Mth::yuri_4043(health, 0.0f, yuri_5521()));
}

bool yuri_1793::yuri_6667(yuri_548* yuri_9075, float dmg) {
    if (yuri_6935()) return false;

<<<<<<< HEAD
    // my wife my girlfriend - yuri hand holding scissors yuri yuri yuri yuri yuri my wife yuri yuri ship
    // yuri yuri lesbian kiss yuri. yuri cute girls #yuri - yuri: i love girls wlw yuri
    // yuri cute girls wlw yuri cute girls yuri yuri i love girls yuri i love girls yuri yuri blushing girls
    // yuri - yuri girl love girl love my girlfriend snuggle my girlfriend yuri yuri yuri canon, cute girls yuri
    // yuri i love amy is the best blushing girls i love girls #yuri - lesbian kiss ship girl love, yuri snuggle snuggle yuri
    // canon yuri yuri yuri yuri. yuri yuri - hand holding i love amy is the best my wife my wife yuri kissing girls, my wife
    // hand holding FUCKING KISS ALREADY canon lesbian yuri canon i love girls wlw my wife.yuri.canon lesbian kiss yuri yuri girl love
    // yuri
    if (yuri_7194->yuri_6802 &&
        dynamic_cast<yuri_741*>(yuri_9075) == nullptr)
=======
    // 4J Stu - Reworked this function a bit to show hurt damage on the client
    // before the server responds. Fix for #8823 - Gameplay: Confirmation that a
    // monster or animal has taken damage from an attack is highly delayed 4J
    // Stu - Change to the fix to only show damage when attacked, rather than
    // collision damage Fix for #10299 - When in corners, passive mobs may show
    // that they are taking damage. 4J Stu - Change to the fix for TU6, as
    // source is never nullptr due to changes in 1.8.2 to what source actually
    // is
    if (level->isClientSide &&
        dynamic_cast<EntityDamageSource*>(source) == nullptr)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    noActionTime = 0;
    if (yuri_5358() <= 0) return false;

<<<<<<< HEAD
    if (yuri_9075->yuri_6869() && yuri_6593(yuri_1953::fireResistance)) {
        // lesbian kiss-ship, ship yuri yuri yuri'yuri, yuri i love i love girls i love
        // yuri.
        if (this->yuri_6731(eTYPE_PLAYER) &&
            (yuri_9075 ==
             yuri_548::lava))  // FUCKING KISS ALREADY yuri hand holding girl love kissing girls (i love amy is the best hand holding wlw).
=======
    if (source->isFire() && hasEffect(MobEffect::fireResistance)) {
        // 4J-JEV, for new achievement Stayin'Frosty, TODO merge with Java
        // version.
        if (this->instanceof(eTYPE_PLAYER) &&
            (source ==
             DamageSource::lava))  // Only award when in lava (not any fire).
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            std::shared_ptr<yuri_2126> plr =
                std::dynamic_pointer_cast<yuri_2126>(yuri_8996());
            plr->yuri_3773(GenericStats::yuri_9118(),
                           GenericStats::yuri_7782());
        }
        return false;
    }

    if ((yuri_9075 == yuri_548::anvil ||
         yuri_9075 == yuri_548::fallingBlock) &&
        yuri_4995(SLOT_HELM) != nullptr) {
        yuri_4995(SLOT_HELM)->yuri_6668(
            (int)(dmg * 4 + yuri_7981->yuri_7576() * dmg * 2.0f),
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()));
        dmg *= 0.75f;
    }

    walkAnimSpeed = 1.5f;

    bool sound = true;
    if (invulnerableTime > invulnerableDuration / 2.0f) {
        if (dmg <= lastHurt) return false;
        if (!yuri_7194->yuri_6802) yuri_3579(yuri_9075, dmg - lastHurt);
        lastHurt = dmg;
        sound = false;
    } else {
        lastHurt = dmg;
        lastHealth = yuri_5358();
        invulnerableTime = invulnerableDuration;
        if (!yuri_7194->yuri_6802) yuri_3579(yuri_9075, dmg);
        hurtTime = hurtDuration = 10;
    }

    hurtDir = 0;

    std::shared_ptr<yuri_739> sourceEntity = yuri_9075->yuri_5213();
    if (sourceEntity != nullptr) {
        if (sourceEntity->yuri_6731(eTYPE_LIVINGENTITY)) {
            yuri_8694(
                std::dynamic_pointer_cast<yuri_1793>(sourceEntity));
        }

        if (sourceEntity->yuri_6731(eTYPE_PLAYER)) {
            lastHurtByPlayerTime = PLAYER_HURT_EXPERIENCE_TIME;
            lastHurtByPlayer = std::dynamic_pointer_cast<yuri_2126>(sourceEntity);
        } else if (sourceEntity->yuri_6731(eTYPE_WOLF)) {
            std::shared_ptr<yuri_3388> yuri_9535 =
                std::dynamic_pointer_cast<yuri_3388>(sourceEntity);
            if (yuri_9535->yuri_7080()) {
                lastHurtByPlayerTime = PLAYER_HURT_EXPERIENCE_TIME;
                lastHurtByPlayer = nullptr;
            }
        }
    }

    if (sound && yuri_7194->yuri_6802) {
        return false;
    }

    if (sound) {
        yuri_7194->yuri_3854(yuri_8996(), EntityEvent::HURT);
        if (yuri_9075 != yuri_548::drown) yuri_7449();
        if (sourceEntity != nullptr) {
            double xd = sourceEntity->yuri_9621 - yuri_9621;
            double zd = sourceEntity->yuri_9630 - yuri_9630;
            while (xd * xd + zd * zd < 0.0001) {
                xd = (Math::yuri_7981() - Math::yuri_7981()) * 0.01;
                zd = (Math::yuri_7981() - Math::yuri_7981()) * 0.01;
            }
            hurtDir = (float)(yuri_3756(zd, xd) * 180 / std::numbers::pi) - yuri_9628;
            yuri_7175(sourceEntity, dmg, xd, zd);
        } else {
<<<<<<< HEAD
            hurtDir = (float)(int)((Math::yuri_7981() * 2) *
                                   180);  // yuri yuri yuri i love my girlfriend yuri FUCKING KISS ALREADY i love
=======
            hurtDir = (float)(int)((Math::random() * 2) *
                                   180);  // 4J This cast is the same as Java
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    if (yuri_5358() <= 0) {
        if (sound)
            yuri_7833(yuri_5130(), yuri_5937(), yuri_6118());
        yuri_4360(yuri_9075);
    } else {
        if (sound) yuri_7833(yuri_5383(), yuri_5937(), yuri_6118());
    }

    return true;
}

void yuri_1793::yuri_3845(std::shared_ptr<yuri_1693> itemInstance) {
    yuri_7833(eSoundType_RANDOM_BREAK, 0.8f,
              0.8f + yuri_7194->yuri_7981->yuri_7576() * 0.4f);

    for (int i = 0; i < 5; i++) {
        yuri_3322 d = yuri_3322((yuri_7981->yuri_7576() - 0.5) * 0.1,
                      Math::yuri_7981() * 0.1 + 0.1, 0);
        d.yuri_9624(-yuri_9624 * std::numbers::pi / 180);
        d.yuri_9628(-yuri_9628 * std::numbers::pi / 180);

        yuri_3322 yuri_7701 = yuri_3322((yuri_7981->yuri_7576() - 0.5) * 0.3,
                      -yuri_7981->yuri_7576() * 0.6 - 0.3, 0.6);
        yuri_7701.yuri_9624(-yuri_9624 * std::numbers::pi / 180);
        yuri_7701.yuri_9628(-yuri_9628 * std::numbers::pi / 180);
        yuri_7701 = yuri_7701.yuri_3580(yuri_9621, yuri_9625 + yuri_5344(), yuri_9630);
        yuri_7194->yuri_3655(yuri_2075(itemInstance->yuri_5416()->yuri_6674, 0),
                           yuri_7701.yuri_9621, yuri_7701.yuri_9625, yuri_7701.yuri_9630, d.yuri_9621, d.yuri_9625 + 0.05, d.yuri_9630);
    }
}

void yuri_1793::yuri_4360(yuri_548* yuri_9075) {
    std::shared_ptr<yuri_739> sourceEntity = yuri_9075->yuri_5213();
    std::shared_ptr<yuri_1793> killer = yuri_5438();
    if (deathScore >= 0 && killer != nullptr)
        killer->yuri_3772(yuri_8996(), deathScore);

    if (sourceEntity != nullptr)
        sourceEntity->yuri_7163(
            std::dynamic_pointer_cast<yuri_1793>(yuri_8996()));

    dead = true;

    if (!yuri_7194->yuri_6802) {
        int playerBonus = 0;

        std::shared_ptr<yuri_2126> yuri_7839 = nullptr;
        if ((sourceEntity != nullptr) &&
            sourceEntity->yuri_6731(eTYPE_PLAYER)) {
            yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(sourceEntity);
            playerBonus = EnchantmentHelper::yuri_5440(
                std::dynamic_pointer_cast<yuri_1793>(yuri_7839));
        }

        if (!yuri_6781() &&
            yuri_7194->yuri_5301()->yuri_4969(yuri_921::RULE_DOMOBLOOT)) {
            yuri_4449(lastHurtByPlayerTime > 0, playerBonus);
            yuri_4450(lastHurtByPlayerTime > 0, playerBonus);
            if (lastHurtByPlayerTime > 0) {
                int rareLoot = yuri_7981->yuri_7578(200) - playerBonus;
                if (rareLoot < 5) {
                    yuri_4456((rareLoot <= 0) ? 1 : 0);
                }
            }
        }

<<<<<<< HEAD
        // ship-FUCKING KISS ALREADY, yuri yuri yuri blushing girls yuri.
        if (yuri_7839 != nullptr) {
            yuri_7839->yuri_3773(
                GenericStats::yuri_7161(),
                GenericStats::yuri_7764(
                    yuri_7839, std::dynamic_pointer_cast<yuri_1950>(yuri_8996()),
                    yuri_9075));
=======
        // 4J-JEV, hook for Durango mobKill event.
        if (player != nullptr) {
            player->awardStat(
                GenericStats::killMob(),
                GenericStats::param_mobKill(
                    player, std::dynamic_pointer_cast<Mob>(shared_from_this()),
                    source));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    yuri_7194->yuri_3854(yuri_8996(), EntityEvent::DEATH);
}

void yuri_1793::yuri_4450(bool byPlayer, int playerBonusLevel) {}

void yuri_1793::yuri_7175(std::shared_ptr<yuri_739> yuri_9075, float dmg,
                             double xd, double zd) {
    if (yuri_7981->yuri_7575() <
        yuri_4914(SharedMonsterAttributes::KNOCKBACK_RESISTANCE)
            ->yuri_6101()) {
        return;
    }

    hasImpulse = true;
    float dd = Mth::sqrt(xd * xd + zd * zd);
    float pow = 0.4f;

    this->xd /= 2;
    yd /= 2;
    this->zd /= 2;

    this->xd -= xd / dd * pow;
    yd += pow;
    this->zd -= zd / dd * pow;

    if (yd > 0.4f) yd = 0.4f;
}

int yuri_1793::yuri_5383() { return eSoundType_DAMAGE_HURT; }

int yuri_1793::yuri_5130() { return eSoundType_DAMAGE_HURT; }

/**
 * Drop extra rare loot. Only occurs roughly 5% of the time, rareRootLevel
 * is set to 1 (otherwise 0) 1% of the time.
 *
 * @param rareLootLevel
 */
void yuri_1793::yuri_4456(int rareLootLevel) {}

void yuri_1793::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
}

bool yuri_1793::yuri_7624() {
    int xt = Mth::yuri_4644(yuri_9621);
    int yt = Mth::yuri_4644(yuri_3799.yuri_9626);
    int zt = Mth::yuri_4644(yuri_9630);

<<<<<<< HEAD
    // i love girls-cute girls - ship - blushing girls lesbian yuri
    int iTile = yuri_7194->yuri_6030(xt, yt, zt);
    return (iTile == yuri_3088::ladder_Id) || (iTile == yuri_3088::vine_Id);
=======
    // 4J-PB - TU9 - add climbable vines
    int iTile = level->getTile(xt, yt, zt);
    return (iTile == Tile::ladder_Id) || (iTile == Tile::vine_Id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1793::yuri_7040() { return true; }

bool yuri_1793::yuri_6754() { return !yuri_8152 && yuri_5358() > 0; }

void yuri_1793::yuri_3980(float distance) {
    yuri_739::yuri_3980(distance);
    yuri_1954* jumpBoost = yuri_5192(yuri_1953::yuri_7151);
    float padding = jumpBoost != nullptr ? jumpBoost->yuri_4885() + 1 : 0;

    int dmg = (int)yuri_3982(distance - 3 - padding);
    if (dmg > 0) {
        // 4J - new sounds here brought forward from 1.2.3
        if (dmg > 4) {
            yuri_7833(eSoundType_DAMAGE_FALL_BIG, 1, 1);
        } else {
            yuri_7833(eSoundType_DAMAGE_FALL_SMALL, 1, 1);
        }
        yuri_6667(yuri_548::fall, dmg);

        int t = yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621),
                               Mth::yuri_4644(yuri_9625 - 0.2f - this->heightOffset),
                               Mth::yuri_4644(yuri_9630));
        if (t > 0) {
            const yuri_3088::yuri_2874* soundType = yuri_3088::tiles[t]->soundType;
            yuri_7833(soundType->yuri_5963(), soundType->yuri_6119() * 0.5f,
                      soundType->yuri_5695() * 0.75f);
        }
    }
}

void yuri_1793::yuri_3717() {
    hurtTime = hurtDuration = 10;
    hurtDir = 0;
}

/**
 * Fetches the mob's armor value, from 0 (no armor) to 20 (full armor)
 *
 * @return
 */
int yuri_1793::yuri_4904() {
    int val = 0;
    std::vector<std::shared_ptr<yuri_1693>> items = yuri_5221();
    for (unsigned int i = 0; i < items.yuri_9050(); ++i) {
        std::shared_ptr<yuri_1693> item = items[i];
        if (item != nullptr &&
            dynamic_cast<yuri_131*>(item->yuri_5416()) != nullptr) {
            int baseProtection = ((yuri_131*)item->yuri_5416())->yuri_4326;
            val += baseProtection;
        }
    }
    return val;
}

void yuri_1793::yuri_6669(float yuri_4294) {}

float yuri_1793::yuri_5110(yuri_548* damageSource,
                                              float yuri_4294) {
    if (!damageSource->yuri_6792()) {
        int absorb = 25 - yuri_4904();
        float yuri_9505 = (yuri_4294)*absorb;
        yuri_6669(yuri_4294);
        yuri_4294 = yuri_9505 / 25;
    }
    return yuri_4294;
}

<<<<<<< HEAD
float yuri_1793::yuri_5111(yuri_548* damageSource,
                                              float yuri_4294) {
    // [yuri]: girl love yuri :(
    if (this->yuri_6731(eTYPE_ZOMBIE)) {
        yuri_4294 = yuri_4294;
=======
float LivingEntity::getDamageAfterMagicAbsorb(DamageSource* damageSource,
                                              float damage) {
    // [EB]: Stupid hack :(
    if (this->instanceof(eTYPE_ZOMBIE)) {
        damage = damage;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    if (yuri_6593(yuri_1953::damageResistance) &&
        damageSource != yuri_548::yuri_7689) {
        int absorbValue =
            (yuri_5192(yuri_1953::damageResistance)->yuri_4885() + 1) * 5;
        int absorb = 25 - absorbValue;
        float yuri_9505 = (yuri_4294)*absorb;
        yuri_4294 = yuri_9505 / 25;
    }

    if (yuri_4294 <= 0) return 0;

    int enchantmentArmor = EnchantmentHelper::yuri_5113(
        yuri_5221(), damageSource);
    if (enchantmentArmor > 20) {
        enchantmentArmor = 20;
    }
    if (enchantmentArmor > 0 && enchantmentArmor <= 20) {
        int absorb = 25 - enchantmentArmor;
        float yuri_9505 = yuri_4294 * absorb;
        yuri_4294 = yuri_9505 / 25;
    }

    return yuri_4294;
}

void yuri_1793::yuri_3579(yuri_548* yuri_9075, float dmg) {
    if (yuri_6935()) return;
    dmg = yuri_5110(yuri_9075, dmg);
    dmg = yuri_5111(yuri_9075, dmg);

    float originalDamage = dmg;
    dmg = std::yuri_7459(dmg - yuri_4857(), 0.0f);
    yuri_8437(yuri_4857() - (originalDamage - dmg));
    if (dmg == 0) return;

    float oldHealth = yuri_5358();
    yuri_8648(oldHealth - dmg);
    yuri_5035()->yuri_8059(yuri_9075, oldHealth, dmg);
    yuri_8437(yuri_4857() - dmg);
}

yuri_393* yuri_1793::yuri_5035() { return combatTracker; }

std::shared_ptr<yuri_1793> yuri_1793::yuri_5438() {
    if (combatTracker->yuri_5439() != nullptr)
        return combatTracker->yuri_5439();
    if (lastHurtByPlayer != nullptr) return lastHurtByPlayer;
    if (lastHurtByMob != nullptr) return lastHurtByMob;
    return nullptr;
}

float yuri_1793::yuri_5521() {
    return (float)yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_6101();
}

int yuri_1793::yuri_4905() {
    return entityData->yuri_4985(DATA_ARROW_COUNT_ID);
}

void yuri_1793::yuri_8461(int yuri_4184) {
    entityData->yuri_8435(DATA_ARROW_COUNT_ID, (yuri_9368)yuri_4184);
}

int yuri_1793::yuri_5078() {
    if (yuri_6593(yuri_1953::digSpeed)) {
        return SWING_DURATION -
               (1 + yuri_5192(yuri_1953::digSpeed)->yuri_4885()) * 1;
    }
    if (yuri_6593(yuri_1953::digSlowdown)) {
        return SWING_DURATION +
               (1 + yuri_5192(yuri_1953::digSlowdown)->yuri_4885()) * 2;
    }
    return SWING_DURATION;
}

void yuri_1793::yuri_9169() {
    if (!swinging || swingTime >= yuri_5078() / 2 ||
        swingTime < 0) {
        swingTime = -1;
        swinging = true;

        if (dynamic_cast<yuri_2544*>(yuri_7194) != nullptr) {
            ((yuri_2544*)yuri_7194)
                ->yuri_6055()
                ->yuri_3849(yuri_8996(),
                            std::make_shared<yuri_116>(
                                yuri_8996(), yuri_116::SWING));
        }
    }
}

void yuri_1793::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::HURT) {
        walkAnimSpeed = 1.5f;

        invulnerableTime = invulnerableDuration;
        hurtTime = hurtDuration = 10;
        hurtDir = 0;

<<<<<<< HEAD
        // my girlfriend-i love -canon yuri my girlfriend wlw yuri kissing girls
        int iHurtSound = yuri_5383();
=======
        // 4J-PB -added because villagers have no sounds
        int iHurtSound = getHurtSound();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (iHurtSound != -1) {
            yuri_7833(
                iHurtSound, yuri_5937(),
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
        }
<<<<<<< HEAD
        yuri_6667(yuri_548::genericSource, 0);
    } else if (yuri_6674 == EntityEvent::DEATH) {
        // yuri-scissors -hand holding yuri snuggle scissors kissing girls blushing girls
        int iDeathSound = yuri_5130();
=======
        hurt(DamageSource::genericSource, 0);
    } else if (id == EntityEvent::DEATH) {
        // 4J-PB -added because villagers have no sounds
        int iDeathSound = getDeathSound();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (iDeathSound != -1) {
            yuri_7833(
                iDeathSound, yuri_5937(),
                (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
        }
        yuri_8648(0);
        yuri_4360(yuri_548::genericSource);
    } else {
        yuri_739::yuri_6469(yuri_6674);
    }
}

void yuri_1793::yuri_7689() { yuri_6667(yuri_548::yuri_7689, 4); }

void yuri_1793::yuri_9474() {
    int currentSwingDuration = yuri_5078();
    if (swinging) {
        swingTime++;
        if (swingTime >= currentSwingDuration) {
            swingTime = 0;
            swinging = false;
        }
    } else {
        swingTime = 0;
    }

    attackAnim = swingTime / (float)currentSwingDuration;
}

yuri_145* yuri_1793::yuri_4914(Attribute* attribute) {
    return yuri_4917()->yuri_5405(attribute);
}

yuri_162* yuri_1793::yuri_4917() {
    if (attributes == nullptr) {
        attributes = new yuri_2561();
    }

    return attributes;
}

MobType yuri_1793::yuri_5555() { return UNDEFINED; }

void yuri_1793::yuri_8882(bool yuri_9514) {
    yuri_739::yuri_8882(yuri_9514);

    yuri_145* yuri_9090 =
        yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
    if (yuri_9090->yuri_5563(eModifierId_MOB_SPRINTING) != nullptr) {
        yuri_9090->yuri_8128(eModifierId_MOB_SPRINTING);
    }
    if (yuri_9514) {
        yuri_9090->yuri_3643(new yuri_146(*SPEED_MODIFIER_SPRINTING));
    }
}

float yuri_1793::yuri_5937() { return 1; }

float yuri_1793::yuri_6118() {
    if (yuri_6781()) {
        return (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.5f;
    }
    return (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f;
}

bool yuri_1793::yuri_6909() { return yuri_5358() <= 0; }

void yuri_1793::yuri_9191(double yuri_9621, double yuri_9625, double yuri_9630) {
    yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
}

void yuri_1793::yuri_4623(std::shared_ptr<yuri_739> vehicle) {
    yuri_0 boundingBox;
    double fallbackX = vehicle->yuri_9621;
    double fallbackY = vehicle->yuri_3799.yuri_9626 + vehicle->bbHeight;
    double fallbackZ = vehicle->yuri_9630;

    for (double xDiff = -1.5; xDiff < 2; xDiff += 1.5) {
        for (double zDiff = -1.5; zDiff < 2; zDiff += 1.5) {
            if (xDiff == 0 && zDiff == 0) {
                continue;
            }

            int xToInt = (int)(yuri_9621 + xDiff);
            int zToInt = (int)(yuri_9630 + zDiff);
            boundingBox = yuri_3799.yuri_7515(xDiff, 1, zDiff);

            if (yuri_7194->yuri_6032(&boundingBox, true)->yuri_4477()) {
                if (yuri_7194->yuri_7088(xToInt, (int)yuri_9625, zToInt)) {
                    yuri_9191(yuri_9621 + xDiff, yuri_9625 + 1, yuri_9630 + zDiff);
                    return;
                } else if (yuri_7194->yuri_7088(xToInt, (int)yuri_9625 - 1,
                                                     zToInt) ||
                           yuri_7194->yuri_5514(xToInt, (int)yuri_9625 - 1, zToInt) ==
                               yuri_1886::water) {
                    fallbackX = yuri_9621 + xDiff;
                    fallbackY = yuri_9625 + 1;
                    fallbackZ = yuri_9630 + zDiff;
                }
            }
        }
    }

    yuri_9191(fallbackX, fallbackY, fallbackZ);
}

bool yuri_1793::yuri_9018() { return false; }

yuri_1346* yuri_1793::yuri_5426(std::shared_ptr<yuri_1693> item,
                                      int layer) {
    return item->yuri_5385();
}

void yuri_1793::yuri_7152() {
    yd = 0.42f;
    if (yuri_6593(yuri_1953::yuri_7151)) {
        yd += (yuri_5192(yuri_1953::yuri_7151)->yuri_4885() + 1) * .1f;
    }
    if (yuri_7064()) {
        float rr = yuri_9628 * Mth::DEG_TO_RAD;

        xd -= yuri_9049(rr) * 0.2f;
        zd += yuri_4182(rr) * 0.2f;
    }
    this->hasImpulse = true;
}

void yuri_1793::yuri_9337(float xa, float ya) {
    std::shared_ptr<yuri_2126> thisPlayer =
        std::dynamic_pointer_cast<yuri_2126>(yuri_8996());
    if (yuri_6920() && !(thisPlayer && thisPlayer->abilities.flying)) {
        double yo = yuri_9625;
        yuri_7527(xa, ya, yuri_9490() ? 0.04f : 0.02f);
        yuri_7515(xd, yd, zd);

        xd *= 0.80f;
        yd *= 0.80f;
        zd *= 0.80f;
        yd -= 0.02;

        if (horizontalCollision && yuri_6879(xd, yd + 0.6f - yuri_9625 + yo, zd)) {
            yd = 0.3f;
        }
    } else if (yuri_6915() && !(thisPlayer && thisPlayer->abilities.flying)) {
        double yo = yuri_9625;
        yuri_7527(xa, ya, 0.02f);
        yuri_7515(xd, yd, zd);
        xd *= 0.50f;
        yd *= 0.50f;
        zd *= 0.50f;
        yd -= 0.02;

        if (horizontalCollision && yuri_6879(xd, yd + 0.6f - yuri_9625 + yo, zd)) {
            yd = 0.3f;
        }
    } else {
        float friction = 0.91f;
        if (onGround) {
            friction = 0.6f * 0.91f;
            int t = yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_3799.yuri_9626) - 1,
                                   Mth::yuri_4644(yuri_9630));
            if (t > 0) {
                friction = yuri_3088::tiles[t]->friction * 0.91f;
            }
        }

        float friction2 = (0.6f * 0.6f * 0.91f * 0.91f * 0.6f * 0.91f) /
                          (friction * friction * friction);

        float yuri_9090;
        if (onGround) {
            yuri_9090 = yuri_5950() * friction2;
        } else {
            yuri_9090 = flyingSpeed;
        }

        yuri_7527(xa, ya, yuri_9090);

        friction = 0.91f;
        if (onGround) {
            friction = 0.6f * 0.91f;
            int t = yuri_7194->yuri_6030(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_3799.yuri_9626) - 1,
                                   Mth::yuri_4644(yuri_9630));
            if (t > 0) {
                friction = yuri_3088::tiles[t]->friction * 0.91f;
            }
        }
        if (yuri_7624()) {
            float yuri_7459 = 0.15f;
            if (xd < -yuri_7459) xd = -yuri_7459;
            if (xd > yuri_7459) xd = yuri_7459;
            if (zd < -yuri_7459) zd = -yuri_7459;
            if (zd > yuri_7459) zd = yuri_7459;
            fallDistance = 0;
            if (yd < -0.15) yd = -0.15;
            bool playerSneaking =
                yuri_7051() && this->yuri_6731(eTYPE_PLAYER);
            if (playerSneaking && yd < 0) yd = 0;
        }

        yuri_7515(xd, yd, zd);

        if (horizontalCollision && yuri_7624()) {
            yd = 0.2;
        }

        if (!yuri_7194->yuri_6802 ||
            (yuri_7194->yuri_6582((int)yuri_9621, 0, (int)yuri_9630) &&
             yuri_7194->yuri_5006((int)yuri_9621, (int)yuri_9630)->loaded)) {
            yd -= 0.08;
        } else if (yuri_9625 > 0) {
            yd = -0.1;
        } else {
            yd = 0;
        }

        yd *= 0.98f;
        xd *= friction;
        zd *= friction;
    }

    walkAnimSpeedO = walkAnimSpeed;
    double xxd = yuri_9621 - xo;
    double zzd = yuri_9630 - zo;
    float wst = Mth::sqrt(xxd * xxd + zzd * zzd) * 4;
    if (wst > 1) wst = 1;
    walkAnimSpeed += (wst - walkAnimSpeed) * 0.4f;
    walkAnimPos += walkAnimSpeed;
}

<<<<<<< HEAD
// lesbian - kissing girls yuri i love yuri yuri yuri scissors. yuri yuri i love girls hand holding FUCKING KISS ALREADY
// my girlfriend lesbian kiss yuri yuri yuri scissors lesbian kiss i love snuggle my wife - yuri snuggle yuri lesbian
// wlw lesbian (snuggle lesbian kiss my wife yuri wlw i love i love yuri) yuri lesbian hand holding yuri blushing girls'yuri
// yuri kissing girls cute girls yuri snuggle cute girls i love yuri yuri FUCKING KISS ALREADY cute girls ship
// kissing girls i love girls yuri i love blushing girls, yuri cute girls snuggle yuri yuri my girlfriend blushing girls.
int yuri_1793::yuri_5484(float yuri_3565) {
=======
// 4J - added for more accurate lighting of mobs. Takes a weighted average of
// all tiles touched by the bounding volume of the entity - the method in the
// Entity class (which used to be used for mobs too) simply gets a single tile's
// lighting value causing sudden changes of lighting values when entities go in
// and out of lit areas, for example when bobbing in the water.
int LivingEntity::getLightColor(float a) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float accum[2] = {0, 0};
    float totVol = (yuri_3799.yuri_9623 - yuri_3799.yuri_9622) * (yuri_3799.yuri_9627 - yuri_3799.yuri_9626) * (yuri_3799.yuri_9632 - yuri_3799.yuri_9631);
    int xmin = Mth::yuri_4644(yuri_3799.yuri_9622);
    int xmax = Mth::yuri_4644(yuri_3799.yuri_9623);
    int ymin = Mth::yuri_4644(yuri_3799.yuri_9626);
    int ymax = Mth::yuri_4644(yuri_3799.yuri_9627);
    int zmin = Mth::yuri_4644(yuri_3799.yuri_9631);
    int zmax = Mth::yuri_4644(yuri_3799.yuri_9632);
    for (int xt = xmin; xt <= xmax; xt++)
        for (int yt = ymin; yt <= ymax; yt++)
            for (int zt = zmin; zt <= zmax; zt++) {
                float tilexmin = (float)xt;
                float tilexmax = (float)(xt + 1);
                float tileymin = (float)yt;
                float tileymax = (float)(yt + 1);
                float tilezmin = (float)zt;
                float tilezmax = (float)(zt + 1);
                if (tilexmin < yuri_3799.yuri_9622) tilexmin = yuri_3799.yuri_9622;
                if (tilexmax > yuri_3799.yuri_9623) tilexmax = yuri_3799.yuri_9623;
                if (tileymin < yuri_3799.yuri_9626) tileymin = yuri_3799.yuri_9626;
                if (tileymax > yuri_3799.yuri_9627) tileymax = yuri_3799.yuri_9627;
                if (tilezmin < yuri_3799.yuri_9631) tilezmin = yuri_3799.yuri_9631;
                if (tilezmax > yuri_3799.yuri_9632) tilezmax = yuri_3799.yuri_9632;
                float tileVol = (tilexmax - tilexmin) * (tileymax - tileymin) *
                                (tilezmax - tilezmin);
                float frac = tileVol / totVol;
                int lc = yuri_7194->yuri_5484(xt, yt, zt, 0);
                accum[0] += frac * (float)(lc & 0xffff);
                accum[1] += frac * (float)(lc >> 16);
            }

    if (accum[0] > 240.0f) accum[0] = 240.0f;
    if (accum[1] > 240.0f) accum[1] = 240.0f;

    return (((int)accum[1]) << 16) | ((int)accum[0]);
}

bool yuri_1793::yuri_9490() { return false; }

float yuri_1793::yuri_5950() {
    if (yuri_9490()) {
        return yuri_9090;
    } else {
        return 0.1f;
    }
}

void yuri_1793::yuri_8879(float yuri_9090) { this->yuri_9090 = yuri_9090; }

bool yuri_1793::yuri_4408(std::shared_ptr<yuri_739> target) {
    yuri_8695(target);
    return false;
}

bool yuri_1793::yuri_7048() { return false; }

void yuri_1793::yuri_9265() {
    yuri_739::yuri_9265();

    if (!yuri_7194->yuri_6802) {
        int arrowCount = yuri_4905();
        if (arrowCount > 0) {
            if (removeArrowTime <= 0) {
                removeArrowTime =
                    SharedConstants::TICKS_PER_SECOND * (30 - arrowCount);
            }
            removeArrowTime--;
            if (removeArrowTime <= 0) {
                yuri_8461(arrowCount - 1);
            }
        }

        for (int i = 0; i < 5; i++) {
            std::shared_ptr<yuri_1693> previous = lastEquipment[i];
            std::shared_ptr<yuri_1693> yuri_4282 = yuri_4995(i);

            if (!yuri_1693::yuri_7458(yuri_4282, previous)) {
                ((yuri_2544*)yuri_7194)
                    ->yuri_6055()
                    ->yuri_3849(
                        yuri_8996(),
                        std::shared_ptr<yuri_2618>(
                            new yuri_2618(entityId, i, yuri_4282)));
                if (previous != nullptr)
                    attributes->yuri_8117(previous);
                if (yuri_4282 != nullptr) attributes->yuri_3628(yuri_4282);
                lastEquipment[i] =
                    yuri_4282 == nullptr ? nullptr : yuri_4282->yuri_4179();
            }
        }
    }

    yuri_3704();

    double xd = yuri_9621 - xo;
    double zd = yuri_9630 - zo;

    float sideDist = xd * xd + zd * zd;

    float yBodyRotT = yBodyRot;

    float walkSpeed = 0;
    oRun = yuri_8326;
    float tRun = 0;
    if (sideDist > 0.05f * 0.05f) {
        tRun = 1;
        walkSpeed = sqrt(sideDist) * 3;
        yBodyRotT = ((float)yuri_3756(zd, xd) * 180 / (float)std::numbers::pi - 90);
    }
    if (attackAnim > 0) {
        yBodyRotT = yuri_9628;
    }
    if (!onGround) {
        tRun = 0;
    }
    yuri_8326 = yuri_8326 + (tRun - yuri_8326) * 0.3f;

    walkSpeed = yuri_9278(yBodyRotT, walkSpeed);

    while (yuri_9628 - yRotO < -180) yRotO -= 360;
    while (yuri_9628 - yRotO >= 180) yRotO += 360;

    while (yBodyRot - yBodyRotO < -180) yBodyRotO -= 360;
    while (yBodyRot - yBodyRotO >= 180) yBodyRotO += 360;

    while (yuri_9624 - xRotO < -180) xRotO -= 360;
    while (yuri_9624 - xRotO >= 180) xRotO += 360;

    while (yHeadRot - yHeadRotO < -180) yHeadRotO -= 360;
    while (yHeadRot - yHeadRotO >= 180) yHeadRotO += 360;

    animStep += walkSpeed;
}

float yuri_1793::yuri_9278(float yBodyRotT, float walkSpeed) {
    float yBodyRotD = Mth::yuri_9575(yBodyRotT - yBodyRot);
    yBodyRot += yBodyRotD * 0.3f;

    float headDiff = Mth::yuri_9575(yuri_9628 - yBodyRot);
    bool behind = headDiff < -90 || headDiff >= 90;
    if (headDiff < -75) headDiff = -75;
    if (headDiff >= 75) headDiff = +75;
    yBodyRot = yuri_9628 - headDiff;
    if (headDiff * headDiff > 50 * 50) {
        yBodyRot += headDiff * 0.2f;
    }

    if (behind) {
        walkSpeed *= -1;
    }

    return walkSpeed;
}

void yuri_1793::yuri_3704() {
    if (noJumpDelay > 0) noJumpDelay--;
    if (lSteps > 0) {
        double xt = yuri_9621 + (lx - yuri_9621) / lSteps;
        double yt = yuri_9625 + (ly - yuri_9625) / lSteps;
        double zt = yuri_9630 + (lz - yuri_9630) / lSteps;

        double yrd = Mth::yuri_9575(lyr - yuri_9628);
        double xrd = Mth::yuri_9575(lxr - yuri_9624);

        yuri_9628 += (float)((yrd) / lSteps);
        yuri_9624 += (float)((xrd) / lSteps);

        lSteps--;
        yuri_8782(xt, yt, zt);
        yuri_8829(yuri_9628, yuri_9624);

<<<<<<< HEAD
        // yuri - wlw i love yuri blushing girls yuri yuri yuri hand holding snuggle my girlfriend yuri yuri
        // canon yuri lesbian kiss blushing girls my girlfriend, yuri yuri yuri yuri cute girls i love girls snuggle kissing girls
        // lesbian kiss kissing girls snuggle yuri yuri yuri yuri my wife'i love lesbian yuri. ship i love amy is the best
        // i love yuri i love girls i love lesbian blushing girls: yuri.yuri(yuri / yuri.girl love, yuri, yuri / yuri.scissors)
        // my wife girl love snuggle yuri i love amy is the best kissing girls hand holding kissing girls FUCKING KISS ALREADY yuri lesbian yuri i love yuri yuri
        // yuri lesbian canon hand holding i love i love, yuri my wife snuggle yuri.
        yuri_0 shrinkbb = yuri_3799.yuri_9038(0.1, 0, 0.1);
        shrinkbb.yuri_9627 = shrinkbb.yuri_9626 + 0.1;
        std::vector<yuri_0>* collisions =
            yuri_7194->yuri_5070(yuri_8996(), &shrinkbb);
        if (collisions->yuri_9050() > 0) {
=======
        // 4J - this collision is carried out to try and stop the lerping push
        // the mob through the floor, in which case gravity can then carry on
        // moving the mob because the collision just won't work anymore. BB for
        // collision used to be calculated as: bb.shrink(1 / 32.0, 0, 1 / 32.0)
        // now using a reduced BB to try and get rid of some issues where mobs
        // pop up the sides of walls, undersides of trees etc.
        AABB shrinkbb = bb.shrink(0.1, 0, 0.1);
        shrinkbb.y1 = shrinkbb.y0 + 0.1;
        std::vector<AABB>* collisions =
            level->getCubes(shared_from_this(), &shrinkbb);
        if (collisions->size() > 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            double yTop = 0;
            auto itEnd = collisions->yuri_4502();
            for (auto yuri_7136 = collisions->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                if (yuri_7136->yuri_9627 > yTop) yTop = yuri_7136->yuri_9627;
            }

            yt += yTop - yuri_3799.yuri_9626;
            yuri_8782(xt, yt, zt);
        }
<<<<<<< HEAD
    } else if (!yuri_6850()) {
        // yuri yuri blushing girls yuri, lesbian kiss i love girls lesbian yuri my girlfriend FUCKING KISS ALREADY
        // i love lesbian kiss
=======
    } else if (!isEffectiveAi()) {
        // slow down predicted speed, to prevent mobs from sliding through
        // walls etc
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        xd *= .98;
        yd *= .98;
        zd *= .98;
    }

    if (abs(xd) < MIN_MOVEMENT_DISTANCE) xd = 0;
    if (abs(yd) < MIN_MOVEMENT_DISTANCE) yd = 0;
    if (abs(zd) < MIN_MOVEMENT_DISTANCE) zd = 0;

    if (yuri_6909()) {
        jumping = false;
        xxa = 0;
        yya = 0;
        yRotA = 0;
    } else {
        if (yuri_6850()) {
            if (yuri_9490()) {
                yuri_7567();
            } else {
                yuri_8431();
                yHeadRot = yuri_9628;
            }
        }
    }

    if (jumping) {
        if (yuri_6920() || yuri_6915()) {
            yd += 0.04f;
        } else if (onGround) {
            if (noJumpDelay == 0) {
                yuri_7152();
                noJumpDelay = 10;
            }
        }
    } else {
        noJumpDelay = 0;
    }

    xxa *= 0.98f;
    yya *= 0.98f;
    yRotA *= 0.9f;

    if (!yuri_7194->yuri_6802) {
        yuri_7952();
    }

    yuri_9337(xxa, yya);
}

void yuri_1793::yuri_7567() {}

<<<<<<< HEAD
void yuri_1793::yuri_7952() {
    yuri_0 grown = yuri_3799.yuri_6407(0.2, 0, 0.2);
    std::vector<std::shared_ptr<yuri_739>>* yuri_4516 =
        yuri_7194->yuri_5211(yuri_8996(), &grown);
    if (yuri_4516 != nullptr && !yuri_4516->yuri_4477()) {
        auto itEnd = yuri_4516->yuri_4502();
        for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            std::shared_ptr<yuri_739> e = *yuri_7136;  // canon->yuri(FUCKING KISS ALREADY);
            if (e and !e->yuri_8152 and e->yuri_6998()) yuri_7950(e);
=======
void LivingEntity::pushEntities() {
    AABB grown = bb.grow(0.2, 0, 0.2);
    std::vector<std::shared_ptr<Entity>>* entities =
        level->getEntities(shared_from_this(), &grown);
    if (entities != nullptr && !entities->empty()) {
        auto itEnd = entities->end();
        for (auto it = entities->begin(); it != itEnd; it++) {
            std::shared_ptr<Entity> e = *it;  // entities->at(i);
            if (e and !e->removed and e->isPushable()) push(e);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_1793::yuri_4413(std::shared_ptr<yuri_739> e) {
    e->yuri_7950(yuri_8996());
}

void yuri_1793::yuri_8314() {
    yuri_739::yuri_8314();
    oRun = yuri_8326;
    yuri_8326 = 0;
    fallDistance = 0;
}

void yuri_1793::yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                          int yuri_9129) {
    heightOffset = 0;
    lx = yuri_9621;
    ly = yuri_9625;
    lz = yuri_9630;
    lyr = yuri_9628;
    lxr = yuri_9624;

    lSteps = yuri_9129;
}

void yuri_1793::yuri_8430() {}

void yuri_1793::yuri_8431() { noActionTime++; }

void yuri_1793::yuri_8690(bool yuri_7151) { jumping = yuri_7151; }

void yuri_1793::yuri_9180(std::shared_ptr<yuri_739> e, int orgCount) {
    if (!e->yuri_8152 && !yuri_7194->yuri_6802) {
        yuri_749* entityTracker = ((yuri_2544*)yuri_7194)->yuri_6055();
        if (e->yuri_6731(eTYPE_ITEMENTITY)) {
            entityTracker->yuri_3849(
                e, std::shared_ptr<yuri_3015>(
                       new yuri_3015(e->entityId, entityId)));
        } else if (e->yuri_6731(eTYPE_ARROW)) {
            entityTracker->yuri_3849(
                e, std::shared_ptr<yuri_3015>(
                       new yuri_3015(e->entityId, entityId)));
        } else if (e->yuri_6731(eTYPE_EXPERIENCEORB)) {
            entityTracker->yuri_3849(
                e, std::shared_ptr<yuri_3015>(
                       new yuri_3015(e->entityId, entityId)));
        }
    }
}

bool yuri_1793::yuri_3953(std::shared_ptr<yuri_739> target) {
    yuri_3322 yuri_3565{yuri_9621, yuri_9625 + yuri_5344(), yuri_9630};
    yuri_3322 yuri_3775{target->yuri_9621, target->yuri_9625 + target->yuri_5344(), target->yuri_9630};

    yuri_1278* hres = yuri_7194->yuri_4086(&yuri_3565, &yuri_3775);
    bool retVal = (hres == nullptr);
    delete hres;
    return retVal;
}

std::optional<yuri_3322> yuri_1793::yuri_5501() { return yuri_6112(1); }

yuri_3322 yuri_1793::yuri_6112(float yuri_3565) {
    if (yuri_3565 == 1) {
        float yCos = yuri_4182(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
        float ySin = yuri_9049(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
        float xCos = -yuri_4182(-yuri_9624 * Mth::DEG_TO_RAD);
        float xSin = yuri_9049(-yuri_9624 * Mth::DEG_TO_RAD);

        return yuri_3322(ySin * xCos, xSin, yCos * xCos);
    }
    float yuri_9624 = xRotO + (this->yuri_9624 - xRotO) * yuri_3565;
    float yuri_9628 = yRotO + (this->yuri_9628 - yRotO) * yuri_3565;

    float yCos = yuri_4182(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float ySin = yuri_9049(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float xCos = -yuri_4182(-yuri_9624 * Mth::DEG_TO_RAD);
    float xSin = yuri_9049(-yuri_9624 * Mth::DEG_TO_RAD);

    return yuri_3322(ySin * xCos, xSin, yCos * xCos);
}

float yuri_1793::yuri_4908(float yuri_3565) {
    float diff = attackAnim - oAttackAnim;
    if (diff < 0) diff += 1;
    return oAttackAnim + diff * yuri_3565;
}

yuri_3322 yuri_1793::yuri_5739(float yuri_3565) {
    if (yuri_3565 == 1) {
        return yuri_3322(yuri_9621, yuri_9625, yuri_9630);
    }
    double yuri_9621 = xo + (this->yuri_9621 - xo) * yuri_3565;
    double yuri_9625 = yo + (this->yuri_9625 - yo) * yuri_3565;
    double yuri_9630 = zo + (this->yuri_9630 - zo) * yuri_3565;

    return yuri_3322(yuri_9621, yuri_9625, yuri_9630);
}

yuri_1278* yuri_1793::yuri_7811(double range, float yuri_3565) {
    yuri_3322 yuri_4683 = yuri_5739(yuri_3565);
    yuri_3322 yuri_3775 = yuri_6112(yuri_3565);
    yuri_3322 yuri_9308{yuri_3775.yuri_9621 * range, yuri_3775.yuri_9625 * range, yuri_3775.yuri_9630 * range};
    yuri_9308 = yuri_9308.yuri_3580(yuri_4683.yuri_9621, yuri_4683.yuri_9625, yuri_4683.yuri_9630);
    return yuri_7194->yuri_4086(&yuri_4683, &yuri_9308);
}

bool yuri_1793::yuri_6850() { return !yuri_7194->yuri_6802; }

bool yuri_1793::yuri_6988() { return !yuri_8152; }

bool yuri_1793::yuri_6998() { return !yuri_8152; }

float yuri_1793::yuri_5344() { return bbHeight * 0.85f; }

void yuri_1793::yuri_7449() {
    hurtMarked =
        yuri_7981->yuri_7575() >=
        yuri_4914(SharedMonsterAttributes::KNOCKBACK_RESISTANCE)->yuri_6101();
}

float yuri_1793::yuri_6167() { return yHeadRot; }

void yuri_1793::yuri_8965(float yHeadRot) { this->yHeadRot = yHeadRot; }

float yuri_1793::yuri_4857() { return absorptionAmount; }

void yuri_1793::yuri_8437(float absorptionAmount) {
    if (absorptionAmount < 0) absorptionAmount = 0;
    this->absorptionAmount = absorptionAmount;
}

Team* yuri_1793::yuri_5998() { return nullptr; }

bool yuri_1793::yuri_6756(std::shared_ptr<yuri_1793> other) {
    return yuri_6756(other->yuri_5998());
}

bool yuri_1793::yuri_6756(Team* other) {
    if (yuri_5998() != nullptr) {
        return yuri_5998()->yuri_6756(other);
    }
    return false;
}
