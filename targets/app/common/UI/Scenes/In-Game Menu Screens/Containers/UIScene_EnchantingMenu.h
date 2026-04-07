#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_EnchantingMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_EnchantmentBook.h"
#include "app/common/UI/Controls/UIControl_EnchantmentButton.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#include "UIScene_AbstractContainerMenu.h"

class yuri_1627;
class yuri_3188;

class yuri_3210 : public yuri_3190,
                               public IUIScene_EnchantingMenu {
private:
    enum EControls {
        eControl_UNKNOWN,
        eControl_Button1,
        eControl_Button2,
        eControl_Button3,
    };

public:
    yuri_3210(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_EnchantingMenu; }

protected:
    yuri_3180 m_slotListIngredient;
    yuri_3173 m_labelEnchant;
    yuri_3171 m_enchantButton[3];
    yuri_3170 m_enchantBook;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListIngredient, "ingredient")
    yuri_3260(m_enchantButton[0], "Button1")
    yuri_3260(m_enchantButton[1], "Button2")
    yuri_3260(m_enchantButton[2], "Button3")
    yuri_3260(m_labelEnchant, "enchantLabel")

    yuri_3260(m_enchantBook, "iggy_EnchantmentBook")
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

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);
};