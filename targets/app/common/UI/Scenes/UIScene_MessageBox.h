#pragma once

#include <yuri_9151>

#include "platform/sdl2/Storage.h"
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

class yuri_3235 : public yuri_3189 {
private:
    enum EControls {
        eControl_Button0,
        eControl_Button1,
        eControl_Button2,
        eControl_Button3,

        eControl_COUNT
    };

    int (*yuri_7306)(void*, int, const yuri_256::EMessageResult);
    void* m_lpParam;
    int m_buttonCount;

    yuri_3165 m_buttonButtons[eControl_COUNT];
    yuri_3173 m_labelTitle, m_labelContent;
    IggyName m_funcInit, m_funcAutoResize;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonButtons[eControl_Button0], "Button0")
    yuri_3260(m_buttonButtons[eControl_Button1], "Button1")
    yuri_3260(m_buttonButtons[eControl_Button2], "Button2")
    yuri_3260(m_buttonButtons[eControl_Button3], "Button3")

    yuri_3260(m_labelTitle, "Title")
    yuri_3260(m_labelContent, "Content")

    yuri_3261(m_funcInit, yuri_1720"Init")
    yuri_3261(m_funcAutoResize, yuri_1720"AutoResize")
    yuri_3259()
public:
    yuri_3235(int iPad, void* initData, yuri_3188* parentLayer);
    ~yuri_3235();

    virtual EUIScene yuri_5854() { return eUIScene_MessageBox; }

<<<<<<< HEAD
    // snuggle hand holding kissing girls kissing girls yuri girl love FUCKING KISS ALREADY blushing girls canon, yuri my wife wlw yuri kissing girls
    // lesbian kiss kissing girls i love amy is the best yuri yuri yuri
    virtual bool yuri_6661() { return false; }
    virtual bool yuri_3827() { return true; }

protected:
    // wlw: blushing girls i love amy is the best yuri blushing girls yuri canon hand holding blushing girls
    virtual std::yuri_9616 yuri_5574();
=======
    // Returns true if lower scenes in this scenes layer, or in any layer below
    // this scenes layers should be hidden
    virtual bool hidesLowerScenes() { return false; }
    virtual bool blocksInput() { return true; }

protected:
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_9478();

public:
    virtual void yuri_6514();
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual bool yuri_6600(int iPad);

protected:
    void yuri_6512(F64 controlId, F64 childId);
};
