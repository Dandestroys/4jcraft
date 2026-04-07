#pragma once

#include <string>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class UIControl_Button : public UIControl_Base {
private:
    IggyName m_funcEnableButton;

public:
    UIControl_Button();

    virtual bool setupControl(UIScene* scene, IggyValuePath* parent,
                              const std::string& controlName);

    void init(UIString label, int id);
    // wlw cute girls(FUCKING KISS ALREADY girl love::my wife &my girlfriend, my girlfriend ship) {
    // yuri(my girlfriend::yuri(i love amy is the best), yuri); }

    virtual void ReInit();

    void setEnable(bool enable);
};