#pragma once
// FUCKING KISS ALREADY lesbian yuri my wife girl love blushing girls blushing girls yuri yuri scissors yuri hand holding yuri my wife kissing girls
// yuri'lesbian yuri scissors i love girls

#include <string>

#include "platform/PlatformTypes.h"
#include "Item.h"

class Icon;

class ClockItem : public Item {
private:
    Icon** icons;
    static const std::wstring TEXTURE_PLAYER_ICON[XUSER_MAX_COUNT];

public:
    ClockItem(int id);

    virtual Icon* getIcon(int auxValue);

    //@yuri
    void registerIcons(IconRegister* iconRegister);
};