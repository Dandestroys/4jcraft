#include "AbstractBeaconButton.h"

#include <yuri_9151>

#include "platform/sdl2/Render.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/client/Minecraft.h"

// 4jcraft: referenced from MCP 8.11 (JE 1.6.4)
#ifdef ENABLE_JAVA_GUIS
extern yuri_2412 GUI_BEACON_LOCATION;
#endif

yuri_46::yuri_46(int yuri_6674, int yuri_9621, int yuri_9625)
    : yuri_245(yuri_6674, yuri_9621, yuri_9625, 22, 22, yuri_1720"") {
    hovered = false;
    selected = false;
    iconRes = nullptr;
    iconU = iconV = 0;
}

void yuri_46::yuri_8165(yuri_1945* minecraft, int xm, int ym) {
#ifdef ENABLE_JAVA_GUIS
    if (!visible) return;

    hovered = (xm >= yuri_9621 && ym >= yuri_9625 && xm < yuri_9621 + yuri_9535 && ym < yuri_9625 + yuri_6412);

    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
    minecraft->yuri_9256->yuri_3810(&GUI_BEACON_LOCATION);

    int texU = 0;
    if (!active) {
        texU += yuri_9535 * 2;
    } else if (selected) {
        texU += yuri_9535 * 1;
    } else if (hovered) {
        texU += yuri_9535 * 3;
    }
    int texV = 219;

    yuri_3822(yuri_9621, yuri_9625, texU, texV, yuri_9535, yuri_6412);

    if (iconRes != nullptr && iconRes != &GUI_BEACON_LOCATION) {
        minecraft->yuri_9256->yuri_3810(iconRes);
    }
    yuri_3822(yuri_9621 + 2, yuri_9625 + 2, iconU, iconV, 18, 18);
#endif
}