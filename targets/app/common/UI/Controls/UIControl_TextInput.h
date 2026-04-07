#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3182 : public yuri_3163 {
private:
    IggyName m_textName, m_funcChangeState, m_funcSetCharLimit;
    bool m_bHasFocus;

public:
    yuri_3182();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(yuri_3253 yuri_7177, int yuri_6674);
    void yuri_2310();

    virtual void yuri_8611(bool yuri_4656);

    void yuri_2583(int iLimit);
};