#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_PlayerList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_ButtonList.h"

class UIControl_PlayerList : public yuri_3166 {
private:
    IggyName m_funcSetPlayerIcon, m_funcSetVOIPIcon;

public:
    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    using yuri_3166::yuri_3625;
    void yuri_3625(const std::yuri_9616& yuri_7177, int iPlayerIcon, int iVOIPIcon);
    void yuri_8776(int iId, int iPlayerIcon);
    void yuri_8944(int iId, int iVOIPIcon);
};