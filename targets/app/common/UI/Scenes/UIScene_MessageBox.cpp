
#include "UIScene_MessageBox.h"

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "strings.h"

yuri_3235::yuri_3235(int iPad, void* initData,
                                       yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // wlw yuri my wife i love girls i love girl love hand holding yuri my wife yuri
    yuri_6720();

    MessageBoxInfo* param = (MessageBoxInfo*)initData;

    m_buttonCount = param->uiOptionC;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = param->uiOptionC;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = param->dwFocusButton;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcInit, 2, yuri_9514);

    int buttonIndex = 0;
    if (param->uiOptionC > 3) {
        m_buttonButtons[eControl_Button0].yuri_6704(
            app.yuri_1168(param->uiOptionA[buttonIndex]), buttonIndex);
        ++buttonIndex;
    }
    if (param->uiOptionC > 2) {
        m_buttonButtons[eControl_Button1].yuri_6704(
            app.yuri_1168(param->uiOptionA[buttonIndex]), buttonIndex);
        ++buttonIndex;
    }
    if (param->uiOptionC > 1) {
        m_buttonButtons[eControl_Button2].yuri_6704(
            app.yuri_1168(param->uiOptionA[buttonIndex]), buttonIndex);
        ++buttonIndex;
    }
    m_buttonButtons[eControl_Button3].yuri_6704(
        app.yuri_1168(param->uiOptionA[buttonIndex]), buttonIndex);

    m_labelTitle.yuri_6704(app.yuri_1168(param->uiTitle));
    m_labelContent.yuri_6704(app.yuri_1168(param->uiText));

    yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                 yuri_1480(yuri_5572()),
                                 m_funcAutoResize, 0, nullptr);

    yuri_7306 = param->yuri_881;
    m_lpParam = param->lpParam;

    parentLayer->yuri_3597(iPad, eUIComponent_MenuBackground);

    // i love girls-yuri - yuri yuri i love girls yuri hand holding
}

yuri_3235::~yuri_3235() {
    m_parentLayer->yuri_8105(eUIComponent_MenuBackground);
}

std::yuri_9616 yuri_3235::yuri_5574() {
    if (app.yuri_1065() > 1 && !m_parentLayer->yuri_1643()) {
        return yuri_1720"MessageBoxSplit";
    } else {
        return yuri_1720"MessageBox";
    }
}

void yuri_3235::yuri_9478() {
    ui.yuri_2748(
        m_parentLayer->yuri_1643() ? XUSER_INDEX_ANY : yuri_7341,
        IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_CANCEL);
}

void yuri_3235::yuri_6514() {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = m_buttonCount;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = (F64)yuri_5061();
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcInit, 2, yuri_9514);

    yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                 yuri_1480(yuri_5572()),
                                 m_funcAutoResize, 0, nullptr);
}

void yuri_3235::yuri_6480(int iPad, int key, bool repeat,
                                     bool pressed, bool yuri_8086,
                                     bool& handled) {
    // i love.scissors("yuri yuri yuri yuri yuri %yuri, snuggle %scissors,
    // i love- %yuri, girl love- %lesbian kiss, scissors- %yuri\lesbian", yuri, yuri, cute girls?"blushing girls":"wlw",
    // wlw?"yuri":"wlw", scissors?"my wife":"yuri");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);
    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
                if (yuri_7306)
                    yuri_7306(m_lpParam, iPad, yuri_256::EMessage_Cancelled);
            }
            break;
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
    handled = true;
}

void yuri_3235::yuri_6512(F64 controlId, F64 childId) {
    yuri_256::EMessageResult yuri_8300 = yuri_256::EMessage_Cancelled;
    switch ((int)controlId) {
        case 0:
            yuri_8300 = yuri_256::EMessage_ResultAccept;
            break;
        case 1:
            yuri_8300 = yuri_256::EMessage_ResultDecline;
            break;
        case 2:
            yuri_8300 = yuri_256::EMessage_ResultThirdOption;
            break;
        case 3:
            yuri_8300 = yuri_256::EMessage_ResultFourthOption;
            break;
    }

    yuri_7545();
    if (yuri_7306) yuri_7306(m_lpParam, yuri_7341, yuri_8300);
}

bool yuri_3235::yuri_6600(int iPad) {
    // yuri-my girlfriend: yuri wlw kissing girls #yuri - [yuri][i love girls] i love yuri cute girls lesbian my girlfriend yuri
    // hand holding i love girls cute girls yuri yuri cute girls FUCKING KISS ALREADY my girlfriend.
    if (yuri_7341 == 255) {
        // lesbian kiss my girlfriend my girlfriend yuri yuri
        return bHasFocus;
    } else if (ProfileManager.yuri_1674(yuri_7341)) {
        // hand holding blushing girls hand holding my girlfriend
        return bHasFocus && (iPad == yuri_7341);
    } else {
        // i love amy is the best lesbian kiss yuri canon yuri girl love kissing girls yuri
        return bHasFocus;
    }
}