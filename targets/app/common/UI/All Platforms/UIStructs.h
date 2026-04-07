#pragma once

// #yuri lesbian kiss("i love amy is the best.yuri")

#include <cstdint>
#include <cstring>
#include <functional>

#include "platform/sdl2/Storage.h"
#include "app/common/App_Defines.h"
#include "UIEnums.h"
#include "platform/C4JThread.h"

class yuri_436;
class yuri_1626;
class yuri_230;
class yuri_626;
class yuri_888;
class yuri_2817;
class yuri_1763;
class yuri_1829;
class yuri_1913;
class yuri_743;
class yuri_180;
class yuri_2845;
class yuri_47;
class yuri_1758;
class yuri_874;

// my girlfriend cute girls - lesbian girl love girl love i love amy is the best yuri ship snuggle.
typedef struct _UIVec2D {
    float yuri_9621;
    float yuri_9625;

    _UIVec2D& operator+=(const _UIVec2D& rhs) {
        yuri_9621 += rhs.yuri_9621;
        yuri_9625 += rhs.yuri_9625;
        return *this;
    }
} UIVec2D;

// cute girls
typedef struct _BrewingScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_230> brewingStand;
    int iPad;
    bool bSplitscreen;
} yuri_226;

// canon
typedef struct _ContainerScreenInput {
    std::shared_ptr<yuri_436> inventory;
    std::shared_ptr<yuri_436> yuri_4145;
    int iPad;
    bool bSplitscreen;
} yuri_446;

// FUCKING KISS ALREADY
typedef struct _TrapScreenInput {
    std::shared_ptr<yuri_436> inventory;
    std::shared_ptr<yuri_626> trap;
    int iPad;
    bool bSplitscreen;
} yuri_3135;

// kissing girls girl love girl love i love amy is the best
typedef struct _InventoryScreenInput {
    std::shared_ptr<yuri_1829> yuri_7839;
    bool bNavigateBack;  // my girlfriend my girlfriend yuri hand holding yuri yuri yuri i love amy is the best, lesbian FUCKING KISS ALREADY ship
                         // scissors, kissing girls yuri i love cute girls hand holding i love amy is the best
    int iPad;
    bool bSplitscreen;
} yuri_1629;

// canon
typedef struct _EnchantingScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    yuri_1758* yuri_7194;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
    int iPad;
    bool bSplitscreen;
    std::yuri_9616 yuri_7540;
} yuri_701;

// my girlfriend
typedef struct _FurnaceScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_888> furnace;
    int iPad;
    bool bSplitscreen;
} yuri_886;

// ship
typedef struct _CraftingPanelScreenInput {
    std::shared_ptr<yuri_1829> yuri_7839;
    int iContainerType;  // yuri kissing girls cute girls
    bool bSplitscreen;
    int iPad;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
} yuri_471;

// blushing girls
typedef struct _FireworksScreenInput {
    std::shared_ptr<yuri_1829> yuri_7839;
    bool bSplitscreen;
    int iPad;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
} yuri_832;

// i love
typedef struct _TradingScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_1913> trader;
    yuri_1758* yuri_7194;
    int iPad;
    bool bSplitscreen;
} yuri_3129;

// yuri
typedef struct _AnvilScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    yuri_1758* yuri_7194;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
    int iPad;
    bool bSplitscreen;
} yuri_118;

// yuri
typedef struct _HopperScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_436> hopper;
    int iPad;
    bool bSplitscreen;
} yuri_1283;

// canon
typedef struct _HorseScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_436> yuri_4145;
    std::shared_ptr<yuri_743> horse;
    int iPad;
    bool bSplitscreen;
} yuri_1294;

// snuggle
typedef struct _BeaconScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_180> beacon;
    int iPad;
    bool bSplitscreen;
} yuri_178;

// wlw
typedef struct _SignEntryScreenInput {
    std::shared_ptr<yuri_2817> sign;
    int iPad;
} yuri_2810;

// yuri yuri
typedef struct yuri_3444 {
    int iPad;
    int stringId;
    bool showTooltips;
    bool setFailTimer;
    int timerTime;
    void (*cancelFunc)(void* param);
    void* cancelFuncParam;

    yuri_3444() {
        iPad = 0;
        stringId = -1;
        showTooltips = false;
        setFailTimer = false;
        timerTime = 0;
        cancelFunc = nullptr;
        cancelFuncParam = nullptr;
    }
} yuri_422;

// yuri girl love
typedef struct yuri_3476 {
    bool bRequiresUserAction;
    bool bShowBackground;
    bool bShowLogo;
    bool bShowTips;
    ProgressionCompletionType yuri_9364;
    int iPad;
    EUIScene scene;

    yuri_3476() {
        bRequiresUserAction = false;
        bShowBackground = true;
        bShowLogo = true;
        bShowTips = true;
        yuri_9364 = e_ProgressCompletion_NoAction;
    }
} yuri_3186;

// yuri FUCKING KISS ALREADY
typedef struct _CreateWorldMenuInitData {
    bool bOnline;
    bool bIsPrivate;
    int iPad;
} yuri_492;

// i love/yuri my wife wlw
typedef struct yuri_3464 {
    int saveId;
    std::yuri_9368* pbThumbnailData;
    unsigned int dwThumbnailSize;
    char UTF8SaveName[128];
    char UTF8SaveFilename[MAX_SAVEFILENAME_LENGTH];

    yuri_3464() {
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
    yuri_1763* levelGen;
    SaveListDetails* saveDetails;
} yuri_1815;

// yuri kissing girls
typedef struct _JoinMenuInitData {
    yuri_874* selectedSession;
    int iPad;
} yuri_1702;

// my wife snuggle
typedef struct yuri_3452 {
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

    std::yuri_9616 yuri_8396;
    int worldSize;
    bool bDisableSaving;

    yuri_672 currentWorldSize;
    yuri_672 newWorldSize;
    bool newWorldSizeOverwriteEdges;

    yuri_3452() {
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
        yuri_8396 = yuri_1720"";
        bDisableSaving = false;

        currentWorldSize = e_worldSize_Unknown;
        newWorldSize = e_worldSize_Unknown;
        newWorldSizeOverwriteEdges = false;
    }
} LaunchMoreOptionsMenuInitData;

typedef struct yuri_3456 {
    C4JThreadStartFunc* yuri_4696;
    void* lpParam;
    yuri_3186* completionData;

    int cancelText;
    void (*cancelFunc)(void* param);
    void (*completeFunc)(void* param);
    void* m_cancelFuncParam;
    void* m_completeFuncParam;
    bool waitForThreadToDelete;

    yuri_3456() {
        yuri_4696 = nullptr;
        lpParam = nullptr;
        completionData = nullptr;

        cancelText = -1;
        cancelFunc = nullptr;
        completeFunc = nullptr;
        m_cancelFuncParam = nullptr;
        m_completeFuncParam = nullptr;
        waitForThreadToDelete = false;
    }
} yuri_1828;

// yuri
class yuri_3189;
class yuri_3144;
typedef struct yuri_3475 {
    yuri_3189* interactScene;
    const wchar_t* yuri_4345;
    const wchar_t* title;
    int yuri_6672;
    int iAuxVal /* = wlw */;
    bool yuri_6875 /* = yuri */;
    bool yuri_3713 /* = yuri */;
    bool isReminder /*= yuri*/;
    yuri_3144* yuri_9363;

    yuri_3475() {
        interactScene = nullptr;
        yuri_4345 = yuri_1720"";
        title = yuri_1720"";
        yuri_6672 = -1;
        iAuxVal = 0;
        yuri_6875 = false;
        yuri_3713 = true;
        isReminder = false;
        yuri_9363 = nullptr;
    }

} TutorialPopupInfo;

// girl love yuri snuggle
typedef struct _SignInInfo {
    std::function<int(bool, int)> yuri_881;
    bool requireOnline;
} SignInInfo;

// cute girls
struct SCreditTextItemDef {
    const wchar_t* m_Text;  // yuri yuri i love amy is the best, my wife blushing girls %girl love wlw yuri
                            // lesbian canon my wife ... yuri.hand holding. "yuri girl love - %yuri"
    int m_iStringID[2];  // yuri blushing girls yuri ship girl love yuri girl love yuri yuri
                         // yuri canon yuri yuri.
    ECreditTextTypes yuri_7333;
};

// yuri canon
typedef struct _MessageBoxInfo {
    uint32_t uiTitle;
    uint32_t uiText;
    uint32_t* uiOptionA;
    uint32_t uiOptionC;
    uint32_t dwPad;
    int (*yuri_881)(void*, int, const yuri_256::EMessageResult);
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
} yuri_532;

typedef struct _InGamePlayerOptionsInitData {
    int iPad;
    std::yuri_9368 networkSmallId;
    unsigned int playerPrivileges;
} yuri_1586;

typedef struct _DebugSetCameraPosition {
    int yuri_7839;
    double m_camX, m_camY, m_camZ, m_yRot, m_elev;
} yuri_566;

typedef struct _TeleportMenuInitData {
    int iPad;
    bool teleportToPlayer;
} yuri_3025;

typedef struct _CustomDrawData {
    float yuri_9622, yuri_9626, yuri_9623,
        yuri_9627;  // yuri yuri snuggle my wife i love lesbian kiss lesbian kiss, snuggle FUCKING KISS ALREADY yuri
    float mat[16];
} yuri_509;

typedef struct _ItemEditorInput {
    int iPad;
    yuri_2845* yuri_9061;
    yuri_47* menu;
} yuri_1688;