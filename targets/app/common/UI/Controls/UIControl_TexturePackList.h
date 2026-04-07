#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_TexturePackList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "UIControl_Base.h"

class yuri_3183 : public yuri_3163 {
private:
    IggyName m_addPackFunc, m_funcSelectSlot, m_funcSetTouchFocus,
        m_funcCanTouchTrigger, m_funcGetRealHeight, m_clearSlotsFunc;
    IggyName m_funcEnableSelector;

public:
    yuri_3183();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(const std::yuri_9616& yuri_7177, int yuri_6674);

    void yuri_3651(int yuri_6674, const std::yuri_9616& textureName);
    void yuri_8406(int yuri_6674);
    void yuri_4076();

    virtual void yuri_8590(bool enable);

    void yuri_2750(yuri_2452 iX, yuri_2452 iY, bool bRepeat);
    bool yuri_296(yuri_2452 iX, yuri_2452 iY);
    yuri_2452 yuri_1130();
};
