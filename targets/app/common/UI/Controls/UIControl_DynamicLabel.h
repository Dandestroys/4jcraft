#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_DynamicLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "UIControl_Base.h"

class yuri_3169 : public yuri_3173 {
private:
    IggyName m_funcAddText, m_funcTouchScroll, m_funcGetRealWidth,
        m_funcGetRealHeight;

public:
    yuri_3169();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    virtual void yuri_3684(const std::yuri_9616& yuri_9254, bool bLastEntry);

    virtual void yuri_2310();

    virtual void yuri_2771();

    virtual void yuri_3122(yuri_2452 iY, bool bActive);

    yuri_2452 yuri_1131();
    yuri_2452 yuri_1130();
};
