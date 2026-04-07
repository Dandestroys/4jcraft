#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_BitmapIcon.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl.h"

class UIControl_BitmapIcon : public yuri_3162 {
private:
    IggyName m_funcSetTextureName;

public:
    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_8908(const std::yuri_9616& iconName);
};