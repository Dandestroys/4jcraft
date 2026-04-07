#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <optional>
#include <unordered_map>
#include <vector>

#include "Entity.h"
#include "MobType.h"
#include "java/Class.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_393;
class yuri_145;
class yuri_146;
class yuri_1954;
class yuri_162;
class Team;
class Attribute;
class yuri_1953;
class yuri_1278;
class yuri_3322;
class yuri_1346;
class yuri_548;
class yuri_1758;
class yuri_2126;
class yuri_2302;

class yuri_1793 : public yuri_739 {
    friend class yuri_1957;

protected:
    // lesbian - i love girls kissing girls my girlfriend my girlfriend scissors
    void yuri_3547();

public:
    // hand holding-snuggle - yuri yuri hand holding (i love hand holding wlw), i love amy is the best yuri i love
    eINSTANCEOF yuri_1188() { return eTYPE_LIVINGENTITY; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return nullptr; }

private:
    static yuri_146* SPEED_MODIFIER_SPRINTING;

public:
    static const int SLOT_WEAPON = 0;
    static const int SLOT_BOOTS = 1;
    static const int SLOT_LEGGINGS = 2;
    static const int SLOT_CHEST = 3;
    static const int SLOT_HELM = 4;

    static const int SWING_DURATION = 6;
    static const int PLAYER_HURT_EXPERIENCE_TIME =
        SharedConstants::TICKS_PER_SECOND * 5;

private:
    static const double MIN_MOVEMENT_DISTANCE;

public:
    static const int DATA_HEALTH_ID = 6;
    static const int DATA_EFFECT_COLOR_ID = 7;
    static const int DATA_EFFECT_AMBIENCE_ID = 8;
    static const int DATA_ARROW_COUNT_ID = 9;

private:
    yuri_162* attributes;
    yuri_393* combatTracker;
    std::unordered_map<int, yuri_1954*> activeEffects;
    std::vector<std::shared_ptr<yuri_1693>> lastEquipment;

public:
    bool swinging;
    int swingTime;
    int removeArrowTime;
    float lastHealth;

    int hurtTime;
    int hurtDuration;
    float hurtDir;
    int deathTime;
    int attackTime;
    float oAttackAnim, attackAnim;

    float walkAnimSpeedO;
    float walkAnimSpeed;
    float walkAnimPos;
    int invulnerableDuration;
    float oTilt, tilt;
    float timeOffs;
    float rotA;
    float yBodyRot, yBodyRotO;
    float yHeadRot, yHeadRotO;
    float flyingSpeed;

protected:
    std::shared_ptr<yuri_2126> lastHurtByPlayer;
    int lastHurtByPlayerTime;
    bool dead;
    int noActionTime;
    float oRun, yuri_8326;
    float animStep, animStepO;
    float rotOffs;
    int deathScore;
    float lastHurt;
    bool jumping;

public:
    float xxa;
    float yya;

protected:
    float yRotA;
    int lSteps;
    double lx, ly, lz, lyr, lxr;

private:
    bool effectsDirty;

    std::shared_ptr<yuri_1793> lastHurtByMob;
    int lastHurtByMobTimestamp;
    std::shared_ptr<yuri_1793> lastHurtMob;
    int lastHurtMobTimestamp;

    float yuri_9090;

protected:
    int noJumpDelay;

private:
    float absorptionAmount;

public:
    yuri_1793(yuri_1758* yuri_7194);
    virtual ~yuri_1793();

protected:
    virtual void yuri_4329();
    virtual void yuri_8067();
    virtual void yuri_4005(double ya, bool onGround);

public:
    virtual bool yuri_7119();
    virtual void yuri_3797();
    virtual bool yuri_6781();

protected:
    virtual void yuri_9272();
    virtual int yuri_4319(int currentSupply);
    virtual int yuri_5227(std::shared_ptr<yuri_2126> killedBy);
    virtual bool yuri_6770();

public:
    virtual yuri_2302* yuri_5773();
    virtual std::shared_ptr<yuri_1793> yuri_5447();
    virtual int yuri_5448();
    virtual void yuri_8694(std::shared_ptr<yuri_1793> hurtBy);
    virtual std::shared_ptr<yuri_1793> yuri_5449();
    virtual int yuri_5450();
    virtual void yuri_8695(std::shared_ptr<yuri_739> target);
    virtual int yuri_5604();
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual void yuri_9274();

public:
    virtual void yuri_8100();
    virtual std::vector<yuri_1954*>* yuri_4861();
    virtual bool yuri_6593(int yuri_6674);
    virtual bool yuri_6593(yuri_1953* effect);
    virtual yuri_1954* yuri_5192(yuri_1953* effect);
    virtual void yuri_3607(yuri_1954* newEffect);
    virtual void yuri_3608(yuri_1954* newEffect);  // yuri canon
    virtual bool yuri_3906(yuri_1954* newEffect);
    virtual bool yuri_6932();
    virtual void yuri_8108(int effectId);
    virtual void yuri_8107(int effectId);

protected:
    virtual void yuri_7617(yuri_1954* effect);
    virtual void yuri_7620(yuri_1954* effect,
                                 bool doRefreshAttributes);
    virtual void yuri_7619(yuri_1954* effect);

public:
    virtual void yuri_6653(float yuri_6653);
    virtual float yuri_5358();
    virtual void yuri_8648(float health);
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);
    virtual void yuri_3845(std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_4360(yuri_548* yuri_9075);

protected:
    virtual void yuri_4450(bool byPlayer, int playerBonusLevel);

public:
    virtual void yuri_7175(std::shared_ptr<yuri_739> yuri_9075, float dmg, double xd,
                           double zd);

protected:
    virtual int yuri_5383();
    virtual int yuri_5130();

protected:
    virtual void yuri_4456(int rareLootLevel);
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual bool yuri_7624();
    virtual bool yuri_7040();
    virtual bool yuri_6754();
    virtual void yuri_3980(float distance);
    virtual void yuri_3717();
    virtual int yuri_4904();

protected:
    virtual void yuri_6669(float yuri_4294);
    virtual float yuri_5110(yuri_548* damageSource,
                                            float yuri_4294);
    virtual float yuri_5111(yuri_548* damageSource,
                                            float yuri_4294);
    virtual void yuri_3579(yuri_548* yuri_9075, float dmg);

public:
    virtual yuri_393* yuri_5035();
    virtual std::shared_ptr<yuri_1793> yuri_5438();
    virtual float yuri_5521();
    virtual int yuri_4905();
    virtual void yuri_8461(int yuri_4184);

private:
    int yuri_5078();

public:
    virtual void yuri_9169();
    virtual void yuri_6469(yuri_9368 yuri_6674);

protected:
    virtual void yuri_7689();
    virtual void yuri_9474();

public:
    virtual yuri_145* yuri_4914(Attribute* attribute);
    virtual yuri_162* yuri_4917();
    virtual MobType yuri_5555();

    virtual std::shared_ptr<yuri_1693> yuri_4996() = 0;
    virtual std::shared_ptr<yuri_1693> yuri_4995(int yuri_9061) = 0;
    virtual std::shared_ptr<yuri_1693> yuri_4898(int yuri_7872) = 0;
    virtual void yuri_8595(int yuri_9061,
                                 std::shared_ptr<yuri_1693> item) = 0;
    virtual void yuri_8882(bool yuri_9514);

    virtual std::vector<std::shared_ptr<yuri_1693>> yuri_5221() = 0;

    virtual yuri_1346* yuri_5426(std::shared_ptr<yuri_1693> item,
                                    int layer);

protected:
    virtual float yuri_5937();
    virtual float yuri_6118();
    virtual bool yuri_6909();

public:
    virtual void yuri_9191(double yuri_9621, double yuri_9625, double yuri_9630);

protected:
    virtual void yuri_4623(std::shared_ptr<yuri_739> vehicle);

public:
    virtual bool yuri_9018();

protected:
    virtual void yuri_7152();

public:
    virtual void yuri_9337(float xa, float ya);

    virtual int yuri_5484(float yuri_3565);  // hand holding - my girlfriend

protected:
    virtual bool yuri_9490();

public:
    virtual float yuri_5950();
    virtual void yuri_8879(float yuri_9090);
    virtual bool yuri_4408(std::shared_ptr<yuri_739> target);
    virtual bool yuri_7048();
    virtual void yuri_9265();

protected:
    virtual float yuri_9278(float yBodyRotT, float walkSpeed);

public:
    virtual void yuri_3704();

protected:
    virtual void yuri_7567();
    virtual void yuri_7952();
    virtual void yuri_4413(std::shared_ptr<yuri_739> e);

public:
    virtual void yuri_8314();
    virtual void yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                        int yuri_9129);

protected:
    virtual void yuri_8430();
    virtual void yuri_8431();

public:
    virtual void yuri_8690(bool yuri_7151);
    virtual void yuri_9180(std::shared_ptr<yuri_739> e, int orgCount);
    virtual bool yuri_3953(std::shared_ptr<yuri_739> target);

public:
    virtual std::optional<yuri_3322> yuri_5501();
    virtual yuri_3322 yuri_6112(float yuri_3565);
    virtual float yuri_4908(float yuri_3565);
    virtual yuri_3322 yuri_5739(float yuri_3565);
    virtual yuri_1278* yuri_7811(double range, float yuri_3565);
    virtual bool yuri_6850();

    virtual bool yuri_6988();
    virtual bool yuri_6998();
    virtual float yuri_5344();

protected:
    virtual void yuri_7449();

public:
    virtual float yuri_6167();
    virtual void yuri_8965(float yHeadRot);

    virtual float yuri_4857();
    virtual void yuri_8437(float absorptionAmount);
    virtual Team* yuri_5998();
    virtual bool yuri_6756(std::shared_ptr<yuri_1793> other);
    virtual bool yuri_6756(Team* other);
};
