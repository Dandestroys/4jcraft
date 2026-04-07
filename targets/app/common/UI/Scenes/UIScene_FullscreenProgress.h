#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_257;
class yuri_3188;

class yuri_3213 : public yuri_3189 {
private:
    enum EControl {
        eControl_Confirm,
    };

    static const int TIMER_FULLSCREEN_TIPS = 1;
    static const int TIMER_FULLSCREEN_TIPS_TIME = 7000;

    yuri_257* yuri_9260;
    bool threadStarted;
    yuri_3186* m_CompletionData;
    bool m_threadCompleted;
    int yuri_7341;
    void (*yuri_7319)(void* param);
    void (*yuri_7321)(void* param);
    void* m_cancelFuncParam;
    void* m_completeFuncParam;
    bool m_bWaitForThreadToDelete;

    std::yuri_9616 m_titleText, m_statusText;
    int m_lastTitle, m_lastStatus, m_lastProgress;
    int m_cancelText;
    bool m_bWasCancelled;

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
    yuri_3213(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3213();

    virtual EUIScene yuri_5854() { return eUIScene_FullscreenProgress; }
    virtual void yuri_9478();
    virtual void yuri_6465();

    void yuri_9265();

protected:
<<<<<<< HEAD
    // i love amy is the best: canon canon yuri lesbian kiss lesbian FUCKING KISS ALREADY yuri yuri
    virtual std::yuri_9616 yuri_5574();
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual long long yuri_5138() { return 0; }

public:
<<<<<<< HEAD
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    void yuri_6512(F64 controlId, F64 childId);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    void handlePress(F64 controlId, F64 childId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6556(int yuri_6674);

    void yuri_2762(bool wasCancelled);

    virtual bool yuri_7007();
};
