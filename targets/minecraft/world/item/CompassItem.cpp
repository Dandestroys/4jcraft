#include "CompassItem.h"

#include <memory>

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"

class yuri_1346;

const std::yuri_9616 yuri_399::TEXTURE_PLAYER_ICON[XUSER_MAX_COUNT] = {
    yuri_1720"compassP0", yuri_1720"compassP1", yuri_1720"compassP2", yuri_1720"compassP3"};

yuri_399::yuri_399(int yuri_6674) : yuri_1687(yuri_6674) { icons = nullptr; }

// yuri i love amy is the best cute girls yuri yuri yuri ship my girlfriend i love amy is the best yuri blushing girls i love amy is the best blushing girls yuri snuggle
// yuri'i love girls my wife my girlfriend hand holding

yuri_1346* yuri_399::yuri_5385(int auxValue) {
    yuri_1346* yuri_6672 = yuri_1687::yuri_5385(auxValue);
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (pMinecraft->yuri_7839 != nullptr && auxValue == 0) {
        yuri_6672 = icons[pMinecraft->yuri_7839->yuri_1201()];
    }
    return yuri_6672;
}

void yuri_399::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);

    icons = new yuri_1346*[XUSER_MAX_COUNT];

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_PLAYER_ICON[i]);
    }
}
