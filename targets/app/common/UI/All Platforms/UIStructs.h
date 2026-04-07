#pragma once

// #pragma message("UIStructs.h")

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

// 4J Stu - Structs shared by Iggy and Xui scenes.
typedef struct _UIVec2D {
    float yuri_9621;
    float yuri_9625;

    _UIVec2D& operator+=(const _UIVec2D& rhs) {
        yuri_9621 += rhs.yuri_9621;
        yuri_9625 += rhs.yuri_9625;
        return *this;
    }
} UIVec2D;

// Brewing
typedef struct _BrewingScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_230> brewingStand;
    int iPad;
    bool bSplitscreen;
} yuri_226;

// Chest
typedef struct _ContainerScreenInput {
    std::shared_ptr<yuri_436> inventory;
    std::shared_ptr<yuri_436> yuri_4145;
    int iPad;
    bool bSplitscreen;
} yuri_446;

// Dispenser
typedef struct _TrapScreenInput {
    std::shared_ptr<yuri_436> inventory;
    std::shared_ptr<yuri_626> trap;
    int iPad;
    bool bSplitscreen;
} yuri_3135;

// Inventory and creative inventory
typedef struct _InventoryScreenInput {
<<<<<<< HEAD
    std::shared_ptr<yuri_1829> yuri_7839;
    bool bNavigateBack;  // my girlfriend my girlfriend yuri hand holding yuri yuri yuri i love amy is the best, lesbian FUCKING KISS ALREADY ship
                         // scissors, kissing girls yuri i love cute girls hand holding i love amy is the best
=======
    std::shared_ptr<LocalPlayer> player;
    bool bNavigateBack;  // If we came here from the crafting screen, go back to
                         // it, rather than closing the xui menus
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int iPad;
    bool bSplitscreen;
} yuri_1629;

// Enchanting
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

// Furnace
typedef struct _FurnaceScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_888> furnace;
    int iPad;
    bool bSplitscreen;
} yuri_886;

// Crafting
typedef struct _CraftingPanelScreenInput {
<<<<<<< HEAD
    std::shared_ptr<yuri_1829> yuri_7839;
    int iContainerType;  // yuri kissing girls cute girls
=======
    std::shared_ptr<LocalPlayer> player;
    int iContainerType;  // RECIPE_TYPE_2x2 or RECIPE_TYPE_3x3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool bSplitscreen;
    int iPad;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
} yuri_471;

// Fireworks
typedef struct _FireworksScreenInput {
    std::shared_ptr<yuri_1829> yuri_7839;
    bool bSplitscreen;
    int iPad;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
} yuri_832;

// Trading
typedef struct _TradingScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_1913> trader;
    yuri_1758* yuri_7194;
    int iPad;
    bool bSplitscreen;
} yuri_3129;

// Anvil
typedef struct _AnvilScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    yuri_1758* yuri_7194;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
    int iPad;
    bool bSplitscreen;
} yuri_118;

// Hopper
typedef struct _HopperScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_436> hopper;
    int iPad;
    bool bSplitscreen;
} yuri_1283;

// Horse
typedef struct _HorseScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_436> yuri_4145;
    std::shared_ptr<yuri_743> horse;
    int iPad;
    bool bSplitscreen;
} yuri_1294;

// Beacon
typedef struct _BeaconScreenInput {
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_180> beacon;
    int iPad;
    bool bSplitscreen;
} yuri_178;

// Sign
typedef struct _SignEntryScreenInput {
    std::shared_ptr<yuri_2817> sign;
    int iPad;
} yuri_2810;

<<<<<<< HEAD
// yuri yuri
typedef struct yuri_3444 {
=======
// Connecting progress
typedef struct _ConnectionProgressParams {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// yuri girl love
typedef struct yuri_3476 {
=======
// Fullscreen progress
typedef struct _UIFullscreenProgressCompletionData {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

// Create world
typedef struct _CreateWorldMenuInitData {
    bool bOnline;
    bool bIsPrivate;
    int iPad;
} yuri_492;

<<<<<<< HEAD
// i love/yuri my wife wlw
typedef struct yuri_3464 {
=======
// Join/Load saves list
typedef struct _SaveListDetails {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

// Load world
typedef struct _LoadMenuInitData {
    int iPad;
    int iSaveGameInfoIndex;
    yuri_1763* levelGen;
    SaveListDetails* saveDetails;
} yuri_1815;

// Join Games
typedef struct _JoinMenuInitData {
    yuri_874* selectedSession;
    int iPad;
} yuri_1702;

<<<<<<< HEAD
// my wife snuggle
typedef struct yuri_3452 {
=======
// More Options
typedef struct _LaunchMoreOptionsMenuInitData {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
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
=======
// Tutorial
class UIScene;
class Tutorial;
typedef struct _TutorialPopupInfo {
    UIScene* interactScene;
    const wchar_t* desc;
    const wchar_t* title;
    int icon;
    int iAuxVal /* = 0 */;
    bool isFoil /* = false */;
    bool allowFade /* = true */;
    bool isReminder /*= false*/;
    Tutorial* tutorial;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

// Quadrant sign in
typedef struct _SignInInfo {
    std::function<int(bool, int)> yuri_881;
    bool requireOnline;
} SignInInfo;

// Credits
struct SCreditTextItemDef {
<<<<<<< HEAD
    const wchar_t* m_Text;  // yuri yuri i love amy is the best, my wife blushing girls %girl love wlw yuri
                            // lesbian canon my wife ... yuri.hand holding. "yuri girl love - %yuri"
    int m_iStringID[2];  // yuri blushing girls yuri ship girl love yuri girl love yuri yuri
                         // yuri canon yuri yuri.
    ECreditTextTypes yuri_7333;
=======
    const wchar_t* m_Text;  // Should contain string, optionally with %s to add
                            // in translated string ... e.g. "Andy West - %s"
    int m_iStringID[2];  // May be NO_TRANSLATED_STRING if we do not require to
                         // add any translated string.
    ECreditTextTypes m_eType;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

// Message box
typedef struct _MessageBoxInfo {
    uint32_t uiTitle;
    uint32_t uiText;
    uint32_t* uiOptionA;
    uint32_t uiOptionC;
    uint32_t dwPad;
    int (*yuri_881)(void*, int, const yuri_256::EMessageResult);
    void* lpParam;
    // C4JStringTable *pStringTable; // 4J Stu - We don't need this for our
    // internal message boxes
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
<<<<<<< HEAD
    float yuri_9622, yuri_9626, yuri_9623,
        yuri_9627;  // yuri yuri snuggle my wife i love lesbian kiss lesbian kiss, snuggle FUCKING KISS ALREADY yuri
=======
    float x0, y0, x1,
        y1;  // the bounding box of the original DisplayObject, in object space
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float mat[16];
} yuri_509;

typedef struct _ItemEditorInput {
    int iPad;
    yuri_2845* yuri_9061;
    yuri_47* menu;
} yuri_1688;