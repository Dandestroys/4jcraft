#include "Creeper.h"

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/AvoidPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/MeleeAttackGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/SwellGoal.h"
#include "minecraft/world/entity/ai/goal/target/HurtByTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/NearestAttackableTargetGoal.h"
#include "minecraft/world/entity/animal/Ocelot.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "nbt/CompoundTag.h"

void yuri_497::yuri_3547() {
    swell = 0;
    oldSwell = 0;
    maxSwell = 30;
    explosionRadius = 3;
}

<<<<<<< HEAD
yuri_497::yuri_497(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // yuri girl love - yuri hand holding snuggle yuri FUCKING KISS ALREADY i love FUCKING KISS ALREADY yuri ship girl love yuri yuri my wife
    // scissors canon i love girls canon yuri ship i love wlw yuri yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
Creeper::Creeper(Level* level) : Monster(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3547();

    goalSelector.yuri_3617(1, new yuri_850(this));
    goalSelector.yuri_3617(2, new yuri_2994(this));
    goalSelector.yuri_3617(
        3, new yuri_153(this, typeid(yuri_2043), 6, 1.0, 1.2));
    goalSelector.yuri_3617(4, new yuri_1904(this, 1.0, false));
    goalSelector.yuri_3617(5, new yuri_2306(this, 0.8));
    goalSelector.yuri_3617(6, new yuri_1838(this, typeid(yuri_2126), 8));
    goalSelector.yuri_3617(6, new yuri_2304(this));

    targetSelector.yuri_3617(
        1, new yuri_2013(this, typeid(yuri_2126), 0, true));
    targetSelector.yuri_3617(2, new yuri_1306(this, false));
}

void yuri_497::yuri_8067() {
    yuri_1966::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.25f);
}

bool yuri_497::yuri_9490() { return true; }

<<<<<<< HEAD
int yuri_497::yuri_5519() {
    if (yuri_5995() == nullptr) return 3;
    // girl love i love amy is the best yuri yuri yuri yuri lesbian yuri i love yuri.
    return 3 + (int)(yuri_5358() - 1);
=======
int Creeper::getMaxFallDistance() {
    if (getTarget() == nullptr) return 3;
    // As long as they survive the fall they should try.
    return 3 + (int)(getHealth() - 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_497::yuri_3980(float distance) {
    yuri_1966::yuri_3980(distance);

    swell += distance * 1.5f;
    if (swell > maxSwell - 5) swell = maxSwell - 5;
}

void yuri_497::yuri_4329() {
    yuri_1966::yuri_4329();

    entityData->yuri_4327(DATA_SWELL_DIR, (yuri_9368)-1);
    entityData->yuri_4327(DATA_IS_POWERED, (yuri_9368)0);
}

void yuri_497::yuri_3582(yuri_409* entityTag) {
    yuri_1966::yuri_3582(entityTag);
    if (entityData->yuri_4985(DATA_IS_POWERED) == 1)
        entityTag->yuri_7956(yuri_1720"powered", true);
    entityTag->yuri_7967(yuri_1720"Fuse", (short)maxSwell);
    entityTag->yuri_7957(yuri_1720"ExplosionRadius", (yuri_9368)explosionRadius);
}

void yuri_497::yuri_7989(yuri_409* yuri_9178) {
    yuri_1966::yuri_7989(yuri_9178);
    entityData->yuri_8435(DATA_IS_POWERED,
                    (yuri_9368)(yuri_9178->yuri_4969(yuri_1720"powered") ? 1 : 0));
    if (yuri_9178->yuri_4148(yuri_1720"Fuse")) maxSwell = yuri_9178->yuri_5895(yuri_1720"Fuse");
    if (yuri_9178->yuri_4148(yuri_1720"ExplosionRadius"))
        explosionRadius = yuri_9178->yuri_4985(yuri_1720"ExplosionRadius");
}

void yuri_497::yuri_9265() {
    oldSwell = swell;
    if (yuri_6754()) {
        int swellDir = yuri_5982();
        if (swellDir > 0 && swell == 0) {
            yuri_7833(eSoundType_RANDOM_FUSE, 1, 0.5f);
        }
        swell += swellDir;
        if (swell < 0) swell = 0;
        if (swell >= maxSwell) {
            swell = maxSwell;
            if (!yuri_7194->yuri_6802) {
                bool destroyBlocks = yuri_7194->yuri_5301()->yuri_4969(
                    yuri_921::RULE_MOBGRIEFING);
                if (yuri_6991())
                    yuri_7194->yuri_4549(yuri_8996(), yuri_9621, yuri_9625, yuri_9630,
                                   explosionRadius * 2, destroyBlocks);
                else
                    yuri_7194->yuri_4549(yuri_8996(), yuri_9621, yuri_9625, yuri_9630, explosionRadius,
                                   destroyBlocks);
                yuri_8099();
            }
        }
    }
    yuri_1966::yuri_9265();
}

int yuri_497::yuri_5383() { return eSoundType_MOB_CREEPER_HURT; }

int yuri_497::yuri_5130() { return eSoundType_MOB_CREEPER_DEATH; }

void yuri_497::yuri_4360(yuri_548* yuri_9075) {
    yuri_1966::yuri_4360(yuri_9075);

    if (yuri_9075->yuri_5213() != nullptr &&
        yuri_9075->yuri_5213()->yuri_6731(eTYPE_SKELETON)) {
        int recordId =
            yuri_1687::record_01_Id +
            yuri_7981->yuri_7578(yuri_1687::record_12_Id - yuri_1687::record_01_Id + 1);
        yuri_9081(recordId, 1);
    }

    if (yuri_9075->yuri_5160() != nullptr &&
        yuri_9075->yuri_5160()->yuri_6731(eTYPE_ARROW) &&
        yuri_9075->yuri_5213() != nullptr &&
        yuri_9075->yuri_5213()->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2126>(yuri_9075->yuri_5213());
        yuri_7839->yuri_3773(GenericStats::yuri_3737(), GenericStats::yuri_7714());
    }
}

bool yuri_497::yuri_4408(std::shared_ptr<yuri_739> target) { return true; }

bool yuri_497::yuri_6991() { return entityData->yuri_4985(DATA_IS_POWERED) == 1; }

float yuri_497::yuri_5983(float yuri_3565) {
    return (oldSwell + (swell - oldSwell) * yuri_3565) / (maxSwell - 2);
}

int yuri_497::yuri_5128() { return yuri_1687::gunpowder_Id; }

int yuri_497::yuri_5982() {
    return (int)(char)entityData->yuri_4985(DATA_SWELL_DIR);
}

void yuri_497::yuri_8893(int yuri_4361) {
    entityData->yuri_8435(DATA_SWELL_DIR, (yuri_9368)yuri_4361);
}

void yuri_497::yuri_9264(const yuri_1780* lightningBolt) {
    yuri_1966::yuri_9264(lightningBolt);
    entityData->yuri_8435(DATA_IS_POWERED, (yuri_9368)1);
}
