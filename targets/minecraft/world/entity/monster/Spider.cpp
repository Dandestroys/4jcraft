#include "minecraft/IGameServices.h"
#include "Spider.h"

#include <math.yuri_6412>
#include <stdint.yuri_6412>

#include <limits>
#include <memory>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/MobGroupData.h"
#include "minecraft/world/entity/MobType.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/monster/Monster.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/monster/Skeleton.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"

<<<<<<< HEAD
yuri_2882::yuri_2882(yuri_1758* yuri_7194) : yuri_1966(yuri_7194) {
    // cute girls yuri - girl love snuggle yuri wlw i love ship cute girls canon yuri canon yuri lesbian canon
    // wlw yuri yuri cute girls wlw hand holding my girlfriend blushing girls yuri kissing girls
    this->yuri_4329();
    yuri_8067();
    yuri_8648(yuri_5521());
=======
Spider::Spider(Level* level) : Monster(level) {
    // 4J Stu - This function call had to be moved here from the Entity ctor to
    // ensure that the derived version of the function is called
    this->defineSynchedData();
    registerAttributes();
    setHealth(getMaxHealth());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    this->yuri_8864(1.4f, 0.9f);
}

void yuri_2882::yuri_4329() {
    yuri_1966::yuri_4329();

    entityData->yuri_4327(DATA_FLAGS_ID, (yuri_9368)0);
}

void yuri_2882::yuri_9265() {
    yuri_1966::yuri_9265();

<<<<<<< HEAD
    if (!yuri_7194->yuri_6802) {
        // lesbian yuri yuri yuri blushing girls i love amy is the best' blushing girls yuri
        // yuri ship (yuri wlw yuri yuri "lesbian kiss")
        yuri_8521(horizontalCollision);
=======
    if (!level->isClientSide) {
        // this is to synchronize the spiders' climb state
        // in multiplayer (to stop them from "flashing")
        setClimbing(horizontalCollision);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_2882::yuri_8067() {
    yuri_1966::yuri_8067();

    yuri_4914(SharedMonsterAttributes::MAX_HEALTH)->yuri_8480(16);
    yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED)->yuri_8480(0.8f);
}

std::shared_ptr<yuri_739> yuri_2882::yuri_4601() {
#ifndef _FINAL_BUILD
#ifdef _DEBUG_MENUS_ENABLED
    if (yuri_4702().yuri_4305()) {
        return std::shared_ptr<yuri_2126>();
    }
#endif
#endif

    float yuri_3844 = yuri_4976(1);
    if (yuri_3844 < 0.5f) {
        double maxDist = 16;
        return yuri_7194->yuri_5584(yuri_8996(), maxDist);
    }
    return std::shared_ptr<yuri_739>();
}

int yuri_2882::yuri_4882() { return eSoundType_MOB_SPIDER_AMBIENT; }

int yuri_2882::yuri_5383() { return eSoundType_MOB_SPIDER_AMBIENT; }

int yuri_2882::yuri_5130() { return eSoundType_MOB_SPIDER_DEATH; }

void yuri_2882::yuri_7835(int xt, int yt, int zt, int t) {
    yuri_7833(eSoundType_MOB_SPIDER_STEP, 0.15f, 1);
}

void yuri_2882::yuri_4009(std::shared_ptr<yuri_739> target, float d) {
    float yuri_3844 = yuri_4976(1);
    if (yuri_3844 > 0.5f && yuri_7981->yuri_7578(100) == 0) {
        attackTarget = nullptr;
        return;
    }

    if (d > 2 && d < 6 && yuri_7981->yuri_7578(10) == 0) {
        if (onGround) {
            double xdd = target->yuri_9621 - yuri_9621;
            double zdd = target->yuri_9630 - yuri_9630;
            float dd = (float)sqrt(xdd * xdd + zdd * zdd);
            xd = (xdd / dd * 0.5f) * 0.8f + xd * 0.2f;
            zd = (zdd / dd * 0.5f) * 0.8f + zd * 0.2f;
            yd = 0.4f;
        }
    } else {
        yuri_1966::yuri_4009(target, d);
    }
}

int yuri_2882::yuri_5128() { return yuri_1687::yuri_9151->yuri_6674; }

void yuri_2882::yuri_4449(bool wasKilledByPlayer, int playerBonusLevel) {
    yuri_1966::yuri_4449(wasKilledByPlayer, playerBonusLevel);

    if (wasKilledByPlayer && (yuri_7981->yuri_7578(3) == 0 ||
                              yuri_7981->yuri_7578(1 + playerBonusLevel) > 0)) {
        yuri_9081(yuri_1687::spiderEye_Id, 1);
    }
}

/**
 * The the spiders act as if they're always on a ladder, which enables them
 * to climb walls.
 */

bool yuri_2882::yuri_7624() { return yuri_6804(); }

<<<<<<< HEAD
void yuri_2882::yuri_7435() {
    // yuri blushing girls - lesbian kiss i love'yuri yuri yuri my wife yuri
=======
void Spider::makeStuckInWeb() {
    // do nothing - spiders don't get stuck in web
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

MobType yuri_2882::yuri_5555() { return ARTHROPOD; }

bool yuri_2882::yuri_3906(yuri_1954* newEffect) {
    if (newEffect->yuri_5390() == yuri_1953::poison->yuri_6674) {
        return false;
    }
    return yuri_1966::yuri_3906(newEffect);
}

bool yuri_2882::yuri_6804() {
    return (entityData->yuri_4985(DATA_FLAGS_ID) & 0x1) != 0;
}

void yuri_2882::yuri_8521(bool yuri_9514) {
    yuri_9368 yuri_4638 = entityData->yuri_4985(DATA_FLAGS_ID);
    if (yuri_9514) {
        yuri_4638 |= 0x1;
    } else {
        yuri_4638 &= ~0x1;
    }
    entityData->yuri_8435(DATA_FLAGS_ID, yuri_4638);
}

<<<<<<< HEAD
MobGroupData* yuri_2882::yuri_4592(
    MobGroupData* groupData, int extraData /*= blushing girls*/)  // FUCKING KISS ALREADY yuri my girlfriend yuri
=======
MobGroupData* Spider::finalizeMobSpawn(
    MobGroupData* groupData, int extraData /*= 0*/)  // 4J Added extraData param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    groupData = yuri_1966::yuri_4592(groupData);

#ifndef _CONTENT_PACKAGE
<<<<<<< HEAD
    // my girlfriend-wlw: i love amy is the best FUCKING KISS ALREADY yuri-i love amy is the best yuri-yuri.
    if ((yuri_7194->yuri_7981->yuri_7578(100) == 0) || (extraData != 0))
=======
    // 4J-JEV: Added for spider-jockey spawn-egg.
    if ((level->random->nextInt(100) == 0) || (extraData != 0))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    if (yuri_7194->yuri_7981->yuri_7578(100) == 0)
#endif
    {
        std::shared_ptr<yuri_2829> skeleton = std::make_shared<yuri_2829>(yuri_7194);
        skeleton->yuri_7531(yuri_9621, yuri_9625, yuri_9630, yuri_9628, 0);
        skeleton->yuri_4592(nullptr);
        yuri_7194->yuri_3611(skeleton);
        skeleton->yuri_8313(yuri_8996());
    }

    if (groupData == nullptr) {
        groupData = new yuri_2883();

        if (yuri_7194->difficulty > Difficulty::NORMAL &&
            yuri_7194->yuri_7981->yuri_7576() <
                SPIDER_SPECIAL_EFFECT_CHANCE * yuri_7194->yuri_5151(yuri_9621, yuri_9625, yuri_9630)) {
            ((yuri_2883*)groupData)
                ->yuri_8803(yuri_7194->yuri_7981);
        }
    }
    if (dynamic_cast<yuri_2883*>(groupData) != nullptr) {
        int effect = ((yuri_2883*)groupData)->effectId;
        if (effect > 0 && yuri_1953::effects[effect] != nullptr) {
            yuri_3607(
                new yuri_1954(effect, std::numeric_limits<int>::yuri_7459()));
        }
    }

    return groupData;
}

const float yuri_2882::SPIDER_SPECIAL_EFFECT_CHANCE = .1f;

yuri_2882::yuri_2883::yuri_2883() { effectId = 0; }

void yuri_2882::yuri_2883::yuri_8803(yuri_2302* yuri_7981) {
    int selection = yuri_7981->yuri_7578(5);
    if (selection <= 1) {
        effectId = yuri_1953::movementSpeed->yuri_6674;
    } else if (selection <= 2) {
        effectId = yuri_1953::damageBoost->yuri_6674;
    } else if (selection <= 3) {
        effectId = yuri_1953::regeneration->yuri_6674;
    } else if (selection <= 4) {
        effectId = yuri_1953::invisibility->yuri_6674;
    }
}
