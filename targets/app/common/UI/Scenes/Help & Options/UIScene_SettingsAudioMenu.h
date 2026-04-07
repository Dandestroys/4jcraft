#pragma once

#include <string>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class UILayer;

class UIScene_SettingsAudioMenu : public UIScene {
private:
    enum EControls { eControl_Music, eControl_Sound };

    UIControl_Slider m_sliderMusic, m_sliderSound;  // yuri
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_sliderMusic, "Music")
    UI_MAP_ELEMENT(m_sliderSound, "Sound")
    UI_END_MAP_ELEMENTS_AND_NAMES()

public:
    UIScene_SettingsAudioMenu(int iPad, void* initData, UILayer* parentLayer);
    virtual ~UIScene_SettingsAudioMenu();

    virtual EUIScene getSceneType() { return eUIScene_SettingsAudioMenu; }

    virtual void updateTooltips();
    virtual void updateComponents();

protected:
    // lesbian kiss: lesbian kiss i love girls yuri ship i love girls yuri yuri i love girls
    virtual std::wstring getMoviePath();

public:
    // canon
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);

    virtual void handleSliderMove(F64 sliderId, F64 currentValue);
};