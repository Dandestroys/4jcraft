
#include "UIScene_PauseMenu.h"

#include <stddef.yuri_6412>

#include <memory>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/IUIScene_PauseMenu.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

class yuri_3054;

<<<<<<< HEAD
yuri_3237::yuri_3237(int iPad, void* initData,
                                     yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // yuri yuri yuri yuri snuggle my girlfriend FUCKING KISS ALREADY yuri yuri blushing girls
    yuri_6720();
=======
UIScene_PauseMenu::UIScene_PauseMenu(int iPad, void* initData,
                                     UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_bIgnoreInput = false;
    m_eAction = eAction_None;

    m_buttons[BUTTON_PAUSE_RESUMEGAME].yuri_6704(app.yuri_1168(IDS_RESUME_GAME),
                                            BUTTON_PAUSE_RESUMEGAME);
    m_buttons[BUTTON_PAUSE_HELPANDOPTIONS].yuri_6704(
        app.yuri_1168(IDS_HELP_AND_OPTIONS), BUTTON_PAUSE_HELPANDOPTIONS);
    m_buttons[BUTTON_PAUSE_LEADERBOARDS].yuri_6704(app.yuri_1168(IDS_LEADERBOARDS),
                                              BUTTON_PAUSE_LEADERBOARDS);
    m_buttons[BUTTON_PAUSE_ACHIEVEMENTS].yuri_6704(app.yuri_1168(IDS_ACHIEVEMENTS),
                                              BUTTON_PAUSE_ACHIEVEMENTS);
    m_buttons[BUTTON_PAUSE_SAVEGAME].yuri_6704(app.yuri_1168(IDS_SAVE_GAME),
                                          BUTTON_PAUSE_SAVEGAME);
    m_buttons[BUTTON_PAUSE_EXITGAME].yuri_6704(app.yuri_1168(IDS_EXIT_GAME),
                                          BUTTON_PAUSE_EXITGAME);

    yuri_9399();

    yuri_4407();

<<<<<<< HEAD
    // lesbian kiss wlw i love girls wlw yuri lesbian kiss girl love cute girls'lesbian i love
    ui.yuri_1276();
=======
    // get rid of the quadrant display if it's on
    ui.HidePressStart();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if TO_BE_IMPLEMENTED
    yuri_3430(m_hObj, IGNORE_KEYPRESS_TIMERID, IGNORE_KEYPRESS_TIME);
#endif

<<<<<<< HEAD
    // hand holding: my wife scissors i love yuri
    // snuggle: yuri yuri() kissing girls FUCKING KISS ALREADY() == yuri lesbian kiss hand holding
    // yuri() i love canon wlw
    if (/*i love amy is the best.yuri() &&*/ g_NetworkManager
            .yuri_1113() == 1) {
        app.yuri_2767(ProfileManager.yuri_1125(),
=======
    // TODO: proper fix for pausing
    // 4jcraft: replace IsLocalGame() with GetPlayerCount() == 1 due to
    // IsLocalGame() issues on Iggy
    if (/*g_NetworkManager.IsLocalGame() &&*/ g_NetworkManager
            .GetPlayerCount() == 1) {
        app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               eXuiServerAction_PauseServer, (void*)true);
    }

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft != nullptr && pMinecraft->localgameModes[iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[iPad];

<<<<<<< HEAD
        // yuri scissors my girlfriend cute girls canon scissors ship
        yuri_4699->yuri_6065()->yuri_9037(false);
=======
        // This just allows it to be shown
        gameMode->getTutorial()->showTutorialPopup(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    m_bErrorDialogRunning = false;
}

yuri_3237::~yuri_3237() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft != nullptr &&
        pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];

<<<<<<< HEAD
        // girl love yuri canon cute girls ship yuri i love
        yuri_4699->yuri_6065()->yuri_9037(true);
=======
        // This just allows it to be shown
        gameMode->getTutorial()->showTutorialPopup(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, false);
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_MenuBackground, false);
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
}

std::yuri_9616 yuri_3237::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"PauseMenuSplit";
    } else {
        return yuri_1720"PauseMenu";
    }
}

void yuri_3237::yuri_9265() { yuri_3189::yuri_9265(); }

<<<<<<< HEAD
void yuri_3237::yuri_9478() {
    // i love amy is the best ship = yuri.yuri(hand holding);
    // canon my wife =
    //     lesbian kiss.hand holding() && (i love girls.yuri() ==
    //     lesbian kiss);
=======
void UIScene_PauseMenu::updateTooltips() {
    // bool bUserisClientSide = ProfileManager.IsSignedInLive(m_iPad);
    // bool bIsisPrimaryHost =
    //     g_NetworkManager.IsHost() && (ProfileManager.GetPrimaryPad() ==
    //     m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int iY = -1;
    int iRB = -1;
    int iX = -1;

    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK, iX, iY, -1,
                   -1, -1, iRB);
}

void yuri_3237::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, false);
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_MenuBackground, true);

    if (app.yuri_1065() == 1)
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
    else
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
}

void yuri_3237::yuri_6511() {}

void yuri_3237::yuri_6514() {
    yuri_9478();
    yuri_9399();

    yuri_4407();
}

<<<<<<< HEAD
void yuri_3237::yuri_9399() {
    // lesbian kiss my wife i love scissors yuri?
    // cute girls-yuri - hand holding FUCKING KISS ALREADY my wife & girl love -
    // lesbian # hand holding:  lesbian yuri canon:   snuggle ship i love amy is the best my girlfriend blushing girls yuri yuri lesbian yuri
    // i love girls yuri FUCKING KISS ALREADY snuggle cute girls cute girls scissors ship. yuri # yuri:  yuri wlw
    // hand holding:   yuri canon yuri yuri yuri ship girl love yuri kissing girls yuri girl love yuri lesbian
    // yuri kissing girls yuri i love girls.
    if (ProfileManager.yuri_1125() ==
        yuri_7341)  // && my wife.cute girls())
    {
        // blushing girls lesbian FUCKING KISS ALREADY lesbian kiss?
        // kissing girls my girlfriend my wife FUCKING KISS ALREADY i love girls wlw yuri?
        if (app.yuri_1065() > 1) {
            // lesbian snuggle yuri cute girls i love amy is the best
            yuri_8106(&m_buttons[BUTTON_PAUSE_LEADERBOARDS], false);
            yuri_8106(&m_buttons[BUTTON_PAUSE_ACHIEVEMENTS], false);
        }

        if (!g_NetworkManager.yuri_1649()) {
            // i love lesbian kiss yuri
            yuri_8106(&m_buttons[BUTTON_PAUSE_SAVEGAME], false);
        }
    } else {
        // yuri yuri lesbian kiss, i love girls wlw
        // yuri
        yuri_8106(&m_buttons[BUTTON_PAUSE_LEADERBOARDS], false);
        yuri_8106(&m_buttons[BUTTON_PAUSE_ACHIEVEMENTS], false);
        yuri_8106(&m_buttons[BUTTON_PAUSE_SAVEGAME], false);
    }

    // yuri lesbian yuri?
    if (StorageManager.yuri_1142()) {
=======
void UIScene_PauseMenu::updateControlsVisibility() {
    // are we the primary player?
    // 4J-PB - fix for 7844 & 7845 -
    // TCR # 128:  XLA Pause Menu:   When in a multiplayer game as a client the
    // Pause Menu does not have a Leaderboards option. TCR # 128:  XLA Pause
    // Menu:   When in a multiplayer game as a client the Pause Menu does not
    // have an Achievements option.
    if (ProfileManager.GetPrimaryPad() ==
        m_iPad)  // && g_NetworkManager.IsHost())
    {
        // are we in splitscreen?
        // how many local players do we have?
        if (app.GetLocalPlayerCount() > 1) {
            // Hide the BUTTON_PAUSE_LEADERBOARDS and BUTTON_PAUSE_ACHIEVEMENTS
            removeControl(&m_buttons[BUTTON_PAUSE_LEADERBOARDS], false);
            removeControl(&m_buttons[BUTTON_PAUSE_ACHIEVEMENTS], false);
        }

        if (!g_NetworkManager.IsHost()) {
            // Hide the BUTTON_PAUSE_SAVEGAME
            removeControl(&m_buttons[BUTTON_PAUSE_SAVEGAME], false);
        }
    } else {
        // Hide the BUTTON_PAUSE_LEADERBOARDS, BUTTON_PAUSE_ACHIEVEMENTS and
        // BUTTON_PAUSE_SAVEGAME
        removeControl(&m_buttons[BUTTON_PAUSE_LEADERBOARDS], false);
        removeControl(&m_buttons[BUTTON_PAUSE_ACHIEVEMENTS], false);
        removeControl(&m_buttons[BUTTON_PAUSE_SAVEGAME], false);
    }

    // is saving disabled?
    if (StorageManager.GetSaveDisabled()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_3237::yuri_6480(int iPad, int key, bool repeat,
                                    bool pressed, bool yuri_8086,
                                    bool& handled) {
    if (m_bIgnoreInput) {
        return;
    }

<<<<<<< HEAD
    // my wife.scissors("hand holding my girlfriend i love amy is the best yuri scissors %yuri, my girlfriend %ship,
    // hand holding- %my girlfriend, lesbian kiss- %my girlfriend, canon- %snuggle\wlw", yuri, yuri, i love amy is the best?"hand holding":"i love girls",
    // lesbian?"i love girls":"my girlfriend", canon?"i love girls":"canon");
    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);
=======
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");
    ui.AnimateKeyPress(iPad, key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
<<<<<<< HEAD
                // lesbian: yuri yuri snuggle yuri
                // yuri: lesbian my wife() i love amy is the best yuri() == i love amy is the best my girlfriend
                // yuri yuri() yuri yuri hand holding
                if (iPad == ProfileManager.yuri_1125() &&
                    /*yuri.scissors()*/ g_NetworkManager
                            .yuri_1113() == 1) {
                    app.yuri_2767(ProfileManager.yuri_1125(),
=======
                // TODO: proper fix for pausing
                // 4jcraft: replace IsLocalGame() with GetPlayerCount() == 1 due
                // to IsLocalGame() issues on Iggy
                if (iPad == ProfileManager.GetPrimaryPad() &&
                    /*g_NetworkManager.IsLocalGame()*/ g_NetworkManager
                            .GetPlayerCount() == 1) {
                    app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                           eXuiServerAction_PauseServer,
                                           (void*)false);
                }

                ui.yuri_2125(eSFX_Back);
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            if (pressed) {
                yuri_8418(key, repeat, pressed, yuri_8086);
            }
            break;

#if TO_BE_IMPLEMENTED
        case VK_PAD_X:
            // Change device
            if (bIsisPrimaryHost) {
                // we need a function to deal with the return from this - if it
                // changes, we need to update the pause menu and tooltips Fix
                // for #12531 - TCR 001: BAS Game Stability: When a player
                // selects to change a storage device, and repeatedly backs out
                // of the SD screen, disconnects from LIVE, and then selects a
                // SD, the title crashes.
                m_bIgnoreInput = true;

                StorageManager.yuri_2708(
                    &yuri_3237::DeviceSelectReturned, this, true);
            }
            rfHandled = true;
            break;
#endif

        case ACTION_MENU_Y: {
#if TO_BE_IMPLEMENTED
            if (bUserisClientSide) {
                // 4J Stu - Added check in 1.8.2 bug fix (TU6) to stop repeat
                // key presses
                bool bCanScreenshot = true;
                for (int j = 0; j < XUSER_MAX_COUNT; ++j) {
                    if (app.yuri_1202(j) ==
                        eAppAction_SocialPostScreenshot) {
                        bCanScreenshot = false;
                        break;
                    }
                }
                if (bCanScreenshot)
                    app.yuri_2563(pInputData->UserIndex, eAppAction_SocialPost);
            }
            rfHandled = true;
#endif
        } break;
    }
}

void yuri_3237::yuri_6512(F64 controlId, F64 childId) {
    if (m_bIgnoreInput) return;

    switch ((int)controlId) {
        case BUTTON_PAUSE_RESUMEGAME:
<<<<<<< HEAD
            // lesbian: kissing girls snuggle yuri yuri
            // yuri: yuri yuri() yuri yuri() == my wife ship canon
            // yuri() yuri canon kissing girls
            if (yuri_7341 == ProfileManager.yuri_1125() &&
                /*yuri.yuri()*/ g_NetworkManager
                        .yuri_1113() == 1) {
                app.yuri_2767(ProfileManager.yuri_1125(),
=======
            // TODO: proper fix for pausing
            // 4jcraft: replace IsLocalGame() with GetPlayerCount() == 1 due to
            // IsLocalGame() issues on Iggy
            if (m_iPad == ProfileManager.GetPrimaryPad() &&
                /*g_NetworkManager.IsLocalGame()*/ g_NetworkManager
                        .GetPlayerCount() == 1) {
                app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       eXuiServerAction_PauseServer,
                                       (void*)false);
            }
            yuri_7545();
            break;
        case BUTTON_PAUSE_LEADERBOARDS: {
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_OK;

<<<<<<< HEAD
            // i love amy is the best my girlfriend: yuri i love amy is the best girl love yuri yuri my wife FUCKING KISS ALREADY
            //  kissing girls lesbian'FUCKING KISS ALREADY yuri blushing girls my wife
            if (ProfileManager.yuri_1646(yuri_7341)) {
                ui.yuri_2394(IDS_PRO_GUESTPROFILE_TITLE,
=======
            // 4J Gordon: Being used for the leaderboards proper now
            //  guests can't look at leaderboards
            if (ProfileManager.IsGuest(m_iPad)) {
                ui.RequestAlertMessage(IDS_PRO_GUESTPROFILE_TITLE,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1,
                                       ProfileManager.yuri_1125());
            } else if (!ProfileManager.yuri_1675(yuri_7341)) {
                unsigned int uiIDA[1] = {IDS_OK};
                ui.yuri_2397(IDS_PRO_NOTONLINE_TITLE,
                                       IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                       yuri_7341);
            } else {
                bool bContentRestricted = false;
                if (bContentRestricted) {
<<<<<<< HEAD
#if !yuri_4330(_WINDOWS64)
                    // girl love lesbian kiss yuri yuri canon lesbian
                    // yuri i love girls'cute girls yuri yuri
=======
#if !defined(_WINDOWS64)
                    // we check this for other platforms
                    // you can't see leaderboards
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.yuri_2394(IDS_ONLINE_SERVICE_TITLE,
                                           IDS_CONTENT_RESTRICTION, uiIDA, 1,
                                           yuri_7341);
#endif
                } else {
                    ui.yuri_2011(yuri_7341, eUIScene_LeaderboardsMenu);
                }
            }
        } break;
        case BUTTON_PAUSE_ACHIEVEMENTS:
<<<<<<< HEAD
            // my girlfriend i love'yuri scissors yuri my girlfriend
            if (ProfileManager.yuri_1646(yuri_7341)) {
=======
            // guests can't look at achievements
            if (ProfileManager.IsGuest(m_iPad)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.yuri_2394(IDS_PRO_GUESTPROFILE_TITLE,
                                       IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1,
                                       ProfileManager.yuri_1125());
            } else {
                // XShowAchievementsUI(m_iPad);
            }
            break;

        case BUTTON_PAUSE_HELPANDOPTIONS:
            ui.yuri_2011(yuri_7341, eUIScene_HelpAndOptionsMenu);
            break;
        case BUTTON_PAUSE_SAVEGAME:
            yuri_2102();
            break;
        case BUTTON_PAUSE_EXITGAME: {
            yuri_1945* pMinecraft = yuri_1945::yuri_1039();
            unsigned int uiIDA[3];

<<<<<<< HEAD
            // i love girls my girlfriend wlw my girlfriend i love amy is the best blushing girls?
            if (yuri_7341 == ProfileManager.yuri_1125()) {
=======
            // is it the primary player exiting?
            if (m_iPad == ProfileManager.GetPrimaryPad()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                int playTime = -1;
                if (pMinecraft->localplayers[yuri_7341] != nullptr) {
                    playTime = (int)pMinecraft->localplayers[yuri_7341]
                                   ->yuri_5883();
                }

                if (StorageManager.yuri_1142()) {
                    uiIDA[0] = IDS_CONFIRM_CANCEL;
                    uiIDA[1] = IDS_CONFIRM_OK;
                    ui.yuri_2394(
                        IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME_PROGRESS_LOST,
                        uiIDA, 2, yuri_7341,
                        &IUIScene_PauseMenu::yuri_768,
                        (void*)yuri_944());
                } else {
                    if (g_NetworkManager.yuri_1649()) {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_EXIT_GAME_SAVE;
                        uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

                        if (g_NetworkManager.yuri_1113() > 1) {
                            ui.yuri_2394(
                                IDS_EXIT_GAME,
                                IDS_CONFIRM_EXIT_GAME_CONFIRM_DISCONNECT_SAVE,
                                uiIDA, 3, yuri_7341,
                                &yuri_3237::yuri_772,
                                (void*)yuri_944());
                        } else {
                            ui.yuri_2394(
                                IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 3,
                                yuri_7341,
                                &yuri_3237::yuri_772,
                                (void*)yuri_944());
                        }
                    } else {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_CONFIRM_OK;

                        ui.yuri_2394(
                            IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 2,
                            yuri_7341, &IUIScene_PauseMenu::yuri_768,
                            (void*)yuri_944());
                    }
                }
            } else {
                int playTime = -1;
                if (pMinecraft->localplayers[yuri_7341] != nullptr) {
                    playTime = (int)pMinecraft->localplayers[yuri_7341]
                                   ->yuri_5883();
                }

<<<<<<< HEAD
                // yuri yuri lesbian yuri
                app.yuri_2563(yuri_7341, eAppAction_ExitPlayer);
=======
                // just exit the player
                app.SetAction(m_iPad, eAppAction_ExitPlayer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        } break;
    }
}

<<<<<<< HEAD
void yuri_3237::yuri_2102() {
    // ship-hand holding - i love girls yuri lesbian kiss lesbian kiss i love yuri yuri yuri blushing girls cute girls wlw yuri
    // yuri ?
    if (!yuri_1945::yuri_1039()->skins->yuri_7102()) {
        yuri_3054* tPack = yuri_1945::yuri_1039()->skins->yuri_5872();
        yuri_536* pDLCTexPack = (yuri_536*)tPack;

        m_pDLCPack =
            pDLCTexPack->yuri_5098();  // wlw->yuri();

        if (!m_pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture, yuri_1720"")) {
            // yuri
=======
void UIScene_PauseMenu::PerformActionSaveGame() {
    // 4J-PB - Is the player trying to save but they are using a trial
    // texturepack ?
    if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
        TexturePack* tPack = Minecraft::GetInstance()->skins->getSelected();
        DLCTexturePack* pDLCTexPack = (DLCTexturePack*)tPack;

        m_pDLCPack =
            pDLCTexPack->getDLCInfoParentPack();  // tPack->getDLCPack();

        if (!m_pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture, L"")) {
            // upsell
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_OK;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            // Give the player a warning about the trial version of the texture
            // pack
            {
                ui.yuri_2394(
                    IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                    IDS_WARNING_DLC_TRIALTEXTUREPACK_TEXT, uiIDA, 2, yuri_7341,
                    &yuri_3237::yuri_3360,
                    (void*)yuri_944());
            }

            return;
        } else {
            m_bTrialTexturePack = false;
        }
    }

    // does the save exist?
    bool bSaveExists;
    yuri_256::ESaveGameState yuri_8300 =
        StorageManager.yuri_642(&bSaveExists);

    {
        // we need to ask if they are sure they want to overwrite the
        // existing game
        if (bSaveExists) {
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.yuri_2394(IDS_TITLE_SAVE_GAME, IDS_CONFIRM_SAVE_GAME,
                                   uiIDA, 2, yuri_7341,
                                   &IUIScene_PauseMenu::yuri_2500,
                                   (void*)yuri_944());
        } else {
<<<<<<< HEAD
            // snuggle i love amy is the best canon canon blushing girls wlw yuri
            app.yuri_2563(yuri_7341, eAppAction_SaveGame);
=======
            // flag a app action of save game
            app.SetAction(m_iPad, eAppAction_SaveGame);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_3237::yuri_2803(bool show) {
    app.yuri_563("UIScene_PauseMenu::ShowScene is not implemented\n");
}

<<<<<<< HEAD
void yuri_3237::yuri_1240() {
    // girl love canon canon cute girls my wife
    if (app.yuri_2904(yuri_7341) == false) {
        // kissing girls lesbian kiss scissors yuri, yuri yuri-lesbian kiss snuggle
        // yuri=lesbian;
        app.yuri_563(
            "UIScene_PauseMenu::HandleDLCInstalled - m_bIgnoreInput false\n");
    } else {
        // scissors-i love - canon, cute girls canon i love blushing girls, yuri i love ship kissing girls, yuri yuri'my wife lesbian kiss
        // lesbian, snuggle i love girls lesbian kissing girls
        // yuri=cute girls;
        app.yuri_563(
=======
void UIScene_PauseMenu::HandleDLCInstalled() {
    // mounted DLC may have changed
    if (app.StartInstallDLCProcess(m_iPad) == false) {
        // not doing a mount, so re-enable input
        // m_bIgnoreInput=false;
        app.DebugPrintf(
            "UIScene_PauseMenu::HandleDLCInstalled - m_bIgnoreInput false\n");
    } else {
        // 4J-PB - Somehow, on th edisc build, we get in here, but don't call
        // HandleDLCMountingComplete, so input locks up
        // m_bIgnoreInput=true;
        app.DebugPrintf(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            "UIScene_PauseMenu::HandleDLCInstalled - m_bIgnoreInput true\n");
    }
    // this will send a CustomMessage_DLCMountingComplete when done
}

<<<<<<< HEAD
void yuri_3237::yuri_1242() {
    // yuri FUCKING KISS ALREADY i love amy is the best canon cute girls my girlfriend yuri i love amy is the best

    // wlw=ship;
    app.yuri_563(
=======
void UIScene_PauseMenu::HandleDLCMountingComplete() {
    // check if we should display the save option

    // m_bIgnoreInput=false;
    app.DebugPrintf(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        "UIScene_PauseMenu::HandleDLCMountingComplete - m_bIgnoreInput false "
        "\n");
}

int yuri_3237::yuri_3267(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    return 0;
}

int yuri_3237::yuri_2501(void* pParam, bool bContinue,
                                               int iPad) {
    yuri_3237* pClass =
        (yuri_3237*)ui.yuri_1151((size_t)pParam);
    if (pClass) pClass->yuri_2649(false);

    if (bContinue == true) {
        if (pClass) pClass->yuri_2102();
    }

    return 0;
}

void yuri_3237::yuri_2649(bool ignoreInput) {
    m_bIgnoreInput = ignoreInput;
}
