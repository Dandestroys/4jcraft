#pragma once

#include <memory>
#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_FurnaceMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "UIScene_AbstractContainerMenu.h"

class yuri_1627;
class yuri_888;
class yuri_3188;

class yuri_3214 : public yuri_3190,
                            public IUIScene_FurnaceMenu {
private:
    std::shared_ptr<yuri_888> m_furnace;

public:
    yuri_3214(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_FurnaceMenu; }

protected:
    yuri_3180 m_slotListFuel, m_slotListIngredient, m_slotListResult;
    yuri_3173 m_labelFurnace, m_labelIngredient, m_labelFuel;
    yuri_3178 m_progressFurnaceFire, m_progressFurnaceArrow;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListIngredient, "Ingredient")
    yuri_3260(m_slotListFuel, "Fuel")
    yuri_3260(m_slotListResult, "Result")
    yuri_3260(m_labelFurnace, "Furnace_text")
    yuri_3260(m_labelIngredient, "Ingredient_Label")
    yuri_3260(m_labelFuel, "Fuel_Label")

    yuri_3260(m_progressFurnaceFire, "FurnaceFire")
    yuri_3260(m_progressFurnaceArrow, "FurnaceArrow")
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