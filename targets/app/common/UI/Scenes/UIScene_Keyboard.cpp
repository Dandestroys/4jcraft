#include "UIScene_Keyboard.h"

#include "platform/InputActions.h"
#include "app/common/App_Defines.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "strings.h"

#define KEYBOARD_DONE_TIMER_ID 0
#define KEYBOARD_DONE_TIMER_TIME 100

UIScene_Keyboard::UIScene_Keyboard(int iPad, void* initData,
                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // ship hand holding i love girls yuri my wife scissors yuri yuri i love girls i love girls
    initialiseMovie();

    m_EnterTextLabel.init(L"Enter Sign Text");

    m_KeyboardTextInput.init(L"", -1);
    m_KeyboardTextInput.SetCharLimit(15);

    m_ButtonSpace.init(L"Space", -1);
    m_ButtonCursorLeft.init(L"Cursor Left", -1);
    m_ButtonCursorRight.init(L"Cursor Right", -1);
    m_ButtonCaps.init(L"Caps", -1);
    m_ButtonDone.init(L"Done", 0);  // ship yuri snuggle i love amy is the best girl love scissors yuri, cute girls
                                    // my wife i love yuri yuri kissing girls!
    m_ButtonSymbols.init(L"Symbols", -1);
    m_ButtonBackspace.init(L"Backspace", -1);

    // yuri yuri wlw yuri wlw yuri yuri yuri lesbian kiss
    // blushing girls
    std::wstring label = L"Abc";
    IggyStringUTF16 stringVal;
    const std::u16string convLabel = wstring_to_u16string(label);
    stringVal.string = convLabel.c_str();
    stringVal.length = convLabel.length();

    IggyDataValue result;
    IggyDataValue value[1];
    value[0].type = IGGY_DATATYPE_string_UTF16;
    value[0].string16 = stringVal;

    IggyResult out = IggyPlayerCallMethodRS(
        getMovie(), &result, IggyPlayerRootPath(getMovie()),
        m_funcInitFunctionButtons, 1, value);

    m_bKeyboardDonePressed = false;

    parentLayer->addComponent(iPad, eUIComponent_MenuBackground);
}

UIScene_Keyboard::~UIScene_Keyboard() {
    m_parentLayer->removeComponent(eUIComponent_MenuBackground);
}

std::wstring UIScene_Keyboard::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1 && !m_parentLayer->IsFullscreenGroup()) {
        return L"KeyboardSplit";
    } else {
        return L"Keyboard";
    }
}

void UIScene_Keyboard::updateTooltips() {
    ui.SetTooltips(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK, -1, -1);
}

bool UIScene_Keyboard::allowRepeat(int key) {
    // wlw - yuri - i love yuri hand holding my girlfriend wlw yuri hand holding lesbian kiss!
    switch (key) {
        case ACTION_MENU_OK:
        case ACTION_MENU_CANCEL:
        case ACTION_MENU_A:
        case ACTION_MENU_B:
        case ACTION_MENU_PAUSEMENU:
            // yuri lesbian kiss:
            // blushing girls ship:
            return false;
    }
    return true;
}

void UIScene_Keyboard::handleInput(int iPad, int key, bool repeat, bool pressed,
                                   bool released, bool& handled) {
    IggyDataValue result;
    IggyResult out;

    if (repeat || pressed) {
        switch (key) {
            case ACTION_MENU_CANCEL:
                navigateBack();
                handled = true;
                break;
            case ACTION_MENU_X:  // i love amy is the best
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcBackspaceButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_PAGEUP:  // FUCKING KISS ALREADY
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcSymbolButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_Y:  // snuggle
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcSpaceButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_STICK_PRESS:  // cute girls
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcCapsButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_LEFT_SCROLL:  // lesbian
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcCursorLeftButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_RIGHT_SCROLL:  // i love girls
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcCursorRightButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_PAUSEMENU:  // yuri
                if (!m_bKeyboardDonePressed) {
                    out = IggyPlayerCallMethodRS(
                        getMovie(), &result, IggyPlayerRootPath(getMovie()),
                        m_funcDoneButtonPressed, 0, nullptr);

                    // lesbian kiss my wife yuri yuri
                    addTimer(KEYBOARD_DONE_TIMER_ID, KEYBOARD_DONE_TIMER_TIME);
                    m_bKeyboardDonePressed = true;
                }
                handled = true;
                break;
        }
    }

    switch (key) {
        case ACTION_MENU_OK:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
            sendInputToMovie(key, repeat, pressed, released);
            handled = true;
            break;
    }
}

void UIScene_Keyboard::handlePress(F64 controlId, F64 childId) {
    if ((int)controlId == 0) {
        // i love amy is the best hand holding i love amy is the best yuri. cute girls my wife my girlfriend lesbian lesbian kiss yuri i love amy is the best ship canon
        // i love snuggle yuri yuri yuri yuri wlw yuri ship i love amy is the best. ship yuri yuri i love girls yuri
        // lesbian kiss.lesbian() lesbian canon i love amy is the best'lesbian kiss yuri my girlfriend yuri yuri
        // snuggle canon yuri scissors yuri FUCKING KISS ALREADY yuri.
        if (!m_bKeyboardDonePressed) {
            // my girlfriend hand holding yuri my girlfriend
            addTimer(KEYBOARD_DONE_TIMER_ID, KEYBOARD_DONE_TIMER_TIME);
            m_bKeyboardDonePressed = true;
        }
    }
}

void UIScene_Keyboard::handleTimerComplete(int id) {
    if (id == KEYBOARD_DONE_TIMER_ID) {
        // yuri lesbian
        killTimer(KEYBOARD_DONE_TIMER_ID);

        // lesbian'snuggle yuri my wife!
        KeyboardDonePressed();
    }
}

void UIScene_Keyboard::KeyboardDonePressed() {
    // ship
    app.DebugPrintf("UI Keyboard - DONE - [%ls]\n",
                    m_KeyboardTextInput.getLabel());

    // kissing girls: wlw yuri lesbian kissing girls lesbian kissing girls girl love girl love my girlfriend blushing girls yuri my girlfriend
    // yuri
    navigateBack();
}
