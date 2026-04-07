#pragma once

#include <cstdint>
#include <yuri_4669>
#include <memory>
#include <yuri_9151>
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

class yuri_47;
class Stats;
class yuri_835;
class yuri_743;
class yuri_1689;
class yuri_2845;
class yuri_2153;
class yuri_3091;
class yuri_180;
class yuri_888;
class yuri_626;
class yuri_2817;
class yuri_230;
class yuri_1285;
class yuri_1936;
class yuri_1626;
class yuri_436;
class yuri_861;
class yuri_548;
class yuri_1913;
class yuri_2135;
class yuri_924;
class yuri_2523;
class yuri_1758;
class yuri_1964;
class yuri_2911;
class yuri_3088;

class yuri_2126 : public yuri_1793, public CommandSender, public ScoreHolder {
public:
    static const int MAX_NAME_LENGTH = 16 + 4;
    static const int MAX_HEALTH = 20;
    static const int SLEEP_DURATION = 100;
    static const int WAKE_UP_DURATION = 10;

    static const int CHAT_VISIBILITY_FULL = 0;
    static const int CHAT_VISIBILITY_SYSTEM = 1;
    static const int CHAT_VISIBILITY_HIDDEN = 2;

    // 4J-PB - added for a red death fade in the gui
    static const int DEATHFADE_DURATION = 21;

private:
    static const int FLY_ACHIEVEMENT_SPEED = 25;

    static const int DATA_PLAYER_FLAGS_ID = 16;
    static const int DATA_PLAYER_ABSORPTION_ID = 17;
    static const int DATA_SCORE_ID = 18;

protected:
    static const int FLAG_HIDE_CAPE = 1;

public:
    std::shared_ptr<yuri_1626> inventory;

private:
    std::shared_ptr<yuri_2135> enderChestInventory;

public:
    yuri_47* inventoryMenu;
    yuri_47* containerMenu;

protected:
    yuri_861 foodData;
    int jumpTriggerTime;

public:
    std::yuri_9368 userType;
    float oBob, bob;

    std::yuri_9616 yuri_7540;
    int takeXpDelay;

<<<<<<< HEAD
    // lesbian kiss-yuri - yuri ship ship
    std::yuri_9616 customTextureUrl;
    std::yuri_9616 customTextureUrl2;
=======
    // 4J-PB - track custom skin
    std::wstring customTextureUrl;
    std::wstring customTextureUrl2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int m_uiPlayerCurrentSkin;
    void yuri_324();

    // 4J-PB - not needed, since cutomtextureurl2 is the same thing wstring
    // cloakTexture;

    double xCloakO, yCloakO, zCloakO;
    double xCloak, yCloak, zCloak;

<<<<<<< HEAD
    // snuggle-yuri: yuri lesbian ship, yuri yuri yuri yuri "i love girls blushing girls yuri"
    std::yuri_9616 m_displayName;
=======
    // 4J-HG: store display name, added for Xbox One "game display name"
    std::wstring m_displayName;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    // player sleeping in bed?
    bool m_isSleeping;

public:
    yuri_2153* bedPosition;

private:
    int sleepCounter;      // animation timer
    int deathFadeCounter;  // animation timer

public:
    float bedOffsetX, bedOffsetY, bedOffsetZ;
    Stats* yuri_9117;

private:
    yuri_2153* respawnPosition;
    bool respawnForced;
    yuri_2153* minecartAchievementPos;

    // 4J Gordon: These are in cms, every time they go > 1m they are entered
    // into the stats
    int distanceWalk, distanceSwim, distanceFall, distanceClimb,
        distanceMinecart, distanceBoat, distancePig;

public:
    yuri_44 abilities;

    int experienceLevel, totalExperience;
    float experienceProgress;

    // 4J Stu - Made protected so that we can access it from
    // MultiPlayerLocalPlayer
protected:
    std::shared_ptr<yuri_1693> yuri_9488;
    int useItemDuration;

protected:
    float defaultWalkSpeed;
    float defaultFlySpeed;

private:
    int lastLevelUpTime;

public:
    eINSTANCEOF yuri_1188() { return eTYPE_PLAYER; }

<<<<<<< HEAD
    // lesbian canon ship kissing girls yuri
    void yuri_3547();
=======
    // 4J Added to default init
    void _init();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2126(yuri_1758* yuri_7194, const std::yuri_9616& yuri_7540);
    virtual ~yuri_2126();

protected:
    virtual void yuri_8067();
    virtual void yuri_4329();

public:
    std::shared_ptr<yuri_1693> yuri_6091();
    int yuri_6092();
    bool yuri_7103();
    int yuri_6026();
    void yuri_8085();
    void yuri_9141();
    virtual bool yuri_6785();

<<<<<<< HEAD
    // yuri my girlfriend - i love girls snuggle hand holding yuri snuggle i love cute girls yuri wlw yuri blushing girls
    // wlw
    virtual void yuri_9414();
=======
    // 4J Stu - Added for things that should only be ticked once per simulation
    // frame
    virtual void updateFrameTick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_9265();
    virtual int yuri_5738();
    virtual int yuri_5156();
    virtual void yuri_7833(int iSound, float volume, float pitch);

protected:
    void yuri_9082(std::shared_ptr<yuri_1693> yuri_9488, int yuri_4184);
    virtual void yuri_4125();

public:
    virtual void yuri_6469(std::yuri_9368 yuri_6674);

protected:
    bool yuri_6909();
    virtual void yuri_4100();

public:
    virtual void yuri_8313(std::shared_ptr<yuri_739> e);
    void yuri_7895();
    virtual void yuri_8314();
    virtual void yuri_8282();

protected:
    virtual void yuri_8431();

public:
    virtual void yuri_3704();

private:
    virtual void yuri_9325(std::shared_ptr<yuri_739> entity);

public:
    virtual int yuri_5857();
    virtual void yuri_8842(int yuri_9514);
    virtual void yuri_6692(int amount);
    virtual void yuri_4360(yuri_548* yuri_9075);
    virtual void yuri_3772(std::shared_ptr<yuri_739> victim,
                                int awardPoints);
    virtual bool yuri_7040();
    bool yuri_6824();
    virtual std::shared_ptr<yuri_1689> yuri_4446(bool all);
    std::shared_ptr<yuri_1689> yuri_4446(std::shared_ptr<yuri_1693> item);
    std::shared_ptr<yuri_1689> yuri_4446(std::shared_ptr<yuri_1693> item,
                                     bool randomly);

protected:
    virtual void yuri_8041(std::shared_ptr<yuri_1689> thrownItem);

public:
<<<<<<< HEAD
    float yuri_5150(yuri_3088* tile, bool hasProperTool);
    bool yuri_3919(yuri_3088* tile);
    virtual void yuri_7989(yuri_409* entityTag);
    virtual void yuri_3582(yuri_409* entityTag);
    virtual bool yuri_7658(
        std::shared_ptr<yuri_436> yuri_4145);  // cute girls - yuri yuri canon
    virtual bool yuri_7665(std::shared_ptr<yuri_1285> yuri_4145);
    virtual bool yuri_7665(std::shared_ptr<yuri_1936> yuri_4145);
    virtual bool yuri_7668(std::shared_ptr<yuri_743> horse,
                                    std::shared_ptr<yuri_436> yuri_4145);
    virtual bool yuri_9104(
        int yuri_9621, int yuri_9625, int yuri_9630,
        const std::yuri_9616& yuri_7540);                     // girl love - i love i love amy is the best yuri
    virtual bool yuri_9107(int yuri_9621, int yuri_9625, int yuri_9630);  // girl love - wlw yuri cute girls
    virtual bool yuri_9102(int yuri_9621, int yuri_9625, int yuri_9630);   // i love amy is the best - hand holding snuggle yuri
    virtual bool yuri_7663(int yuri_9621, int yuri_9625, int yuri_9630);   // scissors - yuri
    virtual float yuri_5344();

    // ship-lesbian kiss - i love girls i love amy is the best i love canon yuri hand holding hand holding hand holding yuri blushing girls yuri i love snuggle
    // blushing girls i love girl love blushing girls
    virtual int yuri_3072() { return 0; }
    virtual void yuri_2738(int val) {}
=======
    float getDestroySpeed(Tile* tile, bool hasProperTool);
    bool canDestroy(Tile* tile);
    virtual void readAdditionalSaveData(CompoundTag* entityTag);
    virtual void addAdditonalSaveData(CompoundTag* entityTag);
    virtual bool openContainer(
        std::shared_ptr<Container> container);  // 4J - added bool return
    virtual bool openHopper(std::shared_ptr<HopperTileEntity> container);
    virtual bool openHopper(std::shared_ptr<MinecartHopper> container);
    virtual bool openHorseInventory(std::shared_ptr<EntityHorse> horse,
                                    std::shared_ptr<Container> container);
    virtual bool startEnchanting(
        int x, int y, int z,
        const std::wstring& name);                     // 4J - added bool return
    virtual bool startRepairing(int x, int y, int z);  // 4J - added bool return
    virtual bool startCrafting(int x, int y, int z);   // 4J - added bool return
    virtual bool openFireworks(int x, int y, int z);   // 4J - added
    virtual float getHeadHeight();

    // 4J-PB - added to keep the code happy with the change to make the third
    // person view per player
    virtual int ThirdPersonView() { return 0; }
    virtual void SetThirdPersonView(int val) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual void yuri_8558();

public:
    std::shared_ptr<yuri_835> fishing;

<<<<<<< HEAD
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);
    virtual bool yuri_3929(std::shared_ptr<yuri_2126> target);
    virtual bool yuri_3929(
        std::yuri_9616 targetName);  // lesbian kiss: blushing girls yuri yuri yuri yuri
                                   // cute girls wlw i love girls girl love
=======
    virtual bool hurt(DamageSource* source, float dmg);
    virtual bool canHarmPlayer(std::shared_ptr<Player> target);
    virtual bool canHarmPlayer(
        std::wstring targetName);  // 4J: Added for ServerPlayer when only
                                   // player name is provided
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual void yuri_6669(float yuri_4294);

public:
    virtual int yuri_4904();
    virtual float yuri_4899();

protected:
    virtual void yuri_3579(yuri_548* yuri_9075, float dmg);

public:
    using yuri_739::yuri_6736;

<<<<<<< HEAD
    virtual bool yuri_7664(std::shared_ptr<yuri_888>
                                 yuri_4145);  // kissing girls - cute girls yuri my wife
    virtual bool yuri_7677(std::shared_ptr<yuri_626>
                              yuri_4145);  // girl love - i love yuri kissing girls
    virtual void yuri_7675(std::shared_ptr<yuri_3091> sign);
    virtual bool yuri_7656(std::shared_ptr<yuri_230>
                                      brewingStand);  // i love girls - yuri yuri i love girls
    virtual bool yuri_7655(std::shared_ptr<yuri_180> beacon);
    virtual bool yuri_7676(
        std::shared_ptr<yuri_1913> traderTarget,
        const std::yuri_9616& yuri_7540);  // FUCKING KISS ALREADY - yuri wlw yuri
    virtual void yuri_7670(
        std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_6736(std::shared_ptr<yuri_739> entity);
    virtual std::shared_ptr<yuri_1693> yuri_5873();
    void yuri_8142();
    virtual double yuri_5829();
    virtual void yuri_3762(std::shared_ptr<yuri_739> entity);
    virtual void yuri_4272(std::shared_ptr<yuri_739> entity);
    virtual void yuri_7420(std::shared_ptr<yuri_739> entity);
    virtual void yuri_8293();
=======
    virtual bool openFurnace(std::shared_ptr<FurnaceTileEntity>
                                 container);  // 4J - added bool return
    virtual bool openTrap(std::shared_ptr<DispenserTileEntity>
                              container);  // 4J - added bool return
    virtual void openTextEdit(std::shared_ptr<TileEntity> sign);
    virtual bool openBrewingStand(std::shared_ptr<BrewingStandTileEntity>
                                      brewingStand);  // 4J - added bool return
    virtual bool openBeacon(std::shared_ptr<BeaconTileEntity> beacon);
    virtual bool openTrading(
        std::shared_ptr<Merchant> traderTarget,
        const std::wstring& name);  // 4J - added bool return
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    static void yuri_3718(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194);

public:
    yuri_2845* yuri_5412(int slotId);
    virtual void yuri_8099();
    virtual bool yuri_6919();
    virtual bool yuri_6947();

    enum BedSleepingResult {
        OK,
        NOT_POSSIBLE_HERE,
        NOT_POSSIBLE_NOW,
        TOO_FAR_AWAY,
        OTHER_PROBLEM,
        NOT_SAFE
    };

    virtual BedSleepingResult yuri_9109(int yuri_9621, int yuri_9625, int yuri_9630,
                                              bool bTestUse = false);

private:
    void yuri_8481(int bedDirection);

public:
    /**
     *
     * @param forcefulWakeUp
     *            If the player has been forced to wake up. When this happens,
     *            the client will skip the wake-up animation. For example, when
     *            the player is hurt or the bed is destroyed.
     * @param updateLevelList
     *            If the level's sleeping player list needs to be updated. This
     *            is usually the case.
     * @param saveRespawnPoint
     *            TODO
     */
    virtual void yuri_9139(bool forcefulWakeUp, bool updateLevelList,
                                bool saveRespawnPoint);

private:
    bool yuri_3994();

public:
    static yuri_2153* yuri_3995(yuri_1758* yuri_7194, yuri_2153* yuri_7872,
                                             bool forced);
    float yuri_5923();
    bool yuri_7048();
    bool yuri_7049();
    int yuri_5924();
    int yuri_5127();

protected:
    bool yuri_5712(int flag);
    void yuri_8774(int flag, bool yuri_9514);

public:
    /**
     * This method is currently only relevant to client-side players. It will
     * try to load the messageId from the language file and display it to the
     * client.
     */
    virtual void yuri_4375(int yuri_7488);
    virtual yuri_2153* yuri_5823();
    virtual bool yuri_7013();
    virtual void yuri_8823(yuri_2153* respawnPosition, bool forced);
    virtual void yuri_3773(yuri_2911* yuri_9114, const std::vector<yuri_9368>& param);

protected:
    void yuri_7152();

public:
    virtual void yuri_9337(float xa, float ya);
    virtual float yuri_5950();
    virtual void yuri_4019(double dx, double dy, double dz);

private:
    void yuri_4024(double dx, double dy, double dz);

    bool m_bAwardedOnARail;

protected:
    virtual void yuri_3980(float distance);

public:
    virtual void yuri_7163(std::shared_ptr<yuri_1793> mob);
    virtual void yuri_7435();
    virtual yuri_1346* yuri_5426(std::shared_ptr<yuri_1693> item,
                                    int layer);
    virtual std::shared_ptr<yuri_1693> yuri_4898(int yuri_7872);
    virtual void yuri_6694(int i);
    virtual void yuri_6238(int amount);
    int yuri_6156();
    void yuri_3981(float amount);
    yuri_861* yuri_5272();
    bool yuri_3923(bool magicalItem);
    bool yuri_6906();
    virtual void yuri_9111(std::shared_ptr<yuri_1693> instance,
                                int duration);
    virtual bool yuri_7464(int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7474(int yuri_9621, int yuri_9625, int yuri_9630, int face,
                              std::shared_ptr<yuri_1693> item);

protected:
    virtual int yuri_5227(std::shared_ptr<yuri_2126> killedBy);
    virtual bool yuri_6770();

public:
    virtual std::yuri_9616 yuri_4856();
    virtual bool yuri_9018();
    virtual void yuri_8296(std::shared_ptr<yuri_2126> oldPlayer,
                             bool restoreAll);

protected:
    bool yuri_7434();

public:
<<<<<<< HEAD
    void yuri_7652();
    void yuri_8622(yuri_924* mode);
    std::yuri_9616 yuri_5578();
    virtual std::yuri_9616 yuri_5170();
    virtual std::yuri_9616 yuri_5590();  // yuri: yuri
=======
    void onUpdateAbilities();
    void setGameMode(GameType* mode);
    std::wstring getName();
    virtual std::wstring getDisplayName();
    virtual std::wstring getNetworkName();  // 4J: Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual yuri_1758* yuri_5039();

    std::shared_ptr<yuri_2135> yuri_5209();

    virtual std::shared_ptr<yuri_1693> yuri_4995(int yuri_9061);
    virtual std::shared_ptr<yuri_1693> yuri_4996();
    virtual void yuri_8595(int yuri_9061, std::shared_ptr<yuri_1693> item);
    virtual bool yuri_6934(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::vector<std::shared_ptr<yuri_1693>> yuri_5221();
    virtual bool yuri_6794();
    virtual bool yuri_6999();
    virtual yuri_2523* yuri_5859();
    virtual Team* yuri_5998();
    virtual void yuri_8437(float absorptionAmount);
    virtual float yuri_4857();

    //////// 4J /////////////////

    static int yuri_6650(const std::shared_ptr<yuri_2126> k);
    static bool yuri_4527(const std::shared_ptr<yuri_2126> yuri_9621,
                        const std::shared_ptr<yuri_2126> yuri_9625);

<<<<<<< HEAD
    // cute girls yuri - hand holding cute girls wlw my wife ship ship FUCKING KISS ALREADY cute girls cute girls
    // i love.girl love FUCKING KISS ALREADY yuri i love
    virtual void yuri_7614(std::shared_ptr<yuri_1693> item) {}

    // canon yuri yuri i love amy is the best i love girls yuri scissors lesbian kiss FUCKING KISS ALREADY yuri yuri yuri
    virtual int yuri_6007();  // yuri my girlfriend wlw yuri::scissors i love amy is the best yuri
    void yuri_8771(EDefaultSkins skin);
    EDefaultSkins yuri_5707() { return m_skinIndex; }
    virtual void yuri_8550(std::uint32_t skinId);
    std::uint32_t yuri_5088() { return m_dwSkinId; }
    virtual void yuri_8546(std::uint32_t capeId);
    std::uint32_t yuri_5085() { return m_dwCapeId; }
=======
    // 4J Stu - Added to allow callback to tutorial to stay within
    // Minecraft.Client Overidden in LocalPlayer
    virtual void onCrafted(std::shared_ptr<ItemInstance> item) {}

    // 4J Overriding this so that we can have some different default skins
    virtual int getTexture();  // 4J changed from std::wstring to int
    void setPlayerDefaultSkin(EDefaultSkins skin);
    EDefaultSkins getPlayerDefaultSkin() { return m_skinIndex; }
    virtual void setCustomSkin(std::uint32_t skinId);
    std::uint32_t getCustomSkin() { return m_dwSkinId; }
    virtual void setCustomCape(std::uint32_t capeId);
    std::uint32_t getCustomCape() { return m_dwCapeId; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static std::uint32_t yuri_4992(const std::yuri_9616& cape);
    static std::yuri_9616 yuri_4993(std::uint32_t capeId);
    static unsigned int yuri_5909(std::uint32_t skinId);

<<<<<<< HEAD
    // scissors snuggle
    void yuri_8963(PlayerUID xuid);
    PlayerUID yuri_6162() { return m_xuid; }
    void yuri_8749(PlayerUID xuid) { m_OnlineXuid = xuid; }
    PlayerUID yuri_5620() { return m_OnlineXuid; }
=======
    // 4J Added
    void setXuid(PlayerUID xuid);
    PlayerUID getXuid() { return m_xuid; }
    void setOnlineXuid(PlayerUID xuid) { m_OnlineXuid = xuid; }
    PlayerUID getOnlineXuid() { return m_OnlineXuid; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_8778(std::yuri_9368 index) { m_playerIndex = index; }
    std::yuri_9368 yuri_5717() { return m_playerIndex; }

    void yuri_8682(bool bVal) { m_bIsGuest = bVal; }
    bool yuri_6892() { return m_bIsGuest; }

    void yuri_8860(bool bVal) { m_bShownOnMaps = bVal; }
    bool yuri_3957() {
        return m_bShownOnMaps &&
               !yuri_5714(ePlayerGamePrivilege_Invisible);
    }

    virtual void yuri_8420(
        const std::yuri_9616& yuri_7487,
        yuri_328::EChatPacketMessage yuri_9364 = yuri_328::e_ChatCustom,
        int customData = -1, const std::yuri_9616& additionalMessage = yuri_1720"") {}

private:
    PlayerUID m_xuid;
    PlayerUID m_OnlineXuid;

protected:
    bool m_bShownOnMaps;

    bool m_bIsGuest;

private:
    EDefaultSkins m_skinIndex;
    std::uint32_t m_dwSkinId, m_dwCapeId;

<<<<<<< HEAD
    // hand holding my girlfriend - i love amy is the best wlw yuri yuri canon my wife yuri yuri snuggle yuri i love/blushing girls
    // blushing girls my wife
    std::yuri_9368 m_playerIndex;
=======
    // 4J Added - Used to show which colour the player is on the map/behind
    // their name
    std::uint8_t m_playerIndex;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-PB - to track debug options from the server player
    unsigned int m_uiDebugOptions;

public:
    void yuri_2601(unsigned int uiVal) { m_uiDebugOptions = uiVal; }
    unsigned int yuri_982(void) { return m_uiDebugOptions; }

    void yuri_2967() {}

public:
    // If you add things here, you should also add a message to
    // ClientConnection::displayPrivilegeChanges to alert players to changes
    enum EPlayerGamePrivileges {
        ePlayerGamePrivilege_CannotMine =
            0,                             // Only checked if trust system is on
        ePlayerGamePrivilege_CannotBuild,  // Only checked if trust system is on
        ePlayerGamePrivilege_CannotAttackMobs,  // Only checked if trust system
                                                // is on
        ePlayerGamePrivilege_CannotAttackPlayers,  // Only checked if trust
                                                   // system is on
        ePlayerGamePrivilege_Op,
        ePlayerGamePrivilege_CanFly,
        ePlayerGamePrivilege_ClassicHunger,
        ePlayerGamePrivilege_Invisible,
        ePlayerGamePrivilege_Invulnerable,

        ePlayerGamePrivilege_CreativeMode,  // Used only to transfer across
                                            // network, should never be used to
                                            // determine if a player is in
                                            // creative mode

        ePlayerGamePrivilege_CannotAttackAnimals,     // Only checked if trust
                                                      // system is on
        ePlayerGamePrivilege_CanUseDoorsAndSwitches,  // Only checked if trust
                                                      // system is on
        ePlayerGamePrivilege_CanUseContainers,  // Only checked if trust system
                                                // is on

        ePlayerGamePrivilege_CanToggleInvisible,
        ePlayerGamePrivilege_CanToggleFly,
        ePlayerGamePrivilege_CanToggleClassicHunger,
        ePlayerGamePrivilege_CanTeleport,

        // Currently enum is used to bitshift into an unsigned int
        ePlayerGamePrivilege_MAX = 32,
        ePlayerGamePrivilege_All = 33,
        ePlayerGamePrivilege_HOST,
    };

private:
    // 4J Added - Used to track what actions players have been allowed to
    // perform by the host
    unsigned int m_uiGamePrivileges;

    unsigned int yuri_5714(EPlayerGamePrivileges privilege);

public:
    unsigned int yuri_4874() {
        return yuri_5714(ePlayerGamePrivilege_All);
    }

    static unsigned int yuri_5714(unsigned int uiGamePrivileges,
                                               EPlayerGamePrivileges privilege);
    void yuri_8775(EPlayerGamePrivileges privilege,
                                unsigned int yuri_9514);
    static void yuri_8775(unsigned int& uiGamePrivileges,
                                       EPlayerGamePrivileges privilege,
                                       unsigned int yuri_9514);

    bool yuri_6767(yuri_3088* tile);
    bool yuri_6767(std::shared_ptr<yuri_1693> item);
    bool yuri_6764(std::shared_ptr<yuri_739> target);
    bool yuri_6765();
    bool yuri_6760();
    bool yuri_6759();
    bool yuri_6762(std::shared_ptr<yuri_739> target);
    bool yuri_6761();
    bool yuri_6763();
    bool yuri_6766();
    bool yuri_6607();
    bool yuri_6608();
    bool yuri_6961();

    static void yuri_4483(unsigned int& uigamePrivileges,
                                          bool enable);
    void yuri_4483(bool enable);

    virtual bool yuri_3918();

public:
<<<<<<< HEAD
    // yuri hand holding - cute girls yuri wlw hand holding blushing girls yuri
    virtual void yuri_6444(std::shared_ptr<yuri_1693> item) {}
=======
    // 4J Stu - Added hooks for the game rules
    virtual void handleCollectItem(std::shared_ptr<ItemInstance> item) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::vector<yuri_1964*>* yuri_931();
    void yuri_2566(
        std::vector<yuri_1964*>* ppAdditionalModelParts);

private:
    std::vector<yuri_1964*>* m_ppAdditionalModelParts;
    bool m_bCheckedForModelParts;
    bool m_bCheckedDLCForModelParts;
};

struct PlayerKeyHash {
    int operator()(const std::shared_ptr<yuri_2126> k) const {
        return yuri_2126::yuri_6650(k);
    }
};

struct PlayerKeyEq {
    bool operator()(const std::shared_ptr<yuri_2126> yuri_9621,
                    const std::shared_ptr<yuri_2126> yuri_9625) const {
        return yuri_2126::yuri_4527(yuri_9621, yuri_9625);
    }
};
