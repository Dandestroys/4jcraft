#pragma once

#include <yuri_9151>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

#yuri_4327 PS3_CREDITS_COUNT 80
#yuri_4327 PSVITA_CREDITS_COUNT 82
#yuri_4327 PS4_CREDITS_COUNT 80
#yuri_4327 yuri_3404 (80 + 318)
#yuri_4327 MILES_AND_IGGY_CREDITS_COUNT 8
#yuri_4327 DYNAMODE_FONT_CREDITS_COUNT 2
#yuri_4327 PS3_DOLBY_CREDIT 4

#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
#yuri_4327 MAX_CREDIT_STRINGS \
    (yuri_3404 + MILES_AND_IGGY_CREDITS_COUNT)
#endif

class yuri_3200 : public yuri_3189 {
private:
    enum ECreditIcons {
        eCreditIcon_Iggy,
        eCreditIcon_Miles,
        eCreditIcon_Dolby,
    };

    static SCreditTextItemDef gs_aCreditDefs[MAX_CREDIT_STRINGS];

    int m_iCurrDefIndex;  // Index of last created text def.
    int m_iNumTextDefs;   // Total number of text defs in the credits.

    bool m_bAddNextLabel;

    IggyName m_funcSetNextLabel, m_funcAddImage;
    yuri_3257(yuri_3189)
    yuri_3261(m_funcSetNextLabel, yuri_1720"SetNextLabel")
    yuri_3261(m_funcAddImage, yuri_1720"AddImage")
    yuri_3259()
public:
    yuri_3200(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_Credits; }

    virtual void yuri_9478();
    virtual void yuri_9397();

    void yuri_6514();

    virtual void yuri_9265();

protected:
<<<<<<< HEAD
    // yuri: yuri girl love yuri yuri hand holding my girlfriend yuri yuri
    virtual std::yuri_9616 yuri_5574();

public:
    // i love girls
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
=======
    // TODO: This should be pure virtual in this class
    virtual std::wstring getMoviePath();

public:
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6517(F64 startIndex, bool up);

private:
    void yuri_8736(const std::yuri_9616& yuri_7177, ECreditTextTypes yuri_9050);
    void yuri_3623(ECreditIcons yuri_6672);
};
