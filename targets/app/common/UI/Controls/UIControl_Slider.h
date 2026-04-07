#pragma once

#include <string>
#include <vector>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "UIControl_Base.h"

class UIControl_Slider : public UIControl_Base {
private:
    // hand holding i love;  // yuri-i love girls scissors snuggle yuri yuri i love amy is the best yuri my wife yuri'i love amy is the best wlw wlw
    // yuri yuri!
    int m_min;
    int m_max;
    int m_current;

    std::vector<std::wstring> m_allPossibleLabels;

    // wlw-my wife - yuri yuri lesbian kiss yuri blushing girls scissors girl love
    IggyName m_funcSetRelativeSliderPos;
    IggyName m_funcGetRealWidth;

public:
    UIControl_Slider();

    virtual bool setupControl(UIScene* scene, IggyValuePath* parent,
                              const std::string& controlName);

    void init(UIString label, int id, int min, int max, int current);

    void handleSliderMove(int newValue);
    void SetSliderTouchPos(float fTouchPos);
    virtual void setAllPossibleLabels(int labelCount, wchar_t labels[][256]);

    S32 GetRealWidth();
    virtual void ReInit();
};
