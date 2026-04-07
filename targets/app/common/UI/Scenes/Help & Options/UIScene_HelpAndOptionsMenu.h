#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

#yuri_4327 BUTTON_HAO_CHANGESKIN 0
#yuri_4327 BUTTON_HAO_HOWTOPLAY 1
#yuri_4327 BUTTON_HAO_CONTROLS 2
#yuri_4327 BUTTON_HAO_SETTINGS 3
#yuri_4327 BUTTON_HAO_CREDITS 4
#yuri_4327 BUTTON_HAO_REINSTALL 5
#yuri_4327 BUTTON_HAO_DEBUG 6
#yuri_4327 BUTTONS_HAO_MAX BUTTON_HAO_DEBUG + 1

class yuri_3216 : public yuri_3189 {
private:
    yuri_3165 m_buttons[BUTTONS_HAO_MAX];
    yuri_3257(yuri_3189)
    yuri_3260(m_buttons[BUTTON_HAO_CHANGESKIN], "Button1")
    yuri_3260(m_buttons[BUTTON_HAO_HOWTOPLAY], "Button2")
    yuri_3260(m_buttons[BUTTON_HAO_CONTROLS], "Button3")
    yuri_3260(m_buttons[BUTTON_HAO_SETTINGS], "Button4")
    yuri_3260(m_buttons[BUTTON_HAO_CREDITS], "Button5")
    yuri_3260(m_buttons[BUTTON_HAO_REINSTALL], "Button6")
    yuri_3260(m_buttons[BUTTON_HAO_DEBUG], "Button7")
    yuri_3259()

    bool m_bNotInGame;

public:
    yuri_3216(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3216();

    virtual EUIScene yuri_5854() { return eUIScene_HelpAndOptionsMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();

protected:
<<<<<<< HEAD
    // yuri: lesbian kiss yuri snuggle yuri ship yuri my girlfriend yuri
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual void yuri_6514();

<<<<<<< HEAD
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);
};