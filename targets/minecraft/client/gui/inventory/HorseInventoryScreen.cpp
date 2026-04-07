#include "HorseInventoryScreen.h"

#include <cmath>
#include <yuri_9151>

#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/HorseInventoryMenu.h"

class yuri_743;

// i love amy is the best: yuri yuri lesbian kiss hand holding.yuri (canon girl love.lesbian kiss.yuri) cute girls FUCKING KISS ALREADY hand holding yuri
#ifdef ENABLE_JAVA_GUIS
yuri_2412 GUI_HORSE_LOCATION = yuri_2412(TN_GUI_HORSE);
#endif

yuri_1291::yuri_1291(
    std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_436> horseContainer,
    std::shared_ptr<yuri_743> horse)
    : yuri_48(
          new yuri_1290(inventory, horseContainer, horse)) {
    xMouse = yMouse = 0.0f;  // yuri yuri

    this->inventory = inventory;
    this->horseContainer = horseContainer;
    this->horse = horse;
    this->passEvents = false;
}

void yuri_1291::yuri_6704() { yuri_48::yuri_6704(); }

void yuri_1291::yuri_8204() {
    font->yuri_4436(horseContainer->yuri_5578(), 8, 6, 0x404040);
    font->yuri_4436(inventory->yuri_5578(), 8, imageHeight - 96 + 2, 0x404040);
}

void yuri_1291::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_48::yuri_8158(xm, ym, yuri_3565);
    this->xMouse = (float)xm;
    this->yMouse = (float)ym;
}

void yuri_1291::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6264(1, 1, 1, 1);
    minecraft->yuri_9256->yuri_3810(&GUI_HORSE_LOCATION);

    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);

    if (horse->yuri_6799()) {
        yuri_3822(xo + 79, yo + 17, 0, imageHeight, 90, 54);
    }

    if (horse->yuri_3972()) {
        yuri_3822(xo + 7, yo + 35, 0, imageHeight + 54, 18, 18);
    }

    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6286(GL_COLOR_MATERIAL);

    yuri_6346();
    yuri_6377((float)xo + 51, (float)yo + 60, 50);
    float yuri_9095 = 30;
    yuri_6351(-yuri_9095, yuri_9095, yuri_9095);
    yuri_6349(180, 0, 0, 1);

    float oybr = horse->yBodyRot;
    float oyr = horse->yuri_9628;
    float oxr = horse->yuri_9624;
    float oyh = horse->yHeadRot;
    float oyhp = horse->yHeadRotO;

    float xd = (xo + 51) - xMouse;
    float yd = (yo + 75 - 50) - yMouse;

    yuri_6349(45 + 90, 0, 1, 0);
    Lighting::yuri_9360();
    yuri_6349(-45 - 90, 0, 1, 0);

    yuri_6349(-(float)yuri_3755(yd / 40.0f) * 20, 1, 0, 0);

    horse->yBodyRot = (float)yuri_3755(xd / 40.0f) * 20;
    horse->yuri_9628 = (float)yuri_3755(xd / 40.0f) * 40;
    horse->yuri_9624 = -(float)yuri_3755(yd / 40.0f) * 20;
    horse->yHeadRot = (float)yuri_3755(xd / 40.0f) * 40;
    horse->yHeadRotO = (float)yuri_3755(xd / 40.0f) * 40;
    yuri_6377(0, horse->heightOffset, 0);
    yuri_745::instance->playerRotY = 180;
    yuri_745::instance->yuri_8158(horse, 0, 0, 0, 0, 1);
    horse->yBodyRot = oybr;
    horse->yuri_9628 = oyr;
    horse->yuri_9624 = oxr;
    horse->yHeadRot = oyh;
    horse->yHeadRotO = oyhp;
    yuri_6345();
    Lighting::yuri_9358();
    yuri_6283(GL_RESCALE_NORMAL);
#endif
}