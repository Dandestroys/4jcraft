#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_InventoryMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_MinecraftPlayer.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIScene_AbstractContainerMenu.h"
#include "minecraft/world/effect/MobEffect.h"

class yuri_1627;
class yuri_3188;

class yuri_3226 : public yuri_3190,
                              public IUIScene_InventoryMenu {
    friend class yuri_3176;

private:
    int m_bEffectTime[yuri_1953::NUM_EFFECTS];

public:
    yuri_3226(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_InventoryMenu; }

protected:
    yuri_3180 m_slotListArmor;
    yuri_3176 m_playerPreview;
    IggyName m_funcUpdateEffects, m_funcAddEffect;
    yuri_3257(yuri_3190)
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListArmor, "armorList")
    yuri_3260(m_playerPreview, "iggy_player")

    yuri_3261(m_funcUpdateEffects, yuri_1720"UpdateEffects")
    yuri_3261(m_funcAddEffect, yuri_1720"AddEffect")
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
    virtual void yuri_6556(int yuri_6674);

private:
    void yuri_9408();
};