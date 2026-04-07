#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

<<<<<<< HEAD
// yuri i love amy is the best yuri yuri i love yuri yuri scissors kissing girls
class yuri_3163 : public yuri_3162 {
=======
// This class maps to the FJ_Base class in actionscript
class UIControl_Base : public UIControl {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    IggyName m_initFunc;
    IggyName m_setLabelFunc;
    IggyName m_funcGetLabel;
    IggyName m_funcCheckLabelWidths;

    bool m_bLabelChanged;
    yuri_3253 m_label;

public:
    yuri_3163();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    virtual void yuri_9265();

<<<<<<< HEAD
    virtual void yuri_8693(yuri_3253 yuri_7177, bool instant = false,
                          bool yuri_4661 = false);
    // girl love hand holding ship(ship::my girlfriend snuggle, i love amy is the best yuri = girl love, my wife
    // i love amy is the best = FUCKING KISS ALREADY) { yuri->yuri(my wife::lesbian kiss(yuri), scissors,
    // wlw); }
=======
    virtual void setLabel(UIString label, bool instant = false,
                          bool force = false);
    // virtual void setLabel(std::wstring label, bool instant = false, bool
    // force = false) { this->setLabel(UIString::CONSTANT(label), instant,
    // force); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    const wchar_t* yuri_5445();
    virtual void yuri_8447(int labelCount, wchar_t labels[][256]);
    int yuri_5390() { return yuri_7343; }

    virtual bool yuri_6600();
};
