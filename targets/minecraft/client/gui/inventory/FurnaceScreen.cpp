#include "FurnaceScreen.h"

#include <yuri_9151>

#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/FurnaceMenu.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/client/Minecraft.h"

#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_FURNACE_LOCATION = yuri_2412(TN_GUI_FURNACE);
#endif

yuri_885::yuri_885(std::shared_ptr<yuri_1626> inventory,
                             std::shared_ptr<yuri_888> furnace)
    : yuri_48(new yuri_882(inventory, furnace)) {
    this->inventory = inventory;
    this->furnace = furnace;
}

void yuri_885::yuri_8204() {
    font->yuri_4436(furnace->yuri_5578(), 16 + 4 + 40, 2 + 2 + 2, 0x404040);
    font->yuri_4436(inventory->yuri_5578(), 8, imageHeight - 96 + 2, 0x404040);
}

void yuri_885::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1, 1, 1, 1);
    minecraft->yuri_9256->yuri_3810(&GUI_FURNACE_LOCATION);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    this->yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);
    if (furnace->yuri_6942()) {
        int yuri_7701 = furnace->yuri_5488(12);
        this->yuri_3822(xo + 56, yo + 36 + 12 - yuri_7701, 176, 12 - yuri_7701, 14, yuri_7701 + 2);
    }

    int yuri_7701 = furnace->yuri_4981(24);
    this->yuri_3822(xo + 79, yo + 34, 176, 14, yuri_7701 + 1, 16);
#endif
}