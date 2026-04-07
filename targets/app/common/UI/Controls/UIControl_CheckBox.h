#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_CheckBox.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3167 : public yuri_3163 {
private:
    IggyName m_checkedProp, m_funcEnable, m_funcSetCheckBox;

    bool m_bChecked, m_bEnabled;

public:
    yuri_3167();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(yuri_3253 yuri_7177, int yuri_6674, bool checked);

    bool yuri_1635();
    bool yuri_1638();
    void yuri_2613(bool enable);
    void yuri_8517(bool checked);
    void yuri_3123(bool checked);

    virtual void yuri_2310();
};
