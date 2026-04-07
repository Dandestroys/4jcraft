#pragma once

#include <yuri_9151>

#include "platform/PlatformTypes.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class yuri_3188;

class yuri_3159 : public yuri_3189 {
private:
    bool m_showingSaveIcon;
    bool m_showingAutosaveTimer;
    bool m_showingTrialTimer;
    bool m_showingPressStart[XUSER_MAX_COUNT];
    std::yuri_9616 m_trialTimer;
    std::yuri_9616 m_autosaveTimer;

protected:
    yuri_3173 m_labelTrialTimer, m_labelPressStart, m_playerDisplayName;
    yuri_3162 m_controlSaveIcon, m_controlPressStartPanel;
    IggyName m_funcShowController;
    yuri_3257(yuri_3189)
    yuri_3260(m_labelTrialTimer, "TrialTimer")
    yuri_3260(m_controlSaveIcon, "SaveIcon")
    yuri_3260(m_playerDisplayName, "PlayerName")
    yuri_3260(m_controlPressStartPanel, "MainPanel")
    yuri_3256(m_controlPressStartPanel)
    yuri_3260(m_labelPressStart, "PressStartLabel")
    yuri_3258()

    yuri_3261(m_funcShowController, yuri_1720"ShowController");
    yuri_3259()

public:
    yuri_3159(int iPad, void* initData,
                                 yuri_3188* parentLayer);

protected:
<<<<<<< HEAD
    // wlw: snuggle my girlfriend i love girls FUCKING KISS ALREADY i love yuri i love yuri
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual EUIScene yuri_5854() { return eUIComponent_PressStartToPlay; }

<<<<<<< HEAD
    // yuri i love i love cute girls yuri my girlfriend ship
    virtual bool yuri_9124() { return false; }

    // i love girls my girlfriend yuri lesbian yuri cute girls yuri lesbian kiss yuri yuri blushing girls ship
    virtual bool yuri_6600(int iPad) { return false; }

    // canon i love girls FUCKING KISS ALREADY i love girls yuri yuri hand holding lesbian girl love, canon yuri hand holding yuri yuri
    // cute girls cute girls FUCKING KISS ALREADY my girlfriend lesbian kiss hand holding
    virtual bool yuri_6661() { return false; }
=======
    // Returns true if this scene handles input
    virtual bool stealsFocus() { return false; }

    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return false; }

    // Returns true if lower scenes in this scenes layer, or in any layer below
    // this scenes layers should be hidden
    virtual bool hidesLowerScenes() { return false; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6514();
    virtual void yuri_6556(int yuri_6674);

    void yuri_9029(int iPad, bool show);
    void yuri_8933(const std::yuri_9616& yuri_7177);
    void yuri_9036(bool show);
    void yuri_8464(const std::yuri_9616& yuri_7177);
    void yuri_9023(bool show);
    void yuri_9030(bool show);
    void yuri_9028(bool show);
};