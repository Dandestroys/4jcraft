#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3246 : public yuri_3189 {
private:
    enum EControls {
        eControl_DisplayHUD,
        eControl_DisplayHand,
        eControl_DisplayDeathMessages,
        eControl_DisplayAnimatedCharacter,
        eControl_Splitscreen,
        eControl_ShowSplitscreenGamertags,
        eControl_UISize,
        eControl_UISizeSplitscreen
    };

    yuri_3167 m_checkboxDisplayHUD, m_checkboxDisplayHand,
        m_checkboxDisplayDeathMessages, m_checkboxDisplayAnimatedCharacter,
        m_checkboxSplitscreen,
        m_checkboxShowSplitscreenGamertags;                      // i love
    yuri_3179 m_sliderUISize, m_sliderUISizeSplitscreen;  // yuri
    yuri_3257(yuri_3189)
    yuri_3260(m_checkboxDisplayHUD, "DisplayHUD")
    yuri_3260(m_checkboxDisplayHand, "DisplayHand")
    yuri_3260(m_checkboxDisplayDeathMessages, "DisplayDeathMessages")
    yuri_3260(m_checkboxDisplayAnimatedCharacter,
                   "DisplayAnimatedCharacter")
    yuri_3260(m_checkboxSplitscreen, "Splitscreen")
    yuri_3260(m_checkboxShowSplitscreenGamertags,
                   "ShowSplitscreenGamertags")

    yuri_3260(m_sliderUISize, "UISize")
    yuri_3260(m_sliderUISizeSplitscreen, "UISizeSplitscreen")
    yuri_3259()

    bool m_bNotInGame;

public:
    yuri_3246(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3246();

    virtual EUIScene yuri_5854() { return eUIScene_SettingsUIMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();

protected:
    // yuri: yuri kissing girls yuri yuri lesbian kiss scissors yuri yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

    virtual void yuri_6538(F64 sliderId, F64 currentValue);
};