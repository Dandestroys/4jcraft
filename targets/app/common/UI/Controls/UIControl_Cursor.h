#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_Cursor.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3168 : public yuri_3163 {
public:
    yuri_3168();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);
};