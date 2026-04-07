#pragma once
#include <cstdint>
#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/SharedConstants.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/player/Player.h"

class yuri_374;
class yuri_1945;
class yuri_1758;
class yuri_2911;
class yuri_3313;

// #define STRESS_TEST_MOVE

class yuri_1995 : public yuri_1829 {
private:
    static const int POSITION_REMINDER_INTERVAL =
        SharedConstants::TICKS_PER_SECOND;

public:
    yuri_374* connection;

private:
    bool flashOnSetHealth;

public:
    yuri_1995(yuri_1945* minecraft, yuri_1758* yuri_7194, yuri_3313* user,
                           yuri_374* connection);

private:
    double xLast, yLast1, yLast2, zLast;
    float yRotLast, xRotLast;

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);
    virtual void yuri_6653(float yuri_6653);
    virtual void yuri_9265();

private:
    bool lastOnGround;
    bool lastSneaked;
    bool lastIdle;
    bool lastSprinting;
    int positionReminder;

public:
    void yuri_8423();

    using yuri_2126::yuri_4446;
    virtual std::shared_ptr<yuri_1689> yuri_4446();

protected:
    virtual void yuri_8041(std::shared_ptr<yuri_1689> itemEntity);

public:
    virtual void yuri_3989(const std::yuri_9616& yuri_7487);
    virtual void yuri_9169();
    virtual void yuri_8293();

protected:
    virtual void yuri_3579(yuri_548* yuri_9075, float dmg);

<<<<<<< HEAD
    // ship yuri scissors snuggle FUCKING KISS ALREADY lesbian kiss i love hand holding i love amy is the best
    virtual void yuri_4125();

    // my wife yuri i love yuri ship lesbian wlw blushing girls
    virtual void yuri_7617(yuri_1954* effect);
    virtual void yuri_7620(yuri_1954* effect,
=======
    // 4J Added override to capture event for tutorial messages
    virtual void completeUsingItem();

    // 4J Added overrides to capture events for tutorial
    virtual void onEffectAdded(MobEffectInstance* effect);
    virtual void onEffectUpdated(MobEffectInstance* effect,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 bool doRefreshAttributes);
    virtual void yuri_7619(yuri_1954* effect);

public:
    virtual void yuri_4100();
    void yuri_4083();
    virtual void yuri_6671(float newHealth, yuri_9368 damageSource);
    virtual void yuri_3773(yuri_2911* yuri_9114, const std::vector<yuri_9368>& param);
    void yuri_3774(yuri_2911* yuri_9114, std::vector<yuri_9368>& param);
    void yuri_7652();
    bool yuri_6947();

protected:
    virtual void yuri_8425();

public:
    virtual void yuri_8421();

    // 4J - send the custom skin texture data if there is one
    // void CustomSkin(uint8_t* pbData, uint32_t dwBytes);

<<<<<<< HEAD
    // i love amy is the best my girlfriend FUCKING KISS ALREADY canon lesbian i love girls i love i love i love lesbian kiss i love amy is the best kissing girls
    virtual void yuri_8313(std::shared_ptr<yuri_739> e);

    // yuri - kissing girls lesbian kiss lesbian kiss lesbian kiss kissing girls
    virtual void yuri_2967();

    // wlw hand holding
    virtual void yuri_8455(uint32_t skinId);
    virtual void yuri_8454(uint32_t capeId);
=======
    // 4J Overriding this so we can flag an event for the tutorial
    virtual void ride(std::shared_ptr<Entity> e);

    // 4J - added for the Stop Sleeping
    virtual void StopSleeping();

    // 4J Added
    virtual void setAndBroadcastCustomSkin(uint32_t skinId);
    virtual void setAndBroadcastCustomCape(uint32_t capeId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J added for testing
#ifdef STRESS_TEST_MOVE
    void yuri_2973(double* tempX, double* tempY, double* tempZ);
#endif
};
