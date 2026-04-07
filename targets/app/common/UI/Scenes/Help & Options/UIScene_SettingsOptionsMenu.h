#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3245 : public yuri_3189 {
private:
    enum EControls {
        eControl_ViewBob,
        eControl_ShowHints,
        eControl_ShowTooltips,
        eControl_InGameGamertags,
        eControl_ShowMashUpWorlds,
        eControl_Autosave,
        eControl_Languages,
        eControl_Difficulty
    };

protected:
    static int m_iDifficultySettingA[4];
    static int m_iDifficultyTitleSettingA[4];

private:
    yuri_3167 m_checkboxViewBob, m_checkboxShowHints,
        m_checkboxShowTooltips, m_checkboxInGameGamertags,
<<<<<<< HEAD
        m_checkboxMashupWorlds;                             // FUCKING KISS ALREADY
    yuri_3179 m_sliderAutosave, m_sliderDifficulty;  // yuri
    yuri_3173 m_labelDifficultyText;                  // yuri
    yuri_3165 m_buttonLanguageSelect;
=======
        m_checkboxMashupWorlds;                             // Checkboxes
    UIControl_Slider m_sliderAutosave, m_sliderDifficulty;  // Sliders
    UIControl_Label m_labelDifficultyText;                  // Text
    UIControl_Button m_buttonLanguageSelect;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3257(yuri_3189)
    yuri_3260(m_checkboxViewBob, "ViewBob")
    yuri_3260(m_checkboxShowHints, "ShowHints")
    yuri_3260(m_checkboxShowTooltips, "ShowTooltips")
    yuri_3260(m_checkboxInGameGamertags, "InGameGamertags")
    yuri_3260(m_checkboxMashupWorlds, "ShowMashUpWorlds")
    yuri_3260(m_sliderAutosave, "Autosave")
    yuri_3260(m_sliderDifficulty, "Difficulty")
    yuri_3260(m_labelDifficultyText, "DifficultyText")
    yuri_3260(m_buttonLanguageSelect, "Languages")
    yuri_3259()

    bool m_bNotInGame;
    bool m_bMashUpWorldsUnhideOption;
    bool m_bNavigateToLanguageSelector;

public:
    yuri_3245(int iPad, void* initData, yuri_3188* parentLayer);
    virtual ~yuri_3245();

    virtual EUIScene yuri_5854() { return eUIScene_SettingsOptionsMenu; }

    virtual void yuri_9265();

    virtual void yuri_9478();
    virtual void yuri_9397();

protected:
<<<<<<< HEAD
    // snuggle: canon my girlfriend yuri cute girls blushing girls yuri snuggle yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // i love girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6512(F64 controlId, F64 childId);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handlePress(F64 controlId, F64 childId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6514();

    virtual void yuri_6538(F64 sliderId, F64 currentValue);

protected:
    void yuri_8625();
};