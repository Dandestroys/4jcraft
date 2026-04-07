#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_FireworksMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIScene_AbstractContainerMenu.h"

class yuri_1627;
class yuri_3188;

class yuri_3212 : public yuri_3190,
                              public IUIScene_FireworksMenu {
public:
    yuri_3212(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_FireworksMenu; }

protected:
    yuri_3180 m_slotListResult, m_slotList3x3, m_slotList2x2;
    yuri_3173 m_labelFireworks;
    IggyName m_funcShowLargeCraftingGrid;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListResult, "Result")
    yuri_3260(m_slotList3x3, "Fireworks3x3")
    yuri_3260(m_slotList2x2, "Fireworks2x2")
    yuri_3260(m_labelFireworks, "FireworksLabel")

    yuri_3261(m_funcShowLargeCraftingGrid, yuri_1720"ShowLargeCraftingGrid")
    yuri_3258()
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

    void yuri_2795(bool bShow);
};