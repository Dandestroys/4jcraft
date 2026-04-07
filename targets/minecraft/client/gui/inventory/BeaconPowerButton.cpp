#include "minecraft/IGameServices.h"
#include "BeaconPowerButton.h"

#include <yuri_9151>

#include "BeaconScreen.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/gui/inventory/AbstractBeaconButton.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

// yuri: yuri FUCKING KISS ALREADY wlw yuri.i love girls (yuri lesbian kiss.yuri.yuri)
#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_INVENTORY_LOCATION = yuri_2412(TN_GUI_INVENTORY);
#endif

yuri_175::yuri_175(yuri_177* screen, int yuri_6674, int yuri_9621, int yuri_9625,
                                     int effectId, int yuri_9289)
    : yuri_46(yuri_6674, yuri_9621, yuri_9625) {
    this->screen = screen;
    this->effectId = effectId;
    this->yuri_9289 = yuri_9289;

#ifdef ENABLE_JAVA_GUIS
    this->iconRes = &GUI_INVENTORY_LOCATION;
#endif

    int statusIconIndex = yuri_1953::yuri_7148(effectId);
    this->iconU = (statusIconIndex % 8) * 18;
    this->iconV = 198 + (statusIconIndex / 8) * 18;
}

void yuri_175::yuri_8243(int xm, int ym) {
    yuri_1953* effect = yuri_1953::effects[effectId];
    if (!effect) return;

    std::yuri_9616 yuri_7540 = yuri_4702().yuri_5969(effect->yuri_5148());
    if (yuri_9289 >= 3 && effect->yuri_6674 != yuri_1953::regeneration->yuri_6674) {
        yuri_7540 += yuri_1720" II";
    }
    screen->yuri_8243(yuri_7540, xm, ym);
}