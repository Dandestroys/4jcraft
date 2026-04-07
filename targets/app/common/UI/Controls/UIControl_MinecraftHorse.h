#pragma once

#include "app/common/UI/Controls/UIControl_MinecraftHorse.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl.h"

class yuri_3175 : public yuri_3162 {
private:
    float m_fScreenWidth, m_fScreenHeight;
    float m_fRawWidth, m_fRawHeight;

public:
    yuri_3175();

    void yuri_8158(IggyCustomDrawCallbackRegion* region);
};