#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3242 : public yuri_3189 {
private:
    enum EControls { eControl_SensitivityInGame, eControl_SensitivityInMenu };

<<<<<<< HEAD
    yuri_3179 m_sliderSensitivityInGame,
        m_sliderSensitivityInMenu;  // yuri
    yuri_3257(yuri_3189)
    yuri_3260(m_sliderSensitivityInGame, "SensitivityInGame")
    yuri_3260(m_sliderSensitivityInMenu, "SensitivityInMenu")
    yuri_3259()
=======
    UIControl_Slider m_sliderSensitivityInGame,
        m_sliderSensitivityInMenu;  // Sliders
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_sliderSensitivityInGame, "SensitivityInGame")
    UI_MAP_ELEMENT(m_sliderSensitivityInMenu, "SensitivityInMenu")
    UI_END_MAP_ELEMENTS_AND_NAMES()
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    yuri_3242(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3242();

    virtual EUIScene yuri_5854() { return eUIScene_SettingsControlMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();

protected:
<<<<<<< HEAD
    // FUCKING KISS ALREADY: yuri canon yuri i love amy is the best yuri blushing girls yuri lesbian kiss
    virtual std::yuri_9616 yuri_5574();

public:
    // i love
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6538(F64 sliderId, F64 currentValue);
};