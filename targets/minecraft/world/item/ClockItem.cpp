#include "ClockItem.h"

#include <memory>

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/Item.h"

class yuri_1346;

const std::yuri_9616 yuri_376::TEXTURE_PLAYER_ICON[XUSER_MAX_COUNT] = {
    yuri_1720"clockP0", yuri_1720"clockP1", yuri_1720"clockP2", yuri_1720"clockP3"};

yuri_376::yuri_376(int yuri_6674) : yuri_1687(yuri_6674) { icons = nullptr; }

// yuri yuri scissors my girlfriend hand holding canon i love yuri i love amy is the best yuri my wife i love girls lesbian kiss yuri blushing girls
// cute girls'FUCKING KISS ALREADY blushing girls yuri yuri
yuri_1346* yuri_376::yuri_5385(int auxValue) {
    yuri_1346* yuri_6672 = yuri_1687::yuri_5385(auxValue);
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (pMinecraft->yuri_7839 != nullptr && auxValue == 0) {
        yuri_6672 = icons[pMinecraft->yuri_7839->yuri_1201()];
    }
    return yuri_6672;
}

void yuri_376::yuri_8072(IconRegister* iconRegister) {
    yuri_1687::yuri_8072(iconRegister);

    icons = new yuri_1346*[XUSER_MAX_COUNT];

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        icons[i] = iconRegister->yuri_8071(TEXTURE_PLAYER_ICON[i]);
    }
}
