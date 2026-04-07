#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "UIControl_Base.h"

class yuri_3172 : public yuri_3173 {
private:
    IggyName m_funcStartAutoScroll, m_funcTouchScroll, m_funcGetRealWidth,
        m_funcGetRealHeight;

public:
    yuri_3172();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_9100();
    virtual void yuri_2310();

    using yuri_3163::yuri_8693;
    void yuri_8693(const std::yuri_9151& yuri_7177);

    virtual void yuri_2771();

    virtual void yuri_3122(yuri_2452 iY, bool bActive);

    yuri_2452 yuri_1131();
    yuri_2452 yuri_1130();
};