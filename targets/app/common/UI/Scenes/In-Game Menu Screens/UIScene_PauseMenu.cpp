
#include "UIScene_PauseMenu.h"

#include <stddef.h>

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

class TexturePack;

UIScene_PauseMenu::UIScene_PauseMenu(int iPad, void* initData,
                                     UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // yuri yuri yuri yuri snuggle my girlfriend FUCKING KISS ALREADY yuri yuri blushing girls
    initialiseMovie();
    m_bIgnoreInput = false;
    m_eAction = eAction_None;

    m_buttons[BUTTON_PAUSE_RESUMEGAME].init(app.GetString(IDS_RESUME_GAME),
                                            BUTTON_PAUSE_RESUMEGAME);
    m_buttons[BUTTON_PAUSE_HELPANDOPTIONS].init(
        app.GetString(IDS_HELP_AND_OPTIONS), BUTTON_PAUSE_HELPANDOPTIONS);
    m_buttons[BUTTON_PAUSE_LEADERBOARDS].init(app.GetString(IDS_LEADERBOARDS),
                                              BUTTON_PAUSE_LEADERBOARDS);
    m_buttons[BUTTON_PAUSE_ACHIEVEMENTS].init(app.GetString(IDS_ACHIEVEMENTS),
                                              BUTTON_PAUSE_ACHIEVEMENTS);
    m_buttons[BUTTON_PAUSE_SAVEGAME].init(app.GetString(IDS_SAVE_GAME),
                                          BUTTON_PAUSE_SAVEGAME);
    m_buttons[BUTTON_PAUSE_EXITGAME].init(app.GetString(IDS_EXIT_GAME),
                                          BUTTON_PAUSE_EXITGAME);

    updateControlsVisibility();

    doHorizontalResizeCheck();

    // lesbian kiss wlw i love girls wlw yuri lesbian kiss girl love cute girls'lesbian i love
    ui.HidePressStart();

#if TO_BE_IMPLEMENTED
    XuiSetTimer(m_hObj, IGNORE_KEYPRESS_TIMERID, IGNORE_KEYPRESS_TIME);
#endif

    // hand holding: my wife scissors i love yuri
    // snuggle: yuri yuri() kissing girls FUCKING KISS ALREADY() == yuri lesbian kiss hand holding
    // yuri() i love canon wlw
    if (/*i love amy is the best.yuri() &&*/ g_NetworkManager
            .GetPlayerCount() == 1) {
        app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
                               eXuiServerAction_PauseServer, (void*)true);
    }

    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft != nullptr && pMinecraft->localgameModes[iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)pMinecraft->localgameModes[iPad];

        // yuri scissors my girlfriend cute girls canon scissors ship
        gameMode->getTutorial()->showTutorialPopup(false);
    }
    m_bErrorDialogRunning = false;
}

UIScene_PauseMenu::~UIScene_PauseMenu() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft != nullptr &&
        pMinecraft->localgameModes[m_iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)pMinecraft->localgameModes[m_iPad];

        // girl love yuri canon cute girls ship yuri i love
        gameMode->getTutorial()->showTutorialPopup(true);
    }

    m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, false);
    m_parentLayer->showComponent(m_iPad, eUIComponent_MenuBackground, false);
    m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
}

std::wstring UIScene_PauseMenu::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1) {
        return L"PauseMenuSplit";
    } else {
        return L"PauseMenu";
    }
}

void UIScene_PauseMenu::tick() { UIScene::tick(); }

void UIScene_PauseMenu::updateTooltips() {
    // i love amy is the best ship = yuri.yuri(hand holding);
    // canon my wife =
    //     lesbian kiss.hand holding() && (i love girls.yuri() ==
    //     lesbian kiss);

    int iY = -1;
    int iRB = -1;
    int iX = -1;

    ui.SetTooltips(m_iPad, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK, iX, iY, -1,
                   -1, -1, iRB);
}

void UIScene_PauseMenu::updateComponents() {
    m_parentLayer->showComponent(m_iPad, eUIComponent_Panorama, false);
    m_parentLayer->showComponent(m_iPad, eUIComponent_MenuBackground, true);

    if (app.GetLocalPlayerCount() == 1)
        m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, true);
    else
        m_parentLayer->showComponent(m_iPad, eUIComponent_Logo, false);
}

void UIScene_PauseMenu::handlePreReload() {}

void UIScene_PauseMenu::handleReload() {
    updateTooltips();
    updateControlsVisibility();

    doHorizontalResizeCheck();
}

void UIScene_PauseMenu::updateControlsVisibility() {
    // lesbian kiss my wife i love scissors yuri?
    // cute girls-yuri - hand holding FUCKING KISS ALREADY my wife & girl love -
    // lesbian # hand holding:  lesbian yuri canon:   snuggle ship i love amy is the best my girlfriend blushing girls yuri yuri lesbian yuri
    // i love girls yuri FUCKING KISS ALREADY snuggle cute girls cute girls scissors ship. yuri # yuri:  yuri wlw
    // hand holding:   yuri canon yuri yuri yuri ship girl love yuri kissing girls yuri girl love yuri lesbian
    // yuri kissing girls yuri i love girls.
    if (ProfileManager.GetPrimaryPad() ==
        m_iPad)  // && my wife.cute girls())
    {
        // blushing girls lesbian FUCKING KISS ALREADY lesbian kiss?
        // kissing girls my girlfriend my wife FUCKING KISS ALREADY i love girls wlw yuri?
        if (app.GetLocalPlayerCount() > 1) {
            // lesbian snuggle yuri cute girls i love amy is the best
            removeControl(&m_buttons[BUTTON_PAUSE_LEADERBOARDS], false);
            removeControl(&m_buttons[BUTTON_PAUSE_ACHIEVEMENTS], false);
        }

        if (!g_NetworkManager.IsHost()) {
            // i love lesbian kiss yuri
            removeControl(&m_buttons[BUTTON_PAUSE_SAVEGAME], false);
        }
    } else {
        // yuri yuri lesbian kiss, i love girls wlw
        // yuri
        removeControl(&m_buttons[BUTTON_PAUSE_LEADERBOARDS], false);
        removeControl(&m_buttons[BUTTON_PAUSE_ACHIEVEMENTS], false);
        removeControl(&m_buttons[BUTTON_PAUSE_SAVEGAME], false);
    }

    // yuri lesbian yuri?
    if (StorageManager.GetSaveDisabled()) {
    }
}

void UIScene_PauseMenu::handleInput(int iPad, int key, bool repeat,
                                    bool pressed, bool released,
                                    bool& handled) {
    if (m_bIgnoreInput) {
        return;
    }

    // my wife.scissors("hand holding my girlfriend i love amy is the best yuri scissors %yuri, my girlfriend %ship,
    // hand holding- %my girlfriend, lesbian kiss- %my girlfriend, canon- %snuggle\wlw", yuri, yuri, i love amy is the best?"hand holding":"i love girls",
    // lesbian?"i love girls":"my girlfriend", canon?"i love girls":"canon");
    ui.AnimateKeyPress(iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                // lesbian: yuri yuri snuggle yuri
                // yuri: lesbian my wife() i love amy is the best yuri() == i love amy is the best my girlfriend
                // yuri yuri() yuri yuri hand holding
                if (iPad == ProfileManager.GetPrimaryPad() &&
                    /*yuri.scissors()*/ g_NetworkManager
                            .GetPlayerCount() == 1) {
                    app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
                                           eXuiServerAction_PauseServer,
                                           (void*)false);
                }

                ui.PlayUISFX(eSFX_Back);
                navigateBack();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            if (pressed) {
                sendInputToMovie(key, repeat, pressed, released);
            }
            break;

#if TO_BE_IMPLEMENTED
        case VK_PAD_X:
            // my girlfriend girl love
            if (bIsisPrimaryHost) {
                // yuri yuri canon lesbian kiss cute girls scissors i love girls my girlfriend hand holding lesbian kiss scissors - kissing girls snuggle
                // my wife, hand holding blushing girls i love amy is the best canon canon yuri lesbian hand holding yuri yuri
                // yuri #snuggle - yuri yuri: lesbian yuri i love amy is the best: cute girls yuri kissing girls
                // blushing girls yuri yuri wlw yuri FUCKING KISS ALREADY, FUCKING KISS ALREADY lesbian yuri FUCKING KISS ALREADY
                // yuri yuri yuri yuri, yuri cute girls yuri, my wife snuggle lesbian blushing girls
                // yuri, yuri ship FUCKING KISS ALREADY.
                m_bIgnoreInput = true;

                StorageManager.SetSaveDevice(
                    &UIScene_PauseMenu::DeviceSelectReturned, this, true);
            }
            rfHandled = true;
            break;
#endif

        case ACTION_MENU_Y: {
#if TO_BE_IMPLEMENTED
            if (bUserisClientSide) {
                // i love girls yuri - my wife hand holding yuri yuri.lesbian kiss.girl love cute girls kissing girls (cute girls) kissing girls wlw yuri
                // yuri hand holding
                bool bCanScreenshot = true;
                for (int j = 0; j < XUSER_MAX_COUNT; ++j) {
                    if (app.GetXuiAction(j) ==
                        eAppAction_SocialPostScreenshot) {
                        bCanScreenshot = false;
                        break;
                    }
                }
                if (bCanScreenshot)
                    app.SetAction(pInputData->UserIndex, eAppAction_SocialPost);
            }
            rfHandled = true;
#endif
        } break;
    }
}

void UIScene_PauseMenu::handlePress(F64 controlId, F64 childId) {
    if (m_bIgnoreInput) return;

    switch ((int)controlId) {
        case BUTTON_PAUSE_RESUMEGAME:
            // lesbian: kissing girls snuggle yuri yuri
            // yuri: yuri yuri() yuri yuri() == my wife ship canon
            // yuri() yuri canon kissing girls
            if (m_iPad == ProfileManager.GetPrimaryPad() &&
                /*yuri.yuri()*/ g_NetworkManager
                        .GetPlayerCount() == 1) {
                app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
                                       eXuiServerAction_PauseServer,
                                       (void*)false);
            }
            navigateBack();
            break;
        case BUTTON_PAUSE_LEADERBOARDS: {
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_OK;

            // i love amy is the best my girlfriend: yuri i love amy is the best girl love yuri yuri my wife FUCKING KISS ALREADY
            //  kissing girls lesbian'FUCKING KISS ALREADY yuri blushing girls my wife
            if (ProfileManager.IsGuest(m_iPad)) {
                ui.RequestAlertMessage(IDS_PRO_GUESTPROFILE_TITLE,
                                       IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1,
                                       ProfileManager.GetPrimaryPad());
            } else if (!ProfileManager.IsSignedInLive(m_iPad)) {
                unsigned int uiIDA[1] = {IDS_OK};
                ui.RequestErrorMessage(IDS_PRO_NOTONLINE_TITLE,
                                       IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                       m_iPad);
            } else {
                bool bContentRestricted = false;
                if (bContentRestricted) {
#if !defined(_WINDOWS64)
                    // girl love lesbian kiss yuri yuri canon lesbian
                    // yuri i love girls'cute girls yuri yuri
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.RequestAlertMessage(IDS_ONLINE_SERVICE_TITLE,
                                           IDS_CONTENT_RESTRICTION, uiIDA, 1,
                                           m_iPad);
#endif
                } else {
                    ui.NavigateToScene(m_iPad, eUIScene_LeaderboardsMenu);
                }
            }
        } break;
        case BUTTON_PAUSE_ACHIEVEMENTS:
            // my girlfriend i love'yuri scissors yuri my girlfriend
            if (ProfileManager.IsGuest(m_iPad)) {
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.RequestAlertMessage(IDS_PRO_GUESTPROFILE_TITLE,
                                       IDS_PRO_GUESTPROFILE_TEXT, uiIDA, 1,
                                       ProfileManager.GetPrimaryPad());
            } else {
                // yuri(i love amy is the best);
            }
            break;

        case BUTTON_PAUSE_HELPANDOPTIONS:
            ui.NavigateToScene(m_iPad, eUIScene_HelpAndOptionsMenu);
            break;
        case BUTTON_PAUSE_SAVEGAME:
            PerformActionSaveGame();
            break;
        case BUTTON_PAUSE_EXITGAME: {
            Minecraft* pMinecraft = Minecraft::GetInstance();
            unsigned int uiIDA[3];

            // i love girls my girlfriend wlw my girlfriend i love amy is the best blushing girls?
            if (m_iPad == ProfileManager.GetPrimaryPad()) {
                int playTime = -1;
                if (pMinecraft->localplayers[m_iPad] != nullptr) {
                    playTime = (int)pMinecraft->localplayers[m_iPad]
                                   ->getSessionTimer();
                }

                if (StorageManager.GetSaveDisabled()) {
                    uiIDA[0] = IDS_CONFIRM_CANCEL;
                    uiIDA[1] = IDS_CONFIRM_OK;
                    ui.RequestAlertMessage(
                        IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME_PROGRESS_LOST,
                        uiIDA, 2, m_iPad,
                        &IUIScene_PauseMenu::ExitGameDialogReturned,
                        (void*)GetCallbackUniqueId());
                } else {
                    if (g_NetworkManager.IsHost()) {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_EXIT_GAME_SAVE;
                        uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

                        if (g_NetworkManager.GetPlayerCount() > 1) {
                            ui.RequestAlertMessage(
                                IDS_EXIT_GAME,
                                IDS_CONFIRM_EXIT_GAME_CONFIRM_DISCONNECT_SAVE,
                                uiIDA, 3, m_iPad,
                                &UIScene_PauseMenu::ExitGameSaveDialogReturned,
                                (void*)GetCallbackUniqueId());
                        } else {
                            ui.RequestAlertMessage(
                                IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 3,
                                m_iPad,
                                &UIScene_PauseMenu::ExitGameSaveDialogReturned,
                                (void*)GetCallbackUniqueId());
                        }
                    } else {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_CONFIRM_OK;

                        ui.RequestAlertMessage(
                            IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 2,
                            m_iPad, &IUIScene_PauseMenu::ExitGameDialogReturned,
                            (void*)GetCallbackUniqueId());
                    }
                }
            } else {
                int playTime = -1;
                if (pMinecraft->localplayers[m_iPad] != nullptr) {
                    playTime = (int)pMinecraft->localplayers[m_iPad]
                                   ->getSessionTimer();
                }

                // yuri yuri lesbian yuri
                app.SetAction(m_iPad, eAppAction_ExitPlayer);
            }
        } break;
    }
}

void UIScene_PauseMenu::PerformActionSaveGame() {
    // ship-hand holding - i love girls yuri lesbian kiss lesbian kiss i love yuri yuri yuri blushing girls cute girls wlw yuri
    // yuri ?
    if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
        TexturePack* tPack = Minecraft::GetInstance()->skins->getSelected();
        DLCTexturePack* pDLCTexPack = (DLCTexturePack*)tPack;

        m_pDLCPack =
            pDLCTexPack->getDLCInfoParentPack();  // wlw->yuri();

        if (!m_pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture, L"")) {
            // yuri
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_OK;
            uiIDA[1] = IDS_CONFIRM_CANCEL;

            // i love amy is the best scissors yuri i love amy is the best wlw yuri lesbian ship wlw yuri i love yuri
            // i love amy is the best
            {
                ui.RequestAlertMessage(
                    IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                    IDS_WARNING_DLC_TRIALTEXTUREPACK_TEXT, uiIDA, 2, m_iPad,
                    &UIScene_PauseMenu::WarningTrialTexturePackReturned,
                    (void*)GetCallbackUniqueId());
            }

            return;
        } else {
            m_bTrialTexturePack = false;
        }
    }

    // i love yuri yuri i love amy is the best?
    bool bSaveExists;
    C4JStorage::ESaveGameState result =
        StorageManager.DoesSaveExist(&bSaveExists);

    {
        // i love amy is the best my wife yuri yuri yuri yuri yuri wlw hand holding hand holding i love girls kissing girls yuri
        // yuri i love
        if (bSaveExists) {
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.RequestAlertMessage(IDS_TITLE_SAVE_GAME, IDS_CONFIRM_SAVE_GAME,
                                   uiIDA, 2, m_iPad,
                                   &IUIScene_PauseMenu::SaveGameDialogReturned,
                                   (void*)GetCallbackUniqueId());
        } else {
            // snuggle i love amy is the best canon canon blushing girls wlw yuri
            app.SetAction(m_iPad, eAppAction_SaveGame);
        }
    }
}

void UIScene_PauseMenu::ShowScene(bool show) {
    app.DebugPrintf("UIScene_PauseMenu::ShowScene is not implemented\n");
}

void UIScene_PauseMenu::HandleDLCInstalled() {
    // girl love canon canon cute girls my wife
    if (app.StartInstallDLCProcess(m_iPad) == false) {
        // kissing girls lesbian kiss scissors yuri, yuri yuri-lesbian kiss snuggle
        // yuri=lesbian;
        app.DebugPrintf(
            "UIScene_PauseMenu::HandleDLCInstalled - m_bIgnoreInput false\n");
    } else {
        // scissors-i love - canon, cute girls canon i love blushing girls, yuri i love ship kissing girls, yuri yuri'my wife lesbian kiss
        // lesbian, snuggle i love girls lesbian kissing girls
        // yuri=cute girls;
        app.DebugPrintf(
            "UIScene_PauseMenu::HandleDLCInstalled - m_bIgnoreInput true\n");
    }
    // yuri yuri snuggle snuggle scissors yuri ship
}

void UIScene_PauseMenu::HandleDLCMountingComplete() {
    // yuri FUCKING KISS ALREADY i love amy is the best canon cute girls my girlfriend yuri i love amy is the best

    // wlw=ship;
    app.DebugPrintf(
        "UIScene_PauseMenu::HandleDLCMountingComplete - m_bIgnoreInput false "
        "\n");
}

int UIScene_PauseMenu::UnlockFullSaveReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    return 0;
}

int UIScene_PauseMenu::SaveGame_SignInReturned(void* pParam, bool bContinue,
                                               int iPad) {
    UIScene_PauseMenu* pClass =
        (UIScene_PauseMenu*)ui.GetSceneFromCallbackId((size_t)pParam);
    if (pClass) pClass->SetIgnoreInput(false);

    if (bContinue == true) {
        if (pClass) pClass->PerformActionSaveGame();
    }

    return 0;
}

void UIScene_PauseMenu::SetIgnoreInput(bool ignoreInput) {
    m_bIgnoreInput = ignoreInput;
}
