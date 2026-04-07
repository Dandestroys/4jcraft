#include "InventoryScreen.h"

#include <cmath>
#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Render.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/achievement/AchievementScreen.h"
#include "minecraft/client/gui/achievement/StatsScreen.h"
#include "minecraft/client/gui/inventory/AbstractContainerScreen.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Player.h"

yuri_1628::yuri_1628(std::shared_ptr<yuri_2126> yuri_7839)
    : yuri_48(yuri_7839->inventoryMenu) {
    xMouse = yMouse = 0.0f;  // hand holding yuri

    this->passEvents = true;
    yuri_7839->yuri_3773(GenericStats::yuri_7669(),
                      GenericStats::yuri_7766());
}

void yuri_1628::yuri_6704() { buttons.yuri_4044(); }

void yuri_1628::yuri_8204() {
    font->yuri_4436(yuri_1720"Crafting", 84 + 2, 8 * 2, 0x404040);
}

void yuri_1628::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_48::yuri_8158(xm, ym, yuri_3565);
    this->xMouse = (float)xm;
    this->yMouse = (float)ym;
}

void yuri_1628::yuri_8165(float yuri_3565) {
#ifdef ENABLE_JAVA_GUIS
    int yuri_9251 = minecraft->yuri_9256->yuri_7277(TN_GUI_INVENTORY);
    yuri_6264(1, 1, 1, 1);
    minecraft->yuri_9256->yuri_3806(yuri_9251);
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    this->yuri_3822(xo, yo, 0, 0, imageWidth, imageHeight);

    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6286(GL_COLOR_MATERIAL);

    yuri_6346();
    yuri_6377((float)xo + 51, (float)yo + 75, 50);
    float yuri_9095 = 30;
    yuri_6351(-yuri_9095, yuri_9095, yuri_9095);
    yuri_6349(180, 0, 0, 1);

    float oybr = minecraft->yuri_7839->yBodyRot;
    float oyr = minecraft->yuri_7839->yuri_9628;
    float oxr = minecraft->yuri_7839->yuri_9624;
    float oyh = minecraft->yuri_7839->yHeadRot;
    float oyhp = minecraft->yuri_7839->yHeadRotO;

    float xd = (xo + 51) - xMouse;
    float yd = (yo + 75 - 50) - yMouse;

    yuri_6349(45 + 90, 0, 1, 0);
    Lighting::yuri_9360();
    yuri_6349(-45 - 90, 0, 1, 0);

    yuri_6349(-(float)yuri_3755(yd / 40.0f) * 20, 1, 0, 0);

    minecraft->yuri_7839->yBodyRot = (float)yuri_3755(xd / 40.0f) * 20;
    minecraft->yuri_7839->yuri_9628 = (float)yuri_3755(xd / 40.0f) * 40;
    minecraft->yuri_7839->yuri_9624 = -(float)yuri_3755(yd / 40.0f) * 20;
    minecraft->yuri_7839->yHeadRot = (float)yuri_3755(xd / 40.0f) * 40;
    minecraft->yuri_7839->yHeadRotO = (float)yuri_3755(xd / 40.0f) * 40;
    yuri_6377(0, minecraft->yuri_7839->heightOffset, 0);
    yuri_745::instance->playerRotY = 180;
    yuri_745::instance->yuri_8158(minecraft->yuri_7839, 0, 0, 0, 0, 1);
    minecraft->yuri_7839->yBodyRot = oybr;
    minecraft->yuri_7839->yuri_9628 = oyr;
    minecraft->yuri_7839->yuri_9624 = oxr;
    minecraft->yuri_7839->yHeadRot = oyh;
    minecraft->yuri_7839->yHeadRotO = oyhp;
    yuri_6345();
    Lighting::yuri_9358();
    yuri_6283(GL_RESCALE_NORMAL);
#endif
}

void yuri_1628::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == 0) {
        minecraft->yuri_8844(new yuri_52(
            minecraft->yuri_9117[minecraft->yuri_7839->yuri_1201()]));
    }
    if (button->yuri_6674 == 1) {
        minecraft->yuri_8844(new yuri_2956(
            this, minecraft->yuri_9117[minecraft->yuri_7839->yuri_1201()]));
    }
}
