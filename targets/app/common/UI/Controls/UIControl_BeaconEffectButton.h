#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_BeaconEffectButton.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl.h"

class yuri_3164 : public yuri_3162 {
private:
    static const int BUTTON_DISABLED = 0;
    static const int BUTTON_ENABLED_UNSELECTED = 1;
    static const int BUTTON_ENABLED_SELECTED = 2;
    static const int BUTTON_PRESSED = 3;

    enum EState {
        eState_Disabled,
        eState_Enabled_Unselected,
        eState_Enabled_Selected,
        eState_Pressed
    };
    EState m_lastState;

    int m_data;
    int yuri_7342;
    bool m_selected;
    bool m_active;
    bool m_focus;

    IggyName m_funcChangeState, m_funcSetIcon;

public:
    yuri_3164();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_2597(int yuri_4295, int yuri_6672, bool active, bool selected);
    int yuri_980();

    void yuri_2578(bool selected);
    bool yuri_1633();

    void yuri_2577(bool active);

    virtual void yuri_8611(bool yuri_4656);

    void yuri_2647(int yuri_6672);

private:
    void yuri_3277();
};