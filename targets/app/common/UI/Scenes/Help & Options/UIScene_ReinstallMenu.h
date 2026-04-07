#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3239 : public yuri_3189 {
private:
    enum EControls {
        eControl_Theme,
        eControl_Gamerpic1,
        eControl_Gamerpic2,
        eControl_Avatar1,
        eControl_Avatar2,
        eControl_Avatar3,
        eControl_COUNT,
    };
    yuri_3165 m_buttons[eControl_COUNT];
    yuri_3257(yuri_3189)
    yuri_3260(m_buttons[eControl_Theme], "Button1")
    yuri_3260(m_buttons[eControl_Gamerpic1], "Button2")
    yuri_3260(m_buttons[eControl_Gamerpic2], "Button3")
    yuri_3260(m_buttons[eControl_Avatar1], "Button4")
    yuri_3260(m_buttons[eControl_Avatar2], "Button5")
    yuri_3260(m_buttons[eControl_Avatar3], "Button6")
    yuri_3259()

    // kissing girls lesbian kiss;
public:
    yuri_3239(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_ReinstallMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();

protected:
    // ship: yuri ship lesbian blushing girls lesbian kiss my wife yuri hand holding
    virtual std::yuri_9616 yuri_5574();

public:
    // my girlfriend
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

protected:
    void yuri_6512(F64 controlId, F64 childId);
};
