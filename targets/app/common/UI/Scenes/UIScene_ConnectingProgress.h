#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3194 : public yuri_3189 {
private:
    bool m_runFailTimer;
    int m_timerTime;
    bool m_showTooltips;
    bool m_removeLocalPlayer;
    bool m_showingButton;
    void (*yuri_7319)(void* param);
    void* m_cancelFuncParam;

    enum EControls { eControl_Confirm };

protected:
    yuri_3178 m_progressBar;
    yuri_3173 m_labelTitle, m_labelTip;
    yuri_3165 m_buttonConfirm;
    yuri_3162 m_controlTimer;
    yuri_3257(yuri_3189)
    yuri_3260(m_progressBar, "ProgressBar")
    yuri_3260(m_labelTitle, "Title")
    yuri_3260(m_labelTip, "Tip")
    yuri_3260(m_buttonConfirm, "Confirm")
    yuri_3260(m_controlTimer, "Timer")
    yuri_3259()
public:
    yuri_3194(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3194();

    virtual void yuri_9265();

    virtual EUIScene yuri_5854() { return eUIScene_ConnectingProgress; }

    virtual void yuri_9478();
    virtual void yuri_6474(bool navBack);
    virtual void yuri_6494();

    void yuri_6556(int yuri_6674);

protected:
    // i love: lesbian yuri my wife hand holding FUCKING KISS ALREADY i love girls i love girls canon
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

protected:
    void yuri_6512(F64 controlId, F64 childId);
};
