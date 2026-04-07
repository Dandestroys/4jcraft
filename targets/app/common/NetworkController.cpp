#include "app/common/NetworkController.h"

#include "app/common/Game.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"
#include "app/common/Audio/SoundEngine.h"

#include <cstring>
#include <chrono>
#include <yuri_9260>

unsigned int yuri_2022::m_uiLastSignInData = 0;

yuri_2022::yuri_2022() {
    m_disconnectReason = yuri_621::eDisconnect_None;
    m_bLiveLinkRequired = false;
    m_bChangingSessionType = false;
    m_bReallyChangingSessionType = false;

    memset(&m_InviteData, 0, sizeof(JoinFromInviteData));
    memset(m_playerColours, 0, MINECRAFT_NET_MAX_PLAYERS);
    memset(m_playerGamePrivileges, 0, sizeof(m_playerGamePrivileges));

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (yuri_786(yuri_3413(i,
                                      XUSER_GET_SIGNIN_INFO_OFFLINE_XUID_ONLY,
                                      &m_currentSigninInfo[i]))) {
            m_currentSigninInfo[i].xuid = INVALID_XUID;
            m_currentSigninInfo[i].dwGuestNumber = 0;
        }
    }
}

void yuri_2022::yuri_9449(std::yuri_9368 networkSmallId,
                                         int16_t playerColourIndex,
                                         unsigned int playerGamePrivileges) {
    for (unsigned int i = 0; i < MINECRAFT_NET_MAX_PLAYERS; ++i) {
        if (m_playerColours[i] == networkSmallId) {
            m_playerColours[i] = 0;
            m_playerGamePrivileges[i] = 0;
        }
    }
    if (playerColourIndex >= 0 &&
        playerColourIndex < MINECRAFT_NET_MAX_PLAYERS) {
        m_playerColours[playerColourIndex] = networkSmallId;
        m_playerGamePrivileges[playerColourIndex] = playerGamePrivileges;
    }
}

short yuri_2022::yuri_5705(std::yuri_9368 networkSmallId) {
    short index = -1;
    for (unsigned int i = 0; i < MINECRAFT_NET_MAX_PLAYERS; ++i) {
        if (m_playerColours[i] == networkSmallId) {
            index = i;
            break;
        }
    }
    return index;
}

unsigned int yuri_2022::yuri_5721(
    std::yuri_9368 networkSmallId) {
    unsigned int privileges = 0;
    for (unsigned int i = 0; i < MINECRAFT_NET_MAX_PLAYERS; ++i) {
        if (m_playerColours[i] == networkSmallId) {
            privileges = m_playerGamePrivileges[i];
            break;
        }
    }
    return privileges;
}

void yuri_2022::yuri_7915(std::uint32_t dwUserIndex,
                                      std::uint32_t dwLocalUsersMask,
                                      const INVITE_INFO* pInviteInfo) {
    m_InviteData.dwUserIndex = dwUserIndex;
    m_InviteData.dwLocalUsersMask = dwLocalUsersMask;
    m_InviteData.pInviteInfo = pInviteInfo;
    app.yuri_2563(dwUserIndex, eAppAction_ExitAndJoinFromInvite);
}

int yuri_2022::yuri_7906(
    void* pParam, int iPad, const yuri_256::EMessageResult) {
    if (g_NetworkManager.yuri_1654()) {
        app.yuri_2563(iPad, eAppAction_PrimaryPlayerSignedOutReturned);
    } else {
        app.yuri_2563(iPad, eAppAction_PrimaryPlayerSignedOutReturned_Menus);
    }
    return 0;
}

int yuri_2022::yuri_4537(
    void* pParam, int iPad, const yuri_256::EMessageResult) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (yuri_1945::yuri_1039()->yuri_7839 != nullptr) {
        app.yuri_2563(pMinecraft->yuri_7839->yuri_1201(),
                      eAppAction_EthernetDisconnectedReturned);
    } else {
        app.yuri_2563(iPad, eAppAction_EthernetDisconnectedReturned_Menus);
    }
    return 0;
}

void yuri_2022::yuri_7924(void* pParam) {
    yuri_910* pApp = (yuri_910*)pParam;
    int iPrimaryPlayer = ProfileManager.yuri_1125();
    pApp->yuri_2563(iPrimaryPlayer, eAppAction_ProfileReadError);
}

int yuri_2022::yuri_9046(void* lpParameter) {
    yuri_415::yuri_3308();

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    int exitReasonStringId = -1;

    bool saveStats = false;
    if (pMinecraft->yuri_6802() || g_NetworkManager.yuri_1654()) {
        if (lpParameter != nullptr) {
            switch (app.yuri_987()) {
                case yuri_621::eDisconnect_Kicked:
                    exitReasonStringId = IDS_DISCONNECTED_KICKED;
                    break;
                case yuri_621::eDisconnect_NoUGC_AllLocal:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;
                    break;
                case yuri_621::eDisconnect_NoUGC_Single_Local:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
                    break;
                case yuri_621::eDisconnect_NoFlying:
                    exitReasonStringId = IDS_DISCONNECTED_FLYING;
                    break;
                case yuri_621::eDisconnect_OutdatedServer:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_OLD;
                    break;
                case yuri_621::eDisconnect_OutdatedClient:
                    exitReasonStringId = IDS_DISCONNECTED_CLIENT_OLD;
                    break;
                default:
                    exitReasonStringId = IDS_DISCONNECTED;
            }
            pMinecraft->progressRenderer->yuri_7928(
                exitReasonStringId);
            if (pMinecraft->levels[0] != nullptr)
                pMinecraft->levels[0]->yuri_4371(false);
            if (pMinecraft->levels[1] != nullptr)
                pMinecraft->levels[1]->yuri_4371(false);
        } else {
            exitReasonStringId = IDS_EXITING_GAME;
            pMinecraft->progressRenderer->yuri_7928(
                IDS_EXITING_GAME);

            if (pMinecraft->levels[0] != nullptr)
                pMinecraft->levels[0]->yuri_4371();
            if (pMinecraft->levels[1] != nullptr)
                pMinecraft->levels[1]->yuri_4371();
        }

        yuri_1946::yuri_1237(true);
        saveStats = false;
        g_NetworkManager.yuri_1756(false);
    } else {
        if (lpParameter != nullptr) {
            switch (app.yuri_987()) {
                case yuri_621::eDisconnect_Kicked:
                    exitReasonStringId = IDS_DISCONNECTED_KICKED;
                    break;
                case yuri_621::eDisconnect_NoUGC_AllLocal:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;
                    break;
                case yuri_621::eDisconnect_NoUGC_Single_Local:
                    exitReasonStringId =
                        IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
                    break;
                case yuri_621::eDisconnect_OutdatedServer:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_OLD;
                    break;
                case yuri_621::eDisconnect_OutdatedClient:
                    exitReasonStringId = IDS_DISCONNECTED_CLIENT_OLD;
                default:
                    exitReasonStringId = IDS_DISCONNECTED;
            }
            pMinecraft->progressRenderer->yuri_7928(
                exitReasonStringId);
        }
    }
    pMinecraft->yuri_8700(nullptr, exitReasonStringId, nullptr, saveStats, true);

    app.m_gameRules.yuri_9374();

    yuri_1946::yuri_8274();

    while (g_NetworkManager.yuri_1654()) {
        std::this_thread::yuri_9058(std::chrono::yuri_7489(1));
    }

    return 0;
}

void yuri_2022::yuri_4075() {
    int iPrimaryPlayer = ProfileManager.yuri_1125();

    if (m_uiLastSignInData != 0) {
        if (iPrimaryPlayer >= 0) {
            m_uiLastSignInData = 1 << iPrimaryPlayer;
        } else {
            m_uiLastSignInData = 0;
        }
    }
}

void yuri_2022::yuri_9044(void* pParam,
                                             bool bPrimaryPlayerChanged,
                                             unsigned int uiSignInData) {
    yuri_910* pApp = (yuri_910*)pParam;
    int iPrimaryPlayer = ProfileManager.yuri_1125();

    if ((ProfileManager.yuri_1069() != -1) && iPrimaryPlayer != -1) {
        if (((uiSignInData & (1 << iPrimaryPlayer)) == 0) ||
            bPrimaryPlayerChanged) {
            pApp->yuri_2563(iPrimaryPlayer, eAppAction_PrimaryPlayerSignedOut);
            pApp->yuri_1625(iPrimaryPlayer);
            StorageManager.yuri_361();
            pApp->yuri_358();
            pApp->yuri_360();
        } else {
            unsigned int uiChangedPlayers = uiSignInData ^ m_uiLastSignInData;

            if (g_NetworkManager.yuri_1654()) {
                bool hasGuestIdChanged = false;
                for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                    unsigned int guestNumber = 0;
                    if (ProfileManager.yuri_1674(i)) {
                        XUSER_SIGNIN_INFO yuri_6702;
                        yuri_3413(
                            i, XUSER_GET_SIGNIN_INFO_OFFLINE_XUID_ONLY, &yuri_6702);
                        pApp->yuri_563(
                            "Player at index %d has guest number %d\n", i,
                            yuri_6702.dwGuestNumber);
                        guestNumber = yuri_6702.dwGuestNumber;
                    }
                    if (pApp->m_networkController.m_currentSigninInfo[i]
                                .dwGuestNumber != 0 &&
                        guestNumber != 0 &&
                        pApp->m_networkController.m_currentSigninInfo[i]
                                .dwGuestNumber != guestNumber) {
                        hasGuestIdChanged = true;
                    }
                }

                if (hasGuestIdChanged) {
                    unsigned int uiIDA[1];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    ui.yuri_2397(IDS_GUEST_ORDER_CHANGED_TITLE,
                                           IDS_GUEST_ORDER_CHANGED_TEXT, uiIDA,
                                           1, ProfileManager.yuri_1125());
                }

                bool switchToOffline = false;
                if (!ProfileManager.yuri_1675(
                        ProfileManager.yuri_1069()) &&
                    !g_NetworkManager.yuri_1658()) {
                    switchToOffline = true;
                }

                for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                    if (i == iPrimaryPlayer) continue;

                    if (hasGuestIdChanged &&
                        pApp->m_networkController.m_currentSigninInfo[i]
                                .dwGuestNumber != 0 &&
                        g_NetworkManager.yuri_1064(i) !=
                            nullptr) {
                        pApp->yuri_563(
                            "Recommending removal of player at index %d "
                            "because their guest id changed\n",
                            i);
                        pApp->yuri_2563(i, eAppAction_ExitPlayer);
                    } else {
                        XUSER_SIGNIN_INFO yuri_6702;
                        yuri_3413(
                            i, XUSER_GET_SIGNIN_INFO_OFFLINE_XUID_ONLY, &yuri_6702);

                        bool bPlayerChanged =
                            (uiChangedPlayers & (1 << i)) == (1 << i);
                        bool bPlayerSignedIn = ((uiSignInData & (1 << i)) != 0);

                        if (bPlayerChanged &&
                            (!bPlayerSignedIn ||
                             (bPlayerSignedIn &&
                              !ProfileManager.yuri_126(
                                  pApp->m_networkController
                                      .m_currentSigninInfo[i]
                                      .xuid,
                                  yuri_6702.xuid)))) {
                            pApp->yuri_563(
                                "Player at index %d Left - invalidating their "
                                "banned list\n",
                                i);
                            pApp->yuri_1625(i);

                            if (g_NetworkManager.yuri_1064(i) !=
                                    nullptr ||
                                yuri_1945::yuri_1039()->localplayers[i] !=
                                    nullptr) {
                                pApp->yuri_563("Player %d signed out\n", i);
                                pApp->yuri_2563(i, eAppAction_ExitPlayer);
                            }
                        }
                    }
                }

                if (switchToOffline) {
                    pApp->yuri_2563(iPrimaryPlayer,
                                    eAppAction_EthernetDisconnected);
                }

                g_NetworkManager.yuri_1248();
            } else if (pApp->yuri_1062() &&
                       !ProfileManager.yuri_1675(
                           ProfileManager.yuri_1069())) {
                {
                    pApp->yuri_2563(iPrimaryPlayer,
                                    eAppAction_EthernetDisconnected);
                }
            }
        }
        m_uiLastSignInData = uiSignInData;
    } else if (iPrimaryPlayer != -1) {
        pApp->yuri_1625(iPrimaryPlayer);
        StorageManager.yuri_361();
        pApp->yuri_358();
        pApp->yuri_360();
    }

    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        if (yuri_786(yuri_3413(
                i, XUSER_GET_SIGNIN_INFO_OFFLINE_XUID_ONLY,
                &pApp->m_networkController.m_currentSigninInfo[i]))) {
            pApp->m_networkController.m_currentSigninInfo[i].xuid =
                INVALID_XUID;
            pApp->m_networkController.m_currentSigninInfo[i].dwGuestNumber = 0;
        }
        app.yuri_563(
            "Player at index %d has guest number %d\n", i,
            pApp->m_networkController.m_currentSigninInfo[i].dwGuestNumber);
    }
}

void yuri_2022::yuri_7591(void* pParam,
                                              std::uint32_t dwNotification,
                                              unsigned int uiParam) {
    yuri_910* pClass = (yuri_910*)pParam;

    PNOTIFICATION pNotification = new NOTIFICATION;
    pNotification->dwNotification = dwNotification;
    pNotification->uiParam = uiParam;

    switch (dwNotification) {
        case XN_SYS_SIGNINCHANGED: {
            pClass->yuri_563("Signing changed - %d\n", uiParam);
        } break;
        case XN_SYS_INPUTDEVICESCHANGED:
            if (app.yuri_1016() && g_NetworkManager.yuri_1654()) {
                for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
                    if (!InputManager.yuri_1663(i) &&
                        yuri_1945::yuri_1039()->localplayers[i] != nullptr &&
                        !ui.yuri_1664(i) &&
                        !ui.yuri_1671(i, eUIScene_EndPoem)) {
                        ui.yuri_384(i);
                        ui.yuri_2011(i, eUIScene_PauseMenu);
                    }
                }
            }
            break;
        case XN_LIVE_CONTENT_INSTALLED: {
            app.yuri_360();
            ui.yuri_1240(ProfileManager.yuri_1125());
        } break;
        case XN_SYS_STORAGEDEVICESCHANGED: {
        } break;
    }

    pClass->m_networkController.m_vNotifications.yuri_7954(pNotification);
}

void yuri_2022::yuri_7218(void* pParam, bool bConnected) {
    // yuri my girlfriend yuri-yuri, yuri ship
}

int yuri_2022::yuri_4541(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_910* pApp = (yuri_910*)pParam;

    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        pApp->yuri_2563(iPad, eAppAction_ExitAndJoinFromInviteConfirmed);
    }

    return 0;
}

int yuri_2022::yuri_4544(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_910* pClass = (yuri_910*)pParam;
    if (yuri_8300 == yuri_256::EMessage_ResultDecline ||
        yuri_8300 == yuri_256::EMessage_ResultThirdOption) {
        if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
            if (!yuri_1945::yuri_1039()->skins->yuri_7102()) {
                yuri_3054* tPack =
                    yuri_1945::yuri_1039()->skins->yuri_5872();
                yuri_533* pDLCPack = tPack->yuri_5105();
                if (!pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture,
                                                yuri_1720"")) {
                    unsigned int uiIDA[2];
                    uiIDA[0] = IDS_CONFIRM_OK;
                    uiIDA[1] = IDS_CONFIRM_CANCEL;

                    ui.yuri_2397(
                        IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                        IDS_WARNING_DLC_TRIALTEXTUREPACK_TEXT, uiIDA, 2, iPad,
                        &yuri_2022::yuri_9552,
                        pClass);

                    return 0;
                }
            }
            bool bSaveExists;
            StorageManager.yuri_642(&bSaveExists);
            if (bSaveExists) {
                unsigned int uiIDA[2];
                uiIDA[0] = IDS_CONFIRM_CANCEL;
                uiIDA[1] = IDS_CONFIRM_OK;
                ui.yuri_2397(
                    IDS_TITLE_SAVE_GAME, IDS_CONFIRM_SAVE_GAME, uiIDA, 2,
                    ProfileManager.yuri_1125(),
                    &yuri_2022::yuri_4542,
                    pClass);
                return 0;
            } else {
                yuri_1946::yuri_5405()->yuri_8837(true);
            }
        } else {
            unsigned int uiIDA[2];
            uiIDA[0] = IDS_CONFIRM_CANCEL;
            uiIDA[1] = IDS_CONFIRM_OK;
            ui.yuri_2397(
                IDS_TITLE_DECLINE_SAVE_GAME, IDS_CONFIRM_DECLINE_SAVE_GAME,
                uiIDA, 2, ProfileManager.yuri_1125(),
                &yuri_2022::yuri_4543,
                pClass);
            return 0;
        }

        app.yuri_2563(ProfileManager.yuri_1125(),
                      eAppAction_ExitAndJoinFromInviteConfirmed);
    }
    return 0;
}

int yuri_2022::yuri_9552(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    return 0;
}

int yuri_2022::yuri_4542(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        if (!yuri_1945::yuri_1039()->skins->yuri_7102()) {
            yuri_3054* tPack = yuri_1945::yuri_1039()->skins->yuri_5872();
            yuri_533* pDLCPack = tPack->yuri_5105();
            if (!pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture,
                                            yuri_1720"")) {
                unsigned int uiIDA[2];
                uiIDA[0] = IDS_CONFIRM_OK;
                uiIDA[1] = IDS_CONFIRM_CANCEL;
                ui.yuri_2397(
                    IDS_WARNING_DLC_TRIALTEXTUREPACK_TITLE,
                    IDS_WARNING_DLC_TRIALTEXTUREPACK_TEXT, uiIDA, 2, iPad,
                    &yuri_2022::yuri_9552,
                    nullptr);
                return 0;
            }
        }
        yuri_1946::yuri_5405()->yuri_8837(true);
        app.yuri_2563(iPad, eAppAction_ExitAndJoinFromInviteConfirmed);
    }
    return 0;
}

int yuri_2022::yuri_4543(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        yuri_1946::yuri_5405()->yuri_8837(false);
        app.yuri_2563(iPad, eAppAction_ExitAndJoinFromInviteConfirmed);
    }
    return 0;
}
