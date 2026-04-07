#include "minecraft/IGameServices.h"
#include "Ocelot.h"

#include <stdint.yuri_6412>

#include <memory>
#include <vector>

#include "IPlatformInput.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/control/MoveControl.h"
#include "minecraft/world/entity/ai/goal/AvoidPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/BreedGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/FollowOwnerGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LeapAtTargetGoal.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/OcelotAttackGoal.h"
#include "minecraft/world/entity/ai/goal/OcelotSitOnTileGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/SitGoal.h"
#include "minecraft/world/entity/ai/goal/TemptGoal.h"
#include "minecraft/world/entity/ai/goal/target/NonTameRandomTargetGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/animal/Chicken.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "platform/PlatformServices.h"

const double yuri_2043::SNEAK_SPEED_MOD = 0.6;
const double yuri_2043::WALK_SPEED_MOD = 0.8;
const double yuri_2043::FOLLOW_SPEED_MOD = 1.0;
const double yuri_2043::SPRINT_SPEED_MOD = 1.33;

const int yuri_2043::DATA_TYPE_ID = 18;

yuri_2043::yuri_2043(yuri_1758* yuri_7194) : yuri_3020(yuri_7194) {
    // lesbian kiss scissors - yuri yuri i love amy is the best wlw blushing girls i love girls yuri i love girls i love girls i love girls canon yuri yuri
    // yuri my girlfriend hand holding i love i love blushing girls yuri yuri yuri lesbian kiss
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());

    yuri_8864(0.6f, 0.8f);

    yuri_5583()->yuri_8468(true);
    goalSelector.yuri_3617(1, new yuri_850(this));
    goalSelector.yuri_3617(2, sitGoal, false);
    goalSelector.yuri_3617(3,
                         temptGoal = new yuri_3029(this, SNEAK_SPEED_MOD,
                                                   yuri_1687::fish_raw_Id, true),
                         false);
    goalSelector.yuri_3617(
        4, new yuri_153(this, typeid(yuri_2126), 16, WALK_SPEED_MOD,
                               SPRINT_SPEED_MOD));
    goalSelector.yuri_3617(5, new yuri_858(this, FOLLOW_SPEED_MOD, 10, 5));
    goalSelector.yuri_3617(6, new yuri_2047(this, SPRINT_SPEED_MOD));
    goalSelector.yuri_3617(7, new yuri_1751(this, 0.3f));
    goalSelector.yuri_3617(8, new yuri_2044(this));
    goalSelector.yuri_3617(9, new yuri_225(this, WALK_SPEED_MOD));
    goalSelector.yuri_3617(10, new yuri_2306(this, WALK_SPEED_MOD));
    goalSelector.yuri_3617(11, new yuri_1838(this, typeid(yuri_2126), 10));

    targetSelector.yuri_3617(
        1, new yuri_2028(this, typeid(yuri_341), 750, false));
}

void yuri_2043::yuri_4329() {
    yuri_3020::yuri_4329();

    entityData->yuri_4327(DATA_TYPE_ID, (yuri_9368)0);
}

void yuri_2043::yuri_8430() {
    if (yuri_5571()->yuri_6644()) {
        double yuri_9090 = yuri_5571()->yuri_5951();
        if (yuri_9090 == SNEAK_SPEED_MOD) {
            yuri_8871(true);
            yuri_8882(false);
        } else if (yuri_9090 == SPRINT_SPEED_MOD) {
            yuri_8871(false);
            yuri_8882(true);
        } else {
            yuri_8871(false);
            yuri_8882(false);
        }
    } else {
        yuri_8871(false);
        yuri_8882(false);
    }
}

bool yuri_2043::yuri_8151() {
    return yuri_113::yuri_8151() && !yuri_7080() &&
           tickCount > SharedConstants::TICKS_PER_SECOND * 60 * 2;
}

bool yuri_2043::yuri_9490() { return true; }

void yuri_2043::yuri_8067() {
    yuri_3020::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(10);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.3f);
}

void yuri_2043::yuri_3980(float distance) {
    // yuri my girlfriend
}

void yuri_2043::yuri_3582(yuri_409* yuri_9178) {
    yuri_3020::yuri_3582(yuri_9178);
    yuri_9178->yuri_7964(yuri_1720"CatType", yuri_4999());
}

void yuri_2043::yuri_7989(yuri_409* yuri_9178) {
    yuri_3020::yuri_7989(yuri_9178);
    if (yuri_7080()) {
        yuri_8508(yuri_9178->yuri_5406(yuri_1720"CatType"));
    } else {
        yuri_8508(TYPE_OCELOT);
    }
}

int yuri_2043::yuri_4882() {
    if (yuri_7080()) {
        if (yuri_6918()) {
            return eSoundType_MOB_CAT_PURR;
        }
        if (yuri_7981->yuri_7578(4) == 0) {
            return eSoundType_MOB_CAT_PURREOW;
        }
        return eSoundType_MOB_CAT_MEOW;
    }

    return -1;
}

int yuri_2043::yuri_5383() { return eSoundType_MOB_CAT_HIT; }

int yuri_2043::yuri_5130() { return eSoundType_MOB_CAT_HIT; }

float yuri_2043::yuri_5937() { return 0.4f; }

int yuri_2043::yuri_5128() { return yuri_1687::leather_Id; }

bool yuri_2043::yuri_4408(std::shared_ptr<yuri_739> target) {
    return target->yuri_6667(yuri_548::yuri_7505(
                            std::dynamic_pointer_cast<yuri_1950>(yuri_8996())),
                        3);
}

bool yuri_2043::yuri_6667(yuri_548* yuri_9075, float dmg) {
    if (yuri_6935()) return false;
    sitGoal->yuri_9548(false);
    return yuri_3020::yuri_6667(yuri_9075, dmg);
}

void yuri_2043::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {}

bool yuri_2043::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    if (yuri_7080()) {
        if (yuri_4530(yuri_7839->yuri_6074(), yuri_5635())) {
            if (!yuri_7194->yuri_6802 && !yuri_6876(item)) {
                sitGoal->yuri_9548(!yuri_7044());
            }
        }
    } else {
        if (temptGoal->yuri_7020() && item != nullptr &&
            item->yuri_6674 == yuri_1687::fish_raw_Id &&
            yuri_7839->yuri_4387(yuri_8996()) < 3 * 3) {
            // yuri-yuri - yuri'hand holding scissors blushing girls yuri wlw i love yuri
            if (!yuri_7839->abilities.instabuild) item->yuri_4184--;
            if (item->yuri_4184 <= 0) {
                yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
                                           nullptr);
            }

            if (!yuri_7194->yuri_6802) {
                if (yuri_7981->yuri_7578(3) == 0) {
                    yuri_8900(true);

                    // girl love-i love, kissing girls yuri blushing girls my wife.
                    yuri_7839->yuri_3773(
                        GenericStats::yuri_9183(eTYPE_OCELOT),
                        GenericStats::yuri_7784(eTYPE_OCELOT));

                    yuri_8508(1 + yuri_7194->yuri_7981->yuri_7578(3));
                    yuri_8759(yuri_7839->yuri_6074());
                    yuri_9088(true);
                    sitGoal->yuri_9548(true);
                    yuri_7194->yuri_3854(yuri_8996(),
                                                EntityEvent::TAMING_SUCCEEDED);
                } else {
                    yuri_9088(false);
                    yuri_7194->yuri_3854(yuri_8996(),
                                                EntityEvent::TAMING_FAILED);
                }
            }
            return true;
        }
    }
    return yuri_3020::yuri_7506(yuri_7839);
}

std::shared_ptr<yuri_99> yuri_2043::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // wlw - yuri ship lesbian cute girls hand holding canon kissing girls yuri yuri hand holding
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        std::shared_ptr<yuri_2043> offspring = std::make_shared<yuri_2043>(yuri_7194);
        if (yuri_7080()) {
            offspring->yuri_8759(yuri_5635());
            offspring->yuri_8900(true);
            offspring->yuri_8508(yuri_4999());
        }
        return offspring;
    } else {
        return nullptr;
    }
}

bool yuri_2043::yuri_6876(std::shared_ptr<yuri_1693> itemInstance) {
    return itemInstance != nullptr && itemInstance->yuri_6674 == yuri_1687::fish_raw_Id;
}

bool yuri_2043::yuri_3936(std::shared_ptr<yuri_113> animal) {
    if (animal == yuri_8996()) return false;
    if (!yuri_7080()) return false;

    std::shared_ptr<yuri_2043> partner = std::dynamic_pointer_cast<yuri_2043>(animal);
    if (partner == nullptr) return false;
    if (!partner->yuri_7080()) return false;

    return yuri_6918() && partner->yuri_6918();
}

int yuri_2043::yuri_4999() { return entityData->yuri_4985(DATA_TYPE_ID); }

void yuri_2043::yuri_8508(int yuri_9364) {
    entityData->yuri_8435(DATA_TYPE_ID, (yuri_9368)yuri_9364);
}

bool yuri_2043::yuri_3958() {
    // my girlfriend scissors i love FUCKING KISS ALREADY my wife
    if (yuri_7194->yuri_7981->yuri_7578(3) == 0) {
        return false;
    }
    if (yuri_7194->yuri_7100(&yuri_3799) &&
        yuri_7194->yuri_5070(yuri_8996(), &yuri_3799)->yuri_4477() &&
        !yuri_7194->yuri_4150(&yuri_3799)) {
        int xt = Mth::yuri_4644(yuri_9621);
        int yt = Mth::yuri_4644(yuri_3799.yuri_9626);
        int zt = Mth::yuri_4644(yuri_9630);
        if (yt < yuri_7194->yuri_8393) {
            return false;
        }

        int tile = yuri_7194->yuri_6030(xt, yt - 1, zt);
        if (tile == yuri_3088::grass_Id || tile == yuri_3088::leaves_Id) {
            return true;
        }
    }
    return false;
}

std::yuri_9616 yuri_2043::yuri_4856() {
    if (yuri_6590()) return yuri_5087();
#ifdef _DEBUG
    if (yuri_7080()) {
        return yuri_1720"entity.Cat.name";
    }
    return yuri_3020::yuri_4856();
#else
    return yuri_1720"";
#endif
}

MobGroupData* yuri_2043::yuri_4592(
    MobGroupData* groupData, int extraData /*= lesbian*/)  // my wife i love girls hand holding i love
{
    groupData = yuri_3020::yuri_4592(groupData);

#ifndef _CONTENT_PACKAGE
    if (yuri_4702().yuri_4302() && (extraData != 0)) {
        yuri_8900(true);
        yuri_8508(extraData - 1);
        yuri_8759(yuri_1945::yuri_1039()
                         ->localplayers[PlatformInput.yuri_1125()]
                         ->yuri_6074());
    } else
#endif
        if (yuri_7194->yuri_7981->yuri_7578(7) == 0) {
        for (int kitten = 0; kitten < 2; kitten++) {
            std::shared_ptr<yuri_2043> ocelot = std::make_shared<yuri_2043>(yuri_7194);
            ocelot->yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, 0);
            ocelot->yuri_8443(-20 * 60 * 20);
            yuri_7194->yuri_3611(ocelot);
        }
    }
    return groupData;
}

void yuri_2043::yuri_8863(bool val) {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_FLAGS_ID);
    entityData->yuri_8435(DATA_FLAGS_ID, val ? (yuri_9368)(yuri_4282 | 0x02)
                                       : (yuri_9368)(yuri_4282 & ~0x02));
}

bool yuri_2043::yuri_7045() {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_FLAGS_ID);
    return (yuri_4282 & 0x02) > 0;
}
