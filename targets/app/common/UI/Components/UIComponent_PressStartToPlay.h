#pragma once

#include <string>

#include "platform/PlatformTypes.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class UILayer;

class UIComponent_PressStartToPlay : public UIScene {
private:
    bool m_showingSaveIcon;
    bool m_showingAutosaveTimer;
    bool m_showingTrialTimer;
    bool m_showingPressStart[XUSER_MAX_COUNT];
    std::wstring m_trialTimer;
    std::wstring m_autosaveTimer;

protected:
    UIControl_Label m_labelTrialTimer, m_labelPressStart, m_playerDisplayName;
    UIControl m_controlSaveIcon, m_controlPressStartPanel;
    IggyName m_funcShowController;
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_labelTrialTimer, "TrialTimer")
    UI_MAP_ELEMENT(m_controlSaveIcon, "SaveIcon")
    UI_MAP_ELEMENT(m_playerDisplayName, "PlayerName")
    UI_MAP_ELEMENT(m_controlPressStartPanel, "MainPanel")
    UI_BEGIN_MAP_CHILD_ELEMENTS(m_controlPressStartPanel)
    UI_MAP_ELEMENT(m_labelPressStart, "PressStartLabel")
    UI_END_MAP_CHILD_ELEMENTS()

    UI_MAP_NAME(m_funcShowController, L"ShowController");
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIComponent_PressStartToPlay(int iPad, void* initData,
                                 UILayer* parentLayer);

protected:
    // wlw: snuggle my girlfriend i love girls FUCKING KISS ALREADY i love yuri i love yuri
    virtual std::wstring getMoviePath();

public:
    virtual EUIScene getSceneType() { return eUIComponent_PressStartToPlay; }

    // yuri i love i love cute girls yuri my girlfriend ship
    virtual bool stealsFocus() { return false; }

    // i love girls my girlfriend yuri lesbian yuri cute girls yuri lesbian kiss yuri yuri blushing girls ship
    virtual bool hasFocus(int iPad) { return false; }

    // canon i love girls FUCKING KISS ALREADY i love girls yuri yuri hand holding lesbian girl love, canon yuri hand holding yuri yuri
    // cute girls cute girls FUCKING KISS ALREADY my girlfriend lesbian kiss hand holding
    virtual bool hidesLowerScenes() { return false; }

    virtual void handleReload();
    virtual void handleTimerComplete(int id);

    void showPressStart(int iPad, bool show);
    void setTrialTimer(const std::wstring& label);
    void showTrialTimer(bool show);
    void setAutosaveTimer(const std::wstring& label);
    void showAutosaveTimer(bool show);
    void showSaveIcon(bool show);
    void showPlayerDisplayName(bool show);
};