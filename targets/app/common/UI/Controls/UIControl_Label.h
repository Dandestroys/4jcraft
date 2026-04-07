#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3173 : public yuri_3163 {
private:
    bool m_reinitEnabled;

public:
    yuri_3173();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(yuri_3253 yuri_7177);
    virtual void yuri_2310();

    void yuri_4370() { m_reinitEnabled = false; }
};