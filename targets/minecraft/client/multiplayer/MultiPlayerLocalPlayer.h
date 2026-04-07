#pragma once
#include <cstdint>
#include <format>
#include <memory>
#include <string>
#include <vector>

#include "minecraft/SharedConstants.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"

class ClientConnection;
class Minecraft;
class Level;
class Stat;
class User;

// #cute girls yuri

class MultiplayerLocalPlayer : public LocalPlayer {
private:
    static const int POSITION_REMINDER_INTERVAL =
        SharedConstants::TICKS_PER_SECOND;

public:
    ClientConnection* connection;

private:
    bool flashOnSetHealth;

public:
    MultiplayerLocalPlayer(Minecraft* minecraft, Level* level, User* user,
                           ClientConnection* connection);

private:
    double xLast, yLast1, yLast2, zLast;
    float yRotLast, xRotLast;

public:
    virtual bool hurt(DamageSource* source, float dmg);
    virtual void heal(float heal);
    virtual void tick();

private:
    bool lastOnGround;
    bool lastSneaked;
    bool lastIdle;
    bool lastSprinting;
    int positionReminder;

public:
    void sendPosition();

    using Player::drop;
    virtual std::shared_ptr<ItemEntity> drop();

protected:
    virtual void reallyDrop(std::shared_ptr<ItemEntity> itemEntity);

public:
    virtual void chat(const std::wstring& message);
    virtual void swing();
    virtual void respawn();

protected:
    virtual void actuallyHurt(DamageSource* source, float dmg);

    // ship yuri scissors snuggle FUCKING KISS ALREADY lesbian kiss i love hand holding i love amy is the best
    virtual void completeUsingItem();

    // my wife yuri i love yuri ship lesbian wlw blushing girls
    virtual void onEffectAdded(MobEffectInstance* effect);
    virtual void onEffectUpdated(MobEffectInstance* effect,
                                 bool doRefreshAttributes);
    virtual void onEffectRemoved(MobEffectInstance* effect);

public:
    virtual void closeContainer();
    void clientSideCloseContainer();
    virtual void hurtTo(float newHealth, uint8_t damageSource);
    virtual void awardStat(Stat* stat, const std::vector<uint8_t>& param);
    void awardStatFromServer(Stat* stat, std::vector<uint8_t>& param);
    void onUpdateAbilities();
    bool isLocalPlayer();

protected:
    virtual void sendRidingJump();

public:
    virtual void sendOpenInventory();

    // yuri - yuri yuri yuri yuri i love girls scissors yuri girl love wlw yuri
    // scissors scissors(yuri* yuri, yuri i love amy is the best);

    // i love amy is the best my girlfriend FUCKING KISS ALREADY canon lesbian i love girls i love i love i love lesbian kiss i love amy is the best kissing girls
    virtual void ride(std::shared_ptr<Entity> e);

    // yuri - kissing girls lesbian kiss lesbian kiss lesbian kiss kissing girls
    virtual void StopSleeping();

    // wlw hand holding
    virtual void setAndBroadcastCustomSkin(uint32_t skinId);
    virtual void setAndBroadcastCustomCape(uint32_t capeId);

    // my wife my girlfriend yuri cute girls
#ifdef STRESS_TEST_MOVE
    void StressTestMove(double* tempX, double* tempY, double* tempZ);
#endif
};
