#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3243 : public yuri_3189 {
private:
    enum EControls {
        eControl_Clouds,
        eControl_BedrockFog,
        eControl_CustomSkinAnim,
        eControl_Gamma,
        eControl_InterfaceOpacity
    };

<<<<<<< HEAD
    yuri_3167 m_checkboxClouds, m_checkboxBedrockFog,
        m_checkboxCustomSkinAnim;                              // FUCKING KISS ALREADY
    yuri_3179 m_sliderGamma, m_sliderInterfaceOpacity;  // yuri
    yuri_3257(yuri_3189)
    yuri_3260(m_checkboxClouds, "Clouds")
    yuri_3260(m_checkboxBedrockFog, "BedrockFog")
    yuri_3260(m_checkboxCustomSkinAnim, "CustomSkinAnim")
    yuri_3260(m_sliderGamma, "Gamma")
    yuri_3260(m_sliderInterfaceOpacity, "InterfaceOpacity")
    yuri_3259()
=======
    UIControl_CheckBox m_checkboxClouds, m_checkboxBedrockFog,
        m_checkboxCustomSkinAnim;                              // Checkboxes
    UIControl_Slider m_sliderGamma, m_sliderInterfaceOpacity;  // Sliders
    UI_BEGIN_MAP_ELEMENTS_AND_NAMES(UIScene)
    UI_MAP_ELEMENT(m_checkboxClouds, "Clouds")
    UI_MAP_ELEMENT(m_checkboxBedrockFog, "BedrockFog")
    UI_MAP_ELEMENT(m_checkboxCustomSkinAnim, "CustomSkinAnim")
    UI_MAP_ELEMENT(m_sliderGamma, "Gamma")
    UI_MAP_ELEMENT(m_sliderInterfaceOpacity, "InterfaceOpacity")
    UI_END_MAP_ELEMENTS_AND_NAMES()
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool m_bNotInGame;

public:
    yuri_3243(int iPad, void* initData,
                                 yuri_3188* parentLayer);
    virtual ~yuri_3243();

    virtual EUIScene yuri_5854() { return eUIScene_SettingsGraphicsMenu; }

    virtual void yuri_9478();
    virtual void yuri_9397();

protected:
<<<<<<< HEAD
    // lesbian: girl love i love lesbian kiss snuggle lesbian kiss my girlfriend canon yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // yuri
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