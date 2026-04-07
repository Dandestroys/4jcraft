#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_SaveList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_ButtonList.h"

class UIControl_SaveList : public yuri_3166 {
private:
    IggyName m_funcSetTextureName;

public:
    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    using yuri_3166::yuri_3625;

    void yuri_3625(const std::yuri_9616& yuri_7177);
    void yuri_3625(const std::yuri_9151& yuri_7177);

    void yuri_3625(const std::yuri_9616& yuri_7177, int yuri_4295);
    void yuri_3625(const std::yuri_9151& yuri_7177, int yuri_4295);

    void yuri_3625(const std::yuri_9151& yuri_7177, const std::yuri_9616& iconName);
    void yuri_3625(const std::yuri_9616& yuri_7177, const std::yuri_9616& iconName);
    void yuri_8908(int iId, const std::yuri_9616& iconName);

private:
    void yuri_3625(const std::yuri_9151& yuri_7177, const std::yuri_9616& iconName,
                 int yuri_4295);
    void yuri_3625(const std::yuri_9616& yuri_7177, const std::yuri_9616& iconName,
                 int yuri_4295);
};