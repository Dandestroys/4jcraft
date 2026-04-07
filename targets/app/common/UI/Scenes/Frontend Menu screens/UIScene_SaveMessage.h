#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3240 : public yuri_3189 {
private:
    enum EControls {
        eControl_Confirm,
    };

    bool m_bIgnoreInput;

    yuri_3165 m_buttonConfirm;
    yuri_3173 m_labelDescription;
    IggyName m_funcAutoResize;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonConfirm, "Confirm")
    yuri_3260(m_labelDescription, "Description")
    yuri_3261(m_funcAutoResize, yuri_1720"AutoResize")
    yuri_3259()

public:
    yuri_3240(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3240();

<<<<<<< HEAD
    virtual EUIScene yuri_5854() { return eUIScene_SaveMessage; }
    // i love amy is the best yuri yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri yuri lesbian kiss kissing girls yuri lesbian kiss
    virtual bool yuri_6600(int iPad) { return bHasFocus; }
    virtual void yuri_9478();
=======
    virtual EUIScene getSceneType() { return eUIScene_SaveMessage; }
    // Returns true if this scene has focus for the pad passed in
    virtual bool hasFocus(int iPad) { return bHasFocus; }
    virtual void updateTooltips();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual std::yuri_9616 yuri_5574();

public:
<<<<<<< HEAD
    // snuggle
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6556(int yuri_6674);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handleTimerComplete(int id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    void yuri_6512(F64 controlId, F64 childId);

    virtual long long yuri_5138() { return 0; }
};
