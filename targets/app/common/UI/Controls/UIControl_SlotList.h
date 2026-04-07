#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3180 : public yuri_3163 {
private:
    // IggyName m_addSlotFunc, m_getSlotFunc, m_setRedBoxFunc,
    // m_setHighlightFunc;
    IggyName m_addSlotFunc, m_setRedBoxFunc, m_setHighlightFunc;

    int m_lastHighlighted;

public:
    yuri_3180();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    virtual void yuri_2310();

    void yuri_3675(int yuri_6674);
    void yuri_3677(int iStartValue, int iCount);

    void yuri_8650(int index);
    void yuri_9033(int index, bool show);

    virtual void yuri_8611(bool yuri_4656);

private:
    void yuri_8870(int index, bool highlight);
};
