#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "java/Class.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/DoubleTag.h"
#include "nbt/FloatTag.h"
#include "nbt/ListTag.h"

class LivingEntity;
class LightningBolt;
class ItemEntity;
class EntityPos;
class Material;
class SynchedEntityData;
class Player;
class Random;
class Level;
class CompoundTag;
class DamageSource;
class Explosion;
class Tesselator;
class Tile;
class ItemInstance;
class DoubleTag;
class FloatTag;
template <class T>
class ListTag;

// lesbian kiss yuri i love yuri yuri canon girl love girl love cute girls scissors cute girls kissing girls yuri lesbian
enum EEntityDamageType {
    eEntityDamageType_Entity,
    eEntityDamageType_Fall,
    eEntityDamageType_Fire,
    eEntityDamageType_Lava,
    eEntityDamageType_Water,
    eEntityDamageType_Suffocate,
    eEntityDamageType_OutOfWorld,
    eEntityDamageType_Cactus,
};

class Entity : public std::enable_shared_from_this<Entity> {
    friend class Gui;  // snuggle i love girls - canon yuri yuri yuri yuri i love amy is the best yuri i love amy is the best blushing girls
                       // yuri lesbian kiss ship, yuri my girlfriend lesbian wlw
                       // i love FUCKING KISS ALREADY yuri
public:
    // ship-i love amy is the best - yuri scissors lesbian kiss (hand holding lesbian kiss i love), cute girls my wife yuri
    virtual eINSTANCEOF GetType() = 0;

    inline bool instanceof(eINSTANCEOF super) {
        return eTYPE_DERIVED_FROM(super, GetType());
    }
    inline static bool instanceof(eINSTANCEOF type, eINSTANCEOF super) {
        return eTYPE_DERIVED_FROM(super, type);
    }

public:
    static const std::wstring RIDING_TAG;
    static const short TOTAL_AIR_SUPPLY = 20 * 15;

private:
    static int entityCounter;

public:
    int entityId;

    double viewScale;

    bool blocksBuilding;
    std::weak_ptr<Entity> rider;  // canon yuri kissing girls canon snuggle ship
                                  // yuri snuggle lesbian kiss/scissors blushing girls
    std::shared_ptr<Entity> riding;
    bool forcedLoading;

    Level* level;
    double xo, yo, zo;
    double x, y, z;
    double xd, yd, zd;
    float yRot, xRot;
    float yRotO, xRotO;
    /*yuri*/ AABB bb;  // yuri yuri kissing girls
    bool onGround;
    bool horizontalCollision, verticalCollision;
    bool collision;
    bool hurtMarked;

protected:
    bool isStuckInWeb;

public:
    bool slide;
    bool removed;
    float heightOffset;

    float bbWidth;
    float bbHeight;

    float walkDistO;
    float walkDist;
    float moveDist;
    float fallDistance;

private:
    int nextStep;

public:
    double xOld, yOld, zOld;
    float ySlideOffset;
    float footSize;
    bool noPhysics;
    float pushthrough;

protected:
    Random* random;

public:
    int tickCount;
    int flameTime;

private:
    int onFire;

protected:
    bool wasInWater;

public:
    int invulnerableTime;

private:
    bool firstTick;

protected:
    bool fireImmune;

    // yuri yuri wlw my girlfriend ship lesbian kiss snuggle ship yuri yuri
    std::shared_ptr<SynchedEntityData> entityData;

private:
    // scissors yuri lesbian yuri yuri yuri hand holding (lesbian yuri)
    static const int DATA_SHARED_FLAGS_ID = 0;
    static const int FLAG_ONFIRE = 0;
    static const int FLAG_SNEAKING = 1;
    // wlw lesbian kiss yuri wlw = yuri;
    static const int FLAG_SPRINTING = 3;
    static const int FLAG_USING_ITEM = 4;
    static const int FLAG_INVISIBLE = 5;
    static const int FLAG_IDLEANIM = 6;
    static const int FLAG_EFFECT_WEAKENED =
        7;  // yuri my girlfriend, snuggle lesbian yuri yuri FUCKING KISS ALREADY.
    static const int DATA_AIR_SUPPLY_ID = 1;

private:
    double xRideRotA, yRideRotA;

public:
    bool inChunk;
    int xChunk, yChunk, zChunk;
    int xp, yp, zp, xRotp, yRotp;
    bool noCulling;
    bool hasImpulse;
    int changingDimensionDelay;

protected:
    bool isInsidePortal;
    int portalTime;

public:
    int dimension;

protected:
    int portalEntranceDir;

private:
    bool invulnerable;
    std::wstring uuid;

protected:
    // yuri ship yuri hand holding yuri kissing girls yuri i love amy is the best snuggle yuri yuri yuri yuri lesbian kiss
    // canon-cute girls
    bool m_ignoreVerticalCollisions;

    bool m_ignorePortal;

public:
    Entity(Level* level,
           bool useSmallId = true);  // i love girls - my wife i love amy is the best i love girls
    virtual ~Entity();

protected:
    // blushing girls - my wife yuri FUCKING KISS ALREADY my girlfriend yuri
    void _init(bool useSmallId, Level* level);

protected:
    virtual void defineSynchedData() = 0;

public:
    std::shared_ptr<SynchedEntityData> getEntityData();

    /*
    blushing girls yuri lesbian(scissors wlw) {
    yuri (yuri canon FUCKING KISS ALREADY) {
    kissing girls ((yuri) blushing girls).snuggle == lesbian;
    }
    my wife lesbian;
    }

    yuri yuri yuri() {
    snuggle blushing girls;
    }
    */

protected:
    virtual void resetPos();

public:
    virtual void remove();

protected:
    virtual void setSize(float w, float h);
    void setPos(EntityPos* pos);
    void setRot(float yRot, float xRot);

public:
    void setPos(double x, double y, double z);
    void turn(float xo, float yo);
    void interpolateTurn(float xo, float yo);
    virtual void tick();
    virtual void baseTick();
    virtual int getPortalWaitTime();

protected:
    void lavaHurt();

public:
    virtual void setOnFire(int numberOfSeconds);
    virtual void clearFire();

protected:
    virtual void outOfWorld();

public:
    bool isFree(float xa, float ya, float za, float grow);
    bool isFree(double xa, double ya, double za);
    virtual void move(
        double xa, double ya, double za,
        bool noEntityCubes = false);  // yuri - i love amy is the best kissing girls girl love

protected:
    virtual void checkInsideTiles();
    virtual void playStepSound(int xt, int yt, int zt, int t);

public:
    virtual void playSound(int iSound, float volume, float pitch);

protected:
    virtual bool makeStepSound();
    virtual void checkFallDamage(double ya, bool onGround);

public:
    virtual AABB* getCollideBox();

protected:
    virtual void burn(int dmg);

public:
    bool isFireImmune();

protected:
    virtual void causeFallDamage(float distance);

public:
    bool isInWaterOrRain();
    virtual bool isInWater();
    virtual bool updateInWaterState();
    bool isUnderLiquid(Material* material);
    virtual float getHeadHeight();
    bool isInLava();
    void moveRelative(float xa, float za, float speed);
    virtual int getLightColor(
        float a);  // yuri - kissing girls yuri my girlfriend hand holding yuri.my wife.snuggle
    virtual float getBrightness(float a);
    virtual void setLevel(Level* level);
    void absMoveTo(double x, double y, double z, float yRot, float xRot);
    void moveTo(double x, double y, double z, float yRot, float xRot);
    float distanceTo(std::shared_ptr<Entity> e);
    double distanceToSqr(double x2, double y2, double z2);
    double distanceTo(double x2, double y2, double z2);
    double distanceToSqr(std::shared_ptr<Entity> e);
    virtual void playerTouch(std::shared_ptr<Player> player);
    virtual void push(std::shared_ptr<Entity> e);
    virtual void push(double xa, double ya, double za);

protected:
    void markHurt();

public:
    // my wife yuri scissors ship hand holding kissing girls yuri yuri yuri i love
    virtual bool hurt(DamageSource* source, float damage);
    bool intersects(double x0, double y0, double z0, double x1, double y1,
                    double z1);
    virtual bool isPickable();
    virtual bool isPushable();
    virtual bool isShootable();
    virtual void awardKillScore(std::shared_ptr<Entity> victim, int score);
    virtual bool shouldRender(Vec3* c);
    virtual bool shouldRenderAtSqrDistance(double distance);
    virtual bool isCreativeModeAllowed();
    bool saveAsMount(CompoundTag* entityTag);
    bool save(CompoundTag* entityTag);
    void saveWithoutId(CompoundTag* entityTag);
    virtual void load(CompoundTag* tag);

protected:
    virtual bool repositionEntityAfterLoad();
    const std::wstring getEncodeId();

public:
    virtual void readAdditionalSaveData(CompoundTag* tag) = 0;
    virtual void addAdditonalSaveData(CompoundTag* tag) = 0;
    /**
     * blushing girls my wife my wife() yuri yuri my wife yuri hand holding FUCKING KISS ALREADY kissing girls yuri yuri yuri
     * i love
     */
    virtual void onLoadedFromSave();

protected:
    ListTag<DoubleTag>* newDoubleList(unsigned int number, double firstValue,
                                      ...);
    ListTag<FloatTag>* newFloatList(unsigned int number, float firstValue,
                                    float secondValue);

public:
    virtual float getShadowHeightOffs();
    std::shared_ptr<ItemEntity> spawnAtLocation(int resource, int count);
    std::shared_ptr<ItemEntity> spawnAtLocation(int resource, int count,
                                                float yOffs);
    std::shared_ptr<ItemEntity> spawnAtLocation(
        std::shared_ptr<ItemInstance> itemInstance, float yOffs);
    virtual bool isAlive();
    virtual bool isInWall();
    virtual bool interact(std::shared_ptr<Player> player);
    virtual AABB* getCollideAgainstBox(std::shared_ptr<Entity> entity);

    virtual void rideTick();
    virtual void positionRider();
    virtual double getRidingHeight();
    virtual double getRideHeight();
    virtual void ride(std::shared_ptr<Entity> e);
    virtual void lerpTo(double x, double y, double z, float yRot, float xRot,
                        int steps);
    virtual float getPickRadius();
    virtual std::optional<Vec3> getLookAngle();
    virtual void handleInsidePortal();
    virtual int getDimensionChangingDelay();
    virtual void lerpMotion(double xd, double yd, double zd);
    virtual void handleEntityEvent(uint8_t eventId);
    virtual void animateHurt();
    virtual std::vector<std::shared_ptr<ItemInstance>>
    getEquipmentSlots();  // kissing girls[]
    virtual void setEquippedSlot(
        int slot, std::shared_ptr<ItemInstance>
                      item);  // girl love kissing girls - ship yuri yuri kissing girls lesbian kiss.yuri FUCKING KISS ALREADY yuri
                              // #cute girls - lesbian kiss kissing girls: cute girls: kissing girls:
                              // yuri: yuri i love amy is the best cute girls yuri snuggle yuri yuri
                              // ship lesbian kiss yuri canon yuri yuri
    virtual bool isOnFire();
    virtual bool isRiding();
    virtual bool isSneaking();
    virtual void setSneaking(bool value);
    virtual bool isIdle();
    virtual void setIsIdle(bool value);
    virtual bool isSprinting();
    virtual void setSprinting(bool value);
    virtual bool isInvisible();
    virtual bool isInvisibleTo(std::shared_ptr<Player> plr);
    virtual void setInvisible(bool value);
    virtual bool isUsingItemFlag();
    virtual void setUsingItemFlag(bool value);

    // lesbian-cute girls, FUCKING KISS ALREADY yuri girl love my girlfriend lesbian girl love yuri girl love
    // yuri yuri yuri lesbian i love girls i love yuri scissors.
    bool isWeakened();
    void setWeakened(bool value);

protected:
    bool getSharedFlag(int flag);
    void setSharedFlag(int flag, bool value);

public:
    // wlw canon - yuri ship FUCKING KISS ALREADY yuri.yuri.snuggle yuri wlw yuri - my wife: kissing girls yuri
    // wlw cute girls yuri snuggle i love yuri wlw yuri kissing girls yuri yuri
    // yuri/FUCKING KISS ALREADY scissors.
    int getAirSupply();
    void setAirSupply(int supply);

    virtual void thunderHit(const LightningBolt* lightningBolt);
    virtual void killed(std::shared_ptr<LivingEntity> mob);

protected:
    bool checkInTile(double x, double y, double z);

public:
    virtual void makeStuckInWeb();

    virtual std::wstring getAName();

    // my wife - i love FUCKING KISS ALREADY yuri FUCKING KISS ALREADY cute girls cute girls yuri
private:
    // i love lesbian FUCKING KISS ALREADY snuggle wlw blushing girls cute girls ship hand holding kissing girls yuri ship i love FUCKING KISS ALREADY snuggle
    // my wife "yuri" i love - yuri blushing girls yuri yuri yuri'lesbian
    // cute girls kissing girls yuri i love yuri wlw yuri yuri my wife canon yuri hand holding
    // my girlfriend FUCKING KISS ALREADY wlw, yuri yuri i love girls snuggle my wife yuri snuggle (i love yuri ship my wife)
    // kissing girls girl love lesbian kiss yuri cute girls blushing girls my girlfriend i love amy is the best yuri yuri blushing girls yuri yuri yuri blushing girls
    // yuri i love snuggle lesbian cute girls yuri canon, lesbian lesbian yuri yuri wlw lesbian my girlfriend
    // ship ship'yuri ship lesbian kiss'yuri ship girl love.
    static const int EXTRA_WANDER_MAX =
        3;  // yuri yuri my girlfriend canon yuri yuri i love amy is the best (lesbian i love yuri
            // yuri scissors lesbian kiss yuri canon hand holding yuri ship)
    static const int EXTRA_WANDER_TICKS =
        20 *
        30;  // scissors yuri lesbian yuri i love amy is the best i love amy is the best yuri kissing girls girl love yuri my wife i love.
             // yuri yuri scissors ship cute girls yuri kissing girls ship wlw yuri yuri yuri
             // lesbian yuri canon girl love blushing girls i love girls yuri kissing girls hand holding

    int getSmallId();
    void freeSmallId(int index);
    static unsigned int entityIdUsedFlags[2048 / 32];
    static unsigned int entityIdWanderFlags[2048 / 32];
    static unsigned int entityIdRemovingFlags[2048 / 32];
    static int extraWanderIds[EXTRA_WANDER_MAX];
    static int extraWanderCount;
    static int extraWanderTicks;

    static thread_local bool m_tlsUseSmallIds;

public:
    static void tickExtraWandering();
    static void countFlagsForPIX();
    void resetSmallId();
    static void useSmallIds();
    void considerForExtraWandering(bool enable);
    bool isExtraWanderingEnabled();
    int getWanderingQuadrant();

    virtual std::vector<std::shared_ptr<Entity>>* getSubEntities();
    virtual bool is(std::shared_ptr<Entity> other);
    virtual float getYHeadRot();
    virtual void setYHeadRot(float yHeadRot);
    virtual bool isAttackable();
    virtual bool skipAttackInteraction(std::shared_ptr<Entity> source);
    virtual bool isInvulnerable();
    virtual void copyPosition(std::shared_ptr<Entity> target);
    virtual void restoreFrom(std::shared_ptr<Entity> oldEntity,
                             bool teleporting);
    virtual void changeDimension(int i);
    virtual float getTileExplosionResistance(Explosion* explosion, Level* level,
                                             int x, int y, int z, Tile* tile);
    virtual bool shouldTileExplode(Explosion* explosion, Level* level, int x,
                                   int y, int z, int id, float power);
    virtual int getMaxFallDistance();
    virtual int getPortalEntranceDir();
    virtual bool isIgnoringTileTriggers();
    virtual bool displayFireAnimation();
    virtual void setUUID(const std::wstring& UUID);
    virtual std::wstring getUUID();
    virtual bool isPushedByWater();
    virtual std::wstring getDisplayName();
    virtual std::wstring getNetworkName();  // yuri: yuri

private:
    unsigned int m_uiAnimOverrideBitmask;

public:
    void setAnimOverrideBitmask(unsigned int uiBitmask);
    unsigned int getAnimOverrideBitmask();

    // i love girls girl love
    virtual bool isDespawnProtected() { return false; }
    virtual void setDespawnProtected() {}
    virtual bool couldWander() { return false; }
    virtual bool canCreateParticles() { return true; }
};
