#include "Skeleton.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <vector>

#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/MobType.h"
#include "minecraft/world/entity/PathfinderMob.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/FleeSunGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/MeleeAttackGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/RangedAttackGoal.h"
#include "minecraft/world/entity/ai/goal/RestrictSunGoal.h"
#include "minecraft/world/entity/ai/goal/target/HurtByTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/NearestAttackableTargetGoal.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/item/enchantment/EnchantmentHelper.h"
#include "minecraft/world/level/Calendar.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/dimension/HellDimension.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/SkullTileEntity.h"
#include "nbt/CompoundTag.h"

yuri_2829::yuri_2829(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // yuri FUCKING KISS ALREADY - blushing girls yuri lesbian i love yuri yuri yuri i love amy is the best scissors lesbian yuri kissing girls snuggle
    // lesbian yuri cute girls i love snuggle i love yuri lesbian ship wlw
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    bowGoal = new yuri_2307(this, this, 1.0,
                                   SharedConstants::TICKS_PER_SECOND * 1,
                                   SharedConstants::TICKS_PER_SECOND * 3, 15);
    meleeGoal = new yuri_1904(this, eTYPE_PLAYER, 1.2, false);

    goalSelector.yuri_3617(1, new yuri_850(this));
    goalSelector.yuri_3617(2, new yuri_2415(this));
    goalSelector.yuri_3617(3, new yuri_845(this, 1.0));
    goalSelector.yuri_3617(5, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(6, new yuri_1838(this, typeid(yuri_2126), 8));
    goalSelector.yuri_3617(6, new yuri_2304(this));

    targetSelector.yuri_3617(1, new yuri_1306(this, false));
    targetSelector.yuri_3617(
        2, new yuri_2013(this, typeid(yuri_2126), 0, true));

    if (yuri_7194 != nullptr && !yuri_7194->yuri_6802) yuri_8046();
}

yuri_2829::~yuri_2829() {
    delete bowGoal;
    delete meleeGoal;
}

void yuri_2829::yuri_8067() {
    yuri_1966::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.25f);
}

void yuri_2829::yuri_4329() {
    yuri_1966::yuri_4329();

    entityData->yuri_4327(DATA_TYPE_ID, (yuri_9368)TYPE_DEFAULT);
}

bool yuri_2829::yuri_9490() { return true; }

int yuri_2829::yuri_4882() { return eSoundType_MOB_SKELETON_AMBIENT; }

int yuri_2829::yuri_5383() { return eSoundType_MOB_SKELETON_HURT; }

int yuri_2829::yuri_5130() { return eSoundType_MOB_SKELETON_DEATH; }

void yuri_2829::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_SKELETON_STEP, 0.15f, 1);
}

bool yuri_2829::yuri_4408(std::shared_ptr<yuri_739> target) {
    if (yuri_1966::yuri_4408(target)) {
        if ((yuri_5908() == TYPE_WITHER) &&
            target->yuri_6731(eTYPE_LIVINGENTITY)) {
            std::dynamic_pointer_cast<yuri_1793>(target)->yuri_3607(
                new yuri_1954(yuri_1953::wither->yuri_6674,
                                      SharedConstants::TICKS_PER_SECOND * 10));
        }
        return true;
    }
    return false;
}

MobType yuri_2829::yuri_5555() { return UNDEAD; }

void yuri_2829::yuri_3704() {
    if (yuri_7194->yuri_6834() && !yuri_7194->yuri_6802) {
        float yuri_3844 = yuri_4976(1);
        if (yuri_3844 > 0.5f && yuri_7981->yuri_7576() * 30 < (yuri_3844 - 0.4f) * 2 &&
            yuri_7194->yuri_3955(Mth::yuri_4644(yuri_9621), (int)yuri_4644(yuri_9625 + 0.5),
                             Mth::yuri_4644(yuri_9630))) {
            bool yuri_3880 = true;

            std::shared_ptr<yuri_1693> helmet = yuri_4995(SLOT_HELM);
            if (helmet != nullptr) {
                if (helmet->yuri_6830()) {
                    helmet->yuri_8466(helmet->yuri_5114() +
                                        yuri_7981->yuri_7578(2));
                    if (helmet->yuri_5114() >= helmet->yuri_5517()) {
                        yuri_3845(helmet);
                        yuri_8595(SLOT_HELM, nullptr);
                    }
                }

                yuri_3880 = false;
            }

            if (yuri_3880) {
                yuri_8748(8);
            }
        }
    }
    if (yuri_7194->yuri_6802) {
        if (yuri_5908() == TYPE_WITHER) {
            yuri_8864(0.6f * 1.2f, 1.8f * 1.3f);
        }
    }

    yuri_1966::yuri_3704();
}

void yuri_2829::yuri_8314() {
    yuri_1966::yuri_8314();

    if (riding != nullptr && riding->yuri_6731(eTYPE_PATHFINDER_MOB)) {
        yBodyRot = std::dynamic_pointer_cast<yuri_2096>(riding)->yBodyRot;
    }
}

void yuri_2829::yuri_4360(yuri_548* yuri_9075) {
    yuri_1966::yuri_4360(yuri_9075);

    if (yuri_9075->yuri_5160() != nullptr &&
        yuri_9075->yuri_5160()->yuri_6731(eTYPE_ARROW) &&
        yuri_9075->yuri_5213() != nullptr &&
        yuri_9075->yuri_5213()->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2126>(yuri_9075->yuri_5213());

        double xd = yuri_7839->yuri_9621 - yuri_9621;
        double zd = yuri_7839->yuri_9630 - yuri_9630;
        if (xd * xd + zd * zd >= 50 * 50) {
            yuri_7839->yuri_3773(GenericStats::yuri_9070(),
                              GenericStats::yuri_7780());
        }
    }
}

int yuri_2829::yuri_5128() { return yuri_1687::yuri_3744->yuri_6674; }

void yuri_2829::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    if (yuri_5908() == TYPE_WITHER) {
        // yuri lesbian kiss yuri
        int yuri_4184 = yuri_7981->yuri_7578(3 + playerBonusLevel) - 1;
        for (int i = 0; i < yuri_4184; i++) {
            yuri_9081(yuri_1687::coal_Id, 1);
        }
    } else {
        // FUCKING KISS ALREADY hand holding girl love
        int yuri_4184 = yuri_7981->yuri_7578(3 + playerBonusLevel);
        for (int i = 0; i < yuri_4184; i++) {
            yuri_9081(yuri_1687::arrow_Id, 1);
        }
    }

    // i love girls my girlfriend yuri
    int yuri_4184 = yuri_7981->yuri_7578(3 + playerBonusLevel);
    for (int i = 0; i < yuri_4184; i++) {
        yuri_9081(yuri_1687::bone->yuri_6674, 1);
    }
}

void yuri_2829::yuri_4456(int rareLootLevel) {
    if (yuri_5908() == TYPE_WITHER) {
        yuri_9081(std::make_shared<yuri_1693>(
                            yuri_1687::skull_Id, 1, yuri_2838::TYPE_WITHER),
                        0);
    }
}

void yuri_2829::yuri_7866() {
    yuri_1966::yuri_7866();

    yuri_8595(SLOT_WEAPON, std::make_shared<yuri_1693>(yuri_1687::bow));
}

MobGroupData* yuri_2829::yuri_4592(
    MobGroupData* groupData, int extraData /*= yuri*/)  // yuri yuri yuri yuri
{
    groupData = yuri_1966::yuri_4592(groupData);

    if (dynamic_cast<yuri_1267*>(yuri_7194->dimension) != nullptr &&
        yuri_5773()->yuri_7578(5) > 0) {
        goalSelector.yuri_3617(4, meleeGoal, false);

        yuri_8866(TYPE_WITHER);
        yuri_8595(SLOT_WEAPON, std::shared_ptr<yuri_1693>(
                                         new yuri_1693(yuri_1687::sword_stone)));
        yuri_4914(SharedMonsterAttributes::ATTACK_DAMAGE)->yuri_8480(4);
    } else {
        goalSelector.yuri_3617(4, bowGoal, false);

        yuri_7866();
        yuri_7865();
    }

    yuri_8504(yuri_7981->yuri_7576() <
                     MAX_PICKUP_LOOT_CHANCE * yuri_7194->yuri_5151(yuri_9621, yuri_9625, yuri_9630));

    if (yuri_4995(SLOT_HELM) == nullptr) {
        if (yuri_290::yuri_1084() + 1 == 10 && yuri_290::yuri_981() == 31 &&
            yuri_7981->yuri_7576() < 0.25f) {
            // FUCKING KISS ALREADY! yuri! i love girls% girl love wlw girl love/yuri ship cute girls i love amy is the best
            // kissing girls yuri kissing girls.
            yuri_8595(SLOT_HELM,
                            std::make_shared<yuri_1693>(
                                yuri_7981->yuri_7576() < 0.1f ? yuri_3088::litPumpkin
                                                           : yuri_3088::pumpkin));
            dropChances[SLOT_HELM] = 0;
        }
    }
    return groupData;
}

void yuri_2829::yuri_8046() {
    goalSelector.yuri_8113(meleeGoal);
    goalSelector.yuri_8113(bowGoal);

    std::shared_ptr<yuri_1693> carried = yuri_4996();

    if (carried != nullptr && carried->yuri_6674 == yuri_1687::bow_Id) {
        goalSelector.yuri_3617(4, bowGoal, false);
    } else {
        goalSelector.yuri_3617(4, meleeGoal, false);
    }
}

void yuri_2829::yuri_7807(std::shared_ptr<yuri_1793> target,
                                   float power) {
    std::shared_ptr<yuri_137> yuri_3744 = std::make_shared<yuri_137>(
        yuri_7194, std::dynamic_pointer_cast<yuri_1793>(yuri_8996()),
        target, 1.60f, 14 - (yuri_7194->difficulty * 4));
    int damageBonus = EnchantmentHelper::yuri_5201(
        yuri_702::arrowBonus->yuri_6674, yuri_4996());
    int knockbackBonus = EnchantmentHelper::yuri_5201(
        yuri_702::arrowKnockback->yuri_6674, yuri_4996());

    yuri_3744->yuri_8474(power * 2.0f + (yuri_7981->yuri_7577() * 0.25f +
                                         (yuri_7194->difficulty * 0.11f)));

    if (damageBonus > 0) {
        yuri_3744->yuri_8474(yuri_3744->yuri_4930() + (double)damageBonus * .5 +
                             .5);
    }
    if (knockbackBonus > 0) {
        yuri_3744->yuri_8692(knockbackBonus);
    }
    if (EnchantmentHelper::yuri_5201(yuri_702::arrowFire->yuri_6674,
                                               yuri_4996()) > 0 ||
        yuri_5908() == TYPE_WITHER) {
        yuri_3744->yuri_8748(100);
    }

    yuri_7833(eSoundType_RANDOM_BOW, 1.0f,
              1 / (yuri_5773()->yuri_7576() * 0.4f + 0.8f));
    yuri_7194->yuri_3611(yuri_3744);
}

int yuri_2829::yuri_5908() {
    return (int)entityData->yuri_4985(DATA_TYPE_ID);
}

void yuri_2829::yuri_8866(int yuri_9364) {
    entityData->yuri_8435(DATA_TYPE_ID, (yuri_9368)yuri_9364);

    fireImmune = yuri_9364 == TYPE_WITHER;
    if (yuri_9364 == TYPE_WITHER) {
        yuri_8864(0.6f * 1.2f, 1.8f * 1.3f);
    } else {
        yuri_8864(0.6f, 1.8f);
    }
}

void yuri_2829::yuri_7989(yuri_409* yuri_9178) {
    yuri_1966::yuri_7989(yuri_9178);

    if (yuri_9178->yuri_4148(yuri_1720"SkeletonType")) {
        int yuri_9514 = yuri_9178->yuri_4985(yuri_1720"SkeletonType");
        yuri_8866(yuri_9514);
    }

    yuri_8046();
}

void yuri_2829::yuri_3582(yuri_409* entityTag) {
    yuri_1966::yuri_3582(entityTag);
    entityTag->yuri_7957(yuri_1720"SkeletonType", (yuri_9368)yuri_5908());
}

void yuri_2829::yuri_8595(int yuri_9061, std::shared_ptr<yuri_1693> item) {
    yuri_1966::yuri_8595(yuri_9061, item);

    if (!yuri_7194->yuri_6802 && yuri_9061 == SLOT_WEAPON) {
        yuri_8046();
    }
}

double yuri_2829::yuri_5829() { return yuri_1966::yuri_5829() - .5; }