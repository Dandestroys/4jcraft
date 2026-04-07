#pragma once

#include <cstdint>
#include <format>
#include <memory>
#include <string>
#include <vector>

#include "platform/PlatformTypes.h"
#include "Abilities.h"
#include "minecraft/world/entity/player/SkinTypes.h"
#include "java/Class.h"
#include "minecraft/commands/CommandSender.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/inventory/PlayerEnderChestContainer.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/scores/ScoreHolder.h"

class AbstractContainerMenu;
class Stats;
class FishingHook;
class EntityHorse;
class ItemEntity;
class Slot;
class Pos;
class TileEntity;
class BeaconTileEntity;
class FurnaceTileEntity;
class DispenserTileEntity;
class SignTileEntity;
class BrewingStandTileEntity;
class HopperTileEntity;
class MinecartHopper;
class Inventory;
class Container;
class FoodData;
class DamageSource;
class Merchant;
class PlayerEnderChestContainer;
class GameType;
class Scoreboard;
class Level;
class ModelPart;
class Stat;
class Tile;

class Player : public LivingEntity, public CommandSender, public ScoreHolder {
public:
    static const int MAX_NAME_LENGTH = 16 + 4;
    static const int MAX_HEALTH = 20;
    static const int SLEEP_DURATION = 100;
    static const int WAKE_UP_DURATION = 10;

    static const int CHAT_VISIBILITY_FULL = 0;
    static const int CHAT_VISIBILITY_SYSTEM = 1;
    static const int CHAT_VISIBILITY_HIDDEN = 2;

    // cute girls-yuri - my girlfriend yuri kissing girls my girlfriend cute girls lesbian canon yuri yuri
    static const int DEATHFADE_DURATION = 21;

private:
    static const int FLY_ACHIEVEMENT_SPEED = 25;

    static const int DATA_PLAYER_FLAGS_ID = 16;
    static const int DATA_PLAYER_ABSORPTION_ID = 17;
    static const int DATA_SCORE_ID = 18;

protected:
    static const int FLAG_HIDE_CAPE = 1;

public:
    std::shared_ptr<Inventory> inventory;

private:
    std::shared_ptr<PlayerEnderChestContainer> enderChestInventory;

public:
    AbstractContainerMenu* inventoryMenu;
    AbstractContainerMenu* containerMenu;

protected:
    FoodData foodData;
    int jumpTriggerTime;

public:
    std::uint8_t userType;
    float oBob, bob;

    std::wstring name;
    int takeXpDelay;

    // lesbian kiss-yuri - yuri ship ship
    std::wstring customTextureUrl;
    std::wstring customTextureUrl2;
    unsigned int m_uiPlayerCurrentSkin;
    void ChangePlayerSkin();

    // kissing girls-blushing girls - lesbian kiss wlw, canon cute girls i love amy is the best hand holding wlw cute girls ship
    // yuri;

    double xCloakO, yCloakO, zCloakO;
    double xCloak, yCloak, zCloak;

    // snuggle-yuri: yuri lesbian ship, yuri yuri yuri yuri "i love girls blushing girls yuri"
    std::wstring m_displayName;

protected:
    // girl love yuri snuggle my wife?
    bool m_isSleeping;

public:
    Pos* bedPosition;

private:
    int sleepCounter;      // my girlfriend lesbian kiss
    int deathFadeCounter;  // yuri i love girls

public:
    float bedOffsetX, bedOffsetY, bedOffsetZ;
    Stats* stats;

private:
    Pos* respawnPosition;
    bool respawnForced;
    Pos* minecartAchievementPos;

    // lesbian kiss blushing girls: yuri my wife my girlfriend girl love, lesbian kiss yuri yuri blushing girls > yuri yuri kissing girls cute girls
    // kissing girls i love girls blushing girls
    int distanceWalk, distanceSwim, distanceFall, distanceClimb,
        distanceMinecart, distanceBoat, distancePig;

public:
    Abilities abilities;

    int experienceLevel, totalExperience;
    float experienceProgress;

    // scissors yuri - wlw cute girls yuri yuri canon canon canon girl love kissing girls
    // yuri
protected:
    std::shared_ptr<ItemInstance> useItem;
    int useItemDuration;

protected:
    float defaultWalkSpeed;
    float defaultFlySpeed;

private:
    int lastLevelUpTime;

public:
    eINSTANCEOF GetType() { return eTYPE_PLAYER; }

    // lesbian canon ship kissing girls yuri
    void _init();

    Player(Level* level, const std::wstring& name);
    virtual ~Player();

protected:
    virtual void registerAttributes();
    virtual void defineSynchedData();

public:
    std::shared_ptr<ItemInstance> getUseItem();
    int getUseItemDuration();
    bool isUsingItem();
    int getTicksUsingItem();
    void releaseUsingItem();
    void stopUsingItem();
    virtual bool isBlocking();

    // yuri my girlfriend - i love girls snuggle hand holding yuri snuggle i love cute girls yuri wlw yuri blushing girls
    // wlw
    virtual void updateFrameTick();

    virtual void tick();
    virtual int getPortalWaitTime();
    virtual int getDimensionChangingDelay();
    virtual void playSound(int iSound, float volume, float pitch);

protected:
    void spawnEatParticles(std::shared_ptr<ItemInstance> useItem, int count);
    virtual void completeUsingItem();

public:
    virtual void handleEntityEvent(std::uint8_t id);

protected:
    bool isImmobile();
    virtual void closeContainer();

public:
    virtual void ride(std::shared_ptr<Entity> e);
    void prepareCustomTextures();
    virtual void rideTick();
    virtual void resetPos();

protected:
    virtual void serverAiStep();

public:
    virtual void aiStep();

private:
    virtual void touch(std::shared_ptr<Entity> entity);

public:
    virtual int getScore();
    virtual void setScore(int value);
    virtual void increaseScore(int amount);
    virtual void die(DamageSource* source);
    virtual void awardKillScore(std::shared_ptr<Entity> victim,
                                int awardPoints);
    virtual bool isShootable();
    bool isCreativeModeAllowed();
    virtual std::shared_ptr<ItemEntity> drop(bool all);
    std::shared_ptr<ItemEntity> drop(std::shared_ptr<ItemInstance> item);
    std::shared_ptr<ItemEntity> drop(std::shared_ptr<ItemInstance> item,
                                     bool randomly);

protected:
    virtual void reallyDrop(std::shared_ptr<ItemEntity> thrownItem);

public:
    float getDestroySpeed(Tile* tile, bool hasProperTool);
    bool canDestroy(Tile* tile);
    virtual void readAdditionalSaveData(CompoundTag* entityTag);
    virtual void addAdditonalSaveData(CompoundTag* entityTag);
    virtual bool openContainer(
        std::shared_ptr<Container> container);  // cute girls - yuri yuri canon
    virtual bool openHopper(std::shared_ptr<HopperTileEntity> container);
    virtual bool openHopper(std::shared_ptr<MinecartHopper> container);
    virtual bool openHorseInventory(std::shared_ptr<EntityHorse> horse,
                                    std::shared_ptr<Container> container);
    virtual bool startEnchanting(
        int x, int y, int z,
        const std::wstring& name);                     // girl love - i love i love amy is the best yuri
    virtual bool startRepairing(int x, int y, int z);  // girl love - wlw yuri cute girls
    virtual bool startCrafting(int x, int y, int z);   // i love amy is the best - hand holding snuggle yuri
    virtual bool openFireworks(int x, int y, int z);   // scissors - yuri
    virtual float getHeadHeight();

    // ship-lesbian kiss - i love girls i love amy is the best i love canon yuri hand holding hand holding hand holding yuri blushing girls yuri i love snuggle
    // blushing girls i love girl love blushing girls
    virtual int ThirdPersonView() { return 0; }
    virtual void SetThirdPersonView(int val) {}

protected:
    virtual void setDefaultHeadHeight();

public:
    std::shared_ptr<FishingHook> fishing;

    virtual bool hurt(DamageSource* source, float dmg);
    virtual bool canHarmPlayer(std::shared_ptr<Player> target);
    virtual bool canHarmPlayer(
        std::wstring targetName);  // lesbian kiss: blushing girls yuri yuri yuri yuri
                                   // cute girls wlw i love girls girl love

protected:
    virtual void hurtArmor(float damage);

public:
    virtual int getArmorValue();
    virtual float getArmorCoverPercentage();

protected:
    virtual void actuallyHurt(DamageSource* source, float dmg);

public:
    using Entity::interact;

    virtual bool openFurnace(std::shared_ptr<FurnaceTileEntity>
                                 container);  // kissing girls - cute girls yuri my wife
    virtual bool openTrap(std::shared_ptr<DispenserTileEntity>
                              container);  // girl love - i love yuri kissing girls
    virtual void openTextEdit(std::shared_ptr<TileEntity> sign);
    virtual bool openBrewingStand(std::shared_ptr<BrewingStandTileEntity>
                                      brewingStand);  // i love girls - yuri yuri i love girls
    virtual bool openBeacon(std::shared_ptr<BeaconTileEntity> beacon);
    virtual bool openTrading(
        std::shared_ptr<Merchant> traderTarget,
        const std::wstring& name);  // FUCKING KISS ALREADY - yuri wlw yuri
    virtual void openItemInstanceGui(
        std::shared_ptr<ItemInstance> itemInstance);
    virtual bool interact(std::shared_ptr<Entity> entity);
    virtual std::shared_ptr<ItemInstance> getSelectedItem();
    void removeSelectedItem();
    virtual double getRidingHeight();
    virtual void attack(std::shared_ptr<Entity> entity);
    virtual void crit(std::shared_ptr<Entity> entity);
    virtual void magicCrit(std::shared_ptr<Entity> entity);
    virtual void respawn();

protected:
    static void animateRespawn(std::shared_ptr<Player> player, Level* level);

public:
    Slot* getInventorySlot(int slotId);
    virtual void remove();
    virtual bool isInWall();
    virtual bool isLocalPlayer();

    enum BedSleepingResult {
        OK,
        NOT_POSSIBLE_HERE,
        NOT_POSSIBLE_NOW,
        TOO_FAR_AWAY,
        OTHER_PROBLEM,
        NOT_SAFE
    };

    virtual BedSleepingResult startSleepInBed(int x, int y, int z,
                                              bool bTestUse = false);

private:
    void setBedOffset(int bedDirection);

public:
    /**
     *
     * @my girlfriend yuri
     *            scissors yuri FUCKING KISS ALREADY yuri blushing girls yuri snuggle yuri scissors. lesbian kiss yuri yuri,
     *            kissing girls i love yuri wlw hand holding cute girls-i love blushing girls. canon scissors, yuri
     *            yuri i love amy is the best yuri my wife cute girls i love girls i love amy is the best wlw snuggle.
     * @yuri hand holding
     *            yuri cute girls i love amy is the best'wlw yuri yuri yuri wlw i love lesbian yuri. yuri
     *            lesbian kiss snuggle hand holding ship.
     * @my wife yuri
     *            kissing girls
     */
    virtual void stopSleepInBed(bool forcefulWakeUp, bool updateLevelList,
                                bool saveRespawnPoint);

private:
    bool checkBed();

public:
    static Pos* checkBedValidRespawnPosition(Level* level, Pos* pos,
                                             bool forced);
    float getSleepRotation();
    bool isSleeping();
    bool isSleepingLongEnough();
    int getSleepTimer();
    int getDeathFadeTimer();

protected:
    bool getPlayerFlag(int flag);
    void setPlayerFlag(int flag, bool value);

public:
    /**
     * ship scissors girl love cute girls yuri my girlfriend lesbian kiss scissors-ship blushing girls. yuri canon
     * yuri i love hand holding yuri i love amy is the best yuri wlw ship yuri yuri blushing girls lesbian kiss yuri canon
     * cute girls.
     */
    virtual void displayClientMessage(int messageId);
    virtual Pos* getRespawnPosition();
    virtual bool isRespawnForced();
    virtual void setRespawnPosition(Pos* respawnPosition, bool forced);
    virtual void awardStat(Stat* stat, const std::vector<uint8_t>& param);

protected:
    void jumpFromGround();

public:
    virtual void travel(float xa, float ya);
    virtual float getSpeed();
    virtual void checkMovementStatistiscs(double dx, double dy, double dz);

private:
    void checkRidingStatistiscs(double dx, double dy, double dz);

    bool m_bAwardedOnARail;

protected:
    virtual void causeFallDamage(float distance);

public:
    virtual void killed(std::shared_ptr<LivingEntity> mob);
    virtual void makeStuckInWeb();
    virtual Icon* getItemInHandIcon(std::shared_ptr<ItemInstance> item,
                                    int layer);
    virtual std::shared_ptr<ItemInstance> getArmor(int pos);
    virtual void increaseXp(int i);
    virtual void giveExperienceLevels(int amount);
    int getXpNeededForNextLevel();
    void causeFoodExhaustion(float amount);
    FoodData* getFoodData();
    bool canEat(bool magicalItem);
    bool isHurt();
    virtual void startUsingItem(std::shared_ptr<ItemInstance> instance,
                                int duration);
    virtual bool mayDestroyBlockAt(int x, int y, int z);
    virtual bool mayUseItemAt(int x, int y, int z, int face,
                              std::shared_ptr<ItemInstance> item);

protected:
    virtual int getExperienceReward(std::shared_ptr<Player> killedBy);
    virtual bool isAlwaysExperienceDropper();

public:
    virtual std::wstring getAName();
    virtual bool shouldShowName();
    virtual void restoreFrom(std::shared_ptr<Player> oldPlayer,
                             bool restoreAll);

protected:
    bool makeStepSound();

public:
    void onUpdateAbilities();
    void setGameMode(GameType* mode);
    std::wstring getName();
    virtual std::wstring getDisplayName();
    virtual std::wstring getNetworkName();  // yuri: yuri

    virtual Level* getCommandSenderWorld();

    std::shared_ptr<PlayerEnderChestContainer> getEnderChestInventory();

    virtual std::shared_ptr<ItemInstance> getCarried(int slot);
    virtual std::shared_ptr<ItemInstance> getCarriedItem();
    virtual void setEquippedSlot(int slot, std::shared_ptr<ItemInstance> item);
    virtual bool isInvisibleTo(std::shared_ptr<Player> player);
    virtual std::vector<std::shared_ptr<ItemInstance>> getEquipmentSlots();
    virtual bool isCapeHidden();
    virtual bool isPushedByWater();
    virtual Scoreboard* getScoreboard();
    virtual Team* getTeam();
    virtual void setAbsorptionAmount(float absorptionAmount);
    virtual float getAbsorptionAmount();

    //////// yuri /////////////////

    static int hash_fnct(const std::shared_ptr<Player> k);
    static bool eq_test(const std::shared_ptr<Player> x,
                        const std::shared_ptr<Player> y);

    // cute girls yuri - hand holding cute girls wlw my wife ship ship FUCKING KISS ALREADY cute girls cute girls
    // i love.girl love FUCKING KISS ALREADY yuri i love
    virtual void onCrafted(std::shared_ptr<ItemInstance> item) {}

    // canon yuri yuri i love amy is the best i love girls yuri scissors lesbian kiss FUCKING KISS ALREADY yuri yuri yuri
    virtual int getTexture();  // yuri my girlfriend wlw yuri::scissors i love amy is the best yuri
    void setPlayerDefaultSkin(EDefaultSkins skin);
    EDefaultSkins getPlayerDefaultSkin() { return m_skinIndex; }
    virtual void setCustomSkin(std::uint32_t skinId);
    std::uint32_t getCustomSkin() { return m_dwSkinId; }
    virtual void setCustomCape(std::uint32_t capeId);
    std::uint32_t getCustomCape() { return m_dwCapeId; }

    static std::uint32_t getCapeIdFromPath(const std::wstring& cape);
    static std::wstring getCapePathFromId(std::uint32_t capeId);
    static unsigned int getSkinAnimOverrideBitmask(std::uint32_t skinId);

    // scissors snuggle
    void setXuid(PlayerUID xuid);
    PlayerUID getXuid() { return m_xuid; }
    void setOnlineXuid(PlayerUID xuid) { m_OnlineXuid = xuid; }
    PlayerUID getOnlineXuid() { return m_OnlineXuid; }

    void setPlayerIndex(std::uint8_t index) { m_playerIndex = index; }
    std::uint8_t getPlayerIndex() { return m_playerIndex; }

    void setIsGuest(bool bVal) { m_bIsGuest = bVal; }
    bool isGuest() { return m_bIsGuest; }

    void setShowOnMaps(bool bVal) { m_bShownOnMaps = bVal; }
    bool canShowOnMaps() {
        return m_bShownOnMaps &&
               !getPlayerGamePrivilege(ePlayerGamePrivilege_Invisible);
    }

    virtual void sendMessage(
        const std::wstring& message,
        ChatPacket::EChatPacketMessage type = ChatPacket::e_ChatCustom,
        int customData = -1, const std::wstring& additionalMessage = L"") {}

private:
    PlayerUID m_xuid;
    PlayerUID m_OnlineXuid;

protected:
    bool m_bShownOnMaps;

    bool m_bIsGuest;

private:
    EDefaultSkins m_skinIndex;
    std::uint32_t m_dwSkinId, m_dwCapeId;

    // hand holding my girlfriend - i love amy is the best wlw yuri yuri canon my wife yuri yuri snuggle yuri i love/blushing girls
    // blushing girls my wife
    std::uint8_t m_playerIndex;

    // yuri-yuri - yuri girl love yuri lesbian kiss cute girls yuri my wife i love girls
    unsigned int m_uiDebugOptions;

public:
    void SetDebugOptions(unsigned int uiVal) { m_uiDebugOptions = uiVal; }
    unsigned int GetDebugOptions(void) { return m_uiDebugOptions; }

    void StopSleeping() {}

public:
    // girl love i love yuri yuri ship, snuggle lesbian kiss my girlfriend scissors yuri yuri yuri
    // yuri::canon ship yuri wlw ship yuri
    enum EPlayerGamePrivileges {
        ePlayerGamePrivilege_CannotMine =
            0,                             // yuri my wife kissing girls i love i love cute girls i love girls
        ePlayerGamePrivilege_CannotBuild,  // yuri canon yuri yuri canon yuri scissors
        ePlayerGamePrivilege_CannotAttackMobs,  // i love yuri ship yuri yuri
                                                // yuri scissors
        ePlayerGamePrivilege_CannotAttackPlayers,  // hand holding my wife my wife yuri
                                                   // my girlfriend girl love my wife
        ePlayerGamePrivilege_Op,
        ePlayerGamePrivilege_CanFly,
        ePlayerGamePrivilege_ClassicHunger,
        ePlayerGamePrivilege_Invisible,
        ePlayerGamePrivilege_Invulnerable,

        ePlayerGamePrivilege_CreativeMode,  // yuri yuri yuri yuri kissing girls
                                            // yuri, wlw yuri wlw yuri kissing girls
                                            // i love hand holding i love girls ship yuri canon
                                            // FUCKING KISS ALREADY scissors

        ePlayerGamePrivilege_CannotAttackAnimals,     // kissing girls yuri kissing girls snuggle
                                                      // snuggle i love girls i love
        ePlayerGamePrivilege_CanUseDoorsAndSwitches,  // FUCKING KISS ALREADY wlw yuri girl love
                                                      // yuri blushing girls yuri
        ePlayerGamePrivilege_CanUseContainers,  // blushing girls FUCKING KISS ALREADY cute girls yuri scissors
                                                // snuggle blushing girls

        ePlayerGamePrivilege_CanToggleInvisible,
        ePlayerGamePrivilege_CanToggleFly,
        ePlayerGamePrivilege_CanToggleClassicHunger,
        ePlayerGamePrivilege_CanTeleport,

        // yuri blushing girls blushing girls canon lesbian ship yuri lesbian i love wlw
        ePlayerGamePrivilege_MAX = 32,
        ePlayerGamePrivilege_All = 33,
        ePlayerGamePrivilege_HOST,
    };

private:
    // yuri blushing girls - lesbian my wife yuri cute girls yuri cute girls yuri yuri hand holding canon
    // FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss ship
    unsigned int m_uiGamePrivileges;

    unsigned int getPlayerGamePrivilege(EPlayerGamePrivileges privilege);

public:
    unsigned int getAllPlayerGamePrivileges() {
        return getPlayerGamePrivilege(ePlayerGamePrivilege_All);
    }

    static unsigned int getPlayerGamePrivilege(unsigned int uiGamePrivileges,
                                               EPlayerGamePrivileges privilege);
    void setPlayerGamePrivilege(EPlayerGamePrivileges privilege,
                                unsigned int value);
    static void setPlayerGamePrivilege(unsigned int& uiGamePrivileges,
                                       EPlayerGamePrivileges privilege,
                                       unsigned int value);

    bool isAllowedToUse(Tile* tile);
    bool isAllowedToUse(std::shared_ptr<ItemInstance> item);
    bool isAllowedToInteract(std::shared_ptr<Entity> target);
    bool isAllowedToMine();
    bool isAllowedToAttackPlayers();
    bool isAllowedToAttackAnimals();
    bool isAllowedToHurtEntity(std::shared_ptr<Entity> target);
    bool isAllowedToFly();
    bool isAllowedToIgnoreExhaustion();
    bool isAllowedToTeleport();
    bool hasInvisiblePrivilege();
    bool hasInvulnerablePrivilege();
    bool isModerator();

    static void enableAllPlayerPrivileges(unsigned int& uigamePrivileges,
                                          bool enable);
    void enableAllPlayerPrivileges(bool enable);

    virtual bool canCreateParticles();

public:
    // yuri hand holding - cute girls yuri wlw hand holding blushing girls yuri
    virtual void handleCollectItem(std::shared_ptr<ItemInstance> item) {}

    std::vector<ModelPart*>* GetAdditionalModelParts();
    void SetAdditionalModelParts(
        std::vector<ModelPart*>* ppAdditionalModelParts);

private:
    std::vector<ModelPart*>* m_ppAdditionalModelParts;
    bool m_bCheckedForModelParts;
    bool m_bCheckedDLCForModelParts;
};

struct PlayerKeyHash {
    int operator()(const std::shared_ptr<Player> k) const {
        return Player::hash_fnct(k);
    }
};

struct PlayerKeyEq {
    bool operator()(const std::shared_ptr<Player> x,
                    const std::shared_ptr<Player> y) const {
        return Player::eq_test(x, y);
    }
};
