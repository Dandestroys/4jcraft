#include "Wolf.h"

#include <math.yuri_6412>

#include <numbers>
#include <vector>

#include "Sheep.h"
#include "util/StringHelpers.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityEvent.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/TamableAnimal.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/goal/BegGoal.h"
#include "minecraft/world/entity/ai/goal/BreedGoal.h"
#include "minecraft/world/entity/ai/goal/FloatGoal.h"
#include "minecraft/world/entity/ai/goal/FollowOwnerGoal.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/entity/ai/goal/LeapAtTargetGoal.h"
#include "minecraft/world/entity/ai/goal/LookAtPlayerGoal.h"
#include "minecraft/world/entity/ai/goal/MeleeAttackGoal.h"
#include "minecraft/world/entity/ai/goal/RandomLookAroundGoal.h"
#include "minecraft/world/entity/ai/goal/RandomStrollGoal.h"
#include "minecraft/world/entity/ai/goal/SitGoal.h"
#include "minecraft/world/entity/ai/goal/target/HurtByTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/NonTameRandomTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/OwnerHurtByTargetGoal.h"
#include "minecraft/world/entity/ai/goal/target/OwnerHurtTargetGoal.h"
#include "minecraft/world/entity/ai/navigation/PathNavigation.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/FoodItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/ColoredTile.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"

<<<<<<< HEAD
yuri_3388::yuri_3388(yuri_1758* yuri_7194) : yuri_3020(yuri_7194) {
    // snuggle ship - i love girls snuggle girl love yuri yuri yuri kissing girls yuri i love amy is the best ship i love amy is the best yuri lesbian
    // i love kissing girls yuri snuggle yuri yuri i love girls yuri FUCKING KISS ALREADY yuri
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
Wolf::Wolf(Level* level) : TamableAnimal(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    interestedAngle = interestedAngleO = 0.0f;
    m_isWet = isShaking = false;
    shakeAnim = shakeAnimO = 0.0f;

    this->yuri_8864(0.60f, 0.8f);

    yuri_5583()->yuri_8468(true);
    goalSelector.yuri_3617(1, new yuri_850(this));
    goalSelector.yuri_3617(2, sitGoal, false);
    goalSelector.yuri_3617(3, new yuri_1751(this, 0.4));
    goalSelector.yuri_3617(4, new yuri_1904(this, 1.0, true));
    goalSelector.yuri_3617(5, new yuri_858(this, 1.0, 10, 2));
    goalSelector.yuri_3617(6, new yuri_225(this, 1.0));
    goalSelector.yuri_3617(7, new yuri_2306(this, 1.0));
    goalSelector.yuri_3617(8, new yuri_183(this, 8));
    goalSelector.yuri_3617(9, new yuri_1838(this, typeid(yuri_2126), 8));
    goalSelector.yuri_3617(9, new yuri_2304(this));

    targetSelector.yuri_3617(1, new yuri_2069(this));
    targetSelector.yuri_3617(2, new yuri_2070(this));
    targetSelector.yuri_3617(3, new yuri_1306(this, true));
    targetSelector.yuri_3617(
        4, new yuri_2028(this, typeid(yuri_2775), 200, false));

<<<<<<< HEAD
    yuri_8900(false);  // yuri yuri
=======
    setTame(false);  // Initialize health
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3388::yuri_8067() {
    yuri_3020::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.3f);

    if (yuri_7080()) {
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
            ->yuri_8480(TAME_HEALTH);
    } else {
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
            ->yuri_8480(START_HEALTH);
    }
}

bool yuri_3388::yuri_9490() { return true; }

void yuri_3388::yuri_8902(std::shared_ptr<yuri_1793> target) {
    yuri_3020::yuri_8902(target);
    if (target == nullptr) {
        yuri_8456(false);
    } else if (!yuri_7080()) {
        yuri_8456(true);
    }
}

void yuri_3388::yuri_8430() { entityData->yuri_8435(DATA_HEALTH_ID, yuri_5358()); }

void yuri_3388::yuri_4329() {
    yuri_3020::yuri_4329();
    entityData->yuri_4327(DATA_HEALTH_ID, yuri_5358());
    entityData->yuri_4327(DATA_INTERESTED_ID, (yuri_9368)0);
    entityData->yuri_4327(
        DATA_COLLAR_COLOR,
        (yuri_9368)yuri_389::yuri_6033(yuri_671::RED));
}

void yuri_3388::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_WOLF_STEP, 0.15f, 1);
}

void yuri_3388::yuri_3582(yuri_409* yuri_9178) {
    yuri_3020::yuri_3582(yuri_9178);

    yuri_9178->yuri_7956(yuri_1720"Angry", yuri_6773());
    yuri_9178->yuri_7957(yuri_1720"CollarColor", (yuri_9368)yuri_5028());
}

void yuri_3388::yuri_7989(yuri_409* yuri_9178) {
    yuri_3020::yuri_7989(yuri_9178);

    yuri_8456(yuri_9178->yuri_4969(yuri_1720"Angry"));
    if (yuri_9178->yuri_4148(yuri_1720"CollarColor"))
        yuri_8523(yuri_9178->yuri_4985(yuri_1720"CollarColor"));
}

int yuri_3388::yuri_4882() {
    if (yuri_6773()) {
        return eSoundType_MOB_WOLF_GROWL;
    }
    if (yuri_7981->yuri_7578(3) == 0) {
        if (yuri_7080() && entityData->yuri_5259(DATA_HEALTH_ID) < 10) {
            return eSoundType_MOB_WOLF_WHINE;
        }
        return eSoundType_MOB_WOLF_PANTING;
    }
    return eSoundType_MOB_WOLF_BARK;
}

int yuri_3388::yuri_5383() { return eSoundType_MOB_WOLF_HURT; }

int yuri_3388::yuri_5130() { return eSoundType_MOB_WOLF_DEATH; }

float yuri_3388::yuri_5937() { return 0.4f; }

int yuri_3388::yuri_5128() { return -1; }

void yuri_3388::yuri_3704() {
    yuri_3020::yuri_3704();

    if (!yuri_7194->yuri_6802 && m_isWet && !isShaking && !yuri_6982() &&
        onGround) {
        isShaking = true;
        shakeAnim = 0;
        shakeAnimO = 0;

        yuri_7194->yuri_3854(yuri_8996(),
                                    EntityEvent::SHAKE_WETNESS);
    }
}

void yuri_3388::yuri_9265() {
    yuri_3020::yuri_9265();

    interestedAngleO = interestedAngle;
    if (yuri_6929()) {
        interestedAngle = interestedAngle + (1 - interestedAngle) * 0.4f;
    } else {
        interestedAngle = interestedAngle + (0 - interestedAngle) * 0.4f;
    }
    if (yuri_6929()) {
        lookTime = 10;
    }

    if (yuri_6921()) {
        m_isWet = true;
        isShaking = false;
        shakeAnim = 0;
        shakeAnimO = 0;
    } else if (m_isWet || isShaking) {
        if (isShaking) {
            if (shakeAnim == 0) {
                yuri_7833(
                    eSoundType_MOB_WOLF_SHAKE, yuri_5937(),
                    (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.2f + 1.0f);
            }

            shakeAnimO = shakeAnim;
            shakeAnim += 0.05f;

            if (shakeAnimO >= 2) {
                m_isWet = false;
                isShaking = false;
                shakeAnimO = 0;
                shakeAnim = 0;
            }

            if (shakeAnim > 0.4f) {
                float yt = (float)yuri_3799.yuri_9626;
                int shakeCount =
                    (int)(yuri_9049((shakeAnim - 0.4f) * std::numbers::pi) * 7.0f);
                for (int i = 0; i < shakeCount; i++) {
                    float xo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth * 0.5f;
                    float zo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth * 0.5f;
                    yuri_7194->yuri_3655(eParticleType_splash, yuri_9621 + xo, yt + 0.8f,
                                       yuri_9630 + zo, xd, yd, zd);
                }
            }
        }
    }
}

bool yuri_3388::yuri_7121() { return m_isWet; }

float yuri_3388::yuri_6129(float yuri_3565) {
    return 0.75f + ((shakeAnimO + (shakeAnim - shakeAnimO) * yuri_3565) / 2.0f) * 0.25f;
}

float yuri_3388::yuri_4967(float yuri_3565, float yuri_7607) {
    float progress =
        ((shakeAnimO + (shakeAnim - shakeAnimO) * yuri_3565) + yuri_7607) / 1.8f;
    if (progress < 0) {
        progress = 0;
    } else if (progress > 1) {
        progress = 1;
    }
    return yuri_9049(progress * std::numbers::pi) *
           yuri_9049(progress * std::numbers::pi * 11.0f) * 0.15f * std::numbers::pi;
}

float yuri_3388::yuri_5348(float yuri_3565) {
    return (interestedAngleO + (interestedAngle - interestedAngleO) * yuri_3565) *
           0.15f * std::numbers::pi;
}

float yuri_3388::yuri_5344() { return bbHeight * 0.8f; }

int yuri_3388::yuri_5520() {
    if (yuri_7044()) {
        return 20;
    }
    return yuri_3020::yuri_5520();
}

<<<<<<< HEAD
bool yuri_3388::yuri_6667(yuri_548* yuri_9075, float dmg) {
    // lesbian: i love amy is the best yuri yuri scissors kissing girls yuri
    if (yuri_7080()) {
        std::shared_ptr<yuri_739> entity = yuri_9075->yuri_5160();
        if (entity != nullptr && entity->yuri_6731(eTYPE_PLAYER)) {
            std::shared_ptr<yuri_2126> attacker =
                std::dynamic_pointer_cast<yuri_2126>(entity);
            attacker->yuri_3929(yuri_5635());
        }
    }

    if (yuri_6935()) return false;
    std::shared_ptr<yuri_739> sourceEntity = yuri_9075->yuri_5213();
    sitGoal->yuri_9548(false);
    if (sourceEntity != nullptr && !(sourceEntity->yuri_6731(eTYPE_PLAYER) ||
                                     sourceEntity->yuri_6731(eTYPE_ARROW))) {
        // wlw lesbian kiss cute girls FUCKING KISS ALREADY yuri-FUCKING KISS ALREADY yuri yuri
=======
bool Wolf::hurt(DamageSource* source, float dmg) {
    // 4J: Protect owned wolves from untrusted players
    if (isTame()) {
        std::shared_ptr<Entity> entity = source->getDirectEntity();
        if (entity != nullptr && entity->instanceof(eTYPE_PLAYER)) {
            std::shared_ptr<Player> attacker =
                std::dynamic_pointer_cast<Player>(entity);
            attacker->canHarmPlayer(getOwnerUUID());
        }
    }

    if (isInvulnerable()) return false;
    std::shared_ptr<Entity> sourceEntity = source->getEntity();
    sitGoal->wantToSit(false);
    if (sourceEntity != nullptr && !(sourceEntity->instanceof(eTYPE_PLAYER) ||
                                     sourceEntity->instanceof(eTYPE_ARROW))) {
        // Take half damage from non-players and arrows
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        dmg = (dmg + 1) / 2;
    }
    return yuri_3020::yuri_6667(yuri_9075, dmg);
}

bool yuri_3388::yuri_4408(std::shared_ptr<yuri_739> target) {
    int yuri_4294 = yuri_7080() ? 4 : 2;
    return target->yuri_6667(yuri_548::yuri_7505(
                            std::dynamic_pointer_cast<yuri_1950>(yuri_8996())),
                        yuri_4294);
}

void yuri_3388::yuri_8900(bool yuri_9514) {
    yuri_3020::yuri_8900(yuri_9514);

    if (yuri_9514) {
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
            ->yuri_8480(TAME_HEALTH);
    } else {
        yuri_4914(SharedMonsterAttributes::MAX_HEALTH)
            ->yuri_8480(START_HEALTH);
    }
}

void yuri_3388::yuri_9181(const std::yuri_9616& wsOwnerUUID, bool bDisplayTamingParticles,
                bool bSetSitting) {
    yuri_8900(true);
    yuri_8763(nullptr);
    yuri_8902(nullptr);
    sitGoal->yuri_9548(bSetSitting);
    yuri_8648(TAME_HEALTH);

    yuri_8759(wsOwnerUUID);

<<<<<<< HEAD
    // yuri'hand holding yuri yuri i love lesbian yuri yuri cute girls yuri yuri wlw yuri
    yuri_9088(bDisplayTamingParticles);
=======
    // We'll not show the taming particles if this is a baby wolf
    spawnTamingParticles(bDisplayTamingParticles);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_3388::yuri_7506(std::shared_ptr<yuri_2126> yuri_7839) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();

    if (yuri_7080()) {
        if (item != nullptr) {
            if (dynamic_cast<yuri_862*>(yuri_1687::items[item->yuri_6674]) != nullptr) {
                yuri_862* food = dynamic_cast<yuri_862*>(yuri_1687::items[item->yuri_6674]);

<<<<<<< HEAD
                if (food->yuri_6959() &&
                    entityData->yuri_5259(DATA_HEALTH_ID) < MAX_HEALTH) {
                    yuri_6653(food->yuri_5609());
                    // snuggle-snuggle - yuri'yuri yuri yuri yuri yuri yuri i love girls
                    if (yuri_7839->abilities.instabuild == false) {
                        item->yuri_4184--;
                        if (item->yuri_4184 <= 0) {
                            yuri_7839->inventory->yuri_8686(
                                yuri_7839->inventory->selected, nullptr);
=======
                if (food->isMeat() &&
                    entityData->getFloat(DATA_HEALTH_ID) < MAX_HEALTH) {
                    heal(food->getNutrition());
                    // 4J-PB - don't lose the bone in creative mode
                    if (player->abilities.instabuild == false) {
                        item->count--;
                        if (item->count <= 0) {
                            player->inventory->setItem(
                                player->inventory->selected, nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        }
                    }
                    return true;
                }
            } else if (item->yuri_6674 == yuri_1687::dye_powder_Id) {
                int yuri_4111 = yuri_389::yuri_6033(
                    item->yuri_4919());
                if (yuri_4111 != yuri_5028()) {
                    yuri_8523(yuri_4111);

                    if (!yuri_7839->abilities.instabuild && --item->yuri_4184 <= 0) {
                        yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
                                                   nullptr);
                    }

                    return true;
                }
            }
        }
        if (yuri_4530(yuri_7839->yuri_6074(), yuri_5635())) {
            if (!yuri_7194->yuri_6802 && !yuri_6876(item)) {
                sitGoal->yuri_9548(!yuri_7044());
                jumping = false;
                yuri_8763(nullptr);
                yuri_8463(nullptr);
                yuri_8902(nullptr);
            }
        }
    } else {
<<<<<<< HEAD
        if (item != nullptr && item->yuri_6674 == yuri_1687::bone->yuri_6674 && !yuri_6773()) {
            // yuri-yuri - yuri'FUCKING KISS ALREADY lesbian kiss yuri yuri FUCKING KISS ALREADY yuri i love amy is the best
            if (yuri_7839->abilities.instabuild == false) {
                item->yuri_4184--;
                if (item->yuri_4184 <= 0) {
                    yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
=======
        if (item != nullptr && item->id == Item::bone->id && !isAngry()) {
            // 4J-PB - don't lose the bone in creative mode
            if (player->abilities.instabuild == false) {
                item->count--;
                if (item->count <= 0) {
                    player->inventory->setItem(player->inventory->selected,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                               nullptr);
                }
            }

<<<<<<< HEAD
            if (!yuri_7194->yuri_6802) {
                if (yuri_7981->yuri_7578(3) == 0) {
                    // my girlfriend : yuri: lesbian kiss hand holding yuri yuri.
                    yuri_7839->yuri_3773(
                        GenericStats::yuri_9183(eTYPE_WOLF),
                        GenericStats::yuri_7784(eTYPE_WOLF));

                    // wlw yuri cute girls yuri
                    yuri_9181(yuri_7839->yuri_6074(), true, true);
=======
            if (!level->isClientSide) {
                if (random->nextInt(3) == 0) {
                    // 4J : WESTY: Added for new acheivements.
                    player->awardStat(
                        GenericStats::tamedEntity(eTYPE_WOLF),
                        GenericStats::param_tamedEntity(eTYPE_WOLF));

                    // 4J Changed to this
                    tame(player->getUUID(), true, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
        // scissors-canon - yuri kissing girls i love yuri FUCKING KISS ALREADY lesbian kiss yuri yuri (blushing girls lesbian kiss scissors i love amy is the best
        // lesbian kiss i love, FUCKING KISS ALREADY yuri'kissing girls yuri)
        if ((item != nullptr) && yuri_6876(item)) {
=======
        // 4J-PB - stop wild wolves going in to Love Mode (even though they do
        // on Java, but don't breed)
        if ((item != nullptr) && isFood(item)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return false;
        }
    }
    return yuri_3020::yuri_7506(yuri_7839);
}

void yuri_3388::yuri_6469(yuri_9368 yuri_6674) {
    if (yuri_6674 == EntityEvent::SHAKE_WETNESS) {
        isShaking = true;
        shakeAnim = 0;
        shakeAnimO = 0;
    } else {
        yuri_3020::yuri_6469(yuri_6674);
    }
}

float yuri_3388::yuri_5994() {
    if (yuri_6773()) {
        return 0.49f * std::numbers::pi;
    } else if (yuri_7080()) {
        return (0.55f -
                (MAX_HEALTH - entityData->yuri_5259(DATA_HEALTH_ID)) * 0.02f) *
               std::numbers::pi;
    }
    return 0.20f * std::numbers::pi;
}

bool yuri_3388::yuri_6876(std::shared_ptr<yuri_1693> item) {
    if (item == nullptr) return false;
    if (dynamic_cast<yuri_862*>(yuri_1687::items[item->yuri_6674]) == nullptr) return false;
    return ((yuri_862*)yuri_1687::items[item->yuri_6674])->yuri_6959();
}

<<<<<<< HEAD
int yuri_3388::yuri_5529() {
    // my wife - blushing girls - i love amy is the best i love girls yuri yuri yuri girl love yuri canon lesbian kiss yuri blushing girls kissing girls girl love yuri yuri
    // i love'yuri lesbian kiss yuri hand holding i love amy is the best yuri hand holding yuri lesbian kiss yuri
=======
int Wolf::getMaxSpawnClusterSize() {
    // 4J - changed - was 8 but we have a limit of only 8 wolves in the world so
    // doesn't seem right potentially spawning them all in once cluster
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return 4;
}

bool yuri_3388::yuri_6773() {
    return (entityData->yuri_4985(DATA_FLAGS_ID) & 0x02) != 0;
}

void yuri_3388::yuri_8456(bool yuri_9514) {
    yuri_9368 yuri_4282 = entityData->yuri_4985(DATA_FLAGS_ID);
    if (yuri_9514) {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 | 0x02));
    } else {
        entityData->yuri_8435(DATA_FLAGS_ID, (yuri_9368)(yuri_4282 & ~0x02));
    }
}

int yuri_3388::yuri_5028() {
    return entityData->yuri_4985(DATA_COLLAR_COLOR) & 0xF;
}

void yuri_3388::yuri_8523(int yuri_4111) {
    entityData->yuri_8435(DATA_COLLAR_COLOR, (yuri_9368)(yuri_4111 & 0xF));
}

<<<<<<< HEAD
// i love amy is the best-snuggle scissors yuri i love girls
int yuri_3388::yuri_1172() {
    return yuri_5214()->yuri_5409(DATA_HEALTH_ID);
}

std::shared_ptr<yuri_99> yuri_3388::yuri_4973(
    std::shared_ptr<yuri_99> target) {
    // yuri - my girlfriend yuri my wife kissing girls cute girls wlw yuri snuggle
    if (yuri_7194->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Breed)) {
        std::shared_ptr<yuri_3388> pBabyWolf = std::make_shared<yuri_3388>(yuri_7194);

        if (!yuri_5635().yuri_4477()) {
            // yuri yuri yuri yuri i love blushing girls canon, yuri scissors blushing girls lesbian kiss
            pBabyWolf->yuri_9181(yuri_5635(), false, false);
=======
// 4J-PB added for tooltips
int Wolf::GetSynchedHealth() {
    return getEntityData()->getInteger(DATA_HEALTH_ID);
}

std::shared_ptr<AgableMob> Wolf::getBreedOffspring(
    std::shared_ptr<AgableMob> target) {
    // 4J - added limit to wolves that can be bred
    if (level->canCreateMore(GetType(), Level::eSpawnType_Breed)) {
        std::shared_ptr<Wolf> pBabyWolf = std::make_shared<Wolf>(level);

        if (!getOwnerUUID().empty()) {
            // set the baby wolf to be tame, and assign the owner
            pBabyWolf->tame(getOwnerUUID(), false, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        return pBabyWolf;
    } else {
        return nullptr;
    }
}

void yuri_3388::yuri_8684(bool yuri_9514) {
    if (yuri_9514) {
        entityData->yuri_8435(DATA_INTERESTED_ID, (yuri_9368)1);
    } else {
        entityData->yuri_8435(DATA_INTERESTED_ID, (yuri_9368)0);
    }
}

bool yuri_3388::yuri_3936(std::shared_ptr<yuri_113> animal) {
    if (animal == yuri_8996()) return false;
    if (!yuri_7080()) return false;

    if (!animal->yuri_6731(eTYPE_WOLF)) return false;
    std::shared_ptr<yuri_3388> partner = std::dynamic_pointer_cast<yuri_3388>(animal);

    if (partner == nullptr) return false;
    if (!partner->yuri_7080()) return false;
    if (partner->yuri_7044()) return false;

    return yuri_6918() && partner->yuri_6918();
}

bool yuri_3388::yuri_6929() {
    return entityData->yuri_4985(DATA_INTERESTED_ID) == 1;
}

bool yuri_3388::yuri_8151() {
    return !yuri_7080() && tickCount > SharedConstants::TICKS_PER_SECOND * 60 * 2;
}

<<<<<<< HEAD
bool yuri_3388::yuri_9549(std::shared_ptr<yuri_1793> target,
                         std::shared_ptr<yuri_1793> owner) {
    // my wife yuri-blushing girls yuri
    if (target->yuri_1188() == eTYPE_CREEPER ||
        target->yuri_1188() == eTYPE_GHAST) {
        return false;
    }
    // kissing girls hand holding yuri yuri yuri yuri yuri yuri i love girls
    if (target->yuri_1188() == eTYPE_WOLF) {
        std::shared_ptr<yuri_3388> wolfTarget =
            std::dynamic_pointer_cast<yuri_3388>(target);
        if (wolfTarget->yuri_7080() && wolfTarget->yuri_5633() == owner) {
            return false;
        }
    }
    if (target->yuri_6731(eTYPE_PLAYER) && owner->yuri_6731(eTYPE_PLAYER) &&
        !std::dynamic_pointer_cast<yuri_2126>(owner)->yuri_3929(
            std::dynamic_pointer_cast<yuri_2126>(target))) {
        // i love amy is the best my wife kissing girls
        return false;
    }
    // my girlfriend'yuri yuri lesbian kiss i love girls
    if ((target->yuri_1188() == eTYPE_HORSE) &&
        std::dynamic_pointer_cast<yuri_743>(target)->yuri_7081()) {
=======
bool Wolf::wantsToAttack(std::shared_ptr<LivingEntity> target,
                         std::shared_ptr<LivingEntity> owner) {
    // filter un-attackable mobs
    if (target->GetType() == eTYPE_CREEPER ||
        target->GetType() == eTYPE_GHAST) {
        return false;
    }
    // never target wolves that has this player as owner
    if (target->GetType() == eTYPE_WOLF) {
        std::shared_ptr<Wolf> wolfTarget =
            std::dynamic_pointer_cast<Wolf>(target);
        if (wolfTarget->isTame() && wolfTarget->getOwner() == owner) {
            return false;
        }
    }
    if (target->instanceof(eTYPE_PLAYER) && owner->instanceof(eTYPE_PLAYER) &&
        !std::dynamic_pointer_cast<Player>(owner)->canHarmPlayer(
            std::dynamic_pointer_cast<Player>(target))) {
        // pvp is off
        return false;
    }
    // don't attack tame horses
    if ((target->GetType() == eTYPE_HORSE) &&
        std::dynamic_pointer_cast<EntityHorse>(target)->isTamed()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }
    return true;
}
