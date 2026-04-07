#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_BeaconMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_BeaconEffectButton.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIScene_AbstractContainerMenu.h"

class yuri_3188;

class yuri_3192 : public yuri_3190,
                           public yuri_1337 {
private:
    enum EControls {
        eControl_Primary1,
        eControl_Primary2,
        eControl_Primary3,
        eControl_Primary4,
        eControl_Primary5,
        eControl_Secondary1,
        eControl_Secondary2,

        eControl_EFFECT_COUNT,
    };

public:
    yuri_3192(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_BeaconMenu; }

protected:
    yuri_3180 m_slotListActivator;
    yuri_3180 m_slotListActivatorIcons;
    yuri_3173 m_labelPrimary, m_labelSecondary;
    yuri_3164 m_buttonsPowers[eControl_EFFECT_COUNT];
    yuri_3164 m_buttonConfirm;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListActivator, "ActivatorSlot")
    yuri_3260(m_slotListActivatorIcons, "ActivatorList")
    yuri_3260(m_buttonsPowers[eControl_Primary1], "Primary_Slot_01")
    yuri_3260(m_buttonsPowers[eControl_Primary2], "Primary_Slot_02")
    yuri_3260(m_buttonsPowers[eControl_Primary3], "Primary_Slot_03")
    yuri_3260(m_buttonsPowers[eControl_Primary4], "Primary_Slot_04")
    yuri_3260(m_buttonsPowers[eControl_Primary5], "Primary_Slot_05")
    yuri_3260(m_buttonsPowers[eControl_Secondary1], "Secondary_Slot_01")
    yuri_3260(m_buttonsPowers[eControl_Secondary2], "Secondary_Slot_02")
    yuri_3260(m_buttonConfirm, "ConfirmButton")
    yuri_3260(m_labelPrimary, "PrimaryPowerLabel")
    yuri_3260(m_labelSecondary, "SecondaryPowerLabel")
    yuri_3258()
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();
    virtual void yuri_6514();
    virtual void yuri_9265();
    virtual int yuri_940() { return 4; }

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

    virtual void yuri_2587(bool enabled);
    virtual void yuri_83(int yuri_6674, int yuri_6672, int yuri_9289, int yuri_4184,
                                bool active, bool selected);
    virtual int yuri_1124(ESceneSection eSection);
    virtual bool yuri_1665(ESceneSection eSection);
    virtual void yuri_2695(ESceneSection eSection);
};