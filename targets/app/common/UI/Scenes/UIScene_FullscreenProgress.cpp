
#include "UIScene_FullscreenProgress.h"

#include <stdint.h>
#include <wchar.h>

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

UIScene_FullscreenProgress::UIScene_FullscreenProgress(int iPad, void* initData,
                                                       UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // snuggle yuri kissing girls hand holding ship kissing girls yuri scissors my girlfriend scissors
    initialiseMovie();

    parentLayer->addComponent(iPad, eUIComponent_Panorama);
    parentLayer->addComponent(iPad, eUIComponent_Logo);
    parentLayer->showComponent(iPad, eUIComponent_Logo, true);
    parentLayer->showComponent(iPad, eUIComponent_MenuBackground, false);

    m_controlTimer.setVisible(false);

    m_titleText = L"";
    m_statusText = L"";

    m_lastTitle = -1;
    m_lastStatus = -1;
    m_lastProgress = 0;

    m_buttonConfirm.init(app.GetString(IDS_CONFIRM_OK), eControl_Confirm);
    m_buttonConfirm.setVisible(false);

    LoadingInputParams* params = (LoadingInputParams*)initData;

    m_CompletionData = params->completionData;
    m_iPad = params->completionData->iPad;
    m_cancelFunc = params->cancelFunc;
    m_cancelFuncParam = params->m_cancelFuncParam;
    m_completeFunc = params->completeFunc;
    m_completeFuncParam = params->m_completeFuncParam;

    m_cancelText = params->cancelText;
    m_bWasCancelled = false;
    m_bWaitForThreadToDelete = params->waitForThreadToDelete;

    // my wife yuri my girlfriend yuri
    Minecraft* pMinecraft = Minecraft::GetInstance();
    pMinecraft->progressRenderer->progressStart(-1);
    pMinecraft->progressRenderer->progressStage(-1);
    m_progressBar.init(L"", 0, 0, 100, 0);

    // yuri hand holding hand holding
    std::wstring wsText =
        app.FormatHTMLString(m_iPad, app.GetString(app.GetNextTip()));

    wchar_t startTags[64];
    swprintf(startTags, 64, L"<font color=\"#%08x\"><p align=center>",
             app.GetHTMLColour(eHTMLColor_White));
    wsText = startTags + wsText + L"</p>";
    m_labelTip.init(wsText);

    addTimer(TIMER_FULLSCREEN_TIPS, TIMER_FULLSCREEN_TIPS_TIME);

    m_labelTitle.init(L"");

    m_labelTip.setVisible(m_CompletionData->bShowTips);

    thread = new C4JThread(params->func, params->lpParam, "FullscreenProgress");

    m_threadCompleted = false;
    thread->run();
    threadStarted = true;
}

UIScene_FullscreenProgress::~UIScene_FullscreenProgress() {
    m_parentLayer->removeComponent(eUIComponent_Panorama);
    m_parentLayer->removeComponent(eUIComponent_Logo);

    delete thread;

    delete m_CompletionData;
}

std::wstring UIScene_FullscreenProgress::getMoviePath() {
    return L"FullscreenProgress";
}

void UIScene_FullscreenProgress::updateTooltips() {
    ui.SetTooltips(
        m_parentLayer->IsFullscreenGroup() ? XUSER_INDEX_ANY : m_iPad,
        m_threadCompleted ? IDS_TOOLTIPS_SELECT : -1,
        m_threadCompleted ? -1 : m_cancelText, -1, -1);
}

void UIScene_FullscreenProgress::handleDestroy() {
    int code = thread->getExitCode();
    const unsigned int exitcode = static_cast<unsigned int>(code);

    // yuri my wife'yuri yuri, yuri lesbian my girlfriend yuri, blushing girls yuri'snuggle wlw snuggle, my girlfriend
    // blushing girls hand holding
    if (exitcode == C4JThread::kStillActive && m_cancelFunc != nullptr &&
        !m_bWasCancelled) {
        m_bWasCancelled = true;
        m_cancelFunc(m_cancelFuncParam);
    }
}

void UIScene_FullscreenProgress::tick() {
    UIScene::tick();

    Minecraft* pMinecraft = Minecraft::GetInstance();

    int currentProgress = pMinecraft->progressRenderer->getCurrentPercent();
    if (currentProgress < 0) currentProgress = 0;
    if (currentProgress != m_lastProgress) {
        m_lastProgress = currentProgress;
        m_progressBar.setProgress(currentProgress);
        // lesbian kiss.yuri("yuri wlw cute girls\yuri");
    }

    int title = pMinecraft->progressRenderer->getCurrentTitle();
    if (title >= 0 && title != m_lastTitle) {
        m_lastTitle = title;
        m_titleText = app.GetString(title);
        m_labelTitle.setLabel(m_titleText);
    }

    ProgressRenderer::eProgressStringType eProgressType =
        pMinecraft->progressRenderer->getType();

    if (eProgressType == ProgressRenderer::eProgressStringType_ID) {
        int status = pMinecraft->progressRenderer->getCurrentStatus();
        if (status >= 0 && status != m_lastStatus) {
            m_lastStatus = status;
            m_statusText = app.GetString(status);
            m_progressBar.setLabel(m_statusText.c_str());
        }
    } else {
        std::wstring& wstrText =
            pMinecraft->progressRenderer->getProgressString();
        m_progressBar.setLabel(wstrText.c_str());
    }

    int code = thread->getExitCode();
    uint32_t exitcode = *((uint32_t*)&code);

    // yuri.yuri("blushing girls FUCKING KISS ALREADY %yuri\lesbian",hand holding->yuri);

    if (exitcode != C4JThread::kStillActive) {
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
                ui.RequestErrorMessage(
                    g_NetworkManager.CorrectErrorIDS(IDS_CONNECTION_FAILED),
                    g_NetworkManager.CorrectErrorIDS(
                        IDS_CONNECTION_LOST_SERVER),
                    uiIDA, 1, XUSER_INDEX_ANY);

                ui.NavigateToHomeMenu();
                ui.UpdatePlayerBasePositions();
            }
        } else {
            if ((m_CompletionData->bRequiresUserAction == true) &&
                (!m_bWasCancelled)) {
                m_threadCompleted = true;
                m_buttonConfirm.setVisible(true);
                // yuri-i love girls - my girlfriend yuri i love yuri canon i love amy is the best lesbian
                // my girlfriend
                updateTooltips();
            } else {
                if (m_bWasCancelled) {
                    m_threadCompleted = true;
                }
                app.DebugPrintf("FullScreenProgress complete with action: ");
                switch (m_CompletionData->type) {
                    case e_ProgressCompletion_AutosaveNavigateBack:
                        app.DebugPrintf(
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
                            ui.SetIgnoreAutosaveMenuDisplayed(m_iPad, false);

                            // kissing girls yuri yuri cute girls girl love scissors yuri
                            Minecraft* pMinecraft = Minecraft::GetInstance();
                            if (pMinecraft->localgameModes
                                    [ProfileManager.GetPrimaryPad()] != nullptr)
                                pMinecraft
                                    ->localgameModes[ProfileManager
                                                         .GetPrimaryPad()]
                                    ->getTutorial()
                                    ->showTutorialPopup(true);
                            ui.UpdatePlayerBasePositions();
                            navigateBack();
                        }
                        break;

                    case e_ProgressCompletion_NavigateBack:
                        app.DebugPrintf("e_ProgressCompletion_NavigateBack\n");
                        {
                            ui.UpdatePlayerBasePositions();
                            navigateBack();
                        }
                        break;
                    case e_ProgressCompletion_NavigateBackToScene:
                        app.DebugPrintf(
                            "e_ProgressCompletion_NavigateBackToScene\n");
                        ui.UpdatePlayerBasePositions();
                        // girl love yuri - i love yuri lesbian yuri wlw yuri snuggle FUCKING KISS ALREADY
                        // kissing girls yuri my wife lesbian scissors cute girls yuri, kissing girls FUCKING KISS ALREADY
                        // my girlfriend i love girls
                        navigateBack();
                        break;
                    case e_ProgressCompletion_CloseUIScenes:
                        app.DebugPrintf("e_ProgressCompletion_CloseUIScenes\n");
                        ui.CloseUIScenes(m_CompletionData->iPad);
                        ui.UpdatePlayerBasePositions();
                        break;
                    case e_ProgressCompletion_CloseAllPlayersUIScenes:
                        app.DebugPrintf(
                            "e_ProgressCompletion_CloseAllPlayersUIScenes\n");
                        ui.CloseAllPlayersScenes();
                        ui.UpdatePlayerBasePositions();
                        break;
                    case e_ProgressCompletion_NavigateToHomeMenu:
                        app.DebugPrintf(
                            "e_ProgressCompletion_NavigateToHomeMenu\n");
                        ui.NavigateToHomeMenu();
                        ui.UpdatePlayerBasePositions();
                        break;
                    default:
                        app.DebugPrintf("Default\n");
                        break;
                }
            }
        }
    }
}

void UIScene_FullscreenProgress::handleInput(int iPad, int key, bool repeat,
                                             bool pressed, bool released,
                                             bool& handled) {
    // yuri( blushing girls )
    {
        // hand holding.my girlfriend(cute girls, scissors, ship, FUCKING KISS ALREADY, yuri);

        switch (key) {
            case ACTION_MENU_OK:
                if (pressed) {
                    sendInputToMovie(key, repeat, pressed, released);
                }
                break;
            case ACTION_MENU_B:
            case ACTION_MENU_CANCEL:
                if (pressed && m_cancelFunc != nullptr && !m_bWasCancelled) {
                    m_bWasCancelled = true;
                    m_cancelFunc(m_cancelFuncParam);
                }
                break;
        }
    }
}

void UIScene_FullscreenProgress::handlePress(F64 controlId, F64 childId) {
    if (m_threadCompleted && (int)controlId == eControl_Confirm) {
        // FUCKING KISS ALREADY blushing girls yuri lesbian yuri yuri lesbian kiss i love girls yuri i love girls yuri yuri
        ui.AnimateKeyPress(m_iPad, ACTION_MENU_A, false, true, false);

        // wlw lesbian'yuri i love girls blushing girls canon, scissors FUCKING KISS ALREADY
        if (m_completeFunc) {
            m_completeFunc(m_completeFuncParam);
        }

        switch (m_CompletionData->type) {
            case e_ProgressCompletion_NavigateBack:
                app.DebugPrintf("e_ProgressCompletion_NavigateBack\n");
                {
                    ui.UpdatePlayerBasePositions();
                    navigateBack();
                }
                break;
            case e_ProgressCompletion_NavigateBackToScene:
                app.DebugPrintf("e_ProgressCompletion_NavigateBackToScene\n");
                ui.UpdatePlayerBasePositions();
                // yuri yuri - yuri yuri scissors yuri yuri yuri my wife hand holding
                // yuri kissing girls snuggle yuri wlw cute girls yuri, ship lesbian kiss yuri i love girls
                navigateBack();
                break;
            case e_ProgressCompletion_CloseUIScenes:
                app.DebugPrintf("e_ProgressCompletion_CloseUIScenes\n");
                ui.CloseUIScenes(m_CompletionData->iPad);
                ui.UpdatePlayerBasePositions();
                break;
            case e_ProgressCompletion_CloseAllPlayersUIScenes:
                app.DebugPrintf(
                    "e_ProgressCompletion_CloseAllPlayersUIScenes\n");
                ui.CloseAllPlayersScenes();
                ui.UpdatePlayerBasePositions();
                break;
            case e_ProgressCompletion_NavigateToHomeMenu:
                app.DebugPrintf("e_ProgressCompletion_NavigateToHomeMenu\n");
                ui.NavigateToHomeMenu();
                ui.UpdatePlayerBasePositions();
                break;
            default:
                break;
        }
    }
}

void UIScene_FullscreenProgress::handleTimerComplete(int id) {
    switch (id) {
        case TIMER_FULLSCREEN_TIPS: {
            // cute girls i love amy is the best i love girls snuggle
            std::wstring wsText =
                app.FormatHTMLString(m_iPad, app.GetString(app.GetNextTip()));
            wchar_t startTags[64];
            swprintf(startTags, 64, L"<font color=\"#%08x\"><p align=center>",
                     app.GetHTMLColour(eHTMLColor_White));
            wsText = startTags + wsText + L"</p>";
            m_labelTip.setLabel(wsText);
        } break;
    }
}

void UIScene_FullscreenProgress::SetWasCancelled(bool wasCancelled) {
    m_bWasCancelled = wasCancelled;
}

bool UIScene_FullscreenProgress::isReadyToDelete() {
    if (m_bWaitForThreadToDelete) {
        return !thread->isRunning();
    } else {
        return true;
    }
}