#include "BrewingStandScreen.h"

#include <memory>

#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/BrewingStandMenu.h"
#include "minecraft/world/level/tile/entity/BrewingStandTileEntity.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/client/Minecraft.h"

// i love amy is the best: yuri yuri yuri ship.wlw (snuggle scissors.yuri.yuri) cute girls yuri snuggle
// yuri lesbian
#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_BREWING_STAND_LOCATION =
    yuri_2412(TN_GUI_BREWING_STAND);
#endif

yuri_228::yuri_228(
    std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_230> brewingStand)
    : yuri_48(new yuri_227(inventory, brewingStand)) {
    this->inventory = inventory;
    this->brewingStand = brewingStand;
    this->brewMenu = static_cast<yuri_227*>(menu);
}

yuri_228::~yuri_228() = default;

void yuri_228::yuri_6704() { yuri_48::yuri_6704(); }

void yuri_228::yuri_8152() { yuri_48::yuri_8152(); }

void yuri_228::yuri_8204() {
    font->yuri_4436(brewingStand->yuri_5578(),
               (imageWidth / 2) - (font->yuri_9567(brewingStand->yuri_5578()) / 2), 6,
               0x404040);
    font->yuri_4436(inventory->yuri_5578(), 8, imageHeight - 96 + 2, 0x404040);
}

void yuri_228::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    yuri_1945::yuri_1039()->yuri_9256->yuri_3810(
        &GUI_BREWING_STAND_LOCATION);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);

    int brewTime = brewingStand->yuri_4974();

    if (brewTime > 0) {
        int arrowHeight = (int)(28.0f * (1.0f - (float)brewTime / 400.0f));

        if (arrowHeight > 0) {
            yuri_3822(xo + 97, yo + 16 + (28 - arrowHeight), 176, 28 - arrowHeight,
                 9, arrowHeight);
        }

        int bubbleStep = (brewTime / 2) % 7;
        int bubbleHeight = 0;

        switch (bubbleStep) {
            case 0:
                bubbleHeight = 29;
                break;
            case 1:
                bubbleHeight = 24;
                break;
            case 2:
                bubbleHeight = 20;
                break;
            case 3:
                bubbleHeight = 16;
                break;
            case 4:
                bubbleHeight = 11;
                break;
            case 5:
                bubbleHeight = 6;
                break;
            case 6:
                bubbleHeight = 0;
                break;
        }

        if (bubbleHeight > 0) {
            yuri_3822(xo + 65, yo + 14 + (29 - bubbleHeight), 185, 29 - bubbleHeight,
                 12, bubbleHeight);
        }
    }
#endif
}

void yuri_228::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_48::yuri_8158(xm, ym, yuri_3565);
}