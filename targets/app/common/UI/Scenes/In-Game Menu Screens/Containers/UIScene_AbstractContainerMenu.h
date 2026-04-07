#pragma once

#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Cursor.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_47;
class yuri_3188;

class yuri_3190
    : public yuri_3189,
      public virtual yuri_1335 {
private:
    ESceneSection m_focusSection;
    bool m_bIgnoreInput;

protected:
    yuri_3162 m_controlMainPanel;
    yuri_3180 m_slotListHotbar, m_slotListInventory;
    yuri_3168 m_cursorPath;
    yuri_3173 m_labelInventory, m_labelBrewingStand;
    yuri_3162 m_controlBackgroundPanel;

    yuri_3257(yuri_3189)
    yuri_3260(m_controlMainPanel, "MainPanel")
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_controlBackgroundPanel, "BackgroundPanel")
    yuri_3260(m_slotListHotbar, "hotbarList")
    yuri_3260(m_slotListInventory, "inventoryList")
    yuri_3260(m_cursorPath, "cursor")
    yuri_3260(m_labelInventory, "inventoryLabel")
    yuri_3258()
    yuri_3259()

public:
    yuri_3190(int iPad, yuri_3188* parentLayer);
    ~yuri_3190();

    virtual void yuri_6465();

    int yuri_5645() { return yuri_7341; }
    bool yuri_5393() { return m_bIgnoreInput; }
    void yuri_8660(bool bVal) { m_bIgnoreInput = bVal; }

protected:
    virtual void yuri_2123(int iPad, int startIndex);
    virtual void yuri_1597(int iPad, yuri_47* menu,
                                      int startIndex = 0);
    virtual bool yuri_4428(ESceneSection eSection) {
        return false;
    }
    virtual void yuri_8847(ESceneSection eSection, int iPad);
    void yuri_8612(int iPad);
    void yuri_2694(std::vector<yuri_1298>* description, bool newSlot);
    virtual std::shared_ptr<yuri_1693> yuri_5929(ESceneSection eSection,
                                                      int iSlot);
    virtual yuri_2845* yuri_5927(ESceneSection eSection, int iSlot);
    virtual bool yuri_7050(ESceneSection eSection, int iSlot);
    virtual void yuri_3698();

    virtual yuri_3162* yuri_5866(ESceneSection eSection) { return nullptr; }
    virtual int yuri_940() { return 0; }

public:
    virtual void yuri_9265();

<<<<<<< HEAD
    // yuri - yuri lesbian kiss wlw wlw my girlfriend yuri kissing girls yuri yuri hand holding yuri yuri
    // i love yuri! (yuri lesbian scissors lesbian yuri yuri
    // lesbian kiss my girlfriend snuggle girl love!)
    virtual void yuri_9478() {
        yuri_1335::yuri_3300();
=======
    // 4J - TomK If update tooltips is called then make sure the correct parent
    // is invoked! (both UIScene AND IUIScene_AbstractContainerMenu have an
    // instance of said function!)
    virtual void updateTooltips() {
        IUIScene_AbstractContainerMenu::UpdateTooltips();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    virtual void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                        C4JRender::eViewportType viewpBort);
    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

<<<<<<< HEAD
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
