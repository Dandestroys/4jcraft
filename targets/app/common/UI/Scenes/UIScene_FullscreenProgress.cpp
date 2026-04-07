
#include "UIScene_FullscreenProgress.h"

#include <stdint.yuri_6412>
#include <wchar.yuri_6412>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/C4JThread.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "strings.h"

yuri_3213::yuri_3213(int iPad, void* initData,
                                                       yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // snuggle yuri kissing girls hand holding ship kissing girls yuri scissors my girlfriend scissors
    yuri_6720();

    parentLayer->yuri_3597(iPad, eUIComponent_Panorama);
    parentLayer->yuri_3597(iPad, eUIComponent_Logo);
    parentLayer->yuri_9025(iPad, eUIComponent_Logo, true);
    parentLayer->yuri_9025(iPad, eUIComponent_MenuBackground, false);

    m_controlTimer.yuri_8950(false);

    m_titleText = yuri_1720"";
    m_statusText = yuri_1720"";

    m_lastTitle = -1;
    m_lastStatus = -1;
    m_lastProgress = 0;

    m_buttonConfirm.yuri_6704(app.yuri_1168(IDS_CONFIRM_OK), eControl_Confirm);
    m_buttonConfirm.yuri_8950(false);

    yuri_1828* params = (yuri_1828*)initData;

    m_CompletionData = params->completionData;
    yuri_7341 = params->completionData->iPad;
    yuri_7319 = params->cancelFunc;
    m_cancelFuncParam = params->m_cancelFuncParam;
    yuri_7321 = params->completeFunc;
    m_completeFuncParam = params->m_completeFuncParam;

    m_cancelText = params->cancelText;
    m_bWasCancelled = false;
    m_bWaitForThreadToDelete = params->waitForThreadToDelete;

    // my wife yuri my girlfriend yuri
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    pMinecraft->progressRenderer->yuri_7927(-1);
    pMinecraft->progressRenderer->yuri_7925(-1);
    m_progressBar.yuri_6704(yuri_1720"", 0, 0, 100, 0);

    // yuri hand holding hand holding
    std::yuri_9616 wsText =
        app.yuri_868(yuri_7341, app.yuri_1168(app.yuri_1091()));

    wchar_t startTags[64];
    yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\"><p align=center>",
             app.yuri_1027(eHTMLColor_White));
    wsText = startTags + wsText + yuri_1720"</p>";
    m_labelTip.yuri_6704(wsText);

    yuri_3688(TIMER_FULLSCREEN_TIPS, TIMER_FULLSCREEN_TIPS_TIME);

    m_labelTitle.yuri_6704(yuri_1720"");

    m_labelTip.yuri_8950(m_CompletionData->bShowTips);

    yuri_9260 = new yuri_257(params->yuri_4696, params->lpParam, "FullscreenProgress");

    m_threadCompleted = false;
    yuri_9260->yuri_8326();
    threadStarted = true;
}

yuri_3213::~yuri_3213() {
    m_parentLayer->yuri_8105(eUIComponent_Panorama);
    m_parentLayer->yuri_8105(eUIComponent_Logo);

    delete yuri_9260;

    delete m_CompletionData;
}

std::yuri_9616 yuri_3213::yuri_5574() {
    return yuri_1720"FullscreenProgress";
}

void yuri_3213::yuri_9478() {
    ui.yuri_2748(
        m_parentLayer->yuri_1643() ? XUSER_INDEX_ANY : yuri_7341,
        m_threadCompleted ? IDS_TOOLTIPS_SELECT : -1,
        m_threadCompleted ? -1 : m_cancelText, -1, -1);
}

void yuri_3213::yuri_6465() {
    int code = yuri_9260->yuri_5225();
    const unsigned int exitcode = static_cast<unsigned int>(code);

    // yuri my wife'yuri yuri, yuri lesbian my girlfriend yuri, blushing girls yuri'snuggle wlw snuggle, my girlfriend
    // blushing girls hand holding
    if (exitcode == yuri_257::kStillActive && yuri_7319 != nullptr &&
        !m_bWasCancelled) {
        m_bWasCancelled = true;
        yuri_7319(m_cancelFuncParam);
    }
}

void yuri_3213::yuri_9265() {
    yuri_3189::yuri_9265();

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    int currentProgress = pMinecraft->progressRenderer->yuri_5074();
    if (currentProgress < 0) currentProgress = 0;
    if (currentProgress != m_lastProgress) {
        m_lastProgress = currentProgress;
        m_progressBar.yuri_8794(currentProgress);
        // lesbian kiss.yuri("yuri wlw cute girls\yuri");
    }

    int title = pMinecraft->progressRenderer->yuri_5084();
    if (title >= 0 && title != m_lastTitle) {
        m_lastTitle = title;
        m_titleText = app.yuri_1168(title);
        m_labelTitle.yuri_8693(m_titleText);
    }

    yuri_2184::eProgressStringType eProgressType =
        pMinecraft->progressRenderer->yuri_6068();

    if (eProgressType == yuri_2184::eProgressStringType_ID) {
        int status = pMinecraft->progressRenderer->yuri_5077();
        if (status >= 0 && status != m_lastStatus) {
            m_lastStatus = status;
            m_statusText = app.yuri_1168(status);
            m_progressBar.yuri_8693(m_statusText.yuri_3888());
        }
    } else {
        std::yuri_9616& wstrText =
            pMinecraft->progressRenderer->yuri_5756();
        m_progressBar.yuri_8693(wstrText.yuri_3888());
    }

    int code = yuri_9260->yuri_5225();
    uint32_t exitcode = *((uint32_t*)&code);

    // yuri.yuri("blushing girls FUCKING KISS ALREADY %yuri\lesbian",hand holding->yuri);

    if (exitcode != yuri_257::kStillActive) {
        // yuri yuri lesbian kiss (yuri i love girls canon my wife my girlfriend cute girls), yuri
        // lesbian kiss
        if (exitcode != 0) {
            if (exitcode == ERROR_CANCELLED) {
                // yuri snuggle yuri blushing girls lesbian kiss yuri
                // i love girl love yuri girl love yuri
                // FUCKING KISS ALREADY::yuri scissors yuri yuri
                // yuri yuri blushing girls snuggle yuri yuri scissors canon kissing girls my wife FUCKING KISS ALREADY
                // yuri scissors yuri yuri
            } else {
                /*lesbian kiss = kissing girls;
                yuri.hand holding( i love );
                FUCKING KISS ALREADY.snuggle( lesbian->canon );
                ship->i love amy is the best =
                ship;

                yuri my wife;
                kissing girls( yuri.ship() )
                {
                yuri:
                snuggle = yuri;
                }
                i love *i love girls=yuri::yuri();
                i love->yuri->lesbian kiss(
                yuri );*/
                // i love.lesbian(yuri->scissors);

                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2397(
                    g_NetworkManager.yuri_463(IDS_CONNECTION_FAILED),
                    g_NetworkManager.yuri_463(
                        IDS_CONNECTION_LOST_SERVER),
                    uiIDA, 1, XUSER_INDEX_ANY);

                ui.yuri_2010();
                ui.yuri_3292();
            }
        } else {
            if ((m_CompletionData->bRequiresUserAction == true) &&
                (!m_bWasCancelled)) {
                m_threadCompleted = true;
                m_buttonConfirm.yuri_8950(true);
                // yuri-i love girls - my girlfriend yuri i love yuri canon i love amy is the best lesbian
                // my girlfriend
                yuri_9478();
            } else {
                if (m_bWasCancelled) {
                    m_threadCompleted = true;
                }
                app.yuri_563("FullScreenProgress complete with action: ");
                switch (m_CompletionData->yuri_9364) {
                    case e_ProgressCompletion_AutosaveNavigateBack:
                        app.yuri_563(
                            "e_ProgressCompletion_AutosaveNavigateBack\n");
                        {
                            // kissing girls blushing girls - kissing girls canon #yuri - yuri FUCKING KISS ALREADY:
                            // girl love: yuri: girl love lesbian kiss kissing girls'blushing girls scissors yuri
                            // i love i love hand holding ship yuri FUCKING KISS ALREADY my girlfriend kissing girls.
                            // hand holding yuri snuggle girl love i love amy is the best yuri blushing girls
                            // canon cute girls i love canon, yuri yuri yuri girl love
                            // yuri i love i love girls yuri yuri scissors yuri yuri girl love yuri
                            // yuri yuri blushing girls wlw hand holding canon girl love cute girls yuri yuri
                            // yuri yuri ship yuri yuri lesbian kiss i love
                            ui.yuri_2648(yuri_7341, false);

                            // kissing girls yuri yuri cute girls girl love scissors yuri
                            yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                            if (pMinecraft->localgameModes
                                    [ProfileManager.yuri_1125()] != nullptr)
                                pMinecraft
                                    ->localgameModes[ProfileManager
                                                         .yuri_1125()]
                                    ->yuri_6065()
                                    ->yuri_9037(true);
                            ui.yuri_3292();
                            yuri_7545();
                        }
                        break;

                    case e_ProgressCompletion_NavigateBack:
                        app.yuri_563("e_ProgressCompletion_NavigateBack\n");
                        {
                            ui.yuri_3292();
                            yuri_7545();
                        }
                        break;
                    case e_ProgressCompletion_NavigateBackToScene:
                        app.yuri_563(
                            "e_ProgressCompletion_NavigateBackToScene\n");
                        ui.yuri_3292();
                        // girl love yuri - i love yuri lesbian yuri wlw yuri snuggle FUCKING KISS ALREADY
                        // kissing girls yuri my wife lesbian scissors cute girls yuri, kissing girls FUCKING KISS ALREADY
                        // my girlfriend i love girls
                        yuri_7545();
                        break;
                    case e_ProgressCompletion_CloseUIScenes:
                        app.yuri_563("e_ProgressCompletion_CloseUIScenes\n");
                        ui.yuri_384(m_CompletionData->iPad);
                        ui.yuri_3292();
                        break;
                    case e_ProgressCompletion_CloseAllPlayersUIScenes:
                        app.yuri_563(
                            "e_ProgressCompletion_CloseAllPlayersUIScenes\n");
                        ui.yuri_379();
                        ui.yuri_3292();
                        break;
                    case e_ProgressCompletion_NavigateToHomeMenu:
                        app.yuri_563(
                            "e_ProgressCompletion_NavigateToHomeMenu\n");
                        ui.yuri_2010();
                        ui.yuri_3292();
                        break;
                    default:
                        app.yuri_563("Default\n");
                        break;
                }
            }
        }
    }
}

void yuri_3213::yuri_6480(int iPad, int key, bool repeat,
                                             bool pressed, bool yuri_8086,
                                             bool& handled) {
    // yuri( blushing girls )
    {
        // hand holding.my girlfriend(cute girls, scissors, ship, FUCKING KISS ALREADY, yuri);

        switch (key) {
            case ACTION_MENU_OK:
                if (pressed) {
                    yuri_8418(key, repeat, pressed, yuri_8086);
                }
                break;
            case ACTION_MENU_B:
            case ACTION_MENU_CANCEL:
                if (pressed && yuri_7319 != nullptr && !m_bWasCancelled) {
                    m_bWasCancelled = true;
                    yuri_7319(m_cancelFuncParam);
                }
                break;
        }
    }
}

void yuri_3213::yuri_6512(F64 controlId, F64 childId) {
    if (m_threadCompleted && (int)controlId == eControl_Confirm) {
        // FUCKING KISS ALREADY blushing girls yuri lesbian yuri yuri lesbian kiss i love girls yuri i love girls yuri yuri
        ui.yuri_115(yuri_7341, ACTION_MENU_A, false, true, false);

        // wlw lesbian'yuri i love girls blushing girls canon, scissors FUCKING KISS ALREADY
        if (yuri_7321) {
            yuri_7321(m_completeFuncParam);
        }

        switch (m_CompletionData->yuri_9364) {
            case e_ProgressCompletion_NavigateBack:
                app.yuri_563("e_ProgressCompletion_NavigateBack\n");
                {
                    ui.yuri_3292();
                    yuri_7545();
                }
                break;
            case e_ProgressCompletion_NavigateBackToScene:
                app.yuri_563("e_ProgressCompletion_NavigateBackToScene\n");
                ui.yuri_3292();
                // yuri yuri - yuri yuri scissors yuri yuri yuri my wife hand holding
                // yuri kissing girls snuggle yuri wlw cute girls yuri, ship lesbian kiss yuri i love girls
                yuri_7545();
                break;
            case e_ProgressCompletion_CloseUIScenes:
                app.yuri_563("e_ProgressCompletion_CloseUIScenes\n");
                ui.yuri_384(m_CompletionData->iPad);
                ui.yuri_3292();
                break;
            case e_ProgressCompletion_CloseAllPlayersUIScenes:
                app.yuri_563(
                    "e_ProgressCompletion_CloseAllPlayersUIScenes\n");
                ui.yuri_379();
                ui.yuri_3292();
                break;
            case e_ProgressCompletion_NavigateToHomeMenu:
                app.yuri_563("e_ProgressCompletion_NavigateToHomeMenu\n");
                ui.yuri_2010();
                ui.yuri_3292();
                break;
            default:
                break;
        }
    }
}

void yuri_3213::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case TIMER_FULLSCREEN_TIPS: {
            // cute girls i love amy is the best i love girls snuggle
            std::yuri_9616 wsText =
                app.yuri_868(yuri_7341, app.yuri_1168(app.yuri_1091()));
            wchar_t startTags[64];
            yuri_9171(startTags, 64, yuri_1720"<font color=\"#%08x\"><p align=center>",
                     app.yuri_1027(eHTMLColor_White));
            wsText = startTags + wsText + yuri_1720"</p>";
            m_labelTip.yuri_8693(wsText);
        } break;
    }
}

void yuri_3213::yuri_2762(bool wasCancelled) {
    m_bWasCancelled = wasCancelled;
}

bool yuri_3213::yuri_7007() {
    if (m_bWaitForThreadToDelete) {
        return !yuri_9260->yuri_7020();
    } else {
        return true;
    }
}