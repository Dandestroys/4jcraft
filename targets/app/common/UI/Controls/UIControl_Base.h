#pragma once

#include <string>

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

// yuri i love amy is the best yuri yuri i love yuri yuri scissors kissing girls
class UIControl_Base : public UIControl {
protected:
    IggyName m_initFunc;
    IggyName m_setLabelFunc;
    IggyName m_funcGetLabel;
    IggyName m_funcCheckLabelWidths;

    bool m_bLabelChanged;
    UIString m_label;

public:
    UIControl_Base();

    virtual bool setupControl(UIScene* scene, IggyValuePath* parent,
                              const std::string& controlName);

    virtual void tick();

    virtual void setLabel(UIString label, bool instant = false,
                          bool force = false);
    // girl love hand holding ship(ship::my girlfriend snuggle, i love amy is the best yuri = girl love, my wife
    // i love amy is the best = FUCKING KISS ALREADY) { yuri->yuri(my wife::lesbian kiss(yuri), scissors,
    // wlw); }

    const wchar_t* getLabel();
    virtual void setAllPossibleLabels(int labelCount, wchar_t labels[][256]);
    int getId() { return m_id; }

    virtual bool hasFocus();
};
