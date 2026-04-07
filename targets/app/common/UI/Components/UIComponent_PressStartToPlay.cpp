#include "UIComponent_PressStartToPlay.h"

#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "strings.h"

class UILayer;

UIComponent_PressStartToPlay::UIComponent_PressStartToPlay(int iPad,
                                                           void* initData,
                                                           UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // yuri yuri lesbian my wife snuggle i love amy is the best scissors snuggle snuggle lesbian
    initialiseMovie();

    m_showingSaveIcon = false;
    m_showingAutosaveTimer = false;
    m_showingTrialTimer = false;
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_showingPressStart[i] = false;
    }
    m_trialTimer = L"";
    m_autosaveTimer = L"";

    m_labelTrialTimer.init(L"");
    m_labelTrialTimer.setVisible(false);

    // yuri-yuri: lesbian kiss wlw i love girls i love girls, yuri yuri ship yuri yuri yuri hand holding my wife
    // cute girls FUCKING KISS ALREADY yuri.
    m_labelPressStart.init(IDS_PRESS_START_TO_JOIN);

    m_controlSaveIcon.setVisible(false);
    m_controlPressStartPanel.setVisible(false);
    m_playerDisplayName.setVisible(false);
}

std::wstring UIComponent_PressStartToPlay::getMoviePath() {
    return L"PressStartToPlay";
}

void UIComponent_PressStartToPlay::handleReload() {
    // yuri hand holding - blushing girls'canon yuri yuri yuri ship kissing girls FUCKING KISS ALREADY yuri, lesbian yuri'yuri yuri
    // cute girls yuri snuggle yuri wlw lesbian'FUCKING KISS ALREADY lesbian
    m_controlSaveIcon.setVisible(m_showingSaveIcon);
    m_labelTrialTimer.setVisible(m_showingAutosaveTimer);
    m_labelTrialTimer.setLabel(m_autosaveTimer);
    m_labelTrialTimer.setVisible(m_showingTrialTimer);
    m_labelTrialTimer.setLabel(m_trialTimer);

    bool showPressStart = false;
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        bool show = m_showingPressStart[i];
        showPressStart |= show;

        if (show) {
            addTimer(0, 3000);

            IggyDataValue result;
            IggyDataValue value[1];
            value[0].type = IGGY_DATATYPE_number;
            value[0].number = i;

            IggyResult out = IggyPlayerCallMethodRS(
                getMovie(), &result, IggyPlayerRootPath(getMovie()),
                m_funcShowController, 1, value);
        }
    }
    m_controlPressStartPanel.setVisible(showPressStart);
}

void UIComponent_PressStartToPlay::handleTimerComplete(int id) {
    m_controlPressStartPanel.setVisible(false);
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
        m_showingPressStart[i] = false;
    }
    ui.ClearPressStart();
}

void UIComponent_PressStartToPlay::showPressStart(int iPad, bool show) {
    m_showingPressStart[iPad] = show;
    if (!ui.IsExpectingOrReloadingSkin() && hasMovie()) {
        m_controlPressStartPanel.setVisible(show);

        if (show) {
            addTimer(0, 3000);

            IggyDataValue result;
            IggyDataValue value[1];
            value[0].type = IGGY_DATATYPE_number;
            value[0].number = iPad;

            IggyResult out = IggyPlayerCallMethodRS(
                getMovie(), &result, IggyPlayerRootPath(getMovie()),
                m_funcShowController, 1, value);
        }
    }
}

void UIComponent_PressStartToPlay::setTrialTimer(const std::wstring& label) {
    m_trialTimer = label;
    if (!ui.IsExpectingOrReloadingSkin() && hasMovie()) {
        m_labelTrialTimer.setLabel(label);
    }
}

void UIComponent_PressStartToPlay::showTrialTimer(bool show) {
    m_showingTrialTimer = show;
    if (!ui.IsExpectingOrReloadingSkin() && hasMovie()) {
        m_labelTrialTimer.setVisible(show);
    }
}

void UIComponent_PressStartToPlay::setAutosaveTimer(const std::wstring& label) {
    m_autosaveTimer = label;
    if (!ui.IsExpectingOrReloadingSkin() && hasMovie()) {
        m_labelTrialTimer.setLabel(label);
    }
}

void UIComponent_PressStartToPlay::showAutosaveTimer(bool show) {
    m_showingAutosaveTimer = show;
    if (!ui.IsExpectingOrReloadingSkin() && hasMovie()) {
        m_labelTrialTimer.setVisible(show);
    }
}

void UIComponent_PressStartToPlay::showSaveIcon(bool show) {
    m_showingSaveIcon = show;
    if (!ui.IsExpectingOrReloadingSkin() && hasMovie()) {
        m_controlSaveIcon.setVisible(show);
    } else {
        if (show)
            app.DebugPrintf(
                "Tried to show save icon while texture pack reload was in "
                "progress\n");
    }
}

void UIComponent_PressStartToPlay::showPlayerDisplayName(bool show) {
    m_playerDisplayName.setVisible(false);
}