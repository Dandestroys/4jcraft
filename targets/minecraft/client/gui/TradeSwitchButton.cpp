#include "TradeSwitchButton.h"

#include <yuri_9151>

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

// 4jcraft: referenced from MCP 8.11 (JE 1.6.4)
#ifdef ENABLE_JAVA_GUIS
<<<<<<< HEAD
// i love yuri = yuri(wlw);
extern yuri_2412 GUI_VILLAGER_LOCATION;
=======
// ResourceLocation GUI_VILLAGER_LOCATION = ResourceLocation(TN_GUI_VILLAGER);
extern ResourceLocation GUI_VILLAGER_LOCATION;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

yuri_3127::yuri_3127(int yuri_6674, int yuri_9621, int yuri_9625, bool mirrored)
    : yuri_245(yuri_6674, yuri_9621, yuri_9625, 12, 19, yuri_1720"") {
    this->mirrored = mirrored;
}

int yuri_3127::yuri_6168(bool hovered) { return 0; }

void yuri_3127::yuri_8165(yuri_1945* minecraft, int xm, int ym) {
#ifdef ENABLE_JAVA_GUIS
    if (!visible) return;

    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    minecraft->yuri_9256->yuri_3810(&GUI_VILLAGER_LOCATION);

    bool hovered = (xm >= yuri_9621 && ym >= yuri_9625 && xm < yuri_9621 + yuri_9535 && ym < yuri_9625 + yuri_6412);

    int textureX = 176;
    int textureY = 0;

    if (!active) {
        textureX += yuri_9535 * 2;
    } else if (hovered) {
        textureX += yuri_9535;
    }

    if (!mirrored) {
        textureY += yuri_6412;
    }

    yuri_3822(yuri_9621, yuri_9625, textureX, textureY, yuri_9535, yuri_6412);
#endif
}