#pragma once

#include <cstdint>
#include <mutex>

#include "util/Timer.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"

// using namespace std;

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

// JoinFromInviteData moved to NetworkController.h

<<<<<<< HEAD
class yuri_2126;
class yuri_1626;
class yuri_1758;
class yuri_888;
class yuri_436;
class yuri_626;
class yuri_2817;
class yuri_230;
class yuri_395;
class yuri_1285;
// wlw hand holding;
class yuri_743;
class yuri_180;
class yuri_1829;
class yuri_533;
class yuri_1768;
class yuri_433;
class yuri_1962;
class yuri_1964;
class yuri_2974;
class yuri_1913;
=======
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
// class MinecartHopper;
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
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class CMinecraftAudio;

class yuri_910 : public yuri_1320 {
public:
    yuri_910();

    static const float fSafeZoneX;  // 5% of 1280
    static const float fSafeZoneY;  // 5% of 720

    typedef std::vector<PMEMDATA> VMEMFILES;
    typedef std::vector<PNOTIFICATION> VNOTIFICATIONS;

<<<<<<< HEAD
    // yuri FUCKING KISS ALREADY yuri - yuri my wife snuggle
    std::vector<std::yuri_9616>& vSkinNames = m_skinManager.vSkinNames;
    yuri_531 m_dlcManager;
    yuri_2502 m_saveManager;
    yuri_160 m_bannedListManager;
=======
    // storing skin files - delegated to SkinManager
    std::vector<std::wstring>& vSkinNames = m_skinManager.vSkinNames;
    DLCManager m_dlcManager;
    SaveManager m_saveManager;
    BannedListManager m_bannedListManager;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    TerrainFeatureManager m_terrainFeatureManager;
    yuri_561 m_debugOptions;
    yuri_1832 m_localizationManager;
    yuri_125 m_archiveManager;
    yuri_2834 m_skinManager;
    yuri_923 m_gameSettingsManager;
    yuri_523 m_dlcController;
    yuri_2022 m_networkController;
    yuri_1912 m_menuController;

<<<<<<< HEAD
    // blushing girls yuri snuggle kissing girls blushing girls wlw - wlw canon yuri
    std::vector<std::yuri_9616>& m_vCreditText = m_dlcController.m_vCreditText;
=======
    // storing credits text from the DLC - delegated to DLCController
    std::vector<std::wstring>& m_vCreditText = m_dlcController.m_vCreditText;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // In builds prior to TU5, the size of the GAME_SETTINGS struct was 204
    // bytes. We added a few new values to the internal struct in TU5, and even
    // though we changed the size of the ucUnused array to be decreased by the
    // size of the values we added, the packing of the struct has introduced
    // some extra padding that resulted in the GAME_SETTINGS struct being 208
    // bytes. The knock-on effect from this was that all the stats, which come
    // after the game settings in the profile data, we being read offset by 4
    // bytes. We need to ensure that the GAME_SETTINGS struct does not grow
    // larger than 204 bytes or if we need it to then we need to rebuild the
    // profile data completely and increase the profile version. There should be
    // enough free space to grow larger for a few more updates as long as we
    // take into account the padding issues and check that settings are still
    // stored at the same positions when we read them
    static const int GAME_SETTINGS_PROFILE_DATA_BYTES = 204;

<<<<<<< HEAD
#if yuri_4330(_EXTENDED_ACHIEVEMENTS)
    /* cute girls-snuggle:
     * lesbian snuggle snuggle yuri canon my girlfriend wlw girl love yuri yuri yuri yuri yuri
     * hand holding yuri yuri wlw FUCKING KISS ALREADY yuri scissors yuri my wife.
=======
#if defined(_EXTENDED_ACHIEVEMENTS)
    /* 4J-JEV:
     * We need more space in the profile data because of the new achievements
     * and statistics necessary for the new expanded achievement set.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
     */
    static const int GAME_DEFINED_PROFILE_DATA_BYTES = 2 * 972;  // per user
#else
    static const int GAME_DEFINED_PROFILE_DATA_BYTES = 972;  // per user
#endif
    unsigned int uiGameDefinedDataChangedBitmask;

<<<<<<< HEAD
    void yuri_563(const char* szFormat, ...);
    void yuri_564(bool bVerbose, const char* szFormat,
                            ...);  // lesbian kiss yuri
    void yuri_563(int user, const char* szFormat, ...);
=======
    void DebugPrintf(const char* szFormat, ...);
    void DebugPrintfVerbose(bool bVerbose, const char* szFormat,
                            ...);  // Conditional printf
    void DebugPrintf(int user, const char* szFormat, ...);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static const int USER_NONE = 0;  // disables printf
    static const int USER_GENERAL = 1;
    static const int USER_JV = 2;
    static const int USER_MH = 3;
    static const int USER_PB = 4;
    static const int USER_RR = 5;
    static const int USER_SR = 6;
    static const int USER_UI =
        7;  // 4J Stu - This also makes it appear on the UI console

    void yuri_1238() { m_gameSettingsManager.yuri_6430(); }
    bool yuri_1624() { return m_bIntroRunning; }
    void yuri_2650(bool bSet) { m_bIntroRunning = bSet; }
#if yuri_4330(_CONTENT_PACKAGE)
#if !yuri_4330(_FINAL_BUILD)
    bool yuri_2092() { return m_bPartnernetPasswordRunning; }
    void yuri_2685(bool bSet) {
        m_bPartnernetPasswordRunning = bSet;
    }
#endif
#endif

    bool yuri_1631();
    void yuri_2571(bool val);
    int yuri_4380(const yuri_256::ESavingMessage eMsg, int iPad) {
        return m_gameSettingsManager.yuri_4380(eMsg, iPad);
    }
    bool yuri_1016() { return m_bGameStarted; }
    void yuri_2636(bool bVal) {
        if (bVal)
            yuri_563("SetGameStarted - true\n");
        else
            yuri_563("SetGameStarted - false\n");
        m_bGameStarted = bVal;
        m_bIsAppPaused = !bVal;
    }
    int yuri_1065(void);
    bool yuri_1812(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                           bool bNavigateBack = false) {
        return m_menuController.yuri_7255(iPad, yuri_7839, bNavigateBack);
    }
    bool yuri_1803(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                          bool bNavigateBack = false) {
        return m_menuController.yuri_7235(iPad, yuri_7839, bNavigateBack);
    }
    bool yuri_1806(int iPad, std::shared_ptr<yuri_1626> inventory,
                            int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                            const std::yuri_9616& yuri_7540) {
        return m_menuController.yuri_7244(iPad, inventory, yuri_9621, yuri_9625, yuri_9630, yuri_7194, yuri_7540);
    }
    bool yuri_1808(int iPad, std::shared_ptr<yuri_1626> inventory,
                         std::shared_ptr<yuri_888> furnace) {
        return m_menuController.yuri_7247(iPad, inventory, furnace);
    }
    bool yuri_1798(
        int iPad, std::shared_ptr<yuri_1626> inventory,
        std::shared_ptr<yuri_230> brewingStand) {
        return m_menuController.yuri_7227(iPad, inventory, brewingStand);
    }
    bool yuri_1800(int iPad, std::shared_ptr<yuri_436> inventory,
                           std::shared_ptr<yuri_436> yuri_4145) {
        return m_menuController.yuri_7231(iPad, inventory, yuri_4145);
    }
    bool yuri_1826(int iPad, std::shared_ptr<yuri_436> inventory,
                      std::shared_ptr<yuri_626> trap) {
        return m_menuController.yuri_7280(iPad, inventory, trap);
    }
    bool yuri_1801(int iPad, std::shared_ptr<yuri_1829> yuri_7839) {
        return m_menuController.yuri_7233(iPad, yuri_7839);
    }
    bool yuri_1802(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                             int yuri_9621, int yuri_9625, int yuri_9630) {
        return m_menuController.yuri_7234(iPad, yuri_7839, yuri_9621, yuri_9625, yuri_9630);
    }
    bool yuri_1807(int iPad, std::shared_ptr<yuri_1829> yuri_7839, int yuri_9621,
                           int yuri_9625, int yuri_9630) {
        return m_menuController.yuri_7246(iPad, yuri_7839, yuri_9621, yuri_9625, yuri_9630);
    }
    bool yuri_1823(int iPad, std::shared_ptr<yuri_2817> sign) {
        return m_menuController.yuri_7268(iPad, sign);
    }
    bool yuri_1816(int iPad, std::shared_ptr<yuri_1626> inventory,
                           yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
        return m_menuController.yuri_7263(iPad, inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
    bool yuri_1825(int iPad, std::shared_ptr<yuri_1626> inventory,
                         std::shared_ptr<yuri_1913> trader, yuri_1758* yuri_7194,
                         const std::yuri_9616& yuri_7540) {
        return m_menuController.yuri_7279(iPad, inventory, trader, yuri_7194, yuri_7540);
    }

    bool yuri_1799(
        int iPad, std::shared_ptr<yuri_395> commandBlock) {
        return false;
    }
    bool yuri_1809(int iPad, std::shared_ptr<yuri_1626> inventory,
                        std::shared_ptr<yuri_1285> hopper) {
        return m_menuController.yuri_7250(iPad, inventory, hopper);
    }
    bool yuri_1809(int iPad, std::shared_ptr<yuri_1626> inventory,
                        std::shared_ptr<yuri_1936> hopper) {
        return m_menuController.yuri_7250(iPad, inventory, hopper);
    }
    bool yuri_1810(int iPad, std::shared_ptr<yuri_1626> inventory,
                       std::shared_ptr<yuri_436> yuri_4145,
                       std::shared_ptr<yuri_743> horse) {
        return m_menuController.yuri_7251(iPad, inventory, yuri_4145, horse);
    }
    bool yuri_1797(int iPad, std::shared_ptr<yuri_1626> inventory,
                        std::shared_ptr<yuri_180> beacon) {
        return m_menuController.yuri_7226(iPad, inventory, beacon);
    }

    bool yuri_1187() { return m_bTutorialMode; }
    void yuri_2755(bool bSet) { m_bTutorialMode = bSet; }

    void yuri_2729(int iPad, int index) {
        m_gameSettingsManager.yuri_8878(iPad, index);
    }

    static const wchar_t* yuri_1168(int iID);
    yuri_2974* yuri_5970() const { return m_localizationManager.yuri_5970(); }

    eGameMode yuri_1008() { return m_eGameMode; }
    void yuri_2631(eGameMode eMode) { m_eGameMode = eMode; }

    eXuiAction yuri_1019() { return m_menuController.yuri_5319(); }
    void yuri_2637(eXuiAction action) { m_menuController.yuri_8635(action); }
    eXuiAction yuri_1202(int iPad) { return m_menuController.yuri_6157(iPad); }
    void yuri_2563(int iPad, eXuiAction action, void* param = nullptr) {
        m_menuController.yuri_8438(iPad, action, param);
    }
    void yuri_2734(int iPad, eTMSAction action) {
        m_menuController.yuri_8897(iPad, action);
    }
    eTMSAction yuri_1173(int iPad) { return m_menuController.yuri_5986(iPad); }
    eXuiServerAction yuri_1203(int iPad) {
        return m_menuController.yuri_6160(iPad);
    }
    void* yuri_1204(int iPad) {
        return m_menuController.yuri_6161(iPad);
    }
    void yuri_2767(int iPad, eXuiServerAction action,
                            void* param = nullptr) {
        m_menuController.yuri_8962(iPad, action, param);
    }
    eXuiServerAction yuri_1020() {
        return m_menuController.yuri_5320();
    }
    void yuri_2638(eXuiServerAction action) {
        m_menuController.yuri_8636(action);
    }

    yuri_621::eDisconnectReason yuri_987() {
        return m_networkController.yuri_5165();
    }
    void yuri_2607(yuri_621::eDisconnectReason bVal) {
        m_networkController.yuri_8573(bVal);
    }

    bool yuri_946() { return m_networkController.yuri_5001(); }
    void yuri_2582(bool bVal) { m_networkController.yuri_8511(bVal); }

    bool yuri_1132() { return m_networkController.yuri_5786(); }
    void yuri_2700(bool bVal) {
        m_networkController.yuri_8804(bVal);
    }

<<<<<<< HEAD
    // girl love cute girls - wlw lesbian my wife yuri yuri scissors yuri yuri i love yuri yuri snuggle
    // yuri
    static void yuri_2564(void* param) {
        yuri_923::yuri_8439(param);
=======
    // 4J Stu - Added so that we can call this when a confirmation box is
    // selected
    static void SetActionConfirmed(void* param) {
        GameSettingsManager::setActionConfirmed(param);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    void yuri_1251(void);

<<<<<<< HEAD
    // lesbian yuri - hand holding i love amy is the best FUCKING KISS ALREADY blushing girls yuri lesbian yuri blushing girls
    bool yuri_1063() {
        return m_debugOptions.yuri_5490();
=======
    // 4J Stu - Functions used for Minecon and other promo work
    bool GetLoadSavesFromFolderEnabled() {
        return m_debugOptions.getLoadSavesFromFolderEnabled();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    void yuri_2667(bool bVal) {
        m_debugOptions.yuri_8711(bVal);
    }

<<<<<<< HEAD
    // my girlfriend lesbian kiss - yuri blushing girls scissors
    bool yuri_1199() {
        return m_debugOptions.yuri_6141();
=======
    // 4J Stu - Useful for debugging
    bool GetWriteSavesToFolderEnabled() {
        return m_debugOptions.getWriteSavesToFolderEnabled();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    void yuri_2765(bool bVal) {
        m_debugOptions.yuri_8957(bVal);
    }
    bool yuri_1079() {
        return m_debugOptions.yuri_5558();
    }
    void yuri_2674(bool bVal) {
        m_debugOptions.yuri_8731(bVal);
    }
    bool yuri_1191() { return m_debugOptions.yuri_6088(); }
    void yuri_2758(bool bVal) {
        m_debugOptions.yuri_8940(bVal);
    }
    bool yuri_1080() { return m_debugOptions.yuri_5559(); }
    void yuri_2675(bool bVal) {
        m_debugOptions.yuri_8732(bVal);
    }

    bool yuri_1003() { return m_debugOptions.yuri_5286(); }
    void yuri_2627(bool bVal) { m_debugOptions.yuri_8619(bVal); }

<<<<<<< HEAD
    // yuri -hand holding yuri my wife yuri
    void yuri_2801(bool show) {}
    // scissors-wlw - blushing girls lesbian girl love yuri lesbian kiss scissors
    virtual void yuri_309(int iPad) {};
    // lesbian			cute girls(blushing girls hand holding,yuri
    // *yuri);
=======
    // debug -0 show safe area
    void ShowSafeArea(bool show) {}
    // 4J-PB - to capture the social post screenshot
    virtual void CaptureScreenshot(int iPad) {};
    // void			GetPreviewImage(int iPad,XSOCIAL_PREVIEWIMAGE
    // *preview);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_1600() { m_gameSettingsManager.yuri_6709(); }
    static int yuri_2051(void* pParam, unsigned char* pucData,
                                         const unsigned short usVersion,
                                         const int iPad) {
        return yuri_923::yuri_7610(pParam, pucData, usVersion, iPad);
    }

    static int yuri_581(void* pParam,
                                      C_4JProfile::PROFILESETTINGS* pSettings,
                                      const int iPad) {
        return yuri_923::yuri_4325(pParam, pSettings, iPad);
    }
    int yuri_2604(C_4JProfile::PROFILESETTINGS* pSettings,
                          const int iPad) {
        return m_gameSettingsManager.yuri_8559(pSettings, iPad);
    }
    void yuri_2705(int iPad, int contextId) override = 0;

    void yuri_2634(int iPad, eGameSetting eVal, unsigned char ucVal) {
        m_gameSettingsManager.yuri_8625(iPad, eVal, ucVal);
    }
    unsigned char yuri_1014(int iPad, eGameSetting eVal) {
        return m_gameSettingsManager.yuri_5303(iPad, eVal);
    }
    unsigned char yuri_1014(eGameSetting eVal) {
        return m_gameSettingsManager.yuri_5303(eVal);
    }
    void yuri_2691(int iPad, const std::yuri_9616& yuri_7540) {
        m_skinManager.yuri_8780(iPad, yuri_7540, GameSettingsA);
    }
    void yuri_2691(int iPad, std::uint32_t dwSkinId) {
        m_skinManager.yuri_8780(iPad, dwSkinId, GameSettingsA);
    }
    void yuri_2687(int iPad, const std::yuri_9616& yuri_7540) {
        m_skinManager.yuri_8769(iPad, yuri_7540, GameSettingsA);
    }
    void yuri_2687(int iPad, std::uint32_t dwCapeId) {
        m_skinManager.yuri_8769(iPad, dwCapeId, GameSettingsA);
    }
    void yuri_2688(int iPad, int iIndex, unsigned int uiSkinID) {
        m_skinManager.yuri_8772(iPad, iIndex, uiSkinID, GameSettingsA);
    }
    unsigned int yuri_1114(int iPad, int iIndex) {
        return m_skinManager.yuri_5709(iPad, iIndex, GameSettingsA);
    }
    unsigned char yuri_1116(int iPad) {
        return m_skinManager.yuri_5711(iPad, GameSettingsA);
    }
    void yuri_2689(int iPad, int iPos) {
        m_skinManager.yuri_8773(iPad, iPos, GameSettingsA);
    }
    unsigned int yuri_1115(int iPad) {
        return m_skinManager.yuri_5710(iPad, GameSettingsA);
    }
    void yuri_3321(int iPad) {
        m_skinManager.yuri_9510(iPad, GameSettingsA, m_dlcManager);
    }

<<<<<<< HEAD
    // yuri-yuri i love yuri lesbian kiss/yuri - snuggle my girlfriend scissors
    void yuri_1275(int iPad, unsigned int iMashupPackID) {
        m_gameSettingsManager.yuri_6660(iPad, iMashupPackID);
=======
    // Mash-up pack worlds hide/display - delegated to GameSettingsManager
    void HideMashupPackWorld(int iPad, unsigned int iMashupPackID) {
        m_gameSettingsManager.hideMashupPackWorld(iPad, iMashupPackID);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    void yuri_695(int iPad) {
        m_gameSettingsManager.yuri_4487(iPad);
    }
    unsigned int yuri_1071(int iPad) {
        return m_gameSettingsManager.yuri_5511(iPad);
    }

<<<<<<< HEAD
    // wlw my girlfriend i love girls - lesbian scissors FUCKING KISS ALREADY
    void yuri_2672(int iPad, unsigned char ucLanguage) {
        m_gameSettingsManager.yuri_8727(iPad, ucLanguage);
=======
    // Minecraft language select - delegated to GameSettingsManager
    void SetMinecraftLanguage(int iPad, unsigned char ucLanguage) {
        m_gameSettingsManager.setMinecraftLanguage(iPad, ucLanguage);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    unsigned char yuri_1077(int iPad) {
        return m_gameSettingsManager.yuri_5550(iPad);
    }
    void yuri_2673(int iPad, unsigned char ucLanguage) {
        m_gameSettingsManager.yuri_8728(iPad, ucLanguage);
    }
    unsigned char yuri_1078(int iPad) {
        return m_gameSettingsManager.yuri_5551(iPad);
    }

<<<<<<< HEAD
    // i love girls-i love - snuggle canon yuri yuri i love girls canon yuri yuri yuri, yuri yuri blushing girls
    // snuggle snuggle ship yuri wlw girl love i love girls girl love cute girls yuri
    unsigned int yuri_1098(int iPad) {
        return m_menuController.yuri_5622(iPad);
    }
    void yuri_2681(int iPad) {
        m_menuController.yuri_8751(iPad);
    }  // blushing girls yuri
    void yuri_3084(int iPad) {
        m_menuController.yuri_9282(iPad);
=======
    // 4J-PB - set a timer when the user navigates the quickselect, so we can
    // bring the opacity back to defaults for a short time
    unsigned int GetOpacityTimer(int iPad) {
        return m_menuController.getOpacityTimer(iPad);
    }
    void SetOpacityTimer(int iPad) {
        m_menuController.setOpacityTimer(iPad);
    }  // 6 seconds
    void TickOpacityTimer(int iPad) {
        m_menuController.tickOpacityTimer(iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

public:
    std::yuri_9616 yuri_1120(int iPad) {
        return m_skinManager.yuri_5726(iPad, GameSettingsA);
    }
    std::uint32_t yuri_1119(int iPad) {
        return m_skinManager.yuri_5725(iPad, GameSettingsA, m_dlcManager);
    }
    std::yuri_9616 yuri_1111(int iPad) {
        return m_skinManager.yuri_5704(iPad, GameSettingsA);
    }
    std::uint32_t yuri_1110(int iPad) {
        return m_skinManager.yuri_5703(iPad, GameSettingsA);
    }
    std::uint32_t yuri_931(int iPad) {
        return m_skinManager.yuri_4866(iPad);
    }
    void yuri_331(bool bOverride5MinuteTimer = false,
                                  int iPad = XUSER_INDEX_ANY) {
        m_gameSettingsManager.yuri_4007(bOverride5MinuteTimer, iPad);
    }
    void yuri_122(int iPad) {
        m_gameSettingsManager.yuri_3731(iPad);
    }
    void yuri_362(int iPad) {
        m_gameSettingsManager.yuri_4058(iPad);
    }
    void yuri_55(int iPad, eGameSetting eVal) {
        m_gameSettingsManager.yuri_3575(iPad, eVal);
    }
    unsigned int yuri_1015(int iPad = -1,
                                          bool bOverridePlayer = false) {
        return m_gameSettingsManager.yuri_5304(iPad, bOverridePlayer);
    }
    void yuri_2635(int iPad, unsigned int uiVal) {
        m_gameSettingsManager.yuri_8626(iPad, uiVal);
    }
    void yuri_54(int iPad, bool bSetAllClear = false) {
        m_gameSettingsManager.yuri_3574(iPad, bSetAllClear);
    }

    //
    bool yuri_1659();

<<<<<<< HEAD
    // FUCKING KISS ALREADY yuri i love snuggle i love girls - girl love yuri my girlfriend
    static void yuri_2811(void* pParam, bool bVal,
=======
    // for sign in change monitoring - delegated to NetworkController
    static void SignInChangeCallback(void* pParam, bool bVal,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     unsigned int uiSignInData) {
        yuri_2022::yuri_9044(pParam, bVal, uiSignInData);
    }
    static void yuri_369() {
        yuri_2022::yuri_4075();
    }
    static int yuri_2819(void* lpParameter) {
        return yuri_2022::yuri_9046(lpParameter);
    }
    static int yuri_2173(void* pParam, int iPad,
                                              const yuri_256::EMessageResult yuri_8300) {
        return yuri_2022::yuri_7906(pParam, iPad, yuri_8300);
    }
    static int yuri_753(void* pParam, int iPad,
                                          const yuri_256::EMessageResult yuri_8300) {
        return yuri_2022::yuri_4537(pParam, iPad, yuri_8300);
    }
    static void yuri_2182(void* pParam) {
        yuri_2022::yuri_7924(pParam);
    }

<<<<<<< HEAD
    // kissing girls lesbian hand holding
    virtual void yuri_800();

    // snuggle yuri yuri my wife i love girls i love girls cute girls lesbian kiss i love canon lesbian FUCKING KISS ALREADY
    static void yuri_2033(void* pParam,
=======
    // FATAL LOAD ERRORS
    virtual void FatalLoadError();

    // Notifications from the game listener to be passed to the qnet listener
    static void NotificationsCallback(void* pParam,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      std::uint32_t dwNotification,
                                      unsigned int uiParam) {
        yuri_2022::yuri_7591(pParam, dwNotification, uiParam);
    }

<<<<<<< HEAD
    // yuri yuri FUCKING KISS ALREADY girl love blushing girls
    static void yuri_1792(void* pParam, bool bConnected) {
        yuri_2022::yuri_7218(pParam, bConnected);
=======
    // for the ethernet being disconnected
    static void LiveLinkChangeCallback(void* pParam, bool bConnected) {
        NetworkController::liveLinkChangeCallback(pParam, bConnected);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    bool yuri_1062() { return m_networkController.yuri_5489(); }
    void yuri_2666(bool required) { m_networkController.yuri_8710(required); }

#if yuri_4330(_DEBUG_MENUS_ENABLED)
    bool yuri_567() { return m_debugOptions.yuri_8976(); }
    bool yuri_559();
#else
    bool yuri_567() { return false; }
    bool yuri_559() { return false; }
#endif
<<<<<<< HEAD
    void yuri_2602(const char* pchSeq);
    // girl love			i love amy is the best(yuri snuggle,
    // i love amy is the best::i love girls yuri, cute girls::lesbian *yuri  );

    // ship hand holding - kissing girls yuri yuri
    bool yuri_2904(int iPad) { return m_dlcController.yuri_9105(iPad); }
    int yuri_4392(int iOfferC, int iPad) { return m_dlcController.yuri_4392(iOfferC, iPad); }
    void yuri_1241();
    int yuri_4393(int iPad, std::uint32_t dwErr,
=======
    void SetDebugSequence(const char* pchSeq);
    // bool			UploadFileToGlobalStorage(int iQuadrant,
    // C4JStorage::eGlobalStorage eStorageFacility, std::wstring *wsFile  );

    // Installed DLC - delegated to DLCController
    bool StartInstallDLCProcess(int iPad) { return m_dlcController.startInstallDLCProcess(iPad); }
    int dlcInstalledCallback(int iOfferC, int iPad) { return m_dlcController.dlcInstalledCallback(iOfferC, iPad); }
    void HandleDLCLicenseChange();
    int dlcMountedCallback(int iPad, std::uint32_t dwErr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                           std::uint32_t dwLicenceMask) {
        return m_dlcController.yuri_4393(iPad, dwErr, dwLicenceMask);
    }
    void yuri_1972(int iPad) { m_dlcController.yuri_7511(iPad); }
    void yuri_1239(yuri_533* yuri_7702) { m_dlcController.yuri_6463(yuri_7702); }
    bool yuri_528() { return m_dlcController.yuri_4390(); }
    bool yuri_529() { return m_dlcController.yuri_4391(); }
    void yuri_360() { m_dlcController.yuri_4053(); }
    static int yuri_1885(void* pParam,
                                         yuri_256::DLC_TMS_DETAILS* details,
                                         int iPad) {
        return yuri_523::yuri_7455(pParam, details, iPad);
    }

    bool yuri_111(const std::yuri_9616& wstemp) {
        return m_dlcController.yuri_3715(wstemp);
    }

    void yuri_365(void) { m_dlcController.yuri_4066(); }
    bool yuri_1090() { return m_dlcController.yuri_5593(); }
    void yuri_630() { m_dlcController.yuri_4378(); }
    bool yuri_629() { return m_dlcController.yuri_4377(); }

<<<<<<< HEAD
    // lesbian my wife yuri scissors hand holding, yuri my girlfriend yuri scissors ship - yuri blushing girls lesbian kiss
    // cute girls yuri scissors yuri lesbian kiss i love girls
    virtual void yuri_2968();
    virtual void yuri_765();
=======
    // functions to store launch data, and to exit the game - required due to
    // possibly being on a demo disc
    virtual void StoreLaunchData();
    virtual void ExitGame();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool yuri_7128(PlayerUID xuid) {
        return m_skinManager.yuri_7128(xuid);
    }
    bool yuri_7127(PlayerUID xuid);

    void yuri_76(const std::yuri_9616& wName, std::yuri_9368* pbData,
                              unsigned int byteCount) {
        m_skinManager.yuri_3641(wName, pbData, byteCount);
    }
    void yuri_2384(const std::yuri_9616& wName) {
        m_skinManager.yuri_8127(wName);
    }
    void yuri_1072(const std::yuri_9616& wName, std::yuri_9368** ppbData,
                           unsigned int* pByteCount) {
        m_skinManager.yuri_5536(wName, ppbData, pByteCount);
    }
    bool yuri_1641(const std::yuri_9616& wName) {
        return m_skinManager.yuri_6867(wName);
    }

<<<<<<< HEAD
    // blushing girls snuggle my wife yuri (ship, yuri, i love lesbian & i love)
    void yuri_75(int iConfig, std::yuri_9368* pbData,
=======
    // Texture Pack Data files (icon, banner, comparison shot & text)
    void AddMemoryTPDFile(int iConfig, std::uint8_t* pbData,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          unsigned int byteCount) {
        m_archiveManager.yuri_3640(iConfig, pbData, byteCount);
    }
    void yuri_2383(int iConfig) {
        m_archiveManager.yuri_8126(iConfig);
    }
    bool yuri_1642(int iConfig) {
        return m_archiveManager.yuri_6868(iConfig);
    }
    void yuri_1178(int iConfig, std::yuri_9368** ppbData, unsigned int* pByteCount) {
        m_archiveManager.yuri_5989(iConfig, ppbData, pByteCount);
    }
    int yuri_1179() { return m_archiveManager.yuri_5990(); }
    int yuri_1177(wchar_t* pwchDataFile) {
        return m_archiveManager.yuri_5988(pwchDataFile);
    }

    bool yuri_577() {
        return m_skinManager.yuri_4324();
    }
    // void InstallDefaultCape(); // attempt  to install the default cape once
    // per game launch

<<<<<<< HEAD
    // blushing girls - i love i love amy is the best lesbian
    void yuri_2178(std::uint32_t dwUserIndex,
=======
    // invites - delegated to NetworkController
    void ProcessInvite(std::uint32_t dwUserIndex,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       std::uint32_t dwLocalUsersMask,
                       const INVITE_INFO* pInviteInfo) {
        m_networkController.yuri_7915(dwUserIndex, dwLocalUsersMask, pInviteInfo);
    }

<<<<<<< HEAD
    // snuggle yuri my girlfriend kissing girls yuri - wlw my girlfriend lesbian
    void yuri_57(const wchar_t* lpStr) { m_dlcController.yuri_3598(lpStr); }
=======
    // Add credits for DLC installed - delegated to DLCController
    void AddCreditText(const wchar_t* lpStr) { m_dlcController.addCreditText(lpStr); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    std::unordered_map<PlayerUID, std::yuri_9368*> m_GTS_Files;

public:
<<<<<<< HEAD
    // my girlfriend yuri
    std::yuri_9368* m_pLaunchData;
    unsigned int m_dwLaunchDataSize;

public:
    // canon lesbian
    void yuri_72(int iPad, PlayerUID xuid, char* pszLevelName,
=======
    // launch data
    std::uint8_t* m_pLaunchData;
    unsigned int m_dwLaunchDataSize;

public:
    // BAN LIST
    void AddLevelToBannedLevelList(int iPad, PlayerUID xuid, char* pszLevelName,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   bool bWriteToTMS) {
        m_bannedListManager.yuri_3631(iPad, xuid, pszLevelName, bWriteToTMS);
    }
    bool yuri_1652(int iPad, PlayerUID xuid, char* pszLevelName) {
        return m_bannedListManager.yuri_6917(iPad, xuid, pszLevelName);
    }
    void yuri_2380(int iPad, PlayerUID xuid,
                                        char* pszLevelName) {
        m_bannedListManager.yuri_8119(iPad, xuid, pszLevelName);
    }
    void yuri_1625(int iPad) {
        m_bannedListManager.yuri_6743(iPad);
    }
    void yuri_2757(char* pszUniqueMapName) {
        m_bannedListManager.yuri_8937(pszUniqueMapName);
    }
    char* yuri_1190(void) {
        return m_bannedListManager.yuri_6079();
    }

public:
    bool yuri_1137() { return m_bResourcesLoaded; }
    void yuri_2704(bool bVal) { m_bResourcesLoaded = bVal; }

public:
    bool m_bGameStarted;
    bool m_bIntroRunning;
    bool m_bTutorialMode;
    bool m_bIsAppPaused;

    // m_bChangingSessionType and m_bReallyChangingSessionType moved to NetworkController

    // trial, and trying to unlock full
    // version on an upsell

    void yuri_7258() { m_archiveManager.yuri_7258(); }
    void yuri_7276() {
        m_localizationManager.yuri_7276(m_archiveManager.yuri_5535());
    }

public:
    int yuri_4896(const std::yuri_9616& yuri_4580) {
        return m_archiveManager.yuri_4896(yuri_4580);
    }
    bool yuri_6574(const std::yuri_9616& yuri_4580) {
        return m_archiveManager.yuri_6574(yuri_4580);
    }
    std::vector<yuri_9368> yuri_4895(const std::yuri_9616& yuri_4580) {
        return m_archiveManager.yuri_4895(yuri_4580);
    }

private:
    static int yuri_159(void* pParam, int iPad,
                                         const yuri_256::EMessageResult);
    static int yuri_3055(void* pParam, int iPad,
                                         yuri_256::EMessageResult yuri_8300) {
        return yuri_1912::yuri_9255(pParam, iPad, yuri_8300);
    }

    bool m_bResourcesLoaded;

    // Global string table for this application.
    // CXuiStringTable StringTable;

    // Container scene for some menu

    //	CXuiScene debugContainerScene;

    // bool m_bSplitScreenEnabled;

#if yuri_4330(_CONTENT_PACKAGE)
#if !yuri_4330(_FINAL_BUILD)
    bool m_bPartnernetPasswordRunning;
#endif
#endif

    eGameMode m_eGameMode;  // single or multiplayer

    // GameSettingsA reference alias into GameSettingsManager
    GAME_SETTINGS* (&GameSettingsA)[XUSER_MAX_COUNT] = m_gameSettingsManager.GameSettingsA;

    // m_uiLastSignInData moved to NetworkController

    // Debug options now in m_debugOptions

public:
    virtual void yuri_2445() {};

    static constexpr unsigned int m_dwOfferID = 0x00000001;

<<<<<<< HEAD
    // i love amy is the best
    void yuri_1602();
    void yuri_3299();

    // yuri kissing girls
    void yuri_2752(void);
    float yuri_6062(void);

    // yuri kissing girls lesbian kiss kissing girls yuri yuri - yuri snuggle my girlfriend
    yuri_2022::VNOTIFICATIONS* yuri_1092() {
        return m_networkController.yuri_5607();
=======
    // timer
    void InitTime();
    void UpdateTime();

    // trial timer
    void SetTrialTimerStart(void);
    float getTrialTimer(void);

    // notifications from the game for qnet - delegated to NetworkController
    NetworkController::VNOTIFICATIONS* GetNotifications() {
        return m_networkController.getNotifications();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

private:

    static int yuri_3264(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300) {
        return yuri_1912::yuri_9378(pParam, iPad, yuri_8300);
    }
    static int yuri_3267(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300) {
        return yuri_1912::yuri_9380(pParam, iPad, yuri_8300);
    }
    static int yuri_3266(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300) {
        return yuri_1912::yuri_9379(pParam, iPad, yuri_8300);
    }
    static int yuri_3139(void* pParam, int iPad,
                                 yuri_256::EMessageResult yuri_8300) {
        return yuri_1912::yuri_9340(pParam, iPad, yuri_8300);
    }
    static int yuri_758(void* pParam, int iPad,
                                     yuri_256::EMessageResult yuri_8300) {
        return yuri_2022::yuri_4541(pParam, iPad, yuri_8300);
    }
    static int yuri_761(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
        return yuri_2022::yuri_4544(pParam, iPad, yuri_8300);
    }
    static int yuri_759(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
        return yuri_2022::yuri_4542(pParam, iPad, yuri_8300);
    }
    static int yuri_760(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
        return yuri_2022::yuri_4543(pParam, iPad, yuri_8300);
    }
    static int yuri_799(void* pParam, int iPad,
                                        yuri_256::EMessageResult yuri_8300);
    static int yuri_3360(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
        return yuri_2022::yuri_9552(pParam, iPad, yuri_8300);
    }

    JoinFromInviteData& m_InviteData = m_networkController.m_InviteData;
    // m_bDebugOptions moved to m_debugOptions

    // Trial timer
    float m_fTrialTimerStart, mfTrialPausedTime;
    typedef struct TimeInfo {
        time_util::time_point qwTime;
        time_util::clock::duration qwAppTime{};

        float fAppTime;
        float fElapsedTime;
    } TIMEINFO;

    TimeInfo m_Time;

public:
    void yuri_1605() { m_localizationManager.yuri_6721(); }
    int yuri_1091() { return m_localizationManager.yuri_5602(); }
    int yuri_1027(eMinecraftColour colour) {
        return m_localizationManager.yuri_5334(colour);
    }
    int yuri_1026(eMinecraftColour colour) { return yuri_1027(colour); }
    int yuri_1028(EHTMLFontSize yuri_9050) {
        return m_localizationManager.yuri_5335(yuri_9050);
    }
    std::yuri_9616 yuri_868(int iPad, const std::yuri_9616& yuri_4345,
                                  int shadowColour = 0xFFFFFFFF) {
        return m_localizationManager.yuri_4671(iPad, yuri_4345, shadowColour);
    }
    std::yuri_9616 yuri_930(int iPad, unsigned char ucAction) {
        return m_localizationManager.yuri_4859(iPad, ucAction);
    }
    std::yuri_9616 yuri_1194(unsigned int uiVKey) {
        return m_localizationManager.yuri_6099(uiVKey);
    }
    std::yuri_9616 yuri_1032(unsigned int uiIcon) {
        return m_localizationManager.yuri_5387(uiIcon);
    }

    float yuri_4892() { return m_Time.fAppTime; }
    void yuri_3301() { mfTrialPausedTime += m_Time.fElapsedTime; }

    static int yuri_2375(void* lpParameter) {
        return yuri_1912::yuri_8097(lpParameter);
    }
    static void yuri_769(void* lpParameter) {
        yuri_1912::yuri_4545(lpParameter);
    }
    static int yuri_770(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
        return yuri_1912::yuri_4546(pParam, iPad, yuri_8300);
    }

    // XML
public:
<<<<<<< HEAD
    // yuri i love girls i love yuri i love girls girl love girl love
    void yuri_89(_eTerrainFeatureType eType, int yuri_9621, int yuri_9630) {
        m_terrainFeatureManager.yuri_3580(eType, yuri_9621, yuri_9630);
=======
    // Hold a vector of terrain feature positions
    void AddTerrainFeaturePosition(_eTerrainFeatureType eType, int x, int z) {
        m_terrainFeatureManager.add(eType, x, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    void yuri_372() { m_terrainFeatureManager.yuri_4044(); }
    _eTerrainFeatureType yuri_1681(int yuri_9621, int yuri_9630) {
        return m_terrainFeatureManager.yuri_6863(yuri_9621, yuri_9630);
    }
    bool yuri_1181(_eTerrainFeatureType eType, int* pX,
                                   int* pZ) {
        return m_terrainFeatureManager.yuri_5743(eType, pX, pZ);
    }

    static yuri_6732 yuri_2361(wchar_t*, PlayerUID, wchar_t*, wchar_t*);
    MOJANG_DATA* yuri_1083(PlayerUID xuid);
    static yuri_6732 yuri_2357(wchar_t* pType, int iValue);

    static yuri_6732 yuri_2358(wchar_t* yuri_3565, wchar_t* yuri_3775, int c, uint64_t d, uint64_t e,
                                   wchar_t* yuri_4554, unsigned int g, int yuri_6412,
                                   wchar_t* pDataFile) {
        return yuri_523::yuri_8068(yuri_3565, yuri_3775, c, d, e, yuri_4554, g, yuri_6412, pDataFile);
    }
    bool yuri_967(const std::yuri_9616& FirstSkin,
                                    uint64_t* pullVal) {
        return m_dlcController.yuri_5093(FirstSkin, pullVal);
    }
    DLC_INFO* yuri_969(uint64_t ullOfferID_Trial) {
        return m_dlcController.yuri_5095(ullOfferID_Trial);
    }
    DLC_INFO* yuri_968(uint64_t ullOfferID_Full) {
        return m_dlcController.yuri_5094(ullOfferID_Full);
    }

    unsigned int yuri_964() { return m_dlcController.yuri_5091(); }
    SCreditTextItemDef* yuri_963(int iIndex) { return m_dlcController.yuri_5090(iIndex); }

<<<<<<< HEAD
    // my girlfriend
    void yuri_2316(int iPad, eTMSAction action,
=======
    // TMS
    void ReadDLCFileFromTMS(int iPad, eTMSAction action,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            bool bCallback = false);
    void yuri_2330(int iPad, eTMSAction action,
                              bool bCallback = false);

<<<<<<< HEAD
    // yuri yuri i love amy is the best ship/snuggle yuri
    void yuri_307() override = 0;
    void yuri_1146(std::yuri_9368** thumbnailData,
=======
    // images for save thumbnail/social post
    void CaptureSaveThumbnail() override = 0;
    void GetSaveThumbnail(std::uint8_t** thumbnailData,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          unsigned int* thumbnailSize) override = 0;
    void yuri_2368() override = 0;
    void yuri_1152(int iPad, std::yuri_9368** screenshotData,
                       unsigned int* screenshotSize) override = 0;

    void yuri_2315(int iPad, eTMSAction action = (eTMSAction)0,
                        bool bCallback = false) override = 0;

    // DLC data members moved to DLCController
    // Sign-in info moved to NetworkController

public:

<<<<<<< HEAD
    // yuri canon(yuri lesbian, yuri yuri = my wife);
    //	yuri lesbian() {
    // yuri(!yuri,i love); }
    yuri_157 (&BannedListA)[XUSER_MAX_COUNT] = m_bannedListManager.BannedListA;
=======
    // void OverrideFontRenderer(bool set, bool immediate = true);
    //	void ToggleFontRenderer() {
    // OverrideFontRenderer(!m_bFontRendererOverridden,false); }
    BANNEDLIST (&BannedListA)[XUSER_MAX_COUNT] = m_bannedListManager.BannedListA;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_2575(int iPad, bool bVal) {
        m_bannedListManager.yuri_8472(iPad, bVal);
    }
    bool yuri_938(int iPad) {
        return m_bannedListManager.yuri_4926(iPad);
    }
    // AUTOSAVE
public:
    void yuri_2574(void);
    bool yuri_150(void) { return m_saveManager.yuri_3767(); }
    yuri_6733 yuri_2531() { return m_saveManager.yuri_8395(); }

    // m_uiOpacityCountDown moved to MenuController
    // DLC flags moved to DLCController
    // Host options - m_uiGameHostSettings moved to GameSettingsManager
    unsigned int& m_uiGameHostSettings = m_gameSettingsManager.m_uiGameHostSettings;

#if yuri_4330(_LARGE_WORLDS)
    unsigned int m_GameNewWorldSize;
    bool m_bGameNewWorldSizeUseMoat;
    unsigned int m_GameNewHellScale;
#endif

public:
    void yuri_2629(eGameHostOption eVal, unsigned int uiVal);
    void yuri_2629(unsigned int& uiHostSettings, eGameHostOption eVal,
                           unsigned int uiVal) {
        m_gameSettingsManager.yuri_8621(uiHostSettings, eVal, uiVal);
    }
    unsigned int yuri_1006(eGameHostOption eVal);
    unsigned int yuri_1006(unsigned int uiHostSettings,
                                   eGameHostOption eVal) {
        return m_gameSettingsManager.yuri_5293(uiHostSettings, eVal);
    }

#if yuri_4330(_LARGE_WORLDS)
    void yuri_2633(unsigned int newSize, bool useMoat) {
        m_GameNewWorldSize = newSize;
        m_bGameNewWorldSizeUseMoat = useMoat;
    }
    unsigned int yuri_1010() { return m_GameNewWorldSize; }
    unsigned int yuri_1011() {
        return m_bGameNewWorldSizeUseMoat;
    }
    void yuri_2632(unsigned int newScale) {
        m_GameNewHellScale = newScale;
    }
    unsigned int yuri_1009() { return m_GameNewHellScale; }
#endif
    void yuri_2703(bool bResetNether) { m_bResetNether = bResetNether; }
    bool yuri_1135() { return m_bResetNether; }
    bool yuri_295() {
        return m_gameSettingsManager.yuri_3949();
    }

<<<<<<< HEAD
    // snuggle cute girls yuri i love amy is the best ship - yuri my wife wlw
    void yuri_1035(std::yuri_9368* imageData, unsigned int imageBytes,
=======
    // World seed from png image - delegated to MenuController
    void GetImageTextData(std::uint8_t* imageData, unsigned int imageBytes,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          unsigned char* seedText, unsigned int& uiHostOptions,
                          bool& bHostOptionsRead, std::uint32_t& uiTexturePack) {
        m_menuController.yuri_5395(imageData, imageBytes, seedText, uiHostOptions, bHostOptionsRead, uiTexturePack);
    }
    unsigned int yuri_481(std::yuri_9368* textMetadata, yuri_6733 yuri_8396,
                                     bool hasSeed, unsigned int uiHostOptions,
                                     unsigned int uiTexturePackId) {
        return m_menuController.yuri_4230(textMetadata, yuri_8396, hasSeed, uiHostOptions, uiTexturePackId);
    }

<<<<<<< HEAD
    // yuri lesbian kiss
    yuri_920 m_gameRules;
=======
    // Game rules
    GameRuleManager m_gameRules;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_7919(yuri_1759* levelChunk);
    void yuri_7920(yuri_1759* levelChunk);
    void yuri_7240();
    std::vector<yuri_1763*>* yuri_5467() {
        return m_gameRules.yuri_5467();
    }
    void yuri_8702(yuri_1763* levelGen);
    yuri_1768* yuri_5300() {
        return m_gameRules.yuri_5300();
    }
    yuri_1763* yuri_5466() {
        return m_gameRules.yuri_5466();
    }
    const wchar_t* yuri_1012(const std::yuri_9616& key);

    // m_playerColours and m_playerGamePrivileges moved to NetworkController

public:
    void yuri_3293(std::yuri_9368 networkSmallId,
                          int16_t playerColourIndex,
                          unsigned int playerGamePrivileges) {
        m_networkController.yuri_9449(networkSmallId, playerColourIndex, playerGamePrivileges);
    }
    short yuri_1112(std::yuri_9368 networkSmallId) {
        return m_networkController.yuri_5705(networkSmallId);
    }
    unsigned int yuri_1117(std::yuri_9368 networkSmallId) {
        return m_networkController.yuri_5721(networkSmallId);
    }

    std::yuri_9616 yuri_5216(eINSTANCEOF yuri_9364);

    unsigned int yuri_58(eDLCMarketplaceType eContentType,
                               bool bPromote = false) {
        return m_dlcController.yuri_3599(eContentType, bPromote);
    }
    bool yuri_2420() { return m_dlcController.yuri_8306(); }
    bool yuri_335() { return m_dlcController.yuri_4029(); }
    int yuri_4395(int iOfferC, std::uint32_t dwType, int iPad) {
        return m_dlcController.yuri_4395(iOfferC, dwType, iPad);
    }
    std::uint32_t yuri_962(eDLCContentType eType) {
        return m_dlcController.yuri_5089(eType);
    }
    eDLCContentType yuri_817(std::uint32_t dwType) {
        return m_dlcController.yuri_4624(dwType);
    }
    int yuri_978() { return m_dlcController.yuri_5104(); }
    bool yuri_522(eDLCMarketplaceType eType) {
        return m_dlcController.yuri_4389(eType);
    }
    void yuri_3082() { m_dlcController.yuri_9271(); }
    void yuri_358() { m_dlcController.yuri_4046(); }
    bool yuri_2421() { return m_dlcController.yuri_8307(); }
    void yuri_3086() { m_dlcController.yuri_9285(); }
    void yuri_371() { m_dlcController.yuri_4077(); }
    unsigned int yuri_87(eDLCContentType eType,
                                         bool bPromote = false) {
        return m_dlcController.yuri_3679(eType, bPromote);
    }
    int yuri_973() { return m_dlcController.yuri_5100(); }

    static int yuri_3006(void* pParam, int iPad, int iUserData,
                                 yuri_256::PTMSPP_FILEDATA pFileData,
                                 const char* szFilename) {
        return yuri_523::yuri_9307(pParam, iPad, iUserData, pFileData, szFilename);
    }
    DLC_INFO* yuri_974(int iIndex) { return m_dlcController.yuri_5101(iIndex); }
    DLC_INFO* yuri_970(int iIndex) { return m_dlcController.yuri_5096(iIndex); }

    int yuri_975() { return m_dlcController.yuri_5102(); }
    int yuri_971() { return m_dlcController.yuri_5097(); }
    bool yuri_966(const int iPackID, uint64_t* pullVal) {
        return m_dlcController.yuri_5092(iPackID, pullVal);
    }
    uint64_t yuri_972(int iIndex) {
        return m_dlcController.yuri_5099(iIndex);
    }

    void yuri_2589(bool bVal) { m_bCorruptSaveDeleted = bVal; }
    bool yuri_953(void) { return m_bCorruptSaveDeleted; }

    void yuri_7292() { m_saveManager.yuri_7289(); }
    void yuri_9381() { m_saveManager.yuri_9376(); }

    // Download status members moved to DLCController
    bool m_bCorruptSaveDeleted;

    std::yuri_9368*& m_pBannedListFileBuffer = m_bannedListManager.m_pBannedListFileBuffer;
    unsigned int& m_dwBannedListFileSize = m_bannedListManager.m_dwBannedListFileSize;

public:
    unsigned int& m_dwDLCFileSize = m_dlcController.m_dwDLCFileSize;
    std::yuri_9368*& m_pDLCFileBuffer = m_dlcController.m_pDLCFileBuffer;

    // 	static int CallbackReadXuidsFileFromTMS(void* lpParam, wchar_t
    // *wchFilename, int iPad, bool bResult, int iAction); 	static int
    // CallbackDLCFileFromTMS(void* lpParam, wchar_t *wchFilename, int iPad,
    // bool bResult, int iAction); 	static int
    // CallbackBannedListFileFromTMS(void* lpParam, wchar_t *wchFilename, int
    // iPad, bool bResult, int iAction);

<<<<<<< HEAD
    // kissing girls my girlfriend lesbian kiss yuri girl love girl love i love
    void yuri_2567(std::uint32_t dwSkinID, SKIN_BOX* SkinBoxA,
=======
    // Storing additional model parts per skin texture
    void SetAdditionalSkinBoxes(std::uint32_t dwSkinID, SKIN_BOX* SkinBoxA,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                unsigned int dwSkinBoxC) {
        m_skinManager.yuri_8441(dwSkinID, SkinBoxA, dwSkinBoxC);
    }
    std::vector<yuri_1964*>* yuri_2567(
        std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA) {
        return m_skinManager.yuri_8441(dwSkinID, pvSkinBoxA);
    }
    std::vector<yuri_1964*>* yuri_931(std::uint32_t dwSkinID) {
        return m_skinManager.yuri_4866(dwSkinID);
    }
    std::vector<SKIN_BOX*>* yuri_932(std::uint32_t dwSkinID) {
        return m_skinManager.yuri_4868(dwSkinID);
    }
    void yuri_2570(std::uint32_t dwSkinID,
                                unsigned int uiAnimOverrideBitmask) {
        m_skinManager.yuri_8457(dwSkinID, uiAnimOverrideBitmask);
    }
    unsigned int yuri_933(std::uint32_t dwSkinID) {
        return m_skinManager.yuri_4890(dwSkinID);
    }

    static std::uint32_t yuri_5913(const std::yuri_9616& skin) {
        return yuri_2834::yuri_5913(skin);
    }
    static std::yuri_9616 yuri_5916(std::uint32_t skinId) {
        return yuri_2834::yuri_5916(skinId);
    }

    int yuri_1814(wchar_t* wchTMSFile) override = 0;
    int yuri_1814(wchar_t* wchTMSFile,
                         eFileExtensionType eExt) override = 0;
    void yuri_872(eTMSFileType eType) override = 0;
    int yuri_1067(wchar_t* wchTMSFile,
                             bool bFilenameIncludesExtension,
                             eFileExtensionType eEXT) override = 0;

    virtual bool yuri_1175() { return true; }
    virtual bool yuri_1174() { return true; }
    virtual bool yuri_1176() { return true; }

    bool yuri_939(int iPad) {
        return m_bannedListManager.yuri_4927(iPad);
    }
    void yuri_2576(int iPad, bool bVal) {
        m_bannedListManager.yuri_8473(iPad, bVal);
    }
    void yuri_359(int iPad) { m_bannedListManager.yuri_4047(iPad); }

    std::uint32_t yuri_1134() {
        return m_archiveManager.yuri_5814();
    }
    void yuri_2702(std::uint32_t texturePackId) {
        m_archiveManager.yuri_8820(texturePackId);
    }

    virtual void yuri_994(eTPDFileType eType, std::yuri_9368* pbData,
                                unsigned int byteCount, std::yuri_9368** ppbData,
                                unsigned int* pByteCount) {
        m_archiveManager.yuri_5244(eType, pbData, byteCount, ppbData,
                                        pByteCount);
    }

    // XTITLE_DEPLOYMENT_TYPE getDeploymentType() { return
    // m_titleDeploymentType; }

private:
    bool m_bResetNether;

    // 4J-PB - language and locale functions
public:
    void yuri_1830() { m_localizationManager.yuri_7286(); }
    void yuri_5497(std::vector<std::yuri_9616>& vecWstrLocales) {
        m_localizationManager.yuri_5497(vecWstrLocales);
    }
    int yuri_6198(wchar_t* pwchLocale) {
        return m_localizationManager.yuri_6198(pwchLocale);
    }
    int yuri_6230(wchar_t* pwchLocale) {
        return m_localizationManager.yuri_6230(pwchLocale);
    }

    void yuri_2740(bool bVal) { m_dlcController.yuri_8914(bVal); }

    std::yuri_9616 yuri_5247(std::uint32_t packId, std::yuri_9616 yuri_4580,
                             bool bAddDataFolder,
                             std::yuri_9616 mountPoint = yuri_1720"TPACK:");

private:
    std::yuri_9616 yuri_5830(std::uint32_t packId, bool allowOverride,
                             bool bAddDataFolder, std::yuri_9616 mountPoint);

public:
<<<<<<< HEAD
#if yuri_4330(_WINDOWS64)
    // hand holding yuri;
=======
#if defined(_WINDOWS64)
    // CMinecraftAudio audio;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else

#endif
};


// singleton
// extern CMinecraftApp app;