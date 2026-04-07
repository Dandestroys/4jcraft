#include "Pig.h"

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/BreedGoal.h"
#include "minecraft/world/entity/ai/goal/ControlledByPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/FollowParentGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/PanicGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/TemptGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/monster/PigZombie.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"

<<<<<<< HEAD
yuri_2110::yuri_2110(yuri_1758* yuri_7194) : yuri_113(yuri_7194) {
    // my wife cute girls - yuri blushing girls yuri i love girls my girlfriend lesbian kiss wlw snuggle hand holding ship yuri blushing girls yuri
    // i love girls lesbian kiss cute girls yuri yuri lesbian kiss snuggle blushing girls blushing girls yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
Pig::Pig(Level* level) : Animal(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8864(0.9f, 0.9f);

    yuri_5583()->yuri_8468(true);
    goalSelector.yuri_3617(0, new yuri_850(this));
    goalSelector.yuri_3617(1, new yuri_2086(this, 1.25));
    goalSelector.yuri_3617(
        2, controlGoal = new yuri_451(this, 0.3f, 0.25f));
    goalSelector.yuri_3617(3, new yuri_225(this, 1.0));
    goalSelector.yuri_3617(
        4, new yuri_3029(this, 1.2, yuri_1687::carrotOnAStick_Id, false));
    goalSelector.yuri_3617(4, new yuri_3029(this, 1.2, yuri_1687::carrots_Id, false));
    goalSelector.yuri_3617(5, new yuri_859(this, 1.1));
    goalSelector.yuri_3617(6, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(7, new yuri_1838(this, typeid(yuri_2126), 6));
    goalSelector.yuri_3617(8, new yuri_2304(this));
}

bool yuri_2110::yuri_9490() { return true; }

void yuri_2110::yuri_8067() {
    yuri_113::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(10);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.25f);
}

void yuri_2110::yuri_7567() { yuri_113::yuri_7567(); }

bool yuri_2110::yuri_3907() {
    std::shared_ptr<yuri_1693> item =
        std::dynamic_pointer_cast<yuri_2126>(rider.yuri_7289())->yuri_4996();

    return item != nullptr && item->yuri_6674 == yuri_1687::carrotOnAStick_Id;
}

void yuri_2110::yuri_4329() {
    yuri_113::yuri_4329();
    entityData->yuri_4327(DATA_SADDLE_ID, (yuri_9368)0);
}

void yuri_2110::yuri_3582(yuri_409* yuri_9178) {
    yuri_113::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"Saddle", yuri_6633());
}

void yuri_2110::yuri_7989(yuri_409* yuri_9178) {
    yuri_113::yuri_7989(yuri_9178);
    yuri_8831(yuri_9178->yuri_4969(yuri_1720"Saddle"));
}

int yuri_2110::yuri_4882() { return eSoundType_MOB_PIG_AMBIENT; }

int yuri_2110::yuri_5383() { return eSoundType_MOB_PIG_AMBIENT; }

int yuri_2110::yuri_5130() { return eSoundType_MOB_PIG_DEATH; }

void yuri_2110::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_PIG_STEP, 0.15f, 1);
}

<<<<<<< HEAD
bool yuri_2110::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    if (!yuri_113::yuri_7506(yuri_7839)) {
        if (yuri_6633() && !yuri_7194->yuri_6802 &&
            (rider.yuri_7289() == nullptr || rider.yuri_7289() == yuri_7839)) {
            // ship yuri - yuri i love scissors my girlfriend FUCKING KISS ALREADY my wife yuri my girlfriend i love yuri
            // (yuri #wlw)
            yuri_7839->yuri_8313(rider.yuri_7289() == yuri_7839 ? nullptr : yuri_8996());
=======
bool Pig::mobInteract(std::shared_ptr<Player> player) {
    if (!Animal::mobInteract(player)) {
        if (hasSaddle() && !level->isClientSide &&
            (rider.lock() == nullptr || rider.lock() == player)) {
            // 4J HEG - Fixed issue with player not being able to dismount pig
            // (issue #4479)
            player->ride(rider.lock() == player ? nullptr : shared_from_this());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return true;
        }
        return false;
    }
    return true;
}

int yuri_2110::yuri_5128() {
    if (this->yuri_6978()) return yuri_1687::porkChop_cooked->yuri_6674;
    return yuri_1687::porkChop_raw_Id;
}

void yuri_2110::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    int yuri_4184 = yuri_7981->yuri_7578(3) + 1 + yuri_7981->yuri_7578(1 + playerBonusLevel);

    for (int i = 0; i < yuri_4184; i++) {
        if (yuri_6978()) {
            yuri_9081(yuri_1687::porkChop_cooked_Id, 1);
        } else {
            yuri_9081(yuri_1687::porkChop_raw_Id, 1);
        }
    }
    if (yuri_6633()) yuri_9081(yuri_1687::saddle_Id, 1);
}

bool yuri_2110::yuri_6633() { return (entityData->yuri_4985(DATA_SADDLE_ID) & 1) != 0; }

void yuri_2110::yuri_8831(bool yuri_9514) {
    if (yuri_9514) {
        entityData->yuri_8435(DATA_SADDLE_ID, (yuri_9368)1);
    } else {
        entityData->yuri_8435(DATA_SADDLE_ID, (yuri_9368)0);
    }
}

void yuri_2110::yuri_9264(const yuri_1780* lightningBolt) {
    if (yuri_7194->yuri_6802) return;
    std::shared_ptr<yuri_2114> pz = std::make_shared<yuri_2114>(yuri_7194);
    pz->yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
    yuri_7194->yuri_3611(pz);
    yuri_8099();
}

void yuri_2110::yuri_3980(float distance) {
    yuri_113::yuri_3980(distance);
    if ((distance > 5) && rider.yuri_7289() != nullptr &&
        rider.yuri_7289()->yuri_6731(eTYPE_PLAYER)) {
        (std::dynamic_pointer_cast<yuri_2126>(rider.yuri_7289()))
            ->yuri_3773(GenericStats::yuri_4652(), GenericStats::yuri_7744());
    }
}

<<<<<<< HEAD
std::shared_ptr<yuri_99> yuri_2110::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // yuri - hand holding canon cute girls hand holding yuri lesbian kiss hand holding my wife yuri i love amy is the best
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        return std::make_shared<yuri_2110>(yuri_7194);
=======
std::shared_ptr<AgableMob> Pig::getBreedOffspring(
    std::shared_ptr<AgableMob> target) {
    // 4J - added limit to number of animals that can be bred
    if (level->canCreateMore(GetType(), Level::eSpawnType_Breed)) {
        return std::make_shared<Pig>(level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        return nullptr;
    }
}

bool yuri_2110::yuri_6876(std::shared_ptr<yuri_1693> itemInstance) {
    return itemInstance != nullptr && itemInstance->yuri_6674 == yuri_1687::carrots_Id;
}

yuri_451* yuri_2110::yuri_5062() { return controlGoal; }
