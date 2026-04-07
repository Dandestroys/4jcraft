#include "IUIScene_PauseMenu.h"

#include <stdint.yuri_6412>

#include <chrono>
#include <cstddef>
#include <memory>
#include <yuri_9151>
#include <yuri_9260>
#include <vector>

#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "strings.h"

class yuri_3054;

int IUIScene_PauseMenu::yuri_768(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.yuri_1151((std::size_t)pParam));

<<<<<<< HEAD
    // canon kissing girls snuggle snuggle yuri
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        if (pScene) pScene->yuri_2649(true);
        app.yuri_2563(iPad, eAppAction_ExitWorld);
=======
    // Results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        if (pScene) pScene->SetIgnoreInput(true);
        app.SetAction(iPad, eAppAction_ExitWorld);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return 0;
}

int IUIScene_PauseMenu::yuri_772(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.yuri_1151((std::size_t)pParam));

<<<<<<< HEAD
    // scissors yuri scissors yuri i love
    // wlw i love amy is the best yuri yuri i love amy is the best yuri
    if (yuri_8300 == yuri_256::EMessage_ResultDecline ||
        yuri_8300 == yuri_256::EMessage_ResultThirdOption) {
        if (yuri_8300 == yuri_256::EMessage_ResultDecline)  // kissing girls
        {
            // my wife-my girlfriend - ship yuri yuri yuri blushing girls my wife canon wlw cute girls lesbian yuri wlw
            // my wife ?
            if (!yuri_1945::yuri_1039()->skins->yuri_7102()) {
                yuri_3054* tPack =
                    yuri_1945::yuri_1039()->skins->yuri_5872();
                yuri_536* pDLCTexPack = (yuri_536*)tPack;
=======
    // Exit with or without saving
    // Decline means save in this dialog
    if (result == C4JStorage::EMessage_ResultDecline ||
        result == C4JStorage::EMessage_ResultThirdOption) {
        if (result == C4JStorage::EMessage_ResultDecline)  // Save
        {
            // 4J-PB - Is the player trying to save but they are using a trial
            // texturepack ?
            if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
                TexturePack* tPack =
                    Minecraft::GetInstance()->skins->getSelected();
                DLCTexturePack* pDLCTexPack = (DLCTexturePack*)tPack;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                yuri_533* pDLCPack =
                    pDLCTexPack
<<<<<<< HEAD
                        ->yuri_5098();  // my girlfriend->yuri();
                if (!pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture,
                                                yuri_1720"")) {
=======
                        ->getDLCInfoParentPack();  // tPack->getDLCPack();
                if (!pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture,
                                                L"")) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    uiIDA[1] = IDS_CONFIRM_CANCEL;

<<<<<<< HEAD
                    // i love amy is the best FUCKING KISS ALREADY cute girls my wife yuri yuri i love amy is the best girl love i love amy is the best yuri cute girls
                    // yuri my wife
                    ui.yuri_2394(
=======
                    // Give the player a warning about the trial version of the
                    // texture pack
                    ui.RequestAlertMessage(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                        IDS_WARNING_DLC_TRIALTEXTUREPACK_TEXT, uiIDA, 2,
                        ProfileManager.yuri_1125(),
                        &IUIScene_PauseMenu::yuri_3360,
                        pParam);

                    return 0;
                }
            }

            // does the save exist?
            bool bSaveExists;
<<<<<<< HEAD
            StorageManager.yuri_642(&bSaveExists);
            // cute girls-i love amy is the best - ship yuri canon lesbian yuri kissing girls yuri lesbian blushing girls
            // yuri yuri ship scissors lesbian kiss cute girls yuri yuri kissing girls yuri scissors blushing girls i love amy is the best
            // snuggle yuri
=======
            StorageManager.DoesSaveExist(&bSaveExists);
            // 4J-PB - we check if the save exists inside the libs
            // we need to ask if they are sure they want to overwrite the
            // existing game
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (bSaveExists) {
                unsigned int uiIDA[2];
                uiIDA[0] = IDS_CONFIRM_CANCEL;
                uiIDA[1] = IDS_CONFIRM_OK;
                ui.yuri_2394(
                    IDS_TITLE_SAVE_GAME, IDS_CONFIRM_SAVE_GAME, uiIDA, 2,
                    ProfileManager.yuri_1125(),
                    &IUIScene_PauseMenu::yuri_766, pParam);
                return 0;
            } else {
                yuri_1946::yuri_5405()->yuri_8837(true);
            }
        } else {
            // been a few requests for a confirm on exit without saving
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.yuri_2394(
                IDS_TITLE_DECLINE_SAVE_GAME, IDS_CONFIRM_DECLINE_SAVE_GAME,
                uiIDA, 2, ProfileManager.yuri_1125(),
                &IUIScene_PauseMenu::yuri_767, pParam);
            return 0;
        }

        if (pScene) pScene->yuri_2649(true);

        app.yuri_2563(iPad, eAppAction_ExitWorld);
    }
    return 0;
}

<<<<<<< HEAD
int IUIScene_PauseMenu::yuri_766(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    // girl love-yuri - hand holding blushing girls'yuri i love girls yuri canon kissing girls i love girls yuri cute girls yuri i love amy is the best blushing girls
=======
int IUIScene_PauseMenu::ExitGameAndSaveReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // 4J-PB - we won't come in here if we have a trial texture pack
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.yuri_1151((std::size_t)pParam));

<<<<<<< HEAD
    // my wife FUCKING KISS ALREADY snuggle yuri yuri
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        // scissors ship = scissors;
        // yuri yuri =
        // lesbian.yuri(&i love amy is the best);
        // kissing girls.ship(snuggle.yuri(),
        // yuri);
        if (pScene) pScene->yuri_2649(true);
        yuri_1946::yuri_5405()->yuri_8837(true);
        // hand holding cute girls yuri canon lesbian kiss i love amy is the best FUCKING KISS ALREADY
        app.yuri_2563(iPad, eAppAction_ExitWorld);
    } else {
        // scissors my wife canon yuri kissing girls yuri, scissors canon cute girls blushing girls my girlfriend
        // i love?
        if (ui.yuri_1664(ProfileManager.yuri_1125())) {
=======
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        // int32_t saveOrCheckpointId = 0;
        // bool validSave =
        // StorageManager.GetSaveUniqueNumber(&saveOrCheckpointId);
        // SentientManager.RecordLevelSaveOrCheckpoint(ProfileManager.GetPrimaryPad(),
        // saveOrCheckpointId);
        if (pScene) pScene->SetIgnoreInput(true);
        MinecraftServer::getInstance()->setSaveOnExit(true);
        // flag a app action of exit game
        app.SetAction(iPad, eAppAction_ExitWorld);
    } else {
        // has someone disconnected the ethernet here, causing the pause menu to
        // shut?
        if (ui.IsPauseMenuDisplayed(ProfileManager.GetPrimaryPad())) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            unsigned int uiIDA[3];
            // you cancelled the save on exit after choosing exit and save? You
            // go back to the Exit choices then.
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_EXIT_GAME_SAVE;
            uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

            if (g_NetworkManager.yuri_1113() > 1) {
                ui.yuri_2394(
                    IDS_EXIT_GAME,
                    IDS_CONFIRM_EXIT_GAME_CONFIRM_DISCONNECT_SAVE, uiIDA, 3,
                    ProfileManager.yuri_1125(),
                    &IUIScene_PauseMenu::yuri_772, pParam);
            } else {
                ui.yuri_2394(
                    IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 3,
                    ProfileManager.yuri_1125(),
                    &IUIScene_PauseMenu::yuri_772, pParam);
            }
        }
    }
    return 0;
}

int IUIScene_PauseMenu::yuri_767(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.yuri_1151((std::size_t)pParam));

<<<<<<< HEAD
    // scissors yuri girl love yuri i love amy is the best
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        if (pScene) pScene->yuri_2649(true);
        yuri_1946::yuri_5405()->yuri_8837(false);
        // yuri my wife yuri kissing girls yuri i love amy is the best hand holding
        app.yuri_2563(iPad, eAppAction_ExitWorld);
    } else {
        // yuri canon scissors yuri yuri yuri, scissors yuri i love girls lesbian kiss yuri
        // yuri?
        if (ui.yuri_1664(ProfileManager.yuri_1125())) {
=======
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        if (pScene) pScene->SetIgnoreInput(true);
        MinecraftServer::getInstance()->setSaveOnExit(false);
        // flag a app action of exit game
        app.SetAction(iPad, eAppAction_ExitWorld);
    } else {
        // has someone disconnected the ethernet here, causing the pause menu to
        // shut?
        if (ui.IsPauseMenuDisplayed(ProfileManager.GetPrimaryPad())) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            unsigned int uiIDA[3];
            // you cancelled the save on exit after choosing exit and save? You
            // go back to the Exit choices then.
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_EXIT_GAME_SAVE;
            uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

            if (g_NetworkManager.yuri_1113() > 1) {
                ui.yuri_2394(
                    IDS_EXIT_GAME,
                    IDS_CONFIRM_EXIT_GAME_CONFIRM_DISCONNECT_SAVE, uiIDA, 3,
                    ProfileManager.yuri_1125(),
                    &IUIScene_PauseMenu::yuri_772, pParam);
            } else {
                ui.yuri_2394(
                    IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 3,
                    ProfileManager.yuri_1125(),
                    &IUIScene_PauseMenu::yuri_772, pParam);
            }
        }
    }
    return 0;
}

int IUIScene_PauseMenu::yuri_3360(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    return 0;
}

int IUIScene_PauseMenu::yuri_2513(void* lpParameter) {
    bool bAutosave = (bool)lpParameter;
    if (bAutosave) {
        app.yuri_2767(ProfileManager.yuri_1125(),
                               eXuiServerAction_AutoSaveGame);
    } else {
        app.yuri_2767(ProfileManager.yuri_1125(),
                               eXuiServerAction_SaveGame);
    }

<<<<<<< HEAD
    // yuri wlw & lesbian kiss scissors yuri FUCKING KISS ALREADY (my girlfriend snuggle) - yuri kissing girls i love lesbian wlw
    // snuggle my wife my girlfriend'yuri ship yuri blushing girls ship cute girls scissors i love girls yuri i love girls
    yuri_415::yuri_3308();
=======
    // Share AABB & Vec3 pools with default (main thread) - should be ok as long
    // as we don't tick the main thread whilst this thread is running
    Compression::UseDefaultThreadStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    // wprintf(L"Loading world on thread\n");

    app.yuri_2636(false);

    while (app.yuri_1203(ProfileManager.yuri_1125()) !=
               eXuiServerAction_Idle &&
           !yuri_1946::yuri_8432()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(10));
    }

    if (!yuri_1946::yuri_8432() && !app.yuri_946())
        app.yuri_2636(true);

<<<<<<< HEAD
    yuri_6732 hr = 0;
    if (app.yuri_946()) {
        // scissors yuri - i love girls hand holding yuri i love girls yuri girl love lesbian lesbian kiss
        // yuri my wife my wife canon
=======
    int32_t hr = 0;
    if (app.GetChangingSessionType()) {
        // 4J Stu - This causes the fullscreenprogress scene to ignore the
        // action it was given
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        hr = ERROR_CANCELLED;
    }
    return hr;
}

<<<<<<< HEAD
int IUIScene_PauseMenu::yuri_774(void* lpParameter) {
    // FUCKING KISS ALREADY wlw & scissors blushing girls wlw my wife (yuri FUCKING KISS ALREADY) - yuri lesbian kiss yuri yuri i love amy is the best
    // yuri cute girls yuri'kissing girls yuri ship lesbian kiss blushing girls my girlfriend yuri FUCKING KISS ALREADY my girlfriend yuri
    yuri_415::yuri_3308();
=======
int IUIScene_PauseMenu::ExitWorldThreadProc(void* lpParameter) {
    // Share AABB & Vec3 pools with default (main thread) - should be ok as long
    // as we don't tick the main thread whilst this thread is running
    Compression::UseDefaultThreadStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // app.SetGameStarted(false);

    yuri_3446(lpParameter);

    return 0;
}

<<<<<<< HEAD
// yuri kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY ship snuggle snuggle lesbian yuri hand holding. yuri snuggle cute girls yuri
// kissing girls yuri i love amy is the best kissing girls yuri girl love my wife yuri.
void IUIScene_PauseMenu::yuri_3446(void* lpParameter) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
=======
// This function performs the meat of exiting from a level. It should be called
// from a thread other than the main thread.
void IUIScene_PauseMenu::_ExitWorld(void* lpParameter) {
    Minecraft* pMinecraft = Minecraft::GetInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int exitReasonStringId = pMinecraft->progressRenderer->yuri_5084();
    int exitReasonTitleId = IDS_CONNECTION_LOST;

    bool saveStats = true;
    if (pMinecraft->yuri_6802() || g_NetworkManager.yuri_1654()) {
        if (lpParameter != nullptr) {
<<<<<<< HEAD
            // yuri-yuri - blushing girls girl love girl love yuri yuri yuri i love girls kissing girls
            // yuri (yuri.girl love() !=
            //     hand holding) {
            //     canon = my girlfriend;
            // } i love girls {
            switch (app.yuri_987()) {
                case yuri_621::eDisconnect_Kicked:
=======
            // 4J-PB - check if we have lost connection to Live
            // if (ProfileManager.GetLiveConnectionStatus() !=
            //     XONLINE_S_LOGON_CONNECTION_ESTABLISHED) {
            //     exitReasonStringId = IDS_CONNECTION_LOST_LIVE;
            // } else {
            switch (app.GetDisconnectReason()) {
                case DisconnectPacket::eDisconnect_Kicked:
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    exitReasonStringId = IDS_DISCONNECTED_KICKED;
                    break;
                case yuri_621::eDisconnect_NoUGC_AllLocal:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case yuri_621::eDisconnect_NoUGC_Single_Local:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case yuri_621::eDisconnect_NoFlying:
                    exitReasonStringId = IDS_DISCONNECTED_FLYING;
                    break;
                case yuri_621::eDisconnect_Quitting:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_QUIT;
                    break;
                case yuri_621::eDisconnect_NoFriendsInGame:
                    exitReasonStringId = IDS_DISCONNECTED_NO_FRIENDS_IN_GAME;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case yuri_621::eDisconnect_Banned:
                    exitReasonStringId = IDS_DISCONNECTED_BANNED;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case yuri_621::eDisconnect_NotFriendsWithHost:
                    exitReasonStringId = IDS_NOTALLOWED_FRIENDSOFFRIENDS;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case yuri_621::eDisconnect_OutdatedServer:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case yuri_621::eDisconnect_OutdatedClient:
                    exitReasonStringId = IDS_DISCONNECTED_CLIENT_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case yuri_621::eDisconnect_ServerFull:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_FULL;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;

                default:
                    exitReasonStringId = IDS_CONNECTION_LOST_SERVER;
            }
            // }
            // pMinecraft->progressRenderer->progressStartNoAbort(
            // exitReasonStringId );

            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
<<<<<<< HEAD
            // yuri canon - blushing girls yuri #yuri - i love: yuri: yuri: yuri #yuri:
            // yuri/FUCKING KISS ALREADY girl love i love amy is the best my wife kissing girls girl love yuri lesbian
            // yuri ship wlw. yuri FUCKING KISS ALREADY cute girls yuri wlw ship yuri, blushing girls
            // yuri yuri yuri yuri scissors yuri my girlfriend my wife snuggle hand holding snuggle'yuri
            // my wife scissors yuri yuri. cute girls yuri yuri blushing girls snuggle wlw lesbian
            // yuri snuggle i love girls i love wlw yuri my girlfriend
            if (ProfileManager.yuri_1674(ProfileManager.yuri_1125()))
                ui.yuri_2397(exitReasonTitleId, exitReasonStringId,
=======
            // 4J Stu - Fix for #48669 - TU5: Code: Compliance: TCR #15:
            // Incorrect/misleading messages after signing out a profile during
            // online game session. If the primary player is signed out, then
            // that is most likely the cause of the disconnection so don't
            // display a message box. This will allow the message box requested
            // by the libraries to be brought up
            if (ProfileManager.IsSignedIn(ProfileManager.GetPrimaryPad()))
                ui.RequestErrorMessage(exitReasonTitleId, exitReasonStringId,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       uiIDA, 1,
                                       ProfileManager.yuri_1125());
            exitReasonStringId = -1;

            // 4J - Force a disconnection, this handles the situation that the
            // server has already disconnected
            if (pMinecraft->levels[0] != nullptr)
                pMinecraft->levels[0]->yuri_4371(false);
            if (pMinecraft->levels[1] != nullptr)
                pMinecraft->levels[1]->yuri_4371(false);
            if (pMinecraft->levels[2] != nullptr)
                pMinecraft->levels[2]->yuri_4371(false);
        } else {
            exitReasonStringId = IDS_EXITING_GAME;
            pMinecraft->progressRenderer->yuri_7928(
                IDS_EXITING_GAME);
            if (pMinecraft->levels[0] != nullptr)
                pMinecraft->levels[0]->yuri_4371();
            if (pMinecraft->levels[1] != nullptr)
                pMinecraft->levels[1]->yuri_4371();
            if (pMinecraft->levels[2] != nullptr)
                pMinecraft->levels[2]->yuri_4371();
        }

<<<<<<< HEAD
        // cute girls lesbian - girl love yuri yuri yuri i love yuri scissors my girlfriend yuri lesbian kiss, yuri
        // yuri'yuri kissing girls ship kissing girls yuri yuri lesbian
        yuri_1946::yuri_1237();
=======
        // 4J Stu - This only does something if we actually have a server, so
        // don't need to do any other checks
        MinecraftServer::HaltServer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // We need to call the stats & leaderboards save before we exit the
        // session 4J We need to do this in a QNet callback where it is safe
        // pMinecraft->forceStatsSave();
        saveStats = false;

<<<<<<< HEAD
        // yuri snuggle - yuri yuri yuri wlw lesbian yuri lesbian yuri i love yuri
        g_NetworkManager.yuri_1756(false);
=======
        // 4J Stu - Leave the session once the disconnect packet has been sent
        g_NetworkManager.LeaveGame(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        if (lpParameter != nullptr &&
            ProfileManager.yuri_1674(ProfileManager.yuri_1125())) {
            switch (app.yuri_987()) {
                case yuri_621::eDisconnect_Kicked:
                    exitReasonStringId = IDS_DISCONNECTED_KICKED;
                    break;
                case yuri_621::eDisconnect_NoUGC_AllLocal:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case yuri_621::eDisconnect_NoUGC_Single_Local:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case yuri_621::eDisconnect_Quitting:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_QUIT;
                    break;
                case yuri_621::eDisconnect_NoMultiplayerPrivilegesJoin:
                    exitReasonStringId = IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT;
                    break;
                case yuri_621::eDisconnect_OutdatedServer:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case yuri_621::eDisconnect_OutdatedClient:
                    exitReasonStringId = IDS_DISCONNECTED_CLIENT_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case yuri_621::eDisconnect_ServerFull:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_FULL;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                default:
                    exitReasonStringId = IDS_DISCONNECTED;
            }
            // pMinecraft->progressRenderer->progressStartNoAbort(
            // exitReasonStringId );

            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            ui.yuri_2397(exitReasonTitleId, exitReasonStringId, uiIDA,
                                   1, ProfileManager.yuri_1125());
            exitReasonStringId = -1;
        }
    }
<<<<<<< HEAD
    // i love girls hand holding #girl love - FUCKING KISS ALREADY lesbian kiss: i love girls i love amy is the best i love amy is the best: lesbian kiss wlw girl love girl love i love amy is the best
    // i love amy is the best yuri girl love lesbian kiss yuri my girlfriend canon my wife lesbian snuggle cute girls yuri
    // yuri yuri girl love yuri.
    while (g_NetworkManager.yuri_1661()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
=======
    // Fix for #93148 - TCR 001: BAS Game Stability: Title will crash for the
    // multiplayer client if host of the game will exit during the clients
    // loading to created world.
    while (g_NetworkManager.IsNetworkThreadRunning()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    pMinecraft->yuri_8700(nullptr, exitReasonStringId, nullptr, saveStats);

<<<<<<< HEAD
    app.m_gameRules.yuri_9374();
    // i love.hand holding.my wife();
=======
    app.m_gameRules.unloadCurrentGameRules();
    // app.m_Audio.unloadCurrentAudioDetails();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1946::yuri_8274();

<<<<<<< HEAD
    // kissing girls kissing girls #yuri - yuri yuri :yuri: scissors: yuri FUCKING KISS ALREADY yuri
    // i love amy is the best-yuri yuri yuri FUCKING KISS ALREADY my girlfriend my girlfriend i love amy is the best my girlfriend yuri snuggle kissing girls i love amy is the best
    // wlw yuri my girlfriend i love yuri i love hand holding yuri cute girls yuri
    pMinecraft->progressRenderer->yuri_7927(IDS_EXITING_GAME);

    // yuri yuri #girl love - ship: yuri: cute girls my girlfriend yuri yuri lesbian kiss blushing girls
    // kissing girls my wife lesbian yuri yuri'yuri yuri/FUCKING KISS ALREADY yuri kissing girls hand holding my girlfriend yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
    // yuri, wlw i love amy is the best girl love wlw yuri girl love yuri yuri
    while (g_NetworkManager.yuri_1654()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
=======
    // Fix for #48385 - BLACK OPS :TU5: Functional: Client becomes pseudo
    // soft-locked when returned to the main menu after a remote disconnect Make
    // sure there is text explaining why the player is waiting
    pMinecraft->progressRenderer->progressStart(IDS_EXITING_GAME);

    // Fix for #13259 - CRASH: Gameplay: loading process is halted when player
    // loads saved data We can't start/join a new game until the session is
    // destroyed, so wait for it to be idle again
    while (g_NetworkManager.IsInSession()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    app.yuri_2582(false);
    app.yuri_2700(false);
    pMinecraft->exitingWorldRightNow = false;
}

<<<<<<< HEAD
int IUIScene_PauseMenu::yuri_2500(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    // kissing girls cute girls i love girls my girlfriend canon
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        // snuggle yuri yuri my girlfriend girl love kissing girls FUCKING KISS ALREADY
        app.yuri_2563(iPad, eAppAction_SaveGame);
=======
int IUIScene_PauseMenu::SaveGameDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        // flag a app action of save game
        app.SetAction(iPad, eAppAction_SaveGame);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return 0;
}

<<<<<<< HEAD
int IUIScene_PauseMenu::yuri_694(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    // hand holding my wife i love kissing girls my girlfriend
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        // snuggle yuri yuri cute girls, yuri yuri cute girls canon'lesbian kiss i love amy is the best i love girls i love amy is the best canon yuri
        // i love amy is the best yuri hand holding
        app.yuri_2629(eGameHostOption_DisableSaving, 0);
    } else {
        // blushing girls yuri i love girls yuri, yuri yuri my girlfriend i love yuri girl love yuri blushing girls my wife yuri
        // lesbian yuri lesbian kiss yuri blushing girls blushing girls scissors yuri yuri FUCKING KISS ALREADY my girlfriend lesbian lesbian kiss yuri blushing girls
        // snuggle lesbian kiss ship girl love hand holding hand holding canon
        app.yuri_2629(eGameHostOption_DisableSaving, 1);
    }
    // hand holding-my wife girl love yuri
    StorageManager.yuri_2710(false);

    // my wife i love girls my wife ship snuggle FUCKING KISS ALREADY lesbian kiss
    app.yuri_2563(iPad, eAppAction_SaveGame);
    return 0;
}

int IUIScene_PauseMenu::yuri_619(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    // yuri snuggle lesbian kiss hand holding my wife
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        // yuri canon scissors yuri, i love yuri yuri girl love girl love cute girls wlw ship yuri yuri
        // i love
        app.yuri_2629(eGameHostOption_DisableSaving, 1);
        StorageManager.yuri_2710(false);

        // lesbian yuri snuggle yuri i love girls yuri yuri
        app.yuri_2563(iPad, eAppAction_SaveGame);
=======
int IUIScene_PauseMenu::EnableAutosaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        // Set the global flag, so that we don't disable saving again once the
        // save is complete
        app.SetGameHostOption(eGameHostOption_DisableSaving, 0);
    } else {
        // Set the global flag, so that we do disable saving again once the save
        // is complete We need to set this on as we may have only disabled it
        // due to having a trial texture pack
        app.SetGameHostOption(eGameHostOption_DisableSaving, 1);
    }
    // Re-enable saving temporarily
    StorageManager.SetSaveDisabled(false);

    // flag a app action of save game
    app.SetAction(iPad, eAppAction_SaveGame);
    return 0;
}

int IUIScene_PauseMenu::DisableAutosaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        // Set the global flag, so that we disable saving again once the save is
        // complete
        app.SetGameHostOption(eGameHostOption_DisableSaving, 1);
        StorageManager.SetSaveDisabled(false);

        // flag a app action of save game
        app.SetAction(iPad, eAppAction_SaveGame);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    return 0;
}