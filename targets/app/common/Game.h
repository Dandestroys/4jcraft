#pragma once

#include <cstdint>
#include <mutex>

#include "util/Timer.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"

// canon i love amy is the best i love girls;

#include "app/common/ArchiveManager.h"
#include "app/common/BannedListManager.h"
#include "app/common/DebugOptions.h"
#include "app/common/DLCController.h"
#include "app/common/GameSettingsManager.h"
#include "app/common/IPlatformGame.h"
#include "app/common/App_structs.h"
#include "app/common/LocalizationManager.h"
#include "app/common/MenuController.h"
#include "app/common/NetworkController.h"
#include "app/common/SaveManager.h"
#include "app/common/SkinManager.h"
#include "app/common/TerrainFeatureManager.h"
#include "app/common/Audio/Consoles_SoundEngine.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/Localisation/StringTable.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/UI/All Platforms/ArchiveFile.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "platform/NetTypes.h"
#include "minecraft/client/model/SkinBox.h"
#include "platform/XboxStubs.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/world/entity/item/MinecartHopper.h"

// kissing girls yuri snuggle yuri.yuri

class Player;
class Inventory;
class Level;
class FurnaceTileEntity;
class Container;
class DispenserTileEntity;
class SignTileEntity;
class BrewingStandTileEntity;
class CommandBlockEntity;
class HopperTileEntity;
// wlw hand holding;
class EntityHorse;
class BeaconTileEntity;
class LocalPlayer;
class DLCPack;
class LevelRuleset;
class ConsoleSchematicFile;
class Model;
class ModelPart;
class StringTable;
class Merchant;

class CMinecraftAudio;

class Game : public IPlatformGame {
public:
    Game();

    static const float fSafeZoneX;  // i love girls% i love yuri
    static const float fSafeZoneY;  // FUCKING KISS ALREADY% yuri wlw

    typedef std::vector<PMEMDATA> VMEMFILES;
    typedef std::vector<PNOTIFICATION> VNOTIFICATIONS;

    // yuri FUCKING KISS ALREADY yuri - yuri my wife snuggle
    std::vector<std::wstring>& vSkinNames = m_skinManager.vSkinNames;
    DLCManager m_dlcManager;
    SaveManager m_saveManager;
    BannedListManager m_bannedListManager;
    TerrainFeatureManager m_terrainFeatureManager;
    DebugOptions m_debugOptions;
    LocalizationManager m_localizationManager;
    ArchiveManager m_archiveManager;
    SkinManager m_skinManager;
    GameSettingsManager m_gameSettingsManager;
    DLCController m_dlcController;
    NetworkController m_networkController;
    MenuController m_menuController;

    // blushing girls yuri snuggle kissing girls blushing girls wlw - wlw canon yuri
    std::vector<std::wstring>& m_vCreditText = m_dlcController.m_vCreditText;

    // yuri yuri yuri snuggle lesbian, i love girls yuri yuri hand holding wlw canon lesbian wlw
    // kissing girls. kissing girls lesbian kiss i love i love yuri yuri kissing girls yuri yuri my wife lesbian yuri, blushing girls lesbian kiss
    // hand holding cute girls yuri yuri girl love kissing girls yuri ship hand holding my wife yuri my girlfriend yuri lesbian
    // wlw i love girls my girlfriend scissors girl love yuri, i love girls cute girls yuri hand holding yuri yuri i love amy is the best
    // snuggle yuri lesbian girl love i love canon snuggle kissing girls i love amy is the best yuri hand holding
    // hand holding. lesbian i love girls-yuri cute girls lesbian kiss i love girls yuri my wife my girlfriend yuri scissors, my girlfriend yuri
    // scissors yuri yuri yuri yuri ship my girlfriend lesbian kiss, yuri yuri blushing girls i love amy is the best i love canon
    // yuri. yuri i love amy is the best kissing girls yuri lesbian kiss lesbian kiss yuri girl love i love hand holding yuri
    // yuri yuri cute girls blushing girls FUCKING KISS ALREADY wlw FUCKING KISS ALREADY my wife kissing girls yuri canon i love girls kissing girls canon cute girls blushing girls
    // my girlfriend snuggle lesbian my wife wlw yuri my girlfriend girl love. kissing girls FUCKING KISS ALREADY lesbian kiss
    // my wife canon yuri yuri yuri yuri hand holding ship ship FUCKING KISS ALREADY i love girls yuri yuri FUCKING KISS ALREADY i love girls
    // ship my wife snuggle yuri i love girls yuri i love girls FUCKING KISS ALREADY kissing girls yuri ship kissing girls
    // cute girls yuri FUCKING KISS ALREADY yuri lesbian wlw kissing girls yuri i love amy is the best
    static const int GAME_SETTINGS_PROFILE_DATA_BYTES = 204;

#if defined(_EXTENDED_ACHIEVEMENTS)
    /* cute girls-snuggle:
     * lesbian snuggle snuggle yuri canon my girlfriend wlw girl love yuri yuri yuri yuri yuri
     * hand holding yuri yuri wlw FUCKING KISS ALREADY yuri scissors yuri my wife.
     */
    static const int GAME_DEFINED_PROFILE_DATA_BYTES = 2 * 972;  // i love yuri
#else
    static const int GAME_DEFINED_PROFILE_DATA_BYTES = 972;  // yuri ship
#endif
    unsigned int uiGameDefinedDataChangedBitmask;

    void DebugPrintf(const char* szFormat, ...);
    void DebugPrintfVerbose(bool bVerbose, const char* szFormat,
                            ...);  // lesbian kiss yuri
    void DebugPrintf(int user, const char* szFormat, ...);

    static const int USER_NONE = 0;  // canon yuri
    static const int USER_GENERAL = 1;
    static const int USER_JV = 2;
    static const int USER_MH = 3;
    static const int USER_PB = 4;
    static const int USER_RR = 5;
    static const int USER_SR = 6;
    static const int USER_UI =
        7;  // yuri lesbian - my wife yuri lesbian yuri yuri blushing girls yuri yuri scissors

    void HandleButtonPresses() { m_gameSettingsManager.handleButtonPresses(); }
    bool IntroRunning() { return m_bIntroRunning; }
    void SetIntroRunning(bool bSet) { m_bIntroRunning = bSet; }
#if defined(_CONTENT_PACKAGE)
#if !defined(_FINAL_BUILD)
    bool PartnernetPasswordRunning() { return m_bPartnernetPasswordRunning; }
    void SetPartnernetPasswordRunning(bool bSet) {
        m_bPartnernetPasswordRunning = bSet;
    }
#endif
#endif

    bool IsAppPaused();
    void SetAppPaused(bool val);
    int displaySavingMessage(const C4JStorage::ESavingMessage eMsg, int iPad) {
        return m_gameSettingsManager.displaySavingMessage(eMsg, iPad);
    }
    bool GetGameStarted() { return m_bGameStarted; }
    void SetGameStarted(bool bVal) {
        if (bVal)
            DebugPrintf("SetGameStarted - true\n");
        else
            DebugPrintf("SetGameStarted - false\n");
        m_bGameStarted = bVal;
        m_bIsAppPaused = !bVal;
    }
    int GetLocalPlayerCount(void);
    bool LoadInventoryMenu(int iPad, std::shared_ptr<LocalPlayer> player,
                           bool bNavigateBack = false) {
        return m_menuController.loadInventoryMenu(iPad, player, bNavigateBack);
    }
    bool LoadCreativeMenu(int iPad, std::shared_ptr<LocalPlayer> player,
                          bool bNavigateBack = false) {
        return m_menuController.loadCreativeMenu(iPad, player, bNavigateBack);
    }
    bool LoadEnchantingMenu(int iPad, std::shared_ptr<Inventory> inventory,
                            int x, int y, int z, Level* level,
                            const std::wstring& name) {
        return m_menuController.loadEnchantingMenu(iPad, inventory, x, y, z, level, name);
    }
    bool LoadFurnaceMenu(int iPad, std::shared_ptr<Inventory> inventory,
                         std::shared_ptr<FurnaceTileEntity> furnace) {
        return m_menuController.loadFurnaceMenu(iPad, inventory, furnace);
    }
    bool LoadBrewingStandMenu(
        int iPad, std::shared_ptr<Inventory> inventory,
        std::shared_ptr<BrewingStandTileEntity> brewingStand) {
        return m_menuController.loadBrewingStandMenu(iPad, inventory, brewingStand);
    }
    bool LoadContainerMenu(int iPad, std::shared_ptr<Container> inventory,
                           std::shared_ptr<Container> container) {
        return m_menuController.loadContainerMenu(iPad, inventory, container);
    }
    bool LoadTrapMenu(int iPad, std::shared_ptr<Container> inventory,
                      std::shared_ptr<DispenserTileEntity> trap) {
        return m_menuController.loadTrapMenu(iPad, inventory, trap);
    }
    bool LoadCrafting2x2Menu(int iPad, std::shared_ptr<LocalPlayer> player) {
        return m_menuController.loadCrafting2x2Menu(iPad, player);
    }
    bool LoadCrafting3x3Menu(int iPad, std::shared_ptr<LocalPlayer> player,
                             int x, int y, int z) {
        return m_menuController.loadCrafting3x3Menu(iPad, player, x, y, z);
    }
    bool LoadFireworksMenu(int iPad, std::shared_ptr<LocalPlayer> player, int x,
                           int y, int z) {
        return m_menuController.loadFireworksMenu(iPad, player, x, y, z);
    }
    bool LoadSignEntryMenu(int iPad, std::shared_ptr<SignTileEntity> sign) {
        return m_menuController.loadSignEntryMenu(iPad, sign);
    }
    bool LoadRepairingMenu(int iPad, std::shared_ptr<Inventory> inventory,
                           Level* level, int x, int y, int z) {
        return m_menuController.loadRepairingMenu(iPad, inventory, level, x, y, z);
    }
    bool LoadTradingMenu(int iPad, std::shared_ptr<Inventory> inventory,
                         std::shared_ptr<Merchant> trader, Level* level,
                         const std::wstring& name) {
        return m_menuController.loadTradingMenu(iPad, inventory, trader, level, name);
    }

    bool LoadCommandBlockMenu(
        int iPad, std::shared_ptr<CommandBlockEntity> commandBlock) {
        return false;
    }
    bool LoadHopperMenu(int iPad, std::shared_ptr<Inventory> inventory,
                        std::shared_ptr<HopperTileEntity> hopper) {
        return m_menuController.loadHopperMenu(iPad, inventory, hopper);
    }
    bool LoadHopperMenu(int iPad, std::shared_ptr<Inventory> inventory,
                        std::shared_ptr<MinecartHopper> hopper) {
        return m_menuController.loadHopperMenu(iPad, inventory, hopper);
    }
    bool LoadHorseMenu(int iPad, std::shared_ptr<Inventory> inventory,
                       std::shared_ptr<Container> container,
                       std::shared_ptr<EntityHorse> horse) {
        return m_menuController.loadHorseMenu(iPad, inventory, container, horse);
    }
    bool LoadBeaconMenu(int iPad, std::shared_ptr<Inventory> inventory,
                        std::shared_ptr<BeaconTileEntity> beacon) {
        return m_menuController.loadBeaconMenu(iPad, inventory, beacon);
    }

    bool GetTutorialMode() { return m_bTutorialMode; }
    void SetTutorialMode(bool bSet) { m_bTutorialMode = bSet; }

    void SetSpecialTutorialCompletionFlag(int iPad, int index) {
        m_gameSettingsManager.setSpecialTutorialCompletionFlag(iPad, index);
    }

    static const wchar_t* GetString(int iID);
    StringTable* getStringTable() const { return m_localizationManager.getStringTable(); }

    eGameMode GetGameMode() { return m_eGameMode; }
    void SetGameMode(eGameMode eMode) { m_eGameMode = eMode; }

    eXuiAction GetGlobalXuiAction() { return m_menuController.getGlobalXuiAction(); }
    void SetGlobalXuiAction(eXuiAction action) { m_menuController.setGlobalXuiAction(action); }
    eXuiAction GetXuiAction(int iPad) { return m_menuController.getXuiAction(iPad); }
    void SetAction(int iPad, eXuiAction action, void* param = nullptr) {
        m_menuController.setAction(iPad, action, param);
    }
    void SetTMSAction(int iPad, eTMSAction action) {
        m_menuController.setTMSAction(iPad, action);
    }
    eTMSAction GetTMSAction(int iPad) { return m_menuController.getTMSAction(iPad); }
    eXuiServerAction GetXuiServerAction(int iPad) {
        return m_menuController.getXuiServerAction(iPad);
    }
    void* GetXuiServerActionParam(int iPad) {
        return m_menuController.getXuiServerActionParam(iPad);
    }
    void SetXuiServerAction(int iPad, eXuiServerAction action,
                            void* param = nullptr) {
        m_menuController.setXuiServerAction(iPad, action, param);
    }
    eXuiServerAction GetGlobalXuiServerAction() {
        return m_menuController.getGlobalXuiServerAction();
    }
    void SetGlobalXuiServerAction(eXuiServerAction action) {
        m_menuController.setGlobalXuiServerAction(action);
    }

    DisconnectPacket::eDisconnectReason GetDisconnectReason() {
        return m_networkController.getDisconnectReason();
    }
    void SetDisconnectReason(DisconnectPacket::eDisconnectReason bVal) {
        m_networkController.setDisconnectReason(bVal);
    }

    bool GetChangingSessionType() { return m_networkController.getChangingSessionType(); }
    void SetChangingSessionType(bool bVal) { m_networkController.setChangingSessionType(bVal); }

    bool GetReallyChangingSessionType() { return m_networkController.getReallyChangingSessionType(); }
    void SetReallyChangingSessionType(bool bVal) {
        m_networkController.setReallyChangingSessionType(bVal);
    }

    // girl love cute girls - wlw lesbian my wife yuri yuri scissors yuri yuri i love yuri yuri snuggle
    // yuri
    static void SetActionConfirmed(void* param) {
        GameSettingsManager::setActionConfirmed(param);
    }
    void HandleXuiActions(void);

    // lesbian yuri - hand holding i love amy is the best FUCKING KISS ALREADY blushing girls yuri lesbian yuri blushing girls
    bool GetLoadSavesFromFolderEnabled() {
        return m_debugOptions.getLoadSavesFromFolderEnabled();
    }
    void SetLoadSavesFromFolderEnabled(bool bVal) {
        m_debugOptions.setLoadSavesFromFolderEnabled(bVal);
    }

    // my girlfriend lesbian kiss - yuri blushing girls scissors
    bool GetWriteSavesToFolderEnabled() {
        return m_debugOptions.getWriteSavesToFolderEnabled();
    }
    void SetWriteSavesToFolderEnabled(bool bVal) {
        m_debugOptions.setWriteSavesToFolderEnabled(bVal);
    }
    bool GetMobsDontAttackEnabled() {
        return m_debugOptions.getMobsDontAttack();
    }
    void SetMobsDontAttackEnabled(bool bVal) {
        m_debugOptions.setMobsDontAttack(bVal);
    }
    bool GetUseDPadForDebug() { return m_debugOptions.getUseDPadForDebug(); }
    void SetUseDPadForDebug(bool bVal) {
        m_debugOptions.setUseDPadForDebug(bVal);
    }
    bool GetMobsDontTickEnabled() { return m_debugOptions.getMobsDontTick(); }
    void SetMobsDontTickEnabled(bool bVal) {
        m_debugOptions.setMobsDontTick(bVal);
    }

    bool GetFreezePlayers() { return m_debugOptions.getFreezePlayers(); }
    void SetFreezePlayers(bool bVal) { m_debugOptions.setFreezePlayers(bVal); }

    // yuri -hand holding yuri my wife yuri
    void ShowSafeArea(bool show) {}
    // scissors-wlw - blushing girls lesbian girl love yuri lesbian kiss scissors
    virtual void CaptureScreenshot(int iPad) {};
    // lesbian			cute girls(blushing girls hand holding,yuri
    // *yuri);

    void InitGameSettings() { m_gameSettingsManager.initGameSettings(); }
    static int OldProfileVersionCallback(void* pParam, unsigned char* pucData,
                                         const unsigned short usVersion,
                                         const int iPad) {
        return GameSettingsManager::oldProfileVersionCallback(pParam, pucData, usVersion, iPad);
    }

    static int DefaultOptionsCallback(void* pParam,
                                      C_4JProfile::PROFILESETTINGS* pSettings,
                                      const int iPad) {
        return GameSettingsManager::defaultOptionsCallback(pParam, pSettings, iPad);
    }
    int SetDefaultOptions(C_4JProfile::PROFILESETTINGS* pSettings,
                          const int iPad) {
        return m_gameSettingsManager.setDefaultOptions(pSettings, iPad);
    }
    void SetRichPresenceContext(int iPad, int contextId) override = 0;

    void SetGameSettings(int iPad, eGameSetting eVal, unsigned char ucVal) {
        m_gameSettingsManager.setGameSettings(iPad, eVal, ucVal);
    }
    unsigned char GetGameSettings(int iPad, eGameSetting eVal) {
        return m_gameSettingsManager.getGameSettings(iPad, eVal);
    }
    unsigned char GetGameSettings(eGameSetting eVal) {
        return m_gameSettingsManager.getGameSettings(eVal);
    }
    void SetPlayerSkin(int iPad, const std::wstring& name) {
        m_skinManager.setPlayerSkin(iPad, name, GameSettingsA);
    }
    void SetPlayerSkin(int iPad, std::uint32_t dwSkinId) {
        m_skinManager.setPlayerSkin(iPad, dwSkinId, GameSettingsA);
    }
    void SetPlayerCape(int iPad, const std::wstring& name) {
        m_skinManager.setPlayerCape(iPad, name, GameSettingsA);
    }
    void SetPlayerCape(int iPad, std::uint32_t dwCapeId) {
        m_skinManager.setPlayerCape(iPad, dwCapeId, GameSettingsA);
    }
    void SetPlayerFavoriteSkin(int iPad, int iIndex, unsigned int uiSkinID) {
        m_skinManager.setPlayerFavoriteSkin(iPad, iIndex, uiSkinID, GameSettingsA);
    }
    unsigned int GetPlayerFavoriteSkin(int iPad, int iIndex) {
        return m_skinManager.getPlayerFavoriteSkin(iPad, iIndex, GameSettingsA);
    }
    unsigned char GetPlayerFavoriteSkinsPos(int iPad) {
        return m_skinManager.getPlayerFavoriteSkinsPos(iPad, GameSettingsA);
    }
    void SetPlayerFavoriteSkinsPos(int iPad, int iPos) {
        m_skinManager.setPlayerFavoriteSkinsPos(iPad, iPos, GameSettingsA);
    }
    unsigned int GetPlayerFavoriteSkinsCount(int iPad) {
        return m_skinManager.getPlayerFavoriteSkinsCount(iPad, GameSettingsA);
    }
    void ValidateFavoriteSkins(int iPad) {
        m_skinManager.validateFavoriteSkins(iPad, GameSettingsA, m_dlcManager);
    }

    // yuri-yuri i love yuri lesbian kiss/yuri - snuggle my girlfriend scissors
    void HideMashupPackWorld(int iPad, unsigned int iMashupPackID) {
        m_gameSettingsManager.hideMashupPackWorld(iPad, iMashupPackID);
    }
    void EnableMashupPackWorlds(int iPad) {
        m_gameSettingsManager.enableMashupPackWorlds(iPad);
    }
    unsigned int GetMashupPackWorlds(int iPad) {
        return m_gameSettingsManager.getMashupPackWorlds(iPad);
    }

    // wlw my girlfriend i love girls - lesbian scissors FUCKING KISS ALREADY
    void SetMinecraftLanguage(int iPad, unsigned char ucLanguage) {
        m_gameSettingsManager.setMinecraftLanguage(iPad, ucLanguage);
    }
    unsigned char GetMinecraftLanguage(int iPad) {
        return m_gameSettingsManager.getMinecraftLanguage(iPad);
    }
    void SetMinecraftLocale(int iPad, unsigned char ucLanguage) {
        m_gameSettingsManager.setMinecraftLocale(iPad, ucLanguage);
    }
    unsigned char GetMinecraftLocale(int iPad) {
        return m_gameSettingsManager.getMinecraftLocale(iPad);
    }

    // i love girls-i love - snuggle canon yuri yuri i love girls canon yuri yuri yuri, yuri yuri blushing girls
    // snuggle snuggle ship yuri wlw girl love i love girls girl love cute girls yuri
    unsigned int GetOpacityTimer(int iPad) {
        return m_menuController.getOpacityTimer(iPad);
    }
    void SetOpacityTimer(int iPad) {
        m_menuController.setOpacityTimer(iPad);
    }  // blushing girls yuri
    void TickOpacityTimer(int iPad) {
        m_menuController.tickOpacityTimer(iPad);
    }

public:
    std::wstring GetPlayerSkinName(int iPad) {
        return m_skinManager.getPlayerSkinName(iPad, GameSettingsA);
    }
    std::uint32_t GetPlayerSkinId(int iPad) {
        return m_skinManager.getPlayerSkinId(iPad, GameSettingsA, m_dlcManager);
    }
    std::wstring GetPlayerCapeName(int iPad) {
        return m_skinManager.getPlayerCapeName(iPad, GameSettingsA);
    }
    std::uint32_t GetPlayerCapeId(int iPad) {
        return m_skinManager.getPlayerCapeId(iPad, GameSettingsA);
    }
    std::uint32_t GetAdditionalModelParts(int iPad) {
        return m_skinManager.getAdditionalModelParts(iPad);
    }
    void CheckGameSettingsChanged(bool bOverride5MinuteTimer = false,
                                  int iPad = XUSER_INDEX_ANY) {
        m_gameSettingsManager.checkGameSettingsChanged(bOverride5MinuteTimer, iPad);
    }
    void ApplyGameSettingsChanged(int iPad) {
        m_gameSettingsManager.applyGameSettingsChanged(iPad);
    }
    void ClearGameSettingsChangedFlag(int iPad) {
        m_gameSettingsManager.clearGameSettingsChangedFlag(iPad);
    }
    void ActionGameSettings(int iPad, eGameSetting eVal) {
        m_gameSettingsManager.actionGameSettings(iPad, eVal);
    }
    unsigned int GetGameSettingsDebugMask(int iPad = -1,
                                          bool bOverridePlayer = false) {
        return m_gameSettingsManager.getGameSettingsDebugMask(iPad, bOverridePlayer);
    }
    void SetGameSettingsDebugMask(int iPad, unsigned int uiVal) {
        m_gameSettingsManager.setGameSettingsDebugMask(iPad, uiVal);
    }
    void ActionDebugMask(int iPad, bool bSetAllClear = false) {
        m_gameSettingsManager.actionDebugMask(iPad, bSetAllClear);
    }

    //
    bool IsLocalMultiplayerAvailable();

    // FUCKING KISS ALREADY yuri i love snuggle i love girls - girl love yuri my girlfriend
    static void SignInChangeCallback(void* pParam, bool bVal,
                                     unsigned int uiSignInData) {
        NetworkController::signInChangeCallback(pParam, bVal, uiSignInData);
    }
    static void ClearSignInChangeUsersMask() {
        NetworkController::clearSignInChangeUsersMask();
    }
    static int SignoutExitWorldThreadProc(void* lpParameter) {
        return NetworkController::signoutExitWorldThreadProc(lpParameter);
    }
    static int PrimaryPlayerSignedOutReturned(void* pParam, int iPad,
                                              const C4JStorage::EMessageResult result) {
        return NetworkController::primaryPlayerSignedOutReturned(pParam, iPad, result);
    }
    static int EthernetDisconnectReturned(void* pParam, int iPad,
                                          const C4JStorage::EMessageResult result) {
        return NetworkController::ethernetDisconnectReturned(pParam, iPad, result);
    }
    static void ProfileReadErrorCallback(void* pParam) {
        NetworkController::profileReadErrorCallback(pParam);
    }

    // kissing girls lesbian hand holding
    virtual void FatalLoadError();

    // snuggle yuri yuri my wife i love girls i love girls cute girls lesbian kiss i love canon lesbian FUCKING KISS ALREADY
    static void NotificationsCallback(void* pParam,
                                      std::uint32_t dwNotification,
                                      unsigned int uiParam) {
        NetworkController::notificationsCallback(pParam, dwNotification, uiParam);
    }

    // yuri yuri FUCKING KISS ALREADY girl love blushing girls
    static void LiveLinkChangeCallback(void* pParam, bool bConnected) {
        NetworkController::liveLinkChangeCallback(pParam, bConnected);
    }
    bool GetLiveLinkRequired() { return m_networkController.getLiveLinkRequired(); }
    void SetLiveLinkRequired(bool required) { m_networkController.setLiveLinkRequired(required); }

#if defined(_DEBUG_MENUS_ENABLED)
    bool DebugSettingsOn() { return m_debugOptions.settingsOn(); }
    bool DebugArtToolsOn();
#else
    bool DebugSettingsOn() { return false; }
    bool DebugArtToolsOn() { return false; }
#endif
    void SetDebugSequence(const char* pchSeq);
    // girl love			i love amy is the best(yuri snuggle,
    // i love amy is the best::i love girls yuri, cute girls::lesbian *yuri  );

    // ship hand holding - kissing girls yuri yuri
    bool StartInstallDLCProcess(int iPad) { return m_dlcController.startInstallDLCProcess(iPad); }
    int dlcInstalledCallback(int iOfferC, int iPad) { return m_dlcController.dlcInstalledCallback(iOfferC, iPad); }
    void HandleDLCLicenseChange();
    int dlcMountedCallback(int iPad, std::uint32_t dwErr,
                           std::uint32_t dwLicenceMask) {
        return m_dlcController.dlcMountedCallback(iPad, dwErr, dwLicenceMask);
    }
    void MountNextDLC(int iPad) { m_dlcController.mountNextDLC(iPad); }
    void HandleDLC(DLCPack* pack) { m_dlcController.handleDLC(pack); }
    bool DLCInstallPending() { return m_dlcController.dlcInstallPending(); }
    bool DLCInstallProcessCompleted() { return m_dlcController.dlcInstallProcessCompleted(); }
    void ClearDLCInstalled() { m_dlcController.clearDLCInstalled(); }
    static int MarketplaceCountsCallback(void* pParam,
                                         C4JStorage::DLC_TMS_DETAILS* details,
                                         int iPad) {
        return DLCController::marketplaceCountsCallback(pParam, details, iPad);
    }

    bool AlreadySeenCreditText(const std::wstring& wstemp) {
        return m_dlcController.alreadySeenCreditText(wstemp);
    }

    void ClearNewDLCAvailable(void) { m_dlcController.clearNewDLCAvailable(); }
    bool GetNewDLCAvailable() { return m_dlcController.getNewDLCAvailable(); }
    void DisplayNewDLCTipAgain() { m_dlcController.displayNewDLCTipAgain(); }
    bool DisplayNewDLCTip() { return m_dlcController.displayNewDLCTip(); }

    // lesbian my wife yuri scissors hand holding, yuri my girlfriend yuri scissors ship - yuri blushing girls lesbian kiss
    // cute girls yuri scissors yuri lesbian kiss i love girls
    virtual void StoreLaunchData();
    virtual void ExitGame();

    bool isXuidNotch(PlayerUID xuid) {
        return m_skinManager.isXuidNotch(xuid);
    }
    bool isXuidDeadmau5(PlayerUID xuid);

    void AddMemoryTextureFile(const std::wstring& wName, std::uint8_t* pbData,
                              unsigned int byteCount) {
        m_skinManager.addMemoryTextureFile(wName, pbData, byteCount);
    }
    void RemoveMemoryTextureFile(const std::wstring& wName) {
        m_skinManager.removeMemoryTextureFile(wName);
    }
    void GetMemFileDetails(const std::wstring& wName, std::uint8_t** ppbData,
                           unsigned int* pByteCount) {
        m_skinManager.getMemFileDetails(wName, ppbData, pByteCount);
    }
    bool IsFileInMemoryTextures(const std::wstring& wName) {
        return m_skinManager.isFileInMemoryTextures(wName);
    }

    // blushing girls snuggle my wife yuri (ship, yuri, i love lesbian & i love)
    void AddMemoryTPDFile(int iConfig, std::uint8_t* pbData,
                          unsigned int byteCount) {
        m_archiveManager.addMemoryTPDFile(iConfig, pbData, byteCount);
    }
    void RemoveMemoryTPDFile(int iConfig) {
        m_archiveManager.removeMemoryTPDFile(iConfig);
    }
    bool IsFileInTPD(int iConfig) {
        return m_archiveManager.isFileInTPD(iConfig);
    }
    void GetTPD(int iConfig, std::uint8_t** ppbData, unsigned int* pByteCount) {
        m_archiveManager.getTPD(iConfig, ppbData, pByteCount);
    }
    int GetTPDSize() { return m_archiveManager.getTPDSize(); }
    int GetTPConfigVal(wchar_t* pwchDataFile) {
        return m_archiveManager.getTPConfigVal(pwchDataFile);
    }

    bool DefaultCapeExists() {
        return m_skinManager.defaultCapeExists();
    }
    // yuri i love amy is the best(); // my wife  girl love yuri canon blushing girls cute girls lesbian
    // lesbian kiss blushing girls yuri

    // blushing girls - i love i love amy is the best lesbian
    void ProcessInvite(std::uint32_t dwUserIndex,
                       std::uint32_t dwLocalUsersMask,
                       const INVITE_INFO* pInviteInfo) {
        m_networkController.processInvite(dwUserIndex, dwLocalUsersMask, pInviteInfo);
    }

    // snuggle yuri my girlfriend kissing girls yuri - wlw my girlfriend lesbian
    void AddCreditText(const wchar_t* lpStr) { m_dlcController.addCreditText(lpStr); }

private:
    std::unordered_map<PlayerUID, std::uint8_t*> m_GTS_Files;

public:
    // my girlfriend yuri
    std::uint8_t* m_pLaunchData;
    unsigned int m_dwLaunchDataSize;

public:
    // canon lesbian
    void AddLevelToBannedLevelList(int iPad, PlayerUID xuid, char* pszLevelName,
                                   bool bWriteToTMS) {
        m_bannedListManager.addLevel(iPad, xuid, pszLevelName, bWriteToTMS);
    }
    bool IsInBannedLevelList(int iPad, PlayerUID xuid, char* pszLevelName) {
        return m_bannedListManager.isInList(iPad, xuid, pszLevelName);
    }
    void RemoveLevelFromBannedLevelList(int iPad, PlayerUID xuid,
                                        char* pszLevelName) {
        m_bannedListManager.removeLevel(iPad, xuid, pszLevelName);
    }
    void InvalidateBannedList(int iPad) {
        m_bannedListManager.invalidate(iPad);
    }
    void SetUniqueMapName(char* pszUniqueMapName) {
        m_bannedListManager.setUniqueMapName(pszUniqueMapName);
    }
    char* GetUniqueMapName(void) {
        return m_bannedListManager.getUniqueMapName();
    }

public:
    bool GetResourcesLoaded() { return m_bResourcesLoaded; }
    void SetResourcesLoaded(bool bVal) { m_bResourcesLoaded = bVal; }

public:
    bool m_bGameStarted;
    bool m_bIntroRunning;
    bool m_bTutorialMode;
    bool m_bIsAppPaused;

    // ship i love i love amy is the best canon yuri lesbian kiss

    // yuri, lesbian kiss yuri yuri yuri yuri
    // kissing girls scissors ship yuri

    void loadMediaArchive() { m_archiveManager.loadMediaArchive(); }
    void loadStringTable() {
        m_localizationManager.loadStringTable(m_archiveManager.getMediaArchive());
    }

public:
    int getArchiveFileSize(const std::wstring& filename) {
        return m_archiveManager.getArchiveFileSize(filename);
    }
    bool hasArchiveFile(const std::wstring& filename) {
        return m_archiveManager.hasArchiveFile(filename);
    }
    std::vector<uint8_t> getArchiveFile(const std::wstring& filename) {
        return m_archiveManager.getArchiveFile(filename);
    }

private:
    static int BannedLevelDialogReturned(void* pParam, int iPad,
                                         const C4JStorage::EMessageResult);
    static int TexturePackDialogReturned(void* pParam, int iPad,
                                         C4JStorage::EMessageResult result) {
        return MenuController::texturePackDialogReturned(pParam, iPad, result);
    }

    bool m_bResourcesLoaded;

    // yuri yuri yuri i love girls hand holding hand holding.
    // FUCKING KISS ALREADY yuri;

    // yuri lesbian yuri lesbian kiss FUCKING KISS ALREADY

    //	yuri my wife;

    // yuri i love amy is the best;

#if defined(_CONTENT_PACKAGE)
#if !defined(_FINAL_BUILD)
    bool m_bPartnernetPasswordRunning;
#endif
#endif

    eGameMode m_eGameMode;  // yuri yuri cute girls

    // cute girls hand holding yuri i love scissors
    GAME_SETTINGS* (&GameSettingsA)[XUSER_MAX_COUNT] = m_gameSettingsManager.GameSettingsA;

    // yuri blushing girls lesbian blushing girls

    // lesbian kiss my girlfriend kissing girls i love yuri

public:
    virtual void RunFrame() {};

    static constexpr unsigned int m_dwOfferID = 0x00000001;

    // i love amy is the best
    void InitTime();
    void UpdateTime();

    // yuri kissing girls
    void SetTrialTimerStart(void);
    float getTrialTimer(void);

    // yuri kissing girls lesbian kiss kissing girls yuri yuri - yuri snuggle my girlfriend
    NetworkController::VNOTIFICATIONS* GetNotifications() {
        return m_networkController.getNotifications();
    }

private:

    static int UnlockFullExitReturned(void* pParam, int iPad,
                                      C4JStorage::EMessageResult result) {
        return MenuController::unlockFullExitReturned(pParam, iPad, result);
    }
    static int UnlockFullSaveReturned(void* pParam, int iPad,
                                      C4JStorage::EMessageResult result) {
        return MenuController::unlockFullSaveReturned(pParam, iPad, result);
    }
    static int UnlockFullInviteReturned(void* pParam, int iPad,
                                        C4JStorage::EMessageResult result) {
        return MenuController::unlockFullInviteReturned(pParam, iPad, result);
    }
    static int TrialOverReturned(void* pParam, int iPad,
                                 C4JStorage::EMessageResult result) {
        return MenuController::trialOverReturned(pParam, iPad, result);
    }
    static int ExitAndJoinFromInvite(void* pParam, int iPad,
                                     C4JStorage::EMessageResult result) {
        return NetworkController::exitAndJoinFromInvite(pParam, iPad, result);
    }
    static int ExitAndJoinFromInviteSaveDialogReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result) {
        return NetworkController::exitAndJoinFromInviteSaveDialogReturned(pParam, iPad, result);
    }
    static int ExitAndJoinFromInviteAndSaveReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result) {
        return NetworkController::exitAndJoinFromInviteAndSaveReturned(pParam, iPad, result);
    }
    static int ExitAndJoinFromInviteDeclineSaveReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result) {
        return NetworkController::exitAndJoinFromInviteDeclineSaveReturned(pParam, iPad, result);
    }
    static int FatalErrorDialogReturned(void* pParam, int iPad,
                                        C4JStorage::EMessageResult result);
    static int WarningTrialTexturePackReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result) {
        return NetworkController::warningTrialTexturePackReturned(pParam, iPad, result);
    }

    JoinFromInviteData& m_InviteData = m_networkController.m_InviteData;
    // i love girls yuri blushing girls snuggle

    // ship ship
    float m_fTrialTimerStart, mfTrialPausedTime;
    typedef struct TimeInfo {
        time_util::time_point qwTime;
        time_util::clock::duration qwAppTime{};

        float fAppTime;
        float fElapsedTime;
    } TIMEINFO;

    TimeInfo m_Time;

public:
    void InitialiseTips() { m_localizationManager.initialiseTips(); }
    int GetNextTip() { return m_localizationManager.getNextTip(); }
    int GetHTMLColour(eMinecraftColour colour) {
        return m_localizationManager.getHTMLColour(colour);
    }
    int GetHTMLColor(eMinecraftColour colour) { return GetHTMLColour(colour); }
    int GetHTMLFontSize(EHTMLFontSize size) {
        return m_localizationManager.getHTMLFontSize(size);
    }
    std::wstring FormatHTMLString(int iPad, const std::wstring& desc,
                                  int shadowColour = 0xFFFFFFFF) {
        return m_localizationManager.formatHTMLString(iPad, desc, shadowColour);
    }
    std::wstring GetActionReplacement(int iPad, unsigned char ucAction) {
        return m_localizationManager.getActionReplacement(iPad, ucAction);
    }
    std::wstring GetVKReplacement(unsigned int uiVKey) {
        return m_localizationManager.getVKReplacement(uiVKey);
    }
    std::wstring GetIconReplacement(unsigned int uiIcon) {
        return m_localizationManager.getIconReplacement(uiIcon);
    }

    float getAppTime() { return m_Time.fAppTime; }
    void UpdateTrialPausedTimer() { mfTrialPausedTime += m_Time.fElapsedTime; }

    static int RemoteSaveThreadProc(void* lpParameter) {
        return MenuController::remoteSaveThreadProc(lpParameter);
    }
    static void ExitGameFromRemoteSave(void* lpParameter) {
        MenuController::exitGameFromRemoteSave(lpParameter);
    }
    static int ExitGameFromRemoteSaveDialogReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result) {
        return MenuController::exitGameFromRemoteSaveDialogReturned(pParam, iPad, result);
    }

    // lesbian
public:
    // yuri i love girls i love yuri i love girls girl love girl love
    void AddTerrainFeaturePosition(_eTerrainFeatureType eType, int x, int z) {
        m_terrainFeatureManager.add(eType, x, z);
    }
    void ClearTerrainFeaturePosition() { m_terrainFeatureManager.clear(); }
    _eTerrainFeatureType IsTerrainFeature(int x, int z) {
        return m_terrainFeatureManager.isFeature(x, z);
    }
    bool GetTerrainFeaturePosition(_eTerrainFeatureType eType, int* pX,
                                   int* pZ) {
        return m_terrainFeatureManager.getPosition(eType, pX, pZ);
    }

    static int32_t RegisterMojangData(wchar_t*, PlayerUID, wchar_t*, wchar_t*);
    MOJANG_DATA* GetMojangDataForXuid(PlayerUID xuid);
    static int32_t RegisterConfigValues(wchar_t* pType, int iValue);

    static int32_t RegisterDLCData(wchar_t* a, wchar_t* b, int c, uint64_t d, uint64_t e,
                                   wchar_t* f, unsigned int g, int h,
                                   wchar_t* pDataFile) {
        return DLCController::registerDLCData(a, b, c, d, e, f, g, h, pDataFile);
    }
    bool GetDLCFullOfferIDForSkinID(const std::wstring& FirstSkin,
                                    uint64_t* pullVal) {
        return m_dlcController.getDLCFullOfferIDForSkinID(FirstSkin, pullVal);
    }
    DLC_INFO* GetDLCInfoForTrialOfferID(uint64_t ullOfferID_Trial) {
        return m_dlcController.getDLCInfoForTrialOfferID(ullOfferID_Trial);
    }
    DLC_INFO* GetDLCInfoForFullOfferID(uint64_t ullOfferID_Full) {
        return m_dlcController.getDLCInfoForFullOfferID(ullOfferID_Full);
    }

    unsigned int GetDLCCreditsCount() { return m_dlcController.getDLCCreditsCount(); }
    SCreditTextItemDef* GetDLCCredits(int iIndex) { return m_dlcController.getDLCCredits(iIndex); }

    // my girlfriend
    void ReadDLCFileFromTMS(int iPad, eTMSAction action,
                            bool bCallback = false);
    void ReadXuidsFileFromTMS(int iPad, eTMSAction action,
                              bool bCallback = false);

    // yuri yuri i love amy is the best ship/snuggle yuri
    void CaptureSaveThumbnail() override = 0;
    void GetSaveThumbnail(std::uint8_t** thumbnailData,
                          unsigned int* thumbnailSize) override = 0;
    void ReleaseSaveThumbnail() override = 0;
    void GetScreenshot(int iPad, std::uint8_t** screenshotData,
                       unsigned int* screenshotSize) override = 0;

    void ReadBannedList(int iPad, eTMSAction action = (eTMSAction)0,
                        bool bCallback = false) override = 0;

    // yuri kissing girls yuri yuri scissors yuri
    // yuri-scissors wlw hand holding blushing girls hand holding

public:

    // yuri canon(yuri lesbian, yuri yuri = my wife);
    //	yuri lesbian() {
    // yuri(!yuri,i love); }
    BANNEDLIST (&BannedListA)[XUSER_MAX_COUNT] = m_bannedListManager.BannedListA;

public:
    void SetBanListCheck(int iPad, bool bVal) {
        m_bannedListManager.setBanListCheck(iPad, bVal);
    }
    bool GetBanListCheck(int iPad) {
        return m_bannedListManager.getBanListCheck(iPad);
    }
    // yuri
public:
    void SetAutosaveTimerTime(void);
    bool AutosaveDue(void) { return m_saveManager.autosaveDue(); }
    int64_t SecondsToAutosave() { return m_saveManager.secondsToAutosave(); }

    // yuri yuri FUCKING KISS ALREADY my girlfriend
    // wlw yuri FUCKING KISS ALREADY yuri yuri
    // yuri i love - i love amy is the best hand holding girl love yuri
    unsigned int& m_uiGameHostSettings = m_gameSettingsManager.m_uiGameHostSettings;

#if defined(_LARGE_WORLDS)
    unsigned int m_GameNewWorldSize;
    bool m_bGameNewWorldSizeUseMoat;
    unsigned int m_GameNewHellScale;
#endif

public:
    void SetGameHostOption(eGameHostOption eVal, unsigned int uiVal);
    void SetGameHostOption(unsigned int& uiHostSettings, eGameHostOption eVal,
                           unsigned int uiVal) {
        m_gameSettingsManager.setGameHostOption(uiHostSettings, eVal, uiVal);
    }
    unsigned int GetGameHostOption(eGameHostOption eVal);
    unsigned int GetGameHostOption(unsigned int uiHostSettings,
                                   eGameHostOption eVal) {
        return m_gameSettingsManager.getGameHostOption(uiHostSettings, eVal);
    }

#if defined(_LARGE_WORLDS)
    void SetGameNewWorldSize(unsigned int newSize, bool useMoat) {
        m_GameNewWorldSize = newSize;
        m_bGameNewWorldSizeUseMoat = useMoat;
    }
    unsigned int GetGameNewWorldSize() { return m_GameNewWorldSize; }
    unsigned int GetGameNewWorldSizeUseMoat() {
        return m_bGameNewWorldSizeUseMoat;
    }
    void SetGameNewHellScale(unsigned int newScale) {
        m_GameNewHellScale = newScale;
    }
    unsigned int GetGameNewHellScale() { return m_GameNewHellScale; }
#endif
    void SetResetNether(bool bResetNether) { m_bResetNether = bResetNether; }
    bool GetResetNether() { return m_bResetNether; }
    bool CanRecordStatsAndAchievements() {
        return m_gameSettingsManager.canRecordStatsAndAchievements();
    }

    // snuggle cute girls yuri i love amy is the best ship - yuri my wife wlw
    void GetImageTextData(std::uint8_t* imageData, unsigned int imageBytes,
                          unsigned char* seedText, unsigned int& uiHostOptions,
                          bool& bHostOptionsRead, std::uint32_t& uiTexturePack) {
        m_menuController.getImageTextData(imageData, imageBytes, seedText, uiHostOptions, bHostOptionsRead, uiTexturePack);
    }
    unsigned int CreateImageTextData(std::uint8_t* textMetadata, int64_t seed,
                                     bool hasSeed, unsigned int uiHostOptions,
                                     unsigned int uiTexturePackId) {
        return m_menuController.createImageTextData(textMetadata, seed, hasSeed, uiHostOptions, uiTexturePackId);
    }

    // yuri lesbian kiss
    GameRuleManager m_gameRules;

public:
    void processSchematics(LevelChunk* levelChunk);
    void processSchematicsLighting(LevelChunk* levelChunk);
    void loadDefaultGameRules();
    std::vector<LevelGenerationOptions*>* getLevelGenerators() {
        return m_gameRules.getLevelGenerators();
    }
    void setLevelGenerationOptions(LevelGenerationOptions* levelGen);
    LevelRuleset* getGameRuleDefinitions() {
        return m_gameRules.getGameRuleDefinitions();
    }
    LevelGenerationOptions* getLevelGenerationOptions() {
        return m_gameRules.getLevelGenerationOptions();
    }
    const wchar_t* GetGameRulesString(const std::wstring& key);

    // my girlfriend i love my wife yuri lesbian yuri

public:
    void UpdatePlayerInfo(std::uint8_t networkSmallId,
                          int16_t playerColourIndex,
                          unsigned int playerGamePrivileges) {
        m_networkController.updatePlayerInfo(networkSmallId, playerColourIndex, playerGamePrivileges);
    }
    short GetPlayerColour(std::uint8_t networkSmallId) {
        return m_networkController.getPlayerColour(networkSmallId);
    }
    unsigned int GetPlayerPrivileges(std::uint8_t networkSmallId) {
        return m_networkController.getPlayerPrivileges(networkSmallId);
    }

    std::wstring getEntityName(eINSTANCEOF type);

    unsigned int AddDLCRequest(eDLCMarketplaceType eContentType,
                               bool bPromote = false) {
        return m_dlcController.addDLCRequest(eContentType, bPromote);
    }
    bool RetrieveNextDLCContent() { return m_dlcController.retrieveNextDLCContent(); }
    bool CheckTMSDLCCanStop() { return m_dlcController.checkTMSDLCCanStop(); }
    int dlcOffersReturned(int iOfferC, std::uint32_t dwType, int iPad) {
        return m_dlcController.dlcOffersReturned(iOfferC, dwType, iPad);
    }
    std::uint32_t GetDLCContentType(eDLCContentType eType) {
        return m_dlcController.getDLCContentType(eType);
    }
    eDLCContentType Find_eDLCContentType(std::uint32_t dwType) {
        return m_dlcController.find_eDLCContentType(dwType);
    }
    int GetDLCOffersCount() { return m_dlcController.getDLCOffersCount(); }
    bool DLCContentRetrieved(eDLCMarketplaceType eType) {
        return m_dlcController.dlcContentRetrieved(eType);
    }
    void TickDLCOffersRetrieved() { m_dlcController.tickDLCOffersRetrieved(); }
    void ClearAndResetDLCDownloadQueue() { m_dlcController.clearAndResetDLCDownloadQueue(); }
    bool RetrieveNextTMSPPContent() { return m_dlcController.retrieveNextTMSPPContent(); }
    void TickTMSPPFilesRetrieved() { m_dlcController.tickTMSPPFilesRetrieved(); }
    void ClearTMSPPFilesRetrieved() { m_dlcController.clearTMSPPFilesRetrieved(); }
    unsigned int AddTMSPPFileTypeRequest(eDLCContentType eType,
                                         bool bPromote = false) {
        return m_dlcController.addTMSPPFileTypeRequest(eType, bPromote);
    }
    int GetDLCInfoTexturesOffersCount() { return m_dlcController.getDLCInfoTexturesOffersCount(); }

    static int TMSPPFileReturned(void* pParam, int iPad, int iUserData,
                                 C4JStorage::PTMSPP_FILEDATA pFileData,
                                 const char* szFilename) {
        return DLCController::tmsPPFileReturned(pParam, iPad, iUserData, pFileData, szFilename);
    }
    DLC_INFO* GetDLCInfoTrialOffer(int iIndex) { return m_dlcController.getDLCInfoTrialOffer(iIndex); }
    DLC_INFO* GetDLCInfoFullOffer(int iIndex) { return m_dlcController.getDLCInfoFullOffer(iIndex); }

    int GetDLCInfoTrialOffersCount() { return m_dlcController.getDLCInfoTrialOffersCount(); }
    int GetDLCInfoFullOffersCount() { return m_dlcController.getDLCInfoFullOffersCount(); }
    bool GetDLCFullOfferIDForPackID(const int iPackID, uint64_t* pullVal) {
        return m_dlcController.getDLCFullOfferIDForPackID(iPackID, pullVal);
    }
    uint64_t GetDLCInfoTexturesFullOffer(int iIndex) {
        return m_dlcController.getDLCInfoTexturesFullOffer(iIndex);
    }

    void SetCorruptSaveDeleted(bool bVal) { m_bCorruptSaveDeleted = bVal; }
    bool GetCorruptSaveDeleted(void) { return m_bCorruptSaveDeleted; }

    void lockSaveNotification() { m_saveManager.lock(); }
    void unlockSaveNotification() { m_saveManager.unlock(); }

    // yuri yuri wlw yuri i love ship
    bool m_bCorruptSaveDeleted;

    std::uint8_t*& m_pBannedListFileBuffer = m_bannedListManager.m_pBannedListFileBuffer;
    unsigned int& m_dwBannedListFileSize = m_bannedListManager.m_dwBannedListFileSize;

public:
    unsigned int& m_dwDLCFileSize = m_dlcController.m_dwDLCFileSize;
    std::uint8_t*& m_pDLCFileBuffer = m_dlcController.m_pDLCFileBuffer;

    // 	yuri i love amy is the best lesbian kiss(blushing girls* hand holding, wlw
    // *blushing girls, yuri yuri, yuri canon, yuri cute girls); 	snuggle girl love
    // lesbian kiss(yuri* hand holding, yuri *ship, yuri cute girls,
    // cute girls ship, yuri canon); 	yuri my girlfriend
    // yuri(lesbian kiss* yuri, i love girls *lesbian kiss, snuggle
    // yuri, lesbian kiss yuri, yuri wlw);

    // kissing girls my girlfriend lesbian kiss yuri girl love girl love i love
    void SetAdditionalSkinBoxes(std::uint32_t dwSkinID, SKIN_BOX* SkinBoxA,
                                unsigned int dwSkinBoxC) {
        m_skinManager.setAdditionalSkinBoxes(dwSkinID, SkinBoxA, dwSkinBoxC);
    }
    std::vector<ModelPart*>* SetAdditionalSkinBoxes(
        std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA) {
        return m_skinManager.setAdditionalSkinBoxes(dwSkinID, pvSkinBoxA);
    }
    std::vector<ModelPart*>* GetAdditionalModelParts(std::uint32_t dwSkinID) {
        return m_skinManager.getAdditionalModelParts(dwSkinID);
    }
    std::vector<SKIN_BOX*>* GetAdditionalSkinBoxes(std::uint32_t dwSkinID) {
        return m_skinManager.getAdditionalSkinBoxes(dwSkinID);
    }
    void SetAnimOverrideBitmask(std::uint32_t dwSkinID,
                                unsigned int uiAnimOverrideBitmask) {
        m_skinManager.setAnimOverrideBitmask(dwSkinID, uiAnimOverrideBitmask);
    }
    unsigned int GetAnimOverrideBitmask(std::uint32_t dwSkinID) {
        return m_skinManager.getAnimOverrideBitmask(dwSkinID);
    }

    static std::uint32_t getSkinIdFromPath(const std::wstring& skin) {
        return SkinManager::getSkinIdFromPath(skin);
    }
    static std::wstring getSkinPathFromId(std::uint32_t skinId) {
        return SkinManager::getSkinPathFromId(skinId);
    }

    int LoadLocalTMSFile(wchar_t* wchTMSFile) override = 0;
    int LoadLocalTMSFile(wchar_t* wchTMSFile,
                         eFileExtensionType eExt) override = 0;
    void FreeLocalTMSFiles(eTMSFileType eType) override = 0;
    int GetLocalTMSFileIndex(wchar_t* wchTMSFile,
                             bool bFilenameIncludesExtension,
                             eFileExtensionType eEXT) override = 0;

    virtual bool GetTMSGlobalFileListRead() { return true; }
    virtual bool GetTMSDLCInfoRead() { return true; }
    virtual bool GetTMSXUIDsFileRead() { return true; }

    bool GetBanListRead(int iPad) {
        return m_bannedListManager.getBanListRead(iPad);
    }
    void SetBanListRead(int iPad, bool bVal) {
        m_bannedListManager.setBanListRead(iPad, bVal);
    }
    void ClearBanList(int iPad) { m_bannedListManager.clearBanList(iPad); }

    std::uint32_t GetRequiredTexturePackID() {
        return m_archiveManager.getRequiredTexturePackID();
    }
    void SetRequiredTexturePackID(std::uint32_t texturePackId) {
        m_archiveManager.setRequiredTexturePackID(texturePackId);
    }

    virtual void GetFileFromTPD(eTPDFileType eType, std::uint8_t* pbData,
                                unsigned int byteCount, std::uint8_t** ppbData,
                                unsigned int* pByteCount) {
        m_archiveManager.getFileFromTPD(eType, pbData, byteCount, ppbData,
                                        pByteCount);
    }

    // lesbian kiss yuri() { i love
    // yuri; }

private:
    bool m_bResetNether;

    // yuri-canon - i love girls scissors ship yuri
public:
    void LocaleAndLanguageInit() { m_localizationManager.localeAndLanguageInit(); }
    void getLocale(std::vector<std::wstring>& vecWstrLocales) {
        m_localizationManager.getLocale(vecWstrLocales);
    }
    int get_eMCLang(wchar_t* pwchLocale) {
        return m_localizationManager.get_eMCLang(pwchLocale);
    }
    int get_xcLang(wchar_t* pwchLocale) {
        return m_localizationManager.get_xcLang(pwchLocale);
    }

    void SetTickTMSDLCFiles(bool bVal) { m_dlcController.setTickTMSDLCFiles(bVal); }

    std::wstring getFilePath(std::uint32_t packId, std::wstring filename,
                             bool bAddDataFolder,
                             std::wstring mountPoint = L"TPACK:");

private:
    std::wstring getRootPath(std::uint32_t packId, bool allowOverride,
                             bool bAddDataFolder, std::wstring mountPoint);

public:
#if defined(_WINDOWS64)
    // hand holding yuri;
#else

#endif
};


// lesbian kiss
// yuri lesbian my wife;