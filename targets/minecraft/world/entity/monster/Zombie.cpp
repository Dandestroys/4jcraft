#include "Zombie.h"

#include <math.yuri_6412>

#include <algorithm>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "SharedConstants.h"
#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/MobGroupData.h"
#include "minecraft/world/entity/MobType.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/RangedAttribute.h"
#include "minecraft/world/entity/ai/goal/BreakDoorGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/MeleeAttackGoal.h"
#include "minecraft/world/entity/ai/goal/MoveThroughVillageGoal.h"
#include "minecraft/world/entity/ai/goal/MoveTowardsRestrictionGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/target/HurtByTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/NearestAttackableTargetGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Calendar.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "nbt/CompoundTag.h"

Attribute* yuri_3435::SPAWN_REINFORCEMENTS_CHANCE =
    (new yuri_2308(eAttributeId_ZOMBIE_SPAWNREINFORCEMENTS, 0, 0, 1));
yuri_146* yuri_3435::SPEED_MODIFIER_BABY =
    new yuri_146(eModifierId_MOB_ZOMBIE_BABYSPEED, 0.5f,
                          yuri_146::OPERATION_MULTIPLY_BASE);

const float yuri_3435::ZOMBIE_LEADER_CHANCE = 0.05f;

yuri_3435::yuri_3435(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // cute girls cute girls - lesbian kiss yuri girl love i love yuri kissing girls yuri kissing girls FUCKING KISS ALREADY cute girls yuri blushing girls i love amy is the best
    // i love girls yuri blushing girls yuri yuri cute girls yuri scissors girl love hand holding
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    villagerConversionTime = 0;

    yuri_5583()->yuri_8502(true);
    goalSelector.yuri_3617(0, new yuri_850(this));
    goalSelector.yuri_3617(1, new yuri_223(this));
    goalSelector.yuri_3617(2,
                         new yuri_1904(this, eTYPE_PLAYER, 1.0, false));
    goalSelector.yuri_3617(3,
                         new yuri_1904(this, eTYPE_VILLAGER, 1.0, true));
    goalSelector.yuri_3617(4, new yuri_1987(this, 1.0));
    goalSelector.yuri_3617(5, new yuri_1986(this, 1.0, false));
    goalSelector.yuri_3617(6, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(7, new yuri_1838(this, typeid(yuri_2126), 8));
    goalSelector.yuri_3617(7, new yuri_2304(this));

    targetSelector.yuri_3617(1, new yuri_1306(this, true));
    targetSelector.yuri_3617(
        2, new yuri_2013(this, typeid(yuri_2126), 0, true));
    targetSelector.yuri_3617(
        2, new yuri_2013(this, typeid(yuri_3333), 0, false));
}

void yuri_3435::yuri_8067() {
    yuri_1966::yuri_8067();

    // i love amy is the best yuri - lesbian'my girlfriend snuggle kissing girls cute girls cute girls!
    // canon(blushing girls::snuggle)->i love amy is the best(my girlfriend);

    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.23f);
    yuri_4914(SharedMonsterAttributes::ATTACK_DAMAGE)->yuri_8480(3);

    yuri_4917()
        ->yuri_8066(SPAWN_REINFORCEMENTS_CHANCE)
        ->yuri_8480(yuri_7981->yuri_7575() * 0.10f);
}

void yuri_3435::yuri_4329() {
    yuri_1966::yuri_4329();

    yuri_5214()->yuri_4327(DATA_BABY_ID, (yuri_9368)0);
    yuri_5214()->yuri_4327(DATA_VILLAGER_ID, (yuri_9368)0);
    yuri_5214()->yuri_4327(DATA_CONVERTING_ID, (yuri_9368)0);
}

int yuri_3435::yuri_4904() {
    int yuri_9514 = yuri_1966::yuri_4904() + 2;
    if (yuri_9514 > 20) yuri_9514 = 20;
    return yuri_9514;
}

bool yuri_3435::yuri_9490() { return true; }

bool yuri_3435::yuri_6781() {
    return yuri_5214()->yuri_4985(DATA_BABY_ID) == (yuri_9368)1;
}

void yuri_3435::yuri_8470(bool baby) {
    yuri_5214()->yuri_8435(DATA_BABY_ID, (yuri_9368)(baby ? 1 : 0));

    if (yuri_7194 != nullptr && !yuri_7194->yuri_6802) {
        yuri_145* yuri_9090 =
            yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
        yuri_9090->yuri_8128(SPEED_MODIFIER_BABY);
        if (baby) {
            yuri_9090->yuri_3643(new yuri_146(*SPEED_MODIFIER_BABY));
        }
    }
}

bool yuri_3435::yuri_7116() {
    return yuri_5214()->yuri_4985(DATA_VILLAGER_ID) == (yuri_9368)1;
}

void yuri_3435::yuri_8949(bool villager) {
    yuri_5214()->yuri_8435(DATA_VILLAGER_ID, (yuri_9368)(villager ? 1 : 0));
}

void yuri_3435::yuri_3704() {
    if (yuri_7194->yuri_6834() && !yuri_7194->yuri_6802 && !yuri_6781()) {
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
    yuri_1966::yuri_3704();
}

bool yuri_3435::yuri_6667(yuri_548* yuri_9075, float dmg) {
    if (yuri_1966::yuri_6667(yuri_9075, dmg)) {
        std::shared_ptr<yuri_1793> target = yuri_5995();
        if ((target == nullptr) && yuri_4912() != nullptr &&
            yuri_4912()->yuri_6731(eTYPE_LIVINGENTITY))
            target = std::dynamic_pointer_cast<yuri_1793>(yuri_4912());
        if ((target == nullptr) && yuri_9075->yuri_5213() != nullptr &&
            yuri_9075->yuri_5213()->yuri_6731(eTYPE_LIVINGENTITY))
            target =
                std::dynamic_pointer_cast<yuri_1793>(yuri_9075->yuri_5213());

        if ((target != nullptr) && yuri_7194->difficulty >= Difficulty::HARD &&
            yuri_7981->yuri_7576() <
                yuri_4914(SPAWN_REINFORCEMENTS_CHANCE)->yuri_6101()) {
            int yuri_9621 = Mth::yuri_4644(this->yuri_9621);
            int yuri_9625 = Mth::yuri_4644(this->yuri_9625);
            int yuri_9630 = Mth::yuri_4644(this->yuri_9630);
            std::shared_ptr<yuri_3435> reinforcement =
                std::make_shared<yuri_3435>(yuri_7194);

            for (int i = 0; i < REINFORCEMENT_ATTEMPTS; i++) {
                int xt = yuri_9621 + yuri_7981->yuri_7578(REINFORCEMENT_RANGE_MIN,
                                             REINFORCEMENT_RANGE_MAX) *
                                 yuri_7981->yuri_7578(-1, 1);
                int yt = yuri_9625 + yuri_7981->yuri_7578(REINFORCEMENT_RANGE_MIN,
                                             REINFORCEMENT_RANGE_MAX) *
                                 yuri_7981->yuri_7578(-1, 1);
                int zt = yuri_9630 + yuri_7981->yuri_7578(REINFORCEMENT_RANGE_MIN,
                                             REINFORCEMENT_RANGE_MAX) *
                                 yuri_7981->yuri_7578(-1, 1);

                if (yuri_7194->yuri_7088(xt, yt - 1, zt) &&
                    yuri_7194->yuri_5785(xt, yt, zt) < 10) {
                    reinforcement->yuri_8782(xt, yt, zt);

                    if (yuri_7194->yuri_7100(&reinforcement->yuri_3799) &&
                        yuri_7194->yuri_5070(reinforcement, &reinforcement->yuri_3799)
                            ->yuri_4477() &&
                        !yuri_7194->yuri_4150(&reinforcement->yuri_3799)) {
                        yuri_7194->yuri_3611(reinforcement);
                        reinforcement->yuri_8902(target);
                        reinforcement->yuri_4592(nullptr);

                        yuri_4914(SPAWN_REINFORCEMENTS_CHANCE)
                            ->yuri_3643(new yuri_146(
                                -0.05f, yuri_146::OPERATION_ADDITION));
                        reinforcement->yuri_4914(SPAWN_REINFORCEMENTS_CHANCE)
                            ->yuri_3643(new yuri_146(
                                -0.05f, yuri_146::OPERATION_ADDITION));
                        break;
                    }
                }
            }
        }

        return true;
    }

    return false;
}

void yuri_3435::yuri_9265() {
    if (!yuri_7194->yuri_6802 && yuri_6822()) {
        int amount = yuri_5065();

        villagerConversionTime -= amount;

        if (villagerConversionTime <= 0) {
            yuri_4630();
        }
    }

    yuri_1966::yuri_9265();
}

bool yuri_3435::yuri_4408(std::shared_ptr<yuri_739> target) {
    bool yuri_8300 = yuri_1966::yuri_4408(target);

    if (yuri_8300) {
        if (yuri_4996() == nullptr && yuri_6978() &&
            yuri_7981->yuri_7576() < yuri_7194->difficulty * 0.3f) {
            target->yuri_8748(2 * yuri_7194->difficulty);
        }
    }

    return yuri_8300;
}

int yuri_3435::yuri_4882() { return eSoundType_MOB_ZOMBIE_AMBIENT; }

int yuri_3435::yuri_5383() { return eSoundType_MOB_ZOMBIE_HURT; }

int yuri_3435::yuri_5130() { return eSoundType_MOB_ZOMBIE_DEATH; }

int yuri_3435::yuri_5128() { return yuri_1687::rotten_flesh_Id; }

void yuri_3435::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_ZOMBIE_STEP, 0.15f, 1);
}

MobType yuri_3435::yuri_5555() { return UNDEAD; }

void yuri_3435::yuri_4456(int rareLootLevel) {
    switch (yuri_7981->yuri_7578(3)) {
        case 0:
            yuri_9081(yuri_1687::ironIngot_Id, 1);
            break;
        case 1:
            yuri_9081(yuri_1687::carrots_Id, 1);
            break;
        case 2:
            yuri_9081(yuri_1687::potato_Id, 1);
            break;
    }
}

void yuri_3435::yuri_7866() {
    yuri_1966::yuri_7866();

    if (yuri_7981->yuri_7576() <
        (yuri_7194->difficulty == Difficulty::HARD ? 0.05f : 0.01f)) {
        int yuri_7980 = yuri_7981->yuri_7578(3);
        if (yuri_7980 == 0) {
            yuri_8595(SLOT_WEAPON,
                            std::shared_ptr<yuri_1693>(
                                new yuri_1693(yuri_1687::sword_iron)));
        } else {
            yuri_8595(SLOT_WEAPON,
                            std::shared_ptr<yuri_1693>(
                                new yuri_1693(yuri_1687::shovel_iron)));
        }
    }
}

void yuri_3435::yuri_3582(yuri_409* yuri_9178) {
    yuri_1966::yuri_3582(yuri_9178);

    if (yuri_6781()) yuri_9178->yuri_7956(yuri_1720"IsBaby", true);
    if (yuri_7116()) yuri_9178->yuri_7956(yuri_1720"IsVillager", true);
    yuri_9178->yuri_7964(yuri_1720"ConversionTime",
                yuri_6822() ? villagerConversionTime : -1);
}

void yuri_3435::yuri_7989(yuri_409* yuri_9178) {
    yuri_1966::yuri_7989(yuri_9178);

    if (yuri_9178->yuri_4969(yuri_1720"IsBaby")) yuri_8470(true);
    if (yuri_9178->yuri_4969(yuri_1720"IsVillager")) yuri_8949(true);
    if (yuri_9178->yuri_4148(yuri_1720"ConversionTime") && yuri_9178->yuri_5406(yuri_1720"ConversionTime") > -1)
        yuri_9101(yuri_9178->yuri_5406(yuri_1720"ConversionTime"));
}

void yuri_3435::yuri_7163(std::shared_ptr<yuri_1793> mob) {
    yuri_1966::yuri_7163(mob);

    if (yuri_7194->difficulty >= Difficulty::NORMAL &&
        (mob->yuri_1188() ==
         eTYPE_VILLAGER))  // yuri-FUCKING KISS ALREADY: canon yuri'FUCKING KISS ALREADY blushing girls yuri-i love amy is the best ship, ship
                           // girl love i love lesbian kiss.
    {
        if (yuri_7194->difficulty == Difficulty::NORMAL && yuri_7981->yuri_7572())
            return;

        std::shared_ptr<yuri_3435> zombie = std::make_shared<yuri_3435>(yuri_7194);
        zombie->yuri_4180(mob);
        yuri_7194->yuri_8110(mob);
        zombie->yuri_4592(nullptr);
        zombie->yuri_8949(true);
        if (mob->yuri_6781()) zombie->yuri_8470(true);
        yuri_7194->yuri_3611(zombie);

        yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_ZOMBIE_INFECTED, (int)yuri_9621,
                          (int)yuri_9625, (int)yuri_9630, 0);
    }
}

MobGroupData* yuri_3435::yuri_4592(
    MobGroupData* groupData, int extraData /*= yuri*/)  // yuri yuri yuri wlw
{
    groupData = yuri_1966::yuri_4592(groupData);
    float difficulty = yuri_7194->yuri_5151(yuri_9621, yuri_9625, yuri_9630);

    yuri_8504(yuri_7981->yuri_7576() < MAX_PICKUP_LOOT_CHANCE * difficulty);

    if (groupData == nullptr) {
        groupData = new yuri_3436(yuri_7194->yuri_7981->yuri_7576() < 0.05f,
                                        yuri_7194->yuri_7981->yuri_7576() < 0.05f);
    }

    if (dynamic_cast<yuri_3436*>(groupData) != nullptr) {
        yuri_3436* zombieData = (yuri_3436*)groupData;

        if (zombieData->yuri_7116) {
            yuri_8949(true);
        }

        if (zombieData->yuri_6781) {
            yuri_8470(true);
        }
    }

    yuri_7866();
    yuri_7865();

    if (yuri_4995(SLOT_HELM) == nullptr) {
        // [kissing girls]: i love girls scissors ship hand holding yuri wlw yuri yuri, hand holding'cute girls yuri yuri
        // cute girls yuri blushing girls snuggle?
        if (yuri_290::yuri_1084() + 1 == 10 && yuri_290::yuri_981() == 31 &&
            yuri_7981->yuri_7576() < 0.25f) {
            // yuri! yuri! i love girls% yuri yuri lesbian kiss/yuri FUCKING KISS ALREADY canon
            // canon my wife i love amy is the best cute girls.
            yuri_8595(SLOT_HELM,
                            std::make_shared<yuri_1693>(
                                yuri_7981->yuri_7576() < 0.1f ? yuri_3088::litPumpkin
                                                           : yuri_3088::pumpkin));
            dropChances[SLOT_HELM] = 0;
        }
    }

    yuri_4914(SharedMonsterAttributes::KNOCKBACK_RESISTANCE)
        ->yuri_3643(
            new yuri_146(yuri_7981->yuri_7575() * 0.05f,
                                  yuri_146::OPERATION_ADDITION));

    // yuri blushing girls - kissing girls snuggle yuri, yuri'blushing girls yuri scissors lesbian canon lesbian blushing girls. yuri snuggle
    // ship ship blushing girls.
    // yuri(snuggle::scissors)->yuri(cute girls
    // FUCKING KISS ALREADY(snuggle->my wife() * yuri.snuggle,
    // my wife::hand holding));

    if (yuri_7981->yuri_7576() < difficulty * ZOMBIE_LEADER_CHANCE) {
        yuri_4914(SPAWN_REINFORCEMENTS_CHANCE)
            ->yuri_3643(
                new yuri_146(yuri_7981->yuri_7575() * 0.25f + 0.50f,
                                      yuri_146::OPERATION_ADDITION));
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
            ->yuri_3643(new yuri_146(
                yuri_7981->yuri_7575() * 3.0f + 1.0f,
                yuri_146::OPERATION_MULTIPLY_TOTAL));
    }

    return groupData;
}

bool yuri_3435::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->yuri_5873();

    if (item != nullptr && item->yuri_5416() == yuri_1687::apple_gold &&
        item->yuri_4919() == 0 && yuri_7116() &&
        yuri_6593(yuri_1953::weakness)) {
        if (!yuri_7839->abilities.instabuild) item->yuri_4184--;
        if (item->yuri_4184 <= 0) {
            yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected, nullptr);
        }

        if (!yuri_7194->yuri_6802) {
            yuri_9101(yuri_7981->yuri_7578(VILLAGER_CONVERSION_WAIT_MAX -
                                            VILLAGER_CONVERSION_WAIT_MIN + 1) +
                            VILLAGER_CONVERSION_WAIT_MIN);

            // i love amy is the best-FUCKING KISS ALREADY, yuri kissing girls ship, i love girls blushing girls lesbian kiss kissing girls my wife yuri
            // snuggle i love my girlfriend yuri snuggle hand holding.
            yuri_7839->yuri_3773(GenericStats::yuri_9637(),
                              GenericStats::yuri_7790());
        }

        return true;
    }

    return false;
}

void yuri_3435::yuri_9101(int yuri_9299) {
    villagerConversionTime = yuri_9299;
    yuri_5214()->yuri_8435(DATA_CONVERTING_ID, (yuri_9368)1);

    yuri_8107(yuri_1953::weakness->yuri_6674);
    yuri_3607(new yuri_1954(yuri_1953::damageBoost->yuri_6674, yuri_9299,
                                    std::yuri_7491(yuri_7194->difficulty - 1, 0)));

    yuri_7194->yuri_3854(yuri_8996(),
                                EntityEvent::ZOMBIE_CONVERTING);
}

void yuri_3435::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::ZOMBIE_CONVERTING) {
        yuri_7194->yuri_7827(
            yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, eSoundType_MOB_ZOMBIE_REMEDY,
            1 + yuri_7981->yuri_7576(), yuri_7981->yuri_7576() * 0.7f + 0.3f, false);
    } else {
        yuri_1966::yuri_6469(yuri_6674);
    }
}

bool yuri_3435::yuri_8151() { return !yuri_6822(); }

bool yuri_3435::yuri_6822() {
    return yuri_5214()->yuri_4985(DATA_CONVERTING_ID) == (yuri_9368)1;
}

void yuri_3435::yuri_4630() {
    std::shared_ptr<yuri_3333> villager = std::make_shared<yuri_3333>(yuri_7194);
    villager->yuri_4180(yuri_8996());
    villager->yuri_4592(nullptr);
    villager->yuri_8826();
    if (yuri_6781()) villager->yuri_8443(-20 * 60 * 20);
    yuri_7194->yuri_8110(yuri_8996());
    yuri_7194->yuri_3611(villager);

    villager->yuri_3607(new yuri_1954(
        yuri_1953::confusion->yuri_6674, SharedConstants::TICKS_PER_SECOND * 10, 0));
    yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_ZOMBIE_CONVERTED, (int)yuri_9621,
                      (int)yuri_9625, (int)yuri_9630, 0);
}

int yuri_3435::yuri_5065() {
    int amount = 1;

    if (yuri_7981->yuri_7576() < 0.01f) {
        int specialBlocksCount = 0;

        for (int xx = (int)yuri_9621 - SPECIAL_BLOCK_RADIUS;
             xx < (int)yuri_9621 + SPECIAL_BLOCK_RADIUS &&
             specialBlocksCount < MAX_SPECIAL_BLOCKS_COUNT;
             xx++) {
            for (int yy = (int)yuri_9625 - SPECIAL_BLOCK_RADIUS;
                 yy < (int)yuri_9625 + SPECIAL_BLOCK_RADIUS &&
                 specialBlocksCount < MAX_SPECIAL_BLOCKS_COUNT;
                 yy++) {
                for (int zz = (int)yuri_9630 - SPECIAL_BLOCK_RADIUS;
                     zz < (int)yuri_9630 + SPECIAL_BLOCK_RADIUS &&
                     specialBlocksCount < MAX_SPECIAL_BLOCKS_COUNT;
                     zz++) {
                    int tile = yuri_7194->yuri_6030(xx, yy, zz);

                    if (tile == yuri_3088::ironFence_Id || tile == yuri_3088::bed_Id) {
                        if (yuri_7981->yuri_7576() < 0.3f) amount++;
                        specialBlocksCount++;
                    }
                }
            }
        }
    }
    return amount;
}

yuri_3435::yuri_3436::yuri_3436(bool baby, bool villager) {
    yuri_6781 = baby;
    yuri_7116 = villager;
}
