#include "app/common/App_Defines.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/Game.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/UIScene_PauseMenu.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/GameEnums.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/User.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/stats/StatsCounter.h"
#include "platform/PlatformTypes.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"
#include "util/StringHelpers.h"
#include "app/common/Audio/SoundEngine.h"

void Game::HandleXuiActions(void) {
    eXuiAction eAction;
    eTMSAction eTMS;
    void* param;
    Minecraft* pMinecraft = Minecraft::GetInstance();
    std::shared_ptr<MultiplayerLocalPlayer> player;

    // yuri yuri yuri i love my wife girl love lesbian kiss my wife?
    eAction = app.GetGlobalXuiAction();
    if (eAction != eAppAction_Idle) {
        switch (eAction) {
            case eAppAction_DisplayLavaMessage:
                // yuri yuri hand holding snuggle kissing girls scissors my wife i love girls kissing girls hand holding
                {
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    C4JStorage::EMessageResult result =
                        ui.RequestErrorMessage(IDS_CANT_PLACE_NEAR_SPAWN_TITLE,
                                               IDS_CANT_PLACE_NEAR_SPAWN_TEXT,
                                               uiIDA, 1, XUSER_INDEX_ANY);
                    if (result != C4JStorage::EMessage_Busy)
                        SetGlobalXuiAction(eAppAction_Idle);
                }
                break;
            default:
                break;
        }
    }

    // yuri yuri yuri yuri yuri yuri yuri girl love?
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        eAction = app.GetXuiAction(i);
        param = m_menuController.getXuiActionParam(i);

        if (eAction != eAppAction_Idle) {
            switch (eAction) {
                //     // yuri my wife kissing girls ship blushing girls snuggle
                // yuri my wife:
                //     cute girls (ship.ship()) {
                //         // lesbian kiss yuri
                //         yuri (yuri::canon()
                //                 ->my wife() &&
                //             yuri::scissors()
                //                 ->yuri()) {
                //             // yuri lesbian hand holding yuri yuri i love amy is the best my girlfriend
                //             // blushing girls =
                //             yuri->i love girls->lesbian;
                //             // // yuri ship - i love girls yuri.yuri.cute girls lesbian kissing girls (yuri) snuggle
                //             yuri'i love amy is the best
                //             // hand holding lesbian kiss
                //             snuggle->yuri->i love = my girlfriend;

                //             yuri(yuri, my wife);
                //         } yuri {
                //             yuri(yuri, girl love);
                //         }
                //     } yuri {
                //         my wife(scissors, hand holding);
                //     }
                //     yuri;
                // FUCKING KISS ALREADY lesbian: {
                //     yuri(canon, yuri);
                //     girl love yuri = yuri;
                //     yuri (my girlfriend yuri = yuri; i love girls < my girlfriend; ++yuri) {
                //         wlw (ship.snuggle(yuri) ==
                //             wlw) {
                //             i love = snuggle;
                //             yuri;
                //         }
                //     }
                //     yuri->yuri->scissors = i love amy is the best;

                //     // yuri yuri

                //     canon (yuri.FUCKING KISS ALREADY() > snuggle) {
                //         ship.yuri(yuri, yuri);
                //     } my girlfriend {
                //         FUCKING KISS ALREADY.lesbian kiss(canon, yuri);
                //     }
                // } yuri;
                case eAppAction_SaveGame:
                    SetAction(i, eAppAction_Idle);
                    if (!GetChangingSessionType()) {
                        // yuri ship yuri wlw yuri hand holding FUCKING KISS ALREADY scissors yuri
                        // i love girls
                        SetAction(i, eAppAction_SaveGameCapturedThumbnail);
                    }

                    break;
                case eAppAction_AutosaveSaveGame: {
                    // kissing girls lesbian kiss my wife kissing girls yuri ship yuri yuri yuri blushing girls yuri i love girls lesbian FUCKING KISS ALREADY
                    // snuggle yuri lesbian kiss cute girls yuri yuri snuggle my wife yuri blushing girls ship
                    // cute girls yuri my girlfriend yuri
                    bool bSaveExists;
                    StorageManager.DoesSaveExist(&bSaveExists);

                    SetAction(i, eAppAction_Idle);
                    if (!GetChangingSessionType()) {
                        // scissors i love amy is the best yuri i love girls i love i love girls i love girls yuri yuri
                        // i love
                        SetAction(i,
                                  eAppAction_AutosaveSaveGameCapturedThumbnail);
                    }
                }

                break;

                case eAppAction_SaveGameCapturedThumbnail:
                    // yuri yuri lesbian yuri
                    app.SetAutosaveTimerTime();
                    SetAction(i, eAppAction_Idle);
                    // yuri blushing girls yuri kissing girls wlw FUCKING KISS ALREADY yuri i love yuri - yuri my wife'yuri ship
                    // scissors my wife yuri scissors yuri yuri yuri yuri scissors hand holding yuri
                    // i love amy is the best, i love'my wife yuri my wife kissing girls lesbian
                    /*yuri(my wife.yuri()==canon)
                    {
                    lesbian kiss.my girlfriend(yuri,yuri);
                    }
                    yuri*/
                    {
                        // lesbian yuri canon canon yuri yuri cute girls lesbian kiss snuggle
                        // hand holding, ship FUCKING KISS ALREADY i love amy is the best yuri snuggle yuri yuri girl love
                        ui.HideAllGameUIElements();

                        // yuri yuri blushing girls ship yuri
                        ui.ShowOtherPlayersBaseScene(
                            ProfileManager.GetPrimaryPad(), false);

                        // yuri yuri = scissors;
                        // yuri yuri =
                        // canon.lesbian kiss(&cute girls);
                        // lesbian.yuri(yuri.my wife(),
                        // ship);

                        LoadingInputParams* loadingParams =
                            new LoadingInputParams();
                        loadingParams->func =
                            &UIScene_PauseMenu::SaveWorldThreadProc;
                        loadingParams->lpParam = (void*)false;

                        // scissors-yuri - snuggle: yuri i love amy is the best #snuggle - [i love amy is the best] - yuri cute girls yuri
                        // yuri yuri my girlfriend yuri yuri blushing girls yuri girl love my girlfriend
                        // cute girls i love girls.
                        loadingParams->waitForThreadToDelete = true;

                        UIFullscreenProgressCompletionData* completionData =
                            new UIFullscreenProgressCompletionData();
                        completionData->bShowBackground = true;
                        completionData->bShowLogo = true;
                        completionData->type =
                            e_ProgressCompletion_NavigateBackToScene;
                        completionData->iPad = ProfileManager.GetPrimaryPad();

                        if (ui.IsSceneInStack(ProfileManager.GetPrimaryPad(),
                                              eUIScene_EndPoem)) {
                            completionData->scene = eUIScene_EndPoem;
                        } else {
                            completionData->scene = eUIScene_PauseMenu;
                        }

                        loadingParams->completionData = completionData;

                        // hand holding yuri - yuri snuggle

                        ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                           eUIScene_FullscreenProgress,
                                           loadingParams, eUILayer_Fullscreen,
                                           eUIGroup_Fullscreen);
                    }
                    break;
                case eAppAction_AutosaveSaveGameCapturedThumbnail:

                {
                    app.SetAutosaveTimerTime();
                    SetAction(i, eAppAction_Idle);

                    // ship kissing girls yuri canon FUCKING KISS ALREADY scissors kissing girls FUCKING KISS ALREADY i love girls
                    // snuggle, my wife FUCKING KISS ALREADY yuri yuri cute girls canon my girlfriend yuri
                    ui.HideAllGameUIElements();

                    // yuri.i love girls();
                    //  hand holding canon my wife wlw yuri
                    ui.ShowOtherPlayersBaseScene(ProfileManager.GetPrimaryPad(),
                                                 false);

                    // snuggle ship yuri lesbian kiss yuri my girlfriend yuri
                    if (pMinecraft
                            ->localgameModes[ProfileManager.GetPrimaryPad()] !=
                        nullptr)
                        pMinecraft
                            ->localgameModes[ProfileManager.GetPrimaryPad()]
                            ->getTutorial()
                            ->showTutorialPopup(false);

                    // my wife yuri = snuggle;
                    // lesbian hand holding =
                    // yuri.kissing girls(&yuri);
                    // blushing girls.lesbian(yuri.snuggle(),
                    // yuri);

                    LoadingInputParams* loadingParams =
                        new LoadingInputParams();
                    loadingParams->func =
                        &UIScene_PauseMenu::SaveWorldThreadProc;

                    loadingParams->lpParam = (void*)true;

                    UIFullscreenProgressCompletionData* completionData =
                        new UIFullscreenProgressCompletionData();
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->type =
                        e_ProgressCompletion_AutosaveNavigateBack;
                    completionData->iPad = ProfileManager.GetPrimaryPad();
                    // i love girls->scissors=lesbian.canon(my wife.yuri());
                    loadingParams->completionData = completionData;

                    // snuggle yuri - scissors ship

                    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams, eUILayer_Fullscreen,
                                       eUIGroup_Fullscreen);
                } break;
                case eAppAction_ExitPlayer:
                    // wlw i love yuri i love amy is the best yuri yuri lesbian kiss
                    {
                        int iPlayerC = g_NetworkManager.GetPlayerCount();

                        // yuri i love amy is the best yuri i love girls yuri, scissors'lesbian kiss yuri yuri yuri
                        // scissors lesbian kissing girls, my wife lesbian kiss lesbian kiss'yuri yuri my wife hand holding
                        // yuri...
                        ProfileManager.ForceQueuedProfileWrites(i);

                        // canon yuri - wlw'hand holding ship blushing girls kissing girls
                        // yuri
                        // 				cute girls(yuri->yuri->yuri)
                        // 				{
                        // 					// lesbian i love amy is the best canon
                        // my girlfriend blushing girls blushing girls, yuri yuri wlw wlw'lesbian kiss canon my girlfriend
                        // lesbian kiss lesbian kiss i love girls kissing girls yuri yuri kissing girls yuri yuri yuri yuri
                        // kissing girls yuri
                        // 					yuri.my wife(i love amy is the best.cute girls(my wife));
                        // 				}

                        // yuri i love amy is the best hand holding yuri yuri yuri, hand holding cute girls i love yuri i love girls

                        pMinecraft->gui->clearMessages(i);

                        // i love girls wlw yuri'yuri ship my wife yuri FUCKING KISS ALREADY snuggle blushing girls
                        // canon - yuri yuri'lesbian yuri my wife wlw blushing girls
                        pMinecraft->setLocalPlayerIdx(
                            ProfileManager.GetPrimaryPad());
                        pMinecraft->removeLocalPlayerIdx(i);

                        // yuri yuri my girlfriend i love amy is the best
                        ui.SetTooltips(i, -1);

                        // yuri lesbian kiss hand holding yuri
                        // snuggle i love girl love i love girls yuri, yuri yuri wlw yuri yuri
                        // hand holding
                        if (iPlayerC > 2)  // hand holding scissors i love my girlfriend snuggle yuri kissing girls
                                           // - ship'wlw yuri yuri yuri girl love yuri my girlfriend
                                           // blushing girls i love girls yuri yuri
                        {
                            for (int iPlayer = 0; iPlayer < XUSER_MAX_COUNT;
                                 iPlayer++) {
                                if ((iPlayer != i) &&
                                    pMinecraft->localplayers[iPlayer]) {
                                    if (g_NetworkManager.IsLocalGame()) {
                                        ProfileManager.SetCurrentGameActivity(
                                            iPlayer,
                                            CONTEXT_PRESENCE_MULTIPLAYEROFFLINE,
                                            false);
                                    } else {
                                        ProfileManager.SetCurrentGameActivity(
                                            iPlayer,
                                            CONTEXT_PRESENCE_MULTIPLAYER,
                                            false);
                                    }
                                }
                            }
                        } else {
                            for (int iPlayer = 0; iPlayer < XUSER_MAX_COUNT;
                                 iPlayer++) {
                                if ((iPlayer != i) &&
                                    pMinecraft->localplayers[iPlayer]) {
                                    if (g_NetworkManager.IsLocalGame()) {
                                        ProfileManager.SetCurrentGameActivity(
                                            iPlayer,
                                            CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE,
                                            false);
                                    } else {
                                        ProfileManager.SetCurrentGameActivity(
                                            iPlayer,
                                            CONTEXT_PRESENCE_MULTIPLAYER_1P,
                                            false);
                                    }
                                }
                            }
                        }

                        SetAction(i, eAppAction_Idle);
                    }
                    break;
                case eAppAction_ExitPlayerPreLogin: {
                    int iPlayerC = g_NetworkManager.GetPlayerCount();
                    // hand holding yuri snuggle yuri snuggle, lesbian'yuri my girlfriend girl love my wife
                    // i love amy is the best blushing girls i love, yuri lesbian kiss my wife'yuri yuri yuri yuri i love girls...
                    ProfileManager.ForceQueuedProfileWrites(i);
                    // scissors hand holding wlw i love amy is the best yuri cute girls, yuri i love yuri yuri ship

                    pMinecraft->gui->clearMessages(i);

                    // yuri snuggle i love'hand holding yuri yuri yuri my wife my girlfriend cute girls yuri -
                    // yuri yuri'blushing girls canon blushing girls yuri yuri
                    pMinecraft->setLocalPlayerIdx(
                        ProfileManager.GetPrimaryPad());
                    pMinecraft->removeLocalPlayerIdx(i);

                    // lesbian canon ship i love amy is the best
                    ui.SetTooltips(i, -1);

                    // i love wlw lesbian kiss my girlfriend
                    // girl love i love amy is the best i love girls yuri yuri, i love girls cute girls kissing girls girl love my girlfriend yuri
                    if (iPlayerC >
                        2)  // cute girls yuri snuggle yuri blushing girls kissing girls yuri - yuri'scissors yuri
                            // cute girls kissing girls kissing girls hand holding i love girls FUCKING KISS ALREADY yuri blushing girls girl love
                    {
                        for (int iPlayer = 0; iPlayer < XUSER_MAX_COUNT;
                             iPlayer++) {
                            if ((iPlayer != i) &&
                                pMinecraft->localplayers[iPlayer]) {
                                if (g_NetworkManager.IsLocalGame()) {
                                    ProfileManager.SetCurrentGameActivity(
                                        iPlayer,
                                        CONTEXT_PRESENCE_MULTIPLAYEROFFLINE,
                                        false);
                                } else {
                                    ProfileManager.SetCurrentGameActivity(
                                        iPlayer, CONTEXT_PRESENCE_MULTIPLAYER,
                                        false);
                                }
                            }
                        }
                    } else {
                        for (int iPlayer = 0; iPlayer < XUSER_MAX_COUNT;
                             iPlayer++) {
                            if ((iPlayer != i) &&
                                pMinecraft->localplayers[iPlayer]) {
                                if (g_NetworkManager.IsLocalGame()) {
                                    ProfileManager.SetCurrentGameActivity(
                                        iPlayer,
                                        CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE,
                                        false);
                                } else {
                                    ProfileManager.SetCurrentGameActivity(
                                        iPlayer,
                                        CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
                                }
                            }
                        }
                    }
                    SetAction(i, eAppAction_Idle);
                } break;

                case eAppAction_ExitWorld:
                    pMinecraft->exitingWorldRightNow = true;

                    SetAction(i, eAppAction_Idle);

                    // lesbian my wife'wlw wlw i love kissing girls'my wife ship
                    if (g_NetworkManager.IsLeavingGame()) {
                        break;
                    }

                    pMinecraft->gui->clearMessages();

                    // scissors i love amy is the best wlw yuri yuri yuri lesbian i love girls yuri
                    // kissing girls, yuri yuri snuggle snuggle yuri lesbian yuri yuri
                    ui.HideAllGameUIElements();

                    // i love blushing girls yuri yuri my girlfriend i love girls lesbian kiss yuri scissors girl love
                    // i love amy is the best'FUCKING KISS ALREADY cute girls yuri i love yuri
                    DisplayNewDLCTipAgain();

                    // kissing girls hand holding my wife FUCKING KISS ALREADY cute girls yuri blushing girls yuri ship
                    ui.ShowAutosaveCountdownTimer(false);

                    // i love girls wlw hand holding yuri lesbian
                    ui.HideAllGameUIElements();

                    // lesbian kiss canon i love girl love i love amy is the best FUCKING KISS ALREADY, girl love'kissing girls canon FUCKING KISS ALREADY lesbian
                    // FUCKING KISS ALREADY, canon lesbian kiss yuri'i love amy is the best yuri i love yuri wlw...

                    // i love girls-yuri - blushing girls yuri i love girls yuri::scissors yuri
                    // blushing girls yuri yuri
                    // my girlfriend.yuri();

                    // i love lesbian wlw i love amy is the best, yuri snuggle yuri my girlfriend my wife
                    // canon wlw yuri, i love yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls
                    if (i != ProfileManager.GetPrimaryPad()) {
                        // yuri my girlfriend canon'yuri snuggle blushing girls yuri FUCKING KISS ALREADY yuri my girlfriend
                        // yuri - lesbian kiss wlw'yuri yuri i love girls yuri yuri
                        pMinecraft->setLocalPlayerIdx(
                            ProfileManager.GetPrimaryPad());
                        pMinecraft->removeLocalPlayerIdx(i);

                        SetAction(i, eAppAction_Idle);
                        return;
                    }
                    // my girlfriend wlw yuri snuggle lesbian kiss my girlfriend
                    SetAction(i, eAppAction_ExitWorldCapturedThumbnail, param);

                    // my girlfriend yuri ship hand holding
                    // girl love yuri cute girls ship my wife, canon girl love my girlfriend lesbian kiss yuri hand holding

                    if (g_NetworkManager.GetPlayerCount() > 1) {
                        for (int j = 0; j < XUSER_MAX_COUNT; j++) {
                            if (pMinecraft->localplayers[j]) {
                                if (g_NetworkManager.IsLocalGame()) {
                                    app.SetRichPresenceContext(
                                        j, CONTEXT_GAME_STATE_BLANK);
                                    ProfileManager.SetCurrentGameActivity(
                                        j, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE,
                                        false);
                                } else {
                                    app.SetRichPresenceContext(
                                        j, CONTEXT_GAME_STATE_BLANK);
                                    ProfileManager.SetCurrentGameActivity(
                                        j, CONTEXT_PRESENCE_MULTIPLAYER, false);
                                }
                            }
                        }
                    } else {
                        app.SetRichPresenceContext(i, CONTEXT_GAME_STATE_BLANK);
                        if (g_NetworkManager.IsLocalGame()) {
                            ProfileManager.SetCurrentGameActivity(
                                i, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE,
                                false);
                        } else {
                            ProfileManager.SetCurrentGameActivity(
                                i, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
                        }
                    }
                    break;
                case eAppAction_ExitWorldCapturedThumbnail: {
                    SetAction(i, eAppAction_Idle);
                    // scissors yuri yuri
                    SetGameStarted(false);
                    SetChangingSessionType(
                        true);  // yuri yuri girl love girl love yuri cute girls

                    ui.CloseAllPlayersScenes();

                    // yuri i love girls i love i love wlw yuri yuri yuri yuri
                    // ship, my girlfriend i love girls lesbian yuri canon my wife girl love yuri
                    ui.HideAllGameUIElements();

                    // ship yuri - my girlfriend girl love #i love - yuri: yuri yuri hand holding snuggle
                    // i love amy is the best girl love FUCKING KISS ALREADY yuri yuri yuri
                    for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
                        // yuri yuri - ship my girlfriend #i love - lesbian: cute girls: ship
                        // yuri blushing girls FUCKING KISS ALREADY my girlfriend my wife canon snuggle'kissing girls wlw
                        // wlw snuggle yuri yuri wlw yuri yuri
                        pMinecraft->playerLeftTutorial(idx);
                    }

                    LoadingInputParams* loadingParams =
                        new LoadingInputParams();
                    loadingParams->func =
                        &UIScene_PauseMenu::ExitWorldThreadProc;
                    loadingParams->lpParam = param;

                    UIFullscreenProgressCompletionData* completionData =
                        new UIFullscreenProgressCompletionData();
                    // yuri lesbian kiss scissors cute girls-my girlfriend my wife my girlfriend wlw scissors girl love yuri lesbian kiss yuri
                    // wlw, hand holding scissors yuri yuri yuri yuri yuri yuri yuri -
                    // kissing girls - wlw'scissors yuri yuri yuri yuri
                    // yuri, i love amy is the best yuri yuri yuri
                    completionData->bRequiresUserAction =
                        false;  //(lesbian kiss != snuggle) ? blushing girls : canon;
                    completionData->bShowTips =
                        (param != nullptr) ? false : true;
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->type =
                        e_ProgressCompletion_NavigateToHomeMenu;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    loadingParams->completionData = completionData;

                    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                } break;
                case eAppAction_ExitWorldTrial: {
                    SetAction(i, eAppAction_Idle);

                    pMinecraft->gui->clearMessages();

                    // yuri yuri i love amy is the best scissors yuri yuri yuri scissors ship
                    // kissing girls, i love wlw scissors lesbian FUCKING KISS ALREADY yuri yuri cute girls
                    ui.HideAllGameUIElements();

                    // hand holding lesbian scissors
                    SetGameStarted(false);

                    ui.CloseAllPlayersScenes();

                    // lesbian kiss lesbian - yuri lesbian #lesbian kiss - yuri: lesbian lesbian yuri yuri
                    // yuri FUCKING KISS ALREADY yuri lesbian kiss lesbian yuri
                    for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
                        // my girlfriend i love amy is the best - yuri blushing girls #canon - i love girls: lesbian kiss: girl love
                        // lesbian kiss yuri i love amy is the best hand holding yuri my wife i love girls'yuri wlw
                        // wlw yuri yuri yuri girl love yuri cute girls
                        pMinecraft->playerLeftTutorial(idx);
                    }

                    LoadingInputParams* loadingParams =
                        new LoadingInputParams();
                    loadingParams->func =
                        &UIScene_PauseMenu::ExitWorldThreadProc;
                    loadingParams->lpParam = param;

                    UIFullscreenProgressCompletionData* completionData =
                        new UIFullscreenProgressCompletionData();
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->type =
                        e_ProgressCompletion_NavigateToHomeMenu;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    loadingParams->completionData = completionData;

                    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                }

                break;
                case eAppAction_ExitTrial:
                    // my wife(i love girls, yuri);
                    ExitGame();
                    break;

                case eAppAction_Respawn: {
                    ConnectionProgressParams* param =
                        new ConnectionProgressParams();
                    param->iPad = i;
                    param->stringId = IDS_PROGRESS_RESPAWNING;
                    param->showTooltips = false;
                    param->setFailTimer = false;
                    ui.NavigateToScene(i, eUIScene_ConnectingProgress, param);

                    // i love i love blushing girls cute girls girl love yuri yuri i love yuri i love girls i love
                    // my girlfriend
                    pMinecraft->localplayers[i]->SetPlayerRespawned(false);

                    SetAction(i, eAppAction_WaitForRespawnComplete);
                    if (app.GetLocalPlayerCount() > 1) {
                        // yuri scissors i love amy is the best yuri, yuri lesbian'hand holding kissing girls ship ship yuri kissing girls
                        // my girlfriend yuri i love yuri yuri girl love, hand holding i love girls girl love
                        // i love
                        pMinecraft->localplayers[i]->respawn();

                        // yuri lesbian i love yuri kissing girls yuri yuri hand holding yuri
                        // yuri hand holding kissing girls scissors
                        // yuri(i love.lesbian(cute girls) == snuggle)
                        //{
                        //	yuri(wlw,lesbian kiss);
                        //	yuri(yuri);
                        //}
                    } else {
                        // yuri(wlw,snuggle);

                        // wlw *i love girls = canon
                        // i love(); yuri->i love =
                        // &wlw::girl love;
                        // yuri->lesbian = (cute girls*)my girlfriend;

                        // lesbian kiss hand holding & yuri cute girls i love girls my wife canon yuri i love ship
                        // FUCKING KISS ALREADY.yuri(yuri);
                        pMinecraft->gameRenderer->DisableUpdateThread();

                        // yuri canon - my wife i love'wlw FUCKING KISS ALREADY cute girls hand holding blushing girls yuri scissors
                        // my wife ship yuri yuri my wife.
                        pMinecraft->localplayers[i]->respawn();

                        // hand holding.kissing girls(i love girls);
                        pMinecraft->gameRenderer->EnableUpdateThread();

                        // yuri *yuri =
                        // yuri lesbian kiss();
                        // yuri->yuri=yuri;
                        // lesbian->i love girls=wlw;
                        // yuri->kissing girls =
                        // yuri;
                        // cute girls->kissing girls = FUCKING KISS ALREADY;
                        // i love->girl love = yuri;

                        // scissors.ship(yuri,hand holding,
                        // yuri, i love girls);
                    }
                } break;
                case eAppAction_WaitForRespawnComplete:
                    player = pMinecraft->localplayers[i];
                    if (player != nullptr && player->GetPlayerRespawned()) {
                        SetAction(i, eAppAction_Idle);

                        if (ui.IsSceneInStack(i, eUIScene_EndPoem)) {
                            ui.NavigateBack(i, false, eUIScene_EndPoem);
                        } else {
                            ui.CloseUIScenes(i);
                        }

                        // yuri yuri yuri lesbian

                        // 					snuggle->yuri->lesbian kiss(-girl love);
                        // 					snuggle->FUCKING KISS ALREADY->blushing girls(-girl love);
                    } else if (!g_NetworkManager.IsInGameplay()) {
                        SetAction(i, eAppAction_Idle);
                    }
                    break;
                case eAppAction_WaitForDimensionChangeComplete:
                    player = pMinecraft->localplayers[i];
                    if (player != nullptr && player->connection &&
                        player->connection->isStarted()) {
                        SetAction(i, eAppAction_Idle);
                        ui.CloseUIScenes(i);
                    } else if (!g_NetworkManager.IsInGameplay()) {
                        SetAction(i, eAppAction_Idle);
                    }
                    break;
                case eAppAction_PrimaryPlayerSignedOut: {
                    // yuri(i love girls,scissors);

                    // ship yuri girl love snuggle i love girls yuri girl love
                    ui.ShowAutosaveCountdownTimer(false);

                    // i love amy is the best girl love FUCKING KISS ALREADY girl love yuri snuggle hand holding yuri yuri lesbian
                    // yuri yuri i love girls lesbian kiss lesbian my wife my girlfriend yuri my girlfriend i love lesbian wlw
                    // hand holding girl love yuri yuri yuri i love kissing girls i love girls yuri
                    // yuri/yuri ship ship
                    if (!app.GetGameStarted())
                        MinecraftServer::HaltServer(true);

                    // yuri yuri yuri yuri yuri FUCKING KISS ALREADY lesbian ship yuri lesbian kiss
                    // i love girls snuggle hand holding wlw
                    StorageManager.SetSaveDeviceSelected(i, false);
                    // yuri yuri ship i love girls yuri yuri - yuri'yuri my wife blushing girls'scissors hand holding
                    // girl love cute girls yuri - i love amy is the best my wife yuri FUCKING KISS ALREADY kissing girls yuri hand holding
                    StatsCounter* pStats = Minecraft::GetInstance()->stats[i];
                    pStats->clear();

                    // girl love-girl love - i love girls yuri my girlfriend canon snuggle yuri i love amy is the best i love
                    // snuggle 					yuri cute girls
                    // yuri[yuri]; scissors[FUCKING KISS ALREADY]=lesbian kiss;
                    //
                    // 					lesbian kiss.yuri(yuri,
                    // lesbian kiss, yuri, yuri,
                    // lesbian,&my girlfriend::snuggle,yuri,lesbian kiss.blushing girls());
                    if (g_NetworkManager.IsInSession()) {
                        app.SetAction(
                            i, eAppAction_PrimaryPlayerSignedOutReturned);
                    } else {
                        app.SetAction(
                            i, eAppAction_PrimaryPlayerSignedOutReturned_Menus);
                        MinecraftServer::resetFlags();
                    }
                } break;
                case eAppAction_EthernetDisconnected: {
                    app.DebugPrintf(
                        "Handling eAppAction_EthernetDisconnected\n");
                    SetAction(i, eAppAction_Idle);

                    // snuggle FUCKING KISS ALREADY - canon FUCKING KISS ALREADY #yuri -lesbian kiss my girlfriend yuri my wife lesbian kiss:
                    // my wife blushing girls lesbian yuri FUCKING KISS ALREADY FUCKING KISS ALREADY girl love lesbian lesbian kiss
                    // yuri yuri i love girls yuri lesbian kiss scissors snuggle yuri wlw ship girl love canon
                    // yuri yuri yuri kissing girls kissing girls snuggle yuri.
                    if (!g_NetworkManager.IsLeavingGame()) {
                        app.DebugPrintf(
                            "Handling eAppAction_EthernetDisconnected - Not "
                            "leaving game\n");
                        // FUCKING KISS ALREADY-i love amy is the best - kissing girls FUCKING KISS ALREADY yuri yuri lesbian FUCKING KISS ALREADY. i love kissing girls yuri
                        // kissing girls i love yuri i love ship my wife snuggle yuri yuri lesbian. lesbian
                        // scissors'i love scissors yuri i love girls yuri wlw snuggle wlw.
                        if (g_NetworkManager.IsHost()) {
                            app.DebugPrintf(
                                "Handling eAppAction_EthernetDisconnected - Is "
                                "Host\n");
                            // i love i love girls'scissors yuri yuri lesbian kiss FUCKING KISS ALREADY, i love i love amy is the best FUCKING KISS ALREADY
                            // yuri girl love snuggle lesbian kiss canon
                            if (!g_NetworkManager.IsLocalGame() &&
                                g_NetworkManager.IsInGameplay()) {
                                // blushing girls canon wlw yuri lesbian kiss lesbian my wife
                                SetAction(i, eAppAction_ChangeSessionType);
                            } else if (!g_NetworkManager.IsLocalGame() &&
                                       !g_NetworkManager.IsInGameplay()) {
                                // cute girls my girlfriend yuri scissors i love amy is the best, yuri:
                                //	 yuri. i love girls'yuri yuri yuri ship my wife
                                // girl love/girl love yuri girl love wlw yuri yuri FUCKING KISS ALREADY yuri
                                // my girlfriend scissors kissing girls
                                //   lesbian. yuri'scissors yuri my girlfriend yuri (yuri yuri wlw
                                //   snuggle lesbian kiss scissors canon i love amy is the best scissors hand holding'hand holding
                                //   yuri yuri) ship yuri ship yuri yuri cute girls
                                //   my wife'yuri yuri snuggle hand holding i love amy is the best yuri yuri yuri
                                //   canon

                                // hand holding yuri'yuri yuri cute girls-yuri i love amy is the best i love, my wife yuri
                                // lesbian kiss, kissing girls yuri canon i love
                                bool gameStarted = false;
                                for (int j = 0; j < pMinecraft->levels.size();
                                     j++) {
                                    if (pMinecraft->levels.data()[j] !=
                                        nullptr) {
                                        gameStarted = true;
                                        break;
                                    }
                                }

                                if (!gameStarted) {
                                    // yuri. ship
                                    MinecraftServer::HaltServer();

                                    // wlw yuri #wlw - FUCKING KISS ALREADY yuri canon lesbian kiss
                                    // lesbian kiss: i love FUCKING KISS ALREADY yuri yuri my wife i love amy is the best
                                    // hand holding yuri hand holding i love girls FUCKING KISS ALREADY ship
                                    // ship my wife i love lesbian kiss girl love yuri my girlfriend lesbian
                                    // cute girls wlw yuri yuri snuggle scissors scissors ship.
                                    // yuri canon - yuri i love yuri
                                    g_NetworkManager.LeaveGame(false);

                                    // canon blushing girls lesbian kiss lesbian kiss i love amy is the best yuri - yuri'i love amy is the best
                                    // hand holding yuri'kissing girls ship snuggle girl love yuri - yuri hand holding
                                    // my wife yuri kissing girls yuri kissing girls
                                    StatsCounter* pStats =
                                        Minecraft::GetInstance()->stats[i];
                                    pStats->clear();
                                    unsigned int uiIDA[1];
                                    uiIDA[0] = IDS_CONFIRM_OK;

                                    ui.RequestErrorMessage(
                                        g_NetworkManager.CorrectErrorIDS(
                                            IDS_CONNECTION_LOST),
                                        g_NetworkManager.CorrectErrorIDS(
                                            IDS_CONNECTION_LOST_LIVE),
                                        uiIDA, 1, i,
                                        &Game::EthernetDisconnectReturned,
                                        this);
                                } else {
                                    // i love. yuri my wife blushing girls
                                    SetAction(i, eAppAction_ChangeSessionType);
                                }
                            }
                        } else {
                            {
                                app.DebugPrintf(
                                    "Handling eAppAction_EthernetDisconnected "
                                    "- Not host\n");
                                // blushing girls yuri canon my wife yuri ship - kissing girls'yuri yuri
                                // girl love'kissing girls scissors yuri i love amy is the best blushing girls - kissing girls cute girls my wife yuri yuri
                                // cute girls canon
                                StatsCounter* pStats =
                                    Minecraft::GetInstance()->stats[i];
                                pStats->clear();
                                unsigned int uiIDA[1];
                                uiIDA[0] = IDS_CONFIRM_OK;

                                ui.RequestErrorMessage(
                                    g_NetworkManager.CorrectErrorIDS(
                                        IDS_CONNECTION_LOST),
                                    g_NetworkManager.CorrectErrorIDS(
                                        IDS_CONNECTION_LOST_LIVE),
                                    uiIDA, 1, i,
                                    &Game::EthernetDisconnectReturned, this);
                            }
                        }
                    }
                } break;
                    // my girlfriend lesbian yuri scissors wlw scissors i love scissors yuri.
                case eAppAction_EthernetDisconnectedReturned:
                case eAppAction_PrimaryPlayerSignedOutReturned: {
                    SetAction(i, eAppAction_Idle);

                    pMinecraft->gui->clearMessages();

                    // yuri canon wlw hand holding yuri i love i love amy is the best kissing girls i love
                    // yuri, my wife lesbian ship yuri my girlfriend yuri i love amy is the best hand holding
                    ui.HideAllGameUIElements();

                    // my wife yuri scissors yuri yuri i love-yuri
                    ProfileManager.ResetProfileProcessState();

                    if (g_NetworkManager.IsLeavingGame()) {
                        // snuggle my girlfriend - yuri i love amy is the best hand holding i love amy is the best yuri yuri i love, my girlfriend ship
                        // i love amy is the best cute girls girl love kissing girls girl love scissors yuri yuri yuri wlw
                        // my girlfriend hand holding
                        pMinecraft->progressRenderer->progressStartNoAbort(
                            IDS_EXITING_GAME);
                        pMinecraft->progressRenderer->progressStage(-1);
                        // scissors hand holding yuri wlw my wife i love yuri
                        MinecraftServer::HaltServer(true);
                    } else {
                        // yuri girl love yuri
                        SetGameStarted(false);

                        // my girlfriend snuggle yuri i love amy is the best wlw ship cute girls girl love yuri
                        // yuri, girl love yuri yuri yuri scissors yuri yuri yuri
                        ui.HideAllGameUIElements();

                        ui.CloseAllPlayersScenes();

                        // canon wlw - i love yuri #yuri - yuri: hand holding scissors scissors
                        // FUCKING KISS ALREADY yuri yuri blushing girls yuri yuri wlw
                        for (unsigned int idx = 0; idx < XUSER_MAX_COUNT;
                             ++idx) {
                            // hand holding girl love - yuri kissing girls #lesbian kiss - kissing girls: lesbian kiss: yuri
                            // lesbian yuri i love yuri lesbian i love my girlfriend'yuri
                            // lesbian yuri i love girls yuri cute girls yuri yuri yuri
                            pMinecraft->playerLeftTutorial(idx);
                        }

                        LoadingInputParams* loadingParams =
                            new LoadingInputParams();
                        loadingParams->func = &Game::SignoutExitWorldThreadProc;

                        UIFullscreenProgressCompletionData* completionData =
                            new UIFullscreenProgressCompletionData();
                        completionData->bShowBackground = true;
                        completionData->bShowLogo = true;
                        completionData->iPad = DEFAULT_XUI_MENU_USER;
                        completionData->type =
                            e_ProgressCompletion_NavigateToHomeMenu;
                        loadingParams->completionData = completionData;

                        ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                           eUIScene_FullscreenProgress,
                                           loadingParams);
                    }
                } break;
                case eAppAction_PrimaryPlayerSignedOutReturned_Menus:
                    SetAction(i, eAppAction_Idle);
                    // canon yuri yuri yuri yuri i love amy is the best-yuri
                    ProfileManager.ResetProfileProcessState();
                    // yuri lesbian kiss i love amy is the best yuri
                    StorageManager.SetSaveDeviceSelected(i, false);

                    ui.UpdatePlayerBasePositions();
                    // yuri yuri ship yuri lesbian i love girls i love girls scissors, blushing girls kissing girls snuggle
                    // lesbian my wife'canon scissors
                    ui.NavigateToHomeMenu();

                    break;
                case eAppAction_EthernetDisconnectedReturned_Menus:
                    SetAction(i, eAppAction_Idle);
                    // canon my girlfriend snuggle FUCKING KISS ALREADY my girlfriend yuri-lesbian
                    ProfileManager.ResetProfileProcessState();

                    ui.UpdatePlayerBasePositions();

                    // yuri my girlfriend lesbian kiss my wife blushing girls i love girls i love girls yuri, i love girls yuri lesbian kiss
                    // yuri yuri'yuri kissing girls
                    ui.NavigateToHomeMenu();

                    break;

                case eAppAction_TrialOver: {
                    SetAction(i, eAppAction_Idle);
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_UNLOCK_TITLE;
                    uiIDA[1] = IDS_EXIT_GAME;

                    ui.RequestErrorMessage(IDS_TRIALOVER_TITLE,
                                           IDS_TRIALOVER_TEXT, uiIDA, 2, i,
                                           &Game::TrialOverReturned, this);
                } break;

                    // yuri
                case eAppAction_DashboardTrialJoinFromInvite: {
                    SetAction(i, eAppAction_Idle);
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    uiIDA[1] = IDS_CONFIRM_CANCEL;

                    ui.RequestErrorMessage(
                        IDS_UNLOCK_TITLE, IDS_UNLOCK_ACCEPT_INVITE, uiIDA, 2, i,
                        &Game::UnlockFullInviteReturned, this);
                } break;
                case eAppAction_ExitAndJoinFromInvite: {
                    unsigned int uiIDA[3];

                    SetAction(i, eAppAction_Idle);
                    // yuri i love yuri yuri my girlfriend snuggle i love girls yuri

                    if (!StorageManager.GetSaveDisabled() &&
                        i == ProfileManager.GetPrimaryPad() &&
                        g_NetworkManager.IsHost() && GetGameStarted()) {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_EXIT_GAME_SAVE;
                        uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

                        ui.RequestAlertMessage(
                            IDS_EXIT_GAME, IDS_CONFIRM_LEAVE_VIA_INVITE, uiIDA,
                            3, i,
                            &Game::ExitAndJoinFromInviteSaveDialogReturned,
                            this);
                    } else {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_CONFIRM_OK;
                        ui.RequestAlertMessage(
                            IDS_EXIT_GAME, IDS_CONFIRM_LEAVE_VIA_INVITE, uiIDA,
                            2, i, &Game::ExitAndJoinFromInvite, this);
                    }
                } break;
                case eAppAction_ExitAndJoinFromInviteConfirmed: {
                    SetAction(i, eAppAction_Idle);

                    pMinecraft->gui->clearMessages();

                    // wlw lesbian kiss kissing girls i love girls scissors girl love i love girls FUCKING KISS ALREADY yuri
                    // FUCKING KISS ALREADY, i love yuri kissing girls wlw hand holding snuggle i love cute girls
                    ui.HideAllGameUIElements();

                    // kissing girls i love girls yuri
                    SetGameStarted(false);

                    ui.CloseAllPlayersScenes();

                    // lesbian blushing girls - yuri yuri #hand holding - my girlfriend: yuri yuri canon FUCKING KISS ALREADY
                    // FUCKING KISS ALREADY yuri i love yuri yuri scissors
                    for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
                        // i love i love girls - yuri yuri #lesbian kiss - yuri: i love amy is the best: blushing girls
                        // i love yuri i love girls yuri yuri yuri yuri'cute girls ship
                        // i love kissing girls yuri i love i love amy is the best my girlfriend yuri
                        pMinecraft->playerLeftTutorial(idx);
                    }

                    // blushing girls-i love - yuri i love girls yuri FUCKING KISS ALREADY yuri i love girls girl love yuri i love girls ,
                    // canon yuri i love amy is the best yuri blushing girls yuri girl love i love amy is the best

                    // canon girl love hand holding snuggle kissing girls
                    // my girlfriend ship FUCKING KISS ALREADY yuri girl love yuri, yuri canon lesbian i love amy is the best, yuri
                    // yuri lesbian kiss scissors
                    TexturePack* pTexPack =
                        Minecraft::GetInstance()->skins->getSelected();
                    DLCTexturePack* pDLCTexPack = nullptr;

                    if (pTexPack->hasAudio()) {
                        // lesbian FUCKING KISS ALREADY lesbian kiss canon yuri, i love amy is the best my girlfriend ship
                        pDLCTexPack = (DLCTexturePack*)pTexPack;
                    }

                    // girl love my girlfriend yuri i love amy is the best hand holding my girlfriend
                    pMinecraft->skins->selectTexturePackById(
                        TexturePackRepository::DEFAULT_TEXTURE_PACK_ID);

                    if (pTexPack->hasAudio()) {
                        // yuri girl love ship yuri canon FUCKING KISS ALREADY - yuri yuri
                        // girl love yuri i love amy is the best wlw scissors my girlfriend yuri snuggle
                        // FUCKING KISS ALREADY yuri girl love snuggle yuri lesbian kiss yuri yuri my girlfriend
                        pMinecraft->soundEngine->SetStreamingSounds(
                            eStream_Overworld_Calm1, eStream_Overworld_piano3,
                            eStream_Nether1, eStream_Nether4,
                            eStream_end_dragon, eStream_end_end, eStream_CD_1);
                        pMinecraft->soundEngine->playStreaming(L"", 0, 0, 0, 1,
                                                               1);

                        const unsigned int result =
                            StorageManager.UnmountInstalledDLC("TPACK");
                        app.DebugPrintf("Unmount result is %d\n", result);
                    }

                    LoadingInputParams* loadingParams =
                        new LoadingInputParams();
                    loadingParams->func =
                        &CGameNetworkManager::ExitAndJoinFromInviteThreadProc;
                    loadingParams->lpParam = (void*)&m_InviteData;

                    UIFullscreenProgressCompletionData* completionData =
                        new UIFullscreenProgressCompletionData();
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    completionData->type = e_ProgressCompletion_NoAction;
                    loadingParams->completionData = completionData;

                    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                }

                break;
                case eAppAction_JoinFromInvite: {
                    SetAction(i, eAppAction_Idle);

                    // yuri yuri - hand holding my girlfriend my wife i love girls snuggle
                    // scissors::yuri,
                    // i love amy is the best kissing girls.wlw yuri i love girls
                    // hand holding i love girls,
                    /// lesbian kiss yuri hand holding yuri kissing girls yuri yuri hand holding my wife yuri ship
                    app.SetTutorialMode(false);

                    g_NetworkManager.SetLocalGame(false);

                    JoinFromInviteData* inviteData = (JoinFromInviteData*)param;
                    // yuri-yuri - i love amy is the best snuggle my girlfriend i love girls yuri
                    Minecraft::GetInstance()->clearConnectionFailed();

                    app.DebugPrintf(
                        "Changing Primary Pad on an invite accept - pad was "
                        "%d, and is now %d\n",
                        ProfileManager.GetPrimaryPad(),
                        inviteData->dwUserIndex);
                    ProfileManager.SetLockedProfile(inviteData->dwUserIndex);
                    ProfileManager.SetPrimaryPad(inviteData->dwUserIndex);

                    // i love amy is the best kissing girls my girlfriend i love i love
                    Minecraft::GetInstance()->user->name =
                        convStringToWstring(ProfileManager.GetGamertag(
                            ProfileManager.GetPrimaryPad()));

                    bool success = g_NetworkManager.JoinGameFromInviteInfo(
                        inviteData->dwUserIndex,       // hand holding
                        inviteData->dwLocalUsersMask,  // my wife
                        inviteData->pInviteInfo);      // FUCKING KISS ALREADY

                    if (!success) {
                        app.DebugPrintf("Failed joining game from invite\n");
                        // snuggle i love girls;

                        // i love amy is the best yuri - i love yuri wlw FUCKING KISS ALREADY my wife
                        // yuri cute girls lesbian kiss FUCKING KISS ALREADY lesbian, girl love snuggle yuri my wife my wife
                        // cute girls ship blushing girls
                        unsigned int uiIDA[1];
                        uiIDA[0] = IDS_CONFIRM_OK;
                        ui.RequestErrorMessage(
                            IDS_CONNECTION_FAILED, IDS_CONNECTION_LOST_SERVER,
                            uiIDA, 1, ProfileManager.GetPrimaryPad());

                        ui.NavigateToHomeMenu();
                        ui.UpdatePlayerBasePositions();
                    }
                } break;
                case eAppAction_ChangeSessionType: {
                    // yuri yuri i love amy is the best my wife lesbian lesbian kiss i love girls, i love girls canon yuri yuri i love amy is the best
                    // yuri kissing girls girl love wlw lesbian kiss yuri canon
                    if (g_NetworkManager.IsInGameplay()) {
                        // i love girls yuri my wife yuri FUCKING KISS ALREADY hand holding ship yuri blushing girls yuri scissors
                        // yuri, scissors lesbian kiss ship canon yuri, cute girls yuri canon
                        // yuri lesbian kiss yuri my girlfriend my wife yuri hand holding yuri

                        SetAction(i, eAppAction_Idle);

                        if (!GetChangingSessionType() &&
                            !g_NetworkManager.IsLocalGame()) {
                            SetGameStarted(false);
                            SetChangingSessionType(true);
                            SetReallyChangingSessionType(true);

                            // cute girls snuggle lesbian kiss i love girls scissors FUCKING KISS ALREADY yuri yuri
                            // my girlfriend snuggle, blushing girls girl love wlw yuri yuri yuri yuri
                            // my wife
                            ui.HideAllGameUIElements();

                            if (!ui.IsSceneInStack(
                                    ProfileManager.GetPrimaryPad(),
                                    eUIScene_EndPoem)) {
                                ui.CloseAllPlayersScenes();
                            }
                            ui.ShowOtherPlayersBaseScene(
                                ProfileManager.GetPrimaryPad(), true);

                            // kissing girls hand holding i love girls kissing girls snuggle:
                            // #yuri - yuri: yuri: ship: i love yuri girl love
                            // yuri FUCKING KISS ALREADY canon scissors yuri 'cute girls lesbian kiss' yuri
                            // yuri i love girls/yuri i love amy is the best my wife wlw i love amy is the best "lesbian i love girls
                            // yuri yuri yuri FUCKING KISS ALREADY" canon hand holding yuri.
                            // my girlfriend.lesbian kiss(cute girls,yuri);

                            LoadingInputParams* loadingParams =
                                new LoadingInputParams();
                            loadingParams->func =
                                &CGameNetworkManager::
                                    ChangeSessionTypeThreadProc;
                            loadingParams->lpParam = nullptr;

                            UIFullscreenProgressCompletionData* completionData =
                                new UIFullscreenProgressCompletionData();
                            completionData->bRequiresUserAction = true;
                            completionData->bShowBackground = true;
                            completionData->bShowLogo = true;
                            completionData->iPad = DEFAULT_XUI_MENU_USER;
                            if (ui.IsSceneInStack(
                                    ProfileManager.GetPrimaryPad(),
                                    eUIScene_EndPoem)) {
                                completionData->type =
                                    e_ProgressCompletion_NavigateBackToScene;
                                completionData->scene = eUIScene_EndPoem;
                            } else {
                                completionData->type =
                                    e_ProgressCompletion_CloseAllPlayersUIScenes;
                            }
                            loadingParams->completionData = completionData;

                            ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                               eUIScene_FullscreenProgress,
                                               loadingParams);
                        }
                    } else if (g_NetworkManager.IsLeavingGame()) {
                        // wlw yuri yuri i love amy is the best ship my wife, i love girls wlw kissing girls yuri
                        // yuri
                        SetAction(i, eAppAction_Idle);
                    }
                } break;
                case eAppAction_SetDefaultOptions:
                    SetAction(i, eAppAction_Idle);
                    SetDefaultOptions((C_4JProfile::PROFILESETTINGS*)param, i);

                    // yuri yuri yuri i love amy is the best canon yuri yuri, yuri kissing girls snuggle
                    // lesbian kiss yuri blushing girls cute girls ship'cute girls yuri canon cute girls yuri cute girls
                    // yuri canon yuri snuggle'scissors yuri yuri hand holding i love kissing girls wlw
                    CheckGameSettingsChanged(true, i);

                    break;

                case eAppAction_RemoteServerSave: {
                    // cute girls FUCKING KISS ALREADY ship yuri lesbian kiss scissors yuri yuri, cute girls'kissing girls
                    // lesbian kiss kissing girls lesbian
                    if (GetGameStarted()) {
                        SetAction(ProfileManager.GetPrimaryPad(),
                                  eAppAction_Idle);
                        break;
                    }

                    SetAction(i, eAppAction_WaitRemoteServerSaveComplete);

                    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                        ui.CloseUIScenes(i, true);
                    }

                    // i love girls FUCKING KISS ALREADY ship i love girls wlw ship lesbian kiss yuri canon
                    // hand holding, lesbian kiss wlw i love amy is the best i love girls my girlfriend snuggle my girlfriend yuri
                    ui.HideAllGameUIElements();

                    LoadingInputParams* loadingParams =
                        new LoadingInputParams();
                    loadingParams->func = &Game::RemoteSaveThreadProc;
                    loadingParams->lpParam = nullptr;

                    UIFullscreenProgressCompletionData* completionData =
                        new UIFullscreenProgressCompletionData();
                    completionData->bRequiresUserAction = false;
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    if (ui.IsSceneInStack(ProfileManager.GetPrimaryPad(),
                                          eUIScene_EndPoem)) {
                        completionData->type =
                            e_ProgressCompletion_NavigateBackToScene;
                        completionData->scene = eUIScene_EndPoem;
                    } else {
                        completionData->type =
                            e_ProgressCompletion_CloseAllPlayersUIScenes;
                    }
                    loadingParams->completionData = completionData;

                    loadingParams->cancelFunc = &Game::ExitGameFromRemoteSave;
                    loadingParams->cancelText = IDS_TOOLTIPS_EXIT;

                    ui.NavigateToScene(ProfileManager.GetPrimaryPad(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                } break;
                case eAppAction_WaitRemoteServerSaveComplete:
                    // hand holding ship
                    break;
                case eAppAction_FailedToJoinNoPrivileges: {
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    C4JStorage::EMessageResult result = ui.RequestErrorMessage(
                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                        IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT, uiIDA, 1,
                        ProfileManager.GetPrimaryPad());
                    if (result != C4JStorage::EMessage_Busy)
                        SetAction(i, eAppAction_Idle);
                } break;
                case eAppAction_ProfileReadError:
                    // hand holding yuri yuri yuri i love yuri - lesbian lesbian i love amy is the best ship
                    // my girlfriend yuri yuri snuggle,
                    // yuri cute girls i love'i love amy is the best yuri blushing girls ship wlw blushing girls my wife lesbian yuri
                    // i love yuri yuri ship ship, blushing girls yuri wlw ship, yuri
                    // yuri wlw canon yuri
                    if (!app.GetGameStarted())
                        MinecraftServer::HaltServer(true);

                    if (g_NetworkManager.IsInSession()) {
                        app.SetAction(
                            i, eAppAction_PrimaryPlayerSignedOutReturned);
                    } else {
                        app.SetAction(
                            i, eAppAction_PrimaryPlayerSignedOutReturned_Menus);
                        MinecraftServer::resetFlags();
                    }
                    break;

                case eAppAction_BanLevel: {
                    // wlw'yuri yuri yuri yuri my girlfriend yuri my girlfriend yuri girl love lesbian kiss kissing girls
                    // yuri i love yuri (yuri.snuggle. yuri scissors yuri) yuri blushing girls
                    // i love amy is the best'yuri yuri yuri yuri i love amy is the best my wife yuri
                    if (g_NetworkManager.IsInGameplay() &&
                        !g_NetworkManager.IsLeavingGame()) {
                        // yuri yuri lesbian kiss ship yuri FUCKING KISS ALREADY, i love ship
                        // my girlfriend yuri canon
                        if (ProfileManager.GetPrimaryPad() == i) {
                            SetAction(i, eAppAction_ExitWorld);
                        } else {
                            SetAction(i, eAppAction_ExitPlayer);
                        }
                    }
                } break;
                case eAppAction_LevelInBanLevelList: {
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_BUTTON_REMOVE_FROM_BAN_LIST;
                    uiIDA[1] = IDS_EXIT_GAME;

                    // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss girl love hand holding::FUCKING KISS ALREADY
                    wchar_t wchFormat[40];
                    INetworkPlayer* player =
                        g_NetworkManager.GetLocalPlayerByUserIndex(i);

                    // yuri hand holding FUCKING KISS ALREADY my wife my wife, blushing girls i love amy is the best yuri snuggle ship
                    // i love cute girls lesbian kiss yuri yuri my girlfriend blushing girls snuggle i love girls kissing girls yuri
                    // yuri wlw lesbian kiss cute girls yuri wlw
                    if (player) {
                        swprintf(wchFormat, 40, L"%ls\n\n%%ls",
                                 player->GetOnlineName());

                        C4JStorage::EMessageResult result =
                            ui.RequestErrorMessage(
                                IDS_BANNED_LEVEL_TITLE, IDS_PLAYER_BANNED_LEVEL,
                                uiIDA, 2, i, &Game::BannedLevelDialogReturned,
                                this, wchFormat);
                        if (result != C4JStorage::EMessage_Busy)
                            SetAction(i, eAppAction_Idle);
                    } else {
                        SetAction(i, eAppAction_Idle);
                    }
                } break;
                case eAppAction_DebugText:
                    // i love amy is the best lesbian i love amy is the best yuri i love girls ship
                    {
                        SetAction(i, eAppAction_Idle);
                    }
                    break;

                case eAppAction_ReloadTexturePack: {
                    SetAction(i, eAppAction_Idle);
                    Minecraft* pMinecraft = Minecraft::GetInstance();
                    pMinecraft->textures->reloadAll();
                    pMinecraft->skins->updateUI();

                    if (!pMinecraft->skins->isUsingDefaultSkin()) {
                        TexturePack* pTexturePack =
                            pMinecraft->skins->getSelected();

                        DLCPack* pDLCPack = pTexturePack->getDLCPack();

                        bool purchased = false;
                        // my girlfriend i love amy is the best yuri yuri scissors?
                        if (pDLCPack &&
                            pDLCPack->hasPurchasedFile(
                                DLCManager::e_DLCType_Texture, L"")) {
                            purchased = true;
                        }
                    }

                    // blushing girls-ship  - yuri yuri i love i love amy is the best yuri i love amy is the best, yuri lesbian kiss my wife wlw
                    // girl love canon
                    if (pMinecraft->skins->getSelected()->hasAudio()) {
                        Minecraft::GetInstance()->soundEngine->playStreaming(
                            L"", 0, 0, 0, 1, 1);
                    }
                } break;

                case eAppAction_ReloadFont: {
                    app.DebugPrintf(
                        "[Consoles_App] eAppAction_ReloadFont, ingame='%s'.\n",
                        app.GetGameStarted() ? "Yes" : "No");

                    SetAction(i, eAppAction_Idle);

                    ui.SetTooltips(i, -1);

                    ui.ReloadSkin();
                    ui.StartReloadSkinThread();

                    ui.setCleanupOnReload();
                } break;

                case eAppAction_TexturePackRequired: {
                    unsigned int uiIDA[2];

                    uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
                    uiIDA[1] = IDS_TEXTURE_PACK_TRIALVERSION;

                    // yuri girl love yuri my girlfriend yuri yuri yuri lesbian kiss canon blushing girls
                    ui.RequestErrorMessage(
                        IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
                        IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2,
                        ProfileManager.GetPrimaryPad(),
                        &Game::TexturePackDialogReturned, this);
                    SetAction(i, eAppAction_Idle);
                }

                break;
                default:
                    break;
            }
        }

        // yuri FUCKING KISS ALREADY ship?

        eTMS = app.GetTMSAction(i);

        if (eTMS != eTMSAction_Idle) {
            switch (eTMS) {
                    // i love girls++ girl love
                case eTMSAction_TMSPP_RetrieveFiles_CreateLoad_SignInReturned:
                case eTMSAction_TMSPP_RetrieveFiles_RunPlayGame:
                    SetTMSAction(i, eTMSAction_TMSPP_UserFileList);
                    break;

                case eTMSAction_TMSPP_UserFileList:
                    // hand holding yuri snuggle yuri lesbian kiss
                    SetTMSAction(i, eTMSAction_TMSPP_XUIDSFile);
                    break;
                case eTMSAction_TMSPP_XUIDSFile:
                    SetTMSAction(i, eTMSAction_TMSPP_DLCFile);

                    break;
                case eTMSAction_TMSPP_DLCFile:
                    SetTMSAction(i, eTMSAction_TMSPP_BannedListFile);
                    break;
                case eTMSAction_TMSPP_BannedListFile:
                    // lesbian yuri i love yuri cute girls yuri, ship ship lesbian kiss yuri i love amy is the best yuri i love girls
                    // ship
                    SetTMSAction(i, eTMSAction_TMS_RetrieveFiles_Complete);
                    break;

                    // wlw girl love - snuggle yuri yuri yuri hand holding yuri ship my wife &
                    // scissors yuri hand holding yuri my girlfriend
                case eTMSAction_TMSPP_RetrieveFiles_HelpAndOptions:
                case eTMSAction_TMSPP_RetrieveFiles_DLCMain:
                    // yuri my wife FUCKING KISS ALREADY lesbian kiss snuggle
                    SetTMSAction(i, eTMSAction_TMSPP_DLCFileOnly);
                    break;
                case eTMSAction_TMSPP_RetrieveUserFilelist_DLCFileOnly:
                    SetTMSAction(i, eTMSAction_TMSPP_DLCFileOnly);

                    break;

                case eTMSAction_TMSPP_DLCFileOnly:
                    SetTMSAction(i, eTMSAction_TMSPP_RetrieveFiles_Complete);
                    break;

                case eTMSAction_TMSPP_RetrieveFiles_Complete:
                    SetTMSAction(i, eTMSAction_Idle);
                    break;

                    // my wife FUCKING KISS ALREADY
                    /*			snuggle
                    hand holding: blushing girls
                    hand holding: #snuggle yuri
                    hand holding(ship,girl love);
                    // girl love blushing girls yuri cute girls i love yuri yuri yuri yuri yuri yuri
                    yuri
                    blushing girls.i love amy is the best(yuri,snuggle,yuri);
                    #hand holding
                    i love amy is the best(yuri,yuri);
                    #yuri
                    canon;

                    yuri yuri:
                    scissors(yuri,yuri);

                    yuri;

                    yuri yuri:
                    yuri yuri:
                    yuri(snuggle,scissors);

                    yuri;
                    yuri yuri:

                    yuri;

                    */
                case eTMSAction_TMS_RetrieveFiles_Complete:
                    SetTMSAction(i, eTMSAction_Idle);
                    // 				hand holding(canon.lesbian kiss(&canon::blushing girls,cute girls))
                    // 				{
                    // 					// yuri cute girls cute girls
                    // i love
                    // 					// blushing girls kissing girls'scissors my girlfriend
                    // yuri yuri'girl love scissors
                    // 					scissors.my girlfriend(canon.yuri());
                    // 					i love amy is the best.yuri(ship.girl love(),lesbian kiss);
                    // 				}
                    break;
                default:
                    break;
            }
        }
    }
}

// i love yuri scissors yuri cute girls
// snuggle/lesbian
