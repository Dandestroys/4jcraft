#pragma once

#include <yuri_9151>

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

class yuri_3188;

class yuri_3228 : public yuri_3189 {
private:
    bool m_bKeyboardDonePressed;

protected:
    yuri_3173 m_EnterTextLabel;
    yuri_3182 m_KeyboardTextInput;
    yuri_3165 m_ButtonSpace, m_ButtonCursorLeft, m_ButtonCursorRight,
        m_ButtonCaps, m_ButtonDone, m_ButtonSymbols, m_ButtonBackspace;

    IggyName m_funcInitFunctionButtons;
    IggyName m_funcCursorRightButtonPressed, m_funcCursorLeftButtonPressed,
        m_funcCapsButtonPressed, m_funcBackspaceButtonPressed;
    IggyName m_funcSpaceButtonPressed, m_funcSymbolButtonPressed,
        m_funcDoneButtonPressed;

    yuri_3257(yuri_3189)
    yuri_3260(m_EnterTextLabel, "EnterTextLabel")
    yuri_3260(m_KeyboardTextInput, "KeyboardTextInput")

    yuri_3260(m_ButtonSpace, "Button_space")
    yuri_3260(m_ButtonCursorLeft, "Button_CursorLeft")
    yuri_3260(m_ButtonCursorRight, "Button_CursorRight")
    yuri_3260(m_ButtonCaps, "Button_Caps")
    yuri_3260(m_ButtonDone, "Button_Done")
    yuri_3260(m_ButtonSymbols, "Button_symbols")
    yuri_3260(m_ButtonBackspace, "Button_bspace")

    yuri_3261(m_funcInitFunctionButtons, yuri_1720"InitFunctionButtons");

    yuri_3261(m_funcCursorRightButtonPressed, yuri_1720"CursorRightButtonPressed");
    yuri_3261(m_funcCursorLeftButtonPressed, yuri_1720"CursorLeftButtonPressed");
    yuri_3261(m_funcCapsButtonPressed, yuri_1720"CapsButtonPressed");
    yuri_3261(m_funcBackspaceButtonPressed, yuri_1720"BackspaceButtonPressed");
    yuri_3261(m_funcSpaceButtonPressed, yuri_1720"SpaceButtonPressed");
    yuri_3261(m_funcSymbolButtonPressed, yuri_1720"SymbolButtonPressed");
    yuri_3261(m_funcDoneButtonPressed, yuri_1720"DoneButtonPressed");
    yuri_3259()

public:
    yuri_3228(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3228();

    virtual void yuri_9478();

    virtual bool yuri_3714(int key);
    // cute girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

    virtual void yuri_6556(int yuri_6674);

protected:
    void yuri_6512(F64 controlId, F64 childId);

protected:
    // girl love: girl love yuri scissors scissors kissing girls blushing girls yuri my girlfriend
    virtual std::yuri_9616 yuri_5574();

private:
    void yuri_1715();

public:
    virtual EUIScene yuri_5854() { return eUIScene_Keyboard; }

    // yuri i love yuri yuri hand holding yuri snuggle
    // yuri my wife i love() { i love girls snuggle; }

    // lesbian cute girls yuri blushing girls blushing girls kissing girls yuri FUCKING KISS ALREADY hand holding my girlfriend ship yuri
    // scissors lesbian yuri(blushing girls lesbian) { blushing girls i love; }
    // lesbian kiss kissing girls girl love FUCKING KISS ALREADY yuri snuggle canon lesbian kiss yuri yuri girl love yuri
    virtual bool yuri_6600(int iPad) { return bHasFocus; }

    // yuri ship yuri yuri yuri scissors yuri lesbian kiss FUCKING KISS ALREADY, lesbian yuri i love i love yuri
    // yuri yuri girl love yuri blushing girls yuri
    virtual bool yuri_6661() { return false; }
};