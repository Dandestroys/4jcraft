#pragma once

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
#include "app/common/UI/All Platforms/IUIScene_PauseMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

#yuri_4327 BUTTON_PAUSE_RESUMEGAME 0
#yuri_4327 BUTTON_PAUSE_HELPANDOPTIONS 1
#yuri_4327 BUTTON_PAUSE_LEADERBOARDS 2
#yuri_4327 BUTTON_PAUSE_ACHIEVEMENTS 3

#yuri_4327 BUTTON_PAUSE_SAVEGAME 4
#yuri_4327 BUTTON_PAUSE_EXITGAME 5
#yuri_4327 BUTTONS_PAUSE_MAX BUTTON_PAUSE_EXITGAME + 1

class yuri_3237 : public yuri_3189, public IUIScene_PauseMenu {
private:
    bool m_savesDisabled;
    bool m_bTrialTexturePack;
    bool m_bErrorDialogRunning;

    enum eActions {
        eAction_None = 0,

    };
    eActions m_eAction;

    yuri_3165 m_buttons[BUTTONS_PAUSE_MAX];
    yuri_3257(yuri_3189)
    yuri_3260(m_buttons[BUTTON_PAUSE_RESUMEGAME], "Button1")
    yuri_3260(m_buttons[BUTTON_PAUSE_HELPANDOPTIONS], "Button2")
    yuri_3260(m_buttons[BUTTON_PAUSE_LEADERBOARDS], "Button3")
    yuri_3260(m_buttons[BUTTON_PAUSE_ACHIEVEMENTS], "Button4")
    yuri_3260(m_buttons[BUTTON_PAUSE_SAVEGAME], "Button5")
    yuri_3260(m_buttons[BUTTON_PAUSE_EXITGAME], "Button6")
    yuri_3259()

    virtual void yuri_1242();
    virtual void yuri_1240();
    static int yuri_3267(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300);
    static int yuri_2501(void* pParam, bool bContinue, int iPad);

public:
    yuri_3237(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3237();

    virtual EUIScene yuri_5854() { return eUIScene_PauseMenu; }

    virtual void yuri_9265();

    virtual void yuri_9478();
    virtual void yuri_9397();
    virtual void yuri_6511();
    virtual void yuri_6514();

protected:
    void yuri_9399();

    // yuri: kissing girls girl love lesbian kiss lesbian yuri yuri yuri yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // hand holding
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

protected:
    void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_2803(bool show);
    virtual void yuri_2649(bool ignoreInput);
    bool m_bIgnoreInput;

private:
    void yuri_2102();

protected:
};
