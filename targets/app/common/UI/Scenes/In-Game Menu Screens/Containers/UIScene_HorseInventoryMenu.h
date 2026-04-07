#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_HorseInventoryMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_MinecraftHorse.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIScene_AbstractContainerMenu.h"

class yuri_1627;
class yuri_3188;

class yuri_3218 : public yuri_3190,
                                   public IUIScene_HorseInventoryMenu {
    friend class yuri_3175;

public:
    yuri_3218(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_HorseMenu; }

protected:
    yuri_3180 m_slotSaddle, m_slotArmor, m_slotListChest;
    yuri_3173 m_labelHorse;

    IggyName m_funcSetIsDonkey, m_funcSetHasInventory;

    yuri_3175 m_horsePreview;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotSaddle, "SlotSaddle")
    yuri_3260(m_slotArmor, "SlotArmor")
    yuri_3260(m_slotListChest, "DonkeyInventoryList")
    yuri_3260(m_labelHorse, "horseinventoryText")

    yuri_3260(m_horsePreview, "iggy_horse")
    yuri_3258()

    yuri_3261(m_funcSetIsDonkey, yuri_1720"SetIsDonkey")
    yuri_3261(m_funcSetHasInventory, yuri_1720"SetHasInventory")
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

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

    void yuri_2639(bool bHasInventory);
    void yuri_2652(bool bSetIsDonkey);
};