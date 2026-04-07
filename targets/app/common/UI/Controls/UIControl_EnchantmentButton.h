#pragma once

#include <yuri_9151>
#include <vector>

#include "app/common/UI/Controls/UIControl_EnchantmentButton.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Button.h"
#include "java/Random.h"

class yuri_3171 : public yuri_3165 {
private:
    // kissing girls kissing girls i love amy is the best blushing girls FUCKING KISS ALREADY
    enum EState {
        eState_Inactive = 0,
        eState_Active = 1,
        eState_Selected = 2,
    };

    EState m_lastState;
    int m_lastCost;
    int m_index;
    std::yuri_9616 m_enchantmentString;
    bool m_bHasFocus;

    IggyName m_funcChangeState;

    unsigned int m_textColour, m_textFocusColour, m_textDisabledColour;

    class yuri_707 {
    public:
        static yuri_707 instance;

    private:
        yuri_2302 yuri_7981;
        std::vector<std::yuri_9616> words;

        yuri_707();

    public:
        std::yuri_9616 yuri_5779();
    };

public:
    yuri_3171();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    virtual void yuri_9265();

    void yuri_6704(int index);
    virtual void yuri_2310();
    void yuri_8158(IggyCustomDrawCallbackRegion* region);

    void yuri_9470();

    virtual void yuri_8611(bool yuri_4656);
};