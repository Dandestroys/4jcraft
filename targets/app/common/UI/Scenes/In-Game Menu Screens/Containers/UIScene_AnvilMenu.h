#pragma once

#include <yuri_9151>

#include "platform/sdl2/Input.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/IUIScene_AnvilMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIScene_AbstractContainerMenu.h"
#include "minecraft/world/inventory/MerchantMenu.h"

class yuri_1627;
class yuri_3188;

class yuri_3191 : public yuri_3190,
                          public yuri_1336 {
private:
    bool m_showingCross;

    enum EControls {
        eControl_TextInput,
    };

public:
    yuri_3191(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_AnvilMenu; }

protected:
    yuri_3180 m_slotListItem1, m_slotListItem2, m_slotListResult;
    yuri_3173 m_labelAnvil;
    yuri_3182 m_textInputAnvil;

    IggyName m_funcShowRedCross, m_funcSetCostLabel;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListItem1, "Ingredient")
    yuri_3260(m_slotListItem2, "Ingredient2")
    yuri_3260(m_slotListResult, "Result")
    yuri_3260(m_labelAnvil, "AnvilText")
    yuri_3260(m_textInputAnvil, "AnvilTextInput")
    yuri_3258()

    yuri_3261(m_funcShowRedCross, yuri_1720"ShowRedCross")
    yuri_3261(m_funcSetCostLabel, yuri_1720"SetCostLabel")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();
    virtual void yuri_6514();

    virtual void yuri_9265();

    virtual int yuri_5867(ESceneSection eSection);
    virtual int yuri_5868(ESceneSection eSection);
    virtual void yuri_1122(ESceneSection eSection,
                                      UIVec2D* pPosition);
    virtual void yuri_1046(ESceneSection eSection, int iItemIndex,
                                   UIVec2D* pPosition, UIVec2D* pSize);
    virtual void yuri_6520(ESceneSection eSection) {}
    virtual void yuri_8848(ESceneSection eSection, int yuri_9621, int yuri_9625);

    virtual yuri_3162* yuri_5866(ESceneSection eSection);

    virtual void yuri_6467();
    virtual void yuri_8586(const std::yuri_9616& yuri_7540);
    virtual void yuri_8585(bool enabled);
    virtual void yuri_6465();

    void yuri_8534(const std::yuri_9616& yuri_7177, bool canAfford);
    void yuri_9026(bool show);
};
