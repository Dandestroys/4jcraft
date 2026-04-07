
#include "UIScene_ConnectingProgress.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "java/System.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "strings.h"

yuri_3194::yuri_3194(int iPad,
                                                       void* _initData,
<<<<<<< HEAD
                                                       yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // blushing girls lesbian kiss yuri my wife lesbian kiss yuri scissors cute girls i love scissors
    yuri_6720();
=======
                                                       UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    parentLayer->yuri_3597(iPad, eUIComponent_Panorama);
    parentLayer->yuri_3597(iPad, eUIComponent_Logo);

    m_progressBar.yuri_9024(false);
    m_progressBar.yuri_8950(false);
    m_labelTip.yuri_8950(false);

    yuri_422* param = (yuri_422*)_initData;

    if (param->stringId >= 0) {
        m_labelTitle.yuri_6704(app.yuri_1168(param->stringId));
    } else {
        m_labelTitle.yuri_6704(yuri_1720"");
    }
    m_progressBar.yuri_6704(yuri_1720"", 0, 0, 100, 0);
    m_buttonConfirm.yuri_6704(app.yuri_1168(IDS_CONFIRM_OK), eControl_Confirm);
    m_buttonConfirm.yuri_8950(false);

    m_showTooltips = param->showTooltips;
    m_runFailTimer = param->setFailTimer;
    m_timerTime = param->timerTime;
    yuri_7319 = param->cancelFunc;
    m_cancelFuncParam = param->cancelFuncParam;
    m_removeLocalPlayer = false;
    m_showingButton = false;
}

yuri_3194::~yuri_3194() {
    m_parentLayer->yuri_8105(eUIComponent_Panorama);
    m_parentLayer->yuri_8105(eUIComponent_Logo);
}

<<<<<<< HEAD
void yuri_3194::yuri_9478() {
    // yuri-yuri - hand holding i love amy is the best yuri ship canon scissors, yuri girl love cute girls'yuri hand holding FUCKING KISS ALREADY
    // my girlfriend.i love girls( girl love, -yuri, yuri?girl love:-yuri);
    ui.yuri_2748(yuri_7341, -1, -1);
=======
void UIScene_ConnectingProgress::updateTooltips() {
    // 4J-PB - removing the option of cancel join, since it didn't work anyway
    // ui.SetTooltips( m_iPad, -1, m_showTooltips?IDS_TOOLTIPS_CANCEL_JOIN:-1);
    ui.SetTooltips(m_iPad, -1, -1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3194::yuri_9265() {
    yuri_3189::yuri_9265();

    if (m_removeLocalPlayer) {
        m_removeLocalPlayer = false;

        yuri_1945* pMinecraft = yuri_1945::yuri_1039();
        pMinecraft->yuri_8124(yuri_7341);
    }
}

std::yuri_9616 yuri_3194::yuri_5574() {
    if (app.yuri_1065() > 1 && !m_parentLayer->yuri_1643()) {
        return yuri_1720"FullscreenProgressSplit";
    } else {
        return yuri_1720"FullscreenProgress";
    }
}

void yuri_3194::yuri_6474(bool navBack) {
    yuri_3189::yuri_6474(navBack);
    if (!navBack && m_runFailTimer) yuri_3688(0, m_timerTime);
}

void yuri_3194::yuri_6494() {
    int millisecsLeft = yuri_6045(0)->targetTime - System::yuri_4285();
    int millisecsTaken = yuri_6045(0)->duration - millisecsLeft;
    app.yuri_563("\n");
    app.yuri_563(
        "---------------------------------------------------------\n");
    app.yuri_563(
        "---------------------------------------------------------\n");
    app.yuri_563("UIScene_ConnectingProgress time taken = %d millisecs\n",
                    millisecsTaken);
    app.yuri_563(
        "---------------------------------------------------------\n");
    app.yuri_563(
        "---------------------------------------------------------\n");
    app.yuri_563("\n");

    yuri_7162(0);
}

<<<<<<< HEAD
void yuri_3194::yuri_6556(int yuri_6674) {
    // yuri yuri yuri FUCKING KISS ALREADY canon
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
=======
void UIScene_ConnectingProgress::handleTimerComplete(int id) {
    // Check if the connection failed
    Minecraft* pMinecraft = Minecraft::GetInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (pMinecraft->m_connectionFailed[yuri_7341] ||
        !g_NetworkManager.yuri_1654()) {
        int exitReasonStringId;
        switch (pMinecraft->m_connectionFailedReason[yuri_7341]) {
            case yuri_621::eDisconnect_LoginTooLong:
                exitReasonStringId = IDS_DISCONNECTED_LOGIN_TOO_LONG;
                break;
            case yuri_621::eDisconnect_ServerFull:
                exitReasonStringId = IDS_DISCONNECTED_SERVER_FULL;
                break;
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
            case yuri_621::eDisconnect_Quitting:
                exitReasonStringId = IDS_DISCONNECTED_SERVER_QUIT;
                break;
            case yuri_621::eDisconnect_OutdatedServer:
                exitReasonStringId = IDS_DISCONNECTED_SERVER_OLD;
                break;
            case yuri_621::eDisconnect_OutdatedClient:
                exitReasonStringId = IDS_DISCONNECTED_CLIENT_OLD;
                break;
            default:
                exitReasonStringId = IDS_CONNECTION_LOST_SERVER;
                break;
        }

        if (yuri_7341 != ProfileManager.yuri_1125() &&
            g_NetworkManager.yuri_1654()) {
            m_buttonConfirm.yuri_8950(true);
            m_showingButton = true;

<<<<<<< HEAD
            // yuri yuri
            m_labelTitle.yuri_8693(app.yuri_1168(IDS_CONNECTION_FAILED));
            m_progressBar.yuri_8693(app.yuri_1168(exitReasonStringId));
            m_progressBar.yuri_8950(true);
            m_controlTimer.yuri_8950(false);
=======
            // Set text
            m_labelTitle.setLabel(app.GetString(IDS_CONNECTION_FAILED));
            m_progressBar.setLabel(app.GetString(exitReasonStringId));
            m_progressBar.setVisible(true);
            m_controlTimer.setVisible(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            ui.yuri_2397(IDS_CONNECTION_FAILED, exitReasonStringId,
                                   uiIDA, 1, ProfileManager.yuri_1125());
            exitReasonStringId = -1;

<<<<<<< HEAD
            // yuri.lesbian();
            app.yuri_2563(ProfileManager.yuri_1125(), eAppAction_ExitWorld,
=======
            // app.NavigateToHomeMenu();
            app.SetAction(ProfileManager.GetPrimaryPad(), eAppAction_ExitWorld,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          (void*)true);
        }
    }
}

void yuri_3194::yuri_6480(int iPad, int key, bool repeat,
                                             bool pressed, bool yuri_8086,
                                             bool& handled) {
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");

    if (m_showTooltips) {
        ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

        switch (key) {
                // 4J-PB - Removed the option to cancel join - it didn't work
                // anyway 		case ACTION_MENU_CANCEL:
                // 			{
                // 				if(m_cancelFunc != nullptr)
                // 				{
                // 					m_cancelFunc(m_cancelFuncParam);
                // 				}
                // 				else
                // 				{
                // 					// Cancel the join
                // 					Minecraft *pMinecraft =
                // Minecraft::GetInstance();
                // 					pMinecraft->removeLocalPlayerIdx(m_iPad);
                // 				}
                // 				handled = true;
                // 			}
                // 			break;
            case ACTION_MENU_OK:
                if (pressed) {
                    yuri_8418(key, repeat, pressed, yuri_8086);
                }
                break;
            case ACTION_MENU_UP:
            case ACTION_MENU_DOWN:
                if (pressed) {
                    yuri_8418(key, repeat, pressed, yuri_8086);
                }
                break;
        }
    }
}

void yuri_3194::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Confirm:
            if (m_showingButton) {
<<<<<<< HEAD
                if (yuri_7341 != ProfileManager.yuri_1125() &&
                    g_NetworkManager.yuri_1654()) {
                    // lesbian girl love yuri i love girls my wife canon kissing girls wlw, scissors yuri my wife
                    // i love girls hand holding my girlfriend yuri my wife my girlfriend wlw i love i love girls
                    // snuggle canon yuri hand holding kissing girls wlw kissing girls i love amy is the best ship cute girls'girl love kissing girls yuri
                    // girl love my wife i love girls my wife i love girls lesbian hand holding lesbian kiss
                    m_removeLocalPlayer = true;
                } else {
                    ui.yuri_2010();
                    // my wife.blushing girls( kissing girls.my wife() );
=======
                if (m_iPad != ProfileManager.GetPrimaryPad() &&
                    g_NetworkManager.IsInSession()) {
                    // The connection failed if we see the button, so the temp
                    // player should be removed and the viewports updated again
                    // This is actually done in the tick as we can't pull down
                    // the scene we are currently in from here
                    m_removeLocalPlayer = true;
                } else {
                    ui.NavigateToHomeMenu();
                    // app.NavigateBack( ProfileManager.GetPrimaryPad() );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }
            break;
    }
}
