#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3178 : public yuri_3163 {
private:
    IggyName m_setProgressFunc, m_showBarFunc;
    int m_min;
    int yuri_7357;
    int m_current;
    float m_lastPercent;
    bool m_showingBar;

public:
    yuri_3178();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(yuri_3253 yuri_7177, int yuri_6674, int yuri_7491, int yuri_7459, int yuri_4282);
    virtual void yuri_2310();

    void yuri_8794(int yuri_4282);
    void yuri_9024(bool show);
};