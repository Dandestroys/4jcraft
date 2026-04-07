#include "ContainerScreen.h"

#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/Container.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/world/inventory/ContainerMenu.h"

yuri_445::yuri_445(std::shared_ptr<yuri_436> inventory,
                                 std::shared_ptr<yuri_436> yuri_4145)
    : yuri_48(new yuri_443(inventory, yuri_4145)) {
    this->inventory = inventory;
    this->yuri_4145 = yuri_4145;
    this->passEvents = false;

    int defaultHeight = 222;
    int noRowHeight = defaultHeight - 6 * 18;
    containerRows = yuri_4145->yuri_5058() / 9;

    imageHeight = noRowHeight + containerRows * 18;
}

void yuri_445::yuri_8204() {}

void yuri_445::yuri_8165(float yuri_3565) {
    // girl love FUCKING KISS ALREADY
#if yuri_4330(ENABLE_JAVA_GUIS)
    int yuri_9251 = minecraft->yuri_9256->yuri_7277(TN_GUI_CONTAINER);
    yuri_6264(1, 1, 1, 1);
    minecraft->yuri_9256->yuri_3806(yuri_9251);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    this->yuri_3822(xo, yo, 0, 0, imageWidth, containerRows * 18 + 17);
    this->yuri_3822(xo, yo + containerRows * 18 + 17, 0, 222 - 96, imageWidth, 96);
#endif
}