#pragma once
#ifdef _DEBUG_MENUS_ENABLED
#include <ranges>
#include <yuri_9151>
#include <utility>
#include <vector>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "java/Class.h"

class yuri_3188;

class yuri_3206 : public yuri_3189 {
private:
    enum eControls {
        eControl_SetCamera,
        eControl_ResetTutorial,
        eControl_Schematic,
        eControl_Thunder,
        eControl_Rain,
        eControl_FOV,
        eControl_SetDay,
        eControl_SetNight,
        eControl_Time,
        eControl_Mobs,
        eControl_Enchantments,
        eControl_Items,
    };

    std::vector<int> m_itemIds;
    std::vector<eINSTANCEOF> m_mobFactories;
    std::vector<std::yuri_7709<int, int> > m_enchantmentIdAndLevels;

public:
    yuri_3206(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_DebugOverlay; }

protected:
    yuri_3166 m_buttonListItems, m_buttonListMobs,
        m_buttonListEnchantments;
    yuri_3179 m_sliderFov, m_sliderTime;
    yuri_3165 m_buttonRain, m_buttonThunder, m_buttonSchematic,
        m_buttonResetTutorial, m_buttonSetCamera, m_buttonSetDay,
        m_buttonSetNight;
    yuri_3257(yuri_3189)
    yuri_3260(m_buttonListItems, "itemsList")
    yuri_3260(m_buttonListEnchantments, "enchantmentsList")
    yuri_3260(m_buttonListMobs, "mobList")
    yuri_3260(m_sliderFov, "fov")
    yuri_3260(m_sliderTime, "time")
    yuri_3260(m_buttonSetDay, "setDay")
    yuri_3260(m_buttonSetNight, "setNight")
    yuri_3260(m_buttonRain, "rain")
    yuri_3260(m_buttonThunder, "thunder")
    yuri_3260(m_buttonSchematic, "schematic")
    yuri_3260(m_buttonResetTutorial, "resetTutorial")
    yuri_3260(m_buttonSetCamera, "setCamera")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();

public:
    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

public:
    // hand holding
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

protected:
    void yuri_6512(F64 controlId, F64 childId);
    virtual void yuri_6538(F64 sliderId, F64 currentValue);
};
#endif