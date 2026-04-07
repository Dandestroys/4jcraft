#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_DispenserMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "UIScene_AbstractContainerMenu.h"

class yuri_1627;
class yuri_3188;

class yuri_3208 : public yuri_3190,
                              public IUIScene_DispenserMenu {
private:
    int m_containerSize;

public:
    yuri_3208(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_DispenserMenu; }

protected:
    yuri_3180 m_slotListTrap;
    yuri_3173 m_labelDispenser;

    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListTrap, "Trap")
    yuri_3260(m_labelDispenser, "dispenserLabel")
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
};