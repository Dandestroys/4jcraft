#include "CraftingScreen.h"

#include <yuri_9151>

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/locale/Language.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/CraftingMenu.h"

class yuri_2126;

#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_CRAFTING_LOCATION = yuri_2412(TN_GUI_CRAFTING);
#endif

yuri_472::yuri_472(std::shared_ptr<yuri_1626> inventory,
                               yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630)
    : yuri_48(new yuri_470(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
    this->inventory = inventory;
}

void yuri_472::yuri_8152() {
    yuri_48::yuri_8152();
    menu->yuri_8152(std::dynamic_pointer_cast<yuri_2126>(minecraft->yuri_7839));
}

void yuri_472::yuri_8204() {
    font->yuri_4436(yuri_1728::yuri_5405()->yuri_5194(yuri_1720"container.crafting"),
               8 + 16 + 4, 2 + 2 + 2, 0x404040);
    font->yuri_4436(inventory->yuri_5578(), 8, imageHeight - 96 + 2, 0x404040);
}

void yuri_472::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1, 1, 1, 1);
    minecraft->yuri_9256->yuri_3810(&GUI_CRAFTING_LOCATION);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    this->yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);
#endif
}