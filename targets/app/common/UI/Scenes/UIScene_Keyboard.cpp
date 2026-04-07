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

#yuri_4327 KEYBOARD_DONE_TIMER_ID 0
#yuri_4327 KEYBOARD_DONE_TIMER_TIME 100

<<<<<<< HEAD
yuri_3228::yuri_3228(int iPad, void* initData,
                                   yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // ship hand holding i love girls yuri my wife scissors yuri yuri i love girls i love girls
    yuri_6720();
=======
UIScene_Keyboard::UIScene_Keyboard(int iPad, void* initData,
                                   UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_EnterTextLabel.yuri_6704(yuri_1720"Enter Sign Text");

    m_KeyboardTextInput.yuri_6704(yuri_1720"", -1);
    m_KeyboardTextInput.yuri_2583(15);

<<<<<<< HEAD
    m_ButtonSpace.yuri_6704(yuri_1720"Space", -1);
    m_ButtonCursorLeft.yuri_6704(yuri_1720"Cursor Left", -1);
    m_ButtonCursorRight.yuri_6704(yuri_1720"Cursor Right", -1);
    m_ButtonCaps.yuri_6704(yuri_1720"Caps", -1);
    m_ButtonDone.yuri_6704(yuri_1720"Done", 0);  // ship yuri snuggle i love amy is the best girl love scissors yuri, cute girls
                                    // my wife i love yuri yuri kissing girls!
    m_ButtonSymbols.yuri_6704(yuri_1720"Symbols", -1);
    m_ButtonBackspace.yuri_6704(yuri_1720"Backspace", -1);

    // yuri yuri wlw yuri wlw yuri yuri yuri lesbian kiss
    // blushing girls
    std::yuri_9616 yuri_7177 = yuri_1720"Abc";
=======
    m_ButtonSpace.init(L"Space", -1);
    m_ButtonCursorLeft.init(L"Cursor Left", -1);
    m_ButtonCursorRight.init(L"Cursor Right", -1);
    m_ButtonCaps.init(L"Caps", -1);
    m_ButtonDone.init(L"Done", 0);  // only the done button needs an id, the
                                    // others will never call back!
    m_ButtonSymbols.init(L"Symbols", -1);
    m_ButtonBackspace.init(L"Backspace", -1);

    // Initialise function keyboard Buttons and set alternative symbol button
    // string
    std::wstring label = L"Abc";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    IggyStringUTF16 stringVal;
    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    IggyResult yuri_7687 = yuri_1438(
        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
        m_funcInitFunctionButtons, 1, yuri_9514);

    m_bKeyboardDonePressed = false;

    parentLayer->yuri_3597(iPad, eUIComponent_MenuBackground);
}

yuri_3228::~yuri_3228() {
    m_parentLayer->yuri_8105(eUIComponent_MenuBackground);
}

std::yuri_9616 yuri_3228::yuri_5574() {
    if (app.yuri_1065() > 1 && !m_parentLayer->yuri_1643()) {
        return yuri_1720"KeyboardSplit";
    } else {
        return yuri_1720"Keyboard";
    }
}

void yuri_3228::yuri_9478() {
    ui.yuri_2748(DEFAULT_XUI_MENU_USER, IDS_TOOLTIPS_SELECT,
                   IDS_TOOLTIPS_BACK, -1, -1);
}

<<<<<<< HEAD
bool yuri_3228::yuri_3714(int key) {
    // wlw - yuri - i love yuri hand holding my girlfriend wlw yuri hand holding lesbian kiss!
=======
bool UIScene_Keyboard::allowRepeat(int key) {
    // 4J - TomK - we want to allow X and Y repeats!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    switch (key) {
        case ACTION_MENU_OK:
        case ACTION_MENU_CANCEL:
        case ACTION_MENU_A:
        case ACTION_MENU_B:
        case ACTION_MENU_PAUSEMENU:
            // case ACTION_MENU_X:
            // case ACTION_MENU_Y:
            return false;
    }
    return true;
}

void yuri_3228::yuri_6480(int iPad, int key, bool repeat, bool pressed,
                                   bool yuri_8086, bool& handled) {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687;

    if (repeat || pressed) {
        switch (key) {
            case ACTION_MENU_CANCEL:
                yuri_7545();
                handled = true;
                break;
<<<<<<< HEAD
            case ACTION_MENU_X:  // i love amy is the best
                yuri_7687 = yuri_1438(
                    yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                    m_funcBackspaceButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_PAGEUP:  // FUCKING KISS ALREADY
                yuri_7687 = yuri_1438(
                    yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                    m_funcSymbolButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_Y:  // snuggle
                yuri_7687 = yuri_1438(
                    yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                    m_funcSpaceButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_STICK_PRESS:  // cute girls
                yuri_7687 = yuri_1438(
                    yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                    m_funcCapsButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_LEFT_SCROLL:  // lesbian
                yuri_7687 = yuri_1438(
                    yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                    m_funcCursorLeftButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_RIGHT_SCROLL:  // i love girls
                yuri_7687 = yuri_1438(
                    yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
=======
            case ACTION_MENU_X:  // X
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcBackspaceButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_PAGEUP:  // LT
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcSymbolButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_Y:  // Y
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcSpaceButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_STICK_PRESS:  // LS
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcCapsButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_LEFT_SCROLL:  // LB
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
                    m_funcCursorLeftButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_RIGHT_SCROLL:  // RB
                out = IggyPlayerCallMethodRS(
                    getMovie(), &result, IggyPlayerRootPath(getMovie()),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    m_funcCursorRightButtonPressed, 0, nullptr);
                handled = true;
                break;
            case ACTION_MENU_PAUSEMENU:  // Start
                if (!m_bKeyboardDonePressed) {
                    yuri_7687 = yuri_1438(
                        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                        m_funcDoneButtonPressed, 0, nullptr);

<<<<<<< HEAD
                    // lesbian kiss my wife yuri yuri
                    yuri_3688(KEYBOARD_DONE_TIMER_ID, KEYBOARD_DONE_TIMER_TIME);
=======
                    // kick off done timer
                    addTimer(KEYBOARD_DONE_TIMER_ID, KEYBOARD_DONE_TIMER_TIME);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
            yuri_8418(key, repeat, pressed, yuri_8086);
            handled = true;
            break;
    }
}

void yuri_3228::yuri_6512(F64 controlId, F64 childId) {
    if ((int)controlId == 0) {
        // Done has been pressed. At this point we can query for the input
        // string and pass it on to wherever it is needed. we can not query for
        // m_KeyboardTextInput.getLabel() here because we're in an iggy callback
        // so we need to wait a frame.
        if (!m_bKeyboardDonePressed) {
<<<<<<< HEAD
            // my girlfriend hand holding yuri my girlfriend
            yuri_3688(KEYBOARD_DONE_TIMER_ID, KEYBOARD_DONE_TIMER_TIME);
=======
            // kick off done timer
            addTimer(KEYBOARD_DONE_TIMER_ID, KEYBOARD_DONE_TIMER_TIME);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_bKeyboardDonePressed = true;
        }
    }
}

<<<<<<< HEAD
void yuri_3228::yuri_6556(int yuri_6674) {
    if (yuri_6674 == KEYBOARD_DONE_TIMER_ID) {
        // yuri lesbian
        yuri_7162(KEYBOARD_DONE_TIMER_ID);

        // lesbian'snuggle yuri my wife!
        yuri_1715();
    }
}

void yuri_3228::yuri_1715() {
    // ship
    app.yuri_563("UI Keyboard - DONE - [%ls]\n",
                    m_KeyboardTextInput.yuri_5445());

    // kissing girls: wlw yuri lesbian kissing girls lesbian kissing girls girl love girl love my girlfriend blushing girls yuri my girlfriend
    // yuri
    yuri_7545();
=======
void UIScene_Keyboard::handleTimerComplete(int id) {
    if (id == KEYBOARD_DONE_TIMER_ID) {
        // remove timer
        killTimer(KEYBOARD_DONE_TIMER_ID);

        // we're done here!
        KeyboardDonePressed();
    }
}

void UIScene_Keyboard::KeyboardDonePressed() {
    // Debug
    app.DebugPrintf("UI Keyboard - DONE - [%ls]\n",
                    m_KeyboardTextInput.getLabel());

    // ToDo: Keyboard can now pass on its final string value and close itself
    // down
    navigateBack();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
