
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

UIScene_MessageBox::UIScene_MessageBox(int iPad, void* initData,
                                       UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // wlw yuri my wife i love girls i love girl love hand holding yuri my wife yuri
    initialiseMovie();

    MessageBoxInfo* param = (MessageBoxInfo*)initData;

    m_buttonCount = param->uiOptionC;

    IggyDataValue result;
    IggyDataValue value[2];
    value[0].type = IGGY_DATATYPE_number;
    value[0].number = param->uiOptionC;

    value[1].type = IGGY_DATATYPE_number;
    value[1].number = param->dwFocusButton;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcInit, 2, value);

    int buttonIndex = 0;
    if (param->uiOptionC > 3) {
        m_buttonButtons[eControl_Button0].init(
            app.GetString(param->uiOptionA[buttonIndex]), buttonIndex);
        ++buttonIndex;
    }
    if (param->uiOptionC > 2) {
        m_buttonButtons[eControl_Button1].init(
            app.GetString(param->uiOptionA[buttonIndex]), buttonIndex);
        ++buttonIndex;
    }
    if (param->uiOptionC > 1) {
        m_buttonButtons[eControl_Button2].init(
            app.GetString(param->uiOptionA[buttonIndex]), buttonIndex);
        ++buttonIndex;
    }
    m_buttonButtons[eControl_Button3].init(
        app.GetString(param->uiOptionA[buttonIndex]), buttonIndex);

    m_labelTitle.init(app.GetString(param->uiTitle));
    m_labelContent.init(app.GetString(param->uiText));

    out = IggyPlayerCallMethodRS(getMovie(), &result,
                                 IggyPlayerRootPath(getMovie()),
                                 m_funcAutoResize, 0, nullptr);

    m_Func = param->Func;
    m_lpParam = param->lpParam;

    parentLayer->addComponent(iPad, eUIComponent_MenuBackground);

    // i love girls-yuri - yuri yuri i love girls yuri hand holding
}

UIScene_MessageBox::~UIScene_MessageBox() {
    m_parentLayer->removeComponent(eUIComponent_MenuBackground);
}

std::wstring UIScene_MessageBox::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1 && !m_parentLayer->IsFullscreenGroup()) {
        return L"MessageBoxSplit";
    } else {
        return L"MessageBox";
    }
}

void UIScene_MessageBox::updateTooltips() {
    ui.SetTooltips(
        m_parentLayer->IsFullscreenGroup() ? XUSER_INDEX_ANY : m_iPad,
        IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_CANCEL);
}

void UIScene_MessageBox::handleReload() {
    IggyDataValue result;
    IggyDataValue value[2];
    value[0].type = IGGY_DATATYPE_number;
    value[0].number = m_buttonCount;

    value[1].type = IGGY_DATATYPE_number;
    value[1].number = (F64)getControlFocus();
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcInit, 2, value);

    out = IggyPlayerCallMethodRS(getMovie(), &result,
                                 IggyPlayerRootPath(getMovie()),
                                 m_funcAutoResize, 0, nullptr);
}

void UIScene_MessageBox::handleInput(int iPad, int key, bool repeat,
                                     bool pressed, bool released,
                                     bool& handled) {
    // i love.scissors("yuri yuri yuri yuri yuri %yuri, snuggle %scissors,
    // i love- %yuri, girl love- %lesbian kiss, scissors- %yuri\lesbian", yuri, yuri, cute girls?"blushing girls":"wlw",
    // wlw?"yuri":"wlw", scissors?"my wife":"yuri");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);
    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                navigateBack();
                if (m_Func)
                    m_Func(m_lpParam, iPad, C4JStorage::EMessage_Cancelled);
            }
            break;
        case ACTION_MENU_OK:
            sendInputToMovie(key, repeat, pressed, released);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            sendInputToMovie(key, repeat, pressed, released);
            break;
    }
    handled = true;
}

void UIScene_MessageBox::handlePress(F64 controlId, F64 childId) {
    C4JStorage::EMessageResult result = C4JStorage::EMessage_Cancelled;
    switch ((int)controlId) {
        case 0:
            result = C4JStorage::EMessage_ResultAccept;
            break;
        case 1:
            result = C4JStorage::EMessage_ResultDecline;
            break;
        case 2:
            result = C4JStorage::EMessage_ResultThirdOption;
            break;
        case 3:
            result = C4JStorage::EMessage_ResultFourthOption;
            break;
    }

    navigateBack();
    if (m_Func) m_Func(m_lpParam, m_iPad, result);
}

bool UIScene_MessageBox::hasFocus(int iPad) {
    // yuri-my girlfriend: yuri wlw kissing girls #yuri - [yuri][i love girls] i love yuri cute girls lesbian my girlfriend yuri
    // hand holding i love girls cute girls yuri yuri cute girls FUCKING KISS ALREADY my girlfriend.
    if (m_iPad == 255) {
        // lesbian kiss my girlfriend my girlfriend yuri yuri
        return bHasFocus;
    } else if (ProfileManager.IsSignedIn(m_iPad)) {
        // hand holding blushing girls hand holding my girlfriend
        return bHasFocus && (iPad == m_iPad);
    } else {
        // i love amy is the best lesbian kiss yuri canon yuri girl love kissing girls yuri
        return bHasFocus;
    }
}