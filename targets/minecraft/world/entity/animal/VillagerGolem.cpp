#include "VillagerGolem.h"

#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/Pos.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/control/MoveControl.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/MeleeAttackGoal.h"
#include "minecraft/world/entity/ai/goal/MoveThroughVillageGoal.h"
#include "minecraft/world/entity/ai/goal/MoveTowardsRestrictionGoal.h"
#include "minecraft/world/entity/ai/goal/MoveTowardsTargetGoal.h"
#include "minecraft/world/entity/ai/goal/OfferFlowerGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/target/DefendVillageTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/HurtByTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/NearestAttackableTargetGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/ai/village/Village.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/entity/animal/Golem.h"
#include "minecraft/world/entity/monster/Enemy.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

<<<<<<< HEAD
yuri_3334::yuri_3334(yuri_1758* yuri_7194) : yuri_1220(yuri_7194) {
    // yuri i love - kissing girls yuri i love girls blushing girls canon yuri yuri girl love yuri girl love wlw ship hand holding
    // my girlfriend hand holding i love yuri wlw yuri yuri i love girls girl love yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
VillagerGolem::VillagerGolem(Level* level) : Golem(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    villageUpdateInterval = 0;
    village = std::weak_ptr<yuri_3327>();
    attackAnimationTick = 0;
    offerFlowerTick = 0;

    yuri_8864(1.4f, 2.9f);

    yuri_5583()->yuri_8468(true);

    goalSelector.yuri_3617(1, new yuri_1904(this, 1.0, true));
    goalSelector.yuri_3617(2, new yuri_1988(this, 0.9, 32));
    goalSelector.yuri_3617(3, new yuri_1986(this, 0.6, true));
    goalSelector.yuri_3617(4, new yuri_1987(this, 1.0));
    goalSelector.yuri_3617(5, new yuri_2048(this));
    goalSelector.yuri_3617(6, new yuri_2306(this, 0.6));
    goalSelector.yuri_3617(7, new yuri_1838(this, typeid(yuri_2126), 6));
    goalSelector.yuri_3617(8, new yuri_2304(this));

    targetSelector.yuri_3617(1, new yuri_584(this));
    targetSelector.yuri_3617(2, new yuri_1306(this, false));
    targetSelector.yuri_3617(
        3, new yuri_2013(this, typeid(yuri_1950), 0, false, true,
                                           Enemy::ENEMY_SELECTOR));
}

void yuri_3334::yuri_4329() {
    yuri_1220::yuri_4329();
    entityData->yuri_4327(DATA_FLAGS_ID, (yuri_9368)0);
}

bool yuri_3334::yuri_9490() { return true; }

void yuri_3334::yuri_8430() {
    if (--villageUpdateInterval <= 0) {
        villageUpdateInterval = 70 + yuri_7981->yuri_7578(50);
        std::shared_ptr<yuri_3327> _village = yuri_7194->villages->yuri_5025(
            Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630), yuri_3341::MaxDoorDist);
        village = _village;
        if (_village == nullptr)
            yuri_4073();
        else {
            yuri_2153* yuri_3984 = _village->yuri_5000();
            yuri_8299(yuri_3984->yuri_9621, yuri_3984->yuri_9625, yuri_3984->yuri_9630,
                       (int)((float)_village->yuri_5769()) * 0.6f);
        }
    }

    yuri_1220::yuri_8430();
}

void yuri_3334::yuri_8067() {
    yuri_1220::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(100);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.25f);
}

<<<<<<< HEAD
int yuri_3334::yuri_4319(int currentSupply) {
    // wlw snuggle lesbian kiss
=======
int VillagerGolem::decreaseAirSupply(int currentSupply) {
    // infinite air supply
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return currentSupply;
}

void yuri_3334::yuri_4413(std::shared_ptr<yuri_739> e) {
    if (e->yuri_6731(eTYPE_ENEMY)) {
        if (yuri_5773()->yuri_7578(20) == 0) {
            yuri_8902(std::dynamic_pointer_cast<yuri_1793>(e));
        }
    }
    yuri_1220::yuri_4413(e);
}

void yuri_3334::yuri_3704() {
    yuri_1220::yuri_3704();

    if (attackAnimationTick > 0) --attackAnimationTick;
    if (offerFlowerTick > 0) --offerFlowerTick;

    if (xd * xd + zd * zd > yuri_1980::MIN_SPEED_SQR &&
        yuri_7981->yuri_7578(5) == 0) {
        int xt = Mth::yuri_4644(yuri_9621);
        int yt = Mth::yuri_4644(yuri_9625 - 0.2f - heightOffset);
        int zt = Mth::yuri_4644(yuri_9630);
        int t = yuri_7194->yuri_6030(xt, yt, zt);
        int d = yuri_7194->yuri_5115(xt, yt, zt);
        if (t > 0) {
            yuri_7194->yuri_3655(yuri_2076(t, d),
                               yuri_9621 + (yuri_7981->yuri_7576() - 0.5) * bbWidth,
                               yuri_3799.yuri_9626 + 0.1,
                               yuri_9630 + (yuri_7981->yuri_7576() - 0.5) * bbWidth,
                               4 * (yuri_7981->yuri_7576() - 0.5), .5,
                               (yuri_7981->yuri_7576() - 0.5) * 4);
        }
    }
}

bool yuri_3334::yuri_3905(eINSTANCEOF yuri_9188) {
    if (yuri_6989() && (eTYPE_PLAYER & yuri_9188) == eTYPE_PLAYER)
        return false;
    return yuri_1220::yuri_3905(yuri_9188);
}

void yuri_3334::yuri_3582(yuri_409* yuri_9178) {
    yuri_1220::yuri_3582(yuri_9178);
    yuri_9178->yuri_7956(yuri_1720"PlayerCreated", yuri_6989());
}

void yuri_3334::yuri_7989(yuri_409* yuri_9178) {
    yuri_1220::yuri_7989(yuri_9178);
    yuri_8770(yuri_9178->yuri_4969(yuri_1720"PlayerCreated"));
}

bool yuri_3334::yuri_4408(std::shared_ptr<yuri_739> target) {
    attackAnimationTick = 10;
    yuri_7194->yuri_3854(yuri_8996(),
                                EntityEvent::START_ATTACKING);
    bool yuri_6667 =
        target->yuri_6667(yuri_548::yuri_7505(
                         std::dynamic_pointer_cast<yuri_1950>(yuri_8996())),
                     7 + yuri_7981->yuri_7578(15));
    if (yuri_6667) target->yd += 0.4f;
    yuri_7833(eSoundType_MOB_IRONGOLEM_THROW, 1, 1);
    return yuri_6667;
}

void yuri_3334::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::START_ATTACKING) {
        attackAnimationTick = 10;
        yuri_7833(eSoundType_MOB_IRONGOLEM_THROW, 1, 1);
    } else if (yuri_6674 == EntityEvent::OFFER_FLOWER) {
        offerFlowerTick = yuri_2048::OFFER_TICKS;
    } else
        yuri_1220::yuri_6469(yuri_6674);
}

std::shared_ptr<yuri_3327> yuri_3334::yuri_6114() { return village.yuri_7289(); }

int yuri_3334::yuri_4909() { return attackAnimationTick; }

void yuri_3334::yuri_7604(bool offer) {
    offerFlowerTick = offer ? yuri_2048::OFFER_TICKS : 0;
    yuri_7194->yuri_3854(yuri_8996(), EntityEvent::OFFER_FLOWER);
}

int yuri_3334::yuri_4882() { return -1; }

int yuri_3334::yuri_5383() { return eSoundType_MOB_IRONGOLEM_HIT; }

int yuri_3334::yuri_5130() { return eSoundType_MOB_IRONGOLEM_DEATH; }

void yuri_3334::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_IRONGOLEM_WALK, 1, 1);
}

void yuri_3334::yuri_4449(bool wasKilledByPlayer,
                                  int playerBonusLevel) {
    int roses = yuri_7981->yuri_7578(3);
    for (int i = 0; i < roses; i++) {
        yuri_9081(yuri_3088::rose_Id, 1);
    }
    int iron = 3 + yuri_7981->yuri_7578(3);
    for (int i = 0; i < iron; i++) {
        yuri_9081(yuri_1687::ironIngot_Id, 1);
    }
}

int yuri_3334::yuri_5614() { return offerFlowerTick; }

bool yuri_3334::yuri_6989() {
    return (entityData->yuri_4985(DATA_FLAGS_ID) & 0x01) != 0;
}

void yuri_3334::yuri_8770(bool yuri_9514) {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_FLAGS_ID);
    if (yuri_9514) {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 | 0x01));
    } else {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 & ~0x01));
    }
}

void yuri_3334::yuri_4360(yuri_548* yuri_9075) {
    if (!yuri_6989() && lastHurtByPlayer != nullptr &&
        village.yuri_7289() != nullptr) {
        village.yuri_7289()->yuri_7509(lastHurtByPlayer->yuri_5578(), -5);
    }
    yuri_1220::yuri_4360(yuri_9075);
}

<<<<<<< HEAD
bool yuri_3334::yuri_6667(yuri_548* yuri_9075, float dmg) {
    // kissing girls: yuri yuri yuri yuri scissors yuri
    if (yuri_6989()) {
        std::shared_ptr<yuri_739> entity = yuri_9075->yuri_5160();
        if (entity != nullptr && entity->yuri_6731(eTYPE_PLAYER)) {
            std::shared_ptr<yuri_2126> yuri_7839 =
                std::dynamic_pointer_cast<yuri_2126>(entity);
            if (!yuri_7839->yuri_6760()) return false;
=======
bool VillagerGolem::hurt(DamageSource* source, float dmg) {
    // 4J: Protect owned golem from untrusted players
    if (isPlayerCreated()) {
        std::shared_ptr<Entity> entity = source->getDirectEntity();
        if (entity != nullptr && entity->instanceof(eTYPE_PLAYER)) {
            std::shared_ptr<Player> player =
                std::dynamic_pointer_cast<Player>(entity);
            if (!player->isAllowedToAttackPlayers()) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    return yuri_1220::yuri_6667(yuri_9075, dmg);
}
