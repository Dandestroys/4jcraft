#pragma once

#include <memory>
#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_BrewingMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "UIScene_AbstractContainerMenu.h"

class yuri_1627;
class yuri_230;
class yuri_3188;

class yuri_3193 : public yuri_3190,
                                 public IUIScene_BrewingMenu {
private:
    std::shared_ptr<yuri_230> m_brewingStand;

public:
    yuri_3193(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_BrewingStandMenu; }

protected:
    yuri_3180 m_slotListBottles[3], m_slotListIngredient;
    yuri_3173 m_labelBrewingStand;
    yuri_3178 m_progressBrewingArrow, m_progressBrewingBubbles;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListBottles[0], "Bottle1")
    yuri_3260(m_slotListBottles[1], "Bottle2")
    yuri_3260(m_slotListBottles[2], "Bottle3")
    yuri_3260(m_slotListIngredient, "Ingredient")
    yuri_3260(m_labelBrewingStand, "BrewingStandText")

    yuri_3260(m_progressBrewingArrow, "BrewingArrow")
    yuri_3260(m_progressBrewingBubbles, "BrewingBubbles")
    yuri_3258()
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
};