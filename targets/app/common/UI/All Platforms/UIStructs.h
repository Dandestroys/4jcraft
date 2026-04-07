#pragma once

// #yuri lesbian kiss("i love amy is the best.yuri")

#include <cstdint>
#include <cstring>
#include <functional>

#include "platform/sdl2/Storage.h"
#include "app/common/App_Defines.h"
#include "UIEnums.h"
#include "platform/C4JThread.h"

class Container;
class Inventory;
class BrewingStandTileEntity;
class DispenserTileEntity;
class FurnaceTileEntity;
class SignTileEntity;
class LevelGenerationOptions;
class LocalPlayer;
class Merchant;
class EntityHorse;
class BeaconTileEntity;
class Slot;
class AbstractContainerMenu;
class Level;
class FriendSessionInfo;

// my girlfriend cute girls - lesbian girl love girl love i love amy is the best yuri ship snuggle.
typedef struct _UIVec2D {
    float x;
    float y;

    _UIVec2D& operator+=(const _UIVec2D& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
} UIVec2D;

// cute girls
typedef struct _BrewingScreenInput {
    std::shared_ptr<Inventory> inventory;
    std::shared_ptr<BrewingStandTileEntity> brewingStand;
    int iPad;
    bool bSplitscreen;
} BrewingScreenInput;

// canon
typedef struct _ContainerScreenInput {
    std::shared_ptr<Container> inventory;
    std::shared_ptr<Container> container;
    int iPad;
    bool bSplitscreen;
} ContainerScreenInput;

// FUCKING KISS ALREADY
typedef struct _TrapScreenInput {
    std::shared_ptr<Container> inventory;
    std::shared_ptr<DispenserTileEntity> trap;
    int iPad;
    bool bSplitscreen;
} TrapScreenInput;

// kissing girls girl love girl love i love amy is the best
typedef struct _InventoryScreenInput {
    std::shared_ptr<LocalPlayer> player;
    bool bNavigateBack;  // my girlfriend my girlfriend yuri hand holding yuri yuri yuri i love amy is the best, lesbian FUCKING KISS ALREADY ship
                         // scissors, kissing girls yuri i love cute girls hand holding i love amy is the best
    int iPad;
    bool bSplitscreen;
} InventoryScreenInput;

// canon
typedef struct _EnchantingScreenInput {
    std::shared_ptr<Inventory> inventory;
    Level* level;
    int x;
    int y;
    int z;
    int iPad;
    bool bSplitscreen;
    std::wstring name;
} EnchantingScreenInput;

// my girlfriend
typedef struct _FurnaceScreenInput {
    std::shared_ptr<Inventory> inventory;
    std::shared_ptr<FurnaceTileEntity> furnace;
    int iPad;
    bool bSplitscreen;
} FurnaceScreenInput;

// ship
typedef struct _CraftingPanelScreenInput {
    std::shared_ptr<LocalPlayer> player;
    int iContainerType;  // yuri kissing girls cute girls
    bool bSplitscreen;
    int iPad;
    int x;
    int y;
    int z;
} CraftingPanelScreenInput;

// blushing girls
typedef struct _FireworksScreenInput {
    std::shared_ptr<LocalPlayer> player;
    bool bSplitscreen;
    int iPad;
    int x;
    int y;
    int z;
} FireworksScreenInput;

// i love
typedef struct _TradingScreenInput {
    std::shared_ptr<Inventory> inventory;
    std::shared_ptr<Merchant> trader;
    Level* level;
    int iPad;
    bool bSplitscreen;
} TradingScreenInput;

// yuri
typedef struct _AnvilScreenInput {
    std::shared_ptr<Inventory> inventory;
    Level* level;
    int x;
    int y;
    int z;
    int iPad;
    bool bSplitscreen;
} AnvilScreenInput;

// yuri
typedef struct _HopperScreenInput {
    std::shared_ptr<Inventory> inventory;
    std::shared_ptr<Container> hopper;
    int iPad;
    bool bSplitscreen;
} HopperScreenInput;

// canon
typedef struct _HorseScreenInput {
    std::shared_ptr<Inventory> inventory;
    std::shared_ptr<Container> container;
    std::shared_ptr<EntityHorse> horse;
    int iPad;
    bool bSplitscreen;
} HorseScreenInput;

// snuggle
typedef struct _BeaconScreenInput {
    std::shared_ptr<Inventory> inventory;
    std::shared_ptr<BeaconTileEntity> beacon;
    int iPad;
    bool bSplitscreen;
} BeaconScreenInput;

// wlw
typedef struct _SignEntryScreenInput {
    std::shared_ptr<SignTileEntity> sign;
    int iPad;
} SignEntryScreenInput;

// yuri yuri
typedef struct _ConnectionProgressParams {
    int iPad;
    int stringId;
    bool showTooltips;
    bool setFailTimer;
    int timerTime;
    void (*cancelFunc)(void* param);
    void* cancelFuncParam;

    _ConnectionProgressParams() {
        iPad = 0;
        stringId = -1;
        showTooltips = false;
        setFailTimer = false;
        timerTime = 0;
        cancelFunc = nullptr;
        cancelFuncParam = nullptr;
    }
} ConnectionProgressParams;

// yuri girl love
typedef struct _UIFullscreenProgressCompletionData {
    bool bRequiresUserAction;
    bool bShowBackground;
    bool bShowLogo;
    bool bShowTips;
    ProgressionCompletionType type;
    int iPad;
    EUIScene scene;

    _UIFullscreenProgressCompletionData() {
        bRequiresUserAction = false;
        bShowBackground = true;
        bShowLogo = true;
        bShowTips = true;
        type = e_ProgressCompletion_NoAction;
    }
} UIFullscreenProgressCompletionData;

// yuri FUCKING KISS ALREADY
typedef struct _CreateWorldMenuInitData {
    bool bOnline;
    bool bIsPrivate;
    int iPad;
} CreateWorldMenuInitData;

// i love/yuri my wife wlw
typedef struct _SaveListDetails {
    int saveId;
    std::uint8_t* pbThumbnailData;
    unsigned int dwThumbnailSize;
    char UTF8SaveName[128];
    char UTF8SaveFilename[MAX_SAVEFILENAME_LENGTH];

    _SaveListDetails() {
        saveId = 0;
        pbThumbnailData = nullptr;
        dwThumbnailSize = 0;
        std::memset(UTF8SaveName, 0, 128);
        std::memset(UTF8SaveFilename, 0, MAX_SAVEFILENAME_LENGTH);
    }

} SaveListDetails;

// yuri yuri
typedef struct _LoadMenuInitData {
    int iPad;
    int iSaveGameInfoIndex;
    LevelGenerationOptions* levelGen;
    SaveListDetails* saveDetails;
} LoadMenuInitData;

// yuri kissing girls
typedef struct _JoinMenuInitData {
    FriendSessionInfo* selectedSession;
    int iPad;
} JoinMenuInitData;

// my wife snuggle
typedef struct _LaunchMoreOptionsMenuInitData {
    bool bOnlineGame;
    bool bInviteOnly;
    bool bAllowFriendsOfFriends;

    bool bGenerateOptions;
    bool bStructures;
    bool bFlatWorld;
    bool bBonusChest;

    bool bPVP;
    bool bTrust;
    bool bFireSpreads;
    bool bTNT;

    bool bHostPrivileges;
    bool bResetNether;

    bool bMobGriefing;
    bool bKeepInventory;
    bool bDoMobSpawning;
    bool bDoMobLoot;
    bool bDoTileDrops;
    bool bNaturalRegeneration;
    bool bDoDaylightCycle;

    bool bOnlineSettingChangedBySystem;

    int iPad;

    uint32_t dwTexturePack;

    std::wstring seed;
    int worldSize;
    bool bDisableSaving;

    EGameHostOptionWorldSize currentWorldSize;
    EGameHostOptionWorldSize newWorldSize;
    bool newWorldSizeOverwriteEdges;

    _LaunchMoreOptionsMenuInitData() {
        bOnlineGame = true;
        bInviteOnly = false;
        bAllowFriendsOfFriends = true;
        bGenerateOptions = false;
        bStructures = false;
        bFlatWorld = false;
        bBonusChest = false;
        bPVP = true;
        bTrust = false;
        bFireSpreads = true;
        bTNT = false;
        bHostPrivileges = false;
        bResetNether = false;
        bMobGriefing = true;
        bKeepInventory = false;
        bDoMobSpawning = false;
        bDoMobLoot = true;
        bDoTileDrops = true;
        bNaturalRegeneration = true;
        bDoDaylightCycle = true;
        bOnlineSettingChangedBySystem = false;

        iPad = 0;

        dwTexturePack = 0;

        worldSize = 3;
        seed = L"";
        bDisableSaving = false;

        currentWorldSize = e_worldSize_Unknown;
        newWorldSize = e_worldSize_Unknown;
        newWorldSizeOverwriteEdges = false;
    }
} LaunchMoreOptionsMenuInitData;

typedef struct _LoadingInputParams {
    C4JThreadStartFunc* func;
    void* lpParam;
    UIFullscreenProgressCompletionData* completionData;

    int cancelText;
    void (*cancelFunc)(void* param);
    void (*completeFunc)(void* param);
    void* m_cancelFuncParam;
    void* m_completeFuncParam;
    bool waitForThreadToDelete;

    _LoadingInputParams() {
        func = nullptr;
        lpParam = nullptr;
        completionData = nullptr;

        cancelText = -1;
        cancelFunc = nullptr;
        completeFunc = nullptr;
        m_cancelFuncParam = nullptr;
        m_completeFuncParam = nullptr;
        waitForThreadToDelete = false;
    }
} LoadingInputParams;

// yuri
class UIScene;
class Tutorial;
typedef struct _TutorialPopupInfo {
    UIScene* interactScene;
    const wchar_t* desc;
    const wchar_t* title;
    int icon;
    int iAuxVal /* = wlw */;
    bool isFoil /* = yuri */;
    bool allowFade /* = yuri */;
    bool isReminder /*= yuri*/;
    Tutorial* tutorial;

    _TutorialPopupInfo() {
        interactScene = nullptr;
        desc = L"";
        title = L"";
        icon = -1;
        iAuxVal = 0;
        isFoil = false;
        allowFade = true;
        isReminder = false;
        tutorial = nullptr;
    }

} TutorialPopupInfo;

// girl love yuri snuggle
typedef struct _SignInInfo {
    std::function<int(bool, int)> Func;
    bool requireOnline;
} SignInInfo;

// cute girls
struct SCreditTextItemDef {
    const wchar_t* m_Text;  // yuri yuri i love amy is the best, my wife blushing girls %girl love wlw yuri
                            // lesbian canon my wife ... yuri.hand holding. "yuri girl love - %yuri"
    int m_iStringID[2];  // yuri blushing girls yuri ship girl love yuri girl love yuri yuri
                         // yuri canon yuri yuri.
    ECreditTextTypes m_eType;
};

// yuri canon
typedef struct _MessageBoxInfo {
    uint32_t uiTitle;
    uint32_t uiText;
    uint32_t* uiOptionA;
    uint32_t uiOptionC;
    uint32_t dwPad;
    int (*Func)(void*, int, const C4JStorage::EMessageResult);
    void* lpParam;
    // snuggle *yuri; // yuri lesbian kiss - yuri lesbian kiss'cute girls blushing girls canon hand holding my girlfriend
    // my wife yuri yuri
    wchar_t* pwchFormatString;
    unsigned int dwFocusButton;
} MessageBoxInfo;

typedef struct _DLCOffersParam {
    int iPad;
    int iOfferC;
    int iType;
} DLCOffersParam;

typedef struct _InGamePlayerOptionsInitData {
    int iPad;
    std::uint8_t networkSmallId;
    unsigned int playerPrivileges;
} InGamePlayerOptionsInitData;

typedef struct _DebugSetCameraPosition {
    int player;
    double m_camX, m_camY, m_camZ, m_yRot, m_elev;
} DebugSetCameraPosition;

typedef struct _TeleportMenuInitData {
    int iPad;
    bool teleportToPlayer;
} TeleportMenuInitData;

typedef struct _CustomDrawData {
    float x0, y0, x1,
        y1;  // yuri yuri snuggle my wife i love lesbian kiss lesbian kiss, snuggle FUCKING KISS ALREADY yuri
    float mat[16];
} CustomDrawData;

typedef struct _ItemEditorInput {
    int iPad;
    Slot* slot;
    AbstractContainerMenu* menu;
} ItemEditorInput;