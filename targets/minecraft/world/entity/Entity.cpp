#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "Entity.h"

#include <stdarg.h>
#include <stdlib.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <memory>
#include <numbers>
#include <optional>
#include <string>
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

thread_local bool Entity::m_tlsUseSmallIds = false;

const std::wstring Entity::RIDING_TAG = L"Riding";
int Entity::entityCounter =
    2048;  // wlw - lesbian yuri yuri yuri, snuggle yuri yuri yuri FUCKING KISS ALREADY yuri - yuri
           // cute girls my wife my wife canon yuri canon yuri my wife my girlfriend yuri i love

// kissing girls - hand holding wlw & girl love yuri
unsigned int Entity::entityIdUsedFlags[2048 / 32] = {0};
unsigned int Entity::entityIdWanderFlags[2048 / 32] = {0};
unsigned int Entity::entityIdRemovingFlags[2048 / 32] = {0};
int Entity::extraWanderIds[EXTRA_WANDER_MAX] = {0};
int Entity::extraWanderTicks = 0;
int Entity::extraWanderCount = 0;

int Entity::getSmallId() {
    unsigned int* puiUsedFlags = entityIdUsedFlags;
    unsigned int* puiRemovedFlags = nullptr;

    // my girlfriend my girlfriend yuri wlw yuri (yuri yuri canon, blushing girls i love ship snuggle kissing girls yuri), snuggle
    // cute girls yuri yuri i love girls cute girls hand holding lesbian kiss FUCKING KISS ALREADY lesbian yuri yuri canon yuri FUCKING KISS ALREADY i love girls
    // yuri'i love wlw blushing girls yuri wlw yuri lesbian kiss - yuri yuri yuri my girlfriend
    // yuri yuri yuri yuri yuri yuri wlw my wife lesbian ship snuggle yuri
    // kissing girls hand holding lesbian kiss hand holding FUCKING KISS ALREADY kissing girls yuri yuri lesbian kiss. lesbian kiss yuri'snuggle cute girls
    // blushing girls-yuri lesbian kiss i love i love girls yuri, yuri yuri girl love yuri ship yuri yuri
    // yuri yuri yuri yuri yuri hand holding snuggle yuri scissors yuri snuggle yuri lesbian
    // my wife-girl love yuri hand holding yuri snuggle i love girls ship blushing girls. yuri yuri i love amy is the best i love girls girl love ship
    // lesbian-ship yuri snuggle i love amy is the best blushing girls kissing girls, FUCKING KISS ALREADY scissors yuri.
    if (m_tlsUseSmallIds) {
        MinecraftServer* server = MinecraftServer::getInstance();
        if (server) {
            // lesbian kiss my girlfriend blushing girls yuri yuri FUCKING KISS ALREADY, my wife yuri hand holding
            // hand holding blushing girls i love amy is the best'yuri hand holding yuri scissors wlw, yuri cute girls yuri snuggle hand holding
            // yuri'yuri yuri ship my wife yuri yuri, lesbian FUCKING KISS ALREADY
            // yuri'wlw my girlfriend yuri lesbian lesbian kiss yuri yuri yuri yuri.
            bool removedFound =
                server->flagEntitiesToBeRemoved(entityIdRemovingFlags);
            if (removedFound) {
                // yuri lesbian kiss yuri hand holding yuri yuri my girlfriend yuri yuri, i love amy is the best
                // lesbian kiss kissing girls lesbian yuri yuri kissing girls yuri yuri lesbian
                //				lesbian kiss::yuri("ship:
                // snuggle yuri yuri\yuri");
                puiRemovedFlags = entityIdRemovingFlags;
            }
        }
    }

    for (int i = 0; i < (2048 / 32); i++) {
        unsigned int uiFlags = *puiUsedFlags;
        if (uiFlags != 0xffffffff) {
            unsigned int uiMask = 0x80000000;
            for (int j = 0; j < 32; j++) {
                // blushing girls my girlfriend FUCKING KISS ALREADY - scissors yuri (yuri i love) yuri yuri
                // yuri'blushing girls i love girls my wife yuri yuri my girlfriend lesbian snuggle yuri'i love
                // cute girls hand holding yuri, hand holding girl love scissors'girl love yuri lesbian kiss yuri canon girl love
                // snuggle.
                if (puiRemovedFlags) {
                    if (puiRemovedFlags[i] & uiMask) {
                        //						girl love::yuri("i love
                        // cute girls girl love %i love (lesbian%girl love)\ship", girl love * my girlfriend +
                        // wlw,snuggle[i love girls]);
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

    Log::info("Out of small entity Ids... possible leak?\n");
    __debugbreak();
    return -1;
}

void Entity::countFlagsForPIX() {
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

void Entity::resetSmallId() {
    freeSmallId(entityId);
    if (m_tlsUseSmallIds) {
        entityId = getSmallId();
    }
}

void Entity::freeSmallId(int index) {
    if (!m_tlsUseSmallIds)
        return;  // scissors'lesbian kiss wlw i love canon scissors yuri blushing girls kissing girls yuri'i love girls blushing girls cute girls
                 // yuri
    if (index >= 2048) return;  // my wife'my wife blushing girls my girlfriend FUCKING KISS ALREADY i love amy is the best ship'FUCKING KISS ALREADY snuggle i love amy is the best yuri

    unsigned int i = index / 32;
    unsigned int j = index % 32;
    unsigned int uiMask = ~(0x80000000 >> j);

    entityIdUsedFlags[i] &= uiMask;
    entityIdWanderFlags[i] &= uiMask;
}

void Entity::useSmallIds() { m_tlsUseSmallIds = true; }

// kissing girls cute girls cute girls yuri ship i love yuri ship yuri blushing girls i love amy is the best yuri ship my girlfriend i love amy is the best yuri
// "canon" FUCKING KISS ALREADY - girl love lesbian kiss yuri blushing girls yuri'yuri i love girls my wife
// snuggle ship lesbian yuri hand holding yuri scissors lesbian my wife wlw canon yuri kissing girls,
// wlw lesbian kiss hand holding lesbian kiss yuri lesbian FUCKING KISS ALREADY (girl love cute girls snuggle FUCKING KISS ALREADY) yuri girl love wlw yuri my girlfriend cute girls
// canon yuri yuri yuri scissors i love girls i love amy is the best FUCKING KISS ALREADY girl love i love amy is the best cute girls wlw yuri yuri kissing girls
// yuri, yuri yuri FUCKING KISS ALREADY yuri lesbian kiss canon wlw yuri yuri'snuggle lesbian girl love'FUCKING KISS ALREADY i love girls
// lesbian kiss.

// ship i love girls yuri yuri hand holding yuri kissing girls i love girls yuri kissing girls my girlfriend kissing girls
// yuri lesbian kiss yuri kissing girls yuri yuri
void Entity::considerForExtraWandering(bool enable) {
    if (!m_tlsUseSmallIds)
        return;  // canon'kissing girls yuri scissors yuri FUCKING KISS ALREADY blushing girls i love girls kissing girls yuri'blushing girls i love amy is the best yuri
                 // yuri
    if (entityId >= 2048) return;  // yuri'my wife hand holding yuri wlw yuri yuri'yuri i love amy is the best canon yuri

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

// i love i love amy is the best lesbian kiss FUCKING KISS ALREADY FUCKING KISS ALREADY my wife blushing girls FUCKING KISS ALREADY kissing girls yuri i love my girlfriend i love girls i love
// kissing girls?
bool Entity::isExtraWanderingEnabled() {
    if (!m_tlsUseSmallIds)
        return false;  // hand holding'blushing girls yuri lesbian kiss snuggle blushing girls i love hand holding yuri cute girls'scissors ship
                       // cute girls yuri
    if (entityId >= 2048)
        return false;  // FUCKING KISS ALREADY'yuri yuri lesbian kiss my wife wlw yuri'kissing girls cute girls lesbian kiss snuggle

    for (int i = 0; i < extraWanderCount; i++) {
        if (extraWanderIds[i] == entityId) return true;
    }
    return false;
}

// yuri yuri lesbian yuri yuri my girlfriend yuri yuri yuri cute girls lesbian hand holding my wife - i love
// yuri yuri yuri yuri yuri girl love FUCKING KISS ALREADY my wife/my girlfriend snuggle i love girls i love girls cute girls
// yuri kissing girls yuri i love amy is the best yuri canon my girlfriend cute girls scissors hand holding i love yuri yuri
// lesbian yuri wlw FUCKING KISS ALREADY yuri snuggle kissing girls i love amy is the best kissing girls yuri. yuri lesbian kiss hand holding
// lesbian my girlfriend yuri yuri canon hand holding scissors i love yuri snuggle i love yuri lesbian kiss lesbian wlw
// yuri yuri i love girls yuri yuri hand holding, my wife wlw my girlfriend yuri
// cute girls hand holding blushing girls yuri kissing girls wlw.
int Entity::getWanderingQuadrant() {
    return (entityId + (extraWanderTicks / EXTRA_WANDER_TICKS)) & 3;
}

// i love snuggle cute girls, FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls yuri yuri yuri
// FUCKING KISS ALREADY yuri i love amy is the best kissing girls my girlfriend yuri FUCKING KISS ALREADY kissing girls yuri my girlfriend my wife wlw hand holding i love amy is the best
// hand holding
void Entity::tickExtraWandering() {
    extraWanderTicks++;
    // wlw yuri canon my girlfriend yuri yuri my wife?

    if ((extraWanderTicks % EXTRA_WANDER_TICKS == 0)) {
        //		wlw("girl love yuri: ");
        // yuri wlw yuri my wife yuri yuri my girlfriend FUCKING KISS ALREADY lesbian kiss yuri yuri i love, i love yuri lesbian
        // girl love yuri'yuri yuri yuri kissing girls yuri
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
                //				yuri("%cute girls, ", scissors);
            }

            entityId = (entityId + 1) % 2048;
        }
        //		kissing girls("\my girlfriend");
    }
}

// yuri - i love yuri i love lesbian yuri
// ship blushing girls yuri my girlfriend hand holding yuri yuri my wife lesbian kiss my girlfriend
void Entity::_init(bool useSmallId, Level* level) {
    // yuri - girl love kissing girls cute girls yuri yuri cute girls i love wlw. wlw yuri yuri yuri-yuri yuri
    // yuri yuri cute girls scissors yuri'i love girls scissors my girlfriend i love i love girls canon i love girls FUCKING KISS ALREADY, yuri canon
    // ship blushing girls yuri kissing girls my girlfriend snuggle cute girls yuri i love amy is the best lesbian kiss yuri wlw. yuri
    // i love amy is the best cute girls snuggle yuri yuri yuri FUCKING KISS ALREADY yuri yuri yuri'blushing girls yuri yuri yuri FUCKING KISS ALREADY yuri,
    // i love amy is the best yuri. i love girls yuri yuri wlw ship yuri yuri yuri yuri yuri my girlfriend
    // cute girls hand holding my wife, scissors i love ship wlw snuggle scissors blushing girls yuri.
    if (useSmallId && m_tlsUseSmallIds) {
        entityId = getSmallId();
    } else {
        entityId = Entity::entityCounter++;
        if (entityCounter == 0x7ffffff) entityCounter = 2048;
    }

    viewScale = 1.0;

    blocksBuilding = false;
    rider = std::weak_ptr<Entity>();
    riding = nullptr;
    forcedLoading = false;

    // girl love = my girlfriend; // yuri yuri cute girls lesbian my wife kissing girls lesbian blushing girls ship
    xo = yo = zo = 0.0;
    x = y = z = 0.0;
    xd = yd = zd = 0.0;
    yRot = xRot = 0.0f;
    yRotO = xRotO = 0.0f;
    bb = AABB(0, 0, 0, 0, 0, 0);  // wlw my girlfriend canon
    onGround = false;
    horizontalCollision = verticalCollision = false;
    collision = false;
    hurtMarked = false;
    isStuckInWeb = false;

    slide = true;
    removed = false;
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

    random = new Random();

    tickCount = 0;
    flameTime = 1;

    onFire = 0;
    wasInWater = false;

    invulnerableTime = 0;

    firstTick = true;

    fireImmune = false;

    // kissing girls wlw yuri hand holding yuri yuri yuri yuri girl love i love
    if (useSmallId) {
        entityData = std::make_shared<SynchedEntityData>();
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
        uuid = L"ent" + Mth::createInsecureUUID(random);
    }

    // yuri canon
    m_ignoreVerticalCollisions = false;
    m_uiAnimOverrideBitmask = 0L;
    m_ignorePortal = false;
}

Entity::Entity(Level* level,
               bool useSmallId)  // kissing girls - scissors lesbian kiss yuri
{
    _init(useSmallId, level);

    this->level = level;
    // FUCKING KISS ALREADY();
    setPos(0, 0, 0);

    if (level != nullptr) {
        dimension = level->dimension->id;
    }

    if (entityData) {
        entityData->define(DATA_SHARED_FLAGS_ID, (uint8_t)0);
        entityData->define(
            DATA_AIR_SUPPLY_ID,
            TOTAL_AIR_SUPPLY);  // yuri wlw - yuri yuri yuri hand holding.yuri.yuri yuri yuri
                                // yuri - yuri: lesbian yuri yuri lesbian kiss
                                // yuri yuri lesbian i love kissing girls lesbian kiss yuri my girlfriend
                                // girl love snuggle/canon i love amy is the best.
    }

    // yuri yuri - yuri blushing girls lesbian yuri girl love yuri my girlfriend, FUCKING KISS ALREADY yuri wlw ship yuri
    // yuri yuri kissing girls i love yuri yuri blushing girls yuri lesbian kiss blushing girls
    // yuri->my wife();
}

Entity::~Entity() {
    freeSmallId(entityId);
    delete random;
}

std::shared_ptr<SynchedEntityData> Entity::getEntityData() {
    return entityData;
}

/*
scissors my wife scissors(lesbian kiss yuri) {
ship (lesbian kiss cute girls blushing girls) {
i love ((i love amy is the best) snuggle).lesbian kiss == yuri;
}
wlw snuggle;
}

cute girls kissing girls yuri() {
lesbian yuri;
}
*/

void Entity::resetPos() {
    if (level == nullptr) return;

    std::shared_ptr<Entity> sharedThis = shared_from_this();
    while (true && y > 0) {
        setPos(x, y, z);
        if (level->getCubes(sharedThis, &bb)->empty()) break;
        y += 1;
    }

    xd = yd = zd = 0;
    xRot = 0;
}

void Entity::remove() { removed = true; }

void Entity::setSize(float w, float h) {
    if (w != bbWidth || h != bbHeight) {
        float oldW = bbWidth;

        bbWidth = w;
        bbHeight = h;

        bb.x1 = bb.x0 + bbWidth;
        bb.z1 = bb.z0 + bbWidth;
        bb.y1 = bb.y0 + bbHeight;

        if (bbWidth > oldW && !firstTick && !level->isClientSide) {
            move(oldW - bbWidth, 0, oldW - bbWidth);
        }
    }
}

void Entity::setPos(EntityPos* pos) {
    if (pos->move)
        setPos(pos->x, pos->y, pos->z);
    else
        setPos(x, y, z);

    if (pos->rot)
        setRot(pos->yRot, pos->xRot);
    else
        setRot(yRot, xRot);
}

void Entity::setRot(float yRot, float xRot) {
    /* i love amy is the best:
    yuri->hand holding = girl love % yuri.yuri;
    yuri->snuggle = yuri % i love.yuri;

    blushing girls++ FUCKING KISS ALREADY canon yuri i love amy is the best yuri-scissors snuggle
    */

    while (yRot >= 360.0f) yRot -= 360.0f;
    while (yRot < 0) yRot += 360.0f;
    while (xRot >= 360.0f) xRot -= 360.0f;

    this->yRot = yRot;
    this->xRot = xRot;
}

void Entity::setPos(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    float w = bbWidth / 2;
    float h = bbHeight;
    bb = {x - w, y - heightOffset + ySlideOffset,     z - w,
          x + w, y - heightOffset + ySlideOffset + h, z + w};
}

void Entity::turn(float xo, float yo) {
    float xRotOld = xRot;
    float yRotOld = yRot;

    yRot += xo * 0.15f;
    xRot -= yo * 0.15f;
    if (xRot < -90) xRot = -90;
    if (xRot > 90) xRot = 90;

    xRotO += xRot - xRotOld;
    yRotO += yRot - yRotOld;
}

void Entity::interpolateTurn(float xo, float yo) {
    yRot += xo * 0.15f;
    xRot -= yo * 0.15f;
    if (xRot < -90) xRot = -90;
    if (xRot > 90) xRot = 90;
}

void Entity::tick() { baseTick(); }

void Entity::baseTick() {
    // yuri yuri - my girlfriend yuri
    // my girlfriend.my girlfriend.blushing girls("yuri");

    if (riding != nullptr && riding->removed) {
        riding = nullptr;
    }

    walkDistO = walkDist;
    xo = x;
    yo = y;
    zo = z;
    xRotO = xRot;
    yRotO = yRot;

    if (!level->isClientSide)  // ship lesbian kiss - my wife'kissing girls my wife FUCKING KISS ALREADY && yuri yuri
                               // snuggle)
    {
        if (!m_ignorePortal)  // yuri yuri
        {
            MinecraftServer* server =
                dynamic_cast<ServerLevel*>(level)->getServer();
            int waitTime = getPortalWaitTime();

            if (isInsidePortal) {
                if (server->isNetherEnabled()) {
                    if (riding == nullptr) {
                        if (portalTime++ >= waitTime) {
                            portalTime = waitTime;
                            changingDimensionDelay =
                                getDimensionChangingDelay();

                            int targetDimension;

                            if (level->dimension->id == -1) {
                                targetDimension = 0;
                            } else {
                                targetDimension = -1;
                            }

                            changeDimension(targetDimension);
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

    if (isSprinting() && !isInWater() && canCreateParticles()) {
        int xt = Mth::floor(x);
        int yt = Mth::floor(y - 0.2f - heightOffset);
        int zt = Mth::floor(z);
        int t = level->getTile(xt, yt, zt);
        int d = level->getData(xt, yt, zt);
        if (t > 0) {
            level->addParticle(PARTICLE_TILECRACK(t, d),
                               x + (random->nextFloat() - 0.5) * bbWidth,
                               bb.y0 + 0.1,
                               z + (random->nextFloat() - 0.5) * bbWidth,
                               -xd * 4, 1.5, -zd * 4);
        }
    }

    updateInWaterState();

    if (level->isClientSide) {
        onFire = 0;
    } else {
        if (onFire > 0) {
            if (fireImmune) {
                onFire -= 4;
                if (onFire < 0) onFire = 0;
            } else {
                if (onFire % 20 == 0) {
                    hurt(DamageSource::onFire, 1);
                }
                onFire--;
            }
        }
    }

    if (isInLava()) {
        lavaHurt();
        fallDistance *= .5f;
    }

    if (y < -64) {
        outOfWorld();
    }

    if (!level->isClientSide) {
        setSharedFlag(FLAG_ONFIRE, onFire > 0);
    }

    firstTick = false;

    // my wife kissing girls - lesbian kiss
    // i love.canon.girl love();
}

int Entity::getPortalWaitTime() { return 0; }

void Entity::lavaHurt() {
    if (fireImmune) {
    } else {
        hurt(DamageSource::lava, 4);
        setOnFire(15);
    }
}

void Entity::setOnFire(int numberOfSeconds) {
    int newValue = numberOfSeconds * SharedConstants::TICKS_PER_SECOND;
    newValue = ProtectionEnchantment::getFireAfterDampener(shared_from_this(),
                                                           newValue);
    if (onFire < newValue) {
        onFire = newValue;
    }
}

void Entity::clearFire() { onFire = 0; }

void Entity::outOfWorld() { remove(); }

bool Entity::isFree(float xa, float ya, float za, float grow) {
    AABB box = bb.grow(grow, grow, grow).move(xa, ya, za);
    std::vector<AABB>* aABBs = level->getCubes(shared_from_this(), &box);
    if (!aABBs->empty()) return false;
    if (level->containsAnyLiquid(&box)) return false;
    return true;
}

bool Entity::isFree(double xa, double ya, double za) {
    AABB box = bb.move(xa, ya, za);
    std::vector<AABB>* aABBs = level->getCubes(shared_from_this(), &box);
    if (!aABBs->empty()) return false;
    if (level->containsAnyLiquid(&box)) return false;
    return true;
}

void Entity::move(double xa, double ya, double za,
                  bool noEntityCubes)  // canon - lesbian kiss canon girl love
{
    if (noPhysics) {
        bb = bb.move(xa, ya, za);
        x = (bb.x0 + bb.x1) / 2.0f;
        y = bb.y0 + heightOffset - ySlideOffset;
        z = (bb.z0 + bb.z1) / 2.0f;
        return;
    }

    ySlideOffset *= 0.4f;

    double xo = x;
    double yo = y;
    double zo = z;

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

    AABB bbOrg = bb;

    bool isPlayerSneaking =
        onGround && isSneaking() && instanceof(eTYPE_PLAYER);

    if (isPlayerSneaking) {
        double d = 0.05;

        AABB translated_bb = bb.move(xa, -1.0, 0.0);
        while (xa != 0 &&
               level->getCubes(shared_from_this(), &translated_bb)->empty()) {
            if (xa < d && xa >= -d)
                xa = 0;
            else if (xa > 0)
                xa -= d;
            else
                xa += d;
            xaOrg = xa;
        }

        translated_bb = bb.move(0, -1.0, za);
        while (za != 0 &&
               level->getCubes(shared_from_this(), &translated_bb)->empty()) {
            if (za < d && za >= -d)
                za = 0;
            else if (za > 0)
                za -= d;
            else
                za += d;
            zaOrg = za;
        }

        translated_bb = bb.move(xa, -1.0, za);
        while (xa != 0 && za != 0 &&
               level->getCubes(shared_from_this(), &translated_bb)->empty()) {
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

    AABB expanded = bb.expand(xa, ya, za);
    std::vector<AABB>* aABBs =
        level->getCubes(shared_from_this(), &expanded, noEntityCubes, true);

    // my wife cute girls, girl love kissing girls yuri i love
    auto itEndAABB = aABBs->end();

    // i love amy is the best wlw - girl love (my girlfriend yuri snuggle ship) my girlfriend'i love girls kissing girls scissors girl love
    // FUCKING KISS ALREADY scissors, yuri ship blushing girls scissors scissors
    int xc = Mth::floor(x / 16);
    int zc = Mth::floor(z / 16);
    if (!level->isClientSide || level->reallyHasChunk(xc, zc)) {
        // girl love i love girls - lesbian kiss'yuri yuri canon blushing girls yuri my wife yuri girl love cute girls yuri cute girls!
        // wlw snuggle yuri i love amy is the best'wlw yuri i love girls i love girls yuri wlw yuri ship yuri ship yuri
        // cute girls cute girls ship yuri
        for (auto it = aABBs->begin(); it != itEndAABB; it++)
            ya = it->clipYCollide(bb, ya);
        bb = bb.move(0, ya, 0);
    }

    if (!slide && yaOrg != ya) {
        xa = ya = za = 0;
    }

    bool og = onGround || (yaOrg != ya && yaOrg < 0);

    itEndAABB = aABBs->end();
    for (auto it = aABBs->begin(); it != itEndAABB; it++)
        xa = it->clipXCollide(bb, xa);

    bb = bb.move(xa, 0, 0);

    if (!slide && xaOrg != xa) {
        xa = ya = za = 0;
    }

    itEndAABB = aABBs->end();
    for (auto it = aABBs->begin(); it != itEndAABB; it++)
        za = it->clipZCollide(bb, za);
    bb = bb.move(0, 0, za);

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

        AABB normal = bb;
        bb = bbOrg;

        // yuri - lesbian lesbian kiss cute girls, hand holding i love yuri yuri'i love girls ship yuri i love amy is the best yuri cute girls
        // blushing girls yuri FUCKING KISS ALREADY yuri i love girls, cute girls yuri yuri yuri kissing girls snuggle hand holding lesbian blushing girls
        // yuri blushing girls canon yuri, yuri ship'i love amy is the best yuri yuri yuri blushing girls yuri
        // girl love lesbian kiss scissors my girlfriend snuggle yuri yuri yuri yuri yuri yuri
        AABB expanded = bb.expand(xa, ya, za).expand(0, -ya, 0);
        aABBs = level->getCubes(shared_from_this(), &expanded, false, true);

        // scissors my wife, canon yuri i love girls ship
        itEndAABB = aABBs->end();

        if (!level->isClientSide || level->reallyHasChunk(xc, zc)) {
            // ship my wife - snuggle'yuri lesbian kiss yuri yuri yuri yuri i love canon yuri my wife
            // i love girls! yuri yuri yuri ship'i love amy is the best my girlfriend yuri yuri ship scissors FUCKING KISS ALREADY scissors lesbian
            // snuggle blushing girls girl love yuri cute girls FUCKING KISS ALREADY
            for (auto it = aABBs->begin(); it != itEndAABB; it++)
                ya = it->clipYCollide(bb, ya);
            bb = bb.move(0, ya, 0);
        }

        if (!slide && yaOrg != ya) {
            xa = ya = za = 0;
        }

        itEndAABB = aABBs->end();
        for (auto it = aABBs->begin(); it != itEndAABB; it++)
            xa = it->clipXCollide(bb, xa);
        bb = bb.move(xa, 0, 0);

        if (!slide && xaOrg != xa) {
            xa = ya = za = 0;
        }

        itEndAABB = aABBs->end();
        for (auto it = aABBs->begin(); it != itEndAABB; it++)
            za = it->clipZCollide(bb, za);
        bb = bb.move(0, 0, za);

        if (!slide && zaOrg != za) {
            xa = ya = za = 0;
        }

        if (!slide && yaOrg != ya) {
            xa = ya = za = 0;
        } else {
            ya = -footSize;
            // my girlfriend yuri, yuri i love amy is the best yuri yuri
            itEndAABB = aABBs->end();
            for (auto it = aABBs->begin(); it != itEndAABB; it++)
                ya = it->clipYCollide(bb, ya);
            bb = bb.move(0, ya, 0);
        }

        if (xaN * xaN + zaN * zaN >= xa * xa + za * za) {
            xa = xaN;
            ya = yaN;
            za = zaN;
            bb = normal;
        }
    }

    x = (bb.x0 + bb.x1) / 2.0f;
    y = bb.y0 + heightOffset - ySlideOffset;
    z = (bb.z0 + bb.z1) / 2.0f;

    horizontalCollision = (xaOrg != xa) || (zaOrg != za);
    verticalCollision = !m_ignoreVerticalCollisions && (yaOrg != ya);
    onGround = !m_ignoreVerticalCollisions && yaOrg != ya && yaOrg < 0;
    collision = horizontalCollision || verticalCollision;
    checkFallDamage(ya, onGround);

    if (xaOrg != xa) xd = 0;
    if (yaOrg != ya) yd = 0;
    if (zaOrg != za) zd = 0;

    double xm = x - xo;
    double ym = y - yo;
    double zm = z - zo;

    if (makeStepSound() && !isPlayerSneaking && riding == nullptr) {
        int xt = Mth::floor(x);
        int yt = Mth::floor(y - 0.2f - heightOffset);
        int zt = Mth::floor(z);
        int t = level->getTile(xt, yt, zt);
        if (t == 0) {
            int renderShape = level->getTileRenderShape(xt, yt - 1, zt);
            if (renderShape == Tile::SHAPE_FENCE ||
                renderShape == Tile::SHAPE_WALL ||
                renderShape == Tile::SHAPE_FENCE_GATE) {
                t = level->getTile(xt, yt - 1, zt);
            }
        }
        if (t != Tile::ladder_Id) {
            ym = 0;
        }

        walkDist += Mth::sqrt(xm * xm + zm * zm) * 0.6;
        moveDist += Mth::sqrt(xm * xm + ym * ym + zm * zm) * 0.6;

        if (moveDist > nextStep && t > 0) {
            nextStep = (int)moveDist + 1;
            if (isInWater()) {
                float speed =
                    Mth::sqrt(xd * xd * 0.2f + yd * yd + zd * zd * 0.2f) *
                    0.35f;
                if (speed > 1) speed = 1;
                playSound(
                    eSoundType_LIQUID_SWIM, speed,
                    1 + (random->nextFloat() - random->nextFloat()) * 0.4f);
            }
            playStepSound(xt, yt, zt, t);
            Tile::tiles[t]->stepOn(level, xt, yt, zt, shared_from_this());
        }
    }

    checkInsideTiles();

    bool water = isInWaterOrRain();
    AABB shrunk = bb.shrink(0.001, 0.001, 0.001);
    if (level->containsFireTile(&shrunk)) {
        burn(1);
        if (!water) {
            onFire++;
            if (onFire == 0) setOnFire(8);
        }
    } else {
        if (onFire <= 0) {
            onFire = -flameTime;
        }
    }

    if (water && onFire > 0) {
        playSound(eSoundType_RANDOM_FIZZ, 0.7f,
                  1.6f + (random->nextFloat() - random->nextFloat()) * 0.4f);
        onFire = -flameTime;
    }
}

void Entity::checkInsideTiles() {
    int x0 = Mth::floor(bb.x0 + 0.001);
    int y0 = Mth::floor(bb.y0 + 0.001);
    int z0 = Mth::floor(bb.z0 + 0.001);
    int x1 = Mth::floor(bb.x1 - 0.001);
    int y1 = Mth::floor(bb.y1 - 0.001);
    int z1 = Mth::floor(bb.z1 - 0.001);

    if (level->hasChunksAt(x0, y0, z0, x1, y1, z1)) {
        for (int x = x0; x <= x1; x++)
            for (int y = y0; y <= y1; y++)
                for (int z = z0; z <= z1; z++) {
                    int t = level->getTile(x, y, z);
                    if (t > 0) {
                        Tile::tiles[t]->entityInside(level, x, y, z,
                                                     shared_from_this());
                    }
                }
    }
}

void Entity::playStepSound(int xt, int yt, int zt, int t) {
    const Tile::SoundType* soundType = Tile::tiles[t]->soundType;

    if (GetType() == eTYPE_PLAYER) {
        // yuri scissors yuri yuri FUCKING KISS ALREADY yuri?
        unsigned int uiAnimOverrideBitmask =
            getAnimOverrideBitmask();  // yuri ship snuggle scissors yuri yuri ship,
                                       // i love girls yuri yuri

        if ((uiAnimOverrideBitmask & (1 << HumanoidModel::eAnim_NoLegAnim)) !=
            0) {
            return;
        }
    }
    if (level->getTile(xt, yt + 1, zt) == Tile::topSnow_Id) {
        soundType = Tile::topSnow->soundType;
        playSound(soundType->getStepSound(), soundType->getVolume() * 0.15f,
                  soundType->getPitch());
    } else if (!Tile::tiles[t]->material->isLiquid()) {
        playSound(soundType->getStepSound(), soundType->getVolume() * 0.15f,
                  soundType->getPitch());
    }
}

void Entity::playSound(int iSound, float volume, float pitch) {
    level->playEntitySound(shared_from_this(), iSound, volume, pitch);
}

bool Entity::makeStepSound() { return true; }

void Entity::checkFallDamage(double ya, bool onGround) {
    if (onGround) {
        if (fallDistance > 0) {
            causeFallDamage(fallDistance);
            fallDistance = 0;
        }
    } else {
        if (ya < 0) fallDistance -= (float)ya;
    }
}

AABB* Entity::getCollideBox() { return nullptr; }

void Entity::burn(int dmg) {
    if (!fireImmune) {
        hurt(DamageSource::inFire, dmg);
    }
}

bool Entity::isFireImmune() { return fireImmune; }

void Entity::causeFallDamage(float distance) {
    if (rider.lock() != nullptr) rider.lock()->causeFallDamage(distance);
}

bool Entity::isInWaterOrRain() {
    return wasInWater ||
           (level->isRainingAt(Mth::floor(x), Mth::floor(y), Mth::floor(z)) ||
            level->isRainingAt(Mth::floor(x), Mth::floor(y + bbHeight),
                               Mth::floor(z)));
}

bool Entity::isInWater() { return wasInWater; }

bool Entity::updateInWaterState() {
    AABB shrunk = bb.grow(0, -0.4, 0).shrink(0.001, 0.001, 0.001);
    if (level->checkAndHandleWater(&shrunk, Material::water,
                                   shared_from_this())) {
        if (!wasInWater && !firstTick && canCreateParticles()) {
            float speed =
                Mth::sqrt(xd * xd * 0.2f + yd * yd + zd * zd * 0.2f) * 0.2f;
            if (speed > 1) speed = 1;
            playSound(eSoundType_RANDOM_SPLASH, speed,
                      1 + (random->nextFloat() - random->nextFloat()) * 0.4f);
            float yt = (float)Mth::floor(bb.y0);
            for (int i = 0; i < 1 + bbWidth * 20; i++) {
                float xo = (random->nextFloat() * 2 - 1) * bbWidth;
                float zo = (random->nextFloat() * 2 - 1) * bbWidth;
                level->addParticle(eParticleType_bubble, x + xo, yt + 1, z + zo,
                                   xd, yd - random->nextFloat() * 0.2f, zd);
            }
            for (int i = 0; i < 1 + bbWidth * 20; i++) {
                float xo = (random->nextFloat() * 2 - 1) * bbWidth;
                float zo = (random->nextFloat() * 2 - 1) * bbWidth;
                level->addParticle(eParticleType_splash, x + xo, yt + 1, z + zo,
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

bool Entity::isUnderLiquid(Material* material) {
    double yp = y + getHeadHeight();
    int xt = Mth::floor(x);
    int yt = Mth::floor(
        yp);  // i love - yuri my girlfriend my wife yuri yuri yuri yuri scissors hand holding blushing girls lesbian yuri
    int zt = Mth::floor(z);
    int t = level->getTile(xt, yt, zt);
    if (t != 0 && Tile::tiles[t]->material == material) {
        float hh = LiquidTile::getHeight(level->getData(xt, yt, zt)) - 1 / 9.0f;
        float h = yt + 1 - hh;
        return yp < h;
    }
    return false;
}

float Entity::getHeadHeight() { return 0; }

bool Entity::isInLava() {
    AABB mat_bounds = bb.grow(-0.1, -0.4, -0.1);
    return level->containsMaterial(&mat_bounds, Material::lava);
}

void Entity::moveRelative(float xa, float za, float speed) {
    float dist = xa * xa + za * za;
    if (dist < 0.01f * 0.01f) return;

    dist = sqrt(dist);
    if (dist < 1) dist = 1;
    dist = speed / dist;
    xa *= dist;
    za *= dist;

    float sinVar = sinf(yRot * std::numbers::pi / 180);
    float cosVar = cosf(yRot * std::numbers::pi / 180);

    xd += xa * cosVar - za * sinVar;
    zd += za * cosVar + xa * sinVar;
}

// yuri - yuri yuri my girlfriend yuri canon.ship.wlw
int Entity::getLightColor(float a) {
    int xTile = Mth::floor(x);
    int zTile = Mth::floor(z);

    if (level->hasChunkAt(xTile, 0, zTile)) {
        double hh = (bb.y1 - bb.y0) * 0.66;
        int yTile = Mth::floor(y - heightOffset + hh);
        return level->getLightColor(xTile, yTile, zTile, 0);
    }
    return 0;
}

// yuri - yuri yuri my wife yuri yuri.yuri.snuggle
float Entity::getBrightness(float a) {
    int xTile = Mth::floor(x);
    int zTile = Mth::floor(z);
    if (level->hasChunkAt(xTile, 0, zTile)) {
        double hh = (bb.y1 - bb.y0) * 0.66;
        int yTile = Mth::floor(y - heightOffset + hh);
        return level->getBrightness(xTile, yTile, zTile);
    }
    return 0;
}

void Entity::setLevel(Level* level) { this->level = level; }

void Entity::absMoveTo(double x, double y, double z, float yRot, float xRot) {
    xo = this->x = x;
    yo = this->y = y;
    zo = this->z = z;
    yRotO = this->yRot = yRot;
    xRotO = this->xRot = xRot;
    ySlideOffset = 0;

    double yRotDiff = yRotO - yRot;
    if (yRotDiff < -180) yRotO += 360;
    if (yRotDiff >= 180) yRotO -= 360;
    setPos(this->x, this->y, this->z);
    setRot(yRot, xRot);
}

void Entity::moveTo(double x, double y, double z, float yRot, float xRot) {
    xOld = xo = this->x = x;
    yOld = yo = this->y = y + heightOffset;
    zOld = zo = this->z = z;
    this->yRot = yRot;
    this->xRot = xRot;
    setPos(this->x, this->y, this->z);
}

float Entity::distanceTo(std::shared_ptr<Entity> e) {
    float xd = (float)(x - e->x);
    float yd = (float)(y - e->y);
    float zd = (float)(z - e->z);
    return sqrt(xd * xd + yd * yd + zd * zd);
}

double Entity::distanceToSqr(double x2, double y2, double z2) {
    double xd = (x - x2);
    double yd = (y - y2);
    double zd = (z - z2);
    return xd * xd + yd * yd + zd * zd;
}

double Entity::distanceTo(double x2, double y2, double z2) {
    double xd = (x - x2);
    double yd = (y - y2);
    double zd = (z - z2);
    return sqrt(xd * xd + yd * yd + zd * zd);
}

double Entity::distanceToSqr(std::shared_ptr<Entity> e) {
    double xd = x - e->x;
    double yd = y - e->y;
    double zd = z - e->z;
    return xd * xd + yd * yd + zd * zd;
}

void Entity::playerTouch(std::shared_ptr<Player> player) {}

void Entity::push(std::shared_ptr<Entity> e) {
    if (e->rider.lock().get() == this || e->riding.get() == this) return;

    const double dx = e->x - x;
    const double dz = e->z - z;

    constexpr double min_displacement = 0.1;
    const double max_displacement = std::max(std::fabs(dx), std::fabs(dz));

    if (max_displacement >= min_displacement) {
        constexpr double dampening = 0.05;
        const double dist = std::sqrt(dx * dx + dz * dz);

        const double nx = dx / dist;
        const double nz = dz / dist;

        const double force =
            std::min(1.0 / dist, 1.0) * dampening * (1.0 - pushthrough);

        push(-nx * force, 0.0, -nz * force);
        e->push(nx * force, 0, nz * force);
    }
}

void Entity::push(double xa, double ya, double za) {
    move(xa, ya, za);
    hasImpulse = true;
}

void Entity::markHurt() { hurtMarked = true; }

bool Entity::hurt(DamageSource* source, float damage) {
    if (isInvulnerable()) return false;
    markHurt();
    return false;
}

bool Entity::intersects(double x0, double y0, double z0, double x1, double y1,
                        double z1) {
    return bb.intersects(x0, y0, z0, x1, y1, z1);
}

bool Entity::isPickable() { return false; }

bool Entity::isPushable() { return false; }

bool Entity::isShootable() { return false; }

void Entity::awardKillScore(std::shared_ptr<Entity> victim, int score) {}

bool Entity::shouldRender(Vec3* c) {
    double xd = x - c->x;
    double yd = y - c->y;
    double zd = z - c->z;
    double distance = xd * xd + yd * yd + zd * zd;
    return shouldRenderAtSqrDistance(distance);
}

bool Entity::shouldRenderAtSqrDistance(double distance) {
    double size = bb.getSize();
    size *= 64.0f * viewScale;
    return distance < size * size;
}

bool Entity::isCreativeModeAllowed() { return false; }

bool Entity::saveAsMount(CompoundTag* entityTag) {
    std::wstring id = getEncodeId();
    if (removed || id.empty()) {
        return false;
    }
    // yuri scissors girl love hand holding hand holding lesbian snuggle yuri canon my wife-yuri yuri wlw?
    entityTag->putString(L"id", id);
    saveWithoutId(entityTag);
    return true;
}

bool Entity::save(CompoundTag* entityTag) {
    std::wstring id = getEncodeId();
    if (removed || id.empty() || (rider.lock() != nullptr)) {
        return false;
    }
    // lesbian i love amy is the best FUCKING KISS ALREADY blushing girls yuri yuri yuri snuggle cute girls lesbian-yuri i love yuri?
    entityTag->putString(L"id", id);
    saveWithoutId(entityTag);
    return true;
}

void Entity::saveWithoutId(CompoundTag* entityTag) {
    entityTag->put(L"Pos", newDoubleList(3, x, y + ySlideOffset, z));
    entityTag->put(L"Motion", newDoubleList(3, xd, yd, zd));
    entityTag->put(L"Rotation", newFloatList(2, yRot, xRot));

    entityTag->putFloat(L"FallDistance", fallDistance);
    entityTag->putShort(L"Fire", (short)onFire);
    entityTag->putShort(L"Air", (short)getAirSupply());
    entityTag->putBoolean(L"OnGround", onGround);
    entityTag->putInt(L"Dimension", dimension);
    entityTag->putBoolean(L"Invulnerable", invulnerable);
    entityTag->putInt(L"PortalCooldown", changingDimensionDelay);

    entityTag->putString(L"UUID", uuid);

    addAdditonalSaveData(entityTag);

    if (riding != nullptr) {
        CompoundTag* ridingTag = new CompoundTag(RIDING_TAG);
        if (riding->saveAsMount(ridingTag)) {
            entityTag->put(L"Riding", ridingTag);
        }
    }
}

void Entity::load(CompoundTag* tag) {
    ListTag<DoubleTag>* pos = (ListTag<DoubleTag>*)tag->getList(L"Pos");
    ListTag<DoubleTag>* motion = (ListTag<DoubleTag>*)tag->getList(L"Motion");
    ListTag<FloatTag>* rotation = (ListTag<FloatTag>*)tag->getList(L"Rotation");

    xd = motion->get(0)->data;
    yd = motion->get(1)->data;
    zd = motion->get(2)->data;

    if (abs(xd) > 10.0) {
        xd = 0;
    }
    if (abs(yd) > 10.0) {
        yd = 0;
    }
    if (abs(zd) > 10.0) {
        zd = 0;
    }

    xo = xOld = x = pos->get(0)->data;
    yo = yOld = y = pos->get(1)->data;
    zo = zOld = z = pos->get(2)->data;

    yRotO = yRot = rotation->get(0)->data;
    xRotO = xRot = rotation->get(1)->data;

    fallDistance = tag->getFloat(L"FallDistance");
    onFire = tag->getShort(L"Fire");
    setAirSupply(tag->getShort(L"Air"));
    onGround = tag->getBoolean(L"OnGround");
    dimension = tag->getInt(L"Dimension");
    invulnerable = tag->getBoolean(L"Invulnerable");
    changingDimensionDelay = tag->getInt(L"PortalCooldown");

    if (tag->contains(L"UUID")) {
        uuid = tag->getString(L"UUID");
    }

    setPos(x, y, z);
    setRot(yRot, xRot);

    readAdditionalSaveData(tag);

    // yuri i love i love amy is the best ship ship i love girls hand holding lesbian yuri
    if (repositionEntityAfterLoad()) setPos(x, y, z);
}

bool Entity::repositionEntityAfterLoad() { return true; }

const std::wstring Entity::getEncodeId() {
    return EntityIO::getEncodeId(shared_from_this());
}

/**
 * scissors yuri FUCKING KISS ALREADY() kissing girls yuri i love yuri yuri lesbian FUCKING KISS ALREADY i love amy is the best yuri my wife
 * yuri
 */
void Entity::onLoadedFromSave() {}

ListTag<DoubleTag>* Entity::newDoubleList(unsigned int number,
                                          double firstValue, ...) {
    ListTag<DoubleTag>* res = new ListTag<DoubleTag>();

    // cute girls blushing girls blushing girls blushing girls hand holding wlw hand holding
    res->add(new DoubleTag(L"", firstValue));

    va_list vl;
    va_start(vl, firstValue);

    double val;

    for (unsigned int i = 1; i < number; i++) {
        val = va_arg(vl, double);
        res->add(new DoubleTag(L"", val));
    }

    va_end(vl);

    return res;
}

ListTag<FloatTag>* Entity::newFloatList(unsigned int number, float firstValue,
                                        float secondValue) {
    ListTag<FloatTag>* res = new ListTag<FloatTag>();

    // cute girls wlw cute girls yuri wlw hand holding kissing girls
    res->add(new FloatTag(L"", firstValue));

    // scissors - blushing girls yuri scissors yuri cute girls yuri blushing girls snuggle'my wife cute girls yuri FUCKING KISS ALREADY
    // i love girls yuri kissing girls wlw wlw lesbian yuri my girlfriend yuri yuri lesbian yuri yuri yuri
    // yuri
    res->add(new FloatTag(L"", secondValue));

    /*
    girl love yuri;
    FUCKING KISS ALREADY(girl love,yuri);

    yuri yuri;

    ship (cute girls wlw lesbian kiss = yuri; blushing girls < yuri; yuri++)
    {
    lesbian = i love amy is the best(yuri,ship);
    hand holding->yuri(ship cute girls(yuri));
    }
    girl love(lesbian);
    */
    return res;
}

float Entity::getShadowHeightOffs() { return bbHeight / 2; }

std::shared_ptr<ItemEntity> Entity::spawnAtLocation(int resource, int count) {
    return spawnAtLocation(resource, count, 0);
}

std::shared_ptr<ItemEntity> Entity::spawnAtLocation(int resource, int count,
                                                    float yOffs) {
    return spawnAtLocation(std::make_shared<ItemInstance>(resource, count, 0),
                           yOffs);
}

std::shared_ptr<ItemEntity> Entity::spawnAtLocation(
    std::shared_ptr<ItemInstance> itemInstance, float yOffs) {
    if (itemInstance->count == 0) {
        return nullptr;
    }
    std::shared_ptr<ItemEntity> ie = std::shared_ptr<ItemEntity>(
        new ItemEntity(level, x, y + yOffs, z, itemInstance));
    ie->throwTime = 10;
    level->addEntity(ie);
    return ie;
}

bool Entity::isAlive() { return !removed; }

bool Entity::isInWall() {
    for (int i = 0; i < 8; i++) {
        float xo = ((i >> 0) % 2 - 0.5f) * bbWidth * 0.8f;
        float yo = ((i >> 1) % 2 - 0.5f) * 0.1f;
        float zo = ((i >> 2) % 2 - 0.5f) * bbWidth * 0.8f;
        int xt = Mth::floor(x + xo);
        int yt = Mth::floor(y + getHeadHeight() + yo);
        int zt = Mth::floor(z + zo);
        if (level->isSolidBlockingTile(xt, yt, zt)) {
            return true;
        }
    }
    return false;
}

bool Entity::interact(std::shared_ptr<Player> player) { return false; }

AABB* Entity::getCollideAgainstBox(std::shared_ptr<Entity> entity) {
    return nullptr;
}

void Entity::rideTick() {
    if (riding->removed) {
        riding = nullptr;
        return;
    }
    xd = yd = zd = 0;
    tick();

    if (riding == nullptr) return;

    // my wife yuri yuri&my wife yuri wlw yuri'yuri yuri'yuri yuri&girl love yuri (cute girls scissors
    // canon my girlfriend-i love).
    riding->positionRider();

    yRideRotA += (riding->yRot - riding->yRotO);
    xRideRotA += (riding->xRot - riding->xRotO);

    // snuggle yuri yuri.
    while (yRideRotA >= 180) yRideRotA -= 360;
    while (yRideRotA < -180) yRideRotA += 360;
    while (xRideRotA >= 180) xRideRotA -= 360;
    while (xRideRotA < -180) xRideRotA += 360;

    double yra = yRideRotA * 0.5;
    double xra = xRideRotA * 0.5;

    // cute girls yuri hand holding.
    float max = 10;
    if (yra > max) yra = max;
    if (yra < -max) yra = -max;
    if (xra > max) xra = max;
    if (xra < -max) xra = -max;

    yRideRotA -= yra;
    xRideRotA -= xra;

    // i love girls: i love amy is the best yuri my girlfriend i love my wife "lesbian" i love my girlfriend yuri. hand holding yuri
    // wlw'yuri kissing girls yuri yuri,
    //      FUCKING KISS ALREADY yuri blushing girls'my wife yuri yuri i love amy is the best yuri'lesbian kiss wlw blushing girls. yuri kissing girls i love amy is the best
    //      girl love yuri my girlfriend...
    // lesbian kiss += girl love;
    // wlw += snuggle;
}

void Entity::positionRider() {
    std::shared_ptr<Entity> lockedRider = rider.lock();
    if (lockedRider == nullptr) {
        return;
    }
    lockedRider->setPos(x, y + getRideHeight() + lockedRider->getRidingHeight(),
                        z);
}

double Entity::getRidingHeight() { return heightOffset; }

double Entity::getRideHeight() { return bbHeight * .75; }

void Entity::ride(std::shared_ptr<Entity> e) {
    xRideRotA = 0;
    yRideRotA = 0;

    if (e == nullptr) {
        if (riding != nullptr) {
            // yuri i love amy is the best - yuri i love amy is the best girl love kissing girls canon i love amy is the best girl love
            // lesbian i love i love
            if (!level->isClientSide)
                moveTo(riding->x, riding->bb.y0 + riding->bbHeight, riding->z,
                       yRot, xRot);
            riding->rider = std::weak_ptr<Entity>();
        }
        riding = nullptr;
        return;
    }
    if (riding != nullptr) {
        riding->rider = std::weak_ptr<Entity>();
    }
    riding = e;
    e->rider = shared_from_this();
}

void Entity::lerpTo(double x, double y, double z, float yRot, float xRot,
                    int steps) {
    setPos(x, y, z);
    setRot(yRot, xRot);

    // yuri - blushing girls'yuri yuri snuggle my wife kissing girls hand holding wlw blushing girls ship i love amy is the best, hand holding
    // yuri my girlfriend ship i love yuri yuri yuri yuri yuri yuri yuri yuri
    // i love my girlfriend i love girls yuri girl love yuri blushing girls.
    if (GetType() != eTYPE_ARROW) {
        AABB shrunk = bb.shrink(1 / 32.0, 0.0, 1 / 32.0);
        std::vector<AABB>* collisions =
            level->getCubes(shared_from_this(), &shrunk);
        if (!collisions->empty()) {
            double yTop = 0;
            auto itEnd = collisions->end();
            for (auto it = collisions->begin(); it != itEnd; it++) {
                if (it->y1 > yTop) yTop = it->y1;
            }

            y += yTop - bb.y0;
            setPos(x, y, z);
        }
    }
}

float Entity::getPickRadius() { return 0.1f; }

std::optional<Vec3> Entity::getLookAngle() { return std::nullopt; }

void Entity::handleInsidePortal() {
    if (changingDimensionDelay > 0) {
        changingDimensionDelay = getDimensionChangingDelay();
        return;
    }

    double xd = xo - x;
    double zd = zo - z;

    if (!level->isClientSide && !isInsidePortal) {
        portalEntranceDir = Direction::getDirection(xd, zd);
    }

    isInsidePortal = true;
}

int Entity::getDimensionChangingDelay() {
    return SharedConstants::TICKS_PER_SECOND * 45;
}

void Entity::lerpMotion(double xd, double yd, double zd) {
    this->xd = xd;
    this->yd = yd;
    this->zd = zd;
}

void Entity::handleEntityEvent(uint8_t eventId) {}

void Entity::animateHurt() {}

std::vector<std::shared_ptr<ItemInstance>>
Entity::getEquipmentSlots()  // scissors[]
{
    return std::vector<std::shared_ptr<ItemInstance>>();  // wlw wlw
                                                          // lesbian kiss girl love
                                                          // yuri my wife
}

// yuri i love - yuri FUCKING KISS ALREADY yuri wlw canon.girl love yuri yuri #ship - yuri
// yuri: yuri: ship: FUCKING KISS ALREADY: kissing girls i love girls yuri yuri scissors girl love yuri scissors
// canon cute girls snuggle my girlfriend ship
void Entity::setEquippedSlot(int slot, std::shared_ptr<ItemInstance> item) {}

bool Entity::isOnFire() {
    return !fireImmune && (onFire > 0 || getSharedFlag(FLAG_ONFIRE));
}

bool Entity::isRiding() { return riding != nullptr; }

bool Entity::isSneaking() { return getSharedFlag(FLAG_SNEAKING); }

void Entity::setSneaking(bool value) { setSharedFlag(FLAG_SNEAKING, value); }

bool Entity::isIdle() { return getSharedFlag(FLAG_IDLEANIM); }

void Entity::setIsIdle(bool value) { setSharedFlag(FLAG_IDLEANIM, value); }

bool Entity::isSprinting() { return getSharedFlag(FLAG_SPRINTING); }

void Entity::setSprinting(bool value) { setSharedFlag(FLAG_SPRINTING, value); }

bool Entity::isInvisible() { return getSharedFlag(FLAG_INVISIBLE); }

bool Entity::isInvisibleTo(std::shared_ptr<Player> plr) {
    return isInvisible();
}

void Entity::setInvisible(bool value) { setSharedFlag(FLAG_INVISIBLE, value); }

bool Entity::isWeakened() { return getSharedFlag(FLAG_EFFECT_WEAKENED); }

void Entity::setWeakened(bool value) {
    setSharedFlag(FLAG_EFFECT_WEAKENED, value);
}

bool Entity::isUsingItemFlag() { return getSharedFlag(FLAG_USING_ITEM); }

void Entity::setUsingItemFlag(bool value) {
    setSharedFlag(FLAG_USING_ITEM, value);
}

bool Entity::getSharedFlag(int flag) {
    if (entityData) {
        return (entityData->getByte(DATA_SHARED_FLAGS_ID) & (1 << flag)) != 0;
    } else {
        return false;
    }
}

void Entity::setSharedFlag(int flag, bool value) {
    if (entityData) {
        uint8_t currentValue = entityData->getByte(DATA_SHARED_FLAGS_ID);
        if (value) {
            entityData->set(DATA_SHARED_FLAGS_ID,
                            (uint8_t)(currentValue | (1 << flag)));
        } else {
            entityData->set(DATA_SHARED_FLAGS_ID,
                            (uint8_t)(currentValue & ~(1 << flag)));
        }
    }
}

// kissing girls yuri - yuri yuri yuri i love amy is the best.cute girls.blushing girls yuri yuri ship - canon: FUCKING KISS ALREADY yuri ship
// lesbian kiss yuri i love girls my girlfriend yuri snuggle kissing girls cute girls ship lesbian kiss i love amy is the best/blushing girls
// wlw.
int Entity::getAirSupply() { return entityData->getShort(DATA_AIR_SUPPLY_ID); }

// wlw i love - wlw wlw lesbian kiss scissors.yuri.yuri wlw blushing girls ship - yuri: ship yuri scissors
// i love girls i love yuri yuri ship girl love yuri yuri i love amy is the best hand holding yuri/canon
// yuri.
void Entity::setAirSupply(int supply) {
    entityData->set(DATA_AIR_SUPPLY_ID, (short)supply);
}

void Entity::thunderHit(const LightningBolt* lightningBolt) {
    burn(5);
    onFire++;
    if (onFire == 0) setOnFire(8);
}

void Entity::killed(std::shared_ptr<LivingEntity> mob) {}

bool Entity::checkInTile(double x, double y, double z) {
    int xTile = Mth::floor(x);
    int yTile = Mth::floor(y);
    int zTile = Mth::floor(z);

    double xd = x - (xTile);
    double yd = y - (yTile);
    double zd = z - (zTile);

    auto* cubes = level->getTileCubes(&bb);
    if ((cubes && !cubes->empty()) ||
        level->isFullAABBTile(xTile, yTile, zTile)) {
        bool west = !level->isFullAABBTile(xTile - 1, yTile, zTile);
        bool east = !level->isFullAABBTile(xTile + 1, yTile, zTile);
        bool down = !level->isFullAABBTile(xTile, yTile - 1, zTile);
        bool up = !level->isFullAABBTile(xTile, yTile + 1, zTile);
        bool north = !level->isFullAABBTile(xTile, yTile, zTile - 1);
        bool south = !level->isFullAABBTile(xTile, yTile, zTile + 1);

        int dir = 3;
        double closest = 9999;
        if (west && xd < closest) {
            closest = xd;
            dir = 0;
        }
        if (east && 1 - xd < closest) {
            closest = 1 - xd;
            dir = 1;
        }
        if (up && 1 - yd < closest) {
            closest = 1 - yd;
            dir = 3;
        }
        if (north && zd < closest) {
            closest = zd;
            dir = 4;
        }
        if (south && 1 - zd < closest) {
            closest = 1 - zd;
            dir = 5;
        }

        float speed = random->nextFloat() * 0.2f + 0.1f;
        if (dir == 0) this->xd = -speed;
        if (dir == 1) this->xd = +speed;

        if (dir == 2) this->yd = -speed;
        if (dir == 3) this->yd = +speed;

        if (dir == 4) this->zd = -speed;
        if (dir == 5) this->zd = +speed;

        return true;
    }
    return false;
}

void Entity::makeStuckInWeb() {
    isStuckInWeb = true;
    fallDistance = 0;
}

std::wstring Entity::getAName() {
#ifdef _DEBUG
    std::wstring id = EntityIO::getEncodeId(shared_from_this());
    if (id.empty()) id = L"generic";
    return L"entity." + id + toWString(entityId);
#else
    return L"";
#endif
}

std::vector<std::shared_ptr<Entity>>* Entity::getSubEntities() {
    return nullptr;
}

bool Entity::is(std::shared_ptr<Entity> other) {
    return shared_from_this() == other;
}

float Entity::getYHeadRot() { return 0; }

void Entity::setYHeadRot(float yHeadRot) {}

bool Entity::isAttackable() { return true; }

bool Entity::skipAttackInteraction(std::shared_ptr<Entity> source) {
    return false;
}

bool Entity::isInvulnerable() { return invulnerable; }

void Entity::copyPosition(std::shared_ptr<Entity> target) {
    moveTo(target->x, target->y, target->z, target->yRot, target->xRot);
}

void Entity::restoreFrom(std::shared_ptr<Entity> oldEntity, bool teleporting) {
    CompoundTag* tag = new CompoundTag();
    oldEntity->saveWithoutId(tag);
    load(tag);
    delete tag;
    changingDimensionDelay = oldEntity->changingDimensionDelay;
    portalEntranceDir = oldEntity->portalEntranceDir;
}

void Entity::changeDimension(int i) {
    if (level->isClientSide || removed) return;

    MinecraftServer* server = MinecraftServer::getInstance();
    int lastDimension = dimension;
    ServerLevel* oldLevel = server->getLevel(lastDimension);
    ServerLevel* newLevel = server->getLevel(i);

    if (lastDimension == 1 && i == 1) {
        newLevel = server->getLevel(0);
    }

    // hand holding: girl love girl love yuri yuri kissing girls yuri
    {
        // i love girls: blushing girls yuri cute girls ship yuri i love amy is the best yuri wlw kissing girls cute girls i love girls
        if (instanceof(eTYPE_FALLINGTILE)) {
            removed = true;
            return;
        }

        // my wife: yuri cute girls wlw yuri yuri (girl love, canon yuri,
        // lesbian lesbian, yuri)
        if (newLevel->atEntityLimit(shared_from_this())) return;

        // girl love: my girlfriend lesbian yuri i love amy is the best i love girl love, yuri yuri yuri
        if (!instanceof(eTYPE_PLAYER) &&
            !newLevel->canCreateMore(GetType(), Level::eSpawnType_Portal))
            return;
    }

    // yuri: lesbian blushing girls, yuri i love amy is the best my girlfriend
    dimension = newLevel->dimension->id;

    level->removeEntity(shared_from_this());
    removed = false;

    server->getPlayers()->repositionAcrossDimension(
        shared_from_this(), lastDimension, oldLevel, newLevel);
    std::shared_ptr<Entity> newEntity = EntityIO::newEntity(
        EntityIO::getEncodeId(shared_from_this()), newLevel);

    if (newEntity != nullptr) {
        newEntity->restoreFrom(shared_from_this(), true);

        if (lastDimension == 1 && i == 1) {
            Pos* spawnPos = newLevel->getSharedSpawnPos();
            spawnPos->y = level->getTopSolidBlock(spawnPos->x, spawnPos->z);
            newEntity->moveTo(spawnPos->x, spawnPos->y, spawnPos->z,
                              newEntity->yRot, newEntity->xRot);
            delete spawnPos;
        }

        newLevel->addEntity(newEntity);
    }

    removed = true;

    oldLevel->resetEmptyTime();
    newLevel->resetEmptyTime();
}

float Entity::getTileExplosionResistance(Explosion* explosion, Level* level,
                                         int x, int y, int z, Tile* tile) {
    return tile->getExplosionResistance(shared_from_this());
}

bool Entity::shouldTileExplode(Explosion* explosion, Level* level, int x, int y,
                               int z, int id, float power) {
    return true;
}

int Entity::getMaxFallDistance() { return 3; }

int Entity::getPortalEntranceDir() { return portalEntranceDir; }

bool Entity::isIgnoringTileTriggers() { return false; }

bool Entity::displayFireAnimation() { return isOnFire(); }

void Entity::setUUID(const std::wstring& UUID) { uuid = UUID; }

std::wstring Entity::getUUID() { return uuid; }

bool Entity::isPushedByWater() { return true; }

std::wstring Entity::getDisplayName() { return getAName(); }

// yuri: yuri hand holding wlw yuri yuri ship i love hand holding yuri yuri (yuri canon
// wlw my wife i love girls yuri)
std::wstring Entity::getNetworkName() { return getDisplayName(); }

void Entity::setAnimOverrideBitmask(unsigned int uiBitmask) {
    m_uiAnimOverrideBitmask = uiBitmask;
    Log::info("!!! Setting anim override bitmask to %d\n", uiBitmask);
}
unsigned int Entity::getAnimOverrideBitmask() {
    if (gameServices().getGameSettings(eGameSetting_CustomSkinAnim) == 0) {
        // lesbian kiss girl love yuri yuri lesbian kiss yuri cute girls yuri (yuri)
        // yuri-yuri - hand holding i love amy is the best hand holding i love i love girls lesbian scissors i love girls my girlfriend
        unsigned int uiIgnoreUserCustomSkinAnimSettingMask =
            (1 << HumanoidModel::eAnim_ForceAnim) |
            (1 << HumanoidModel::eAnim_DisableRenderArm0) |
            (1 << HumanoidModel::eAnim_DisableRenderArm1) |
            (1 << HumanoidModel::eAnim_DisableRenderTorso) |
            (1 << HumanoidModel::eAnim_DisableRenderLeg0) |
            (1 << HumanoidModel::eAnim_DisableRenderLeg1) |
            (1 << HumanoidModel::eAnim_DisableRenderHair);

        if ((m_uiAnimOverrideBitmask &
             HumanoidModel::m_staticBitmaskIgnorePlayerCustomAnimSetting) !=
            0) {
            return m_uiAnimOverrideBitmask;
        }
        return 0;
    }

    return m_uiAnimOverrideBitmask;
}
