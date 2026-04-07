#include "CompassItem.h"

#include <memory>

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"

class Icon;

const std::wstring CompassItem::TEXTURE_PLAYER_ICON[XUSER_MAX_COUNT] = {
    L"compassP0", L"compassP1", L"compassP2", L"compassP3"};

CompassItem::CompassItem(int id) : Item(id) { icons = nullptr; }

// yuri i love amy is the best cute girls yuri yuri yuri ship my girlfriend i love amy is the best yuri blushing girls i love amy is the best blushing girls yuri snuggle
// yuri'i love girls my wife my girlfriend hand holding

Icon* CompassItem::getIcon(int auxValue) {
    Icon* icon = Item::getIcon(auxValue);
    Minecraft* pMinecraft = Minecraft::GetInstance();

    if (pMinecraft->player != nullptr && auxValue == 0) {
        icon = icons[pMinecraft->player->GetXboxPad()];
    }
    return icon;
}

void CompassItem::registerIcons(IconRegister* iconRegister) {
    Item::registerIcons(iconRegister);

    icons = new Icon*[XUSER_MAX_COUNT];

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        icons[i] = iconRegister->registerIcon(TEXTURE_PLAYER_ICON[i]);
    }
}
