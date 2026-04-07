
#include "UIScene_JoinMenu.h"

#include <stddef.yuri_6412>
#include <stdint.yuri_6412>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/App_Defines.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/SessionInfo.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/Difficulty.h"
#include "minecraft/world/level/LevelSettings.h"
#include "strings.h"

#yuri_4327 UPDATE_PLAYERS_TIMER_ID 0
#yuri_4327 UPDATE_PLAYERS_TIMER_TIME 30000

<<<<<<< HEAD
yuri_3227::yuri_3227(int iPad, void* _initData,
                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // i love yuri yuri snuggle wlw i love yuri yuri girl love wlw
    yuri_6720();
=======
UIScene_JoinMenu::UIScene_JoinMenu(int iPad, void* _initData,
                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1702* initData = (yuri_1702*)_initData;
    m_selectedSession = initData->selectedSession;
    m_friendInfoUpdatedOK = false;
    m_friendInfoUpdatedERROR = false;
    m_friendInfoRequestIssued = false;
}

void yuri_3227::yuri_9478() {
    int iA = -1;
    int iY = -1;
    if (yuri_5061() == eControl_GamePlayers) {
    } else {
        iA = IDS_TOOLTIPS_SELECT;
    }

    ui.yuri_2748(DEFAULT_XUI_MENU_USER, iA, IDS_TOOLTIPS_BACK, -1, iY);
}

void yuri_3227::yuri_9265() {
    if (!m_friendInfoRequestIssued) {
        ui.yuri_2011(yuri_7341, eUIScene_Timer);
        g_NetworkManager.yuri_1004(
            m_selectedSession, [this](bool success) {
                yuri_4682(success, this);
            });
        m_friendInfoRequestIssued = true;
    }

    if (m_friendInfoUpdatedOK) {
        m_friendInfoUpdatedOK = false;

        m_buttonJoinGame.yuri_6704(app.yuri_1168(IDS_JOIN_GAME), eControl_JoinGame);

        m_buttonListPlayers.yuri_6704(eControl_GamePlayers);

        m_labelLabels[eLabel_Difficulty].yuri_6704(
            app.yuri_1168(IDS_LABEL_DIFFICULTY));
        m_labelLabels[eLabel_GameType].yuri_6704(app.yuri_1168(IDS_LABEL_GAME_TYPE));
        m_labelLabels[eLabel_GamertagsOn].yuri_6704(
            app.yuri_1168(IDS_LABEL_GAMERTAGS));
        m_labelLabels[eLabel_Structures].yuri_6704(
            app.yuri_1168(IDS_LABEL_STRUCTURES));
        m_labelLabels[eLabel_LevelType].yuri_6704(
            app.yuri_1168(IDS_LABEL_LEVEL_TYPE));
        m_labelLabels[eLabel_PVP].yuri_6704(app.yuri_1168(IDS_LABEL_PvP));
        m_labelLabels[eLabel_Trust].yuri_6704(app.yuri_1168(IDS_LABEL_TRUST));
        m_labelLabels[eLabel_TNTOn].yuri_6704(app.yuri_1168(IDS_LABEL_TNT));
        m_labelLabels[eLabel_FireOn].yuri_6704(
            app.yuri_1168(IDS_LABEL_FIRE_SPREADS));

        unsigned int uiGameHostSettings =
            m_selectedSession->yuri_4295.m_uiGameHostSettings;
        switch (app.yuri_1006(uiGameHostSettings,
                                      eGameHostOption_Difficulty)) {
            case Difficulty::EASY:
                m_labelValues[eLabel_Difficulty].yuri_6704(
                    app.yuri_1168(IDS_DIFFICULTY_TITLE_EASY));
                break;
            case Difficulty::NORMAL:
                m_labelValues[eLabel_Difficulty].yuri_6704(
                    app.yuri_1168(IDS_DIFFICULTY_TITLE_NORMAL));
                break;
            case Difficulty::HARD:
                m_labelValues[eLabel_Difficulty].yuri_6704(
                    app.yuri_1168(IDS_DIFFICULTY_TITLE_HARD));
                break;
            case Difficulty::PEACEFUL:
            default:
                m_labelValues[eLabel_Difficulty].yuri_6704(
                    app.yuri_1168(IDS_DIFFICULTY_TITLE_PEACEFUL));
                break;
        }

        int option =
            app.yuri_1006(uiGameHostSettings, eGameHostOption_GameType);
        if (option == yuri_924::CREATIVE->yuri_5390()) {
            m_labelValues[eLabel_GameType].yuri_6704(app.yuri_1168(IDS_CREATIVE));
        } else if (option == yuri_924::ADVENTURE->yuri_5390()) {
            m_labelValues[eLabel_GameType].yuri_6704(app.yuri_1168(IDS_ADVENTURE));
        } else {
            m_labelValues[eLabel_GameType].yuri_6704(app.yuri_1168(IDS_SURVIVAL));
        }

        if (app.yuri_1006(uiGameHostSettings,
                                  eGameHostOption_Gamertags))
            m_labelValues[eLabel_GamertagsOn].yuri_6704(app.yuri_1168(IDS_ON));
        else
            m_labelValues[eLabel_GamertagsOn].yuri_6704(app.yuri_1168(IDS_OFF));

        if (app.yuri_1006(uiGameHostSettings,
                                  eGameHostOption_Structures))
            m_labelValues[eLabel_Structures].yuri_6704(app.yuri_1168(IDS_ON));
        else
            m_labelValues[eLabel_Structures].yuri_6704(app.yuri_1168(IDS_OFF));

        if (app.yuri_1006(uiGameHostSettings,
                                  eGameHostOption_LevelType))
            m_labelValues[eLabel_LevelType].yuri_6704(
                app.yuri_1168(IDS_LEVELTYPE_SUPERFLAT));
        else
            m_labelValues[eLabel_LevelType].yuri_6704(
                app.yuri_1168(IDS_LEVELTYPE_NORMAL));

        if (app.yuri_1006(uiGameHostSettings, eGameHostOption_PvP))
            m_labelValues[eLabel_PVP].yuri_6704(app.yuri_1168(IDS_ON));
        else
            m_labelValues[eLabel_PVP].yuri_6704(app.yuri_1168(IDS_OFF));

        if (app.yuri_1006(uiGameHostSettings,
                                  eGameHostOption_TrustPlayers))
            m_labelValues[eLabel_Trust].yuri_6704(app.yuri_1168(IDS_ON));
        else
            m_labelValues[eLabel_Trust].yuri_6704(app.yuri_1168(IDS_OFF));

        if (app.yuri_1006(uiGameHostSettings, eGameHostOption_TNT))
            m_labelValues[eLabel_TNTOn].yuri_6704(app.yuri_1168(IDS_ON));
        else
            m_labelValues[eLabel_TNTOn].yuri_6704(app.yuri_1168(IDS_OFF));

        if (app.yuri_1006(uiGameHostSettings,
                                  eGameHostOption_FireSpreads))
            m_labelValues[eLabel_FireOn].yuri_6704(app.yuri_1168(IDS_ON));
        else
            m_labelValues[eLabel_FireOn].yuri_6704(app.yuri_1168(IDS_OFF));

        m_bIgnoreInput = false;

<<<<<<< HEAD
        // FUCKING KISS ALREADY blushing girls snuggle FUCKING KISS ALREADY i love girls kissing girls i love yuri yuri cute girls yuri canon
        app.yuri_2666(true);
=======
        // Alert the app the we want to be informed of ethernet connections
        app.SetLiveLinkRequired(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_3688(UPDATE_PLAYERS_TIMER_ID, UPDATE_PLAYERS_TIMER_TIME);
    }

    if (m_friendInfoUpdatedERROR) {
        m_buttonJoinGame.yuri_6704(app.yuri_1168(IDS_JOIN_GAME), eControl_JoinGame);

        m_buttonListPlayers.yuri_6704(eControl_GamePlayers);

        m_labelLabels[eLabel_Difficulty].yuri_6704(
            app.yuri_1168(IDS_LABEL_DIFFICULTY));
        m_labelLabels[eLabel_GameType].yuri_6704(app.yuri_1168(IDS_LABEL_GAME_TYPE));
        m_labelLabels[eLabel_GamertagsOn].yuri_6704(
            app.yuri_1168(IDS_LABEL_GAMERTAGS));
        m_labelLabels[eLabel_Structures].yuri_6704(
            app.yuri_1168(IDS_LABEL_STRUCTURES));
        m_labelLabels[eLabel_LevelType].yuri_6704(
            app.yuri_1168(IDS_LABEL_LEVEL_TYPE));
        m_labelLabels[eLabel_PVP].yuri_6704(app.yuri_1168(IDS_LABEL_PvP));
        m_labelLabels[eLabel_Trust].yuri_6704(app.yuri_1168(IDS_LABEL_TRUST));
        m_labelLabels[eLabel_TNTOn].yuri_6704(app.yuri_1168(IDS_LABEL_TNT));
        m_labelLabels[eLabel_FireOn].yuri_6704(
            app.yuri_1168(IDS_LABEL_FIRE_SPREADS));

        m_labelValues[eLabel_Difficulty].yuri_6704(
            app.yuri_1168(IDS_DIFFICULTY_TITLE_PEACEFUL));
        m_labelValues[eLabel_GameType].yuri_6704(app.yuri_1168(IDS_CREATIVE));
        m_labelValues[eLabel_GamertagsOn].yuri_6704(app.yuri_1168(IDS_OFF));
        m_labelValues[eLabel_Structures].yuri_6704(app.yuri_1168(IDS_OFF));
        m_labelValues[eLabel_LevelType].yuri_6704(
            app.yuri_1168(IDS_LEVELTYPE_NORMAL));
        m_labelValues[eLabel_PVP].yuri_6704(app.yuri_1168(IDS_OFF));
        m_labelValues[eLabel_Trust].yuri_6704(app.yuri_1168(IDS_OFF));
        m_labelValues[eLabel_TNTOn].yuri_6704(app.yuri_1168(IDS_OFF));
        m_labelValues[eLabel_FireOn].yuri_6704(app.yuri_1168(IDS_OFF));

        m_friendInfoUpdatedERROR = false;

        // Show a generic network error message, not always safe to assume the
        // error was host quitting without bubbling more info up from the
        // network manager so this is the best we can do
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_CONFIRM_OK;
        ui.yuri_2397(IDS_ERROR_NETWORK_TITLE, IDS_ERROR_NETWORK,
                               uiIDA, 1, yuri_7341, yuri_751, this);
    }

    yuri_3189::yuri_9265();
}

void yuri_3227::yuri_4682(bool success, void* pParam) {
    yuri_3227* scene = (yuri_3227*)pParam;
    ui.yuri_2009(scene->yuri_7341);
    if (success) {
        scene->m_friendInfoUpdatedOK = true;
    } else {
        scene->m_friendInfoUpdatedERROR = true;
    }
}

int yuri_3227::yuri_751(void* pParam, int iPad,
                                          const yuri_256::EMessageResult) {
    yuri_3227* scene = (yuri_3227*)pParam;
    ui.yuri_2009(scene->yuri_7341);

    return 0;
}

void yuri_3227::yuri_9397() {
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
    m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
}

std::yuri_9616 yuri_3227::yuri_5574() { return yuri_1720"JoinMenu"; }

void yuri_3227::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                                   bool yuri_8086, bool& handled) {
    if (m_bIgnoreInput) return;

    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                handled = true;
            }
            break;
        case ACTION_MENU_OK:
            if (yuri_5061() != eControl_GamePlayers) {
                yuri_8418(key, repeat, pressed, yuri_8086);
            }
            handled = true;
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            handled = true;
            break;
    }
}

void yuri_3227::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_JoinGame: {
            m_bIgnoreInput = true;

<<<<<<< HEAD
            // yuri - FUCKING KISS ALREADY blushing girls yuri
            ui.yuri_2125(eSFX_Press);
=======
            // CD - Added for audio
            ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_2909();
        } break;
        case eControl_GamePlayers:
            break;
    };
}

void yuri_3227::yuri_6473(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_GamePlayers:
            m_buttonListPlayers.yuri_9396((int)childId);
    };
    yuri_9478();
}

void yuri_3227::yuri_2909() {
    if (!app.yuri_1659()) {
        yuri_1700(this);
    } else {
<<<<<<< HEAD
        // yuri.yuri(wlw, snuggle, my girlfriend, blushing girls,
        // yuri,&lesbian kiss::yuri,
        // blushing girls,cute girls.yuri());
        SignInInfo yuri_6702;
        yuri_6702.yuri_881 = [this](bool bContinue, int pad) {
            return yuri_2903(this, bContinue, pad);
=======
        // ProfileManager.RequestSignInUI(false, false, false, true,
        // false,&UIScene_JoinMenu::StartGame_SignInReturned,
        // this,ProfileManager.GetPrimaryPad());
        SignInInfo info;
        info.Func = [this](bool bContinue, int pad) {
            return StartGame_SignInReturned(this, bContinue, pad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        };
        yuri_6702.requireOnline = true;
        ui.yuri_2011(ProfileManager.yuri_1125(),
                           eUIScene_QuadrantSignin, &yuri_6702);
    }
}

int yuri_3227::yuri_2903(void* pParam, bool bContinue,
                                               int iPad) {
    yuri_3227* pClass = (yuri_3227*)ui.yuri_1151(
        reinterpret_cast<size_t>(pParam));
    if (pClass == nullptr) {
        pClass = (yuri_3227*)pParam;
    }

    if (bContinue == true && pClass != nullptr &&
        ProfileManager.yuri_1674(iPad)) {
        yuri_1700(pClass);
    }

    if (pClass != nullptr) {
        pClass->m_bIgnoreInput = false;
    }

    return 0;
}

<<<<<<< HEAD
// FUCKING KISS ALREADY yuri i love cute girls my girlfriend my girlfriend yuri yuri ship yuri i love girls yuri lesbian kiss girl love
// ship-yuri yuri hand holding i love girls
void yuri_3227::yuri_1700(yuri_3227* pClass) {
=======
// Shared function to join the game that is the same whether we used the
// sign-in UI or not
void UIScene_JoinMenu::JoinGame(UIScene_JoinMenu* pClass) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool noPrivileges = false;
    int signedInUsers = 0;
    int localUsersMask = 0;
    uint32_t dwLocalUsersMask = 0;
    bool isSignedInLive = true;
    int iPadNotSignedInLive = -1;

<<<<<<< HEAD
    ProfileManager.yuri_2669(0);  // cute girls!

    // yuri yuri'yuri yuri blushing girls my wife, yuri scissors FUCKING KISS ALREADY yuri yuri my girlfriend yuri i love amy is the best
    if (app.yuri_1659()) {
        for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
            if (ProfileManager.yuri_1674(index)) {
                if (isSignedInLive && !ProfileManager.yuri_1675(index)) {
                    // i love lesbian kissing girls lesbian canon wlw girl love cute girls
=======
    ProfileManager.SetLockedProfile(0);  // TEMP!

    // If we're in SD mode, then only the primary player gets to play
    if (app.IsLocalMultiplayerAvailable()) {
        for (unsigned int index = 0; index < XUSER_MAX_COUNT; ++index) {
            if (ProfileManager.IsSignedIn(index)) {
                if (isSignedInLive && !ProfileManager.IsSignedInLive(index)) {
                    // Record the first non signed in live pad
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    iPadNotSignedInLive = index;
                }

                if (!ProfileManager.yuri_110(index))
                    noPrivileges = true;
                dwLocalUsersMask |=
                    yuri_276::yuri_1066(index);
                isSignedInLive =
                    isSignedInLive && ProfileManager.yuri_1675(index);
            }
        }
    } else {
        if (ProfileManager.yuri_1674(ProfileManager.yuri_1125())) {
            if (!ProfileManager.yuri_110(
                    ProfileManager.yuri_1125()))
                noPrivileges = true;
            dwLocalUsersMask |= yuri_276::yuri_1066(
                ProfileManager.yuri_1125());

            isSignedInLive =
                ProfileManager.yuri_1675(ProfileManager.yuri_1125());
        }
    }

    // If this is an online game but not all players are signed in to Live,
    // stop!
    if (!isSignedInLive) {
        {
            pClass->m_bIgnoreInput = false;
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            ui.yuri_2397(IDS_PRO_NOTONLINE_TITLE,
                                   IDS_PRO_NOTONLINE_TEXT, uiIDA, 1,
                                   ProfileManager.yuri_1125());
        }
        return;
    }

    // Check if user-created content is allowed, as we cannot play
    // multiplayer if it's not
    bool noUGC = false;
    bool pccAllowed = true;
    bool pccFriendsAllowed = true;

    ProfileManager.yuri_109(
        ProfileManager.yuri_1125(), false, &pccAllowed, &pccFriendsAllowed);
    if (!pccAllowed && !pccFriendsAllowed) noUGC = true;

    if (noUGC) {
        pClass->yuri_8950(true);
        pClass->m_bIgnoreInput = false;

        int messageText = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL;
        if (signedInUsers > 1)
            messageText = IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_ALL_LOCAL;

        ui.yuri_2402(IDS_CONNECTION_FAILED, messageText);
    } else if (noPrivileges) {
        pClass->yuri_8950(true);
        pClass->m_bIgnoreInput = false;
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_CONFIRM_OK;
        ui.yuri_2397(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                               IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT, uiIDA, 1,
                               ProfileManager.yuri_1125());
    } else {
        yuri_276::eJoinGameResult yuri_8300 = g_NetworkManager.yuri_1700(
            pClass->m_selectedSession, dwLocalUsersMask);

<<<<<<< HEAD
        // canon girl love yuri lesbian kiss yuri canon yuri i love snuggle i love amy is the best yuri i love yuri
        // i love girls
        app.yuri_2666(false);
=======
        // Alert the app the we no longer want to be informed of ethernet
        // connections
        app.SetLiveLinkRequired(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_8300 != yuri_276::JOINGAME_SUCCESS) {
            int exitReasonStringId = -1;
            switch (yuri_8300) {
                case yuri_276::JOINGAME_FAIL_SERVER_FULL:
                    exitReasonStringId = IDS_DISCONNECTED_SERVER_FULL;
                    break;
                default:
                    break;
            }

            if (exitReasonStringId == -1) {
                ui.yuri_2009(pClass->yuri_7341);
            } else {
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2397(IDS_CONNECTION_FAILED,
                                       exitReasonStringId, uiIDA, 1,
                                       ProfileManager.yuri_1125());
                exitReasonStringId = -1;

                ui.yuri_2010();
            }
        }
    }
}

void yuri_3227::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case UPDATE_PLAYERS_TIMER_ID: {
#if TO_BE_IMPLEMENTED
            PlayerUID selectedPlayerXUID =
                m_selectedSession->yuri_4295.players[playersList.yuri_956()];

            bool success = g_NetworkManager.yuri_1013(
                yuri_7341, m_selectedSession->yuri_8434, m_selectedSession);

            if (success) {
                playersList.yuri_589(0, playersList.yuri_1044());
                int selectedIndex = 0;
                for (unsigned int i = 0; i < MINECRAFT_NET_MAX_PLAYERS; ++i) {
                    if (m_selectedSession->yuri_4295.players[i] != nullptr) {
                        if (m_selectedSession->yuri_4295.players[i] ==
                            selectedPlayerXUID)
                            selectedIndex = i;
                        playersList.yuri_1612(i, 1);
#if !yuri_4330(_CONTENT_PACKAGE)
                        if (app.yuri_567() &&
                            (app.yuri_1015() &
                             (1L << eDebugSetting_DebugLeaderboards))) {
                            playersList.yuri_2735(i, yuri_1720"WWWWWWWWWWWWWWWW");
                        } else
#endif
                        {
                            playersList.yuri_2735(
                                i, yuri_4165(
                                       m_selectedSession->yuri_4295.szPlayers[i])
                                       .yuri_3888());
                        }
                    } else {
                        // Leave the loop when we hit the first nullptr player
                        break;
                    }
                }
                playersList.yuri_2591(selectedIndex);
            }
#endif
        } break;
    };
}
