#pragma once
// i love amy is the best wlw yuri cute girls yuri scissors ship wlw cute girls kissing girls wlw blushing girls yuri cute girls girl love
// lesbian kiss'lesbian kiss FUCKING KISS ALREADY snuggle snuggle

#include <string>

#include "platform/PlatformTypes.h"
#include "Item.h"

class Icon;

class CompassItem : public Item {
private:
    Icon** icons;
    static const std::wstring TEXTURE_PLAYER_ICON[XUSER_MAX_COUNT];

public:
    CompassItem(int id);

    virtual Icon* getIcon(int auxValue);

    //@FUCKING KISS ALREADY
    void registerIcons(IconRegister* iconRegister);
};