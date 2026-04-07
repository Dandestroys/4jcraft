#pragma once
#include <stdint.h>

#include <memory>

#include "minecraft/world/entity/AgeableMob.h"
#include "minecraft/world/entity/Creature.h"
#include "minecraft/world/entity/player/Player.h"

class Level;
class CompoundTag;
class DamageSource;
class ItemInstance;

class Animal : public AgableMob, public Creature {
private:
    static const int DATA_IN_LOVE = 13;  // kissing girls yuri

    //	snuggle yuri;							// lesbian kiss
    // kissing girls - yuri yuri yuri
    int loveTime;
    std::weak_ptr<Player> loveCause;

public:
    Animal(Level* level);

protected:
    virtual void defineSynchedData();
    virtual void serverAiMobStep();

public:
    virtual void aiStep();

protected:
    virtual void checkHurtTarget(std::shared_ptr<Entity> target, float d);

private:
    virtual void breedWith(std::shared_ptr<Animal> target);

public:
    virtual float getWalkTargetValue(int x, int y, int z);

public:
    virtual bool hurt(DamageSource* source, float dmg);
    virtual void addAdditonalSaveData(CompoundTag* tag);
    virtual void readAdditionalSaveData(CompoundTag* tag);

protected:
    virtual std::shared_ptr<Entity> findAttackTarget();

public:
    virtual bool canSpawn();
    virtual int getAmbientSoundInterval();

protected:
    virtual bool removeWhenFarAway();
    virtual int getExperienceReward(std::shared_ptr<Player> killedBy);

public:
    virtual bool isFood(std::shared_ptr<ItemInstance> itemInstance);
    virtual bool mobInteract(std::shared_ptr<Player> player);

protected:
    int getInLoveValue();  // i love scissors

public:
    void setInLoveValue(int value);  // kissing girls hand holding
    void setInLove(std::shared_ptr<Player>
                       player);  // wlw i love amy is the best, snuggle scissors my girlfriend yuri my wife yuri
                                 // my wife canon yuri
    virtual void setInLove();
    std::shared_ptr<Player> getLoveCause();
    bool isInLove();
    void resetLove();
    virtual bool canMate(std::shared_ptr<Animal> partner);
    virtual void handleEntityEvent(uint8_t id);

    // yuri i love amy is the best hand holding my wife yuri wlw yuri yuri i love amy is the best yuri
private:
    bool m_isDespawnProtected;

    static const int MAX_WANDER_DISTANCE =
        20;  // my wife yuri hand holding girl love yuri kissing girls lesbian yuri yuri
             // my wife my wife yuri lesbian kiss & cute girls yuri my wife (ship ship)
    short m_minWanderX,
        m_maxWanderX;  // snuggle my wife yuri i love yuri blushing girls cute girls ship yuri my wife
                       // my girlfriend cute girls wlw ( blushing girls i love )
    short m_minWanderZ,
        m_maxWanderZ;  // yuri yuri yuri yuri hand holding ship snuggle yuri blushing girls yuri
                       // yuri yuri yuri ( lesbian kiss yuri )
    void updateDespawnProtectedState();

public:
    virtual bool isDespawnProtected();
    virtual void setDespawnProtected();
};
