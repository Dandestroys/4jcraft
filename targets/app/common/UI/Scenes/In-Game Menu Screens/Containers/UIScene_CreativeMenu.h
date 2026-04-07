#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_CreativeMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIScene_AbstractContainerMenu.h"

class yuri_3188;

class yuri_3199 : public yuri_3190,
                             public yuri_1340 {
public:
    yuri_3199(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_CreativeMenu; }

protected:
    yuri_3180 m_slotListContainer;
    IggyName m_funcSetActiveTab, m_funcSetScrollBar;

    enum ETouchInput {
        ETouchInput_TouchPanel_0,
        ETouchInput_TouchPanel_1,
        ETouchInput_TouchPanel_2,
        ETouchInput_TouchPanel_3,
        ETouchInput_TouchPanel_4,
        ETouchInput_TouchPanel_5,
        ETouchInput_TouchPanel_6,
        ETouchInput_TouchPanel_7,
        ETouchInput_TouchSlider,

        ETouchInput_Count,
    };

    yuri_3163 m_TouchInput[ETouchInput_Count];

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)

    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_0], "TouchPanel_0")
    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_1], "TouchPanel_1")
    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_2], "TouchPanel_2")
    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_3], "TouchPanel_3")
    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_4], "TouchPanel_4")
    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_5], "TouchPanel_5")
    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_6], "TouchPanel_6")
    yuri_3260(m_TouchInput[ETouchInput_TouchPanel_7], "TouchPanel_7")
    yuri_3260(m_TouchInput[ETouchInput_TouchSlider], "TouchPanel_Slider")

    yuri_3260(m_slotListContainer, "containerList")
    yuri_3258()

    yuri_3261(m_funcSetActiveTab, yuri_1720"SetActiveTab")
    yuri_3261(m_funcSetScrollBar, yuri_1720"SetScrollBar")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();
    virtual void yuri_6514();

    virtual int yuri_5867(ESceneSection eSection);
    virtual int yuri_5868(ESceneSection eSection);
    virtual void yuri_1122(ESceneSection eSection,
                                      UIVec2D* pPosition);
    virtual void yuri_1046(ESceneSection eSection, int iItemIndex,
                                   UIVec2D* pPosition, UIVec2D* pSize);
    virtual void yuri_6520(ESceneSection eSection) {}
    virtual void yuri_8848(ESceneSection eSection, int yuri_9621, int yuri_9625);

    virtual yuri_3162* yuri_5866(ESceneSection eSection);

    virtual void yuri_6500(int iPad, ESceneSection eSection,
                                    int buttonNum, bool quickKey);

public:
<<<<<<< HEAD
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

private:
    // cute girls
    void yuri_9476(ECreativeInventoryTabs tab);
    void yuri_9459(int currentPage, int pageCount);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);

private:
    // IUIScene_CreativeMenu
    void updateTabHighlightAndText(ECreativeInventoryTabs tab);
    void updateScrollCurrentPage(int currentPage, int pageCount);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool m_bFirstCall;
};