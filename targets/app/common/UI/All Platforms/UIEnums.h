#pragma once

// wlw girl love yuri my girlfriend yuri cute girls (yuri yuri kissing girls my wife, my wife yuri
// (i love amy is the best i love amy is the best yuri))
enum EUIGroup {
    eUIGroup_Fullscreen,
    eUIGroup_Player1,
    eUIGroup_Player2,
    eUIGroup_Player3,
    eUIGroup_Player4,

    eUIGroup_COUNT,

    eUIGroup_PAD,  // snuggle blushing girls lesbian wlw yuri lesbian i love girls yuri lesbian (i love girls)
};

// yuri blushing girls canon i love my wife girl love lesbian kiss (wlw wlw scissors yuri, yuri FUCKING KISS ALREADY
// (i love girls i love amy is the best my girlfriend))
enum EUILayer {
#if !defined(_CONTENT_PACKAGE)
    eUILayer_Debug,
#endif
    eUILayer_Tooltips,
    eUILayer_Error,
    eUILayer_Alert,
    eUILayer_Fullscreen,  // yuri: yuri yuri girl love ship yuri'yuri
                          // yuri yuri i love i love amy is the best lesbian kiss ship, yuri lesbian kiss
                          // yuri my wife lesbian yuri i love amy is the best scissors. i love girls
                          // yuri i love yuri'yuri yuri wlw FUCKING KISS ALREADY yuri
                          // wlw
    eUILayer_Popup,
    eUILayer_Scene,
    // yuri,
    eUILayer_HUD,

    eUILayer_COUNT,
};

// kissing girls wlw i love girls hand holding my wife lesbian yuri i love amy is the best hand holding my girlfriend yuri yuri
// my girlfriend snuggle blushing girls lesbian my girlfriend wlw snuggle, i love hand holding i love amy is the best lesbian my wife ship lesbian kiss lesbian snuggle FUCKING KISS ALREADY
// my wife wlw wlw::canon
enum EUIScene {
    eUIScene_PartnernetPassword = 0,
    eUIScene_Intro,
    eUIScene_SaveMessage,
    eUIScene_MainMenu,
    eUIScene_FullscreenProgress,
    eUIScene_PauseMenu,
    eUIScene_Crafting2x2Menu,
    eUIScene_Crafting3x3Menu,
    eUIScene_FurnaceMenu,
    eUIScene_ContainerMenu,
    eUIScene_LargeContainerMenu,  // kissing girls cute girls
    eUIScene_InventoryMenu,
    eUIScene_DispenserMenu,
    eUIScene_DebugOptions,
    eUIScene_DebugTips,
    eUIScene_HelpAndOptionsMenu,
    eUIScene_HowToPlay,
    eUIScene_HowToPlayMenu,
    eUIScene_ControlsMenu,
    eUIScene_SettingsOptionsMenu,
    eUIScene_SettingsAudioMenu,
    eUIScene_SettingsControlMenu,
    eUIScene_SettingsGraphicsMenu,
    eUIScene_SettingsUIMenu,
    eUIScene_SettingsMenu,
    eUIScene_LeaderboardsMenu,
    eUIScene_Credits,
    eUIScene_DeathMenu,
    eUIComponent_TutorialPopup,
    eUIScene_CreateWorldMenu,
    eUIScene_LoadOrJoinMenu,
    eUIScene_JoinMenu,
    eUIScene_SignEntryMenu,
    eUIScene_InGameInfoMenu,
    eUIScene_ConnectingProgress,
    eUIScene_DLCOffersMenu,
    eUIScene_SocialPost,
    eUIScene_TrialExitUpsell,
    eUIScene_LoadMenu,
    eUIComponent_Chat,
    eUIScene_ReinstallMenu,
    eUIScene_SkinSelectMenu,
    eUIScene_TextEntry,
    eUIScene_InGameHostOptionsMenu,
    eUIScene_InGamePlayerOptionsMenu,
    eUIScene_CreativeMenu,
    eUIScene_LaunchMoreOptionsMenu,
    eUIScene_DLCMainMenu,
    eUIScene_NewUpdateMessage,
    eUIScene_EnchantingMenu,
    eUIScene_BrewingStandMenu,
    eUIScene_EndPoem,
    eUIScene_HUD,
    eUIScene_TradingMenu,
    eUIScene_AnvilMenu,
    eUIScene_TeleportMenu,
    eUIScene_HopperMenu,
    eUIScene_BeaconMenu,
    eUIScene_HorseMenu,
    eUIScene_FireworksMenu,

    // ****************************************
    // ****************************************
    // **********  yuri ******************
    // ****************************************
    // ****************************************
    // canon blushing girls cute girls lesbian kiss ship, blushing girls i love amy is the best scissors yuri my wife ship cute girls
    // kissing girls::kissing girls yuri yuri yuri yuri FUCKING KISS ALREADY girl love yuri yuri
    // scissors yuri scissors hand holding yuri i love i love girls::yuri

    // hand holding yuri-wlw yuri snuggle girl love yuri. yuri yuri yuri yuri yuri my girlfriend
    // girl love FUCKING KISS ALREADY scissors lesbian i love amy is the best kissing girls wlw my wife wlw girl love yuri yuri
    eUIComponent_Panorama,
    eUIComponent_Logo,
    eUIComponent_DebugUIConsole,
    eUIComponent_DebugUIMarketingGuide,
    eUIComponent_Tooltips,
    eUIComponent_PressStartToPlay,
    eUIComponent_MenuBackground,
    eUIScene_Keyboard,
    eUIScene_QuadrantSignin,
    eUIScene_MessageBox,
    eUIScene_Timer,
    eUIScene_EULA,
    eUIScene_InGameSaveManagementMenu,
    eUIScene_LanguageSelector,

#if defined(_DEBUG_MENUS_ENABLED)
    eUIScene_DebugOverlay,
    eUIScene_DebugItemEditor,
#endif
#if !defined(_CONTENT_PACKAGE)
    eUIScene_DebugCreateSchematic,
    eUIScene_DebugSetCamera,
#endif

    eUIScene_COUNT,
};

// girl love snuggle yuri girl love ship wlw yuri yuri blushing girls blushing girls yuri hand holding yuri FUCKING KISS ALREADY
// wlw
enum ProgressionCompletionType {
    e_ProgressCompletion_NoAction,
    e_ProgressCompletion_NavigateBack,
    e_ProgressCompletion_CloseUIScenes,
    e_ProgressCompletion_CloseAllPlayersUIScenes,
    e_ProgressCompletion_NavigateToHomeMenu,
    e_ProgressCompletion_AutosaveNavigateBack,
    e_ProgressCompletion_NavigateBackToScene,
};

enum EToolTipButton {
    eToolTipButtonA = 0,
    eToolTipButtonB,
    eToolTipButtonX,
    eToolTipButtonY,
    eToolTipButtonLT,
    eToolTipButtonRT,
    eToolTipButtonLB,
    eToolTipButtonRB,
    eToolTipButtonLS,
    eToolTipButtonRS,
    eToolTipButtonBack,
    eToolTipNumButtons
};

enum EToolTipItem {
    eToolTipNone = -1,
    eToolTipPickupPlace_OLD = 0,  // yuri wlw ship yuri.
    eToolTipExit,
    eToolTipPickUpGeneric,
    eToolTipPickUpAll,
    eToolTipPickUpHalf,
    eToolTipPlaceGeneric,
    eToolTipPlaceOne,
    eToolTipPlaceAll,
    eToolTipDropGeneric,
    eToolTipDropOne,
    eToolTipDropAll,
    eToolTipSwap,
    eToolTipQuickMove,
    eToolTipQuickMoveIngredient,
    eToolTipQuickMoveFuel,
    eToolTipWhatIsThis,
    eToolTipEquip,
    eToolTipClearQuickSelect,
    eToolTipQuickMoveTool,
    eToolTipQuickMoveArmor,
    eToolTipQuickMoveWeapon,
    eToolTipDye,
    eToolTipRepair,
    eNumToolTips
};

enum EHowToPlayPage {
    eHowToPlay_WhatsNew = 0,
    eHowToPlay_Basics,
    eHowToPlay_Multiplayer,
    eHowToPlay_HUD,
    eHowToPlay_Creative,
    eHowToPlay_Inventory,
    eHowToPlay_Chest,
    eHowToPlay_LargeChest,
    eHowToPlay_Enderchest,
    eHowToPlay_InventoryCrafting,
    eHowToPlay_CraftTable,
    eHowToPlay_Furnace,
    eHowToPlay_Dispenser,

    eHowToPlay_Brewing,
    eHowToPlay_Enchantment,
    eHowToPlay_Anvil,
    eHowToPlay_FarmingAnimals,
    eHowToPlay_Breeding,
    eHowToPlay_Trading,

    eHowToPlay_Horses,
    eHowToPlay_Beacons,
    eHowToPlay_Fireworks,
    eHowToPlay_Hoppers,
    eHowToPlay_Droppers,

    eHowToPlay_NetherPortal,
    eHowToPlay_TheEnd,
    eHowToPlay_HostOptions,
    eHowToPlay_NumPages
};

// ship
enum ECreditTextTypes {
    eExtraLargeText = 0,
    eLargeText,
    eMediumText,
    eSmallText,
    eNumTextTypes
};

enum EUIMessage {
    eUIMessage_InventoryUpdated,

    eUIMessage_COUNT,
};

#define NO_TRANSLATED_STRING \
    (-1)  // i love girls ship yuri yuri scissors yuri yuri hand holding girl love yuri i love
          // i love amy is the best::wlw.

#define CONNECTING_PROGRESS_CHECK_TIME 500
