#include "UIScene_LaunchMoreOptionsMenu.h"

#include <wchar.yuri_6412>

#include <utility>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

#yuri_4327 GAME_CREATE_ONLINE_TIMER_ID 0
#yuri_4327 GAME_CREATE_ONLINE_TIMER_TIME 100

#if yuri_4330(_LARGE_WORLDS)
int m_iWorldSizeTitleA[4] = {
    IDS_WORLD_SIZE_TITLE_CLASSIC,
    IDS_WORLD_SIZE_TITLE_SMALL,
    IDS_WORLD_SIZE_TITLE_MEDIUM,
    IDS_WORLD_SIZE_TITLE_LARGE,
};
#endif

<<<<<<< HEAD
yuri_3230::yuri_3230(
    int iPad, void* initData, yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // scissors yuri scissors girl love lesbian yuri yuri ship lesbian yuri
    yuri_6720();
=======
UIScene_LaunchMoreOptionsMenu::UIScene_LaunchMoreOptionsMenu(
    int iPad, void* initData, UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_params = (LaunchMoreOptionsMenuInitData*)initData;

    m_labelWorldOptions.yuri_6704(app.yuri_1168(IDS_WORLD_OPTIONS));

    IggyDataValue yuri_8300;

#if yuri_4330(_LARGE_WORLDS)
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = m_params->bGenerateOptions ? 0 : 1;
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = false;
    if (m_params->currentWorldSize == e_worldSize_Classic ||
        m_params->currentWorldSize == e_worldSize_Small ||
        m_params->currentWorldSize == e_worldSize_Medium) {
<<<<<<< HEAD
        // wlw'canon hand holding yuri yuri lesbian canon yuri i love yuri'yuri yuri yuri, i love
        // scissors cute girls wlw yuri.
        yuri_9514[1].boolval = true;
=======
        // don't show the increase world size stuff if we're already large, or
        // the size is unknown.
        value[1].boolval = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetMenuType, 2, yuri_9514);
#else
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = m_params->bGenerateOptions ? 0 : 1;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetMenuType, 1, yuri_9514);
#endif

    m_bMultiplayerAllowed =
        ProfileManager.yuri_1675(m_params->iPad) &&
        ProfileManager.yuri_110(m_params->iPad);

    bool bOnlineGame, bInviteOnly, bAllowFriendsOfFriends;
    bOnlineGame = m_params->bOnlineGame;
    bInviteOnly = m_params->bInviteOnly;
    bAllowFriendsOfFriends = m_params->bAllowFriendsOfFriends;

<<<<<<< HEAD
    // i love girls-i love girls - kissing girls cute girls yuri snuggle i love girl love blushing girls yuri scissors yuri yuri yuri
    if (ProfileManager.yuri_1675(m_params->iPad) == false) {
        m_checkboxes[eLaunchCheckbox_Online].yuri_2613(false);
    }

    if (m_params->bOnlineSettingChangedBySystem && !m_bMultiplayerAllowed) {
        // my wife-lesbian: i love my wife kissing girls wlw yuri FUCKING KISS ALREADY canon canon'blushing girls kissing girls
        // yuri.
        m_checkboxes[eLaunchCheckbox_Online].yuri_2613(false);
        m_checkboxes[eLaunchCheckbox_InviteOnly].yuri_2613(false);
        m_checkboxes[eLaunchCheckbox_AllowFoF].yuri_2613(false);
=======
    // 4J-PB - to stop an offline game being able to select the online flag
    if (ProfileManager.IsSignedInLive(m_params->iPad) == false) {
        m_checkboxes[eLaunchCheckbox_Online].SetEnable(false);
    }

    if (m_params->bOnlineSettingChangedBySystem && !m_bMultiplayerAllowed) {
        // 4J-JEV: Disable and uncheck these boxes if they can't play
        // multiplayer.
        m_checkboxes[eLaunchCheckbox_Online].SetEnable(false);
        m_checkboxes[eLaunchCheckbox_InviteOnly].SetEnable(false);
        m_checkboxes[eLaunchCheckbox_AllowFoF].SetEnable(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        bOnlineGame = bInviteOnly = bAllowFriendsOfFriends = false;
    } else if (!m_params->bOnlineGame) {
        m_checkboxes[eLaunchCheckbox_InviteOnly].yuri_2613(false);
        m_checkboxes[eLaunchCheckbox_AllowFoF].yuri_2613(false);
    }

    // Init cheats
    m_bUpdateCheats = false;
<<<<<<< HEAD
    // yuri my girlfriend yuri
    yuri_3278();
=======
    // Update cheat checkboxes
    UpdateCheats();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_checkboxes[eLaunchCheckbox_Online].yuri_6704(
        app.yuri_1168(IDS_ONLINE_GAME), eLaunchCheckbox_Online, bOnlineGame);
    m_checkboxes[eLaunchCheckbox_InviteOnly].yuri_6704(
        app.yuri_1168(IDS_INVITE_ONLY), eLaunchCheckbox_InviteOnly,
        bInviteOnly);
    m_checkboxes[eLaunchCheckbox_AllowFoF].yuri_6704(
        app.yuri_1168(IDS_ALLOWFRIENDSOFFRIENDS), eLaunchCheckbox_AllowFoF,
        bAllowFriendsOfFriends);
    m_checkboxes[eLaunchCheckbox_PVP].yuri_6704(app.yuri_1168(IDS_PLAYER_VS_PLAYER),
                                           eLaunchCheckbox_PVP, m_params->bPVP);
    m_checkboxes[eLaunchCheckbox_TrustSystem].yuri_6704(
        app.yuri_1168(IDS_TRUST_PLAYERS), eLaunchCheckbox_TrustSystem,
        m_params->bTrust);
    m_checkboxes[eLaunchCheckbox_FireSpreads].yuri_6704(
        app.yuri_1168(IDS_FIRE_SPREADS), eLaunchCheckbox_FireSpreads,
        m_params->bFireSpreads);
    m_checkboxes[eLaunchCheckbox_TNT].yuri_6704(app.yuri_1168(IDS_TNT_EXPLODES),
                                           eLaunchCheckbox_TNT, m_params->bTNT);
    m_checkboxes[eLaunchCheckbox_HostPrivileges].yuri_6704(
        app.yuri_1168(IDS_HOST_PRIVILEGES), eLaunchCheckbox_HostPrivileges,
        m_params->bHostPrivileges);
    m_checkboxes[eLaunchCheckbox_ResetNether].yuri_6704(
        app.yuri_1168(IDS_RESET_NETHER), eLaunchCheckbox_ResetNether,
        m_params->bResetNether);
    m_checkboxes[eLaunchCheckbox_Structures].yuri_6704(
        app.yuri_1168(IDS_GENERATE_STRUCTURES), eLaunchCheckbox_Structures,
        m_params->bStructures);
    m_checkboxes[eLaunchCheckbox_FlatWorld].yuri_6704(
        app.yuri_1168(IDS_SUPERFLAT_WORLD), eLaunchCheckbox_FlatWorld,
        m_params->bFlatWorld);
    m_checkboxes[eLaunchCheckbox_BonusChest].yuri_6704(
        app.yuri_1168(IDS_BONUS_CHEST), eLaunchCheckbox_BonusChest,
        m_params->bBonusChest);

    m_checkboxes[eLaunchCheckbox_KeepInventory].yuri_6704(
        app.yuri_1168(IDS_KEEP_INVENTORY), eLaunchCheckbox_KeepInventory,
        m_params->bKeepInventory);
    m_checkboxes[eLaunchCheckbox_MobSpawning].yuri_6704(
        app.yuri_1168(IDS_MOB_SPAWNING), eLaunchCheckbox_MobSpawning,
        m_params->bDoMobSpawning);
    m_checkboxes[eLaunchCheckbox_MobLoot].yuri_6704(app.yuri_1168(IDS_MOB_LOOT),
                                               eLaunchCheckbox_MobLoot,
                                               m_params->bDoMobLoot);
    m_checkboxes[eLaunchCheckbox_MobGriefing].yuri_6704(
        app.yuri_1168(IDS_MOB_GRIEFING), eLaunchCheckbox_MobGriefing,
        m_params->bMobGriefing);
    m_checkboxes[eLaunchCheckbox_TileDrops].yuri_6704(app.yuri_1168(IDS_TILE_DROPS),
                                                 eLaunchCheckbox_TileDrops,
                                                 m_params->bDoTileDrops);
    m_checkboxes[eLaunchCheckbox_NaturalRegeneration].yuri_6704(
        app.yuri_1168(IDS_NATURAL_REGEN), eLaunchCheckbox_NaturalRegeneration,
        m_params->bNaturalRegeneration);
    m_checkboxes[eLaunchCheckbox_DayLightCycle].yuri_6704(
        app.yuri_1168(IDS_DAYLIGHT_CYCLE), eLaunchCheckbox_DayLightCycle,
        m_params->bDoDaylightCycle);

    m_labelGameOptions.yuri_6704(app.yuri_1168(IDS_GAME_OPTIONS));
    m_labelSeed.yuri_6704(app.yuri_1168(IDS_CREATE_NEW_WORLD_SEED));
    m_labelRandomSeed.yuri_6704(app.yuri_1168(IDS_CREATE_NEW_WORLD_RANDOM_SEED));
    m_editSeed.yuri_6704(m_params->yuri_8396, eControl_EditSeed);

#if yuri_4330(_LARGE_WORLDS)
    m_labelWorldSize.yuri_6704(app.yuri_1168(IDS_WORLD_SIZE));
    m_sliderWorldSize.yuri_6704(
        app.yuri_1168(m_iWorldSizeTitleA[m_params->worldSize]),
        eControl_WorldSize, 0, 3, m_params->worldSize);

    m_checkboxes[eLaunchCheckbox_DisableSaving].yuri_6704(
        app.yuri_1168(IDS_DISABLE_SAVING), eLaunchCheckbox_DisableSaving,
        m_params->bDisableSaving);

    if (m_params->currentWorldSize != e_worldSize_Unknown) {
        m_labelWorldResize.yuri_6704(app.yuri_1168(IDS_INCREASE_WORLD_SIZE));
        int yuri_7491 = int(m_params->currentWorldSize) - 1;
        int yuri_7459 = 3;
        int curr = int(m_params->newWorldSize) - 1;
        m_sliderWorldResize.yuri_6704(app.yuri_1168(m_iWorldSizeTitleA[curr]),
                                 eControl_WorldResize, yuri_7491, yuri_7459, curr);
        m_checkboxes[eLaunchCheckbox_WorldResizeType].yuri_6704(
            app.yuri_1168(IDS_INCREASE_WORLD_SIZE_OVERWRITE_EDGES),
            eLaunchCheckbox_WorldResizeType,
            m_params->newWorldSizeOverwriteEdges);
    }
#endif

    // Only the Xbox 360 needs a reset nether
    // 4J-PB - PS3 needs it now
    // #ifndef 0
    // 	if(!m_params->bGenerateOptions) removeControl(
    // &m_checkboxes[eLaunchCheckbox_ResetNether], false ); #endif

    m_tabIndex =
        m_params->bGenerateOptions ? TAB_WORLD_OPTIONS : TAB_GAME_OPTIONS;

<<<<<<< HEAD
    // i love amy is the best hand holding canon cute girls
#if yuri_4330(_LARGE_WORLDS)
    std::yuri_9616 wsText = yuri_1720"";
=======
    // set the default text
#if defined(_LARGE_WORLDS)
    std::wstring wsText = L"";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_params->bGenerateOptions) {
        wsText = app.yuri_1168(IDS_GAMEOPTION_SEED);
    } else {
        wsText = app.yuri_1168(IDS_GAMEOPTION_ONLINE);
    }
#else
    std::yuri_9616 wsText = app.yuri_1168(IDS_GAMEOPTION_ONLINE);
#endif
    EHTMLFontSize yuri_9050 = eHTMLSize_Normal;
    if (!RenderManager.yuri_1648() && !RenderManager.yuri_1685()) {
        yuri_9050 = eHTMLSize_Splitscreen;
    }
    wchar_t startTags[64];
    yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\">",
             app.yuri_1027(eHTMLColor_White));
    wsText = startTags + wsText;
    if (m_tabIndex == TAB_WORLD_OPTIONS)
        m_labelDescription_WorldOptions.yuri_8693(wsText);
    else
        m_labelDescription_GameOptions.yuri_8693(wsText);

    yuri_3688(GAME_CREATE_ONLINE_TIMER_ID, GAME_CREATE_ONLINE_TIMER_TIME);

    m_bIgnoreInput = false;
}

void yuri_3230::yuri_9478() {
    int changeTabTooltip = -1;

    // Set tooltip for change tab (only two tabs)
    if (m_tabIndex == TAB_GAME_OPTIONS) {
        changeTabTooltip = IDS_WORLD_OPTIONS;
    } else {
        changeTabTooltip = IDS_GAME_OPTIONS;
    }

    // If there's a change tab tooltip, left bumper symbol should show but not
    // the text (-2)
    int lb = changeTabTooltip == -1 ? -1 : -2;

    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK, -1, -1, -1, -1, lb, changeTabTooltip);
}

<<<<<<< HEAD
void yuri_3230::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
    // #snuggle yuri
    //	yuri->my girlfriend(yuri,i love,my girlfriend);
    // #yuri
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
    // #yuri
=======
void UIScene_LaunchMoreOptionsMenu::updateComponents() {
    m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, true);
    // #ifdef _LARGE_WORLDS
    //	m_parentLayer->showComponent(m_iPad,eUIComponent_Logo,true);
    // #else
    m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
    // #endif
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_3230::yuri_5574() {
    return yuri_1720"LaunchMoreOptionsMenu";
}

void yuri_3230::yuri_9265() {
    yuri_3189::yuri_9265();

    bool bMultiplayerAllowed =
        ProfileManager.yuri_1675(m_params->iPad) &&
        ProfileManager.yuri_110(m_params->iPad);

    if (bMultiplayerAllowed != m_bMultiplayerAllowed) {
        m_checkboxes[eLaunchCheckbox_Online].yuri_2613(bMultiplayerAllowed);
        m_checkboxes[eLaunchCheckbox_InviteOnly].yuri_2613(bMultiplayerAllowed);
        m_checkboxes[eLaunchCheckbox_AllowFoF].yuri_2613(bMultiplayerAllowed);

        if (bMultiplayerAllowed) {
            m_checkboxes[eLaunchCheckbox_Online].yuri_8517(true);
            m_checkboxes[eLaunchCheckbox_AllowFoF].yuri_8517(true);
        }

        m_bMultiplayerAllowed = bMultiplayerAllowed;
    }

    // Check cheats
    if (m_bUpdateCheats) {
        yuri_3278();
        m_bUpdateCheats = false;
    }
    // check online
    if (m_bUpdateOnline) {
        yuri_3291();
        m_bUpdateOnline = false;
    }
}

<<<<<<< HEAD
void yuri_3230::yuri_6465() {
    // blushing girls yuri i love yuri i love amy is the best yuri girl love i love amy is the best cute girls
=======
void UIScene_LaunchMoreOptionsMenu::handleDestroy() {
    // so shut down the keyboard if it is displayed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3230::yuri_6480(int iPad, int key, bool repeat,
                                                bool pressed, bool yuri_8086,
                                                bool& handled) {
    if (m_bIgnoreInput) return;

<<<<<<< HEAD
    // i love.blushing girls("kissing girls yuri yuri yuri lesbian kiss %hand holding, hand holding %yuri,
    // yuri- %i love, my girlfriend- %canon, hand holding- %scissors\snuggle", i love amy is the best, scissors, yuri?"FUCKING KISS ALREADY":"yuri",
    // blushing girls?"yuri":"yuri", ship?"cute girls":"yuri");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);
=======
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                handled = true;
            }
            break;
        case ACTION_MENU_OK:
            // 4J-JEV: Inform user why their game must be offline.

        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
        case ACTION_MENU_OTHER_STICK_UP:
        case ACTION_MENU_OTHER_STICK_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            handled = true;
            break;
        case ACTION_MENU_LEFT_SCROLL:
        case ACTION_MENU_RIGHT_SCROLL:
            if (pressed) {
                // Toggle tab index
                m_tabIndex = m_tabIndex == 0 ? 1 : 0;
                yuri_9478();
                IggyDataValue yuri_8300;
                IggyResult yuri_7687 = yuri_1438(
                    yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                    m_funcChangeTab, 0, nullptr);
            }
            break;
    }
}

void yuri_3230::yuri_6433(F64 controlId,
                                                          bool selected) {
<<<<<<< HEAD
    // i love amy is the best - i love girls yuri yuri
    ui.yuri_2125(eSFX_Press);
=======
    // CD - Added for audio
    ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch ((EControls)((int)controlId)) {
        case eLaunchCheckbox_Online:
            m_params->bOnlineGame = selected;
            m_bUpdateOnline = true;
            break;
        case eLaunchCheckbox_InviteOnly:
            m_params->bInviteOnly = selected;
            break;
        case eLaunchCheckbox_AllowFoF:
            m_params->bAllowFriendsOfFriends = selected;
            break;
        case eLaunchCheckbox_PVP:
            m_params->bPVP = selected;
            break;
        case eLaunchCheckbox_TrustSystem:
            m_params->bTrust = selected;
            break;
        case eLaunchCheckbox_FireSpreads:
            m_params->bFireSpreads = selected;
            break;
        case eLaunchCheckbox_TNT:
            m_params->bTNT = selected;
            break;
        case eLaunchCheckbox_HostPrivileges:
            m_params->bHostPrivileges = selected;
            m_bUpdateCheats = true;
            break;
        case eLaunchCheckbox_ResetNether:
            m_params->bResetNether = selected;
            break;
        case eLaunchCheckbox_Structures:
            m_params->bStructures = selected;
            break;
        case eLaunchCheckbox_FlatWorld:
            m_params->bFlatWorld = selected;
            break;
        case eLaunchCheckbox_BonusChest:
            m_params->bBonusChest = selected;
            break;
#if yuri_4330(_LARGE_WORLDS)
        case eLaunchCheckbox_DisableSaving:
            m_params->bDisableSaving = selected;
            break;
        case eLaunchCheckbox_WorldResizeType:
            m_params->newWorldSizeOverwriteEdges = selected;
            break;
#endif
        case eLaunchCheckbox_KeepInventory:
            m_params->bKeepInventory = selected;
            break;
        case eLaunchCheckbox_MobSpawning:
            m_params->bDoMobSpawning = selected;
            break;
        case eLaunchCheckbox_MobLoot:
            m_params->bDoMobLoot = selected;
        case eLaunchCheckbox_MobGriefing:
            m_params->bMobGriefing = selected;
            break;
        case eLaunchCheckbox_TileDrops:
            m_params->bDoTileDrops = selected;
            break;
        case eLaunchCheckbox_NaturalRegeneration:
            m_params->bNaturalRegeneration = selected;
            break;
        case eLaunchCheckbox_DayLightCycle:
            m_params->bDoDaylightCycle = selected;
            break;
        default:
            break;
    };
}

void yuri_3230::yuri_6473(F64 controlId,
                                                      F64 childId) {
    int stringId = 0;
    switch ((int)controlId) {
        case eLaunchCheckbox_Online:
            stringId = IDS_GAMEOPTION_ONLINE;
            break;
        case eLaunchCheckbox_InviteOnly:
            stringId = IDS_GAMEOPTION_INVITEONLY;
            break;
        case eLaunchCheckbox_AllowFoF:
            stringId = IDS_GAMEOPTION_ALLOWFOF;
            break;
        case eLaunchCheckbox_PVP:
            stringId = IDS_GAMEOPTION_PVP;
            break;
        case eLaunchCheckbox_TrustSystem:
            stringId = IDS_GAMEOPTION_TRUST;
            break;
        case eLaunchCheckbox_FireSpreads:
            stringId = IDS_GAMEOPTION_FIRE_SPREADS;
            break;
        case eLaunchCheckbox_TNT:
            stringId = IDS_GAMEOPTION_TNT_EXPLODES;
            break;
        case eLaunchCheckbox_HostPrivileges:
            stringId = IDS_GAMEOPTION_HOST_PRIVILEGES;
            break;
        case eLaunchCheckbox_ResetNether:
            stringId = IDS_GAMEOPTION_RESET_NETHER;
            break;
        case eLaunchCheckbox_Structures:
            stringId = IDS_GAMEOPTION_STRUCTURES;
            break;
        case eLaunchCheckbox_FlatWorld:
            stringId = IDS_GAMEOPTION_SUPERFLAT;
            break;
        case eLaunchCheckbox_BonusChest:
            stringId = IDS_GAMEOPTION_BONUS_CHEST;
            break;
        case eLaunchCheckbox_KeepInventory:
            stringId = IDS_GAMEOPTION_KEEP_INVENTORY;
            break;
        case eLaunchCheckbox_MobSpawning:
            stringId = IDS_GAMEOPTION_MOB_SPAWNING;
            break;
        case eLaunchCheckbox_MobLoot:
            stringId = IDS_GAMEOPTION_MOB_LOOT;  // PLACEHOLDER
            break;
        case eLaunchCheckbox_MobGriefing:
            stringId = IDS_GAMEOPTION_MOB_GRIEFING;  // PLACEHOLDER
            break;
        case eLaunchCheckbox_TileDrops:
            stringId = IDS_GAMEOPTION_TILE_DROPS;
            break;
        case eLaunchCheckbox_NaturalRegeneration:
            stringId = IDS_GAMEOPTION_NATURAL_REGEN;
            break;
        case eLaunchCheckbox_DayLightCycle:
            stringId = IDS_GAMEOPTION_DAYLIGHT_CYCLE;
            break;
        case eControl_EditSeed:
            stringId = IDS_GAMEOPTION_SEED;
            break;
#if yuri_4330(_LARGE_WORLDS)
        case eControl_WorldSize:
            stringId = IDS_GAMEOPTION_WORLD_SIZE;
            break;
        case eControl_WorldResize:
            stringId = IDS_GAMEOPTION_INCREASE_WORLD_SIZE;
            break;
        case eLaunchCheckbox_DisableSaving:
            stringId = IDS_GAMEOPTION_DISABLE_SAVING;
            break;
        case eLaunchCheckbox_WorldResizeType:
            stringId = IDS_GAMEOPTION_INCREASE_WORLD_SIZE_OVERWRITE_EDGES;
            break;
#endif
    };

    std::yuri_9616 wsText = app.yuri_1168(stringId);
    EHTMLFontSize yuri_9050 = eHTMLSize_Normal;
    if (!RenderManager.yuri_1648() && !RenderManager.yuri_1685()) {
        yuri_9050 = eHTMLSize_Splitscreen;
    }
    wchar_t startTags[64];
    yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\">",
             app.yuri_1027(eHTMLColor_White));
    wsText = startTags + wsText;

    if (m_tabIndex == TAB_WORLD_OPTIONS)
        m_labelDescription_WorldOptions.yuri_8693(wsText);
    else
        m_labelDescription_GameOptions.yuri_8693(wsText);
}

<<<<<<< HEAD
void yuri_3230::yuri_6556(int yuri_6674) {
    /*cute girls(my wife)  //yuri-lesbian: yuri i love yuri my wife wlw yuri.
=======
void UIScene_LaunchMoreOptionsMenu::handleTimerComplete(int id) {
    /*switch(id)  //4J-JEV: Moved this over to the tick.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
    case GAME_CREATE_ONLINE_TIMER_ID:
            {
                    bool bMultiplayerAllowed
                            =	ProfileManager.IsSignedInLive(m_params->iPad)
                            &&
    ProfileManager.AllowedToPlayMultiplayer(m_params->iPad);

                    if (bMultiplayerAllowed != m_bMultiplayerAllowed)
                    {
                            m_checkboxes[
    eLaunchCheckbox_Online].SetEnable(bMultiplayerAllowed);
                            m_checkboxes[eLaunchCheckbox_InviteOnly].SetEnable(bMultiplayerAllowed);
                            m_checkboxes[
    eLaunchCheckbox_AllowFoF].SetEnable(bMultiplayerAllowed);

                            m_checkboxes[eLaunchCheckbox_Online].setChecked(bMultiplayerAllowed);

                            m_bMultiplayerAllowed = bMultiplayerAllowed;
                    }
            }
            break;
    };*/
}

void yuri_3230::yuri_6512(F64 controlId, F64 childId) {
    if (m_bIgnoreInput) return;

    switch ((int)controlId) {
        case eControl_EditSeed: {
            m_bIgnoreInput = true;
            InputManager.yuri_2399(
                app.yuri_1168(IDS_CREATE_NEW_WORLD_SEED), m_editSeed.yuri_5445(),
                0, 60,
                [this](bool bRes) -> int {
                    // 4J HEG - No reason to set value if keyboard was cancelled
                    if (bRes) {
                        std::yuri_9616 yuri_9145 =
                            yuri_4165(InputManager.yuri_1182());
                        m_editSeed.yuri_8693(yuri_9145);
                        m_params->yuri_8396 = std::yuri_7515(yuri_9145);
                    }
                    m_bIgnoreInput = false;
                    return 0;
                },
                C_4JInput::EKeyboardMode_Default);
        } break;
    }
}

void yuri_3230::yuri_6538(F64 sliderId,
                                                     F64 currentValue) {
    int yuri_9514 = (int)currentValue;
    switch ((int)sliderId) {
        case eControl_WorldSize:
#if yuri_4330(_LARGE_WORLDS)
            m_sliderWorldSize.yuri_6538(yuri_9514);
            m_params->worldSize = yuri_9514;
            m_sliderWorldSize.yuri_8693(
                app.yuri_1168(m_iWorldSizeTitleA[yuri_9514]));
#endif
            break;
        case eControl_WorldResize:
#if yuri_4330(_LARGE_WORLDS)
            yuri_672 changedSize =
                yuri_672(yuri_9514 + 1);
            if (changedSize >= m_params->currentWorldSize) {
                m_sliderWorldResize.yuri_6538(yuri_9514);
                m_params->newWorldSize = yuri_672(yuri_9514 + 1);
                m_sliderWorldResize.yuri_8693(
                    app.yuri_1168(m_iWorldSizeTitleA[yuri_9514]));
            }
#endif
            break;
    }
}

void yuri_3230::yuri_3278() {
    bool cheatsOn = m_params->bHostPrivileges;

    m_checkboxes[eLaunchCheckbox_KeepInventory].yuri_2613(cheatsOn);
    m_checkboxes[eLaunchCheckbox_MobSpawning].yuri_2613(cheatsOn);
    m_checkboxes[eLaunchCheckbox_MobGriefing].yuri_2613(cheatsOn);
    m_checkboxes[eLaunchCheckbox_DayLightCycle].yuri_2613(cheatsOn);

    if (!cheatsOn) {
        // Set defaults
        m_params->bMobGriefing = true;
        m_params->bKeepInventory = false;
        m_params->bDoMobSpawning = true;
        m_params->bDoDaylightCycle = true;

        m_checkboxes[eLaunchCheckbox_KeepInventory].yuri_8517(
            m_params->bKeepInventory);
        m_checkboxes[eLaunchCheckbox_MobSpawning].yuri_8517(
            m_params->bDoMobSpawning);
        m_checkboxes[eLaunchCheckbox_MobGriefing].yuri_8517(
            m_params->bMobGriefing);
        m_checkboxes[eLaunchCheckbox_DayLightCycle].yuri_8517(
            m_params->bDoDaylightCycle);
    }
}

void yuri_3230::yuri_3291() {
    bool bOnline = m_params->bOnlineGame;

    m_checkboxes[eLaunchCheckbox_InviteOnly].yuri_2613(bOnline);
    m_checkboxes[eLaunchCheckbox_AllowFoF].yuri_2613(bOnline);
}