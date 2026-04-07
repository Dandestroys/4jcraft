#include "UIControl_BeaconEffectButton.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

yuri_3164::yuri_3164() {
    m_data = 0;
    yuri_7342 = 0;
    m_selected = false;
    m_active = false;
    m_focus = false;
}

bool yuri_3164::yuri_8980(
    yuri_3189* scene, IggyValuePath* yuri_7791, const std::yuri_9151& controlName) {
    bool success = yuri_3162::yuri_8980(scene, yuri_7791, controlName);

    m_funcChangeState = yuri_8069(yuri_1720"ChangeState");
    m_funcSetIcon = yuri_8069(yuri_1720"SetIcon");

    return success;
}

void yuri_3164::yuri_2597(int yuri_4295, int yuri_6672, bool active,
                                           bool selected) {
    m_data = yuri_4295;
    m_active = active;
    m_selected = selected;

    yuri_2647(yuri_6672);
    yuri_3277();
}

int yuri_3164::yuri_980() { return m_data; }

void yuri_3164::yuri_2578(bool selected) {
    if (selected != m_selected) {
        m_selected = selected;

        yuri_3277();
    }
}

bool yuri_3164::yuri_1633() { return m_selected; }

void yuri_3164::yuri_2577(bool active) {
    if (m_active != active) {
        m_active = active;

        yuri_3277();
    }
}

void yuri_3164::yuri_8611(bool yuri_4656) {
    if (m_focus != yuri_4656) {
        m_focus = yuri_4656;

        yuri_3277();
    }
}

void yuri_3164::yuri_2647(int yuri_6672) {
    if (yuri_6672 != yuri_7342) {
        yuri_7342 = yuri_6672;

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = yuri_7342;
        IggyResult yuri_7687 =
            yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                   yuri_5392(), m_funcSetIcon, 1, yuri_9514);
    }
}

void yuri_3164::yuri_3277() {
    EState state = eState_Disabled;

    if (!m_active) {
        state = eState_Disabled;
    } else if (m_selected) {
        state = eState_Pressed;
    } else if (m_focus) {
        state = eState_Enabled_Selected;
    } else {
        state = eState_Enabled_Unselected;
    }

    if (state != m_lastState) {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = state;
        IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(),
                                                &yuri_8300, yuri_5392(),
                                                m_funcChangeState, 1, yuri_9514);

        if (yuri_7687 == IGGY_RESULT_SUCCESS) m_lastState = state;
    }
}