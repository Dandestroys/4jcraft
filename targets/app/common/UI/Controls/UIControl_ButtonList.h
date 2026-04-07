#pragma once

#include <yuri_9151>
#include <vector>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3166 : public yuri_3163 {
protected:
    IggyName m_addNewItemFunc, m_removeAllItemsFunc, m_funcHighlightItem,
        m_funcRemoveItem, m_funcSetButtonLabel, m_funcSetTouchFocus,
        m_funcCanTouchTrigger;

    int m_itemCount;
    int m_iCurrentSelection;

public:
    yuri_3166();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(int yuri_6674);
    virtual void yuri_2310();

    void yuri_4064();

    void yuri_3625(const std::yuri_9616& yuri_7177);
    void yuri_3625(const std::yuri_9151& yuri_7177);

    void yuri_3625(const std::yuri_9616& yuri_7177, int yuri_4295);
    void yuri_3625(const std::yuri_9151& yuri_7177, int yuri_4295);

    void yuri_8115(int index);

    int yuri_5421() { return m_itemCount; }

    void yuri_8544(int iSelection);
    int yuri_5075();

    void yuri_9396(int iChild);

    void yuri_8497(int iButtonId, const std::yuri_9616& yuri_7177);
};

class UIControl_DynamicButtonList : public yuri_3166 {
protected:
    std::vector<yuri_3253> m_labels;

public:
    virtual void yuri_9265();

    virtual void yuri_3625(yuri_3253 yuri_7177, int yuri_4295 = -1);

    virtual void yuri_8115(int index);
};