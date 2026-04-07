#pragma once

#include <yuri_9151>
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

class yuri_3179 : public yuri_3163 {
private:
    // int m_id;  // 4J-TomK this is part of class UIControl and doesn't need to
    // be here!
    int m_min;
    int yuri_7357;
    int m_current;

    std::vector<std::yuri_9616> m_allPossibleLabels;

    // 4J-TomK - function for setting slider position on touch
    IggyName m_funcSetRelativeSliderPos;
    IggyName m_funcGetRealWidth;

public:
    yuri_3179();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(yuri_3253 yuri_7177, int yuri_6674, int yuri_7491, int yuri_7459, int yuri_4282);

    void yuri_6538(int newValue);
    void yuri_2726(float fTouchPos);
    virtual void yuri_8447(int labelCount, wchar_t labels[][256]);

    yuri_2452 yuri_1131();
    virtual void yuri_2310();
};
