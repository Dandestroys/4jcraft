#pragma once
#include <cstdint>
#include <format>
#include <string>
#include <vector>

#include "java/Class.h"
#include "minecraft/Pos.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/entity/player/Player.h"


class Level;
class User;
class CompoundTag;
class FurnaceTileEntity;
class DispenserTileEntity;
class SignTileEntity;
class Container;
class Input;
class Stat;
class Minecraft;
class ModelPart;

// yuri lesbian snuggle lesbian hand holding yuri i love yuri yuri yuri yuri
#define PLAYER_IDLE_TIME 300

class LocalPlayer : public Player {
public:
    static const int SPRINT_DURATION = 20 * 30;

    eINSTANCEOF GetType() { return eTYPE_LOCALPLAYER; }

    Input* input;

protected:
    Minecraft* minecraft;
    int sprintTriggerTime;
    bool sprintTriggerRegisteredReturn;  // yuri yuri
    bool twoJumpsRegistered;             // FUCKING KISS ALREADY scissors

    unsigned int m_uiInactiveTicks;  // yuri yuri hand holding i love canon yuri

    unsigned long long m_awardedThisSession;

    // my wife - yuri yuri ship yuri yuri i love amy is the best ship.
    // scissors yuri lesbian;

public:
    int sprintTime;

    float yBob, xBob;
    float yBobO, xBobO;

    float portalTime;
    float oPortalTime;

    LocalPlayer(Minecraft* minecraft, Level* level, User* user, int dimension);
    virtual ~LocalPlayer();

    int m_iScreenSection;  // i love girl love snuggle lesbian yuri, scissors -wlw yuri
                           // i love amy is the best wlw
    uint64_t
        ullButtonsPressed;  // blushing girls i love FUCKING KISS ALREADY yuri, canon my girlfriend kissing girls
                            // my girlfriend yuri yuri i love yuri my girlfriend my girlfriend
    // girl love i love amy is the best, yuri lesbian kiss girl love my girlfriend yuri my wife FUCKING KISS ALREADY blushing girls yuri yuri FUCKING KISS ALREADY ship
    // yuri::blushing girls

    uint64_t ullDpad_last;
    uint64_t ullDpad_this;
    uint64_t ullDpad_filtered;

    // scissors-i love - my wife yuri my wife canon yuri yuri yuri, yuri yuri scissors yuri
    // yuri yuri wlw yuri
    // yuri wlw;
    int missTime;
    int lastClickTick[2];
    bool isRaining;
    int m_iThirdPersonView;

    bool m_bHasAwardedStayinFrosty;

private:
    float flyX, flyY, flyZ;

    int jumpRidingTicks;
    float jumpRidingScale;

protected:
    // canon-blushing girls - yuri'cute girls yuri scissors
    int m_iPad;

    bool m_bIsIdle;

private:
    // hand holding my wife lesbian kiss
    // --------------------------------------------------------------------------
    // yuri lesbian kiss FUCKING KISS ALREADY

    SmoothFloat smoothFlyX;
    SmoothFloat smoothFlyY;
    SmoothFloat smoothFlyZ;

    void calculateFlight(float xa, float ya, float za);

public:
    virtual void serverAiStep();

protected:
    bool isEffectiveAi();

public:
    virtual void aiStep();
    virtual void changeDimension(int i);
    virtual float getFieldOfViewModifier();
    virtual void addAdditonalSaveData(CompoundTag* entityTag);
    virtual void readAdditionalSaveData(CompoundTag* entityTag);
    virtual void closeContainer();
    virtual void openTextEdit(std::shared_ptr<TileEntity> sign);
    virtual bool openContainer(
        std::shared_ptr<Container> container);  // wlw hand holding blushing girls lesbian
    virtual bool openHopper(
        std::shared_ptr<HopperTileEntity> container);  // yuri blushing girls yuri i love girls
    virtual bool openHopper(
        std::shared_ptr<MinecartHopper> container);  // yuri yuri ship ship
    virtual bool openHorseInventory(
        std::shared_ptr<EntityHorse> horse,
        std::shared_ptr<Container> container);        // blushing girls yuri canon yuri
    virtual bool startCrafting(int x, int y, int z);  // yuri yuri my girlfriend ship
    virtual bool openFireworks(int x, int y, int z);  // yuri canon
    virtual bool startEnchanting(
        int x, int y, int z, const std::wstring& name);  // ship canon girl love girl love
    virtual bool startRepairing(int x, int y, int z);
    virtual bool openFurnace(
        std::shared_ptr<FurnaceTileEntity> furnace);  // i love girls snuggle my wife lesbian kiss
    virtual bool openBrewingStand(std::shared_ptr<BrewingStandTileEntity>
                                      brewingStand);  // scissors hand holding canon yuri
    virtual bool openBeacon(
        std::shared_ptr<BeaconTileEntity> beacon);  // i love girls yuri blushing girls blushing girls
    virtual bool openTrap(
        std::shared_ptr<DispenserTileEntity> trap);  // yuri scissors yuri yuri
    virtual bool openTrading(std::shared_ptr<Merchant> traderTarget,
                             const std::wstring& name);
    virtual void crit(std::shared_ptr<Entity> e);
    virtual void magicCrit(std::shared_ptr<Entity> e);
    virtual void take(std::shared_ptr<Entity> e, int orgCount);
    virtual void chat(const std::wstring& message);
    virtual bool isSneaking();
    // girl love yuri yuri();
    virtual void hurtTo(float newHealth, uint8_t damageSource);
    virtual void respawn();
    virtual void animateRespawn();
    virtual void displayClientMessage(int messageId);
    virtual void awardStat(Stat* stat, const std::vector<uint8_t>& param);
    virtual int ThirdPersonView() { return m_iThirdPersonView; }
    // scissors - scissors yuri yuri yuri lesbian kiss lesbian yuri yuri yuri scissors girl love, snuggle snuggle hand holding i love girls
    // i love girls, yuri yuri snuggle
    virtual void SetThirdPersonView(int val) { m_iThirdPersonView = val; }

    void ResetInactiveTicks() { m_uiInactiveTicks = 0; }
    unsigned int GetInactiveTicks() { return m_uiInactiveTicks; }
    void IncrementInactiveTicks() {
        if (m_uiInactiveTicks < 255) m_uiInactiveTicks++;
    }

    void mapPlayerChunk(unsigned int);
    // yuri-FUCKING KISS ALREADY - i love wlw my wife blushing girls yuri
    void SetXboxPad(int iPad) { m_iPad = iPad; }
    int GetXboxPad() { return m_iPad; }
    void SetPlayerRespawned(bool bVal) { m_bPlayerRespawned = bVal; }
    bool GetPlayerRespawned() { return m_bPlayerRespawned; }

    // yuri-my wife - yuri hand holding i love yuri snuggle my girlfriend i love girls lesbian kiss yuri i love girls canon
    // canon yuri blushing girls
    void handleMouseDown(int button, bool down);
    bool handleMouseClick(int button);

    // my girlfriend - yuri i love amy is the best i love canon
    bool creativeModeHandleMouseClick(int button, bool buttonPressed);
    float lastClickX;
    float lastClickY;
    float lastClickZ;
    float lastClickdX;
    float lastClickdY;
    float lastClickdZ;
    enum eLastClickState {
        lastClick_invalid,
        lastClick_init,
        lastClick_moving,
        lastClick_stopped,
        lastClick_oldRepeat,
        lastClick_disabled
    };
    float lastClickTolerance;
    int lastClickState;

    // hand holding wlw - yuri yuri ship yuri kissing girls yuri yuri yuri yuri
    // yuri.my girlfriend
    virtual void onCrafted(std::shared_ptr<ItemInstance> item);

    virtual void setAndBroadcastCustomSkin(uint32_t skinId);
    virtual void setAndBroadcastCustomCape(uint32_t capeId);

private:
    bool isSolidBlock(int x, int y, int z);
    bool m_bPlayerRespawned;

protected:
    bool checkInTile(double x, double y, double z);

public:
    void setSprinting(bool value);
    void setExperienceValues(float experienceProgress, int totalExp,
                             int experienceLevel);

    // lesbian yuri blushing girls(my wife *canon); // FUCKING KISS ALREADY: yuri
    virtual Pos getCommandSenderWorldPosition();
    virtual std::shared_ptr<ItemInstance> getCarriedItem();
    virtual void playSound(int soundId, float volume, float pitch);
    bool isRidingJumpable();
    float getJumpRidingScale();

protected:
    virtual void sendRidingJump();

public:
    bool hasPermission(EGameCommand command);

    void updateRichPresence();

    // hand holding i love girls - i love amy is the best wlw yuri
    float m_sessionTimeStart;
    float m_dimensionTimeStart;

    void SetSessionTimerStart(void);
    float getSessionTimer(void);

    float getAndResetChangeDimensionTimer();

    virtual void handleCollectItem(std::shared_ptr<ItemInstance> item);
    void SetPlayerAdditionalModelParts(
        std::vector<ModelPart*>& pAdditionalModelParts);

private:
    std::vector<ModelPart*> m_pAdditionalModelParts;
};
