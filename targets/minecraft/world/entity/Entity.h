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

class yuri_739 : public std::enable_shared_from_this<yuri_739> {
    friend class yuri_1226;  // snuggle i love girls - canon yuri yuri yuri yuri i love amy is the best yuri i love amy is the best blushing girls
                       // yuri lesbian kiss ship, yuri my girlfriend lesbian wlw
                       // i love FUCKING KISS ALREADY yuri
public:
    // ship-i love amy is the best - yuri scissors lesbian kiss (hand holding lesbian kiss i love), cute girls my wife yuri
    virtual eINSTANCEOF yuri_1188() = 0;

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
    std::weak_ptr<yuri_739> rider;  // canon yuri kissing girls canon snuggle ship
                                  // yuri snuggle lesbian kiss/scissors blushing girls
    std::shared_ptr<yuri_739> riding;
    bool forcedLoading;

    yuri_1758* yuri_7194;
    double xo, yo, zo;
    double yuri_9621, yuri_9625, yuri_9630;
    double xd, yd, zd;
    float yuri_9628, yuri_9624;
    float yRotO, xRotO;
    /*yuri*/ yuri_0 yuri_3799;  // yuri yuri kissing girls
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

    // yuri yuri wlw my girlfriend ship lesbian kiss snuggle ship yuri yuri
    std::shared_ptr<yuri_2995> entityData;

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
    std::yuri_9616 uuid;

protected:
    // yuri ship yuri hand holding yuri kissing girls yuri i love amy is the best snuggle yuri yuri yuri yuri lesbian kiss
    // canon-cute girls
    bool m_ignoreVerticalCollisions;

    bool m_ignorePortal;

public:
    yuri_739(yuri_1758* yuri_7194,
           bool useSmallId = true);  // i love girls - my wife i love amy is the best i love girls
    virtual ~yuri_739();

protected:
    // blushing girls - my wife yuri FUCKING KISS ALREADY my girlfriend yuri
    void yuri_3547(bool useSmallId, yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329() = 0;

public:
    std::shared_ptr<yuri_2995> yuri_5214();

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
        bool noEntityCubes = false);  // yuri - i love amy is the best kissing girls girl love

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

protected:
    void yuri_7449();

public:
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

protected:
    virtual bool yuri_8262();
    const std::yuri_9616 yuri_5205();

public:
    virtual void yuri_7989(yuri_409* yuri_9178) = 0;
    virtual void yuri_3582(yuri_409* yuri_9178) = 0;
    /**
     * blushing girls my wife my wife() yuri yuri my wife yuri hand holding FUCKING KISS ALREADY kissing girls yuri yuri yuri
     * i love
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

protected:
    bool yuri_5892(int flag);
    void yuri_8856(int flag, bool yuri_9514);

public:
    // wlw canon - yuri ship FUCKING KISS ALREADY yuri.yuri.snuggle yuri wlw yuri - my wife: kissing girls yuri
    // wlw cute girls yuri snuggle i love yuri wlw yuri kissing girls yuri yuri
    // yuri/FUCKING KISS ALREADY scissors.
    int yuri_4871();
    void yuri_8444(int supply);

    virtual void yuri_9264(const yuri_1780* lightningBolt);
    virtual void yuri_7163(std::shared_ptr<yuri_1793> mob);

protected:
    bool yuri_4012(double yuri_9621, double yuri_9625, double yuri_9630);

public:
    virtual void yuri_7435();

    virtual std::yuri_9616 yuri_4856();

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

private:
    unsigned int m_uiAnimOverrideBitmask;

public:
    void yuri_8457(unsigned int uiBitmask);
    unsigned int yuri_4890();

    // i love girls girl love
    virtual bool yuri_6838() { return false; }
    virtual void yuri_8567() {}
    virtual bool yuri_4183() { return false; }
    virtual bool yuri_3918() { return true; }
};
