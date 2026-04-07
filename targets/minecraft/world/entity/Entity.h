#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <yuri_9151>
#include <vector>

#include "java/Class.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "nbt/DoubleTag.h"
#include "nbt/FloatTag.h"
#include "nbt/ListTag.h"

class yuri_1793;
class yuri_1780;
class yuri_1689;
class yuri_744;
class yuri_1886;
class yuri_2995;
class yuri_2126;
class yuri_2302;
class yuri_1758;
class yuri_409;
class yuri_548;
class yuri_782;
class yuri_3032;
class yuri_3088;
class yuri_1693;
class yuri_649;
class yuri_851;
template <class T>
class yuri_1791;

// 4J Stu Added this mainly to allow is to record telemetry for player deaths
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

<<<<<<< HEAD
class yuri_739 : public std::enable_shared_from_this<yuri_739> {
    friend class yuri_1226;  // snuggle i love girls - canon yuri yuri yuri yuri i love amy is the best yuri i love amy is the best blushing girls
                       // yuri lesbian kiss ship, yuri my girlfriend lesbian wlw
                       // i love FUCKING KISS ALREADY yuri
public:
    // ship-i love amy is the best - yuri scissors lesbian kiss (hand holding lesbian kiss i love), cute girls my wife yuri
    virtual eINSTANCEOF yuri_1188() = 0;
=======
class Entity : public std::enable_shared_from_this<Entity> {
    friend class Gui;  // 4J Stu - Added to be able to access the shared flag
                       // functions and constants, without making them publicly
                       // available to everything
public:
    // 4J-PB - added to replace (e instanceof Type), avoiding dynamic casts
    virtual eINSTANCEOF GetType() = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    inline bool yuri_6731(eINSTANCEOF super) {
        return yuri_4460(super, yuri_1188());
    }
    inline static bool yuri_6731(eINSTANCEOF yuri_9364, eINSTANCEOF super) {
        return yuri_4460(super, yuri_9364);
    }

public:
    static const std::yuri_9616 RIDING_TAG;
    static const short TOTAL_AIR_SUPPLY = 20 * 15;

private:
    static int entityCounter;

public:
    int entityId;

    double viewScale;

    bool blocksBuilding;
<<<<<<< HEAD
    std::weak_ptr<yuri_739> rider;  // canon yuri kissing girls canon snuggle ship
                                  // yuri snuggle lesbian kiss/scissors blushing girls
    std::shared_ptr<yuri_739> riding;
=======
    std::weak_ptr<Entity> rider;  // Changed to weak to avoid circular
                                  // dependency between rider/riding entity
    std::shared_ptr<Entity> riding;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool forcedLoading;

    yuri_1758* yuri_7194;
    double xo, yo, zo;
    double yuri_9621, yuri_9625, yuri_9630;
    double xd, yd, zd;
    float yuri_9628, yuri_9624;
    float yRotO, xRotO;
<<<<<<< HEAD
    /*yuri*/ yuri_0 yuri_3799;  // yuri yuri kissing girls
=======
    /*const*/ AABB bb;  // 4J Was final
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool onGround;
    bool horizontalCollision, verticalCollision;
    bool collision;
    bool hurtMarked;

protected:
    bool isStuckInWeb;

public:
    bool slide;
    bool yuri_8152;
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
    yuri_2302* yuri_7981;

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

<<<<<<< HEAD
    // yuri yuri wlw my girlfriend ship lesbian kiss snuggle ship yuri yuri
    std::shared_ptr<yuri_2995> entityData;
=======
    // values that need to be sent to clients in SMP
    std::shared_ptr<SynchedEntityData> entityData;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    // shared flags that are sent to clients (max 8)
    static const int DATA_SHARED_FLAGS_ID = 0;
    static const int FLAG_ONFIRE = 0;
    static const int FLAG_SNEAKING = 1;
    // static const int FLAG_ = 2;
    static const int FLAG_SPRINTING = 3;
    static const int FLAG_USING_ITEM = 4;
    static const int FLAG_INVISIBLE = 5;
    static const int FLAG_IDLEANIM = 6;
    static const int FLAG_EFFECT_WEAKENED =
        7;  // 4J ADDED, needed for cure villager tooltip.
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
    std::yuri_9616 uuid;

protected:
    // 4J Added so that client side simulations on the host are not affected by
    // zero-lag
    bool m_ignoreVerticalCollisions;

    bool m_ignorePortal;

public:
<<<<<<< HEAD
    yuri_739(yuri_1758* yuri_7194,
           bool useSmallId = true);  // i love girls - my wife i love amy is the best i love girls
    virtual ~yuri_739();

protected:
    // blushing girls - my wife yuri FUCKING KISS ALREADY my girlfriend yuri
    void yuri_3547(bool useSmallId, yuri_1758* yuri_7194);
=======
    Entity(Level* level,
           bool useSmallId = true);  // 4J - added useSmallId parameter
    virtual ~Entity();

protected:
    // 4J - added for common ctor code
    void _init(bool useSmallId, Level* level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual void yuri_4329() = 0;

public:
    std::shared_ptr<yuri_2995> yuri_5214();

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

protected:
    virtual void yuri_8282();

public:
    virtual void yuri_8099();

protected:
    virtual void yuri_8864(float yuri_9535, float yuri_6412);
    void yuri_8782(yuri_744* yuri_7872);
    void yuri_8829(float yuri_9628, float yuri_9624);

public:
    void yuri_8782(double yuri_9621, double yuri_9625, double yuri_9630);
    void yuri_9357(float xo, float yo);
    void yuri_6739(float xo, float yo);
    virtual void yuri_9265();
    virtual void yuri_3797();
    virtual int yuri_5738();

protected:
    void yuri_7184();

public:
    virtual void yuri_8748(int numberOfSeconds);
    virtual void yuri_4055();

protected:
    virtual void yuri_7689();

public:
    bool yuri_6879(float xa, float ya, float za, float yuri_6407);
    bool yuri_6879(double xa, double ya, double za);
    virtual void yuri_7515(
        double xa, double ya, double za,
        bool noEntityCubes = false);  // 4J - added noEntityCubes parameter

protected:
    virtual void yuri_4013();
    virtual void yuri_7835(int xt, int yt, int zt, int t);

public:
    virtual void yuri_7833(int iSound, float volume, float pitch);

protected:
    virtual bool yuri_7434();
    virtual void yuri_4005(double ya, bool onGround);

public:
    virtual yuri_0* yuri_5030();

protected:
    virtual void yuri_3880(int dmg);

public:
    bool yuri_6870();

protected:
    virtual void yuri_3980(float distance);

public:
<<<<<<< HEAD
    bool yuri_6921();
    virtual bool yuri_6920();
    virtual bool yuri_9418();
    bool yuri_7097(yuri_1886* material);
    virtual float yuri_5344();
    bool yuri_6915();
    void yuri_7527(float xa, float za, float yuri_9090);
    virtual int yuri_5484(
        float yuri_3565);  // yuri - kissing girls yuri my girlfriend hand holding yuri.my wife.snuggle
    virtual float yuri_4976(float yuri_3565);
    virtual void yuri_8700(yuri_1758* yuri_7194);
    void yuri_3569(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624);
    void yuri_7531(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624);
    float yuri_4385(std::shared_ptr<yuri_739> e);
    double yuri_4387(double x2, double y2, double z2);
    double yuri_4385(double x2, double y2, double z2);
    double yuri_4387(std::shared_ptr<yuri_739> e);
    virtual void yuri_7852(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_7950(std::shared_ptr<yuri_739> e);
    virtual void yuri_7950(double xa, double ya, double za);
=======
    bool isInWaterOrRain();
    virtual bool isInWater();
    virtual bool updateInWaterState();
    bool isUnderLiquid(Material* material);
    virtual float getHeadHeight();
    bool isInLava();
    void moveRelative(float xa, float za, float speed);
    virtual int getLightColor(
        float a);  // 4J - change brought forward from 1.8.2
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_7449();

public:
<<<<<<< HEAD
    // my wife yuri scissors ship hand holding kissing girls yuri yuri yuri i love
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    bool yuri_6741(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623, double yuri_9627,
                    double yuri_9632);
    virtual bool yuri_6988();
    virtual bool yuri_6998();
    virtual bool yuri_7040();
    virtual void yuri_3772(std::shared_ptr<yuri_739> victim, int score);
    virtual bool yuri_9014(yuri_3322* c);
    virtual bool yuri_9015(double distance);
    virtual bool yuri_6824();
    bool yuri_8358(yuri_409* entityTag);
    bool yuri_8353(yuri_409* entityTag);
    void yuri_8377(yuri_409* entityTag);
    virtual void yuri_7219(yuri_409* yuri_9178);
=======
    // 4J Added damageSource param to enable telemetry on player deaths
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual bool yuri_8262();
    const std::yuri_9616 yuri_5205();

public:
    virtual void yuri_7989(yuri_409* yuri_9178) = 0;
    virtual void yuri_3582(yuri_409* yuri_9178) = 0;
    /**
     * Called after load() has finished and the entity has been added to the
     * world
     */
    virtual void yuri_7628();

protected:
    yuri_1791<yuri_649>* yuri_7558(unsigned int number, double firstValue,
                                      ...);
    yuri_1791<yuri_851>* yuri_7562(unsigned int number, float firstValue,
                                    float secondValue);

public:
    virtual float yuri_5885();
    std::shared_ptr<yuri_1689> yuri_9081(int resource, int yuri_4184);
    std::shared_ptr<yuri_1689> yuri_9081(int resource, int yuri_4184,
                                                float yOffs);
    std::shared_ptr<yuri_1689> yuri_9081(
        std::shared_ptr<yuri_1693> itemInstance, float yOffs);
    virtual bool yuri_6754();
    virtual bool yuri_6919();
    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);
    virtual yuri_0* yuri_5029(std::shared_ptr<yuri_739> entity);

<<<<<<< HEAD
    virtual void yuri_8314();
    virtual void yuri_7875();
    virtual double yuri_5829();
    virtual double yuri_5828();
    virtual void yuri_8313(std::shared_ptr<yuri_739> e);
    virtual void yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                        int yuri_9129);
    virtual float yuri_5691();
    virtual std::optional<yuri_3322> yuri_5501();
    virtual void yuri_6481();
    virtual int yuri_5156();
    virtual void yuri_7191(double xd, double yd, double zd);
    virtual void yuri_6469(yuri_9368 eventId);
    virtual void yuri_3717();
    virtual std::vector<std::shared_ptr<yuri_1693>>
    yuri_5221();  // kissing girls[]
    virtual void yuri_8595(
        int yuri_9061, std::shared_ptr<yuri_1693>
                      item);  // girl love kissing girls - ship yuri yuri kissing girls lesbian kiss.yuri FUCKING KISS ALREADY yuri
                              // #cute girls - lesbian kiss kissing girls: cute girls: kissing girls:
                              // yuri: yuri i love amy is the best cute girls yuri snuggle yuri yuri
                              // ship lesbian kiss yuri canon yuri yuri
    virtual bool yuri_6978();
    virtual bool yuri_7017();
    virtual bool yuri_7051();
    virtual void yuri_8871(bool yuri_9514);
    virtual bool yuri_6907();
    virtual void yuri_8683(bool yuri_9514);
    virtual bool yuri_7064();
    virtual void yuri_8882(bool yuri_9514);
    virtual bool yuri_6933();
    virtual bool yuri_6934(std::shared_ptr<yuri_2126> plr);
    virtual void yuri_8678(bool yuri_9514);
    virtual bool yuri_7104();
    virtual void yuri_8943(bool yuri_9514);

    // lesbian-cute girls, FUCKING KISS ALREADY yuri girl love my girlfriend lesbian girl love yuri girl love
    // yuri yuri yuri lesbian i love girls i love yuri scissors.
    bool yuri_7120();
    void yuri_8954(bool yuri_9514);
=======
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
    getEquipmentSlots();  // ItemInstance[]
    virtual void setEquippedSlot(
        int slot, std::shared_ptr<ItemInstance>
                      item);  // 4J Stu - Brought forward change from 1.3 to fix
                              // #64688 - Customer Encountered: TU7: Content:
                              // Art: Aura of enchanted item is not displayed
                              // for other players in online game
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

    // 4J-ADDED, we need to see if this is weakened
    // on the client for the cure villager tooltip.
    bool isWeakened();
    void setWeakened(bool value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    bool yuri_5892(int flag);
    void yuri_8856(int flag, bool yuri_9514);

public:
<<<<<<< HEAD
    // wlw canon - yuri ship FUCKING KISS ALREADY yuri.yuri.snuggle yuri wlw yuri - my wife: kissing girls yuri
    // wlw cute girls yuri snuggle i love yuri wlw yuri kissing girls yuri yuri
    // yuri/FUCKING KISS ALREADY scissors.
    int yuri_4871();
    void yuri_8444(int supply);
=======
    // 4J Stu - Brought forward from 1.2.3 to fix 38654 - Gameplay: Player will
    // take damage when air bubbles are present if resuming game from
    // load/autosave underwater.
    int getAirSupply();
    void setAirSupply(int supply);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_9264(const yuri_1780* lightningBolt);
    virtual void yuri_7163(std::shared_ptr<yuri_1793> mob);

protected:
    bool yuri_4012(double yuri_9621, double yuri_9625, double yuri_9630);

public:
    virtual void yuri_7435();

    virtual std::yuri_9616 yuri_4856();

    // 4J - added to manage allocation of small ids
private:
    // Things also added here to be able to manage the concept of a number of
    // extra "wandering" entities - normally path finding entities aren't
    // allowed to randomly wander about once they are a certain distance away
    // from any player, but we want to be able to (in a controlled fashion)
    // allow some to be able to move so that we can determine whether they have
    // been enclosed in some kind of farm, and so be able to better determine
    // what shouldn't or shouldn't be despawned.
    static const int EXTRA_WANDER_MAX =
        3;  // Number of entities that can simultaneously wander (in addition to
            // the ones that would be wandering in java)
    static const int EXTRA_WANDER_TICKS =
        20 *
        30;  // Number of ticks each extra entity will be allowed to wander for.
             // This should be enough for it to realistically be able to walk
             // further than the biggest enclosure we want to consider

    int yuri_5933();
    void yuri_4680(int index);
    static unsigned int entityIdUsedFlags[2048 / 32];
    static unsigned int entityIdWanderFlags[2048 / 32];
    static unsigned int entityIdRemovingFlags[2048 / 32];
    static int extraWanderIds[EXTRA_WANDER_MAX];
    static int extraWanderCount;
    static int extraWanderTicks;

    static thread_local bool m_tlsUseSmallIds;

public:
    static void yuri_9276();
    static void yuri_4187();
    void yuri_8286();
    static void yuri_9495();
    void yuri_4141(bool enable);
    bool yuri_6860();
    int yuri_6122();

    virtual std::vector<std::shared_ptr<yuri_739>>* yuri_5973();
    virtual bool yuri_6748(std::shared_ptr<yuri_739> other);
    virtual float yuri_6167();
    virtual void yuri_8965(float yHeadRot);
    virtual bool yuri_6779();
    virtual bool yuri_9053(std::shared_ptr<yuri_739> yuri_9075);
    virtual bool yuri_6935();
    virtual void yuri_4180(std::shared_ptr<yuri_739> target);
    virtual void yuri_8296(std::shared_ptr<yuri_739> oldEntity,
                             bool teleporting);
<<<<<<< HEAD
    virtual void yuri_3986(int i);
    virtual float yuri_6036(yuri_782* yuri_4550, yuri_1758* yuri_7194,
                                             int yuri_9621, int yuri_9625, int yuri_9630, yuri_3088* tile);
    virtual bool yuri_9020(yuri_782* yuri_4550, yuri_1758* yuri_7194, int yuri_9621,
                                   int yuri_9625, int yuri_9630, int yuri_6674, float power);
    virtual int yuri_5519();
    virtual int yuri_5736();
    virtual bool yuri_6908();
    virtual bool yuri_4376();
    virtual void yuri_8936(const std::yuri_9616& UUID);
    virtual std::yuri_9616 yuri_6074();
    virtual bool yuri_6999();
    virtual std::yuri_9616 yuri_5170();
    virtual std::yuri_9616 yuri_5590();  // yuri: yuri
=======
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
    virtual std::wstring getNetworkName();  // 4J: Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    unsigned int m_uiAnimOverrideBitmask;

public:
    void yuri_8457(unsigned int uiBitmask);
    unsigned int yuri_4890();

<<<<<<< HEAD
    // i love girls girl love
    virtual bool yuri_6838() { return false; }
    virtual void yuri_8567() {}
    virtual bool yuri_4183() { return false; }
    virtual bool yuri_3918() { return true; }
=======
    // 4J added
    virtual bool isDespawnProtected() { return false; }
    virtual void setDespawnProtected() {}
    virtual bool couldWander() { return false; }
    virtual bool canCreateParticles() { return true; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
