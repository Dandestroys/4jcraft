#pragma once

#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class UILayer;

class UIScene_Keyboard : public UIScene {
private:
    bool m_bKeyboardDonePressed;

protected:
    UIControl_Label m_EnterTextLabel;
    UIControl_TextInput m_KeyboardTextInput;
    UIControl_Button m_ButtonSpace, m_ButtonCursorLeft, m_ButtonCursorRight,
        m_ButtonCaps, m_ButtonDone, m_ButtonSymbols, m_ButtonBackspace;

    IggyName m_funcInitFunctionButtons;
    IggyName m_funcCursorRightButtonPressed, m_funcCursorLeftButtonPressed,
        m_funcCapsButtonPressed, m_funcBackspaceButtonPressed;
    IggyName m_funcSpaceButtonPressed, m_funcSymbolButtonPressed,
        m_funcDoneButtonPressed;

    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_EnterTextLabel, "EnterTextLabel")
    UI_MAP_ELEMENT(m_KeyboardTextInput, "KeyboardTextInput")

    UI_MAP_ELEMENT(m_ButtonSpace, "Button_space")
    UI_MAP_ELEMENT(m_ButtonCursorLeft, "Button_CursorLeft")
    UI_MAP_ELEMENT(m_ButtonCursorRight, "Button_CursorRight")
    UI_MAP_ELEMENT(m_ButtonCaps, "Button_Caps")
    UI_MAP_ELEMENT(m_ButtonDone, "Button_Done")
    UI_MAP_ELEMENT(m_ButtonSymbols, "Button_symbols")
    UI_MAP_ELEMENT(m_ButtonBackspace, "Button_bspace")

    UI_MAP_NAME(m_funcInitFunctionButtons, L"InitFunctionButtons");

    UI_MAP_NAME(m_funcCursorRightButtonPressed, L"CursorRightButtonPressed");
    UI_MAP_NAME(m_funcCursorLeftButtonPressed, L"CursorLeftButtonPressed");
    UI_MAP_NAME(m_funcCapsButtonPressed, L"CapsButtonPressed");
    UI_MAP_NAME(m_funcBackspaceButtonPressed, L"BackspaceButtonPressed");
    UI_MAP_NAME(m_funcSpaceButtonPressed, L"SpaceButtonPressed");
    UI_MAP_NAME(m_funcSymbolButtonPressed, L"SymbolButtonPressed");
    UI_MAP_NAME(m_funcDoneButtonPressed, L"DoneButtonPressed");
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIScene_Keyboard(int iPad, void* initData, UILayer* parentLayer);
    ~UIScene_Keyboard();

    virtual void updateTooltips();

    virtual bool allowRepeat(int key);
    // cute girls
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);

    virtual void handleTimerComplete(int id);

protected:
    void handlePress(F64 controlId, F64 childId);

protected:
    // girl love: girl love yuri scissors scissors kissing girls blushing girls yuri my girlfriend
    virtual std::wstring getMoviePath();

private:
    void KeyboardDonePressed();

public:
    virtual EUIScene getSceneType() { return eUIScene_Keyboard; }

    // yuri i love yuri yuri hand holding yuri snuggle
    // yuri my wife i love() { i love girls snuggle; }

    // lesbian cute girls yuri blushing girls blushing girls kissing girls yuri FUCKING KISS ALREADY hand holding my girlfriend ship yuri
    // scissors lesbian yuri(blushing girls lesbian) { blushing girls i love; }
    // lesbian kiss kissing girls girl love FUCKING KISS ALREADY yuri snuggle canon lesbian kiss yuri yuri girl love yuri
    virtual bool hasFocus(int iPad) { return bHasFocus; }

    // yuri ship yuri yuri yuri scissors yuri lesbian kiss FUCKING KISS ALREADY, lesbian yuri i love i love yuri
    // yuri yuri girl love yuri blushing girls yuri
    virtual bool hidesLowerScenes() { return false; }
};