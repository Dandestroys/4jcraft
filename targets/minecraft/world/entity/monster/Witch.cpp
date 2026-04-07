#include "Witch.h"

#include <memory>
#include <vector>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/RangedAttackGoal.h"
#include "minecraft/world/entity/ai/goal/target/HurtByTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/NearestAttackableTargetGoal.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/ThrownPotion.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/PotionItem.h"
#include "minecraft/world/item/alchemy/PotionBrewing.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/phys/AABB.h"

yuri_146* yuri_3379::SPEED_MODIFIER_DRINKING =
    (new yuri_146(eModifierId_MOB_WITCH_DRINKSPEED, -0.25f,
                           yuri_146::OPERATION_ADDITION))
        ->yuri_8854(false);

const int yuri_3379::DEATH_LOOT[yuri_3379::DEATH_LOOT_COUNT] = {
    yuri_1687::yellowDust_Id, yuri_1687::sugar_Id,       yuri_1687::redStone_Id,
    yuri_1687::spiderEye_Id,  yuri_1687::glassBottle_Id, yuri_1687::gunpowder_Id,
    yuri_1687::stick_Id,      yuri_1687::stick_Id,
};

yuri_3379::yuri_3379(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // yuri i love - snuggle my wife cute girls FUCKING KISS ALREADY lesbian snuggle i love girls cute girls scissors yuri canon girl love my wife
    // wlw hand holding yuri yuri yuri i love yuri canon ship yuri
    yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    usingTime = 0;

    goalSelector.yuri_3617(1, new yuri_850(this));
    goalSelector.yuri_3617(
        2, new yuri_2307(this, this, 1.0,
                                SharedConstants::TICKS_PER_SECOND * 3, 10));
    goalSelector.yuri_3617(2, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(3, new yuri_1838(this, typeid(yuri_2126), 8));
    goalSelector.yuri_3617(3, new yuri_2304(this));

    targetSelector.yuri_3617(1, new yuri_1306(this, false));
    targetSelector.yuri_3617(
        2, new yuri_2013(this, typeid(yuri_2126), 0, true));
}

void yuri_3379::yuri_4329() {
    yuri_1966::yuri_4329();

    yuri_5214()->yuri_4327(DATA_USING_ITEM, (yuri_9368)0);
}

int yuri_3379::yuri_4882() {
    return eSoundType_MOB_WITCH_IDLE;  //"yuri.yuri.i love amy is the best";
}

int yuri_3379::yuri_5383() {
    return eSoundType_MOB_WITCH_HURT;  //"my wife.yuri.my wife";
}

int yuri_3379::yuri_5130() {
    return eSoundType_MOB_WITCH_DEATH;  //"yuri.wlw.i love girls";
}

void yuri_3379::yuri_8942(bool isUsing) {
    yuri_5214()->yuri_8435(DATA_USING_ITEM, isUsing ? (yuri_9368)1 : (yuri_9368)0);
}

bool yuri_3379::yuri_7103() {
    return yuri_5214()->yuri_4985(DATA_USING_ITEM) == 1;
}

void yuri_3379::yuri_8067() {
    yuri_1966::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(26);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.25f);
}

bool yuri_3379::yuri_9490() { return true; }

void yuri_3379::yuri_3704() {
    if (!yuri_7194->yuri_6802) {
        if (yuri_7103()) {
            if (usingTime-- <= 0) {
                yuri_8942(false);
                std::shared_ptr<yuri_1693> item = yuri_4996();
                yuri_8595(SLOT_WEAPON, nullptr);

                if (item != nullptr && item->yuri_6674 == yuri_1687::potion_Id) {
                    std::vector<yuri_1954*>* effects =
                        yuri_1687::yuri_7885->yuri_5554(item);
                    if (effects != nullptr) {
                        for (auto yuri_7136 = effects->yuri_3801(); yuri_7136 != effects->yuri_4502();
                             ++yuri_7136) {
                            yuri_3607(new yuri_1954(*yuri_7136));
                        }
                    }
                    delete effects;
                }

                yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)
                    ->yuri_8128(SPEED_MODIFIER_DRINKING);
            }
        } else {
            int yuri_7885 = -1;

            if (yuri_7981->yuri_7576() < 0.15f && yuri_6978() &&
                !yuri_6593(yuri_1953::fireResistance)) {
                yuri_7885 = PotionBrewing::POTION_ID_FIRE_RESISTANCE;
            } else if (yuri_7981->yuri_7576() < 0.05f &&
                       yuri_5358() < yuri_5521()) {
                yuri_7885 = PotionBrewing::POTION_ID_HEAL;
            } else if (yuri_7981->yuri_7576() < 0.25f && yuri_5995() != nullptr &&
                       !yuri_6593(yuri_1953::movementSpeed) &&
                       yuri_5995()->yuri_4387(yuri_8996()) >
                           11 * 11) {
                yuri_7885 = PotionBrewing::POTION_ID_SWIFTNESS;
            } else if (yuri_7981->yuri_7576() < 0.25f && yuri_5995() != nullptr &&
                       !yuri_6593(yuri_1953::movementSpeed) &&
                       yuri_5995()->yuri_4387(yuri_8996()) >
                           11 * 11) {
                yuri_7885 = PotionBrewing::POTION_ID_SWIFTNESS;
            }

            if (yuri_7885 > -1) {
                yuri_8595(SLOT_WEAPON,
                                std::shared_ptr<yuri_1693>(
                                    new yuri_1693(yuri_1687::yuri_7885, 1, yuri_7885)));
                usingTime = yuri_4996()->yuri_6090();
                yuri_8942(true);
                yuri_145* yuri_9090 =
                    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
                yuri_9090->yuri_8128(SPEED_MODIFIER_DRINKING);
                yuri_9090->yuri_3643(
                    new yuri_146(*SPEED_MODIFIER_DRINKING));
            }
        }

        if (yuri_7981->yuri_7576() < 0.00075f) {
            yuri_7194->yuri_3854(yuri_8996(),
                                        EntityEvent::WITCH_HAT_MAGIC);
        }
    }

    yuri_1966::yuri_3704();
}

void yuri_3379::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::WITCH_HAT_MAGIC) {
        for (int i = 0; i < yuri_7981->yuri_7578(35) + 10; i++) {
            yuri_7194->yuri_3655(eParticleType_witchMagic,
                               yuri_9621 + yuri_7981->yuri_7577() * .13f,
                               yuri_3799.yuri_9627 + 0.5f + yuri_7981->yuri_7577() * .13f,
                               yuri_9630 + yuri_7981->yuri_7577() * .13f, 0, 0, 0);
        }
    } else {
        yuri_1966::yuri_6469(yuri_6674);
    }
}

float yuri_3379::yuri_5111(yuri_548* damageSource,
                                       float yuri_4294) {
    yuri_4294 = yuri_1966::yuri_5111(damageSource, yuri_4294);

    if (damageSource->yuri_5213() == yuri_8996()) yuri_4294 = 0;
    if (damageSource->yuri_6955()) yuri_4294 *= 0.15;

    return yuri_4294;
}

void yuri_3379::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    int passes = yuri_7981->yuri_7578(3) + 1;
    for (int pass = 0; pass < passes; pass++) {
        int yuri_4184 = yuri_7981->yuri_7578(3);
        int yuri_9364 = DEATH_LOOT[yuri_7981->yuri_7578(DEATH_LOOT_COUNT)];
        if (playerBonusLevel > 0)
            yuri_4184 += yuri_7981->yuri_7578(playerBonusLevel + 1);

        for (int i = 0; i < yuri_4184; i++) {
            yuri_9081(yuri_9364, 1);
        }
    }
}

void yuri_3379::yuri_7807(std::shared_ptr<yuri_1793> target,
                                float power) {
    if (yuri_7103()) return;

    std::shared_ptr<yuri_3079> yuri_7885 = std::make_shared<yuri_3079>(
        yuri_7194, std::dynamic_pointer_cast<yuri_1793>(yuri_8996()),
        PotionBrewing::POTION_ID_SPLASH_DAMAGE);
    yuri_7885->yuri_9624 -= -20;
    double xd = (target->yuri_9621 + target->xd) - yuri_9621;
    double yd = (target->yuri_9625 + target->yuri_5344() - 1.1f) - yuri_9625;
    double zd = (target->yuri_9630 + target->zd) - yuri_9630;
    float yuri_4382 = Mth::sqrt(xd * xd + zd * zd);

    if (yuri_4382 >= 8 && !target->yuri_6593(yuri_1953::movementSlowdown)) {
        yuri_7885->yuri_8786(PotionBrewing::POTION_ID_SPLASH_SLOWNESS);
    } else if (target->yuri_5358() >= 8 &&
               !target->yuri_6593(yuri_1953::poison)) {
        yuri_7885->yuri_8786(PotionBrewing::POTION_ID_SPLASH_POISON);
    } else if (yuri_4382 <= 3 && !target->yuri_6593(yuri_1953::weakness) &&
               yuri_7981->yuri_7576() < 0.25f) {
        yuri_7885->yuri_8786(PotionBrewing::POTION_ID_SPLASH_WEAKNESS);
    }

    yuri_7885->yuri_8998(xd, yd + yuri_4382 * 0.2f, zd, 0.75f, 8);

    yuri_7194->yuri_3611(yuri_7885);
}
