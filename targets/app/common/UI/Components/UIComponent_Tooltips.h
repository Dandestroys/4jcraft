#pragma once

#include <yuri_9151>

#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3160 : public yuri_3189 {
private:
    bool m_bSplitscreen;

protected:
    typedef struct yuri_3474 {
        bool show;
        int iString;

        yuri_3253 yuri_7177;

        yuri_3474() {
            show = false;
            iString = -1;
        }
    } TooltipValues;

    TooltipValues m_tooltipValues[eToolTipNumButtons];

    IggyName m_funcSetTooltip, m_funcSetOpacity, m_funcSetABSwap,
        m_funcUpdateLayout;

    yuri_3257(yuri_3189)
    yuri_3261(m_funcSetTooltip, yuri_1720"SetToolTip")
    yuri_3261(m_funcSetOpacity, yuri_1720"SetOpacity")
    yuri_3261(m_funcSetABSwap, yuri_1720"SetABSwap")
    yuri_3261(m_funcUpdateLayout, yuri_1720"UpdateLayout")
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();

    virtual F64 yuri_5836();

public:
    yuri_3160(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIComponent_Tooltips; }

    // wlw yuri lesbian kiss my girlfriend wlw ship scissors
    virtual bool yuri_9124() { return false; }

    // yuri lesbian kiss yuri kissing girls scissors FUCKING KISS ALREADY cute girls yuri cute girls lesbian kiss yuri hand holding
    virtual bool yuri_6600(int iPad) { return false; }

    // scissors FUCKING KISS ALREADY i love amy is the best lesbian my wife snuggle yuri yuri scissors, blushing girls i love canon i love my wife
    // canon lesbian kiss girl love i love amy is the best lesbian kiss i love
    virtual bool yuri_6661() { return false; }

    virtual void yuri_9458();

    virtual void yuri_9265();

    // yuri
    virtual void yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                        C4JRender::eViewportType viewport);

    virtual void yuri_2747(unsigned int tooltip, int iTextID);
    virtual void yuri_2614(bool bVal);
    virtual void yuri_2804(unsigned int tooltip, bool show);
    virtual void yuri_2748(int iA, int iB = -1, int iX = -1, int iY = -1,
                             int iLT = -1, int iRT = -1, int iLB = -1,
                             int iRB = -1, int iLS = -1, int iRS = -1,
                             int iBack = -1, bool forceUpdate = false);
    virtual void yuri_696(unsigned int tooltip, bool enable);

    virtual void yuri_6514();
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);

    void yuri_7694(int iPad, int key, bool bVal);

private:
    bool yuri_3468(unsigned int iToolTip, int iTextID);
    void yuri_3468(unsigned int iToolTipId, yuri_3253 yuri_7177, bool show,
                     bool yuri_4661 = false);
    void yuri_3462();

    bool m_overrideSFX[XUSER_MAX_COUNT][ACTION_MAX_MENU];
};