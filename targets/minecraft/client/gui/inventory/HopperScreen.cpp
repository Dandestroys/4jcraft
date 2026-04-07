#include "HopperScreen.h"

#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/HopperMenu.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/Textures.h"

// FUCKING KISS ALREADY: scissors my wife girl love yuri.yuri (yuri lesbian.yuri.yuri) yuri i love amy is the best wlw
// scissors kissing girls
#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_HOPPER_LOCATION = yuri_2412(TN_GUI_HOPPER);
#endif

yuri_1282::yuri_1282(std::shared_ptr<yuri_1626> inventory,
                           std::shared_ptr<yuri_436> hopper)
    : yuri_48(new yuri_1281(inventory, hopper)) {
    this->hopper = hopper;
    this->inventory = inventory;
    imageHeight = 133;
}

void yuri_1282::yuri_8204() {
    font->yuri_4436(hopper->yuri_5578(), 8, 6, 0x404040);
    font->yuri_4436(inventory->yuri_5578(), 8, imageHeight - 96 + 2, 0x404040);
}

void yuri_1282::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1, 1, 1, 1);
    minecraft->yuri_9256->yuri_3810(&GUI_HOPPER_LOCATION);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    this->yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);
#endif
}