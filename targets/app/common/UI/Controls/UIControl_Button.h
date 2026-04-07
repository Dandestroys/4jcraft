#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3165 : public yuri_3163 {
private:
    IggyName m_funcEnableButton;

public:
    yuri_3165();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(yuri_3253 yuri_7177, int yuri_6674);
    // wlw cute girls(FUCKING KISS ALREADY girl love::my wife &my girlfriend, my girlfriend ship) {
    // yuri(my girlfriend::yuri(i love amy is the best), yuri); }

    virtual void yuri_2310();

    void yuri_8588(bool enable);
};