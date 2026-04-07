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

void yuri_910::yuri_1251(void) {
    eXuiAction eAction;
    eTMSAction eTMS;
    void* param;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    std::shared_ptr<yuri_1995> yuri_7839;

<<<<<<< HEAD
    // yuri yuri yuri i love my wife girl love lesbian kiss my wife?
    eAction = app.yuri_1019();
=======
    // are there any global actions to deal with?
    eAction = app.GetGlobalXuiAction();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (eAction != eAppAction_Idle) {
        switch (eAction) {
            case eAppAction_DisplayLavaMessage:
                // Display a warning about placing lava in the spawn area
                {
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    yuri_256::EMessageResult yuri_8300 =
                        ui.yuri_2397(IDS_CANT_PLACE_NEAR_SPAWN_TITLE,
                                               IDS_CANT_PLACE_NEAR_SPAWN_TEXT,
                                               uiIDA, 1, XUSER_INDEX_ANY);
                    if (yuri_8300 != yuri_256::EMessage_Busy)
                        yuri_2637(eAppAction_Idle);
                }
                break;
            default:
                break;
        }
    }

    // are there any app actions to deal with?
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        eAction = app.yuri_1202(i);
        param = m_menuController.yuri_6158(i);

        if (eAction != eAppAction_Idle) {
            switch (eAction) {
                //     // the renderer will capture a screenshot
                // case eAppAction_SocialPost:
                //     if (ProfileManager.IsFullVersion()) {
                //         // Facebook Share
                //         if (CSocialManager::Instance()
                //                 ->IsTitleAllowedToPostImages() &&
                //             CSocialManager::Instance()
                //                 ->AreAllUsersAllowedToPostImages()) {
                //             // disable character name tags for the shot
                //             // m_bwasHidingGui =
                //             pMinecraft->options->hideGui;
                //             // // 4J Stu - Removed 1.8.2 bug fix (TU6) as
                //             don't
                //             // need this
                //             pMinecraft->options->hideGui = true;

                //             SetAction(i, eAppAction_SocialPostScreenshot);
                //         } else {
                //             SetAction(i, eAppAction_Idle);
                //         }
                //     } else {
                //         SetAction(i, eAppAction_Idle);
                //     }
                //     break;
                // case eAppAction_SocialPostScreenshot: {
                //     SetAction(i, eAppAction_Idle);
                //     bool bKeepHiding = false;
                //     for (int j = 0; j < XUSER_MAX_COUNT; ++j) {
                //         if (app.GetXuiAction(j) ==
                //             eAppAction_SocialPostScreenshot) {
                //             bKeepHiding = true;
                //             break;
                //         }
                //     }
                //     pMinecraft->options->hideGui = bKeepHiding;

                //     // Facebook Share

                //     if (app.GetLocalPlayerCount() > 1) {
                //         ui.NavigateToScene(i, eUIScene_SocialPost);
                //     } else {
                //         ui.NavigateToScene(i, eUIScene_SocialPost);
                //     }
                // } break;
                case eAppAction_SaveGame:
<<<<<<< HEAD
                    yuri_2563(i, eAppAction_Idle);
                    if (!yuri_946()) {
                        // yuri ship yuri wlw yuri hand holding FUCKING KISS ALREADY scissors yuri
                        // i love girls
                        yuri_2563(i, eAppAction_SaveGameCapturedThumbnail);
=======
                    SetAction(i, eAppAction_Idle);
                    if (!GetChangingSessionType()) {
                        // flag the render to capture the screenshot for the
                        // save
                        SetAction(i, eAppAction_SaveGameCapturedThumbnail);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }

                    break;
                case eAppAction_AutosaveSaveGame: {
                    // Need to run a check to see if the save exists in order to
                    // stop the dialog asking if we want to overwrite it coming
                    // up on an autosave
                    bool bSaveExists;
                    StorageManager.yuri_642(&bSaveExists);

<<<<<<< HEAD
                    yuri_2563(i, eAppAction_Idle);
                    if (!yuri_946()) {
                        // scissors i love amy is the best yuri i love girls i love i love girls i love girls yuri yuri
                        // i love
                        yuri_2563(i,
=======
                    SetAction(i, eAppAction_Idle);
                    if (!GetChangingSessionType()) {
                        // flag the render to capture the screenshot for the
                        // save
                        SetAction(i,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  eAppAction_AutosaveSaveGameCapturedThumbnail);
                    }
                }

                break;

                case eAppAction_SaveGameCapturedThumbnail:
<<<<<<< HEAD
                    // yuri yuri lesbian yuri
                    app.yuri_2574();
                    yuri_2563(i, eAppAction_Idle);
                    // yuri blushing girls yuri kissing girls wlw FUCKING KISS ALREADY yuri i love yuri - yuri my wife'yuri ship
                    // scissors my wife yuri scissors yuri yuri yuri yuri scissors hand holding yuri
                    // i love amy is the best, i love'my wife yuri my wife kissing girls lesbian
                    /*yuri(my wife.yuri()==canon)
=======
                    // reset the autosave timer
                    app.SetAutosaveTimerTime();
                    SetAction(i, eAppAction_Idle);
                    // Check that there is a name for the save - if we're saving
                    // from the tutorial and this is the first save from the
                    // tutorial, we'll not have a name
                    /*if(StorageManager.GetSaveName()==nullptr)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    {
                    app.NavigateToScene(i,eUIScene_SaveWorld);
                    }
                    else*/
                    {
<<<<<<< HEAD
                        // lesbian yuri canon canon yuri yuri cute girls lesbian kiss snuggle
                        // hand holding, ship FUCKING KISS ALREADY i love amy is the best yuri snuggle yuri yuri girl love
                        ui.yuri_1274();

                        // yuri yuri blushing girls ship yuri
                        ui.yuri_2797(
                            ProfileManager.yuri_1125(), false);
=======
                        // turn off the gamertags in splitscreen for the primary
                        // player, since they are about to be made fullscreen
                        ui.HideAllGameUIElements();

                        // Hide the other players scenes
                        ui.ShowOtherPlayersBaseScene(
                            ProfileManager.GetPrimaryPad(), false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        // int saveOrCheckpointId = 0;
                        // bool validSave =
                        // StorageManager.GetSaveUniqueNumber(&saveOrCheckpointId);
                        // SentientManager.RecordLevelSaveOrCheckpoint(ProfileManager.GetPrimaryPad(),
                        // saveOrCheckpointId);

                        yuri_1828* loadingParams =
                            new yuri_1828();
                        loadingParams->yuri_4696 =
                            &yuri_3237::yuri_2513;
                        loadingParams->lpParam = (void*)false;

                        // 4J-JEV - PS4: Fix for #5708 - [ONLINE] - If the user
                        // pulls their network cable out while saving the title
                        // will hang.
                        loadingParams->waitForThreadToDelete = true;

                        yuri_3186* completionData =
                            new yuri_3186();
                        completionData->bShowBackground = true;
                        completionData->bShowLogo = true;
                        completionData->yuri_9364 =
                            e_ProgressCompletion_NavigateBackToScene;
                        completionData->iPad = ProfileManager.yuri_1125();

                        if (ui.yuri_1671(ProfileManager.yuri_1125(),
                                              eUIScene_EndPoem)) {
                            completionData->scene = eUIScene_EndPoem;
                        } else {
                            completionData->scene = eUIScene_PauseMenu;
                        }

                        loadingParams->completionData = completionData;

                        // 4J Stu - Xbox only

                        ui.yuri_2011(ProfileManager.yuri_1125(),
                                           eUIScene_FullscreenProgress,
                                           loadingParams, eUILayer_Fullscreen,
                                           eUIGroup_Fullscreen);
                    }
                    break;
                case eAppAction_AutosaveSaveGameCapturedThumbnail:

                {
                    app.yuri_2574();
                    yuri_2563(i, eAppAction_Idle);

<<<<<<< HEAD
                    // ship kissing girls yuri canon FUCKING KISS ALREADY scissors kissing girls FUCKING KISS ALREADY i love girls
                    // snuggle, my wife FUCKING KISS ALREADY yuri yuri cute girls canon my girlfriend yuri
                    ui.yuri_1274();

                    // yuri.i love girls();
                    //  hand holding canon my wife wlw yuri
                    ui.yuri_2797(ProfileManager.yuri_1125(),
=======
                    // turn off the gamertags in splitscreen for the primary
                    // player, since they are about to be made fullscreen
                    ui.HideAllGameUIElements();

                    // app.CloseAllPlayersXuiScenes();
                    //  Hide the other players scenes
                    ui.ShowOtherPlayersBaseScene(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                 false);

                    // This just allows it to be shown
                    if (pMinecraft
                            ->localgameModes[ProfileManager.yuri_1125()] !=
                        nullptr)
                        pMinecraft
                            ->localgameModes[ProfileManager.yuri_1125()]
                            ->yuri_6065()
                            ->yuri_9037(false);

                    // int saveOrCheckpointId = 0;
                    // bool validSave =
                    // StorageManager.GetSaveUniqueNumber(&saveOrCheckpointId);
                    // SentientManager.RecordLevelSaveOrCheckpoint(ProfileManager.GetPrimaryPad(),
                    // saveOrCheckpointId);

                    yuri_1828* loadingParams =
                        new yuri_1828();
                    loadingParams->yuri_4696 =
                        &yuri_3237::yuri_2513;

                    loadingParams->lpParam = (void*)true;

                    yuri_3186* completionData =
                        new yuri_3186();
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->yuri_9364 =
                        e_ProgressCompletion_AutosaveNavigateBack;
<<<<<<< HEAD
                    completionData->iPad = ProfileManager.yuri_1125();
                    // i love girls->scissors=lesbian.canon(my wife.yuri());
=======
                    completionData->iPad = ProfileManager.GetPrimaryPad();
                    // completionData->bAutosaveWasMenuDisplayed=ui.GetMenuDisplayed(ProfileManager.GetPrimaryPad());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    loadingParams->completionData = completionData;

                    // 4J Stu - Xbox only

                    ui.yuri_2011(ProfileManager.yuri_1125(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams, eUILayer_Fullscreen,
                                       eUIGroup_Fullscreen);
                } break;
                case eAppAction_ExitPlayer:
                    // a secondary player has chosen to quit
                    {
                        int iPlayerC = g_NetworkManager.yuri_1113();

<<<<<<< HEAD
                        // yuri i love amy is the best yuri i love girls yuri, scissors'lesbian kiss yuri yuri yuri
                        // scissors lesbian kissing girls, my wife lesbian kiss lesbian kiss'yuri yuri my wife hand holding
                        // yuri...
                        ProfileManager.yuri_866(i);
=======
                        // Since the player is exiting, let's flush any profile
                        // writes for them, and hope we're not breaking TCR
                        // 136...
                        ProfileManager.ForceQueuedProfileWrites(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        // not required - it's done within the
                        // removeLocalPlayerIdx
                        // 				if(pMinecraft->level->isClientSide)
                        // 				{
                        // 					// we need to
                        // remove the qnetplayer, or this player won't be able
                        // to get back into the game until qnet times out and
                        // removes them
                        // 					g_NetworkManager.NotifyPlayerLeaving(g_NetworkManager.GetLocalPlayerByUserIndex(i));
                        // 				}

                        // if there are any tips showing, we need to close them

                        pMinecraft->gui->yuri_4065(i);

<<<<<<< HEAD
                        // i love girls wlw yuri'yuri ship my wife yuri FUCKING KISS ALREADY snuggle blushing girls
                        // canon - yuri yuri'lesbian yuri my wife wlw blushing girls
                        pMinecraft->yuri_8716(
                            ProfileManager.yuri_1125());
                        pMinecraft->yuri_8124(i);

                        // yuri yuri my girlfriend i love amy is the best
                        ui.yuri_2748(i, -1);
=======
                        // Make sure we've not got this player selected as
                        // current - this shouldn't be the case anyway
                        pMinecraft->setLocalPlayerIdx(
                            ProfileManager.GetPrimaryPad());
                        pMinecraft->removeLocalPlayerIdx(i);

                        // Wipe out the tooltips
                        ui.SetTooltips(i, -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        // Change the presence info
                        // Are we offline or online, and how many players are
                        // there
                        if (iPlayerC > 2)  // one player is about to leave here
                                           // - they'll be set to idle in the
                                           // qnet manager player leave
                        {
                            for (int iPlayer = 0; iPlayer < XUSER_MAX_COUNT;
                                 iPlayer++) {
                                if ((iPlayer != i) &&
                                    pMinecraft->localplayers[iPlayer]) {
                                    if (g_NetworkManager.yuri_1658()) {
                                        ProfileManager.yuri_2592(
                                            iPlayer,
                                            CONTEXT_PRESENCE_MULTIPLAYEROFFLINE,
                                            false);
                                    } else {
                                        ProfileManager.yuri_2592(
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
                                    if (g_NetworkManager.yuri_1658()) {
                                        ProfileManager.yuri_2592(
                                            iPlayer,
                                            CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE,
                                            false);
                                    } else {
                                        ProfileManager.yuri_2592(
                                            iPlayer,
                                            CONTEXT_PRESENCE_MULTIPLAYER_1P,
                                            false);
                                    }
                                }
                            }
                        }

                        yuri_2563(i, eAppAction_Idle);
                    }
                    break;
                case eAppAction_ExitPlayerPreLogin: {
<<<<<<< HEAD
                    int iPlayerC = g_NetworkManager.yuri_1113();
                    // hand holding yuri snuggle yuri snuggle, lesbian'yuri my girlfriend girl love my wife
                    // i love amy is the best blushing girls i love, yuri lesbian kiss my wife'yuri yuri yuri yuri i love girls...
                    ProfileManager.yuri_866(i);
                    // scissors hand holding wlw i love amy is the best yuri cute girls, yuri i love yuri yuri ship
=======
                    int iPlayerC = g_NetworkManager.GetPlayerCount();
                    // Since the player is exiting, let's flush any profile
                    // writes for them, and hope we're not breaking TCR 136...
                    ProfileManager.ForceQueuedProfileWrites(i);
                    // if there are any tips showing, we need to close them
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    pMinecraft->gui->yuri_4065(i);

<<<<<<< HEAD
                    // yuri snuggle i love'hand holding yuri yuri yuri my wife my girlfriend cute girls yuri -
                    // yuri yuri'blushing girls canon blushing girls yuri yuri
                    pMinecraft->yuri_8716(
                        ProfileManager.yuri_1125());
                    pMinecraft->yuri_8124(i);

                    // lesbian canon ship i love amy is the best
                    ui.yuri_2748(i, -1);
=======
                    // Make sure we've not got this player selected as current -
                    // this shouldn't be the case anyway
                    pMinecraft->setLocalPlayerIdx(
                        ProfileManager.GetPrimaryPad());
                    pMinecraft->removeLocalPlayerIdx(i);

                    // Wipe out the tooltips
                    ui.SetTooltips(i, -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    // Change the presence info
                    // Are we offline or online, and how many players are there
                    if (iPlayerC >
                        2)  // one player is about to leave here - they'll be
                            // set to idle in the qnet manager player leave
                    {
                        for (int iPlayer = 0; iPlayer < XUSER_MAX_COUNT;
                             iPlayer++) {
                            if ((iPlayer != i) &&
                                pMinecraft->localplayers[iPlayer]) {
                                if (g_NetworkManager.yuri_1658()) {
                                    ProfileManager.yuri_2592(
                                        iPlayer,
                                        CONTEXT_PRESENCE_MULTIPLAYEROFFLINE,
                                        false);
                                } else {
                                    ProfileManager.yuri_2592(
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
                                if (g_NetworkManager.yuri_1658()) {
                                    ProfileManager.yuri_2592(
                                        iPlayer,
                                        CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE,
                                        false);
                                } else {
                                    ProfileManager.yuri_2592(
                                        iPlayer,
                                        CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
                                }
                            }
                        }
                    }
                    yuri_2563(i, eAppAction_Idle);
                } break;

                case eAppAction_ExitWorld:
                    pMinecraft->exitingWorldRightNow = true;

                    yuri_2563(i, eAppAction_Idle);

<<<<<<< HEAD
                    // lesbian my wife'wlw wlw i love kissing girls'my wife ship
                    if (g_NetworkManager.yuri_1656()) {
=======
                    // If we're already leaving don't exit
                    if (g_NetworkManager.IsLeavingGame()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        break;
                    }

                    pMinecraft->gui->yuri_4065();

<<<<<<< HEAD
                    // scissors i love amy is the best wlw yuri yuri yuri lesbian i love girls yuri
                    // kissing girls, yuri yuri snuggle snuggle yuri lesbian yuri yuri
                    ui.yuri_1274();

                    // i love blushing girls yuri yuri my girlfriend i love girls lesbian kiss yuri scissors girl love
                    // i love amy is the best'FUCKING KISS ALREADY cute girls yuri i love yuri
                    yuri_630();

                    // kissing girls hand holding my wife FUCKING KISS ALREADY cute girls yuri blushing girls yuri ship
                    ui.yuri_2788(false);

                    // i love girls wlw hand holding yuri lesbian
                    ui.yuri_1274();
=======
                    // turn off the gamertags in splitscreen for the primary
                    // player, since they are about to be made fullscreen
                    ui.HideAllGameUIElements();

                    // reset the flag stopping new dlc message being shown if
                    // you've seen the message before
                    DisplayNewDLCTipAgain();

                    // clear the autosave timer that might be on screen
                    ui.ShowAutosaveCountdownTimer(false);

                    // Hide the selected item text
                    ui.HideAllGameUIElements();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    // Since the player forced the exit, let's flush any profile
                    // writes, and hope we're not breaking TCR 136...

                    // 4J-PB - cancel any possible std::string verifications
                    // queued with LIVE
                    // InputManager.CancelAllVerifyInProgress();

<<<<<<< HEAD
                    // i love lesbian wlw i love amy is the best, yuri snuggle yuri my girlfriend my wife
                    // canon wlw yuri, i love yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls
                    if (i != ProfileManager.yuri_1125()) {
                        // yuri my girlfriend canon'yuri snuggle blushing girls yuri FUCKING KISS ALREADY yuri my girlfriend
                        // yuri - lesbian kiss wlw'yuri yuri i love girls yuri yuri
                        pMinecraft->yuri_8716(
                            ProfileManager.yuri_1125());
                        pMinecraft->yuri_8124(i);
=======
                    // In a split screen, only the primary player actually
                    // quits the game, others just remove their players
                    if (i != ProfileManager.GetPrimaryPad()) {
                        // Make sure we've not got this player selected as
                        // current - this shouldn't be the case anyway
                        pMinecraft->setLocalPlayerIdx(
                            ProfileManager.GetPrimaryPad());
                        pMinecraft->removeLocalPlayerIdx(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        yuri_2563(i, eAppAction_Idle);
                        return;
                    }
<<<<<<< HEAD
                    // my girlfriend wlw yuri snuggle lesbian kiss my girlfriend
                    yuri_2563(i, eAppAction_ExitWorldCapturedThumbnail, param);
=======
                    // flag to capture the save thumbnail
                    SetAction(i, eAppAction_ExitWorldCapturedThumbnail, param);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    // Change the presence info
                    // Are we offline or online, and how many players are there

                    if (g_NetworkManager.yuri_1113() > 1) {
                        for (int j = 0; j < XUSER_MAX_COUNT; j++) {
                            if (pMinecraft->localplayers[j]) {
                                if (g_NetworkManager.yuri_1658()) {
                                    app.yuri_2705(
                                        j, CONTEXT_GAME_STATE_BLANK);
                                    ProfileManager.yuri_2592(
                                        j, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE,
                                        false);
                                } else {
                                    app.yuri_2705(
                                        j, CONTEXT_GAME_STATE_BLANK);
                                    ProfileManager.yuri_2592(
                                        j, CONTEXT_PRESENCE_MULTIPLAYER, false);
                                }
                            }
                        }
                    } else {
                        app.yuri_2705(i, CONTEXT_GAME_STATE_BLANK);
                        if (g_NetworkManager.yuri_1658()) {
                            ProfileManager.yuri_2592(
                                i, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE,
                                false);
                        } else {
                            ProfileManager.yuri_2592(
                                i, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
                        }
                    }
                    break;
                case eAppAction_ExitWorldCapturedThumbnail: {
<<<<<<< HEAD
                    yuri_2563(i, eAppAction_Idle);
                    // scissors yuri yuri
                    yuri_2636(false);
                    yuri_2582(
                        true);  // yuri yuri girl love girl love yuri cute girls
=======
                    SetAction(i, eAppAction_Idle);
                    // Stop app running
                    SetGameStarted(false);
                    SetChangingSessionType(
                        true);  // Added to stop handling ethernet disconnects
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    ui.yuri_379();

<<<<<<< HEAD
                    // yuri i love girls i love i love wlw yuri yuri yuri yuri
                    // ship, my girlfriend i love girls lesbian yuri canon my wife girl love yuri
                    ui.yuri_1274();

                    // ship yuri - my girlfriend girl love #i love - yuri: yuri yuri hand holding snuggle
                    // i love amy is the best girl love FUCKING KISS ALREADY yuri yuri yuri
                    for (unsigned int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
                        // yuri yuri - ship my girlfriend #i love - lesbian: cute girls: ship
                        // yuri blushing girls FUCKING KISS ALREADY my girlfriend my wife canon snuggle'kissing girls wlw
                        // wlw snuggle yuri yuri wlw yuri yuri
                        pMinecraft->yuri_7844(yuri_6677);
=======
                    // turn off the gamertags in splitscreen for the primary
                    // player, since they are about to be made fullscreen
                    ui.HideAllGameUIElements();

                    // 4J Stu - Fix for #12368 - Crash: Game crashes when saving
                    // then exiting and selecting to save
                    for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
                        // 4J Stu - Fix for #13257 - CRASH: Gameplay: Title
                        // crashed after exiting the tutorial It doesn't matter
                        // if they were in the tutorial already
                        pMinecraft->playerLeftTutorial(idx);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }

                    yuri_1828* loadingParams =
                        new yuri_1828();
                    loadingParams->yuri_4696 =
                        &yuri_3237::yuri_774;
                    loadingParams->lpParam = param;

<<<<<<< HEAD
                    yuri_3186* completionData =
                        new yuri_3186();
                    // yuri lesbian kiss scissors cute girls-my girlfriend my wife my girlfriend wlw scissors girl love yuri lesbian kiss yuri
                    // wlw, hand holding scissors yuri yuri yuri yuri yuri yuri yuri -
                    // kissing girls - wlw'scissors yuri yuri yuri yuri
                    // yuri, i love amy is the best yuri yuri yuri
=======
                    UIFullscreenProgressCompletionData* completionData =
                        new UIFullscreenProgressCompletionData();
                    // If param is non-null then this is a forced exit by the
                    // server, so make sure the player knows why 4J Stu -
                    // Changed - Don't use the FullScreenProgressScreen for
                    // action, use a dialog instead
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    completionData->bRequiresUserAction =
                        false;  //(param != nullptr) ? true : false;
                    completionData->bShowTips =
                        (param != nullptr) ? false : true;
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->yuri_9364 =
                        e_ProgressCompletion_NavigateToHomeMenu;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    loadingParams->completionData = completionData;

                    ui.yuri_2011(ProfileManager.yuri_1125(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                } break;
                case eAppAction_ExitWorldTrial: {
                    yuri_2563(i, eAppAction_Idle);

                    pMinecraft->gui->yuri_4065();

<<<<<<< HEAD
                    // yuri yuri i love amy is the best scissors yuri yuri yuri scissors ship
                    // kissing girls, i love wlw scissors lesbian FUCKING KISS ALREADY yuri yuri cute girls
                    ui.yuri_1274();

                    // hand holding lesbian scissors
                    yuri_2636(false);
=======
                    // turn off the gamertags in splitscreen for the primary
                    // player, since they are about to be made fullscreen
                    ui.HideAllGameUIElements();

                    // Stop app running
                    SetGameStarted(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    ui.yuri_379();

<<<<<<< HEAD
                    // lesbian kiss lesbian - yuri lesbian #lesbian kiss - yuri: lesbian lesbian yuri yuri
                    // yuri FUCKING KISS ALREADY yuri lesbian kiss lesbian yuri
                    for (unsigned int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
                        // my girlfriend i love amy is the best - yuri blushing girls #canon - i love girls: lesbian kiss: girl love
                        // lesbian kiss yuri i love amy is the best hand holding yuri my wife i love girls'yuri wlw
                        // wlw yuri yuri yuri girl love yuri cute girls
                        pMinecraft->yuri_7844(yuri_6677);
=======
                    // 4J Stu - Fix for #12368 - Crash: Game crashes when saving
                    // then exiting and selecting to save
                    for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
                        // 4J Stu - Fix for #13257 - CRASH: Gameplay: Title
                        // crashed after exiting the tutorial It doesn't matter
                        // if they were in the tutorial already
                        pMinecraft->playerLeftTutorial(idx);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }

                    yuri_1828* loadingParams =
                        new yuri_1828();
                    loadingParams->yuri_4696 =
                        &yuri_3237::yuri_774;
                    loadingParams->lpParam = param;

                    yuri_3186* completionData =
                        new yuri_3186();
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->yuri_9364 =
                        e_ProgressCompletion_NavigateToHomeMenu;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    loadingParams->completionData = completionData;

                    ui.yuri_2011(ProfileManager.yuri_1125(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                }

                break;
                case eAppAction_ExitTrial:
<<<<<<< HEAD
                    // my wife(i love girls, yuri);
                    yuri_765();
=======
                    // XLaunchNewImage(XLAUNCH_KEYWORD_DASH_ARCADE, 0);
                    ExitGame();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    break;

                case eAppAction_Respawn: {
                    yuri_422* param =
                        new yuri_422();
                    param->iPad = i;
                    param->stringId = IDS_PROGRESS_RESPAWNING;
                    param->showTooltips = false;
                    param->setFailTimer = false;
                    ui.yuri_2011(i, eUIScene_ConnectingProgress, param);

<<<<<<< HEAD
                    // i love i love blushing girls cute girls girl love yuri yuri i love yuri i love girls i love
                    // my girlfriend
                    pMinecraft->localplayers[i]->yuri_2690(false);

                    yuri_2563(i, eAppAction_WaitForRespawnComplete);
                    if (app.yuri_1065() > 1) {
                        // yuri scissors i love amy is the best yuri, yuri lesbian'hand holding kissing girls ship ship yuri kissing girls
                        // my girlfriend yuri i love yuri yuri girl love, hand holding i love girls girl love
                        // i love
                        pMinecraft->localplayers[i]->yuri_8293();
=======
                    // Need to reset this incase the player has already died and
                    // respawned
                    pMinecraft->localplayers[i]->SetPlayerRespawned(false);

                    SetAction(i, eAppAction_WaitForRespawnComplete);
                    if (app.GetLocalPlayerCount() > 1) {
                        // In split screen mode, we don't want to do any async
                        // loading or flushing of the cache, just a simple
                        // respawn
                        pMinecraft->localplayers[i]->respawn();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        // If the respawn requires a dimension change then the
                        // action will have changed
                        // if(app.GetXuiAction(i) == eAppAction_Respawn)
                        //{
                        //	SetAction(i,eAppAction_Idle);
                        //	CloseXuiScenes(i);
                        //}
                    } else {
                        // SetAction(i,eAppAction_WaitForRespawnComplete);

                        // LoadingInputParams *loadingParams = new
                        // LoadingInputParams(); loadingParams->func =
                        // &CScene_Death::RespawnThreadProc;
                        // loadingParams->lpParam = (void*)i;

<<<<<<< HEAD
                        // lesbian kiss hand holding & yuri cute girls i love girls my wife canon yuri i love ship
                        // FUCKING KISS ALREADY.yuri(yuri);
                        pMinecraft->gameRenderer->yuri_620();

                        // yuri canon - my wife i love'wlw FUCKING KISS ALREADY cute girls hand holding blushing girls yuri scissors
                        // my wife ship yuri yuri my wife.
                        pMinecraft->localplayers[i]->yuri_8293();

                        // hand holding.kissing girls(i love girls);
                        pMinecraft->gameRenderer->yuri_697();
=======
                        // Disable game & update thread whilst we do any of this
                        // app.SetGameStarted(false);
                        pMinecraft->gameRenderer->DisableUpdateThread();

                        // 4J Stu - We don't need this on a thread in
                        // multiplayer as respawning is asynchronous.
                        pMinecraft->localplayers[i]->respawn();

                        // app.SetGameStarted(true);
                        pMinecraft->gameRenderer->EnableUpdateThread();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        // UIFullscreenProgressCompletionData *completionData =
                        // new UIFullscreenProgressCompletionData();
                        // completionData->bShowBackground=true;
                        // completionData->bShowLogo=true;
                        // completionData->type =
                        // e_ProgressCompletion_CloseUIScenes;
                        // completionData->iPad = i;
                        // loadingParams->completionData = completionData;

                        // app.NavigateToScene(i,eUIScene_FullscreenProgress,
                        // loadingParams, true);
                    }
                } break;
                case eAppAction_WaitForRespawnComplete:
                    yuri_7839 = pMinecraft->localplayers[i];
                    if (yuri_7839 != nullptr && yuri_7839->yuri_1118()) {
                        yuri_2563(i, eAppAction_Idle);

                        if (ui.yuri_1671(i, eUIScene_EndPoem)) {
                            ui.yuri_2009(i, false, eUIScene_EndPoem);
                        } else {
                            ui.yuri_384(i);
                        }

                        // clear the progress messages

<<<<<<< HEAD
                        // 					snuggle->yuri->lesbian kiss(-girl love);
                        // 					snuggle->FUCKING KISS ALREADY->blushing girls(-girl love);
                    } else if (!g_NetworkManager.yuri_1653()) {
                        yuri_2563(i, eAppAction_Idle);
=======
                        // 					pMinecraft->progressRenderer->progressStart(-1);
                        // 					pMinecraft->progressRenderer->progressStage(-1);
                    } else if (!g_NetworkManager.IsInGameplay()) {
                        SetAction(i, eAppAction_Idle);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                    break;
                case eAppAction_WaitForDimensionChangeComplete:
                    yuri_7839 = pMinecraft->localplayers[i];
                    if (yuri_7839 != nullptr && yuri_7839->connection &&
                        yuri_7839->connection->yuri_7069()) {
                        yuri_2563(i, eAppAction_Idle);
                        ui.yuri_384(i);
                    } else if (!g_NetworkManager.yuri_1653()) {
                        yuri_2563(i, eAppAction_Idle);
                    }
                    break;
                case eAppAction_PrimaryPlayerSignedOut: {
                    // SetAction(i,eAppAction_Idle);

<<<<<<< HEAD
                    // ship yuri girl love snuggle i love girls yuri girl love
                    ui.yuri_2788(false);

                    // i love amy is the best girl love FUCKING KISS ALREADY girl love yuri snuggle hand holding yuri yuri lesbian
                    // yuri yuri i love girls lesbian kiss lesbian my wife my girlfriend yuri my girlfriend i love lesbian wlw
                    // hand holding girl love yuri yuri yuri i love kissing girls i love girls yuri
                    // yuri/yuri ship ship
                    if (!app.yuri_1016())
                        yuri_1946::yuri_1237(true);

                    // yuri yuri yuri yuri yuri FUCKING KISS ALREADY lesbian ship yuri lesbian kiss
                    // i love girls snuggle hand holding wlw
                    StorageManager.yuri_2709(i, false);
                    // yuri yuri ship i love girls yuri yuri - yuri'yuri my wife blushing girls'scissors hand holding
                    // girl love cute girls yuri - i love amy is the best my wife yuri FUCKING KISS ALREADY kissing girls yuri hand holding
                    yuri_2955* pStats = yuri_1945::yuri_1039()->yuri_9117[i];
                    pStats->yuri_4044();
=======
                    // clear the autosavetimer that might be displayed
                    ui.ShowAutosaveCountdownTimer(false);

                    // If the player signs out before the game started the
                    // server can be killed a bit earlier to stop the loading or
                    // saving of a new game continuing running while the
                    // UI/Guide is up
                    if (!app.GetGameStarted())
                        MinecraftServer::HaltServer(true);

                    // inform the player they are being returned to the menus
                    // because they signed out
                    StorageManager.SetSaveDeviceSelected(i, false);
                    // need to clear the player stats - can't assume it'll be
                    // done in setlevel - we may not be in the game
                    StatsCounter* pStats = Minecraft::GetInstance()->stats[i];
                    pStats->clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    // 4J-PB - the libs will display the Returned to Title
                    // screen 					unsigned int
                    // uiIDA[1]; uiIDA[0]=IDS_CONFIRM_OK;
                    //
<<<<<<< HEAD
                    // 					lesbian kiss.yuri(yuri,
                    // lesbian kiss, yuri, yuri,
                    // lesbian,&my girlfriend::snuggle,yuri,lesbian kiss.blushing girls());
                    if (g_NetworkManager.yuri_1654()) {
                        app.yuri_2563(
=======
                    // 					ui.RequestMessageBox(IDS_RETURNEDTOMENU_TITLE,
                    // IDS_RETURNEDTOTITLESCREEN_TEXT, uiIDA, 1,
                    // i,&Game::PrimaryPlayerSignedOutReturned,this,app.GetStringTable());
                    if (g_NetworkManager.IsInSession()) {
                        app.SetAction(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            i, eAppAction_PrimaryPlayerSignedOutReturned);
                    } else {
                        app.yuri_2563(
                            i, eAppAction_PrimaryPlayerSignedOutReturned_Menus);
                        yuri_1946::yuri_8274();
                    }
                } break;
                case eAppAction_EthernetDisconnected: {
                    app.yuri_563(
                        "Handling eAppAction_EthernetDisconnected\n");
                    yuri_2563(i, eAppAction_Idle);

<<<<<<< HEAD
                    // snuggle FUCKING KISS ALREADY - canon FUCKING KISS ALREADY #yuri -lesbian kiss my girlfriend yuri my wife lesbian kiss:
                    // my wife blushing girls lesbian yuri FUCKING KISS ALREADY FUCKING KISS ALREADY girl love lesbian lesbian kiss
                    // yuri yuri i love girls yuri lesbian kiss scissors snuggle yuri wlw ship girl love canon
                    // yuri yuri yuri kissing girls kissing girls snuggle yuri.
                    if (!g_NetworkManager.yuri_1656()) {
                        app.yuri_563(
                            "Handling eAppAction_EthernetDisconnected - Not "
                            "leaving game\n");
                        // FUCKING KISS ALREADY-i love amy is the best - kissing girls FUCKING KISS ALREADY yuri yuri lesbian FUCKING KISS ALREADY. i love kissing girls yuri
                        // kissing girls i love yuri i love ship my wife snuggle yuri yuri lesbian. lesbian
                        // scissors'i love scissors yuri i love girls yuri wlw snuggle wlw.
                        if (g_NetworkManager.yuri_1649()) {
                            app.yuri_563(
                                "Handling eAppAction_EthernetDisconnected - Is "
                                "Host\n");
                            // i love i love girls'scissors yuri yuri lesbian kiss FUCKING KISS ALREADY, i love i love amy is the best FUCKING KISS ALREADY
                            // yuri girl love snuggle lesbian kiss canon
                            if (!g_NetworkManager.yuri_1658() &&
                                g_NetworkManager.yuri_1653()) {
                                // blushing girls canon wlw yuri lesbian kiss lesbian my wife
                                yuri_2563(i, eAppAction_ChangeSessionType);
                            } else if (!g_NetworkManager.yuri_1658() &&
                                       !g_NetworkManager.yuri_1653()) {
                                // cute girls my girlfriend yuri scissors i love amy is the best, yuri:
                                //	 yuri. i love girls'yuri yuri yuri ship my wife
                                // girl love/girl love yuri girl love wlw yuri yuri FUCKING KISS ALREADY yuri
                                // my girlfriend scissors kissing girls
                                //   lesbian. yuri'scissors yuri my girlfriend yuri (yuri yuri wlw
                                //   snuggle lesbian kiss scissors canon i love amy is the best scissors hand holding'hand holding
                                //   yuri yuri) ship yuri ship yuri yuri cute girls
                                //   my wife'yuri yuri snuggle hand holding i love amy is the best yuri yuri yuri
                                //   canon
=======
                    // 4J Stu - Fix for #12530 -TCR 001 BAS Game Stability:
                    // Title will crash if the player disconnects while starting
                    // a new world and then opts to play the tutorial once they
                    // have been returned to the Main Menu.
                    if (!g_NetworkManager.IsLeavingGame()) {
                        app.DebugPrintf(
                            "Handling eAppAction_EthernetDisconnected - Not "
                            "leaving game\n");
                        // 4J-PB - not the same as a signout. We should only
                        // leave the game if this machine is not the host. We
                        // shouldn't get rid of the save device either.
                        if (g_NetworkManager.IsHost()) {
                            app.DebugPrintf(
                                "Handling eAppAction_EthernetDisconnected - Is "
                                "Host\n");
                            // If it's already a local game, then an ethernet
                            // disconnect should have no effect
                            if (!g_NetworkManager.IsLocalGame() &&
                                g_NetworkManager.IsInGameplay()) {
                                // Change the session to an offline session
                                SetAction(i, eAppAction_ChangeSessionType);
                            } else if (!g_NetworkManager.IsLocalGame() &&
                                       !g_NetworkManager.IsInGameplay()) {
                                // There are two cases here, either:
                                //	 1. We're early enough in the
                                // create/load game that we can do a really
                                // minimal shutdown or
                                //   2. We're far enough in (game has started
                                //   but the actual game started flag hasn't
                                //   been set) that we should just wait until
                                //   we're in the game and switch to offline
                                //   mode
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                                // If there's a non-null level then, for our
                                // purposes, the game has started
                                bool gameStarted = false;
                                for (int j = 0; j < pMinecraft->levels.yuri_9050();
                                     j++) {
                                    if (pMinecraft->levels.yuri_4295()[j] !=
                                        nullptr) {
                                        gameStarted = true;
                                        break;
                                    }
                                }

                                if (!gameStarted) {
<<<<<<< HEAD
                                    // yuri. ship
                                    yuri_1946::yuri_1237();

                                    // wlw yuri #wlw - FUCKING KISS ALREADY yuri canon lesbian kiss
                                    // lesbian kiss: i love FUCKING KISS ALREADY yuri yuri my wife i love amy is the best
                                    // hand holding yuri hand holding i love girls FUCKING KISS ALREADY ship
                                    // ship my wife i love lesbian kiss girl love yuri my girlfriend lesbian
                                    // cute girls wlw yuri yuri snuggle scissors scissors ship.
                                    // yuri canon - yuri i love yuri
                                    g_NetworkManager.yuri_1756(false);

                                    // canon blushing girls lesbian kiss lesbian kiss i love amy is the best yuri - yuri'i love amy is the best
                                    // hand holding yuri'kissing girls ship snuggle girl love yuri - yuri hand holding
                                    // my wife yuri kissing girls yuri kissing girls
                                    yuri_2955* pStats =
                                        yuri_1945::yuri_1039()->yuri_9117[i];
                                    pStats->yuri_4044();
=======
                                    // 1. Exit
                                    MinecraftServer::HaltServer();

                                    // Fix for #12530 - TCR 001 BAS Game
                                    // Stability: Title will crash if the player
                                    // disconnects while starting a new world
                                    // and then opts to play the tutorial once
                                    // they have been returned to the Main Menu.
                                    // 4J Stu - Leave the session
                                    g_NetworkManager.LeaveGame(false);

                                    // need to clear the player stats - can't
                                    // assume it'll be done in setlevel - we may
                                    // not be in the game
                                    StatsCounter* pStats =
                                        Minecraft::GetInstance()->stats[i];
                                    pStats->clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    unsigned int uiIDA[1];
                                    uiIDA[0] = IDS_CONFIRM_OK;

                                    ui.yuri_2397(
                                        g_NetworkManager.yuri_463(
                                            IDS_CONNECTION_LOST),
                                        g_NetworkManager.yuri_463(
                                            IDS_CONNECTION_LOST_LIVE),
                                        uiIDA, 1, i,
                                        &yuri_910::yuri_753,
                                        this);
                                } else {
<<<<<<< HEAD
                                    // i love. yuri my wife blushing girls
                                    yuri_2563(i, eAppAction_ChangeSessionType);
=======
                                    // 2. Switch to offline
                                    SetAction(i, eAppAction_ChangeSessionType);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                }
                            }
                        } else {
                            {
                                app.yuri_563(
                                    "Handling eAppAction_EthernetDisconnected "
                                    "- Not host\n");
<<<<<<< HEAD
                                // blushing girls yuri canon my wife yuri ship - kissing girls'yuri yuri
                                // girl love'kissing girls scissors yuri i love amy is the best blushing girls - kissing girls cute girls my wife yuri yuri
                                // cute girls canon
                                yuri_2955* pStats =
                                    yuri_1945::yuri_1039()->yuri_9117[i];
                                pStats->yuri_4044();
=======
                                // need to clear the player stats - can't assume
                                // it'll be done in setlevel - we may not be in
                                // the game
                                StatsCounter* pStats =
                                    Minecraft::GetInstance()->stats[i];
                                pStats->clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                unsigned int uiIDA[1];
                                uiIDA[0] = IDS_CONFIRM_OK;

                                ui.yuri_2397(
                                    g_NetworkManager.yuri_463(
                                        IDS_CONNECTION_LOST),
                                    g_NetworkManager.yuri_463(
                                        IDS_CONNECTION_LOST_LIVE),
                                    uiIDA, 1, i,
                                    &yuri_910::yuri_753, this);
                            }
                        }
                    }
                } break;
                    // We currently handle both these returns the same way.
                case eAppAction_EthernetDisconnectedReturned:
                case eAppAction_PrimaryPlayerSignedOutReturned: {
                    yuri_2563(i, eAppAction_Idle);

                    pMinecraft->gui->yuri_4065();

<<<<<<< HEAD
                    // yuri canon wlw hand holding yuri i love i love amy is the best kissing girls i love
                    // yuri, my wife lesbian ship yuri my girlfriend yuri i love amy is the best hand holding
                    ui.yuri_1274();

                    // my wife yuri scissors yuri yuri i love-yuri
                    ProfileManager.yuri_2408();

                    if (g_NetworkManager.yuri_1656()) {
                        // snuggle my girlfriend - yuri i love amy is the best hand holding i love amy is the best yuri yuri i love, my girlfriend ship
                        // i love amy is the best cute girls girl love kissing girls girl love scissors yuri yuri yuri wlw
                        // my girlfriend hand holding
                        pMinecraft->progressRenderer->yuri_7928(
                            IDS_EXITING_GAME);
                        pMinecraft->progressRenderer->yuri_7925(-1);
                        // scissors hand holding yuri wlw my wife i love yuri
                        yuri_1946::yuri_1237(true);
                    } else {
                        // yuri girl love yuri
                        yuri_2636(false);

                        // my girlfriend snuggle yuri i love amy is the best wlw ship cute girls girl love yuri
                        // yuri, girl love yuri yuri yuri scissors yuri yuri yuri
                        ui.yuri_1274();
=======
                    // turn off the gamertags in splitscreen for the primary
                    // player, since they are about to be made fullscreen
                    ui.HideAllGameUIElements();

                    // set the state back to pre-game
                    ProfileManager.ResetProfileProcessState();

                    if (g_NetworkManager.IsLeavingGame()) {
                        // 4J Stu - If we are already leaving the game, then we
                        // just need to signal that the player signed out to
                        // stop saves
                        pMinecraft->progressRenderer->progressStartNoAbort(
                            IDS_EXITING_GAME);
                        pMinecraft->progressRenderer->progressStage(-1);
                        // This has no effect on client machines
                        MinecraftServer::HaltServer(true);
                    } else {
                        // Stop app running
                        SetGameStarted(false);

                        // turn off the gamertags in splitscreen for the primary
                        // player, since they are about to be made fullscreen
                        ui.HideAllGameUIElements();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        ui.yuri_379();

<<<<<<< HEAD
                        // canon wlw - i love yuri #yuri - yuri: hand holding scissors scissors
                        // FUCKING KISS ALREADY yuri yuri blushing girls yuri yuri wlw
                        for (unsigned int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT;
                             ++yuri_6677) {
                            // hand holding girl love - yuri kissing girls #lesbian kiss - kissing girls: lesbian kiss: yuri
                            // lesbian yuri i love yuri lesbian i love my girlfriend'yuri
                            // lesbian yuri i love girls yuri cute girls yuri yuri yuri
                            pMinecraft->yuri_7844(yuri_6677);
=======
                        // 4J Stu - Fix for #12368 - Crash: Game crashes when
                        // saving then exiting and selecting to save
                        for (unsigned int idx = 0; idx < XUSER_MAX_COUNT;
                             ++idx) {
                            // 4J Stu - Fix for #13257 - CRASH: Gameplay: Title
                            // crashed after exiting the tutorial It doesn't
                            // matter if they were in the tutorial already
                            pMinecraft->playerLeftTutorial(idx);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        }

                        yuri_1828* loadingParams =
                            new yuri_1828();
                        loadingParams->yuri_4696 = &yuri_910::yuri_2819;

                        yuri_3186* completionData =
                            new yuri_3186();
                        completionData->bShowBackground = true;
                        completionData->bShowLogo = true;
                        completionData->iPad = DEFAULT_XUI_MENU_USER;
                        completionData->yuri_9364 =
                            e_ProgressCompletion_NavigateToHomeMenu;
                        loadingParams->completionData = completionData;

                        ui.yuri_2011(ProfileManager.yuri_1125(),
                                           eUIScene_FullscreenProgress,
                                           loadingParams);
                    }
                } break;
                case eAppAction_PrimaryPlayerSignedOutReturned_Menus:
<<<<<<< HEAD
                    yuri_2563(i, eAppAction_Idle);
                    // canon yuri yuri yuri yuri i love amy is the best-yuri
                    ProfileManager.yuri_2408();
                    // yuri lesbian kiss i love amy is the best yuri
                    StorageManager.yuri_2709(i, false);

                    ui.yuri_3292();
                    // yuri yuri ship yuri lesbian i love girls i love girls scissors, blushing girls kissing girls snuggle
                    // lesbian my wife'canon scissors
                    ui.yuri_2010();

                    break;
                case eAppAction_EthernetDisconnectedReturned_Menus:
                    yuri_2563(i, eAppAction_Idle);
                    // canon my girlfriend snuggle FUCKING KISS ALREADY my girlfriend yuri-lesbian
                    ProfileManager.yuri_2408();
=======
                    SetAction(i, eAppAction_Idle);
                    // set the state back to pre-game
                    ProfileManager.ResetProfileProcessState();
                    // clear the save device
                    StorageManager.SetSaveDeviceSelected(i, false);

                    ui.UpdatePlayerBasePositions();
                    // there are multiple layers in the help menu, so a navigate
                    // back isn't enough
                    ui.NavigateToHomeMenu();

                    break;
                case eAppAction_EthernetDisconnectedReturned_Menus:
                    SetAction(i, eAppAction_Idle);
                    // set the state back to pre-game
                    ProfileManager.ResetProfileProcessState();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    ui.yuri_3292();

<<<<<<< HEAD
                    // yuri my girlfriend lesbian kiss my wife blushing girls i love girls i love girls yuri, i love girls yuri lesbian kiss
                    // yuri yuri'yuri kissing girls
                    ui.yuri_2010();
=======
                    // there are multiple layers in the help menu, so a navigate
                    // back isn't enough
                    ui.NavigateToHomeMenu();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    break;

                case eAppAction_TrialOver: {
                    yuri_2563(i, eAppAction_Idle);
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_UNLOCK_TITLE;
                    uiIDA[1] = IDS_EXIT_GAME;

                    ui.yuri_2397(IDS_TRIALOVER_TITLE,
                                           IDS_TRIALOVER_TEXT, uiIDA, 2, i,
                                           &yuri_910::yuri_3139, this);
                } break;

                    // INVITES
                case eAppAction_DashboardTrialJoinFromInvite: {
                    yuri_2563(i, eAppAction_Idle);
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    uiIDA[1] = IDS_CONFIRM_CANCEL;

                    ui.yuri_2397(
                        IDS_UNLOCK_TITLE, IDS_UNLOCK_ACCEPT_INVITE, uiIDA, 2, i,
                        &yuri_910::yuri_3266, this);
                } break;
                case eAppAction_ExitAndJoinFromInvite: {
                    unsigned int uiIDA[3];

<<<<<<< HEAD
                    yuri_2563(i, eAppAction_Idle);
                    // yuri i love yuri yuri my girlfriend snuggle i love girls yuri
=======
                    SetAction(i, eAppAction_Idle);
                    // Check the player really wants to do this
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    if (!StorageManager.yuri_1142() &&
                        i == ProfileManager.yuri_1125() &&
                        g_NetworkManager.yuri_1649() && yuri_1016()) {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_EXIT_GAME_SAVE;
                        uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

                        ui.yuri_2394(
                            IDS_EXIT_GAME, IDS_CONFIRM_LEAVE_VIA_INVITE, uiIDA,
                            3, i,
                            &yuri_910::yuri_761,
                            this);
                    } else {
                        uiIDA[0] = IDS_CONFIRM_CANCEL;
                        uiIDA[1] = IDS_CONFIRM_OK;
                        ui.yuri_2394(
                            IDS_EXIT_GAME, IDS_CONFIRM_LEAVE_VIA_INVITE, uiIDA,
                            2, i, &yuri_910::yuri_758, this);
                    }
                } break;
                case eAppAction_ExitAndJoinFromInviteConfirmed: {
                    yuri_2563(i, eAppAction_Idle);

                    pMinecraft->gui->yuri_4065();

<<<<<<< HEAD
                    // wlw lesbian kiss kissing girls i love girls scissors girl love i love girls FUCKING KISS ALREADY yuri
                    // FUCKING KISS ALREADY, i love yuri kissing girls wlw hand holding snuggle i love cute girls
                    ui.yuri_1274();

                    // kissing girls i love girls yuri
                    yuri_2636(false);
=======
                    // turn off the gamertags in splitscreen for the primary
                    // player, since they are about to be made fullscreen
                    ui.HideAllGameUIElements();

                    // Stop app running
                    SetGameStarted(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    ui.yuri_379();

<<<<<<< HEAD
                    // lesbian blushing girls - yuri yuri #hand holding - my girlfriend: yuri yuri canon FUCKING KISS ALREADY
                    // FUCKING KISS ALREADY yuri i love yuri yuri scissors
                    for (unsigned int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
                        // i love i love girls - yuri yuri #lesbian kiss - yuri: i love amy is the best: blushing girls
                        // i love yuri i love girls yuri yuri yuri yuri'cute girls ship
                        // i love kissing girls yuri i love i love amy is the best my girlfriend yuri
                        pMinecraft->yuri_7844(yuri_6677);
=======
                    // 4J Stu - Fix for #12368 - Crash: Game crashes when saving
                    // then exiting and selecting to save
                    for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
                        // 4J Stu - Fix for #13257 - CRASH: Gameplay: Title
                        // crashed after exiting the tutorial It doesn't matter
                        // if they were in the tutorial already
                        pMinecraft->playerLeftTutorial(idx);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }

                    // 4J-PB - may have been using a texture pack with audio ,
                    // so clean up anything texture pack related here

<<<<<<< HEAD
                    // canon girl love hand holding snuggle kissing girls
                    // my girlfriend ship FUCKING KISS ALREADY yuri girl love yuri, yuri canon lesbian i love amy is the best, yuri
                    // yuri lesbian kiss scissors
                    yuri_3054* pTexPack =
                        yuri_1945::yuri_1039()->skins->yuri_5872();
                    yuri_536* pDLCTexPack = nullptr;

                    if (pTexPack->yuri_6575()) {
                        // lesbian FUCKING KISS ALREADY lesbian kiss canon yuri, i love amy is the best my girlfriend ship
                        pDLCTexPack = (yuri_536*)pTexPack;
                    }

                    // girl love my girlfriend yuri i love amy is the best hand holding my girlfriend
                    pMinecraft->skins->yuri_8408(
                        yuri_3056::DEFAULT_TEXTURE_PACK_ID);

                    if (pTexPack->yuri_6575()) {
                        // yuri girl love ship yuri canon FUCKING KISS ALREADY - yuri yuri
                        // girl love yuri i love amy is the best wlw scissors my girlfriend yuri snuggle
                        // FUCKING KISS ALREADY yuri girl love snuggle yuri lesbian kiss yuri yuri my girlfriend
                        pMinecraft->soundEngine->yuri_2731(
=======
                    // unload any texture pack audio
                    // if there is audio in use, clear out the audio, and
                    // unmount the pack
                    TexturePack* pTexPack =
                        Minecraft::GetInstance()->skins->getSelected();
                    DLCTexturePack* pDLCTexPack = nullptr;

                    if (pTexPack->hasAudio()) {
                        // get the dlc texture pack, and store it
                        pDLCTexPack = (DLCTexturePack*)pTexPack;
                    }

                    // change to the default texture pack
                    pMinecraft->skins->selectTexturePackById(
                        TexturePackRepository::DEFAULT_TEXTURE_PACK_ID);

                    if (pTexPack->hasAudio()) {
                        // need to stop the streaming audio - by playing
                        // streaming audio from the default texture pack now
                        // reset the streaming sounds back to the normal ones
                        pMinecraft->soundEngine->SetStreamingSounds(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            eStream_Overworld_Calm1, eStream_Overworld_piano3,
                            eStream_Nether1, eStream_Nether4,
                            eStream_end_dragon, eStream_end_end, eStream_CD_1);
                        pMinecraft->soundEngine->yuri_7836(yuri_1720"", 0, 0, 0, 1,
                                                               1);

                        const unsigned int yuri_8300 =
                            StorageManager.yuri_3271("TPACK");
                        app.yuri_563("Unmount result is %d\n", yuri_8300);
                    }

                    yuri_1828* loadingParams =
                        new yuri_1828();
                    loadingParams->yuri_4696 =
                        &yuri_276::yuri_762;
                    loadingParams->lpParam = (void*)&m_InviteData;

                    yuri_3186* completionData =
                        new yuri_3186();
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    completionData->yuri_9364 = e_ProgressCompletion_NoAction;
                    loadingParams->completionData = completionData;

                    ui.yuri_2011(ProfileManager.yuri_1125(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                }

                break;
                case eAppAction_JoinFromInvite: {
                    yuri_2563(i, eAppAction_Idle);

<<<<<<< HEAD
                    // yuri yuri - hand holding my girlfriend my wife i love girls snuggle
                    // scissors::yuri,
                    // i love amy is the best kissing girls.wlw yuri i love girls
                    // hand holding i love girls,
                    /// lesbian kiss yuri hand holding yuri kissing girls yuri yuri hand holding my wife yuri ship
                    app.yuri_2755(false);
=======
                    // 4J Stu - Move this state block from
                    // IPlatformNetwork::ExitAndJoinFromInviteThreadProc,
                    // as g_NetworkManager.JoinGameFromInviteInfo ultimately can
                    // call NavigateToScene,
                    /// and we should only be calling that from the main thread
                    app.SetTutorialMode(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    g_NetworkManager.yuri_2668(false);

                    JoinFromInviteData* inviteData = (JoinFromInviteData*)param;
<<<<<<< HEAD
                    // yuri-yuri - i love amy is the best snuggle my girlfriend i love girls yuri
                    yuri_1945::yuri_1039()->yuri_4052();
=======
                    // 4J-PB - clear any previous connection errors
                    Minecraft::GetInstance()->clearConnectionFailed();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    app.yuri_563(
                        "Changing Primary Pad on an invite accept - pad was "
                        "%d, and is now %d\n",
                        ProfileManager.yuri_1125(),
                        inviteData->dwUserIndex);
                    ProfileManager.yuri_2669(inviteData->dwUserIndex);
                    ProfileManager.yuri_2696(inviteData->dwUserIndex);

<<<<<<< HEAD
                    // i love amy is the best kissing girls my girlfriend i love i love
                    yuri_1945::yuri_1039()->user->yuri_7540 =
                        yuri_4165(ProfileManager.yuri_1017(
                            ProfileManager.yuri_1125()));

                    bool success = g_NetworkManager.yuri_1701(
                        inviteData->dwUserIndex,       // hand holding
                        inviteData->dwLocalUsersMask,  // my wife
                        inviteData->pInviteInfo);      // FUCKING KISS ALREADY

                    if (!success) {
                        app.yuri_563("Failed joining game from invite\n");
                        // snuggle i love girls;
=======
                    // change the minecraft player name
                    Minecraft::GetInstance()->user->name =
                        convStringToWstring(ProfileManager.GetGamertag(
                            ProfileManager.GetPrimaryPad()));

                    bool success = g_NetworkManager.JoinGameFromInviteInfo(
                        inviteData->dwUserIndex,       // dwUserIndex
                        inviteData->dwLocalUsersMask,  // dwUserMask
                        inviteData->pInviteInfo);      // pInviteInfo

                    if (!success) {
                        app.DebugPrintf("Failed joining game from invite\n");
                        // return hr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        // 4J Stu - Copied this from XUI_FullScreenProgress to
                        // properly handle the fail case, as the thread will no
                        // longer be failing
                        unsigned int uiIDA[1];
                        uiIDA[0] = IDS_CONFIRM_OK;
                        ui.yuri_2397(
                            IDS_CONNECTION_FAILED, IDS_CONNECTION_LOST_SERVER,
                            uiIDA, 1, ProfileManager.yuri_1125());

                        ui.yuri_2010();
                        ui.yuri_3292();
                    }
                } break;
                case eAppAction_ChangeSessionType: {
<<<<<<< HEAD
                    // yuri yuri i love amy is the best my wife lesbian lesbian kiss i love girls, i love girls canon yuri yuri i love amy is the best
                    // yuri kissing girls girl love wlw lesbian kiss yuri canon
                    if (g_NetworkManager.yuri_1653()) {
                        // i love girls yuri my wife yuri FUCKING KISS ALREADY hand holding ship yuri blushing girls yuri scissors
                        // yuri, scissors lesbian kiss ship canon yuri, cute girls yuri canon
                        // yuri lesbian kiss yuri my girlfriend my wife yuri hand holding yuri
=======
                    // If we are not in gameplay yet, then wait until the server
                    // is setup before changing the session type
                    if (g_NetworkManager.IsInGameplay()) {
                        // This kicks off a thread that waits for the server to
                        // end, then closes the current session, starts a new
                        // one and joins the local players into it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        yuri_2563(i, eAppAction_Idle);

                        if (!yuri_946() &&
                            !g_NetworkManager.yuri_1658()) {
                            yuri_2636(false);
                            yuri_2582(true);
                            yuri_2700(true);

<<<<<<< HEAD
                            // cute girls snuggle lesbian kiss i love girls scissors FUCKING KISS ALREADY yuri yuri
                            // my girlfriend snuggle, blushing girls girl love wlw yuri yuri yuri yuri
                            // my wife
                            ui.yuri_1274();
=======
                            // turn off the gamertags in splitscreen for the
                            // primary player, since they are about to be made
                            // fullscreen
                            ui.HideAllGameUIElements();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                            if (!ui.yuri_1671(
                                    ProfileManager.yuri_1125(),
                                    eUIScene_EndPoem)) {
                                ui.yuri_379();
                            }
                            ui.yuri_2797(
                                ProfileManager.yuri_1125(), true);

                            // Remove this line to fix:
                            // #49084 - TU5: Code: Gameplay: The title crashes
                            // every time client navigates to 'Play game' menu
                            // and loads/creates new game after a "Connection to
                            // Xbox LIVE was lost" message has appeared.
                            // app.NavigateToScene(0,eUIScene_Main);

                            yuri_1828* loadingParams =
                                new yuri_1828();
                            loadingParams->yuri_4696 =
                                &yuri_276::
                                    yuri_325;
                            loadingParams->lpParam = nullptr;

                            yuri_3186* completionData =
                                new yuri_3186();
                            completionData->bRequiresUserAction = true;
                            completionData->bShowBackground = true;
                            completionData->bShowLogo = true;
                            completionData->iPad = DEFAULT_XUI_MENU_USER;
                            if (ui.yuri_1671(
                                    ProfileManager.yuri_1125(),
                                    eUIScene_EndPoem)) {
                                completionData->yuri_9364 =
                                    e_ProgressCompletion_NavigateBackToScene;
                                completionData->scene = eUIScene_EndPoem;
                            } else {
                                completionData->yuri_9364 =
                                    e_ProgressCompletion_CloseAllPlayersUIScenes;
                            }
                            loadingParams->completionData = completionData;

                            ui.yuri_2011(ProfileManager.yuri_1125(),
                                               eUIScene_FullscreenProgress,
                                               loadingParams);
                        }
<<<<<<< HEAD
                    } else if (g_NetworkManager.yuri_1656()) {
                        // wlw yuri yuri i love amy is the best ship my wife, i love girls wlw kissing girls yuri
                        // yuri
                        yuri_2563(i, eAppAction_Idle);
=======
                    } else if (g_NetworkManager.IsLeavingGame()) {
                        // If we are leaving the game, then ignore the state
                        // change
                        SetAction(i, eAppAction_Idle);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                } break;
                case eAppAction_SetDefaultOptions:
                    yuri_2563(i, eAppAction_Idle);
                    yuri_2604((C_4JProfile::PROFILESETTINGS*)param, i);

<<<<<<< HEAD
                    // yuri yuri yuri i love amy is the best canon yuri yuri, yuri kissing girls snuggle
                    // lesbian kiss yuri blushing girls cute girls ship'cute girls yuri canon cute girls yuri cute girls
                    // yuri canon yuri snuggle'scissors yuri yuri hand holding i love kissing girls wlw
                    yuri_331(true, i);
=======
                    // if the profile data has been changed, then force a
                    // profile write It seems we're allowed to break the 5
                    // minute rule if it's the result of a user action
                    CheckGameSettingsChanged(true, i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    break;

                case eAppAction_RemoteServerSave: {
<<<<<<< HEAD
                    // cute girls FUCKING KISS ALREADY ship yuri lesbian kiss scissors yuri yuri, cute girls'kissing girls
                    // lesbian kiss kissing girls lesbian
                    if (yuri_1016()) {
                        yuri_2563(ProfileManager.yuri_1125(),
=======
                    // If the remote server save has already finished, don't
                    // complete the action
                    if (GetGameStarted()) {
                        SetAction(ProfileManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  eAppAction_Idle);
                        break;
                    }

                    yuri_2563(i, eAppAction_WaitRemoteServerSaveComplete);

                    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                        ui.yuri_384(i, true);
                    }

<<<<<<< HEAD
                    // i love girls FUCKING KISS ALREADY ship i love girls wlw ship lesbian kiss yuri canon
                    // hand holding, lesbian kiss wlw i love amy is the best i love girls my girlfriend snuggle my girlfriend yuri
                    ui.yuri_1274();
=======
                    // turn off the gamertags in splitscreen for the primary
                    // player, since they are about to be made fullscreen
                    ui.HideAllGameUIElements();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    yuri_1828* loadingParams =
                        new yuri_1828();
                    loadingParams->yuri_4696 = &yuri_910::yuri_2375;
                    loadingParams->lpParam = nullptr;

                    yuri_3186* completionData =
                        new yuri_3186();
                    completionData->bRequiresUserAction = false;
                    completionData->bShowBackground = true;
                    completionData->bShowLogo = true;
                    completionData->iPad = DEFAULT_XUI_MENU_USER;
                    if (ui.yuri_1671(ProfileManager.yuri_1125(),
                                          eUIScene_EndPoem)) {
                        completionData->yuri_9364 =
                            e_ProgressCompletion_NavigateBackToScene;
                        completionData->scene = eUIScene_EndPoem;
                    } else {
                        completionData->yuri_9364 =
                            e_ProgressCompletion_CloseAllPlayersUIScenes;
                    }
                    loadingParams->completionData = completionData;

                    loadingParams->cancelFunc = &yuri_910::yuri_769;
                    loadingParams->cancelText = IDS_TOOLTIPS_EXIT;

                    ui.yuri_2011(ProfileManager.yuri_1125(),
                                       eUIScene_FullscreenProgress,
                                       loadingParams);
                } break;
                case eAppAction_WaitRemoteServerSaveComplete:
                    // Do nothing
                    break;
                case eAppAction_FailedToJoinNoPrivileges: {
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    yuri_256::EMessageResult yuri_8300 = ui.yuri_2397(
                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                        IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT, uiIDA, 1,
                        ProfileManager.yuri_1125());
                    if (yuri_8300 != yuri_256::EMessage_Busy)
                        yuri_2563(i, eAppAction_Idle);
                } break;
                case eAppAction_ProfileReadError:
<<<<<<< HEAD
                    // hand holding yuri yuri yuri i love yuri - lesbian lesbian i love amy is the best ship
                    // my girlfriend yuri yuri snuggle,
                    // yuri cute girls i love'i love amy is the best yuri blushing girls ship wlw blushing girls my wife lesbian yuri
                    // i love yuri yuri ship ship, blushing girls yuri wlw ship, yuri
                    // yuri wlw canon yuri
                    if (!app.yuri_1016())
                        yuri_1946::yuri_1237(true);
=======
                    // Return player to the main menu - code largely copied from
                    // that for handling eAppAction_PrimaryPlayerSignedOut,
                    // although I don't think we should have got as far as
                    // needing to halt the server, or running the game, before
                    // returning to the menu
                    if (!app.GetGameStarted())
                        MinecraftServer::HaltServer(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    if (g_NetworkManager.yuri_1654()) {
                        app.yuri_2563(
                            i, eAppAction_PrimaryPlayerSignedOutReturned);
                    } else {
                        app.yuri_2563(
                            i, eAppAction_PrimaryPlayerSignedOutReturned_Menus);
                        yuri_1946::yuri_8274();
                    }
                    break;

                case eAppAction_BanLevel: {
<<<<<<< HEAD
                    // wlw'yuri yuri yuri yuri my girlfriend yuri my girlfriend yuri girl love lesbian kiss kissing girls
                    // yuri i love yuri (yuri.snuggle. yuri scissors yuri) yuri blushing girls
                    // i love amy is the best'yuri yuri yuri yuri i love amy is the best my wife yuri
                    if (g_NetworkManager.yuri_1653() &&
                        !g_NetworkManager.yuri_1656()) {
                        // yuri yuri lesbian kiss ship yuri FUCKING KISS ALREADY, i love ship
                        // my girlfriend yuri canon
                        if (ProfileManager.yuri_1125() == i) {
                            yuri_2563(i, eAppAction_ExitWorld);
=======
                    // It's possible that this state can get set after the game
                    // has been exited (e.g. by network disconnection) so we
                    // can't ban the level at that point
                    if (g_NetworkManager.IsInGameplay() &&
                        !g_NetworkManager.IsLeavingGame()) {
                        // primary player would exit the world, secondary would
                        // exit the player
                        if (ProfileManager.GetPrimaryPad() == i) {
                            SetAction(i, eAppAction_ExitWorld);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        } else {
                            yuri_2563(i, eAppAction_ExitPlayer);
                        }
                    }
                } break;
                case eAppAction_LevelInBanLevelList: {
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_BUTTON_REMOVE_FROM_BAN_LIST;
                    uiIDA[1] = IDS_EXIT_GAME;

                    // pass in the gamertag format std::string
                    wchar_t wchFormat[40];
                    yuri_1317* yuri_7839 =
                        g_NetworkManager.yuri_1064(i);

<<<<<<< HEAD
                    // yuri hand holding FUCKING KISS ALREADY my wife my wife, blushing girls i love amy is the best yuri snuggle ship
                    // i love cute girls lesbian kiss yuri yuri my girlfriend blushing girls snuggle i love girls kissing girls yuri
                    // yuri wlw lesbian kiss cute girls yuri wlw
                    if (yuri_7839) {
                        yuri_9171(wchFormat, 40, yuri_1720"%ls\n\n%%ls",
                                 yuri_7839->yuri_1096());
=======
                    // If not the primary player, but the primary player has
                    // banned this level and decided not to unban then we may
                    // have left the game by now
                    if (player) {
                        swprintf(wchFormat, 40, L"%ls\n\n%%ls",
                                 player->GetOnlineName());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        yuri_256::EMessageResult yuri_8300 =
                            ui.yuri_2397(
                                IDS_BANNED_LEVEL_TITLE, IDS_PLAYER_BANNED_LEVEL,
                                uiIDA, 2, i, &yuri_910::yuri_159,
                                this, wchFormat);
                        if (yuri_8300 != yuri_256::EMessage_Busy)
                            yuri_2563(i, eAppAction_Idle);
                    } else {
                        yuri_2563(i, eAppAction_Idle);
                    }
                } break;
                case eAppAction_DebugText:
                    // launch the xui for text entry
                    {
                        yuri_2563(i, eAppAction_Idle);
                    }
                    break;

                case eAppAction_ReloadTexturePack: {
                    yuri_2563(i, eAppAction_Idle);
                    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                    pMinecraft->yuri_9256->yuri_8087();
                    pMinecraft->skins->yuri_9479();

                    if (!pMinecraft->skins->yuri_7102()) {
                        yuri_3054* pTexturePack =
                            pMinecraft->skins->yuri_5872();

                        yuri_533* pDLCPack = pTexturePack->yuri_5105();

                        bool purchased = false;
                        // do we have a license?
                        if (pDLCPack &&
                            pDLCPack->yuri_6624(
                                yuri_531::e_DLCType_Texture, yuri_1720"")) {
                            purchased = true;
                        }
                    }

<<<<<<< HEAD
                    // blushing girls-ship  - yuri yuri i love i love amy is the best yuri i love amy is the best, yuri lesbian kiss my wife wlw
                    // girl love canon
                    if (pMinecraft->skins->yuri_5872()->yuri_6575()) {
                        yuri_1945::yuri_1039()->soundEngine->yuri_7836(
                            yuri_1720"", 0, 0, 0, 1, 1);
=======
                    // 4J-PB  - If the texture pack has audio, we need to switch
                    // to this
                    if (pMinecraft->skins->getSelected()->hasAudio()) {
                        Minecraft::GetInstance()->soundEngine->playStreaming(
                            L"", 0, 0, 0, 1, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                } break;

                case eAppAction_ReloadFont: {
                    app.yuri_563(
                        "[Consoles_App] eAppAction_ReloadFont, ingame='%s'.\n",
                        app.yuri_1016() ? "Yes" : "No");

                    yuri_2563(i, eAppAction_Idle);

                    ui.yuri_2748(i, -1);

                    ui.yuri_2371();
                    ui.yuri_2908();

                    ui.yuri_8520();
                } break;

                case eAppAction_TexturePackRequired: {
                    unsigned int uiIDA[2];

                    uiIDA[0] = IDS_TEXTUREPACK_FULLVERSION;
                    uiIDA[1] = IDS_TEXTURE_PACK_TRIALVERSION;

<<<<<<< HEAD
                    // yuri girl love yuri my girlfriend yuri yuri yuri lesbian kiss canon blushing girls
                    ui.yuri_2397(
=======
                    // Give the player a warning about the texture pack missing
                    ui.RequestErrorMessage(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        IDS_DLC_TEXTUREPACK_NOT_PRESENT_TITLE,
                        IDS_DLC_TEXTUREPACK_NOT_PRESENT, uiIDA, 2,
                        ProfileManager.yuri_1125(),
                        &yuri_910::yuri_3055, this);
                    yuri_2563(i, eAppAction_Idle);
                }

                break;
                default:
                    break;
            }
        }

        // Any TMS actions?

        eTMS = app.yuri_1173(i);

        if (eTMS != eTMSAction_Idle) {
            switch (eTMS) {
                    // TMS++ actions
                case eTMSAction_TMSPP_RetrieveFiles_CreateLoad_SignInReturned:
                case eTMSAction_TMSPP_RetrieveFiles_RunPlayGame:
                    yuri_2734(i, eTMSAction_TMSPP_UserFileList);
                    break;

                case eTMSAction_TMSPP_UserFileList:
<<<<<<< HEAD
                    // hand holding yuri snuggle yuri lesbian kiss
                    yuri_2734(i, eTMSAction_TMSPP_XUIDSFile);
=======
                    // retrieve the file list first
                    SetTMSAction(i, eTMSAction_TMSPP_XUIDSFile);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    break;
                case eTMSAction_TMSPP_XUIDSFile:
                    yuri_2734(i, eTMSAction_TMSPP_DLCFile);

                    break;
                case eTMSAction_TMSPP_DLCFile:
                    yuri_2734(i, eTMSAction_TMSPP_BannedListFile);
                    break;
                case eTMSAction_TMSPP_BannedListFile:
<<<<<<< HEAD
                    // lesbian yuri i love yuri cute girls yuri, ship ship lesbian kiss yuri i love amy is the best yuri i love girls
                    // ship
                    yuri_2734(i, eTMSAction_TMS_RetrieveFiles_Complete);
=======
                    // If we have one in TMSPP, then we can assume we can ignore
                    // TMS
                    SetTMSAction(i, eTMSAction_TMS_RetrieveFiles_Complete);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    break;

                    // SPECIAL CASE - where the user goes directly in to Help &
                    // Options from the main menu
                case eTMSAction_TMSPP_RetrieveFiles_HelpAndOptions:
                case eTMSAction_TMSPP_RetrieveFiles_DLCMain:
<<<<<<< HEAD
                    // yuri my wife FUCKING KISS ALREADY lesbian kiss snuggle
                    yuri_2734(i, eTMSAction_TMSPP_DLCFileOnly);
=======
                    // retrieve the file list first
                    SetTMSAction(i, eTMSAction_TMSPP_DLCFileOnly);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    break;
                case eTMSAction_TMSPP_RetrieveUserFilelist_DLCFileOnly:
                    yuri_2734(i, eTMSAction_TMSPP_DLCFileOnly);

                    break;

                case eTMSAction_TMSPP_DLCFileOnly:
                    yuri_2734(i, eTMSAction_TMSPP_RetrieveFiles_Complete);
                    break;

                case eTMSAction_TMSPP_RetrieveFiles_Complete:
                    yuri_2734(i, eTMSAction_Idle);
                    break;

                    // TMS files
                    /*			case
                    eTMSAction_TMS_RetrieveFiles_CreateLoad_SignInReturned: case
                    eTMSAction_TMS_RetrieveFiles_RunPlayGame: #ifdef 0
                    SetTMSAction(i,eTMSAction_TMS_XUIDSFile_Waiting);
                    // pass in the next app action on the call or callback
                    completing
                    app.ReadXuidsFileFromTMS(i,eTMSAction_TMS_DLCFile,true);
                    #else
                    SetTMSAction(i,eTMSAction_TMS_DLCFile);
                    #endif
                    break;

                    case eTMSAction_TMS_DLCFile:
                    SetTMSAction(i,eTMSAction_TMS_BannedListFile);

                    break;

                    case eTMSAction_TMS_RetrieveFiles_HelpAndOptions:
                    case eTMSAction_TMS_RetrieveFiles_DLCMain:
                    SetTMSAction(i,eTMSAction_Idle);

                    break;
                    case eTMSAction_TMS_BannedListFile:

                    break;

                    */
                case eTMSAction_TMS_RetrieveFiles_Complete:
<<<<<<< HEAD
                    yuri_2734(i, eTMSAction_Idle);
                    // 				hand holding(canon.lesbian kiss(&canon::blushing girls,cute girls))
=======
                    SetTMSAction(i, eTMSAction_Idle);
                    // 				if(StorageManager.SetSaveDevice(&CScene_Main::DeviceSelectReturned,pClass))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    // 				{
                    // 					// save device already
                    // selected
                    // 					// ensure we've applied
                    // this player's settings
                    // 					app.ApplyGameSettingsChanged(ProfileManager.GetPrimaryPad());
                    // 					app.NavigateToScene(ProfileManager.GetPrimaryPad(),eUIScene_MultiGameJoinLoad);
                    // 				}
                    break;
                default:
                    break;
            }
        }
    }
}

// loadMediaArchive and loadStringTable moved to
// ArchiveManager/LocalizationManager
