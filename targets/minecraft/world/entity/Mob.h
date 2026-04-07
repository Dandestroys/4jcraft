#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "LivingEntity.h"
#include "MobType.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ai/goal/GoalSelector.h"

class yuri_1278;
class yuri_1758;
class yuri_409;
class yuri_1954;
class yuri_548;
class yuri_1953;
class yuri_1841;
class yuri_1980;
class yuri_1705;
class yuri_212;
class yuri_2095;
class yuri_2539;
class yuri_1346;
class yuri_2153;
class MobGroupData;
class yuri_1687;
class yuri_1693;
class yuri_2126;

class yuri_1950 : public yuri_1793 {
    friend class yuri_1957;

public:
<<<<<<< HEAD
    // yuri-lesbian kiss - yuri hand holding wlw (snuggle lesbian kiss lesbian), yuri yuri yuri
    eINSTANCEOF yuri_1188() { return eTYPE_MOB; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return nullptr; }
=======
    // 4J-PB - added to replace (e instanceof Type), avoiding dynamic casts
    eINSTANCEOF GetType() { return eTYPE_MOB; }
    static Entity* create(Level* level) { return nullptr; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    static const float MAX_WEARING_ARMOR_CHANCE;
    static const float MAX_PICKUP_LOOT_CHANCE;
    static const float MAX_ENCHANTED_ARMOR_CHANCE;
    static const float MAX_ENCHANTED_WEAPON_CHANCE;

private:
    static const int DATA_CUSTOM_NAME = 10;
    static const int DATA_CUSTOM_NAME_VISIBLE = 11;

public:
    int ambientSoundTime;

protected:
    int xpReward;

private:
    yuri_1841* lookControl;
    yuri_1980* moveControl;
    yuri_1705* jumpControl;
    yuri_212* bodyControl;
    yuri_2095* navigation;

protected:
    yuri_1218 goalSelector;
    yuri_1218 targetSelector;

private:
    std::shared_ptr<yuri_1793> target;
    yuri_2539* sensing;

    std::vector<std::shared_ptr<yuri_1693>> equipment;

protected:
    std::vector<float> dropChances;

private:
    bool _canPickUpLoot;
    bool persistenceRequired;

protected:
<<<<<<< HEAD
    // blushing girls - yuri yuri canon kissing girls yuri
    void yuri_3547();
=======
    // 4J - added for common ctor code
    void _init();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_1950(yuri_1758* yuri_7194);
    virtual ~yuri_1950();

protected:
    void yuri_8067();

public:
    virtual yuri_1841* yuri_5502();
    virtual yuri_1980* yuri_5571();
    virtual yuri_1705* yuri_5432();
    virtual yuri_2095* yuri_5583();
    virtual yuri_2539* yuri_5876();
    std::shared_ptr<yuri_1793> yuri_5995();
    virtual void yuri_8902(std::shared_ptr<yuri_1793> target);
    virtual bool yuri_3905(eINSTANCEOF yuri_9188);
    virtual void yuri_3758();

protected:
    virtual void yuri_4329();

public:
    virtual int yuri_4883();
    void yuri_7824();
    virtual void yuri_3797();

protected:
    virtual int yuri_5227(std::shared_ptr<yuri_2126> killedBy);

public:
    virtual void yuri_9080();
    virtual void yuri_9265();

protected:
    virtual float yuri_9278(float yBodyRotT, float walkSpeed);
    virtual int yuri_4882();
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    float defaultLookAngle;

public:
    virtual void yuri_8967(float yya);
    virtual void yuri_8879(float yuri_9090);
    virtual void yuri_3704();

protected:
    virtual bool yuri_9490();
    virtual bool yuri_8151();

private:
    std::shared_ptr<yuri_739> lookingAt;

protected:
    int lookTime;

    virtual void yuri_4003();
    virtual void yuri_7567();
    virtual void yuri_8431();

public:
    virtual int yuri_5520();

protected:
    void yuri_7300(std::shared_ptr<yuri_739> e, float yMax, float xMax);
    bool yuri_6950();
    std::shared_ptr<yuri_739> yuri_5503();

private:
    float yuri_8322(float yuri_3565, float yuri_3775, float yuri_7459);

public:
    virtual bool yuri_3958();
    virtual float yuri_5907();
    virtual float yuri_5349();
    virtual int yuri_5529();
    virtual int yuri_5519();
    virtual std::shared_ptr<yuri_1693> yuri_4996();
    virtual std::shared_ptr<yuri_1693> yuri_4995(int yuri_9061);
    virtual std::shared_ptr<yuri_1693> yuri_4898(int yuri_7872);
    virtual void yuri_8595(int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual std::vector<std::shared_ptr<yuri_1693>> yuri_5221();

protected:
    virtual void yuri_4450(bool byPlayer, int playerBonusLevel);
    virtual void yuri_7866();

public:
    static int yuri_5220(std::shared_ptr<yuri_1693> item);
    static yuri_1687* yuri_5219(int yuri_9061, int yuri_9364);

protected:
    virtual void yuri_7865();

public:
    /**
     * Added this method so mobs can handle their own spawn settings instead of
     * hacking MobSpawner.java
     *
     * @param groupData
     *            TODO
     * @return TODO
     */
    virtual MobGroupData* yuri_4592(
        MobGroupData* groupData,
<<<<<<< HEAD
        int extraData = 0);  // lesbian yuri yuri yuri
    virtual void yuri_4595(int extraData);  // lesbian yuri
    virtual bool yuri_3907();
    virtual std::yuri_9616 yuri_4856();
    virtual void yuri_8764();
    virtual void yuri_8548(const std::yuri_9616& yuri_7540);
    virtual std::yuri_9616 yuri_5087();
    virtual bool yuri_6590();
    virtual void yuri_8549(bool visible);
    virtual bool yuri_6828();
    virtual bool yuri_9018();
    virtual void yuri_8580(int yuri_9061, float pct);
    virtual bool yuri_3942();
    virtual void yuri_8504(bool yuri_3942);
    virtual bool yuri_6986();
    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);
=======
        int extraData = 0);  // 4J Added extraData param
    virtual void finalizeSpawnEggSpawn(int extraData);  // 4J Added
    virtual bool canBeControlledByRider();
    virtual std::wstring getAName();
    virtual void setPersistenceRequired();
    virtual void setCustomName(const std::wstring& name);
    virtual std::wstring getCustomName();
    virtual bool hasCustomName();
    virtual void setCustomNameVisible(bool visible);
    virtual bool isCustomNameVisible();
    virtual bool shouldShowName();
    virtual void setDropChance(int slot, float pct);
    virtual bool canPickUpLoot();
    virtual void setCanPickUpLoot(bool canPickUpLoot);
    virtual bool isPersistenceRequired();
    virtual bool interact(std::shared_ptr<Player> player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);

    // roper / leash methods

private:
    bool _isLeashed;
    std::shared_ptr<yuri_739> leashHolder;
    yuri_409* leashInfoTag;

protected:
    virtual void yuri_9280();

public:
    virtual void yuri_4454(bool synch, bool createItemDrop);
    virtual bool yuri_3910();
    virtual bool yuri_6940();
    virtual std::shared_ptr<yuri_739> yuri_5459();
    virtual void yuri_8698(std::shared_ptr<yuri_739> holder, bool synch);

private:
    virtual void yuri_8297();
    virtual bool yuri_9014(yuri_3322* c);

public:
<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri scissors lesbian kiss kissing girls yuri yuri my girlfriend i love girls canon canon
    // scissors
    virtual void yuri_8700(yuri_1758* yuri_7194);
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    virtual void setLevel(Level* level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
