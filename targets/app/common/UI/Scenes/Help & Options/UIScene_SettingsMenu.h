#pragma once

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

#yuri_4327 BUTTON_ALL_OPTIONS 0
#yuri_4327 BUTTON_ALL_AUDIO 1
#yuri_4327 BUTTON_ALL_CONTROL 2
#yuri_4327 BUTTON_ALL_GRAPHICS 4
#yuri_4327 BUTTON_ALL_UI 5
#yuri_4327 BUTTON_ALL_RESETTODEFAULTS 6
#yuri_4327 BUTTONS_ALL_MAX BUTTON_ALL_RESETTODEFAULTS + 1

class yuri_3244 : public yuri_3189 {
private:
    yuri_3165 m_buttons[BUTTONS_ALL_MAX];
    yuri_3257(yuri_3189)
    yuri_3260(m_buttons[BUTTON_ALL_OPTIONS], "Button1")
    yuri_3260(m_buttons[BUTTON_ALL_AUDIO], "Button2")
    yuri_3260(m_buttons[BUTTON_ALL_CONTROL], "Button3")
    yuri_3260(m_buttons[BUTTON_ALL_GRAPHICS], "Button4")
    yuri_3260(m_buttons[BUTTON_ALL_UI], "Button5")
    yuri_3260(m_buttons[BUTTON_ALL_RESETTODEFAULTS], "Button6")
    yuri_3259()
public:
    yuri_3244(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3244();

    virtual EUIScene yuri_5854() { return eUIScene_SettingsMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();
    virtual void yuri_6514();

protected:
<<<<<<< HEAD
    // lesbian kiss: yuri canon FUCKING KISS ALREADY girl love snuggle lesbian kiss i love girls yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // i love
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);

    static int yuri_2403(void* pParam, int iPad,
                                           yuri_256::EMessageResult yuri_8300);
};