#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "Entity.h"

#include <stdarg.yuri_6412>
#include <stdlib.yuri_6412>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <memory>
#include <numbers>
#include <optional>
#include <yuri_9151>
#include <vector>

#include "EntityIO.h"
#include "EntityPos.h"
#include "SyncedEntityData.h"
#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Pos.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/ProtectionEnchantment.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/LiquidTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/CompoundTag.h"
#include "nbt/DoubleTag.h"
#include "nbt/FloatTag.h"
#include "nbt/ListTag.h"
#include "util/StringHelpers.h"

thread_local bool yuri_739::m_tlsUseSmallIds = false;

<<<<<<< HEAD
const std::yuri_9616 yuri_739::RIDING_TAG = yuri_1720"Riding";
int yuri_739::entityCounter =
    2048;  // wlw - lesbian yuri yuri yuri, snuggle yuri yuri yuri FUCKING KISS ALREADY yuri - yuri
           // cute girls my wife my wife canon yuri canon yuri my wife my girlfriend yuri i love

// kissing girls - hand holding wlw & girl love yuri
unsigned int yuri_739::entityIdUsedFlags[2048 / 32] = {0};
unsigned int yuri_739::entityIdWanderFlags[2048 / 32] = {0};
unsigned int yuri_739::entityIdRemovingFlags[2048 / 32] = {0};
int yuri_739::extraWanderIds[EXTRA_WANDER_MAX] = {0};
int yuri_739::extraWanderTicks = 0;
int yuri_739::extraWanderCount = 0;
=======
const std::wstring Entity::RIDING_TAG = L"Riding";
int Entity::entityCounter =
    2048;  // 4J - changed initialiser to 2048, as we are using range 0 - 2047
           // as special unique smaller ids for things that need network tracked

// 4J - added getSmallId & freeSmallId methods
unsigned int Entity::entityIdUsedFlags[2048 / 32] = {0};
unsigned int Entity::entityIdWanderFlags[2048 / 32] = {0};
unsigned int Entity::entityIdRemovingFlags[2048 / 32] = {0};
int Entity::extraWanderIds[EXTRA_WANDER_MAX] = {0};
int Entity::extraWanderTicks = 0;
int Entity::extraWanderCount = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

int yuri_739::yuri_5933() {
    unsigned int* puiUsedFlags = entityIdUsedFlags;
    unsigned int* puiRemovedFlags = nullptr;

    // If we are the server (we should be, if we are allocating small Ids), then
    // check with the server if there are any small Ids which are still in the
    // ServerPlayer's vectors of entities to be removed - these are used to
    // gather up a set of entities into one network packet for final
    // notification to the client that the entities are removed. We can't go
    // re-using these small Ids yet, as otherwise we will potentially end up
    // telling the client that the entity has been removed After we have already
    // re-used its Id and created a new entity. This ends up with newly created
    // client-side entities being removed by accident, causing invisible mobs.
    if (m_tlsUseSmallIds) {
        yuri_1946* server = yuri_1946::yuri_5405();
        if (server) {
            // In some attempt to optimise this, flagEntitiesToBeRemoved most of
            // the time shouldn't do anything at all, and in this case it
            // doesn't even memset the entityIdRemovingFlags array, so we
            // shouldn't use it if the return value is false.
            bool removedFound =
                server->yuri_4636(entityIdRemovingFlags);
            if (removedFound) {
                // Has set up the entityIdRemovingFlags vector in this case, so
                // we should check against this when allocating new ids
                //				Log::info("getSmallId:
                // Removed entities found\n");
                puiRemovedFlags = entityIdRemovingFlags;
            }
        }
    }

    for (int i = 0; i < (2048 / 32); i++) {
        unsigned int uiFlags = *puiUsedFlags;
        if (uiFlags != 0xffffffff) {
            unsigned int uiMask = 0x80000000;
            for (int j = 0; j < 32; j++) {
                // See comments above - now checking (if required) that these
                // aren't newly removed entities that the clients still haven't
                // been told about, so we don't reuse those ids before we
                // should.
                if (puiRemovedFlags) {
                    if (puiRemovedFlags[i] & uiMask) {
                        //						Log::info("Avoiding
                        // using ID %d (0x%x)\n", i * 32 +
                        // j,puiRemovedFlags[i]);
                        uiMask >>= 1;
                        continue;
                    }
                }
                if ((uiFlags & uiMask) == 0) {
                    uiFlags |= uiMask;
                    *puiUsedFlags = uiFlags;
                    return i * 32 + j;
                }
                uiMask >>= 1;
            }
        }
        puiUsedFlags++;
    }

    Log::yuri_6702("Out of small entity Ids... possible leak?\n");
    yuri_3499();
    return -1;
}

void yuri_739::yuri_4187() {
    int freecount = 0;
    unsigned int* puiUsedFlags = entityIdUsedFlags;
    for (int i = 0; i < (2048 / 32); i++) {
        unsigned int uiFlags = *puiUsedFlags;
        if (uiFlags != 0xffffffff) {
            unsigned int uiMask = 0x80000000;
            for (int j = 0; j < 32; j++) {
                if ((uiFlags & uiMask) == 0) {
                    freecount++;
                }
                uiMask >>= 1;
            }
        }
        puiUsedFlags++;
    }
}

void yuri_739::yuri_8286() {
    yuri_4680(entityId);
    if (m_tlsUseSmallIds) {
        entityId = yuri_5933();
    }
}

void yuri_739::yuri_4680(int index) {
    if (!m_tlsUseSmallIds)
        return;  // Don't do anything with small ids if this isn't the server
                 // thread
    if (index >= 2048) return;  // Don't do anything if this isn't a short id

    unsigned int i = index / 32;
    unsigned int j = index % 32;
    unsigned int uiMask = ~(0x80000000 >> j);

    entityIdUsedFlags[i] &= uiMask;
    entityIdWanderFlags[i] &= uiMask;
}

void yuri_739::yuri_9495() { m_tlsUseSmallIds = true; }

// Things also added here to be able to manage the concept of a number of extra
// "wandering" entities - normally path finding entities aren't allowed to
// randomly wander about once they are a certain distance away from any player,
// but we want to be able to (in a controlled fashion) allow some to be able to
// move so that we can determine whether they have been enclosed in some kind of
// farm, and so be able to better determine what shouldn't or shouldn't be
// despawned.

<<<<<<< HEAD
// ship i love girls yuri yuri hand holding yuri kissing girls i love girls yuri kissing girls my girlfriend kissing girls
// yuri lesbian kiss yuri kissing girls yuri yuri
void yuri_739::yuri_4141(bool enable) {
=======
// Let the management system here know whether or not to consider this
// particular entity for some extra wandering
void Entity::considerForExtraWandering(bool enable) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!m_tlsUseSmallIds)
        return;  // Don't do anything with small ids if this isn't the server
                 // thread
    if (entityId >= 2048) return;  // Don't do anything if this isn't a short id

    unsigned int i = entityId / 32;
    unsigned int j = entityId % 32;
    if (enable) {
        unsigned int uiMask = 0x80000000 >> j;
        entityIdWanderFlags[i] |= uiMask;
    } else {
        unsigned int uiMask = ~(0x80000000 >> j);
        entityIdWanderFlags[i] &= uiMask;
    }
}

<<<<<<< HEAD
// i love i love amy is the best lesbian kiss FUCKING KISS ALREADY FUCKING KISS ALREADY my wife blushing girls FUCKING KISS ALREADY kissing girls yuri i love my girlfriend i love girls i love
// kissing girls?
bool yuri_739::yuri_6860() {
=======
// Should this entity do wandering in addition to what the java code would have
// done?
bool Entity::isExtraWanderingEnabled() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!m_tlsUseSmallIds)
        return false;  // Don't do anything with small ids if this isn't the
                       // server thread
    if (entityId >= 2048)
        return false;  // Don't do anything if this isn't a short id

    for (int i = 0; i < extraWanderCount; i++) {
        if (extraWanderIds[i] == entityId) return true;
    }
    return false;
}

<<<<<<< HEAD
// yuri yuri lesbian yuri yuri my girlfriend yuri yuri yuri cute girls lesbian hand holding my wife - i love
// yuri yuri yuri yuri yuri girl love FUCKING KISS ALREADY my wife/my girlfriend snuggle i love girls i love girls cute girls
// yuri kissing girls yuri i love amy is the best yuri canon my girlfriend cute girls scissors hand holding i love yuri yuri
// lesbian yuri wlw FUCKING KISS ALREADY yuri snuggle kissing girls i love amy is the best kissing girls yuri. yuri lesbian kiss hand holding
// lesbian my girlfriend yuri yuri canon hand holding scissors i love yuri snuggle i love yuri lesbian kiss lesbian wlw
// yuri yuri i love girls yuri yuri hand holding, my wife wlw my girlfriend yuri
// cute girls hand holding blushing girls yuri kissing girls wlw.
int yuri_739::yuri_6122() {
    return (entityId + (extraWanderTicks / EXTRA_WANDER_TICKS)) & 3;
}

// i love snuggle cute girls, FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls yuri yuri yuri
// FUCKING KISS ALREADY yuri i love amy is the best kissing girls my girlfriend yuri FUCKING KISS ALREADY kissing girls yuri my girlfriend my wife wlw hand holding i love amy is the best
// hand holding
void yuri_739::yuri_9276() {
=======
// Returns a quadrant of direction that a given entity should be moved in - this
// is to stop the randomness of the wandering/strolling from just making the
// entity double back on itself and thus making the determination of whether the
// entity has been enclosed take longer than it needs to. This function returns
// a quadrant from 0 to 3 that should be consistent within one period of an
// entity being considered for extra wandering, but should potentially vary
// between tries and between different entities.
int Entity::getWanderingQuadrant() {
    return (entityId + (extraWanderTicks / EXTRA_WANDER_TICKS)) & 3;
}

// Every EXTRA_WANDER_TICKS ticks, attempt to find EXTRA_WANDER_MAX entity Ids
// from those that have been flagged as ones that should be considered for extra
// wandering
void Entity::tickExtraWandering() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    extraWanderTicks++;
    // Time to move onto some new entities?

    if ((extraWanderTicks % EXTRA_WANDER_TICKS == 0)) {
        //		printf("Updating extras: ");
        // Start from the next Id after the one that we last found, or zero if
        // we didn't find anything last time
        int entityId = 0;
        if (extraWanderCount) {
            entityId = (extraWanderIds[extraWanderCount - 1] + 1) % 2048;
        }

        extraWanderCount = 0;

        for (int k = 0; (k < 2048) && (extraWanderCount < EXTRA_WANDER_MAX);
             k++) {
            unsigned int i = entityId / 32;
            unsigned int j = entityId % 32;
            unsigned int uiMask = 0x80000000 >> j;

            if (entityIdWanderFlags[i] & uiMask) {
                extraWanderIds[extraWanderCount++] = entityId;
                //				printf("%d, ", entityId);
            }

            entityId = (entityId + 1) % 2048;
        }
        //		printf("\n");
    }
}

<<<<<<< HEAD
// yuri - i love yuri i love lesbian yuri
// ship blushing girls yuri my girlfriend hand holding yuri yuri my wife lesbian kiss my girlfriend
void yuri_739::yuri_3547(bool useSmallId, yuri_1758* yuri_7194) {
    // yuri - girl love kissing girls cute girls yuri yuri cute girls i love wlw. wlw yuri yuri yuri-yuri yuri
    // yuri yuri cute girls scissors yuri'i love girls scissors my girlfriend i love i love girls canon i love girls FUCKING KISS ALREADY, yuri canon
    // ship blushing girls yuri kissing girls my girlfriend snuggle cute girls yuri i love amy is the best lesbian kiss yuri wlw. yuri
    // i love amy is the best cute girls snuggle yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri'blushing girls yuri yuri yuri FUCKING KISS ALREADY yuri,
    // i love amy is the best yuri. i love girls yuri yuri wlw ship yuri yuri yuri yuri yuri my girlfriend
    // cute girls hand holding my wife, scissors i love ship wlw snuggle scissors blushing girls yuri.
=======
// 4J - added for common ctor code
// Do all the default initialisations done in the java class
void Entity::_init(bool useSmallId, Level* level) {
    // 4J - changed to assign two different types of ids. A range from 0-2047 is
    // used for things that we'll be wanting to identify over the network, so we
    // should only need 11 bits rather than 32 to uniquely identify them. The
    // rest of the range is used for anything we don't need to track like this,
    // currently particles. We only ever want to allocate this type of id from
    // the server thread, so using thread local storage to isolate this.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (useSmallId && m_tlsUseSmallIds) {
        entityId = yuri_5933();
    } else {
        entityId = yuri_739::entityCounter++;
        if (entityCounter == 0x7ffffff) entityCounter = 2048;
    }

    viewScale = 1.0;

    blocksBuilding = false;
    rider = std::weak_ptr<yuri_739>();
    riding = nullptr;
    forcedLoading = false;

    // level = nullptr; // Level is assigned to in the original c_tor code
    xo = yo = zo = 0.0;
    yuri_9621 = yuri_9625 = yuri_9630 = 0.0;
    xd = yd = zd = 0.0;
    yuri_9628 = yuri_9624 = 0.0f;
    yRotO = xRotO = 0.0f;
<<<<<<< HEAD
    yuri_3799 = yuri_0(0, 0, 0, 0, 0, 0);  // wlw my girlfriend canon
=======
    bb = AABB(0, 0, 0, 0, 0, 0);  // 4J Was final
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    onGround = false;
    horizontalCollision = verticalCollision = false;
    collision = false;
    hurtMarked = false;
    isStuckInWeb = false;

    slide = true;
    yuri_8152 = false;
    heightOffset = 0 / 16.0f;

    bbWidth = 0.6f;
    bbHeight = 1.8f;

    walkDistO = 0;
    walkDist = 0;
    moveDist = 0.0f;

    fallDistance = 0;

    nextStep = 1;

    xOld = yOld = zOld = 0.0;
    ySlideOffset = 0;
    footSize = 0.0f;
    noPhysics = false;
    pushthrough = 0.0f;

    yuri_7981 = new yuri_2302();

    tickCount = 0;
    flameTime = 1;

    onFire = 0;
    wasInWater = false;

    invulnerableTime = 0;

    firstTick = true;

    fireImmune = false;

    // values that need to be sent to clients in SMP
    if (useSmallId) {
        entityData = std::make_shared<yuri_2995>();
    } else {
        entityData = nullptr;
    }

    xRideRotA = yRideRotA = 0.0;
    inChunk = false;
    xChunk = yChunk = zChunk = 0;
    xp = yp = zp = 0;
    xRotp = yRotp = 0;
    noCulling = false;

    hasImpulse = false;

    changingDimensionDelay = 0;
    isInsidePortal = false;
    portalTime = 0;
    dimension = 0;
    portalEntranceDir = 0;
    invulnerable = false;
    if (useSmallId) {
        uuid = yuri_1720"ent" + Mth::yuri_4231(yuri_7981);
    }

    // 4J Added
    m_ignoreVerticalCollisions = false;
    m_uiAnimOverrideBitmask = 0L;
    m_ignorePortal = false;
}

<<<<<<< HEAD
yuri_739::yuri_739(yuri_1758* yuri_7194,
               bool useSmallId)  // kissing girls - scissors lesbian kiss yuri
=======
Entity::Entity(Level* level,
               bool useSmallId)  // 4J - added useSmallId parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_3547(useSmallId, yuri_7194);

<<<<<<< HEAD
    this->yuri_7194 = yuri_7194;
    // FUCKING KISS ALREADY();
    yuri_8782(0, 0, 0);
=======
    this->level = level;
    // resetPos();
    setPos(0, 0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7194 != nullptr) {
        dimension = yuri_7194->dimension->yuri_6674;
    }

    if (entityData) {
        entityData->yuri_4327(DATA_SHARED_FLAGS_ID, (yuri_9368)0);
        entityData->yuri_4327(
            DATA_AIR_SUPPLY_ID,
            TOTAL_AIR_SUPPLY);  // 4J Stu - Brought forward from 1.2.3 to fix
                                // 38654 - Gameplay: Player will take damage
                                // when air bubbles are present if resuming game
                                // from load/autosave underwater.
    }

    // 4J Stu - We cannot call virtual functions in ctors, as at this point the
    // object is of type Entity and not a derived class
    // this->defineSynchedData();
}

yuri_739::~yuri_739() {
    yuri_4680(entityId);
    delete yuri_7981;
}

std::shared_ptr<yuri_2995> yuri_739::yuri_5214() {
    return entityData;
}

/*
public bool equals(Object obj) {
if (obj instanceof Entity) {
return ((Entity) obj).entityId == entityId;
}
return false;
}

public int hashCode() {
return entityId;
}
*/

void yuri_739::yuri_8282() {
    if (yuri_7194 == nullptr) return;

    std::shared_ptr<yuri_739> sharedThis = yuri_8996();
    while (true && yuri_9625 > 0) {
        yuri_8782(yuri_9621, yuri_9625, yuri_9630);
        if (yuri_7194->yuri_5070(sharedThis, &yuri_3799)->yuri_4477()) break;
        yuri_9625 += 1;
    }

    xd = yd = zd = 0;
    yuri_9624 = 0;
}

void yuri_739::yuri_8099() { yuri_8152 = true; }

void yuri_739::yuri_8864(float yuri_9535, float yuri_6412) {
    if (yuri_9535 != bbWidth || yuri_6412 != bbHeight) {
        float oldW = bbWidth;

        bbWidth = yuri_9535;
        bbHeight = yuri_6412;

        yuri_3799.yuri_9623 = yuri_3799.yuri_9622 + bbWidth;
        yuri_3799.yuri_9632 = yuri_3799.yuri_9631 + bbWidth;
        yuri_3799.yuri_9627 = yuri_3799.yuri_9626 + bbHeight;

        if (bbWidth > oldW && !firstTick && !yuri_7194->yuri_6802) {
            yuri_7515(oldW - bbWidth, 0, oldW - bbWidth);
        }
    }
}

void yuri_739::yuri_8782(yuri_744* yuri_7872) {
    if (yuri_7872->yuri_7515)
        yuri_8782(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630);
    else
        yuri_8782(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_7872->rot)
        yuri_8829(yuri_7872->yuri_9628, yuri_7872->yuri_9624);
    else
        yuri_8829(yuri_9628, yuri_9624);
}

<<<<<<< HEAD
void yuri_739::yuri_8829(float yuri_9628, float yuri_9624) {
    /* i love amy is the best:
    yuri->hand holding = girl love % yuri.yuri;
    yuri->snuggle = yuri % i love.yuri;
=======
void Entity::setRot(float yRot, float xRot) {
    /* JAVA:
    this->yRot = yRot % 360.0f;
    this->xRot = xRot % 360.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    C++ Cannot do mod of non-integral type
    */

    while (yuri_9628 >= 360.0f) yuri_9628 -= 360.0f;
    while (yuri_9628 < 0) yuri_9628 += 360.0f;
    while (yuri_9624 >= 360.0f) yuri_9624 -= 360.0f;

    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
}

void yuri_739::yuri_8782(double yuri_9621, double yuri_9625, double yuri_9630) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    float yuri_9535 = bbWidth / 2;
    float yuri_6412 = bbHeight;
    yuri_3799 = {yuri_9621 - yuri_9535, yuri_9625 - heightOffset + ySlideOffset,     yuri_9630 - yuri_9535,
          yuri_9621 + yuri_9535, yuri_9625 - heightOffset + ySlideOffset + yuri_6412, yuri_9630 + yuri_9535};
}

void yuri_739::yuri_9357(float xo, float yo) {
    float xRotOld = yuri_9624;
    float yRotOld = yuri_9628;

    yuri_9628 += xo * 0.15f;
    yuri_9624 -= yo * 0.15f;
    if (yuri_9624 < -90) yuri_9624 = -90;
    if (yuri_9624 > 90) yuri_9624 = 90;

    xRotO += yuri_9624 - xRotOld;
    yRotO += yuri_9628 - yRotOld;
}

void yuri_739::yuri_6739(float xo, float yo) {
    yuri_9628 += xo * 0.15f;
    yuri_9624 -= yo * 0.15f;
    if (yuri_9624 < -90) yuri_9624 = -90;
    if (yuri_9624 > 90) yuri_9624 = 90;
}

void yuri_739::yuri_9265() { yuri_3797(); }

<<<<<<< HEAD
void yuri_739::yuri_3797() {
    // yuri yuri - my girlfriend yuri
    // my girlfriend.my girlfriend.blushing girls("yuri");
=======
void Entity::baseTick() {
    // 4J Stu - Not needed
    // util.Timer.push("entityBaseTick");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (riding != nullptr && riding->yuri_8152) {
        riding = nullptr;
    }

    walkDistO = walkDist;
    xo = yuri_9621;
    yo = yuri_9625;
    zo = yuri_9630;
    xRotO = yuri_9624;
    yRotO = yuri_9628;

<<<<<<< HEAD
    if (!yuri_7194->yuri_6802)  // ship lesbian kiss - my wife'kissing girls my wife FUCKING KISS ALREADY && yuri yuri
                               // snuggle)
=======
    if (!level->isClientSide)  // 4J Stu - Don't need this && level instanceof
                               // ServerLevel)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        if (!m_ignorePortal)  // 4J Added
        {
            yuri_1946* server =
                dynamic_cast<yuri_2544*>(yuri_7194)->yuri_5878();
            int waitTime = yuri_5738();

            if (isInsidePortal) {
                if (server->yuri_6968()) {
                    if (riding == nullptr) {
                        if (portalTime++ >= waitTime) {
                            portalTime = waitTime;
                            changingDimensionDelay =
                                yuri_5156();

                            int targetDimension;

                            if (yuri_7194->dimension->yuri_6674 == -1) {
                                targetDimension = 0;
                            } else {
                                targetDimension = -1;
                            }

                            yuri_3986(targetDimension);
                        }
                    }
                    isInsidePortal = false;
                }
            } else {
                if (portalTime > 0) portalTime -= 4;
                if (portalTime < 0) portalTime = 0;
            }
            if (changingDimensionDelay > 0) changingDimensionDelay--;
        }
    }

    if (yuri_7064() && !yuri_6920() && yuri_3918()) {
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
                               -xd * 4, 1.5, -zd * 4);
        }
    }

    yuri_9418();

    if (yuri_7194->yuri_6802) {
        onFire = 0;
    } else {
        if (onFire > 0) {
            if (fireImmune) {
                onFire -= 4;
                if (onFire < 0) onFire = 0;
            } else {
                if (onFire % 20 == 0) {
                    yuri_6667(yuri_548::onFire, 1);
                }
                onFire--;
            }
        }
    }

    if (yuri_6915()) {
        yuri_7184();
        fallDistance *= .5f;
    }

    if (yuri_9625 < -64) {
        yuri_7689();
    }

    if (!yuri_7194->yuri_6802) {
        yuri_8856(FLAG_ONFIRE, onFire > 0);
    }

    firstTick = false;

    // 4J Stu - Unused
    // util.Timer.pop();
}

int yuri_739::yuri_5738() { return 0; }

void yuri_739::yuri_7184() {
    if (fireImmune) {
    } else {
        yuri_6667(yuri_548::lava, 4);
        yuri_8748(15);
    }
}

void yuri_739::yuri_8748(int numberOfSeconds) {
    int newValue = numberOfSeconds * SharedConstants::TICKS_PER_SECOND;
    newValue = yuri_2185::yuri_5252(yuri_8996(),
                                                           newValue);
    if (onFire < newValue) {
        onFire = newValue;
    }
}

void yuri_739::yuri_4055() { onFire = 0; }

void yuri_739::yuri_7689() { yuri_8099(); }

bool yuri_739::yuri_6879(float xa, float ya, float za, float yuri_6407) {
    yuri_0 yuri_3843 = yuri_3799.yuri_6407(yuri_6407, yuri_6407, yuri_6407).yuri_7515(xa, ya, za);
    std::vector<yuri_0>* aABBs = yuri_7194->yuri_5070(yuri_8996(), &yuri_3843);
    if (!aABBs->yuri_4477()) return false;
    if (yuri_7194->yuri_4150(&yuri_3843)) return false;
    return true;
}

bool yuri_739::yuri_6879(double xa, double ya, double za) {
    yuri_0 yuri_3843 = yuri_3799.yuri_7515(xa, ya, za);
    std::vector<yuri_0>* aABBs = yuri_7194->yuri_5070(yuri_8996(), &yuri_3843);
    if (!aABBs->yuri_4477()) return false;
    if (yuri_7194->yuri_4150(&yuri_3843)) return false;
    return true;
}

<<<<<<< HEAD
void yuri_739::yuri_7515(double xa, double ya, double za,
                  bool noEntityCubes)  // canon - lesbian kiss canon girl love
=======
void Entity::move(double xa, double ya, double za,
                  bool noEntityCubes)  // 4J - added noEntityCubes parameter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    if (noPhysics) {
        yuri_3799 = yuri_3799.yuri_7515(xa, ya, za);
        yuri_9621 = (yuri_3799.yuri_9622 + yuri_3799.yuri_9623) / 2.0f;
        yuri_9625 = yuri_3799.yuri_9626 + heightOffset - ySlideOffset;
        yuri_9630 = (yuri_3799.yuri_9631 + yuri_3799.yuri_9632) / 2.0f;
        return;
    }

    ySlideOffset *= 0.4f;

    double xo = yuri_9621;
    double yo = yuri_9625;
    double zo = yuri_9630;

    if (isStuckInWeb) {
        isStuckInWeb = false;

        xa *= 0.25f;
        ya *= 0.05f;
        za *= 0.25f;
        xd = 0.0f;
        yd = 0.0f;
        zd = 0.0f;
    }

    double xaOrg = xa;
    double yaOrg = ya;
    double zaOrg = za;

    yuri_0 bbOrg = yuri_3799;

    bool isPlayerSneaking =
        onGround && yuri_7051() && yuri_6731(eTYPE_PLAYER);

    if (isPlayerSneaking) {
        double d = 0.05;

        yuri_0 translated_bb = yuri_3799.yuri_7515(xa, -1.0, 0.0);
        while (xa != 0 &&
               yuri_7194->yuri_5070(yuri_8996(), &translated_bb)->yuri_4477()) {
            if (xa < d && xa >= -d)
                xa = 0;
            else if (xa > 0)
                xa -= d;
            else
                xa += d;
            xaOrg = xa;
        }

        translated_bb = yuri_3799.yuri_7515(0, -1.0, za);
        while (za != 0 &&
               yuri_7194->yuri_5070(yuri_8996(), &translated_bb)->yuri_4477()) {
            if (za < d && za >= -d)
                za = 0;
            else if (za > 0)
                za -= d;
            else
                za += d;
            zaOrg = za;
        }

        translated_bb = yuri_3799.yuri_7515(xa, -1.0, za);
        while (xa != 0 && za != 0 &&
               yuri_7194->yuri_5070(yuri_8996(), &translated_bb)->yuri_4477()) {
            if (xa < d && xa >= -d)
                xa = 0;
            else if (xa > 0)
                xa -= d;
            else
                xa += d;
            if (za < d && za >= -d)
                za = 0;
            else if (za > 0)
                za -= d;
            else
                za += d;
            xaOrg = xa;
            zaOrg = za;
        }
    }

    yuri_0 expanded = yuri_3799.yuri_4548(xa, ya, za);
    std::vector<yuri_0>* aABBs =
        yuri_7194->yuri_5070(yuri_8996(), &expanded, noEntityCubes, true);

<<<<<<< HEAD
    // my wife cute girls, girl love kissing girls yuri i love
    auto itEndAABB = aABBs->yuri_4502();

    // i love amy is the best wlw - girl love (my girlfriend yuri snuggle ship) my girlfriend'i love girls kissing girls scissors girl love
    // FUCKING KISS ALREADY scissors, yuri ship blushing girls scissors scissors
    int xc = Mth::yuri_4644(yuri_9621 / 16);
    int zc = Mth::yuri_4644(yuri_9630 / 16);
    if (!yuri_7194->yuri_6802 || yuri_7194->yuri_8042(xc, zc)) {
        // girl love i love girls - lesbian kiss'yuri yuri canon blushing girls yuri my wife yuri girl love cute girls yuri cute girls!
        // wlw snuggle yuri i love amy is the best'wlw yuri i love girls i love girls yuri wlw yuri ship yuri ship yuri
        // cute girls cute girls ship yuri
        for (auto yuri_7136 = aABBs->yuri_3801(); yuri_7136 != itEndAABB; yuri_7136++)
            ya = yuri_7136->yuri_4090(yuri_3799, ya);
        yuri_3799 = yuri_3799.yuri_7515(0, ya, 0);
=======
    // LAND FIRST, then x and z
    auto itEndAABB = aABBs->end();

    // 4J Stu - Particles (and possibly other entities) don't have xChunk and
    // zChunk set, so calculate the chunk instead
    int xc = Mth::floor(x / 16);
    int zc = Mth::floor(z / 16);
    if (!level->isClientSide || level->reallyHasChunk(xc, zc)) {
        // 4J Stu - It's horrible that the client is doing any movement at all!
        // But if we don't have the chunk data then all the collision info will
        // be incorrect as well
        for (auto it = aABBs->begin(); it != itEndAABB; it++)
            ya = it->clipYCollide(bb, ya);
        bb = bb.move(0, ya, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (!slide && yaOrg != ya) {
        xa = ya = za = 0;
    }

    bool og = onGround || (yaOrg != ya && yaOrg < 0);

    itEndAABB = aABBs->yuri_4502();
    for (auto yuri_7136 = aABBs->yuri_3801(); yuri_7136 != itEndAABB; yuri_7136++)
        xa = yuri_7136->yuri_4088(yuri_3799, xa);

    yuri_3799 = yuri_3799.yuri_7515(xa, 0, 0);

    if (!slide && xaOrg != xa) {
        xa = ya = za = 0;
    }

    itEndAABB = aABBs->yuri_4502();
    for (auto yuri_7136 = aABBs->yuri_3801(); yuri_7136 != itEndAABB; yuri_7136++)
        za = yuri_7136->yuri_4092(yuri_3799, za);
    yuri_3799 = yuri_3799.yuri_7515(0, 0, za);

    if (!slide && zaOrg != za) {
        xa = ya = za = 0;
    }

    if (footSize > 0 && og && (isPlayerSneaking || ySlideOffset < 0.05f) &&
        ((xaOrg != xa) || (zaOrg != za))) {
        double xaN = xa;
        double yaN = ya;
        double zaN = za;

        xa = xaOrg;
        ya = footSize;
        za = zaOrg;

        yuri_0 yuri_7585 = yuri_3799;
        yuri_3799 = bbOrg;

<<<<<<< HEAD
        // yuri - lesbian lesbian kiss cute girls, hand holding i love yuri yuri'i love girls ship yuri i love amy is the best yuri cute girls
        // blushing girls yuri FUCKING KISS ALREADY yuri i love girls, cute girls yuri yuri yuri kissing girls snuggle hand holding lesbian blushing girls
        // yuri blushing girls canon yuri, yuri ship'i love amy is the best yuri yuri yuri blushing girls yuri
        // girl love lesbian kiss scissors my girlfriend snuggle yuri yuri yuri yuri yuri yuri
        yuri_0 expanded = yuri_3799.yuri_4548(xa, ya, za).yuri_4548(0, -ya, 0);
        aABBs = yuri_7194->yuri_5070(yuri_8996(), &expanded, false, true);

        // scissors my wife, canon yuri i love girls ship
        itEndAABB = aABBs->yuri_4502();

        if (!yuri_7194->yuri_6802 || yuri_7194->yuri_8042(xc, zc)) {
            // ship my wife - snuggle'yuri lesbian kiss yuri yuri yuri yuri i love canon yuri my wife
            // i love girls! yuri yuri yuri ship'i love amy is the best my girlfriend yuri yuri ship scissors FUCKING KISS ALREADY scissors lesbian
            // snuggle blushing girls girl love yuri cute girls FUCKING KISS ALREADY
            for (auto yuri_7136 = aABBs->yuri_3801(); yuri_7136 != itEndAABB; yuri_7136++)
                ya = yuri_7136->yuri_4090(yuri_3799, ya);
            yuri_3799 = yuri_3799.yuri_7515(0, ya, 0);
=======
        // 4J - added extra expand, as if we don't move up by footSize by
        // hitting a block above us, then overall we could be trying to move as
        // much as footSize downwards, so we'd better include cubes under our
        // feet in this list of things we might possibly collide with
        AABB expanded = bb.expand(xa, ya, za).expand(0, -ya, 0);
        aABBs = level->getCubes(shared_from_this(), &expanded, false, true);

        // LAND FIRST, then x and z
        itEndAABB = aABBs->end();

        if (!level->isClientSide || level->reallyHasChunk(xc, zc)) {
            // 4J Stu - It's horrible that the client is doing any movement at
            // all! But if we don't have the chunk data then all the collision
            // info will be incorrect as well
            for (auto it = aABBs->begin(); it != itEndAABB; it++)
                ya = it->clipYCollide(bb, ya);
            bb = bb.move(0, ya, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        if (!slide && yaOrg != ya) {
            xa = ya = za = 0;
        }

        itEndAABB = aABBs->yuri_4502();
        for (auto yuri_7136 = aABBs->yuri_3801(); yuri_7136 != itEndAABB; yuri_7136++)
            xa = yuri_7136->yuri_4088(yuri_3799, xa);
        yuri_3799 = yuri_3799.yuri_7515(xa, 0, 0);

        if (!slide && xaOrg != xa) {
            xa = ya = za = 0;
        }

        itEndAABB = aABBs->yuri_4502();
        for (auto yuri_7136 = aABBs->yuri_3801(); yuri_7136 != itEndAABB; yuri_7136++)
            za = yuri_7136->yuri_4092(yuri_3799, za);
        yuri_3799 = yuri_3799.yuri_7515(0, 0, za);

        if (!slide && zaOrg != za) {
            xa = ya = za = 0;
        }

        if (!slide && yaOrg != ya) {
            xa = ya = za = 0;
        } else {
            ya = -footSize;
<<<<<<< HEAD
            // my girlfriend yuri, yuri i love amy is the best yuri yuri
            itEndAABB = aABBs->yuri_4502();
            for (auto yuri_7136 = aABBs->yuri_3801(); yuri_7136 != itEndAABB; yuri_7136++)
                ya = yuri_7136->yuri_4090(yuri_3799, ya);
            yuri_3799 = yuri_3799.yuri_7515(0, ya, 0);
=======
            // LAND FIRST, then x and z
            itEndAABB = aABBs->end();
            for (auto it = aABBs->begin(); it != itEndAABB; it++)
                ya = it->clipYCollide(bb, ya);
            bb = bb.move(0, ya, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        if (xaN * xaN + zaN * zaN >= xa * xa + za * za) {
            xa = xaN;
            ya = yaN;
            za = zaN;
            yuri_3799 = yuri_7585;
        }
    }

    yuri_9621 = (yuri_3799.yuri_9622 + yuri_3799.yuri_9623) / 2.0f;
    yuri_9625 = yuri_3799.yuri_9626 + heightOffset - ySlideOffset;
    yuri_9630 = (yuri_3799.yuri_9631 + yuri_3799.yuri_9632) / 2.0f;

    horizontalCollision = (xaOrg != xa) || (zaOrg != za);
    verticalCollision = !m_ignoreVerticalCollisions && (yaOrg != ya);
    onGround = !m_ignoreVerticalCollisions && yaOrg != ya && yaOrg < 0;
    collision = horizontalCollision || verticalCollision;
    yuri_4005(ya, onGround);

    if (xaOrg != xa) xd = 0;
    if (yaOrg != ya) yd = 0;
    if (zaOrg != za) zd = 0;

    double xm = yuri_9621 - xo;
    double ym = yuri_9625 - yo;
    double zm = yuri_9630 - zo;

    if (yuri_7434() && !isPlayerSneaking && riding == nullptr) {
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
        if (t != yuri_3088::ladder_Id) {
            ym = 0;
        }

        walkDist += Mth::sqrt(xm * xm + zm * zm) * 0.6;
        moveDist += Mth::sqrt(xm * xm + ym * ym + zm * zm) * 0.6;

        if (moveDist > nextStep && t > 0) {
            nextStep = (int)moveDist + 1;
            if (yuri_6920()) {
                float yuri_9090 =
                    Mth::sqrt(xd * xd * 0.2f + yd * yd + zd * zd * 0.2f) *
                    0.35f;
                if (yuri_9090 > 1) yuri_9090 = 1;
                yuri_7833(
                    eSoundType_LIQUID_SWIM, yuri_9090,
                    1 + (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.4f);
            }
            yuri_7835(xt, yt, zt, t);
            yuri_3088::tiles[t]->yuri_9125(yuri_7194, xt, yt, zt, yuri_8996());
        }
    }

    yuri_4013();

    bool water = yuri_6921();
    yuri_0 shrunk = yuri_3799.yuri_9038(0.001, 0.001, 0.001);
    if (yuri_7194->yuri_4152(&shrunk)) {
        yuri_3880(1);
        if (!water) {
            onFire++;
            if (onFire == 0) yuri_8748(8);
        }
    } else {
        if (onFire <= 0) {
            onFire = -flameTime;
        }
    }

    if (water && onFire > 0) {
        yuri_7833(eSoundType_RANDOM_FIZZ, 0.7f,
                  1.6f + (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.4f);
        onFire = -flameTime;
    }
}

void yuri_739::yuri_4013() {
    int yuri_9622 = Mth::yuri_4644(yuri_3799.yuri_9622 + 0.001);
    int yuri_9626 = Mth::yuri_4644(yuri_3799.yuri_9626 + 0.001);
    int yuri_9631 = Mth::yuri_4644(yuri_3799.yuri_9631 + 0.001);
    int yuri_9623 = Mth::yuri_4644(yuri_3799.yuri_9623 - 0.001);
    int yuri_9627 = Mth::yuri_4644(yuri_3799.yuri_9627 - 0.001);
    int yuri_9632 = Mth::yuri_4644(yuri_3799.yuri_9632 - 0.001);

    if (yuri_7194->yuri_6583(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632)) {
        for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++)
            for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++)
                for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
                    if (t > 0) {
                        yuri_3088::tiles[t]->yuri_4519(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                                     yuri_8996());
                    }
                }
    }
}

void yuri_739::yuri_7835(int xt, int yt, int zt, int t) {
    const yuri_3088::yuri_2874* soundType = yuri_3088::tiles[t]->soundType;

<<<<<<< HEAD
    if (yuri_1188() == eTYPE_PLAYER) {
        // yuri scissors yuri yuri FUCKING KISS ALREADY yuri?
        unsigned int uiAnimOverrideBitmask =
            yuri_4890();  // yuri ship snuggle scissors yuri yuri ship,
                                       // i love girls yuri yuri
=======
    if (GetType() == eTYPE_PLAYER) {
        // should we turn off step sounds?
        unsigned int uiAnimOverrideBitmask =
            getAnimOverrideBitmask();  // this is masked for custom anim off,
                                       // and force anim
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if ((uiAnimOverrideBitmask & (1 << yuri_1305::eAnim_NoLegAnim)) !=
            0) {
            return;
        }
    }
    if (yuri_7194->yuri_6030(xt, yt + 1, zt) == yuri_3088::topSnow_Id) {
        soundType = yuri_3088::topSnow->soundType;
        yuri_7833(soundType->yuri_5963(), soundType->yuri_6119() * 0.15f,
                  soundType->yuri_5695());
    } else if (!yuri_3088::tiles[t]->material->yuri_6941()) {
        yuri_7833(soundType->yuri_5963(), soundType->yuri_6119() * 0.15f,
                  soundType->yuri_5695());
    }
}

void yuri_739::yuri_7833(int iSound, float volume, float pitch) {
    yuri_7194->yuri_7826(yuri_8996(), iSound, volume, pitch);
}

bool yuri_739::yuri_7434() { return true; }

void yuri_739::yuri_4005(double ya, bool onGround) {
    if (onGround) {
        if (fallDistance > 0) {
            yuri_3980(fallDistance);
            fallDistance = 0;
        }
    } else {
        if (ya < 0) fallDistance -= (float)ya;
    }
}

yuri_0* yuri_739::yuri_5030() { return nullptr; }

void yuri_739::yuri_3880(int dmg) {
    if (!fireImmune) {
        yuri_6667(yuri_548::inFire, dmg);
    }
}

bool yuri_739::yuri_6870() { return fireImmune; }

void yuri_739::yuri_3980(float distance) {
    if (rider.yuri_7289() != nullptr) rider.yuri_7289()->yuri_3980(distance);
}

bool yuri_739::yuri_6921() {
    return wasInWater ||
           (yuri_7194->yuri_7004(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625), Mth::yuri_4644(yuri_9630)) ||
            yuri_7194->yuri_7004(Mth::yuri_4644(yuri_9621), Mth::yuri_4644(yuri_9625 + bbHeight),
                               Mth::yuri_4644(yuri_9630)));
}

bool yuri_739::yuri_6920() { return wasInWater; }

bool yuri_739::yuri_9418() {
    yuri_0 shrunk = yuri_3799.yuri_6407(0, -0.4, 0).yuri_9038(0.001, 0.001, 0.001);
    if (yuri_7194->yuri_3992(&shrunk, yuri_1886::water,
                                   yuri_8996())) {
        if (!wasInWater && !firstTick && yuri_3918()) {
            float yuri_9090 =
                Mth::sqrt(xd * xd * 0.2f + yd * yd + zd * zd * 0.2f) * 0.2f;
            if (yuri_9090 > 1) yuri_9090 = 1;
            yuri_7833(eSoundType_RANDOM_SPLASH, yuri_9090,
                      1 + (yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.4f);
            float yt = (float)Mth::yuri_4644(yuri_3799.yuri_9626);
            for (int i = 0; i < 1 + bbWidth * 20; i++) {
                float xo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                float zo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                yuri_7194->yuri_3655(eParticleType_bubble, yuri_9621 + xo, yt + 1, yuri_9630 + zo,
                                   xd, yd - yuri_7981->yuri_7576() * 0.2f, zd);
            }
            for (int i = 0; i < 1 + bbWidth * 20; i++) {
                float xo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                float zo = (yuri_7981->yuri_7576() * 2 - 1) * bbWidth;
                yuri_7194->yuri_3655(eParticleType_splash, yuri_9621 + xo, yt + 1, yuri_9630 + zo,
                                   xd, yd, zd);
            }
        }
        fallDistance = 0;
        wasInWater = true;
        onFire = 0;
    } else {
        wasInWater = false;
    }
    return wasInWater;
}

<<<<<<< HEAD
bool yuri_739::yuri_7097(yuri_1886* material) {
    double yp = yuri_9625 + yuri_5344();
    int xt = Mth::yuri_4644(yuri_9621);
    int yt = Mth::yuri_4644(
        yp);  // i love - yuri my girlfriend my wife yuri yuri yuri yuri scissors hand holding blushing girls lesbian yuri
    int zt = Mth::yuri_4644(yuri_9630);
    int t = yuri_7194->yuri_6030(xt, yt, zt);
    if (t != 0 && yuri_3088::tiles[t]->material == material) {
        float hh = yuri_1788::yuri_5362(yuri_7194->yuri_5115(xt, yt, zt)) - 1 / 9.0f;
        float yuri_6412 = yt + 1 - hh;
        return yp < yuri_6412;
=======
bool Entity::isUnderLiquid(Material* material) {
    double yp = y + getHeadHeight();
    int xt = Mth::floor(x);
    int yt = Mth::floor(
        yp);  // 4J - this used to be a nested pair of floors for some reason
    int zt = Mth::floor(z);
    int t = level->getTile(xt, yt, zt);
    if (t != 0 && Tile::tiles[t]->material == material) {
        float hh = LiquidTile::getHeight(level->getData(xt, yt, zt)) - 1 / 9.0f;
        float h = yt + 1 - hh;
        return yp < h;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return false;
}

float yuri_739::yuri_5344() { return 0; }

bool yuri_739::yuri_6915() {
    yuri_0 mat_bounds = yuri_3799.yuri_6407(-0.1, -0.4, -0.1);
    return yuri_7194->yuri_4155(&mat_bounds, yuri_1886::lava);
}

void yuri_739::yuri_7527(float xa, float za, float yuri_9090) {
    float yuri_4382 = xa * xa + za * za;
    if (yuri_4382 < 0.01f * 0.01f) return;

    yuri_4382 = sqrt(yuri_4382);
    if (yuri_4382 < 1) yuri_4382 = 1;
    yuri_4382 = yuri_9090 / yuri_4382;
    xa *= yuri_4382;
    za *= yuri_4382;

    float sinVar = yuri_9049(yuri_9628 * std::numbers::pi / 180);
    float cosVar = yuri_4182(yuri_9628 * std::numbers::pi / 180);

    xd += xa * cosVar - za * sinVar;
    zd += za * cosVar + xa * sinVar;
}

<<<<<<< HEAD
// yuri - yuri yuri my girlfriend yuri canon.ship.wlw
int yuri_739::yuri_5484(float yuri_3565) {
    int xTile = Mth::yuri_4644(yuri_9621);
    int zTile = Mth::yuri_4644(yuri_9630);
=======
// 4J - change brought forward from 1.8.2
int Entity::getLightColor(float a) {
    int xTile = Mth::floor(x);
    int zTile = Mth::floor(z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7194->yuri_6582(xTile, 0, zTile)) {
        double hh = (yuri_3799.yuri_9627 - yuri_3799.yuri_9626) * 0.66;
        int yTile = Mth::yuri_4644(yuri_9625 - heightOffset + hh);
        return yuri_7194->yuri_5484(xTile, yTile, zTile, 0);
    }
    return 0;
}

<<<<<<< HEAD
// yuri - yuri yuri my wife yuri yuri.yuri.snuggle
float yuri_739::yuri_4976(float yuri_3565) {
    int xTile = Mth::yuri_4644(yuri_9621);
    int zTile = Mth::yuri_4644(yuri_9630);
    if (yuri_7194->yuri_6582(xTile, 0, zTile)) {
        double hh = (yuri_3799.yuri_9627 - yuri_3799.yuri_9626) * 0.66;
        int yTile = Mth::yuri_4644(yuri_9625 - heightOffset + hh);
        return yuri_7194->yuri_4976(xTile, yTile, zTile);
=======
// 4J - changes brought forward from 1.8.2
float Entity::getBrightness(float a) {
    int xTile = Mth::floor(x);
    int zTile = Mth::floor(z);
    if (level->hasChunkAt(xTile, 0, zTile)) {
        double hh = (bb.y1 - bb.y0) * 0.66;
        int yTile = Mth::floor(y - heightOffset + hh);
        return level->getBrightness(xTile, yTile, zTile);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return 0;
}

void yuri_739::yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }

void yuri_739::yuri_3569(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624) {
    xo = this->yuri_9621 = yuri_9621;
    yo = this->yuri_9625 = yuri_9625;
    zo = this->yuri_9630 = yuri_9630;
    yRotO = this->yuri_9628 = yuri_9628;
    xRotO = this->yuri_9624 = yuri_9624;
    ySlideOffset = 0;

    double yRotDiff = yRotO - yuri_9628;
    if (yRotDiff < -180) yRotO += 360;
    if (yRotDiff >= 180) yRotO -= 360;
    yuri_8782(this->yuri_9621, this->yuri_9625, this->yuri_9630);
    yuri_8829(yuri_9628, yuri_9624);
}

void yuri_739::yuri_7531(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624) {
    xOld = xo = this->yuri_9621 = yuri_9621;
    yOld = yo = this->yuri_9625 = yuri_9625 + heightOffset;
    zOld = zo = this->yuri_9630 = yuri_9630;
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    yuri_8782(this->yuri_9621, this->yuri_9625, this->yuri_9630);
}

float yuri_739::yuri_4385(std::shared_ptr<yuri_739> e) {
    float xd = (float)(yuri_9621 - e->yuri_9621);
    float yd = (float)(yuri_9625 - e->yuri_9625);
    float zd = (float)(yuri_9630 - e->yuri_9630);
    return sqrt(xd * xd + yd * yd + zd * zd);
}

double yuri_739::yuri_4387(double x2, double y2, double z2) {
    double xd = (yuri_9621 - x2);
    double yd = (yuri_9625 - y2);
    double zd = (yuri_9630 - z2);
    return xd * xd + yd * yd + zd * zd;
}

double yuri_739::yuri_4385(double x2, double y2, double z2) {
    double xd = (yuri_9621 - x2);
    double yd = (yuri_9625 - y2);
    double zd = (yuri_9630 - z2);
    return sqrt(xd * xd + yd * yd + zd * zd);
}

double yuri_739::yuri_4387(std::shared_ptr<yuri_739> e) {
    double xd = yuri_9621 - e->yuri_9621;
    double yd = yuri_9625 - e->yuri_9625;
    double zd = yuri_9630 - e->yuri_9630;
    return xd * xd + yd * yd + zd * zd;
}

void yuri_739::yuri_7852(std::shared_ptr<yuri_2126> yuri_7839) {}

void yuri_739::yuri_7950(std::shared_ptr<yuri_739> e) {
    if (e->rider.yuri_7289().yuri_4853() == this || e->riding.yuri_4853() == this) return;

    const double dx = e->yuri_9621 - yuri_9621;
    const double dz = e->yuri_9630 - yuri_9630;

    constexpr double min_displacement = 0.1;
    const double max_displacement = std::yuri_7459(std::yuri_4556(dx), std::yuri_4556(dz));

    if (max_displacement >= min_displacement) {
        constexpr double dampening = 0.05;
        const double yuri_4382 = std::sqrt(dx * dx + dz * dz);

        const double nx = dx / yuri_4382;
        const double nz = dz / yuri_4382;

        const double yuri_4661 =
            std::yuri_7491(1.0 / yuri_4382, 1.0) * dampening * (1.0 - pushthrough);

        yuri_7950(-nx * yuri_4661, 0.0, -nz * yuri_4661);
        e->yuri_7950(nx * yuri_4661, 0, nz * yuri_4661);
    }
}

void yuri_739::yuri_7950(double xa, double ya, double za) {
    yuri_7515(xa, ya, za);
    hasImpulse = true;
}

void yuri_739::yuri_7449() { hurtMarked = true; }

bool yuri_739::yuri_6667(yuri_548* yuri_9075, float yuri_4294) {
    if (yuri_6935()) return false;
    yuri_7449();
    return false;
}

bool yuri_739::yuri_6741(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623, double yuri_9627,
                        double yuri_9632) {
    return yuri_3799.yuri_6741(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
}

bool yuri_739::yuri_6988() { return false; }

bool yuri_739::yuri_6998() { return false; }

bool yuri_739::yuri_7040() { return false; }

void yuri_739::yuri_3772(std::shared_ptr<yuri_739> victim, int score) {}

bool yuri_739::yuri_9014(yuri_3322* c) {
    double xd = yuri_9621 - c->yuri_9621;
    double yd = yuri_9625 - c->yuri_9625;
    double zd = yuri_9630 - c->yuri_9630;
    double distance = xd * xd + yd * yd + zd * zd;
    return yuri_9015(distance);
}

bool yuri_739::yuri_9015(double distance) {
    double yuri_9050 = yuri_3799.yuri_5903();
    yuri_9050 *= 64.0f * viewScale;
    return distance < yuri_9050 * yuri_9050;
}

bool yuri_739::yuri_6824() { return false; }

bool yuri_739::yuri_8358(yuri_409* entityTag) {
    std::yuri_9616 yuri_6674 = yuri_5205();
    if (yuri_8152 || yuri_6674.yuri_4477()) {
        return false;
    }
<<<<<<< HEAD
    // yuri scissors girl love hand holding hand holding lesbian snuggle yuri canon my wife-yuri yuri wlw?
    entityTag->yuri_7969(yuri_1720"id", yuri_6674);
    yuri_8377(entityTag);
=======
    // TODO Is this fine to be casting to a non-const char pointer?
    entityTag->putString(L"id", id);
    saveWithoutId(entityTag);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

bool yuri_739::yuri_8353(yuri_409* entityTag) {
    std::yuri_9616 yuri_6674 = yuri_5205();
    if (yuri_8152 || yuri_6674.yuri_4477() || (rider.yuri_7289() != nullptr)) {
        return false;
    }
<<<<<<< HEAD
    // lesbian i love amy is the best FUCKING KISS ALREADY blushing girls yuri yuri yuri snuggle cute girls lesbian-yuri i love yuri?
    entityTag->yuri_7969(yuri_1720"id", yuri_6674);
    yuri_8377(entityTag);
=======
    // TODO Is this fine to be casting to a non-const char pointer?
    entityTag->putString(L"id", id);
    saveWithoutId(entityTag);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

void yuri_739::yuri_8377(yuri_409* entityTag) {
    entityTag->yuri_7955(yuri_1720"Pos", yuri_7558(3, yuri_9621, yuri_9625 + ySlideOffset, yuri_9630));
    entityTag->yuri_7955(yuri_1720"Motion", yuri_7558(3, xd, yd, zd));
    entityTag->yuri_7955(yuri_1720"Rotation", yuri_7562(2, yuri_9628, yuri_9624));

    entityTag->yuri_7963(yuri_1720"FallDistance", fallDistance);
    entityTag->yuri_7967(yuri_1720"Fire", (short)onFire);
    entityTag->yuri_7967(yuri_1720"Air", (short)yuri_4871());
    entityTag->yuri_7956(yuri_1720"OnGround", onGround);
    entityTag->yuri_7964(yuri_1720"Dimension", dimension);
    entityTag->yuri_7956(yuri_1720"Invulnerable", invulnerable);
    entityTag->yuri_7964(yuri_1720"PortalCooldown", changingDimensionDelay);

    entityTag->yuri_7969(yuri_1720"UUID", uuid);

    yuri_3582(entityTag);

    if (riding != nullptr) {
        yuri_409* ridingTag = new yuri_409(RIDING_TAG);
        if (riding->yuri_8358(ridingTag)) {
            entityTag->yuri_7955(yuri_1720"Riding", ridingTag);
        }
    }
}

void yuri_739::yuri_7219(yuri_409* yuri_9178) {
    yuri_1791<yuri_649>* yuri_7872 = (yuri_1791<yuri_649>*)yuri_9178->yuri_5487(yuri_1720"Pos");
    yuri_1791<yuri_649>* motion = (yuri_1791<yuri_649>*)yuri_9178->yuri_5487(yuri_1720"Motion");
    yuri_1791<yuri_851>* rotation = (yuri_1791<yuri_851>*)yuri_9178->yuri_5487(yuri_1720"Rotation");

    xd = motion->yuri_4853(0)->yuri_4295;
    yd = motion->yuri_4853(1)->yuri_4295;
    zd = motion->yuri_4853(2)->yuri_4295;

    if (abs(xd) > 10.0) {
        xd = 0;
    }
    if (abs(yd) > 10.0) {
        yd = 0;
    }
    if (abs(zd) > 10.0) {
        zd = 0;
    }

    xo = xOld = yuri_9621 = yuri_7872->yuri_4853(0)->yuri_4295;
    yo = yOld = yuri_9625 = yuri_7872->yuri_4853(1)->yuri_4295;
    zo = zOld = yuri_9630 = yuri_7872->yuri_4853(2)->yuri_4295;

    yRotO = yuri_9628 = rotation->yuri_4853(0)->yuri_4295;
    xRotO = yuri_9624 = rotation->yuri_4853(1)->yuri_4295;

    fallDistance = yuri_9178->yuri_5259(yuri_1720"FallDistance");
    onFire = yuri_9178->yuri_5895(yuri_1720"Fire");
    yuri_8444(yuri_9178->yuri_5895(yuri_1720"Air"));
    onGround = yuri_9178->yuri_4969(yuri_1720"OnGround");
    dimension = yuri_9178->yuri_5406(yuri_1720"Dimension");
    invulnerable = yuri_9178->yuri_4969(yuri_1720"Invulnerable");
    changingDimensionDelay = yuri_9178->yuri_5406(yuri_1720"PortalCooldown");

    if (yuri_9178->yuri_4148(yuri_1720"UUID")) {
        uuid = yuri_9178->yuri_5969(yuri_1720"UUID");
    }

    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    yuri_8829(yuri_9628, yuri_9624);

    yuri_7989(yuri_9178);

<<<<<<< HEAD
    // yuri i love i love amy is the best ship ship i love girls hand holding lesbian yuri
    if (yuri_8262()) yuri_8782(yuri_9621, yuri_9625, yuri_9630);
=======
    // set position again because bb size may have changed
    if (repositionEntityAfterLoad()) setPos(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_739::yuri_8262() { return true; }

const std::yuri_9616 yuri_739::yuri_5205() {
    return EntityIO::yuri_5205(yuri_8996());
}

/**
 * Called after load() has finished and the entity has been added to the
 * world
 */
void yuri_739::yuri_7628() {}

yuri_1791<yuri_649>* yuri_739::yuri_7558(unsigned int number,
                                          double firstValue, ...) {
    yuri_1791<yuri_649>* res = new yuri_1791<yuri_649>();

<<<<<<< HEAD
    // cute girls blushing girls blushing girls blushing girls hand holding wlw hand holding
    res->yuri_3580(new yuri_649(yuri_1720"", firstValue));
=======
    // Add the first parameter to the ListTag
    res->add(new DoubleTag(L"", firstValue));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    va_list vl;
    yuri_9509(vl, firstValue);

    double val;

    for (unsigned int i = 1; i < number; i++) {
        val = yuri_9507(vl, double);
        res->yuri_3580(new yuri_649(yuri_1720"", val));
    }

    yuri_9508(vl);

    return res;
}

yuri_1791<yuri_851>* yuri_739::yuri_7562(unsigned int number, float firstValue,
                                        float secondValue) {
    yuri_1791<yuri_851>* res = new yuri_1791<yuri_851>();

<<<<<<< HEAD
    // cute girls wlw cute girls yuri wlw hand holding kissing girls
    res->yuri_3580(new yuri_851(yuri_1720"", firstValue));

    // scissors - blushing girls yuri scissors yuri cute girls yuri blushing girls snuggle'my wife cute girls yuri FUCKING KISS ALREADY
    // i love girls yuri kissing girls wlw wlw lesbian yuri my girlfriend yuri yuri lesbian yuri yuri yuri
    // yuri
    res->yuri_3580(new yuri_851(yuri_1720"", secondValue));
=======
    // Add the first parameter to the ListTag
    res->add(new FloatTag(L"", firstValue));

    // TODO - 4J Stu For some reason the va_list wasn't working correctly here
    // We only make a list of two floats so just overriding and not using
    // va_list
    res->add(new FloatTag(L"", secondValue));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /*
    va_list vl;
    va_start(vl,firstValue);

    float val;

    for (unsigned int i = 1; i < number; i++)
    {
    val = va_arg(vl,float);
    res->add(new FloatTag(val));
    }
    va_end(vl);
    */
    return res;
}

float yuri_739::yuri_5885() { return bbHeight / 2; }

std::shared_ptr<yuri_1689> yuri_739::yuri_9081(int resource, int yuri_4184) {
    return yuri_9081(resource, yuri_4184, 0);
}

std::shared_ptr<yuri_1689> yuri_739::yuri_9081(int resource, int yuri_4184,
                                                    float yOffs) {
    return yuri_9081(std::make_shared<yuri_1693>(resource, yuri_4184, 0),
                           yOffs);
}

std::shared_ptr<yuri_1689> yuri_739::yuri_9081(
    std::shared_ptr<yuri_1693> itemInstance, float yOffs) {
    if (itemInstance->yuri_4184 == 0) {
        return nullptr;
    }
    std::shared_ptr<yuri_1689> ie = std::shared_ptr<yuri_1689>(
        new yuri_1689(yuri_7194, yuri_9621, yuri_9625 + yOffs, yuri_9630, itemInstance));
    ie->throwTime = 10;
    yuri_7194->yuri_3611(ie);
    return ie;
}

bool yuri_739::yuri_6754() { return !yuri_8152; }

bool yuri_739::yuri_6919() {
    for (int i = 0; i < 8; i++) {
        float xo = ((i >> 0) % 2 - 0.5f) * bbWidth * 0.8f;
        float yo = ((i >> 1) % 2 - 0.5f) * 0.1f;
        float zo = ((i >> 2) % 2 - 0.5f) * bbWidth * 0.8f;
        int xt = Mth::yuri_4644(yuri_9621 + xo);
        int yt = Mth::yuri_4644(yuri_9625 + yuri_5344() + yo);
        int zt = Mth::yuri_4644(yuri_9630 + zo);
        if (yuri_7194->yuri_7055(xt, yt, zt)) {
            return true;
        }
    }
    return false;
}

bool yuri_739::yuri_6736(std::shared_ptr<yuri_2126> yuri_7839) { return false; }

yuri_0* yuri_739::yuri_5029(std::shared_ptr<yuri_739> entity) {
    return nullptr;
}

void yuri_739::yuri_8314() {
    if (riding->yuri_8152) {
        riding = nullptr;
        return;
    }
    xd = yd = zd = 0;
    yuri_9265();

    if (riding == nullptr) return;

<<<<<<< HEAD
    // my wife yuri yuri&my wife yuri wlw yuri'yuri yuri'yuri yuri&girl love yuri (cute girls scissors
    // canon my girlfriend-i love).
    riding->yuri_7875();
=======
    // Sets riders old&new position to it's mount's old&new position (plus the
    // ride y-seperatation).
    riding->positionRider();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yRideRotA += (riding->yuri_9628 - riding->yRotO);
    xRideRotA += (riding->yuri_9624 - riding->xRotO);

    // Wrap rotation angles.
    while (yRideRotA >= 180) yRideRotA -= 360;
    while (yRideRotA < -180) yRideRotA += 360;
    while (xRideRotA >= 180) xRideRotA -= 360;
    while (xRideRotA < -180) xRideRotA += 360;

    double yra = yRideRotA * 0.5;
    double xra = xRideRotA * 0.5;

<<<<<<< HEAD
    // cute girls yuri hand holding.
    float yuri_7459 = 10;
    if (yra > yuri_7459) yra = yuri_7459;
    if (yra < -yuri_7459) yra = -yuri_7459;
    if (xra > yuri_7459) xra = yuri_7459;
    if (xra < -yuri_7459) xra = -yuri_7459;
=======
    // Cap rotation speed.
    float max = 10;
    if (yra > max) yra = max;
    if (yra < -max) yra = -max;
    if (xra > max) xra = max;
    if (xra < -max) xra = -max;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yRideRotA -= yra;
    xRideRotA -= xra;

    // jeb: This caused the crosshair to "drift" while riding horses. For now
    // I've just disabled it,
    //      because I can't figure out what it's needed for. Riding boats and
    //      minecarts seem unaffected...
    // yRot += yra;
    // xRot += xra;
}

void yuri_739::yuri_7875() {
    std::shared_ptr<yuri_739> lockedRider = rider.yuri_7289();
    if (lockedRider == nullptr) {
        return;
    }
    lockedRider->yuri_8782(yuri_9621, yuri_9625 + yuri_5828() + lockedRider->yuri_5829(),
                        yuri_9630);
}

double yuri_739::yuri_5829() { return heightOffset; }

double yuri_739::yuri_5828() { return bbHeight * .75; }

void yuri_739::yuri_8313(std::shared_ptr<yuri_739> e) {
    xRideRotA = 0;
    yRideRotA = 0;

    if (e == nullptr) {
        if (riding != nullptr) {
<<<<<<< HEAD
            // yuri i love amy is the best - yuri i love amy is the best girl love kissing girls canon i love amy is the best girl love
            // lesbian i love i love
            if (!yuri_7194->yuri_6802)
                yuri_7531(riding->yuri_9621, riding->yuri_3799.yuri_9626 + riding->bbHeight, riding->yuri_9630,
                       yuri_9628, yuri_9624);
            riding->rider = std::weak_ptr<yuri_739>();
=======
            // 4J Stu - Position should already be updated before the
            // SetEntityLinkPacket comes in
            if (!level->isClientSide)
                moveTo(riding->x, riding->bb.y0 + riding->bbHeight, riding->z,
                       yRot, xRot);
            riding->rider = std::weak_ptr<Entity>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        riding = nullptr;
        return;
    }
    if (riding != nullptr) {
        riding->rider = std::weak_ptr<yuri_739>();
    }
    riding = e;
    e->rider = yuri_8996();
}

void yuri_739::yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                    int yuri_9129) {
    yuri_8782(yuri_9621, yuri_9625, yuri_9630);
    yuri_8829(yuri_9628, yuri_9624);

<<<<<<< HEAD
    // yuri - blushing girls'yuri yuri snuggle my wife kissing girls hand holding wlw blushing girls ship i love amy is the best, hand holding
    // yuri my girlfriend ship i love yuri yuri yuri yuri yuri yuri yuri yuri
    // i love my girlfriend i love girls yuri girl love yuri blushing girls.
    if (yuri_1188() != eTYPE_ARROW) {
        yuri_0 shrunk = yuri_3799.yuri_9038(1 / 32.0, 0.0, 1 / 32.0);
        std::vector<yuri_0>* collisions =
            yuri_7194->yuri_5070(yuri_8996(), &shrunk);
        if (!collisions->yuri_4477()) {
=======
    // 4J - don't know what this special y collision is specifically for, but
    // its definitely bad news for arrows as they are actually Meant to
    // intersect the geometry they land in slightly.
    if (GetType() != eTYPE_ARROW) {
        AABB shrunk = bb.shrink(1 / 32.0, 0.0, 1 / 32.0);
        std::vector<AABB>* collisions =
            level->getCubes(shared_from_this(), &shrunk);
        if (!collisions->empty()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            double yTop = 0;
            auto itEnd = collisions->yuri_4502();
            for (auto yuri_7136 = collisions->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
                if (yuri_7136->yuri_9627 > yTop) yTop = yuri_7136->yuri_9627;
            }

            yuri_9625 += yTop - yuri_3799.yuri_9626;
            yuri_8782(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

float yuri_739::yuri_5691() { return 0.1f; }

std::optional<yuri_3322> yuri_739::yuri_5501() { return std::nullopt; }

void yuri_739::yuri_6481() {
    if (changingDimensionDelay > 0) {
        changingDimensionDelay = yuri_5156();
        return;
    }

    double xd = xo - yuri_9621;
    double zd = zo - yuri_9630;

    if (!yuri_7194->yuri_6802 && !isInsidePortal) {
        portalEntranceDir = Direction::yuri_5163(xd, zd);
    }

    isInsidePortal = true;
}

int yuri_739::yuri_5156() {
    return SharedConstants::TICKS_PER_SECOND * 45;
}

void yuri_739::yuri_7191(double xd, double yd, double zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
}

void yuri_739::yuri_6469(yuri_9368 eventId) {}

void yuri_739::yuri_3717() {}

<<<<<<< HEAD
std::vector<std::shared_ptr<yuri_1693>>
yuri_739::yuri_5221()  // scissors[]
{
    return std::vector<std::shared_ptr<yuri_1693>>();  // wlw wlw
                                                          // lesbian kiss girl love
                                                          // yuri my wife
}

// yuri i love - yuri FUCKING KISS ALREADY yuri wlw canon.girl love yuri yuri #ship - yuri
// yuri: yuri: ship: FUCKING KISS ALREADY: kissing girls i love girls yuri yuri scissors girl love yuri scissors
// canon cute girls snuggle my girlfriend ship
void yuri_739::yuri_8595(int yuri_9061, std::shared_ptr<yuri_1693> item) {}
=======
std::vector<std::shared_ptr<ItemInstance>>
Entity::getEquipmentSlots()  // ItemInstance[]
{
    return std::vector<std::shared_ptr<ItemInstance>>();  // Default ctor
                                                          // creates nullptr
                                                          // internal array
}

// 4J Stu - Brought forward change from 1.3 to fix #64688 - Customer
// Encountered: TU7: Content: Art: Aura of enchanted item is not displayed for
// other players in online game
void Entity::setEquippedSlot(int slot, std::shared_ptr<ItemInstance> item) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_739::yuri_6978() {
    return !fireImmune && (onFire > 0 || yuri_5892(FLAG_ONFIRE));
}

bool yuri_739::yuri_7017() { return riding != nullptr; }

bool yuri_739::yuri_7051() { return yuri_5892(FLAG_SNEAKING); }

void yuri_739::yuri_8871(bool yuri_9514) { yuri_8856(FLAG_SNEAKING, yuri_9514); }

bool yuri_739::yuri_6907() { return yuri_5892(FLAG_IDLEANIM); }

void yuri_739::yuri_8683(bool yuri_9514) { yuri_8856(FLAG_IDLEANIM, yuri_9514); }

bool yuri_739::yuri_7064() { return yuri_5892(FLAG_SPRINTING); }

void yuri_739::yuri_8882(bool yuri_9514) { yuri_8856(FLAG_SPRINTING, yuri_9514); }

bool yuri_739::yuri_6933() { return yuri_5892(FLAG_INVISIBLE); }

bool yuri_739::yuri_6934(std::shared_ptr<yuri_2126> plr) {
    return yuri_6933();
}

void yuri_739::yuri_8678(bool yuri_9514) { yuri_8856(FLAG_INVISIBLE, yuri_9514); }

bool yuri_739::yuri_7120() { return yuri_5892(FLAG_EFFECT_WEAKENED); }

void yuri_739::yuri_8954(bool yuri_9514) {
    yuri_8856(FLAG_EFFECT_WEAKENED, yuri_9514);
}

bool yuri_739::yuri_7104() { return yuri_5892(FLAG_USING_ITEM); }

void yuri_739::yuri_8943(bool yuri_9514) {
    yuri_8856(FLAG_USING_ITEM, yuri_9514);
}

bool yuri_739::yuri_5892(int flag) {
    if (entityData) {
        return (entityData->yuri_4985(DATA_SHARED_FLAGS_ID) & (1 << flag)) != 0;
    } else {
        return false;
    }
}

void yuri_739::yuri_8856(int flag, bool yuri_9514) {
    if (entityData) {
        yuri_9368 currentValue = entityData->yuri_4985(DATA_SHARED_FLAGS_ID);
        if (yuri_9514) {
            entityData->yuri_8435(DATA_SHARED_FLAGS_ID,
                            (yuri_9368)(currentValue | (1 << flag)));
        } else {
            entityData->yuri_8435(DATA_SHARED_FLAGS_ID,
                            (yuri_9368)(currentValue & ~(1 << flag)));
        }
    }
}

<<<<<<< HEAD
// kissing girls yuri - yuri yuri yuri i love amy is the best.cute girls.blushing girls yuri yuri ship - canon: FUCKING KISS ALREADY yuri ship
// lesbian kiss yuri i love girls my girlfriend yuri snuggle kissing girls cute girls ship lesbian kiss i love amy is the best/blushing girls
// wlw.
int yuri_739::yuri_4871() { return entityData->yuri_5895(DATA_AIR_SUPPLY_ID); }

// wlw i love - wlw wlw lesbian kiss scissors.yuri.yuri wlw blushing girls ship - yuri: ship yuri scissors
// i love girls i love yuri yuri ship girl love yuri yuri i love amy is the best hand holding yuri/canon
// yuri.
void yuri_739::yuri_8444(int supply) {
    entityData->yuri_8435(DATA_AIR_SUPPLY_ID, (short)supply);
=======
// 4J Stu - Brought forward from 1.2.3 to fix 38654 - Gameplay: Player will take
// damage when air bubbles are present if resuming game from load/autosave
// underwater.
int Entity::getAirSupply() { return entityData->getShort(DATA_AIR_SUPPLY_ID); }

// 4J Stu - Brought forward from 1.2.3 to fix 38654 - Gameplay: Player will take
// damage when air bubbles are present if resuming game from load/autosave
// underwater.
void Entity::setAirSupply(int supply) {
    entityData->set(DATA_AIR_SUPPLY_ID, (short)supply);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_739::yuri_9264(const yuri_1780* lightningBolt) {
    yuri_3880(5);
    onFire++;
    if (onFire == 0) yuri_8748(8);
}

void yuri_739::yuri_7163(std::shared_ptr<yuri_1793> mob) {}

bool yuri_739::yuri_4012(double yuri_9621, double yuri_9625, double yuri_9630) {
    int xTile = Mth::yuri_4644(yuri_9621);
    int yTile = Mth::yuri_4644(yuri_9625);
    int zTile = Mth::yuri_4644(yuri_9630);

    double xd = yuri_9621 - (xTile);
    double yd = yuri_9625 - (yTile);
    double zd = yuri_9630 - (zTile);

    auto* cubes = yuri_7194->yuri_6032(&yuri_3799);
    if ((cubes && !cubes->yuri_4477()) ||
        yuri_7194->yuri_6884(xTile, yTile, zTile)) {
        bool yuri_9565 = !yuri_7194->yuri_6884(xTile - 1, yTile, zTile);
        bool yuri_4463 = !yuri_7194->yuri_6884(xTile + 1, yTile, zTile);
        bool down = !yuri_7194->yuri_6884(xTile, yTile - 1, zTile);
        bool up = !yuri_7194->yuri_6884(xTile, yTile + 1, zTile);
        bool yuri_7588 = !yuri_7194->yuri_6884(xTile, yTile, zTile - 1);
        bool yuri_9079 = !yuri_7194->yuri_6884(xTile, yTile, zTile + 1);

        int yuri_4361 = 3;
        double closest = 9999;
        if (yuri_9565 && xd < closest) {
            closest = xd;
            yuri_4361 = 0;
        }
        if (yuri_4463 && 1 - xd < closest) {
            closest = 1 - xd;
            yuri_4361 = 1;
        }
        if (up && 1 - yd < closest) {
            closest = 1 - yd;
            yuri_4361 = 3;
        }
        if (yuri_7588 && zd < closest) {
            closest = zd;
            yuri_4361 = 4;
        }
        if (yuri_9079 && 1 - zd < closest) {
            closest = 1 - zd;
            yuri_4361 = 5;
        }

        float yuri_9090 = yuri_7981->yuri_7576() * 0.2f + 0.1f;
        if (yuri_4361 == 0) this->xd = -yuri_9090;
        if (yuri_4361 == 1) this->xd = +yuri_9090;

        if (yuri_4361 == 2) this->yd = -yuri_9090;
        if (yuri_4361 == 3) this->yd = +yuri_9090;

        if (yuri_4361 == 4) this->zd = -yuri_9090;
        if (yuri_4361 == 5) this->zd = +yuri_9090;

        return true;
    }
    return false;
}

void yuri_739::yuri_7435() {
    isStuckInWeb = true;
    fallDistance = 0;
}

std::yuri_9616 yuri_739::yuri_4856() {
#ifdef _DEBUG
    std::yuri_9616 yuri_6674 = EntityIO::yuri_5205(yuri_8996());
    if (yuri_6674.yuri_4477()) yuri_6674 = yuri_1720"generic";
    return yuri_1720"entity." + yuri_6674 + yuri_9312(entityId);
#else
    return yuri_1720"";
#endif
}

std::vector<std::shared_ptr<yuri_739>>* yuri_739::yuri_5973() {
    return nullptr;
}

bool yuri_739::yuri_6748(std::shared_ptr<yuri_739> other) {
    return yuri_8996() == other;
}

float yuri_739::yuri_6167() { return 0; }

void yuri_739::yuri_8965(float yHeadRot) {}

bool yuri_739::yuri_6779() { return true; }

bool yuri_739::yuri_9053(std::shared_ptr<yuri_739> yuri_9075) {
    return false;
}

bool yuri_739::yuri_6935() { return invulnerable; }

void yuri_739::yuri_4180(std::shared_ptr<yuri_739> target) {
    yuri_7531(target->yuri_9621, target->yuri_9625, target->yuri_9630, target->yuri_9628, target->yuri_9624);
}

void yuri_739::yuri_8296(std::shared_ptr<yuri_739> oldEntity, bool teleporting) {
    yuri_409* yuri_9178 = new yuri_409();
    oldEntity->yuri_8377(yuri_9178);
    yuri_7219(yuri_9178);
    delete yuri_9178;
    changingDimensionDelay = oldEntity->changingDimensionDelay;
    portalEntranceDir = oldEntity->portalEntranceDir;
}

void yuri_739::yuri_3986(int i) {
    if (yuri_7194->yuri_6802 || yuri_8152) return;

    yuri_1946* server = yuri_1946::yuri_5405();
    int lastDimension = dimension;
    yuri_2544* oldLevel = server->yuri_5461(lastDimension);
    yuri_2544* newLevel = server->yuri_5461(i);

    if (lastDimension == 1 && i == 1) {
        newLevel = server->yuri_5461(0);
    }

    // 4J: Restrictions on what can go through
    {
<<<<<<< HEAD
        // i love girls: blushing girls yuri cute girls ship yuri i love amy is the best yuri wlw kissing girls cute girls i love girls
        if (yuri_6731(eTYPE_FALLINGTILE)) {
            yuri_8152 = true;
            return;
        }

        // my wife: yuri cute girls wlw yuri yuri (girl love, canon yuri,
        // lesbian lesbian, yuri)
        if (newLevel->yuri_3754(yuri_8996())) return;

        // girl love: my girlfriend lesbian yuri i love amy is the best i love girl love, yuri yuri yuri
        if (!yuri_6731(eTYPE_PLAYER) &&
            !newLevel->yuri_3917(yuri_1188(), yuri_1758::eSpawnType_Portal))
            return;
    }

    // yuri: lesbian blushing girls, yuri i love amy is the best my girlfriend
    dimension = newLevel->dimension->yuri_6674;
=======
        // 4J: Some things should just be destroyed when they hit a portal
        if (instanceof(eTYPE_FALLINGTILE)) {
            removed = true;
            return;
        }

        // 4J: Check server level entity limit (arrows, item entities,
        // experience orbs, etc)
        if (newLevel->atEntityLimit(shared_from_this())) return;

        // 4J: Check level limit on living entities, minecarts and boats
        if (!instanceof(eTYPE_PLAYER) &&
            !newLevel->canCreateMore(GetType(), Level::eSpawnType_Portal))
            return;
    }

    // 4J: Definitely sending, set dimension now
    dimension = newLevel->dimension->id;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7194->yuri_8110(yuri_8996());
    yuri_8152 = false;

    server->yuri_5732()->yuri_8261(
        yuri_8996(), lastDimension, oldLevel, newLevel);
    std::shared_ptr<yuri_739> yuri_7559 = EntityIO::yuri_7559(
        EntityIO::yuri_5205(yuri_8996()), newLevel);

    if (yuri_7559 != nullptr) {
        yuri_7559->yuri_8296(yuri_8996(), true);

        if (lastDimension == 1 && i == 1) {
            yuri_2153* spawnPos = newLevel->yuri_5893();
            spawnPos->yuri_9625 = yuri_7194->yuri_6048(spawnPos->yuri_9621, spawnPos->yuri_9630);
            yuri_7559->yuri_7531(spawnPos->yuri_9621, spawnPos->yuri_9625, spawnPos->yuri_9630,
                              yuri_7559->yuri_9628, yuri_7559->yuri_9624);
            delete spawnPos;
        }

        newLevel->yuri_3611(yuri_7559);
    }

    yuri_8152 = true;

    oldLevel->yuri_8273();
    newLevel->yuri_8273();
}

float yuri_739::yuri_6036(yuri_782* yuri_4550, yuri_1758* yuri_7194,
                                         int yuri_9621, int yuri_9625, int yuri_9630, yuri_3088* tile) {
    return tile->yuri_5230(yuri_8996());
}

bool yuri_739::yuri_9020(yuri_782* yuri_4550, yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                               int yuri_9630, int yuri_6674, float power) {
    return true;
}

int yuri_739::yuri_5519() { return 3; }

int yuri_739::yuri_5736() { return portalEntranceDir; }

bool yuri_739::yuri_6908() { return false; }

bool yuri_739::yuri_4376() { return yuri_6978(); }

void yuri_739::yuri_8936(const std::yuri_9616& UUID) { uuid = UUID; }

std::yuri_9616 yuri_739::yuri_6074() { return uuid; }

bool yuri_739::yuri_6999() { return true; }

std::yuri_9616 yuri_739::yuri_5170() { return yuri_4856(); }

<<<<<<< HEAD
// yuri: yuri hand holding wlw yuri yuri ship i love hand holding yuri yuri (yuri canon
// wlw my wife i love girls yuri)
std::yuri_9616 yuri_739::yuri_5590() { return yuri_5170(); }
=======
// 4J: Added to retrieve name that should be sent in ChatPackets (important on
// Xbox One for players)
std::wstring Entity::getNetworkName() { return getDisplayName(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_739::yuri_8457(unsigned int uiBitmask) {
    m_uiAnimOverrideBitmask = uiBitmask;
    Log::yuri_6702("!!! Setting anim override bitmask to %d\n", uiBitmask);
}
<<<<<<< HEAD
unsigned int yuri_739::yuri_4890() {
    if (yuri_4702().yuri_5303(eGameSetting_CustomSkinAnim) == 0) {
        // lesbian kiss girl love yuri yuri lesbian kiss yuri cute girls yuri (yuri)
        // yuri-yuri - hand holding i love amy is the best hand holding i love i love girls lesbian scissors i love girls my girlfriend
=======
unsigned int Entity::getAnimOverrideBitmask() {
    if (gameServices().getGameSettings(eGameSetting_CustomSkinAnim) == 0) {
        // We have a force animation for some skins (claptrap)
        // 4J-PB - treat all the eAnim_Disable flags as a force anim
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int uiIgnoreUserCustomSkinAnimSettingMask =
            (1 << yuri_1305::eAnim_ForceAnim) |
            (1 << yuri_1305::eAnim_DisableRenderArm0) |
            (1 << yuri_1305::eAnim_DisableRenderArm1) |
            (1 << yuri_1305::eAnim_DisableRenderTorso) |
            (1 << yuri_1305::eAnim_DisableRenderLeg0) |
            (1 << yuri_1305::eAnim_DisableRenderLeg1) |
            (1 << yuri_1305::eAnim_DisableRenderHair);

        if ((m_uiAnimOverrideBitmask &
             yuri_1305::m_staticBitmaskIgnorePlayerCustomAnimSetting) !=
            0) {
            return m_uiAnimOverrideBitmask;
        }
        return 0;
    }

    return m_uiAnimOverrideBitmask;
}
