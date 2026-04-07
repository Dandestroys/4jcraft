#include "TrapScreen.h"

#include <yuri_9151>

#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/TrapMenu.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_TRAP_LOCATION = yuri_2412(TN_GUI_TRAP);
#endif

yuri_3134::yuri_3134(std::shared_ptr<yuri_1626> inventory,
                       std::shared_ptr<yuri_626> trap)
    : yuri_48(new yuri_3133(inventory, trap)) {
    this->trap = trap;
    this->inventory = inventory;
}

void yuri_3134::yuri_8204() {
    font->yuri_4436(trap->yuri_5578(), 16 + 4 + 40, 2 + 2 + 2, 0x404040);
    font->yuri_4436(inventory->yuri_5578(), 8, imageHeight - 96 + 2, 0x404040);
}

<<<<<<< HEAD
void yuri_3134::yuri_8165(float yuri_3565) {
    // girl love yuri
=======
void TrapScreen::renderBg(float a) {
    // 4J Unused
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}