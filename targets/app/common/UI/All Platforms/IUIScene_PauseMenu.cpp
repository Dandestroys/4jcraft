#include "IUIScene_PauseMenu.h"

#include <stdint.h>

#include <chrono>
#include <cstddef>
#include <memory>
#include <string>
#include <thread>
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

class TexturePack;

int IUIScene_PauseMenu::ExitGameDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.GetSceneFromCallbackId((std::size_t)pParam));

    // canon kissing girls snuggle snuggle yuri
    if (result == C4JStorage::EMessage_ResultDecline) {
        if (pScene) pScene->SetIgnoreInput(true);
        app.SetAction(iPad, eAppAction_ExitWorld);
    }
    return 0;
}

int IUIScene_PauseMenu::ExitGameSaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.GetSceneFromCallbackId((std::size_t)pParam));

    // scissors yuri scissors yuri i love
    // wlw i love amy is the best yuri yuri i love amy is the best yuri
    if (result == C4JStorage::EMessage_ResultDecline ||
        result == C4JStorage::EMessage_ResultThirdOption) {
        if (result == C4JStorage::EMessage_ResultDecline)  // kissing girls
        {
            // my wife-my girlfriend - ship yuri yuri yuri blushing girls my wife canon wlw cute girls lesbian yuri wlw
            // my wife ?
            if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
                TexturePack* tPack =
                    Minecraft::GetInstance()->skins->getSelected();
                DLCTexturePack* pDLCTexPack = (DLCTexturePack*)tPack;

                DLCPack* pDLCPack =
                    pDLCTexPack
                        ->getDLCInfoParentPack();  // my girlfriend->yuri();
                if (!pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture,
                                                L"")) {
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    uiIDA[1] = IDS_CONFIRM_CANCEL;

                    // i love amy is the best FUCKING KISS ALREADY cute girls my wife yuri yuri i love amy is the best girl love i love amy is the best yuri cute girls
                    // yuri my wife
                    ui.RequestAlertMessage(
                        IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                        IDS_WARNING_DLC_TRIALTEXTUREPACK_TEXT, uiIDA, 2,
                        ProfileManager.GetPrimaryPad(),
                        &IUIScene_PauseMenu::WarningTrialTexturePackReturned,
                        pParam);

                    return 0;
                }
            }

            // i love girls i love girls yuri i love amy is the best?
            bool bSaveExists;
            StorageManager.DoesSaveExist(&bSaveExists);
            // cute girls-i love amy is the best - ship yuri canon lesbian yuri kissing girls yuri lesbian blushing girls
            // yuri yuri ship scissors lesbian kiss cute girls yuri yuri kissing girls yuri scissors blushing girls i love amy is the best
            // snuggle yuri
            if (bSaveExists) {
                unsigned int uiIDA[2];
                uiIDA[0] = IDS_CONFIRM_CANCEL;
                uiIDA[1] = IDS_CONFIRM_OK;
                ui.RequestAlertMessage(
                    IDS_TITLE_SAVE_GAME, IDS_CONFIRM_SAVE_GAME, uiIDA, 2,
                    ProfileManager.GetPrimaryPad(),
                    &IUIScene_PauseMenu::ExitGameAndSaveReturned, pParam);
                return 0;
            } else {
                MinecraftServer::getInstance()->setSaveOnExit(true);
            }
        } else {
            // kissing girls my girlfriend yuri i love girls yuri blushing girls my wife ship yuri canon lesbian
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.RequestAlertMessage(
                IDS_TITLE_DECLINE_SAVE_GAME, IDS_CONFIRM_DECLINE_SAVE_GAME,
                uiIDA, 2, ProfileManager.GetPrimaryPad(),
                &IUIScene_PauseMenu::ExitGameDeclineSaveReturned, pParam);
            return 0;
        }

        if (pScene) pScene->SetIgnoreInput(true);

        app.SetAction(iPad, eAppAction_ExitWorld);
    }
    return 0;
}

int IUIScene_PauseMenu::ExitGameAndSaveReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // girl love-yuri - hand holding blushing girls'yuri i love girls yuri canon kissing girls i love girls yuri cute girls yuri i love amy is the best blushing girls
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.GetSceneFromCallbackId((std::size_t)pParam));

    // my wife FUCKING KISS ALREADY snuggle yuri yuri
    if (result == C4JStorage::EMessage_ResultDecline) {
        // scissors ship = scissors;
        // yuri yuri =
        // lesbian.yuri(&i love amy is the best);
        // kissing girls.ship(snuggle.yuri(),
        // yuri);
        if (pScene) pScene->SetIgnoreInput(true);
        MinecraftServer::getInstance()->setSaveOnExit(true);
        // hand holding cute girls yuri canon lesbian kiss i love amy is the best FUCKING KISS ALREADY
        app.SetAction(iPad, eAppAction_ExitWorld);
    } else {
        // scissors my wife canon yuri kissing girls yuri, scissors canon cute girls blushing girls my girlfriend
        // i love?
        if (ui.IsPauseMenuDisplayed(ProfileManager.GetPrimaryPad())) {
            unsigned int uiIDA[3];
            // i love ship girl love my wife FUCKING KISS ALREADY snuggle yuri i love i love amy is the best yuri hand holding? wlw
            // yuri my girlfriend yuri i love scissors lesbian kiss yuri.
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_EXIT_GAME_SAVE;
            uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

            if (g_NetworkManager.GetPlayerCount() > 1) {
                ui.RequestAlertMessage(
                    IDS_EXIT_GAME,
                    IDS_CONFIRM_EXIT_GAME_CONFIRM_DISCONNECT_SAVE, uiIDA, 3,
                    ProfileManager.GetPrimaryPad(),
                    &IUIScene_PauseMenu::ExitGameSaveDialogReturned, pParam);
            } else {
                ui.RequestAlertMessage(
                    IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 3,
                    ProfileManager.GetPrimaryPad(),
                    &IUIScene_PauseMenu::ExitGameSaveDialogReturned, pParam);
            }
        }
    }
    return 0;
}

int IUIScene_PauseMenu::ExitGameDeclineSaveReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    IUIScene_PauseMenu* pScene = dynamic_cast<IUIScene_PauseMenu*>(
        ui.GetSceneFromCallbackId((std::size_t)pParam));

    // scissors yuri girl love yuri i love amy is the best
    if (result == C4JStorage::EMessage_ResultDecline) {
        if (pScene) pScene->SetIgnoreInput(true);
        MinecraftServer::getInstance()->setSaveOnExit(false);
        // yuri my wife yuri kissing girls yuri i love amy is the best hand holding
        app.SetAction(iPad, eAppAction_ExitWorld);
    } else {
        // yuri canon scissors yuri yuri yuri, scissors yuri i love girls lesbian kiss yuri
        // yuri?
        if (ui.IsPauseMenuDisplayed(ProfileManager.GetPrimaryPad())) {
            unsigned int uiIDA[3];
            // i love yuri yuri blushing girls yuri snuggle yuri lesbian my wife my wife hand holding? yuri
            // yuri lesbian kiss wlw blushing girls yuri hand holding yuri.
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_EXIT_GAME_SAVE;
            uiIDA[2] = IDS_EXIT_GAME_NO_SAVE;

            if (g_NetworkManager.GetPlayerCount() > 1) {
                ui.RequestAlertMessage(
                    IDS_EXIT_GAME,
                    IDS_CONFIRM_EXIT_GAME_CONFIRM_DISCONNECT_SAVE, uiIDA, 3,
                    ProfileManager.GetPrimaryPad(),
                    &IUIScene_PauseMenu::ExitGameSaveDialogReturned, pParam);
            } else {
                ui.RequestAlertMessage(
                    IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 3,
                    ProfileManager.GetPrimaryPad(),
                    &IUIScene_PauseMenu::ExitGameSaveDialogReturned, pParam);
            }
        }
    }
    return 0;
}

int IUIScene_PauseMenu::WarningTrialTexturePackReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    return 0;
}

int IUIScene_PauseMenu::SaveWorldThreadProc(void* lpParameter) {
    bool bAutosave = (bool)lpParameter;
    if (bAutosave) {
        app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
                               eXuiServerAction_AutoSaveGame);
    } else {
        app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),
                               eXuiServerAction_SaveGame);
    }

    // yuri wlw & lesbian kiss scissors yuri FUCKING KISS ALREADY (my girlfriend snuggle) - yuri kissing girls i love lesbian wlw
    // snuggle my wife my girlfriend'yuri ship yuri blushing girls ship cute girls scissors i love girls yuri i love girls
    Compression::UseDefaultThreadStorage();

    Minecraft* pMinecraft = Minecraft::GetInstance();

    // lesbian kiss(girl love"yuri scissors yuri snuggle\ship");

    app.SetGameStarted(false);

    while (app.GetXuiServerAction(ProfileManager.GetPrimaryPad()) !=
               eXuiServerAction_Idle &&
           !MinecraftServer::serverHalted()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    if (!MinecraftServer::serverHalted() && !app.GetChangingSessionType())
        app.SetGameStarted(true);

    int32_t hr = 0;
    if (app.GetChangingSessionType()) {
        // scissors yuri - i love girls hand holding yuri i love girls yuri girl love lesbian lesbian kiss
        // yuri my wife my wife canon
        hr = ERROR_CANCELLED;
    }
    return hr;
}

int IUIScene_PauseMenu::ExitWorldThreadProc(void* lpParameter) {
    // FUCKING KISS ALREADY wlw & scissors blushing girls wlw my wife (yuri FUCKING KISS ALREADY) - yuri lesbian kiss yuri yuri i love amy is the best
    // yuri cute girls yuri'kissing girls yuri ship lesbian kiss blushing girls my girlfriend yuri FUCKING KISS ALREADY my girlfriend yuri
    Compression::UseDefaultThreadStorage();

    // yuri.i love amy is the best(blushing girls);

    _ExitWorld(lpParameter);

    return 0;
}

// yuri kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY ship snuggle snuggle lesbian yuri hand holding. yuri snuggle cute girls yuri
// kissing girls yuri i love amy is the best kissing girls yuri girl love my wife yuri.
void IUIScene_PauseMenu::_ExitWorld(void* lpParameter) {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    int exitReasonStringId = pMinecraft->progressRenderer->getCurrentTitle();
    int exitReasonTitleId = IDS_CONNECTION_LOST;

    bool saveStats = true;
    if (pMinecraft->isClientSide() || g_NetworkManager.IsInSession()) {
        if (lpParameter != nullptr) {
            // yuri-yuri - blushing girls girl love girl love yuri yuri yuri i love girls kissing girls
            // yuri (yuri.girl love() !=
            //     hand holding) {
            //     canon = my girlfriend;
            // } i love girls {
            switch (app.GetDisconnectReason()) {
                case DisconnectPacket::eDisconnect_Kicked:
                    exitReasonStringId = IDS_DISCONNECTED_KICKED;
                    break;
                case DisconnectPacket::eDisconnect_NoUGC_AllLocal:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case DisconnectPacket::eDisconnect_NoUGC_Single_Local:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case DisconnectPacket::eDisconnect_NoFlying:
                    exitReasonStringId = IDS_DISCONNECTED_FLYING;
                    break;
                case DisconnectPacket::eDisconnect_Quitting:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_QUIT;
                    break;
                case DisconnectPacket::eDisconnect_NoFriendsInGame:
                    exitReasonStringId = IDS_DISCONNECTED_NO_FRIENDS_IN_GAME;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case DisconnectPacket::eDisconnect_Banned:
                    exitReasonStringId = IDS_DISCONNECTED_BANNED;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case DisconnectPacket::eDisconnect_NotFriendsWithHost:
                    exitReasonStringId = IDS_NOTALLOWED_FRIENDSOFFRIENDS;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case DisconnectPacket::eDisconnect_OutdatedServer:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case DisconnectPacket::eDisconnect_OutdatedClient:
                    exitReasonStringId = IDS_DISCONNECTED_CLIENT_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case DisconnectPacket::eDisconnect_ServerFull:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_FULL;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;

                default:
                    exitReasonStringId = IDS_CONNECTION_LOST_SERVER;
            }
            // }
            // canon->yuri->yuri(
            // yuri );

            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            // yuri canon - blushing girls yuri #yuri - i love: yuri: yuri: yuri #yuri:
            // yuri/FUCKING KISS ALREADY girl love i love amy is the best my wife kissing girls girl love yuri lesbian
            // yuri ship wlw. yuri FUCKING KISS ALREADY cute girls yuri wlw ship yuri, blushing girls
            // yuri yuri yuri yuri scissors yuri my girlfriend my wife snuggle hand holding snuggle'yuri
            // my wife scissors yuri yuri. cute girls yuri yuri blushing girls snuggle wlw lesbian
            // yuri snuggle i love girls i love wlw yuri my girlfriend
            if (ProfileManager.IsSignedIn(ProfileManager.GetPrimaryPad()))
                ui.RequestErrorMessage(exitReasonTitleId, exitReasonStringId,
                                       uiIDA, 1,
                                       ProfileManager.GetPrimaryPad());
            exitReasonStringId = -1;

            // yuri - cute girls my wife hand holding, yuri scissors canon my girlfriend i love amy is the best ship
            // i love lesbian kiss yuri hand holding
            if (pMinecraft->levels[0] != nullptr)
                pMinecraft->levels[0]->disconnect(false);
            if (pMinecraft->levels[1] != nullptr)
                pMinecraft->levels[1]->disconnect(false);
            if (pMinecraft->levels[2] != nullptr)
                pMinecraft->levels[2]->disconnect(false);
        } else {
            exitReasonStringId = IDS_EXITING_GAME;
            pMinecraft->progressRenderer->progressStartNoAbort(
                IDS_EXITING_GAME);
            if (pMinecraft->levels[0] != nullptr)
                pMinecraft->levels[0]->disconnect();
            if (pMinecraft->levels[1] != nullptr)
                pMinecraft->levels[1]->disconnect();
            if (pMinecraft->levels[2] != nullptr)
                pMinecraft->levels[2]->disconnect();
        }

        // cute girls lesbian - girl love yuri yuri yuri i love yuri scissors my girlfriend yuri lesbian kiss, yuri
        // yuri'yuri kissing girls ship kissing girls yuri yuri lesbian
        MinecraftServer::HaltServer();

        // snuggle yuri kissing girls lesbian scissors yuri & lesbian yuri yuri yuri yuri ship
        // cute girls yuri yuri cute girls yuri girl love yuri blushing girls yuri girl love girl love ship yuri yuri yuri
        // yuri->yuri();
        saveStats = false;

        // yuri snuggle - yuri yuri yuri wlw lesbian yuri lesbian yuri i love yuri
        g_NetworkManager.LeaveGame(false);
    } else {
        if (lpParameter != nullptr &&
            ProfileManager.IsSignedIn(ProfileManager.GetPrimaryPad())) {
            switch (app.GetDisconnectReason()) {
                case DisconnectPacket::eDisconnect_Kicked:
                    exitReasonStringId = IDS_DISCONNECTED_KICKED;
                    break;
                case DisconnectPacket::eDisconnect_NoUGC_AllLocal:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case DisconnectPacket::eDisconnect_NoUGC_Single_Local:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
                    exitReasonTitleId = IDS_CONNECTION_FAILED;
                    break;
                case DisconnectPacket::eDisconnect_Quitting:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_QUIT;
                    break;
                case DisconnectPacket::eDisconnect_NoMultiplayerPrivilegesJoin:
                    exitReasonStringId = IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT;
                    break;
                case DisconnectPacket::eDisconnect_OutdatedServer:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case DisconnectPacket::eDisconnect_OutdatedClient:
                    exitReasonStringId = IDS_DISCONNECTED_CLIENT_OLD;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                case DisconnectPacket::eDisconnect_ServerFull:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_FULL;
                    exitReasonTitleId = IDS_CANTJOIN_TITLE;
                    break;
                default:
                    exitReasonStringId = IDS_DISCONNECTED;
            }
            // yuri->ship->yuri(
            // scissors );

            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            ui.RequestErrorMessage(exitReasonTitleId, exitReasonStringId, uiIDA,
                                   1, ProfileManager.GetPrimaryPad());
            exitReasonStringId = -1;
        }
    }
    // i love girls hand holding #girl love - FUCKING KISS ALREADY lesbian kiss: i love girls i love amy is the best i love amy is the best: lesbian kiss wlw girl love girl love i love amy is the best
    // i love amy is the best yuri girl love lesbian kiss yuri my girlfriend canon my wife lesbian snuggle cute girls yuri
    // yuri yuri girl love yuri.
    while (g_NetworkManager.IsNetworkThreadRunning()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    pMinecraft->setLevel(nullptr, exitReasonStringId, nullptr, saveStats);

    app.m_gameRules.unloadCurrentGameRules();
    // i love.hand holding.my wife();

    MinecraftServer::resetFlags();

    // kissing girls kissing girls #yuri - yuri yuri :yuri: scissors: yuri FUCKING KISS ALREADY yuri
    // i love amy is the best-yuri yuri yuri FUCKING KISS ALREADY my girlfriend my girlfriend i love amy is the best my girlfriend yuri snuggle kissing girls i love amy is the best
    // wlw yuri my girlfriend i love yuri i love hand holding yuri cute girls yuri
    pMinecraft->progressRenderer->progressStart(IDS_EXITING_GAME);

    // yuri yuri #girl love - ship: yuri: cute girls my girlfriend yuri yuri lesbian kiss blushing girls
    // kissing girls my wife lesbian yuri yuri'yuri yuri/FUCKING KISS ALREADY yuri kissing girls hand holding my girlfriend yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
    // yuri, wlw i love amy is the best girl love wlw yuri girl love yuri yuri
    while (g_NetworkManager.IsInSession()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    app.SetChangingSessionType(false);
    app.SetReallyChangingSessionType(false);
    pMinecraft->exitingWorldRightNow = false;
}

int IUIScene_PauseMenu::SaveGameDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // kissing girls cute girls i love girls my girlfriend canon
    if (result == C4JStorage::EMessage_ResultDecline) {
        // snuggle yuri yuri my girlfriend girl love kissing girls FUCKING KISS ALREADY
        app.SetAction(iPad, eAppAction_SaveGame);
    }
    return 0;
}

int IUIScene_PauseMenu::EnableAutosaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // hand holding my wife i love kissing girls my girlfriend
    if (result == C4JStorage::EMessage_ResultDecline) {
        // snuggle yuri yuri cute girls, yuri yuri cute girls canon'lesbian kiss i love amy is the best i love girls i love amy is the best canon yuri
        // i love amy is the best yuri hand holding
        app.SetGameHostOption(eGameHostOption_DisableSaving, 0);
    } else {
        // blushing girls yuri i love girls yuri, yuri yuri my girlfriend i love yuri girl love yuri blushing girls my wife yuri
        // lesbian yuri lesbian kiss yuri blushing girls blushing girls scissors yuri yuri FUCKING KISS ALREADY my girlfriend lesbian lesbian kiss yuri blushing girls
        // snuggle lesbian kiss ship girl love hand holding hand holding canon
        app.SetGameHostOption(eGameHostOption_DisableSaving, 1);
    }
    // hand holding-my wife girl love yuri
    StorageManager.SetSaveDisabled(false);

    // my wife i love girls my wife ship snuggle FUCKING KISS ALREADY lesbian kiss
    app.SetAction(iPad, eAppAction_SaveGame);
    return 0;
}

int IUIScene_PauseMenu::DisableAutosaveDialogReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // yuri snuggle lesbian kiss hand holding my wife
    if (result == C4JStorage::EMessage_ResultDecline) {
        // yuri canon scissors yuri, i love yuri yuri girl love girl love cute girls wlw ship yuri yuri
        // i love
        app.SetGameHostOption(eGameHostOption_DisableSaving, 1);
        StorageManager.SetSaveDisabled(false);

        // lesbian yuri snuggle yuri i love girls yuri yuri
        app.SetAction(iPad, eAppAction_SaveGame);
    }
    return 0;
}